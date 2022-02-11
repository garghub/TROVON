static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
switch ( V_4 -> type ) {
case V_5 :
F_2 ( V_2 , V_4 -> V_6 , V_4 -> V_7 , V_8 ) ;
break;
case V_9 :
F_3 ( V_2 , V_4 -> V_6 , V_4 -> V_7 , V_8 ) ;
break;
default:
F_4 ( true , L_1 ) ;
}
}
static inline void F_5 ( struct V_10 * V_11 ,
T_1 V_6 ,
T_2 V_7 ,
enum V_12 V_13 )
{
T_2 V_14 = V_11 -> V_15 & V_11 -> V_16 ;
V_11 -> V_17 . V_18 [ V_14 ] . V_6 = V_6 ;
V_11 -> V_17 . V_18 [ V_14 ] . V_7 = V_7 ;
V_11 -> V_17 . V_18 [ V_14 ] . type = V_13 ;
V_11 -> V_15 ++ ;
}
static inline struct V_3 * F_6 ( struct V_10 * V_11 , T_2 V_14 )
{
return & V_11 -> V_17 . V_18 [ V_14 & V_11 -> V_16 ] ;
}
static void F_7 ( struct V_10 * V_11 , T_3 V_19 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ ) {
struct V_3 * V_20 =
F_6 ( V_11 , -- V_11 -> V_15 ) ;
F_1 ( V_11 -> V_2 , V_20 ) ;
}
}
T_4 F_8 ( struct V_21 * V_22 , struct V_23 * V_24 ,
void * V_25 , T_5 V_26 )
{
struct V_27 * V_28 = F_9 ( V_22 ) ;
int V_29 = V_26 ( V_22 , V_24 ) ;
T_4 V_30 ;
int V_31 = 0 ;
if ( ! F_10 ( V_22 ) )
return V_29 ;
if ( F_11 ( V_24 ) )
V_31 = V_24 -> V_32 >> V_33 ;
V_30 = V_28 -> V_34 . V_35 . V_30 ;
if ( V_29 >= V_30 )
V_29 = F_12 ( V_29 , V_30 ) ;
return V_28 -> V_36 [ V_29 ] [ V_31 ] ;
}
static inline int F_13 ( struct V_23 * V_24 )
{
#define F_14 (ETH_HLEN + VLAN_HLEN)
return F_15 ( F_16 ( V_24 ) , F_14 ) ;
}
static inline int F_17 ( struct V_23 * V_24 )
{
struct V_37 V_38 ;
if ( F_18 ( V_24 ) )
return F_19 ( V_24 ) ;
else if ( F_20 ( V_24 , & V_38 , 0 ) )
return V_38 . V_39 . V_40 ;
else
return F_13 ( V_24 ) ;
}
static inline unsigned int F_21 ( enum V_41 V_42 ,
struct V_23 * V_24 )
{
int V_43 ;
switch ( V_42 ) {
case V_44 :
return 0 ;
case V_45 :
V_43 = F_22 ( V_24 -> V_46 , F_23 ( V_24 ) ) ;
if ( V_43 == V_47 && ! F_11 ( V_24 ) )
V_43 += V_48 ;
return V_43 ;
case V_49 :
if ( F_19 ( V_24 ) )
return F_17 ( V_24 ) ;
case V_50 :
default:
return F_13 ( V_24 ) ;
}
}
static inline void F_24 ( unsigned char * * V_51 ,
unsigned int * V_52 ,
unsigned int V_53 )
{
* V_52 -= V_53 ;
* V_51 += V_53 ;
}
static inline void F_25 ( void * V_54 , struct V_23 * V_24 , T_4 V_55 ,
unsigned char * * V_51 ,
unsigned int * V_52 )
{
struct V_56 * V_57 = (struct V_56 * ) V_54 ;
int V_58 = 2 * V_59 ;
int V_60 = V_55 - V_58 ;
memcpy ( V_57 , * V_51 , V_58 ) ;
F_24 ( V_51 , V_52 , V_58 ) ;
V_57 -> V_61 = V_24 -> V_62 ;
V_57 -> V_63 = F_26 ( F_27 ( V_24 ) ) ;
memcpy ( & V_57 -> V_64 , * V_51 , V_60 ) ;
F_24 ( V_51 , V_52 , V_60 ) ;
}
static inline void
F_28 ( struct V_10 * V_11 , struct V_23 * V_24 , struct V_65 * V_66 )
{
if ( F_29 ( V_24 -> V_67 == V_68 ) ) {
V_66 -> V_69 = V_70 ;
if ( V_24 -> V_71 ) {
V_66 -> V_69 |= V_72 |
V_73 ;
V_11 -> V_74 . V_75 ++ ;
} else {
V_66 -> V_69 |= V_76 ;
}
} else
V_11 -> V_74 . V_77 ++ ;
}
static inline T_4
F_30 ( struct V_10 * V_11 , struct V_23 * V_24 ,
struct V_65 * V_66 , unsigned int * V_78 )
{
T_4 V_55 ;
V_66 -> V_79 = F_26 ( F_31 ( V_24 ) -> V_80 ) ;
if ( V_24 -> V_71 ) {
V_55 = F_32 ( V_24 ) + F_33 ( V_24 ) ;
V_11 -> V_74 . V_81 ++ ;
V_11 -> V_74 . V_82 += V_24 -> V_53 - V_55 ;
} else {
V_55 = F_19 ( V_24 ) + F_34 ( V_24 ) ;
V_11 -> V_74 . V_83 ++ ;
V_11 -> V_74 . V_84 += V_24 -> V_53 - V_55 ;
}
* V_78 = V_24 -> V_53 + ( F_31 ( V_24 ) -> V_85 - 1 ) * V_55 ;
return V_55 ;
}
static inline int
F_35 ( struct V_10 * V_11 , struct V_23 * V_24 ,
unsigned char * V_51 , T_4 V_86 ,
struct V_87 * V_88 )
{
T_1 V_89 = 0 ;
T_3 V_19 = 0 ;
int V_14 ;
if ( V_86 ) {
V_89 = F_36 ( V_11 -> V_2 , V_51 , V_86 ,
V_8 ) ;
if ( F_37 ( F_38 ( V_11 -> V_2 , V_89 ) ) )
return - V_90 ;
V_88 -> V_6 = F_39 ( V_89 ) ;
V_88 -> V_91 = V_11 -> V_92 ;
V_88 -> V_93 = F_40 ( V_86 ) ;
F_5 ( V_11 , V_89 , V_86 , V_5 ) ;
V_19 ++ ;
V_88 ++ ;
}
for ( V_14 = 0 ; V_14 < F_31 ( V_24 ) -> V_94 ; V_14 ++ ) {
struct V_95 * V_96 = & F_31 ( V_24 ) -> V_97 [ V_14 ] ;
int V_98 = F_41 ( V_96 ) ;
V_89 = F_42 ( V_11 -> V_2 , V_96 , 0 , V_98 ,
V_8 ) ;
if ( F_37 ( F_38 ( V_11 -> V_2 , V_89 ) ) )
return - V_90 ;
V_88 -> V_6 = F_39 ( V_89 ) ;
V_88 -> V_91 = V_11 -> V_92 ;
V_88 -> V_93 = F_40 ( V_98 ) ;
F_5 ( V_11 , V_89 , V_98 , V_9 ) ;
V_19 ++ ;
V_88 ++ ;
}
return V_19 ;
}
static inline void
F_43 ( struct V_10 * V_11 , struct V_23 * V_24 ,
T_3 V_99 , T_4 V_100 , T_2 V_78 , T_3 V_19 ,
struct V_101 * V_102 , struct V_103 * V_104 )
{
struct V_105 * V_106 = & V_11 -> V_106 ;
T_4 V_107 ;
V_102 -> V_78 = V_78 ;
V_102 -> V_19 = V_19 ;
V_102 -> V_108 = F_44 ( V_100 , V_109 ) ;
V_102 -> V_24 = V_24 ;
V_104 -> V_110 = F_40 ( ( V_11 -> V_111 << 8 ) | V_99 ) ;
V_104 -> V_112 = F_40 ( ( V_11 -> V_113 << 8 ) | V_100 ) ;
F_45 ( V_11 -> V_114 , V_78 ) ;
if ( F_37 ( F_31 ( V_24 ) -> V_115 & V_116 ) )
F_31 ( V_24 ) -> V_115 |= V_117 ;
V_11 -> V_111 += V_102 -> V_108 ;
if ( F_37 ( ! F_46 ( V_106 , V_11 -> V_118 , V_11 -> V_111 , V_119 ) ) ) {
F_47 ( V_11 -> V_114 ) ;
V_11 -> V_74 . V_120 ++ ;
}
if ( ! V_24 -> V_121 || F_48 ( V_11 -> V_114 ) )
F_49 ( V_106 , V_11 -> V_111 , V_11 -> V_122 , V_104 ) ;
while ( ( V_107 = ( V_11 -> V_111 & V_106 -> V_123 ) ) > V_11 -> V_124 ) {
V_11 -> V_17 . V_125 [ V_107 ] . V_24 = NULL ;
F_50 ( V_106 , V_11 -> V_113 , & V_11 -> V_111 ) ;
V_11 -> V_74 . V_126 ++ ;
}
}
static T_6 F_51 ( struct V_10 * V_11 , struct V_23 * V_24 )
{
struct V_105 * V_106 = & V_11 -> V_106 ;
T_4 V_107 = V_11 -> V_111 & V_106 -> V_123 ;
struct V_127 * V_128 = F_52 ( V_106 , V_107 ) ;
struct V_101 * V_102 = & V_11 -> V_17 . V_125 [ V_107 ] ;
struct V_103 * V_104 = & V_128 -> V_129 ;
struct V_65 * V_66 = & V_128 -> V_130 ;
unsigned char * V_51 = V_24 -> V_46 ;
unsigned int V_52 = V_24 -> V_53 ;
T_3 V_99 = V_131 ;
unsigned int V_78 ;
int V_19 ;
T_4 V_86 ;
T_4 V_100 ;
T_4 V_55 ;
memset ( V_128 , 0 , sizeof( * V_128 ) ) ;
F_28 ( V_11 , V_24 , V_66 ) ;
if ( F_53 ( V_24 ) ) {
V_99 = V_132 ;
V_55 = F_30 ( V_11 , V_24 , V_66 , & V_78 ) ;
V_11 -> V_74 . V_133 += F_31 ( V_24 ) -> V_85 ;
} else {
V_55 = F_21 ( V_11 -> V_134 , V_24 ) ;
V_78 = F_54 (unsigned int, skb->len, ETH_ZLEN) ;
V_11 -> V_74 . V_133 ++ ;
}
V_11 -> V_74 . V_135 += V_78 ;
V_11 -> V_74 . V_121 += V_24 -> V_121 ;
V_100 = sizeof( * V_128 ) / V_136 ;
if ( V_55 ) {
if ( F_11 ( V_24 ) ) {
F_25 ( V_66 -> V_137 . V_54 , V_24 , V_55 , & V_51 , & V_52 ) ;
V_55 += V_48 ;
} else {
memcpy ( V_66 -> V_137 . V_54 , V_51 , V_55 ) ;
F_24 ( & V_51 , & V_52 , V_55 ) ;
}
V_66 -> V_137 . V_138 = F_26 ( V_55 ) ;
V_100 += F_44 ( V_55 - sizeof( V_66 -> V_137 . V_54 ) , V_136 ) ;
} else if ( F_11 ( V_24 ) ) {
V_66 -> V_139 . type = F_26 ( V_140 ) ;
V_66 -> V_139 . V_32 = F_26 ( F_27 ( V_24 ) ) ;
}
V_86 = V_52 - V_24 -> V_141 ;
V_19 = F_35 ( V_11 , V_24 , V_51 , V_86 ,
(struct V_87 * ) V_104 + V_100 ) ;
if ( F_37 ( V_19 < 0 ) )
goto V_142;
F_43 ( V_11 , V_24 , V_99 , V_100 + V_19 ,
V_78 , V_19 , V_102 , V_104 ) ;
return V_143 ;
V_142:
V_11 -> V_74 . V_144 ++ ;
F_7 ( V_11 , V_102 -> V_19 ) ;
F_55 ( V_24 ) ;
return V_143 ;
}
T_6 F_56 ( struct V_23 * V_24 , struct V_21 * V_22 )
{
struct V_27 * V_28 = F_9 ( V_22 ) ;
struct V_10 * V_11 = V_28 -> V_145 [ F_57 ( V_24 ) ] ;
return F_51 ( V_11 , V_24 ) ;
}
bool F_58 ( struct V_146 * V_147 , int V_148 )
{
struct V_10 * V_11 ;
T_2 V_149 ;
T_2 V_150 ;
T_4 V_151 ;
T_4 V_152 ;
int V_14 ;
V_11 = F_59 ( V_147 , struct V_10 , V_147 ) ;
if ( F_37 ( ! F_60 ( V_153 , & V_11 -> V_154 ) ) )
return false ;
V_151 = 0 ;
V_150 = 0 ;
V_152 = V_11 -> V_118 ;
V_149 = V_11 -> V_149 ;
for ( V_14 = 0 ; V_14 < V_155 ; V_14 ++ ) {
struct V_156 * V_157 ;
T_4 V_158 ;
bool V_159 ;
V_157 = F_61 ( V_147 ) ;
if ( ! V_157 )
break;
F_62 ( & V_147 -> V_106 ) ;
V_158 = F_63 ( V_157 -> V_158 ) ;
do {
struct V_101 * V_102 ;
struct V_23 * V_24 ;
T_4 V_160 ;
int V_161 ;
V_159 = ( V_152 == V_158 ) ;
V_160 = V_152 & V_11 -> V_106 . V_123 ;
V_102 = & V_11 -> V_17 . V_125 [ V_160 ] ;
V_24 = V_102 -> V_24 ;
if ( F_37 ( ! V_24 ) ) {
V_152 ++ ;
continue;
}
if ( F_37 ( F_31 ( V_24 ) -> V_115 &
V_116 ) ) {
struct V_162 V_163 = {} ;
F_64 ( V_11 -> V_164 ,
F_65 ( V_157 ) , & V_163 ) ;
F_66 ( V_24 , & V_163 ) ;
}
for ( V_161 = 0 ; V_161 < V_102 -> V_19 ; V_161 ++ ) {
struct V_3 * V_4 =
F_6 ( V_11 , V_149 ++ ) ;
F_1 ( V_11 -> V_2 , V_4 ) ;
}
V_151 ++ ;
V_150 += V_102 -> V_78 ;
V_152 += V_102 -> V_108 ;
F_67 ( V_24 , V_148 ) ;
} while ( ! V_159 );
}
F_68 ( & V_147 -> V_106 ) ;
F_69 () ;
V_11 -> V_149 = V_149 ;
V_11 -> V_118 = V_152 ;
F_70 ( V_11 -> V_114 , V_151 , V_150 ) ;
if ( F_71 ( V_11 -> V_114 ) &&
F_46 ( & V_11 -> V_106 , V_11 -> V_118 , V_11 -> V_111 , V_119 ) ) {
F_72 ( V_11 -> V_114 ) ;
V_11 -> V_74 . V_165 ++ ;
}
return ( V_14 == V_155 ) ;
}
void F_73 ( struct V_10 * V_11 )
{
struct V_101 * V_102 ;
struct V_23 * V_24 ;
T_4 V_160 ;
int V_14 ;
while ( V_11 -> V_118 != V_11 -> V_111 ) {
V_160 = V_11 -> V_118 & V_11 -> V_106 . V_123 ;
V_102 = & V_11 -> V_17 . V_125 [ V_160 ] ;
V_24 = V_102 -> V_24 ;
if ( ! V_24 ) {
V_11 -> V_118 ++ ;
continue;
}
for ( V_14 = 0 ; V_14 < V_102 -> V_19 ; V_14 ++ ) {
struct V_3 * V_4 =
F_6 ( V_11 , V_11 -> V_149 ++ ) ;
F_1 ( V_11 -> V_2 , V_4 ) ;
}
F_55 ( V_24 ) ;
V_11 -> V_118 += V_102 -> V_108 ;
}
}
static inline void
F_74 ( struct V_166 * V_167 , T_2 V_168 , T_2 V_169 ,
struct V_170 * V_88 )
{
memcpy ( & V_88 -> V_167 , V_167 , sizeof( struct V_166 ) ) ;
V_88 -> V_167 . V_171 = F_40 ( V_168 | V_172 ) ;
V_88 -> V_167 . V_173 . V_174 . V_174 = F_40 ( V_169 ) ;
}
T_6 F_75 ( struct V_10 * V_11 , struct V_23 * V_24 ,
struct V_166 * V_167 , T_2 V_168 , T_2 V_169 )
{
struct V_105 * V_106 = & V_11 -> V_106 ;
T_4 V_107 = V_11 -> V_111 & V_106 -> V_123 ;
struct V_175 * V_128 = F_52 ( V_106 , V_107 ) ;
struct V_101 * V_102 = & V_11 -> V_17 . V_125 [ V_107 ] ;
struct V_103 * V_104 = & V_128 -> V_129 ;
struct V_170 * V_176 = & V_128 -> V_176 ;
struct V_65 * V_66 = & V_128 -> V_130 ;
unsigned char * V_51 = V_24 -> V_46 ;
unsigned int V_52 = V_24 -> V_53 ;
T_3 V_99 = V_131 ;
unsigned int V_78 ;
int V_19 ;
T_4 V_86 ;
T_4 V_100 ;
T_4 V_55 ;
memset ( V_128 , 0 , sizeof( * V_128 ) ) ;
F_74 ( V_167 , V_168 , V_169 , V_176 ) ;
F_28 ( V_11 , V_24 , V_66 ) ;
if ( F_53 ( V_24 ) ) {
V_99 = V_132 ;
V_55 = F_30 ( V_11 , V_24 , V_66 , & V_78 ) ;
} else {
V_55 = F_21 ( V_11 -> V_134 , V_24 ) ;
V_78 = F_54 (unsigned int, skb->len, ETH_ZLEN) ;
}
V_100 = sizeof( * V_128 ) / V_136 ;
if ( V_55 ) {
memcpy ( V_66 -> V_137 . V_54 , V_51 , V_55 ) ;
F_24 ( & V_51 , & V_52 , V_55 ) ;
V_66 -> V_137 . V_138 = F_26 ( V_55 ) ;
V_100 += F_44 ( V_55 - sizeof( V_66 -> V_137 . V_54 ) , V_136 ) ;
}
V_86 = V_52 - V_24 -> V_141 ;
V_19 = F_35 ( V_11 , V_24 , V_51 , V_86 ,
(struct V_87 * ) V_104 + V_100 ) ;
if ( F_37 ( V_19 < 0 ) )
goto V_142;
F_43 ( V_11 , V_24 , V_99 , V_100 + V_19 ,
V_78 , V_19 , V_102 , V_104 ) ;
return V_143 ;
V_142:
V_11 -> V_74 . V_144 ++ ;
F_7 ( V_11 , V_102 -> V_19 ) ;
F_55 ( V_24 ) ;
return V_143 ;
}
