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
int V_14 ;
V_14 = F_28 ( V_3 , V_5 ) ;
if ( V_14 ) {
F_14 ( V_5 ) ;
return V_14 ;
}
if ( ( V_5 -> V_32 > F_29 ( V_5 ) && ! F_30 ( V_5 ) ) ||
F_31 ( F_2 ( V_5 ) ) ||
( F_9 ( V_5 ) -> V_41 && V_5 -> V_32 > F_9 ( V_5 ) -> V_41 ) )
return F_32 ( V_1 , V_3 , V_5 , F_1 ) ;
else
return F_1 ( V_1 , V_3 , V_5 ) ;
}
int F_33 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_8 * V_9 = F_2 ( V_5 ) -> V_9 ;
struct V_18 * V_19 = F_6 ( F_2 ( V_5 ) ) ;
if ( F_22 ( V_19 -> V_42 . V_43 ) ) {
F_13 ( V_1 , V_19 , V_30 ) ;
F_14 ( V_5 ) ;
return 0 ;
}
return F_34 ( V_26 , V_27 ,
V_1 , V_3 , V_5 , NULL , V_9 ,
F_27 ,
! ( F_9 ( V_5 ) -> V_20 & V_44 ) ) ;
}
int F_35 ( const struct V_2 * V_3 , struct V_4 * V_5 , struct V_45 * V_46 ,
T_1 V_47 , struct V_48 * V_49 , int V_50 )
{
struct V_1 * V_1 = F_36 ( V_3 ) ;
const struct V_51 * V_52 = F_37 ( V_3 ) ;
struct V_12 * V_53 = & V_46 -> V_17 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_54 * V_55 ;
T_2 V_56 = V_46 -> V_57 ;
int V_58 = V_5 -> V_32 ;
int V_59 = - 1 ;
T_3 V_60 ;
if ( V_49 ) {
unsigned int V_61 ;
V_61 = V_49 -> V_62 + V_49 -> V_63 ;
V_58 += V_61 ;
V_61 += sizeof( struct V_54 ) + F_38 ( V_7 -> V_9 ) ;
if ( F_39 ( V_5 ) < V_61 ) {
struct V_4 * V_64 = F_40 ( V_5 , V_61 ) ;
if ( ! V_64 ) {
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_30 ) ;
F_14 ( V_5 ) ;
return - V_65 ;
}
F_41 ( V_5 ) ;
V_5 = V_64 ;
F_42 ( V_5 , (struct V_2 * ) V_3 ) ;
}
if ( V_49 -> V_63 )
F_43 ( V_5 , V_49 , & V_56 ) ;
if ( V_49 -> V_62 )
F_44 ( V_5 , V_49 , & V_56 , & V_53 ,
& V_46 -> V_23 ) ;
}
F_45 ( V_5 , sizeof( struct V_54 ) ) ;
F_46 ( V_5 ) ;
V_55 = F_5 ( V_5 ) ;
if ( V_52 )
V_59 = V_52 -> V_29 ;
if ( V_59 < 0 )
V_59 = F_47 ( V_7 ) ;
F_48 ( V_55 , V_50 , F_49 ( V_1 , V_5 , V_46 -> V_66 ,
V_52 -> V_67 , V_46 ) ) ;
V_55 -> V_68 = F_3 ( V_58 ) ;
V_55 -> V_69 = V_56 ;
V_55 -> V_29 = V_59 ;
V_55 -> V_23 = V_46 -> V_23 ;
V_55 -> V_17 = * V_53 ;
V_5 -> V_15 = F_3 ( V_16 ) ;
V_5 -> V_70 = V_3 -> V_71 ;
V_5 -> V_47 = V_47 ;
V_60 = F_50 ( V_7 ) ;
if ( ( V_5 -> V_32 <= V_60 ) || V_5 -> V_72 || F_30 ( V_5 ) ) {
F_15 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_73 , V_5 -> V_32 ) ;
V_5 = F_51 ( (struct V_2 * ) V_3 , V_5 ) ;
if ( F_22 ( ! V_5 ) )
return 0 ;
return F_12 ( V_26 , V_74 ,
V_1 , (struct V_2 * ) V_3 , V_5 , NULL , V_7 -> V_9 ,
V_75 ) ;
}
V_5 -> V_9 = V_7 -> V_9 ;
F_52 ( (struct V_2 * ) V_3 , V_76 , V_46 , V_60 ) ;
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) , V_77 ) ;
F_14 ( V_5 ) ;
return - V_76 ;
}
static int F_53 ( struct V_4 * V_5 , int V_78 )
{
struct V_79 * V_80 ;
struct V_2 * V_81 = NULL ;
F_54 ( & V_82 ) ;
for ( V_80 = V_79 ; V_80 ; V_80 = V_80 -> V_83 ) {
struct V_2 * V_3 = V_80 -> V_3 ;
if ( V_3 && V_80 -> V_78 == V_78 &&
( ! V_3 -> V_84 ||
V_3 -> V_84 == V_5 -> V_9 -> V_85 ) ) {
if ( V_81 ) {
struct V_4 * V_64 = F_11 ( V_5 , V_25 ) ;
if ( V_64 )
F_55 ( V_81 , V_64 ) ;
}
V_81 = V_3 ;
}
}
if ( V_81 ) {
F_55 ( V_81 , V_5 ) ;
F_56 ( & V_82 ) ;
return 1 ;
}
F_56 ( & V_82 ) ;
return 0 ;
}
static int F_57 ( struct V_4 * V_5 )
{
struct V_54 * V_55 = F_5 ( V_5 ) ;
T_2 V_69 = V_55 -> V_69 ;
T_4 V_86 ;
int V_87 ;
if ( F_58 ( V_69 ) ) {
V_87 = F_59 ( V_5 , sizeof( * V_55 ) , & V_69 , & V_86 ) ;
if ( V_87 < 0 )
return 0 ;
} else
V_87 = sizeof( struct V_54 ) ;
if ( V_69 == V_88 ) {
struct V_89 * V_90 ;
if ( ! F_60 ( V_5 , ( F_61 ( V_5 ) +
V_87 + 1 - V_5 -> V_91 ) ) )
return 0 ;
V_90 = (struct V_89 * ) ( F_61 ( V_5 ) + V_87 ) ;
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
if ( F_62 ( & V_55 -> V_17 ) & V_98 ) {
F_63 ( V_5 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_64 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 )
{
return V_75 ( V_1 , V_3 , V_5 ) ;
}
static unsigned int F_65 ( const struct V_6 * V_7 )
{
unsigned int V_60 ;
struct V_18 * V_19 ;
if ( F_66 ( V_7 , V_99 ) ) {
V_60 = F_67 ( V_7 , V_99 ) ;
if ( V_60 )
return V_60 ;
}
V_60 = V_100 ;
F_68 () ;
V_19 = F_69 ( V_7 -> V_9 ) ;
if ( V_19 )
V_60 = V_19 -> V_42 . V_101 ;
F_70 () ;
return V_60 ;
}
static bool F_71 ( const struct V_4 * V_5 , unsigned int V_60 )
{
if ( V_5 -> V_32 <= V_60 )
return false ;
if ( F_9 ( V_5 ) -> V_41 && F_9 ( V_5 ) -> V_41 > V_60 )
return true ;
if ( V_5 -> V_72 )
return false ;
if ( F_30 ( V_5 ) && F_72 ( V_5 , V_60 ) )
return false ;
return true ;
}
int F_73 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_54 * V_55 = F_5 ( V_5 ) ;
struct V_102 * V_49 = F_9 ( V_5 ) ;
struct V_1 * V_1 = F_74 ( V_7 -> V_9 ) ;
T_3 V_60 ;
if ( V_1 -> V_103 . V_104 -> V_105 == 0 )
goto error;
if ( V_5 -> V_106 != V_107 )
goto V_108;
if ( F_22 ( V_5 -> V_3 ) )
goto V_108;
if ( F_75 ( V_5 ) )
goto V_108;
if ( ! F_76 ( NULL , V_109 , V_5 ) ) {
F_77 ( V_1 , F_6 ( V_7 ) ,
V_110 ) ;
goto V_108;
}
F_78 ( V_5 ) ;
if ( F_22 ( V_49 -> V_20 & V_111 ) ) {
if ( F_53 ( V_5 , F_79 ( V_49 -> V_80 ) ) )
return 0 ;
}
if ( V_55 -> V_29 <= 1 ) {
V_5 -> V_9 = V_7 -> V_9 ;
F_80 ( V_5 , V_112 , V_113 , 0 ) ;
F_77 ( V_1 , F_6 ( V_7 ) ,
V_114 ) ;
F_14 ( V_5 ) ;
return - V_115 ;
}
if ( V_1 -> V_103 . V_104 -> V_116 &&
F_81 ( & V_38 , V_1 , & V_55 -> V_17 , V_5 -> V_9 , 0 ) ) {
int V_117 = F_57 ( V_5 ) ;
if ( V_117 > 0 )
return F_82 ( V_5 ) ;
else if ( V_117 < 0 ) {
F_77 ( V_1 , F_6 ( V_7 ) ,
V_110 ) ;
goto V_108;
}
}
if ( ! F_83 ( V_5 ) ) {
F_77 ( V_1 , F_6 ( V_7 ) ,
V_110 ) ;
goto V_108;
}
V_7 = F_2 ( V_5 ) ;
if ( V_5 -> V_9 == V_7 -> V_9 && V_49 -> V_118 == 0 && ! F_84 ( V_5 ) ) {
struct V_12 * V_119 = NULL ;
struct V_120 * V_121 ;
struct V_37 * V_122 ;
V_122 = (struct V_37 * ) V_7 ;
if ( V_122 -> V_123 & V_124 )
V_119 = & V_122 -> V_125 ;
else
V_119 = & V_55 -> V_17 ;
V_121 = F_85 ( V_1 -> V_103 . V_126 , & V_55 -> V_17 , 1 ) ;
if ( F_86 ( V_121 , 1 * V_127 ) )
F_87 ( V_5 , V_119 ) ;
if ( V_121 )
F_88 ( V_121 ) ;
} else {
int V_128 = F_62 ( & V_55 -> V_23 ) ;
if ( V_128 == V_129 ||
V_128 & ( V_130 | V_131 ) )
goto error;
if ( V_128 & V_98 ) {
F_80 ( V_5 , V_132 ,
V_133 , 0 ) ;
goto error;
}
}
V_60 = F_65 ( V_7 ) ;
if ( V_60 < V_100 )
V_60 = V_100 ;
if ( F_71 ( V_5 , V_60 ) ) {
V_5 -> V_9 = V_7 -> V_9 ;
F_80 ( V_5 , V_134 , 0 , V_60 ) ;
F_77 ( V_1 , F_6 ( V_7 ) ,
V_135 ) ;
F_77 ( V_1 , F_6 ( V_7 ) ,
V_77 ) ;
F_14 ( V_5 ) ;
return - V_76 ;
}
if ( F_89 ( V_5 , V_7 -> V_9 -> V_136 ) ) {
F_77 ( V_1 , F_6 ( V_7 ) ,
V_30 ) ;
goto V_108;
}
V_55 = F_5 ( V_5 ) ;
V_55 -> V_29 -- ;
F_77 ( V_1 , F_6 ( V_7 ) , V_137 ) ;
F_90 ( V_1 , F_6 ( V_7 ) , V_138 , V_5 -> V_32 ) ;
return F_12 ( V_26 , V_139 ,
V_1 , NULL , V_5 , V_5 -> V_9 , V_7 -> V_9 ,
F_64 ) ;
error:
F_77 ( V_1 , F_6 ( V_7 ) , V_140 ) ;
V_108:
F_14 ( V_5 ) ;
return - V_40 ;
}
static void F_91 ( struct V_4 * V_141 , struct V_4 * V_142 )
{
V_141 -> V_106 = V_142 -> V_106 ;
V_141 -> V_70 = V_142 -> V_70 ;
V_141 -> V_15 = V_142 -> V_15 ;
F_92 ( V_141 ) ;
F_93 ( V_141 , F_94 ( F_2 ( V_142 ) ) ) ;
V_141 -> V_9 = V_142 -> V_9 ;
V_141 -> V_47 = V_142 -> V_47 ;
#ifdef F_95
V_141 -> V_143 = V_142 -> V_143 ;
#endif
F_96 ( V_141 , V_142 ) ;
F_97 ( V_141 , V_142 ) ;
}
int F_32 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 ,
int (* F_98)( struct V_1 * , struct V_2 * , struct V_4 * ) )
{
struct V_4 * V_144 ;
struct V_37 * V_122 = (struct V_37 * ) F_2 ( V_5 ) ;
struct V_51 * V_52 = V_5 -> V_3 && ! F_99 () ?
F_37 ( V_5 -> V_3 ) : NULL ;
struct V_54 * V_145 ;
struct V_146 * V_147 ;
unsigned int V_60 , V_148 , V_149 , V_32 ;
int V_150 , V_151 ;
T_5 V_152 ;
int V_153 , V_87 = 0 , V_154 = 0 ;
T_2 * V_155 , V_69 = 0 ;
V_148 = F_100 ( V_5 , & V_155 ) ;
V_69 = * V_155 ;
V_60 = F_29 ( V_5 ) ;
if ( F_22 ( ! V_5 -> V_72 && V_5 -> V_32 > V_60 ) )
goto V_156;
if ( F_9 ( V_5 ) -> V_41 ) {
if ( F_9 ( V_5 ) -> V_41 > V_60 )
goto V_156;
V_60 = F_9 ( V_5 ) -> V_41 ;
if ( V_60 < V_100 )
V_60 = V_100 ;
}
if ( V_52 && V_52 -> V_157 < V_60 ) {
if ( V_52 -> V_157 )
V_60 = V_52 -> V_157 ;
}
if ( V_60 < V_148 + sizeof( struct V_146 ) + 8 )
goto V_156;
V_60 -= V_148 + sizeof( struct V_146 ) ;
V_152 = F_101 ( V_1 , & F_5 ( V_5 ) -> V_17 ,
& F_5 ( V_5 ) -> V_23 ) ;
if ( V_5 -> V_158 == V_159 &&
( V_154 = F_102 ( V_5 ) ) )
goto V_160;
V_150 = F_38 ( V_122 -> V_7 . V_9 ) ;
if ( F_103 ( V_5 ) ) {
unsigned int V_161 = F_104 ( V_5 ) ;
struct V_4 * V_162 ;
if ( V_161 - V_148 > V_60 ||
( ( V_161 - V_148 ) & 7 ) ||
F_105 ( V_5 ) ||
F_39 ( V_5 ) < ( V_150 + sizeof( struct V_146 ) ) )
goto V_163;
F_106 (skb, frag) {
if ( V_144 -> V_32 > V_60 ||
( ( V_144 -> V_32 & 7 ) && V_144 -> V_83 ) ||
F_39 ( V_144 ) < ( V_148 + V_150 + sizeof( struct V_146 ) ) )
goto V_164;
if ( F_107 ( V_144 ) )
goto V_164;
F_108 ( V_144 -> V_3 ) ;
if ( V_5 -> V_3 ) {
V_144 -> V_3 = V_5 -> V_3 ;
V_144 -> V_165 = V_166 ;
}
V_5 -> V_167 -= V_144 -> V_167 ;
}
V_154 = 0 ;
V_87 = 0 ;
* V_155 = V_168 ;
V_145 = F_109 ( F_61 ( V_5 ) , V_148 , V_25 ) ;
if ( ! V_145 ) {
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_77 ) ;
V_154 = - V_169 ;
goto V_160;
}
V_144 = F_110 ( V_5 ) -> V_170 ;
F_111 ( V_5 ) ;
F_112 ( V_5 , V_148 ) ;
V_147 = (struct V_146 * ) F_113 ( V_5 , sizeof( struct V_146 ) ) ;
F_113 ( V_5 , V_148 ) ;
F_46 ( V_5 ) ;
memcpy ( F_61 ( V_5 ) , V_145 , V_148 ) ;
V_147 -> V_69 = V_69 ;
V_147 -> V_171 = 0 ;
V_147 -> V_86 = F_3 ( V_172 ) ;
V_147 -> V_173 = V_152 ;
V_161 = F_104 ( V_5 ) ;
V_5 -> V_174 = V_161 - F_114 ( V_5 ) ;
V_5 -> V_32 = V_161 ;
F_5 ( V_5 ) -> V_68 = F_3 ( V_161 -
sizeof( struct V_54 ) ) ;
F_115 ( & V_122 -> V_7 ) ;
for (; ; ) {
if ( V_144 ) {
V_144 -> V_158 = V_175 ;
F_116 ( V_144 ) ;
V_147 = (struct V_146 * ) F_113 ( V_144 , sizeof( struct V_146 ) ) ;
F_113 ( V_144 , V_148 ) ;
F_46 ( V_144 ) ;
memcpy ( F_61 ( V_144 ) , V_145 ,
V_148 ) ;
V_87 += V_5 -> V_32 - V_148 - sizeof( struct V_146 ) ;
V_147 -> V_69 = V_69 ;
V_147 -> V_171 = 0 ;
V_147 -> V_86 = F_3 ( V_87 ) ;
if ( V_144 -> V_83 )
V_147 -> V_86 |= F_3 ( V_172 ) ;
V_147 -> V_173 = V_152 ;
F_5 ( V_144 ) -> V_68 =
F_3 ( V_144 -> V_32 -
sizeof( struct V_54 ) ) ;
F_91 ( V_144 , V_5 ) ;
}
V_154 = F_98 ( V_1 , V_3 , V_5 ) ;
if ( ! V_154 )
F_13 ( V_1 , F_6 ( & V_122 -> V_7 ) ,
V_176 ) ;
if ( V_154 || ! V_144 )
break;
V_5 = V_144 ;
V_144 = V_5 -> V_83 ;
V_5 -> V_83 = NULL ;
}
F_117 ( V_145 ) ;
if ( V_154 == 0 ) {
F_13 ( V_1 , F_6 ( & V_122 -> V_7 ) ,
V_177 ) ;
F_118 ( V_122 ) ;
return 0 ;
}
F_119 ( V_144 ) ;
F_13 ( V_1 , F_6 ( & V_122 -> V_7 ) ,
V_77 ) ;
F_118 ( V_122 ) ;
return V_154 ;
V_164:
F_106 (skb, frag2) {
if ( V_162 == V_144 )
break;
V_162 -> V_3 = NULL ;
V_162 -> V_165 = NULL ;
V_5 -> V_167 += V_162 -> V_167 ;
}
}
V_163:
V_149 = V_5 -> V_32 - V_148 ;
V_153 = V_148 ;
* V_155 = V_168 ;
V_151 = V_122 -> V_7 . V_9 -> V_178 ;
while ( V_149 > 0 ) {
V_32 = V_149 ;
if ( V_32 > V_60 )
V_32 = V_60 ;
if ( V_32 < V_149 ) {
V_32 &= ~ 7 ;
}
V_144 = F_120 ( V_32 + V_148 + sizeof( struct V_146 ) +
V_150 + V_151 , V_25 ) ;
if ( ! V_144 ) {
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_77 ) ;
V_154 = - V_169 ;
goto V_160;
}
F_91 ( V_144 , V_5 ) ;
F_121 ( V_144 , V_150 ) ;
F_122 ( V_144 , V_32 + V_148 + sizeof( struct V_146 ) ) ;
F_46 ( V_144 ) ;
V_147 = (struct V_146 * ) ( F_61 ( V_144 ) + V_148 ) ;
V_144 -> V_179 = ( V_144 -> V_180 + V_148 +
sizeof( struct V_146 ) ) ;
if ( V_5 -> V_3 )
F_42 ( V_144 , V_5 -> V_3 ) ;
F_123 ( V_5 , F_61 ( V_144 ) , V_148 ) ;
V_147 -> V_69 = V_69 ;
V_147 -> V_171 = 0 ;
V_147 -> V_173 = V_152 ;
F_108 ( F_124 ( V_5 , V_153 , F_125 ( V_144 ) ,
V_32 ) ) ;
V_149 -= V_32 ;
V_147 -> V_86 = F_3 ( V_87 ) ;
if ( V_149 > 0 )
V_147 -> V_86 |= F_3 ( V_172 ) ;
F_5 ( V_144 ) -> V_68 = F_3 ( V_144 -> V_32 -
sizeof( struct V_54 ) ) ;
V_153 += V_32 ;
V_87 += V_32 ;
V_154 = F_98 ( V_1 , V_3 , V_144 ) ;
if ( V_154 )
goto V_160;
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_176 ) ;
}
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_177 ) ;
F_41 ( V_5 ) ;
return V_154 ;
V_156:
if ( V_5 -> V_3 && F_31 ( F_2 ( V_5 ) ) )
F_126 ( V_5 -> V_3 , V_181 ) ;
V_5 -> V_9 = F_2 ( V_5 ) -> V_9 ;
F_80 ( V_5 , V_134 , 0 , V_60 ) ;
V_154 = - V_76 ;
V_160:
F_13 ( V_1 , F_6 ( F_2 ( V_5 ) ) ,
V_77 ) ;
F_14 ( V_5 ) ;
return V_154 ;
}
static inline int F_127 ( const struct V_182 * V_183 ,
const struct V_12 * V_184 ,
const struct V_12 * V_185 )
{
return ( V_183 -> V_186 != 128 || ! F_128 ( V_184 , & V_183 -> V_187 ) ) &&
( ! V_185 || ! F_128 ( V_184 , V_185 ) ) ;
}
static struct V_6 * F_129 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
const struct V_45 * V_46 )
{
struct V_51 * V_52 = F_37 ( V_3 ) ;
struct V_37 * V_122 ;
if ( ! V_7 )
goto V_188;
if ( V_7 -> V_189 -> V_190 != V_191 ) {
F_130 ( V_7 ) ;
return NULL ;
}
V_122 = (struct V_37 * ) V_7 ;
if ( F_127 ( & V_122 -> V_192 , & V_46 -> V_17 , V_52 -> V_193 ) ||
#ifdef F_131
F_127 ( & V_122 -> V_194 , & V_46 -> V_23 , V_52 -> V_195 ) ||
#endif
( ! ( V_46 -> V_196 & V_197 ) &&
( V_46 -> V_198 && V_46 -> V_198 != V_7 -> V_9 -> V_85 ) ) ) {
F_130 ( V_7 ) ;
V_7 = NULL ;
}
V_188:
return V_7 ;
}
static int F_132 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
struct V_6 * * V_7 , struct V_45 * V_46 )
{
#ifdef F_133
struct V_10 * V_199 ;
struct V_37 * V_122 ;
#endif
int V_154 ;
int V_20 = 0 ;
if ( F_134 ( & V_46 -> V_23 ) && ( ! * V_7 || ! ( * V_7 ) -> error ) ) {
struct V_37 * V_122 ;
bool V_200 = * V_7 != NULL ;
if ( ! V_200 )
* V_7 = F_135 ( V_1 , V_3 , V_46 ) ;
V_122 = ( * V_7 ) -> error ? NULL : (struct V_37 * ) * V_7 ;
V_154 = F_136 ( V_1 , V_122 , & V_46 -> V_17 ,
V_3 ? F_37 ( V_3 ) -> V_201 : 0 ,
& V_46 -> V_23 ) ;
if ( V_154 )
goto V_202;
if ( ! V_200 && ( * V_7 ) -> error ) {
F_130 ( * V_7 ) ;
* V_7 = NULL ;
}
if ( V_46 -> V_198 )
V_20 |= V_203 ;
}
if ( ! * V_7 )
* V_7 = F_137 ( V_1 , V_3 , V_46 , V_20 ) ;
V_154 = ( * V_7 ) -> error ;
if ( V_154 )
goto V_202;
#ifdef F_133
V_122 = (struct V_37 * ) * V_7 ;
F_19 () ;
V_199 = F_21 ( V_122 -> V_7 . V_9 ,
F_20 ( V_122 , & V_46 -> V_17 ) ) ;
V_154 = V_199 && ! ( V_199 -> V_204 & V_205 ) ? - V_40 : 0 ;
F_26 () ;
if ( V_154 ) {
struct V_206 * V_207 ;
struct V_45 V_208 ;
int V_209 ;
V_207 = F_138 ( V_1 , & V_46 -> V_23 ,
( * V_7 ) -> V_9 , 1 ) ;
V_209 = ( V_207 && V_207 -> V_20 & V_210 ) ;
if ( V_207 )
F_139 ( V_207 ) ;
if ( V_209 ) {
F_130 ( * V_7 ) ;
memcpy ( & V_208 , V_46 , sizeof( struct V_45 ) ) ;
memset ( & V_208 . V_17 , 0 , sizeof( struct V_12 ) ) ;
* V_7 = F_135 ( V_1 , V_3 , & V_208 ) ;
V_154 = ( * V_7 ) -> error ;
if ( V_154 )
goto V_202;
}
}
#endif
if ( F_140 ( & V_46 -> V_23 ) &&
! ( F_140 ( & V_46 -> V_17 ) || F_134 ( & V_46 -> V_17 ) ) ) {
V_154 = - V_211 ;
goto V_202;
}
return 0 ;
V_202:
F_130 ( * V_7 ) ;
* V_7 = NULL ;
if ( V_154 == - V_212 )
F_13 ( V_1 , NULL , V_39 ) ;
return V_154 ;
}
int F_141 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_6 * * V_7 ,
struct V_45 * V_46 )
{
* V_7 = NULL ;
return F_132 ( V_1 , V_3 , V_7 , V_46 ) ;
}
struct V_6 * F_142 ( const struct V_2 * V_3 , struct V_45 * V_46 ,
const struct V_12 * V_213 )
{
struct V_6 * V_7 = NULL ;
int V_154 ;
V_154 = F_132 ( F_36 ( V_3 ) , V_3 , & V_7 , V_46 ) ;
if ( V_154 )
return F_143 ( V_154 ) ;
if ( V_213 )
V_46 -> V_17 = * V_213 ;
return F_144 ( F_36 ( V_3 ) , V_7 , F_145 ( V_46 ) , V_3 , 0 ) ;
}
struct V_6 * F_146 ( struct V_2 * V_3 , struct V_45 * V_46 ,
const struct V_12 * V_213 )
{
struct V_6 * V_7 = F_147 ( V_3 , F_37 ( V_3 ) -> V_214 ) ;
V_7 = F_129 ( V_3 , V_7 , V_46 ) ;
if ( ! V_7 )
V_7 = F_142 ( V_3 , V_46 , V_213 ) ;
return V_7 ;
}
static inline int F_148 ( struct V_2 * V_3 ,
struct V_215 * V_216 ,
int F_149 ( void * V_142 , char * V_141 , int V_87 , int V_32 ,
int V_217 , struct V_4 * V_5 ) ,
void * V_142 , int V_218 , int V_219 , int V_220 ,
int V_221 , int V_222 , int V_60 ,
unsigned int V_20 , const struct V_45 * V_46 )
{
struct V_4 * V_5 ;
int V_154 ;
V_5 = F_150 ( V_216 ) ;
if ( ! V_5 ) {
V_5 = F_151 ( V_3 ,
V_219 + V_220 + V_222 + 20 ,
( V_20 & V_223 ) , & V_154 ) ;
if ( ! V_5 )
return V_154 ;
F_121 ( V_5 , V_219 ) ;
F_122 ( V_5 , V_220 + V_222 ) ;
F_152 ( V_5 , V_221 ) ;
V_5 -> V_179 = V_5 -> V_180 + V_220 ;
V_5 -> V_15 = F_3 ( V_16 ) ;
V_5 -> V_224 = 0 ;
F_153 ( V_216 , V_5 ) ;
} else if ( F_30 ( V_5 ) ) {
goto V_225;
}
V_5 -> V_158 = V_159 ;
F_110 ( V_5 ) -> V_226 = ( V_60 - V_220 -
sizeof( struct V_146 ) ) & ~ 7 ;
F_110 ( V_5 ) -> V_227 = V_228 ;
F_110 ( V_5 ) -> V_229 = F_101 ( F_36 ( V_3 ) ,
& V_46 -> V_17 ,
& V_46 -> V_23 ) ;
V_225:
return F_154 ( V_3 , V_5 , F_149 , V_142 ,
( V_218 - V_222 ) ) ;
}
static inline struct V_230 * F_155 ( struct V_230 * V_231 ,
T_6 V_232 )
{
return V_231 ? F_109 ( V_231 , ( V_231 -> V_233 + 1 ) * 8 , V_232 ) : NULL ;
}
static inline struct V_234 * F_156 ( struct V_234 * V_231 ,
T_6 V_232 )
{
return V_231 ? F_109 ( V_231 , ( V_231 -> V_233 + 1 ) * 8 , V_232 ) : NULL ;
}
static void F_157 ( unsigned int * V_60 ,
int * V_235 ,
unsigned int V_220 ,
struct V_4 * V_5 ,
struct V_37 * V_122 ,
unsigned int V_236 )
{
if ( ! ( V_122 -> V_7 . V_20 & V_237 ) ) {
if ( ! V_5 ) {
* V_60 = V_236 - V_122 -> V_7 . V_238 ;
} else {
* V_60 = V_236 ;
}
* V_235 = ( ( * V_60 - V_220 ) & ~ 7 )
+ V_220 - sizeof( struct V_146 ) ;
}
}
static int F_158 ( struct V_2 * V_3 , struct V_239 * V_240 ,
struct V_241 * V_242 , struct V_243 * V_244 ,
struct V_37 * V_122 , struct V_45 * V_46 )
{
struct V_51 * V_52 = F_37 ( V_3 ) ;
unsigned int V_60 ;
struct V_48 * V_49 = V_244 -> V_49 ;
if ( V_49 ) {
if ( F_159 ( V_242 -> V_49 ) )
return - V_40 ;
V_242 -> V_49 = F_160 ( V_49 -> V_245 , V_3 -> V_246 ) ;
if ( F_22 ( ! V_242 -> V_49 ) )
return - V_65 ;
V_242 -> V_49 -> V_245 = V_49 -> V_245 ;
V_242 -> V_49 -> V_63 = V_49 -> V_63 ;
V_242 -> V_49 -> V_62 = V_49 -> V_62 ;
V_242 -> V_49 -> V_247 = F_155 ( V_49 -> V_247 ,
V_3 -> V_246 ) ;
if ( V_49 -> V_247 && ! V_242 -> V_49 -> V_247 )
return - V_65 ;
V_242 -> V_49 -> V_248 = F_155 ( V_49 -> V_248 ,
V_3 -> V_246 ) ;
if ( V_49 -> V_248 && ! V_242 -> V_49 -> V_248 )
return - V_65 ;
V_242 -> V_49 -> V_249 = F_155 ( V_49 -> V_249 ,
V_3 -> V_246 ) ;
if ( V_49 -> V_249 && ! V_242 -> V_49 -> V_249 )
return - V_65 ;
V_242 -> V_49 -> V_118 = F_156 ( V_49 -> V_118 ,
V_3 -> V_246 ) ;
if ( V_49 -> V_118 && ! V_242 -> V_49 -> V_118 )
return - V_65 ;
}
F_115 ( & V_122 -> V_7 ) ;
V_240 -> V_250 . V_7 = & V_122 -> V_7 ;
V_240 -> V_251 . V_252 . V_253 = * V_46 ;
V_242 -> V_29 = V_244 -> V_59 ;
V_242 -> V_50 = V_244 -> V_50 ;
if ( V_122 -> V_7 . V_20 & V_237 )
V_60 = V_52 -> V_254 >= V_255 ?
V_122 -> V_7 . V_9 -> V_60 : F_50 ( & V_122 -> V_7 ) ;
else
V_60 = V_52 -> V_254 >= V_255 ?
V_122 -> V_7 . V_9 -> V_60 : F_50 ( V_122 -> V_7 . V_256 ) ;
if ( V_52 -> V_157 < V_60 ) {
if ( V_52 -> V_157 )
V_60 = V_52 -> V_157 ;
}
V_240 -> V_250 . V_257 = V_60 ;
if ( F_31 ( V_122 -> V_7 . V_256 ) )
V_240 -> V_250 . V_20 |= V_258 ;
V_240 -> V_250 . V_218 = 0 ;
return 0 ;
}
static int F_161 ( struct V_2 * V_3 ,
struct V_45 * V_46 ,
struct V_215 * V_216 ,
struct V_259 * V_240 ,
struct V_241 * V_242 ,
struct V_260 * V_261 ,
int F_149 ( void * V_142 , char * V_141 , int V_87 ,
int V_32 , int V_217 , struct V_4 * V_5 ) ,
void * V_142 , int V_218 , int V_222 ,
unsigned int V_20 , struct V_243 * V_244 ,
const struct V_262 * V_263 )
{
struct V_4 * V_5 , * V_264 = NULL ;
unsigned int V_235 , V_220 , V_60 , V_236 ;
int V_221 = 0 ;
int V_265 = 0 ;
int V_219 ;
int V_266 ;
int V_154 ;
int V_87 = 0 ;
T_7 V_267 = 0 ;
T_3 V_268 = 0 ;
struct V_37 * V_122 = (struct V_37 * ) V_240 -> V_7 ;
struct V_48 * V_49 = V_242 -> V_49 ;
int V_269 = V_175 ;
unsigned int V_270 , V_271 ;
V_5 = F_150 ( V_216 ) ;
if ( ! V_5 ) {
V_221 = V_49 ? V_49 -> V_63 : 0 ;
V_265 = V_122 -> V_7 . V_238 - V_122 -> V_272 ;
}
V_60 = V_240 -> V_257 ;
V_236 = V_60 ;
V_219 = F_38 ( V_122 -> V_7 . V_9 ) ;
V_220 = sizeof( struct V_54 ) + V_122 -> V_272 +
( V_49 ? V_49 -> V_62 : 0 ) ;
V_235 = ( ( V_60 - V_220 ) & ~ 7 ) + V_220 -
sizeof( struct V_146 ) ;
V_271 = sizeof( struct V_54 ) +
( V_49 ? V_49 -> V_63 + V_49 -> V_62 : 0 ) +
( F_31 ( & V_122 -> V_7 ) ?
sizeof( struct V_146 ) : 0 ) +
V_122 -> V_272 ;
if ( V_240 -> V_218 + V_218 > V_60 - V_271 && V_244 -> V_273 &&
( V_3 -> V_274 == V_275 ||
V_3 -> V_274 == V_276 ) ) {
F_162 ( V_3 , V_46 , V_60 - V_271 +
sizeof( struct V_54 ) ) ;
goto V_277;
}
if ( F_163 ( V_3 ) )
V_270 = sizeof( struct V_54 ) + V_278 ;
else
V_270 = V_60 ;
if ( V_240 -> V_218 + V_218 > V_270 - V_271 ) {
V_277:
F_52 ( V_3 , V_76 , V_46 ,
V_60 - V_271 +
sizeof( struct V_54 ) ) ;
return - V_76 ;
}
if ( V_222 && V_3 -> V_274 == V_275 &&
V_271 == sizeof( struct V_54 ) &&
V_218 <= V_60 - V_271 &&
! ( V_20 & V_279 ) &&
V_122 -> V_7 . V_9 -> V_280 & ( V_281 | V_282 ) )
V_269 = V_159 ;
if ( V_3 -> V_283 == V_284 || V_3 -> V_283 == V_285 ) {
F_164 ( V_3 , V_263 -> V_286 , & V_267 ) ;
if ( V_267 & V_287 &&
V_3 -> V_288 & V_289 )
V_268 = V_3 -> V_290 ++ ;
}
V_240 -> V_218 += V_218 ;
if ( ( ( ( V_218 + V_220 ) > V_60 ) ||
( V_5 && F_30 ( V_5 ) ) ) &&
( V_3 -> V_274 == V_275 ) &&
( V_122 -> V_7 . V_9 -> V_280 & V_291 ) && ! V_122 -> V_7 . V_238 &&
( V_3 -> V_283 == V_284 ) && ! F_165 ( V_3 ) ) {
V_154 = F_148 ( V_3 , V_216 , F_149 , V_142 , V_218 ,
V_219 , V_220 , V_221 ,
V_222 , V_60 , V_20 , V_46 ) ;
if ( V_154 )
goto error;
return 0 ;
}
if ( ! V_5 )
goto V_292;
while ( V_218 > 0 ) {
V_266 = ( V_240 -> V_218 <= V_60 && ! ( V_240 -> V_20 & V_258 ) ? V_60 : V_235 ) - V_5 -> V_32 ;
if ( V_266 < V_218 )
V_266 = V_235 - V_5 -> V_32 ;
if ( V_266 <= 0 ) {
char * V_91 ;
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
F_157 ( & V_60 , & V_235 ,
V_220 , V_5 , V_122 ,
V_236 ) ;
V_264 = V_5 ;
V_293 = V_218 + V_295 ;
if ( V_293 > ( V_240 -> V_218 <= V_60 && ! ( V_240 -> V_20 & V_258 ) ? V_60 : V_235 ) - V_220 )
V_293 = V_235 - V_220 - V_122 -> V_7 . V_297 ;
if ( ( V_20 & V_279 ) &&
! ( V_122 -> V_7 . V_9 -> V_280 & V_298 ) )
V_296 = V_60 ;
else
V_296 = V_293 + V_220 ;
V_296 += V_265 ;
if ( V_293 != V_218 + V_295 ) {
V_293 += V_122 -> V_7 . V_297 ;
}
V_296 += V_122 -> V_7 . V_297 ;
V_294 = V_293 + V_220 ;
V_296 += sizeof( struct V_146 ) ;
if ( V_222 ) {
V_5 = F_151 ( V_3 ,
V_296 + V_219 ,
( V_20 & V_223 ) , & V_154 ) ;
} else {
V_5 = NULL ;
if ( F_166 ( & V_3 -> V_299 ) <=
2 * V_3 -> V_300 )
V_5 = F_167 ( V_3 ,
V_296 + V_219 , 1 ,
V_3 -> V_246 ) ;
if ( F_22 ( ! V_5 ) )
V_154 = - V_65 ;
}
if ( ! V_5 )
goto error;
V_5 -> V_15 = F_3 ( V_16 ) ;
V_5 -> V_158 = V_269 ;
V_5 -> V_224 = 0 ;
F_121 ( V_5 , V_219 + sizeof( struct V_146 ) +
V_265 ) ;
F_110 ( V_5 ) -> V_267 = V_267 ;
V_267 = 0 ;
F_110 ( V_5 ) -> V_268 = V_268 ;
V_268 = 0 ;
V_91 = F_122 ( V_5 , V_294 ) ;
F_152 ( V_5 , V_221 ) ;
V_91 += V_220 ;
V_5 -> V_179 = ( V_5 -> V_180 +
V_220 ) ;
if ( V_295 ) {
V_5 -> V_224 = F_168 (
V_264 , V_235 ,
V_91 + V_222 , V_295 , 0 ) ;
V_264 -> V_224 = F_169 ( V_264 -> V_224 ,
V_5 -> V_224 ) ;
V_91 += V_295 ;
F_170 ( V_264 , V_235 ) ;
}
V_266 = V_293 - V_222 - V_295 ;
if ( V_266 < 0 ) {
V_154 = - V_40 ;
F_14 ( V_5 ) ;
goto error;
} else if ( V_266 > 0 && F_149 ( V_142 , V_91 + V_222 , V_87 , V_266 , V_295 , V_5 ) < 0 ) {
V_154 = - V_301 ;
F_14 ( V_5 ) ;
goto error;
}
V_87 += V_266 ;
V_218 -= V_293 - V_295 ;
V_222 = 0 ;
V_221 = 0 ;
V_265 = 0 ;
F_153 ( V_216 , V_5 ) ;
continue;
}
if ( V_266 > V_218 )
V_266 = V_218 ;
if ( ! ( V_122 -> V_7 . V_9 -> V_280 & V_298 ) ) {
unsigned int V_302 ;
V_302 = V_5 -> V_32 ;
if ( F_149 ( V_142 , F_122 ( V_5 , V_266 ) ,
V_87 , V_266 , V_302 , V_5 ) < 0 ) {
F_171 ( V_5 , V_302 ) ;
V_154 = - V_301 ;
goto error;
}
} else {
int V_303 = F_110 ( V_5 ) -> V_304 ;
V_154 = - V_169 ;
if ( ! F_172 ( V_3 , V_261 ) )
goto error;
if ( ! F_173 ( V_5 , V_303 , V_261 -> V_305 ,
V_261 -> V_87 ) ) {
V_154 = - V_76 ;
if ( V_303 == V_306 )
goto error;
F_174 ( V_5 , V_303 , V_261 -> V_305 ,
V_261 -> V_87 , 0 ) ;
F_110 ( V_5 ) -> V_304 = ++ V_303 ;
F_175 ( V_261 -> V_305 ) ;
}
V_266 = F_176 ( int , V_266 , V_261 -> V_307 - V_261 -> V_87 ) ;
if ( F_149 ( V_142 ,
F_177 ( V_261 -> V_305 ) + V_261 -> V_87 ,
V_87 , V_266 , V_5 -> V_32 , V_5 ) < 0 )
goto V_308;
V_261 -> V_87 += V_266 ;
F_178 ( & F_110 ( V_5 ) -> V_309 [ V_303 - 1 ] , V_266 ) ;
V_5 -> V_32 += V_266 ;
V_5 -> V_174 += V_266 ;
V_5 -> V_167 += V_266 ;
F_179 ( V_266 , & V_3 -> V_299 ) ;
}
V_87 += V_266 ;
V_218 -= V_266 ;
}
return 0 ;
V_308:
V_154 = - V_301 ;
error:
V_240 -> V_218 -= V_218 ;
F_13 ( F_36 ( V_3 ) , V_122 -> V_310 , V_30 ) ;
return V_154 ;
}
int F_180 ( struct V_2 * V_3 ,
int F_149 ( void * V_142 , char * V_141 , int V_87 , int V_32 ,
int V_217 , struct V_4 * V_5 ) ,
void * V_142 , int V_218 , int V_222 ,
struct V_243 * V_244 , struct V_45 * V_46 ,
struct V_37 * V_122 , unsigned int V_20 ,
const struct V_262 * V_263 )
{
struct V_311 * V_312 = F_181 ( V_3 ) ;
struct V_51 * V_52 = F_37 ( V_3 ) ;
int V_221 ;
int V_154 ;
if ( V_20 & V_313 )
return 0 ;
if ( F_182 ( & V_3 -> V_314 ) ) {
V_154 = F_158 ( V_3 , & V_312 -> V_240 , & V_52 -> V_240 ,
V_244 , V_122 , V_46 ) ;
if ( V_154 )
return V_154 ;
V_221 = ( V_244 -> V_49 ? V_244 -> V_49 -> V_63 : 0 ) ;
V_218 += V_221 ;
V_222 += V_221 ;
} else {
V_46 = & V_312 -> V_240 . V_251 . V_252 . V_253 ;
V_222 = 0 ;
}
return F_161 ( V_3 , V_46 , & V_3 -> V_314 , & V_312 -> V_240 . V_250 ,
& V_52 -> V_240 , F_183 ( V_3 ) , F_149 ,
V_142 , V_218 , V_222 , V_20 , V_244 , V_263 ) ;
}
static void F_184 ( struct V_239 * V_240 ,
struct V_241 * V_242 )
{
if ( V_242 -> V_49 ) {
F_117 ( V_242 -> V_49 -> V_247 ) ;
F_117 ( V_242 -> V_49 -> V_248 ) ;
F_117 ( V_242 -> V_49 -> V_249 ) ;
F_117 ( V_242 -> V_49 -> V_118 ) ;
F_117 ( V_242 -> V_49 ) ;
V_242 -> V_49 = NULL ;
}
if ( V_240 -> V_250 . V_7 ) {
F_130 ( V_240 -> V_250 . V_7 ) ;
V_240 -> V_250 . V_7 = NULL ;
V_240 -> V_250 . V_20 &= ~ V_258 ;
}
memset ( & V_240 -> V_251 , 0 , sizeof( V_240 -> V_251 ) ) ;
}
struct V_4 * F_185 ( struct V_2 * V_3 ,
struct V_215 * V_216 ,
struct V_239 * V_240 ,
struct V_241 * V_242 )
{
struct V_4 * V_5 , * V_315 ;
struct V_4 * * V_316 ;
struct V_12 V_317 , * V_213 = & V_317 ;
struct V_51 * V_52 = F_37 ( V_3 ) ;
struct V_1 * V_1 = F_36 ( V_3 ) ;
struct V_54 * V_55 ;
struct V_48 * V_49 = V_242 -> V_49 ;
struct V_37 * V_122 = (struct V_37 * ) V_240 -> V_250 . V_7 ;
struct V_45 * V_46 = & V_240 -> V_251 . V_252 . V_253 ;
unsigned char V_56 = V_46 -> V_57 ;
V_5 = F_186 ( V_216 ) ;
if ( ! V_5 )
goto V_188;
V_316 = & ( F_110 ( V_5 ) -> V_170 ) ;
if ( V_5 -> V_91 < F_61 ( V_5 ) )
F_112 ( V_5 , F_187 ( V_5 ) ) ;
while ( ( V_315 = F_186 ( V_216 ) ) != NULL ) {
F_112 ( V_315 , F_188 ( V_5 ) ) ;
* V_316 = V_315 ;
V_316 = & ( V_315 -> V_83 ) ;
V_5 -> V_32 += V_315 -> V_32 ;
V_5 -> V_174 += V_315 -> V_32 ;
V_5 -> V_167 += V_315 -> V_167 ;
V_315 -> V_165 = NULL ;
V_315 -> V_3 = NULL ;
}
V_5 -> V_72 = F_163 ( V_3 ) ;
* V_213 = V_46 -> V_17 ;
F_112 ( V_5 , F_188 ( V_5 ) ) ;
if ( V_49 && V_49 -> V_63 )
F_43 ( V_5 , V_49 , & V_56 ) ;
if ( V_49 && V_49 -> V_62 )
F_44 ( V_5 , V_49 , & V_56 , & V_213 , & V_46 -> V_23 ) ;
F_45 ( V_5 , sizeof( struct V_54 ) ) ;
F_46 ( V_5 ) ;
V_55 = F_5 ( V_5 ) ;
F_48 ( V_55 , V_242 -> V_50 ,
F_49 ( V_1 , V_5 , V_46 -> V_66 ,
V_52 -> V_67 , V_46 ) ) ;
V_55 -> V_29 = V_242 -> V_29 ;
V_55 -> V_69 = V_56 ;
V_55 -> V_23 = V_46 -> V_23 ;
V_55 -> V_17 = * V_213 ;
V_5 -> V_70 = V_3 -> V_71 ;
V_5 -> V_47 = V_3 -> V_318 ;
F_93 ( V_5 , F_94 ( & V_122 -> V_7 ) ) ;
F_15 ( V_1 , V_122 -> V_310 , V_73 , V_5 -> V_32 ) ;
if ( V_56 == V_88 ) {
struct V_18 * V_19 = F_6 ( F_2 ( V_5 ) ) ;
F_189 ( V_1 , V_19 , F_190 ( V_5 ) -> V_92 ) ;
F_191 ( V_1 , V_19 , V_319 ) ;
}
F_184 ( V_240 , V_242 ) ;
V_188:
return V_5 ;
}
int F_192 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_36 ( V_5 -> V_3 ) ;
struct V_37 * V_122 = (struct V_37 * ) F_2 ( V_5 ) ;
int V_154 ;
V_154 = F_193 ( V_1 , V_5 -> V_3 , V_5 ) ;
if ( V_154 ) {
if ( V_154 > 0 )
V_154 = F_194 ( V_154 ) ;
if ( V_154 )
F_13 ( V_1 , V_122 -> V_310 ,
V_30 ) ;
}
return V_154 ;
}
int F_195 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_196 ( V_3 ) ;
if ( ! V_5 )
return 0 ;
return F_192 ( V_5 ) ;
}
static void F_197 ( struct V_2 * V_3 ,
struct V_215 * V_216 ,
struct V_239 * V_240 ,
struct V_241 * V_242 )
{
struct V_4 * V_5 ;
while ( ( V_5 = F_198 ( V_216 ) ) != NULL ) {
if ( F_2 ( V_5 ) )
F_13 ( F_36 ( V_3 ) , F_6 ( F_2 ( V_5 ) ) ,
V_30 ) ;
F_14 ( V_5 ) ;
}
F_184 ( V_240 , V_242 ) ;
}
void F_199 ( struct V_2 * V_3 )
{
F_197 ( V_3 , & V_3 -> V_314 ,
& F_181 ( V_3 ) -> V_240 , & F_37 ( V_3 ) -> V_240 ) ;
}
struct V_4 * F_200 ( struct V_2 * V_3 ,
int F_149 ( void * V_142 , char * V_141 , int V_87 ,
int V_32 , int V_217 , struct V_4 * V_5 ) ,
void * V_142 , int V_218 , int V_222 ,
struct V_243 * V_244 , struct V_45 * V_46 ,
struct V_37 * V_122 , unsigned int V_20 ,
const struct V_262 * V_263 )
{
struct V_239 V_240 ;
struct V_241 V_242 ;
struct V_215 V_216 ;
int V_221 = ( V_244 -> V_49 ? V_244 -> V_49 -> V_63 : 0 ) ;
int V_154 ;
if ( V_20 & V_313 )
return NULL ;
F_201 ( & V_216 ) ;
V_240 . V_250 . V_20 = 0 ;
V_240 . V_250 . V_187 = 0 ;
V_240 . V_250 . V_49 = NULL ;
V_242 . V_49 = NULL ;
V_154 = F_158 ( V_3 , & V_240 , & V_242 , V_244 , V_122 , V_46 ) ;
if ( V_154 )
return F_143 ( V_154 ) ;
if ( V_244 -> V_273 < 0 )
V_244 -> V_273 = F_37 ( V_3 ) -> V_273 ;
V_154 = F_161 ( V_3 , V_46 , & V_216 , & V_240 . V_250 , & V_242 ,
& V_320 -> V_321 , F_149 , V_142 ,
V_218 + V_221 , V_222 + V_221 ,
V_20 , V_244 , V_263 ) ;
if ( V_154 ) {
F_197 ( V_3 , & V_216 , & V_240 , & V_242 ) ;
return F_143 ( V_154 ) ;
}
return F_185 ( V_3 , & V_216 , & V_240 , & V_242 ) ;
}
