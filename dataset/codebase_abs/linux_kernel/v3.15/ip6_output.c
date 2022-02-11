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
F_46 ( V_51 , V_45 , V_42 -> V_62 ) ;
V_51 -> V_63 = F_3 ( V_54 ) ;
V_51 -> V_64 = V_52 ;
V_51 -> V_27 = V_55 ;
V_51 -> V_21 = V_42 -> V_21 ;
V_51 -> V_14 = * V_49 ;
V_2 -> V_12 = F_3 ( V_13 ) ;
V_2 -> V_65 = V_19 -> V_66 ;
V_2 -> V_67 = V_19 -> V_68 ;
V_56 = F_47 ( V_4 ) ;
if ( ( V_2 -> V_30 <= V_56 ) || V_2 -> V_69 || F_28 ( V_2 ) ) {
F_16 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_70 , V_2 -> V_30 ) ;
return F_13 ( V_24 , V_71 , V_2 , NULL ,
V_4 -> V_6 , V_72 ) ;
}
V_2 -> V_6 = V_4 -> V_6 ;
F_48 ( V_19 , V_73 , V_42 , V_56 ) ;
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) , V_74 ) ;
F_15 ( V_2 ) ;
return - V_73 ;
}
static int F_49 ( struct V_1 * V_2 , int V_75 )
{
struct V_76 * V_77 ;
struct V_37 * V_78 = NULL ;
F_50 ( & V_79 ) ;
for ( V_77 = V_76 ; V_77 ; V_77 = V_77 -> V_80 ) {
struct V_37 * V_19 = V_77 -> V_19 ;
if ( V_19 && V_77 -> V_75 == V_75 &&
( ! V_19 -> V_81 ||
V_19 -> V_81 == V_2 -> V_6 -> V_82 ) ) {
if ( V_78 ) {
struct V_1 * V_60 = F_12 ( V_2 , V_23 ) ;
if ( V_60 )
F_51 ( V_78 , V_60 ) ;
}
V_78 = V_19 ;
}
}
if ( V_78 ) {
F_51 ( V_78 , V_2 ) ;
F_52 ( & V_79 ) ;
return 1 ;
}
F_52 ( & V_79 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_5 ( V_2 ) ;
T_1 V_64 = V_51 -> V_64 ;
T_3 V_83 ;
int V_84 ;
if ( F_54 ( V_64 ) ) {
V_84 = F_55 ( V_2 , sizeof( * V_51 ) , & V_64 , & V_83 ) ;
if ( V_84 < 0 )
return 0 ;
} else
V_84 = sizeof( struct V_50 ) ;
if ( V_64 == V_85 ) {
struct V_86 * V_87 ;
if ( ! F_56 ( V_2 , ( F_57 ( V_2 ) +
V_84 + 1 - V_2 -> V_88 ) ) )
return 0 ;
V_87 = (struct V_86 * ) ( F_57 ( V_2 ) + V_84 ) ;
switch ( V_87 -> V_89 ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
return 1 ;
default:
break;
}
}
if ( F_58 ( & V_51 -> V_14 ) & V_95 ) {
F_59 ( V_2 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_60 ( struct V_1 * V_2 )
{
return V_72 ( V_2 ) ;
}
static unsigned int F_61 ( const struct V_3 * V_4 )
{
unsigned int V_56 ;
struct V_15 * V_16 ;
if ( F_62 ( V_4 , V_96 ) ) {
V_56 = F_63 ( V_4 , V_96 ) ;
if ( V_56 )
return V_56 ;
}
V_56 = V_97 ;
F_64 () ;
V_16 = F_65 ( V_4 -> V_6 ) ;
if ( V_16 )
V_56 = V_16 -> V_38 . V_98 ;
F_66 () ;
return V_56 ;
}
static bool F_67 ( const struct V_1 * V_2 , unsigned int V_56 )
{
if ( V_2 -> V_30 <= V_56 )
return false ;
if ( F_10 ( V_2 ) -> V_36 && F_10 ( V_2 ) -> V_36 > V_56 )
return true ;
if ( V_2 -> V_69 )
return false ;
if ( F_28 ( V_2 ) && F_68 ( V_2 ) <= V_56 )
return false ;
return true ;
}
int F_69 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_50 * V_51 = F_5 ( V_2 ) ;
struct V_99 * V_44 = F_10 ( V_2 ) ;
struct V_46 * V_46 = F_9 ( V_4 -> V_6 ) ;
T_2 V_56 ;
if ( V_46 -> V_100 . V_101 -> V_102 == 0 )
goto error;
if ( V_2 -> V_103 != V_104 )
goto V_105;
if ( F_70 ( V_2 ) )
goto V_105;
if ( ! F_71 ( NULL , V_106 , V_2 ) ) {
F_72 ( V_46 , F_6 ( V_4 ) ,
V_107 ) ;
goto V_105;
}
F_73 ( V_2 ) ;
if ( F_21 ( V_44 -> V_17 & V_108 ) ) {
if ( F_49 ( V_2 , F_74 ( V_44 -> V_77 ) ) )
return 0 ;
}
if ( V_51 -> V_27 <= 1 ) {
V_2 -> V_6 = V_4 -> V_6 ;
F_75 ( V_2 , V_109 , V_110 , 0 ) ;
F_72 ( V_46 , F_6 ( V_4 ) ,
V_111 ) ;
F_15 ( V_2 ) ;
return - V_112 ;
}
if ( V_46 -> V_100 . V_101 -> V_113 &&
F_76 ( & V_33 , V_46 , & V_51 -> V_14 , V_2 -> V_6 , 0 ) ) {
int V_114 = F_53 ( V_2 ) ;
if ( V_114 > 0 )
return F_77 ( V_2 ) ;
else if ( V_114 < 0 ) {
F_72 ( V_46 , F_6 ( V_4 ) ,
V_107 ) ;
goto V_105;
}
}
if ( ! F_78 ( V_2 ) ) {
F_72 ( V_46 , F_6 ( V_4 ) ,
V_107 ) ;
goto V_105;
}
V_4 = F_2 ( V_2 ) ;
if ( V_2 -> V_6 == V_4 -> V_6 && V_44 -> V_115 == 0 && ! F_79 ( V_2 ) ) {
struct V_9 * V_116 = NULL ;
struct V_117 * V_118 ;
struct V_32 * V_119 ;
V_119 = (struct V_32 * ) V_4 ;
if ( V_119 -> V_120 & V_121 )
V_116 = & V_119 -> V_122 ;
else
V_116 = & V_51 -> V_14 ;
V_118 = F_80 ( V_46 -> V_100 . V_123 , & V_119 -> V_124 . V_125 , 1 ) ;
if ( F_81 ( V_118 , 1 * V_126 ) )
F_82 ( V_2 , V_116 ) ;
if ( V_118 )
F_83 ( V_118 ) ;
} else {
int V_127 = F_58 ( & V_51 -> V_21 ) ;
if ( V_127 == V_128 ||
V_127 & ( V_129 | V_130 ) )
goto error;
if ( V_127 & V_95 ) {
F_75 ( V_2 , V_131 ,
V_132 , 0 ) ;
goto error;
}
}
V_56 = F_61 ( V_4 ) ;
if ( V_56 < V_97 )
V_56 = V_97 ;
if ( F_67 ( V_2 , V_56 ) ) {
V_2 -> V_6 = V_4 -> V_6 ;
F_75 ( V_2 , V_133 , 0 , V_56 ) ;
F_72 ( V_46 , F_6 ( V_4 ) ,
V_134 ) ;
F_72 ( V_46 , F_6 ( V_4 ) ,
V_74 ) ;
F_15 ( V_2 ) ;
return - V_73 ;
}
if ( F_84 ( V_2 , V_4 -> V_6 -> V_135 ) ) {
F_72 ( V_46 , F_6 ( V_4 ) ,
V_28 ) ;
goto V_105;
}
V_51 = F_5 ( V_2 ) ;
V_51 -> V_27 -- ;
F_72 ( V_46 , F_6 ( V_4 ) , V_136 ) ;
F_85 ( V_46 , F_6 ( V_4 ) , V_137 , V_2 -> V_30 ) ;
return F_13 ( V_24 , V_138 , V_2 , V_2 -> V_6 , V_4 -> V_6 ,
F_60 ) ;
error:
F_72 ( V_46 , F_6 ( V_4 ) , V_139 ) ;
V_105:
F_15 ( V_2 ) ;
return - V_35 ;
}
static void F_86 ( struct V_1 * V_140 , struct V_1 * V_141 )
{
V_140 -> V_103 = V_141 -> V_103 ;
V_140 -> V_65 = V_141 -> V_65 ;
V_140 -> V_12 = V_141 -> V_12 ;
F_87 ( V_140 ) ;
F_88 ( V_140 , F_89 ( F_2 ( V_141 ) ) ) ;
V_140 -> V_6 = V_141 -> V_6 ;
V_140 -> V_67 = V_141 -> V_67 ;
#ifdef F_90
V_140 -> V_142 = V_141 -> V_142 ;
#endif
F_91 ( V_140 , V_141 ) ;
F_92 ( V_140 , V_141 ) ;
}
int F_30 ( struct V_1 * V_2 , int (* F_93)( struct V_1 * ) )
{
struct V_1 * V_143 ;
struct V_32 * V_119 = (struct V_32 * ) F_2 ( V_2 ) ;
struct V_47 * V_48 = V_2 -> V_19 ? F_35 ( V_2 -> V_19 ) : NULL ;
struct V_50 * V_144 ;
struct V_145 * V_146 ;
unsigned int V_56 , V_147 , V_148 , V_30 ;
int V_149 , V_150 ;
T_4 V_151 = 0 ;
int V_152 , V_84 = 0 , V_153 = 0 ;
T_1 * V_154 , V_64 = 0 ;
struct V_46 * V_46 = F_9 ( F_2 ( V_2 ) -> V_6 ) ;
V_147 = F_94 ( V_2 , & V_154 ) ;
V_64 = * V_154 ;
V_56 = F_27 ( V_2 ) ;
if ( F_21 ( ! V_2 -> V_69 && V_2 -> V_30 > V_56 ) ||
( F_10 ( V_2 ) -> V_36 &&
F_10 ( V_2 ) -> V_36 > V_56 ) ) {
if ( V_2 -> V_19 && F_29 ( F_2 ( V_2 ) ) )
F_95 ( V_2 -> V_19 , V_155 ) ;
V_2 -> V_6 = F_2 ( V_2 ) -> V_6 ;
F_75 ( V_2 , V_133 , 0 , V_56 ) ;
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_74 ) ;
F_15 ( V_2 ) ;
return - V_73 ;
}
if ( V_48 && V_48 -> V_156 < V_56 ) {
if ( V_48 -> V_156 )
V_56 = V_48 -> V_156 ;
}
V_56 -= V_147 + sizeof( struct V_145 ) ;
if ( F_96 ( V_2 ) ) {
int V_157 = F_97 ( V_2 ) ;
struct V_1 * V_158 ;
if ( V_157 - V_147 > V_56 ||
( ( V_157 - V_147 ) & 7 ) ||
F_98 ( V_2 ) )
goto V_159;
F_99 (skb, frag) {
if ( V_143 -> V_30 > V_56 ||
( ( V_143 -> V_30 & 7 ) && V_143 -> V_80 ) ||
F_37 ( V_143 ) < V_147 )
goto V_160;
if ( F_100 ( V_143 ) )
goto V_160;
F_101 ( V_143 -> V_19 ) ;
if ( V_2 -> V_19 ) {
V_143 -> V_19 = V_2 -> V_19 ;
V_143 -> V_161 = V_162 ;
}
V_2 -> V_163 -= V_143 -> V_163 ;
}
V_153 = 0 ;
V_84 = 0 ;
V_143 = F_102 ( V_2 ) -> V_164 ;
F_103 ( V_2 ) ;
* V_154 = V_165 ;
V_144 = F_104 ( F_57 ( V_2 ) , V_147 , V_23 ) ;
if ( ! V_144 ) {
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_74 ) ;
return - V_166 ;
}
F_105 ( V_2 , V_147 ) ;
V_146 = (struct V_145 * ) F_106 ( V_2 , sizeof( struct V_145 ) ) ;
F_106 ( V_2 , V_147 ) ;
F_44 ( V_2 ) ;
memcpy ( F_57 ( V_2 ) , V_144 , V_147 ) ;
F_107 ( V_146 , V_119 ) ;
V_146 -> V_64 = V_64 ;
V_146 -> V_167 = 0 ;
V_146 -> V_83 = F_3 ( V_168 ) ;
V_151 = V_146 -> V_169 ;
V_157 = F_97 ( V_2 ) ;
V_2 -> V_170 = V_157 - F_108 ( V_2 ) ;
V_2 -> V_30 = V_157 ;
F_5 ( V_2 ) -> V_63 = F_3 ( V_157 -
sizeof( struct V_50 ) ) ;
F_109 ( & V_119 -> V_4 ) ;
for (; ; ) {
if ( V_143 ) {
V_143 -> V_171 = V_172 ;
F_110 ( V_143 ) ;
V_146 = (struct V_145 * ) F_106 ( V_143 , sizeof( struct V_145 ) ) ;
F_106 ( V_143 , V_147 ) ;
F_44 ( V_143 ) ;
memcpy ( F_57 ( V_143 ) , V_144 ,
V_147 ) ;
V_84 += V_2 -> V_30 - V_147 - sizeof( struct V_145 ) ;
V_146 -> V_64 = V_64 ;
V_146 -> V_167 = 0 ;
V_146 -> V_83 = F_3 ( V_84 ) ;
if ( V_143 -> V_80 != NULL )
V_146 -> V_83 |= F_3 ( V_168 ) ;
V_146 -> V_169 = V_151 ;
F_5 ( V_143 ) -> V_63 =
F_3 ( V_143 -> V_30 -
sizeof( struct V_50 ) ) ;
F_86 ( V_143 , V_2 ) ;
}
V_153 = F_93 ( V_2 ) ;
if( ! V_153 )
F_14 ( V_46 , F_6 ( & V_119 -> V_4 ) ,
V_173 ) ;
if ( V_153 || ! V_143 )
break;
V_2 = V_143 ;
V_143 = V_2 -> V_80 ;
V_2 -> V_80 = NULL ;
}
F_111 ( V_144 ) ;
if ( V_153 == 0 ) {
F_14 ( V_46 , F_6 ( & V_119 -> V_4 ) ,
V_174 ) ;
F_112 ( V_119 ) ;
return 0 ;
}
while ( V_143 ) {
V_2 = V_143 -> V_80 ;
F_15 ( V_143 ) ;
V_143 = V_2 ;
}
F_14 ( V_46 , F_6 ( & V_119 -> V_4 ) ,
V_74 ) ;
F_112 ( V_119 ) ;
return V_153 ;
V_160:
F_99 (skb, frag2) {
if ( V_158 == V_143 )
break;
V_158 -> V_19 = NULL ;
V_158 -> V_161 = NULL ;
V_2 -> V_163 += V_158 -> V_163 ;
}
}
V_159:
if ( ( V_2 -> V_171 == V_175 ) &&
F_113 ( V_2 ) )
goto V_176;
V_148 = V_2 -> V_30 - V_147 ;
V_152 = V_147 ;
* V_154 = V_165 ;
V_149 = F_36 ( V_119 -> V_4 . V_6 ) ;
V_150 = V_119 -> V_4 . V_6 -> V_177 ;
while( V_148 > 0 ) {
V_30 = V_148 ;
if ( V_30 > V_56 )
V_30 = V_56 ;
if ( V_30 < V_148 ) {
V_30 &= ~ 7 ;
}
if ( ( V_143 = F_114 ( V_30 + V_147 + sizeof( struct V_145 ) +
V_149 + V_150 , V_23 ) ) == NULL ) {
F_115 ( V_178 L_1 ) ;
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_74 ) ;
V_153 = - V_166 ;
goto V_176;
}
F_86 ( V_143 , V_2 ) ;
F_116 ( V_143 , V_149 ) ;
F_117 ( V_143 , V_30 + V_147 + sizeof( struct V_145 ) ) ;
F_44 ( V_143 ) ;
V_146 = (struct V_145 * ) ( F_57 ( V_143 ) + V_147 ) ;
V_143 -> V_179 = ( V_143 -> V_180 + V_147 +
sizeof( struct V_145 ) ) ;
if ( V_2 -> V_19 )
F_40 ( V_143 , V_2 -> V_19 ) ;
F_118 ( V_2 , F_57 ( V_143 ) , V_147 ) ;
V_146 -> V_64 = V_64 ;
V_146 -> V_167 = 0 ;
if ( ! V_151 ) {
F_107 ( V_146 , V_119 ) ;
V_151 = V_146 -> V_169 ;
} else
V_146 -> V_169 = V_151 ;
if ( F_119 ( V_2 , V_152 , F_120 ( V_143 ) , V_30 ) )
F_121 () ;
V_148 -= V_30 ;
V_146 -> V_83 = F_3 ( V_84 ) ;
if ( V_148 > 0 )
V_146 -> V_83 |= F_3 ( V_168 ) ;
F_5 ( V_143 ) -> V_63 = F_3 ( V_143 -> V_30 -
sizeof( struct V_50 ) ) ;
V_152 += V_30 ;
V_84 += V_30 ;
V_153 = F_93 ( V_143 ) ;
if ( V_153 )
goto V_176;
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_173 ) ;
}
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_174 ) ;
F_39 ( V_2 ) ;
return V_153 ;
V_176:
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_74 ) ;
F_15 ( V_2 ) ;
return V_153 ;
}
static inline int F_122 ( const struct V_181 * V_182 ,
const struct V_9 * V_183 ,
const struct V_9 * V_184 )
{
return ( V_182 -> V_185 != 128 || ! F_123 ( V_183 , & V_182 -> V_125 ) ) &&
( V_184 == NULL || ! F_123 ( V_183 , V_184 ) ) ;
}
static struct V_3 * F_124 ( struct V_37 * V_19 ,
struct V_3 * V_4 ,
const struct V_41 * V_42 )
{
struct V_47 * V_48 = F_35 ( V_19 ) ;
struct V_32 * V_119 ;
if ( ! V_4 )
goto V_186;
if ( V_4 -> V_187 -> V_188 != V_189 ) {
F_125 ( V_4 ) ;
return NULL ;
}
V_119 = (struct V_32 * ) V_4 ;
if ( F_122 ( & V_119 -> V_124 , & V_42 -> V_14 , V_48 -> V_190 ) ||
#ifdef F_126
F_122 ( & V_119 -> V_191 , & V_42 -> V_21 , V_48 -> V_192 ) ||
#endif
( V_42 -> V_193 && V_42 -> V_193 != V_4 -> V_6 -> V_82 ) ) {
F_125 ( V_4 ) ;
V_4 = NULL ;
}
V_186:
return V_4 ;
}
static int F_127 ( struct V_37 * V_19 ,
struct V_3 * * V_4 , struct V_41 * V_42 )
{
struct V_46 * V_46 = F_34 ( V_19 ) ;
#ifdef F_128
struct V_7 * V_194 ;
struct V_32 * V_119 ;
#endif
int V_153 ;
if ( * V_4 == NULL )
* V_4 = F_129 ( V_46 , V_19 , V_42 ) ;
if ( ( V_153 = ( * V_4 ) -> error ) )
goto V_195;
if ( F_130 ( & V_42 -> V_21 ) ) {
struct V_32 * V_119 = (struct V_32 * ) * V_4 ;
V_153 = F_131 ( V_46 , V_119 , & V_42 -> V_14 ,
V_19 ? F_35 ( V_19 ) -> V_196 : 0 ,
& V_42 -> V_21 ) ;
if ( V_153 )
goto V_195;
}
#ifdef F_128
V_119 = (struct V_32 * ) * V_4 ;
F_18 () ;
V_194 = F_20 ( V_119 -> V_4 . V_6 , F_19 ( V_119 ) ) ;
V_153 = V_194 && ! ( V_194 -> V_197 & V_198 ) ? - V_35 : 0 ;
F_25 () ;
if ( V_153 ) {
struct V_199 * V_200 ;
struct V_41 V_201 ;
int V_202 ;
V_200 = F_132 ( V_46 , & V_42 -> V_21 ,
( * V_4 ) -> V_6 , 1 ) ;
V_202 = ( V_200 && V_200 -> V_17 & V_203 ) ;
if ( V_200 )
F_133 ( V_200 ) ;
if ( V_202 ) {
F_125 ( * V_4 ) ;
memcpy ( & V_201 , V_42 , sizeof( struct V_41 ) ) ;
memset ( & V_201 . V_14 , 0 , sizeof( struct V_9 ) ) ;
* V_4 = F_129 ( V_46 , V_19 , & V_201 ) ;
if ( ( V_153 = ( * V_4 ) -> error ) )
goto V_195;
}
}
#endif
return 0 ;
V_195:
if ( V_153 == - V_204 )
F_14 ( V_46 , NULL , V_34 ) ;
F_125 ( * V_4 ) ;
* V_4 = NULL ;
return V_153 ;
}
int F_134 ( struct V_37 * V_19 , struct V_3 * * V_4 , struct V_41 * V_42 )
{
* V_4 = NULL ;
return F_127 ( V_19 , V_4 , V_42 ) ;
}
struct V_3 * F_135 ( struct V_37 * V_19 , struct V_41 * V_42 ,
const struct V_9 * V_205 )
{
struct V_3 * V_4 = NULL ;
int V_153 ;
V_153 = F_127 ( V_19 , & V_4 , V_42 ) ;
if ( V_153 )
return F_136 ( V_153 ) ;
if ( V_205 )
V_42 -> V_14 = * V_205 ;
return F_137 ( F_34 ( V_19 ) , V_4 , F_138 ( V_42 ) , V_19 , 0 ) ;
}
struct V_3 * F_139 ( struct V_37 * V_19 , struct V_41 * V_42 ,
const struct V_9 * V_205 )
{
struct V_3 * V_4 = F_140 ( V_19 , F_35 ( V_19 ) -> V_206 ) ;
int V_153 ;
V_4 = F_124 ( V_19 , V_4 , V_42 ) ;
V_153 = F_127 ( V_19 , & V_4 , V_42 ) ;
if ( V_153 )
return F_136 ( V_153 ) ;
if ( V_205 )
V_42 -> V_14 = * V_205 ;
return F_137 ( F_34 ( V_19 ) , V_4 , F_138 ( V_42 ) , V_19 , 0 ) ;
}
static inline int F_141 ( struct V_37 * V_19 ,
int F_142 ( void * V_141 , char * V_140 , int V_84 , int V_30 ,
int V_207 , struct V_1 * V_2 ) ,
void * V_141 , int V_208 , int V_209 , int V_210 ,
int V_211 , int V_56 , unsigned int V_17 ,
struct V_32 * V_119 )
{
struct V_1 * V_2 ;
struct V_145 V_212 ;
int V_153 ;
if ( ( V_2 = F_143 ( & V_19 -> V_213 ) ) == NULL ) {
V_2 = F_144 ( V_19 ,
V_209 + V_210 + V_211 + 20 ,
( V_17 & V_214 ) , & V_153 ) ;
if ( V_2 == NULL )
return V_153 ;
F_116 ( V_2 , V_209 ) ;
F_117 ( V_2 , V_210 + V_211 ) ;
F_44 ( V_2 ) ;
V_2 -> V_179 = V_2 -> V_180 + V_210 ;
V_2 -> V_12 = F_3 ( V_13 ) ;
V_2 -> V_215 = 0 ;
F_145 ( & V_19 -> V_213 , V_2 ) ;
} else if ( F_28 ( V_2 ) ) {
goto V_216;
}
V_2 -> V_171 = V_175 ;
F_102 ( V_2 ) -> V_217 = ( V_56 - V_210 -
sizeof( struct V_145 ) ) & ~ 7 ;
F_102 ( V_2 ) -> V_218 = V_219 ;
F_107 ( & V_212 , V_119 ) ;
F_102 ( V_2 ) -> V_220 = V_212 . V_169 ;
V_216:
return F_146 ( V_19 , V_2 , F_142 , V_141 ,
( V_208 - V_211 ) ) ;
}
static inline struct V_221 * F_147 ( struct V_221 * V_222 ,
T_5 V_223 )
{
return V_222 ? F_104 ( V_222 , ( V_222 -> V_224 + 1 ) * 8 , V_223 ) : NULL ;
}
static inline struct V_225 * F_148 ( struct V_225 * V_222 ,
T_5 V_223 )
{
return V_222 ? F_104 ( V_222 , ( V_222 -> V_224 + 1 ) * 8 , V_223 ) : NULL ;
}
static void F_149 ( unsigned int * V_56 ,
int * V_226 ,
unsigned int V_210 ,
struct V_1 * V_2 ,
struct V_32 * V_119 ,
unsigned int V_227 )
{
if ( ! ( V_119 -> V_4 . V_17 & V_228 ) ) {
if ( V_2 == NULL ) {
* V_56 = V_227 - V_119 -> V_4 . V_229 ;
} else {
* V_56 = V_227 ;
}
* V_226 = ( ( * V_56 - V_210 ) & ~ 7 )
+ V_210 - sizeof( struct V_145 ) ;
}
}
int F_150 ( struct V_37 * V_19 , int F_142 ( void * V_141 , char * V_140 ,
int V_84 , int V_30 , int V_207 , struct V_1 * V_2 ) ,
void * V_141 , int V_208 , int V_211 ,
int V_55 , int V_45 , struct V_43 * V_44 , struct V_41 * V_42 ,
struct V_32 * V_119 , unsigned int V_17 , int V_230 )
{
struct V_231 * V_232 = F_151 ( V_19 ) ;
struct V_47 * V_48 = F_35 ( V_19 ) ;
struct V_233 * V_234 ;
struct V_1 * V_2 , * V_235 = NULL ;
unsigned int V_226 , V_210 , V_56 , V_227 ;
int V_236 ;
int V_237 ;
int V_209 ;
int V_238 ;
int V_153 ;
int V_84 = 0 ;
T_6 V_239 = 0 ;
if ( V_17 & V_240 )
return 0 ;
V_234 = & V_232 -> V_234 . V_241 ;
if ( F_152 ( & V_19 -> V_213 ) ) {
if ( V_44 ) {
if ( F_153 ( V_48 -> V_234 . V_44 ) )
return - V_35 ;
V_48 -> V_234 . V_44 = F_154 ( V_44 -> V_242 , V_19 -> V_243 ) ;
if ( F_21 ( V_48 -> V_234 . V_44 == NULL ) )
return - V_61 ;
V_48 -> V_234 . V_44 -> V_242 = V_44 -> V_242 ;
V_48 -> V_234 . V_44 -> V_59 = V_44 -> V_59 ;
V_48 -> V_234 . V_44 -> V_58 = V_44 -> V_58 ;
V_48 -> V_234 . V_44 -> V_244 = F_147 ( V_44 -> V_244 ,
V_19 -> V_243 ) ;
if ( V_44 -> V_244 && ! V_48 -> V_234 . V_44 -> V_244 )
return - V_61 ;
V_48 -> V_234 . V_44 -> V_245 = F_147 ( V_44 -> V_245 ,
V_19 -> V_243 ) ;
if ( V_44 -> V_245 && ! V_48 -> V_234 . V_44 -> V_245 )
return - V_61 ;
V_48 -> V_234 . V_44 -> V_246 = F_147 ( V_44 -> V_246 ,
V_19 -> V_243 ) ;
if ( V_44 -> V_246 && ! V_48 -> V_234 . V_44 -> V_246 )
return - V_61 ;
V_48 -> V_234 . V_44 -> V_115 = F_148 ( V_44 -> V_115 ,
V_19 -> V_243 ) ;
if ( V_44 -> V_115 && ! V_48 -> V_234 . V_44 -> V_115 )
return - V_61 ;
}
F_109 ( & V_119 -> V_4 ) ;
V_234 -> V_4 = & V_119 -> V_4 ;
V_232 -> V_234 . V_247 . V_248 . V_249 = * V_42 ;
V_48 -> V_234 . V_27 = V_55 ;
V_48 -> V_234 . V_45 = V_45 ;
if ( V_119 -> V_4 . V_17 & V_228 )
V_56 = V_48 -> V_250 >= V_251 ?
V_119 -> V_4 . V_6 -> V_56 : F_47 ( & V_119 -> V_4 ) ;
else
V_56 = V_48 -> V_250 >= V_251 ?
V_119 -> V_4 . V_6 -> V_56 : F_47 ( V_119 -> V_4 . V_252 ) ;
if ( V_48 -> V_156 < V_56 ) {
if ( V_48 -> V_156 )
V_56 = V_48 -> V_156 ;
}
V_234 -> V_253 = V_56 ;
if ( F_29 ( V_119 -> V_4 . V_252 ) )
V_234 -> V_17 |= V_254 ;
V_234 -> V_208 = 0 ;
V_236 = ( V_44 ? V_44 -> V_59 : 0 ) ;
V_208 += V_236 ;
V_211 += V_236 ;
V_237 = V_119 -> V_4 . V_229 - V_119 -> V_255 ;
} else {
V_119 = (struct V_32 * ) V_234 -> V_4 ;
V_42 = & V_232 -> V_234 . V_247 . V_248 . V_249 ;
V_44 = V_48 -> V_234 . V_44 ;
V_211 = 0 ;
V_236 = 0 ;
V_237 = 0 ;
V_56 = V_234 -> V_253 ;
}
V_227 = V_56 ;
V_209 = F_36 ( V_119 -> V_4 . V_6 ) ;
V_210 = sizeof( struct V_50 ) + V_119 -> V_255 +
( V_44 ? V_44 -> V_58 : 0 ) ;
V_226 = ( ( V_56 - V_210 ) & ~ 7 ) + V_210 -
sizeof( struct V_145 ) ;
if ( V_56 <= sizeof( struct V_50 ) + V_256 ) {
unsigned int V_257 , V_258 ;
V_258 = sizeof( struct V_50 ) +
( V_44 ? V_44 -> V_59 + V_44 -> V_58 : 0 ) +
( F_29 ( & V_119 -> V_4 ) ?
sizeof( struct V_145 ) : 0 ) +
V_119 -> V_255 ;
if ( F_155 ( V_19 ) )
V_257 = sizeof( struct V_50 ) + V_256 ;
else
V_257 = V_56 ;
if ( ( V_234 -> V_208 + V_208 > V_56 - V_258 ) && V_230 &&
( V_19 -> V_259 == V_260 ||
V_19 -> V_259 == V_261 ) ) {
F_156 ( V_19 , V_42 , V_56 - V_258 +
sizeof( struct V_50 ) ) ;
goto V_262;
}
if ( V_234 -> V_208 + V_208 > V_257 - V_258 ) {
V_262:
F_48 ( V_19 , V_73 , V_42 ,
V_56 - V_258 +
sizeof( struct V_50 ) ) ;
return - V_73 ;
}
}
if ( V_19 -> V_263 == V_264 )
F_157 ( V_19 , & V_239 ) ;
V_2 = F_143 ( & V_19 -> V_213 ) ;
V_234 -> V_208 += V_208 ;
if ( ( ( V_208 > V_56 ) ||
( V_2 && F_28 ( V_2 ) ) ) &&
( V_19 -> V_259 == V_260 ) &&
( V_119 -> V_4 . V_6 -> V_265 & V_266 ) ) {
V_153 = F_141 ( V_19 , F_142 , V_141 , V_208 ,
V_209 , V_210 ,
V_211 , V_56 , V_17 , V_119 ) ;
if ( V_153 )
goto error;
return 0 ;
}
if ( ! V_2 )
goto V_267;
while ( V_208 > 0 ) {
V_238 = ( V_234 -> V_208 <= V_56 && ! ( V_234 -> V_17 & V_254 ) ? V_56 : V_226 ) - V_2 -> V_30 ;
if ( V_238 < V_208 )
V_238 = V_226 - V_2 -> V_30 ;
if ( V_238 <= 0 ) {
char * V_88 ;
unsigned int V_268 ;
unsigned int V_269 ;
unsigned int V_270 ;
unsigned int V_271 ;
V_267:
if ( V_2 )
V_270 = V_2 -> V_30 - V_226 ;
else
V_270 = 0 ;
if ( V_2 == NULL || V_235 == NULL )
F_149 ( & V_56 , & V_226 ,
V_210 , V_2 , V_119 ,
V_227 ) ;
V_235 = V_2 ;
V_268 = V_208 + V_270 ;
if ( V_268 > ( V_234 -> V_208 <= V_56 && ! ( V_234 -> V_17 & V_254 ) ? V_56 : V_226 ) - V_210 )
V_268 = V_226 - V_210 - V_119 -> V_4 . V_272 ;
if ( ( V_17 & V_273 ) &&
! ( V_119 -> V_4 . V_6 -> V_265 & V_274 ) )
V_271 = V_56 ;
else
V_271 = V_268 + V_210 ;
V_271 += V_237 ;
if ( V_268 != V_208 + V_270 ) {
V_268 += V_119 -> V_4 . V_272 ;
}
V_271 += V_119 -> V_4 . V_272 ;
V_269 = V_268 + V_210 ;
V_271 += sizeof( struct V_145 ) ;
if ( V_211 ) {
V_2 = F_144 ( V_19 ,
V_271 + V_209 ,
( V_17 & V_214 ) , & V_153 ) ;
} else {
V_2 = NULL ;
if ( F_158 ( & V_19 -> V_275 ) <=
2 * V_19 -> V_276 )
V_2 = F_159 ( V_19 ,
V_271 + V_209 , 1 ,
V_19 -> V_243 ) ;
if ( F_21 ( V_2 == NULL ) )
V_153 = - V_61 ;
else {
V_239 = 0 ;
}
}
if ( V_2 == NULL )
goto error;
V_2 -> V_12 = F_3 ( V_13 ) ;
V_2 -> V_171 = V_172 ;
V_2 -> V_215 = 0 ;
F_116 ( V_2 , V_209 + sizeof( struct V_145 ) +
V_237 ) ;
if ( V_19 -> V_263 == V_264 )
F_102 ( V_2 ) -> V_239 = V_239 ;
V_88 = F_117 ( V_2 , V_269 ) ;
F_160 ( V_2 , V_236 ) ;
V_88 += V_210 ;
V_2 -> V_179 = ( V_2 -> V_180 +
V_210 ) ;
if ( V_270 ) {
V_2 -> V_215 = F_161 (
V_235 , V_226 ,
V_88 + V_211 , V_270 , 0 ) ;
V_235 -> V_215 = F_162 ( V_235 -> V_215 ,
V_2 -> V_215 ) ;
V_88 += V_270 ;
F_163 ( V_235 , V_226 ) ;
}
V_238 = V_268 - V_211 - V_270 ;
if ( V_238 < 0 ) {
V_153 = - V_35 ;
F_15 ( V_2 ) ;
goto error;
} else if ( V_238 > 0 && F_142 ( V_141 , V_88 + V_211 , V_84 , V_238 , V_270 , V_2 ) < 0 ) {
V_153 = - V_277 ;
F_15 ( V_2 ) ;
goto error;
}
V_84 += V_238 ;
V_208 -= V_268 - V_270 ;
V_211 = 0 ;
V_236 = 0 ;
V_237 = 0 ;
F_145 ( & V_19 -> V_213 , V_2 ) ;
continue;
}
if ( V_238 > V_208 )
V_238 = V_208 ;
if ( ! ( V_119 -> V_4 . V_6 -> V_265 & V_274 ) ) {
unsigned int V_278 ;
V_278 = V_2 -> V_30 ;
if ( F_142 ( V_141 , F_117 ( V_2 , V_238 ) ,
V_84 , V_238 , V_278 , V_2 ) < 0 ) {
F_164 ( V_2 , V_278 ) ;
V_153 = - V_277 ;
goto error;
}
} else {
int V_279 = F_102 ( V_2 ) -> V_280 ;
struct V_281 * V_282 = F_165 ( V_19 ) ;
V_153 = - V_166 ;
if ( ! F_166 ( V_19 , V_282 ) )
goto error;
if ( ! F_167 ( V_2 , V_279 , V_282 -> V_283 ,
V_282 -> V_84 ) ) {
V_153 = - V_73 ;
if ( V_279 == V_284 )
goto error;
F_168 ( V_2 , V_279 , V_282 -> V_283 ,
V_282 -> V_84 , 0 ) ;
F_102 ( V_2 ) -> V_280 = ++ V_279 ;
F_169 ( V_282 -> V_283 ) ;
}
V_238 = F_170 ( int , V_238 , V_282 -> V_285 - V_282 -> V_84 ) ;
if ( F_142 ( V_141 ,
F_171 ( V_282 -> V_283 ) + V_282 -> V_84 ,
V_84 , V_238 , V_2 -> V_30 , V_2 ) < 0 )
goto V_286;
V_282 -> V_84 += V_238 ;
F_172 ( & F_102 ( V_2 ) -> V_287 [ V_279 - 1 ] , V_238 ) ;
V_2 -> V_30 += V_238 ;
V_2 -> V_170 += V_238 ;
V_2 -> V_163 += V_238 ;
F_173 ( V_238 , & V_19 -> V_275 ) ;
}
V_84 += V_238 ;
V_208 -= V_238 ;
}
return 0 ;
V_286:
V_153 = - V_277 ;
error:
V_234 -> V_208 -= V_208 ;
F_14 ( F_34 ( V_19 ) , V_119 -> V_288 , V_28 ) ;
return V_153 ;
}
static void F_174 ( struct V_231 * V_232 , struct V_47 * V_48 )
{
if ( V_48 -> V_234 . V_44 ) {
F_111 ( V_48 -> V_234 . V_44 -> V_244 ) ;
F_111 ( V_48 -> V_234 . V_44 -> V_245 ) ;
F_111 ( V_48 -> V_234 . V_44 -> V_246 ) ;
F_111 ( V_48 -> V_234 . V_44 -> V_115 ) ;
F_111 ( V_48 -> V_234 . V_44 ) ;
V_48 -> V_234 . V_44 = NULL ;
}
if ( V_232 -> V_234 . V_241 . V_4 ) {
F_125 ( V_232 -> V_234 . V_241 . V_4 ) ;
V_232 -> V_234 . V_241 . V_4 = NULL ;
V_232 -> V_234 . V_241 . V_17 &= ~ V_254 ;
}
memset ( & V_232 -> V_234 . V_247 , 0 , sizeof( V_232 -> V_234 . V_247 ) ) ;
}
int F_175 ( struct V_37 * V_19 )
{
struct V_1 * V_2 , * V_289 ;
struct V_1 * * V_290 ;
struct V_9 V_291 , * V_205 = & V_291 ;
struct V_231 * V_232 = F_151 ( V_19 ) ;
struct V_47 * V_48 = F_35 ( V_19 ) ;
struct V_46 * V_46 = F_34 ( V_19 ) ;
struct V_50 * V_51 ;
struct V_43 * V_44 = V_48 -> V_234 . V_44 ;
struct V_32 * V_119 = (struct V_32 * ) V_232 -> V_234 . V_241 . V_4 ;
struct V_41 * V_42 = & V_232 -> V_234 . V_247 . V_248 . V_249 ;
unsigned char V_52 = V_42 -> V_53 ;
int V_153 = 0 ;
if ( ( V_2 = F_176 ( & V_19 -> V_213 ) ) == NULL )
goto V_186;
V_290 = & ( F_102 ( V_2 ) -> V_164 ) ;
if ( V_2 -> V_88 < F_57 ( V_2 ) )
F_105 ( V_2 , F_177 ( V_2 ) ) ;
while ( ( V_289 = F_176 ( & V_19 -> V_213 ) ) != NULL ) {
F_105 ( V_289 , F_178 ( V_2 ) ) ;
* V_290 = V_289 ;
V_290 = & ( V_289 -> V_80 ) ;
V_2 -> V_30 += V_289 -> V_30 ;
V_2 -> V_170 += V_289 -> V_30 ;
V_2 -> V_163 += V_289 -> V_163 ;
V_289 -> V_161 = NULL ;
V_289 -> V_19 = NULL ;
}
V_2 -> V_69 = F_155 ( V_19 ) ;
* V_205 = V_42 -> V_14 ;
F_105 ( V_2 , F_178 ( V_2 ) ) ;
if ( V_44 && V_44 -> V_59 )
F_41 ( V_2 , V_44 , & V_52 ) ;
if ( V_44 && V_44 -> V_58 )
F_42 ( V_2 , V_44 , & V_52 , & V_205 ) ;
F_43 ( V_2 , sizeof( struct V_50 ) ) ;
F_44 ( V_2 ) ;
V_51 = F_5 ( V_2 ) ;
F_46 ( V_51 , V_48 -> V_234 . V_45 , V_42 -> V_62 ) ;
V_51 -> V_27 = V_48 -> V_234 . V_27 ;
V_51 -> V_64 = V_52 ;
V_51 -> V_21 = V_42 -> V_21 ;
V_51 -> V_14 = * V_205 ;
V_2 -> V_65 = V_19 -> V_66 ;
V_2 -> V_67 = V_19 -> V_68 ;
F_88 ( V_2 , F_89 ( & V_119 -> V_4 ) ) ;
F_16 ( V_46 , V_119 -> V_288 , V_70 , V_2 -> V_30 ) ;
if ( V_52 == V_85 ) {
struct V_15 * V_16 = F_6 ( F_2 ( V_2 ) ) ;
F_179 ( V_46 , V_16 , F_180 ( V_2 ) -> V_89 ) ;
F_181 ( V_46 , V_16 , V_292 ) ;
}
V_153 = F_182 ( V_2 ) ;
if ( V_153 ) {
if ( V_153 > 0 )
V_153 = F_183 ( V_153 ) ;
if ( V_153 )
goto error;
}
V_186:
F_174 ( V_232 , V_48 ) ;
return V_153 ;
error:
F_14 ( V_46 , V_119 -> V_288 , V_28 ) ;
goto V_186;
}
void F_184 ( struct V_37 * V_19 )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_185 ( & V_19 -> V_213 ) ) != NULL ) {
if ( F_2 ( V_2 ) )
F_14 ( F_34 ( V_19 ) , F_6 ( F_2 ( V_2 ) ) ,
V_28 ) ;
F_15 ( V_2 ) ;
}
F_174 ( F_151 ( V_19 ) , F_35 ( V_19 ) ) ;
}
