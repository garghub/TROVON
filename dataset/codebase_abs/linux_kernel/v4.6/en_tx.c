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
int V_46 = ( F_14 ( V_39 ) && F_15 ( V_18 ) ) ?
V_18 -> V_47 >> V_48 : 0 ;
return V_44 -> V_49 [ V_45 ] [ V_46 ] ;
}
static inline T_1 F_16 ( struct V_1 * V_2 ,
struct V_40 * V_18 , bool V_50 )
{
#define F_17 ETH_HLEN
if ( V_50 ) {
T_1 V_51 = F_18 ( V_18 ) ;
if ( F_15 ( V_18 ) )
V_51 += V_52 ;
if ( V_51 <= V_2 -> V_53 )
return F_18 ( V_18 ) ;
}
return F_17 ;
}
static inline void F_19 ( unsigned char * * V_54 ,
unsigned int * V_55 ,
unsigned int V_56 )
{
* V_55 -= V_56 ;
* V_54 += V_56 ;
}
static inline void F_20 ( void * V_57 , struct V_40 * V_18 , T_1 V_51 ,
unsigned char * * V_54 ,
unsigned int * V_55 )
{
struct V_58 * V_59 = (struct V_58 * ) V_57 ;
int V_60 = 2 * V_61 ;
int V_62 = V_51 - V_60 ;
memcpy ( V_59 , * V_54 , V_60 ) ;
F_19 ( V_54 , V_55 , V_60 ) ;
V_59 -> V_63 = V_18 -> V_64 ;
V_59 -> V_65 = F_21 ( F_22 ( V_18 ) ) ;
memcpy ( & V_59 -> V_66 , * V_54 , V_62 ) ;
F_19 ( V_54 , V_55 , V_62 ) ;
}
static T_6 F_23 ( struct V_1 * V_2 , struct V_40 * V_18 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
T_1 V_6 = V_2 -> V_7 & V_5 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_5 , V_6 ) ;
struct V_67 * V_68 = & V_2 -> V_69 [ V_6 ] ;
struct V_11 * V_12 = & V_10 -> V_13 ;
struct V_70 * V_71 = & V_10 -> V_72 ;
struct V_73 * V_74 ;
unsigned char * V_54 = V_18 -> V_75 ;
unsigned int V_55 = V_18 -> V_56 ;
T_4 V_76 = V_77 ;
T_2 V_78 = 0 ;
unsigned int V_79 ;
bool V_50 = false ;
T_1 V_80 ;
T_1 V_81 ;
T_1 V_51 ;
int V_35 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
if ( F_24 ( V_18 -> V_82 == V_83 ) ) {
V_71 -> V_84 = V_85 ;
if ( V_18 -> V_86 ) {
V_71 -> V_84 |= V_87 |
V_88 ;
V_2 -> V_89 . V_90 ++ ;
} else {
V_71 -> V_84 |= V_91 ;
}
} else
V_2 -> V_89 . V_92 ++ ;
if ( V_2 -> V_93 != V_2 -> V_94 ) {
V_2 -> V_94 = V_2 -> V_93 ;
V_2 -> V_95 = ( V_2 -> V_93 == V_2 -> V_7 ) ? V_96 : 0 ;
}
if ( F_25 ( V_18 ) ) {
V_71 -> V_97 = F_21 ( F_26 ( V_18 ) -> V_98 ) ;
V_76 = V_99 ;
if ( V_18 -> V_86 ) {
V_51 = F_27 ( V_18 ) + F_28 ( V_18 ) ;
V_2 -> V_89 . V_100 ++ ;
V_2 -> V_89 . V_101 += V_18 -> V_56 - V_51 ;
} else {
V_51 = F_29 ( V_18 ) + F_30 ( V_18 ) ;
V_2 -> V_89 . V_102 ++ ;
V_2 -> V_89 . V_103 += V_18 -> V_56 - V_51 ;
}
V_79 = V_18 -> V_56 + ( F_26 ( V_18 ) -> V_104 - 1 ) * V_51 ;
} else {
V_50 = V_2 -> V_95 &&
! V_18 -> V_105 &&
! F_26 ( V_18 ) -> V_106 ;
V_51 = F_16 ( V_2 , V_18 , V_50 ) ;
V_79 = F_31 (unsigned int, skb->len, ETH_ZLEN) ;
}
V_68 -> V_79 = V_79 ;
if ( F_15 ( V_18 ) ) {
F_20 ( V_71 -> V_107 , V_18 , V_51 , & V_54 ,
& V_55 ) ;
V_51 += V_52 ;
} else {
memcpy ( V_71 -> V_107 , V_54 , V_51 ) ;
F_19 ( & V_54 , & V_55 , V_51 ) ;
}
V_71 -> V_108 = F_21 ( V_51 ) ;
V_81 = sizeof( * V_10 ) / V_109 ;
V_81 += F_32 ( V_51 - sizeof( V_71 -> V_107 ) ,
V_109 ) ;
V_74 = (struct V_73 * ) V_12 + V_81 ;
V_68 -> V_36 = 0 ;
V_80 = V_55 - V_18 -> V_110 ;
if ( V_80 ) {
V_78 = F_33 ( V_2 -> V_22 , V_54 , V_80 ,
V_28 ) ;
if ( F_34 ( F_35 ( V_2 -> V_22 , V_78 ) ) )
goto V_111;
V_74 -> V_26 = F_36 ( V_78 ) ;
V_74 -> V_112 = V_2 -> V_113 ;
V_74 -> V_114 = F_3 ( V_80 ) ;
F_9 ( V_2 , V_78 , V_80 , V_25 ) ;
V_68 -> V_36 ++ ;
V_74 ++ ;
}
for ( V_35 = 0 ; V_35 < F_26 ( V_18 ) -> V_106 ; V_35 ++ ) {
struct V_115 * V_116 = & F_26 ( V_18 ) -> V_117 [ V_35 ] ;
int V_118 = F_37 ( V_116 ) ;
V_78 = F_38 ( V_2 -> V_22 , V_116 , 0 , V_118 ,
V_28 ) ;
if ( F_34 ( F_35 ( V_2 -> V_22 , V_78 ) ) )
goto V_111;
V_74 -> V_26 = F_36 ( V_78 ) ;
V_74 -> V_112 = V_2 -> V_113 ;
V_74 -> V_114 = F_3 ( V_118 ) ;
F_9 ( V_2 , V_78 , V_118 , V_29 ) ;
V_68 -> V_36 ++ ;
V_74 ++ ;
}
V_81 += V_68 -> V_36 ;
V_12 -> V_14 = F_3 ( ( V_2 -> V_7 << 8 ) | V_76 ) ;
V_12 -> V_16 = F_3 ( ( V_2 -> V_17 << 8 ) | V_81 ) ;
V_2 -> V_18 [ V_6 ] = V_18 ;
V_68 -> V_119 = F_32 ( V_81 , V_120 ) ;
V_2 -> V_7 += V_68 -> V_119 ;
F_39 ( V_2 -> V_121 , V_68 -> V_79 ) ;
if ( F_34 ( F_26 ( V_18 ) -> V_122 & V_123 ) )
F_26 ( V_18 ) -> V_122 |= V_124 ;
if ( F_34 ( ! F_40 ( V_2 , V_125 ) ) ) {
F_41 ( V_2 -> V_121 ) ;
V_2 -> V_89 . V_126 ++ ;
}
if ( ! V_18 -> V_105 || F_42 ( V_2 -> V_121 ) ) {
int V_127 = 0 ;
if ( V_50 && F_43 ( V_128 , & V_2 -> V_129 ) )
V_127 = V_68 -> V_119 << 3 ;
V_12 -> V_19 = V_20 ;
F_4 ( V_2 , V_10 , V_127 ) ;
}
while ( ( V_2 -> V_7 & V_5 -> V_8 ) > V_2 -> V_130 )
F_1 ( V_2 , false ) ;
V_2 -> V_95 = V_50 ? V_2 -> V_95 - 1 : 0 ;
V_2 -> V_89 . V_131 ++ ;
V_2 -> V_89 . V_132 += V_79 ;
return V_133 ;
V_111:
V_2 -> V_89 . V_134 ++ ;
F_11 ( V_2 , V_68 -> V_36 ) ;
F_44 ( V_18 ) ;
return V_133 ;
}
T_6 F_45 ( struct V_40 * V_18 , struct V_38 * V_39 )
{
struct V_43 * V_44 = F_13 ( V_39 ) ;
struct V_1 * V_2 = V_44 -> V_135 [ F_46 ( V_18 ) ] ;
return F_23 ( V_2 , V_18 ) ;
}
bool F_47 ( struct V_136 * V_137 , int V_138 )
{
struct V_1 * V_2 ;
T_3 V_139 ;
T_3 V_140 ;
T_1 V_141 ;
T_1 V_142 ;
int V_35 ;
V_2 = F_48 ( V_137 , struct V_1 , V_137 ) ;
V_141 = 0 ;
V_140 = 0 ;
V_142 = V_2 -> V_93 ;
V_139 = V_2 -> V_139 ;
for ( V_35 = 0 ; V_35 < V_143 ; V_35 ++ ) {
struct V_144 * V_145 ;
T_1 V_146 ;
bool V_147 ;
V_145 = F_49 ( V_137 ) ;
if ( ! V_145 )
break;
F_50 ( & V_137 -> V_5 ) ;
V_146 = F_51 ( V_145 -> V_146 ) ;
do {
struct V_67 * V_68 ;
struct V_40 * V_18 ;
T_1 V_148 ;
int V_149 ;
V_147 = ( V_142 == V_146 ) ;
V_148 = V_142 & V_2 -> V_5 . V_8 ;
V_18 = V_2 -> V_18 [ V_148 ] ;
V_68 = & V_2 -> V_69 [ V_148 ] ;
if ( F_34 ( ! V_18 ) ) {
V_2 -> V_89 . V_150 ++ ;
V_142 ++ ;
continue;
}
if ( F_34 ( F_26 ( V_18 ) -> V_122 &
V_123 ) ) {
struct V_151 V_152 = {} ;
F_52 ( V_2 -> V_153 ,
F_53 ( V_145 ) , & V_152 ) ;
F_54 ( V_18 , & V_152 ) ;
}
for ( V_149 = 0 ; V_149 < V_68 -> V_36 ; V_149 ++ ) {
struct V_23 * V_24 =
F_10 ( V_2 , V_139 ++ ) ;
F_5 ( V_2 -> V_22 , V_24 ) ;
}
V_141 ++ ;
V_140 += V_68 -> V_79 ;
V_142 += V_68 -> V_119 ;
F_55 ( V_18 , V_138 ) ;
} while ( ! V_147 );
}
F_56 ( & V_137 -> V_5 ) ;
F_57 () ;
V_2 -> V_139 = V_139 ;
V_2 -> V_93 = V_142 ;
F_58 ( V_2 -> V_121 , V_141 , V_140 ) ;
if ( F_59 ( V_2 -> V_121 ) &&
F_40 ( V_2 , V_125 ) &&
F_24 ( F_43 ( V_154 , & V_2 -> V_129 ) ) ) {
F_60 ( V_2 -> V_121 ) ;
V_2 -> V_89 . V_155 ++ ;
}
return ( V_35 == V_143 ) ;
}
