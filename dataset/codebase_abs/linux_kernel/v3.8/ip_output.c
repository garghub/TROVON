T_1 void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
V_2 -> V_3 = F_2 ( ( unsigned char * ) V_2 , V_2 -> V_4 ) ;
}
int F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
V_2 -> V_7 = F_5 ( V_6 -> V_8 ) ;
F_1 ( V_2 ) ;
return F_6 ( V_9 , V_10 , V_6 , NULL ,
F_7 ( V_6 ) -> V_11 , V_12 ) ;
}
int F_8 ( struct V_5 * V_6 )
{
int V_13 ;
V_13 = F_3 ( V_6 ) ;
if ( F_9 ( V_13 == 1 ) )
V_13 = V_12 ( V_6 ) ;
return V_13 ;
}
static inline int F_10 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
int V_18 = V_15 -> V_19 ;
if ( V_18 < 0 )
V_18 = F_11 ( V_17 ) ;
return V_18 ;
}
int F_12 ( struct V_5 * V_6 , struct V_20 * V_21 ,
T_2 V_22 , T_2 V_23 , struct V_24 * V_25 )
{
struct V_14 * V_15 = F_13 ( V_21 ) ;
struct V_26 * V_27 = F_14 ( V_6 ) ;
struct V_1 * V_2 ;
F_15 ( V_6 , sizeof( struct V_1 ) + ( V_25 ? V_25 -> V_25 . V_28 : 0 ) ) ;
F_16 ( V_6 ) ;
V_2 = F_4 ( V_6 ) ;
V_2 -> V_29 = 4 ;
V_2 -> V_4 = 5 ;
V_2 -> V_30 = V_15 -> V_30 ;
if ( F_17 ( V_21 , & V_27 -> V_17 ) )
V_2 -> V_31 = F_5 ( V_32 ) ;
else
V_2 -> V_31 = 0 ;
V_2 -> V_18 = F_10 ( V_15 , & V_27 -> V_17 ) ;
V_2 -> V_23 = ( V_25 && V_25 -> V_25 . V_33 ? V_25 -> V_25 . V_34 : V_23 ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_35 = V_21 -> V_36 ;
F_18 ( V_2 , & V_27 -> V_17 , V_21 ) ;
if ( V_25 && V_25 -> V_25 . V_28 ) {
V_2 -> V_4 += V_25 -> V_25 . V_28 >> 2 ;
F_19 ( V_6 , & V_25 -> V_25 , V_23 , V_27 , 0 ) ;
}
V_6 -> V_37 = V_21 -> V_38 ;
V_6 -> V_39 = V_21 -> V_40 ;
return F_8 ( V_6 ) ;
}
static inline int F_20 ( struct V_5 * V_6 )
{
struct V_16 * V_17 = F_7 ( V_6 ) ;
struct V_26 * V_27 = (struct V_26 * ) V_17 ;
struct V_41 * V_11 = V_17 -> V_11 ;
unsigned int V_42 = F_21 ( V_11 ) ;
struct V_43 * V_44 ;
T_3 V_45 ;
if ( V_27 -> V_46 == V_47 ) {
F_22 ( F_23 ( V_11 ) , V_48 , V_6 -> V_8 ) ;
} else if ( V_27 -> V_46 == V_49 )
F_22 ( F_23 ( V_11 ) , V_50 , V_6 -> V_8 ) ;
if ( F_24 ( F_25 ( V_6 ) < V_42 && V_11 -> V_51 ) ) {
struct V_5 * V_52 ;
V_52 = F_26 ( V_6 , F_21 ( V_11 ) ) ;
if ( V_52 == NULL ) {
F_27 ( V_6 ) ;
return - V_53 ;
}
if ( V_6 -> V_21 )
F_28 ( V_52 , V_6 -> V_21 ) ;
F_29 ( V_6 ) ;
V_6 = V_52 ;
}
F_30 () ;
V_45 = ( V_54 T_3 ) F_31 ( V_27 , F_4 ( V_6 ) -> V_23 ) ;
V_44 = F_32 ( V_11 , V_45 ) ;
if ( F_24 ( ! V_44 ) )
V_44 = F_33 ( & V_55 , & V_45 , V_11 , false ) ;
if ( ! F_34 ( V_44 ) ) {
int V_56 = F_35 ( V_17 , V_44 , V_6 ) ;
F_36 () ;
return V_56 ;
}
F_36 () ;
F_37 ( L_1 ,
V_57 ) ;
F_27 ( V_6 ) ;
return - V_58 ;
}
static inline int F_38 ( struct V_5 * V_6 )
{
struct V_14 * V_15 = V_6 -> V_21 ? F_13 ( V_6 -> V_21 ) : NULL ;
return ( V_15 && V_15 -> V_59 == V_60 ) ?
F_7 ( V_6 ) -> V_11 -> V_61 : F_39 ( F_7 ( V_6 ) ) ;
}
static int F_40 ( struct V_5 * V_6 )
{
#if F_41 ( V_62 ) && F_41 ( V_63 )
if ( F_7 ( V_6 ) -> V_64 != NULL ) {
F_42 ( V_6 ) -> V_65 |= V_66 ;
return V_12 ( V_6 ) ;
}
#endif
if ( V_6 -> V_8 > F_38 ( V_6 ) && ! F_43 ( V_6 ) )
return F_44 ( V_6 , F_20 ) ;
else
return F_20 ( V_6 ) ;
}
int F_45 ( struct V_5 * V_6 )
{
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_26 * V_27 = F_14 ( V_6 ) ;
struct V_41 * V_11 = V_27 -> V_17 . V_11 ;
F_22 ( F_23 ( V_11 ) , V_67 , V_6 -> V_8 ) ;
V_6 -> V_11 = V_11 ;
V_6 -> V_35 = F_5 ( V_68 ) ;
if ( V_27 -> V_69 & V_70 ) {
if ( F_46 ( V_21 )
#ifdef F_47
&&
( ( V_27 -> V_69 & V_71 ) ||
! ( F_42 ( V_6 ) -> V_65 & V_72 ) )
#endif
) {
struct V_5 * V_73 = F_48 ( V_6 , V_74 ) ;
if ( V_73 )
F_49 ( V_9 , V_75 ,
V_73 , NULL , V_73 -> V_11 ,
V_76 ) ;
}
if ( F_4 ( V_6 ) -> V_18 == 0 ) {
F_27 ( V_6 ) ;
return 0 ;
}
}
if ( V_27 -> V_69 & V_77 ) {
struct V_5 * V_73 = F_48 ( V_6 , V_74 ) ;
if ( V_73 )
F_49 ( V_9 , V_75 , V_73 ,
NULL , V_73 -> V_11 , V_76 ) ;
}
return F_50 ( V_9 , V_75 , V_6 , NULL ,
V_6 -> V_11 , F_40 ,
! ( F_42 ( V_6 ) -> V_65 & V_66 ) ) ;
}
int F_51 ( struct V_5 * V_6 )
{
struct V_41 * V_11 = F_7 ( V_6 ) -> V_11 ;
F_22 ( F_23 ( V_11 ) , V_67 , V_6 -> V_8 ) ;
V_6 -> V_11 = V_11 ;
V_6 -> V_35 = F_5 ( V_68 ) ;
return F_50 ( V_9 , V_75 , V_6 , NULL , V_11 ,
F_40 ,
! ( F_42 ( V_6 ) -> V_65 & V_66 ) ) ;
}
static void F_52 ( struct V_1 * V_2 , const struct V_78 * V_79 )
{
F_53 ( F_54 ( F_55 ( * V_79 ) , V_23 ) !=
F_54 ( F_55 ( * V_79 ) , V_22 ) + sizeof( V_79 -> V_22 ) ) ;
memcpy ( & V_2 -> V_22 , & V_79 -> V_22 ,
sizeof( V_79 -> V_22 ) + sizeof( V_79 -> V_23 ) ) ;
}
int F_56 ( struct V_5 * V_6 , struct V_80 * V_81 )
{
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_14 * V_15 = F_13 ( V_21 ) ;
struct V_24 * V_82 ;
struct V_78 * V_79 ;
struct V_26 * V_27 ;
struct V_1 * V_2 ;
int V_56 ;
F_57 () ;
V_82 = F_58 ( V_15 -> V_82 ) ;
V_79 = & V_81 -> V_83 . V_84 ;
V_27 = F_14 ( V_6 ) ;
if ( V_27 != NULL )
goto V_85;
V_27 = (struct V_26 * ) F_59 ( V_21 , 0 ) ;
if ( V_27 == NULL ) {
T_2 V_23 ;
V_23 = V_15 -> V_86 ;
if ( V_82 && V_82 -> V_25 . V_33 )
V_23 = V_82 -> V_25 . V_34 ;
V_27 = F_60 ( F_61 ( V_21 ) , V_79 , V_21 ,
V_23 , V_15 -> V_87 ,
V_15 -> V_88 ,
V_15 -> V_89 ,
V_21 -> V_36 ,
F_62 ( V_21 ) ,
V_21 -> V_90 ) ;
if ( F_34 ( V_27 ) )
goto V_91;
F_63 ( V_21 , & V_27 -> V_17 ) ;
}
F_64 ( V_6 , & V_27 -> V_17 ) ;
V_85:
if ( V_82 && V_82 -> V_25 . V_92 && V_27 -> V_93 )
goto V_91;
F_15 ( V_6 , sizeof( struct V_1 ) + ( V_82 ? V_82 -> V_25 . V_28 : 0 ) ) ;
F_16 ( V_6 ) ;
V_2 = F_4 ( V_6 ) ;
* ( ( V_94 * ) V_2 ) = F_5 ( ( 4 << 12 ) | ( 5 << 8 ) | ( V_15 -> V_30 & 0xff ) ) ;
if ( F_17 ( V_21 , & V_27 -> V_17 ) && ! V_6 -> V_95 )
V_2 -> V_31 = F_5 ( V_32 ) ;
else
V_2 -> V_31 = 0 ;
V_2 -> V_18 = F_10 ( V_15 , & V_27 -> V_17 ) ;
V_2 -> V_35 = V_21 -> V_36 ;
F_52 ( V_2 , V_79 ) ;
if ( V_82 && V_82 -> V_25 . V_28 ) {
V_2 -> V_4 += V_82 -> V_25 . V_28 >> 2 ;
F_19 ( V_6 , & V_82 -> V_25 , V_15 -> V_86 , V_27 , 0 ) ;
}
F_65 ( V_2 , & V_27 -> V_17 , V_21 ,
( F_66 ( V_6 ) -> V_96 ? : 1 ) - 1 ) ;
V_6 -> V_37 = V_21 -> V_38 ;
V_6 -> V_39 = V_21 -> V_40 ;
V_56 = F_8 ( V_6 ) ;
F_67 () ;
return V_56 ;
V_91:
F_67 () ;
F_68 ( F_61 ( V_21 ) , V_97 ) ;
F_27 ( V_6 ) ;
return - V_98 ;
}
static void F_69 ( struct V_5 * V_99 , struct V_5 * V_100 )
{
V_99 -> V_101 = V_100 -> V_101 ;
V_99 -> V_37 = V_100 -> V_37 ;
V_99 -> V_35 = V_100 -> V_35 ;
F_70 ( V_99 ) ;
F_71 ( V_99 , V_100 ) ;
V_99 -> V_11 = V_100 -> V_11 ;
V_99 -> V_39 = V_100 -> V_39 ;
F_42 ( V_99 ) -> V_65 = F_42 ( V_100 ) -> V_65 ;
#ifdef F_72
V_99 -> V_102 = V_100 -> V_102 ;
#endif
F_73 ( V_99 , V_100 ) ;
#if F_41 ( V_103 ) || \
F_41 ( V_104 )
V_99 -> V_105 = V_100 -> V_105 ;
#endif
#if F_41 ( V_106 ) || F_41 ( V_107 )
V_99 -> V_108 = V_100 -> V_108 ;
#endif
F_74 ( V_99 , V_100 ) ;
}
int F_44 ( struct V_5 * V_6 , int (* F_75)( struct V_5 * ) )
{
struct V_1 * V_2 ;
int V_109 ;
struct V_41 * V_11 ;
struct V_5 * V_52 ;
unsigned int V_61 , V_110 , V_111 , V_8 , V_112 ;
int V_113 ;
V_94 V_114 ;
struct V_26 * V_27 = F_14 ( V_6 ) ;
int V_13 = 0 ;
V_11 = V_27 -> V_17 . V_11 ;
V_2 = F_4 ( V_6 ) ;
if ( F_24 ( ( ( V_2 -> V_31 & F_5 ( V_32 ) ) && ! V_6 -> V_95 ) ||
( F_42 ( V_6 ) -> V_115 &&
F_42 ( V_6 ) -> V_115 > F_39 ( & V_27 -> V_17 ) ) ) ) {
F_68 ( F_23 ( V_11 ) , V_116 ) ;
F_76 ( V_6 , V_117 , V_118 ,
F_77 ( F_38 ( V_6 ) ) ) ;
F_27 ( V_6 ) ;
return - V_119 ;
}
V_110 = V_2 -> V_4 * 4 ;
V_61 = F_39 ( & V_27 -> V_17 ) - V_110 ;
#ifdef F_78
if ( V_6 -> V_120 )
V_61 -= F_79 ( V_6 ) ;
#endif
F_42 ( V_6 ) -> V_65 |= V_121 ;
if ( F_80 ( V_6 ) ) {
struct V_5 * V_122 , * V_123 ;
int V_124 = F_81 ( V_6 ) ;
if ( V_124 - V_110 > V_61 ||
( ( V_124 - V_110 ) & 7 ) ||
F_82 ( V_2 ) ||
F_83 ( V_6 ) )
goto V_125;
F_84 (skb, frag) {
if ( V_122 -> V_8 > V_61 ||
( ( V_122 -> V_8 & 7 ) && V_122 -> V_126 ) ||
F_25 ( V_122 ) < V_110 )
goto V_127;
if ( F_85 ( V_122 ) )
goto V_127;
F_86 ( V_122 -> V_21 ) ;
if ( V_6 -> V_21 ) {
V_122 -> V_21 = V_6 -> V_21 ;
V_122 -> V_128 = V_129 ;
}
V_6 -> V_130 -= V_122 -> V_130 ;
}
V_13 = 0 ;
V_113 = 0 ;
V_122 = F_66 ( V_6 ) -> V_131 ;
F_87 ( V_6 ) ;
V_6 -> V_132 = V_124 - F_88 ( V_6 ) ;
V_6 -> V_8 = V_124 ;
V_2 -> V_7 = F_5 ( V_124 ) ;
V_2 -> V_31 = F_5 ( V_133 ) ;
F_1 ( V_2 ) ;
for (; ; ) {
if ( V_122 ) {
V_122 -> V_134 = V_135 ;
F_89 ( V_122 ) ;
F_90 ( V_122 , V_110 ) ;
F_16 ( V_122 ) ;
memcpy ( F_91 ( V_122 ) , V_2 , V_110 ) ;
V_2 = F_4 ( V_122 ) ;
V_2 -> V_7 = F_5 ( V_122 -> V_8 ) ;
F_69 ( V_122 , V_6 ) ;
if ( V_113 == 0 )
F_92 ( V_122 ) ;
V_113 += V_6 -> V_8 - V_110 ;
V_2 -> V_31 = F_5 ( V_113 >> 3 ) ;
if ( V_122 -> V_126 != NULL )
V_2 -> V_31 |= F_5 ( V_133 ) ;
F_1 ( V_2 ) ;
}
V_13 = F_75 ( V_6 ) ;
if ( ! V_13 )
F_68 ( F_23 ( V_11 ) , V_136 ) ;
if ( V_13 || ! V_122 )
break;
V_6 = V_122 ;
V_122 = V_6 -> V_126 ;
V_6 -> V_126 = NULL ;
}
if ( V_13 == 0 ) {
F_68 ( F_23 ( V_11 ) , V_137 ) ;
return 0 ;
}
while ( V_122 ) {
V_6 = V_122 -> V_126 ;
F_27 ( V_122 ) ;
V_122 = V_6 ;
}
F_68 ( F_23 ( V_11 ) , V_116 ) ;
return V_13 ;
V_127:
F_84 (skb, frag2) {
if ( V_123 == V_122 )
break;
V_123 -> V_21 = NULL ;
V_123 -> V_128 = NULL ;
V_6 -> V_130 += V_123 -> V_130 ;
}
}
V_125:
if ( ( V_6 -> V_134 == V_138 ) && F_93 ( V_6 ) )
goto V_139;
V_111 = V_6 -> V_8 - V_110 ;
V_109 = V_110 ;
V_112 = F_94 ( V_27 -> V_17 . V_11 , F_95 ( V_6 ) ) ;
V_113 = ( F_96 ( V_2 -> V_31 ) & V_140 ) << 3 ;
V_114 = V_2 -> V_31 & F_5 ( V_133 ) ;
while ( V_111 > 0 ) {
V_8 = V_111 ;
if ( V_8 > V_61 )
V_8 = V_61 ;
if ( V_8 < V_111 ) {
V_8 &= ~ 7 ;
}
if ( ( V_52 = F_97 ( V_8 + V_110 + V_112 , V_74 ) ) == NULL ) {
F_98 ( V_141 L_2 ) ;
V_13 = - V_53 ;
goto V_139;
}
F_69 ( V_52 , V_6 ) ;
F_99 ( V_52 , V_112 ) ;
F_100 ( V_52 , V_8 + V_110 ) ;
F_16 ( V_52 ) ;
V_52 -> V_142 = V_52 -> V_143 + V_110 ;
if ( V_6 -> V_21 )
F_28 ( V_52 , V_6 -> V_21 ) ;
F_101 ( V_6 , F_91 ( V_52 ) , V_110 ) ;
if ( F_102 ( V_6 , V_109 , F_103 ( V_52 ) , V_8 ) )
F_104 () ;
V_111 -= V_8 ;
V_2 = F_4 ( V_52 ) ;
V_2 -> V_31 = F_5 ( ( V_113 >> 3 ) ) ;
if ( V_113 == 0 )
F_92 ( V_6 ) ;
if ( V_111 > 0 || V_114 )
V_2 -> V_31 |= F_5 ( V_133 ) ;
V_109 += V_8 ;
V_113 += V_8 ;
V_2 -> V_7 = F_5 ( V_8 + V_110 ) ;
F_1 ( V_2 ) ;
V_13 = F_75 ( V_52 ) ;
if ( V_13 )
goto V_139;
F_68 ( F_23 ( V_11 ) , V_136 ) ;
}
F_29 ( V_6 ) ;
F_68 ( F_23 ( V_11 ) , V_137 ) ;
return V_13 ;
V_139:
F_27 ( V_6 ) ;
F_68 ( F_23 ( V_11 ) , V_116 ) ;
return V_13 ;
}
int
F_105 ( void * V_100 , char * V_99 , int V_113 , int V_8 , int V_144 , struct V_5 * V_6 )
{
struct V_145 * V_146 = V_100 ;
if ( V_6 -> V_134 == V_138 ) {
if ( F_106 ( V_99 , V_146 , V_113 , V_8 ) < 0 )
return - V_147 ;
} else {
T_4 V_148 = 0 ;
if ( F_107 ( V_99 , V_146 , V_113 , V_8 , & V_148 ) < 0 )
return - V_147 ;
V_6 -> V_148 = F_108 ( V_6 -> V_148 , V_148 , V_144 ) ;
}
return 0 ;
}
static inline T_4
F_109 ( struct V_149 * V_149 , int V_113 , int V_150 )
{
char * V_151 ;
T_4 V_148 ;
V_151 = F_110 ( V_149 ) ;
V_148 = F_111 ( V_151 + V_113 , V_150 , 0 ) ;
F_112 ( V_149 ) ;
return V_148 ;
}
static inline int F_113 ( struct V_20 * V_21 ,
struct V_152 * V_153 ,
int F_114 ( void * V_100 , char * V_99 , int V_113 , int V_8 ,
int V_144 , struct V_5 * V_6 ) ,
void * V_100 , int V_154 , int V_42 , int V_155 ,
int V_156 , int V_157 , unsigned int V_65 )
{
struct V_5 * V_6 ;
int V_13 ;
if ( ( V_6 = F_115 ( V_153 ) ) == NULL ) {
V_6 = F_116 ( V_21 ,
V_42 + V_155 + V_156 + 20 ,
( V_65 & V_158 ) , & V_13 ) ;
if ( V_6 == NULL )
return V_13 ;
F_99 ( V_6 , V_42 ) ;
F_100 ( V_6 , V_155 + V_156 ) ;
F_16 ( V_6 ) ;
V_6 -> V_142 = V_6 -> V_143 + V_155 ;
V_6 -> V_134 = V_138 ;
V_6 -> V_148 = 0 ;
F_66 ( V_6 ) -> V_159 = V_157 - V_155 ;
F_66 ( V_6 ) -> V_160 = V_161 ;
F_117 ( V_153 , V_6 ) ;
}
return F_118 ( V_21 , V_6 , F_114 , V_100 ,
( V_154 - V_156 ) ) ;
}
static int F_119 ( struct V_20 * V_21 ,
struct V_78 * V_79 ,
struct V_152 * V_153 ,
struct V_162 * V_163 ,
struct V_164 * V_165 ,
int F_114 ( void * V_100 , char * V_99 , int V_113 ,
int V_8 , int V_144 , struct V_5 * V_6 ) ,
void * V_100 , int V_154 , int V_156 ,
unsigned int V_65 )
{
struct V_14 * V_15 = F_13 ( V_21 ) ;
struct V_5 * V_6 ;
struct V_166 * V_25 = V_163 -> V_25 ;
int V_42 ;
int V_167 ;
int V_61 ;
int V_150 ;
int V_13 ;
int V_113 = 0 ;
unsigned int V_157 , V_155 ;
int V_168 = V_135 ;
struct V_26 * V_27 = (struct V_26 * ) V_163 -> V_17 ;
V_6 = F_115 ( V_153 ) ;
V_167 = ! V_6 ? V_27 -> V_17 . V_169 : 0 ;
V_61 = V_163 -> V_170 ;
V_42 = F_21 ( V_27 -> V_17 . V_11 ) ;
V_155 = sizeof( struct V_1 ) + ( V_25 ? V_25 -> V_28 : 0 ) ;
V_157 = ( ( V_61 - V_155 ) & ~ 7 ) + V_155 ;
if ( V_163 -> V_154 + V_154 > 0xFFFF - V_155 ) {
F_120 ( V_21 , V_119 , V_79 -> V_23 , V_15 -> V_88 ,
V_61 - V_167 ) ;
return - V_119 ;
}
if ( V_156 &&
V_154 + V_155 <= V_61 &&
V_27 -> V_17 . V_11 -> V_171 & V_172 &&
! V_167 )
V_168 = V_138 ;
V_163 -> V_154 += V_154 ;
if ( ( ( V_154 > V_61 ) || ( V_6 && F_43 ( V_6 ) ) ) &&
( V_21 -> V_36 == V_173 ) &&
( V_27 -> V_17 . V_11 -> V_171 & V_174 ) && ! V_27 -> V_17 . V_169 ) {
V_13 = F_113 ( V_21 , V_153 , F_114 , V_100 , V_154 ,
V_42 , V_155 , V_156 ,
V_157 , V_65 ) ;
if ( V_13 )
goto error;
return 0 ;
}
if ( ! V_6 )
goto V_175;
while ( V_154 > 0 ) {
V_150 = V_61 - V_6 -> V_8 ;
if ( V_150 < V_154 )
V_150 = V_157 - V_6 -> V_8 ;
if ( V_150 <= 0 ) {
char * V_176 ;
unsigned int V_177 ;
unsigned int V_178 ;
unsigned int V_179 ;
unsigned int V_180 ;
struct V_5 * V_181 ;
V_175:
V_181 = V_6 ;
if ( V_181 )
V_179 = V_181 -> V_8 - V_157 ;
else
V_179 = 0 ;
V_177 = V_154 + V_179 ;
if ( V_177 > V_61 - V_155 )
V_177 = V_157 - V_155 ;
V_178 = V_177 + V_155 ;
if ( ( V_65 & V_182 ) &&
! ( V_27 -> V_17 . V_11 -> V_171 & V_183 ) )
V_180 = V_61 ;
else
V_180 = V_178 ;
V_180 += V_167 ;
if ( V_177 == V_154 + V_179 )
V_180 += V_27 -> V_17 . V_184 ;
if ( V_156 ) {
V_6 = F_116 ( V_21 ,
V_180 + V_42 + 15 ,
( V_65 & V_158 ) , & V_13 ) ;
} else {
V_6 = NULL ;
if ( F_121 ( & V_21 -> V_185 ) <=
2 * V_21 -> V_186 )
V_6 = F_122 ( V_21 ,
V_180 + V_42 + 15 , 1 ,
V_21 -> V_187 ) ;
if ( F_24 ( V_6 == NULL ) )
V_13 = - V_188 ;
else
V_163 -> V_189 = 0 ;
}
if ( V_6 == NULL )
goto error;
V_6 -> V_134 = V_168 ;
V_6 -> V_148 = 0 ;
F_99 ( V_6 , V_42 ) ;
F_66 ( V_6 ) -> V_189 = V_163 -> V_189 ;
V_176 = F_100 ( V_6 , V_178 + V_167 ) ;
F_123 ( V_6 , V_167 ) ;
V_6 -> V_142 = ( V_6 -> V_143 +
V_155 ) ;
V_176 += V_155 + V_167 ;
if ( V_179 ) {
V_6 -> V_148 = F_124 (
V_181 , V_157 ,
V_176 + V_156 , V_179 , 0 ) ;
V_181 -> V_148 = F_125 ( V_181 -> V_148 ,
V_6 -> V_148 ) ;
V_176 += V_179 ;
F_126 ( V_181 , V_157 ) ;
}
V_150 = V_177 - V_156 - V_179 ;
if ( V_150 > 0 && F_114 ( V_100 , V_176 + V_156 , V_113 , V_150 , V_179 , V_6 ) < 0 ) {
V_13 = - V_147 ;
F_27 ( V_6 ) ;
goto error;
}
V_113 += V_150 ;
V_154 -= V_177 - V_179 ;
V_156 = 0 ;
V_167 = 0 ;
V_168 = V_135 ;
F_117 ( V_153 , V_6 ) ;
continue;
}
if ( V_150 > V_154 )
V_150 = V_154 ;
if ( ! ( V_27 -> V_17 . V_11 -> V_171 & V_183 ) ) {
unsigned int V_190 ;
V_190 = V_6 -> V_8 ;
if ( F_114 ( V_100 , F_100 ( V_6 , V_150 ) ,
V_113 , V_150 , V_190 , V_6 ) < 0 ) {
F_127 ( V_6 , V_190 ) ;
V_13 = - V_147 ;
goto error;
}
} else {
int V_191 = F_66 ( V_6 ) -> V_192 ;
V_13 = - V_53 ;
if ( ! F_128 ( V_21 , V_165 ) )
goto error;
if ( ! F_129 ( V_6 , V_191 , V_165 -> V_149 ,
V_165 -> V_113 ) ) {
V_13 = - V_119 ;
if ( V_191 == V_193 )
goto error;
F_130 ( V_6 , V_191 , V_165 -> V_149 ,
V_165 -> V_113 , 0 ) ;
F_66 ( V_6 ) -> V_192 = ++ V_191 ;
F_131 ( V_165 -> V_149 ) ;
}
V_150 = F_132 ( int , V_150 , V_165 -> V_194 - V_165 -> V_113 ) ;
if ( F_114 ( V_100 ,
F_133 ( V_165 -> V_149 ) + V_165 -> V_113 ,
V_113 , V_150 , V_6 -> V_8 , V_6 ) < 0 )
goto V_195;
V_165 -> V_113 += V_150 ;
F_134 ( & F_66 ( V_6 ) -> V_196 [ V_191 - 1 ] , V_150 ) ;
V_6 -> V_8 += V_150 ;
V_6 -> V_132 += V_150 ;
V_6 -> V_130 += V_150 ;
F_135 ( V_150 , & V_21 -> V_185 ) ;
}
V_113 += V_150 ;
V_154 -= V_150 ;
}
return 0 ;
V_195:
V_13 = - V_147 ;
error:
V_163 -> V_154 -= V_154 ;
F_68 ( F_61 ( V_21 ) , V_197 ) ;
return V_13 ;
}
static int F_136 ( struct V_20 * V_21 , struct V_162 * V_163 ,
struct V_198 * V_199 , struct V_26 * * V_200 )
{
struct V_14 * V_15 = F_13 ( V_21 ) ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
V_25 = V_199 -> V_25 ;
if ( V_25 ) {
if ( V_163 -> V_25 == NULL ) {
V_163 -> V_25 = F_137 ( sizeof( struct V_166 ) + 40 ,
V_21 -> V_187 ) ;
if ( F_24 ( V_163 -> V_25 == NULL ) )
return - V_188 ;
}
memcpy ( V_163 -> V_25 , & V_25 -> V_25 , sizeof( struct V_166 ) + V_25 -> V_25 . V_28 ) ;
V_163 -> V_65 |= V_201 ;
V_163 -> V_202 = V_199 -> V_202 ;
}
V_27 = * V_200 ;
if ( F_24 ( ! V_27 ) )
return - V_147 ;
* V_200 = NULL ;
V_163 -> V_170 = V_15 -> V_59 == V_60 ?
V_27 -> V_17 . V_11 -> V_61 : F_39 ( & V_27 -> V_17 ) ;
V_163 -> V_17 = & V_27 -> V_17 ;
V_163 -> V_154 = 0 ;
V_163 -> V_189 = V_199 -> V_189 ;
return 0 ;
}
int F_138 ( struct V_20 * V_21 , struct V_78 * V_79 ,
int F_114 ( void * V_100 , char * V_99 , int V_113 , int V_8 ,
int V_144 , struct V_5 * V_6 ) ,
void * V_100 , int V_154 , int V_156 ,
struct V_198 * V_199 , struct V_26 * * V_200 ,
unsigned int V_65 )
{
struct V_14 * V_15 = F_13 ( V_21 ) ;
int V_13 ;
if ( V_65 & V_203 )
return 0 ;
if ( F_139 ( & V_21 -> V_204 ) ) {
V_13 = F_136 ( V_21 , & V_15 -> V_163 . V_205 , V_199 , V_200 ) ;
if ( V_13 )
return V_13 ;
} else {
V_156 = 0 ;
}
return F_119 ( V_21 , V_79 , & V_21 -> V_204 , & V_15 -> V_163 . V_205 ,
F_140 ( V_21 ) , F_114 ,
V_100 , V_154 , V_156 , V_65 ) ;
}
T_5 F_141 ( struct V_20 * V_21 , struct V_78 * V_79 , struct V_149 * V_149 ,
int V_113 , T_6 V_194 , int V_65 )
{
struct V_14 * V_15 = F_13 ( V_21 ) ;
struct V_5 * V_6 ;
struct V_26 * V_27 ;
struct V_166 * V_25 = NULL ;
struct V_162 * V_163 ;
int V_42 ;
int V_61 ;
int V_8 ;
int V_13 ;
unsigned int V_157 , V_155 , V_179 ;
if ( V_15 -> V_206 )
return - V_207 ;
if ( V_65 & V_203 )
return 0 ;
if ( F_139 ( & V_21 -> V_204 ) )
return - V_58 ;
V_163 = & V_15 -> V_163 . V_205 ;
V_27 = (struct V_26 * ) V_163 -> V_17 ;
if ( V_163 -> V_65 & V_201 )
V_25 = V_163 -> V_25 ;
if ( ! ( V_27 -> V_17 . V_11 -> V_171 & V_183 ) )
return - V_208 ;
V_42 = F_21 ( V_27 -> V_17 . V_11 ) ;
V_61 = V_163 -> V_170 ;
V_155 = sizeof( struct V_1 ) + ( V_25 ? V_25 -> V_28 : 0 ) ;
V_157 = ( ( V_61 - V_155 ) & ~ 7 ) + V_155 ;
if ( V_163 -> V_154 + V_194 > 0xFFFF - V_155 ) {
F_120 ( V_21 , V_119 , V_79 -> V_23 , V_15 -> V_88 , V_61 ) ;
return - V_119 ;
}
if ( ( V_6 = F_115 ( & V_21 -> V_204 ) ) == NULL )
return - V_58 ;
V_163 -> V_154 += V_194 ;
if ( ( V_194 + V_6 -> V_8 > V_61 ) &&
( V_21 -> V_36 == V_173 ) &&
( V_27 -> V_17 . V_11 -> V_171 & V_174 ) ) {
F_66 ( V_6 ) -> V_159 = V_61 - V_155 ;
F_66 ( V_6 ) -> V_160 = V_161 ;
}
while ( V_194 > 0 ) {
int V_191 ;
if ( F_43 ( V_6 ) )
V_8 = V_194 ;
else {
V_8 = V_61 - V_6 -> V_8 ;
if ( V_8 < V_194 )
V_8 = V_157 - V_6 -> V_8 ;
}
if ( V_8 <= 0 ) {
struct V_5 * V_181 ;
int V_180 ;
V_181 = V_6 ;
V_179 = V_181 -> V_8 - V_157 ;
V_180 = V_155 + V_42 + V_179 + 15 ;
V_6 = F_122 ( V_21 , V_180 , 1 , V_21 -> V_187 ) ;
if ( F_24 ( ! V_6 ) ) {
V_13 = - V_188 ;
goto error;
}
V_6 -> V_134 = V_135 ;
V_6 -> V_148 = 0 ;
F_99 ( V_6 , V_42 ) ;
F_100 ( V_6 , V_155 + V_179 ) ;
F_16 ( V_6 ) ;
V_6 -> V_142 = ( V_6 -> V_143 +
V_155 ) ;
if ( V_179 ) {
V_6 -> V_148 = F_124 ( V_181 ,
V_157 ,
F_103 ( V_6 ) ,
V_179 , 0 ) ;
V_181 -> V_148 = F_125 ( V_181 -> V_148 ,
V_6 -> V_148 ) ;
F_126 ( V_181 , V_157 ) ;
}
F_117 ( & V_21 -> V_204 , V_6 ) ;
continue;
}
V_191 = F_66 ( V_6 ) -> V_192 ;
if ( V_8 > V_194 )
V_8 = V_194 ;
if ( F_129 ( V_6 , V_191 , V_149 , V_113 ) ) {
F_134 ( & F_66 ( V_6 ) -> V_196 [ V_191 - 1 ] , V_8 ) ;
} else if ( V_191 < V_193 ) {
F_131 ( V_149 ) ;
F_142 ( V_6 , V_191 , V_149 , V_113 , V_8 ) ;
} else {
V_13 = - V_119 ;
goto error;
}
if ( V_6 -> V_134 == V_135 ) {
T_4 V_148 ;
V_148 = F_109 ( V_149 , V_113 , V_8 ) ;
V_6 -> V_148 = F_108 ( V_6 -> V_148 , V_148 , V_6 -> V_8 ) ;
}
V_6 -> V_8 += V_8 ;
V_6 -> V_132 += V_8 ;
V_6 -> V_130 += V_8 ;
F_135 ( V_8 , & V_21 -> V_185 ) ;
V_113 += V_8 ;
V_194 -= V_8 ;
}
return 0 ;
error:
V_163 -> V_154 -= V_194 ;
F_68 ( F_61 ( V_21 ) , V_197 ) ;
return V_13 ;
}
static void F_143 ( struct V_162 * V_163 )
{
V_163 -> V_65 &= ~ V_201 ;
F_144 ( V_163 -> V_25 ) ;
V_163 -> V_25 = NULL ;
F_145 ( V_163 -> V_17 ) ;
V_163 -> V_17 = NULL ;
}
struct V_5 * F_146 ( struct V_20 * V_21 ,
struct V_78 * V_79 ,
struct V_152 * V_153 ,
struct V_162 * V_163 )
{
struct V_5 * V_6 , * V_209 ;
struct V_5 * * V_210 ;
struct V_14 * V_15 = F_13 ( V_21 ) ;
struct V_211 * V_211 = F_61 ( V_21 ) ;
struct V_166 * V_25 = NULL ;
struct V_26 * V_27 = (struct V_26 * ) V_163 -> V_17 ;
struct V_1 * V_2 ;
V_94 V_212 = 0 ;
T_7 V_18 ;
if ( ( V_6 = F_147 ( V_153 ) ) == NULL )
goto V_213;
V_210 = & ( F_66 ( V_6 ) -> V_131 ) ;
if ( V_6 -> V_176 < F_91 ( V_6 ) )
F_148 ( V_6 , F_149 ( V_6 ) ) ;
while ( ( V_209 = F_147 ( V_153 ) ) != NULL ) {
F_148 ( V_209 , F_150 ( V_6 ) ) ;
* V_210 = V_209 ;
V_210 = & ( V_209 -> V_126 ) ;
V_6 -> V_8 += V_209 -> V_8 ;
V_6 -> V_132 += V_209 -> V_8 ;
V_6 -> V_130 += V_209 -> V_130 ;
V_209 -> V_128 = NULL ;
V_209 -> V_21 = NULL ;
}
if ( V_15 -> V_59 < V_214 )
V_6 -> V_95 = 1 ;
if ( V_15 -> V_59 >= V_214 ||
( V_6 -> V_8 <= F_39 ( & V_27 -> V_17 ) &&
F_17 ( V_21 , & V_27 -> V_17 ) ) )
V_212 = F_5 ( V_32 ) ;
if ( V_163 -> V_65 & V_201 )
V_25 = V_163 -> V_25 ;
if ( V_27 -> V_46 == V_47 )
V_18 = V_15 -> V_215 ;
else
V_18 = F_10 ( V_15 , & V_27 -> V_17 ) ;
V_2 = (struct V_1 * ) V_6 -> V_176 ;
V_2 -> V_29 = 4 ;
V_2 -> V_4 = 5 ;
V_2 -> V_30 = V_15 -> V_30 ;
V_2 -> V_31 = V_212 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_35 = V_21 -> V_36 ;
F_52 ( V_2 , V_79 ) ;
F_18 ( V_2 , & V_27 -> V_17 , V_21 ) ;
if ( V_25 ) {
V_2 -> V_4 += V_25 -> V_28 >> 2 ;
F_19 ( V_6 , V_25 , V_163 -> V_202 , V_27 , 0 ) ;
}
V_6 -> V_37 = V_21 -> V_38 ;
V_6 -> V_39 = V_21 -> V_40 ;
V_163 -> V_17 = NULL ;
F_151 ( V_6 , & V_27 -> V_17 ) ;
if ( V_2 -> V_35 == V_216 )
F_152 ( V_211 , ( (struct V_217 * )
F_103 ( V_6 ) ) -> type ) ;
F_143 ( V_163 ) ;
V_213:
return V_6 ;
}
int F_153 ( struct V_211 * V_211 , struct V_5 * V_6 )
{
int V_13 ;
V_13 = F_8 ( V_6 ) ;
if ( V_13 ) {
if ( V_13 > 0 )
V_13 = F_154 ( V_13 ) ;
if ( V_13 )
F_68 ( V_211 , V_197 ) ;
}
return V_13 ;
}
int F_155 ( struct V_20 * V_21 , struct V_78 * V_79 )
{
struct V_5 * V_6 ;
V_6 = F_156 ( V_21 , V_79 ) ;
if ( ! V_6 )
return 0 ;
return F_153 ( F_61 ( V_21 ) , V_6 ) ;
}
static void F_157 ( struct V_20 * V_21 ,
struct V_152 * V_153 ,
struct V_162 * V_163 )
{
struct V_5 * V_6 ;
while ( ( V_6 = F_158 ( V_153 ) ) != NULL )
F_27 ( V_6 ) ;
F_143 ( V_163 ) ;
}
void F_159 ( struct V_20 * V_21 )
{
F_157 ( V_21 , & V_21 -> V_204 , & F_13 ( V_21 ) -> V_163 . V_205 ) ;
}
struct V_5 * F_160 ( struct V_20 * V_21 ,
struct V_78 * V_79 ,
int F_114 ( void * V_100 , char * V_99 , int V_113 ,
int V_8 , int V_144 , struct V_5 * V_6 ) ,
void * V_100 , int V_154 , int V_156 ,
struct V_198 * V_199 , struct V_26 * * V_200 ,
unsigned int V_65 )
{
struct V_162 V_163 ;
struct V_152 V_153 ;
int V_13 ;
if ( V_65 & V_203 )
return NULL ;
F_161 ( & V_153 ) ;
V_163 . V_65 = 0 ;
V_163 . V_202 = 0 ;
V_163 . V_25 = NULL ;
V_13 = F_136 ( V_21 , & V_163 , V_199 , V_200 ) ;
if ( V_13 )
return F_162 ( V_13 ) ;
V_13 = F_119 ( V_21 , V_79 , & V_153 , & V_163 ,
& V_218 -> V_219 , F_114 ,
V_100 , V_154 , V_156 , V_65 ) ;
if ( V_13 ) {
F_157 ( V_21 , & V_153 , & V_163 ) ;
return F_162 ( V_13 ) ;
}
return F_146 ( V_21 , V_79 , & V_153 , & V_163 ) ;
}
static int F_163 ( void * V_220 , char * V_99 , int V_113 ,
int V_8 , int V_144 , struct V_5 * V_6 )
{
T_4 V_148 ;
V_148 = F_164 ( V_220 + V_113 , V_99 , V_8 , 0 ) ;
V_6 -> V_148 = F_108 ( V_6 -> V_148 , V_148 , V_144 ) ;
return 0 ;
}
void F_165 ( struct V_211 * V_211 , struct V_5 * V_6 , T_2 V_23 ,
T_2 V_22 , const struct V_221 * V_222 ,
unsigned int V_8 )
{
struct V_223 V_224 ;
struct V_198 V_199 ;
struct V_78 V_79 ;
struct V_26 * V_27 = F_14 ( V_6 ) ;
struct V_5 * V_225 ;
struct V_20 * V_21 ;
struct V_14 * V_15 ;
if ( F_166 ( & V_224 . V_25 . V_25 , V_6 ) )
return;
V_199 . V_202 = V_23 ;
V_199 . V_25 = NULL ;
V_199 . V_189 = 0 ;
if ( V_224 . V_25 . V_25 . V_28 ) {
V_199 . V_25 = & V_224 . V_25 ;
if ( V_224 . V_25 . V_25 . V_33 )
V_23 = V_224 . V_25 . V_25 . V_34 ;
}
F_167 ( & V_79 , V_222 -> V_226 , 0 ,
F_168 ( V_222 -> V_30 ) ,
V_227 , F_4 ( V_6 ) -> V_35 ,
F_169 ( V_222 ) ,
V_23 , V_22 ,
F_170 ( V_6 ) -> V_228 , F_170 ( V_6 ) -> V_229 ) ;
F_171 ( V_6 , F_172 ( & V_79 ) ) ;
V_27 = F_173 ( V_211 , & V_79 ) ;
if ( F_34 ( V_27 ) )
return;
V_15 = & F_174 ( V_230 ) ;
V_15 -> V_30 = V_222 -> V_30 ;
V_21 = & V_15 -> V_21 ;
V_21 -> V_38 = V_6 -> V_37 ;
V_21 -> V_36 = F_4 ( V_6 ) -> V_35 ;
V_21 -> V_90 = V_222 -> V_226 ;
F_175 ( V_21 , V_211 ) ;
F_161 ( & V_21 -> V_204 ) ;
V_21 -> V_186 = V_231 ;
F_138 ( V_21 , & V_79 , F_163 , V_222 -> V_146 -> V_232 , V_8 , 0 ,
& V_199 , & V_27 , V_158 ) ;
V_225 = F_176 ( & V_21 -> V_204 ) ;
if ( V_225 ) {
if ( V_222 -> V_233 >= 0 )
* ( ( V_234 * ) F_103 ( V_225 ) +
V_222 -> V_233 ) = F_177 ( F_178 ( V_225 -> V_148 ,
V_222 -> V_148 ) ) ;
V_225 -> V_134 = V_135 ;
F_179 ( V_225 ) ;
F_180 ( V_225 , F_181 ( V_6 ) ) ;
F_155 ( V_21 , & V_79 ) ;
}
F_182 ( V_230 ) ;
F_183 ( V_27 ) ;
}
void T_8 F_184 ( void )
{
F_185 () ;
F_186 () ;
#if F_41 ( V_235 ) && F_41 ( V_236 )
F_187 () ;
#endif
}
