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
return 0 ;
case V_64 :
V_62 = F_26 ( V_44 -> V_65 , F_27 ( V_44 ) ) ;
if ( V_62 == V_66 && ! F_15 ( V_44 ) )
V_62 += V_67 ;
return V_62 ;
case V_68 :
if ( F_23 ( V_44 ) )
return F_21 ( V_44 ) ;
case V_69 :
default:
return F_17 ( V_44 ) ;
}
}
static inline T_1 F_28 ( struct V_1 * V_2 ,
struct V_43 * V_44 , bool V_70 )
{
if ( V_70 ) {
T_1 V_71 = F_27 ( V_44 ) ;
if ( F_15 ( V_44 ) )
V_71 += V_67 ;
if ( V_71 <= V_2 -> V_72 )
return F_27 ( V_44 ) ;
}
return F_25 ( V_2 -> V_73 , V_44 ) ;
}
static inline void F_29 ( unsigned char * * V_74 ,
unsigned int * V_75 ,
unsigned int V_76 )
{
* V_75 -= V_76 ;
* V_74 += V_76 ;
}
static inline void F_30 ( void * V_77 , struct V_43 * V_44 , T_1 V_71 ,
unsigned char * * V_74 ,
unsigned int * V_75 )
{
struct V_78 * V_79 = (struct V_78 * ) V_77 ;
int V_80 = 2 * V_81 ;
int V_82 = V_71 - V_80 ;
memcpy ( V_79 , * V_74 , V_80 ) ;
F_29 ( V_74 , V_75 , V_80 ) ;
V_79 -> V_83 = V_44 -> V_84 ;
V_79 -> V_85 = F_31 ( F_32 ( V_44 ) ) ;
memcpy ( & V_79 -> V_86 , * V_74 , V_82 ) ;
F_29 ( V_74 , V_75 , V_82 ) ;
}
static T_6 F_33 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
T_1 V_6 = V_2 -> V_7 & V_5 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_5 , V_6 ) ;
struct V_87 * V_88 = & V_2 -> V_36 . V_37 . V_89 [ V_6 ] ;
struct V_11 * V_12 = & V_10 -> V_13 ;
struct V_90 * V_91 = & V_10 -> V_92 ;
struct V_93 * V_94 ;
unsigned char * V_74 = V_44 -> V_65 ;
unsigned int V_75 = V_44 -> V_76 ;
T_4 V_95 = V_96 ;
T_2 V_97 = 0 ;
unsigned int V_98 ;
bool V_70 = false ;
T_1 V_99 ;
T_1 V_100 ;
T_1 V_71 ;
int V_33 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
if ( F_34 ( V_44 -> V_101 == V_102 ) ) {
V_91 -> V_103 = V_104 ;
if ( V_44 -> V_105 ) {
V_91 -> V_103 |= V_106 |
V_107 ;
V_2 -> V_18 . V_108 ++ ;
} else {
V_91 -> V_103 |= V_109 ;
}
} else
V_2 -> V_18 . V_110 ++ ;
if ( V_2 -> V_111 != V_2 -> V_112 ) {
V_2 -> V_112 = V_2 -> V_111 ;
V_2 -> V_113 = ( V_2 -> V_111 == V_2 -> V_7 ) ? V_114 : 0 ;
}
if ( F_35 ( V_44 ) ) {
V_91 -> V_115 = F_31 ( F_36 ( V_44 ) -> V_116 ) ;
V_95 = V_117 ;
if ( V_44 -> V_105 ) {
V_71 = F_37 ( V_44 ) + F_38 ( V_44 ) ;
V_2 -> V_18 . V_118 ++ ;
V_2 -> V_18 . V_119 += V_44 -> V_76 - V_71 ;
} else {
V_71 = F_23 ( V_44 ) + F_39 ( V_44 ) ;
V_2 -> V_18 . V_120 ++ ;
V_2 -> V_18 . V_121 += V_44 -> V_76 - V_71 ;
}
V_2 -> V_18 . V_122 += F_36 ( V_44 ) -> V_123 ;
V_98 = V_44 -> V_76 + ( F_36 ( V_44 ) -> V_123 - 1 ) * V_71 ;
} else {
V_70 = V_2 -> V_113 &&
! V_44 -> V_124 &&
! F_36 ( V_44 ) -> V_125 ;
V_71 = F_28 ( V_2 , V_44 , V_70 ) ;
V_2 -> V_18 . V_122 ++ ;
V_98 = F_40 (unsigned int, skb->len, ETH_ZLEN) ;
}
V_2 -> V_18 . V_126 += V_98 ;
V_88 -> V_98 = V_98 ;
V_100 = sizeof( * V_10 ) / V_127 ;
if ( V_71 ) {
if ( F_15 ( V_44 ) ) {
F_30 ( V_91 -> V_128 . V_77 , V_44 , V_71 , & V_74 , & V_75 ) ;
V_71 += V_67 ;
} else {
memcpy ( V_91 -> V_128 . V_77 , V_74 , V_71 ) ;
F_29 ( & V_74 , & V_75 , V_71 ) ;
}
V_91 -> V_128 . V_129 = F_31 ( V_71 ) ;
V_100 += F_41 ( V_71 - sizeof( V_91 -> V_128 . V_77 ) , V_127 ) ;
} else if ( F_15 ( V_44 ) ) {
V_91 -> V_130 . type = F_31 ( V_131 ) ;
V_91 -> V_130 . V_51 = F_31 ( F_32 ( V_44 ) ) ;
}
V_94 = (struct V_93 * ) V_12 + V_100 ;
V_88 -> V_39 = 0 ;
V_99 = V_75 - V_44 -> V_132 ;
if ( V_99 ) {
V_97 = F_42 ( V_2 -> V_23 , V_74 , V_99 ,
V_29 ) ;
if ( F_43 ( F_44 ( V_2 -> V_23 , V_97 ) ) )
goto V_133;
V_94 -> V_27 = F_45 ( V_97 ) ;
V_94 -> V_134 = V_2 -> V_135 ;
V_94 -> V_136 = F_3 ( V_99 ) ;
F_9 ( V_2 , V_97 , V_99 , V_26 ) ;
V_88 -> V_39 ++ ;
V_94 ++ ;
}
for ( V_33 = 0 ; V_33 < F_36 ( V_44 ) -> V_125 ; V_33 ++ ) {
struct V_137 * V_138 = & F_36 ( V_44 ) -> V_139 [ V_33 ] ;
int V_140 = F_46 ( V_138 ) ;
V_97 = F_47 ( V_2 -> V_23 , V_138 , 0 , V_140 ,
V_29 ) ;
if ( F_43 ( F_44 ( V_2 -> V_23 , V_97 ) ) )
goto V_133;
V_94 -> V_27 = F_45 ( V_97 ) ;
V_94 -> V_134 = V_2 -> V_135 ;
V_94 -> V_136 = F_3 ( V_140 ) ;
F_9 ( V_2 , V_97 , V_140 , V_30 ) ;
V_88 -> V_39 ++ ;
V_94 ++ ;
}
V_100 += V_88 -> V_39 ;
V_12 -> V_14 = F_3 ( ( V_2 -> V_7 << 8 ) | V_95 ) ;
V_12 -> V_16 = F_3 ( ( V_2 -> V_17 << 8 ) | V_100 ) ;
V_2 -> V_36 . V_37 . V_44 [ V_6 ] = V_44 ;
V_88 -> V_141 = F_41 ( V_100 , V_142 ) ;
V_2 -> V_7 += V_88 -> V_141 ;
F_48 ( V_2 -> V_37 , V_88 -> V_98 ) ;
if ( F_43 ( F_36 ( V_44 ) -> V_143 & V_144 ) )
F_36 ( V_44 ) -> V_143 |= V_145 ;
if ( F_43 ( ! F_49 ( V_2 , V_146 ) ) ) {
F_50 ( V_2 -> V_37 ) ;
V_2 -> V_18 . V_147 ++ ;
}
V_2 -> V_18 . V_124 += V_44 -> V_124 ;
if ( ! V_44 -> V_124 || F_51 ( V_2 -> V_37 ) ) {
int V_148 = 0 ;
if ( V_70 && F_52 ( V_149 , & V_2 -> V_150 ) )
V_148 = V_88 -> V_141 << 3 ;
V_12 -> V_20 = V_21 ;
F_4 ( V_2 , & V_10 -> V_13 , V_148 ) ;
}
while ( ( V_6 = ( V_2 -> V_7 & V_5 -> V_8 ) ) > V_2 -> V_151 ) {
V_2 -> V_36 . V_37 . V_44 [ V_6 ] = NULL ;
F_1 ( V_2 , false ) ;
}
if ( V_70 )
V_2 -> V_113 -- ;
return V_152 ;
V_133:
V_2 -> V_18 . V_153 ++ ;
F_11 ( V_2 , V_88 -> V_39 ) ;
F_53 ( V_44 ) ;
return V_152 ;
}
T_6 F_54 ( struct V_43 * V_44 , struct V_41 * V_42 )
{
struct V_47 * V_48 = F_13 ( V_42 ) ;
struct V_1 * V_2 = V_48 -> V_154 [ F_55 ( V_44 ) ] ;
return F_33 ( V_2 , V_44 ) ;
}
bool F_56 ( struct V_155 * V_156 , int V_157 )
{
struct V_1 * V_2 ;
T_3 V_158 ;
T_3 V_159 ;
T_1 V_160 ;
T_1 V_161 ;
int V_33 ;
V_2 = F_57 ( V_156 , struct V_1 , V_156 ) ;
if ( F_43 ( ! F_52 ( V_162 , & V_2 -> V_150 ) ) )
return false ;
V_160 = 0 ;
V_159 = 0 ;
V_161 = V_2 -> V_111 ;
V_158 = V_2 -> V_158 ;
for ( V_33 = 0 ; V_33 < V_163 ; V_33 ++ ) {
struct V_164 * V_165 ;
T_1 V_166 ;
bool V_167 ;
V_165 = F_58 ( V_156 ) ;
if ( ! V_165 )
break;
F_59 ( & V_156 -> V_5 ) ;
V_166 = F_60 ( V_165 -> V_166 ) ;
do {
struct V_87 * V_88 ;
struct V_43 * V_44 ;
T_1 V_168 ;
int V_169 ;
V_167 = ( V_161 == V_166 ) ;
V_168 = V_161 & V_2 -> V_5 . V_8 ;
V_44 = V_2 -> V_36 . V_37 . V_44 [ V_168 ] ;
V_88 = & V_2 -> V_36 . V_37 . V_89 [ V_168 ] ;
if ( F_43 ( ! V_44 ) ) {
V_161 ++ ;
continue;
}
if ( F_43 ( F_36 ( V_44 ) -> V_143 &
V_144 ) ) {
struct V_170 V_171 = {} ;
F_61 ( V_2 -> V_172 ,
F_62 ( V_165 ) , & V_171 ) ;
F_63 ( V_44 , & V_171 ) ;
}
for ( V_169 = 0 ; V_169 < V_88 -> V_39 ; V_169 ++ ) {
struct V_24 * V_25 =
F_10 ( V_2 , V_158 ++ ) ;
F_5 ( V_2 -> V_23 , V_25 ) ;
}
V_160 ++ ;
V_159 += V_88 -> V_98 ;
V_161 += V_88 -> V_141 ;
F_64 ( V_44 , V_157 ) ;
} while ( ! V_167 );
}
F_65 ( & V_156 -> V_5 ) ;
F_66 () ;
V_2 -> V_158 = V_158 ;
V_2 -> V_111 = V_161 ;
F_67 ( V_2 -> V_37 , V_160 , V_159 ) ;
if ( F_68 ( V_2 -> V_37 ) &&
F_49 ( V_2 , V_146 ) ) {
F_69 ( V_2 -> V_37 ) ;
V_2 -> V_18 . V_173 ++ ;
}
return ( V_33 == V_163 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_87 * V_88 ;
struct V_43 * V_44 ;
T_1 V_168 ;
int V_33 ;
while ( V_2 -> V_111 != V_2 -> V_7 ) {
V_168 = V_2 -> V_111 & V_2 -> V_5 . V_8 ;
V_44 = V_2 -> V_36 . V_37 . V_44 [ V_168 ] ;
V_88 = & V_2 -> V_36 . V_37 . V_89 [ V_168 ] ;
if ( ! V_44 ) {
V_2 -> V_111 ++ ;
continue;
}
for ( V_33 = 0 ; V_33 < V_88 -> V_39 ; V_33 ++ ) {
struct V_24 * V_25 =
F_10 ( V_2 , V_2 -> V_158 ++ ) ;
F_5 ( V_2 -> V_23 , V_25 ) ;
}
F_53 ( V_44 ) ;
V_2 -> V_111 += V_88 -> V_141 ;
}
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_174 * V_88 ;
struct V_175 * V_176 ;
T_1 V_168 ;
while ( V_2 -> V_111 != V_2 -> V_7 ) {
V_168 = V_2 -> V_111 & V_2 -> V_5 . V_8 ;
V_176 = & V_2 -> V_36 . V_177 . V_176 [ V_168 ] ;
V_88 = & V_2 -> V_36 . V_177 . V_89 [ V_168 ] ;
if ( V_88 -> V_95 == V_15 ) {
V_2 -> V_111 ++ ;
continue;
}
V_2 -> V_111 += V_88 -> V_141 ;
F_72 ( & V_2 -> V_178 -> V_179 , V_176 , false ) ;
}
}
void F_73 ( struct V_1 * V_2 )
{
switch ( V_2 -> type ) {
case V_180 :
F_70 ( V_2 ) ;
break;
case V_181 :
F_71 ( V_2 ) ;
break;
}
}
