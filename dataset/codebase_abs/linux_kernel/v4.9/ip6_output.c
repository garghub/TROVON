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
if ( F_17 ( V_7 -> V_34 ) ) {
int V_35 = F_18 ( V_5 ) ;
if ( V_35 < 0 || V_35 == V_36 )
return V_35 ;
}
F_19 () ;
V_13 = F_20 ( (struct V_37 * ) V_7 , & F_5 ( V_5 ) -> V_17 ) ;
V_11 = F_21 ( V_7 -> V_9 , V_13 ) ;
if ( F_22 ( ! V_11 ) )
V_11 = F_23 ( & V_38 , V_13 , V_7 -> V_9 , false ) ;
if ( ! F_24 ( V_11 ) ) {
V_14 = F_25 ( V_7 , V_11 , V_5 ) ;
F_26 () ;
return V_14 ;
}
F_26 () ;
F_13 ( V_1 , F_6 ( V_7 ) , V_39 ) ;
F_14 ( V_5 ) ;
return - V_40 ;
}
static int F_27 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
if ( ( V_5 -> V_32 > F_28 ( V_5 ) && ! F_29 ( V_5 ) ) ||
F_30 ( F_2 ( V_5 ) ) ||
( F_9 ( V_5 ) -> V_41 && V_5 -> V_32 > F_9 ( V_5 ) -> V_41 ) )
return F_31 ( V_1 , V_3 , V_5 , F_1 ) ;
else
return F_1 ( V_1 , V_3 , V_5 ) ;
}
int F_32 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_8 * V_9 = F_2 ( V_5 ) -> V_9 ;
struct V_18 * V_19 = F_6 ( F_2 ( V_5 ) ) ;
if ( F_22 ( V_19 -> V_42 . V_43 ) ) {
F_13 ( V_1 , V_19 , V_30 ) ;
F_14 ( V_5 ) ;
return 0 ;
}
return F_33 ( V_26 , V_27 ,
V_1 , V_3 , V_5 , NULL , V_9 ,
F_27 ,
! ( F_9 ( V_5 ) -> V_20 & V_44 ) ) ;
}
int F_34 ( const struct V_2 * V_3 , struct V_4 * V_5 , struct V_45 * V_46 ,
struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_1 = F_35 ( V_3 ) ;
const struct V_50 * V_51 = F_36 ( V_3 ) ;
struct V_12 * V_52 = & V_46 -> V_17 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_53 * V_54 ;
T_1 V_55 = V_46 -> V_56 ;
int V_57 = V_5 -> V_32 ;
int V_58 = - 1 ;
T_2 V_59 ;
if ( V_48 ) {
unsigned int V_60 ;
V_60 = V_48 -> V_61 + V_48 -> V_62 ;
V_57 += V_60 ;
V_60 += sizeof( struct V_53 ) + F_37 ( V_7 -> V_9 ) ;
if ( F_38 ( V_5 ) < V_60 ) {
struct V_4 * V_63 = F_39 ( V_5 , V_60 ) ;
if ( ! V_63 ) {
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_30 ) ;
F_14 ( V_5 ) ;
return - V_64 ;
}
F_40 ( V_5 ) ;
V_5 = V_63 ;
F_41 ( V_5 , (struct V_2 * ) V_3 ) ;
}
if ( V_48 -> V_62 )
F_42 ( V_5 , V_48 , & V_55 ) ;
if ( V_48 -> V_61 )
F_43 ( V_5 , V_48 , & V_55 , & V_52 ) ;
}
F_44 ( V_5 , sizeof( struct V_53 ) ) ;
F_45 ( V_5 ) ;
V_54 = F_5 ( V_5 ) ;
if ( V_51 )
V_58 = V_51 -> V_29 ;
if ( V_58 < 0 )
V_58 = F_46 ( V_7 ) ;
F_47 ( V_54 , V_49 , F_48 ( V_1 , V_5 , V_46 -> V_65 ,
V_51 -> V_66 , V_46 ) ) ;
V_54 -> V_67 = F_3 ( V_57 ) ;
V_54 -> V_68 = V_55 ;
V_54 -> V_29 = V_58 ;
V_54 -> V_23 = V_46 -> V_23 ;
V_54 -> V_17 = * V_52 ;
V_5 -> V_15 = F_3 ( V_16 ) ;
V_5 -> V_69 = V_3 -> V_70 ;
V_5 -> V_71 = V_3 -> V_72 ;
V_59 = F_49 ( V_7 ) ;
if ( ( V_5 -> V_32 <= V_59 ) || V_5 -> V_73 || F_29 ( V_5 ) ) {
F_15 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_74 , V_5 -> V_32 ) ;
V_5 = F_50 ( (struct V_2 * ) V_3 , V_5 ) ;
if ( F_22 ( ! V_5 ) )
return 0 ;
return F_12 ( V_26 , V_75 ,
V_1 , (struct V_2 * ) V_3 , V_5 , NULL , V_7 -> V_9 ,
V_76 ) ;
}
V_5 -> V_9 = V_7 -> V_9 ;
F_51 ( (struct V_2 * ) V_3 , V_77 , V_46 , V_59 ) ;
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) , V_78 ) ;
F_14 ( V_5 ) ;
return - V_77 ;
}
static int F_52 ( struct V_4 * V_5 , int V_79 )
{
struct V_80 * V_81 ;
struct V_2 * V_82 = NULL ;
F_53 ( & V_83 ) ;
for ( V_81 = V_80 ; V_81 ; V_81 = V_81 -> V_84 ) {
struct V_2 * V_3 = V_81 -> V_3 ;
if ( V_3 && V_81 -> V_79 == V_79 &&
( ! V_3 -> V_85 ||
V_3 -> V_85 == V_5 -> V_9 -> V_86 ) ) {
if ( V_82 ) {
struct V_4 * V_63 = F_11 ( V_5 , V_25 ) ;
if ( V_63 )
F_54 ( V_82 , V_63 ) ;
}
V_82 = V_3 ;
}
}
if ( V_82 ) {
F_54 ( V_82 , V_5 ) ;
F_55 ( & V_83 ) ;
return 1 ;
}
F_55 ( & V_83 ) ;
return 0 ;
}
static int F_56 ( struct V_4 * V_5 )
{
struct V_53 * V_54 = F_5 ( V_5 ) ;
T_1 V_68 = V_54 -> V_68 ;
T_3 V_87 ;
int V_88 ;
if ( F_57 ( V_68 ) ) {
V_88 = F_58 ( V_5 , sizeof( * V_54 ) , & V_68 , & V_87 ) ;
if ( V_88 < 0 )
return 0 ;
} else
V_88 = sizeof( struct V_53 ) ;
if ( V_68 == V_89 ) {
struct V_90 * V_91 ;
if ( ! F_59 ( V_5 , ( F_60 ( V_5 ) +
V_88 + 1 - V_5 -> V_92 ) ) )
return 0 ;
V_91 = (struct V_90 * ) ( F_60 ( V_5 ) + V_88 ) ;
switch ( V_91 -> V_93 ) {
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
return 1 ;
default:
break;
}
}
if ( F_61 ( & V_54 -> V_17 ) & V_99 ) {
F_62 ( V_5 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_63 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
return V_76 ( V_1 , V_3 , V_5 ) ;
}
static unsigned int F_64 ( const struct V_6 * V_7 )
{
unsigned int V_59 ;
struct V_18 * V_19 ;
if ( F_65 ( V_7 , V_100 ) ) {
V_59 = F_66 ( V_7 , V_100 ) ;
if ( V_59 )
return V_59 ;
}
V_59 = V_101 ;
F_67 () ;
V_19 = F_68 ( V_7 -> V_9 ) ;
if ( V_19 )
V_59 = V_19 -> V_42 . V_102 ;
F_69 () ;
return V_59 ;
}
static bool F_70 ( const struct V_4 * V_5 , unsigned int V_59 )
{
if ( V_5 -> V_32 <= V_59 )
return false ;
if ( F_9 ( V_5 ) -> V_41 && F_9 ( V_5 ) -> V_41 > V_59 )
return true ;
if ( V_5 -> V_73 )
return false ;
if ( F_29 ( V_5 ) && F_71 ( V_5 , V_59 ) )
return false ;
return true ;
}
int F_72 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_53 * V_54 = F_5 ( V_5 ) ;
struct V_103 * V_48 = F_9 ( V_5 ) ;
struct V_1 * V_1 = F_73 ( V_7 -> V_9 ) ;
T_2 V_59 ;
if ( V_1 -> V_104 . V_105 -> V_106 == 0 )
goto error;
if ( V_5 -> V_107 != V_108 )
goto V_109;
if ( F_22 ( V_5 -> V_3 ) )
goto V_109;
if ( F_74 ( V_5 ) )
goto V_109;
if ( ! F_75 ( NULL , V_110 , V_5 ) ) {
F_76 ( V_1 , F_6 ( V_7 ) ,
V_111 ) ;
goto V_109;
}
F_77 ( V_5 ) ;
if ( F_22 ( V_48 -> V_20 & V_112 ) ) {
if ( F_52 ( V_5 , F_78 ( V_48 -> V_81 ) ) )
return 0 ;
}
if ( V_54 -> V_29 <= 1 ) {
V_5 -> V_9 = V_7 -> V_9 ;
F_79 ( V_5 , V_113 , V_114 , 0 ) ;
F_76 ( V_1 , F_6 ( V_7 ) ,
V_115 ) ;
F_14 ( V_5 ) ;
return - V_116 ;
}
if ( V_1 -> V_104 . V_105 -> V_117 &&
F_80 ( & V_38 , V_1 , & V_54 -> V_17 , V_5 -> V_9 , 0 ) ) {
int V_118 = F_56 ( V_5 ) ;
if ( V_118 > 0 )
return F_81 ( V_5 ) ;
else if ( V_118 < 0 ) {
F_76 ( V_1 , F_6 ( V_7 ) ,
V_111 ) ;
goto V_109;
}
}
if ( ! F_82 ( V_5 ) ) {
F_76 ( V_1 , F_6 ( V_7 ) ,
V_111 ) ;
goto V_109;
}
V_7 = F_2 ( V_5 ) ;
if ( V_5 -> V_9 == V_7 -> V_9 && V_48 -> V_119 == 0 && ! F_83 ( V_5 ) ) {
struct V_12 * V_120 = NULL ;
struct V_121 * V_122 ;
struct V_37 * V_123 ;
V_123 = (struct V_37 * ) V_7 ;
if ( V_123 -> V_124 & V_125 )
V_120 = & V_123 -> V_126 ;
else
V_120 = & V_54 -> V_17 ;
V_122 = F_84 ( V_1 -> V_104 . V_127 , & V_54 -> V_17 , 1 ) ;
if ( F_85 ( V_122 , 1 * V_128 ) )
F_86 ( V_5 , V_120 ) ;
if ( V_122 )
F_87 ( V_122 ) ;
} else {
int V_129 = F_61 ( & V_54 -> V_23 ) ;
if ( V_129 == V_130 ||
V_129 & ( V_131 | V_132 ) )
goto error;
if ( V_129 & V_99 ) {
F_79 ( V_5 , V_133 ,
V_134 , 0 ) ;
goto error;
}
}
V_59 = F_64 ( V_7 ) ;
if ( V_59 < V_101 )
V_59 = V_101 ;
if ( F_70 ( V_5 , V_59 ) ) {
V_5 -> V_9 = V_7 -> V_9 ;
F_79 ( V_5 , V_135 , 0 , V_59 ) ;
F_76 ( V_1 , F_6 ( V_7 ) ,
V_136 ) ;
F_76 ( V_1 , F_6 ( V_7 ) ,
V_78 ) ;
F_14 ( V_5 ) ;
return - V_77 ;
}
if ( F_88 ( V_5 , V_7 -> V_9 -> V_137 ) ) {
F_76 ( V_1 , F_6 ( V_7 ) ,
V_30 ) ;
goto V_109;
}
V_54 = F_5 ( V_5 ) ;
V_54 -> V_29 -- ;
F_76 ( V_1 , F_6 ( V_7 ) , V_138 ) ;
F_89 ( V_1 , F_6 ( V_7 ) , V_139 , V_5 -> V_32 ) ;
return F_12 ( V_26 , V_140 ,
V_1 , NULL , V_5 , V_5 -> V_9 , V_7 -> V_9 ,
F_63 ) ;
error:
F_76 ( V_1 , F_6 ( V_7 ) , V_141 ) ;
V_109:
F_14 ( V_5 ) ;
return - V_40 ;
}
static void F_90 ( struct V_4 * V_142 , struct V_4 * V_143 )
{
V_142 -> V_107 = V_143 -> V_107 ;
V_142 -> V_69 = V_143 -> V_69 ;
V_142 -> V_15 = V_143 -> V_15 ;
F_91 ( V_142 ) ;
F_92 ( V_142 , F_93 ( F_2 ( V_143 ) ) ) ;
V_142 -> V_9 = V_143 -> V_9 ;
V_142 -> V_71 = V_143 -> V_71 ;
#ifdef F_94
V_142 -> V_144 = V_143 -> V_144 ;
#endif
F_95 ( V_142 , V_143 ) ;
F_96 ( V_142 , V_143 ) ;
}
int F_31 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 ,
int (* F_97)( struct V_1 * , struct V_2 * , struct V_4 * ) )
{
struct V_4 * V_145 ;
struct V_37 * V_123 = (struct V_37 * ) F_2 ( V_5 ) ;
struct V_50 * V_51 = V_5 -> V_3 && ! F_98 () ?
F_36 ( V_5 -> V_3 ) : NULL ;
struct V_53 * V_146 ;
struct V_147 * V_148 ;
unsigned int V_59 , V_149 , V_150 , V_32 ;
int V_151 , V_152 ;
T_4 V_153 ;
int V_154 , V_88 = 0 , V_155 = 0 ;
T_1 * V_156 , V_68 = 0 ;
V_149 = F_99 ( V_5 , & V_156 ) ;
V_68 = * V_156 ;
V_59 = F_28 ( V_5 ) ;
if ( F_22 ( ! V_5 -> V_73 && V_5 -> V_32 > V_59 ) )
goto V_157;
if ( F_9 ( V_5 ) -> V_41 ) {
if ( F_9 ( V_5 ) -> V_41 > V_59 )
goto V_157;
V_59 = F_9 ( V_5 ) -> V_41 ;
if ( V_59 < V_101 )
V_59 = V_101 ;
}
if ( V_51 && V_51 -> V_158 < V_59 ) {
if ( V_51 -> V_158 )
V_59 = V_51 -> V_158 ;
}
if ( V_59 < V_149 + sizeof( struct V_147 ) + 8 )
goto V_157;
V_59 -= V_149 + sizeof( struct V_147 ) ;
V_153 = F_100 ( V_1 , & F_5 ( V_5 ) -> V_17 ,
& F_5 ( V_5 ) -> V_23 ) ;
if ( V_5 -> V_159 == V_160 &&
( V_155 = F_101 ( V_5 ) ) )
goto V_161;
V_151 = F_37 ( V_123 -> V_7 . V_9 ) ;
if ( F_102 ( V_5 ) ) {
int V_162 = F_103 ( V_5 ) ;
struct V_4 * V_163 ;
if ( V_162 - V_149 > V_59 ||
( ( V_162 - V_149 ) & 7 ) ||
F_104 ( V_5 ) ||
F_38 ( V_5 ) < ( V_151 + sizeof( struct V_147 ) ) )
goto V_164;
F_105 (skb, frag) {
if ( V_145 -> V_32 > V_59 ||
( ( V_145 -> V_32 & 7 ) && V_145 -> V_84 ) ||
F_38 ( V_145 ) < ( V_149 + V_151 + sizeof( struct V_147 ) ) )
goto V_165;
if ( F_106 ( V_145 ) )
goto V_165;
F_107 ( V_145 -> V_3 ) ;
if ( V_5 -> V_3 ) {
V_145 -> V_3 = V_5 -> V_3 ;
V_145 -> V_166 = V_167 ;
}
V_5 -> V_168 -= V_145 -> V_168 ;
}
V_155 = 0 ;
V_88 = 0 ;
* V_156 = V_169 ;
V_146 = F_108 ( F_60 ( V_5 ) , V_149 , V_25 ) ;
if ( ! V_146 ) {
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_78 ) ;
V_155 = - V_170 ;
goto V_161;
}
V_145 = F_109 ( V_5 ) -> V_171 ;
F_110 ( V_5 ) ;
F_111 ( V_5 , V_149 ) ;
V_148 = (struct V_147 * ) F_112 ( V_5 , sizeof( struct V_147 ) ) ;
F_112 ( V_5 , V_149 ) ;
F_45 ( V_5 ) ;
memcpy ( F_60 ( V_5 ) , V_146 , V_149 ) ;
V_148 -> V_68 = V_68 ;
V_148 -> V_172 = 0 ;
V_148 -> V_87 = F_3 ( V_173 ) ;
V_148 -> V_174 = V_153 ;
V_162 = F_103 ( V_5 ) ;
V_5 -> V_175 = V_162 - F_113 ( V_5 ) ;
V_5 -> V_32 = V_162 ;
F_5 ( V_5 ) -> V_67 = F_3 ( V_162 -
sizeof( struct V_53 ) ) ;
F_114 ( & V_123 -> V_7 ) ;
for (; ; ) {
if ( V_145 ) {
V_145 -> V_159 = V_176 ;
F_115 ( V_145 ) ;
V_148 = (struct V_147 * ) F_112 ( V_145 , sizeof( struct V_147 ) ) ;
F_112 ( V_145 , V_149 ) ;
F_45 ( V_145 ) ;
memcpy ( F_60 ( V_145 ) , V_146 ,
V_149 ) ;
V_88 += V_5 -> V_32 - V_149 - sizeof( struct V_147 ) ;
V_148 -> V_68 = V_68 ;
V_148 -> V_172 = 0 ;
V_148 -> V_87 = F_3 ( V_88 ) ;
if ( V_145 -> V_84 )
V_148 -> V_87 |= F_3 ( V_173 ) ;
V_148 -> V_174 = V_153 ;
F_5 ( V_145 ) -> V_67 =
F_3 ( V_145 -> V_32 -
sizeof( struct V_53 ) ) ;
F_90 ( V_145 , V_5 ) ;
}
V_155 = F_97 ( V_1 , V_3 , V_5 ) ;
if ( ! V_155 )
F_13 ( V_1 , F_6 ( & V_123 -> V_7 ) ,
V_177 ) ;
if ( V_155 || ! V_145 )
break;
V_5 = V_145 ;
V_145 = V_5 -> V_84 ;
V_5 -> V_84 = NULL ;
}
F_116 ( V_146 ) ;
if ( V_155 == 0 ) {
F_13 ( V_1 , F_6 ( & V_123 -> V_7 ) ,
V_178 ) ;
F_117 ( V_123 ) ;
return 0 ;
}
F_118 ( V_145 ) ;
F_13 ( V_1 , F_6 ( & V_123 -> V_7 ) ,
V_78 ) ;
F_117 ( V_123 ) ;
return V_155 ;
V_165:
F_105 (skb, frag2) {
if ( V_163 == V_145 )
break;
V_163 -> V_3 = NULL ;
V_163 -> V_166 = NULL ;
V_5 -> V_168 += V_163 -> V_168 ;
}
}
V_164:
V_150 = V_5 -> V_32 - V_149 ;
V_154 = V_149 ;
* V_156 = V_169 ;
V_152 = V_123 -> V_7 . V_9 -> V_179 ;
while ( V_150 > 0 ) {
V_32 = V_150 ;
if ( V_32 > V_59 )
V_32 = V_59 ;
if ( V_32 < V_150 ) {
V_32 &= ~ 7 ;
}
V_145 = F_119 ( V_32 + V_149 + sizeof( struct V_147 ) +
V_151 + V_152 , V_25 ) ;
if ( ! V_145 ) {
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_78 ) ;
V_155 = - V_170 ;
goto V_161;
}
F_90 ( V_145 , V_5 ) ;
F_120 ( V_145 , V_151 ) ;
F_121 ( V_145 , V_32 + V_149 + sizeof( struct V_147 ) ) ;
F_45 ( V_145 ) ;
V_148 = (struct V_147 * ) ( F_60 ( V_145 ) + V_149 ) ;
V_145 -> V_180 = ( V_145 -> V_181 + V_149 +
sizeof( struct V_147 ) ) ;
if ( V_5 -> V_3 )
F_41 ( V_145 , V_5 -> V_3 ) ;
F_122 ( V_5 , F_60 ( V_145 ) , V_149 ) ;
V_148 -> V_68 = V_68 ;
V_148 -> V_172 = 0 ;
V_148 -> V_174 = V_153 ;
F_107 ( F_123 ( V_5 , V_154 , F_124 ( V_145 ) ,
V_32 ) ) ;
V_150 -= V_32 ;
V_148 -> V_87 = F_3 ( V_88 ) ;
if ( V_150 > 0 )
V_148 -> V_87 |= F_3 ( V_173 ) ;
F_5 ( V_145 ) -> V_67 = F_3 ( V_145 -> V_32 -
sizeof( struct V_53 ) ) ;
V_154 += V_32 ;
V_88 += V_32 ;
V_155 = F_97 ( V_1 , V_3 , V_145 ) ;
if ( V_155 )
goto V_161;
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_177 ) ;
}
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_178 ) ;
F_40 ( V_5 ) ;
return V_155 ;
V_157:
if ( V_5 -> V_3 && F_30 ( F_2 ( V_5 ) ) )
F_125 ( V_5 -> V_3 , V_182 ) ;
V_5 -> V_9 = F_2 ( V_5 ) -> V_9 ;
F_79 ( V_5 , V_135 , 0 , V_59 ) ;
V_155 = - V_77 ;
V_161:
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_78 ) ;
F_14 ( V_5 ) ;
return V_155 ;
}
static inline int F_126 ( const struct V_183 * V_184 ,
const struct V_12 * V_185 ,
const struct V_12 * V_186 )
{
return ( V_184 -> V_187 != 128 || ! F_127 ( V_185 , & V_184 -> V_188 ) ) &&
( ! V_186 || ! F_127 ( V_185 , V_186 ) ) ;
}
static struct V_6 * F_128 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
const struct V_45 * V_46 )
{
struct V_50 * V_51 = F_36 ( V_3 ) ;
struct V_37 * V_123 ;
if ( ! V_7 )
goto V_189;
if ( V_7 -> V_190 -> V_191 != V_192 ) {
F_129 ( V_7 ) ;
return NULL ;
}
V_123 = (struct V_37 * ) V_7 ;
if ( F_126 ( & V_123 -> V_193 , & V_46 -> V_17 , V_51 -> V_194 ) ||
#ifdef F_130
F_126 ( & V_123 -> V_195 , & V_46 -> V_23 , V_51 -> V_196 ) ||
#endif
( ! ( V_46 -> V_197 & V_198 ) &&
( V_46 -> V_199 && V_46 -> V_199 != V_7 -> V_9 -> V_86 ) ) ) {
F_129 ( V_7 ) ;
V_7 = NULL ;
}
V_189:
return V_7 ;
}
static int F_131 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
struct V_6 * * V_7 , struct V_45 * V_46 )
{
#ifdef F_132
struct V_10 * V_200 ;
struct V_37 * V_123 ;
#endif
int V_155 ;
int V_20 = 0 ;
if ( F_133 ( & V_46 -> V_23 ) && ( ! * V_7 || ! ( * V_7 ) -> error ) ) {
struct V_37 * V_123 ;
bool V_201 = * V_7 != NULL ;
if ( ! V_201 )
* V_7 = F_134 ( V_1 , V_3 , V_46 ) ;
V_123 = ( * V_7 ) -> error ? NULL : (struct V_37 * ) * V_7 ;
V_155 = F_135 ( V_1 , V_123 , & V_46 -> V_17 ,
V_3 ? F_36 ( V_3 ) -> V_202 : 0 ,
& V_46 -> V_23 ) ;
if ( V_155 )
goto V_203;
if ( ! V_201 && ( * V_7 ) -> error ) {
F_129 ( * V_7 ) ;
* V_7 = NULL ;
}
if ( V_46 -> V_199 )
V_20 |= V_204 ;
}
if ( ! * V_7 )
* V_7 = F_136 ( V_1 , V_3 , V_46 , V_20 ) ;
V_155 = ( * V_7 ) -> error ;
if ( V_155 )
goto V_203;
#ifdef F_132
V_123 = (struct V_37 * ) * V_7 ;
F_19 () ;
V_200 = F_21 ( V_123 -> V_7 . V_9 ,
F_20 ( V_123 , & V_46 -> V_17 ) ) ;
V_155 = V_200 && ! ( V_200 -> V_205 & V_206 ) ? - V_40 : 0 ;
F_26 () ;
if ( V_155 ) {
struct V_207 * V_208 ;
struct V_45 V_209 ;
int V_210 ;
V_208 = F_137 ( V_1 , & V_46 -> V_23 ,
( * V_7 ) -> V_9 , 1 ) ;
V_210 = ( V_208 && V_208 -> V_20 & V_211 ) ;
if ( V_208 )
F_138 ( V_208 ) ;
if ( V_210 ) {
F_129 ( * V_7 ) ;
memcpy ( & V_209 , V_46 , sizeof( struct V_45 ) ) ;
memset ( & V_209 . V_17 , 0 , sizeof( struct V_12 ) ) ;
* V_7 = F_134 ( V_1 , V_3 , & V_209 ) ;
V_155 = ( * V_7 ) -> error ;
if ( V_155 )
goto V_203;
}
}
#endif
return 0 ;
V_203:
F_129 ( * V_7 ) ;
* V_7 = NULL ;
if ( V_155 == - V_212 )
F_13 ( V_1 , NULL , V_39 ) ;
return V_155 ;
}
int F_139 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_6 * * V_7 ,
struct V_45 * V_46 )
{
* V_7 = NULL ;
return F_131 ( V_1 , V_3 , V_7 , V_46 ) ;
}
struct V_6 * F_140 ( const struct V_2 * V_3 , struct V_45 * V_46 ,
const struct V_12 * V_213 )
{
struct V_6 * V_7 = NULL ;
int V_155 ;
V_155 = F_131 ( F_35 ( V_3 ) , V_3 , & V_7 , V_46 ) ;
if ( V_155 )
return F_141 ( V_155 ) ;
if ( V_213 )
V_46 -> V_17 = * V_213 ;
return F_142 ( F_35 ( V_3 ) , V_7 , F_143 ( V_46 ) , V_3 , 0 ) ;
}
struct V_6 * F_144 ( struct V_2 * V_3 , struct V_45 * V_46 ,
const struct V_12 * V_213 )
{
struct V_6 * V_7 = F_145 ( V_3 , F_36 ( V_3 ) -> V_214 ) ;
V_7 = F_128 ( V_3 , V_7 , V_46 ) ;
if ( ! V_7 )
V_7 = F_140 ( V_3 , V_46 , V_213 ) ;
return V_7 ;
}
static inline int F_146 ( struct V_2 * V_3 ,
struct V_215 * V_216 ,
int F_147 ( void * V_143 , char * V_142 , int V_88 , int V_32 ,
int V_217 , struct V_4 * V_5 ) ,
void * V_143 , int V_218 , int V_219 , int V_220 ,
int V_221 , int V_222 , int V_59 ,
unsigned int V_20 , const struct V_45 * V_46 )
{
struct V_4 * V_5 ;
int V_155 ;
V_5 = F_148 ( V_216 ) ;
if ( ! V_5 ) {
V_5 = F_149 ( V_3 ,
V_219 + V_220 + V_222 + 20 ,
( V_20 & V_223 ) , & V_155 ) ;
if ( ! V_5 )
return V_155 ;
F_120 ( V_5 , V_219 ) ;
F_121 ( V_5 , V_220 + V_222 ) ;
F_150 ( V_5 , V_221 ) ;
V_5 -> V_180 = V_5 -> V_181 + V_220 ;
V_5 -> V_15 = F_3 ( V_16 ) ;
V_5 -> V_224 = 0 ;
F_151 ( V_216 , V_5 ) ;
} else if ( F_29 ( V_5 ) ) {
goto V_225;
}
V_5 -> V_159 = V_160 ;
F_109 ( V_5 ) -> V_226 = ( V_59 - V_220 -
sizeof( struct V_147 ) ) & ~ 7 ;
F_109 ( V_5 ) -> V_227 = V_228 ;
F_109 ( V_5 ) -> V_229 = F_100 ( F_35 ( V_3 ) ,
& V_46 -> V_17 ,
& V_46 -> V_23 ) ;
V_225:
return F_152 ( V_3 , V_5 , F_147 , V_143 ,
( V_218 - V_222 ) ) ;
}
static inline struct V_230 * F_153 ( struct V_230 * V_231 ,
T_5 V_232 )
{
return V_231 ? F_108 ( V_231 , ( V_231 -> V_233 + 1 ) * 8 , V_232 ) : NULL ;
}
static inline struct V_234 * F_154 ( struct V_234 * V_231 ,
T_5 V_232 )
{
return V_231 ? F_108 ( V_231 , ( V_231 -> V_233 + 1 ) * 8 , V_232 ) : NULL ;
}
static void F_155 ( unsigned int * V_59 ,
int * V_235 ,
unsigned int V_220 ,
struct V_4 * V_5 ,
struct V_37 * V_123 ,
unsigned int V_236 )
{
if ( ! ( V_123 -> V_7 . V_20 & V_237 ) ) {
if ( ! V_5 ) {
* V_59 = V_236 - V_123 -> V_7 . V_238 ;
} else {
* V_59 = V_236 ;
}
* V_235 = ( ( * V_59 - V_220 ) & ~ 7 )
+ V_220 - sizeof( struct V_147 ) ;
}
}
static int F_156 ( struct V_2 * V_3 , struct V_239 * V_240 ,
struct V_241 * V_242 , struct V_243 * V_244 ,
struct V_37 * V_123 , struct V_45 * V_46 )
{
struct V_50 * V_51 = F_36 ( V_3 ) ;
unsigned int V_59 ;
struct V_47 * V_48 = V_244 -> V_48 ;
if ( V_48 ) {
if ( F_157 ( V_242 -> V_48 ) )
return - V_40 ;
V_242 -> V_48 = F_158 ( V_48 -> V_245 , V_3 -> V_246 ) ;
if ( F_22 ( ! V_242 -> V_48 ) )
return - V_64 ;
V_242 -> V_48 -> V_245 = V_48 -> V_245 ;
V_242 -> V_48 -> V_62 = V_48 -> V_62 ;
V_242 -> V_48 -> V_61 = V_48 -> V_61 ;
V_242 -> V_48 -> V_247 = F_153 ( V_48 -> V_247 ,
V_3 -> V_246 ) ;
if ( V_48 -> V_247 && ! V_242 -> V_48 -> V_247 )
return - V_64 ;
V_242 -> V_48 -> V_248 = F_153 ( V_48 -> V_248 ,
V_3 -> V_246 ) ;
if ( V_48 -> V_248 && ! V_242 -> V_48 -> V_248 )
return - V_64 ;
V_242 -> V_48 -> V_249 = F_153 ( V_48 -> V_249 ,
V_3 -> V_246 ) ;
if ( V_48 -> V_249 && ! V_242 -> V_48 -> V_249 )
return - V_64 ;
V_242 -> V_48 -> V_119 = F_154 ( V_48 -> V_119 ,
V_3 -> V_246 ) ;
if ( V_48 -> V_119 && ! V_242 -> V_48 -> V_119 )
return - V_64 ;
}
F_114 ( & V_123 -> V_7 ) ;
V_240 -> V_250 . V_7 = & V_123 -> V_7 ;
V_240 -> V_251 . V_252 . V_253 = * V_46 ;
V_242 -> V_29 = V_244 -> V_58 ;
V_242 -> V_49 = V_244 -> V_49 ;
if ( V_123 -> V_7 . V_20 & V_237 )
V_59 = V_51 -> V_254 >= V_255 ?
V_123 -> V_7 . V_9 -> V_59 : F_49 ( & V_123 -> V_7 ) ;
else
V_59 = V_51 -> V_254 >= V_255 ?
V_123 -> V_7 . V_9 -> V_59 : F_49 ( V_123 -> V_7 . V_256 ) ;
if ( V_51 -> V_158 < V_59 ) {
if ( V_51 -> V_158 )
V_59 = V_51 -> V_158 ;
}
V_240 -> V_250 . V_257 = V_59 ;
if ( F_30 ( V_123 -> V_7 . V_256 ) )
V_240 -> V_250 . V_20 |= V_258 ;
V_240 -> V_250 . V_218 = 0 ;
return 0 ;
}
static int F_159 ( struct V_2 * V_3 ,
struct V_45 * V_46 ,
struct V_215 * V_216 ,
struct V_259 * V_240 ,
struct V_241 * V_242 ,
struct V_260 * V_261 ,
int F_147 ( void * V_143 , char * V_142 , int V_88 ,
int V_32 , int V_217 , struct V_4 * V_5 ) ,
void * V_143 , int V_218 , int V_222 ,
unsigned int V_20 , struct V_243 * V_244 ,
const struct V_262 * V_263 )
{
struct V_4 * V_5 , * V_264 = NULL ;
unsigned int V_235 , V_220 , V_59 , V_236 ;
int V_221 = 0 ;
int V_265 = 0 ;
int V_219 ;
int V_266 ;
int V_155 ;
int V_88 = 0 ;
T_6 V_267 = 0 ;
T_2 V_268 = 0 ;
struct V_37 * V_123 = (struct V_37 * ) V_240 -> V_7 ;
struct V_47 * V_48 = V_242 -> V_48 ;
int V_269 = V_176 ;
unsigned int V_270 , V_271 ;
V_5 = F_148 ( V_216 ) ;
if ( ! V_5 ) {
V_221 = V_48 ? V_48 -> V_62 : 0 ;
V_265 = V_123 -> V_7 . V_238 - V_123 -> V_272 ;
}
V_59 = V_240 -> V_257 ;
V_236 = V_59 ;
V_219 = F_37 ( V_123 -> V_7 . V_9 ) ;
V_220 = sizeof( struct V_53 ) + V_123 -> V_272 +
( V_48 ? V_48 -> V_61 : 0 ) ;
V_235 = ( ( V_59 - V_220 ) & ~ 7 ) + V_220 -
sizeof( struct V_147 ) ;
V_271 = sizeof( struct V_53 ) +
( V_48 ? V_48 -> V_62 + V_48 -> V_61 : 0 ) +
( F_30 ( & V_123 -> V_7 ) ?
sizeof( struct V_147 ) : 0 ) +
V_123 -> V_272 ;
if ( V_240 -> V_218 + V_218 > V_59 - V_271 && V_244 -> V_273 &&
( V_3 -> V_274 == V_275 ||
V_3 -> V_274 == V_276 ) ) {
F_160 ( V_3 , V_46 , V_59 - V_271 +
sizeof( struct V_53 ) ) ;
goto V_277;
}
if ( F_161 ( V_3 ) )
V_270 = sizeof( struct V_53 ) + V_278 ;
else
V_270 = V_59 ;
if ( V_240 -> V_218 + V_218 > V_270 - V_271 ) {
V_277:
F_51 ( V_3 , V_77 , V_46 ,
V_59 - V_271 +
sizeof( struct V_53 ) ) ;
return - V_77 ;
}
if ( V_222 && V_3 -> V_274 == V_275 &&
V_271 == sizeof( struct V_53 ) &&
V_218 < V_59 - V_271 &&
! ( V_20 & V_279 ) &&
V_123 -> V_7 . V_9 -> V_280 & ( V_281 | V_282 ) )
V_269 = V_160 ;
if ( V_3 -> V_283 == V_284 || V_3 -> V_283 == V_285 ) {
F_162 ( V_3 , V_263 -> V_286 , & V_267 ) ;
if ( V_267 & V_287 &&
V_3 -> V_288 & V_289 )
V_268 = V_3 -> V_290 ++ ;
}
V_240 -> V_218 += V_218 ;
if ( ( ( V_218 > V_59 ) ||
( V_5 && F_29 ( V_5 ) ) ) &&
( V_3 -> V_274 == V_275 ) &&
( V_123 -> V_7 . V_9 -> V_280 & V_291 ) && ! V_123 -> V_7 . V_238 &&
( V_3 -> V_283 == V_284 ) && ! F_163 ( V_3 ) ) {
V_155 = F_146 ( V_3 , V_216 , F_147 , V_143 , V_218 ,
V_219 , V_220 , V_221 ,
V_222 , V_59 , V_20 , V_46 ) ;
if ( V_155 )
goto error;
return 0 ;
}
if ( ! V_5 )
goto V_292;
while ( V_218 > 0 ) {
V_266 = ( V_240 -> V_218 <= V_59 && ! ( V_240 -> V_20 & V_258 ) ? V_59 : V_235 ) - V_5 -> V_32 ;
if ( V_266 < V_218 )
V_266 = V_235 - V_5 -> V_32 ;
if ( V_266 <= 0 ) {
char * V_92 ;
unsigned int V_293 ;
unsigned int V_294 ;
unsigned int V_295 ;
unsigned int V_296 ;
V_292:
if ( V_5 )
V_295 = V_5 -> V_32 - V_235 ;
else
V_295 = 0 ;
if ( ! V_5 || ! V_264 )
F_155 ( & V_59 , & V_235 ,
V_220 , V_5 , V_123 ,
V_236 ) ;
V_264 = V_5 ;
V_293 = V_218 + V_295 ;
if ( V_293 > ( V_240 -> V_218 <= V_59 && ! ( V_240 -> V_20 & V_258 ) ? V_59 : V_235 ) - V_220 )
V_293 = V_235 - V_220 - V_123 -> V_7 . V_297 ;
if ( ( V_20 & V_279 ) &&
! ( V_123 -> V_7 . V_9 -> V_280 & V_298 ) )
V_296 = V_59 ;
else
V_296 = V_293 + V_220 ;
V_296 += V_265 ;
if ( V_293 != V_218 + V_295 ) {
V_293 += V_123 -> V_7 . V_297 ;
}
V_296 += V_123 -> V_7 . V_297 ;
V_294 = V_293 + V_220 ;
V_296 += sizeof( struct V_147 ) ;
if ( V_222 ) {
V_5 = F_149 ( V_3 ,
V_296 + V_219 ,
( V_20 & V_223 ) , & V_155 ) ;
} else {
V_5 = NULL ;
if ( F_164 ( & V_3 -> V_299 ) <=
2 * V_3 -> V_300 )
V_5 = F_165 ( V_3 ,
V_296 + V_219 , 1 ,
V_3 -> V_246 ) ;
if ( F_22 ( ! V_5 ) )
V_155 = - V_64 ;
}
if ( ! V_5 )
goto error;
V_5 -> V_15 = F_3 ( V_16 ) ;
V_5 -> V_159 = V_269 ;
V_5 -> V_224 = 0 ;
F_120 ( V_5 , V_219 + sizeof( struct V_147 ) +
V_265 ) ;
F_109 ( V_5 ) -> V_267 = V_267 ;
V_267 = 0 ;
F_109 ( V_5 ) -> V_268 = V_268 ;
V_268 = 0 ;
V_92 = F_121 ( V_5 , V_294 ) ;
F_150 ( V_5 , V_221 ) ;
V_92 += V_220 ;
V_5 -> V_180 = ( V_5 -> V_181 +
V_220 ) ;
if ( V_295 ) {
V_5 -> V_224 = F_166 (
V_264 , V_235 ,
V_92 + V_222 , V_295 , 0 ) ;
V_264 -> V_224 = F_167 ( V_264 -> V_224 ,
V_5 -> V_224 ) ;
V_92 += V_295 ;
F_168 ( V_264 , V_235 ) ;
}
V_266 = V_293 - V_222 - V_295 ;
if ( V_266 < 0 ) {
V_155 = - V_40 ;
F_14 ( V_5 ) ;
goto error;
} else if ( V_266 > 0 && F_147 ( V_143 , V_92 + V_222 , V_88 , V_266 , V_295 , V_5 ) < 0 ) {
V_155 = - V_301 ;
F_14 ( V_5 ) ;
goto error;
}
V_88 += V_266 ;
V_218 -= V_293 - V_295 ;
V_222 = 0 ;
V_221 = 0 ;
V_265 = 0 ;
F_151 ( V_216 , V_5 ) ;
continue;
}
if ( V_266 > V_218 )
V_266 = V_218 ;
if ( ! ( V_123 -> V_7 . V_9 -> V_280 & V_298 ) ) {
unsigned int V_302 ;
V_302 = V_5 -> V_32 ;
if ( F_147 ( V_143 , F_121 ( V_5 , V_266 ) ,
V_88 , V_266 , V_302 , V_5 ) < 0 ) {
F_169 ( V_5 , V_302 ) ;
V_155 = - V_301 ;
goto error;
}
} else {
int V_303 = F_109 ( V_5 ) -> V_304 ;
V_155 = - V_170 ;
if ( ! F_170 ( V_3 , V_261 ) )
goto error;
if ( ! F_171 ( V_5 , V_303 , V_261 -> V_305 ,
V_261 -> V_88 ) ) {
V_155 = - V_77 ;
if ( V_303 == V_306 )
goto error;
F_172 ( V_5 , V_303 , V_261 -> V_305 ,
V_261 -> V_88 , 0 ) ;
F_109 ( V_5 ) -> V_304 = ++ V_303 ;
F_173 ( V_261 -> V_305 ) ;
}
V_266 = F_174 ( int , V_266 , V_261 -> V_307 - V_261 -> V_88 ) ;
if ( F_147 ( V_143 ,
F_175 ( V_261 -> V_305 ) + V_261 -> V_88 ,
V_88 , V_266 , V_5 -> V_32 , V_5 ) < 0 )
goto V_308;
V_261 -> V_88 += V_266 ;
F_176 ( & F_109 ( V_5 ) -> V_309 [ V_303 - 1 ] , V_266 ) ;
V_5 -> V_32 += V_266 ;
V_5 -> V_175 += V_266 ;
V_5 -> V_168 += V_266 ;
F_177 ( V_266 , & V_3 -> V_299 ) ;
}
V_88 += V_266 ;
V_218 -= V_266 ;
}
return 0 ;
V_308:
V_155 = - V_301 ;
error:
V_240 -> V_218 -= V_218 ;
F_13 ( F_35 ( V_3 ) , V_123 -> V_310 , V_30 ) ;
return V_155 ;
}
int F_178 ( struct V_2 * V_3 ,
int F_147 ( void * V_143 , char * V_142 , int V_88 , int V_32 ,
int V_217 , struct V_4 * V_5 ) ,
void * V_143 , int V_218 , int V_222 ,
struct V_243 * V_244 , struct V_45 * V_46 ,
struct V_37 * V_123 , unsigned int V_20 ,
const struct V_262 * V_263 )
{
struct V_311 * V_312 = F_179 ( V_3 ) ;
struct V_50 * V_51 = F_36 ( V_3 ) ;
int V_221 ;
int V_155 ;
if ( V_20 & V_313 )
return 0 ;
if ( F_180 ( & V_3 -> V_314 ) ) {
V_155 = F_156 ( V_3 , & V_312 -> V_240 , & V_51 -> V_240 ,
V_244 , V_123 , V_46 ) ;
if ( V_155 )
return V_155 ;
V_221 = ( V_244 -> V_48 ? V_244 -> V_48 -> V_62 : 0 ) ;
V_218 += V_221 ;
V_222 += V_221 ;
} else {
V_46 = & V_312 -> V_240 . V_251 . V_252 . V_253 ;
V_222 = 0 ;
}
return F_159 ( V_3 , V_46 , & V_3 -> V_314 , & V_312 -> V_240 . V_250 ,
& V_51 -> V_240 , F_181 ( V_3 ) , F_147 ,
V_143 , V_218 , V_222 , V_20 , V_244 , V_263 ) ;
}
static void F_182 ( struct V_239 * V_240 ,
struct V_241 * V_242 )
{
if ( V_242 -> V_48 ) {
F_116 ( V_242 -> V_48 -> V_247 ) ;
F_116 ( V_242 -> V_48 -> V_248 ) ;
F_116 ( V_242 -> V_48 -> V_249 ) ;
F_116 ( V_242 -> V_48 -> V_119 ) ;
F_116 ( V_242 -> V_48 ) ;
V_242 -> V_48 = NULL ;
}
if ( V_240 -> V_250 . V_7 ) {
F_129 ( V_240 -> V_250 . V_7 ) ;
V_240 -> V_250 . V_7 = NULL ;
V_240 -> V_250 . V_20 &= ~ V_258 ;
}
memset ( & V_240 -> V_251 , 0 , sizeof( V_240 -> V_251 ) ) ;
}
struct V_4 * F_183 ( struct V_2 * V_3 ,
struct V_215 * V_216 ,
struct V_239 * V_240 ,
struct V_241 * V_242 )
{
struct V_4 * V_5 , * V_315 ;
struct V_4 * * V_316 ;
struct V_12 V_317 , * V_213 = & V_317 ;
struct V_50 * V_51 = F_36 ( V_3 ) ;
struct V_1 * V_1 = F_35 ( V_3 ) ;
struct V_53 * V_54 ;
struct V_47 * V_48 = V_242 -> V_48 ;
struct V_37 * V_123 = (struct V_37 * ) V_240 -> V_250 . V_7 ;
struct V_45 * V_46 = & V_240 -> V_251 . V_252 . V_253 ;
unsigned char V_55 = V_46 -> V_56 ;
V_5 = F_184 ( V_216 ) ;
if ( ! V_5 )
goto V_189;
V_316 = & ( F_109 ( V_5 ) -> V_171 ) ;
if ( V_5 -> V_92 < F_60 ( V_5 ) )
F_111 ( V_5 , F_185 ( V_5 ) ) ;
while ( ( V_315 = F_184 ( V_216 ) ) != NULL ) {
F_111 ( V_315 , F_186 ( V_5 ) ) ;
* V_316 = V_315 ;
V_316 = & ( V_315 -> V_84 ) ;
V_5 -> V_32 += V_315 -> V_32 ;
V_5 -> V_175 += V_315 -> V_32 ;
V_5 -> V_168 += V_315 -> V_168 ;
V_315 -> V_166 = NULL ;
V_315 -> V_3 = NULL ;
}
V_5 -> V_73 = F_161 ( V_3 ) ;
* V_213 = V_46 -> V_17 ;
F_111 ( V_5 , F_186 ( V_5 ) ) ;
if ( V_48 && V_48 -> V_62 )
F_42 ( V_5 , V_48 , & V_55 ) ;
if ( V_48 && V_48 -> V_61 )
F_43 ( V_5 , V_48 , & V_55 , & V_213 ) ;
F_44 ( V_5 , sizeof( struct V_53 ) ) ;
F_45 ( V_5 ) ;
V_54 = F_5 ( V_5 ) ;
F_47 ( V_54 , V_242 -> V_49 ,
F_48 ( V_1 , V_5 , V_46 -> V_65 ,
V_51 -> V_66 , V_46 ) ) ;
V_54 -> V_29 = V_242 -> V_29 ;
V_54 -> V_68 = V_55 ;
V_54 -> V_23 = V_46 -> V_23 ;
V_54 -> V_17 = * V_213 ;
V_5 -> V_69 = V_3 -> V_70 ;
V_5 -> V_71 = V_3 -> V_72 ;
F_92 ( V_5 , F_93 ( & V_123 -> V_7 ) ) ;
F_15 ( V_1 , V_123 -> V_310 , V_74 , V_5 -> V_32 ) ;
if ( V_55 == V_89 ) {
struct V_18 * V_19 = F_6 ( F_2 ( V_5 ) ) ;
F_187 ( V_1 , V_19 , F_188 ( V_5 ) -> V_93 ) ;
F_189 ( V_1 , V_19 , V_318 ) ;
}
F_182 ( V_240 , V_242 ) ;
V_189:
return V_5 ;
}
int F_190 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_35 ( V_5 -> V_3 ) ;
struct V_37 * V_123 = (struct V_37 * ) F_2 ( V_5 ) ;
int V_155 ;
V_155 = F_191 ( V_1 , V_5 -> V_3 , V_5 ) ;
if ( V_155 ) {
if ( V_155 > 0 )
V_155 = F_192 ( V_155 ) ;
if ( V_155 )
F_13 ( V_1 , V_123 -> V_310 ,
V_30 ) ;
}
return V_155 ;
}
int F_193 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_194 ( V_3 ) ;
if ( ! V_5 )
return 0 ;
return F_190 ( V_5 ) ;
}
static void F_195 ( struct V_2 * V_3 ,
struct V_215 * V_216 ,
struct V_239 * V_240 ,
struct V_241 * V_242 )
{
struct V_4 * V_5 ;
while ( ( V_5 = F_196 ( V_216 ) ) != NULL ) {
if ( F_2 ( V_5 ) )
F_13 ( F_35 ( V_3 ) , F_6 ( F_2 ( V_5 ) ) ,
V_30 ) ;
F_14 ( V_5 ) ;
}
F_182 ( V_240 , V_242 ) ;
}
void F_197 ( struct V_2 * V_3 )
{
F_195 ( V_3 , & V_3 -> V_314 ,
& F_179 ( V_3 ) -> V_240 , & F_36 ( V_3 ) -> V_240 ) ;
}
struct V_4 * F_198 ( struct V_2 * V_3 ,
int F_147 ( void * V_143 , char * V_142 , int V_88 ,
int V_32 , int V_217 , struct V_4 * V_5 ) ,
void * V_143 , int V_218 , int V_222 ,
struct V_243 * V_244 , struct V_45 * V_46 ,
struct V_37 * V_123 , unsigned int V_20 ,
const struct V_262 * V_263 )
{
struct V_239 V_240 ;
struct V_241 V_242 ;
struct V_215 V_216 ;
int V_221 = ( V_244 -> V_48 ? V_244 -> V_48 -> V_62 : 0 ) ;
int V_155 ;
if ( V_20 & V_313 )
return NULL ;
F_199 ( & V_216 ) ;
V_240 . V_250 . V_20 = 0 ;
V_240 . V_250 . V_188 = 0 ;
V_240 . V_250 . V_48 = NULL ;
V_242 . V_48 = NULL ;
V_155 = F_156 ( V_3 , & V_240 , & V_242 , V_244 , V_123 , V_46 ) ;
if ( V_155 )
return F_141 ( V_155 ) ;
if ( V_244 -> V_273 < 0 )
V_244 -> V_273 = F_36 ( V_3 ) -> V_273 ;
V_155 = F_159 ( V_3 , V_46 , & V_216 , & V_240 . V_250 , & V_242 ,
& V_319 -> V_320 , F_147 , V_143 ,
V_218 + V_221 , V_222 + V_221 ,
V_20 , V_244 , V_263 ) ;
if ( V_155 ) {
F_195 ( V_3 , & V_216 , & V_240 , & V_242 ) ;
return F_141 ( V_155 ) ;
}
return F_183 ( V_3 , & V_216 , & V_240 , & V_242 ) ;
}
