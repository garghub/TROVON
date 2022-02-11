static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
V_2 -> V_12 = F_3 ( V_13 ) ;
V_2 -> V_6 = V_6 ;
if ( F_4 ( & F_5 ( V_2 ) -> V_14 ) ) {
struct V_15 * V_16 = F_6 ( F_2 ( V_2 ) ) ;
if ( ! ( V_6 -> V_17 & V_18 ) && F_7 ( V_2 -> V_19 ) &&
( ( F_8 ( F_9 ( V_6 ) , V_2 ) &&
! ( F_10 ( V_2 ) -> V_17 & V_20 ) ) ||
F_11 ( V_6 , & F_5 ( V_2 ) -> V_14 ,
& F_5 ( V_2 ) -> V_21 ) ) ) {
struct V_1 * V_22 = F_12 ( V_2 , V_23 ) ;
if ( V_22 )
F_13 ( V_24 , V_25 ,
V_22 , NULL , V_22 -> V_6 ,
V_26 ) ;
if ( F_5 ( V_2 ) -> V_27 == 0 ) {
F_14 ( F_9 ( V_6 ) , V_16 ,
V_28 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
}
F_16 ( F_9 ( V_6 ) , V_16 , V_29 ,
V_2 -> V_30 ) ;
if ( F_17 ( & F_5 ( V_2 ) -> V_14 ) <=
V_31 &&
! ( V_6 -> V_17 & V_18 ) ) {
F_15 ( V_2 ) ;
return 0 ;
}
}
F_18 () ;
V_10 = F_19 ( (struct V_32 * ) V_4 ) ;
V_8 = F_20 ( V_4 -> V_6 , V_10 ) ;
if ( F_21 ( ! V_8 ) )
V_8 = F_22 ( & V_33 , V_10 , V_4 -> V_6 , false ) ;
if ( ! F_23 ( V_8 ) ) {
V_11 = F_24 ( V_4 , V_8 , V_2 ) ;
F_25 () ;
return V_11 ;
}
F_25 () ;
F_14 ( F_9 ( V_4 -> V_6 ) ,
F_6 ( V_4 ) , V_34 ) ;
F_15 ( V_2 ) ;
return - V_35 ;
}
static int F_26 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_30 > F_27 ( V_2 ) && ! F_28 ( V_2 ) ) ||
F_29 ( F_2 ( V_2 ) ) ||
( F_10 ( V_2 ) -> V_36 && V_2 -> V_30 > F_10 ( V_2 ) -> V_36 ) )
return F_30 ( V_2 , F_1 ) ;
else
return F_1 ( V_2 ) ;
}
int F_31 ( struct V_37 * V_19 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) -> V_6 ;
struct V_15 * V_16 = F_6 ( F_2 ( V_2 ) ) ;
if ( F_21 ( V_16 -> V_38 . V_39 ) ) {
F_14 ( F_9 ( V_6 ) , V_16 ,
V_28 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
return F_32 ( V_24 , V_25 , V_2 , NULL , V_6 ,
F_26 ,
! ( F_10 ( V_2 ) -> V_17 & V_40 ) ) ;
}
int F_33 ( struct V_37 * V_19 , struct V_1 * V_2 , struct V_41 * V_42 ,
struct V_43 * V_44 , int V_45 )
{
struct V_46 * V_46 = F_34 ( V_19 ) ;
struct V_47 * V_48 = F_35 ( V_19 ) ;
struct V_9 * V_49 = & V_42 -> V_14 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_50 * V_51 ;
T_1 V_52 = V_42 -> V_53 ;
int V_54 = V_2 -> V_30 ;
int V_55 = - 1 ;
T_2 V_56 ;
if ( V_44 ) {
unsigned int V_57 ;
V_57 = V_44 -> V_58 + V_44 -> V_59 ;
V_54 += V_57 ;
V_57 += sizeof( struct V_50 ) + F_36 ( V_4 -> V_6 ) ;
if ( F_37 ( V_2 ) < V_57 ) {
struct V_1 * V_60 = F_38 ( V_2 , V_57 ) ;
if ( V_60 == NULL ) {
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_28 ) ;
F_15 ( V_2 ) ;
return - V_61 ;
}
F_39 ( V_2 ) ;
V_2 = V_60 ;
F_40 ( V_2 , V_19 ) ;
}
if ( V_44 -> V_59 )
F_41 ( V_2 , V_44 , & V_52 ) ;
if ( V_44 -> V_58 )
F_42 ( V_2 , V_44 , & V_52 , & V_49 ) ;
}
F_43 ( V_2 , sizeof( struct V_50 ) ) ;
F_44 ( V_2 ) ;
V_51 = F_5 ( V_2 ) ;
if ( V_48 )
V_55 = V_48 -> V_27 ;
if ( V_55 < 0 )
V_55 = F_45 ( V_4 ) ;
F_46 ( V_51 , V_45 , F_47 ( V_46 , V_2 , V_42 -> V_62 ,
V_48 -> V_63 ) ) ;
V_51 -> V_64 = F_3 ( V_54 ) ;
V_51 -> V_65 = V_52 ;
V_51 -> V_27 = V_55 ;
V_51 -> V_21 = V_42 -> V_21 ;
V_51 -> V_14 = * V_49 ;
V_2 -> V_12 = F_3 ( V_13 ) ;
V_2 -> V_66 = V_19 -> V_67 ;
V_2 -> V_68 = V_19 -> V_69 ;
V_56 = F_48 ( V_4 ) ;
if ( ( V_2 -> V_30 <= V_56 ) || V_2 -> V_70 || F_28 ( V_2 ) ) {
F_16 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_71 , V_2 -> V_30 ) ;
return F_13 ( V_24 , V_72 , V_2 , NULL ,
V_4 -> V_6 , V_73 ) ;
}
V_2 -> V_6 = V_4 -> V_6 ;
F_49 ( V_19 , V_74 , V_42 , V_56 ) ;
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) , V_75 ) ;
F_15 ( V_2 ) ;
return - V_74 ;
}
static int F_50 ( struct V_1 * V_2 , int V_76 )
{
struct V_77 * V_78 ;
struct V_37 * V_79 = NULL ;
F_51 ( & V_80 ) ;
for ( V_78 = V_77 ; V_78 ; V_78 = V_78 -> V_81 ) {
struct V_37 * V_19 = V_78 -> V_19 ;
if ( V_19 && V_78 -> V_76 == V_76 &&
( ! V_19 -> V_82 ||
V_19 -> V_82 == V_2 -> V_6 -> V_83 ) ) {
if ( V_79 ) {
struct V_1 * V_60 = F_12 ( V_2 , V_23 ) ;
if ( V_60 )
F_52 ( V_79 , V_60 ) ;
}
V_79 = V_19 ;
}
}
if ( V_79 ) {
F_52 ( V_79 , V_2 ) ;
F_53 ( & V_80 ) ;
return 1 ;
}
F_53 ( & V_80 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_5 ( V_2 ) ;
T_1 V_65 = V_51 -> V_65 ;
T_3 V_84 ;
int V_85 ;
if ( F_55 ( V_65 ) ) {
V_85 = F_56 ( V_2 , sizeof( * V_51 ) , & V_65 , & V_84 ) ;
if ( V_85 < 0 )
return 0 ;
} else
V_85 = sizeof( struct V_50 ) ;
if ( V_65 == V_86 ) {
struct V_87 * V_88 ;
if ( ! F_57 ( V_2 , ( F_58 ( V_2 ) +
V_85 + 1 - V_2 -> V_89 ) ) )
return 0 ;
V_88 = (struct V_87 * ) ( F_58 ( V_2 ) + V_85 ) ;
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
if ( F_59 ( & V_51 -> V_14 ) & V_96 ) {
F_60 ( V_2 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_61 ( struct V_1 * V_2 )
{
F_62 ( V_2 ) ;
return V_73 ( V_2 ) ;
}
static unsigned int F_63 ( const struct V_3 * V_4 )
{
unsigned int V_56 ;
struct V_15 * V_16 ;
if ( F_64 ( V_4 , V_97 ) ) {
V_56 = F_65 ( V_4 , V_97 ) ;
if ( V_56 )
return V_56 ;
}
V_56 = V_98 ;
F_66 () ;
V_16 = F_67 ( V_4 -> V_6 ) ;
if ( V_16 )
V_56 = V_16 -> V_38 . V_99 ;
F_68 () ;
return V_56 ;
}
static bool F_69 ( const struct V_1 * V_2 , unsigned int V_56 )
{
if ( V_2 -> V_30 <= V_56 )
return false ;
if ( F_10 ( V_2 ) -> V_36 && F_10 ( V_2 ) -> V_36 > V_56 )
return true ;
if ( V_2 -> V_70 )
return false ;
if ( F_28 ( V_2 ) && F_70 ( V_2 ) <= V_56 )
return false ;
return true ;
}
int F_71 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_50 * V_51 = F_5 ( V_2 ) ;
struct V_100 * V_44 = F_10 ( V_2 ) ;
struct V_46 * V_46 = F_9 ( V_4 -> V_6 ) ;
T_2 V_56 ;
if ( V_46 -> V_101 . V_102 -> V_103 == 0 )
goto error;
if ( V_2 -> V_104 != V_105 )
goto V_106;
if ( F_72 ( V_2 ) )
goto V_106;
if ( ! F_73 ( NULL , V_107 , V_2 ) ) {
F_74 ( V_46 , F_6 ( V_4 ) ,
V_108 ) ;
goto V_106;
}
F_75 ( V_2 ) ;
if ( F_21 ( V_44 -> V_17 & V_109 ) ) {
if ( F_50 ( V_2 , F_76 ( V_44 -> V_78 ) ) )
return 0 ;
}
if ( V_51 -> V_27 <= 1 ) {
V_2 -> V_6 = V_4 -> V_6 ;
F_77 ( V_2 , V_110 , V_111 , 0 ) ;
F_74 ( V_46 , F_6 ( V_4 ) ,
V_112 ) ;
F_15 ( V_2 ) ;
return - V_113 ;
}
if ( V_46 -> V_101 . V_102 -> V_114 &&
F_78 ( & V_33 , V_46 , & V_51 -> V_14 , V_2 -> V_6 , 0 ) ) {
int V_115 = F_54 ( V_2 ) ;
if ( V_115 > 0 )
return F_79 ( V_2 ) ;
else if ( V_115 < 0 ) {
F_74 ( V_46 , F_6 ( V_4 ) ,
V_108 ) ;
goto V_106;
}
}
if ( ! F_80 ( V_2 ) ) {
F_74 ( V_46 , F_6 ( V_4 ) ,
V_108 ) ;
goto V_106;
}
V_4 = F_2 ( V_2 ) ;
if ( V_2 -> V_6 == V_4 -> V_6 && V_44 -> V_116 == 0 && ! F_81 ( V_2 ) ) {
struct V_9 * V_117 = NULL ;
struct V_118 * V_119 ;
struct V_32 * V_120 ;
V_120 = (struct V_32 * ) V_4 ;
if ( V_120 -> V_121 & V_122 )
V_117 = & V_120 -> V_123 ;
else
V_117 = & V_51 -> V_14 ;
V_119 = F_82 ( V_46 -> V_101 . V_124 , & V_120 -> V_125 . V_126 , 1 ) ;
if ( F_83 ( V_119 , 1 * V_127 ) )
F_84 ( V_2 , V_117 ) ;
if ( V_119 )
F_85 ( V_119 ) ;
} else {
int V_128 = F_59 ( & V_51 -> V_21 ) ;
if ( V_128 == V_129 ||
V_128 & ( V_130 | V_131 ) )
goto error;
if ( V_128 & V_96 ) {
F_77 ( V_2 , V_132 ,
V_133 , 0 ) ;
goto error;
}
}
V_56 = F_63 ( V_4 ) ;
if ( V_56 < V_98 )
V_56 = V_98 ;
if ( F_69 ( V_2 , V_56 ) ) {
V_2 -> V_6 = V_4 -> V_6 ;
F_77 ( V_2 , V_134 , 0 , V_56 ) ;
F_74 ( V_46 , F_6 ( V_4 ) ,
V_135 ) ;
F_74 ( V_46 , F_6 ( V_4 ) ,
V_75 ) ;
F_15 ( V_2 ) ;
return - V_74 ;
}
if ( F_86 ( V_2 , V_4 -> V_6 -> V_136 ) ) {
F_74 ( V_46 , F_6 ( V_4 ) ,
V_28 ) ;
goto V_106;
}
V_51 = F_5 ( V_2 ) ;
V_51 -> V_27 -- ;
F_74 ( V_46 , F_6 ( V_4 ) , V_137 ) ;
F_87 ( V_46 , F_6 ( V_4 ) , V_138 , V_2 -> V_30 ) ;
return F_13 ( V_24 , V_139 , V_2 , V_2 -> V_6 , V_4 -> V_6 ,
F_61 ) ;
error:
F_74 ( V_46 , F_6 ( V_4 ) , V_140 ) ;
V_106:
F_15 ( V_2 ) ;
return - V_35 ;
}
static void F_88 ( struct V_1 * V_141 , struct V_1 * V_142 )
{
V_141 -> V_104 = V_142 -> V_104 ;
V_141 -> V_66 = V_142 -> V_66 ;
V_141 -> V_12 = V_142 -> V_12 ;
F_89 ( V_141 ) ;
F_90 ( V_141 , F_91 ( F_2 ( V_142 ) ) ) ;
V_141 -> V_6 = V_142 -> V_6 ;
V_141 -> V_68 = V_142 -> V_68 ;
#ifdef F_92
V_141 -> V_143 = V_142 -> V_143 ;
#endif
F_93 ( V_141 , V_142 ) ;
F_94 ( V_141 , V_142 ) ;
}
int F_30 ( struct V_1 * V_2 , int (* F_95)( struct V_1 * ) )
{
struct V_1 * V_144 ;
struct V_32 * V_120 = (struct V_32 * ) F_2 ( V_2 ) ;
struct V_47 * V_48 = V_2 -> V_19 && ! F_96 () ?
F_35 ( V_2 -> V_19 ) : NULL ;
struct V_50 * V_145 ;
struct V_146 * V_147 ;
unsigned int V_56 , V_148 , V_149 , V_30 ;
int V_150 , V_151 ;
T_4 V_152 = 0 ;
int V_153 , V_85 = 0 , V_154 = 0 ;
T_1 * V_155 , V_65 = 0 ;
struct V_46 * V_46 = F_9 ( F_2 ( V_2 ) -> V_6 ) ;
V_148 = F_97 ( V_2 , & V_155 ) ;
V_65 = * V_155 ;
V_56 = F_27 ( V_2 ) ;
if ( F_21 ( ! V_2 -> V_70 && V_2 -> V_30 > V_56 ) ||
( F_10 ( V_2 ) -> V_36 &&
F_10 ( V_2 ) -> V_36 > V_56 ) ) {
if ( V_2 -> V_19 && F_29 ( F_2 ( V_2 ) ) )
F_98 ( V_2 -> V_19 , V_156 ) ;
V_2 -> V_6 = F_2 ( V_2 ) -> V_6 ;
F_77 ( V_2 , V_134 , 0 , V_56 ) ;
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_75 ) ;
F_15 ( V_2 ) ;
return - V_74 ;
}
if ( V_48 && V_48 -> V_157 < V_56 ) {
if ( V_48 -> V_157 )
V_56 = V_48 -> V_157 ;
}
V_56 -= V_148 + sizeof( struct V_146 ) ;
if ( F_99 ( V_2 ) ) {
int V_158 = F_100 ( V_2 ) ;
struct V_1 * V_159 ;
if ( V_158 - V_148 > V_56 ||
( ( V_158 - V_148 ) & 7 ) ||
F_101 ( V_2 ) )
goto V_160;
F_102 (skb, frag) {
if ( V_144 -> V_30 > V_56 ||
( ( V_144 -> V_30 & 7 ) && V_144 -> V_81 ) ||
F_37 ( V_144 ) < V_148 )
goto V_161;
if ( F_103 ( V_144 ) )
goto V_161;
F_104 ( V_144 -> V_19 ) ;
if ( V_2 -> V_19 ) {
V_144 -> V_19 = V_2 -> V_19 ;
V_144 -> V_162 = V_163 ;
}
V_2 -> V_164 -= V_144 -> V_164 ;
}
V_154 = 0 ;
V_85 = 0 ;
V_144 = F_105 ( V_2 ) -> V_165 ;
F_106 ( V_2 ) ;
* V_155 = V_166 ;
V_145 = F_107 ( F_58 ( V_2 ) , V_148 , V_23 ) ;
if ( ! V_145 ) {
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_75 ) ;
return - V_167 ;
}
F_108 ( V_2 , V_148 ) ;
V_147 = (struct V_146 * ) F_109 ( V_2 , sizeof( struct V_146 ) ) ;
F_109 ( V_2 , V_148 ) ;
F_44 ( V_2 ) ;
memcpy ( F_58 ( V_2 ) , V_145 , V_148 ) ;
F_110 ( V_147 , V_120 ) ;
V_147 -> V_65 = V_65 ;
V_147 -> V_168 = 0 ;
V_147 -> V_84 = F_3 ( V_169 ) ;
V_152 = V_147 -> V_170 ;
V_158 = F_100 ( V_2 ) ;
V_2 -> V_171 = V_158 - F_111 ( V_2 ) ;
V_2 -> V_30 = V_158 ;
F_5 ( V_2 ) -> V_64 = F_3 ( V_158 -
sizeof( struct V_50 ) ) ;
F_112 ( & V_120 -> V_4 ) ;
for (; ; ) {
if ( V_144 ) {
V_144 -> V_172 = V_173 ;
F_113 ( V_144 ) ;
V_147 = (struct V_146 * ) F_109 ( V_144 , sizeof( struct V_146 ) ) ;
F_109 ( V_144 , V_148 ) ;
F_44 ( V_144 ) ;
memcpy ( F_58 ( V_144 ) , V_145 ,
V_148 ) ;
V_85 += V_2 -> V_30 - V_148 - sizeof( struct V_146 ) ;
V_147 -> V_65 = V_65 ;
V_147 -> V_168 = 0 ;
V_147 -> V_84 = F_3 ( V_85 ) ;
if ( V_144 -> V_81 != NULL )
V_147 -> V_84 |= F_3 ( V_169 ) ;
V_147 -> V_170 = V_152 ;
F_5 ( V_144 ) -> V_64 =
F_3 ( V_144 -> V_30 -
sizeof( struct V_50 ) ) ;
F_88 ( V_144 , V_2 ) ;
}
V_154 = F_95 ( V_2 ) ;
if ( ! V_154 )
F_14 ( V_46 , F_6 ( & V_120 -> V_4 ) ,
V_174 ) ;
if ( V_154 || ! V_144 )
break;
V_2 = V_144 ;
V_144 = V_2 -> V_81 ;
V_2 -> V_81 = NULL ;
}
F_114 ( V_145 ) ;
if ( V_154 == 0 ) {
F_14 ( V_46 , F_6 ( & V_120 -> V_4 ) ,
V_175 ) ;
F_115 ( V_120 ) ;
return 0 ;
}
F_116 ( V_144 ) ;
F_14 ( V_46 , F_6 ( & V_120 -> V_4 ) ,
V_75 ) ;
F_115 ( V_120 ) ;
return V_154 ;
V_161:
F_102 (skb, frag2) {
if ( V_159 == V_144 )
break;
V_159 -> V_19 = NULL ;
V_159 -> V_162 = NULL ;
V_2 -> V_164 += V_159 -> V_164 ;
}
}
V_160:
if ( ( V_2 -> V_172 == V_176 ) &&
F_117 ( V_2 ) )
goto V_177;
V_149 = V_2 -> V_30 - V_148 ;
V_153 = V_148 ;
* V_155 = V_166 ;
V_150 = F_36 ( V_120 -> V_4 . V_6 ) ;
V_151 = V_120 -> V_4 . V_6 -> V_178 ;
while ( V_149 > 0 ) {
V_30 = V_149 ;
if ( V_30 > V_56 )
V_30 = V_56 ;
if ( V_30 < V_149 ) {
V_30 &= ~ 7 ;
}
V_144 = F_118 ( V_30 + V_148 + sizeof( struct V_146 ) +
V_150 + V_151 , V_23 ) ;
if ( ! V_144 ) {
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_75 ) ;
V_154 = - V_167 ;
goto V_177;
}
F_88 ( V_144 , V_2 ) ;
F_119 ( V_144 , V_150 ) ;
F_120 ( V_144 , V_30 + V_148 + sizeof( struct V_146 ) ) ;
F_44 ( V_144 ) ;
V_147 = (struct V_146 * ) ( F_58 ( V_144 ) + V_148 ) ;
V_144 -> V_179 = ( V_144 -> V_180 + V_148 +
sizeof( struct V_146 ) ) ;
if ( V_2 -> V_19 )
F_40 ( V_144 , V_2 -> V_19 ) ;
F_121 ( V_2 , F_58 ( V_144 ) , V_148 ) ;
V_147 -> V_65 = V_65 ;
V_147 -> V_168 = 0 ;
if ( ! V_152 ) {
F_110 ( V_147 , V_120 ) ;
V_152 = V_147 -> V_170 ;
} else
V_147 -> V_170 = V_152 ;
F_104 ( F_122 ( V_2 , V_153 , F_123 ( V_144 ) ,
V_30 ) ) ;
V_149 -= V_30 ;
V_147 -> V_84 = F_3 ( V_85 ) ;
if ( V_149 > 0 )
V_147 -> V_84 |= F_3 ( V_169 ) ;
F_5 ( V_144 ) -> V_64 = F_3 ( V_144 -> V_30 -
sizeof( struct V_50 ) ) ;
V_153 += V_30 ;
V_85 += V_30 ;
V_154 = F_95 ( V_144 ) ;
if ( V_154 )
goto V_177;
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_174 ) ;
}
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_175 ) ;
F_39 ( V_2 ) ;
return V_154 ;
V_177:
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_75 ) ;
F_15 ( V_2 ) ;
return V_154 ;
}
static inline int F_124 ( const struct V_181 * V_182 ,
const struct V_9 * V_183 ,
const struct V_9 * V_184 )
{
return ( V_182 -> V_185 != 128 || ! F_125 ( V_183 , & V_182 -> V_126 ) ) &&
( V_184 == NULL || ! F_125 ( V_183 , V_184 ) ) ;
}
static struct V_3 * F_126 ( struct V_37 * V_19 ,
struct V_3 * V_4 ,
const struct V_41 * V_42 )
{
struct V_47 * V_48 = F_35 ( V_19 ) ;
struct V_32 * V_120 ;
if ( ! V_4 )
goto V_186;
if ( V_4 -> V_187 -> V_188 != V_189 ) {
F_127 ( V_4 ) ;
return NULL ;
}
V_120 = (struct V_32 * ) V_4 ;
if ( F_124 ( & V_120 -> V_125 , & V_42 -> V_14 , V_48 -> V_190 ) ||
#ifdef F_128
F_124 ( & V_120 -> V_191 , & V_42 -> V_21 , V_48 -> V_192 ) ||
#endif
( V_42 -> V_193 && V_42 -> V_193 != V_4 -> V_6 -> V_83 ) ) {
F_127 ( V_4 ) ;
V_4 = NULL ;
}
V_186:
return V_4 ;
}
static int F_129 ( struct V_37 * V_19 ,
struct V_3 * * V_4 , struct V_41 * V_42 )
{
struct V_46 * V_46 = F_34 ( V_19 ) ;
#ifdef F_130
struct V_7 * V_194 ;
struct V_32 * V_120 ;
#endif
int V_154 ;
if ( * V_4 == NULL )
* V_4 = F_131 ( V_46 , V_19 , V_42 ) ;
V_154 = ( * V_4 ) -> error ;
if ( V_154 )
goto V_195;
if ( F_132 ( & V_42 -> V_21 ) ) {
struct V_32 * V_120 = (struct V_32 * ) * V_4 ;
V_154 = F_133 ( V_46 , V_120 , & V_42 -> V_14 ,
V_19 ? F_35 ( V_19 ) -> V_196 : 0 ,
& V_42 -> V_21 ) ;
if ( V_154 )
goto V_195;
}
#ifdef F_130
V_120 = (struct V_32 * ) * V_4 ;
F_18 () ;
V_194 = F_20 ( V_120 -> V_4 . V_6 , F_19 ( V_120 ) ) ;
V_154 = V_194 && ! ( V_194 -> V_197 & V_198 ) ? - V_35 : 0 ;
F_25 () ;
if ( V_154 ) {
struct V_199 * V_200 ;
struct V_41 V_201 ;
int V_202 ;
V_200 = F_134 ( V_46 , & V_42 -> V_21 ,
( * V_4 ) -> V_6 , 1 ) ;
V_202 = ( V_200 && V_200 -> V_17 & V_203 ) ;
if ( V_200 )
F_135 ( V_200 ) ;
if ( V_202 ) {
F_127 ( * V_4 ) ;
memcpy ( & V_201 , V_42 , sizeof( struct V_41 ) ) ;
memset ( & V_201 . V_14 , 0 , sizeof( struct V_9 ) ) ;
* V_4 = F_131 ( V_46 , V_19 , & V_201 ) ;
V_154 = ( * V_4 ) -> error ;
if ( V_154 )
goto V_195;
}
}
#endif
return 0 ;
V_195:
if ( V_154 == - V_204 )
F_14 ( V_46 , NULL , V_34 ) ;
F_127 ( * V_4 ) ;
* V_4 = NULL ;
return V_154 ;
}
int F_136 ( struct V_37 * V_19 , struct V_3 * * V_4 , struct V_41 * V_42 )
{
* V_4 = NULL ;
return F_129 ( V_19 , V_4 , V_42 ) ;
}
struct V_3 * F_137 ( struct V_37 * V_19 , struct V_41 * V_42 ,
const struct V_9 * V_205 )
{
struct V_3 * V_4 = NULL ;
int V_154 ;
V_154 = F_129 ( V_19 , & V_4 , V_42 ) ;
if ( V_154 )
return F_138 ( V_154 ) ;
if ( V_205 )
V_42 -> V_14 = * V_205 ;
return F_139 ( F_34 ( V_19 ) , V_4 , F_140 ( V_42 ) , V_19 , 0 ) ;
}
struct V_3 * F_141 ( struct V_37 * V_19 , struct V_41 * V_42 ,
const struct V_9 * V_205 )
{
struct V_3 * V_4 = F_142 ( V_19 , F_35 ( V_19 ) -> V_206 ) ;
int V_154 ;
V_4 = F_126 ( V_19 , V_4 , V_42 ) ;
V_154 = F_129 ( V_19 , & V_4 , V_42 ) ;
if ( V_154 )
return F_138 ( V_154 ) ;
if ( V_205 )
V_42 -> V_14 = * V_205 ;
return F_139 ( F_34 ( V_19 ) , V_4 , F_140 ( V_42 ) , V_19 , 0 ) ;
}
static inline int F_143 ( struct V_37 * V_19 ,
struct V_207 * V_208 ,
int F_144 ( void * V_142 , char * V_141 , int V_85 , int V_30 ,
int V_209 , struct V_1 * V_2 ) ,
void * V_142 , int V_210 , int V_211 , int V_212 ,
int V_213 , int V_56 , unsigned int V_17 ,
struct V_32 * V_120 )
{
struct V_1 * V_2 ;
struct V_146 V_214 ;
int V_154 ;
V_2 = F_145 ( V_208 ) ;
if ( V_2 == NULL ) {
V_2 = F_146 ( V_19 ,
V_211 + V_212 + V_213 + 20 ,
( V_17 & V_215 ) , & V_154 ) ;
if ( V_2 == NULL )
return V_154 ;
F_119 ( V_2 , V_211 ) ;
F_120 ( V_2 , V_212 + V_213 ) ;
F_44 ( V_2 ) ;
V_2 -> V_179 = V_2 -> V_180 + V_212 ;
V_2 -> V_12 = F_3 ( V_13 ) ;
V_2 -> V_216 = 0 ;
F_147 ( V_208 , V_2 ) ;
} else if ( F_28 ( V_2 ) ) {
goto V_217;
}
V_2 -> V_172 = V_176 ;
F_105 ( V_2 ) -> V_218 = ( V_56 - V_212 -
sizeof( struct V_146 ) ) & ~ 7 ;
F_105 ( V_2 ) -> V_219 = V_220 ;
F_110 ( & V_214 , V_120 ) ;
F_105 ( V_2 ) -> V_221 = V_214 . V_170 ;
V_217:
return F_148 ( V_19 , V_2 , F_144 , V_142 ,
( V_210 - V_213 ) ) ;
}
static inline struct V_222 * F_149 ( struct V_222 * V_223 ,
T_5 V_224 )
{
return V_223 ? F_107 ( V_223 , ( V_223 -> V_225 + 1 ) * 8 , V_224 ) : NULL ;
}
static inline struct V_226 * F_150 ( struct V_226 * V_223 ,
T_5 V_224 )
{
return V_223 ? F_107 ( V_223 , ( V_223 -> V_225 + 1 ) * 8 , V_224 ) : NULL ;
}
static void F_151 ( unsigned int * V_56 ,
int * V_227 ,
unsigned int V_212 ,
struct V_1 * V_2 ,
struct V_32 * V_120 ,
unsigned int V_228 )
{
if ( ! ( V_120 -> V_4 . V_17 & V_229 ) ) {
if ( V_2 == NULL ) {
* V_56 = V_228 - V_120 -> V_4 . V_230 ;
} else {
* V_56 = V_228 ;
}
* V_227 = ( ( * V_56 - V_212 ) & ~ 7 )
+ V_212 - sizeof( struct V_146 ) ;
}
}
static int F_152 ( struct V_37 * V_19 , struct V_231 * V_232 ,
struct V_233 * V_234 ,
int V_55 , int V_45 , struct V_43 * V_44 ,
struct V_32 * V_120 , struct V_41 * V_42 )
{
struct V_47 * V_48 = F_35 ( V_19 ) ;
unsigned int V_56 ;
if ( V_44 ) {
if ( F_153 ( V_234 -> V_44 ) )
return - V_35 ;
V_234 -> V_44 = F_154 ( V_44 -> V_235 , V_19 -> V_236 ) ;
if ( F_21 ( V_234 -> V_44 == NULL ) )
return - V_61 ;
V_234 -> V_44 -> V_235 = V_44 -> V_235 ;
V_234 -> V_44 -> V_59 = V_44 -> V_59 ;
V_234 -> V_44 -> V_58 = V_44 -> V_58 ;
V_234 -> V_44 -> V_237 = F_149 ( V_44 -> V_237 ,
V_19 -> V_236 ) ;
if ( V_44 -> V_237 && ! V_234 -> V_44 -> V_237 )
return - V_61 ;
V_234 -> V_44 -> V_238 = F_149 ( V_44 -> V_238 ,
V_19 -> V_236 ) ;
if ( V_44 -> V_238 && ! V_234 -> V_44 -> V_238 )
return - V_61 ;
V_234 -> V_44 -> V_239 = F_149 ( V_44 -> V_239 ,
V_19 -> V_236 ) ;
if ( V_44 -> V_239 && ! V_234 -> V_44 -> V_239 )
return - V_61 ;
V_234 -> V_44 -> V_116 = F_150 ( V_44 -> V_116 ,
V_19 -> V_236 ) ;
if ( V_44 -> V_116 && ! V_234 -> V_44 -> V_116 )
return - V_61 ;
}
F_112 ( & V_120 -> V_4 ) ;
V_232 -> V_240 . V_4 = & V_120 -> V_4 ;
V_232 -> V_241 . V_242 . V_243 = * V_42 ;
V_234 -> V_27 = V_55 ;
V_234 -> V_45 = V_45 ;
if ( V_120 -> V_4 . V_17 & V_229 )
V_56 = V_48 -> V_244 >= V_245 ?
V_120 -> V_4 . V_6 -> V_56 : F_48 ( & V_120 -> V_4 ) ;
else
V_56 = V_48 -> V_244 >= V_245 ?
V_120 -> V_4 . V_6 -> V_56 : F_48 ( V_120 -> V_4 . V_246 ) ;
if ( V_48 -> V_157 < V_56 ) {
if ( V_48 -> V_157 )
V_56 = V_48 -> V_157 ;
}
V_232 -> V_240 . V_247 = V_56 ;
if ( F_29 ( V_120 -> V_4 . V_246 ) )
V_232 -> V_240 . V_17 |= V_248 ;
V_232 -> V_240 . V_210 = 0 ;
return 0 ;
}
static int F_155 ( struct V_37 * V_19 ,
struct V_41 * V_42 ,
struct V_207 * V_208 ,
struct V_249 * V_232 ,
struct V_233 * V_234 ,
struct V_250 * V_251 ,
int F_144 ( void * V_142 , char * V_141 , int V_85 ,
int V_30 , int V_209 , struct V_1 * V_2 ) ,
void * V_142 , int V_210 , int V_213 ,
unsigned int V_17 , int V_252 )
{
struct V_1 * V_2 , * V_253 = NULL ;
unsigned int V_227 , V_212 , V_56 , V_228 ;
int V_254 = 0 ;
int V_255 = 0 ;
int V_211 ;
int V_256 ;
int V_154 ;
int V_85 = 0 ;
T_6 V_257 = 0 ;
T_2 V_258 = 0 ;
struct V_32 * V_120 = (struct V_32 * ) V_232 -> V_4 ;
struct V_43 * V_44 = V_234 -> V_44 ;
int V_259 = V_173 ;
V_2 = F_145 ( V_208 ) ;
if ( ! V_2 ) {
V_254 = V_44 ? V_44 -> V_59 : 0 ;
V_255 = V_120 -> V_4 . V_230 - V_120 -> V_260 ;
}
V_56 = V_232 -> V_247 ;
V_228 = V_56 ;
V_211 = F_36 ( V_120 -> V_4 . V_6 ) ;
V_212 = sizeof( struct V_50 ) + V_120 -> V_260 +
( V_44 ? V_44 -> V_58 : 0 ) ;
V_227 = ( ( V_56 - V_212 ) & ~ 7 ) + V_212 -
sizeof( struct V_146 ) ;
if ( V_56 <= sizeof( struct V_50 ) + V_261 ) {
unsigned int V_262 , V_263 ;
V_263 = sizeof( struct V_50 ) +
( V_44 ? V_44 -> V_59 + V_44 -> V_58 : 0 ) +
( F_29 ( & V_120 -> V_4 ) ?
sizeof( struct V_146 ) : 0 ) +
V_120 -> V_260 ;
if ( F_156 ( V_19 ) )
V_262 = sizeof( struct V_50 ) + V_261 ;
else
V_262 = V_56 ;
if ( ( V_232 -> V_210 + V_210 > V_56 - V_263 ) && V_252 &&
( V_19 -> V_264 == V_265 ||
V_19 -> V_264 == V_266 ) ) {
F_157 ( V_19 , V_42 , V_56 - V_263 +
sizeof( struct V_50 ) ) ;
goto V_267;
}
if ( V_232 -> V_210 + V_210 > V_262 - V_263 ) {
V_267:
F_49 ( V_19 , V_74 , V_42 ,
V_56 - V_263 +
sizeof( struct V_50 ) ) ;
return - V_74 ;
}
}
if ( V_19 -> V_268 == V_269 || V_19 -> V_268 == V_270 ) {
F_158 ( V_19 , & V_257 ) ;
if ( V_257 & V_271 &&
V_19 -> V_272 & V_273 )
V_258 = V_19 -> V_274 ++ ;
}
if ( ! V_2 && V_19 -> V_264 == V_265 &&
V_210 + V_212 < V_56 &&
V_120 -> V_4 . V_6 -> V_275 & V_276 &&
! V_254 )
V_259 = V_176 ;
V_232 -> V_210 += V_210 ;
if ( ( ( V_210 > V_56 ) ||
( V_2 && F_28 ( V_2 ) ) ) &&
( V_19 -> V_264 == V_265 ) &&
( V_120 -> V_4 . V_6 -> V_275 & V_277 ) &&
( V_19 -> V_268 == V_269 ) ) {
V_154 = F_143 ( V_19 , V_208 , F_144 , V_142 , V_210 ,
V_211 , V_212 ,
V_213 , V_56 , V_17 , V_120 ) ;
if ( V_154 )
goto error;
return 0 ;
}
if ( ! V_2 )
goto V_278;
while ( V_210 > 0 ) {
V_256 = ( V_232 -> V_210 <= V_56 && ! ( V_232 -> V_17 & V_248 ) ? V_56 : V_227 ) - V_2 -> V_30 ;
if ( V_256 < V_210 )
V_256 = V_227 - V_2 -> V_30 ;
if ( V_256 <= 0 ) {
char * V_89 ;
unsigned int V_279 ;
unsigned int V_280 ;
unsigned int V_281 ;
unsigned int V_282 ;
V_278:
if ( V_2 )
V_281 = V_2 -> V_30 - V_227 ;
else
V_281 = 0 ;
if ( V_2 == NULL || V_253 == NULL )
F_151 ( & V_56 , & V_227 ,
V_212 , V_2 , V_120 ,
V_228 ) ;
V_253 = V_2 ;
V_279 = V_210 + V_281 ;
if ( V_279 > ( V_232 -> V_210 <= V_56 && ! ( V_232 -> V_17 & V_248 ) ? V_56 : V_227 ) - V_212 )
V_279 = V_227 - V_212 - V_120 -> V_4 . V_283 ;
if ( ( V_17 & V_284 ) &&
! ( V_120 -> V_4 . V_6 -> V_275 & V_285 ) )
V_282 = V_56 ;
else
V_282 = V_279 + V_212 ;
V_282 += V_255 ;
if ( V_279 != V_210 + V_281 ) {
V_279 += V_120 -> V_4 . V_283 ;
}
V_282 += V_120 -> V_4 . V_283 ;
V_280 = V_279 + V_212 ;
V_282 += sizeof( struct V_146 ) ;
if ( V_213 ) {
V_2 = F_146 ( V_19 ,
V_282 + V_211 ,
( V_17 & V_215 ) , & V_154 ) ;
} else {
V_2 = NULL ;
if ( F_159 ( & V_19 -> V_286 ) <=
2 * V_19 -> V_287 )
V_2 = F_160 ( V_19 ,
V_282 + V_211 , 1 ,
V_19 -> V_236 ) ;
if ( F_21 ( V_2 == NULL ) )
V_154 = - V_61 ;
}
if ( V_2 == NULL )
goto error;
V_2 -> V_12 = F_3 ( V_13 ) ;
V_2 -> V_172 = V_259 ;
V_2 -> V_216 = 0 ;
F_119 ( V_2 , V_211 + sizeof( struct V_146 ) +
V_255 ) ;
F_105 ( V_2 ) -> V_257 = V_257 ;
V_257 = 0 ;
F_105 ( V_2 ) -> V_258 = V_258 ;
V_258 = 0 ;
V_89 = F_120 ( V_2 , V_280 ) ;
F_161 ( V_2 , V_254 ) ;
V_89 += V_212 ;
V_2 -> V_179 = ( V_2 -> V_180 +
V_212 ) ;
if ( V_281 ) {
V_2 -> V_216 = F_162 (
V_253 , V_227 ,
V_89 + V_213 , V_281 , 0 ) ;
V_253 -> V_216 = F_163 ( V_253 -> V_216 ,
V_2 -> V_216 ) ;
V_89 += V_281 ;
F_164 ( V_253 , V_227 ) ;
}
V_256 = V_279 - V_213 - V_281 ;
if ( V_256 < 0 ) {
V_154 = - V_35 ;
F_15 ( V_2 ) ;
goto error;
} else if ( V_256 > 0 && F_144 ( V_142 , V_89 + V_213 , V_85 , V_256 , V_281 , V_2 ) < 0 ) {
V_154 = - V_288 ;
F_15 ( V_2 ) ;
goto error;
}
V_85 += V_256 ;
V_210 -= V_279 - V_281 ;
V_213 = 0 ;
V_254 = 0 ;
V_255 = 0 ;
F_147 ( V_208 , V_2 ) ;
continue;
}
if ( V_256 > V_210 )
V_256 = V_210 ;
if ( ! ( V_120 -> V_4 . V_6 -> V_275 & V_285 ) ) {
unsigned int V_289 ;
V_289 = V_2 -> V_30 ;
if ( F_144 ( V_142 , F_120 ( V_2 , V_256 ) ,
V_85 , V_256 , V_289 , V_2 ) < 0 ) {
F_165 ( V_2 , V_289 ) ;
V_154 = - V_288 ;
goto error;
}
} else {
int V_290 = F_105 ( V_2 ) -> V_291 ;
V_154 = - V_167 ;
if ( ! F_166 ( V_19 , V_251 ) )
goto error;
if ( ! F_167 ( V_2 , V_290 , V_251 -> V_292 ,
V_251 -> V_85 ) ) {
V_154 = - V_74 ;
if ( V_290 == V_293 )
goto error;
F_168 ( V_2 , V_290 , V_251 -> V_292 ,
V_251 -> V_85 , 0 ) ;
F_105 ( V_2 ) -> V_291 = ++ V_290 ;
F_169 ( V_251 -> V_292 ) ;
}
V_256 = F_170 ( int , V_256 , V_251 -> V_294 - V_251 -> V_85 ) ;
if ( F_144 ( V_142 ,
F_171 ( V_251 -> V_292 ) + V_251 -> V_85 ,
V_85 , V_256 , V_2 -> V_30 , V_2 ) < 0 )
goto V_295;
V_251 -> V_85 += V_256 ;
F_172 ( & F_105 ( V_2 ) -> V_296 [ V_290 - 1 ] , V_256 ) ;
V_2 -> V_30 += V_256 ;
V_2 -> V_171 += V_256 ;
V_2 -> V_164 += V_256 ;
F_173 ( V_256 , & V_19 -> V_286 ) ;
}
V_85 += V_256 ;
V_210 -= V_256 ;
}
return 0 ;
V_295:
V_154 = - V_288 ;
error:
V_232 -> V_210 -= V_210 ;
F_14 ( F_34 ( V_19 ) , V_120 -> V_297 , V_28 ) ;
return V_154 ;
}
int F_174 ( struct V_37 * V_19 ,
int F_144 ( void * V_142 , char * V_141 , int V_85 , int V_30 ,
int V_209 , struct V_1 * V_2 ) ,
void * V_142 , int V_210 , int V_213 , int V_55 ,
int V_45 , struct V_43 * V_44 , struct V_41 * V_42 ,
struct V_32 * V_120 , unsigned int V_17 , int V_252 )
{
struct V_298 * V_299 = F_175 ( V_19 ) ;
struct V_47 * V_48 = F_35 ( V_19 ) ;
int V_254 ;
int V_154 ;
if ( V_17 & V_300 )
return 0 ;
if ( F_176 ( & V_19 -> V_301 ) ) {
V_154 = F_152 ( V_19 , & V_299 -> V_232 , & V_48 -> V_232 , V_55 ,
V_45 , V_44 , V_120 , V_42 ) ;
if ( V_154 )
return V_154 ;
V_254 = ( V_44 ? V_44 -> V_59 : 0 ) ;
V_210 += V_254 ;
V_213 += V_254 ;
} else {
V_42 = & V_299 -> V_232 . V_241 . V_242 . V_243 ;
V_213 = 0 ;
}
return F_155 ( V_19 , V_42 , & V_19 -> V_301 , & V_299 -> V_232 . V_240 ,
& V_48 -> V_232 , F_177 ( V_19 ) , F_144 ,
V_142 , V_210 , V_213 , V_17 , V_252 ) ;
}
static void F_178 ( struct V_231 * V_232 ,
struct V_233 * V_234 )
{
if ( V_234 -> V_44 ) {
F_114 ( V_234 -> V_44 -> V_237 ) ;
F_114 ( V_234 -> V_44 -> V_238 ) ;
F_114 ( V_234 -> V_44 -> V_239 ) ;
F_114 ( V_234 -> V_44 -> V_116 ) ;
F_114 ( V_234 -> V_44 ) ;
V_234 -> V_44 = NULL ;
}
if ( V_232 -> V_240 . V_4 ) {
F_127 ( V_232 -> V_240 . V_4 ) ;
V_232 -> V_240 . V_4 = NULL ;
V_232 -> V_240 . V_17 &= ~ V_248 ;
}
memset ( & V_232 -> V_241 , 0 , sizeof( V_232 -> V_241 ) ) ;
}
struct V_1 * F_179 ( struct V_37 * V_19 ,
struct V_207 * V_208 ,
struct V_231 * V_232 ,
struct V_233 * V_234 )
{
struct V_1 * V_2 , * V_302 ;
struct V_1 * * V_303 ;
struct V_9 V_304 , * V_205 = & V_304 ;
struct V_47 * V_48 = F_35 ( V_19 ) ;
struct V_46 * V_46 = F_34 ( V_19 ) ;
struct V_50 * V_51 ;
struct V_43 * V_44 = V_234 -> V_44 ;
struct V_32 * V_120 = (struct V_32 * ) V_232 -> V_240 . V_4 ;
struct V_41 * V_42 = & V_232 -> V_241 . V_242 . V_243 ;
unsigned char V_52 = V_42 -> V_53 ;
V_2 = F_180 ( V_208 ) ;
if ( V_2 == NULL )
goto V_186;
V_303 = & ( F_105 ( V_2 ) -> V_165 ) ;
if ( V_2 -> V_89 < F_58 ( V_2 ) )
F_108 ( V_2 , F_181 ( V_2 ) ) ;
while ( ( V_302 = F_180 ( V_208 ) ) != NULL ) {
F_108 ( V_302 , F_182 ( V_2 ) ) ;
* V_303 = V_302 ;
V_303 = & ( V_302 -> V_81 ) ;
V_2 -> V_30 += V_302 -> V_30 ;
V_2 -> V_171 += V_302 -> V_30 ;
V_2 -> V_164 += V_302 -> V_164 ;
V_302 -> V_162 = NULL ;
V_302 -> V_19 = NULL ;
}
V_2 -> V_70 = F_156 ( V_19 ) ;
* V_205 = V_42 -> V_14 ;
F_108 ( V_2 , F_182 ( V_2 ) ) ;
if ( V_44 && V_44 -> V_59 )
F_41 ( V_2 , V_44 , & V_52 ) ;
if ( V_44 && V_44 -> V_58 )
F_42 ( V_2 , V_44 , & V_52 , & V_205 ) ;
F_43 ( V_2 , sizeof( struct V_50 ) ) ;
F_44 ( V_2 ) ;
V_51 = F_5 ( V_2 ) ;
F_46 ( V_51 , V_234 -> V_45 ,
F_47 ( V_46 , V_2 , V_42 -> V_62 ,
V_48 -> V_63 ) ) ;
V_51 -> V_27 = V_234 -> V_27 ;
V_51 -> V_65 = V_52 ;
V_51 -> V_21 = V_42 -> V_21 ;
V_51 -> V_14 = * V_205 ;
V_2 -> V_66 = V_19 -> V_67 ;
V_2 -> V_68 = V_19 -> V_69 ;
F_90 ( V_2 , F_91 ( & V_120 -> V_4 ) ) ;
F_16 ( V_46 , V_120 -> V_297 , V_71 , V_2 -> V_30 ) ;
if ( V_52 == V_86 ) {
struct V_15 * V_16 = F_6 ( F_2 ( V_2 ) ) ;
F_183 ( V_46 , V_16 , F_184 ( V_2 ) -> V_90 ) ;
F_185 ( V_46 , V_16 , V_305 ) ;
}
F_178 ( V_232 , V_234 ) ;
V_186:
return V_2 ;
}
int F_186 ( struct V_1 * V_2 )
{
struct V_46 * V_46 = F_34 ( V_2 -> V_19 ) ;
struct V_32 * V_120 = (struct V_32 * ) F_2 ( V_2 ) ;
int V_154 ;
V_154 = F_187 ( V_2 ) ;
if ( V_154 ) {
if ( V_154 > 0 )
V_154 = F_188 ( V_154 ) ;
if ( V_154 )
F_14 ( V_46 , V_120 -> V_297 ,
V_28 ) ;
}
return V_154 ;
}
int F_189 ( struct V_37 * V_19 )
{
struct V_1 * V_2 ;
V_2 = F_190 ( V_19 ) ;
if ( ! V_2 )
return 0 ;
return F_186 ( V_2 ) ;
}
static void F_191 ( struct V_37 * V_19 ,
struct V_207 * V_208 ,
struct V_231 * V_232 ,
struct V_233 * V_234 )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_192 ( V_208 ) ) != NULL ) {
if ( F_2 ( V_2 ) )
F_14 ( F_34 ( V_19 ) , F_6 ( F_2 ( V_2 ) ) ,
V_28 ) ;
F_15 ( V_2 ) ;
}
F_178 ( V_232 , V_234 ) ;
}
void F_193 ( struct V_37 * V_19 )
{
F_191 ( V_19 , & V_19 -> V_301 ,
& F_175 ( V_19 ) -> V_232 , & F_35 ( V_19 ) -> V_232 ) ;
}
struct V_1 * F_194 ( struct V_37 * V_19 ,
int F_144 ( void * V_142 , char * V_141 , int V_85 ,
int V_30 , int V_209 , struct V_1 * V_2 ) ,
void * V_142 , int V_210 , int V_213 ,
int V_55 , int V_45 ,
struct V_43 * V_44 , struct V_41 * V_42 ,
struct V_32 * V_120 , unsigned int V_17 ,
int V_252 )
{
struct V_231 V_232 ;
struct V_233 V_234 ;
struct V_207 V_208 ;
int V_254 = ( V_44 ? V_44 -> V_59 : 0 ) ;
int V_154 ;
if ( V_17 & V_300 )
return NULL ;
F_195 ( & V_208 ) ;
V_232 . V_240 . V_17 = 0 ;
V_232 . V_240 . V_126 = 0 ;
V_232 . V_240 . V_44 = NULL ;
V_234 . V_44 = NULL ;
V_154 = F_152 ( V_19 , & V_232 , & V_234 , V_55 , V_45 , V_44 , V_120 , V_42 ) ;
if ( V_154 )
return F_138 ( V_154 ) ;
if ( V_252 < 0 )
V_252 = F_35 ( V_19 ) -> V_252 ;
V_154 = F_155 ( V_19 , V_42 , & V_208 , & V_232 . V_240 , & V_234 ,
& V_306 -> V_307 , F_144 , V_142 ,
V_210 + V_254 , V_213 + V_254 ,
V_17 , V_252 ) ;
if ( V_154 ) {
F_191 ( V_19 , & V_208 , & V_232 , & V_234 ) ;
return F_138 ( V_154 ) ;
}
return F_179 ( V_19 , & V_208 , & V_232 , & V_234 ) ;
}
