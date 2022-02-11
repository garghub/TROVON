int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = V_2 -> V_3 - sizeof( struct V_4 ) ;
if ( V_3 > V_5 )
V_3 = 0 ;
F_2 ( V_2 ) -> V_6 = F_3 ( V_3 ) ;
return F_4 ( V_7 , V_8 , V_2 , NULL ,
F_5 ( V_2 ) -> V_9 , V_10 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_1 ( V_2 ) ;
if ( F_7 ( V_11 == 1 ) )
V_11 = V_10 ( V_2 ) ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_5 ( V_2 ) ;
struct V_14 * V_9 = V_13 -> V_9 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
V_2 -> V_19 = F_3 ( V_20 ) ;
V_2 -> V_9 = V_9 ;
if ( F_9 ( & F_2 ( V_2 ) -> V_21 ) ) {
struct V_22 * V_23 = F_10 ( F_5 ( V_2 ) ) ;
if ( ! ( V_9 -> V_24 & V_25 ) && F_11 ( V_2 -> V_26 ) &&
( ( F_12 ( F_13 ( V_9 ) , V_2 ) &&
! ( F_14 ( V_2 ) -> V_24 & V_27 ) ) ||
F_15 ( V_9 , & F_2 ( V_2 ) -> V_21 ,
& F_2 ( V_2 ) -> V_28 ) ) ) {
struct V_1 * V_29 = F_16 ( V_2 , V_30 ) ;
if ( V_29 )
F_17 ( V_7 , V_31 ,
V_29 , NULL , V_29 -> V_9 ,
V_32 ) ;
if ( F_2 ( V_2 ) -> V_33 == 0 ) {
F_18 ( F_13 ( V_9 ) , V_23 ,
V_34 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
}
F_20 ( F_13 ( V_9 ) , V_23 , V_35 ,
V_2 -> V_3 ) ;
}
F_21 () ;
V_18 = (struct V_17 * ) V_13 ;
V_16 = V_18 -> V_36 ;
if ( V_16 ) {
int V_37 = F_22 ( V_13 , V_16 , V_2 ) ;
F_23 () ;
return V_37 ;
}
F_23 () ;
F_24 ( F_13 ( V_13 -> V_9 ) ,
F_10 ( V_13 ) , V_38 ) ;
F_19 ( V_2 ) ;
return - V_39 ;
}
static int F_25 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 > F_26 ( V_2 ) && ! F_27 ( V_2 ) ) ||
F_28 ( F_5 ( V_2 ) ) )
return F_29 ( V_2 , F_8 ) ;
else
return F_8 ( V_2 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
struct V_14 * V_9 = F_5 ( V_2 ) -> V_9 ;
struct V_22 * V_23 = F_10 ( F_5 ( V_2 ) ) ;
if ( F_31 ( V_23 -> V_40 . V_41 ) ) {
F_18 ( F_13 ( V_9 ) , V_23 ,
V_34 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
return F_32 ( V_7 , V_31 , V_2 , NULL , V_9 ,
F_25 ,
! ( F_14 ( V_2 ) -> V_24 & V_42 ) ) ;
}
int F_33 ( struct V_43 * V_26 , struct V_1 * V_2 , struct V_44 * V_45 ,
struct V_46 * V_47 , int V_48 )
{
struct V_49 * V_49 = F_34 ( V_26 ) ;
struct V_50 * V_51 = F_35 ( V_26 ) ;
struct V_52 * V_53 = & V_45 -> V_21 ;
struct V_12 * V_13 = F_5 ( V_2 ) ;
struct V_4 * V_54 ;
T_1 V_55 = V_45 -> V_56 ;
int V_57 = V_2 -> V_3 ;
int V_58 = - 1 ;
T_2 V_59 ;
if ( V_47 ) {
unsigned int V_60 ;
V_60 = V_47 -> V_61 + V_47 -> V_62 ;
V_57 += V_60 ;
V_60 += sizeof( struct V_4 ) + F_36 ( V_13 -> V_9 ) ;
if ( F_37 ( V_2 ) < V_60 ) {
struct V_1 * V_63 = F_38 ( V_2 , V_60 ) ;
if ( V_63 == NULL ) {
F_18 ( V_49 , F_10 ( F_5 ( V_2 ) ) ,
V_34 ) ;
F_19 ( V_2 ) ;
return - V_64 ;
}
F_39 ( V_2 ) ;
V_2 = V_63 ;
F_40 ( V_2 , V_26 ) ;
}
if ( V_47 -> V_62 )
F_41 ( V_2 , V_47 , & V_55 ) ;
if ( V_47 -> V_61 )
F_42 ( V_2 , V_47 , & V_55 , & V_53 ) ;
}
F_43 ( V_2 , sizeof( struct V_4 ) ) ;
F_44 ( V_2 ) ;
V_54 = F_2 ( V_2 ) ;
if ( V_51 )
V_58 = V_51 -> V_33 ;
if ( V_58 < 0 )
V_58 = F_45 ( V_13 ) ;
* ( V_65 * ) V_54 = F_46 ( 0x60000000 | ( V_48 << 20 ) ) | V_45 -> V_66 ;
V_54 -> V_6 = F_3 ( V_57 ) ;
V_54 -> V_67 = V_55 ;
V_54 -> V_33 = V_58 ;
V_54 -> V_28 = V_45 -> V_28 ;
V_54 -> V_21 = * V_53 ;
V_2 -> V_68 = V_26 -> V_69 ;
V_2 -> V_70 = V_26 -> V_71 ;
V_59 = F_47 ( V_13 ) ;
if ( ( V_2 -> V_3 <= V_59 ) || V_2 -> V_72 || F_27 ( V_2 ) ) {
F_20 ( V_49 , F_10 ( F_5 ( V_2 ) ) ,
V_73 , V_2 -> V_3 ) ;
return F_17 ( V_7 , V_8 , V_2 , NULL ,
V_13 -> V_9 , V_10 ) ;
}
F_48 ( L_1 ) ;
V_2 -> V_9 = V_13 -> V_9 ;
F_49 ( V_2 , V_74 , 0 , V_59 ) ;
F_18 ( V_49 , F_10 ( F_5 ( V_2 ) ) , V_75 ) ;
F_19 ( V_2 ) ;
return - V_76 ;
}
int F_50 ( struct V_43 * V_26 , struct V_1 * V_2 , struct V_14 * V_9 ,
const struct V_52 * V_28 , const struct V_52 * V_21 ,
int V_55 , int V_3 )
{
struct V_50 * V_51 = F_35 ( V_26 ) ;
struct V_4 * V_54 ;
V_2 -> V_19 = F_3 ( V_20 ) ;
V_2 -> V_9 = V_9 ;
F_44 ( V_2 ) ;
F_51 ( V_2 , sizeof( struct V_4 ) ) ;
V_54 = F_2 ( V_2 ) ;
* ( V_65 * ) V_54 = F_46 ( 0x60000000 ) ;
V_54 -> V_6 = F_3 ( V_3 ) ;
V_54 -> V_67 = V_55 ;
V_54 -> V_33 = V_51 -> V_33 ;
V_54 -> V_28 = * V_28 ;
V_54 -> V_21 = * V_21 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , int V_77 )
{
struct V_78 * V_79 ;
struct V_43 * V_80 = NULL ;
F_53 ( & V_81 ) ;
for ( V_79 = V_78 ; V_79 ; V_79 = V_79 -> V_82 ) {
struct V_43 * V_26 = V_79 -> V_26 ;
if ( V_26 && V_79 -> V_77 == V_77 &&
( ! V_26 -> V_83 ||
V_26 -> V_83 == V_2 -> V_9 -> V_84 ) ) {
if ( V_80 ) {
struct V_1 * V_63 = F_16 ( V_2 , V_30 ) ;
if ( V_63 )
F_54 ( V_80 , V_63 ) ;
}
V_80 = V_26 ;
}
}
if ( V_80 ) {
F_54 ( V_80 , V_2 ) ;
F_55 ( & V_81 ) ;
return 1 ;
}
F_55 ( & V_81 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_4 * V_54 = F_2 ( V_2 ) ;
T_1 V_67 = V_54 -> V_67 ;
T_3 V_85 ;
int V_86 ;
if ( F_57 ( V_67 ) ) {
V_86 = F_58 ( V_2 , sizeof( * V_54 ) , & V_67 , & V_85 ) ;
if ( V_86 < 0 )
return 0 ;
} else
V_86 = sizeof( struct V_4 ) ;
if ( V_67 == V_87 ) {
struct V_88 * V_89 ;
if ( ! F_59 ( V_2 , ( F_60 ( V_2 ) +
V_86 + 1 - V_2 -> V_90 ) ) )
return 0 ;
V_89 = (struct V_88 * ) ( F_60 ( V_2 ) + V_86 ) ;
switch ( V_89 -> V_91 ) {
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
return 1 ;
default:
break;
}
}
if ( F_61 ( & V_54 -> V_21 ) & V_97 ) {
F_62 ( V_2 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_63 ( struct V_1 * V_2 )
{
return V_10 ( V_2 ) ;
}
int F_64 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_5 ( V_2 ) ;
struct V_4 * V_54 = F_2 ( V_2 ) ;
struct V_98 * V_47 = F_14 ( V_2 ) ;
struct V_49 * V_49 = F_13 ( V_13 -> V_9 ) ;
T_2 V_59 ;
if ( V_49 -> V_99 . V_100 -> V_101 == 0 )
goto error;
if ( F_65 ( V_2 ) )
goto V_102;
if ( ! F_66 ( NULL , V_103 , V_2 ) ) {
F_18 ( V_49 , F_10 ( V_13 ) , V_104 ) ;
goto V_102;
}
if ( V_2 -> V_105 != V_106 )
goto V_102;
F_67 ( V_2 ) ;
if ( V_47 -> V_79 ) {
T_1 * V_107 = F_60 ( V_2 ) + V_47 -> V_79 ;
if ( F_52 ( V_2 , ( V_107 [ 2 ] << 8 ) + V_107 [ 3 ] ) )
return 0 ;
}
if ( V_54 -> V_33 <= 1 ) {
V_2 -> V_9 = V_13 -> V_9 ;
F_49 ( V_2 , V_108 , V_109 , 0 ) ;
F_24 ( V_49 ,
F_10 ( V_13 ) , V_110 ) ;
F_19 ( V_2 ) ;
return - V_111 ;
}
if ( V_49 -> V_99 . V_100 -> V_112 &&
F_68 ( & V_113 , V_49 , & V_54 -> V_21 , V_2 -> V_9 , 0 ) ) {
int V_114 = F_56 ( V_2 ) ;
if ( V_114 > 0 )
return F_69 ( V_2 ) ;
else if ( V_114 < 0 ) {
F_18 ( V_49 , F_10 ( V_13 ) ,
V_104 ) ;
goto V_102;
}
}
if ( ! F_70 ( V_2 ) ) {
F_18 ( V_49 , F_10 ( V_13 ) , V_104 ) ;
goto V_102;
}
V_13 = F_5 ( V_2 ) ;
if ( V_2 -> V_9 == V_13 -> V_9 && V_47 -> V_115 == 0 && ! F_71 ( V_2 ) ) {
struct V_52 * V_116 = NULL ;
struct V_117 * V_118 ;
struct V_17 * V_18 ;
V_18 = (struct V_17 * ) V_13 ;
if ( V_18 -> V_119 & V_120 )
V_116 = & V_18 -> V_121 ;
else
V_116 = & V_54 -> V_21 ;
V_118 = F_72 ( V_49 -> V_99 . V_122 , & V_18 -> V_123 . V_124 , 1 ) ;
if ( F_73 ( V_118 , 1 * V_125 ) )
F_74 ( V_2 , V_116 ) ;
if ( V_118 )
F_75 ( V_118 ) ;
} else {
int V_126 = F_61 ( & V_54 -> V_28 ) ;
if ( V_126 == V_127 ||
V_126 & ( V_128 | V_129 ) )
goto error;
if ( V_126 & V_97 ) {
F_49 ( V_2 , V_130 ,
V_131 , 0 ) ;
goto error;
}
}
V_59 = F_47 ( V_13 ) ;
if ( V_59 < V_132 )
V_59 = V_132 ;
if ( V_2 -> V_3 > V_59 && ! F_27 ( V_2 ) ) {
V_2 -> V_9 = V_13 -> V_9 ;
F_49 ( V_2 , V_74 , 0 , V_59 ) ;
F_24 ( V_49 ,
F_10 ( V_13 ) , V_133 ) ;
F_24 ( V_49 ,
F_10 ( V_13 ) , V_75 ) ;
F_19 ( V_2 ) ;
return - V_76 ;
}
if ( F_76 ( V_2 , V_13 -> V_9 -> V_134 ) ) {
F_18 ( V_49 , F_10 ( V_13 ) , V_34 ) ;
goto V_102;
}
V_54 = F_2 ( V_2 ) ;
V_54 -> V_33 -- ;
F_24 ( V_49 , F_10 ( V_13 ) , V_135 ) ;
F_77 ( V_49 , F_10 ( V_13 ) , V_136 , V_2 -> V_3 ) ;
return F_17 ( V_7 , V_137 , V_2 , V_2 -> V_9 , V_13 -> V_9 ,
F_63 ) ;
error:
F_24 ( V_49 , F_10 ( V_13 ) , V_138 ) ;
V_102:
F_19 ( V_2 ) ;
return - V_39 ;
}
static void F_78 ( struct V_1 * V_139 , struct V_1 * V_140 )
{
V_139 -> V_105 = V_140 -> V_105 ;
V_139 -> V_68 = V_140 -> V_68 ;
V_139 -> V_19 = V_140 -> V_19 ;
F_79 ( V_139 ) ;
F_80 ( V_139 , F_81 ( F_5 ( V_140 ) ) ) ;
V_139 -> V_9 = V_140 -> V_9 ;
V_139 -> V_70 = V_140 -> V_70 ;
#ifdef F_82
V_139 -> V_141 = V_140 -> V_141 ;
#endif
F_83 ( V_139 , V_140 ) ;
#if F_84 ( V_142 ) || \
F_84 ( V_143 )
V_139 -> V_144 = V_140 -> V_144 ;
#endif
F_85 ( V_139 , V_140 ) ;
}
int F_86 ( struct V_1 * V_2 , T_1 * * V_67 )
{
T_4 V_86 = sizeof( struct V_4 ) ;
struct V_145 * V_146 =
(struct V_145 * ) ( F_2 ( V_2 ) + 1 ) ;
unsigned int V_147 = V_2 -> V_148 - V_2 -> V_149 ;
int V_150 = 0 ;
* V_67 = & F_2 ( V_2 ) -> V_67 ;
while ( V_86 + 1 <= V_147 ) {
switch ( * * V_67 ) {
case V_151 :
break;
case V_152 :
V_150 = 1 ;
break;
case V_153 :
#if F_84 ( V_154 ) || F_84 ( V_155 )
if ( F_87 ( V_2 , V_86 , V_156 ) >= 0 )
break;
#endif
if ( V_150 )
return V_86 ;
break;
default :
return V_86 ;
}
V_86 += F_88 ( V_146 ) ;
* V_67 = & V_146 -> V_67 ;
V_146 = (struct V_145 * ) ( F_60 ( V_2 ) +
V_86 ) ;
}
return V_86 ;
}
void F_89 ( struct V_157 * V_158 , struct V_17 * V_18 )
{
static T_5 V_159 ;
int V_160 , V_161 ;
if ( V_18 && ! ( V_18 -> V_13 . V_24 & V_162 ) ) {
struct V_117 * V_118 ;
struct V_49 * V_49 ;
V_49 = F_13 ( V_18 -> V_13 . V_9 ) ;
V_118 = F_72 ( V_49 -> V_99 . V_122 , & V_18 -> V_123 . V_124 , 1 ) ;
if ( V_118 ) {
V_158 -> V_163 = F_46 ( F_90 ( V_118 , 0 ) ) ;
F_75 ( V_118 ) ;
return;
}
}
do {
V_160 = F_91 ( & V_159 ) ;
V_161 = V_160 + 1 ;
if ( ! V_161 )
V_161 = 1 ;
} while ( F_92 ( & V_159 , V_160 , V_161 ) != V_160 );
V_158 -> V_163 = F_46 ( V_161 ) ;
}
int F_29 ( struct V_1 * V_2 , int (* F_93)( struct V_1 * ) )
{
struct V_1 * V_164 ;
struct V_17 * V_18 = (struct V_17 * ) F_5 ( V_2 ) ;
struct V_50 * V_51 = V_2 -> V_26 ? F_35 ( V_2 -> V_26 ) : NULL ;
struct V_4 * V_165 ;
struct V_157 * V_166 ;
unsigned int V_59 , V_167 , V_168 , V_3 ;
int V_169 , V_170 ;
V_65 V_171 = 0 ;
int V_107 , V_86 = 0 , V_11 = 0 ;
T_1 * V_172 , V_67 = 0 ;
struct V_49 * V_49 = F_13 ( F_5 ( V_2 ) -> V_9 ) ;
V_167 = F_86 ( V_2 , & V_172 ) ;
V_67 = * V_172 ;
V_59 = F_26 ( V_2 ) ;
if ( F_31 ( ! V_2 -> V_72 && V_2 -> V_3 > V_59 ) ) {
if ( V_2 -> V_26 && F_28 ( F_5 ( V_2 ) ) )
F_94 ( V_2 -> V_26 , V_173 ) ;
V_2 -> V_9 = F_5 ( V_2 ) -> V_9 ;
F_49 ( V_2 , V_74 , 0 , V_59 ) ;
F_18 ( V_49 , F_10 ( F_5 ( V_2 ) ) ,
V_75 ) ;
F_19 ( V_2 ) ;
return - V_76 ;
}
if ( V_51 && V_51 -> V_174 < V_59 ) {
if ( V_51 -> V_174 )
V_59 = V_51 -> V_174 ;
}
V_59 -= V_167 + sizeof( struct V_157 ) ;
if ( F_95 ( V_2 ) ) {
int V_175 = F_96 ( V_2 ) ;
struct V_1 * V_176 ;
if ( V_175 - V_167 > V_59 ||
( ( V_175 - V_167 ) & 7 ) ||
F_97 ( V_2 ) )
goto V_177;
F_98 (skb, frag) {
if ( V_164 -> V_3 > V_59 ||
( ( V_164 -> V_3 & 7 ) && V_164 -> V_82 ) ||
F_37 ( V_164 ) < V_167 )
goto V_178;
if ( F_99 ( V_164 ) )
goto V_178;
F_100 ( V_164 -> V_26 ) ;
if ( V_2 -> V_26 ) {
V_164 -> V_26 = V_2 -> V_26 ;
V_164 -> V_179 = V_180 ;
}
V_2 -> V_181 -= V_164 -> V_181 ;
}
V_11 = 0 ;
V_86 = 0 ;
V_164 = F_101 ( V_2 ) -> V_182 ;
F_102 ( V_2 ) ;
* V_172 = V_183 ;
V_165 = F_103 ( F_60 ( V_2 ) , V_167 , V_30 ) ;
if ( ! V_165 ) {
F_18 ( V_49 , F_10 ( F_5 ( V_2 ) ) ,
V_75 ) ;
return - V_184 ;
}
F_104 ( V_2 , V_167 ) ;
V_166 = (struct V_157 * ) F_105 ( V_2 , sizeof( struct V_157 ) ) ;
F_105 ( V_2 , V_167 ) ;
F_44 ( V_2 ) ;
memcpy ( F_60 ( V_2 ) , V_165 , V_167 ) ;
F_89 ( V_166 , V_18 ) ;
V_166 -> V_67 = V_67 ;
V_166 -> V_185 = 0 ;
V_166 -> V_85 = F_3 ( V_186 ) ;
V_171 = V_166 -> V_163 ;
V_175 = F_96 ( V_2 ) ;
V_2 -> V_187 = V_175 - F_106 ( V_2 ) ;
V_2 -> V_3 = V_175 ;
F_2 ( V_2 ) -> V_6 = F_3 ( V_175 -
sizeof( struct V_4 ) ) ;
F_107 ( & V_18 -> V_13 ) ;
for (; ; ) {
if ( V_164 ) {
V_164 -> V_188 = V_189 ;
F_108 ( V_164 ) ;
V_166 = (struct V_157 * ) F_105 ( V_164 , sizeof( struct V_157 ) ) ;
F_105 ( V_164 , V_167 ) ;
F_44 ( V_164 ) ;
memcpy ( F_60 ( V_164 ) , V_165 ,
V_167 ) ;
V_86 += V_2 -> V_3 - V_167 - sizeof( struct V_157 ) ;
V_166 -> V_67 = V_67 ;
V_166 -> V_185 = 0 ;
V_166 -> V_85 = F_3 ( V_86 ) ;
if ( V_164 -> V_82 != NULL )
V_166 -> V_85 |= F_3 ( V_186 ) ;
V_166 -> V_163 = V_171 ;
F_2 ( V_164 ) -> V_6 =
F_3 ( V_164 -> V_3 -
sizeof( struct V_4 ) ) ;
F_78 ( V_164 , V_2 ) ;
}
V_11 = F_93 ( V_2 ) ;
if( ! V_11 )
F_18 ( V_49 , F_10 ( & V_18 -> V_13 ) ,
V_190 ) ;
if ( V_11 || ! V_164 )
break;
V_2 = V_164 ;
V_164 = V_2 -> V_82 ;
V_2 -> V_82 = NULL ;
}
F_109 ( V_165 ) ;
if ( V_11 == 0 ) {
F_18 ( V_49 , F_10 ( & V_18 -> V_13 ) ,
V_191 ) ;
F_110 ( & V_18 -> V_13 ) ;
return 0 ;
}
while ( V_164 ) {
V_2 = V_164 -> V_82 ;
F_19 ( V_164 ) ;
V_164 = V_2 ;
}
F_18 ( V_49 , F_10 ( & V_18 -> V_13 ) ,
V_75 ) ;
F_110 ( & V_18 -> V_13 ) ;
return V_11 ;
V_178:
F_98 (skb, frag2) {
if ( V_176 == V_164 )
break;
V_176 -> V_26 = NULL ;
V_176 -> V_179 = NULL ;
V_2 -> V_181 += V_176 -> V_181 ;
}
}
V_177:
if ( ( V_2 -> V_188 == V_192 ) &&
F_111 ( V_2 ) )
goto V_193;
V_168 = V_2 -> V_3 - V_167 ;
V_107 = V_167 ;
* V_172 = V_183 ;
V_169 = F_36 ( V_18 -> V_13 . V_9 ) ;
V_170 = V_18 -> V_13 . V_9 -> V_194 ;
while( V_168 > 0 ) {
V_3 = V_168 ;
if ( V_3 > V_59 )
V_3 = V_59 ;
if ( V_3 < V_168 ) {
V_3 &= ~ 7 ;
}
if ( ( V_164 = F_112 ( V_3 + V_167 + sizeof( struct V_157 ) +
V_169 + V_170 , V_30 ) ) == NULL ) {
F_113 ( V_195 L_2 ) ;
F_18 ( V_49 , F_10 ( F_5 ( V_2 ) ) ,
V_75 ) ;
V_11 = - V_184 ;
goto V_193;
}
F_78 ( V_164 , V_2 ) ;
F_114 ( V_164 , V_169 ) ;
F_51 ( V_164 , V_3 + V_167 + sizeof( struct V_157 ) ) ;
F_44 ( V_164 ) ;
V_166 = (struct V_157 * ) ( F_60 ( V_164 ) + V_167 ) ;
V_164 -> V_196 = ( V_164 -> V_149 + V_167 +
sizeof( struct V_157 ) ) ;
if ( V_2 -> V_26 )
F_40 ( V_164 , V_2 -> V_26 ) ;
F_115 ( V_2 , F_60 ( V_164 ) , V_167 ) ;
V_166 -> V_67 = V_67 ;
V_166 -> V_185 = 0 ;
if ( ! V_171 ) {
F_89 ( V_166 , V_18 ) ;
V_171 = V_166 -> V_163 ;
} else
V_166 -> V_163 = V_171 ;
if ( F_116 ( V_2 , V_107 , F_117 ( V_164 ) , V_3 ) )
F_118 () ;
V_168 -= V_3 ;
V_166 -> V_85 = F_3 ( V_86 ) ;
if ( V_168 > 0 )
V_166 -> V_85 |= F_3 ( V_186 ) ;
F_2 ( V_164 ) -> V_6 = F_3 ( V_164 -> V_3 -
sizeof( struct V_4 ) ) ;
V_107 += V_3 ;
V_86 += V_3 ;
V_11 = F_93 ( V_164 ) ;
if ( V_11 )
goto V_193;
F_18 ( V_49 , F_10 ( F_5 ( V_2 ) ) ,
V_190 ) ;
}
F_18 ( V_49 , F_10 ( F_5 ( V_2 ) ) ,
V_191 ) ;
F_39 ( V_2 ) ;
return V_11 ;
V_193:
F_18 ( V_49 , F_10 ( F_5 ( V_2 ) ) ,
V_75 ) ;
F_19 ( V_2 ) ;
return V_11 ;
}
static inline int F_119 ( const struct V_197 * V_198 ,
const struct V_52 * V_199 ,
const struct V_52 * V_200 )
{
return ( V_198 -> V_201 != 128 || ! F_120 ( V_199 , & V_198 -> V_124 ) ) &&
( V_200 == NULL || ! F_120 ( V_199 , V_200 ) ) ;
}
static struct V_12 * F_121 ( struct V_43 * V_26 ,
struct V_12 * V_13 ,
const struct V_44 * V_45 )
{
struct V_50 * V_51 = F_35 ( V_26 ) ;
struct V_17 * V_18 = (struct V_17 * ) V_13 ;
if ( ! V_13 )
goto V_202;
if ( F_119 ( & V_18 -> V_123 , & V_45 -> V_21 , V_51 -> V_203 ) ||
#ifdef F_122
F_119 ( & V_18 -> V_204 , & V_45 -> V_28 , V_51 -> V_205 ) ||
#endif
( V_45 -> V_206 && V_45 -> V_206 != V_13 -> V_9 -> V_84 ) ) {
F_110 ( V_13 ) ;
V_13 = NULL ;
}
V_202:
return V_13 ;
}
static int F_123 ( struct V_43 * V_26 ,
struct V_12 * * V_13 , struct V_44 * V_45 )
{
struct V_49 * V_49 = F_34 ( V_26 ) ;
#ifdef F_124
struct V_15 * V_36 ;
struct V_17 * V_18 ;
#endif
int V_11 ;
if ( * V_13 == NULL )
* V_13 = F_125 ( V_49 , V_26 , V_45 ) ;
if ( ( V_11 = ( * V_13 ) -> error ) )
goto V_207;
if ( F_126 ( & V_45 -> V_28 ) ) {
struct V_17 * V_18 = (struct V_17 * ) * V_13 ;
V_11 = F_127 ( V_49 , V_18 , & V_45 -> V_21 ,
V_26 ? F_35 ( V_26 ) -> V_208 : 0 ,
& V_45 -> V_28 ) ;
if ( V_11 )
goto V_207;
}
#ifdef F_124
F_21 () ;
V_18 = (struct V_17 * ) * V_13 ;
V_36 = V_18 -> V_36 ;
if ( V_36 && ! ( V_36 -> V_209 & V_210 ) ) {
struct V_211 * V_212 ;
struct V_44 V_213 ;
int V_214 ;
F_23 () ;
V_212 = F_128 ( V_49 , & V_45 -> V_28 ,
( * V_13 ) -> V_9 , 1 ) ;
V_214 = ( V_212 && V_212 -> V_24 & V_215 ) ;
if ( V_212 )
F_129 ( V_212 ) ;
if ( V_214 ) {
F_110 ( * V_13 ) ;
memcpy ( & V_213 , V_45 , sizeof( struct V_44 ) ) ;
memset ( & V_213 . V_21 , 0 , sizeof( struct V_52 ) ) ;
* V_13 = F_125 ( V_49 , V_26 , & V_213 ) ;
if ( ( V_11 = ( * V_13 ) -> error ) )
goto V_207;
}
} else {
F_23 () ;
}
#endif
return 0 ;
V_207:
if ( V_11 == - V_216 )
F_24 ( V_49 , NULL , V_38 ) ;
F_110 ( * V_13 ) ;
* V_13 = NULL ;
return V_11 ;
}
int F_130 ( struct V_43 * V_26 , struct V_12 * * V_13 , struct V_44 * V_45 )
{
* V_13 = NULL ;
return F_123 ( V_26 , V_13 , V_45 ) ;
}
struct V_12 * F_131 ( struct V_43 * V_26 , struct V_44 * V_45 ,
const struct V_52 * V_217 ,
bool V_218 )
{
struct V_12 * V_13 = NULL ;
int V_11 ;
V_11 = F_123 ( V_26 , & V_13 , V_45 ) ;
if ( V_11 )
return F_132 ( V_11 ) ;
if ( V_217 )
V_45 -> V_21 = * V_217 ;
if ( V_218 )
V_45 -> V_219 |= V_220 ;
return F_133 ( F_34 ( V_26 ) , V_13 , F_134 ( V_45 ) , V_26 , 0 ) ;
}
struct V_12 * F_135 ( struct V_43 * V_26 , struct V_44 * V_45 ,
const struct V_52 * V_217 ,
bool V_218 )
{
struct V_12 * V_13 = F_136 ( V_26 , F_35 ( V_26 ) -> V_221 ) ;
int V_11 ;
V_13 = F_121 ( V_26 , V_13 , V_45 ) ;
V_11 = F_123 ( V_26 , & V_13 , V_45 ) ;
if ( V_11 )
return F_132 ( V_11 ) ;
if ( V_217 )
V_45 -> V_21 = * V_217 ;
if ( V_218 )
V_45 -> V_219 |= V_220 ;
return F_133 ( F_34 ( V_26 ) , V_13 , F_134 ( V_45 ) , V_26 , 0 ) ;
}
static inline int F_137 ( struct V_43 * V_26 ,
int F_138 ( void * V_140 , char * V_139 , int V_86 , int V_3 ,
int V_222 , struct V_1 * V_2 ) ,
void * V_140 , int V_223 , int V_224 , int V_225 ,
int V_226 , int V_59 , unsigned int V_24 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 ;
int V_11 ;
if ( ( V_2 = F_139 ( & V_26 -> V_227 ) ) == NULL ) {
V_2 = F_140 ( V_26 ,
V_224 + V_225 + V_226 + 20 ,
( V_24 & V_228 ) , & V_11 ) ;
if ( V_2 == NULL )
return V_11 ;
F_114 ( V_2 , V_224 ) ;
F_51 ( V_2 , V_225 + V_226 ) ;
F_44 ( V_2 ) ;
V_2 -> V_196 = V_2 -> V_149 + V_225 ;
V_2 -> V_188 = V_192 ;
V_2 -> V_229 = 0 ;
}
V_11 = F_141 ( V_26 , V_2 , F_138 , V_140 ,
( V_223 - V_226 ) ) ;
if ( ! V_11 ) {
struct V_157 V_158 ;
F_101 ( V_2 ) -> V_230 = ( V_59 - V_225 -
sizeof( struct V_157 ) ) & ~ 7 ;
F_101 ( V_2 ) -> V_231 = V_232 ;
F_89 ( & V_158 , V_18 ) ;
F_101 ( V_2 ) -> V_233 = V_158 . V_163 ;
F_142 ( & V_26 -> V_227 , V_2 ) ;
return 0 ;
}
F_19 ( V_2 ) ;
return V_11 ;
}
static inline struct V_145 * F_143 ( struct V_145 * V_234 ,
T_6 V_235 )
{
return V_234 ? F_103 ( V_234 , ( V_234 -> V_236 + 1 ) * 8 , V_235 ) : NULL ;
}
static inline struct V_237 * F_144 ( struct V_237 * V_234 ,
T_6 V_235 )
{
return V_234 ? F_103 ( V_234 , ( V_234 -> V_236 + 1 ) * 8 , V_235 ) : NULL ;
}
static void F_145 ( int * V_59 ,
int * V_238 ,
unsigned int V_225 ,
struct V_1 * V_2 ,
struct V_17 * V_18 )
{
if ( ! ( V_18 -> V_13 . V_24 & V_239 ) ) {
if ( V_2 == NULL ) {
* V_59 = * V_59 - V_18 -> V_13 . V_240 ;
} else {
* V_59 = F_47 ( V_18 -> V_13 . V_241 ) ;
}
* V_238 = ( ( * V_59 - V_225 ) & ~ 7 )
+ V_225 - sizeof( struct V_157 ) ;
}
}
int F_146 ( struct V_43 * V_26 , int F_138 ( void * V_140 , char * V_139 ,
int V_86 , int V_3 , int V_222 , struct V_1 * V_2 ) ,
void * V_140 , int V_223 , int V_226 ,
int V_58 , int V_48 , struct V_46 * V_47 , struct V_44 * V_45 ,
struct V_17 * V_18 , unsigned int V_24 , int V_242 )
{
struct V_243 * V_244 = F_147 ( V_26 ) ;
struct V_50 * V_51 = F_35 ( V_26 ) ;
struct V_245 * V_246 ;
struct V_1 * V_2 , * V_247 = NULL ;
unsigned int V_238 , V_225 ;
int V_248 ;
int V_249 ;
int V_224 ;
int V_59 ;
int V_250 ;
int V_11 ;
int V_86 = 0 ;
T_7 V_251 = 0 ;
if ( V_24 & V_252 )
return 0 ;
V_246 = & V_244 -> V_246 . V_253 ;
if ( F_148 ( & V_26 -> V_227 ) ) {
if ( V_47 ) {
if ( F_149 ( V_51 -> V_246 . V_47 ) )
return - V_39 ;
V_51 -> V_246 . V_47 = F_150 ( V_47 -> V_254 , V_26 -> V_255 ) ;
if ( F_31 ( V_51 -> V_246 . V_47 == NULL ) )
return - V_64 ;
V_51 -> V_246 . V_47 -> V_254 = V_47 -> V_254 ;
V_51 -> V_246 . V_47 -> V_62 = V_47 -> V_62 ;
V_51 -> V_246 . V_47 -> V_61 = V_47 -> V_61 ;
V_51 -> V_246 . V_47 -> V_256 = F_143 ( V_47 -> V_256 ,
V_26 -> V_255 ) ;
if ( V_47 -> V_256 && ! V_51 -> V_246 . V_47 -> V_256 )
return - V_64 ;
V_51 -> V_246 . V_47 -> V_257 = F_143 ( V_47 -> V_257 ,
V_26 -> V_255 ) ;
if ( V_47 -> V_257 && ! V_51 -> V_246 . V_47 -> V_257 )
return - V_64 ;
V_51 -> V_246 . V_47 -> V_258 = F_143 ( V_47 -> V_258 ,
V_26 -> V_255 ) ;
if ( V_47 -> V_258 && ! V_51 -> V_246 . V_47 -> V_258 )
return - V_64 ;
V_51 -> V_246 . V_47 -> V_115 = F_144 ( V_47 -> V_115 ,
V_26 -> V_255 ) ;
if ( V_47 -> V_115 && ! V_51 -> V_246 . V_47 -> V_115 )
return - V_64 ;
}
F_107 ( & V_18 -> V_13 ) ;
V_246 -> V_13 = & V_18 -> V_13 ;
V_244 -> V_246 . V_259 . V_260 . V_261 = * V_45 ;
V_51 -> V_246 . V_33 = V_58 ;
V_51 -> V_246 . V_48 = V_48 ;
if ( V_18 -> V_13 . V_24 & V_239 )
V_59 = V_51 -> V_262 == V_263 ?
V_18 -> V_13 . V_9 -> V_59 : F_47 ( & V_18 -> V_13 ) ;
else
V_59 = V_51 -> V_262 == V_263 ?
V_18 -> V_13 . V_9 -> V_59 : F_47 ( V_18 -> V_13 . V_241 ) ;
if ( V_51 -> V_174 < V_59 ) {
if ( V_51 -> V_174 )
V_59 = V_51 -> V_174 ;
}
V_246 -> V_264 = V_59 ;
if ( F_28 ( V_18 -> V_13 . V_241 ) )
V_246 -> V_24 |= V_265 ;
V_246 -> V_223 = 0 ;
V_26 -> V_266 = NULL ;
V_26 -> V_267 = 0 ;
V_248 = ( V_47 ? V_47 -> V_62 : 0 ) - V_18 -> V_268 ;
V_223 += V_248 ;
V_226 += V_248 ;
V_249 = V_18 -> V_13 . V_240 ;
} else {
V_18 = (struct V_17 * ) V_246 -> V_13 ;
V_45 = & V_244 -> V_246 . V_259 . V_260 . V_261 ;
V_47 = V_51 -> V_246 . V_47 ;
V_226 = 0 ;
V_248 = 0 ;
V_249 = 0 ;
V_59 = V_246 -> V_264 ;
}
V_224 = F_36 ( V_18 -> V_13 . V_9 ) ;
V_225 = sizeof( struct V_4 ) + V_18 -> V_268 +
( V_47 ? V_47 -> V_61 : 0 ) ;
V_238 = ( ( V_59 - V_225 ) & ~ 7 ) + V_225 - sizeof( struct V_157 ) ;
if ( V_59 <= sizeof( struct V_4 ) + V_5 ) {
if ( V_246 -> V_223 + V_223 > sizeof( struct V_4 ) + V_5 - V_225 ) {
F_151 ( V_26 , V_76 , V_45 , V_59 - V_248 ) ;
return - V_76 ;
}
}
if ( V_26 -> V_269 == V_270 ) {
V_11 = F_152 ( V_26 , & V_251 ) ;
if ( V_11 )
goto error;
}
V_246 -> V_223 += V_223 ;
if ( V_223 > V_59 ) {
int V_55 = V_26 -> V_271 ;
if ( V_242 && ( V_55 == V_272 || V_55 == V_273 ) ) {
F_153 ( V_26 , V_45 , V_59 - V_248 ) ;
return - V_76 ;
}
if ( V_55 == V_272 &&
( V_18 -> V_13 . V_9 -> V_274 & V_275 ) ) {
V_11 = F_137 ( V_26 , F_138 , V_140 , V_223 ,
V_224 , V_225 ,
V_226 , V_59 , V_24 , V_18 ) ;
if ( V_11 )
goto error;
return 0 ;
}
}
if ( ( V_2 = F_139 ( & V_26 -> V_227 ) ) == NULL )
goto V_276;
while ( V_223 > 0 ) {
V_250 = ( V_246 -> V_223 <= V_59 && ! ( V_246 -> V_24 & V_265 ) ? V_59 : V_238 ) - V_2 -> V_3 ;
if ( V_250 < V_223 )
V_250 = V_238 - V_2 -> V_3 ;
if ( V_250 <= 0 ) {
char * V_90 ;
unsigned int V_277 ;
unsigned int V_278 ;
unsigned int V_279 ;
unsigned int V_280 ;
V_276:
if ( V_2 )
V_279 = V_2 -> V_3 - V_238 ;
else
V_279 = 0 ;
if ( V_2 == NULL || V_247 == NULL )
F_145 ( & V_59 , & V_238 ,
V_225 , V_2 , V_18 ) ;
V_247 = V_2 ;
V_277 = V_223 + V_279 ;
if ( V_277 > ( V_246 -> V_223 <= V_59 && ! ( V_246 -> V_24 & V_265 ) ? V_59 : V_238 ) - V_225 )
V_277 = V_238 - V_225 - V_18 -> V_13 . V_281 ;
if ( ( V_24 & V_282 ) &&
! ( V_18 -> V_13 . V_9 -> V_274 & V_283 ) )
V_280 = V_59 ;
else
V_280 = V_277 + V_225 ;
V_280 += V_249 ;
if ( V_277 != V_223 + V_279 ) {
V_277 += V_18 -> V_13 . V_281 ;
}
V_280 += V_18 -> V_13 . V_281 ;
V_278 = V_277 + V_225 ;
V_280 += sizeof( struct V_157 ) ;
if ( V_226 ) {
V_2 = F_140 ( V_26 ,
V_280 + V_224 ,
( V_24 & V_228 ) , & V_11 ) ;
} else {
V_2 = NULL ;
if ( F_91 ( & V_26 -> V_284 ) <=
2 * V_26 -> V_285 )
V_2 = F_154 ( V_26 ,
V_280 + V_224 , 1 ,
V_26 -> V_255 ) ;
if ( F_31 ( V_2 == NULL ) )
V_11 = - V_64 ;
else {
V_251 = 0 ;
}
}
if ( V_2 == NULL )
goto error;
V_2 -> V_188 = V_189 ;
V_2 -> V_229 = 0 ;
F_114 ( V_2 , V_224 + sizeof( struct V_157 ) +
V_249 ) ;
if ( V_26 -> V_269 == V_270 )
F_101 ( V_2 ) -> V_251 = V_251 ;
V_90 = F_51 ( V_2 , V_278 ) ;
F_155 ( V_2 , V_248 ) ;
V_90 += V_225 ;
V_2 -> V_196 = ( V_2 -> V_149 +
V_225 ) ;
if ( V_279 ) {
V_2 -> V_229 = F_156 (
V_247 , V_238 ,
V_90 + V_226 , V_279 , 0 ) ;
V_247 -> V_229 = F_157 ( V_247 -> V_229 ,
V_2 -> V_229 ) ;
V_90 += V_279 ;
F_158 ( V_247 , V_238 ) ;
}
V_250 = V_277 - V_226 - V_279 ;
if ( V_250 < 0 ) {
V_11 = - V_39 ;
F_19 ( V_2 ) ;
goto error;
} else if ( V_250 > 0 && F_138 ( V_140 , V_90 + V_226 , V_86 , V_250 , V_279 , V_2 ) < 0 ) {
V_11 = - V_286 ;
F_19 ( V_2 ) ;
goto error;
}
V_86 += V_250 ;
V_223 -= V_277 - V_279 ;
V_226 = 0 ;
V_248 = 0 ;
V_249 = 0 ;
F_142 ( & V_26 -> V_227 , V_2 ) ;
continue;
}
if ( V_250 > V_223 )
V_250 = V_223 ;
if ( ! ( V_18 -> V_13 . V_9 -> V_274 & V_283 ) ) {
unsigned int V_287 ;
V_287 = V_2 -> V_3 ;
if ( F_138 ( V_140 , F_51 ( V_2 , V_250 ) ,
V_86 , V_250 , V_287 , V_2 ) < 0 ) {
F_159 ( V_2 , V_287 ) ;
V_11 = - V_286 ;
goto error;
}
} else {
int V_288 = F_101 ( V_2 ) -> V_289 ;
T_8 * V_164 = & F_101 ( V_2 ) -> V_290 [ V_288 - 1 ] ;
struct V_291 * V_291 = V_26 -> V_266 ;
int V_287 = V_26 -> V_267 ;
unsigned int V_168 ;
if ( V_291 && ( V_168 = V_292 - V_287 ) > 0 ) {
if ( V_250 >= V_168 )
V_250 = V_168 ;
if ( V_291 != F_160 ( V_164 ) ) {
if ( V_288 == V_293 ) {
V_11 = - V_76 ;
goto error;
}
F_161 ( V_2 , V_288 , V_291 , V_26 -> V_267 , 0 ) ;
F_162 ( V_2 , V_288 ) ;
V_164 = & F_101 ( V_2 ) -> V_290 [ V_288 ] ;
}
} else if( V_288 < V_293 ) {
if ( V_250 > V_292 )
V_250 = V_292 ;
V_291 = F_163 ( V_26 -> V_255 , 0 ) ;
if ( V_291 == NULL ) {
V_11 = - V_184 ;
goto error;
}
V_26 -> V_266 = V_291 ;
V_26 -> V_267 = 0 ;
F_161 ( V_2 , V_288 , V_291 , 0 , 0 ) ;
V_164 = & F_101 ( V_2 ) -> V_290 [ V_288 ] ;
} else {
V_11 = - V_76 ;
goto error;
}
if ( F_138 ( V_140 ,
F_164 ( V_164 ) + F_165 ( V_164 ) ,
V_86 , V_250 , V_2 -> V_3 , V_2 ) < 0 ) {
V_11 = - V_286 ;
goto error;
}
V_26 -> V_267 += V_250 ;
F_166 ( V_164 , V_250 ) ;
V_2 -> V_3 += V_250 ;
V_2 -> V_187 += V_250 ;
V_2 -> V_181 += V_250 ;
F_167 ( V_250 , & V_26 -> V_284 ) ;
}
V_86 += V_250 ;
V_223 -= V_250 ;
}
return 0 ;
error:
V_246 -> V_223 -= V_223 ;
F_18 ( F_34 ( V_26 ) , V_18 -> V_294 , V_34 ) ;
return V_11 ;
}
static void F_168 ( struct V_243 * V_244 , struct V_50 * V_51 )
{
if ( V_51 -> V_246 . V_47 ) {
F_109 ( V_51 -> V_246 . V_47 -> V_256 ) ;
F_109 ( V_51 -> V_246 . V_47 -> V_257 ) ;
F_109 ( V_51 -> V_246 . V_47 -> V_258 ) ;
F_109 ( V_51 -> V_246 . V_47 -> V_115 ) ;
F_109 ( V_51 -> V_246 . V_47 ) ;
V_51 -> V_246 . V_47 = NULL ;
}
if ( V_244 -> V_246 . V_253 . V_13 ) {
F_110 ( V_244 -> V_246 . V_253 . V_13 ) ;
V_244 -> V_246 . V_253 . V_13 = NULL ;
V_244 -> V_246 . V_253 . V_24 &= ~ V_265 ;
}
memset ( & V_244 -> V_246 . V_259 , 0 , sizeof( V_244 -> V_246 . V_259 ) ) ;
}
int F_169 ( struct V_43 * V_26 )
{
struct V_1 * V_2 , * V_295 ;
struct V_1 * * V_296 ;
struct V_52 V_297 , * V_217 = & V_297 ;
struct V_243 * V_244 = F_147 ( V_26 ) ;
struct V_50 * V_51 = F_35 ( V_26 ) ;
struct V_49 * V_49 = F_34 ( V_26 ) ;
struct V_4 * V_54 ;
struct V_46 * V_47 = V_51 -> V_246 . V_47 ;
struct V_17 * V_18 = (struct V_17 * ) V_244 -> V_246 . V_253 . V_13 ;
struct V_44 * V_45 = & V_244 -> V_246 . V_259 . V_260 . V_261 ;
unsigned char V_55 = V_45 -> V_56 ;
int V_11 = 0 ;
if ( ( V_2 = F_170 ( & V_26 -> V_227 ) ) == NULL )
goto V_202;
V_296 = & ( F_101 ( V_2 ) -> V_182 ) ;
if ( V_2 -> V_90 < F_60 ( V_2 ) )
F_104 ( V_2 , F_171 ( V_2 ) ) ;
while ( ( V_295 = F_170 ( & V_26 -> V_227 ) ) != NULL ) {
F_104 ( V_295 , F_172 ( V_2 ) ) ;
* V_296 = V_295 ;
V_296 = & ( V_295 -> V_82 ) ;
V_2 -> V_3 += V_295 -> V_3 ;
V_2 -> V_187 += V_295 -> V_3 ;
V_2 -> V_181 += V_295 -> V_181 ;
V_295 -> V_179 = NULL ;
V_295 -> V_26 = NULL ;
}
if ( V_51 -> V_262 < V_298 )
V_2 -> V_72 = 1 ;
* V_217 = V_45 -> V_21 ;
F_104 ( V_2 , F_172 ( V_2 ) ) ;
if ( V_47 && V_47 -> V_62 )
F_41 ( V_2 , V_47 , & V_55 ) ;
if ( V_47 && V_47 -> V_61 )
F_42 ( V_2 , V_47 , & V_55 , & V_217 ) ;
F_43 ( V_2 , sizeof( struct V_4 ) ) ;
F_44 ( V_2 ) ;
V_54 = F_2 ( V_2 ) ;
* ( V_65 * ) V_54 = V_45 -> V_66 |
F_46 ( 0x60000000 | ( ( int ) V_51 -> V_246 . V_48 << 20 ) ) ;
V_54 -> V_33 = V_51 -> V_246 . V_33 ;
V_54 -> V_67 = V_55 ;
V_54 -> V_28 = V_45 -> V_28 ;
V_54 -> V_21 = * V_217 ;
V_2 -> V_68 = V_26 -> V_69 ;
V_2 -> V_70 = V_26 -> V_71 ;
F_80 ( V_2 , F_81 ( & V_18 -> V_13 ) ) ;
F_20 ( V_49 , V_18 -> V_294 , V_73 , V_2 -> V_3 ) ;
if ( V_55 == V_87 ) {
struct V_22 * V_23 = F_10 ( F_5 ( V_2 ) ) ;
F_173 ( V_49 , V_23 , F_174 ( V_2 ) -> V_91 ) ;
F_175 ( V_49 , V_23 , V_299 ) ;
}
V_11 = F_6 ( V_2 ) ;
if ( V_11 ) {
if ( V_11 > 0 )
V_11 = F_176 ( V_11 ) ;
if ( V_11 )
goto error;
}
V_202:
F_168 ( V_244 , V_51 ) ;
return V_11 ;
error:
F_18 ( V_49 , V_18 -> V_294 , V_34 ) ;
goto V_202;
}
void F_177 ( struct V_43 * V_26 )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_178 ( & V_26 -> V_227 ) ) != NULL ) {
if ( F_5 ( V_2 ) )
F_18 ( F_34 ( V_26 ) , F_10 ( F_5 ( V_2 ) ) ,
V_34 ) ;
F_19 ( V_2 ) ;
}
F_168 ( F_147 ( V_26 ) , F_35 ( V_26 ) ) ;
}
