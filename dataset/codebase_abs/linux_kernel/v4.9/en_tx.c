void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
T_1 V_6 = V_2 -> V_7 & V_5 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_5 , V_6 ) ;
struct V_11 * V_12 = & V_10 -> V_13 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_14 = F_3 ( ( V_2 -> V_7 << 8 ) | V_15 ) ;
V_12 -> V_16 = F_3 ( ( V_2 -> V_17 << 8 ) | 0x01 ) ;
V_2 -> V_7 ++ ;
V_2 -> V_18 . V_19 ++ ;
if ( V_3 ) {
V_12 -> V_20 = V_21 ;
F_4 ( V_2 , & V_10 -> V_13 , 0 ) ;
}
}
static inline void F_5 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
switch ( V_25 -> type ) {
case V_26 :
F_6 ( V_23 , V_25 -> V_27 , V_25 -> V_28 , V_29 ) ;
break;
case V_30 :
F_7 ( V_23 , V_25 -> V_27 , V_25 -> V_28 , V_29 ) ;
break;
default:
F_8 ( true , L_1 ) ;
}
}
static inline void F_9 ( struct V_1 * V_2 ,
T_2 V_27 ,
T_3 V_28 ,
enum V_31 V_32 )
{
T_3 V_33 = V_2 -> V_34 & V_2 -> V_35 ;
V_2 -> V_36 . V_37 . V_38 [ V_33 ] . V_27 = V_27 ;
V_2 -> V_36 . V_37 . V_38 [ V_33 ] . V_28 = V_28 ;
V_2 -> V_36 . V_37 . V_38 [ V_33 ] . type = V_32 ;
V_2 -> V_34 ++ ;
}
static inline struct V_24 * F_10 ( struct V_1 * V_2 , T_3 V_33 )
{
return & V_2 -> V_36 . V_37 . V_38 [ V_33 & V_2 -> V_35 ] ;
}
static void F_11 ( struct V_1 * V_2 , T_4 V_39 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_39 ; V_33 ++ ) {
struct V_24 * V_40 =
F_10 ( V_2 , -- V_2 -> V_34 ) ;
F_5 ( V_2 -> V_23 , V_40 ) ;
}
}
T_1 F_12 ( struct V_41 * V_42 , struct V_43 * V_44 ,
void * V_45 , T_5 V_46 )
{
struct V_47 * V_48 = F_13 ( V_42 ) ;
int V_49 = V_46 ( V_42 , V_44 ) ;
int V_50 = 0 ;
if ( ! F_14 ( V_42 ) )
return V_49 ;
if ( F_15 ( V_44 ) )
V_50 = V_44 -> V_51 >> V_52 ;
if ( V_49 >= V_48 -> V_53 . V_54 )
V_49 = F_16 ( V_49 ,
V_48 -> V_53 . V_54 ) ;
return V_48 -> V_55 [ V_49 ] [ V_50 ] ;
}
static inline int F_17 ( struct V_43 * V_44 )
{
#define F_18 (ETH_HLEN + VLAN_HLEN)
return F_19 ( F_20 ( V_44 ) , F_18 ) ;
}
static inline int F_21 ( struct V_43 * V_44 )
{
struct V_56 V_57 ;
if ( F_22 ( V_44 ) )
return F_23 ( V_44 ) ;
else if ( F_24 ( V_44 , & V_57 , 0 ) )
return V_57 . V_58 . V_59 ;
else
return F_17 ( V_44 ) ;
}
static inline unsigned int F_25 ( enum V_60 V_61 ,
struct V_43 * V_44 )
{
int V_62 ;
switch ( V_61 ) {
case V_63 :
V_62 = F_26 ( V_44 -> V_64 , F_27 ( V_44 ) ) ;
if ( V_62 == V_65 && ! F_15 ( V_44 ) )
V_62 += V_66 ;
return V_62 ;
case V_67 :
if ( F_23 ( V_44 ) )
return F_21 ( V_44 ) ;
case V_68 :
default:
return F_17 ( V_44 ) ;
}
}
static inline T_1 F_28 ( struct V_1 * V_2 ,
struct V_43 * V_44 , bool V_69 )
{
if ( V_69 ) {
T_1 V_70 = F_27 ( V_44 ) ;
if ( F_15 ( V_44 ) )
V_70 += V_66 ;
if ( V_70 <= V_2 -> V_71 )
return F_27 ( V_44 ) ;
}
return F_25 ( V_2 -> V_72 , V_44 ) ;
}
static inline void F_29 ( unsigned char * * V_73 ,
unsigned int * V_74 ,
unsigned int V_75 )
{
* V_74 -= V_75 ;
* V_73 += V_75 ;
}
static inline void F_30 ( void * V_76 , struct V_43 * V_44 , T_1 V_70 ,
unsigned char * * V_73 ,
unsigned int * V_74 )
{
struct V_77 * V_78 = (struct V_77 * ) V_76 ;
int V_79 = 2 * V_80 ;
int V_81 = V_70 - V_79 ;
memcpy ( V_78 , * V_73 , V_79 ) ;
F_29 ( V_73 , V_74 , V_79 ) ;
V_78 -> V_82 = V_44 -> V_83 ;
V_78 -> V_84 = F_31 ( F_32 ( V_44 ) ) ;
memcpy ( & V_78 -> V_85 , * V_73 , V_81 ) ;
F_29 ( V_73 , V_74 , V_81 ) ;
}
static T_6 F_33 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
T_1 V_6 = V_2 -> V_7 & V_5 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_5 , V_6 ) ;
struct V_86 * V_87 = & V_2 -> V_36 . V_37 . V_88 [ V_6 ] ;
struct V_11 * V_12 = & V_10 -> V_13 ;
struct V_89 * V_90 = & V_10 -> V_91 ;
struct V_92 * V_93 ;
unsigned char * V_73 = V_44 -> V_64 ;
unsigned int V_74 = V_44 -> V_75 ;
T_4 V_94 = V_95 ;
T_2 V_96 = 0 ;
unsigned int V_97 ;
bool V_69 = false ;
T_1 V_98 ;
T_1 V_99 ;
T_1 V_70 ;
int V_33 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
if ( F_34 ( V_44 -> V_100 == V_101 ) ) {
V_90 -> V_102 = V_103 ;
if ( V_44 -> V_104 ) {
V_90 -> V_102 |= V_105 |
V_106 ;
V_2 -> V_18 . V_107 ++ ;
} else {
V_90 -> V_102 |= V_108 ;
}
} else
V_2 -> V_18 . V_109 ++ ;
if ( V_2 -> V_110 != V_2 -> V_111 ) {
V_2 -> V_111 = V_2 -> V_110 ;
V_2 -> V_112 = ( V_2 -> V_110 == V_2 -> V_7 ) ? V_113 : 0 ;
}
if ( F_35 ( V_44 ) ) {
V_90 -> V_114 = F_31 ( F_36 ( V_44 ) -> V_115 ) ;
V_94 = V_116 ;
if ( V_44 -> V_104 ) {
V_70 = F_37 ( V_44 ) + F_38 ( V_44 ) ;
V_2 -> V_18 . V_117 ++ ;
V_2 -> V_18 . V_118 += V_44 -> V_75 - V_70 ;
} else {
V_70 = F_23 ( V_44 ) + F_39 ( V_44 ) ;
V_2 -> V_18 . V_119 ++ ;
V_2 -> V_18 . V_120 += V_44 -> V_75 - V_70 ;
}
V_97 = V_44 -> V_75 + ( F_36 ( V_44 ) -> V_121 - 1 ) * V_70 ;
} else {
V_69 = V_2 -> V_112 &&
! V_44 -> V_122 &&
! F_36 ( V_44 ) -> V_123 ;
V_70 = F_28 ( V_2 , V_44 , V_69 ) ;
V_97 = F_40 (unsigned int, skb->len, ETH_ZLEN) ;
}
V_87 -> V_97 = V_97 ;
if ( F_15 ( V_44 ) ) {
F_30 ( V_90 -> V_124 , V_44 , V_70 , & V_73 ,
& V_74 ) ;
V_70 += V_66 ;
} else {
memcpy ( V_90 -> V_124 , V_73 , V_70 ) ;
F_29 ( & V_73 , & V_74 , V_70 ) ;
}
V_90 -> V_125 = F_31 ( V_70 ) ;
V_99 = sizeof( * V_10 ) / V_126 ;
V_99 += F_41 ( V_70 - sizeof( V_90 -> V_124 ) ,
V_126 ) ;
V_93 = (struct V_92 * ) V_12 + V_99 ;
V_87 -> V_39 = 0 ;
V_98 = V_74 - V_44 -> V_127 ;
if ( V_98 ) {
V_96 = F_42 ( V_2 -> V_23 , V_73 , V_98 ,
V_29 ) ;
if ( F_43 ( F_44 ( V_2 -> V_23 , V_96 ) ) )
goto V_128;
V_93 -> V_27 = F_45 ( V_96 ) ;
V_93 -> V_129 = V_2 -> V_130 ;
V_93 -> V_131 = F_3 ( V_98 ) ;
F_9 ( V_2 , V_96 , V_98 , V_26 ) ;
V_87 -> V_39 ++ ;
V_93 ++ ;
}
for ( V_33 = 0 ; V_33 < F_36 ( V_44 ) -> V_123 ; V_33 ++ ) {
struct V_132 * V_133 = & F_36 ( V_44 ) -> V_134 [ V_33 ] ;
int V_135 = F_46 ( V_133 ) ;
V_96 = F_47 ( V_2 -> V_23 , V_133 , 0 , V_135 ,
V_29 ) ;
if ( F_43 ( F_44 ( V_2 -> V_23 , V_96 ) ) )
goto V_128;
V_93 -> V_27 = F_45 ( V_96 ) ;
V_93 -> V_129 = V_2 -> V_130 ;
V_93 -> V_131 = F_3 ( V_135 ) ;
F_9 ( V_2 , V_96 , V_135 , V_30 ) ;
V_87 -> V_39 ++ ;
V_93 ++ ;
}
V_99 += V_87 -> V_39 ;
V_12 -> V_14 = F_3 ( ( V_2 -> V_7 << 8 ) | V_94 ) ;
V_12 -> V_16 = F_3 ( ( V_2 -> V_17 << 8 ) | V_99 ) ;
V_2 -> V_36 . V_37 . V_44 [ V_6 ] = V_44 ;
V_87 -> V_136 = F_41 ( V_99 , V_137 ) ;
V_2 -> V_7 += V_87 -> V_136 ;
F_48 ( V_2 -> V_37 , V_87 -> V_97 ) ;
if ( F_43 ( F_36 ( V_44 ) -> V_138 & V_139 ) )
F_36 ( V_44 ) -> V_138 |= V_140 ;
if ( F_43 ( ! F_49 ( V_2 , V_141 ) ) ) {
F_50 ( V_2 -> V_37 ) ;
V_2 -> V_18 . V_142 ++ ;
}
V_2 -> V_18 . V_122 += V_44 -> V_122 ;
if ( ! V_44 -> V_122 || F_51 ( V_2 -> V_37 ) ) {
int V_143 = 0 ;
if ( V_69 && F_52 ( V_144 , & V_2 -> V_145 ) )
V_143 = V_87 -> V_136 << 3 ;
V_12 -> V_20 = V_21 ;
F_4 ( V_2 , & V_10 -> V_13 , V_143 ) ;
}
while ( ( V_6 = ( V_2 -> V_7 & V_5 -> V_8 ) ) > V_2 -> V_146 ) {
V_2 -> V_36 . V_37 . V_44 [ V_6 ] = NULL ;
F_1 ( V_2 , false ) ;
}
if ( V_69 )
V_2 -> V_112 -- ;
V_2 -> V_18 . V_147 ++ ;
V_2 -> V_18 . V_148 += V_97 ;
return V_149 ;
V_128:
V_2 -> V_18 . V_150 ++ ;
F_11 ( V_2 , V_87 -> V_39 ) ;
F_53 ( V_44 ) ;
return V_149 ;
}
T_6 F_54 ( struct V_43 * V_44 , struct V_41 * V_42 )
{
struct V_47 * V_48 = F_13 ( V_42 ) ;
struct V_1 * V_2 = V_48 -> V_151 [ F_55 ( V_44 ) ] ;
return F_33 ( V_2 , V_44 ) ;
}
bool F_56 ( struct V_152 * V_153 , int V_154 )
{
struct V_1 * V_2 ;
T_3 V_155 ;
T_3 V_156 ;
T_1 V_157 ;
T_1 V_158 ;
int V_33 ;
V_2 = F_57 ( V_153 , struct V_1 , V_153 ) ;
if ( F_43 ( ! F_52 ( V_159 , & V_2 -> V_145 ) ) )
return false ;
V_157 = 0 ;
V_156 = 0 ;
V_158 = V_2 -> V_110 ;
V_155 = V_2 -> V_155 ;
for ( V_33 = 0 ; V_33 < V_160 ; V_33 ++ ) {
struct V_161 * V_162 ;
T_1 V_163 ;
bool V_164 ;
V_162 = F_58 ( V_153 ) ;
if ( ! V_162 )
break;
F_59 ( & V_153 -> V_5 ) ;
V_163 = F_60 ( V_162 -> V_163 ) ;
do {
struct V_86 * V_87 ;
struct V_43 * V_44 ;
T_1 V_165 ;
int V_166 ;
V_164 = ( V_158 == V_163 ) ;
V_165 = V_158 & V_2 -> V_5 . V_8 ;
V_44 = V_2 -> V_36 . V_37 . V_44 [ V_165 ] ;
V_87 = & V_2 -> V_36 . V_37 . V_88 [ V_165 ] ;
if ( F_43 ( ! V_44 ) ) {
V_158 ++ ;
continue;
}
if ( F_43 ( F_36 ( V_44 ) -> V_138 &
V_139 ) ) {
struct V_167 V_168 = {} ;
F_61 ( V_2 -> V_169 ,
F_62 ( V_162 ) , & V_168 ) ;
F_63 ( V_44 , & V_168 ) ;
}
for ( V_166 = 0 ; V_166 < V_87 -> V_39 ; V_166 ++ ) {
struct V_24 * V_25 =
F_10 ( V_2 , V_155 ++ ) ;
F_5 ( V_2 -> V_23 , V_25 ) ;
}
V_157 ++ ;
V_156 += V_87 -> V_97 ;
V_158 += V_87 -> V_136 ;
F_64 ( V_44 , V_154 ) ;
} while ( ! V_164 );
}
F_65 ( & V_153 -> V_5 ) ;
F_66 () ;
V_2 -> V_155 = V_155 ;
V_2 -> V_110 = V_158 ;
F_67 ( V_2 -> V_37 , V_157 , V_156 ) ;
if ( F_68 ( V_2 -> V_37 ) &&
F_49 ( V_2 , V_141 ) ) {
F_69 ( V_2 -> V_37 ) ;
V_2 -> V_18 . V_170 ++ ;
}
return ( V_33 == V_160 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_86 * V_87 ;
struct V_43 * V_44 ;
T_1 V_165 ;
int V_33 ;
while ( V_2 -> V_110 != V_2 -> V_7 ) {
V_165 = V_2 -> V_110 & V_2 -> V_5 . V_8 ;
V_44 = V_2 -> V_36 . V_37 . V_44 [ V_165 ] ;
V_87 = & V_2 -> V_36 . V_37 . V_88 [ V_165 ] ;
if ( ! V_44 ) {
V_2 -> V_110 ++ ;
continue;
}
for ( V_33 = 0 ; V_33 < V_87 -> V_39 ; V_33 ++ ) {
struct V_24 * V_25 =
F_10 ( V_2 , V_2 -> V_155 ++ ) ;
F_5 ( V_2 -> V_23 , V_25 ) ;
}
F_53 ( V_44 ) ;
V_2 -> V_110 += V_87 -> V_136 ;
}
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_171 * V_87 ;
struct V_172 * V_173 ;
T_1 V_165 ;
while ( V_2 -> V_110 != V_2 -> V_7 ) {
V_165 = V_2 -> V_110 & V_2 -> V_5 . V_8 ;
V_173 = & V_2 -> V_36 . V_174 . V_173 [ V_165 ] ;
V_87 = & V_2 -> V_36 . V_174 . V_88 [ V_165 ] ;
if ( V_87 -> V_94 == V_15 ) {
V_2 -> V_110 ++ ;
continue;
}
V_2 -> V_110 += V_87 -> V_136 ;
F_72 ( & V_2 -> V_175 -> V_176 , V_173 , false ) ;
}
}
void F_73 ( struct V_1 * V_2 )
{
switch ( V_2 -> type ) {
case V_177 :
F_70 ( V_2 ) ;
break;
case V_178 :
F_71 ( V_2 ) ;
break;
}
}
