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
static void F_93 ( struct V_143 * V_144 , struct V_32 * V_119 )
{
static T_2 T_4 V_145 ;
T_2 V_146 , V_147 ;
F_94 ( & T_4 , sizeof( T_4 ) ) ;
V_146 = F_95 ( & V_119 -> V_124 . V_125 , T_4 ) ;
V_146 = F_95 ( & V_119 -> V_148 . V_125 , V_146 ) ;
V_147 = F_96 ( V_146 , 1 ) ;
V_144 -> V_149 = F_97 ( V_147 ) ;
}
int F_30 ( struct V_1 * V_2 , int (* F_98)( struct V_1 * ) )
{
struct V_1 * V_150 ;
struct V_32 * V_119 = (struct V_32 * ) F_2 ( V_2 ) ;
struct V_47 * V_48 = V_2 -> V_19 ? F_35 ( V_2 -> V_19 ) : NULL ;
struct V_50 * V_151 ;
struct V_143 * V_152 ;
unsigned int V_56 , V_153 , V_154 , V_30 ;
int V_155 , V_156 ;
T_5 V_157 = 0 ;
int V_158 , V_84 = 0 , V_159 = 0 ;
T_1 * V_160 , V_64 = 0 ;
struct V_46 * V_46 = F_9 ( F_2 ( V_2 ) -> V_6 ) ;
V_153 = F_99 ( V_2 , & V_160 ) ;
V_64 = * V_160 ;
V_56 = F_27 ( V_2 ) ;
if ( F_21 ( ! V_2 -> V_69 && V_2 -> V_30 > V_56 ) ||
( F_10 ( V_2 ) -> V_36 &&
F_10 ( V_2 ) -> V_36 > V_56 ) ) {
if ( V_2 -> V_19 && F_29 ( F_2 ( V_2 ) ) )
F_100 ( V_2 -> V_19 , V_161 ) ;
V_2 -> V_6 = F_2 ( V_2 ) -> V_6 ;
F_75 ( V_2 , V_133 , 0 , V_56 ) ;
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_74 ) ;
F_15 ( V_2 ) ;
return - V_73 ;
}
if ( V_48 && V_48 -> V_162 < V_56 ) {
if ( V_48 -> V_162 )
V_56 = V_48 -> V_162 ;
}
V_56 -= V_153 + sizeof( struct V_143 ) ;
if ( F_101 ( V_2 ) ) {
int V_163 = F_102 ( V_2 ) ;
struct V_1 * V_164 ;
if ( V_163 - V_153 > V_56 ||
( ( V_163 - V_153 ) & 7 ) ||
F_103 ( V_2 ) )
goto V_165;
F_104 (skb, frag) {
if ( V_150 -> V_30 > V_56 ||
( ( V_150 -> V_30 & 7 ) && V_150 -> V_80 ) ||
F_37 ( V_150 ) < V_153 )
goto V_166;
if ( F_105 ( V_150 ) )
goto V_166;
F_106 ( V_150 -> V_19 ) ;
if ( V_2 -> V_19 ) {
V_150 -> V_19 = V_2 -> V_19 ;
V_150 -> V_167 = V_168 ;
}
V_2 -> V_169 -= V_150 -> V_169 ;
}
V_159 = 0 ;
V_84 = 0 ;
V_150 = F_107 ( V_2 ) -> V_170 ;
F_108 ( V_2 ) ;
* V_160 = V_171 ;
V_151 = F_109 ( F_57 ( V_2 ) , V_153 , V_23 ) ;
if ( ! V_151 ) {
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_74 ) ;
return - V_172 ;
}
F_110 ( V_2 , V_153 ) ;
V_152 = (struct V_143 * ) F_111 ( V_2 , sizeof( struct V_143 ) ) ;
F_111 ( V_2 , V_153 ) ;
F_44 ( V_2 ) ;
memcpy ( F_57 ( V_2 ) , V_151 , V_153 ) ;
F_93 ( V_152 , V_119 ) ;
V_152 -> V_64 = V_64 ;
V_152 -> V_173 = 0 ;
V_152 -> V_83 = F_3 ( V_174 ) ;
V_157 = V_152 -> V_149 ;
V_163 = F_102 ( V_2 ) ;
V_2 -> V_175 = V_163 - F_112 ( V_2 ) ;
V_2 -> V_30 = V_163 ;
F_5 ( V_2 ) -> V_63 = F_3 ( V_163 -
sizeof( struct V_50 ) ) ;
F_113 ( & V_119 -> V_4 ) ;
for (; ; ) {
if ( V_150 ) {
V_150 -> V_176 = V_177 ;
F_114 ( V_150 ) ;
V_152 = (struct V_143 * ) F_111 ( V_150 , sizeof( struct V_143 ) ) ;
F_111 ( V_150 , V_153 ) ;
F_44 ( V_150 ) ;
memcpy ( F_57 ( V_150 ) , V_151 ,
V_153 ) ;
V_84 += V_2 -> V_30 - V_153 - sizeof( struct V_143 ) ;
V_152 -> V_64 = V_64 ;
V_152 -> V_173 = 0 ;
V_152 -> V_83 = F_3 ( V_84 ) ;
if ( V_150 -> V_80 != NULL )
V_152 -> V_83 |= F_3 ( V_174 ) ;
V_152 -> V_149 = V_157 ;
F_5 ( V_150 ) -> V_63 =
F_3 ( V_150 -> V_30 -
sizeof( struct V_50 ) ) ;
F_86 ( V_150 , V_2 ) ;
}
V_159 = F_98 ( V_2 ) ;
if( ! V_159 )
F_14 ( V_46 , F_6 ( & V_119 -> V_4 ) ,
V_178 ) ;
if ( V_159 || ! V_150 )
break;
V_2 = V_150 ;
V_150 = V_2 -> V_80 ;
V_2 -> V_80 = NULL ;
}
F_115 ( V_151 ) ;
if ( V_159 == 0 ) {
F_14 ( V_46 , F_6 ( & V_119 -> V_4 ) ,
V_179 ) ;
F_116 ( V_119 ) ;
return 0 ;
}
while ( V_150 ) {
V_2 = V_150 -> V_80 ;
F_15 ( V_150 ) ;
V_150 = V_2 ;
}
F_14 ( V_46 , F_6 ( & V_119 -> V_4 ) ,
V_74 ) ;
F_116 ( V_119 ) ;
return V_159 ;
V_166:
F_104 (skb, frag2) {
if ( V_164 == V_150 )
break;
V_164 -> V_19 = NULL ;
V_164 -> V_167 = NULL ;
V_2 -> V_169 += V_164 -> V_169 ;
}
}
V_165:
if ( ( V_2 -> V_176 == V_180 ) &&
F_117 ( V_2 ) )
goto V_181;
V_154 = V_2 -> V_30 - V_153 ;
V_158 = V_153 ;
* V_160 = V_171 ;
V_155 = F_36 ( V_119 -> V_4 . V_6 ) ;
V_156 = V_119 -> V_4 . V_6 -> V_182 ;
while( V_154 > 0 ) {
V_30 = V_154 ;
if ( V_30 > V_56 )
V_30 = V_56 ;
if ( V_30 < V_154 ) {
V_30 &= ~ 7 ;
}
if ( ( V_150 = F_118 ( V_30 + V_153 + sizeof( struct V_143 ) +
V_155 + V_156 , V_23 ) ) == NULL ) {
F_119 ( V_183 L_1 ) ;
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_74 ) ;
V_159 = - V_172 ;
goto V_181;
}
F_86 ( V_150 , V_2 ) ;
F_120 ( V_150 , V_155 ) ;
F_121 ( V_150 , V_30 + V_153 + sizeof( struct V_143 ) ) ;
F_44 ( V_150 ) ;
V_152 = (struct V_143 * ) ( F_57 ( V_150 ) + V_153 ) ;
V_150 -> V_184 = ( V_150 -> V_185 + V_153 +
sizeof( struct V_143 ) ) ;
if ( V_2 -> V_19 )
F_40 ( V_150 , V_2 -> V_19 ) ;
F_122 ( V_2 , F_57 ( V_150 ) , V_153 ) ;
V_152 -> V_64 = V_64 ;
V_152 -> V_173 = 0 ;
if ( ! V_157 ) {
F_93 ( V_152 , V_119 ) ;
V_157 = V_152 -> V_149 ;
} else
V_152 -> V_149 = V_157 ;
if ( F_123 ( V_2 , V_158 , F_124 ( V_150 ) , V_30 ) )
F_125 () ;
V_154 -= V_30 ;
V_152 -> V_83 = F_3 ( V_84 ) ;
if ( V_154 > 0 )
V_152 -> V_83 |= F_3 ( V_174 ) ;
F_5 ( V_150 ) -> V_63 = F_3 ( V_150 -> V_30 -
sizeof( struct V_50 ) ) ;
V_158 += V_30 ;
V_84 += V_30 ;
V_159 = F_98 ( V_150 ) ;
if ( V_159 )
goto V_181;
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_178 ) ;
}
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_179 ) ;
F_39 ( V_2 ) ;
return V_159 ;
V_181:
F_14 ( V_46 , F_6 ( F_2 ( V_2 ) ) ,
V_74 ) ;
F_15 ( V_2 ) ;
return V_159 ;
}
static inline int F_126 ( const struct V_186 * V_187 ,
const struct V_9 * V_188 ,
const struct V_9 * V_189 )
{
return ( V_187 -> V_190 != 128 || ! F_127 ( V_188 , & V_187 -> V_125 ) ) &&
( V_189 == NULL || ! F_127 ( V_188 , V_189 ) ) ;
}
static struct V_3 * F_128 ( struct V_37 * V_19 ,
struct V_3 * V_4 ,
const struct V_41 * V_42 )
{
struct V_47 * V_48 = F_35 ( V_19 ) ;
struct V_32 * V_119 ;
if ( ! V_4 )
goto V_191;
if ( V_4 -> V_192 -> V_193 != V_194 ) {
F_129 ( V_4 ) ;
return NULL ;
}
V_119 = (struct V_32 * ) V_4 ;
if ( F_126 ( & V_119 -> V_124 , & V_42 -> V_14 , V_48 -> V_195 ) ||
#ifdef F_130
F_126 ( & V_119 -> V_148 , & V_42 -> V_21 , V_48 -> V_196 ) ||
#endif
( V_42 -> V_197 && V_42 -> V_197 != V_4 -> V_6 -> V_82 ) ) {
F_129 ( V_4 ) ;
V_4 = NULL ;
}
V_191:
return V_4 ;
}
static int F_131 ( struct V_37 * V_19 ,
struct V_3 * * V_4 , struct V_41 * V_42 )
{
struct V_46 * V_46 = F_34 ( V_19 ) ;
#ifdef F_132
struct V_7 * V_198 ;
struct V_32 * V_119 ;
#endif
int V_159 ;
if ( * V_4 == NULL )
* V_4 = F_133 ( V_46 , V_19 , V_42 ) ;
if ( ( V_159 = ( * V_4 ) -> error ) )
goto V_199;
if ( F_134 ( & V_42 -> V_21 ) ) {
struct V_32 * V_119 = (struct V_32 * ) * V_4 ;
V_159 = F_135 ( V_46 , V_119 , & V_42 -> V_14 ,
V_19 ? F_35 ( V_19 ) -> V_200 : 0 ,
& V_42 -> V_21 ) ;
if ( V_159 )
goto V_199;
}
#ifdef F_132
V_119 = (struct V_32 * ) * V_4 ;
F_18 () ;
V_198 = F_20 ( V_119 -> V_4 . V_6 , F_19 ( V_119 ) ) ;
V_159 = V_198 && ! ( V_198 -> V_201 & V_202 ) ? - V_35 : 0 ;
F_25 () ;
if ( V_159 ) {
struct V_203 * V_204 ;
struct V_41 V_205 ;
int V_206 ;
V_204 = F_136 ( V_46 , & V_42 -> V_21 ,
( * V_4 ) -> V_6 , 1 ) ;
V_206 = ( V_204 && V_204 -> V_17 & V_207 ) ;
if ( V_204 )
F_137 ( V_204 ) ;
if ( V_206 ) {
F_129 ( * V_4 ) ;
memcpy ( & V_205 , V_42 , sizeof( struct V_41 ) ) ;
memset ( & V_205 . V_14 , 0 , sizeof( struct V_9 ) ) ;
* V_4 = F_133 ( V_46 , V_19 , & V_205 ) ;
if ( ( V_159 = ( * V_4 ) -> error ) )
goto V_199;
}
}
#endif
return 0 ;
V_199:
if ( V_159 == - V_208 )
F_14 ( V_46 , NULL , V_34 ) ;
F_129 ( * V_4 ) ;
* V_4 = NULL ;
return V_159 ;
}
int F_138 ( struct V_37 * V_19 , struct V_3 * * V_4 , struct V_41 * V_42 )
{
* V_4 = NULL ;
return F_131 ( V_19 , V_4 , V_42 ) ;
}
struct V_3 * F_139 ( struct V_37 * V_19 , struct V_41 * V_42 ,
const struct V_9 * V_209 )
{
struct V_3 * V_4 = NULL ;
int V_159 ;
V_159 = F_131 ( V_19 , & V_4 , V_42 ) ;
if ( V_159 )
return F_140 ( V_159 ) ;
if ( V_209 )
V_42 -> V_14 = * V_209 ;
return F_141 ( F_34 ( V_19 ) , V_4 , F_142 ( V_42 ) , V_19 , 0 ) ;
}
struct V_3 * F_143 ( struct V_37 * V_19 , struct V_41 * V_42 ,
const struct V_9 * V_209 )
{
struct V_3 * V_4 = F_144 ( V_19 , F_35 ( V_19 ) -> V_210 ) ;
int V_159 ;
V_4 = F_128 ( V_19 , V_4 , V_42 ) ;
V_159 = F_131 ( V_19 , & V_4 , V_42 ) ;
if ( V_159 )
return F_140 ( V_159 ) ;
if ( V_209 )
V_42 -> V_14 = * V_209 ;
return F_141 ( F_34 ( V_19 ) , V_4 , F_142 ( V_42 ) , V_19 , 0 ) ;
}
static inline int F_145 ( struct V_37 * V_19 ,
int F_146 ( void * V_141 , char * V_140 , int V_84 , int V_30 ,
int V_211 , struct V_1 * V_2 ) ,
void * V_141 , int V_212 , int V_213 , int V_214 ,
int V_215 , int V_56 , unsigned int V_17 ,
struct V_32 * V_119 )
{
struct V_1 * V_2 ;
struct V_143 V_144 ;
int V_159 ;
if ( ( V_2 = F_147 ( & V_19 -> V_216 ) ) == NULL ) {
V_2 = F_148 ( V_19 ,
V_213 + V_214 + V_215 + 20 ,
( V_17 & V_217 ) , & V_159 ) ;
if ( V_2 == NULL )
return V_159 ;
F_120 ( V_2 , V_213 ) ;
F_121 ( V_2 , V_214 + V_215 ) ;
F_44 ( V_2 ) ;
V_2 -> V_184 = V_2 -> V_185 + V_214 ;
V_2 -> V_12 = F_3 ( V_13 ) ;
V_2 -> V_218 = 0 ;
F_149 ( & V_19 -> V_216 , V_2 ) ;
} else if ( F_28 ( V_2 ) ) {
goto V_219;
}
V_2 -> V_176 = V_180 ;
F_107 ( V_2 ) -> V_220 = ( V_56 - V_214 -
sizeof( struct V_143 ) ) & ~ 7 ;
F_107 ( V_2 ) -> V_221 = V_222 ;
F_93 ( & V_144 , V_119 ) ;
F_107 ( V_2 ) -> V_223 = V_144 . V_149 ;
V_219:
return F_150 ( V_19 , V_2 , F_146 , V_141 ,
( V_212 - V_215 ) ) ;
}
static inline struct V_224 * F_151 ( struct V_224 * V_225 ,
T_6 V_226 )
{
return V_225 ? F_109 ( V_225 , ( V_225 -> V_227 + 1 ) * 8 , V_226 ) : NULL ;
}
static inline struct V_228 * F_152 ( struct V_228 * V_225 ,
T_6 V_226 )
{
return V_225 ? F_109 ( V_225 , ( V_225 -> V_227 + 1 ) * 8 , V_226 ) : NULL ;
}
static void F_153 ( unsigned int * V_56 ,
int * V_229 ,
unsigned int V_214 ,
struct V_1 * V_2 ,
struct V_32 * V_119 ,
unsigned int V_230 )
{
if ( ! ( V_119 -> V_4 . V_17 & V_231 ) ) {
if ( V_2 == NULL ) {
* V_56 = V_230 - V_119 -> V_4 . V_232 ;
} else {
* V_56 = V_230 ;
}
* V_229 = ( ( * V_56 - V_214 ) & ~ 7 )
+ V_214 - sizeof( struct V_143 ) ;
}
}
int F_154 ( struct V_37 * V_19 , int F_146 ( void * V_141 , char * V_140 ,
int V_84 , int V_30 , int V_211 , struct V_1 * V_2 ) ,
void * V_141 , int V_212 , int V_215 ,
int V_55 , int V_45 , struct V_43 * V_44 , struct V_41 * V_42 ,
struct V_32 * V_119 , unsigned int V_17 , int V_233 )
{
struct V_234 * V_235 = F_155 ( V_19 ) ;
struct V_47 * V_48 = F_35 ( V_19 ) ;
struct V_236 * V_237 ;
struct V_1 * V_2 , * V_238 = NULL ;
unsigned int V_229 , V_214 , V_56 , V_230 ;
int V_239 ;
int V_240 ;
int V_213 ;
int V_241 ;
int V_159 ;
int V_84 = 0 ;
T_7 V_242 = 0 ;
if ( V_17 & V_243 )
return 0 ;
V_237 = & V_235 -> V_237 . V_244 ;
if ( F_156 ( & V_19 -> V_216 ) ) {
if ( V_44 ) {
if ( F_157 ( V_48 -> V_237 . V_44 ) )
return - V_35 ;
V_48 -> V_237 . V_44 = F_158 ( V_44 -> V_245 , V_19 -> V_246 ) ;
if ( F_21 ( V_48 -> V_237 . V_44 == NULL ) )
return - V_61 ;
V_48 -> V_237 . V_44 -> V_245 = V_44 -> V_245 ;
V_48 -> V_237 . V_44 -> V_59 = V_44 -> V_59 ;
V_48 -> V_237 . V_44 -> V_58 = V_44 -> V_58 ;
V_48 -> V_237 . V_44 -> V_247 = F_151 ( V_44 -> V_247 ,
V_19 -> V_246 ) ;
if ( V_44 -> V_247 && ! V_48 -> V_237 . V_44 -> V_247 )
return - V_61 ;
V_48 -> V_237 . V_44 -> V_248 = F_151 ( V_44 -> V_248 ,
V_19 -> V_246 ) ;
if ( V_44 -> V_248 && ! V_48 -> V_237 . V_44 -> V_248 )
return - V_61 ;
V_48 -> V_237 . V_44 -> V_249 = F_151 ( V_44 -> V_249 ,
V_19 -> V_246 ) ;
if ( V_44 -> V_249 && ! V_48 -> V_237 . V_44 -> V_249 )
return - V_61 ;
V_48 -> V_237 . V_44 -> V_115 = F_152 ( V_44 -> V_115 ,
V_19 -> V_246 ) ;
if ( V_44 -> V_115 && ! V_48 -> V_237 . V_44 -> V_115 )
return - V_61 ;
}
F_113 ( & V_119 -> V_4 ) ;
V_237 -> V_4 = & V_119 -> V_4 ;
V_235 -> V_237 . V_250 . V_251 . V_252 = * V_42 ;
V_48 -> V_237 . V_27 = V_55 ;
V_48 -> V_237 . V_45 = V_45 ;
if ( V_119 -> V_4 . V_17 & V_231 )
V_56 = V_48 -> V_253 >= V_254 ?
V_119 -> V_4 . V_6 -> V_56 : F_47 ( & V_119 -> V_4 ) ;
else
V_56 = V_48 -> V_253 >= V_254 ?
V_119 -> V_4 . V_6 -> V_56 : F_47 ( V_119 -> V_4 . V_255 ) ;
if ( V_48 -> V_162 < V_56 ) {
if ( V_48 -> V_162 )
V_56 = V_48 -> V_162 ;
}
V_237 -> V_256 = V_56 ;
if ( F_29 ( V_119 -> V_4 . V_255 ) )
V_237 -> V_17 |= V_257 ;
V_237 -> V_212 = 0 ;
V_239 = ( V_44 ? V_44 -> V_59 : 0 ) ;
V_212 += V_239 ;
V_215 += V_239 ;
V_240 = V_119 -> V_4 . V_232 - V_119 -> V_258 ;
} else {
V_119 = (struct V_32 * ) V_237 -> V_4 ;
V_42 = & V_235 -> V_237 . V_250 . V_251 . V_252 ;
V_44 = V_48 -> V_237 . V_44 ;
V_215 = 0 ;
V_239 = 0 ;
V_240 = 0 ;
V_56 = V_237 -> V_256 ;
}
V_230 = V_56 ;
V_213 = F_36 ( V_119 -> V_4 . V_6 ) ;
V_214 = sizeof( struct V_50 ) + V_119 -> V_258 +
( V_44 ? V_44 -> V_58 : 0 ) ;
V_229 = ( ( V_56 - V_214 ) & ~ 7 ) + V_214 -
sizeof( struct V_143 ) ;
if ( V_56 <= sizeof( struct V_50 ) + V_259 ) {
unsigned int V_260 , V_261 ;
V_261 = sizeof( struct V_50 ) +
( V_44 ? V_44 -> V_59 + V_44 -> V_58 : 0 ) +
( F_29 ( & V_119 -> V_4 ) ?
sizeof( struct V_143 ) : 0 ) +
V_119 -> V_258 ;
if ( F_159 ( V_19 ) )
V_260 = sizeof( struct V_50 ) + V_259 ;
else
V_260 = V_56 ;
if ( ( V_237 -> V_212 + V_212 > V_56 - V_261 ) && V_233 &&
( V_19 -> V_262 == V_263 ||
V_19 -> V_262 == V_264 ) ) {
F_160 ( V_19 , V_42 , V_56 - V_261 +
sizeof( struct V_50 ) ) ;
goto V_265;
}
if ( V_237 -> V_212 + V_212 > V_260 - V_261 ) {
V_265:
F_48 ( V_19 , V_73 , V_42 ,
V_56 - V_261 +
sizeof( struct V_50 ) ) ;
return - V_73 ;
}
}
if ( V_19 -> V_266 == V_267 )
F_161 ( V_19 , & V_242 ) ;
V_2 = F_147 ( & V_19 -> V_216 ) ;
V_237 -> V_212 += V_212 ;
if ( ( ( V_212 > V_56 ) ||
( V_2 && F_28 ( V_2 ) ) ) &&
( V_19 -> V_262 == V_263 ) &&
( V_119 -> V_4 . V_6 -> V_268 & V_269 ) ) {
V_159 = F_145 ( V_19 , F_146 , V_141 , V_212 ,
V_213 , V_214 ,
V_215 , V_56 , V_17 , V_119 ) ;
if ( V_159 )
goto error;
return 0 ;
}
if ( ! V_2 )
goto V_270;
while ( V_212 > 0 ) {
V_241 = ( V_237 -> V_212 <= V_56 && ! ( V_237 -> V_17 & V_257 ) ? V_56 : V_229 ) - V_2 -> V_30 ;
if ( V_241 < V_212 )
V_241 = V_229 - V_2 -> V_30 ;
if ( V_241 <= 0 ) {
char * V_88 ;
unsigned int V_271 ;
unsigned int V_272 ;
unsigned int V_273 ;
unsigned int V_274 ;
V_270:
if ( V_2 )
V_273 = V_2 -> V_30 - V_229 ;
else
V_273 = 0 ;
if ( V_2 == NULL || V_238 == NULL )
F_153 ( & V_56 , & V_229 ,
V_214 , V_2 , V_119 ,
V_230 ) ;
V_238 = V_2 ;
V_271 = V_212 + V_273 ;
if ( V_271 > ( V_237 -> V_212 <= V_56 && ! ( V_237 -> V_17 & V_257 ) ? V_56 : V_229 ) - V_214 )
V_271 = V_229 - V_214 - V_119 -> V_4 . V_275 ;
if ( ( V_17 & V_276 ) &&
! ( V_119 -> V_4 . V_6 -> V_268 & V_277 ) )
V_274 = V_56 ;
else
V_274 = V_271 + V_214 ;
V_274 += V_240 ;
if ( V_271 != V_212 + V_273 ) {
V_271 += V_119 -> V_4 . V_275 ;
}
V_274 += V_119 -> V_4 . V_275 ;
V_272 = V_271 + V_214 ;
V_274 += sizeof( struct V_143 ) ;
if ( V_215 ) {
V_2 = F_148 ( V_19 ,
V_274 + V_213 ,
( V_17 & V_217 ) , & V_159 ) ;
} else {
V_2 = NULL ;
if ( F_162 ( & V_19 -> V_278 ) <=
2 * V_19 -> V_279 )
V_2 = F_163 ( V_19 ,
V_274 + V_213 , 1 ,
V_19 -> V_246 ) ;
if ( F_21 ( V_2 == NULL ) )
V_159 = - V_61 ;
else {
V_242 = 0 ;
}
}
if ( V_2 == NULL )
goto error;
V_2 -> V_12 = F_3 ( V_13 ) ;
V_2 -> V_176 = V_177 ;
V_2 -> V_218 = 0 ;
F_120 ( V_2 , V_213 + sizeof( struct V_143 ) +
V_240 ) ;
if ( V_19 -> V_266 == V_267 )
F_107 ( V_2 ) -> V_242 = V_242 ;
V_88 = F_121 ( V_2 , V_272 ) ;
F_164 ( V_2 , V_239 ) ;
V_88 += V_214 ;
V_2 -> V_184 = ( V_2 -> V_185 +
V_214 ) ;
if ( V_273 ) {
V_2 -> V_218 = F_165 (
V_238 , V_229 ,
V_88 + V_215 , V_273 , 0 ) ;
V_238 -> V_218 = F_166 ( V_238 -> V_218 ,
V_2 -> V_218 ) ;
V_88 += V_273 ;
F_167 ( V_238 , V_229 ) ;
}
V_241 = V_271 - V_215 - V_273 ;
if ( V_241 < 0 ) {
V_159 = - V_35 ;
F_15 ( V_2 ) ;
goto error;
} else if ( V_241 > 0 && F_146 ( V_141 , V_88 + V_215 , V_84 , V_241 , V_273 , V_2 ) < 0 ) {
V_159 = - V_280 ;
F_15 ( V_2 ) ;
goto error;
}
V_84 += V_241 ;
V_212 -= V_271 - V_273 ;
V_215 = 0 ;
V_239 = 0 ;
V_240 = 0 ;
F_149 ( & V_19 -> V_216 , V_2 ) ;
continue;
}
if ( V_241 > V_212 )
V_241 = V_212 ;
if ( ! ( V_119 -> V_4 . V_6 -> V_268 & V_277 ) ) {
unsigned int V_281 ;
V_281 = V_2 -> V_30 ;
if ( F_146 ( V_141 , F_121 ( V_2 , V_241 ) ,
V_84 , V_241 , V_281 , V_2 ) < 0 ) {
F_168 ( V_2 , V_281 ) ;
V_159 = - V_280 ;
goto error;
}
} else {
int V_282 = F_107 ( V_2 ) -> V_283 ;
struct V_284 * V_285 = F_169 ( V_19 ) ;
V_159 = - V_172 ;
if ( ! F_170 ( V_19 , V_285 ) )
goto error;
if ( ! F_171 ( V_2 , V_282 , V_285 -> V_286 ,
V_285 -> V_84 ) ) {
V_159 = - V_73 ;
if ( V_282 == V_287 )
goto error;
F_172 ( V_2 , V_282 , V_285 -> V_286 ,
V_285 -> V_84 , 0 ) ;
F_107 ( V_2 ) -> V_283 = ++ V_282 ;
F_173 ( V_285 -> V_286 ) ;
}
V_241 = F_174 ( int , V_241 , V_285 -> V_288 - V_285 -> V_84 ) ;
if ( F_146 ( V_141 ,
F_175 ( V_285 -> V_286 ) + V_285 -> V_84 ,
V_84 , V_241 , V_2 -> V_30 , V_2 ) < 0 )
goto V_289;
V_285 -> V_84 += V_241 ;
F_176 ( & F_107 ( V_2 ) -> V_290 [ V_282 - 1 ] , V_241 ) ;
V_2 -> V_30 += V_241 ;
V_2 -> V_175 += V_241 ;
V_2 -> V_169 += V_241 ;
F_177 ( V_241 , & V_19 -> V_278 ) ;
}
V_84 += V_241 ;
V_212 -= V_241 ;
}
return 0 ;
V_289:
V_159 = - V_280 ;
error:
V_237 -> V_212 -= V_212 ;
F_14 ( F_34 ( V_19 ) , V_119 -> V_291 , V_28 ) ;
return V_159 ;
}
static void F_178 ( struct V_234 * V_235 , struct V_47 * V_48 )
{
if ( V_48 -> V_237 . V_44 ) {
F_115 ( V_48 -> V_237 . V_44 -> V_247 ) ;
F_115 ( V_48 -> V_237 . V_44 -> V_248 ) ;
F_115 ( V_48 -> V_237 . V_44 -> V_249 ) ;
F_115 ( V_48 -> V_237 . V_44 -> V_115 ) ;
F_115 ( V_48 -> V_237 . V_44 ) ;
V_48 -> V_237 . V_44 = NULL ;
}
if ( V_235 -> V_237 . V_244 . V_4 ) {
F_129 ( V_235 -> V_237 . V_244 . V_4 ) ;
V_235 -> V_237 . V_244 . V_4 = NULL ;
V_235 -> V_237 . V_244 . V_17 &= ~ V_257 ;
}
memset ( & V_235 -> V_237 . V_250 , 0 , sizeof( V_235 -> V_237 . V_250 ) ) ;
}
int F_179 ( struct V_37 * V_19 )
{
struct V_1 * V_2 , * V_292 ;
struct V_1 * * V_293 ;
struct V_9 V_294 , * V_209 = & V_294 ;
struct V_234 * V_235 = F_155 ( V_19 ) ;
struct V_47 * V_48 = F_35 ( V_19 ) ;
struct V_46 * V_46 = F_34 ( V_19 ) ;
struct V_50 * V_51 ;
struct V_43 * V_44 = V_48 -> V_237 . V_44 ;
struct V_32 * V_119 = (struct V_32 * ) V_235 -> V_237 . V_244 . V_4 ;
struct V_41 * V_42 = & V_235 -> V_237 . V_250 . V_251 . V_252 ;
unsigned char V_52 = V_42 -> V_53 ;
int V_159 = 0 ;
if ( ( V_2 = F_180 ( & V_19 -> V_216 ) ) == NULL )
goto V_191;
V_293 = & ( F_107 ( V_2 ) -> V_170 ) ;
if ( V_2 -> V_88 < F_57 ( V_2 ) )
F_110 ( V_2 , F_181 ( V_2 ) ) ;
while ( ( V_292 = F_180 ( & V_19 -> V_216 ) ) != NULL ) {
F_110 ( V_292 , F_182 ( V_2 ) ) ;
* V_293 = V_292 ;
V_293 = & ( V_292 -> V_80 ) ;
V_2 -> V_30 += V_292 -> V_30 ;
V_2 -> V_175 += V_292 -> V_30 ;
V_2 -> V_169 += V_292 -> V_169 ;
V_292 -> V_167 = NULL ;
V_292 -> V_19 = NULL ;
}
V_2 -> V_69 = F_159 ( V_19 ) ;
* V_209 = V_42 -> V_14 ;
F_110 ( V_2 , F_182 ( V_2 ) ) ;
if ( V_44 && V_44 -> V_59 )
F_41 ( V_2 , V_44 , & V_52 ) ;
if ( V_44 && V_44 -> V_58 )
F_42 ( V_2 , V_44 , & V_52 , & V_209 ) ;
F_43 ( V_2 , sizeof( struct V_50 ) ) ;
F_44 ( V_2 ) ;
V_51 = F_5 ( V_2 ) ;
F_46 ( V_51 , V_48 -> V_237 . V_45 , V_42 -> V_62 ) ;
V_51 -> V_27 = V_48 -> V_237 . V_27 ;
V_51 -> V_64 = V_52 ;
V_51 -> V_21 = V_42 -> V_21 ;
V_51 -> V_14 = * V_209 ;
V_2 -> V_65 = V_19 -> V_66 ;
V_2 -> V_67 = V_19 -> V_68 ;
F_88 ( V_2 , F_89 ( & V_119 -> V_4 ) ) ;
F_16 ( V_46 , V_119 -> V_291 , V_70 , V_2 -> V_30 ) ;
if ( V_52 == V_85 ) {
struct V_15 * V_16 = F_6 ( F_2 ( V_2 ) ) ;
F_183 ( V_46 , V_16 , F_184 ( V_2 ) -> V_89 ) ;
F_185 ( V_46 , V_16 , V_295 ) ;
}
V_159 = F_186 ( V_2 ) ;
if ( V_159 ) {
if ( V_159 > 0 )
V_159 = F_187 ( V_159 ) ;
if ( V_159 )
goto error;
}
V_191:
F_178 ( V_235 , V_48 ) ;
return V_159 ;
error:
F_14 ( V_46 , V_119 -> V_291 , V_28 ) ;
goto V_191;
}
void F_188 ( struct V_37 * V_19 )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_189 ( & V_19 -> V_216 ) ) != NULL ) {
if ( F_2 ( V_2 ) )
F_14 ( F_34 ( V_19 ) , F_6 ( F_2 ( V_2 ) ) ,
V_28 ) ;
F_15 ( V_2 ) ;
}
F_178 ( F_155 ( V_19 ) , F_35 ( V_19 ) ) ;
}
