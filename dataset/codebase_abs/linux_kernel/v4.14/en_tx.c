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
static inline T_4 F_21 ( enum V_41 V_42 ,
struct V_23 * V_24 )
{
T_4 V_43 ;
switch ( V_42 ) {
case V_44 :
return 0 ;
case V_45 :
V_43 = F_22 ( V_24 -> V_46 , F_23 ( V_24 ) ) ;
if ( V_43 == V_47 && ! F_11 ( V_24 ) )
V_43 += V_48 ;
break;
case V_49 :
if ( F_19 ( V_24 ) ) {
V_43 = F_17 ( V_24 ) ;
break;
}
case V_50 :
default:
V_43 = F_13 ( V_24 ) ;
}
return F_24 ( T_4 , V_43 , V_24 -> V_51 ) ;
}
static inline void F_25 ( unsigned char * * V_52 ,
unsigned int * V_53 ,
unsigned int V_51 )
{
* V_53 -= V_51 ;
* V_52 += V_51 ;
}
static inline void F_26 ( void * V_54 , struct V_23 * V_24 , T_4 V_55 ,
unsigned char * * V_52 ,
unsigned int * V_53 )
{
struct V_56 * V_57 = (struct V_56 * ) V_54 ;
int V_58 = 2 * V_59 ;
int V_60 = V_55 - V_58 ;
memcpy ( V_57 , * V_52 , V_58 ) ;
F_25 ( V_52 , V_53 , V_58 ) ;
V_57 -> V_61 = V_24 -> V_62 ;
V_57 -> V_63 = F_27 ( F_28 ( V_24 ) ) ;
memcpy ( & V_57 -> V_64 , * V_52 , V_60 ) ;
F_25 ( V_52 , V_53 , V_60 ) ;
}
static inline void
F_29 ( struct V_10 * V_11 , struct V_23 * V_24 , struct V_65 * V_66 )
{
if ( F_30 ( V_24 -> V_67 == V_68 ) ) {
V_66 -> V_69 = V_70 ;
if ( V_24 -> V_71 ) {
V_66 -> V_69 |= V_72 |
V_73 ;
V_11 -> V_74 . V_75 ++ ;
} else {
V_66 -> V_69 |= V_76 ;
V_11 -> V_74 . V_77 ++ ;
}
} else
V_11 -> V_74 . V_78 ++ ;
}
static inline T_4
F_31 ( struct V_10 * V_11 , struct V_23 * V_24 ,
struct V_65 * V_66 , unsigned int * V_79 )
{
T_4 V_55 ;
V_66 -> V_80 = F_27 ( F_32 ( V_24 ) -> V_81 ) ;
if ( V_24 -> V_71 ) {
V_55 = F_33 ( V_24 ) + F_34 ( V_24 ) ;
V_11 -> V_74 . V_82 ++ ;
V_11 -> V_74 . V_83 += V_24 -> V_51 - V_55 ;
} else {
V_55 = F_19 ( V_24 ) + F_35 ( V_24 ) ;
V_11 -> V_74 . V_84 ++ ;
V_11 -> V_74 . V_85 += V_24 -> V_51 - V_55 ;
}
* V_79 = V_24 -> V_51 + ( F_32 ( V_24 ) -> V_86 - 1 ) * V_55 ;
return V_55 ;
}
static inline int
F_36 ( struct V_10 * V_11 , struct V_23 * V_24 ,
unsigned char * V_52 , T_4 V_87 ,
struct V_88 * V_89 )
{
T_1 V_90 = 0 ;
T_3 V_19 = 0 ;
int V_14 ;
if ( V_87 ) {
V_90 = F_37 ( V_11 -> V_2 , V_52 , V_87 ,
V_8 ) ;
if ( F_38 ( F_39 ( V_11 -> V_2 , V_90 ) ) )
return - V_91 ;
V_89 -> V_6 = F_40 ( V_90 ) ;
V_89 -> V_92 = V_11 -> V_93 ;
V_89 -> V_94 = F_41 ( V_87 ) ;
F_5 ( V_11 , V_90 , V_87 , V_5 ) ;
V_19 ++ ;
V_89 ++ ;
}
for ( V_14 = 0 ; V_14 < F_32 ( V_24 ) -> V_95 ; V_14 ++ ) {
struct V_96 * V_97 = & F_32 ( V_24 ) -> V_98 [ V_14 ] ;
int V_99 = F_42 ( V_97 ) ;
V_90 = F_43 ( V_11 -> V_2 , V_97 , 0 , V_99 ,
V_8 ) ;
if ( F_38 ( F_39 ( V_11 -> V_2 , V_90 ) ) )
return - V_91 ;
V_89 -> V_6 = F_40 ( V_90 ) ;
V_89 -> V_92 = V_11 -> V_93 ;
V_89 -> V_94 = F_41 ( V_99 ) ;
F_5 ( V_11 , V_90 , V_99 , V_9 ) ;
V_19 ++ ;
V_89 ++ ;
}
return V_19 ;
}
static inline void
F_44 ( struct V_10 * V_11 , struct V_23 * V_24 ,
T_3 V_100 , T_4 V_101 , T_2 V_79 , T_3 V_19 ,
struct V_102 * V_103 , struct V_104 * V_105 )
{
struct V_106 * V_107 = & V_11 -> V_107 ;
T_4 V_108 ;
V_103 -> V_79 = V_79 ;
V_103 -> V_19 = V_19 ;
V_103 -> V_109 = F_45 ( V_101 , V_110 ) ;
V_103 -> V_24 = V_24 ;
V_105 -> V_111 = F_41 ( ( V_11 -> V_112 << 8 ) | V_100 ) ;
V_105 -> V_113 = F_41 ( ( V_11 -> V_114 << 8 ) | V_101 ) ;
F_46 ( V_11 -> V_115 , V_79 ) ;
if ( F_38 ( F_32 ( V_24 ) -> V_116 & V_117 ) )
F_32 ( V_24 ) -> V_116 |= V_118 ;
V_11 -> V_112 += V_103 -> V_109 ;
if ( F_38 ( ! F_47 ( V_107 , V_11 -> V_119 , V_11 -> V_112 , V_120 ) ) ) {
F_48 ( V_11 -> V_115 ) ;
V_11 -> V_74 . V_121 ++ ;
}
if ( ! V_24 -> V_122 || F_49 ( V_11 -> V_115 ) )
F_50 ( V_107 , V_11 -> V_112 , V_11 -> V_123 , V_105 ) ;
while ( ( V_108 = ( V_11 -> V_112 & V_107 -> V_124 ) ) > V_11 -> V_125 ) {
V_11 -> V_17 . V_126 [ V_108 ] . V_24 = NULL ;
F_51 ( V_107 , V_11 -> V_114 , & V_11 -> V_112 ) ;
V_11 -> V_74 . V_127 ++ ;
}
}
static T_6 F_52 ( struct V_10 * V_11 , struct V_23 * V_24 ,
struct V_128 * V_129 , T_4 V_108 )
{
struct V_102 * V_103 = & V_11 -> V_17 . V_126 [ V_108 ] ;
struct V_104 * V_105 = & V_129 -> V_130 ;
struct V_65 * V_66 = & V_129 -> V_131 ;
unsigned char * V_52 = V_24 -> V_46 ;
unsigned int V_53 = V_24 -> V_51 ;
T_3 V_100 = V_132 ;
unsigned int V_79 ;
int V_19 ;
T_4 V_87 ;
T_4 V_101 ;
T_4 V_55 ;
F_29 ( V_11 , V_24 , V_66 ) ;
if ( F_53 ( V_24 ) ) {
V_100 = V_133 ;
V_55 = F_31 ( V_11 , V_24 , V_66 , & V_79 ) ;
V_11 -> V_74 . V_134 += F_32 ( V_24 ) -> V_86 ;
} else {
V_55 = F_21 ( V_11 -> V_135 , V_24 ) ;
V_79 = F_54 (unsigned int, skb->len, ETH_ZLEN) ;
V_11 -> V_74 . V_134 ++ ;
}
V_11 -> V_74 . V_136 += V_79 ;
V_11 -> V_74 . V_122 += V_24 -> V_122 ;
V_101 = sizeof( * V_129 ) / V_137 ;
if ( V_55 ) {
if ( F_11 ( V_24 ) ) {
F_26 ( V_66 -> V_138 . V_54 , V_24 , V_55 , & V_52 , & V_53 ) ;
V_55 += V_48 ;
} else {
memcpy ( V_66 -> V_138 . V_54 , V_52 , V_55 ) ;
F_25 ( & V_52 , & V_53 , V_55 ) ;
}
V_66 -> V_138 . V_139 = F_27 ( V_55 ) ;
V_101 += F_45 ( V_55 - sizeof( V_66 -> V_138 . V_54 ) , V_137 ) ;
} else if ( F_11 ( V_24 ) ) {
V_66 -> V_140 . type = F_27 ( V_141 ) ;
V_66 -> V_140 . V_32 = F_27 ( F_28 ( V_24 ) ) ;
}
V_87 = V_53 - V_24 -> V_142 ;
V_19 = F_36 ( V_11 , V_24 , V_52 , V_87 ,
(struct V_88 * ) V_105 + V_101 ) ;
if ( F_38 ( V_19 < 0 ) )
goto V_143;
F_44 ( V_11 , V_24 , V_100 , V_101 + V_19 ,
V_79 , V_19 , V_103 , V_105 ) ;
return V_144 ;
V_143:
V_11 -> V_74 . V_145 ++ ;
F_7 ( V_11 , V_103 -> V_19 ) ;
F_55 ( V_24 ) ;
return V_144 ;
}
T_6 F_56 ( struct V_23 * V_24 , struct V_21 * V_22 )
{
struct V_27 * V_28 = F_9 ( V_22 ) ;
struct V_10 * V_11 = V_28 -> V_146 [ F_57 ( V_24 ) ] ;
struct V_106 * V_107 = & V_11 -> V_107 ;
T_4 V_108 = V_11 -> V_112 & V_107 -> V_124 ;
struct V_128 * V_129 = F_58 ( V_107 , V_108 ) ;
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
#ifdef F_59
if ( V_11 -> V_147 & F_60 ( V_148 ) ) {
V_24 = F_61 ( V_22 , V_129 , V_24 ) ;
if ( F_38 ( ! V_24 ) )
return V_144 ;
}
#endif
return F_52 ( V_11 , V_24 , V_129 , V_108 ) ;
}
bool F_62 ( struct V_149 * V_150 , int V_151 )
{
struct V_10 * V_11 ;
struct V_152 * V_153 ;
T_2 V_154 ;
T_2 V_155 ;
T_4 V_156 ;
T_4 V_157 ;
int V_14 ;
V_11 = F_63 ( V_150 , struct V_10 , V_150 ) ;
if ( F_38 ( ! F_64 ( V_11 -> V_147 , V_158 ) ) )
return false ;
V_153 = F_65 ( & V_150 -> V_107 ) ;
if ( ! V_153 )
return false ;
V_156 = 0 ;
V_155 = 0 ;
V_157 = V_11 -> V_119 ;
V_154 = V_11 -> V_154 ;
V_14 = 0 ;
do {
T_4 V_159 ;
bool V_160 ;
F_66 ( & V_150 -> V_107 ) ;
V_159 = F_67 ( V_153 -> V_159 ) ;
do {
struct V_102 * V_103 ;
struct V_23 * V_24 ;
T_4 V_161 ;
int V_162 ;
V_160 = ( V_157 == V_159 ) ;
V_161 = V_157 & V_11 -> V_107 . V_124 ;
V_103 = & V_11 -> V_17 . V_126 [ V_161 ] ;
V_24 = V_103 -> V_24 ;
if ( F_38 ( ! V_24 ) ) {
V_157 ++ ;
continue;
}
if ( F_38 ( F_32 ( V_24 ) -> V_116 &
V_117 ) ) {
struct V_163 V_164 = {} ;
F_68 ( V_11 -> V_165 ,
F_69 ( V_153 ) , & V_164 ) ;
F_70 ( V_24 , & V_164 ) ;
}
for ( V_162 = 0 ; V_162 < V_103 -> V_19 ; V_162 ++ ) {
struct V_3 * V_4 =
F_6 ( V_11 , V_154 ++ ) ;
F_1 ( V_11 -> V_2 , V_4 ) ;
}
V_156 ++ ;
V_155 += V_103 -> V_79 ;
V_157 += V_103 -> V_109 ;
F_71 ( V_24 , V_151 ) ;
} while ( ! V_160 );
} while ( ( ++ V_14 < V_166 ) && ( V_153 = F_65 ( & V_150 -> V_107 ) ) );
F_72 ( & V_150 -> V_107 ) ;
F_73 () ;
V_11 -> V_154 = V_154 ;
V_11 -> V_119 = V_157 ;
F_74 ( V_11 -> V_115 , V_156 , V_155 ) ;
if ( F_75 ( V_11 -> V_115 ) &&
F_47 ( & V_11 -> V_107 , V_11 -> V_119 , V_11 -> V_112 , V_120 ) ) {
F_76 ( V_11 -> V_115 ) ;
V_11 -> V_74 . V_167 ++ ;
}
return ( V_14 == V_166 ) ;
}
void F_77 ( struct V_10 * V_11 )
{
struct V_102 * V_103 ;
struct V_23 * V_24 ;
T_4 V_161 ;
int V_14 ;
while ( V_11 -> V_119 != V_11 -> V_112 ) {
V_161 = V_11 -> V_119 & V_11 -> V_107 . V_124 ;
V_103 = & V_11 -> V_17 . V_126 [ V_161 ] ;
V_24 = V_103 -> V_24 ;
if ( ! V_24 ) {
V_11 -> V_119 ++ ;
continue;
}
for ( V_14 = 0 ; V_14 < V_103 -> V_19 ; V_14 ++ ) {
struct V_3 * V_4 =
F_6 ( V_11 , V_11 -> V_154 ++ ) ;
F_1 ( V_11 -> V_2 , V_4 ) ;
}
F_55 ( V_24 ) ;
V_11 -> V_119 += V_103 -> V_109 ;
}
}
static inline void
F_78 ( struct V_168 * V_169 , T_2 V_170 , T_2 V_171 ,
struct V_172 * V_89 )
{
memcpy ( & V_89 -> V_169 , V_169 , sizeof( struct V_168 ) ) ;
V_89 -> V_169 . V_173 = F_41 ( V_170 | V_174 ) ;
V_89 -> V_169 . V_175 . V_176 . V_176 = F_41 ( V_171 ) ;
}
T_6 F_79 ( struct V_10 * V_11 , struct V_23 * V_24 ,
struct V_168 * V_169 , T_2 V_170 , T_2 V_171 )
{
struct V_106 * V_107 = & V_11 -> V_107 ;
T_4 V_108 = V_11 -> V_112 & V_107 -> V_124 ;
struct V_177 * V_129 = F_58 ( V_107 , V_108 ) ;
struct V_102 * V_103 = & V_11 -> V_17 . V_126 [ V_108 ] ;
struct V_104 * V_105 = & V_129 -> V_130 ;
struct V_172 * V_178 = & V_129 -> V_178 ;
struct V_65 * V_66 = & V_129 -> V_131 ;
unsigned char * V_52 = V_24 -> V_46 ;
unsigned int V_53 = V_24 -> V_51 ;
T_3 V_100 = V_132 ;
unsigned int V_79 ;
int V_19 ;
T_4 V_87 ;
T_4 V_101 ;
T_4 V_55 ;
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
F_78 ( V_169 , V_170 , V_171 , V_178 ) ;
F_29 ( V_11 , V_24 , V_66 ) ;
if ( F_53 ( V_24 ) ) {
V_100 = V_133 ;
V_55 = F_31 ( V_11 , V_24 , V_66 , & V_79 ) ;
V_11 -> V_74 . V_134 += F_32 ( V_24 ) -> V_86 ;
} else {
V_55 = F_21 ( V_11 -> V_135 , V_24 ) ;
V_79 = F_54 (unsigned int, skb->len, ETH_ZLEN) ;
V_11 -> V_74 . V_134 ++ ;
}
V_11 -> V_74 . V_136 += V_79 ;
V_11 -> V_74 . V_122 += V_24 -> V_122 ;
V_101 = sizeof( * V_129 ) / V_137 ;
if ( V_55 ) {
memcpy ( V_66 -> V_138 . V_54 , V_52 , V_55 ) ;
F_25 ( & V_52 , & V_53 , V_55 ) ;
V_66 -> V_138 . V_139 = F_27 ( V_55 ) ;
V_101 += F_45 ( V_55 - sizeof( V_66 -> V_138 . V_54 ) , V_137 ) ;
}
V_87 = V_53 - V_24 -> V_142 ;
V_19 = F_36 ( V_11 , V_24 , V_52 , V_87 ,
(struct V_88 * ) V_105 + V_101 ) ;
if ( F_38 ( V_19 < 0 ) )
goto V_143;
F_44 ( V_11 , V_24 , V_100 , V_101 + V_19 ,
V_79 , V_19 , V_103 , V_105 ) ;
return V_144 ;
V_143:
V_11 -> V_74 . V_145 ++ ;
F_7 ( V_11 , V_103 -> V_19 ) ;
F_55 ( V_24 ) ;
return V_144 ;
}
