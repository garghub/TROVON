void F_1 ( struct V_1 * V_2 )
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
T_1 V_22 , T_1 V_23 , struct V_24 * V_25 )
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
F_18 ( V_6 , & V_27 -> V_17 , V_21 ) ;
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
T_2 V_45 ;
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
V_45 = ( V_54 T_2 ) F_31 ( V_27 , F_4 ( V_6 ) -> V_23 ) ;
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
static int F_38 ( struct V_5 * V_6 )
{
#if F_39 ( V_59 ) && F_39 ( V_60 )
if ( F_7 ( V_6 ) -> V_61 != NULL ) {
F_40 ( V_6 ) -> V_62 |= V_63 ;
return V_12 ( V_6 ) ;
}
#endif
if ( V_6 -> V_8 > F_41 ( V_6 ) && ! F_42 ( V_6 ) )
return F_43 ( V_6 , F_20 ) ;
else
return F_20 ( V_6 ) ;
}
int F_44 ( struct V_5 * V_6 )
{
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_26 * V_27 = F_14 ( V_6 ) ;
struct V_41 * V_11 = V_27 -> V_17 . V_11 ;
F_22 ( F_23 ( V_11 ) , V_64 , V_6 -> V_8 ) ;
V_6 -> V_11 = V_11 ;
V_6 -> V_35 = F_5 ( V_65 ) ;
if ( V_27 -> V_66 & V_67 ) {
if ( F_45 ( V_21 )
#ifdef F_46
&&
( ( V_27 -> V_66 & V_68 ) ||
! ( F_40 ( V_6 ) -> V_62 & V_69 ) )
#endif
) {
struct V_5 * V_70 = F_47 ( V_6 , V_71 ) ;
if ( V_70 )
F_48 ( V_9 , V_72 ,
V_70 , NULL , V_70 -> V_11 ,
V_73 ) ;
}
if ( F_4 ( V_6 ) -> V_18 == 0 ) {
F_27 ( V_6 ) ;
return 0 ;
}
}
if ( V_27 -> V_66 & V_74 ) {
struct V_5 * V_70 = F_47 ( V_6 , V_71 ) ;
if ( V_70 )
F_48 ( V_9 , V_72 , V_70 ,
NULL , V_70 -> V_11 , V_73 ) ;
}
return F_49 ( V_9 , V_72 , V_6 , NULL ,
V_6 -> V_11 , F_38 ,
! ( F_40 ( V_6 ) -> V_62 & V_63 ) ) ;
}
int F_50 ( struct V_5 * V_6 )
{
struct V_41 * V_11 = F_7 ( V_6 ) -> V_11 ;
F_22 ( F_23 ( V_11 ) , V_64 , V_6 -> V_8 ) ;
V_6 -> V_11 = V_11 ;
V_6 -> V_35 = F_5 ( V_65 ) ;
return F_49 ( V_9 , V_72 , V_6 , NULL , V_11 ,
F_38 ,
! ( F_40 ( V_6 ) -> V_62 & V_63 ) ) ;
}
static void F_51 ( struct V_1 * V_2 , const struct V_75 * V_76 )
{
F_52 ( F_53 ( F_54 ( * V_76 ) , V_23 ) !=
F_53 ( F_54 ( * V_76 ) , V_22 ) + sizeof( V_76 -> V_22 ) ) ;
memcpy ( & V_2 -> V_22 , & V_76 -> V_22 ,
sizeof( V_76 -> V_22 ) + sizeof( V_76 -> V_23 ) ) ;
}
int F_55 ( struct V_5 * V_6 , struct V_77 * V_78 )
{
struct V_20 * V_21 = V_6 -> V_21 ;
struct V_14 * V_15 = F_13 ( V_21 ) ;
struct V_24 * V_79 ;
struct V_75 * V_76 ;
struct V_26 * V_27 ;
struct V_1 * V_2 ;
int V_56 ;
F_56 () ;
V_79 = F_57 ( V_15 -> V_79 ) ;
V_76 = & V_78 -> V_80 . V_81 ;
V_27 = F_14 ( V_6 ) ;
if ( V_27 != NULL )
goto V_82;
V_27 = (struct V_26 * ) F_58 ( V_21 , 0 ) ;
if ( V_27 == NULL ) {
T_1 V_23 ;
V_23 = V_15 -> V_83 ;
if ( V_79 && V_79 -> V_25 . V_33 )
V_23 = V_79 -> V_25 . V_34 ;
V_27 = F_59 ( F_60 ( V_21 ) , V_76 , V_21 ,
V_23 , V_15 -> V_84 ,
V_15 -> V_85 ,
V_15 -> V_86 ,
V_21 -> V_36 ,
F_61 ( V_21 ) ,
V_21 -> V_87 ) ;
if ( F_34 ( V_27 ) )
goto V_88;
F_62 ( V_21 , & V_27 -> V_17 ) ;
}
F_63 ( V_6 , & V_27 -> V_17 ) ;
V_82:
if ( V_79 && V_79 -> V_25 . V_89 && V_27 -> V_90 )
goto V_88;
F_15 ( V_6 , sizeof( struct V_1 ) + ( V_79 ? V_79 -> V_25 . V_28 : 0 ) ) ;
F_16 ( V_6 ) ;
V_2 = F_4 ( V_6 ) ;
* ( ( V_91 * ) V_2 ) = F_5 ( ( 4 << 12 ) | ( 5 << 8 ) | ( V_15 -> V_30 & 0xff ) ) ;
if ( F_17 ( V_21 , & V_27 -> V_17 ) && ! V_6 -> V_92 )
V_2 -> V_31 = F_5 ( V_32 ) ;
else
V_2 -> V_31 = 0 ;
V_2 -> V_18 = F_10 ( V_15 , & V_27 -> V_17 ) ;
V_2 -> V_35 = V_21 -> V_36 ;
F_51 ( V_2 , V_76 ) ;
if ( V_79 && V_79 -> V_25 . V_28 ) {
V_2 -> V_4 += V_79 -> V_25 . V_28 >> 2 ;
F_19 ( V_6 , & V_79 -> V_25 , V_15 -> V_83 , V_27 , 0 ) ;
}
F_64 ( V_6 , & V_27 -> V_17 , V_21 ,
( F_65 ( V_6 ) -> V_93 ? : 1 ) - 1 ) ;
V_6 -> V_37 = V_21 -> V_38 ;
V_6 -> V_39 = V_21 -> V_40 ;
V_56 = F_8 ( V_6 ) ;
F_66 () ;
return V_56 ;
V_88:
F_66 () ;
F_67 ( F_60 ( V_21 ) , V_94 ) ;
F_27 ( V_6 ) ;
return - V_95 ;
}
static void F_68 ( struct V_5 * V_96 , struct V_5 * V_97 )
{
V_96 -> V_98 = V_97 -> V_98 ;
V_96 -> V_37 = V_97 -> V_37 ;
V_96 -> V_35 = V_97 -> V_35 ;
F_69 ( V_96 ) ;
F_70 ( V_96 , V_97 ) ;
V_96 -> V_11 = V_97 -> V_11 ;
V_96 -> V_39 = V_97 -> V_39 ;
F_40 ( V_96 ) -> V_62 = F_40 ( V_97 ) -> V_62 ;
#ifdef F_71
V_96 -> V_99 = V_97 -> V_99 ;
#endif
F_72 ( V_96 , V_97 ) ;
#if F_73 ( V_100 )
V_96 -> V_101 = V_97 -> V_101 ;
#endif
#if F_39 ( V_102 ) || F_39 ( V_103 )
V_96 -> V_104 = V_97 -> V_104 ;
#endif
F_74 ( V_96 , V_97 ) ;
}
int F_43 ( struct V_5 * V_6 , int (* F_75)( struct V_5 * ) )
{
struct V_1 * V_2 ;
int V_105 ;
struct V_41 * V_11 ;
struct V_5 * V_52 ;
unsigned int V_106 , V_107 , V_108 , V_8 , V_109 ;
int V_110 ;
V_91 V_111 ;
struct V_26 * V_27 = F_14 ( V_6 ) ;
int V_13 = 0 ;
V_11 = V_27 -> V_17 . V_11 ;
V_2 = F_4 ( V_6 ) ;
if ( F_24 ( ( ( V_2 -> V_31 & F_5 ( V_32 ) ) && ! V_6 -> V_92 ) ||
( F_40 ( V_6 ) -> V_112 &&
F_40 ( V_6 ) -> V_112 > F_76 ( & V_27 -> V_17 ) ) ) ) {
F_67 ( F_23 ( V_11 ) , V_113 ) ;
F_77 ( V_6 , V_114 , V_115 ,
F_78 ( F_41 ( V_6 ) ) ) ;
F_27 ( V_6 ) ;
return - V_116 ;
}
V_107 = V_2 -> V_4 * 4 ;
V_106 = F_76 ( & V_27 -> V_17 ) - V_107 ;
#ifdef F_79
if ( V_6 -> V_117 )
V_106 -= F_80 ( V_6 ) ;
#endif
F_40 ( V_6 ) -> V_62 |= V_118 ;
if ( F_81 ( V_6 ) ) {
struct V_5 * V_119 , * V_120 ;
int V_121 = F_82 ( V_6 ) ;
if ( V_121 - V_107 > V_106 ||
( ( V_121 - V_107 ) & 7 ) ||
F_83 ( V_2 ) ||
F_84 ( V_6 ) )
goto V_122;
F_85 (skb, frag) {
if ( V_119 -> V_8 > V_106 ||
( ( V_119 -> V_8 & 7 ) && V_119 -> V_123 ) ||
F_25 ( V_119 ) < V_107 )
goto V_124;
if ( F_86 ( V_119 ) )
goto V_124;
F_87 ( V_119 -> V_21 ) ;
if ( V_6 -> V_21 ) {
V_119 -> V_21 = V_6 -> V_21 ;
V_119 -> V_125 = V_126 ;
}
V_6 -> V_127 -= V_119 -> V_127 ;
}
V_13 = 0 ;
V_110 = 0 ;
V_119 = F_65 ( V_6 ) -> V_128 ;
F_88 ( V_6 ) ;
V_6 -> V_129 = V_121 - F_89 ( V_6 ) ;
V_6 -> V_8 = V_121 ;
V_2 -> V_7 = F_5 ( V_121 ) ;
V_2 -> V_31 = F_5 ( V_130 ) ;
F_1 ( V_2 ) ;
for (; ; ) {
if ( V_119 ) {
V_119 -> V_131 = V_132 ;
F_90 ( V_119 ) ;
F_91 ( V_119 , V_107 ) ;
F_16 ( V_119 ) ;
memcpy ( F_92 ( V_119 ) , V_2 , V_107 ) ;
V_2 = F_4 ( V_119 ) ;
V_2 -> V_7 = F_5 ( V_119 -> V_8 ) ;
F_68 ( V_119 , V_6 ) ;
if ( V_110 == 0 )
F_93 ( V_119 ) ;
V_110 += V_6 -> V_8 - V_107 ;
V_2 -> V_31 = F_5 ( V_110 >> 3 ) ;
if ( V_119 -> V_123 != NULL )
V_2 -> V_31 |= F_5 ( V_130 ) ;
F_1 ( V_2 ) ;
}
V_13 = F_75 ( V_6 ) ;
if ( ! V_13 )
F_67 ( F_23 ( V_11 ) , V_133 ) ;
if ( V_13 || ! V_119 )
break;
V_6 = V_119 ;
V_119 = V_6 -> V_123 ;
V_6 -> V_123 = NULL ;
}
if ( V_13 == 0 ) {
F_67 ( F_23 ( V_11 ) , V_134 ) ;
return 0 ;
}
while ( V_119 ) {
V_6 = V_119 -> V_123 ;
F_27 ( V_119 ) ;
V_119 = V_6 ;
}
F_67 ( F_23 ( V_11 ) , V_113 ) ;
return V_13 ;
V_124:
F_85 (skb, frag2) {
if ( V_120 == V_119 )
break;
V_120 -> V_21 = NULL ;
V_120 -> V_125 = NULL ;
V_6 -> V_127 += V_120 -> V_127 ;
}
}
V_122:
if ( ( V_6 -> V_131 == V_135 ) && F_94 ( V_6 ) )
goto V_136;
V_2 = F_4 ( V_6 ) ;
V_108 = V_6 -> V_8 - V_107 ;
V_105 = V_107 ;
V_109 = F_95 ( V_27 -> V_17 . V_11 , F_96 ( V_6 ) ) ;
V_110 = ( F_97 ( V_2 -> V_31 ) & V_137 ) << 3 ;
V_111 = V_2 -> V_31 & F_5 ( V_130 ) ;
while ( V_108 > 0 ) {
V_8 = V_108 ;
if ( V_8 > V_106 )
V_8 = V_106 ;
if ( V_8 < V_108 ) {
V_8 &= ~ 7 ;
}
if ( ( V_52 = F_98 ( V_8 + V_107 + V_109 , V_71 ) ) == NULL ) {
F_99 ( V_138 L_2 ) ;
V_13 = - V_53 ;
goto V_136;
}
F_68 ( V_52 , V_6 ) ;
F_100 ( V_52 , V_109 ) ;
F_101 ( V_52 , V_8 + V_107 ) ;
F_16 ( V_52 ) ;
V_52 -> V_139 = V_52 -> V_140 + V_107 ;
if ( V_6 -> V_21 )
F_28 ( V_52 , V_6 -> V_21 ) ;
F_102 ( V_6 , F_92 ( V_52 ) , V_107 ) ;
if ( F_103 ( V_6 , V_105 , F_104 ( V_52 ) , V_8 ) )
F_105 () ;
V_108 -= V_8 ;
V_2 = F_4 ( V_52 ) ;
V_2 -> V_31 = F_5 ( ( V_110 >> 3 ) ) ;
if ( V_110 == 0 )
F_93 ( V_6 ) ;
if ( V_108 > 0 || V_111 )
V_2 -> V_31 |= F_5 ( V_130 ) ;
V_105 += V_8 ;
V_110 += V_8 ;
V_2 -> V_7 = F_5 ( V_8 + V_107 ) ;
F_1 ( V_2 ) ;
V_13 = F_75 ( V_52 ) ;
if ( V_13 )
goto V_136;
F_67 ( F_23 ( V_11 ) , V_133 ) ;
}
F_29 ( V_6 ) ;
F_67 ( F_23 ( V_11 ) , V_134 ) ;
return V_13 ;
V_136:
F_27 ( V_6 ) ;
F_67 ( F_23 ( V_11 ) , V_113 ) ;
return V_13 ;
}
int
F_106 ( void * V_97 , char * V_96 , int V_110 , int V_8 , int V_141 , struct V_5 * V_6 )
{
struct V_142 * V_143 = V_97 ;
if ( V_6 -> V_131 == V_135 ) {
if ( F_107 ( V_96 , V_143 , V_110 , V_8 ) < 0 )
return - V_144 ;
} else {
T_3 V_145 = 0 ;
if ( F_108 ( V_96 , V_143 , V_110 , V_8 , & V_145 ) < 0 )
return - V_144 ;
V_6 -> V_145 = F_109 ( V_6 -> V_145 , V_145 , V_141 ) ;
}
return 0 ;
}
static inline T_3
F_110 ( struct V_146 * V_146 , int V_110 , int V_147 )
{
char * V_148 ;
T_3 V_145 ;
V_148 = F_111 ( V_146 ) ;
V_145 = F_112 ( V_148 + V_110 , V_147 , 0 ) ;
F_113 ( V_146 ) ;
return V_145 ;
}
static inline int F_114 ( struct V_20 * V_21 ,
struct V_149 * V_150 ,
int F_115 ( void * V_97 , char * V_96 , int V_110 , int V_8 ,
int V_141 , struct V_5 * V_6 ) ,
void * V_97 , int V_151 , int V_42 , int V_152 ,
int V_153 , int V_154 , unsigned int V_62 )
{
struct V_5 * V_6 ;
int V_13 ;
if ( ( V_6 = F_116 ( V_150 ) ) == NULL ) {
V_6 = F_117 ( V_21 ,
V_42 + V_152 + V_153 + 20 ,
( V_62 & V_155 ) , & V_13 ) ;
if ( V_6 == NULL )
return V_13 ;
F_100 ( V_6 , V_42 ) ;
F_101 ( V_6 , V_152 + V_153 ) ;
F_16 ( V_6 ) ;
V_6 -> V_139 = V_6 -> V_140 + V_152 ;
V_6 -> V_145 = 0 ;
F_118 ( V_150 , V_6 ) ;
} else if ( F_42 ( V_6 ) ) {
goto V_156;
}
V_6 -> V_131 = V_135 ;
F_65 ( V_6 ) -> V_157 = V_154 - V_152 ;
F_65 ( V_6 ) -> V_158 = V_159 ;
V_156:
return F_119 ( V_21 , V_6 , F_115 , V_97 ,
( V_151 - V_153 ) ) ;
}
static int F_120 ( struct V_20 * V_21 ,
struct V_75 * V_76 ,
struct V_149 * V_150 ,
struct V_160 * V_161 ,
struct V_162 * V_163 ,
int F_115 ( void * V_97 , char * V_96 , int V_110 ,
int V_8 , int V_141 , struct V_5 * V_6 ) ,
void * V_97 , int V_151 , int V_153 ,
unsigned int V_62 )
{
struct V_14 * V_15 = F_13 ( V_21 ) ;
struct V_5 * V_6 ;
struct V_164 * V_25 = V_161 -> V_25 ;
int V_42 ;
int V_165 ;
int V_106 ;
int V_147 ;
int V_13 ;
int V_110 = 0 ;
unsigned int V_154 , V_152 , V_166 ;
int V_167 = V_132 ;
struct V_26 * V_27 = (struct V_26 * ) V_161 -> V_17 ;
V_6 = F_116 ( V_150 ) ;
V_165 = ! V_6 ? V_27 -> V_17 . V_168 : 0 ;
V_106 = V_161 -> V_169 ;
V_42 = F_21 ( V_27 -> V_17 . V_11 ) ;
V_152 = sizeof( struct V_1 ) + ( V_25 ? V_25 -> V_28 : 0 ) ;
V_154 = ( ( V_106 - V_152 ) & ~ 7 ) + V_152 ;
V_166 = ( V_15 -> V_170 >= V_171 ) ?
V_106 : 0xFFFF ;
if ( V_161 -> V_151 + V_151 > V_166 - V_152 ) {
F_121 ( V_21 , V_116 , V_76 -> V_23 , V_15 -> V_85 ,
V_106 - ( V_25 ? V_25 -> V_28 : 0 ) ) ;
return - V_116 ;
}
if ( V_153 &&
V_151 + V_152 <= V_106 &&
V_27 -> V_17 . V_11 -> V_172 & V_173 &&
! V_165 )
V_167 = V_135 ;
V_161 -> V_151 += V_151 ;
if ( ( ( V_151 > V_106 ) || ( V_6 && F_42 ( V_6 ) ) ) &&
( V_21 -> V_36 == V_174 ) &&
( V_27 -> V_17 . V_11 -> V_172 & V_175 ) && ! V_27 -> V_17 . V_168 ) {
V_13 = F_114 ( V_21 , V_150 , F_115 , V_97 , V_151 ,
V_42 , V_152 , V_153 ,
V_154 , V_62 ) ;
if ( V_13 )
goto error;
return 0 ;
}
if ( ! V_6 )
goto V_176;
while ( V_151 > 0 ) {
V_147 = V_106 - V_6 -> V_8 ;
if ( V_147 < V_151 )
V_147 = V_154 - V_6 -> V_8 ;
if ( V_147 <= 0 ) {
char * V_177 ;
unsigned int V_178 ;
unsigned int V_179 ;
unsigned int V_180 ;
unsigned int V_181 ;
struct V_5 * V_182 ;
V_176:
V_182 = V_6 ;
if ( V_182 )
V_180 = V_182 -> V_8 - V_154 ;
else
V_180 = 0 ;
V_178 = V_151 + V_180 ;
if ( V_178 > V_106 - V_152 )
V_178 = V_154 - V_152 ;
V_179 = V_178 + V_152 ;
if ( ( V_62 & V_183 ) &&
! ( V_27 -> V_17 . V_11 -> V_172 & V_184 ) )
V_181 = V_106 ;
else
V_181 = V_179 ;
V_181 += V_165 ;
if ( V_178 == V_151 + V_180 )
V_181 += V_27 -> V_17 . V_185 ;
if ( V_153 ) {
V_6 = F_117 ( V_21 ,
V_181 + V_42 + 15 ,
( V_62 & V_155 ) , & V_13 ) ;
} else {
V_6 = NULL ;
if ( F_122 ( & V_21 -> V_186 ) <=
2 * V_21 -> V_187 )
V_6 = F_123 ( V_21 ,
V_181 + V_42 + 15 , 1 ,
V_21 -> V_188 ) ;
if ( F_24 ( V_6 == NULL ) )
V_13 = - V_189 ;
else
V_161 -> V_190 = 0 ;
}
if ( V_6 == NULL )
goto error;
V_6 -> V_131 = V_167 ;
V_6 -> V_145 = 0 ;
F_100 ( V_6 , V_42 ) ;
F_65 ( V_6 ) -> V_190 = V_161 -> V_190 ;
V_177 = F_101 ( V_6 , V_179 + V_165 ) ;
F_124 ( V_6 , V_165 ) ;
V_6 -> V_139 = ( V_6 -> V_140 +
V_152 ) ;
V_177 += V_152 + V_165 ;
if ( V_180 ) {
V_6 -> V_145 = F_125 (
V_182 , V_154 ,
V_177 + V_153 , V_180 , 0 ) ;
V_182 -> V_145 = F_126 ( V_182 -> V_145 ,
V_6 -> V_145 ) ;
V_177 += V_180 ;
F_127 ( V_182 , V_154 ) ;
}
V_147 = V_178 - V_153 - V_180 ;
if ( V_147 > 0 && F_115 ( V_97 , V_177 + V_153 , V_110 , V_147 , V_180 , V_6 ) < 0 ) {
V_13 = - V_144 ;
F_27 ( V_6 ) ;
goto error;
}
V_110 += V_147 ;
V_151 -= V_178 - V_180 ;
V_153 = 0 ;
V_165 = 0 ;
V_167 = V_132 ;
F_118 ( V_150 , V_6 ) ;
continue;
}
if ( V_147 > V_151 )
V_147 = V_151 ;
if ( ! ( V_27 -> V_17 . V_11 -> V_172 & V_184 ) ) {
unsigned int V_191 ;
V_191 = V_6 -> V_8 ;
if ( F_115 ( V_97 , F_101 ( V_6 , V_147 ) ,
V_110 , V_147 , V_191 , V_6 ) < 0 ) {
F_128 ( V_6 , V_191 ) ;
V_13 = - V_144 ;
goto error;
}
} else {
int V_192 = F_65 ( V_6 ) -> V_193 ;
V_13 = - V_53 ;
if ( ! F_129 ( V_21 , V_163 ) )
goto error;
if ( ! F_130 ( V_6 , V_192 , V_163 -> V_146 ,
V_163 -> V_110 ) ) {
V_13 = - V_116 ;
if ( V_192 == V_194 )
goto error;
F_131 ( V_6 , V_192 , V_163 -> V_146 ,
V_163 -> V_110 , 0 ) ;
F_65 ( V_6 ) -> V_193 = ++ V_192 ;
F_132 ( V_163 -> V_146 ) ;
}
V_147 = F_133 ( int , V_147 , V_163 -> V_195 - V_163 -> V_110 ) ;
if ( F_115 ( V_97 ,
F_134 ( V_163 -> V_146 ) + V_163 -> V_110 ,
V_110 , V_147 , V_6 -> V_8 , V_6 ) < 0 )
goto V_196;
V_163 -> V_110 += V_147 ;
F_135 ( & F_65 ( V_6 ) -> V_197 [ V_192 - 1 ] , V_147 ) ;
V_6 -> V_8 += V_147 ;
V_6 -> V_129 += V_147 ;
V_6 -> V_127 += V_147 ;
F_136 ( V_147 , & V_21 -> V_186 ) ;
}
V_110 += V_147 ;
V_151 -= V_147 ;
}
return 0 ;
V_196:
V_13 = - V_144 ;
error:
V_161 -> V_151 -= V_151 ;
F_67 ( F_60 ( V_21 ) , V_198 ) ;
return V_13 ;
}
static int F_137 ( struct V_20 * V_21 , struct V_160 * V_161 ,
struct V_199 * V_200 , struct V_26 * * V_201 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 ;
V_25 = V_200 -> V_25 ;
if ( V_25 ) {
if ( V_161 -> V_25 == NULL ) {
V_161 -> V_25 = F_138 ( sizeof( struct V_164 ) + 40 ,
V_21 -> V_188 ) ;
if ( F_24 ( V_161 -> V_25 == NULL ) )
return - V_189 ;
}
memcpy ( V_161 -> V_25 , & V_25 -> V_25 , sizeof( struct V_164 ) + V_25 -> V_25 . V_28 ) ;
V_161 -> V_62 |= V_202 ;
V_161 -> V_203 = V_200 -> V_203 ;
}
V_27 = * V_201 ;
if ( F_24 ( ! V_27 ) )
return - V_144 ;
* V_201 = NULL ;
V_161 -> V_169 = F_139 ( V_21 ) ?
F_76 ( & V_27 -> V_17 ) : V_27 -> V_17 . V_11 -> V_106 ;
V_161 -> V_17 = & V_27 -> V_17 ;
V_161 -> V_151 = 0 ;
V_161 -> V_18 = V_200 -> V_18 ;
V_161 -> V_30 = V_200 -> V_30 ;
V_161 -> V_37 = V_200 -> V_37 ;
V_161 -> V_190 = V_200 -> V_190 ;
return 0 ;
}
int F_140 ( struct V_20 * V_21 , struct V_75 * V_76 ,
int F_115 ( void * V_97 , char * V_96 , int V_110 , int V_8 ,
int V_141 , struct V_5 * V_6 ) ,
void * V_97 , int V_151 , int V_153 ,
struct V_199 * V_200 , struct V_26 * * V_201 ,
unsigned int V_62 )
{
struct V_14 * V_15 = F_13 ( V_21 ) ;
int V_13 ;
if ( V_62 & V_204 )
return 0 ;
if ( F_141 ( & V_21 -> V_205 ) ) {
V_13 = F_137 ( V_21 , & V_15 -> V_161 . V_206 , V_200 , V_201 ) ;
if ( V_13 )
return V_13 ;
} else {
V_153 = 0 ;
}
return F_120 ( V_21 , V_76 , & V_21 -> V_205 , & V_15 -> V_161 . V_206 ,
F_142 ( V_21 ) , F_115 ,
V_97 , V_151 , V_153 , V_62 ) ;
}
T_4 F_143 ( struct V_20 * V_21 , struct V_75 * V_76 , struct V_146 * V_146 ,
int V_110 , T_5 V_195 , int V_62 )
{
struct V_14 * V_15 = F_13 ( V_21 ) ;
struct V_5 * V_6 ;
struct V_26 * V_27 ;
struct V_164 * V_25 = NULL ;
struct V_160 * V_161 ;
int V_42 ;
int V_106 ;
int V_8 ;
int V_13 ;
unsigned int V_154 , V_152 , V_180 , V_166 ;
if ( V_15 -> V_207 )
return - V_208 ;
if ( V_62 & V_204 )
return 0 ;
if ( F_141 ( & V_21 -> V_205 ) )
return - V_58 ;
V_161 = & V_15 -> V_161 . V_206 ;
V_27 = (struct V_26 * ) V_161 -> V_17 ;
if ( V_161 -> V_62 & V_202 )
V_25 = V_161 -> V_25 ;
if ( ! ( V_27 -> V_17 . V_11 -> V_172 & V_184 ) )
return - V_209 ;
V_42 = F_21 ( V_27 -> V_17 . V_11 ) ;
V_106 = V_161 -> V_169 ;
V_152 = sizeof( struct V_1 ) + ( V_25 ? V_25 -> V_28 : 0 ) ;
V_154 = ( ( V_106 - V_152 ) & ~ 7 ) + V_152 ;
V_166 = ( V_15 -> V_170 >= V_171 ) ?
V_106 : 0xFFFF ;
if ( V_161 -> V_151 + V_195 > V_166 - V_152 ) {
F_121 ( V_21 , V_116 , V_76 -> V_23 , V_15 -> V_85 ,
V_106 - ( V_25 ? V_25 -> V_28 : 0 ) ) ;
return - V_116 ;
}
if ( ( V_6 = F_116 ( & V_21 -> V_205 ) ) == NULL )
return - V_58 ;
V_161 -> V_151 += V_195 ;
if ( ( V_195 + V_6 -> V_8 > V_106 ) &&
( V_21 -> V_36 == V_174 ) &&
( V_27 -> V_17 . V_11 -> V_172 & V_175 ) ) {
F_65 ( V_6 ) -> V_157 = V_106 - V_152 ;
F_65 ( V_6 ) -> V_158 = V_159 ;
}
while ( V_195 > 0 ) {
int V_192 ;
if ( F_42 ( V_6 ) )
V_8 = V_195 ;
else {
V_8 = V_106 - V_6 -> V_8 ;
if ( V_8 < V_195 )
V_8 = V_154 - V_6 -> V_8 ;
}
if ( V_8 <= 0 ) {
struct V_5 * V_182 ;
int V_181 ;
V_182 = V_6 ;
V_180 = V_182 -> V_8 - V_154 ;
V_181 = V_152 + V_42 + V_180 + 15 ;
V_6 = F_123 ( V_21 , V_181 , 1 , V_21 -> V_188 ) ;
if ( F_24 ( ! V_6 ) ) {
V_13 = - V_189 ;
goto error;
}
V_6 -> V_131 = V_132 ;
V_6 -> V_145 = 0 ;
F_100 ( V_6 , V_42 ) ;
F_101 ( V_6 , V_152 + V_180 ) ;
F_16 ( V_6 ) ;
V_6 -> V_139 = ( V_6 -> V_140 +
V_152 ) ;
if ( V_180 ) {
V_6 -> V_145 = F_125 ( V_182 ,
V_154 ,
F_104 ( V_6 ) ,
V_180 , 0 ) ;
V_182 -> V_145 = F_126 ( V_182 -> V_145 ,
V_6 -> V_145 ) ;
F_127 ( V_182 , V_154 ) ;
}
F_118 ( & V_21 -> V_205 , V_6 ) ;
continue;
}
V_192 = F_65 ( V_6 ) -> V_193 ;
if ( V_8 > V_195 )
V_8 = V_195 ;
if ( F_130 ( V_6 , V_192 , V_146 , V_110 ) ) {
F_135 ( & F_65 ( V_6 ) -> V_197 [ V_192 - 1 ] , V_8 ) ;
} else if ( V_192 < V_194 ) {
F_132 ( V_146 ) ;
F_144 ( V_6 , V_192 , V_146 , V_110 , V_8 ) ;
} else {
V_13 = - V_116 ;
goto error;
}
if ( V_6 -> V_131 == V_132 ) {
T_3 V_145 ;
V_145 = F_110 ( V_146 , V_110 , V_8 ) ;
V_6 -> V_145 = F_109 ( V_6 -> V_145 , V_145 , V_6 -> V_8 ) ;
}
V_6 -> V_8 += V_8 ;
V_6 -> V_129 += V_8 ;
V_6 -> V_127 += V_8 ;
F_136 ( V_8 , & V_21 -> V_186 ) ;
V_110 += V_8 ;
V_195 -= V_8 ;
}
return 0 ;
error:
V_161 -> V_151 -= V_195 ;
F_67 ( F_60 ( V_21 ) , V_198 ) ;
return V_13 ;
}
static void F_145 ( struct V_160 * V_161 )
{
V_161 -> V_62 &= ~ V_202 ;
F_146 ( V_161 -> V_25 ) ;
V_161 -> V_25 = NULL ;
F_147 ( V_161 -> V_17 ) ;
V_161 -> V_17 = NULL ;
}
struct V_5 * F_148 ( struct V_20 * V_21 ,
struct V_75 * V_76 ,
struct V_149 * V_150 ,
struct V_160 * V_161 )
{
struct V_5 * V_6 , * V_210 ;
struct V_5 * * V_211 ;
struct V_14 * V_15 = F_13 ( V_21 ) ;
struct V_212 * V_212 = F_60 ( V_21 ) ;
struct V_164 * V_25 = NULL ;
struct V_26 * V_27 = (struct V_26 * ) V_161 -> V_17 ;
struct V_1 * V_2 ;
V_91 V_213 = 0 ;
T_6 V_18 ;
if ( ( V_6 = F_149 ( V_150 ) ) == NULL )
goto V_214;
V_211 = & ( F_65 ( V_6 ) -> V_128 ) ;
if ( V_6 -> V_177 < F_92 ( V_6 ) )
F_150 ( V_6 , F_151 ( V_6 ) ) ;
while ( ( V_210 = F_149 ( V_150 ) ) != NULL ) {
F_150 ( V_210 , F_152 ( V_6 ) ) ;
* V_211 = V_210 ;
V_211 = & ( V_210 -> V_123 ) ;
V_6 -> V_8 += V_210 -> V_8 ;
V_6 -> V_129 += V_210 -> V_8 ;
V_6 -> V_127 += V_210 -> V_127 ;
V_210 -> V_125 = NULL ;
V_210 -> V_21 = NULL ;
}
if ( V_15 -> V_170 < V_171 )
V_6 -> V_92 = 1 ;
if ( V_15 -> V_170 == V_171 ||
V_15 -> V_170 == V_215 ||
( V_6 -> V_8 <= F_76 ( & V_27 -> V_17 ) &&
F_17 ( V_21 , & V_27 -> V_17 ) ) )
V_213 = F_5 ( V_32 ) ;
if ( V_161 -> V_62 & V_202 )
V_25 = V_161 -> V_25 ;
if ( V_161 -> V_18 != 0 )
V_18 = V_161 -> V_18 ;
else if ( V_27 -> V_46 == V_47 )
V_18 = V_15 -> V_216 ;
else
V_18 = F_10 ( V_15 , & V_27 -> V_17 ) ;
V_2 = F_4 ( V_6 ) ;
V_2 -> V_29 = 4 ;
V_2 -> V_4 = 5 ;
V_2 -> V_30 = ( V_161 -> V_30 != - 1 ) ? V_161 -> V_30 : V_15 -> V_30 ;
V_2 -> V_31 = V_213 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_35 = V_21 -> V_36 ;
F_51 ( V_2 , V_76 ) ;
F_18 ( V_6 , & V_27 -> V_17 , V_21 ) ;
if ( V_25 ) {
V_2 -> V_4 += V_25 -> V_28 >> 2 ;
F_19 ( V_6 , V_25 , V_161 -> V_203 , V_27 , 0 ) ;
}
V_6 -> V_37 = ( V_161 -> V_30 != - 1 ) ? V_161 -> V_37 : V_21 -> V_38 ;
V_6 -> V_39 = V_21 -> V_40 ;
V_161 -> V_17 = NULL ;
F_153 ( V_6 , & V_27 -> V_17 ) ;
if ( V_2 -> V_35 == V_217 )
F_154 ( V_212 , ( (struct V_218 * )
F_104 ( V_6 ) ) -> type ) ;
F_145 ( V_161 ) ;
V_214:
return V_6 ;
}
int F_155 ( struct V_212 * V_212 , struct V_5 * V_6 )
{
int V_13 ;
V_13 = F_8 ( V_6 ) ;
if ( V_13 ) {
if ( V_13 > 0 )
V_13 = F_156 ( V_13 ) ;
if ( V_13 )
F_67 ( V_212 , V_198 ) ;
}
return V_13 ;
}
int F_157 ( struct V_20 * V_21 , struct V_75 * V_76 )
{
struct V_5 * V_6 ;
V_6 = F_158 ( V_21 , V_76 ) ;
if ( ! V_6 )
return 0 ;
return F_155 ( F_60 ( V_21 ) , V_6 ) ;
}
static void F_159 ( struct V_20 * V_21 ,
struct V_149 * V_150 ,
struct V_160 * V_161 )
{
struct V_5 * V_6 ;
while ( ( V_6 = F_160 ( V_150 ) ) != NULL )
F_27 ( V_6 ) ;
F_145 ( V_161 ) ;
}
void F_161 ( struct V_20 * V_21 )
{
F_159 ( V_21 , & V_21 -> V_205 , & F_13 ( V_21 ) -> V_161 . V_206 ) ;
}
struct V_5 * F_162 ( struct V_20 * V_21 ,
struct V_75 * V_76 ,
int F_115 ( void * V_97 , char * V_96 , int V_110 ,
int V_8 , int V_141 , struct V_5 * V_6 ) ,
void * V_97 , int V_151 , int V_153 ,
struct V_199 * V_200 , struct V_26 * * V_201 ,
unsigned int V_62 )
{
struct V_160 V_161 ;
struct V_149 V_150 ;
int V_13 ;
if ( V_62 & V_204 )
return NULL ;
F_163 ( & V_150 ) ;
V_161 . V_62 = 0 ;
V_161 . V_203 = 0 ;
V_161 . V_25 = NULL ;
V_13 = F_137 ( V_21 , & V_161 , V_200 , V_201 ) ;
if ( V_13 )
return F_164 ( V_13 ) ;
V_13 = F_120 ( V_21 , V_76 , & V_150 , & V_161 ,
& V_219 -> V_220 , F_115 ,
V_97 , V_151 , V_153 , V_62 ) ;
if ( V_13 ) {
F_159 ( V_21 , & V_150 , & V_161 ) ;
return F_164 ( V_13 ) ;
}
return F_148 ( V_21 , V_76 , & V_150 , & V_161 ) ;
}
static int F_165 ( void * V_221 , char * V_96 , int V_110 ,
int V_8 , int V_141 , struct V_5 * V_6 )
{
T_3 V_145 ;
V_145 = F_166 ( V_221 + V_110 , V_96 , V_8 , 0 ) ;
V_6 -> V_145 = F_109 ( V_6 -> V_145 , V_145 , V_141 ) ;
return 0 ;
}
void F_167 ( struct V_212 * V_212 , struct V_5 * V_6 , T_1 V_23 ,
T_1 V_22 , const struct V_222 * V_223 ,
unsigned int V_8 )
{
struct V_224 V_225 ;
struct V_199 V_200 ;
struct V_75 V_76 ;
struct V_26 * V_27 = F_14 ( V_6 ) ;
struct V_5 * V_226 ;
struct V_20 * V_21 ;
struct V_14 * V_15 ;
if ( F_168 ( & V_225 . V_25 . V_25 , V_6 ) )
return;
V_200 . V_203 = V_23 ;
V_200 . V_25 = NULL ;
V_200 . V_190 = 0 ;
V_200 . V_18 = 0 ;
V_200 . V_30 = - 1 ;
if ( V_225 . V_25 . V_25 . V_28 ) {
V_200 . V_25 = & V_225 . V_25 ;
if ( V_225 . V_25 . V_25 . V_33 )
V_23 = V_225 . V_25 . V_25 . V_34 ;
}
F_169 ( & V_76 , V_223 -> V_227 , 0 ,
F_170 ( V_223 -> V_30 ) ,
V_228 , F_4 ( V_6 ) -> V_35 ,
F_171 ( V_223 ) ,
V_23 , V_22 ,
F_172 ( V_6 ) -> V_229 , F_172 ( V_6 ) -> V_230 ) ;
F_173 ( V_6 , F_174 ( & V_76 ) ) ;
V_27 = F_175 ( V_212 , & V_76 ) ;
if ( F_34 ( V_27 ) )
return;
V_15 = & F_176 ( V_231 ) ;
V_15 -> V_30 = V_223 -> V_30 ;
V_21 = & V_15 -> V_21 ;
V_21 -> V_38 = V_6 -> V_37 ;
V_21 -> V_36 = F_4 ( V_6 ) -> V_35 ;
V_21 -> V_87 = V_223 -> V_227 ;
F_177 ( V_21 , V_212 ) ;
F_163 ( & V_21 -> V_205 ) ;
V_21 -> V_187 = V_232 ;
F_140 ( V_21 , & V_76 , F_165 , V_223 -> V_143 -> V_233 , V_8 , 0 ,
& V_200 , & V_27 , V_155 ) ;
V_226 = F_178 ( & V_21 -> V_205 ) ;
if ( V_226 ) {
if ( V_223 -> V_234 >= 0 )
* ( ( V_235 * ) F_104 ( V_226 ) +
V_223 -> V_234 ) = F_179 ( F_180 ( V_226 -> V_145 ,
V_223 -> V_145 ) ) ;
V_226 -> V_131 = V_132 ;
F_181 ( V_226 ) ;
F_182 ( V_226 , F_183 ( V_6 ) ) ;
F_157 ( V_21 , & V_76 ) ;
}
F_184 ( V_231 ) ;
F_185 ( V_27 ) ;
}
void T_7 F_186 ( void )
{
F_187 () ;
F_188 () ;
#if F_39 ( V_236 ) && F_39 ( V_237 )
F_189 () ;
#endif
}
