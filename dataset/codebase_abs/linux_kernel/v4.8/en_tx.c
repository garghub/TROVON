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
static inline int F_17 ( struct V_42 * V_18 )
{
#define F_18 (ETH_HLEN + VLAN_HLEN)
return F_19 ( F_20 ( V_18 ) , F_18 ) ;
}
static inline int F_21 ( struct V_42 * V_18 )
{
struct V_54 V_55 ;
if ( F_22 ( V_18 ) )
return F_23 ( V_18 ) ;
else if ( F_24 ( V_18 , & V_55 , 0 ) )
return V_55 . V_56 . V_57 ;
else
return F_17 ( V_18 ) ;
}
static inline unsigned int F_25 ( enum V_58 V_59 ,
struct V_42 * V_18 )
{
int V_60 ;
switch ( V_59 ) {
case V_61 :
V_60 = F_26 ( V_18 -> V_62 , F_27 ( V_18 ) ) ;
if ( V_60 == V_63 && ! F_15 ( V_18 ) )
V_60 += V_64 ;
return V_60 ;
case V_65 :
if ( F_23 ( V_18 ) )
return F_21 ( V_18 ) ;
case V_66 :
default:
return F_17 ( V_18 ) ;
}
}
static inline T_1 F_28 ( struct V_1 * V_2 ,
struct V_42 * V_18 , bool V_67 )
{
if ( V_67 ) {
T_1 V_68 = F_27 ( V_18 ) ;
if ( F_15 ( V_18 ) )
V_68 += V_64 ;
if ( V_68 <= V_2 -> V_69 )
return F_27 ( V_18 ) ;
}
return F_25 ( V_2 -> V_70 , V_18 ) ;
}
static inline void F_29 ( unsigned char * * V_71 ,
unsigned int * V_72 ,
unsigned int V_73 )
{
* V_72 -= V_73 ;
* V_71 += V_73 ;
}
static inline void F_30 ( void * V_74 , struct V_42 * V_18 , T_1 V_68 ,
unsigned char * * V_71 ,
unsigned int * V_72 )
{
struct V_75 * V_76 = (struct V_75 * ) V_74 ;
int V_77 = 2 * V_78 ;
int V_79 = V_68 - V_77 ;
memcpy ( V_76 , * V_71 , V_77 ) ;
F_29 ( V_71 , V_72 , V_77 ) ;
V_76 -> V_80 = V_18 -> V_81 ;
V_76 -> V_82 = F_31 ( F_32 ( V_18 ) ) ;
memcpy ( & V_76 -> V_83 , * V_71 , V_79 ) ;
F_29 ( V_71 , V_72 , V_79 ) ;
}
static T_6 F_33 ( struct V_1 * V_2 , struct V_42 * V_18 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
T_1 V_6 = V_2 -> V_7 & V_5 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_5 , V_6 ) ;
struct V_84 * V_85 = & V_2 -> V_86 [ V_6 ] ;
struct V_11 * V_12 = & V_10 -> V_13 ;
struct V_87 * V_88 = & V_10 -> V_89 ;
struct V_90 * V_91 ;
unsigned char * V_71 = V_18 -> V_62 ;
unsigned int V_72 = V_18 -> V_73 ;
T_4 V_92 = V_93 ;
T_2 V_94 = 0 ;
unsigned int V_95 ;
bool V_67 = false ;
T_1 V_96 ;
T_1 V_97 ;
T_1 V_68 ;
int V_37 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
if ( F_34 ( V_18 -> V_98 == V_99 ) ) {
V_88 -> V_100 = V_101 ;
if ( V_18 -> V_102 ) {
V_88 -> V_100 |= V_103 |
V_104 ;
V_2 -> V_19 . V_105 ++ ;
} else {
V_88 -> V_100 |= V_106 ;
}
} else
V_2 -> V_19 . V_107 ++ ;
if ( V_2 -> V_108 != V_2 -> V_109 ) {
V_2 -> V_109 = V_2 -> V_108 ;
V_2 -> V_110 = ( V_2 -> V_108 == V_2 -> V_7 ) ? V_111 : 0 ;
}
if ( F_35 ( V_18 ) ) {
V_88 -> V_112 = F_31 ( F_36 ( V_18 ) -> V_113 ) ;
V_92 = V_114 ;
if ( V_18 -> V_102 ) {
V_68 = F_37 ( V_18 ) + F_38 ( V_18 ) ;
V_2 -> V_19 . V_115 ++ ;
V_2 -> V_19 . V_116 += V_18 -> V_73 - V_68 ;
} else {
V_68 = F_23 ( V_18 ) + F_39 ( V_18 ) ;
V_2 -> V_19 . V_117 ++ ;
V_2 -> V_19 . V_118 += V_18 -> V_73 - V_68 ;
}
V_95 = V_18 -> V_73 + ( F_36 ( V_18 ) -> V_119 - 1 ) * V_68 ;
} else {
V_67 = V_2 -> V_110 &&
! V_18 -> V_120 &&
! F_36 ( V_18 ) -> V_121 ;
V_68 = F_28 ( V_2 , V_18 , V_67 ) ;
V_95 = F_40 (unsigned int, skb->len, ETH_ZLEN) ;
}
V_85 -> V_95 = V_95 ;
if ( F_15 ( V_18 ) ) {
F_30 ( V_88 -> V_122 , V_18 , V_68 , & V_71 ,
& V_72 ) ;
V_68 += V_64 ;
} else {
memcpy ( V_88 -> V_122 , V_71 , V_68 ) ;
F_29 ( & V_71 , & V_72 , V_68 ) ;
}
V_88 -> V_123 = F_31 ( V_68 ) ;
V_97 = sizeof( * V_10 ) / V_124 ;
V_97 += F_41 ( V_68 - sizeof( V_88 -> V_122 ) ,
V_124 ) ;
V_91 = (struct V_90 * ) V_12 + V_97 ;
V_85 -> V_38 = 0 ;
V_96 = V_72 - V_18 -> V_125 ;
if ( V_96 ) {
V_94 = F_42 ( V_2 -> V_24 , V_71 , V_96 ,
V_30 ) ;
if ( F_43 ( F_44 ( V_2 -> V_24 , V_94 ) ) )
goto V_126;
V_91 -> V_28 = F_45 ( V_94 ) ;
V_91 -> V_127 = V_2 -> V_128 ;
V_91 -> V_129 = F_3 ( V_96 ) ;
F_9 ( V_2 , V_94 , V_96 , V_27 ) ;
V_85 -> V_38 ++ ;
V_91 ++ ;
}
for ( V_37 = 0 ; V_37 < F_36 ( V_18 ) -> V_121 ; V_37 ++ ) {
struct V_130 * V_131 = & F_36 ( V_18 ) -> V_132 [ V_37 ] ;
int V_133 = F_46 ( V_131 ) ;
V_94 = F_47 ( V_2 -> V_24 , V_131 , 0 , V_133 ,
V_30 ) ;
if ( F_43 ( F_44 ( V_2 -> V_24 , V_94 ) ) )
goto V_126;
V_91 -> V_28 = F_45 ( V_94 ) ;
V_91 -> V_127 = V_2 -> V_128 ;
V_91 -> V_129 = F_3 ( V_133 ) ;
F_9 ( V_2 , V_94 , V_133 , V_31 ) ;
V_85 -> V_38 ++ ;
V_91 ++ ;
}
V_97 += V_85 -> V_38 ;
V_12 -> V_14 = F_3 ( ( V_2 -> V_7 << 8 ) | V_92 ) ;
V_12 -> V_16 = F_3 ( ( V_2 -> V_17 << 8 ) | V_97 ) ;
V_2 -> V_18 [ V_6 ] = V_18 ;
V_85 -> V_134 = F_41 ( V_97 , V_135 ) ;
V_2 -> V_7 += V_85 -> V_134 ;
F_48 ( V_2 -> V_136 , V_85 -> V_95 ) ;
if ( F_43 ( F_36 ( V_18 ) -> V_137 & V_138 ) )
F_36 ( V_18 ) -> V_137 |= V_139 ;
if ( F_43 ( ! F_49 ( V_2 , V_140 ) ) ) {
F_50 ( V_2 -> V_136 ) ;
V_2 -> V_19 . V_141 ++ ;
}
V_2 -> V_19 . V_120 += V_18 -> V_120 ;
if ( ! V_18 -> V_120 || F_51 ( V_2 -> V_136 ) ) {
int V_142 = 0 ;
if ( V_67 && F_52 ( V_143 , & V_2 -> V_144 ) )
V_142 = V_85 -> V_134 << 3 ;
V_12 -> V_21 = V_22 ;
F_4 ( V_2 , & V_10 -> V_13 , V_142 ) ;
}
while ( ( V_2 -> V_7 & V_5 -> V_8 ) > V_2 -> V_145 )
F_1 ( V_2 , false ) ;
if ( V_67 )
V_2 -> V_110 -- ;
V_2 -> V_19 . V_146 ++ ;
V_2 -> V_19 . V_147 += V_95 ;
return V_148 ;
V_126:
V_2 -> V_19 . V_149 ++ ;
F_11 ( V_2 , V_85 -> V_38 ) ;
F_53 ( V_18 ) ;
return V_148 ;
}
T_6 F_54 ( struct V_42 * V_18 , struct V_40 * V_41 )
{
struct V_45 * V_46 = F_13 ( V_41 ) ;
struct V_1 * V_2 = V_46 -> V_150 [ F_55 ( V_18 ) ] ;
return F_33 ( V_2 , V_18 ) ;
}
bool F_56 ( struct V_151 * V_152 , int V_153 )
{
struct V_1 * V_2 ;
T_3 V_154 ;
T_3 V_155 ;
T_1 V_156 ;
T_1 V_157 ;
int V_37 ;
V_2 = F_57 ( V_152 , struct V_1 , V_152 ) ;
if ( F_43 ( F_52 ( V_158 , & V_2 -> V_144 ) ) )
return false ;
V_156 = 0 ;
V_155 = 0 ;
V_157 = V_2 -> V_108 ;
V_154 = V_2 -> V_154 ;
for ( V_37 = 0 ; V_37 < V_159 ; V_37 ++ ) {
struct V_160 * V_161 ;
T_1 V_162 ;
bool V_163 ;
V_161 = F_58 ( V_152 ) ;
if ( ! V_161 )
break;
F_59 ( & V_152 -> V_5 ) ;
V_162 = F_60 ( V_161 -> V_162 ) ;
do {
struct V_84 * V_85 ;
struct V_42 * V_18 ;
T_1 V_164 ;
int V_165 ;
V_163 = ( V_157 == V_162 ) ;
V_164 = V_157 & V_2 -> V_5 . V_8 ;
V_18 = V_2 -> V_18 [ V_164 ] ;
V_85 = & V_2 -> V_86 [ V_164 ] ;
if ( F_43 ( ! V_18 ) ) {
V_157 ++ ;
continue;
}
if ( F_43 ( F_36 ( V_18 ) -> V_137 &
V_138 ) ) {
struct V_166 V_167 = {} ;
F_61 ( V_2 -> V_168 ,
F_62 ( V_161 ) , & V_167 ) ;
F_63 ( V_18 , & V_167 ) ;
}
for ( V_165 = 0 ; V_165 < V_85 -> V_38 ; V_165 ++ ) {
struct V_25 * V_26 =
F_10 ( V_2 , V_154 ++ ) ;
F_5 ( V_2 -> V_24 , V_26 ) ;
}
V_156 ++ ;
V_155 += V_85 -> V_95 ;
V_157 += V_85 -> V_134 ;
F_64 ( V_18 , V_153 ) ;
} while ( ! V_163 );
}
F_65 ( & V_152 -> V_5 ) ;
F_66 () ;
V_2 -> V_154 = V_154 ;
V_2 -> V_108 = V_157 ;
F_67 ( V_2 -> V_136 , V_156 , V_155 ) ;
if ( F_68 ( V_2 -> V_136 ) &&
F_49 ( V_2 , V_140 ) ) {
F_69 ( V_2 -> V_136 ) ;
V_2 -> V_19 . V_169 ++ ;
}
return ( V_37 == V_159 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
struct V_84 * V_85 ;
struct V_42 * V_18 ;
T_1 V_164 ;
int V_37 ;
while ( V_2 -> V_108 != V_2 -> V_7 ) {
V_164 = V_2 -> V_108 & V_2 -> V_5 . V_8 ;
V_18 = V_2 -> V_18 [ V_164 ] ;
V_85 = & V_2 -> V_86 [ V_164 ] ;
if ( ! V_18 ) {
V_2 -> V_108 ++ ;
continue;
}
for ( V_37 = 0 ; V_37 < V_85 -> V_38 ; V_37 ++ ) {
struct V_25 * V_26 =
F_10 ( V_2 , V_2 -> V_154 ++ ) ;
F_5 ( V_2 -> V_24 , V_26 ) ;
}
F_53 ( V_18 ) ;
V_2 -> V_108 += V_85 -> V_134 ;
}
}
