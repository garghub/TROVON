static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
int V_14 ;
if ( F_3 ( & F_4 ( V_5 ) -> V_15 ) ) {
struct V_16 * V_17 = F_5 ( F_2 ( V_5 ) ) ;
if ( ! ( V_9 -> V_18 & V_19 ) && F_6 ( V_3 ) &&
( ( F_7 ( V_1 , V_5 ) &&
! ( F_8 ( V_5 ) -> V_18 & V_20 ) ) ||
F_9 ( V_9 , & F_4 ( V_5 ) -> V_15 ,
& F_4 ( V_5 ) -> V_21 ) ) ) {
struct V_4 * V_22 = F_10 ( V_5 , V_23 ) ;
if ( V_22 )
F_11 ( V_24 , V_25 ,
V_1 , V_3 , V_22 , NULL , V_22 -> V_9 ,
V_26 ) ;
if ( F_4 ( V_5 ) -> V_27 == 0 ) {
F_12 ( V_1 , V_17 ,
V_28 ) ;
F_13 ( V_5 ) ;
return 0 ;
}
}
F_14 ( V_1 , V_17 , V_29 , V_5 -> V_30 ) ;
if ( F_15 ( & F_4 ( V_5 ) -> V_15 ) <=
V_31 &&
! ( V_9 -> V_18 & V_19 ) ) {
F_13 ( V_5 ) ;
return 0 ;
}
}
if ( F_16 ( V_7 -> V_32 ) ) {
int V_33 = F_17 ( V_5 ) ;
if ( V_33 < 0 || V_33 == V_34 )
return V_33 ;
}
F_18 () ;
V_13 = F_19 ( (struct V_35 * ) V_7 , & F_4 ( V_5 ) -> V_15 ) ;
V_11 = F_20 ( V_7 -> V_9 , V_13 ) ;
if ( F_21 ( ! V_11 ) )
V_11 = F_22 ( & V_36 , V_13 , V_7 -> V_9 , false ) ;
if ( ! F_23 ( V_11 ) ) {
F_24 ( V_5 , V_11 ) ;
V_14 = F_25 ( V_11 , V_5 ) ;
F_26 () ;
return V_14 ;
}
F_26 () ;
F_12 ( V_1 , F_5 ( V_7 ) , V_37 ) ;
F_13 ( V_5 ) ;
return - V_38 ;
}
static int F_27 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_14 ;
V_14 = F_28 ( V_3 , V_5 ) ;
if ( V_14 ) {
F_13 ( V_5 ) ;
return V_14 ;
}
if ( ( V_5 -> V_30 > F_29 ( V_5 ) && ! F_30 ( V_5 ) ) ||
F_31 ( F_2 ( V_5 ) ) ||
( F_8 ( V_5 ) -> V_39 && V_5 -> V_30 > F_8 ( V_5 ) -> V_39 ) )
return F_32 ( V_1 , V_3 , V_5 , F_1 ) ;
else
return F_1 ( V_1 , V_3 , V_5 ) ;
}
int F_33 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_8 * V_9 = F_2 ( V_5 ) -> V_9 ;
struct V_16 * V_17 = F_5 ( F_2 ( V_5 ) ) ;
V_5 -> V_40 = F_34 ( V_41 ) ;
V_5 -> V_9 = V_9 ;
if ( F_21 ( V_17 -> V_42 . V_43 ) ) {
F_12 ( V_1 , V_17 , V_28 ) ;
F_13 ( V_5 ) ;
return 0 ;
}
return F_35 ( V_24 , V_25 ,
V_1 , V_3 , V_5 , NULL , V_9 ,
F_27 ,
! ( F_8 ( V_5 ) -> V_18 & V_44 ) ) ;
}
int F_36 ( const struct V_2 * V_3 , struct V_4 * V_5 , struct V_45 * V_46 ,
T_1 V_47 , struct V_48 * V_49 , int V_50 )
{
struct V_1 * V_1 = F_37 ( V_3 ) ;
const struct V_51 * V_52 = F_38 ( V_3 ) ;
struct V_12 * V_53 = & V_46 -> V_15 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_54 * V_55 ;
T_2 V_56 = V_46 -> V_57 ;
int V_58 = V_5 -> V_30 ;
int V_59 = - 1 ;
T_3 V_60 ;
if ( V_49 ) {
unsigned int V_61 ;
V_61 = V_49 -> V_62 + V_49 -> V_63 ;
V_58 += V_61 ;
V_61 += sizeof( struct V_54 ) + F_39 ( V_7 -> V_9 ) ;
if ( F_40 ( V_5 ) < V_61 ) {
struct V_4 * V_64 = F_41 ( V_5 , V_61 ) ;
if ( ! V_64 ) {
F_12 ( V_1 , F_5 ( F_2 ( V_5 ) ) ,
V_28 ) ;
F_13 ( V_5 ) ;
return - V_65 ;
}
F_42 ( V_5 ) ;
V_5 = V_64 ;
F_43 ( V_5 , (struct V_2 * ) V_3 ) ;
}
if ( V_49 -> V_63 )
F_44 ( V_5 , V_49 , & V_56 ) ;
if ( V_49 -> V_62 )
F_45 ( V_5 , V_49 , & V_56 , & V_53 ,
& V_46 -> V_21 ) ;
}
F_46 ( V_5 , sizeof( struct V_54 ) ) ;
F_47 ( V_5 ) ;
V_55 = F_4 ( V_5 ) ;
if ( V_52 )
V_59 = V_52 -> V_27 ;
if ( V_59 < 0 )
V_59 = F_48 ( V_7 ) ;
F_49 ( V_55 , V_50 , F_50 ( V_1 , V_5 , V_46 -> V_66 ,
V_52 -> V_67 , V_46 ) ) ;
V_55 -> V_68 = F_34 ( V_58 ) ;
V_55 -> V_69 = V_56 ;
V_55 -> V_27 = V_59 ;
V_55 -> V_21 = V_46 -> V_21 ;
V_55 -> V_15 = * V_53 ;
V_5 -> V_40 = F_34 ( V_41 ) ;
V_5 -> V_70 = V_3 -> V_71 ;
V_5 -> V_47 = V_47 ;
V_60 = F_51 ( V_7 ) ;
if ( ( V_5 -> V_30 <= V_60 ) || V_5 -> V_72 || F_30 ( V_5 ) ) {
F_14 ( V_1 , F_5 ( F_2 ( V_5 ) ) ,
V_73 , V_5 -> V_30 ) ;
V_5 = F_52 ( (struct V_2 * ) V_3 , V_5 ) ;
if ( F_21 ( ! V_5 ) )
return 0 ;
return F_11 ( V_24 , V_74 ,
V_1 , (struct V_2 * ) V_3 , V_5 , NULL , V_7 -> V_9 ,
V_75 ) ;
}
V_5 -> V_9 = V_7 -> V_9 ;
F_53 ( (struct V_2 * ) V_3 , V_76 , V_46 , V_60 ) ;
F_12 ( V_1 , F_5 ( F_2 ( V_5 ) ) , V_77 ) ;
F_13 ( V_5 ) ;
return - V_76 ;
}
static int F_54 ( struct V_4 * V_5 , int V_78 )
{
struct V_79 * V_80 ;
struct V_2 * V_81 = NULL ;
F_55 ( & V_82 ) ;
for ( V_80 = V_79 ; V_80 ; V_80 = V_80 -> V_83 ) {
struct V_2 * V_3 = V_80 -> V_3 ;
if ( V_3 && V_80 -> V_78 == V_78 &&
( ! V_3 -> V_84 ||
V_3 -> V_84 == V_5 -> V_9 -> V_85 ) ) {
if ( V_81 ) {
struct V_4 * V_64 = F_10 ( V_5 , V_23 ) ;
if ( V_64 )
F_56 ( V_81 , V_64 ) ;
}
V_81 = V_3 ;
}
}
if ( V_81 ) {
F_56 ( V_81 , V_5 ) ;
F_57 ( & V_82 ) ;
return 1 ;
}
F_57 ( & V_82 ) ;
return 0 ;
}
static int F_58 ( struct V_4 * V_5 )
{
struct V_54 * V_55 = F_4 ( V_5 ) ;
T_2 V_69 = V_55 -> V_69 ;
T_4 V_86 ;
int V_87 ;
if ( F_59 ( V_69 ) ) {
V_87 = F_60 ( V_5 , sizeof( * V_55 ) , & V_69 , & V_86 ) ;
if ( V_87 < 0 )
return 0 ;
} else
V_87 = sizeof( struct V_54 ) ;
if ( V_69 == V_88 ) {
struct V_89 * V_90 ;
if ( ! F_61 ( V_5 , ( F_62 ( V_5 ) +
V_87 + 1 - V_5 -> V_91 ) ) )
return 0 ;
V_90 = (struct V_89 * ) ( F_62 ( V_5 ) + V_87 ) ;
switch ( V_90 -> V_92 ) {
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
return 1 ;
default:
break;
}
}
if ( F_63 ( & V_55 -> V_15 ) & V_98 ) {
F_64 ( V_5 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_65 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
return V_75 ( V_1 , V_3 , V_5 ) ;
}
static unsigned int F_66 ( const struct V_6 * V_7 )
{
unsigned int V_60 ;
struct V_16 * V_17 ;
if ( F_67 ( V_7 , V_99 ) ) {
V_60 = F_68 ( V_7 , V_99 ) ;
if ( V_60 )
return V_60 ;
}
V_60 = V_100 ;
F_69 () ;
V_17 = F_70 ( V_7 -> V_9 ) ;
if ( V_17 )
V_60 = V_17 -> V_42 . V_101 ;
F_71 () ;
return V_60 ;
}
static bool F_72 ( const struct V_4 * V_5 , unsigned int V_60 )
{
if ( V_5 -> V_30 <= V_60 )
return false ;
if ( F_8 ( V_5 ) -> V_39 && F_8 ( V_5 ) -> V_39 > V_60 )
return true ;
if ( V_5 -> V_72 )
return false ;
if ( F_30 ( V_5 ) && F_73 ( V_5 , V_60 ) )
return false ;
return true ;
}
int F_74 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_54 * V_55 = F_4 ( V_5 ) ;
struct V_102 * V_49 = F_8 ( V_5 ) ;
struct V_1 * V_1 = F_75 ( V_7 -> V_9 ) ;
T_3 V_60 ;
if ( V_1 -> V_103 . V_104 -> V_105 == 0 )
goto error;
if ( V_5 -> V_106 != V_107 )
goto V_108;
if ( F_21 ( V_5 -> V_3 ) )
goto V_108;
if ( F_76 ( V_5 ) )
goto V_108;
if ( ! F_77 ( NULL , V_109 , V_5 ) ) {
F_78 ( V_1 , F_5 ( V_7 ) ,
V_110 ) ;
goto V_108;
}
F_79 ( V_5 ) ;
if ( F_21 ( V_49 -> V_18 & V_111 ) ) {
if ( F_54 ( V_5 , F_80 ( V_49 -> V_80 ) ) )
return 0 ;
}
if ( V_55 -> V_27 <= 1 ) {
V_5 -> V_9 = V_7 -> V_9 ;
F_81 ( V_5 , V_112 , V_113 , 0 ) ;
F_78 ( V_1 , F_5 ( V_7 ) ,
V_114 ) ;
F_13 ( V_5 ) ;
return - V_115 ;
}
if ( V_1 -> V_103 . V_104 -> V_116 &&
F_82 ( & V_36 , V_1 , & V_55 -> V_15 , V_5 -> V_9 , 0 ) ) {
int V_117 = F_58 ( V_5 ) ;
if ( V_117 > 0 )
return F_83 ( V_5 ) ;
else if ( V_117 < 0 ) {
F_78 ( V_1 , F_5 ( V_7 ) ,
V_110 ) ;
goto V_108;
}
}
if ( ! F_84 ( V_5 ) ) {
F_78 ( V_1 , F_5 ( V_7 ) ,
V_110 ) ;
goto V_108;
}
V_7 = F_2 ( V_5 ) ;
if ( V_5 -> V_9 == V_7 -> V_9 && V_49 -> V_118 == 0 && ! F_85 ( V_5 ) ) {
struct V_12 * V_119 = NULL ;
struct V_120 * V_121 ;
struct V_35 * V_122 ;
V_122 = (struct V_35 * ) V_7 ;
if ( V_122 -> V_123 & V_124 )
V_119 = & V_122 -> V_125 ;
else
V_119 = & V_55 -> V_15 ;
V_121 = F_86 ( V_1 -> V_103 . V_126 , & V_55 -> V_15 , 1 ) ;
if ( F_87 ( V_121 , 1 * V_127 ) )
F_88 ( V_5 , V_119 ) ;
if ( V_121 )
F_89 ( V_121 ) ;
} else {
int V_128 = F_63 ( & V_55 -> V_21 ) ;
if ( V_128 == V_129 ||
V_128 & ( V_130 | V_131 ) )
goto error;
if ( V_128 & V_98 ) {
F_81 ( V_5 , V_132 ,
V_133 , 0 ) ;
goto error;
}
}
V_60 = F_66 ( V_7 ) ;
if ( V_60 < V_100 )
V_60 = V_100 ;
if ( F_72 ( V_5 , V_60 ) ) {
V_5 -> V_9 = V_7 -> V_9 ;
F_81 ( V_5 , V_134 , 0 , V_60 ) ;
F_78 ( V_1 , F_5 ( V_7 ) ,
V_135 ) ;
F_78 ( V_1 , F_5 ( V_7 ) ,
V_77 ) ;
F_13 ( V_5 ) ;
return - V_76 ;
}
if ( F_90 ( V_5 , V_7 -> V_9 -> V_136 ) ) {
F_78 ( V_1 , F_5 ( V_7 ) ,
V_28 ) ;
goto V_108;
}
V_55 = F_4 ( V_5 ) ;
V_55 -> V_27 -- ;
F_78 ( V_1 , F_5 ( V_7 ) , V_137 ) ;
F_91 ( V_1 , F_5 ( V_7 ) , V_138 , V_5 -> V_30 ) ;
return F_11 ( V_24 , V_139 ,
V_1 , NULL , V_5 , V_5 -> V_9 , V_7 -> V_9 ,
F_65 ) ;
error:
F_78 ( V_1 , F_5 ( V_7 ) , V_140 ) ;
V_108:
F_13 ( V_5 ) ;
return - V_38 ;
}
static void F_92 ( struct V_4 * V_141 , struct V_4 * V_142 )
{
V_141 -> V_106 = V_142 -> V_106 ;
V_141 -> V_70 = V_142 -> V_70 ;
V_141 -> V_40 = V_142 -> V_40 ;
F_93 ( V_141 ) ;
F_94 ( V_141 , F_95 ( F_2 ( V_142 ) ) ) ;
V_141 -> V_9 = V_142 -> V_9 ;
V_141 -> V_47 = V_142 -> V_47 ;
#ifdef F_96
V_141 -> V_143 = V_142 -> V_143 ;
#endif
F_97 ( V_141 , V_142 ) ;
F_98 ( V_141 , V_142 ) ;
}
int F_32 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 ,
int (* F_99)( struct V_1 * , struct V_2 * , struct V_4 * ) )
{
struct V_4 * V_144 ;
struct V_35 * V_122 = (struct V_35 * ) F_2 ( V_5 ) ;
struct V_51 * V_52 = V_5 -> V_3 && ! F_100 () ?
F_38 ( V_5 -> V_3 ) : NULL ;
struct V_54 * V_145 ;
struct V_146 * V_147 ;
unsigned int V_60 , V_148 , V_149 , V_30 ;
int V_150 , V_151 ;
T_5 V_152 ;
int V_153 , V_87 = 0 , V_154 = 0 ;
T_2 * V_155 , V_69 = 0 ;
V_154 = F_101 ( V_5 , & V_155 ) ;
if ( V_154 < 0 )
goto V_156;
V_148 = V_154 ;
V_69 = * V_155 ;
V_60 = F_29 ( V_5 ) ;
if ( F_21 ( ! V_5 -> V_72 && V_5 -> V_30 > V_60 ) )
goto V_157;
if ( F_8 ( V_5 ) -> V_39 ) {
if ( F_8 ( V_5 ) -> V_39 > V_60 )
goto V_157;
V_60 = F_8 ( V_5 ) -> V_39 ;
if ( V_60 < V_100 )
V_60 = V_100 ;
}
if ( V_52 && V_52 -> V_158 < V_60 ) {
if ( V_52 -> V_158 )
V_60 = V_52 -> V_158 ;
}
if ( V_60 < V_148 + sizeof( struct V_146 ) + 8 )
goto V_157;
V_60 -= V_148 + sizeof( struct V_146 ) ;
V_152 = F_102 ( V_1 , & F_4 ( V_5 ) -> V_15 ,
& F_4 ( V_5 ) -> V_21 ) ;
if ( V_5 -> V_159 == V_160 &&
( V_154 = F_103 ( V_5 ) ) )
goto V_156;
V_150 = F_39 ( V_122 -> V_7 . V_9 ) ;
if ( F_104 ( V_5 ) ) {
unsigned int V_161 = F_105 ( V_5 ) ;
struct V_4 * V_162 ;
if ( V_161 - V_148 > V_60 ||
( ( V_161 - V_148 ) & 7 ) ||
F_106 ( V_5 ) ||
F_40 ( V_5 ) < ( V_150 + sizeof( struct V_146 ) ) )
goto V_163;
F_107 (skb, frag) {
if ( V_144 -> V_30 > V_60 ||
( ( V_144 -> V_30 & 7 ) && V_144 -> V_83 ) ||
F_40 ( V_144 ) < ( V_148 + V_150 + sizeof( struct V_146 ) ) )
goto V_164;
if ( F_108 ( V_144 ) )
goto V_164;
F_109 ( V_144 -> V_3 ) ;
if ( V_5 -> V_3 ) {
V_144 -> V_3 = V_5 -> V_3 ;
V_144 -> V_165 = V_166 ;
}
V_5 -> V_167 -= V_144 -> V_167 ;
}
V_154 = 0 ;
V_87 = 0 ;
* V_155 = V_168 ;
V_145 = F_110 ( F_62 ( V_5 ) , V_148 , V_23 ) ;
if ( ! V_145 ) {
V_154 = - V_169 ;
goto V_156;
}
V_144 = F_111 ( V_5 ) -> V_170 ;
F_112 ( V_5 ) ;
F_113 ( V_5 , V_148 ) ;
V_147 = F_114 ( V_5 , sizeof( struct V_146 ) ) ;
F_114 ( V_5 , V_148 ) ;
F_47 ( V_5 ) ;
memcpy ( F_62 ( V_5 ) , V_145 , V_148 ) ;
V_147 -> V_69 = V_69 ;
V_147 -> V_171 = 0 ;
V_147 -> V_86 = F_34 ( V_172 ) ;
V_147 -> V_173 = V_152 ;
V_161 = F_105 ( V_5 ) ;
V_5 -> V_174 = V_161 - F_115 ( V_5 ) ;
V_5 -> V_30 = V_161 ;
F_4 ( V_5 ) -> V_68 = F_34 ( V_161 -
sizeof( struct V_54 ) ) ;
for (; ; ) {
if ( V_144 ) {
V_144 -> V_159 = V_175 ;
F_116 ( V_144 ) ;
V_147 = F_114 ( V_144 , sizeof( struct V_146 ) ) ;
F_114 ( V_144 , V_148 ) ;
F_47 ( V_144 ) ;
memcpy ( F_62 ( V_144 ) , V_145 ,
V_148 ) ;
V_87 += V_5 -> V_30 - V_148 - sizeof( struct V_146 ) ;
V_147 -> V_69 = V_69 ;
V_147 -> V_171 = 0 ;
V_147 -> V_86 = F_34 ( V_87 ) ;
if ( V_144 -> V_83 )
V_147 -> V_86 |= F_34 ( V_172 ) ;
V_147 -> V_173 = V_152 ;
F_4 ( V_144 ) -> V_68 =
F_34 ( V_144 -> V_30 -
sizeof( struct V_54 ) ) ;
F_92 ( V_144 , V_5 ) ;
}
V_154 = F_99 ( V_1 , V_3 , V_5 ) ;
if ( ! V_154 )
F_12 ( V_1 , F_5 ( & V_122 -> V_7 ) ,
V_176 ) ;
if ( V_154 || ! V_144 )
break;
V_5 = V_144 ;
V_144 = V_5 -> V_83 ;
V_5 -> V_83 = NULL ;
}
F_117 ( V_145 ) ;
if ( V_154 == 0 ) {
F_12 ( V_1 , F_5 ( & V_122 -> V_7 ) ,
V_177 ) ;
return 0 ;
}
F_118 ( V_144 ) ;
F_12 ( V_1 , F_5 ( & V_122 -> V_7 ) ,
V_77 ) ;
return V_154 ;
V_164:
F_107 (skb, frag2) {
if ( V_162 == V_144 )
break;
V_162 -> V_3 = NULL ;
V_162 -> V_165 = NULL ;
V_5 -> V_167 += V_162 -> V_167 ;
}
}
V_163:
V_149 = V_5 -> V_30 - V_148 ;
V_153 = V_148 ;
V_151 = V_122 -> V_7 . V_9 -> V_178 ;
while ( V_149 > 0 ) {
T_2 * V_179 ;
V_30 = V_149 ;
if ( V_30 > V_60 )
V_30 = V_60 ;
if ( V_30 < V_149 ) {
V_30 &= ~ 7 ;
}
V_144 = F_119 ( V_30 + V_148 + sizeof( struct V_146 ) +
V_150 + V_151 , V_23 ) ;
if ( ! V_144 ) {
V_154 = - V_169 ;
goto V_156;
}
F_92 ( V_144 , V_5 ) ;
F_120 ( V_144 , V_150 ) ;
F_121 ( V_144 , V_30 + V_148 + sizeof( struct V_146 ) ) ;
F_47 ( V_144 ) ;
V_147 = (struct V_146 * ) ( F_62 ( V_144 ) + V_148 ) ;
V_144 -> V_180 = ( V_144 -> V_181 + V_148 +
sizeof( struct V_146 ) ) ;
if ( V_5 -> V_3 )
F_43 ( V_144 , V_5 -> V_3 ) ;
F_122 ( V_5 , F_62 ( V_144 ) , V_148 ) ;
V_179 = F_62 ( V_144 ) ;
V_179 += V_155 - F_62 ( V_5 ) ;
* V_179 = V_168 ;
V_147 -> V_69 = V_69 ;
V_147 -> V_171 = 0 ;
V_147 -> V_173 = V_152 ;
F_109 ( F_123 ( V_5 , V_153 , F_124 ( V_144 ) ,
V_30 ) ) ;
V_149 -= V_30 ;
V_147 -> V_86 = F_34 ( V_87 ) ;
if ( V_149 > 0 )
V_147 -> V_86 |= F_34 ( V_172 ) ;
F_4 ( V_144 ) -> V_68 = F_34 ( V_144 -> V_30 -
sizeof( struct V_54 ) ) ;
V_153 += V_30 ;
V_87 += V_30 ;
V_154 = F_99 ( V_1 , V_3 , V_144 ) ;
if ( V_154 )
goto V_156;
F_12 ( V_1 , F_5 ( F_2 ( V_5 ) ) ,
V_176 ) ;
}
F_12 ( V_1 , F_5 ( F_2 ( V_5 ) ) ,
V_177 ) ;
F_42 ( V_5 ) ;
return V_154 ;
V_157:
if ( V_5 -> V_3 && F_31 ( F_2 ( V_5 ) ) )
F_125 ( V_5 -> V_3 , V_182 ) ;
F_81 ( V_5 , V_134 , 0 , V_60 ) ;
V_154 = - V_76 ;
V_156:
F_12 ( V_1 , F_5 ( F_2 ( V_5 ) ) ,
V_77 ) ;
F_13 ( V_5 ) ;
return V_154 ;
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
struct V_51 * V_52 = F_38 ( V_3 ) ;
struct V_35 * V_122 ;
if ( ! V_7 )
goto V_189;
if ( V_7 -> V_190 -> V_191 != V_192 ) {
F_129 ( V_7 ) ;
return NULL ;
}
V_122 = (struct V_35 * ) V_7 ;
if ( F_126 ( & V_122 -> V_193 , & V_46 -> V_15 , V_52 -> V_194 ) ||
#ifdef F_130
F_126 ( & V_122 -> V_195 , & V_46 -> V_21 , V_52 -> V_196 ) ||
#endif
( ! ( V_46 -> V_197 & V_198 ) &&
( V_46 -> V_199 && V_46 -> V_199 != V_7 -> V_9 -> V_85 ) ) ) {
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
struct V_35 * V_122 ;
#endif
int V_154 ;
int V_18 = 0 ;
if ( F_133 ( & V_46 -> V_21 ) && ( ! * V_7 || ! ( * V_7 ) -> error ) ) {
struct V_35 * V_122 ;
bool V_201 = * V_7 != NULL ;
if ( ! V_201 )
* V_7 = F_134 ( V_1 , V_3 , V_46 ) ;
V_122 = ( * V_7 ) -> error ? NULL : (struct V_35 * ) * V_7 ;
V_154 = F_135 ( V_1 , V_122 , & V_46 -> V_15 ,
V_3 ? F_38 ( V_3 ) -> V_202 : 0 ,
& V_46 -> V_21 ) ;
if ( V_154 )
goto V_203;
if ( ! V_201 && ( * V_7 ) -> error ) {
F_129 ( * V_7 ) ;
* V_7 = NULL ;
}
if ( V_46 -> V_199 )
V_18 |= V_204 ;
}
if ( ! * V_7 )
* V_7 = F_136 ( V_1 , V_3 , V_46 , V_18 ) ;
V_154 = ( * V_7 ) -> error ;
if ( V_154 )
goto V_203;
#ifdef F_132
V_122 = (struct V_35 * ) * V_7 ;
F_18 () ;
V_200 = F_20 ( V_122 -> V_7 . V_9 ,
F_19 ( V_122 , & V_46 -> V_15 ) ) ;
V_154 = V_200 && ! ( V_200 -> V_205 & V_206 ) ? - V_38 : 0 ;
F_26 () ;
if ( V_154 ) {
struct V_207 * V_208 ;
struct V_45 V_209 ;
int V_210 ;
V_208 = F_137 ( V_1 , & V_46 -> V_21 ,
( * V_7 ) -> V_9 , 1 ) ;
V_210 = ( V_208 && V_208 -> V_18 & V_211 ) ;
if ( V_208 )
F_138 ( V_208 ) ;
if ( V_210 ) {
F_129 ( * V_7 ) ;
memcpy ( & V_209 , V_46 , sizeof( struct V_45 ) ) ;
memset ( & V_209 . V_15 , 0 , sizeof( struct V_12 ) ) ;
* V_7 = F_134 ( V_1 , V_3 , & V_209 ) ;
V_154 = ( * V_7 ) -> error ;
if ( V_154 )
goto V_203;
}
}
#endif
if ( F_139 ( & V_46 -> V_21 ) &&
! ( F_139 ( & V_46 -> V_15 ) || F_133 ( & V_46 -> V_15 ) ) ) {
V_154 = - V_212 ;
goto V_203;
}
return 0 ;
V_203:
F_129 ( * V_7 ) ;
* V_7 = NULL ;
if ( V_154 == - V_213 )
F_12 ( V_1 , NULL , V_37 ) ;
return V_154 ;
}
int F_140 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_6 * * V_7 ,
struct V_45 * V_46 )
{
* V_7 = NULL ;
return F_131 ( V_1 , V_3 , V_7 , V_46 ) ;
}
struct V_6 * F_141 ( const struct V_2 * V_3 , struct V_45 * V_46 ,
const struct V_12 * V_214 )
{
struct V_6 * V_7 = NULL ;
int V_154 ;
V_154 = F_131 ( F_37 ( V_3 ) , V_3 , & V_7 , V_46 ) ;
if ( V_154 )
return F_142 ( V_154 ) ;
if ( V_214 )
V_46 -> V_15 = * V_214 ;
return F_143 ( F_37 ( V_3 ) , V_7 , F_144 ( V_46 ) , V_3 , 0 ) ;
}
struct V_6 * F_145 ( struct V_2 * V_3 , struct V_45 * V_46 ,
const struct V_12 * V_214 )
{
struct V_6 * V_7 = F_146 ( V_3 , F_38 ( V_3 ) -> V_215 ) ;
V_7 = F_128 ( V_3 , V_7 , V_46 ) ;
if ( ! V_7 )
V_7 = F_141 ( V_3 , V_46 , V_214 ) ;
return V_7 ;
}
static inline int F_147 ( struct V_2 * V_3 ,
struct V_216 * V_217 ,
int F_148 ( void * V_142 , char * V_141 , int V_87 , int V_30 ,
int V_218 , struct V_4 * V_5 ) ,
void * V_142 , int V_219 , int V_220 , int V_221 ,
int V_222 , int V_223 , int V_60 ,
unsigned int V_18 , const struct V_45 * V_46 )
{
struct V_4 * V_5 ;
int V_154 ;
V_5 = F_149 ( V_217 ) ;
if ( ! V_5 ) {
V_5 = F_150 ( V_3 ,
V_220 + V_221 + V_223 + 20 ,
( V_18 & V_224 ) , & V_154 ) ;
if ( ! V_5 )
return V_154 ;
F_120 ( V_5 , V_220 ) ;
F_121 ( V_5 , V_221 + V_223 ) ;
F_151 ( V_5 , V_222 ) ;
V_5 -> V_180 = V_5 -> V_181 + V_221 ;
V_5 -> V_40 = F_34 ( V_41 ) ;
V_5 -> V_225 = 0 ;
if ( V_18 & V_226 )
F_152 ( V_5 , 1 ) ;
F_153 ( V_217 , V_5 ) ;
} else if ( F_30 ( V_5 ) ) {
goto V_227;
}
V_5 -> V_159 = V_160 ;
F_111 ( V_5 ) -> V_228 = ( V_60 - V_221 -
sizeof( struct V_146 ) ) & ~ 7 ;
F_111 ( V_5 ) -> V_229 = V_230 ;
F_111 ( V_5 ) -> V_231 = F_102 ( F_37 ( V_3 ) ,
& V_46 -> V_15 ,
& V_46 -> V_21 ) ;
V_227:
return F_154 ( V_3 , V_5 , F_148 , V_142 ,
( V_219 - V_223 ) ) ;
}
static inline struct V_232 * F_155 ( struct V_232 * V_233 ,
T_6 V_234 )
{
return V_233 ? F_110 ( V_233 , ( V_233 -> V_235 + 1 ) * 8 , V_234 ) : NULL ;
}
static inline struct V_236 * F_156 ( struct V_236 * V_233 ,
T_6 V_234 )
{
return V_233 ? F_110 ( V_233 , ( V_233 -> V_235 + 1 ) * 8 , V_234 ) : NULL ;
}
static void F_157 ( unsigned int * V_60 ,
int * V_237 ,
unsigned int V_221 ,
struct V_4 * V_5 ,
struct V_35 * V_122 ,
unsigned int V_238 )
{
if ( ! ( V_122 -> V_7 . V_18 & V_239 ) ) {
if ( ! V_5 ) {
* V_60 = V_238 - V_122 -> V_7 . V_240 ;
} else {
* V_60 = V_238 ;
}
* V_237 = ( ( * V_60 - V_221 ) & ~ 7 )
+ V_221 - sizeof( struct V_146 ) ;
}
}
static int F_158 ( struct V_2 * V_3 , struct V_241 * V_242 ,
struct V_243 * V_244 , struct V_245 * V_246 ,
struct V_35 * V_122 , struct V_45 * V_46 )
{
struct V_51 * V_52 = F_38 ( V_3 ) ;
unsigned int V_60 ;
struct V_48 * V_49 = V_246 -> V_49 ;
if ( V_49 ) {
if ( F_159 ( V_244 -> V_49 ) )
return - V_38 ;
V_244 -> V_49 = F_160 ( V_49 -> V_247 , V_3 -> V_248 ) ;
if ( F_21 ( ! V_244 -> V_49 ) )
return - V_65 ;
V_244 -> V_49 -> V_247 = V_49 -> V_247 ;
V_244 -> V_49 -> V_63 = V_49 -> V_63 ;
V_244 -> V_49 -> V_62 = V_49 -> V_62 ;
V_244 -> V_49 -> V_249 = F_155 ( V_49 -> V_249 ,
V_3 -> V_248 ) ;
if ( V_49 -> V_249 && ! V_244 -> V_49 -> V_249 )
return - V_65 ;
V_244 -> V_49 -> V_250 = F_155 ( V_49 -> V_250 ,
V_3 -> V_248 ) ;
if ( V_49 -> V_250 && ! V_244 -> V_49 -> V_250 )
return - V_65 ;
V_244 -> V_49 -> V_251 = F_155 ( V_49 -> V_251 ,
V_3 -> V_248 ) ;
if ( V_49 -> V_251 && ! V_244 -> V_49 -> V_251 )
return - V_65 ;
V_244 -> V_49 -> V_118 = F_156 ( V_49 -> V_118 ,
V_3 -> V_248 ) ;
if ( V_49 -> V_118 && ! V_244 -> V_49 -> V_118 )
return - V_65 ;
}
F_161 ( & V_122 -> V_7 ) ;
V_242 -> V_252 . V_7 = & V_122 -> V_7 ;
V_242 -> V_253 . V_254 . V_255 = * V_46 ;
V_244 -> V_27 = V_246 -> V_59 ;
V_244 -> V_50 = V_246 -> V_50 ;
if ( V_122 -> V_7 . V_18 & V_239 )
V_60 = V_52 -> V_256 >= V_257 ?
V_122 -> V_7 . V_9 -> V_60 : F_51 ( & V_122 -> V_7 ) ;
else
V_60 = V_52 -> V_256 >= V_257 ?
V_122 -> V_7 . V_9 -> V_60 : F_51 ( V_122 -> V_7 . V_258 ) ;
if ( V_52 -> V_158 < V_60 ) {
if ( V_52 -> V_158 )
V_60 = V_52 -> V_158 ;
}
V_242 -> V_252 . V_259 = V_60 ;
if ( F_31 ( V_122 -> V_7 . V_258 ) )
V_242 -> V_252 . V_18 |= V_260 ;
V_242 -> V_252 . V_219 = 0 ;
return 0 ;
}
static int F_162 ( struct V_2 * V_3 ,
struct V_45 * V_46 ,
struct V_216 * V_217 ,
struct V_261 * V_242 ,
struct V_243 * V_244 ,
struct V_262 * V_263 ,
int F_148 ( void * V_142 , char * V_141 , int V_87 ,
int V_30 , int V_218 , struct V_4 * V_5 ) ,
void * V_142 , int V_219 , int V_223 ,
unsigned int V_18 , struct V_245 * V_246 ,
const struct V_264 * V_265 )
{
struct V_4 * V_5 , * V_266 = NULL ;
unsigned int V_237 , V_221 , V_60 , V_238 ;
int V_222 = 0 ;
int V_267 = 0 ;
int V_220 ;
int V_268 ;
int V_154 ;
int V_87 = 0 ;
T_7 V_269 = 0 ;
T_3 V_270 = 0 ;
struct V_35 * V_122 = (struct V_35 * ) V_242 -> V_7 ;
struct V_48 * V_49 = V_244 -> V_49 ;
int V_271 = V_175 ;
unsigned int V_272 , V_273 ;
V_5 = F_149 ( V_217 ) ;
if ( ! V_5 ) {
V_222 = V_49 ? V_49 -> V_63 : 0 ;
V_267 = V_122 -> V_7 . V_240 - V_122 -> V_274 ;
}
V_60 = V_242 -> V_259 ;
V_238 = V_60 ;
V_220 = F_39 ( V_122 -> V_7 . V_9 ) ;
V_221 = sizeof( struct V_54 ) + V_122 -> V_274 +
( V_49 ? V_49 -> V_62 : 0 ) ;
V_237 = ( ( V_60 - V_221 ) & ~ 7 ) + V_221 -
sizeof( struct V_146 ) ;
V_273 = sizeof( struct V_54 ) +
( V_49 ? V_49 -> V_63 + V_49 -> V_62 : 0 ) +
( F_31 ( & V_122 -> V_7 ) ?
sizeof( struct V_146 ) : 0 ) +
V_122 -> V_274 ;
if ( V_242 -> V_219 + V_219 > V_60 - V_273 && V_246 -> V_275 &&
( V_3 -> V_276 == V_277 ||
V_3 -> V_276 == V_278 ) ) {
F_163 ( V_3 , V_46 , V_60 - V_273 +
sizeof( struct V_54 ) ) ;
goto V_279;
}
if ( F_164 ( V_3 ) )
V_272 = sizeof( struct V_54 ) + V_280 ;
else
V_272 = V_60 ;
if ( V_242 -> V_219 + V_219 > V_272 - V_273 ) {
V_279:
F_53 ( V_3 , V_76 , V_46 ,
V_60 - V_273 +
sizeof( struct V_54 ) ) ;
return - V_76 ;
}
if ( V_223 && V_3 -> V_276 == V_277 &&
V_273 == sizeof( struct V_54 ) &&
V_219 <= V_60 - V_273 &&
! ( V_18 & V_281 ) &&
V_122 -> V_7 . V_9 -> V_282 & ( V_283 | V_284 ) )
V_271 = V_160 ;
if ( V_3 -> V_285 == V_286 || V_3 -> V_285 == V_287 ) {
F_165 ( V_3 , V_265 -> V_288 , & V_269 ) ;
if ( V_269 & V_289 &&
V_3 -> V_290 & V_291 )
V_270 = V_3 -> V_292 ++ ;
}
V_242 -> V_219 += V_219 ;
if ( ( V_5 && F_30 ( V_5 ) ) ||
( ( ( V_219 + ( V_5 ? V_5 -> V_30 : V_273 ) ) > V_60 ) &&
( F_166 ( V_217 ) <= 1 ) &&
( V_3 -> V_276 == V_277 ) &&
( V_122 -> V_7 . V_9 -> V_282 & V_293 ) && ! F_167 ( & V_122 -> V_7 ) &&
( V_3 -> V_285 == V_286 ) && ! F_168 ( V_3 ) ) ) {
V_154 = F_147 ( V_3 , V_217 , F_148 , V_142 , V_219 ,
V_220 , V_221 , V_222 ,
V_223 , V_60 , V_18 , V_46 ) ;
if ( V_154 )
goto error;
return 0 ;
}
if ( ! V_5 )
goto V_294;
while ( V_219 > 0 ) {
V_268 = ( V_242 -> V_219 <= V_60 && ! ( V_242 -> V_18 & V_260 ) ? V_60 : V_237 ) - V_5 -> V_30 ;
if ( V_268 < V_219 )
V_268 = V_237 - V_5 -> V_30 ;
if ( V_268 <= 0 ) {
char * V_91 ;
unsigned int V_295 ;
unsigned int V_296 ;
unsigned int V_297 ;
unsigned int V_298 ;
V_294:
if ( V_5 )
V_297 = V_5 -> V_30 - V_237 ;
else
V_297 = 0 ;
if ( ! V_5 || ! V_266 )
F_157 ( & V_60 , & V_237 ,
V_221 , V_5 , V_122 ,
V_238 ) ;
V_266 = V_5 ;
V_295 = V_219 + V_297 ;
if ( V_295 > ( V_242 -> V_219 <= V_60 && ! ( V_242 -> V_18 & V_260 ) ? V_60 : V_237 ) - V_221 )
V_295 = V_237 - V_221 - V_122 -> V_7 . V_299 ;
if ( ( V_18 & V_281 ) &&
! ( V_122 -> V_7 . V_9 -> V_282 & V_300 ) )
V_298 = V_60 ;
else
V_298 = V_295 + V_221 ;
V_298 += V_267 ;
if ( V_295 != V_219 + V_297 ) {
V_295 += V_122 -> V_7 . V_299 ;
}
V_298 += V_122 -> V_7 . V_299 ;
V_296 = V_295 + V_221 ;
V_298 += sizeof( struct V_146 ) ;
V_268 = V_295 - V_223 - V_297 ;
if ( V_268 < 0 ) {
V_154 = - V_38 ;
goto error;
}
if ( V_223 ) {
V_5 = F_150 ( V_3 ,
V_298 + V_220 ,
( V_18 & V_224 ) , & V_154 ) ;
} else {
V_5 = NULL ;
if ( F_169 ( & V_3 -> V_301 ) <=
2 * V_3 -> V_302 )
V_5 = F_170 ( V_3 ,
V_298 + V_220 , 1 ,
V_3 -> V_248 ) ;
if ( F_21 ( ! V_5 ) )
V_154 = - V_65 ;
}
if ( ! V_5 )
goto error;
V_5 -> V_40 = F_34 ( V_41 ) ;
V_5 -> V_159 = V_271 ;
V_5 -> V_225 = 0 ;
F_120 ( V_5 , V_220 + sizeof( struct V_146 ) +
V_267 ) ;
F_111 ( V_5 ) -> V_269 = V_269 ;
V_269 = 0 ;
F_111 ( V_5 ) -> V_270 = V_270 ;
V_270 = 0 ;
V_91 = F_121 ( V_5 , V_296 ) ;
F_151 ( V_5 , V_222 ) ;
V_91 += V_221 ;
V_5 -> V_180 = ( V_5 -> V_181 +
V_221 ) ;
if ( V_297 ) {
V_5 -> V_225 = F_171 (
V_266 , V_237 ,
V_91 + V_223 , V_297 , 0 ) ;
V_266 -> V_225 = F_172 ( V_266 -> V_225 ,
V_5 -> V_225 ) ;
V_91 += V_297 ;
F_173 ( V_266 , V_237 ) ;
}
if ( V_268 > 0 &&
F_148 ( V_142 , V_91 + V_223 , V_87 ,
V_268 , V_297 , V_5 ) < 0 ) {
V_154 = - V_303 ;
F_13 ( V_5 ) ;
goto error;
}
V_87 += V_268 ;
V_219 -= V_295 - V_297 ;
V_223 = 0 ;
V_222 = 0 ;
V_267 = 0 ;
if ( ( V_18 & V_226 ) && ! V_266 )
F_152 ( V_5 , 1 ) ;
F_153 ( V_217 , V_5 ) ;
continue;
}
if ( V_268 > V_219 )
V_268 = V_219 ;
if ( ! ( V_122 -> V_7 . V_9 -> V_282 & V_300 ) ) {
unsigned int V_304 ;
V_304 = V_5 -> V_30 ;
if ( F_148 ( V_142 , F_121 ( V_5 , V_268 ) ,
V_87 , V_268 , V_304 , V_5 ) < 0 ) {
F_174 ( V_5 , V_304 ) ;
V_154 = - V_303 ;
goto error;
}
} else {
int V_305 = F_111 ( V_5 ) -> V_306 ;
V_154 = - V_169 ;
if ( ! F_175 ( V_3 , V_263 ) )
goto error;
if ( ! F_176 ( V_5 , V_305 , V_263 -> V_307 ,
V_263 -> V_87 ) ) {
V_154 = - V_76 ;
if ( V_305 == V_308 )
goto error;
F_177 ( V_5 , V_305 , V_263 -> V_307 ,
V_263 -> V_87 , 0 ) ;
F_111 ( V_5 ) -> V_306 = ++ V_305 ;
F_178 ( V_263 -> V_307 ) ;
}
V_268 = F_179 ( int , V_268 , V_263 -> V_309 - V_263 -> V_87 ) ;
if ( F_148 ( V_142 ,
F_180 ( V_263 -> V_307 ) + V_263 -> V_87 ,
V_87 , V_268 , V_5 -> V_30 , V_5 ) < 0 )
goto V_310;
V_263 -> V_87 += V_268 ;
F_181 ( & F_111 ( V_5 ) -> V_311 [ V_305 - 1 ] , V_268 ) ;
V_5 -> V_30 += V_268 ;
V_5 -> V_174 += V_268 ;
V_5 -> V_167 += V_268 ;
F_182 ( V_268 , & V_3 -> V_301 ) ;
}
V_87 += V_268 ;
V_219 -= V_268 ;
}
return 0 ;
V_310:
V_154 = - V_303 ;
error:
V_242 -> V_219 -= V_219 ;
F_12 ( F_37 ( V_3 ) , V_122 -> V_312 , V_28 ) ;
return V_154 ;
}
int F_183 ( struct V_2 * V_3 ,
int F_148 ( void * V_142 , char * V_141 , int V_87 , int V_30 ,
int V_218 , struct V_4 * V_5 ) ,
void * V_142 , int V_219 , int V_223 ,
struct V_245 * V_246 , struct V_45 * V_46 ,
struct V_35 * V_122 , unsigned int V_18 ,
const struct V_264 * V_265 )
{
struct V_313 * V_314 = F_184 ( V_3 ) ;
struct V_51 * V_52 = F_38 ( V_3 ) ;
int V_222 ;
int V_154 ;
if ( V_18 & V_315 )
return 0 ;
if ( F_185 ( & V_3 -> V_316 ) ) {
V_154 = F_158 ( V_3 , & V_314 -> V_242 , & V_52 -> V_242 ,
V_246 , V_122 , V_46 ) ;
if ( V_154 )
return V_154 ;
V_222 = ( V_246 -> V_49 ? V_246 -> V_49 -> V_63 : 0 ) ;
V_219 += V_222 ;
V_223 += V_222 ;
} else {
V_46 = & V_314 -> V_242 . V_253 . V_254 . V_255 ;
V_223 = 0 ;
}
return F_162 ( V_3 , V_46 , & V_3 -> V_316 , & V_314 -> V_242 . V_252 ,
& V_52 -> V_242 , F_186 ( V_3 ) , F_148 ,
V_142 , V_219 , V_223 , V_18 , V_246 , V_265 ) ;
}
static void F_187 ( struct V_241 * V_242 ,
struct V_243 * V_244 )
{
if ( V_244 -> V_49 ) {
F_117 ( V_244 -> V_49 -> V_249 ) ;
F_117 ( V_244 -> V_49 -> V_250 ) ;
F_117 ( V_244 -> V_49 -> V_251 ) ;
F_117 ( V_244 -> V_49 -> V_118 ) ;
F_117 ( V_244 -> V_49 ) ;
V_244 -> V_49 = NULL ;
}
if ( V_242 -> V_252 . V_7 ) {
F_129 ( V_242 -> V_252 . V_7 ) ;
V_242 -> V_252 . V_7 = NULL ;
V_242 -> V_252 . V_18 &= ~ V_260 ;
}
memset ( & V_242 -> V_253 , 0 , sizeof( V_242 -> V_253 ) ) ;
}
struct V_4 * F_188 ( struct V_2 * V_3 ,
struct V_216 * V_217 ,
struct V_241 * V_242 ,
struct V_243 * V_244 )
{
struct V_4 * V_5 , * V_317 ;
struct V_4 * * V_318 ;
struct V_12 V_319 , * V_214 = & V_319 ;
struct V_51 * V_52 = F_38 ( V_3 ) ;
struct V_1 * V_1 = F_37 ( V_3 ) ;
struct V_54 * V_55 ;
struct V_48 * V_49 = V_244 -> V_49 ;
struct V_35 * V_122 = (struct V_35 * ) V_242 -> V_252 . V_7 ;
struct V_45 * V_46 = & V_242 -> V_253 . V_254 . V_255 ;
unsigned char V_56 = V_46 -> V_57 ;
V_5 = F_189 ( V_217 ) ;
if ( ! V_5 )
goto V_189;
V_318 = & ( F_111 ( V_5 ) -> V_170 ) ;
if ( V_5 -> V_91 < F_62 ( V_5 ) )
F_113 ( V_5 , F_190 ( V_5 ) ) ;
while ( ( V_317 = F_189 ( V_217 ) ) != NULL ) {
F_113 ( V_317 , F_191 ( V_5 ) ) ;
* V_318 = V_317 ;
V_318 = & ( V_317 -> V_83 ) ;
V_5 -> V_30 += V_317 -> V_30 ;
V_5 -> V_174 += V_317 -> V_30 ;
V_5 -> V_167 += V_317 -> V_167 ;
V_317 -> V_165 = NULL ;
V_317 -> V_3 = NULL ;
}
V_5 -> V_72 = F_164 ( V_3 ) ;
* V_214 = V_46 -> V_15 ;
F_113 ( V_5 , F_191 ( V_5 ) ) ;
if ( V_49 && V_49 -> V_63 )
F_44 ( V_5 , V_49 , & V_56 ) ;
if ( V_49 && V_49 -> V_62 )
F_45 ( V_5 , V_49 , & V_56 , & V_214 , & V_46 -> V_21 ) ;
F_46 ( V_5 , sizeof( struct V_54 ) ) ;
F_47 ( V_5 ) ;
V_55 = F_4 ( V_5 ) ;
F_49 ( V_55 , V_244 -> V_50 ,
F_50 ( V_1 , V_5 , V_46 -> V_66 ,
V_52 -> V_67 , V_46 ) ) ;
V_55 -> V_27 = V_244 -> V_27 ;
V_55 -> V_69 = V_56 ;
V_55 -> V_21 = V_46 -> V_21 ;
V_55 -> V_15 = * V_214 ;
V_5 -> V_70 = V_3 -> V_71 ;
V_5 -> V_47 = V_3 -> V_320 ;
F_94 ( V_5 , F_95 ( & V_122 -> V_7 ) ) ;
F_14 ( V_1 , V_122 -> V_312 , V_73 , V_5 -> V_30 ) ;
if ( V_56 == V_88 ) {
struct V_16 * V_17 = F_5 ( F_2 ( V_5 ) ) ;
F_192 ( V_1 , V_17 , F_193 ( V_5 ) -> V_92 ) ;
F_194 ( V_1 , V_17 , V_321 ) ;
}
F_187 ( V_242 , V_244 ) ;
V_189:
return V_5 ;
}
int F_195 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_37 ( V_5 -> V_3 ) ;
struct V_35 * V_122 = (struct V_35 * ) F_2 ( V_5 ) ;
int V_154 ;
V_154 = F_196 ( V_1 , V_5 -> V_3 , V_5 ) ;
if ( V_154 ) {
if ( V_154 > 0 )
V_154 = F_197 ( V_154 ) ;
if ( V_154 )
F_12 ( V_1 , V_122 -> V_312 ,
V_28 ) ;
}
return V_154 ;
}
int F_198 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_199 ( V_3 ) ;
if ( ! V_5 )
return 0 ;
return F_195 ( V_5 ) ;
}
static void F_200 ( struct V_2 * V_3 ,
struct V_216 * V_217 ,
struct V_241 * V_242 ,
struct V_243 * V_244 )
{
struct V_4 * V_5 ;
while ( ( V_5 = F_201 ( V_217 ) ) != NULL ) {
if ( F_2 ( V_5 ) )
F_12 ( F_37 ( V_3 ) , F_5 ( F_2 ( V_5 ) ) ,
V_28 ) ;
F_13 ( V_5 ) ;
}
F_187 ( V_242 , V_244 ) ;
}
void F_202 ( struct V_2 * V_3 )
{
F_200 ( V_3 , & V_3 -> V_316 ,
& F_184 ( V_3 ) -> V_242 , & F_38 ( V_3 ) -> V_242 ) ;
}
struct V_4 * F_203 ( struct V_2 * V_3 ,
int F_148 ( void * V_142 , char * V_141 , int V_87 ,
int V_30 , int V_218 , struct V_4 * V_5 ) ,
void * V_142 , int V_219 , int V_223 ,
struct V_245 * V_246 , struct V_45 * V_46 ,
struct V_35 * V_122 , unsigned int V_18 ,
const struct V_264 * V_265 )
{
struct V_241 V_242 ;
struct V_243 V_244 ;
struct V_216 V_217 ;
int V_222 = ( V_246 -> V_49 ? V_246 -> V_49 -> V_63 : 0 ) ;
int V_154 ;
if ( V_18 & V_315 )
return NULL ;
F_204 ( & V_217 ) ;
V_242 . V_252 . V_18 = 0 ;
V_242 . V_252 . V_188 = 0 ;
V_242 . V_252 . V_49 = NULL ;
V_244 . V_49 = NULL ;
V_154 = F_158 ( V_3 , & V_242 , & V_244 , V_246 , V_122 , V_46 ) ;
if ( V_154 )
return F_142 ( V_154 ) ;
if ( V_246 -> V_275 < 0 )
V_246 -> V_275 = F_38 ( V_3 ) -> V_275 ;
V_154 = F_162 ( V_3 , V_46 , & V_217 , & V_242 . V_252 , & V_244 ,
& V_322 -> V_323 , F_148 , V_142 ,
V_219 + V_222 , V_223 + V_222 ,
V_18 , V_246 , V_265 ) ;
if ( V_154 ) {
F_200 ( V_3 , & V_217 , & V_242 , & V_244 ) ;
return F_142 ( V_154 ) ;
}
return F_188 ( V_3 , & V_217 , & V_242 , & V_244 ) ;
}
