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
int V_20 = 0 ;
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
if ( V_43 -> V_196 )
V_20 |= V_201 ;
}
if ( ! * V_7 )
* V_7 = F_134 ( V_1 , V_3 , V_43 , V_20 ) ;
V_152 = ( * V_7 ) -> error ;
if ( V_152 )
goto V_200;
#ifdef F_130
V_120 = (struct V_34 * ) * V_7 ;
F_17 () ;
V_197 = F_19 ( V_120 -> V_7 . V_9 ,
F_18 ( V_120 , & V_43 -> V_17 ) ) ;
V_152 = V_197 && ! ( V_197 -> V_202 & V_203 ) ? - V_37 : 0 ;
F_24 () ;
if ( V_152 ) {
struct V_204 * V_205 ;
struct V_42 V_206 ;
int V_207 ;
V_205 = F_135 ( V_1 , & V_43 -> V_23 ,
( * V_7 ) -> V_9 , 1 ) ;
V_207 = ( V_205 && V_205 -> V_20 & V_208 ) ;
if ( V_205 )
F_136 ( V_205 ) ;
if ( V_207 ) {
F_127 ( * V_7 ) ;
memcpy ( & V_206 , V_43 , sizeof( struct V_42 ) ) ;
memset ( & V_206 . V_17 , 0 , sizeof( struct V_12 ) ) ;
* V_7 = F_132 ( V_1 , V_3 , & V_206 ) ;
V_152 = ( * V_7 ) -> error ;
if ( V_152 )
goto V_200;
}
}
#endif
return 0 ;
V_200:
if ( V_152 == - V_209 )
F_13 ( V_1 , NULL , V_36 ) ;
F_127 ( * V_7 ) ;
* V_7 = NULL ;
return V_152 ;
}
int F_137 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_6 * * V_7 ,
struct V_42 * V_43 )
{
* V_7 = NULL ;
return F_129 ( V_1 , V_3 , V_7 , V_43 ) ;
}
struct V_6 * F_138 ( const struct V_2 * V_3 , struct V_42 * V_43 ,
const struct V_12 * V_210 )
{
struct V_6 * V_7 = NULL ;
int V_152 ;
V_152 = F_129 ( F_33 ( V_3 ) , V_3 , & V_7 , V_43 ) ;
if ( V_152 )
return F_139 ( V_152 ) ;
if ( V_210 )
V_43 -> V_17 = * V_210 ;
if ( ! V_43 -> V_196 )
V_43 -> V_196 = F_140 ( V_7 -> V_9 ) ;
return F_141 ( F_33 ( V_3 ) , V_7 , F_142 ( V_43 ) , V_3 , 0 ) ;
}
struct V_6 * F_143 ( struct V_2 * V_3 , struct V_42 * V_43 ,
const struct V_12 * V_210 )
{
struct V_6 * V_7 = F_144 ( V_3 , F_34 ( V_3 ) -> V_211 ) ;
int V_152 ;
V_7 = F_126 ( V_3 , V_7 , V_43 ) ;
V_152 = F_129 ( F_33 ( V_3 ) , V_3 , & V_7 , V_43 ) ;
if ( V_152 )
return F_139 ( V_152 ) ;
if ( V_210 )
V_43 -> V_17 = * V_210 ;
return F_141 ( F_33 ( V_3 ) , V_7 , F_142 ( V_43 ) , V_3 , 0 ) ;
}
static inline int F_145 ( struct V_2 * V_3 ,
struct V_212 * V_213 ,
int F_146 ( void * V_140 , char * V_139 , int V_85 , int V_32 ,
int V_214 , struct V_4 * V_5 ) ,
void * V_140 , int V_215 , int V_216 , int V_217 ,
int V_218 , int V_56 , unsigned int V_20 ,
const struct V_42 * V_43 )
{
struct V_4 * V_5 ;
int V_152 ;
V_5 = F_147 ( V_213 ) ;
if ( ! V_5 ) {
V_5 = F_148 ( V_3 ,
V_216 + V_217 + V_218 + 20 ,
( V_20 & V_219 ) , & V_152 ) ;
if ( ! V_5 )
return V_152 ;
F_118 ( V_5 , V_216 ) ;
F_119 ( V_5 , V_217 + V_218 ) ;
F_43 ( V_5 ) ;
V_5 -> V_177 = V_5 -> V_178 + V_217 ;
V_5 -> V_15 = F_3 ( V_16 ) ;
V_5 -> V_220 = 0 ;
F_149 ( V_213 , V_5 ) ;
} else if ( F_27 ( V_5 ) ) {
goto V_221;
}
V_5 -> V_156 = V_157 ;
F_107 ( V_5 ) -> V_222 = ( V_56 - V_217 -
sizeof( struct V_144 ) ) & ~ 7 ;
F_107 ( V_5 ) -> V_223 = V_224 ;
F_107 ( V_5 ) -> V_225 = F_98 ( F_33 ( V_3 ) ,
& V_43 -> V_17 ,
& V_43 -> V_23 ) ;
V_221:
return F_150 ( V_3 , V_5 , F_146 , V_140 ,
( V_215 - V_218 ) ) ;
}
static inline struct V_226 * F_151 ( struct V_226 * V_227 ,
T_5 V_228 )
{
return V_227 ? F_106 ( V_227 , ( V_227 -> V_229 + 1 ) * 8 , V_228 ) : NULL ;
}
static inline struct V_230 * F_152 ( struct V_230 * V_227 ,
T_5 V_228 )
{
return V_227 ? F_106 ( V_227 , ( V_227 -> V_229 + 1 ) * 8 , V_228 ) : NULL ;
}
static void F_153 ( unsigned int * V_56 ,
int * V_231 ,
unsigned int V_217 ,
struct V_4 * V_5 ,
struct V_34 * V_120 ,
unsigned int V_232 )
{
if ( ! ( V_120 -> V_7 . V_20 & V_233 ) ) {
if ( ! V_5 ) {
* V_56 = V_232 - V_120 -> V_7 . V_234 ;
} else {
* V_56 = V_232 ;
}
* V_231 = ( ( * V_56 - V_217 ) & ~ 7 )
+ V_217 - sizeof( struct V_144 ) ;
}
}
static int F_154 ( struct V_2 * V_3 , struct V_235 * V_236 ,
struct V_237 * V_238 ,
int V_55 , int V_46 , struct V_44 * V_45 ,
struct V_34 * V_120 , struct V_42 * V_43 )
{
struct V_47 * V_48 = F_34 ( V_3 ) ;
unsigned int V_56 ;
if ( V_45 ) {
if ( F_155 ( V_238 -> V_45 ) )
return - V_37 ;
V_238 -> V_45 = F_156 ( V_45 -> V_239 , V_3 -> V_240 ) ;
if ( F_20 ( ! V_238 -> V_45 ) )
return - V_61 ;
V_238 -> V_45 -> V_239 = V_45 -> V_239 ;
V_238 -> V_45 -> V_59 = V_45 -> V_59 ;
V_238 -> V_45 -> V_58 = V_45 -> V_58 ;
V_238 -> V_45 -> V_241 = F_151 ( V_45 -> V_241 ,
V_3 -> V_240 ) ;
if ( V_45 -> V_241 && ! V_238 -> V_45 -> V_241 )
return - V_61 ;
V_238 -> V_45 -> V_242 = F_151 ( V_45 -> V_242 ,
V_3 -> V_240 ) ;
if ( V_45 -> V_242 && ! V_238 -> V_45 -> V_242 )
return - V_61 ;
V_238 -> V_45 -> V_243 = F_151 ( V_45 -> V_243 ,
V_3 -> V_240 ) ;
if ( V_45 -> V_243 && ! V_238 -> V_45 -> V_243 )
return - V_61 ;
V_238 -> V_45 -> V_116 = F_152 ( V_45 -> V_116 ,
V_3 -> V_240 ) ;
if ( V_45 -> V_116 && ! V_238 -> V_45 -> V_116 )
return - V_61 ;
}
F_112 ( & V_120 -> V_7 ) ;
V_236 -> V_244 . V_7 = & V_120 -> V_7 ;
V_236 -> V_245 . V_246 . V_247 = * V_43 ;
V_238 -> V_29 = V_55 ;
V_238 -> V_46 = V_46 ;
if ( V_120 -> V_7 . V_20 & V_233 )
V_56 = V_48 -> V_248 >= V_249 ?
V_120 -> V_7 . V_9 -> V_56 : F_47 ( & V_120 -> V_7 ) ;
else
V_56 = V_48 -> V_248 >= V_249 ?
V_120 -> V_7 . V_9 -> V_56 : F_47 ( V_120 -> V_7 . V_250 ) ;
if ( V_48 -> V_155 < V_56 ) {
if ( V_48 -> V_155 )
V_56 = V_48 -> V_155 ;
}
V_236 -> V_244 . V_251 = V_56 ;
if ( F_28 ( V_120 -> V_7 . V_250 ) )
V_236 -> V_244 . V_20 |= V_252 ;
V_236 -> V_244 . V_215 = 0 ;
return 0 ;
}
static int F_157 ( struct V_2 * V_3 ,
struct V_42 * V_43 ,
struct V_212 * V_213 ,
struct V_253 * V_236 ,
struct V_237 * V_238 ,
struct V_254 * V_255 ,
int F_146 ( void * V_140 , char * V_139 , int V_85 ,
int V_32 , int V_214 , struct V_4 * V_5 ) ,
void * V_140 , int V_215 , int V_218 ,
unsigned int V_20 , int V_256 )
{
struct V_4 * V_5 , * V_257 = NULL ;
unsigned int V_231 , V_217 , V_56 , V_232 ;
int V_258 = 0 ;
int V_259 = 0 ;
int V_216 ;
int V_260 ;
int V_152 ;
int V_85 = 0 ;
T_6 V_261 = 0 ;
T_2 V_262 = 0 ;
struct V_34 * V_120 = (struct V_34 * ) V_236 -> V_7 ;
struct V_44 * V_45 = V_238 -> V_45 ;
int V_263 = V_173 ;
unsigned int V_264 , V_265 ;
V_5 = F_147 ( V_213 ) ;
if ( ! V_5 ) {
V_258 = V_45 ? V_45 -> V_59 : 0 ;
V_259 = V_120 -> V_7 . V_234 - V_120 -> V_266 ;
}
V_56 = V_236 -> V_251 ;
V_232 = V_56 ;
V_216 = F_35 ( V_120 -> V_7 . V_9 ) ;
V_217 = sizeof( struct V_50 ) + V_120 -> V_266 +
( V_45 ? V_45 -> V_58 : 0 ) ;
V_231 = ( ( V_56 - V_217 ) & ~ 7 ) + V_217 -
sizeof( struct V_144 ) ;
V_265 = sizeof( struct V_50 ) +
( V_45 ? V_45 -> V_59 + V_45 -> V_58 : 0 ) +
( F_28 ( & V_120 -> V_7 ) ?
sizeof( struct V_144 ) : 0 ) +
V_120 -> V_266 ;
if ( V_236 -> V_215 + V_215 > V_56 - V_265 && V_256 &&
( V_3 -> V_267 == V_268 ||
V_3 -> V_267 == V_269 ) ) {
F_158 ( V_3 , V_43 , V_56 - V_265 +
sizeof( struct V_50 ) ) ;
goto V_270;
}
if ( F_159 ( V_3 ) )
V_264 = sizeof( struct V_50 ) + V_271 ;
else
V_264 = V_56 ;
if ( V_236 -> V_215 + V_215 > V_264 - V_265 ) {
V_270:
F_48 ( V_3 , V_74 , V_43 ,
V_56 - V_265 +
sizeof( struct V_50 ) ) ;
return - V_74 ;
}
if ( V_218 && V_3 -> V_267 == V_268 &&
V_265 == sizeof( struct V_50 ) &&
V_215 < V_56 - V_265 &&
! ( V_20 & V_272 ) &&
V_120 -> V_7 . V_9 -> V_273 & ( V_274 | V_275 ) )
V_263 = V_157 ;
if ( V_3 -> V_276 == V_277 || V_3 -> V_276 == V_278 ) {
F_160 ( V_3 , & V_261 ) ;
if ( V_261 & V_279 &&
V_3 -> V_280 & V_281 )
V_262 = V_3 -> V_282 ++ ;
}
V_236 -> V_215 += V_215 ;
if ( ( ( V_215 > V_56 ) ||
( V_5 && F_27 ( V_5 ) ) ) &&
( V_3 -> V_267 == V_268 ) &&
( V_120 -> V_7 . V_9 -> V_273 & V_283 ) &&
( V_3 -> V_276 == V_277 ) && ! F_161 ( V_3 ) ) {
V_152 = F_145 ( V_3 , V_213 , F_146 , V_140 , V_215 ,
V_216 , V_217 ,
V_218 , V_56 , V_20 , V_43 ) ;
if ( V_152 )
goto error;
return 0 ;
}
if ( ! V_5 )
goto V_284;
while ( V_215 > 0 ) {
V_260 = ( V_236 -> V_215 <= V_56 && ! ( V_236 -> V_20 & V_252 ) ? V_56 : V_231 ) - V_5 -> V_32 ;
if ( V_260 < V_215 )
V_260 = V_231 - V_5 -> V_32 ;
if ( V_260 <= 0 ) {
char * V_89 ;
unsigned int V_285 ;
unsigned int V_286 ;
unsigned int V_287 ;
unsigned int V_288 ;
V_284:
if ( V_5 )
V_287 = V_5 -> V_32 - V_231 ;
else
V_287 = 0 ;
if ( ! V_5 || ! V_257 )
F_153 ( & V_56 , & V_231 ,
V_217 , V_5 , V_120 ,
V_232 ) ;
V_257 = V_5 ;
V_285 = V_215 + V_287 ;
if ( V_285 > ( V_236 -> V_215 <= V_56 && ! ( V_236 -> V_20 & V_252 ) ? V_56 : V_231 ) - V_217 )
V_285 = V_231 - V_217 - V_120 -> V_7 . V_289 ;
if ( ( V_20 & V_272 ) &&
! ( V_120 -> V_7 . V_9 -> V_273 & V_290 ) )
V_288 = V_56 ;
else
V_288 = V_285 + V_217 ;
V_288 += V_259 ;
if ( V_285 != V_215 + V_287 ) {
V_285 += V_120 -> V_7 . V_289 ;
}
V_288 += V_120 -> V_7 . V_289 ;
V_286 = V_285 + V_217 ;
V_288 += sizeof( struct V_144 ) ;
if ( V_218 ) {
V_5 = F_148 ( V_3 ,
V_288 + V_216 ,
( V_20 & V_219 ) , & V_152 ) ;
} else {
V_5 = NULL ;
if ( F_162 ( & V_3 -> V_291 ) <=
2 * V_3 -> V_292 )
V_5 = F_163 ( V_3 ,
V_288 + V_216 , 1 ,
V_3 -> V_240 ) ;
if ( F_20 ( ! V_5 ) )
V_152 = - V_61 ;
}
if ( ! V_5 )
goto error;
V_5 -> V_15 = F_3 ( V_16 ) ;
V_5 -> V_156 = V_263 ;
V_5 -> V_220 = 0 ;
F_118 ( V_5 , V_216 + sizeof( struct V_144 ) +
V_259 ) ;
F_107 ( V_5 ) -> V_261 = V_261 ;
V_261 = 0 ;
F_107 ( V_5 ) -> V_262 = V_262 ;
V_262 = 0 ;
V_89 = F_119 ( V_5 , V_286 ) ;
F_164 ( V_5 , V_258 ) ;
V_89 += V_217 ;
V_5 -> V_177 = ( V_5 -> V_178 +
V_217 ) ;
if ( V_287 ) {
V_5 -> V_220 = F_165 (
V_257 , V_231 ,
V_89 + V_218 , V_287 , 0 ) ;
V_257 -> V_220 = F_166 ( V_257 -> V_220 ,
V_5 -> V_220 ) ;
V_89 += V_287 ;
F_167 ( V_257 , V_231 ) ;
}
V_260 = V_285 - V_218 - V_287 ;
if ( V_260 < 0 ) {
V_152 = - V_37 ;
F_14 ( V_5 ) ;
goto error;
} else if ( V_260 > 0 && F_146 ( V_140 , V_89 + V_218 , V_85 , V_260 , V_287 , V_5 ) < 0 ) {
V_152 = - V_293 ;
F_14 ( V_5 ) ;
goto error;
}
V_85 += V_260 ;
V_215 -= V_285 - V_287 ;
V_218 = 0 ;
V_258 = 0 ;
V_259 = 0 ;
F_149 ( V_213 , V_5 ) ;
continue;
}
if ( V_260 > V_215 )
V_260 = V_215 ;
if ( ! ( V_120 -> V_7 . V_9 -> V_273 & V_290 ) ) {
unsigned int V_294 ;
V_294 = V_5 -> V_32 ;
if ( F_146 ( V_140 , F_119 ( V_5 , V_260 ) ,
V_85 , V_260 , V_294 , V_5 ) < 0 ) {
F_168 ( V_5 , V_294 ) ;
V_152 = - V_293 ;
goto error;
}
} else {
int V_295 = F_107 ( V_5 ) -> V_296 ;
V_152 = - V_167 ;
if ( ! F_169 ( V_3 , V_255 ) )
goto error;
if ( ! F_170 ( V_5 , V_295 , V_255 -> V_297 ,
V_255 -> V_85 ) ) {
V_152 = - V_74 ;
if ( V_295 == V_298 )
goto error;
F_171 ( V_5 , V_295 , V_255 -> V_297 ,
V_255 -> V_85 , 0 ) ;
F_107 ( V_5 ) -> V_296 = ++ V_295 ;
F_172 ( V_255 -> V_297 ) ;
}
V_260 = F_173 ( int , V_260 , V_255 -> V_299 - V_255 -> V_85 ) ;
if ( F_146 ( V_140 ,
F_174 ( V_255 -> V_297 ) + V_255 -> V_85 ,
V_85 , V_260 , V_5 -> V_32 , V_5 ) < 0 )
goto V_300;
V_255 -> V_85 += V_260 ;
F_175 ( & F_107 ( V_5 ) -> V_301 [ V_295 - 1 ] , V_260 ) ;
V_5 -> V_32 += V_260 ;
V_5 -> V_172 += V_260 ;
V_5 -> V_165 += V_260 ;
F_176 ( V_260 , & V_3 -> V_291 ) ;
}
V_85 += V_260 ;
V_215 -= V_260 ;
}
return 0 ;
V_300:
V_152 = - V_293 ;
error:
V_236 -> V_215 -= V_215 ;
F_13 ( F_33 ( V_3 ) , V_120 -> V_302 , V_30 ) ;
return V_152 ;
}
int F_177 ( struct V_2 * V_3 ,
int F_146 ( void * V_140 , char * V_139 , int V_85 , int V_32 ,
int V_214 , struct V_4 * V_5 ) ,
void * V_140 , int V_215 , int V_218 , int V_55 ,
int V_46 , struct V_44 * V_45 , struct V_42 * V_43 ,
struct V_34 * V_120 , unsigned int V_20 , int V_256 )
{
struct V_303 * V_304 = F_178 ( V_3 ) ;
struct V_47 * V_48 = F_34 ( V_3 ) ;
int V_258 ;
int V_152 ;
if ( V_20 & V_305 )
return 0 ;
if ( F_179 ( & V_3 -> V_306 ) ) {
V_152 = F_154 ( V_3 , & V_304 -> V_236 , & V_48 -> V_236 , V_55 ,
V_46 , V_45 , V_120 , V_43 ) ;
if ( V_152 )
return V_152 ;
V_258 = ( V_45 ? V_45 -> V_59 : 0 ) ;
V_215 += V_258 ;
V_218 += V_258 ;
} else {
V_43 = & V_304 -> V_236 . V_245 . V_246 . V_247 ;
V_218 = 0 ;
}
return F_157 ( V_3 , V_43 , & V_3 -> V_306 , & V_304 -> V_236 . V_244 ,
& V_48 -> V_236 , F_180 ( V_3 ) , F_146 ,
V_140 , V_215 , V_218 , V_20 , V_256 ) ;
}
static void F_181 ( struct V_235 * V_236 ,
struct V_237 * V_238 )
{
if ( V_238 -> V_45 ) {
F_114 ( V_238 -> V_45 -> V_241 ) ;
F_114 ( V_238 -> V_45 -> V_242 ) ;
F_114 ( V_238 -> V_45 -> V_243 ) ;
F_114 ( V_238 -> V_45 -> V_116 ) ;
F_114 ( V_238 -> V_45 ) ;
V_238 -> V_45 = NULL ;
}
if ( V_236 -> V_244 . V_7 ) {
F_127 ( V_236 -> V_244 . V_7 ) ;
V_236 -> V_244 . V_7 = NULL ;
V_236 -> V_244 . V_20 &= ~ V_252 ;
}
memset ( & V_236 -> V_245 , 0 , sizeof( V_236 -> V_245 ) ) ;
}
struct V_4 * F_182 ( struct V_2 * V_3 ,
struct V_212 * V_213 ,
struct V_235 * V_236 ,
struct V_237 * V_238 )
{
struct V_4 * V_5 , * V_307 ;
struct V_4 * * V_308 ;
struct V_12 V_309 , * V_210 = & V_309 ;
struct V_47 * V_48 = F_34 ( V_3 ) ;
struct V_1 * V_1 = F_33 ( V_3 ) ;
struct V_50 * V_51 ;
struct V_44 * V_45 = V_238 -> V_45 ;
struct V_34 * V_120 = (struct V_34 * ) V_236 -> V_244 . V_7 ;
struct V_42 * V_43 = & V_236 -> V_245 . V_246 . V_247 ;
unsigned char V_52 = V_43 -> V_53 ;
V_5 = F_183 ( V_213 ) ;
if ( ! V_5 )
goto V_186;
V_308 = & ( F_107 ( V_5 ) -> V_168 ) ;
if ( V_5 -> V_89 < F_57 ( V_5 ) )
F_109 ( V_5 , F_184 ( V_5 ) ) ;
while ( ( V_307 = F_183 ( V_213 ) ) != NULL ) {
F_109 ( V_307 , F_185 ( V_5 ) ) ;
* V_308 = V_307 ;
V_308 = & ( V_307 -> V_81 ) ;
V_5 -> V_32 += V_307 -> V_32 ;
V_5 -> V_172 += V_307 -> V_32 ;
V_5 -> V_165 += V_307 -> V_165 ;
V_307 -> V_163 = NULL ;
V_307 -> V_3 = NULL ;
}
V_5 -> V_70 = F_159 ( V_3 ) ;
* V_210 = V_43 -> V_17 ;
F_109 ( V_5 , F_185 ( V_5 ) ) ;
if ( V_45 && V_45 -> V_59 )
F_40 ( V_5 , V_45 , & V_52 ) ;
if ( V_45 && V_45 -> V_58 )
F_41 ( V_5 , V_45 , & V_52 , & V_210 ) ;
F_42 ( V_5 , sizeof( struct V_50 ) ) ;
F_43 ( V_5 ) ;
V_51 = F_5 ( V_5 ) ;
F_45 ( V_51 , V_238 -> V_46 ,
F_46 ( V_1 , V_5 , V_43 -> V_62 ,
V_48 -> V_63 , V_43 ) ) ;
V_51 -> V_29 = V_238 -> V_29 ;
V_51 -> V_65 = V_52 ;
V_51 -> V_23 = V_43 -> V_23 ;
V_51 -> V_17 = * V_210 ;
V_5 -> V_66 = V_3 -> V_67 ;
V_5 -> V_68 = V_3 -> V_69 ;
F_90 ( V_5 , F_91 ( & V_120 -> V_7 ) ) ;
F_15 ( V_1 , V_120 -> V_302 , V_71 , V_5 -> V_32 ) ;
if ( V_52 == V_86 ) {
struct V_18 * V_19 = F_6 ( F_2 ( V_5 ) ) ;
F_186 ( V_1 , V_19 , F_187 ( V_5 ) -> V_90 ) ;
F_188 ( V_1 , V_19 , V_310 ) ;
}
F_181 ( V_236 , V_238 ) ;
V_186:
return V_5 ;
}
int F_189 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_33 ( V_5 -> V_3 ) ;
struct V_34 * V_120 = (struct V_34 * ) F_2 ( V_5 ) ;
int V_152 ;
V_152 = F_190 ( V_1 , V_5 -> V_3 , V_5 ) ;
if ( V_152 ) {
if ( V_152 > 0 )
V_152 = F_191 ( V_152 ) ;
if ( V_152 )
F_13 ( V_1 , V_120 -> V_302 ,
V_30 ) ;
}
return V_152 ;
}
int F_192 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_193 ( V_3 ) ;
if ( ! V_5 )
return 0 ;
return F_189 ( V_5 ) ;
}
static void F_194 ( struct V_2 * V_3 ,
struct V_212 * V_213 ,
struct V_235 * V_236 ,
struct V_237 * V_238 )
{
struct V_4 * V_5 ;
while ( ( V_5 = F_195 ( V_213 ) ) != NULL ) {
if ( F_2 ( V_5 ) )
F_13 ( F_33 ( V_3 ) , F_6 ( F_2 ( V_5 ) ) ,
V_30 ) ;
F_14 ( V_5 ) ;
}
F_181 ( V_236 , V_238 ) ;
}
void F_196 ( struct V_2 * V_3 )
{
F_194 ( V_3 , & V_3 -> V_306 ,
& F_178 ( V_3 ) -> V_236 , & F_34 ( V_3 ) -> V_236 ) ;
}
struct V_4 * F_197 ( struct V_2 * V_3 ,
int F_146 ( void * V_140 , char * V_139 , int V_85 ,
int V_32 , int V_214 , struct V_4 * V_5 ) ,
void * V_140 , int V_215 , int V_218 ,
int V_55 , int V_46 ,
struct V_44 * V_45 , struct V_42 * V_43 ,
struct V_34 * V_120 , unsigned int V_20 ,
int V_256 )
{
struct V_235 V_236 ;
struct V_237 V_238 ;
struct V_212 V_213 ;
int V_258 = ( V_45 ? V_45 -> V_59 : 0 ) ;
int V_152 ;
if ( V_20 & V_305 )
return NULL ;
F_198 ( & V_213 ) ;
V_236 . V_244 . V_20 = 0 ;
V_236 . V_244 . V_185 = 0 ;
V_236 . V_244 . V_45 = NULL ;
V_238 . V_45 = NULL ;
V_152 = F_154 ( V_3 , & V_236 , & V_238 , V_55 , V_46 , V_45 , V_120 , V_43 ) ;
if ( V_152 )
return F_139 ( V_152 ) ;
if ( V_256 < 0 )
V_256 = F_34 ( V_3 ) -> V_256 ;
V_152 = F_157 ( V_3 , V_43 , & V_213 , & V_236 . V_244 , & V_238 ,
& V_311 -> V_312 , F_146 , V_140 ,
V_215 + V_258 , V_218 + V_258 ,
V_20 , V_256 ) ;
if ( V_152 ) {
F_194 ( V_3 , & V_213 , & V_236 , & V_238 ) ;
return F_139 ( V_152 ) ;
}
return F_182 ( V_3 , & V_213 , & V_236 , & V_238 ) ;
}
