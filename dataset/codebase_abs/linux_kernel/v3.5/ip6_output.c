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
static int F_8 ( struct V_1 * V_12 )
{
F_9 ( V_12 ) ;
F_10 ( V_12 , F_11 ( V_12 ) ) ;
V_12 -> V_13 = V_14 ;
V_12 -> V_15 = V_16 ;
F_12 ( ! F_5 ( V_12 ) ) ;
F_13 ( V_12 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_5 ( V_2 ) ;
struct V_19 * V_9 = V_18 -> V_9 ;
struct V_20 * V_21 ;
V_2 -> V_22 = F_3 ( V_23 ) ;
V_2 -> V_9 = V_9 ;
if ( F_15 ( & F_2 ( V_2 ) -> V_24 ) ) {
struct V_25 * V_26 = F_16 ( F_5 ( V_2 ) ) ;
if ( ! ( V_9 -> V_27 & V_28 ) && F_17 ( V_2 -> V_29 ) &&
( ( F_18 ( F_19 ( V_9 ) , V_2 ) &&
! ( F_20 ( V_2 ) -> V_27 & V_30 ) ) ||
F_21 ( V_9 , & F_2 ( V_2 ) -> V_24 ,
& F_2 ( V_2 ) -> V_31 ) ) ) {
struct V_1 * V_12 = F_22 ( V_2 , V_32 ) ;
if ( V_12 )
F_23 ( V_7 , V_33 ,
V_12 , NULL , V_12 -> V_9 ,
F_8 ) ;
if ( F_2 ( V_2 ) -> V_34 == 0 ) {
F_24 ( F_19 ( V_9 ) , V_26 ,
V_35 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
}
F_26 ( F_19 ( V_9 ) , V_26 , V_36 ,
V_2 -> V_3 ) ;
}
F_27 () ;
V_21 = F_28 ( V_18 ) ;
if ( V_21 ) {
int V_37 = F_29 ( V_21 , V_2 ) ;
F_30 () ;
return V_37 ;
}
F_30 () ;
F_31 ( F_19 ( V_18 -> V_9 ) ,
F_16 ( V_18 ) , V_38 ) ;
F_25 ( V_2 ) ;
return - V_39 ;
}
static int F_32 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 > F_33 ( V_2 ) && ! F_34 ( V_2 ) ) ||
F_35 ( F_5 ( V_2 ) ) )
return F_36 ( V_2 , F_14 ) ;
else
return F_14 ( V_2 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_19 * V_9 = F_5 ( V_2 ) -> V_9 ;
struct V_25 * V_26 = F_16 ( F_5 ( V_2 ) ) ;
if ( F_38 ( V_26 -> V_40 . V_41 ) ) {
F_24 ( F_19 ( V_9 ) , V_26 ,
V_35 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
return F_39 ( V_7 , V_33 , V_2 , NULL , V_9 ,
F_32 ,
! ( F_20 ( V_2 ) -> V_27 & V_42 ) ) ;
}
int F_40 ( struct V_43 * V_29 , struct V_1 * V_2 , struct V_44 * V_45 ,
struct V_46 * V_47 , int V_48 )
{
struct V_49 * V_49 = F_41 ( V_29 ) ;
struct V_50 * V_51 = F_42 ( V_29 ) ;
struct V_52 * V_53 = & V_45 -> V_24 ;
struct V_17 * V_18 = F_5 ( V_2 ) ;
struct V_4 * V_54 ;
T_1 V_55 = V_45 -> V_56 ;
int V_57 = V_2 -> V_3 ;
int V_58 = - 1 ;
T_2 V_59 ;
if ( V_47 ) {
unsigned int V_60 ;
V_60 = V_47 -> V_61 + V_47 -> V_62 ;
V_57 += V_60 ;
V_60 += sizeof( struct V_4 ) + F_43 ( V_18 -> V_9 ) ;
if ( F_44 ( V_2 ) < V_60 ) {
struct V_1 * V_63 = F_45 ( V_2 , V_60 ) ;
if ( V_63 == NULL ) {
F_24 ( V_49 , F_16 ( F_5 ( V_2 ) ) ,
V_35 ) ;
F_25 ( V_2 ) ;
return - V_64 ;
}
F_46 ( V_2 ) ;
V_2 = V_63 ;
F_47 ( V_2 , V_29 ) ;
}
if ( V_47 -> V_62 )
F_48 ( V_2 , V_47 , & V_55 ) ;
if ( V_47 -> V_61 )
F_49 ( V_2 , V_47 , & V_55 , & V_53 ) ;
}
F_50 ( V_2 , sizeof( struct V_4 ) ) ;
F_51 ( V_2 ) ;
V_54 = F_2 ( V_2 ) ;
if ( V_51 )
V_58 = V_51 -> V_34 ;
if ( V_58 < 0 )
V_58 = F_52 ( V_18 ) ;
* ( V_65 * ) V_54 = F_53 ( 0x60000000 | ( V_48 << 20 ) ) | V_45 -> V_66 ;
V_54 -> V_6 = F_3 ( V_57 ) ;
V_54 -> V_67 = V_55 ;
V_54 -> V_34 = V_58 ;
V_54 -> V_31 = V_45 -> V_31 ;
V_54 -> V_24 = * V_53 ;
V_2 -> V_68 = V_29 -> V_69 ;
V_2 -> V_70 = V_29 -> V_71 ;
V_59 = F_54 ( V_18 ) ;
if ( ( V_2 -> V_3 <= V_59 ) || V_2 -> V_72 || F_34 ( V_2 ) ) {
F_26 ( V_49 , F_16 ( F_5 ( V_2 ) ) ,
V_73 , V_2 -> V_3 ) ;
return F_23 ( V_7 , V_8 , V_2 , NULL ,
V_18 -> V_9 , V_10 ) ;
}
F_55 ( L_1 ) ;
V_2 -> V_9 = V_18 -> V_9 ;
F_56 ( V_2 , V_74 , 0 , V_59 ) ;
F_24 ( V_49 , F_16 ( F_5 ( V_2 ) ) , V_75 ) ;
F_25 ( V_2 ) ;
return - V_76 ;
}
int F_57 ( struct V_43 * V_29 , struct V_1 * V_2 , struct V_19 * V_9 ,
const struct V_52 * V_31 , const struct V_52 * V_24 ,
int V_55 , int V_3 )
{
struct V_50 * V_51 = F_42 ( V_29 ) ;
struct V_4 * V_54 ;
V_2 -> V_22 = F_3 ( V_23 ) ;
V_2 -> V_9 = V_9 ;
F_51 ( V_2 ) ;
F_58 ( V_2 , sizeof( struct V_4 ) ) ;
V_54 = F_2 ( V_2 ) ;
* ( V_65 * ) V_54 = F_53 ( 0x60000000 ) ;
V_54 -> V_6 = F_3 ( V_3 ) ;
V_54 -> V_67 = V_55 ;
V_54 -> V_34 = V_51 -> V_34 ;
V_54 -> V_31 = * V_31 ;
V_54 -> V_24 = * V_24 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , int V_77 )
{
struct V_78 * V_79 ;
struct V_43 * V_80 = NULL ;
F_60 ( & V_81 ) ;
for ( V_79 = V_78 ; V_79 ; V_79 = V_79 -> V_82 ) {
struct V_43 * V_29 = V_79 -> V_29 ;
if ( V_29 && V_79 -> V_77 == V_77 &&
( ! V_29 -> V_83 ||
V_29 -> V_83 == V_2 -> V_9 -> V_84 ) ) {
if ( V_80 ) {
struct V_1 * V_63 = F_22 ( V_2 , V_32 ) ;
if ( V_63 )
F_61 ( V_80 , V_63 ) ;
}
V_80 = V_29 ;
}
}
if ( V_80 ) {
F_61 ( V_80 , V_2 ) ;
F_62 ( & V_81 ) ;
return 1 ;
}
F_62 ( & V_81 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_4 * V_54 = F_2 ( V_2 ) ;
T_1 V_67 = V_54 -> V_67 ;
T_3 V_85 ;
int V_86 ;
if ( F_64 ( V_67 ) ) {
V_86 = F_65 ( V_2 , sizeof( * V_54 ) , & V_67 , & V_85 ) ;
if ( V_86 < 0 )
return 0 ;
} else
V_86 = sizeof( struct V_4 ) ;
if ( V_67 == V_87 ) {
struct V_88 * V_89 ;
if ( ! F_66 ( V_2 , ( F_67 ( V_2 ) +
V_86 + 1 - V_2 -> V_90 ) ) )
return 0 ;
V_89 = (struct V_88 * ) ( F_67 ( V_2 ) + V_86 ) ;
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
if ( F_68 ( & V_54 -> V_24 ) & V_97 ) {
F_69 ( V_2 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_70 ( struct V_1 * V_2 )
{
return V_10 ( V_2 ) ;
}
int F_71 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_5 ( V_2 ) ;
struct V_4 * V_54 = F_2 ( V_2 ) ;
struct V_98 * V_47 = F_20 ( V_2 ) ;
struct V_49 * V_49 = F_19 ( V_18 -> V_9 ) ;
T_2 V_59 ;
if ( V_49 -> V_99 . V_100 -> V_101 == 0 )
goto error;
if ( F_72 ( V_2 ) )
goto V_102;
if ( ! F_73 ( NULL , V_103 , V_2 ) ) {
F_24 ( V_49 , F_16 ( V_18 ) , V_104 ) ;
goto V_102;
}
if ( V_2 -> V_13 != V_105 )
goto V_102;
F_74 ( V_2 ) ;
if ( V_47 -> V_79 ) {
T_1 * V_106 = F_67 ( V_2 ) + V_47 -> V_79 ;
if ( F_59 ( V_2 , ( V_106 [ 2 ] << 8 ) + V_106 [ 3 ] ) )
return 0 ;
}
if ( V_54 -> V_34 <= 1 ) {
V_2 -> V_9 = V_18 -> V_9 ;
F_56 ( V_2 , V_107 , V_108 , 0 ) ;
F_31 ( V_49 ,
F_16 ( V_18 ) , V_109 ) ;
F_25 ( V_2 ) ;
return - V_110 ;
}
if ( V_49 -> V_99 . V_100 -> V_111 &&
F_75 ( & V_112 , V_49 , & V_54 -> V_24 , V_2 -> V_9 , 0 ) ) {
int V_113 = F_63 ( V_2 ) ;
if ( V_113 > 0 )
return F_76 ( V_2 ) ;
else if ( V_113 < 0 ) {
F_24 ( V_49 , F_16 ( V_18 ) ,
V_104 ) ;
goto V_102;
}
}
if ( ! F_77 ( V_2 ) ) {
F_24 ( V_49 , F_16 ( V_18 ) , V_104 ) ;
goto V_102;
}
V_18 = F_5 ( V_2 ) ;
if ( V_2 -> V_9 == V_18 -> V_9 && V_47 -> V_114 == 0 && ! F_78 ( V_2 ) ) {
struct V_52 * V_115 = NULL ;
struct V_116 * V_117 ;
V_117 = (struct V_116 * ) V_18 ;
if ( V_117 -> V_118 & V_119 )
V_115 = & V_117 -> V_120 ;
else
V_115 = & V_54 -> V_24 ;
if ( ! V_117 -> V_121 )
F_79 ( V_117 , 1 ) ;
if ( F_80 ( V_117 -> V_121 , 1 * V_122 ) )
F_81 ( V_2 , V_115 ) ;
} else {
int V_123 = F_68 ( & V_54 -> V_31 ) ;
if ( V_123 == V_124 ||
V_123 & ( V_125 | V_126 ) )
goto error;
if ( V_123 & V_97 ) {
F_56 ( V_2 , V_127 ,
V_128 , 0 ) ;
goto error;
}
}
V_59 = F_54 ( V_18 ) ;
if ( V_59 < V_129 )
V_59 = V_129 ;
if ( V_2 -> V_3 > V_59 && ! F_34 ( V_2 ) ) {
V_2 -> V_9 = V_18 -> V_9 ;
F_56 ( V_2 , V_74 , 0 , V_59 ) ;
F_31 ( V_49 ,
F_16 ( V_18 ) , V_130 ) ;
F_31 ( V_49 ,
F_16 ( V_18 ) , V_75 ) ;
F_25 ( V_2 ) ;
return - V_76 ;
}
if ( F_82 ( V_2 , V_18 -> V_9 -> V_131 ) ) {
F_24 ( V_49 , F_16 ( V_18 ) , V_35 ) ;
goto V_102;
}
V_54 = F_2 ( V_2 ) ;
V_54 -> V_34 -- ;
F_31 ( V_49 , F_16 ( V_18 ) , V_132 ) ;
F_83 ( V_49 , F_16 ( V_18 ) , V_133 , V_2 -> V_3 ) ;
return F_23 ( V_7 , V_134 , V_2 , V_2 -> V_9 , V_18 -> V_9 ,
F_70 ) ;
error:
F_31 ( V_49 , F_16 ( V_18 ) , V_135 ) ;
V_102:
F_25 ( V_2 ) ;
return - V_39 ;
}
static void F_84 ( struct V_1 * V_136 , struct V_1 * V_137 )
{
V_136 -> V_13 = V_137 -> V_13 ;
V_136 -> V_68 = V_137 -> V_68 ;
V_136 -> V_22 = V_137 -> V_22 ;
F_85 ( V_136 ) ;
F_86 ( V_136 , F_87 ( F_5 ( V_137 ) ) ) ;
V_136 -> V_9 = V_137 -> V_9 ;
V_136 -> V_70 = V_137 -> V_70 ;
#ifdef F_88
V_136 -> V_138 = V_137 -> V_138 ;
#endif
F_89 ( V_136 , V_137 ) ;
#if F_90 ( V_139 ) || \
F_90 ( V_140 )
V_136 -> V_141 = V_137 -> V_141 ;
#endif
F_91 ( V_136 , V_137 ) ;
}
int F_92 ( struct V_1 * V_2 , T_1 * * V_67 )
{
T_4 V_86 = sizeof( struct V_4 ) ;
struct V_142 * V_143 =
(struct V_142 * ) ( F_2 ( V_2 ) + 1 ) ;
unsigned int V_144 = V_2 -> V_145 - V_2 -> V_146 ;
int V_147 = 0 ;
* V_67 = & F_2 ( V_2 ) -> V_67 ;
while ( V_86 + 1 <= V_144 ) {
switch ( * * V_67 ) {
case V_148 :
break;
case V_149 :
V_147 = 1 ;
break;
case V_150 :
#if F_90 ( V_151 ) || F_90 ( V_152 )
if ( F_93 ( V_2 , V_86 , V_153 ) >= 0 )
break;
#endif
if ( V_147 )
return V_86 ;
break;
default :
return V_86 ;
}
V_86 += F_94 ( V_143 ) ;
* V_67 = & V_143 -> V_67 ;
V_143 = (struct V_142 * ) ( F_67 ( V_2 ) +
V_86 ) ;
}
return V_86 ;
}
void F_95 ( struct V_154 * V_155 , struct V_116 * V_117 )
{
static T_5 V_156 ;
int V_157 , V_158 ;
if ( V_117 && ! ( V_117 -> V_18 . V_27 & V_159 ) ) {
struct V_160 * V_161 ;
if ( ! V_117 -> V_121 )
F_79 ( V_117 , 1 ) ;
V_161 = V_117 -> V_121 ;
if ( V_161 ) {
V_155 -> V_162 = F_53 ( F_96 ( V_161 , 0 ) ) ;
return;
}
}
do {
V_157 = F_97 ( & V_156 ) ;
V_158 = V_157 + 1 ;
if ( ! V_158 )
V_158 = 1 ;
} while ( F_98 ( & V_156 , V_157 , V_158 ) != V_157 );
V_155 -> V_162 = F_53 ( V_158 ) ;
}
int F_36 ( struct V_1 * V_2 , int (* F_99)( struct V_1 * ) )
{
struct V_1 * V_163 ;
struct V_116 * V_117 = (struct V_116 * ) F_5 ( V_2 ) ;
struct V_50 * V_51 = V_2 -> V_29 ? F_42 ( V_2 -> V_29 ) : NULL ;
struct V_4 * V_164 ;
struct V_154 * V_165 ;
unsigned int V_59 , V_166 , V_167 , V_3 ;
int V_168 , V_169 ;
V_65 V_170 = 0 ;
int V_106 , V_86 = 0 , V_11 = 0 ;
T_1 * V_171 , V_67 = 0 ;
struct V_49 * V_49 = F_19 ( F_5 ( V_2 ) -> V_9 ) ;
V_166 = F_92 ( V_2 , & V_171 ) ;
V_67 = * V_171 ;
V_59 = F_33 ( V_2 ) ;
if ( F_38 ( ! V_2 -> V_72 && V_2 -> V_3 > V_59 ) ) {
if ( V_2 -> V_29 && F_35 ( F_5 ( V_2 ) ) )
F_100 ( V_2 -> V_29 , V_172 ) ;
V_2 -> V_9 = F_5 ( V_2 ) -> V_9 ;
F_56 ( V_2 , V_74 , 0 , V_59 ) ;
F_24 ( V_49 , F_16 ( F_5 ( V_2 ) ) ,
V_75 ) ;
F_25 ( V_2 ) ;
return - V_76 ;
}
if ( V_51 && V_51 -> V_173 < V_59 ) {
if ( V_51 -> V_173 )
V_59 = V_51 -> V_173 ;
}
V_59 -= V_166 + sizeof( struct V_154 ) ;
if ( F_101 ( V_2 ) ) {
int V_174 = F_102 ( V_2 ) ;
struct V_1 * V_175 ;
if ( V_174 - V_166 > V_59 ||
( ( V_174 - V_166 ) & 7 ) ||
F_103 ( V_2 ) )
goto V_176;
F_104 (skb, frag) {
if ( V_163 -> V_3 > V_59 ||
( ( V_163 -> V_3 & 7 ) && V_163 -> V_82 ) ||
F_44 ( V_163 ) < V_166 )
goto V_177;
if ( F_105 ( V_163 ) )
goto V_177;
F_106 ( V_163 -> V_29 ) ;
if ( V_2 -> V_29 ) {
V_163 -> V_29 = V_2 -> V_29 ;
V_163 -> V_178 = V_179 ;
}
V_2 -> V_180 -= V_163 -> V_180 ;
}
V_11 = 0 ;
V_86 = 0 ;
V_163 = F_107 ( V_2 ) -> V_181 ;
F_108 ( V_2 ) ;
* V_171 = V_182 ;
V_164 = F_109 ( F_67 ( V_2 ) , V_166 , V_32 ) ;
if ( ! V_164 ) {
F_24 ( V_49 , F_16 ( F_5 ( V_2 ) ) ,
V_75 ) ;
return - V_183 ;
}
F_10 ( V_2 , V_166 ) ;
V_165 = (struct V_154 * ) F_110 ( V_2 , sizeof( struct V_154 ) ) ;
F_110 ( V_2 , V_166 ) ;
F_51 ( V_2 ) ;
memcpy ( F_67 ( V_2 ) , V_164 , V_166 ) ;
F_95 ( V_165 , V_117 ) ;
V_165 -> V_67 = V_67 ;
V_165 -> V_184 = 0 ;
V_165 -> V_85 = F_3 ( V_185 ) ;
V_170 = V_165 -> V_162 ;
V_174 = F_102 ( V_2 ) ;
V_2 -> V_186 = V_174 - F_111 ( V_2 ) ;
V_2 -> V_3 = V_174 ;
F_2 ( V_2 ) -> V_6 = F_3 ( V_174 -
sizeof( struct V_4 ) ) ;
F_112 ( & V_117 -> V_18 ) ;
for (; ; ) {
if ( V_163 ) {
V_163 -> V_15 = V_187 ;
F_113 ( V_163 ) ;
V_165 = (struct V_154 * ) F_110 ( V_163 , sizeof( struct V_154 ) ) ;
F_110 ( V_163 , V_166 ) ;
F_51 ( V_163 ) ;
memcpy ( F_67 ( V_163 ) , V_164 ,
V_166 ) ;
V_86 += V_2 -> V_3 - V_166 - sizeof( struct V_154 ) ;
V_165 -> V_67 = V_67 ;
V_165 -> V_184 = 0 ;
V_165 -> V_85 = F_3 ( V_86 ) ;
if ( V_163 -> V_82 != NULL )
V_165 -> V_85 |= F_3 ( V_185 ) ;
V_165 -> V_162 = V_170 ;
F_2 ( V_163 ) -> V_6 =
F_3 ( V_163 -> V_3 -
sizeof( struct V_4 ) ) ;
F_84 ( V_163 , V_2 ) ;
}
V_11 = F_99 ( V_2 ) ;
if( ! V_11 )
F_24 ( V_49 , F_16 ( & V_117 -> V_18 ) ,
V_188 ) ;
if ( V_11 || ! V_163 )
break;
V_2 = V_163 ;
V_163 = V_2 -> V_82 ;
V_2 -> V_82 = NULL ;
}
F_114 ( V_164 ) ;
if ( V_11 == 0 ) {
F_24 ( V_49 , F_16 ( & V_117 -> V_18 ) ,
V_189 ) ;
F_115 ( & V_117 -> V_18 ) ;
return 0 ;
}
while ( V_163 ) {
V_2 = V_163 -> V_82 ;
F_25 ( V_163 ) ;
V_163 = V_2 ;
}
F_24 ( V_49 , F_16 ( & V_117 -> V_18 ) ,
V_75 ) ;
F_115 ( & V_117 -> V_18 ) ;
return V_11 ;
V_177:
F_104 (skb, frag2) {
if ( V_175 == V_163 )
break;
V_175 -> V_29 = NULL ;
V_175 -> V_178 = NULL ;
V_2 -> V_180 += V_175 -> V_180 ;
}
}
V_176:
if ( ( V_2 -> V_15 == V_190 ) &&
F_116 ( V_2 ) )
goto V_191;
V_167 = V_2 -> V_3 - V_166 ;
V_106 = V_166 ;
* V_171 = V_182 ;
V_168 = F_43 ( V_117 -> V_18 . V_9 ) ;
V_169 = V_117 -> V_18 . V_9 -> V_192 ;
while( V_167 > 0 ) {
V_3 = V_167 ;
if ( V_3 > V_59 )
V_3 = V_59 ;
if ( V_3 < V_167 ) {
V_3 &= ~ 7 ;
}
if ( ( V_163 = F_117 ( V_3 + V_166 + sizeof( struct V_154 ) +
V_168 + V_169 , V_32 ) ) == NULL ) {
F_118 ( V_193 L_2 ) ;
F_24 ( V_49 , F_16 ( F_5 ( V_2 ) ) ,
V_75 ) ;
V_11 = - V_183 ;
goto V_191;
}
F_84 ( V_163 , V_2 ) ;
F_119 ( V_163 , V_168 ) ;
F_58 ( V_163 , V_3 + V_166 + sizeof( struct V_154 ) ) ;
F_51 ( V_163 ) ;
V_165 = (struct V_154 * ) ( F_67 ( V_163 ) + V_166 ) ;
V_163 -> V_194 = ( V_163 -> V_146 + V_166 +
sizeof( struct V_154 ) ) ;
if ( V_2 -> V_29 )
F_47 ( V_163 , V_2 -> V_29 ) ;
F_120 ( V_2 , F_67 ( V_163 ) , V_166 ) ;
V_165 -> V_67 = V_67 ;
V_165 -> V_184 = 0 ;
if ( ! V_170 ) {
F_95 ( V_165 , V_117 ) ;
V_170 = V_165 -> V_162 ;
} else
V_165 -> V_162 = V_170 ;
if ( F_121 ( V_2 , V_106 , F_122 ( V_163 ) , V_3 ) )
F_123 () ;
V_167 -= V_3 ;
V_165 -> V_85 = F_3 ( V_86 ) ;
if ( V_167 > 0 )
V_165 -> V_85 |= F_3 ( V_185 ) ;
F_2 ( V_163 ) -> V_6 = F_3 ( V_163 -> V_3 -
sizeof( struct V_4 ) ) ;
V_106 += V_3 ;
V_86 += V_3 ;
V_11 = F_99 ( V_163 ) ;
if ( V_11 )
goto V_191;
F_24 ( V_49 , F_16 ( F_5 ( V_2 ) ) ,
V_188 ) ;
}
F_24 ( V_49 , F_16 ( F_5 ( V_2 ) ) ,
V_189 ) ;
F_46 ( V_2 ) ;
return V_11 ;
V_191:
F_24 ( V_49 , F_16 ( F_5 ( V_2 ) ) ,
V_75 ) ;
F_25 ( V_2 ) ;
return V_11 ;
}
static inline int F_124 ( const struct V_195 * V_196 ,
const struct V_52 * V_197 ,
const struct V_52 * V_198 )
{
return ( V_196 -> V_199 != 128 || ! F_125 ( V_197 , & V_196 -> V_200 ) ) &&
( V_198 == NULL || ! F_125 ( V_197 , V_198 ) ) ;
}
static struct V_17 * F_126 ( struct V_43 * V_29 ,
struct V_17 * V_18 ,
const struct V_44 * V_45 )
{
struct V_50 * V_51 = F_42 ( V_29 ) ;
struct V_116 * V_117 = (struct V_116 * ) V_18 ;
if ( ! V_18 )
goto V_201;
if ( F_124 ( & V_117 -> V_202 , & V_45 -> V_24 , V_51 -> V_203 ) ||
#ifdef F_127
F_124 ( & V_117 -> V_204 , & V_45 -> V_31 , V_51 -> V_205 ) ||
#endif
( V_45 -> V_206 && V_45 -> V_206 != V_18 -> V_9 -> V_84 ) ) {
F_115 ( V_18 ) ;
V_18 = NULL ;
}
V_201:
return V_18 ;
}
static int F_128 ( struct V_43 * V_29 ,
struct V_17 * * V_18 , struct V_44 * V_45 )
{
struct V_49 * V_49 = F_41 ( V_29 ) ;
#ifdef F_129
struct V_20 * V_207 ;
#endif
int V_11 ;
if ( * V_18 == NULL )
* V_18 = F_130 ( V_49 , V_29 , V_45 ) ;
if ( ( V_11 = ( * V_18 ) -> error ) )
goto V_208;
if ( F_131 ( & V_45 -> V_31 ) ) {
struct V_116 * V_117 = (struct V_116 * ) * V_18 ;
V_11 = F_132 ( V_49 , V_117 , & V_45 -> V_24 ,
V_29 ? F_42 ( V_29 ) -> V_209 : 0 ,
& V_45 -> V_31 ) ;
if ( V_11 )
goto V_208;
}
#ifdef F_129
F_27 () ;
V_207 = F_28 ( * V_18 ) ;
if ( V_207 && ! ( V_207 -> V_210 & V_211 ) ) {
struct V_212 * V_213 ;
struct V_44 V_214 ;
int V_215 ;
F_30 () ;
V_213 = F_133 ( V_49 , & V_45 -> V_31 ,
( * V_18 ) -> V_9 , 1 ) ;
V_215 = ( V_213 && V_213 -> V_27 & V_216 ) ;
if ( V_213 )
F_134 ( V_213 ) ;
if ( V_215 ) {
F_115 ( * V_18 ) ;
memcpy ( & V_214 , V_45 , sizeof( struct V_44 ) ) ;
memset ( & V_214 . V_24 , 0 , sizeof( struct V_52 ) ) ;
* V_18 = F_130 ( V_49 , V_29 , & V_214 ) ;
if ( ( V_11 = ( * V_18 ) -> error ) )
goto V_208;
}
} else {
F_30 () ;
}
#endif
return 0 ;
V_208:
if ( V_11 == - V_217 )
F_31 ( V_49 , NULL , V_38 ) ;
F_115 ( * V_18 ) ;
* V_18 = NULL ;
return V_11 ;
}
int F_135 ( struct V_43 * V_29 , struct V_17 * * V_18 , struct V_44 * V_45 )
{
* V_18 = NULL ;
return F_128 ( V_29 , V_18 , V_45 ) ;
}
struct V_17 * F_136 ( struct V_43 * V_29 , struct V_44 * V_45 ,
const struct V_52 * V_218 ,
bool V_219 )
{
struct V_17 * V_18 = NULL ;
int V_11 ;
V_11 = F_128 ( V_29 , & V_18 , V_45 ) ;
if ( V_11 )
return F_137 ( V_11 ) ;
if ( V_218 )
V_45 -> V_24 = * V_218 ;
if ( V_219 )
V_45 -> V_220 |= V_221 ;
return F_138 ( F_41 ( V_29 ) , V_18 , F_139 ( V_45 ) , V_29 , 0 ) ;
}
struct V_17 * F_140 ( struct V_43 * V_29 , struct V_44 * V_45 ,
const struct V_52 * V_218 ,
bool V_219 )
{
struct V_17 * V_18 = F_141 ( V_29 , F_42 ( V_29 ) -> V_222 ) ;
int V_11 ;
V_18 = F_126 ( V_29 , V_18 , V_45 ) ;
V_11 = F_128 ( V_29 , & V_18 , V_45 ) ;
if ( V_11 )
return F_137 ( V_11 ) ;
if ( V_218 )
V_45 -> V_24 = * V_218 ;
if ( V_219 )
V_45 -> V_220 |= V_221 ;
return F_138 ( F_41 ( V_29 ) , V_18 , F_139 ( V_45 ) , V_29 , 0 ) ;
}
static inline int F_142 ( struct V_43 * V_29 ,
int F_143 ( void * V_137 , char * V_136 , int V_86 , int V_3 ,
int V_223 , struct V_1 * V_2 ) ,
void * V_137 , int V_224 , int V_225 , int V_226 ,
int V_227 , int V_59 , unsigned int V_27 ,
struct V_116 * V_117 )
{
struct V_1 * V_2 ;
int V_11 ;
if ( ( V_2 = F_144 ( & V_29 -> V_228 ) ) == NULL ) {
V_2 = F_145 ( V_29 ,
V_225 + V_226 + V_227 + 20 ,
( V_27 & V_229 ) , & V_11 ) ;
if ( V_2 == NULL )
return V_11 ;
F_119 ( V_2 , V_225 ) ;
F_58 ( V_2 , V_226 + V_227 ) ;
F_51 ( V_2 ) ;
V_2 -> V_194 = V_2 -> V_146 + V_226 ;
V_2 -> V_15 = V_190 ;
V_2 -> V_230 = 0 ;
}
V_11 = F_146 ( V_29 , V_2 , F_143 , V_137 ,
( V_224 - V_227 ) ) ;
if ( ! V_11 ) {
struct V_154 V_155 ;
F_107 ( V_2 ) -> V_231 = ( V_59 - V_226 -
sizeof( struct V_154 ) ) & ~ 7 ;
F_107 ( V_2 ) -> V_232 = V_233 ;
F_95 ( & V_155 , V_117 ) ;
F_107 ( V_2 ) -> V_234 = V_155 . V_162 ;
F_147 ( & V_29 -> V_228 , V_2 ) ;
return 0 ;
}
F_25 ( V_2 ) ;
return V_11 ;
}
static inline struct V_142 * F_148 ( struct V_142 * V_235 ,
T_6 V_236 )
{
return V_235 ? F_109 ( V_235 , ( V_235 -> V_237 + 1 ) * 8 , V_236 ) : NULL ;
}
static inline struct V_238 * F_149 ( struct V_238 * V_235 ,
T_6 V_236 )
{
return V_235 ? F_109 ( V_235 , ( V_235 -> V_237 + 1 ) * 8 , V_236 ) : NULL ;
}
static void F_150 ( int * V_59 ,
int * V_239 ,
unsigned int V_226 ,
struct V_1 * V_2 ,
struct V_116 * V_117 )
{
if ( ! ( V_117 -> V_18 . V_27 & V_240 ) ) {
if ( V_2 == NULL ) {
* V_59 = * V_59 - V_117 -> V_18 . V_241 ;
} else {
* V_59 = F_54 ( V_117 -> V_18 . V_242 ) ;
}
* V_239 = ( ( * V_59 - V_226 ) & ~ 7 )
+ V_226 - sizeof( struct V_154 ) ;
}
}
int F_151 ( struct V_43 * V_29 , int F_143 ( void * V_137 , char * V_136 ,
int V_86 , int V_3 , int V_223 , struct V_1 * V_2 ) ,
void * V_137 , int V_224 , int V_227 ,
int V_58 , int V_48 , struct V_46 * V_47 , struct V_44 * V_45 ,
struct V_116 * V_117 , unsigned int V_27 , int V_243 )
{
struct V_244 * V_245 = F_152 ( V_29 ) ;
struct V_50 * V_51 = F_42 ( V_29 ) ;
struct V_246 * V_247 ;
struct V_1 * V_2 , * V_248 = NULL ;
unsigned int V_239 , V_226 ;
int V_249 ;
int V_250 ;
int V_225 ;
int V_59 ;
int V_251 ;
int V_11 ;
int V_86 = 0 ;
T_7 V_252 = 0 ;
if ( V_27 & V_253 )
return 0 ;
V_247 = & V_245 -> V_247 . V_254 ;
if ( F_153 ( & V_29 -> V_228 ) ) {
if ( V_47 ) {
if ( F_12 ( V_51 -> V_247 . V_47 ) )
return - V_39 ;
V_51 -> V_247 . V_47 = F_154 ( V_47 -> V_255 , V_29 -> V_256 ) ;
if ( F_38 ( V_51 -> V_247 . V_47 == NULL ) )
return - V_64 ;
V_51 -> V_247 . V_47 -> V_255 = V_47 -> V_255 ;
V_51 -> V_247 . V_47 -> V_62 = V_47 -> V_62 ;
V_51 -> V_247 . V_47 -> V_61 = V_47 -> V_61 ;
V_51 -> V_247 . V_47 -> V_257 = F_148 ( V_47 -> V_257 ,
V_29 -> V_256 ) ;
if ( V_47 -> V_257 && ! V_51 -> V_247 . V_47 -> V_257 )
return - V_64 ;
V_51 -> V_247 . V_47 -> V_258 = F_148 ( V_47 -> V_258 ,
V_29 -> V_256 ) ;
if ( V_47 -> V_258 && ! V_51 -> V_247 . V_47 -> V_258 )
return - V_64 ;
V_51 -> V_247 . V_47 -> V_259 = F_148 ( V_47 -> V_259 ,
V_29 -> V_256 ) ;
if ( V_47 -> V_259 && ! V_51 -> V_247 . V_47 -> V_259 )
return - V_64 ;
V_51 -> V_247 . V_47 -> V_114 = F_149 ( V_47 -> V_114 ,
V_29 -> V_256 ) ;
if ( V_47 -> V_114 && ! V_51 -> V_247 . V_47 -> V_114 )
return - V_64 ;
}
F_112 ( & V_117 -> V_18 ) ;
V_247 -> V_18 = & V_117 -> V_18 ;
V_245 -> V_247 . V_260 . V_261 . V_262 = * V_45 ;
V_51 -> V_247 . V_34 = V_58 ;
V_51 -> V_247 . V_48 = V_48 ;
if ( V_117 -> V_18 . V_27 & V_240 )
V_59 = V_51 -> V_263 == V_264 ?
V_117 -> V_18 . V_9 -> V_59 : F_54 ( & V_117 -> V_18 ) ;
else
V_59 = V_51 -> V_263 == V_264 ?
V_117 -> V_18 . V_9 -> V_59 : F_54 ( V_117 -> V_18 . V_242 ) ;
if ( V_51 -> V_173 < V_59 ) {
if ( V_51 -> V_173 )
V_59 = V_51 -> V_173 ;
}
V_247 -> V_265 = V_59 ;
if ( F_35 ( V_117 -> V_18 . V_242 ) )
V_247 -> V_27 |= V_266 ;
V_247 -> V_224 = 0 ;
V_29 -> V_267 = NULL ;
V_29 -> V_268 = 0 ;
V_249 = ( V_47 ? V_47 -> V_62 : 0 ) - V_117 -> V_269 ;
V_224 += V_249 ;
V_227 += V_249 ;
V_250 = V_117 -> V_18 . V_241 ;
} else {
V_117 = (struct V_116 * ) V_247 -> V_18 ;
V_45 = & V_245 -> V_247 . V_260 . V_261 . V_262 ;
V_47 = V_51 -> V_247 . V_47 ;
V_227 = 0 ;
V_249 = 0 ;
V_250 = 0 ;
V_59 = V_247 -> V_265 ;
}
V_225 = F_43 ( V_117 -> V_18 . V_9 ) ;
V_226 = sizeof( struct V_4 ) + V_117 -> V_269 +
( V_47 ? V_47 -> V_61 : 0 ) ;
V_239 = ( ( V_59 - V_226 ) & ~ 7 ) + V_226 - sizeof( struct V_154 ) ;
if ( V_59 <= sizeof( struct V_4 ) + V_5 ) {
if ( V_247 -> V_224 + V_224 > sizeof( struct V_4 ) + V_5 - V_226 ) {
F_155 ( V_29 , V_76 , V_45 , V_59 - V_249 ) ;
return - V_76 ;
}
}
if ( V_29 -> V_270 == V_271 ) {
V_11 = F_156 ( V_29 , & V_252 ) ;
if ( V_11 )
goto error;
}
V_247 -> V_224 += V_224 ;
if ( V_224 > V_59 ) {
int V_55 = V_29 -> V_272 ;
if ( V_243 && ( V_55 == V_273 || V_55 == V_274 ) ) {
F_157 ( V_29 , V_45 , V_59 - V_249 ) ;
return - V_76 ;
}
if ( V_55 == V_273 &&
( V_117 -> V_18 . V_9 -> V_275 & V_276 ) ) {
V_11 = F_142 ( V_29 , F_143 , V_137 , V_224 ,
V_225 , V_226 ,
V_227 , V_59 , V_27 , V_117 ) ;
if ( V_11 )
goto error;
return 0 ;
}
}
if ( ( V_2 = F_144 ( & V_29 -> V_228 ) ) == NULL )
goto V_277;
while ( V_224 > 0 ) {
V_251 = ( V_247 -> V_224 <= V_59 && ! ( V_247 -> V_27 & V_266 ) ? V_59 : V_239 ) - V_2 -> V_3 ;
if ( V_251 < V_224 )
V_251 = V_239 - V_2 -> V_3 ;
if ( V_251 <= 0 ) {
char * V_90 ;
unsigned int V_278 ;
unsigned int V_279 ;
unsigned int V_280 ;
unsigned int V_281 ;
V_277:
if ( V_2 )
V_280 = V_2 -> V_3 - V_239 ;
else
V_280 = 0 ;
if ( V_2 == NULL || V_248 == NULL )
F_150 ( & V_59 , & V_239 ,
V_226 , V_2 , V_117 ) ;
V_248 = V_2 ;
V_278 = V_224 + V_280 ;
if ( V_278 > ( V_247 -> V_224 <= V_59 && ! ( V_247 -> V_27 & V_266 ) ? V_59 : V_239 ) - V_226 )
V_278 = V_239 - V_226 - V_117 -> V_18 . V_282 ;
if ( ( V_27 & V_283 ) &&
! ( V_117 -> V_18 . V_9 -> V_275 & V_284 ) )
V_281 = V_59 ;
else
V_281 = V_278 + V_226 ;
V_281 += V_250 ;
if ( V_278 != V_224 + V_280 ) {
V_278 += V_117 -> V_18 . V_282 ;
}
V_281 += V_117 -> V_18 . V_282 ;
V_279 = V_278 + V_226 ;
V_281 += sizeof( struct V_154 ) ;
if ( V_227 ) {
V_2 = F_145 ( V_29 ,
V_281 + V_225 ,
( V_27 & V_229 ) , & V_11 ) ;
} else {
V_2 = NULL ;
if ( F_97 ( & V_29 -> V_285 ) <=
2 * V_29 -> V_286 )
V_2 = F_158 ( V_29 ,
V_281 + V_225 , 1 ,
V_29 -> V_256 ) ;
if ( F_38 ( V_2 == NULL ) )
V_11 = - V_64 ;
else {
V_252 = 0 ;
}
}
if ( V_2 == NULL )
goto error;
V_2 -> V_15 = V_187 ;
V_2 -> V_230 = 0 ;
F_119 ( V_2 , V_225 + sizeof( struct V_154 ) +
V_250 ) ;
if ( V_29 -> V_270 == V_271 )
F_107 ( V_2 ) -> V_252 = V_252 ;
V_90 = F_58 ( V_2 , V_279 ) ;
F_159 ( V_2 , V_249 ) ;
V_90 += V_226 ;
V_2 -> V_194 = ( V_2 -> V_146 +
V_226 ) ;
if ( V_280 ) {
V_2 -> V_230 = F_160 (
V_248 , V_239 ,
V_90 + V_227 , V_280 , 0 ) ;
V_248 -> V_230 = F_161 ( V_248 -> V_230 ,
V_2 -> V_230 ) ;
V_90 += V_280 ;
F_162 ( V_248 , V_239 ) ;
}
V_251 = V_278 - V_227 - V_280 ;
if ( V_251 < 0 ) {
V_11 = - V_39 ;
F_25 ( V_2 ) ;
goto error;
} else if ( V_251 > 0 && F_143 ( V_137 , V_90 + V_227 , V_86 , V_251 , V_280 , V_2 ) < 0 ) {
V_11 = - V_287 ;
F_25 ( V_2 ) ;
goto error;
}
V_86 += V_251 ;
V_224 -= V_278 - V_280 ;
V_227 = 0 ;
V_249 = 0 ;
V_250 = 0 ;
F_147 ( & V_29 -> V_228 , V_2 ) ;
continue;
}
if ( V_251 > V_224 )
V_251 = V_224 ;
if ( ! ( V_117 -> V_18 . V_9 -> V_275 & V_284 ) ) {
unsigned int V_288 ;
V_288 = V_2 -> V_3 ;
if ( F_143 ( V_137 , F_58 ( V_2 , V_251 ) ,
V_86 , V_251 , V_288 , V_2 ) < 0 ) {
F_163 ( V_2 , V_288 ) ;
V_11 = - V_287 ;
goto error;
}
} else {
int V_289 = F_107 ( V_2 ) -> V_290 ;
T_8 * V_163 = & F_107 ( V_2 ) -> V_291 [ V_289 - 1 ] ;
struct V_292 * V_292 = V_29 -> V_267 ;
int V_288 = V_29 -> V_268 ;
unsigned int V_167 ;
if ( V_292 && ( V_167 = V_293 - V_288 ) > 0 ) {
if ( V_251 >= V_167 )
V_251 = V_167 ;
if ( V_292 != F_164 ( V_163 ) ) {
if ( V_289 == V_294 ) {
V_11 = - V_76 ;
goto error;
}
F_165 ( V_2 , V_289 , V_292 , V_29 -> V_268 , 0 ) ;
F_166 ( V_2 , V_289 ) ;
V_163 = & F_107 ( V_2 ) -> V_291 [ V_289 ] ;
}
} else if( V_289 < V_294 ) {
if ( V_251 > V_293 )
V_251 = V_293 ;
V_292 = F_167 ( V_29 -> V_256 , 0 ) ;
if ( V_292 == NULL ) {
V_11 = - V_183 ;
goto error;
}
V_29 -> V_267 = V_292 ;
V_29 -> V_268 = 0 ;
F_165 ( V_2 , V_289 , V_292 , 0 , 0 ) ;
V_163 = & F_107 ( V_2 ) -> V_291 [ V_289 ] ;
} else {
V_11 = - V_76 ;
goto error;
}
if ( F_143 ( V_137 ,
F_168 ( V_163 ) + F_169 ( V_163 ) ,
V_86 , V_251 , V_2 -> V_3 , V_2 ) < 0 ) {
V_11 = - V_287 ;
goto error;
}
V_29 -> V_268 += V_251 ;
F_170 ( V_163 , V_251 ) ;
V_2 -> V_3 += V_251 ;
V_2 -> V_186 += V_251 ;
V_2 -> V_180 += V_251 ;
F_171 ( V_251 , & V_29 -> V_285 ) ;
}
V_86 += V_251 ;
V_224 -= V_251 ;
}
return 0 ;
error:
V_247 -> V_224 -= V_224 ;
F_24 ( F_41 ( V_29 ) , V_117 -> V_295 , V_35 ) ;
return V_11 ;
}
static void F_172 ( struct V_244 * V_245 , struct V_50 * V_51 )
{
if ( V_51 -> V_247 . V_47 ) {
F_114 ( V_51 -> V_247 . V_47 -> V_257 ) ;
F_114 ( V_51 -> V_247 . V_47 -> V_258 ) ;
F_114 ( V_51 -> V_247 . V_47 -> V_259 ) ;
F_114 ( V_51 -> V_247 . V_47 -> V_114 ) ;
F_114 ( V_51 -> V_247 . V_47 ) ;
V_51 -> V_247 . V_47 = NULL ;
}
if ( V_245 -> V_247 . V_254 . V_18 ) {
F_115 ( V_245 -> V_247 . V_254 . V_18 ) ;
V_245 -> V_247 . V_254 . V_18 = NULL ;
V_245 -> V_247 . V_254 . V_27 &= ~ V_266 ;
}
memset ( & V_245 -> V_247 . V_260 , 0 , sizeof( V_245 -> V_247 . V_260 ) ) ;
}
int F_173 ( struct V_43 * V_29 )
{
struct V_1 * V_2 , * V_296 ;
struct V_1 * * V_297 ;
struct V_52 V_298 , * V_218 = & V_298 ;
struct V_244 * V_245 = F_152 ( V_29 ) ;
struct V_50 * V_51 = F_42 ( V_29 ) ;
struct V_49 * V_49 = F_41 ( V_29 ) ;
struct V_4 * V_54 ;
struct V_46 * V_47 = V_51 -> V_247 . V_47 ;
struct V_116 * V_117 = (struct V_116 * ) V_245 -> V_247 . V_254 . V_18 ;
struct V_44 * V_45 = & V_245 -> V_247 . V_260 . V_261 . V_262 ;
unsigned char V_55 = V_45 -> V_56 ;
int V_11 = 0 ;
if ( ( V_2 = F_174 ( & V_29 -> V_228 ) ) == NULL )
goto V_201;
V_297 = & ( F_107 ( V_2 ) -> V_181 ) ;
if ( V_2 -> V_90 < F_67 ( V_2 ) )
F_10 ( V_2 , F_11 ( V_2 ) ) ;
while ( ( V_296 = F_174 ( & V_29 -> V_228 ) ) != NULL ) {
F_10 ( V_296 , F_175 ( V_2 ) ) ;
* V_297 = V_296 ;
V_297 = & ( V_296 -> V_82 ) ;
V_2 -> V_3 += V_296 -> V_3 ;
V_2 -> V_186 += V_296 -> V_3 ;
V_2 -> V_180 += V_296 -> V_180 ;
V_296 -> V_178 = NULL ;
V_296 -> V_29 = NULL ;
}
if ( V_51 -> V_263 < V_299 )
V_2 -> V_72 = 1 ;
* V_218 = V_45 -> V_24 ;
F_10 ( V_2 , F_175 ( V_2 ) ) ;
if ( V_47 && V_47 -> V_62 )
F_48 ( V_2 , V_47 , & V_55 ) ;
if ( V_47 && V_47 -> V_61 )
F_49 ( V_2 , V_47 , & V_55 , & V_218 ) ;
F_50 ( V_2 , sizeof( struct V_4 ) ) ;
F_51 ( V_2 ) ;
V_54 = F_2 ( V_2 ) ;
* ( V_65 * ) V_54 = V_45 -> V_66 |
F_53 ( 0x60000000 | ( ( int ) V_51 -> V_247 . V_48 << 20 ) ) ;
V_54 -> V_34 = V_51 -> V_247 . V_34 ;
V_54 -> V_67 = V_55 ;
V_54 -> V_31 = V_45 -> V_31 ;
V_54 -> V_24 = * V_218 ;
V_2 -> V_68 = V_29 -> V_69 ;
V_2 -> V_70 = V_29 -> V_71 ;
F_86 ( V_2 , F_87 ( & V_117 -> V_18 ) ) ;
F_26 ( V_49 , V_117 -> V_295 , V_73 , V_2 -> V_3 ) ;
if ( V_55 == V_87 ) {
struct V_25 * V_26 = F_16 ( F_5 ( V_2 ) ) ;
F_176 ( V_49 , V_26 , F_177 ( V_2 ) -> V_91 ) ;
F_178 ( V_49 , V_26 , V_300 ) ;
}
V_11 = F_6 ( V_2 ) ;
if ( V_11 ) {
if ( V_11 > 0 )
V_11 = F_179 ( V_11 ) ;
if ( V_11 )
goto error;
}
V_201:
F_172 ( V_245 , V_51 ) ;
return V_11 ;
error:
F_24 ( V_49 , V_117 -> V_295 , V_35 ) ;
goto V_201;
}
void F_180 ( struct V_43 * V_29 )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_181 ( & V_29 -> V_228 ) ) != NULL ) {
if ( F_5 ( V_2 ) )
F_24 ( F_41 ( V_29 ) , F_16 ( F_5 ( V_2 ) ) ,
V_35 ) ;
F_25 ( V_2 ) ;
}
F_172 ( F_152 ( V_29 ) , F_42 ( V_29 ) ) ;
}
