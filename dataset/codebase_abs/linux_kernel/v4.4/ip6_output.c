static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
int V_14 ;
V_5 -> V_15 = F_3 ( V_16 ) ;
V_5 -> V_9 = V_9 ;
if ( F_4 ( & F_5 ( V_5 ) -> V_17 ) ) {
struct V_18 * V_19 = F_6 ( F_2 ( V_5 ) ) ;
if ( ! ( V_9 -> V_20 & V_21 ) && F_7 ( V_3 ) &&
( ( F_8 ( V_1 , V_5 ) &&
! ( F_9 ( V_5 ) -> V_20 & V_22 ) ) ||
F_10 ( V_9 , & F_5 ( V_5 ) -> V_17 ,
& F_5 ( V_5 ) -> V_23 ) ) ) {
struct V_4 * V_24 = F_11 ( V_5 , V_25 ) ;
if ( V_24 )
F_12 ( V_26 , V_27 ,
V_1 , V_3 , V_24 , NULL , V_24 -> V_9 ,
V_28 ) ;
if ( F_5 ( V_5 ) -> V_29 == 0 ) {
F_13 ( V_1 , V_19 ,
V_30 ) ;
F_14 ( V_5 ) ;
return 0 ;
}
}
F_15 ( V_1 , V_19 , V_31 , V_5 -> V_32 ) ;
if ( F_16 ( & F_5 ( V_5 ) -> V_17 ) <=
V_33 &&
! ( V_9 -> V_20 & V_21 ) ) {
F_14 ( V_5 ) ;
return 0 ;
}
}
F_17 () ;
V_13 = F_18 ( (struct V_34 * ) V_7 , & F_5 ( V_5 ) -> V_17 ) ;
V_11 = F_19 ( V_7 -> V_9 , V_13 ) ;
if ( F_20 ( ! V_11 ) )
V_11 = F_21 ( & V_35 , V_13 , V_7 -> V_9 , false ) ;
if ( ! F_22 ( V_11 ) ) {
V_14 = F_23 ( V_7 , V_11 , V_5 ) ;
F_24 () ;
return V_14 ;
}
F_24 () ;
F_13 ( V_1 , F_6 ( V_7 ) , V_36 ) ;
F_14 ( V_5 ) ;
return - V_37 ;
}
static int F_25 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
if ( ( V_5 -> V_32 > F_26 ( V_5 ) && ! F_27 ( V_5 ) ) ||
F_28 ( F_2 ( V_5 ) ) ||
( F_9 ( V_5 ) -> V_38 && V_5 -> V_32 > F_9 ( V_5 ) -> V_38 ) )
return F_29 ( V_1 , V_3 , V_5 , F_1 ) ;
else
return F_1 ( V_1 , V_3 , V_5 ) ;
}
int F_30 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_8 * V_9 = F_2 ( V_5 ) -> V_9 ;
struct V_18 * V_19 = F_6 ( F_2 ( V_5 ) ) ;
if ( F_20 ( V_19 -> V_39 . V_40 ) ) {
F_13 ( V_1 , V_19 , V_30 ) ;
F_14 ( V_5 ) ;
return 0 ;
}
return F_31 ( V_26 , V_27 ,
V_1 , V_3 , V_5 , NULL , V_9 ,
F_25 ,
! ( F_9 ( V_5 ) -> V_20 & V_41 ) ) ;
}
int F_32 ( const struct V_2 * V_3 , struct V_4 * V_5 , struct V_42 * V_43 ,
struct V_44 * V_45 , int V_46 )
{
struct V_1 * V_1 = F_33 ( V_3 ) ;
const struct V_47 * V_48 = F_34 ( V_3 ) ;
struct V_12 * V_49 = & V_43 -> V_17 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_50 * V_51 ;
T_1 V_52 = V_43 -> V_53 ;
int V_54 = V_5 -> V_32 ;
int V_55 = - 1 ;
T_2 V_56 ;
if ( V_45 ) {
unsigned int V_57 ;
V_57 = V_45 -> V_58 + V_45 -> V_59 ;
V_54 += V_57 ;
V_57 += sizeof( struct V_50 ) + F_35 ( V_7 -> V_9 ) ;
if ( F_36 ( V_5 ) < V_57 ) {
struct V_4 * V_60 = F_37 ( V_5 , V_57 ) ;
if ( ! V_60 ) {
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_30 ) ;
F_14 ( V_5 ) ;
return - V_61 ;
}
F_38 ( V_5 ) ;
V_5 = V_60 ;
F_39 ( V_5 , (struct V_2 * ) V_3 ) ;
}
if ( V_45 -> V_59 )
F_40 ( V_5 , V_45 , & V_52 ) ;
if ( V_45 -> V_58 )
F_41 ( V_5 , V_45 , & V_52 , & V_49 ) ;
}
F_42 ( V_5 , sizeof( struct V_50 ) ) ;
F_43 ( V_5 ) ;
V_51 = F_5 ( V_5 ) ;
if ( V_48 )
V_55 = V_48 -> V_29 ;
if ( V_55 < 0 )
V_55 = F_44 ( V_7 ) ;
F_45 ( V_51 , V_46 , F_46 ( V_1 , V_5 , V_43 -> V_62 ,
V_48 -> V_63 , V_43 ) ) ;
V_51 -> V_64 = F_3 ( V_54 ) ;
V_51 -> V_65 = V_52 ;
V_51 -> V_29 = V_55 ;
V_51 -> V_23 = V_43 -> V_23 ;
V_51 -> V_17 = * V_49 ;
V_5 -> V_15 = F_3 ( V_16 ) ;
V_5 -> V_66 = V_3 -> V_67 ;
V_5 -> V_68 = V_3 -> V_69 ;
V_56 = F_47 ( V_7 ) ;
if ( ( V_5 -> V_32 <= V_56 ) || V_5 -> V_70 || F_27 ( V_5 ) ) {
F_15 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_71 , V_5 -> V_32 ) ;
return F_12 ( V_26 , V_72 ,
V_1 , (struct V_2 * ) V_3 , V_5 , NULL , V_7 -> V_9 ,
V_73 ) ;
}
V_5 -> V_9 = V_7 -> V_9 ;
F_48 ( (struct V_2 * ) V_3 , V_74 , V_43 , V_56 ) ;
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) , V_75 ) ;
F_14 ( V_5 ) ;
return - V_74 ;
}
static int F_49 ( struct V_4 * V_5 , int V_76 )
{
struct V_77 * V_78 ;
struct V_2 * V_79 = NULL ;
F_50 ( & V_80 ) ;
for ( V_78 = V_77 ; V_78 ; V_78 = V_78 -> V_81 ) {
struct V_2 * V_3 = V_78 -> V_3 ;
if ( V_3 && V_78 -> V_76 == V_76 &&
( ! V_3 -> V_82 ||
V_3 -> V_82 == V_5 -> V_9 -> V_83 ) ) {
if ( V_79 ) {
struct V_4 * V_60 = F_11 ( V_5 , V_25 ) ;
if ( V_60 )
F_51 ( V_79 , V_60 ) ;
}
V_79 = V_3 ;
}
}
if ( V_79 ) {
F_51 ( V_79 , V_5 ) ;
F_52 ( & V_80 ) ;
return 1 ;
}
F_52 ( & V_80 ) ;
return 0 ;
}
static int F_53 ( struct V_4 * V_5 )
{
struct V_50 * V_51 = F_5 ( V_5 ) ;
T_1 V_65 = V_51 -> V_65 ;
T_3 V_84 ;
int V_85 ;
if ( F_54 ( V_65 ) ) {
V_85 = F_55 ( V_5 , sizeof( * V_51 ) , & V_65 , & V_84 ) ;
if ( V_85 < 0 )
return 0 ;
} else
V_85 = sizeof( struct V_50 ) ;
if ( V_65 == V_86 ) {
struct V_87 * V_88 ;
if ( ! F_56 ( V_5 , ( F_57 ( V_5 ) +
V_85 + 1 - V_5 -> V_89 ) ) )
return 0 ;
V_88 = (struct V_87 * ) ( F_57 ( V_5 ) + V_85 ) ;
switch ( V_88 -> V_90 ) {
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
return 1 ;
default:
break;
}
}
if ( F_58 ( & V_51 -> V_17 ) & V_96 ) {
F_59 ( V_5 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_60 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
F_61 ( V_5 ) ;
return V_73 ( V_1 , V_3 , V_5 ) ;
}
static unsigned int F_62 ( const struct V_6 * V_7 )
{
unsigned int V_56 ;
struct V_18 * V_19 ;
if ( F_63 ( V_7 , V_97 ) ) {
V_56 = F_64 ( V_7 , V_97 ) ;
if ( V_56 )
return V_56 ;
}
V_56 = V_98 ;
F_65 () ;
V_19 = F_66 ( V_7 -> V_9 ) ;
if ( V_19 )
V_56 = V_19 -> V_39 . V_99 ;
F_67 () ;
return V_56 ;
}
static bool F_68 ( const struct V_4 * V_5 , unsigned int V_56 )
{
if ( V_5 -> V_32 <= V_56 )
return false ;
if ( F_9 ( V_5 ) -> V_38 && F_9 ( V_5 ) -> V_38 > V_56 )
return true ;
if ( V_5 -> V_70 )
return false ;
if ( F_27 ( V_5 ) && F_69 ( V_5 ) <= V_56 )
return false ;
return true ;
}
int F_70 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_50 * V_51 = F_5 ( V_5 ) ;
struct V_100 * V_45 = F_9 ( V_5 ) ;
struct V_1 * V_1 = F_71 ( V_7 -> V_9 ) ;
T_2 V_56 ;
if ( V_1 -> V_101 . V_102 -> V_103 == 0 )
goto error;
if ( V_5 -> V_104 != V_105 )
goto V_106;
if ( F_20 ( V_5 -> V_3 ) )
goto V_106;
if ( F_72 ( V_5 ) )
goto V_106;
if ( ! F_73 ( NULL , V_107 , V_5 ) ) {
F_74 ( V_1 , F_6 ( V_7 ) ,
V_108 ) ;
goto V_106;
}
F_75 ( V_5 ) ;
if ( F_20 ( V_45 -> V_20 & V_109 ) ) {
if ( F_49 ( V_5 , F_76 ( V_45 -> V_78 ) ) )
return 0 ;
}
if ( V_51 -> V_29 <= 1 ) {
V_5 -> V_9 = V_7 -> V_9 ;
F_77 ( V_5 , V_110 , V_111 , 0 ) ;
F_74 ( V_1 , F_6 ( V_7 ) ,
V_112 ) ;
F_14 ( V_5 ) ;
return - V_113 ;
}
if ( V_1 -> V_101 . V_102 -> V_114 &&
F_78 ( & V_35 , V_1 , & V_51 -> V_17 , V_5 -> V_9 , 0 ) ) {
int V_115 = F_53 ( V_5 ) ;
if ( V_115 > 0 )
return F_79 ( V_5 ) ;
else if ( V_115 < 0 ) {
F_74 ( V_1 , F_6 ( V_7 ) ,
V_108 ) ;
goto V_106;
}
}
if ( ! F_80 ( V_5 ) ) {
F_74 ( V_1 , F_6 ( V_7 ) ,
V_108 ) ;
goto V_106;
}
V_7 = F_2 ( V_5 ) ;
if ( V_5 -> V_9 == V_7 -> V_9 && V_45 -> V_116 == 0 && ! F_81 ( V_5 ) ) {
struct V_12 * V_117 = NULL ;
struct V_118 * V_119 ;
struct V_34 * V_120 ;
V_120 = (struct V_34 * ) V_7 ;
if ( V_120 -> V_121 & V_122 )
V_117 = & V_120 -> V_123 ;
else
V_117 = & V_51 -> V_17 ;
V_119 = F_82 ( V_1 -> V_101 . V_124 , & V_51 -> V_17 , 1 ) ;
if ( F_83 ( V_119 , 1 * V_125 ) )
F_84 ( V_5 , V_117 ) ;
if ( V_119 )
F_85 ( V_119 ) ;
} else {
int V_126 = F_58 ( & V_51 -> V_23 ) ;
if ( V_126 == V_127 ||
V_126 & ( V_128 | V_129 ) )
goto error;
if ( V_126 & V_96 ) {
F_77 ( V_5 , V_130 ,
V_131 , 0 ) ;
goto error;
}
}
V_56 = F_62 ( V_7 ) ;
if ( V_56 < V_98 )
V_56 = V_98 ;
if ( F_68 ( V_5 , V_56 ) ) {
V_5 -> V_9 = V_7 -> V_9 ;
F_77 ( V_5 , V_132 , 0 , V_56 ) ;
F_74 ( V_1 , F_6 ( V_7 ) ,
V_133 ) ;
F_74 ( V_1 , F_6 ( V_7 ) ,
V_75 ) ;
F_14 ( V_5 ) ;
return - V_74 ;
}
if ( F_86 ( V_5 , V_7 -> V_9 -> V_134 ) ) {
F_74 ( V_1 , F_6 ( V_7 ) ,
V_30 ) ;
goto V_106;
}
V_51 = F_5 ( V_5 ) ;
V_51 -> V_29 -- ;
F_74 ( V_1 , F_6 ( V_7 ) , V_135 ) ;
F_87 ( V_1 , F_6 ( V_7 ) , V_136 , V_5 -> V_32 ) ;
return F_12 ( V_26 , V_137 ,
V_1 , NULL , V_5 , V_5 -> V_9 , V_7 -> V_9 ,
F_60 ) ;
error:
F_74 ( V_1 , F_6 ( V_7 ) , V_138 ) ;
V_106:
F_14 ( V_5 ) ;
return - V_37 ;
}
static void F_88 ( struct V_4 * V_139 , struct V_4 * V_140 )
{
V_139 -> V_104 = V_140 -> V_104 ;
V_139 -> V_66 = V_140 -> V_66 ;
V_139 -> V_15 = V_140 -> V_15 ;
F_89 ( V_139 ) ;
F_90 ( V_139 , F_91 ( F_2 ( V_140 ) ) ) ;
V_139 -> V_9 = V_140 -> V_9 ;
V_139 -> V_68 = V_140 -> V_68 ;
#ifdef F_92
V_139 -> V_141 = V_140 -> V_141 ;
#endif
F_93 ( V_139 , V_140 ) ;
F_94 ( V_139 , V_140 ) ;
}
int F_29 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 ,
int (* F_95)( struct V_1 * , struct V_2 * , struct V_4 * ) )
{
struct V_4 * V_142 ;
struct V_34 * V_120 = (struct V_34 * ) F_2 ( V_5 ) ;
struct V_47 * V_48 = V_5 -> V_3 && ! F_96 () ?
F_34 ( V_5 -> V_3 ) : NULL ;
struct V_50 * V_143 ;
struct V_144 * V_145 ;
unsigned int V_56 , V_146 , V_147 , V_32 ;
int V_148 , V_149 ;
T_4 V_150 ;
int V_151 , V_85 = 0 , V_152 = 0 ;
T_1 * V_153 , V_65 = 0 ;
V_146 = F_97 ( V_5 , & V_153 ) ;
V_65 = * V_153 ;
V_56 = F_26 ( V_5 ) ;
if ( F_20 ( ! V_5 -> V_70 && V_5 -> V_32 > V_56 ) )
goto V_154;
if ( F_9 ( V_5 ) -> V_38 ) {
if ( F_9 ( V_5 ) -> V_38 > V_56 )
goto V_154;
V_56 = F_9 ( V_5 ) -> V_38 ;
if ( V_56 < V_98 )
V_56 = V_98 ;
}
if ( V_48 && V_48 -> V_155 < V_56 ) {
if ( V_48 -> V_155 )
V_56 = V_48 -> V_155 ;
}
if ( V_56 < V_146 + sizeof( struct V_144 ) + 8 )
goto V_154;
V_56 -= V_146 + sizeof( struct V_144 ) ;
V_150 = F_98 ( V_1 , & F_5 ( V_5 ) -> V_17 ,
& F_5 ( V_5 ) -> V_23 ) ;
if ( V_5 -> V_156 == V_157 &&
( V_152 = F_99 ( V_5 ) ) )
goto V_158;
V_148 = F_35 ( V_120 -> V_7 . V_9 ) ;
if ( F_100 ( V_5 ) ) {
int V_159 = F_101 ( V_5 ) ;
struct V_4 * V_160 ;
if ( V_159 - V_146 > V_56 ||
( ( V_159 - V_146 ) & 7 ) ||
F_102 ( V_5 ) ||
F_36 ( V_5 ) < ( V_148 + sizeof( struct V_144 ) ) )
goto V_161;
F_103 (skb, frag) {
if ( V_142 -> V_32 > V_56 ||
( ( V_142 -> V_32 & 7 ) && V_142 -> V_81 ) ||
F_36 ( V_142 ) < ( V_146 + V_148 + sizeof( struct V_144 ) ) )
goto V_162;
if ( F_104 ( V_142 ) )
goto V_162;
F_105 ( V_142 -> V_3 ) ;
if ( V_5 -> V_3 ) {
V_142 -> V_3 = V_5 -> V_3 ;
V_142 -> V_163 = V_164 ;
}
V_5 -> V_165 -= V_142 -> V_165 ;
}
V_152 = 0 ;
V_85 = 0 ;
* V_153 = V_166 ;
V_143 = F_106 ( F_57 ( V_5 ) , V_146 , V_25 ) ;
if ( ! V_143 ) {
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_75 ) ;
V_152 = - V_167 ;
goto V_158;
}
V_142 = F_107 ( V_5 ) -> V_168 ;
F_108 ( V_5 ) ;
F_109 ( V_5 , V_146 ) ;
V_145 = (struct V_144 * ) F_110 ( V_5 , sizeof( struct V_144 ) ) ;
F_110 ( V_5 , V_146 ) ;
F_43 ( V_5 ) ;
memcpy ( F_57 ( V_5 ) , V_143 , V_146 ) ;
V_145 -> V_65 = V_65 ;
V_145 -> V_169 = 0 ;
V_145 -> V_84 = F_3 ( V_170 ) ;
V_145 -> V_171 = V_150 ;
V_159 = F_101 ( V_5 ) ;
V_5 -> V_172 = V_159 - F_111 ( V_5 ) ;
V_5 -> V_32 = V_159 ;
F_5 ( V_5 ) -> V_64 = F_3 ( V_159 -
sizeof( struct V_50 ) ) ;
F_112 ( & V_120 -> V_7 ) ;
for (; ; ) {
if ( V_142 ) {
V_142 -> V_156 = V_173 ;
F_113 ( V_142 ) ;
V_145 = (struct V_144 * ) F_110 ( V_142 , sizeof( struct V_144 ) ) ;
F_110 ( V_142 , V_146 ) ;
F_43 ( V_142 ) ;
memcpy ( F_57 ( V_142 ) , V_143 ,
V_146 ) ;
V_85 += V_5 -> V_32 - V_146 - sizeof( struct V_144 ) ;
V_145 -> V_65 = V_65 ;
V_145 -> V_169 = 0 ;
V_145 -> V_84 = F_3 ( V_85 ) ;
if ( V_142 -> V_81 )
V_145 -> V_84 |= F_3 ( V_170 ) ;
V_145 -> V_171 = V_150 ;
F_5 ( V_142 ) -> V_64 =
F_3 ( V_142 -> V_32 -
sizeof( struct V_50 ) ) ;
F_88 ( V_142 , V_5 ) ;
}
V_152 = F_95 ( V_1 , V_3 , V_5 ) ;
if ( ! V_152 )
F_13 ( V_1 , F_6 ( & V_120 -> V_7 ) ,
V_174 ) ;
if ( V_152 || ! V_142 )
break;
V_5 = V_142 ;
V_142 = V_5 -> V_81 ;
V_5 -> V_81 = NULL ;
}
F_114 ( V_143 ) ;
if ( V_152 == 0 ) {
F_13 ( V_1 , F_6 ( & V_120 -> V_7 ) ,
V_175 ) ;
F_115 ( V_120 ) ;
return 0 ;
}
F_116 ( V_142 ) ;
F_13 ( V_1 , F_6 ( & V_120 -> V_7 ) ,
V_75 ) ;
F_115 ( V_120 ) ;
return V_152 ;
V_162:
F_103 (skb, frag2) {
if ( V_160 == V_142 )
break;
V_160 -> V_3 = NULL ;
V_160 -> V_163 = NULL ;
V_5 -> V_165 += V_160 -> V_165 ;
}
}
V_161:
V_147 = V_5 -> V_32 - V_146 ;
V_151 = V_146 ;
* V_153 = V_166 ;
V_149 = V_120 -> V_7 . V_9 -> V_176 ;
while ( V_147 > 0 ) {
V_32 = V_147 ;
if ( V_32 > V_56 )
V_32 = V_56 ;
if ( V_32 < V_147 ) {
V_32 &= ~ 7 ;
}
V_142 = F_117 ( V_32 + V_146 + sizeof( struct V_144 ) +
V_148 + V_149 , V_25 ) ;
if ( ! V_142 ) {
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_75 ) ;
V_152 = - V_167 ;
goto V_158;
}
F_88 ( V_142 , V_5 ) ;
F_118 ( V_142 , V_148 ) ;
F_119 ( V_142 , V_32 + V_146 + sizeof( struct V_144 ) ) ;
F_43 ( V_142 ) ;
V_145 = (struct V_144 * ) ( F_57 ( V_142 ) + V_146 ) ;
V_142 -> V_177 = ( V_142 -> V_178 + V_146 +
sizeof( struct V_144 ) ) ;
if ( V_5 -> V_3 )
F_39 ( V_142 , V_5 -> V_3 ) ;
F_120 ( V_5 , F_57 ( V_142 ) , V_146 ) ;
V_145 -> V_65 = V_65 ;
V_145 -> V_169 = 0 ;
V_145 -> V_171 = V_150 ;
F_105 ( F_121 ( V_5 , V_151 , F_122 ( V_142 ) ,
V_32 ) ) ;
V_147 -= V_32 ;
V_145 -> V_84 = F_3 ( V_85 ) ;
if ( V_147 > 0 )
V_145 -> V_84 |= F_3 ( V_170 ) ;
F_5 ( V_142 ) -> V_64 = F_3 ( V_142 -> V_32 -
sizeof( struct V_50 ) ) ;
V_151 += V_32 ;
V_85 += V_32 ;
V_152 = F_95 ( V_1 , V_3 , V_142 ) ;
if ( V_152 )
goto V_158;
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_174 ) ;
}
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_175 ) ;
F_38 ( V_5 ) ;
return V_152 ;
V_154:
if ( V_5 -> V_3 && F_28 ( F_2 ( V_5 ) ) )
F_123 ( V_5 -> V_3 , V_179 ) ;
V_5 -> V_9 = F_2 ( V_5 ) -> V_9 ;
F_77 ( V_5 , V_132 , 0 , V_56 ) ;
V_152 = - V_74 ;
V_158:
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_75 ) ;
F_14 ( V_5 ) ;
return V_152 ;
}
static inline int F_124 ( const struct V_180 * V_181 ,
const struct V_12 * V_182 ,
const struct V_12 * V_183 )
{
return ( V_181 -> V_184 != 128 || ! F_125 ( V_182 , & V_181 -> V_185 ) ) &&
( ! V_183 || ! F_125 ( V_182 , V_183 ) ) ;
}
static struct V_6 * F_126 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
const struct V_42 * V_43 )
{
struct V_47 * V_48 = F_34 ( V_3 ) ;
struct V_34 * V_120 ;
if ( ! V_7 )
goto V_186;
if ( V_7 -> V_187 -> V_188 != V_189 ) {
F_127 ( V_7 ) ;
return NULL ;
}
V_120 = (struct V_34 * ) V_7 ;
if ( F_124 ( & V_120 -> V_190 , & V_43 -> V_17 , V_48 -> V_191 ) ||
#ifdef F_128
F_124 ( & V_120 -> V_192 , & V_43 -> V_23 , V_48 -> V_193 ) ||
#endif
( ! ( V_43 -> V_194 & V_195 ) &&
( V_43 -> V_196 && V_43 -> V_196 != V_7 -> V_9 -> V_83 ) ) ) {
F_127 ( V_7 ) ;
V_7 = NULL ;
}
V_186:
return V_7 ;
}
static int F_129 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
struct V_6 * * V_7 , struct V_42 * V_43 )
{
#ifdef F_130
struct V_10 * V_197 ;
struct V_34 * V_120 ;
#endif
int V_152 ;
if ( F_131 ( & V_43 -> V_23 ) && ( ! * V_7 || ! ( * V_7 ) -> error ) ) {
struct V_34 * V_120 ;
bool V_198 = * V_7 != NULL ;
if ( ! V_198 )
* V_7 = F_132 ( V_1 , V_3 , V_43 ) ;
V_120 = ( * V_7 ) -> error ? NULL : (struct V_34 * ) * V_7 ;
V_152 = F_133 ( V_1 , V_120 , & V_43 -> V_17 ,
V_3 ? F_34 ( V_3 ) -> V_199 : 0 ,
& V_43 -> V_23 ) ;
if ( V_152 )
goto V_200;
if ( ! V_198 && ( * V_7 ) -> error ) {
F_127 ( * V_7 ) ;
* V_7 = NULL ;
}
}
if ( ! * V_7 )
* V_7 = F_132 ( V_1 , V_3 , V_43 ) ;
V_152 = ( * V_7 ) -> error ;
if ( V_152 )
goto V_200;
#ifdef F_130
V_120 = (struct V_34 * ) * V_7 ;
F_17 () ;
V_197 = F_19 ( V_120 -> V_7 . V_9 ,
F_18 ( V_120 , & V_43 -> V_17 ) ) ;
V_152 = V_197 && ! ( V_197 -> V_201 & V_202 ) ? - V_37 : 0 ;
F_24 () ;
if ( V_152 ) {
struct V_203 * V_204 ;
struct V_42 V_205 ;
int V_206 ;
V_204 = F_134 ( V_1 , & V_43 -> V_23 ,
( * V_7 ) -> V_9 , 1 ) ;
V_206 = ( V_204 && V_204 -> V_20 & V_207 ) ;
if ( V_204 )
F_135 ( V_204 ) ;
if ( V_206 ) {
F_127 ( * V_7 ) ;
memcpy ( & V_205 , V_43 , sizeof( struct V_42 ) ) ;
memset ( & V_205 . V_17 , 0 , sizeof( struct V_12 ) ) ;
* V_7 = F_132 ( V_1 , V_3 , & V_205 ) ;
V_152 = ( * V_7 ) -> error ;
if ( V_152 )
goto V_200;
}
}
#endif
return 0 ;
V_200:
if ( V_152 == - V_208 )
F_13 ( V_1 , NULL , V_36 ) ;
F_127 ( * V_7 ) ;
* V_7 = NULL ;
return V_152 ;
}
int F_136 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_6 * * V_7 ,
struct V_42 * V_43 )
{
* V_7 = NULL ;
return F_129 ( V_1 , V_3 , V_7 , V_43 ) ;
}
struct V_6 * F_137 ( const struct V_2 * V_3 , struct V_42 * V_43 ,
const struct V_12 * V_209 )
{
struct V_6 * V_7 = NULL ;
int V_152 ;
V_152 = F_129 ( F_33 ( V_3 ) , V_3 , & V_7 , V_43 ) ;
if ( V_152 )
return F_138 ( V_152 ) ;
if ( V_209 )
V_43 -> V_17 = * V_209 ;
if ( ! V_43 -> V_196 )
V_43 -> V_196 = F_139 ( V_7 -> V_9 ) ;
return F_140 ( F_33 ( V_3 ) , V_7 , F_141 ( V_43 ) , V_3 , 0 ) ;
}
struct V_6 * F_142 ( struct V_2 * V_3 , struct V_42 * V_43 ,
const struct V_12 * V_209 )
{
struct V_6 * V_7 = F_143 ( V_3 , F_34 ( V_3 ) -> V_210 ) ;
int V_152 ;
V_7 = F_126 ( V_3 , V_7 , V_43 ) ;
V_152 = F_129 ( F_33 ( V_3 ) , V_3 , & V_7 , V_43 ) ;
if ( V_152 )
return F_138 ( V_152 ) ;
if ( V_209 )
V_43 -> V_17 = * V_209 ;
return F_140 ( F_33 ( V_3 ) , V_7 , F_141 ( V_43 ) , V_3 , 0 ) ;
}
static inline int F_144 ( struct V_2 * V_3 ,
struct V_211 * V_212 ,
int F_145 ( void * V_140 , char * V_139 , int V_85 , int V_32 ,
int V_213 , struct V_4 * V_5 ) ,
void * V_140 , int V_214 , int V_215 , int V_216 ,
int V_217 , int V_56 , unsigned int V_20 ,
const struct V_42 * V_43 )
{
struct V_4 * V_5 ;
int V_152 ;
V_5 = F_146 ( V_212 ) ;
if ( ! V_5 ) {
V_5 = F_147 ( V_3 ,
V_215 + V_216 + V_217 + 20 ,
( V_20 & V_218 ) , & V_152 ) ;
if ( ! V_5 )
return V_152 ;
F_118 ( V_5 , V_215 ) ;
F_119 ( V_5 , V_216 + V_217 ) ;
F_43 ( V_5 ) ;
V_5 -> V_177 = V_5 -> V_178 + V_216 ;
V_5 -> V_15 = F_3 ( V_16 ) ;
V_5 -> V_219 = 0 ;
F_148 ( V_212 , V_5 ) ;
} else if ( F_27 ( V_5 ) ) {
goto V_220;
}
V_5 -> V_156 = V_157 ;
F_107 ( V_5 ) -> V_221 = ( V_56 - V_216 -
sizeof( struct V_144 ) ) & ~ 7 ;
F_107 ( V_5 ) -> V_222 = V_223 ;
F_107 ( V_5 ) -> V_224 = F_98 ( F_33 ( V_3 ) ,
& V_43 -> V_17 ,
& V_43 -> V_23 ) ;
V_220:
return F_149 ( V_3 , V_5 , F_145 , V_140 ,
( V_214 - V_217 ) ) ;
}
static inline struct V_225 * F_150 ( struct V_225 * V_226 ,
T_5 V_227 )
{
return V_226 ? F_106 ( V_226 , ( V_226 -> V_228 + 1 ) * 8 , V_227 ) : NULL ;
}
static inline struct V_229 * F_151 ( struct V_229 * V_226 ,
T_5 V_227 )
{
return V_226 ? F_106 ( V_226 , ( V_226 -> V_228 + 1 ) * 8 , V_227 ) : NULL ;
}
static void F_152 ( unsigned int * V_56 ,
int * V_230 ,
unsigned int V_216 ,
struct V_4 * V_5 ,
struct V_34 * V_120 ,
unsigned int V_231 )
{
if ( ! ( V_120 -> V_7 . V_20 & V_232 ) ) {
if ( ! V_5 ) {
* V_56 = V_231 - V_120 -> V_7 . V_233 ;
} else {
* V_56 = V_231 ;
}
* V_230 = ( ( * V_56 - V_216 ) & ~ 7 )
+ V_216 - sizeof( struct V_144 ) ;
}
}
static int F_153 ( struct V_2 * V_3 , struct V_234 * V_235 ,
struct V_236 * V_237 ,
int V_55 , int V_46 , struct V_44 * V_45 ,
struct V_34 * V_120 , struct V_42 * V_43 )
{
struct V_47 * V_48 = F_34 ( V_3 ) ;
unsigned int V_56 ;
if ( V_45 ) {
if ( F_154 ( V_237 -> V_45 ) )
return - V_37 ;
V_237 -> V_45 = F_155 ( V_45 -> V_238 , V_3 -> V_239 ) ;
if ( F_20 ( ! V_237 -> V_45 ) )
return - V_61 ;
V_237 -> V_45 -> V_238 = V_45 -> V_238 ;
V_237 -> V_45 -> V_59 = V_45 -> V_59 ;
V_237 -> V_45 -> V_58 = V_45 -> V_58 ;
V_237 -> V_45 -> V_240 = F_150 ( V_45 -> V_240 ,
V_3 -> V_239 ) ;
if ( V_45 -> V_240 && ! V_237 -> V_45 -> V_240 )
return - V_61 ;
V_237 -> V_45 -> V_241 = F_150 ( V_45 -> V_241 ,
V_3 -> V_239 ) ;
if ( V_45 -> V_241 && ! V_237 -> V_45 -> V_241 )
return - V_61 ;
V_237 -> V_45 -> V_242 = F_150 ( V_45 -> V_242 ,
V_3 -> V_239 ) ;
if ( V_45 -> V_242 && ! V_237 -> V_45 -> V_242 )
return - V_61 ;
V_237 -> V_45 -> V_116 = F_151 ( V_45 -> V_116 ,
V_3 -> V_239 ) ;
if ( V_45 -> V_116 && ! V_237 -> V_45 -> V_116 )
return - V_61 ;
}
F_112 ( & V_120 -> V_7 ) ;
V_235 -> V_243 . V_7 = & V_120 -> V_7 ;
V_235 -> V_244 . V_245 . V_246 = * V_43 ;
V_237 -> V_29 = V_55 ;
V_237 -> V_46 = V_46 ;
if ( V_120 -> V_7 . V_20 & V_232 )
V_56 = V_48 -> V_247 >= V_248 ?
V_120 -> V_7 . V_9 -> V_56 : F_47 ( & V_120 -> V_7 ) ;
else
V_56 = V_48 -> V_247 >= V_248 ?
V_120 -> V_7 . V_9 -> V_56 : F_47 ( V_120 -> V_7 . V_249 ) ;
if ( V_48 -> V_155 < V_56 ) {
if ( V_48 -> V_155 )
V_56 = V_48 -> V_155 ;
}
V_235 -> V_243 . V_250 = V_56 ;
if ( F_28 ( V_120 -> V_7 . V_249 ) )
V_235 -> V_243 . V_20 |= V_251 ;
V_235 -> V_243 . V_214 = 0 ;
return 0 ;
}
static int F_156 ( struct V_2 * V_3 ,
struct V_42 * V_43 ,
struct V_211 * V_212 ,
struct V_252 * V_235 ,
struct V_236 * V_237 ,
struct V_253 * V_254 ,
int F_145 ( void * V_140 , char * V_139 , int V_85 ,
int V_32 , int V_213 , struct V_4 * V_5 ) ,
void * V_140 , int V_214 , int V_217 ,
unsigned int V_20 , int V_255 )
{
struct V_4 * V_5 , * V_256 = NULL ;
unsigned int V_230 , V_216 , V_56 , V_231 ;
int V_257 = 0 ;
int V_258 = 0 ;
int V_215 ;
int V_259 ;
int V_152 ;
int V_85 = 0 ;
T_6 V_260 = 0 ;
T_2 V_261 = 0 ;
struct V_34 * V_120 = (struct V_34 * ) V_235 -> V_7 ;
struct V_44 * V_45 = V_237 -> V_45 ;
int V_262 = V_173 ;
unsigned int V_263 , V_264 ;
V_5 = F_146 ( V_212 ) ;
if ( ! V_5 ) {
V_257 = V_45 ? V_45 -> V_59 : 0 ;
V_258 = V_120 -> V_7 . V_233 - V_120 -> V_265 ;
}
V_56 = V_235 -> V_250 ;
V_231 = V_56 ;
V_215 = F_35 ( V_120 -> V_7 . V_9 ) ;
V_216 = sizeof( struct V_50 ) + V_120 -> V_265 +
( V_45 ? V_45 -> V_58 : 0 ) ;
V_230 = ( ( V_56 - V_216 ) & ~ 7 ) + V_216 -
sizeof( struct V_144 ) ;
V_264 = sizeof( struct V_50 ) +
( V_45 ? V_45 -> V_59 + V_45 -> V_58 : 0 ) +
( F_28 ( & V_120 -> V_7 ) ?
sizeof( struct V_144 ) : 0 ) +
V_120 -> V_265 ;
if ( V_235 -> V_214 + V_214 > V_56 - V_264 && V_255 &&
( V_3 -> V_266 == V_267 ||
V_3 -> V_266 == V_268 ) ) {
F_157 ( V_3 , V_43 , V_56 - V_264 +
sizeof( struct V_50 ) ) ;
goto V_269;
}
if ( F_158 ( V_3 ) )
V_263 = sizeof( struct V_50 ) + V_270 ;
else
V_263 = V_56 ;
if ( V_235 -> V_214 + V_214 > V_263 - V_264 ) {
V_269:
F_48 ( V_3 , V_74 , V_43 ,
V_56 - V_264 +
sizeof( struct V_50 ) ) ;
return - V_74 ;
}
if ( V_217 && V_3 -> V_266 == V_267 &&
V_264 == sizeof( struct V_50 ) &&
V_214 < V_56 - V_264 &&
! ( V_20 & V_271 ) &&
V_120 -> V_7 . V_9 -> V_272 & V_273 )
V_262 = V_157 ;
if ( V_3 -> V_274 == V_275 || V_3 -> V_274 == V_276 ) {
F_159 ( V_3 , & V_260 ) ;
if ( V_260 & V_277 &&
V_3 -> V_278 & V_279 )
V_261 = V_3 -> V_280 ++ ;
}
V_235 -> V_214 += V_214 ;
if ( ( ( V_214 > V_56 ) ||
( V_5 && F_27 ( V_5 ) ) ) &&
( V_3 -> V_266 == V_267 ) &&
( V_120 -> V_7 . V_9 -> V_272 & V_281 ) &&
( V_3 -> V_274 == V_275 ) ) {
V_152 = F_144 ( V_3 , V_212 , F_145 , V_140 , V_214 ,
V_215 , V_216 ,
V_217 , V_56 , V_20 , V_43 ) ;
if ( V_152 )
goto error;
return 0 ;
}
if ( ! V_5 )
goto V_282;
while ( V_214 > 0 ) {
V_259 = ( V_235 -> V_214 <= V_56 && ! ( V_235 -> V_20 & V_251 ) ? V_56 : V_230 ) - V_5 -> V_32 ;
if ( V_259 < V_214 )
V_259 = V_230 - V_5 -> V_32 ;
if ( V_259 <= 0 ) {
char * V_89 ;
unsigned int V_283 ;
unsigned int V_284 ;
unsigned int V_285 ;
unsigned int V_286 ;
V_282:
if ( V_5 )
V_285 = V_5 -> V_32 - V_230 ;
else
V_285 = 0 ;
if ( ! V_5 || ! V_256 )
F_152 ( & V_56 , & V_230 ,
V_216 , V_5 , V_120 ,
V_231 ) ;
V_256 = V_5 ;
V_283 = V_214 + V_285 ;
if ( V_283 > ( V_235 -> V_214 <= V_56 && ! ( V_235 -> V_20 & V_251 ) ? V_56 : V_230 ) - V_216 )
V_283 = V_230 - V_216 - V_120 -> V_7 . V_287 ;
if ( ( V_20 & V_271 ) &&
! ( V_120 -> V_7 . V_9 -> V_272 & V_288 ) )
V_286 = V_56 ;
else
V_286 = V_283 + V_216 ;
V_286 += V_258 ;
if ( V_283 != V_214 + V_285 ) {
V_283 += V_120 -> V_7 . V_287 ;
}
V_286 += V_120 -> V_7 . V_287 ;
V_284 = V_283 + V_216 ;
V_286 += sizeof( struct V_144 ) ;
if ( V_217 ) {
V_5 = F_147 ( V_3 ,
V_286 + V_215 ,
( V_20 & V_218 ) , & V_152 ) ;
} else {
V_5 = NULL ;
if ( F_160 ( & V_3 -> V_289 ) <=
2 * V_3 -> V_290 )
V_5 = F_161 ( V_3 ,
V_286 + V_215 , 1 ,
V_3 -> V_239 ) ;
if ( F_20 ( ! V_5 ) )
V_152 = - V_61 ;
}
if ( ! V_5 )
goto error;
V_5 -> V_15 = F_3 ( V_16 ) ;
V_5 -> V_156 = V_262 ;
V_5 -> V_219 = 0 ;
F_118 ( V_5 , V_215 + sizeof( struct V_144 ) +
V_258 ) ;
F_107 ( V_5 ) -> V_260 = V_260 ;
V_260 = 0 ;
F_107 ( V_5 ) -> V_261 = V_261 ;
V_261 = 0 ;
V_89 = F_119 ( V_5 , V_284 ) ;
F_162 ( V_5 , V_257 ) ;
V_89 += V_216 ;
V_5 -> V_177 = ( V_5 -> V_178 +
V_216 ) ;
if ( V_285 ) {
V_5 -> V_219 = F_163 (
V_256 , V_230 ,
V_89 + V_217 , V_285 , 0 ) ;
V_256 -> V_219 = F_164 ( V_256 -> V_219 ,
V_5 -> V_219 ) ;
V_89 += V_285 ;
F_165 ( V_256 , V_230 ) ;
}
V_259 = V_283 - V_217 - V_285 ;
if ( V_259 < 0 ) {
V_152 = - V_37 ;
F_14 ( V_5 ) ;
goto error;
} else if ( V_259 > 0 && F_145 ( V_140 , V_89 + V_217 , V_85 , V_259 , V_285 , V_5 ) < 0 ) {
V_152 = - V_291 ;
F_14 ( V_5 ) ;
goto error;
}
V_85 += V_259 ;
V_214 -= V_283 - V_285 ;
V_217 = 0 ;
V_257 = 0 ;
V_258 = 0 ;
F_148 ( V_212 , V_5 ) ;
continue;
}
if ( V_259 > V_214 )
V_259 = V_214 ;
if ( ! ( V_120 -> V_7 . V_9 -> V_272 & V_288 ) ) {
unsigned int V_292 ;
V_292 = V_5 -> V_32 ;
if ( F_145 ( V_140 , F_119 ( V_5 , V_259 ) ,
V_85 , V_259 , V_292 , V_5 ) < 0 ) {
F_166 ( V_5 , V_292 ) ;
V_152 = - V_291 ;
goto error;
}
} else {
int V_293 = F_107 ( V_5 ) -> V_294 ;
V_152 = - V_167 ;
if ( ! F_167 ( V_3 , V_254 ) )
goto error;
if ( ! F_168 ( V_5 , V_293 , V_254 -> V_295 ,
V_254 -> V_85 ) ) {
V_152 = - V_74 ;
if ( V_293 == V_296 )
goto error;
F_169 ( V_5 , V_293 , V_254 -> V_295 ,
V_254 -> V_85 , 0 ) ;
F_107 ( V_5 ) -> V_294 = ++ V_293 ;
F_170 ( V_254 -> V_295 ) ;
}
V_259 = F_171 ( int , V_259 , V_254 -> V_297 - V_254 -> V_85 ) ;
if ( F_145 ( V_140 ,
F_172 ( V_254 -> V_295 ) + V_254 -> V_85 ,
V_85 , V_259 , V_5 -> V_32 , V_5 ) < 0 )
goto V_298;
V_254 -> V_85 += V_259 ;
F_173 ( & F_107 ( V_5 ) -> V_299 [ V_293 - 1 ] , V_259 ) ;
V_5 -> V_32 += V_259 ;
V_5 -> V_172 += V_259 ;
V_5 -> V_165 += V_259 ;
F_174 ( V_259 , & V_3 -> V_289 ) ;
}
V_85 += V_259 ;
V_214 -= V_259 ;
}
return 0 ;
V_298:
V_152 = - V_291 ;
error:
V_235 -> V_214 -= V_214 ;
F_13 ( F_33 ( V_3 ) , V_120 -> V_300 , V_30 ) ;
return V_152 ;
}
int F_175 ( struct V_2 * V_3 ,
int F_145 ( void * V_140 , char * V_139 , int V_85 , int V_32 ,
int V_213 , struct V_4 * V_5 ) ,
void * V_140 , int V_214 , int V_217 , int V_55 ,
int V_46 , struct V_44 * V_45 , struct V_42 * V_43 ,
struct V_34 * V_120 , unsigned int V_20 , int V_255 )
{
struct V_301 * V_302 = F_176 ( V_3 ) ;
struct V_47 * V_48 = F_34 ( V_3 ) ;
int V_257 ;
int V_152 ;
if ( V_20 & V_303 )
return 0 ;
if ( F_177 ( & V_3 -> V_304 ) ) {
V_152 = F_153 ( V_3 , & V_302 -> V_235 , & V_48 -> V_235 , V_55 ,
V_46 , V_45 , V_120 , V_43 ) ;
if ( V_152 )
return V_152 ;
V_257 = ( V_45 ? V_45 -> V_59 : 0 ) ;
V_214 += V_257 ;
V_217 += V_257 ;
} else {
V_43 = & V_302 -> V_235 . V_244 . V_245 . V_246 ;
V_217 = 0 ;
}
return F_156 ( V_3 , V_43 , & V_3 -> V_304 , & V_302 -> V_235 . V_243 ,
& V_48 -> V_235 , F_178 ( V_3 ) , F_145 ,
V_140 , V_214 , V_217 , V_20 , V_255 ) ;
}
static void F_179 ( struct V_234 * V_235 ,
struct V_236 * V_237 )
{
if ( V_237 -> V_45 ) {
F_114 ( V_237 -> V_45 -> V_240 ) ;
F_114 ( V_237 -> V_45 -> V_241 ) ;
F_114 ( V_237 -> V_45 -> V_242 ) ;
F_114 ( V_237 -> V_45 -> V_116 ) ;
F_114 ( V_237 -> V_45 ) ;
V_237 -> V_45 = NULL ;
}
if ( V_235 -> V_243 . V_7 ) {
F_127 ( V_235 -> V_243 . V_7 ) ;
V_235 -> V_243 . V_7 = NULL ;
V_235 -> V_243 . V_20 &= ~ V_251 ;
}
memset ( & V_235 -> V_244 , 0 , sizeof( V_235 -> V_244 ) ) ;
}
struct V_4 * F_180 ( struct V_2 * V_3 ,
struct V_211 * V_212 ,
struct V_234 * V_235 ,
struct V_236 * V_237 )
{
struct V_4 * V_5 , * V_305 ;
struct V_4 * * V_306 ;
struct V_12 V_307 , * V_209 = & V_307 ;
struct V_47 * V_48 = F_34 ( V_3 ) ;
struct V_1 * V_1 = F_33 ( V_3 ) ;
struct V_50 * V_51 ;
struct V_44 * V_45 = V_237 -> V_45 ;
struct V_34 * V_120 = (struct V_34 * ) V_235 -> V_243 . V_7 ;
struct V_42 * V_43 = & V_235 -> V_244 . V_245 . V_246 ;
unsigned char V_52 = V_43 -> V_53 ;
V_5 = F_181 ( V_212 ) ;
if ( ! V_5 )
goto V_186;
V_306 = & ( F_107 ( V_5 ) -> V_168 ) ;
if ( V_5 -> V_89 < F_57 ( V_5 ) )
F_109 ( V_5 , F_182 ( V_5 ) ) ;
while ( ( V_305 = F_181 ( V_212 ) ) != NULL ) {
F_109 ( V_305 , F_183 ( V_5 ) ) ;
* V_306 = V_305 ;
V_306 = & ( V_305 -> V_81 ) ;
V_5 -> V_32 += V_305 -> V_32 ;
V_5 -> V_172 += V_305 -> V_32 ;
V_5 -> V_165 += V_305 -> V_165 ;
V_305 -> V_163 = NULL ;
V_305 -> V_3 = NULL ;
}
V_5 -> V_70 = F_158 ( V_3 ) ;
* V_209 = V_43 -> V_17 ;
F_109 ( V_5 , F_183 ( V_5 ) ) ;
if ( V_45 && V_45 -> V_59 )
F_40 ( V_5 , V_45 , & V_52 ) ;
if ( V_45 && V_45 -> V_58 )
F_41 ( V_5 , V_45 , & V_52 , & V_209 ) ;
F_42 ( V_5 , sizeof( struct V_50 ) ) ;
F_43 ( V_5 ) ;
V_51 = F_5 ( V_5 ) ;
F_45 ( V_51 , V_237 -> V_46 ,
F_46 ( V_1 , V_5 , V_43 -> V_62 ,
V_48 -> V_63 , V_43 ) ) ;
V_51 -> V_29 = V_237 -> V_29 ;
V_51 -> V_65 = V_52 ;
V_51 -> V_23 = V_43 -> V_23 ;
V_51 -> V_17 = * V_209 ;
V_5 -> V_66 = V_3 -> V_67 ;
V_5 -> V_68 = V_3 -> V_69 ;
F_90 ( V_5 , F_91 ( & V_120 -> V_7 ) ) ;
F_15 ( V_1 , V_120 -> V_300 , V_71 , V_5 -> V_32 ) ;
if ( V_52 == V_86 ) {
struct V_18 * V_19 = F_6 ( F_2 ( V_5 ) ) ;
F_184 ( V_1 , V_19 , F_185 ( V_5 ) -> V_90 ) ;
F_186 ( V_1 , V_19 , V_308 ) ;
}
F_179 ( V_235 , V_237 ) ;
V_186:
return V_5 ;
}
int F_187 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_33 ( V_5 -> V_3 ) ;
struct V_34 * V_120 = (struct V_34 * ) F_2 ( V_5 ) ;
int V_152 ;
V_152 = F_188 ( V_1 , V_5 -> V_3 , V_5 ) ;
if ( V_152 ) {
if ( V_152 > 0 )
V_152 = F_189 ( V_152 ) ;
if ( V_152 )
F_13 ( V_1 , V_120 -> V_300 ,
V_30 ) ;
}
return V_152 ;
}
int F_190 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_191 ( V_3 ) ;
if ( ! V_5 )
return 0 ;
return F_187 ( V_5 ) ;
}
static void F_192 ( struct V_2 * V_3 ,
struct V_211 * V_212 ,
struct V_234 * V_235 ,
struct V_236 * V_237 )
{
struct V_4 * V_5 ;
while ( ( V_5 = F_193 ( V_212 ) ) != NULL ) {
if ( F_2 ( V_5 ) )
F_13 ( F_33 ( V_3 ) , F_6 ( F_2 ( V_5 ) ) ,
V_30 ) ;
F_14 ( V_5 ) ;
}
F_179 ( V_235 , V_237 ) ;
}
void F_194 ( struct V_2 * V_3 )
{
F_192 ( V_3 , & V_3 -> V_304 ,
& F_176 ( V_3 ) -> V_235 , & F_34 ( V_3 ) -> V_235 ) ;
}
struct V_4 * F_195 ( struct V_2 * V_3 ,
int F_145 ( void * V_140 , char * V_139 , int V_85 ,
int V_32 , int V_213 , struct V_4 * V_5 ) ,
void * V_140 , int V_214 , int V_217 ,
int V_55 , int V_46 ,
struct V_44 * V_45 , struct V_42 * V_43 ,
struct V_34 * V_120 , unsigned int V_20 ,
int V_255 )
{
struct V_234 V_235 ;
struct V_236 V_237 ;
struct V_211 V_212 ;
int V_257 = ( V_45 ? V_45 -> V_59 : 0 ) ;
int V_152 ;
if ( V_20 & V_303 )
return NULL ;
F_196 ( & V_212 ) ;
V_235 . V_243 . V_20 = 0 ;
V_235 . V_243 . V_185 = 0 ;
V_235 . V_243 . V_45 = NULL ;
V_237 . V_45 = NULL ;
V_152 = F_153 ( V_3 , & V_235 , & V_237 , V_55 , V_46 , V_45 , V_120 , V_43 ) ;
if ( V_152 )
return F_138 ( V_152 ) ;
if ( V_255 < 0 )
V_255 = F_34 ( V_3 ) -> V_255 ;
V_152 = F_156 ( V_3 , V_43 , & V_212 , & V_235 . V_243 , & V_237 ,
& V_309 -> V_310 , F_145 , V_140 ,
V_214 + V_257 , V_217 + V_257 ,
V_20 , V_255 ) ;
if ( V_152 ) {
F_192 ( V_3 , & V_212 , & V_235 , & V_237 ) ;
return F_138 ( V_152 ) ;
}
return F_180 ( V_3 , & V_212 , & V_235 , & V_237 ) ;
}
