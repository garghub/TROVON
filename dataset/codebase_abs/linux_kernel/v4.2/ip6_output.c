static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
V_4 -> V_14 = F_3 ( V_15 ) ;
V_4 -> V_8 = V_8 ;
if ( F_4 ( & F_5 ( V_4 ) -> V_16 ) ) {
struct V_17 * V_18 = F_6 ( F_2 ( V_4 ) ) ;
if ( ! ( V_8 -> V_19 & V_20 ) && F_7 ( V_2 ) &&
( ( F_8 ( F_9 ( V_8 ) , V_4 ) &&
! ( F_10 ( V_4 ) -> V_19 & V_21 ) ) ||
F_11 ( V_8 , & F_5 ( V_4 ) -> V_16 ,
& F_5 ( V_4 ) -> V_22 ) ) ) {
struct V_3 * V_23 = F_12 ( V_4 , V_24 ) ;
if ( V_23 )
F_13 ( V_25 , V_26 ,
V_2 , V_23 , NULL , V_23 -> V_8 ,
V_27 ) ;
if ( F_5 ( V_4 ) -> V_28 == 0 ) {
F_14 ( F_9 ( V_8 ) , V_18 ,
V_29 ) ;
F_15 ( V_4 ) ;
return 0 ;
}
}
F_16 ( F_9 ( V_8 ) , V_18 , V_30 ,
V_4 -> V_31 ) ;
if ( F_17 ( & F_5 ( V_4 ) -> V_16 ) <=
V_32 &&
! ( V_8 -> V_19 & V_20 ) ) {
F_15 ( V_4 ) ;
return 0 ;
}
}
F_18 () ;
V_12 = F_19 ( (struct V_33 * ) V_6 , & F_5 ( V_4 ) -> V_16 ) ;
V_10 = F_20 ( V_6 -> V_8 , V_12 ) ;
if ( F_21 ( ! V_10 ) )
V_10 = F_22 ( & V_34 , V_12 , V_6 -> V_8 , false ) ;
if ( ! F_23 ( V_10 ) ) {
V_13 = F_24 ( V_6 , V_10 , V_4 ) ;
F_25 () ;
return V_13 ;
}
F_25 () ;
F_14 ( F_9 ( V_6 -> V_8 ) ,
F_6 ( V_6 ) , V_35 ) ;
F_15 ( V_4 ) ;
return - V_36 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ( V_4 -> V_31 > F_27 ( V_4 ) && ! F_28 ( V_4 ) ) ||
F_29 ( F_2 ( V_4 ) ) ||
( F_10 ( V_4 ) -> V_37 && V_4 -> V_31 > F_10 ( V_4 ) -> V_37 ) )
return F_30 ( V_2 , V_4 , F_1 ) ;
else
return F_1 ( V_2 , V_4 ) ;
}
int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) -> V_8 ;
struct V_17 * V_18 = F_6 ( F_2 ( V_4 ) ) ;
if ( F_21 ( V_18 -> V_38 . V_39 ) ) {
F_14 ( F_9 ( V_8 ) , V_18 ,
V_29 ) ;
F_15 ( V_4 ) ;
return 0 ;
}
return F_32 ( V_25 , V_26 , V_2 , V_4 ,
NULL , V_8 ,
F_26 ,
! ( F_10 ( V_4 ) -> V_19 & V_40 ) ) ;
}
int F_33 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_41 * V_42 ,
struct V_43 * V_44 , int V_45 )
{
struct V_46 * V_46 = F_34 ( V_2 ) ;
struct V_47 * V_48 = F_35 ( V_2 ) ;
struct V_11 * V_49 = & V_42 -> V_16 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_50 * V_51 ;
T_1 V_52 = V_42 -> V_53 ;
int V_54 = V_4 -> V_31 ;
int V_55 = - 1 ;
T_2 V_56 ;
if ( V_44 ) {
unsigned int V_57 ;
V_57 = V_44 -> V_58 + V_44 -> V_59 ;
V_54 += V_57 ;
V_57 += sizeof( struct V_50 ) + F_36 ( V_6 -> V_8 ) ;
if ( F_37 ( V_4 ) < V_57 ) {
struct V_3 * V_60 = F_38 ( V_4 , V_57 ) ;
if ( ! V_60 ) {
F_14 ( V_46 , F_6 ( F_2 ( V_4 ) ) ,
V_29 ) ;
F_15 ( V_4 ) ;
return - V_61 ;
}
F_39 ( V_4 ) ;
V_4 = V_60 ;
F_40 ( V_4 , V_2 ) ;
}
if ( V_44 -> V_59 )
F_41 ( V_4 , V_44 , & V_52 ) ;
if ( V_44 -> V_58 )
F_42 ( V_4 , V_44 , & V_52 , & V_49 ) ;
}
F_43 ( V_4 , sizeof( struct V_50 ) ) ;
F_44 ( V_4 ) ;
V_51 = F_5 ( V_4 ) ;
if ( V_48 )
V_55 = V_48 -> V_28 ;
if ( V_55 < 0 )
V_55 = F_45 ( V_6 ) ;
F_46 ( V_51 , V_45 , F_47 ( V_46 , V_4 , V_42 -> V_62 ,
V_48 -> V_63 ) ) ;
V_51 -> V_64 = F_3 ( V_54 ) ;
V_51 -> V_65 = V_52 ;
V_51 -> V_28 = V_55 ;
V_51 -> V_22 = V_42 -> V_22 ;
V_51 -> V_16 = * V_49 ;
V_4 -> V_14 = F_3 ( V_15 ) ;
V_4 -> V_66 = V_2 -> V_67 ;
V_4 -> V_68 = V_2 -> V_69 ;
V_56 = F_48 ( V_6 ) ;
if ( ( V_4 -> V_31 <= V_56 ) || V_4 -> V_70 || F_28 ( V_4 ) ) {
F_16 ( V_46 , F_6 ( F_2 ( V_4 ) ) ,
V_71 , V_4 -> V_31 ) ;
return F_13 ( V_25 , V_72 , V_2 , V_4 ,
NULL , V_6 -> V_8 , V_73 ) ;
}
V_4 -> V_8 = V_6 -> V_8 ;
F_49 ( V_2 , V_74 , V_42 , V_56 ) ;
F_14 ( V_46 , F_6 ( F_2 ( V_4 ) ) , V_75 ) ;
F_15 ( V_4 ) ;
return - V_74 ;
}
static int F_50 ( struct V_3 * V_4 , int V_76 )
{
struct V_77 * V_78 ;
struct V_1 * V_79 = NULL ;
F_51 ( & V_80 ) ;
for ( V_78 = V_77 ; V_78 ; V_78 = V_78 -> V_81 ) {
struct V_1 * V_2 = V_78 -> V_2 ;
if ( V_2 && V_78 -> V_76 == V_76 &&
( ! V_2 -> V_82 ||
V_2 -> V_82 == V_4 -> V_8 -> V_83 ) ) {
if ( V_79 ) {
struct V_3 * V_60 = F_12 ( V_4 , V_24 ) ;
if ( V_60 )
F_52 ( V_79 , V_60 ) ;
}
V_79 = V_2 ;
}
}
if ( V_79 ) {
F_52 ( V_79 , V_4 ) ;
F_53 ( & V_80 ) ;
return 1 ;
}
F_53 ( & V_80 ) ;
return 0 ;
}
static int F_54 ( struct V_3 * V_4 )
{
struct V_50 * V_51 = F_5 ( V_4 ) ;
T_1 V_65 = V_51 -> V_65 ;
T_3 V_84 ;
int V_85 ;
if ( F_55 ( V_65 ) ) {
V_85 = F_56 ( V_4 , sizeof( * V_51 ) , & V_65 , & V_84 ) ;
if ( V_85 < 0 )
return 0 ;
} else
V_85 = sizeof( struct V_50 ) ;
if ( V_65 == V_86 ) {
struct V_87 * V_88 ;
if ( ! F_57 ( V_4 , ( F_58 ( V_4 ) +
V_85 + 1 - V_4 -> V_89 ) ) )
return 0 ;
V_88 = (struct V_87 * ) ( F_58 ( V_4 ) + V_85 ) ;
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
if ( F_59 ( & V_51 -> V_16 ) & V_96 ) {
F_60 ( V_4 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_61 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_62 ( V_4 ) ;
return V_73 ( V_2 , V_4 ) ;
}
static unsigned int F_63 ( const struct V_5 * V_6 )
{
unsigned int V_56 ;
struct V_17 * V_18 ;
if ( F_64 ( V_6 , V_97 ) ) {
V_56 = F_65 ( V_6 , V_97 ) ;
if ( V_56 )
return V_56 ;
}
V_56 = V_98 ;
F_66 () ;
V_18 = F_67 ( V_6 -> V_8 ) ;
if ( V_18 )
V_56 = V_18 -> V_38 . V_99 ;
F_68 () ;
return V_56 ;
}
static bool F_69 ( const struct V_3 * V_4 , unsigned int V_56 )
{
if ( V_4 -> V_31 <= V_56 )
return false ;
if ( F_10 ( V_4 ) -> V_37 && F_10 ( V_4 ) -> V_37 > V_56 )
return true ;
if ( V_4 -> V_70 )
return false ;
if ( F_28 ( V_4 ) && F_70 ( V_4 ) <= V_56 )
return false ;
return true ;
}
int F_71 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_50 * V_51 = F_5 ( V_4 ) ;
struct V_100 * V_44 = F_10 ( V_4 ) ;
struct V_46 * V_46 = F_9 ( V_6 -> V_8 ) ;
T_2 V_56 ;
if ( V_46 -> V_101 . V_102 -> V_103 == 0 )
goto error;
if ( V_4 -> V_104 != V_105 )
goto V_106;
if ( F_72 ( V_4 ) )
goto V_106;
if ( ! F_73 ( NULL , V_107 , V_4 ) ) {
F_74 ( V_46 , F_6 ( V_6 ) ,
V_108 ) ;
goto V_106;
}
F_75 ( V_4 ) ;
if ( F_21 ( V_44 -> V_19 & V_109 ) ) {
if ( F_50 ( V_4 , F_76 ( V_44 -> V_78 ) ) )
return 0 ;
}
if ( V_51 -> V_28 <= 1 ) {
V_4 -> V_8 = V_6 -> V_8 ;
F_77 ( V_4 , V_110 , V_111 , 0 ) ;
F_74 ( V_46 , F_6 ( V_6 ) ,
V_112 ) ;
F_15 ( V_4 ) ;
return - V_113 ;
}
if ( V_46 -> V_101 . V_102 -> V_114 &&
F_78 ( & V_34 , V_46 , & V_51 -> V_16 , V_4 -> V_8 , 0 ) ) {
int V_115 = F_54 ( V_4 ) ;
if ( V_115 > 0 )
return F_79 ( V_4 ) ;
else if ( V_115 < 0 ) {
F_74 ( V_46 , F_6 ( V_6 ) ,
V_108 ) ;
goto V_106;
}
}
if ( ! F_80 ( V_4 ) ) {
F_74 ( V_46 , F_6 ( V_6 ) ,
V_108 ) ;
goto V_106;
}
V_6 = F_2 ( V_4 ) ;
if ( V_4 -> V_8 == V_6 -> V_8 && V_44 -> V_116 == 0 && ! F_81 ( V_4 ) ) {
struct V_11 * V_117 = NULL ;
struct V_118 * V_119 ;
struct V_33 * V_120 ;
V_120 = (struct V_33 * ) V_6 ;
if ( V_120 -> V_121 & V_122 )
V_117 = & V_120 -> V_123 ;
else
V_117 = & V_51 -> V_16 ;
V_119 = F_82 ( V_46 -> V_101 . V_124 , & V_51 -> V_16 , 1 ) ;
if ( F_83 ( V_119 , 1 * V_125 ) )
F_84 ( V_4 , V_117 ) ;
if ( V_119 )
F_85 ( V_119 ) ;
} else {
int V_126 = F_59 ( & V_51 -> V_22 ) ;
if ( V_126 == V_127 ||
V_126 & ( V_128 | V_129 ) )
goto error;
if ( V_126 & V_96 ) {
F_77 ( V_4 , V_130 ,
V_131 , 0 ) ;
goto error;
}
}
V_56 = F_63 ( V_6 ) ;
if ( V_56 < V_98 )
V_56 = V_98 ;
if ( F_69 ( V_4 , V_56 ) ) {
V_4 -> V_8 = V_6 -> V_8 ;
F_77 ( V_4 , V_132 , 0 , V_56 ) ;
F_74 ( V_46 , F_6 ( V_6 ) ,
V_133 ) ;
F_74 ( V_46 , F_6 ( V_6 ) ,
V_75 ) ;
F_15 ( V_4 ) ;
return - V_74 ;
}
if ( F_86 ( V_4 , V_6 -> V_8 -> V_134 ) ) {
F_74 ( V_46 , F_6 ( V_6 ) ,
V_29 ) ;
goto V_106;
}
V_51 = F_5 ( V_4 ) ;
V_51 -> V_28 -- ;
F_74 ( V_46 , F_6 ( V_6 ) , V_135 ) ;
F_87 ( V_46 , F_6 ( V_6 ) , V_136 , V_4 -> V_31 ) ;
return F_13 ( V_25 , V_137 , NULL , V_4 ,
V_4 -> V_8 , V_6 -> V_8 ,
F_61 ) ;
error:
F_74 ( V_46 , F_6 ( V_6 ) , V_138 ) ;
V_106:
F_15 ( V_4 ) ;
return - V_36 ;
}
static void F_88 ( struct V_3 * V_139 , struct V_3 * V_140 )
{
V_139 -> V_104 = V_140 -> V_104 ;
V_139 -> V_66 = V_140 -> V_66 ;
V_139 -> V_14 = V_140 -> V_14 ;
F_89 ( V_139 ) ;
F_90 ( V_139 , F_91 ( F_2 ( V_140 ) ) ) ;
V_139 -> V_8 = V_140 -> V_8 ;
V_139 -> V_68 = V_140 -> V_68 ;
#ifdef F_92
V_139 -> V_141 = V_140 -> V_141 ;
#endif
F_93 ( V_139 , V_140 ) ;
F_94 ( V_139 , V_140 ) ;
}
int F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int (* F_95)( struct V_1 * , struct V_3 * ) )
{
struct V_3 * V_142 ;
struct V_33 * V_120 = (struct V_33 * ) F_2 ( V_4 ) ;
struct V_47 * V_48 = V_4 -> V_2 && ! F_96 () ?
F_35 ( V_4 -> V_2 ) : NULL ;
struct V_50 * V_143 ;
struct V_144 * V_145 ;
unsigned int V_56 , V_146 , V_147 , V_31 ;
int V_148 , V_149 ;
T_4 V_150 ;
int V_151 , V_85 = 0 , V_152 = 0 ;
T_1 * V_153 , V_65 = 0 ;
struct V_46 * V_46 = F_9 ( F_2 ( V_4 ) -> V_8 ) ;
V_146 = F_97 ( V_4 , & V_153 ) ;
V_65 = * V_153 ;
V_56 = F_27 ( V_4 ) ;
if ( F_21 ( ! V_4 -> V_70 && V_4 -> V_31 > V_56 ) )
goto V_154;
if ( F_10 ( V_4 ) -> V_37 ) {
if ( F_10 ( V_4 ) -> V_37 > V_56 )
goto V_154;
V_56 = F_10 ( V_4 ) -> V_37 ;
if ( V_56 < V_98 )
V_56 = V_98 ;
}
if ( V_48 && V_48 -> V_155 < V_56 ) {
if ( V_48 -> V_155 )
V_56 = V_48 -> V_155 ;
}
V_56 -= V_146 + sizeof( struct V_144 ) ;
V_150 = F_98 ( V_46 , & F_5 ( V_4 ) -> V_16 ,
& F_5 ( V_4 ) -> V_22 ) ;
if ( F_99 ( V_4 ) ) {
int V_156 = F_100 ( V_4 ) ;
struct V_3 * V_157 ;
if ( V_156 - V_146 > V_56 ||
( ( V_156 - V_146 ) & 7 ) ||
F_101 ( V_4 ) )
goto V_158;
F_102 (skb, frag) {
if ( V_142 -> V_31 > V_56 ||
( ( V_142 -> V_31 & 7 ) && V_142 -> V_81 ) ||
F_37 ( V_142 ) < V_146 )
goto V_159;
if ( F_103 ( V_142 ) )
goto V_159;
F_104 ( V_142 -> V_2 ) ;
if ( V_4 -> V_2 ) {
V_142 -> V_2 = V_4 -> V_2 ;
V_142 -> V_160 = V_161 ;
}
V_4 -> V_162 -= V_142 -> V_162 ;
}
V_152 = 0 ;
V_85 = 0 ;
V_142 = F_105 ( V_4 ) -> V_163 ;
F_106 ( V_4 ) ;
* V_153 = V_164 ;
V_143 = F_107 ( F_58 ( V_4 ) , V_146 , V_24 ) ;
if ( ! V_143 ) {
F_14 ( V_46 , F_6 ( F_2 ( V_4 ) ) ,
V_75 ) ;
return - V_165 ;
}
F_108 ( V_4 , V_146 ) ;
V_145 = (struct V_144 * ) F_109 ( V_4 , sizeof( struct V_144 ) ) ;
F_109 ( V_4 , V_146 ) ;
F_44 ( V_4 ) ;
memcpy ( F_58 ( V_4 ) , V_143 , V_146 ) ;
V_145 -> V_65 = V_65 ;
V_145 -> V_166 = 0 ;
V_145 -> V_84 = F_3 ( V_167 ) ;
V_145 -> V_168 = V_150 ;
V_156 = F_100 ( V_4 ) ;
V_4 -> V_169 = V_156 - F_110 ( V_4 ) ;
V_4 -> V_31 = V_156 ;
F_5 ( V_4 ) -> V_64 = F_3 ( V_156 -
sizeof( struct V_50 ) ) ;
F_111 ( & V_120 -> V_6 ) ;
for (; ; ) {
if ( V_142 ) {
V_142 -> V_170 = V_171 ;
F_112 ( V_142 ) ;
V_145 = (struct V_144 * ) F_109 ( V_142 , sizeof( struct V_144 ) ) ;
F_109 ( V_142 , V_146 ) ;
F_44 ( V_142 ) ;
memcpy ( F_58 ( V_142 ) , V_143 ,
V_146 ) ;
V_85 += V_4 -> V_31 - V_146 - sizeof( struct V_144 ) ;
V_145 -> V_65 = V_65 ;
V_145 -> V_166 = 0 ;
V_145 -> V_84 = F_3 ( V_85 ) ;
if ( V_142 -> V_81 )
V_145 -> V_84 |= F_3 ( V_167 ) ;
V_145 -> V_168 = V_150 ;
F_5 ( V_142 ) -> V_64 =
F_3 ( V_142 -> V_31 -
sizeof( struct V_50 ) ) ;
F_88 ( V_142 , V_4 ) ;
}
V_152 = F_95 ( V_2 , V_4 ) ;
if ( ! V_152 )
F_14 ( V_46 , F_6 ( & V_120 -> V_6 ) ,
V_172 ) ;
if ( V_152 || ! V_142 )
break;
V_4 = V_142 ;
V_142 = V_4 -> V_81 ;
V_4 -> V_81 = NULL ;
}
F_113 ( V_143 ) ;
if ( V_152 == 0 ) {
F_14 ( V_46 , F_6 ( & V_120 -> V_6 ) ,
V_173 ) ;
F_114 ( V_120 ) ;
return 0 ;
}
F_115 ( V_142 ) ;
F_14 ( V_46 , F_6 ( & V_120 -> V_6 ) ,
V_75 ) ;
F_114 ( V_120 ) ;
return V_152 ;
V_159:
F_102 (skb, frag2) {
if ( V_157 == V_142 )
break;
V_157 -> V_2 = NULL ;
V_157 -> V_160 = NULL ;
V_4 -> V_162 += V_157 -> V_162 ;
}
}
V_158:
if ( ( V_4 -> V_170 == V_174 ) &&
F_116 ( V_4 ) )
goto V_175;
V_147 = V_4 -> V_31 - V_146 ;
V_151 = V_146 ;
* V_153 = V_164 ;
V_148 = F_36 ( V_120 -> V_6 . V_8 ) ;
V_149 = V_120 -> V_6 . V_8 -> V_176 ;
while ( V_147 > 0 ) {
V_31 = V_147 ;
if ( V_31 > V_56 )
V_31 = V_56 ;
if ( V_31 < V_147 ) {
V_31 &= ~ 7 ;
}
V_142 = F_117 ( V_31 + V_146 + sizeof( struct V_144 ) +
V_148 + V_149 , V_24 ) ;
if ( ! V_142 ) {
F_14 ( V_46 , F_6 ( F_2 ( V_4 ) ) ,
V_75 ) ;
V_152 = - V_165 ;
goto V_175;
}
F_88 ( V_142 , V_4 ) ;
F_118 ( V_142 , V_148 ) ;
F_119 ( V_142 , V_31 + V_146 + sizeof( struct V_144 ) ) ;
F_44 ( V_142 ) ;
V_145 = (struct V_144 * ) ( F_58 ( V_142 ) + V_146 ) ;
V_142 -> V_177 = ( V_142 -> V_178 + V_146 +
sizeof( struct V_144 ) ) ;
if ( V_4 -> V_2 )
F_40 ( V_142 , V_4 -> V_2 ) ;
F_120 ( V_4 , F_58 ( V_142 ) , V_146 ) ;
V_145 -> V_65 = V_65 ;
V_145 -> V_166 = 0 ;
V_145 -> V_168 = V_150 ;
F_104 ( F_121 ( V_4 , V_151 , F_122 ( V_142 ) ,
V_31 ) ) ;
V_147 -= V_31 ;
V_145 -> V_84 = F_3 ( V_85 ) ;
if ( V_147 > 0 )
V_145 -> V_84 |= F_3 ( V_167 ) ;
F_5 ( V_142 ) -> V_64 = F_3 ( V_142 -> V_31 -
sizeof( struct V_50 ) ) ;
V_151 += V_31 ;
V_85 += V_31 ;
V_152 = F_95 ( V_2 , V_142 ) ;
if ( V_152 )
goto V_175;
F_14 ( V_46 , F_6 ( F_2 ( V_4 ) ) ,
V_172 ) ;
}
F_14 ( V_46 , F_6 ( F_2 ( V_4 ) ) ,
V_173 ) ;
F_39 ( V_4 ) ;
return V_152 ;
V_154:
if ( V_4 -> V_2 && F_29 ( F_2 ( V_4 ) ) )
F_123 ( V_4 -> V_2 , V_179 ) ;
V_4 -> V_8 = F_2 ( V_4 ) -> V_8 ;
F_77 ( V_4 , V_132 , 0 , V_56 ) ;
V_152 = - V_74 ;
V_175:
F_14 ( V_46 , F_6 ( F_2 ( V_4 ) ) ,
V_75 ) ;
F_15 ( V_4 ) ;
return V_152 ;
}
static inline int F_124 ( const struct V_180 * V_181 ,
const struct V_11 * V_182 ,
const struct V_11 * V_183 )
{
return ( V_181 -> V_184 != 128 || ! F_125 ( V_182 , & V_181 -> V_185 ) ) &&
( ! V_183 || ! F_125 ( V_182 , V_183 ) ) ;
}
static struct V_5 * F_126 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const struct V_41 * V_42 )
{
struct V_47 * V_48 = F_35 ( V_2 ) ;
struct V_33 * V_120 ;
if ( ! V_6 )
goto V_186;
if ( V_6 -> V_187 -> V_188 != V_189 ) {
F_127 ( V_6 ) ;
return NULL ;
}
V_120 = (struct V_33 * ) V_6 ;
if ( F_124 ( & V_120 -> V_190 , & V_42 -> V_16 , V_48 -> V_191 ) ||
#ifdef F_128
F_124 ( & V_120 -> V_192 , & V_42 -> V_22 , V_48 -> V_193 ) ||
#endif
( V_42 -> V_194 && V_42 -> V_194 != V_6 -> V_8 -> V_83 ) ) {
F_127 ( V_6 ) ;
V_6 = NULL ;
}
V_186:
return V_6 ;
}
static int F_129 ( struct V_1 * V_2 ,
struct V_5 * * V_6 , struct V_41 * V_42 )
{
struct V_46 * V_46 = F_34 ( V_2 ) ;
#ifdef F_130
struct V_9 * V_195 ;
struct V_33 * V_120 ;
#endif
int V_152 ;
if ( F_131 ( & V_42 -> V_22 ) && ( ! * V_6 || ! ( * V_6 ) -> error ) ) {
struct V_33 * V_120 ;
bool V_196 = * V_6 != NULL ;
if ( ! V_196 )
* V_6 = F_132 ( V_46 , V_2 , V_42 ) ;
V_120 = ( * V_6 ) -> error ? NULL : (struct V_33 * ) * V_6 ;
V_152 = F_133 ( V_46 , V_120 , & V_42 -> V_16 ,
V_2 ? F_35 ( V_2 ) -> V_197 : 0 ,
& V_42 -> V_22 ) ;
if ( V_152 )
goto V_198;
if ( ! V_196 && ( * V_6 ) -> error ) {
F_127 ( * V_6 ) ;
* V_6 = NULL ;
}
}
if ( ! * V_6 )
* V_6 = F_132 ( V_46 , V_2 , V_42 ) ;
V_152 = ( * V_6 ) -> error ;
if ( V_152 )
goto V_198;
#ifdef F_130
V_120 = (struct V_33 * ) * V_6 ;
F_18 () ;
V_195 = F_20 ( V_120 -> V_6 . V_8 ,
F_19 ( V_120 , & V_42 -> V_16 ) ) ;
V_152 = V_195 && ! ( V_195 -> V_199 & V_200 ) ? - V_36 : 0 ;
F_25 () ;
if ( V_152 ) {
struct V_201 * V_202 ;
struct V_41 V_203 ;
int V_204 ;
V_202 = F_134 ( V_46 , & V_42 -> V_22 ,
( * V_6 ) -> V_8 , 1 ) ;
V_204 = ( V_202 && V_202 -> V_19 & V_205 ) ;
if ( V_202 )
F_135 ( V_202 ) ;
if ( V_204 ) {
F_127 ( * V_6 ) ;
memcpy ( & V_203 , V_42 , sizeof( struct V_41 ) ) ;
memset ( & V_203 . V_16 , 0 , sizeof( struct V_11 ) ) ;
* V_6 = F_132 ( V_46 , V_2 , & V_203 ) ;
V_152 = ( * V_6 ) -> error ;
if ( V_152 )
goto V_198;
}
}
#endif
return 0 ;
V_198:
if ( V_152 == - V_206 )
F_14 ( V_46 , NULL , V_35 ) ;
F_127 ( * V_6 ) ;
* V_6 = NULL ;
return V_152 ;
}
int F_136 ( struct V_1 * V_2 , struct V_5 * * V_6 , struct V_41 * V_42 )
{
* V_6 = NULL ;
return F_129 ( V_2 , V_6 , V_42 ) ;
}
struct V_5 * F_137 ( struct V_1 * V_2 , struct V_41 * V_42 ,
const struct V_11 * V_207 )
{
struct V_5 * V_6 = NULL ;
int V_152 ;
V_152 = F_129 ( V_2 , & V_6 , V_42 ) ;
if ( V_152 )
return F_138 ( V_152 ) ;
if ( V_207 )
V_42 -> V_16 = * V_207 ;
return F_139 ( F_34 ( V_2 ) , V_6 , F_140 ( V_42 ) , V_2 , 0 ) ;
}
struct V_5 * F_141 ( struct V_1 * V_2 , struct V_41 * V_42 ,
const struct V_11 * V_207 )
{
struct V_5 * V_6 = F_142 ( V_2 , F_35 ( V_2 ) -> V_208 ) ;
int V_152 ;
V_6 = F_126 ( V_2 , V_6 , V_42 ) ;
V_152 = F_129 ( V_2 , & V_6 , V_42 ) ;
if ( V_152 )
return F_138 ( V_152 ) ;
if ( V_207 )
V_42 -> V_16 = * V_207 ;
return F_139 ( F_34 ( V_2 ) , V_6 , F_140 ( V_42 ) , V_2 , 0 ) ;
}
static inline int F_143 ( struct V_1 * V_2 ,
struct V_209 * V_210 ,
int F_144 ( void * V_140 , char * V_139 , int V_85 , int V_31 ,
int V_211 , struct V_3 * V_4 ) ,
void * V_140 , int V_212 , int V_213 , int V_214 ,
int V_215 , int V_56 , unsigned int V_19 ,
const struct V_41 * V_42 )
{
struct V_3 * V_4 ;
int V_152 ;
V_4 = F_145 ( V_210 ) ;
if ( ! V_4 ) {
V_4 = F_146 ( V_2 ,
V_213 + V_214 + V_215 + 20 ,
( V_19 & V_216 ) , & V_152 ) ;
if ( ! V_4 )
return V_152 ;
F_118 ( V_4 , V_213 ) ;
F_119 ( V_4 , V_214 + V_215 ) ;
F_44 ( V_4 ) ;
V_4 -> V_177 = V_4 -> V_178 + V_214 ;
V_4 -> V_14 = F_3 ( V_15 ) ;
V_4 -> V_217 = 0 ;
F_147 ( V_210 , V_4 ) ;
} else if ( F_28 ( V_4 ) ) {
goto V_218;
}
V_4 -> V_170 = V_174 ;
F_105 ( V_4 ) -> V_219 = ( V_56 - V_214 -
sizeof( struct V_144 ) ) & ~ 7 ;
F_105 ( V_4 ) -> V_220 = V_221 ;
F_105 ( V_4 ) -> V_222 = F_98 ( F_34 ( V_2 ) ,
& V_42 -> V_16 ,
& V_42 -> V_22 ) ;
V_218:
return F_148 ( V_2 , V_4 , F_144 , V_140 ,
( V_212 - V_215 ) ) ;
}
static inline struct V_223 * F_149 ( struct V_223 * V_224 ,
T_5 V_225 )
{
return V_224 ? F_107 ( V_224 , ( V_224 -> V_226 + 1 ) * 8 , V_225 ) : NULL ;
}
static inline struct V_227 * F_150 ( struct V_227 * V_224 ,
T_5 V_225 )
{
return V_224 ? F_107 ( V_224 , ( V_224 -> V_226 + 1 ) * 8 , V_225 ) : NULL ;
}
static void F_151 ( unsigned int * V_56 ,
int * V_228 ,
unsigned int V_214 ,
struct V_3 * V_4 ,
struct V_33 * V_120 ,
unsigned int V_229 )
{
if ( ! ( V_120 -> V_6 . V_19 & V_230 ) ) {
if ( ! V_4 ) {
* V_56 = V_229 - V_120 -> V_6 . V_231 ;
} else {
* V_56 = V_229 ;
}
* V_228 = ( ( * V_56 - V_214 ) & ~ 7 )
+ V_214 - sizeof( struct V_144 ) ;
}
}
static int F_152 ( struct V_1 * V_2 , struct V_232 * V_233 ,
struct V_234 * V_235 ,
int V_55 , int V_45 , struct V_43 * V_44 ,
struct V_33 * V_120 , struct V_41 * V_42 )
{
struct V_47 * V_48 = F_35 ( V_2 ) ;
unsigned int V_56 ;
if ( V_44 ) {
if ( F_153 ( V_235 -> V_44 ) )
return - V_36 ;
V_235 -> V_44 = F_154 ( V_44 -> V_236 , V_2 -> V_237 ) ;
if ( F_21 ( ! V_235 -> V_44 ) )
return - V_61 ;
V_235 -> V_44 -> V_236 = V_44 -> V_236 ;
V_235 -> V_44 -> V_59 = V_44 -> V_59 ;
V_235 -> V_44 -> V_58 = V_44 -> V_58 ;
V_235 -> V_44 -> V_238 = F_149 ( V_44 -> V_238 ,
V_2 -> V_237 ) ;
if ( V_44 -> V_238 && ! V_235 -> V_44 -> V_238 )
return - V_61 ;
V_235 -> V_44 -> V_239 = F_149 ( V_44 -> V_239 ,
V_2 -> V_237 ) ;
if ( V_44 -> V_239 && ! V_235 -> V_44 -> V_239 )
return - V_61 ;
V_235 -> V_44 -> V_240 = F_149 ( V_44 -> V_240 ,
V_2 -> V_237 ) ;
if ( V_44 -> V_240 && ! V_235 -> V_44 -> V_240 )
return - V_61 ;
V_235 -> V_44 -> V_116 = F_150 ( V_44 -> V_116 ,
V_2 -> V_237 ) ;
if ( V_44 -> V_116 && ! V_235 -> V_44 -> V_116 )
return - V_61 ;
}
F_111 ( & V_120 -> V_6 ) ;
V_233 -> V_241 . V_6 = & V_120 -> V_6 ;
V_233 -> V_242 . V_243 . V_244 = * V_42 ;
V_235 -> V_28 = V_55 ;
V_235 -> V_45 = V_45 ;
if ( V_120 -> V_6 . V_19 & V_230 )
V_56 = V_48 -> V_245 >= V_246 ?
V_120 -> V_6 . V_8 -> V_56 : F_48 ( & V_120 -> V_6 ) ;
else
V_56 = V_48 -> V_245 >= V_246 ?
V_120 -> V_6 . V_8 -> V_56 : F_48 ( V_120 -> V_6 . V_247 ) ;
if ( V_48 -> V_155 < V_56 ) {
if ( V_48 -> V_155 )
V_56 = V_48 -> V_155 ;
}
V_233 -> V_241 . V_248 = V_56 ;
if ( F_29 ( V_120 -> V_6 . V_247 ) )
V_233 -> V_241 . V_19 |= V_249 ;
V_233 -> V_241 . V_212 = 0 ;
return 0 ;
}
static int F_155 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
struct V_209 * V_210 ,
struct V_250 * V_233 ,
struct V_234 * V_235 ,
struct V_251 * V_252 ,
int F_144 ( void * V_140 , char * V_139 , int V_85 ,
int V_31 , int V_211 , struct V_3 * V_4 ) ,
void * V_140 , int V_212 , int V_215 ,
unsigned int V_19 , int V_253 )
{
struct V_3 * V_4 , * V_254 = NULL ;
unsigned int V_228 , V_214 , V_56 , V_229 ;
int V_255 = 0 ;
int V_256 = 0 ;
int V_213 ;
int V_257 ;
int V_152 ;
int V_85 = 0 ;
T_6 V_258 = 0 ;
T_2 V_259 = 0 ;
struct V_33 * V_120 = (struct V_33 * ) V_233 -> V_6 ;
struct V_43 * V_44 = V_235 -> V_44 ;
int V_260 = V_171 ;
V_4 = F_145 ( V_210 ) ;
if ( ! V_4 ) {
V_255 = V_44 ? V_44 -> V_59 : 0 ;
V_256 = V_120 -> V_6 . V_231 - V_120 -> V_261 ;
}
V_56 = V_233 -> V_248 ;
V_229 = V_56 ;
V_213 = F_36 ( V_120 -> V_6 . V_8 ) ;
V_214 = sizeof( struct V_50 ) + V_120 -> V_261 +
( V_44 ? V_44 -> V_58 : 0 ) ;
V_228 = ( ( V_56 - V_214 ) & ~ 7 ) + V_214 -
sizeof( struct V_144 ) ;
if ( V_56 <= sizeof( struct V_50 ) + V_262 ) {
unsigned int V_263 , V_264 ;
V_264 = sizeof( struct V_50 ) +
( V_44 ? V_44 -> V_59 + V_44 -> V_58 : 0 ) +
( F_29 ( & V_120 -> V_6 ) ?
sizeof( struct V_144 ) : 0 ) +
V_120 -> V_261 ;
if ( F_156 ( V_2 ) )
V_263 = sizeof( struct V_50 ) + V_262 ;
else
V_263 = V_56 ;
if ( ( V_233 -> V_212 + V_212 > V_56 - V_264 ) && V_253 &&
( V_2 -> V_265 == V_266 ||
V_2 -> V_265 == V_267 ) ) {
F_157 ( V_2 , V_42 , V_56 - V_264 +
sizeof( struct V_50 ) ) ;
goto V_268;
}
if ( V_233 -> V_212 + V_212 > V_263 - V_264 ) {
V_268:
F_49 ( V_2 , V_74 , V_42 ,
V_56 - V_264 +
sizeof( struct V_50 ) ) ;
return - V_74 ;
}
}
if ( V_2 -> V_269 == V_270 || V_2 -> V_269 == V_271 ) {
F_158 ( V_2 , & V_258 ) ;
if ( V_258 & V_272 &&
V_2 -> V_273 & V_274 )
V_259 = V_2 -> V_275 ++ ;
}
if ( V_215 && V_2 -> V_265 == V_266 &&
V_212 + V_214 < V_56 &&
V_120 -> V_6 . V_8 -> V_276 & V_277 &&
! V_255 )
V_260 = V_174 ;
V_233 -> V_212 += V_212 ;
if ( ( ( V_212 > V_56 ) ||
( V_4 && F_28 ( V_4 ) ) ) &&
( V_2 -> V_265 == V_266 ) &&
( V_120 -> V_6 . V_8 -> V_276 & V_278 ) &&
( V_2 -> V_269 == V_270 ) ) {
V_152 = F_143 ( V_2 , V_210 , F_144 , V_140 , V_212 ,
V_213 , V_214 ,
V_215 , V_56 , V_19 , V_42 ) ;
if ( V_152 )
goto error;
return 0 ;
}
if ( ! V_4 )
goto V_279;
while ( V_212 > 0 ) {
V_257 = ( V_233 -> V_212 <= V_56 && ! ( V_233 -> V_19 & V_249 ) ? V_56 : V_228 ) - V_4 -> V_31 ;
if ( V_257 < V_212 )
V_257 = V_228 - V_4 -> V_31 ;
if ( V_257 <= 0 ) {
char * V_89 ;
unsigned int V_280 ;
unsigned int V_281 ;
unsigned int V_282 ;
unsigned int V_283 ;
V_279:
if ( V_4 )
V_282 = V_4 -> V_31 - V_228 ;
else
V_282 = 0 ;
if ( ! V_4 || ! V_254 )
F_151 ( & V_56 , & V_228 ,
V_214 , V_4 , V_120 ,
V_229 ) ;
V_254 = V_4 ;
V_280 = V_212 + V_282 ;
if ( V_280 > ( V_233 -> V_212 <= V_56 && ! ( V_233 -> V_19 & V_249 ) ? V_56 : V_228 ) - V_214 )
V_280 = V_228 - V_214 - V_120 -> V_6 . V_284 ;
if ( ( V_19 & V_285 ) &&
! ( V_120 -> V_6 . V_8 -> V_276 & V_286 ) )
V_283 = V_56 ;
else
V_283 = V_280 + V_214 ;
V_283 += V_256 ;
if ( V_280 != V_212 + V_282 ) {
V_280 += V_120 -> V_6 . V_284 ;
}
V_283 += V_120 -> V_6 . V_284 ;
V_281 = V_280 + V_214 ;
V_283 += sizeof( struct V_144 ) ;
if ( V_215 ) {
V_4 = F_146 ( V_2 ,
V_283 + V_213 ,
( V_19 & V_216 ) , & V_152 ) ;
} else {
V_4 = NULL ;
if ( F_159 ( & V_2 -> V_287 ) <=
2 * V_2 -> V_288 )
V_4 = F_160 ( V_2 ,
V_283 + V_213 , 1 ,
V_2 -> V_237 ) ;
if ( F_21 ( ! V_4 ) )
V_152 = - V_61 ;
}
if ( ! V_4 )
goto error;
V_4 -> V_14 = F_3 ( V_15 ) ;
V_4 -> V_170 = V_260 ;
V_4 -> V_217 = 0 ;
F_118 ( V_4 , V_213 + sizeof( struct V_144 ) +
V_256 ) ;
F_105 ( V_4 ) -> V_258 = V_258 ;
V_258 = 0 ;
F_105 ( V_4 ) -> V_259 = V_259 ;
V_259 = 0 ;
V_89 = F_119 ( V_4 , V_281 ) ;
F_161 ( V_4 , V_255 ) ;
V_89 += V_214 ;
V_4 -> V_177 = ( V_4 -> V_178 +
V_214 ) ;
if ( V_282 ) {
V_4 -> V_217 = F_162 (
V_254 , V_228 ,
V_89 + V_215 , V_282 , 0 ) ;
V_254 -> V_217 = F_163 ( V_254 -> V_217 ,
V_4 -> V_217 ) ;
V_89 += V_282 ;
F_164 ( V_254 , V_228 ) ;
}
V_257 = V_280 - V_215 - V_282 ;
if ( V_257 < 0 ) {
V_152 = - V_36 ;
F_15 ( V_4 ) ;
goto error;
} else if ( V_257 > 0 && F_144 ( V_140 , V_89 + V_215 , V_85 , V_257 , V_282 , V_4 ) < 0 ) {
V_152 = - V_289 ;
F_15 ( V_4 ) ;
goto error;
}
V_85 += V_257 ;
V_212 -= V_280 - V_282 ;
V_215 = 0 ;
V_255 = 0 ;
V_256 = 0 ;
F_147 ( V_210 , V_4 ) ;
continue;
}
if ( V_257 > V_212 )
V_257 = V_212 ;
if ( ! ( V_120 -> V_6 . V_8 -> V_276 & V_286 ) ) {
unsigned int V_290 ;
V_290 = V_4 -> V_31 ;
if ( F_144 ( V_140 , F_119 ( V_4 , V_257 ) ,
V_85 , V_257 , V_290 , V_4 ) < 0 ) {
F_165 ( V_4 , V_290 ) ;
V_152 = - V_289 ;
goto error;
}
} else {
int V_291 = F_105 ( V_4 ) -> V_292 ;
V_152 = - V_165 ;
if ( ! F_166 ( V_2 , V_252 ) )
goto error;
if ( ! F_167 ( V_4 , V_291 , V_252 -> V_293 ,
V_252 -> V_85 ) ) {
V_152 = - V_74 ;
if ( V_291 == V_294 )
goto error;
F_168 ( V_4 , V_291 , V_252 -> V_293 ,
V_252 -> V_85 , 0 ) ;
F_105 ( V_4 ) -> V_292 = ++ V_291 ;
F_169 ( V_252 -> V_293 ) ;
}
V_257 = F_170 ( int , V_257 , V_252 -> V_295 - V_252 -> V_85 ) ;
if ( F_144 ( V_140 ,
F_171 ( V_252 -> V_293 ) + V_252 -> V_85 ,
V_85 , V_257 , V_4 -> V_31 , V_4 ) < 0 )
goto V_296;
V_252 -> V_85 += V_257 ;
F_172 ( & F_105 ( V_4 ) -> V_297 [ V_291 - 1 ] , V_257 ) ;
V_4 -> V_31 += V_257 ;
V_4 -> V_169 += V_257 ;
V_4 -> V_162 += V_257 ;
F_173 ( V_257 , & V_2 -> V_287 ) ;
}
V_85 += V_257 ;
V_212 -= V_257 ;
}
return 0 ;
V_296:
V_152 = - V_289 ;
error:
V_233 -> V_212 -= V_212 ;
F_14 ( F_34 ( V_2 ) , V_120 -> V_298 , V_29 ) ;
return V_152 ;
}
int F_174 ( struct V_1 * V_2 ,
int F_144 ( void * V_140 , char * V_139 , int V_85 , int V_31 ,
int V_211 , struct V_3 * V_4 ) ,
void * V_140 , int V_212 , int V_215 , int V_55 ,
int V_45 , struct V_43 * V_44 , struct V_41 * V_42 ,
struct V_33 * V_120 , unsigned int V_19 , int V_253 )
{
struct V_299 * V_300 = F_175 ( V_2 ) ;
struct V_47 * V_48 = F_35 ( V_2 ) ;
int V_255 ;
int V_152 ;
if ( V_19 & V_301 )
return 0 ;
if ( F_176 ( & V_2 -> V_302 ) ) {
V_152 = F_152 ( V_2 , & V_300 -> V_233 , & V_48 -> V_233 , V_55 ,
V_45 , V_44 , V_120 , V_42 ) ;
if ( V_152 )
return V_152 ;
V_255 = ( V_44 ? V_44 -> V_59 : 0 ) ;
V_212 += V_255 ;
V_215 += V_255 ;
} else {
V_42 = & V_300 -> V_233 . V_242 . V_243 . V_244 ;
V_215 = 0 ;
}
return F_155 ( V_2 , V_42 , & V_2 -> V_302 , & V_300 -> V_233 . V_241 ,
& V_48 -> V_233 , F_177 ( V_2 ) , F_144 ,
V_140 , V_212 , V_215 , V_19 , V_253 ) ;
}
static void F_178 ( struct V_232 * V_233 ,
struct V_234 * V_235 )
{
if ( V_235 -> V_44 ) {
F_113 ( V_235 -> V_44 -> V_238 ) ;
F_113 ( V_235 -> V_44 -> V_239 ) ;
F_113 ( V_235 -> V_44 -> V_240 ) ;
F_113 ( V_235 -> V_44 -> V_116 ) ;
F_113 ( V_235 -> V_44 ) ;
V_235 -> V_44 = NULL ;
}
if ( V_233 -> V_241 . V_6 ) {
F_127 ( V_233 -> V_241 . V_6 ) ;
V_233 -> V_241 . V_6 = NULL ;
V_233 -> V_241 . V_19 &= ~ V_249 ;
}
memset ( & V_233 -> V_242 , 0 , sizeof( V_233 -> V_242 ) ) ;
}
struct V_3 * F_179 ( struct V_1 * V_2 ,
struct V_209 * V_210 ,
struct V_232 * V_233 ,
struct V_234 * V_235 )
{
struct V_3 * V_4 , * V_303 ;
struct V_3 * * V_304 ;
struct V_11 V_305 , * V_207 = & V_305 ;
struct V_47 * V_48 = F_35 ( V_2 ) ;
struct V_46 * V_46 = F_34 ( V_2 ) ;
struct V_50 * V_51 ;
struct V_43 * V_44 = V_235 -> V_44 ;
struct V_33 * V_120 = (struct V_33 * ) V_233 -> V_241 . V_6 ;
struct V_41 * V_42 = & V_233 -> V_242 . V_243 . V_244 ;
unsigned char V_52 = V_42 -> V_53 ;
V_4 = F_180 ( V_210 ) ;
if ( ! V_4 )
goto V_186;
V_304 = & ( F_105 ( V_4 ) -> V_163 ) ;
if ( V_4 -> V_89 < F_58 ( V_4 ) )
F_108 ( V_4 , F_181 ( V_4 ) ) ;
while ( ( V_303 = F_180 ( V_210 ) ) != NULL ) {
F_108 ( V_303 , F_182 ( V_4 ) ) ;
* V_304 = V_303 ;
V_304 = & ( V_303 -> V_81 ) ;
V_4 -> V_31 += V_303 -> V_31 ;
V_4 -> V_169 += V_303 -> V_31 ;
V_4 -> V_162 += V_303 -> V_162 ;
V_303 -> V_160 = NULL ;
V_303 -> V_2 = NULL ;
}
V_4 -> V_70 = F_156 ( V_2 ) ;
* V_207 = V_42 -> V_16 ;
F_108 ( V_4 , F_182 ( V_4 ) ) ;
if ( V_44 && V_44 -> V_59 )
F_41 ( V_4 , V_44 , & V_52 ) ;
if ( V_44 && V_44 -> V_58 )
F_42 ( V_4 , V_44 , & V_52 , & V_207 ) ;
F_43 ( V_4 , sizeof( struct V_50 ) ) ;
F_44 ( V_4 ) ;
V_51 = F_5 ( V_4 ) ;
F_46 ( V_51 , V_235 -> V_45 ,
F_47 ( V_46 , V_4 , V_42 -> V_62 ,
V_48 -> V_63 ) ) ;
V_51 -> V_28 = V_235 -> V_28 ;
V_51 -> V_65 = V_52 ;
V_51 -> V_22 = V_42 -> V_22 ;
V_51 -> V_16 = * V_207 ;
V_4 -> V_66 = V_2 -> V_67 ;
V_4 -> V_68 = V_2 -> V_69 ;
F_90 ( V_4 , F_91 ( & V_120 -> V_6 ) ) ;
F_16 ( V_46 , V_120 -> V_298 , V_71 , V_4 -> V_31 ) ;
if ( V_52 == V_86 ) {
struct V_17 * V_18 = F_6 ( F_2 ( V_4 ) ) ;
F_183 ( V_46 , V_18 , F_184 ( V_4 ) -> V_90 ) ;
F_185 ( V_46 , V_18 , V_306 ) ;
}
F_178 ( V_233 , V_235 ) ;
V_186:
return V_4 ;
}
int F_186 ( struct V_3 * V_4 )
{
struct V_46 * V_46 = F_34 ( V_4 -> V_2 ) ;
struct V_33 * V_120 = (struct V_33 * ) F_2 ( V_4 ) ;
int V_152 ;
V_152 = F_187 ( V_4 ) ;
if ( V_152 ) {
if ( V_152 > 0 )
V_152 = F_188 ( V_152 ) ;
if ( V_152 )
F_14 ( V_46 , V_120 -> V_298 ,
V_29 ) ;
}
return V_152 ;
}
int F_189 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_190 ( V_2 ) ;
if ( ! V_4 )
return 0 ;
return F_186 ( V_4 ) ;
}
static void F_191 ( struct V_1 * V_2 ,
struct V_209 * V_210 ,
struct V_232 * V_233 ,
struct V_234 * V_235 )
{
struct V_3 * V_4 ;
while ( ( V_4 = F_192 ( V_210 ) ) != NULL ) {
if ( F_2 ( V_4 ) )
F_14 ( F_34 ( V_2 ) , F_6 ( F_2 ( V_4 ) ) ,
V_29 ) ;
F_15 ( V_4 ) ;
}
F_178 ( V_233 , V_235 ) ;
}
void F_193 ( struct V_1 * V_2 )
{
F_191 ( V_2 , & V_2 -> V_302 ,
& F_175 ( V_2 ) -> V_233 , & F_35 ( V_2 ) -> V_233 ) ;
}
struct V_3 * F_194 ( struct V_1 * V_2 ,
int F_144 ( void * V_140 , char * V_139 , int V_85 ,
int V_31 , int V_211 , struct V_3 * V_4 ) ,
void * V_140 , int V_212 , int V_215 ,
int V_55 , int V_45 ,
struct V_43 * V_44 , struct V_41 * V_42 ,
struct V_33 * V_120 , unsigned int V_19 ,
int V_253 )
{
struct V_232 V_233 ;
struct V_234 V_235 ;
struct V_209 V_210 ;
int V_255 = ( V_44 ? V_44 -> V_59 : 0 ) ;
int V_152 ;
if ( V_19 & V_301 )
return NULL ;
F_195 ( & V_210 ) ;
V_233 . V_241 . V_19 = 0 ;
V_233 . V_241 . V_185 = 0 ;
V_233 . V_241 . V_44 = NULL ;
V_235 . V_44 = NULL ;
V_152 = F_152 ( V_2 , & V_233 , & V_235 , V_55 , V_45 , V_44 , V_120 , V_42 ) ;
if ( V_152 )
return F_138 ( V_152 ) ;
if ( V_253 < 0 )
V_253 = F_35 ( V_2 ) -> V_253 ;
V_152 = F_155 ( V_2 , V_42 , & V_210 , & V_233 . V_241 , & V_235 ,
& V_307 -> V_308 , F_144 , V_140 ,
V_212 + V_255 , V_215 + V_255 ,
V_19 , V_253 ) ;
if ( V_152 ) {
F_191 ( V_2 , & V_210 , & V_233 , & V_235 ) ;
return F_138 ( V_152 ) ;
}
return F_179 ( V_2 , & V_210 , & V_233 , & V_235 ) ;
}
