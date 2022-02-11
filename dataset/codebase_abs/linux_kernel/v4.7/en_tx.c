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
V_2 -> V_19 . V_20 ++ ;
if ( V_3 ) {
V_12 -> V_21 = V_22 ;
F_4 ( V_2 , & V_10 -> V_13 , 0 ) ;
}
}
static inline void F_5 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
switch ( V_26 -> type ) {
case V_27 :
F_6 ( V_24 , V_26 -> V_28 , V_26 -> V_29 , V_30 ) ;
break;
case V_31 :
F_7 ( V_24 , V_26 -> V_28 , V_26 -> V_29 , V_30 ) ;
break;
default:
F_8 ( true , L_1 ) ;
}
}
static inline void F_9 ( struct V_1 * V_2 ,
T_2 V_28 ,
T_3 V_29 ,
enum V_32 V_33 )
{
V_2 -> V_34 [ V_2 -> V_35 & V_2 -> V_36 ] . V_28 = V_28 ;
V_2 -> V_34 [ V_2 -> V_35 & V_2 -> V_36 ] . V_29 = V_29 ;
V_2 -> V_34 [ V_2 -> V_35 & V_2 -> V_36 ] . type = V_33 ;
V_2 -> V_35 ++ ;
}
static inline struct V_25 * F_10 ( struct V_1 * V_2 , T_3 V_37 )
{
return & V_2 -> V_34 [ V_37 & V_2 -> V_36 ] ;
}
static void F_11 ( struct V_1 * V_2 , T_4 V_38 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
struct V_25 * V_39 =
F_10 ( V_2 , -- V_2 -> V_35 ) ;
F_5 ( V_2 -> V_24 , V_39 ) ;
}
}
T_1 F_12 ( struct V_40 * V_41 , struct V_42 * V_18 ,
void * V_43 , T_5 V_44 )
{
struct V_45 * V_46 = F_13 ( V_41 ) ;
int V_47 = V_44 ( V_41 , V_18 ) ;
int V_48 = 0 ;
if ( ! F_14 ( V_41 ) )
return V_47 ;
if ( F_15 ( V_18 ) )
V_48 = V_18 -> V_49 >> V_50 ;
if ( V_47 >= V_46 -> V_51 . V_52 )
V_47 = F_16 ( V_47 ,
V_46 -> V_51 . V_52 ) ;
return V_46 -> V_53 [ V_47 ] [ V_48 ] ;
}
static inline T_1 F_17 ( struct V_1 * V_2 ,
struct V_42 * V_18 , bool V_54 )
{
#define F_18 (ETH_HLEN + VLAN_HLEN)
if ( V_54 ) {
T_1 V_55 = F_19 ( V_18 ) ;
if ( F_15 ( V_18 ) )
V_55 += V_56 ;
if ( V_55 <= V_2 -> V_57 )
return F_19 ( V_18 ) ;
}
return F_20 ( F_21 ( V_18 ) , F_18 ) ;
}
static inline void F_22 ( unsigned char * * V_58 ,
unsigned int * V_59 ,
unsigned int V_60 )
{
* V_59 -= V_60 ;
* V_58 += V_60 ;
}
static inline void F_23 ( void * V_61 , struct V_42 * V_18 , T_1 V_55 ,
unsigned char * * V_58 ,
unsigned int * V_59 )
{
struct V_62 * V_63 = (struct V_62 * ) V_61 ;
int V_64 = 2 * V_65 ;
int V_66 = V_55 - V_64 ;
memcpy ( V_63 , * V_58 , V_64 ) ;
F_22 ( V_58 , V_59 , V_64 ) ;
V_63 -> V_67 = V_18 -> V_68 ;
V_63 -> V_69 = F_24 ( F_25 ( V_18 ) ) ;
memcpy ( & V_63 -> V_70 , * V_58 , V_66 ) ;
F_22 ( V_58 , V_59 , V_66 ) ;
}
static T_6 F_26 ( struct V_1 * V_2 , struct V_42 * V_18 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
T_1 V_6 = V_2 -> V_7 & V_5 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_5 , V_6 ) ;
struct V_71 * V_72 = & V_2 -> V_73 [ V_6 ] ;
struct V_11 * V_12 = & V_10 -> V_13 ;
struct V_74 * V_75 = & V_10 -> V_76 ;
struct V_77 * V_78 ;
unsigned char * V_58 = V_18 -> V_79 ;
unsigned int V_59 = V_18 -> V_60 ;
T_4 V_80 = V_81 ;
T_2 V_82 = 0 ;
unsigned int V_83 ;
bool V_54 = false ;
T_1 V_84 ;
T_1 V_85 ;
T_1 V_55 ;
int V_37 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
if ( F_27 ( V_18 -> V_86 == V_87 ) ) {
V_75 -> V_88 = V_89 ;
if ( V_18 -> V_90 ) {
V_75 -> V_88 |= V_91 |
V_92 ;
V_2 -> V_19 . V_93 ++ ;
} else {
V_75 -> V_88 |= V_94 ;
}
} else
V_2 -> V_19 . V_95 ++ ;
if ( V_2 -> V_96 != V_2 -> V_97 ) {
V_2 -> V_97 = V_2 -> V_96 ;
V_2 -> V_98 = ( V_2 -> V_96 == V_2 -> V_7 ) ? V_99 : 0 ;
}
if ( F_28 ( V_18 ) ) {
V_75 -> V_100 = F_24 ( F_29 ( V_18 ) -> V_101 ) ;
V_80 = V_102 ;
if ( V_18 -> V_90 ) {
V_55 = F_30 ( V_18 ) + F_31 ( V_18 ) ;
V_2 -> V_19 . V_103 ++ ;
V_2 -> V_19 . V_104 += V_18 -> V_60 - V_55 ;
} else {
V_55 = F_32 ( V_18 ) + F_33 ( V_18 ) ;
V_2 -> V_19 . V_105 ++ ;
V_2 -> V_19 . V_106 += V_18 -> V_60 - V_55 ;
}
V_83 = V_18 -> V_60 + ( F_29 ( V_18 ) -> V_107 - 1 ) * V_55 ;
} else {
V_54 = V_2 -> V_98 &&
! V_18 -> V_108 &&
! F_29 ( V_18 ) -> V_109 ;
V_55 = F_17 ( V_2 , V_18 , V_54 ) ;
V_83 = F_34 (unsigned int, skb->len, ETH_ZLEN) ;
}
V_72 -> V_83 = V_83 ;
if ( F_15 ( V_18 ) ) {
F_23 ( V_75 -> V_110 , V_18 , V_55 , & V_58 ,
& V_59 ) ;
V_55 += V_56 ;
} else {
memcpy ( V_75 -> V_110 , V_58 , V_55 ) ;
F_22 ( & V_58 , & V_59 , V_55 ) ;
}
V_75 -> V_111 = F_24 ( V_55 ) ;
V_85 = sizeof( * V_10 ) / V_112 ;
V_85 += F_35 ( V_55 - sizeof( V_75 -> V_110 ) ,
V_112 ) ;
V_78 = (struct V_77 * ) V_12 + V_85 ;
V_72 -> V_38 = 0 ;
V_84 = V_59 - V_18 -> V_113 ;
if ( V_84 ) {
V_82 = F_36 ( V_2 -> V_24 , V_58 , V_84 ,
V_30 ) ;
if ( F_37 ( F_38 ( V_2 -> V_24 , V_82 ) ) )
goto V_114;
V_78 -> V_28 = F_39 ( V_82 ) ;
V_78 -> V_115 = V_2 -> V_116 ;
V_78 -> V_117 = F_3 ( V_84 ) ;
F_9 ( V_2 , V_82 , V_84 , V_27 ) ;
V_72 -> V_38 ++ ;
V_78 ++ ;
}
for ( V_37 = 0 ; V_37 < F_29 ( V_18 ) -> V_109 ; V_37 ++ ) {
struct V_118 * V_119 = & F_29 ( V_18 ) -> V_120 [ V_37 ] ;
int V_121 = F_40 ( V_119 ) ;
V_82 = F_41 ( V_2 -> V_24 , V_119 , 0 , V_121 ,
V_30 ) ;
if ( F_37 ( F_38 ( V_2 -> V_24 , V_82 ) ) )
goto V_114;
V_78 -> V_28 = F_39 ( V_82 ) ;
V_78 -> V_115 = V_2 -> V_116 ;
V_78 -> V_117 = F_3 ( V_121 ) ;
F_9 ( V_2 , V_82 , V_121 , V_31 ) ;
V_72 -> V_38 ++ ;
V_78 ++ ;
}
V_85 += V_72 -> V_38 ;
V_12 -> V_14 = F_3 ( ( V_2 -> V_7 << 8 ) | V_80 ) ;
V_12 -> V_16 = F_3 ( ( V_2 -> V_17 << 8 ) | V_85 ) ;
V_2 -> V_18 [ V_6 ] = V_18 ;
V_72 -> V_122 = F_35 ( V_85 , V_123 ) ;
V_2 -> V_7 += V_72 -> V_122 ;
F_42 ( V_2 -> V_124 , V_72 -> V_83 ) ;
if ( F_37 ( F_29 ( V_18 ) -> V_125 & V_126 ) )
F_29 ( V_18 ) -> V_125 |= V_127 ;
if ( F_37 ( ! F_43 ( V_2 , V_128 ) ) ) {
F_44 ( V_2 -> V_124 ) ;
V_2 -> V_19 . V_129 ++ ;
}
if ( ! V_18 -> V_108 || F_45 ( V_2 -> V_124 ) ) {
int V_130 = 0 ;
if ( V_54 && F_46 ( V_131 , & V_2 -> V_132 ) )
V_130 = V_72 -> V_122 << 3 ;
V_12 -> V_21 = V_22 ;
F_4 ( V_2 , & V_10 -> V_13 , V_130 ) ;
}
while ( ( V_2 -> V_7 & V_5 -> V_8 ) > V_2 -> V_133 )
F_1 ( V_2 , false ) ;
if ( V_54 )
V_2 -> V_98 -- ;
V_2 -> V_19 . V_134 ++ ;
V_2 -> V_19 . V_135 += V_83 ;
return V_136 ;
V_114:
V_2 -> V_19 . V_137 ++ ;
F_11 ( V_2 , V_72 -> V_38 ) ;
F_47 ( V_18 ) ;
return V_136 ;
}
T_6 F_48 ( struct V_42 * V_18 , struct V_40 * V_41 )
{
struct V_45 * V_46 = F_13 ( V_41 ) ;
struct V_1 * V_2 = V_46 -> V_138 [ F_49 ( V_18 ) ] ;
return F_26 ( V_2 , V_18 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_71 * V_72 ;
struct V_42 * V_18 ;
T_1 V_139 ;
int V_37 ;
while ( V_2 -> V_96 != V_2 -> V_7 ) {
V_139 = V_2 -> V_96 & V_2 -> V_5 . V_8 ;
V_18 = V_2 -> V_18 [ V_139 ] ;
V_72 = & V_2 -> V_73 [ V_139 ] ;
if ( ! V_18 ) {
V_2 -> V_96 ++ ;
continue;
}
for ( V_37 = 0 ; V_37 < V_72 -> V_38 ; V_37 ++ ) {
struct V_25 * V_26 =
F_10 ( V_2 , V_2 -> V_140 ++ ) ;
F_5 ( V_2 -> V_24 , V_26 ) ;
}
F_47 ( V_18 ) ;
V_2 -> V_96 += V_72 -> V_122 ;
}
}
bool F_51 ( struct V_141 * V_142 , int V_143 )
{
struct V_1 * V_2 ;
T_3 V_140 ;
T_3 V_144 ;
T_1 V_145 ;
T_1 V_146 ;
int V_37 ;
V_2 = F_52 ( V_142 , struct V_1 , V_142 ) ;
if ( F_37 ( F_46 ( V_147 , & V_2 -> V_132 ) ) )
return false ;
V_145 = 0 ;
V_144 = 0 ;
V_146 = V_2 -> V_96 ;
V_140 = V_2 -> V_140 ;
for ( V_37 = 0 ; V_37 < V_148 ; V_37 ++ ) {
struct V_149 * V_150 ;
T_1 V_151 ;
bool V_152 ;
V_150 = F_53 ( V_142 ) ;
if ( ! V_150 )
break;
F_54 ( & V_142 -> V_5 ) ;
V_151 = F_55 ( V_150 -> V_151 ) ;
do {
struct V_71 * V_72 ;
struct V_42 * V_18 ;
T_1 V_139 ;
int V_153 ;
V_152 = ( V_146 == V_151 ) ;
V_139 = V_146 & V_2 -> V_5 . V_8 ;
V_18 = V_2 -> V_18 [ V_139 ] ;
V_72 = & V_2 -> V_73 [ V_139 ] ;
if ( F_37 ( ! V_18 ) ) {
V_146 ++ ;
continue;
}
if ( F_37 ( F_29 ( V_18 ) -> V_125 &
V_126 ) ) {
struct V_154 V_155 = {} ;
F_56 ( V_2 -> V_156 ,
F_57 ( V_150 ) , & V_155 ) ;
F_58 ( V_18 , & V_155 ) ;
}
for ( V_153 = 0 ; V_153 < V_72 -> V_38 ; V_153 ++ ) {
struct V_25 * V_26 =
F_10 ( V_2 , V_140 ++ ) ;
F_5 ( V_2 -> V_24 , V_26 ) ;
}
V_145 ++ ;
V_144 += V_72 -> V_83 ;
V_146 += V_72 -> V_122 ;
F_59 ( V_18 , V_143 ) ;
} while ( ! V_152 );
}
F_60 ( & V_142 -> V_5 ) ;
F_61 () ;
V_2 -> V_140 = V_140 ;
V_2 -> V_96 = V_146 ;
F_62 ( V_2 -> V_124 , V_145 , V_144 ) ;
if ( F_63 ( V_2 -> V_124 ) &&
F_43 ( V_2 , V_128 ) &&
F_27 ( F_46 ( V_157 , & V_2 -> V_132 ) ) ) {
F_64 ( V_2 -> V_124 ) ;
V_2 -> V_19 . V_158 ++ ;
}
return ( V_37 == V_148 ) ;
}
