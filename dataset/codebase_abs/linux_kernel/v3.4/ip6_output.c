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
F_25 ( V_2 ) ;
V_2 = V_63 ;
F_46 ( V_2 , V_29 ) ;
}
if ( V_47 -> V_62 )
F_47 ( V_2 , V_47 , & V_55 ) ;
if ( V_47 -> V_61 )
F_48 ( V_2 , V_47 , & V_55 , & V_53 ) ;
}
F_49 ( V_2 , sizeof( struct V_4 ) ) ;
F_50 ( V_2 ) ;
V_54 = F_2 ( V_2 ) ;
if ( V_51 )
V_58 = V_51 -> V_34 ;
if ( V_58 < 0 )
V_58 = F_51 ( V_18 ) ;
* ( V_65 * ) V_54 = F_52 ( 0x60000000 | ( V_48 << 20 ) ) | V_45 -> V_66 ;
V_54 -> V_6 = F_3 ( V_57 ) ;
V_54 -> V_67 = V_55 ;
V_54 -> V_34 = V_58 ;
V_54 -> V_31 = V_45 -> V_31 ;
V_54 -> V_24 = * V_53 ;
V_2 -> V_68 = V_29 -> V_69 ;
V_2 -> V_70 = V_29 -> V_71 ;
V_59 = F_53 ( V_18 ) ;
if ( ( V_2 -> V_3 <= V_59 ) || V_2 -> V_72 || F_34 ( V_2 ) ) {
F_26 ( V_49 , F_16 ( F_5 ( V_2 ) ) ,
V_73 , V_2 -> V_3 ) ;
return F_23 ( V_7 , V_8 , V_2 , NULL ,
V_18 -> V_9 , V_10 ) ;
}
if ( F_54 () )
F_55 ( V_74 L_1 ) ;
V_2 -> V_9 = V_18 -> V_9 ;
F_56 ( V_2 , V_75 , 0 , V_59 ) ;
F_24 ( V_49 , F_16 ( F_5 ( V_2 ) ) , V_76 ) ;
F_25 ( V_2 ) ;
return - V_77 ;
}
int F_57 ( struct V_43 * V_29 , struct V_1 * V_2 , struct V_19 * V_9 ,
const struct V_52 * V_31 , const struct V_52 * V_24 ,
int V_55 , int V_3 )
{
struct V_50 * V_51 = F_42 ( V_29 ) ;
struct V_4 * V_54 ;
V_2 -> V_22 = F_3 ( V_23 ) ;
V_2 -> V_9 = V_9 ;
F_50 ( V_2 ) ;
F_58 ( V_2 , sizeof( struct V_4 ) ) ;
V_54 = F_2 ( V_2 ) ;
* ( V_65 * ) V_54 = F_52 ( 0x60000000 ) ;
V_54 -> V_6 = F_3 ( V_3 ) ;
V_54 -> V_67 = V_55 ;
V_54 -> V_34 = V_51 -> V_34 ;
V_54 -> V_31 = * V_31 ;
V_54 -> V_24 = * V_24 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , int V_78 )
{
struct V_79 * V_80 ;
struct V_43 * V_81 = NULL ;
F_60 ( & V_82 ) ;
for ( V_80 = V_79 ; V_80 ; V_80 = V_80 -> V_83 ) {
struct V_43 * V_29 = V_80 -> V_29 ;
if ( V_29 && V_80 -> V_78 == V_78 &&
( ! V_29 -> V_84 ||
V_29 -> V_84 == V_2 -> V_9 -> V_85 ) ) {
if ( V_81 ) {
struct V_1 * V_63 = F_22 ( V_2 , V_32 ) ;
if ( V_63 )
F_61 ( V_81 , V_63 ) ;
}
V_81 = V_29 ;
}
}
if ( V_81 ) {
F_61 ( V_81 , V_2 ) ;
F_62 ( & V_82 ) ;
return 1 ;
}
F_62 ( & V_82 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_4 * V_54 = F_2 ( V_2 ) ;
T_1 V_67 = V_54 -> V_67 ;
T_3 V_86 ;
int V_87 ;
if ( F_64 ( V_67 ) ) {
V_87 = F_65 ( V_2 , sizeof( * V_54 ) , & V_67 , & V_86 ) ;
if ( V_87 < 0 )
return 0 ;
} else
V_87 = sizeof( struct V_4 ) ;
if ( V_67 == V_88 ) {
struct V_89 * V_90 ;
if ( ! F_66 ( V_2 , ( F_67 ( V_2 ) +
V_87 + 1 - V_2 -> V_91 ) ) )
return 0 ;
V_90 = (struct V_89 * ) ( F_67 ( V_2 ) + V_87 ) ;
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
if ( F_68 ( & V_54 -> V_24 ) & V_98 ) {
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
struct V_99 * V_47 = F_20 ( V_2 ) ;
struct V_49 * V_49 = F_19 ( V_18 -> V_9 ) ;
T_2 V_59 ;
if ( V_49 -> V_100 . V_101 -> V_102 == 0 )
goto error;
if ( F_72 ( V_2 ) )
goto V_103;
if ( ! F_73 ( NULL , V_104 , V_2 ) ) {
F_24 ( V_49 , F_16 ( V_18 ) , V_105 ) ;
goto V_103;
}
if ( V_2 -> V_13 != V_106 )
goto V_103;
F_74 ( V_2 ) ;
if ( V_47 -> V_80 ) {
T_1 * V_107 = F_67 ( V_2 ) + V_47 -> V_80 ;
if ( F_59 ( V_2 , ( V_107 [ 2 ] << 8 ) + V_107 [ 3 ] ) )
return 0 ;
}
if ( V_54 -> V_34 <= 1 ) {
V_2 -> V_9 = V_18 -> V_9 ;
F_56 ( V_2 , V_108 , V_109 , 0 ) ;
F_31 ( V_49 ,
F_16 ( V_18 ) , V_110 ) ;
F_25 ( V_2 ) ;
return - V_111 ;
}
if ( V_49 -> V_100 . V_101 -> V_112 &&
F_75 ( & V_113 , V_49 , & V_54 -> V_24 , V_2 -> V_9 , 0 ) ) {
int V_114 = F_63 ( V_2 ) ;
if ( V_114 > 0 )
return F_76 ( V_2 ) ;
else if ( V_114 < 0 ) {
F_24 ( V_49 , F_16 ( V_18 ) ,
V_105 ) ;
goto V_103;
}
}
if ( ! F_77 ( V_2 ) ) {
F_24 ( V_49 , F_16 ( V_18 ) , V_105 ) ;
goto V_103;
}
V_18 = F_5 ( V_2 ) ;
if ( V_2 -> V_9 == V_18 -> V_9 && V_47 -> V_115 == 0 && ! F_78 ( V_2 ) ) {
struct V_52 * V_116 = NULL ;
struct V_117 * V_118 ;
V_118 = (struct V_117 * ) V_18 ;
if ( V_118 -> V_119 & V_120 )
V_116 = & V_118 -> V_121 ;
else
V_116 = & V_54 -> V_24 ;
if ( ! V_118 -> V_122 )
F_79 ( V_118 , 1 ) ;
if ( F_80 ( V_118 -> V_122 , 1 * V_123 ) )
F_81 ( V_2 , V_116 ) ;
} else {
int V_124 = F_68 ( & V_54 -> V_31 ) ;
if ( V_124 == V_125 ||
V_124 & ( V_126 | V_127 ) )
goto error;
if ( V_124 & V_98 ) {
F_56 ( V_2 , V_128 ,
V_129 , 0 ) ;
goto error;
}
}
V_59 = F_53 ( V_18 ) ;
if ( V_59 < V_130 )
V_59 = V_130 ;
if ( V_2 -> V_3 > V_59 && ! F_34 ( V_2 ) ) {
V_2 -> V_9 = V_18 -> V_9 ;
F_56 ( V_2 , V_75 , 0 , V_59 ) ;
F_31 ( V_49 ,
F_16 ( V_18 ) , V_131 ) ;
F_31 ( V_49 ,
F_16 ( V_18 ) , V_76 ) ;
F_25 ( V_2 ) ;
return - V_77 ;
}
if ( F_82 ( V_2 , V_18 -> V_9 -> V_132 ) ) {
F_24 ( V_49 , F_16 ( V_18 ) , V_35 ) ;
goto V_103;
}
V_54 = F_2 ( V_2 ) ;
V_54 -> V_34 -- ;
F_31 ( V_49 , F_16 ( V_18 ) , V_133 ) ;
return F_23 ( V_7 , V_134 , V_2 , V_2 -> V_9 , V_18 -> V_9 ,
F_70 ) ;
error:
F_31 ( V_49 , F_16 ( V_18 ) , V_135 ) ;
V_103:
F_25 ( V_2 ) ;
return - V_39 ;
}
static void F_83 ( struct V_1 * V_136 , struct V_1 * V_137 )
{
V_136 -> V_13 = V_137 -> V_13 ;
V_136 -> V_68 = V_137 -> V_68 ;
V_136 -> V_22 = V_137 -> V_22 ;
F_84 ( V_136 ) ;
F_85 ( V_136 , F_86 ( F_5 ( V_137 ) ) ) ;
V_136 -> V_9 = V_137 -> V_9 ;
V_136 -> V_70 = V_137 -> V_70 ;
#ifdef F_87
V_136 -> V_138 = V_137 -> V_138 ;
#endif
F_88 ( V_136 , V_137 ) ;
#if F_89 ( V_139 ) || \
F_89 ( V_140 )
V_136 -> V_141 = V_137 -> V_141 ;
#endif
F_90 ( V_136 , V_137 ) ;
}
int F_91 ( struct V_1 * V_2 , T_1 * * V_67 )
{
T_4 V_87 = sizeof( struct V_4 ) ;
struct V_142 * V_143 =
(struct V_142 * ) ( F_2 ( V_2 ) + 1 ) ;
unsigned int V_144 = V_2 -> V_145 - V_2 -> V_146 ;
int V_147 = 0 ;
* V_67 = & F_2 ( V_2 ) -> V_67 ;
while ( V_87 + 1 <= V_144 ) {
switch ( * * V_67 ) {
case V_148 :
break;
case V_149 :
V_147 = 1 ;
break;
case V_150 :
#if F_89 ( V_151 ) || F_89 ( V_152 )
if ( F_92 ( V_2 , V_87 , V_153 ) >= 0 )
break;
#endif
if ( V_147 )
return V_87 ;
break;
default :
return V_87 ;
}
V_87 += F_93 ( V_143 ) ;
* V_67 = & V_143 -> V_67 ;
V_143 = (struct V_142 * ) ( F_67 ( V_2 ) +
V_87 ) ;
}
return V_87 ;
}
void F_94 ( struct V_154 * V_155 , struct V_117 * V_118 )
{
static T_5 V_156 ;
int V_157 , V_158 ;
if ( V_118 && ! ( V_118 -> V_18 . V_27 & V_159 ) ) {
struct V_160 * V_161 ;
if ( ! V_118 -> V_122 )
F_79 ( V_118 , 1 ) ;
V_161 = V_118 -> V_122 ;
if ( V_161 ) {
V_155 -> V_162 = F_52 ( F_95 ( V_161 , 0 ) ) ;
return;
}
}
do {
V_157 = F_96 ( & V_156 ) ;
V_158 = V_157 + 1 ;
if ( ! V_158 )
V_158 = 1 ;
} while ( F_97 ( & V_156 , V_157 , V_158 ) != V_157 );
V_155 -> V_162 = F_52 ( V_158 ) ;
}
int F_36 ( struct V_1 * V_2 , int (* F_98)( struct V_1 * ) )
{
struct V_1 * V_163 ;
struct V_117 * V_118 = (struct V_117 * ) F_5 ( V_2 ) ;
struct V_50 * V_51 = V_2 -> V_29 ? F_42 ( V_2 -> V_29 ) : NULL ;
struct V_4 * V_164 ;
struct V_154 * V_165 ;
unsigned int V_59 , V_166 , V_167 , V_3 ;
int V_168 , V_169 ;
V_65 V_170 = 0 ;
int V_107 , V_87 = 0 , V_11 = 0 ;
T_1 * V_171 , V_67 = 0 ;
struct V_49 * V_49 = F_19 ( F_5 ( V_2 ) -> V_9 ) ;
V_166 = F_91 ( V_2 , & V_171 ) ;
V_67 = * V_171 ;
V_59 = F_33 ( V_2 ) ;
if ( ! V_2 -> V_72 && V_2 -> V_3 > V_59 ) {
V_2 -> V_9 = F_5 ( V_2 ) -> V_9 ;
F_56 ( V_2 , V_75 , 0 , V_59 ) ;
F_24 ( V_49 , F_16 ( F_5 ( V_2 ) ) ,
V_76 ) ;
F_25 ( V_2 ) ;
return - V_77 ;
}
if ( V_51 && V_51 -> V_172 < V_59 ) {
if ( V_51 -> V_172 )
V_59 = V_51 -> V_172 ;
}
V_59 -= V_166 + sizeof( struct V_154 ) ;
if ( F_99 ( V_2 ) ) {
int V_173 = F_100 ( V_2 ) ;
struct V_1 * V_174 ;
if ( V_173 - V_166 > V_59 ||
( ( V_173 - V_166 ) & 7 ) ||
F_101 ( V_2 ) )
goto V_175;
F_102 (skb, frag) {
if ( V_163 -> V_3 > V_59 ||
( ( V_163 -> V_3 & 7 ) && V_163 -> V_83 ) ||
F_44 ( V_163 ) < V_166 )
goto V_176;
if ( F_103 ( V_163 ) )
goto V_176;
F_104 ( V_163 -> V_29 ) ;
if ( V_2 -> V_29 ) {
V_163 -> V_29 = V_2 -> V_29 ;
V_163 -> V_177 = V_178 ;
}
V_2 -> V_179 -= V_163 -> V_179 ;
}
V_11 = 0 ;
V_87 = 0 ;
V_163 = F_105 ( V_2 ) -> V_180 ;
F_106 ( V_2 ) ;
* V_171 = V_181 ;
V_164 = F_107 ( F_67 ( V_2 ) , V_166 , V_32 ) ;
if ( ! V_164 ) {
F_24 ( V_49 , F_16 ( F_5 ( V_2 ) ) ,
V_76 ) ;
return - V_182 ;
}
F_10 ( V_2 , V_166 ) ;
V_165 = (struct V_154 * ) F_108 ( V_2 , sizeof( struct V_154 ) ) ;
F_108 ( V_2 , V_166 ) ;
F_50 ( V_2 ) ;
memcpy ( F_67 ( V_2 ) , V_164 , V_166 ) ;
F_94 ( V_165 , V_118 ) ;
V_165 -> V_67 = V_67 ;
V_165 -> V_183 = 0 ;
V_165 -> V_86 = F_3 ( V_184 ) ;
V_170 = V_165 -> V_162 ;
V_173 = F_100 ( V_2 ) ;
V_2 -> V_185 = V_173 - F_109 ( V_2 ) ;
V_2 -> V_3 = V_173 ;
F_2 ( V_2 ) -> V_6 = F_3 ( V_173 -
sizeof( struct V_4 ) ) ;
F_110 ( & V_118 -> V_18 ) ;
for (; ; ) {
if ( V_163 ) {
V_163 -> V_15 = V_186 ;
F_111 ( V_163 ) ;
V_165 = (struct V_154 * ) F_108 ( V_163 , sizeof( struct V_154 ) ) ;
F_108 ( V_163 , V_166 ) ;
F_50 ( V_163 ) ;
memcpy ( F_67 ( V_163 ) , V_164 ,
V_166 ) ;
V_87 += V_2 -> V_3 - V_166 - sizeof( struct V_154 ) ;
V_165 -> V_67 = V_67 ;
V_165 -> V_183 = 0 ;
V_165 -> V_86 = F_3 ( V_87 ) ;
if ( V_163 -> V_83 != NULL )
V_165 -> V_86 |= F_3 ( V_184 ) ;
V_165 -> V_162 = V_170 ;
F_2 ( V_163 ) -> V_6 =
F_3 ( V_163 -> V_3 -
sizeof( struct V_4 ) ) ;
F_83 ( V_163 , V_2 ) ;
}
V_11 = F_98 ( V_2 ) ;
if( ! V_11 )
F_24 ( V_49 , F_16 ( & V_118 -> V_18 ) ,
V_187 ) ;
if ( V_11 || ! V_163 )
break;
V_2 = V_163 ;
V_163 = V_2 -> V_83 ;
V_2 -> V_83 = NULL ;
}
F_112 ( V_164 ) ;
if ( V_11 == 0 ) {
F_24 ( V_49 , F_16 ( & V_118 -> V_18 ) ,
V_188 ) ;
F_113 ( & V_118 -> V_18 ) ;
return 0 ;
}
while ( V_163 ) {
V_2 = V_163 -> V_83 ;
F_25 ( V_163 ) ;
V_163 = V_2 ;
}
F_24 ( V_49 , F_16 ( & V_118 -> V_18 ) ,
V_76 ) ;
F_113 ( & V_118 -> V_18 ) ;
return V_11 ;
V_176:
F_102 (skb, frag2) {
if ( V_174 == V_163 )
break;
V_174 -> V_29 = NULL ;
V_174 -> V_177 = NULL ;
V_2 -> V_179 += V_174 -> V_179 ;
}
}
V_175:
V_167 = V_2 -> V_3 - V_166 ;
V_107 = V_166 ;
* V_171 = V_181 ;
V_168 = F_43 ( V_118 -> V_18 . V_9 ) ;
V_169 = V_118 -> V_18 . V_9 -> V_189 ;
while( V_167 > 0 ) {
V_3 = V_167 ;
if ( V_3 > V_59 )
V_3 = V_59 ;
if ( V_3 < V_167 ) {
V_3 &= ~ 7 ;
}
if ( ( V_163 = F_114 ( V_3 + V_166 + sizeof( struct V_154 ) +
V_168 + V_169 , V_32 ) ) == NULL ) {
F_115 ( V_190 L_2 ) ;
F_24 ( V_49 , F_16 ( F_5 ( V_2 ) ) ,
V_76 ) ;
V_11 = - V_182 ;
goto V_191;
}
F_83 ( V_163 , V_2 ) ;
F_116 ( V_163 , V_168 ) ;
F_58 ( V_163 , V_3 + V_166 + sizeof( struct V_154 ) ) ;
F_50 ( V_163 ) ;
V_165 = (struct V_154 * ) ( F_67 ( V_163 ) + V_166 ) ;
V_163 -> V_192 = ( V_163 -> V_146 + V_166 +
sizeof( struct V_154 ) ) ;
if ( V_2 -> V_29 )
F_46 ( V_163 , V_2 -> V_29 ) ;
F_117 ( V_2 , F_67 ( V_163 ) , V_166 ) ;
V_165 -> V_67 = V_67 ;
V_165 -> V_183 = 0 ;
if ( ! V_170 ) {
F_94 ( V_165 , V_118 ) ;
V_170 = V_165 -> V_162 ;
} else
V_165 -> V_162 = V_170 ;
if ( F_118 ( V_2 , V_107 , F_119 ( V_163 ) , V_3 ) )
F_120 () ;
V_167 -= V_3 ;
V_165 -> V_86 = F_3 ( V_87 ) ;
if ( V_167 > 0 )
V_165 -> V_86 |= F_3 ( V_184 ) ;
F_2 ( V_163 ) -> V_6 = F_3 ( V_163 -> V_3 -
sizeof( struct V_4 ) ) ;
V_107 += V_3 ;
V_87 += V_3 ;
V_11 = F_98 ( V_163 ) ;
if ( V_11 )
goto V_191;
F_24 ( V_49 , F_16 ( F_5 ( V_2 ) ) ,
V_187 ) ;
}
F_24 ( V_49 , F_16 ( F_5 ( V_2 ) ) ,
V_188 ) ;
F_25 ( V_2 ) ;
return V_11 ;
V_191:
F_24 ( V_49 , F_16 ( F_5 ( V_2 ) ) ,
V_76 ) ;
F_25 ( V_2 ) ;
return V_11 ;
}
static inline int F_121 ( const struct V_193 * V_194 ,
const struct V_52 * V_195 ,
const struct V_52 * V_196 )
{
return ( V_194 -> V_197 != 128 || ! F_122 ( V_195 , & V_194 -> V_198 ) ) &&
( V_196 == NULL || ! F_122 ( V_195 , V_196 ) ) ;
}
static struct V_17 * F_123 ( struct V_43 * V_29 ,
struct V_17 * V_18 ,
const struct V_44 * V_45 )
{
struct V_50 * V_51 = F_42 ( V_29 ) ;
struct V_117 * V_118 = (struct V_117 * ) V_18 ;
if ( ! V_18 )
goto V_199;
if ( F_121 ( & V_118 -> V_200 , & V_45 -> V_24 , V_51 -> V_201 ) ||
#ifdef F_124
F_121 ( & V_118 -> V_202 , & V_45 -> V_31 , V_51 -> V_203 ) ||
#endif
( V_45 -> V_204 && V_45 -> V_204 != V_18 -> V_9 -> V_85 ) ) {
F_113 ( V_18 ) ;
V_18 = NULL ;
}
V_199:
return V_18 ;
}
static int F_125 ( struct V_43 * V_29 ,
struct V_17 * * V_18 , struct V_44 * V_45 )
{
struct V_49 * V_49 = F_41 ( V_29 ) ;
#ifdef F_126
struct V_20 * V_205 ;
#endif
int V_11 ;
if ( * V_18 == NULL )
* V_18 = F_127 ( V_49 , V_29 , V_45 ) ;
if ( ( V_11 = ( * V_18 ) -> error ) )
goto V_206;
if ( F_128 ( & V_45 -> V_31 ) ) {
struct V_117 * V_118 = (struct V_117 * ) * V_18 ;
V_11 = F_129 ( V_49 , V_118 , & V_45 -> V_24 ,
V_29 ? F_42 ( V_29 ) -> V_207 : 0 ,
& V_45 -> V_31 ) ;
if ( V_11 )
goto V_206;
}
#ifdef F_126
F_27 () ;
V_205 = F_28 ( * V_18 ) ;
if ( V_205 && ! ( V_205 -> V_208 & V_209 ) ) {
struct V_210 * V_211 ;
struct V_44 V_212 ;
int V_213 ;
F_30 () ;
V_211 = F_130 ( V_49 , & V_45 -> V_31 ,
( * V_18 ) -> V_9 , 1 ) ;
V_213 = ( V_211 && V_211 -> V_27 & V_214 ) ;
if ( V_211 )
F_131 ( V_211 ) ;
if ( V_213 ) {
F_113 ( * V_18 ) ;
memcpy ( & V_212 , V_45 , sizeof( struct V_44 ) ) ;
memset ( & V_212 . V_24 , 0 , sizeof( struct V_52 ) ) ;
* V_18 = F_127 ( V_49 , V_29 , & V_212 ) ;
if ( ( V_11 = ( * V_18 ) -> error ) )
goto V_206;
}
} else {
F_30 () ;
}
#endif
return 0 ;
V_206:
if ( V_11 == - V_215 )
F_31 ( V_49 , NULL , V_38 ) ;
F_113 ( * V_18 ) ;
* V_18 = NULL ;
return V_11 ;
}
int F_132 ( struct V_43 * V_29 , struct V_17 * * V_18 , struct V_44 * V_45 )
{
* V_18 = NULL ;
return F_125 ( V_29 , V_18 , V_45 ) ;
}
struct V_17 * F_133 ( struct V_43 * V_29 , struct V_44 * V_45 ,
const struct V_52 * V_216 ,
bool V_217 )
{
struct V_17 * V_18 = NULL ;
int V_11 ;
V_11 = F_125 ( V_29 , & V_18 , V_45 ) ;
if ( V_11 )
return F_134 ( V_11 ) ;
if ( V_216 )
V_45 -> V_24 = * V_216 ;
if ( V_217 )
V_45 -> V_218 |= V_219 ;
return F_135 ( F_41 ( V_29 ) , V_18 , F_136 ( V_45 ) , V_29 , 0 ) ;
}
struct V_17 * F_137 ( struct V_43 * V_29 , struct V_44 * V_45 ,
const struct V_52 * V_216 ,
bool V_217 )
{
struct V_17 * V_18 = F_138 ( V_29 , F_42 ( V_29 ) -> V_220 ) ;
int V_11 ;
V_18 = F_123 ( V_29 , V_18 , V_45 ) ;
V_11 = F_125 ( V_29 , & V_18 , V_45 ) ;
if ( V_11 )
return F_134 ( V_11 ) ;
if ( V_216 )
V_45 -> V_24 = * V_216 ;
if ( V_217 )
V_45 -> V_218 |= V_219 ;
return F_135 ( F_41 ( V_29 ) , V_18 , F_136 ( V_45 ) , V_29 , 0 ) ;
}
static inline int F_139 ( struct V_43 * V_29 ,
int F_140 ( void * V_137 , char * V_136 , int V_87 , int V_3 ,
int V_221 , struct V_1 * V_2 ) ,
void * V_137 , int V_222 , int V_223 , int V_224 ,
int V_225 , int V_59 , unsigned int V_27 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 ;
int V_11 ;
if ( ( V_2 = F_141 ( & V_29 -> V_226 ) ) == NULL ) {
V_2 = F_142 ( V_29 ,
V_223 + V_224 + V_225 + 20 ,
( V_27 & V_227 ) , & V_11 ) ;
if ( V_2 == NULL )
return V_11 ;
F_116 ( V_2 , V_223 ) ;
F_58 ( V_2 , V_224 + V_225 ) ;
F_50 ( V_2 ) ;
V_2 -> V_192 = V_2 -> V_146 + V_224 ;
V_2 -> V_15 = V_228 ;
V_2 -> V_229 = 0 ;
}
V_11 = F_143 ( V_29 , V_2 , F_140 , V_137 ,
( V_222 - V_225 ) ) ;
if ( ! V_11 ) {
struct V_154 V_155 ;
F_105 ( V_2 ) -> V_230 = ( V_59 - V_224 -
sizeof( struct V_154 ) ) & ~ 7 ;
F_105 ( V_2 ) -> V_231 = V_232 ;
F_94 ( & V_155 , V_118 ) ;
F_105 ( V_2 ) -> V_233 = V_155 . V_162 ;
F_144 ( & V_29 -> V_226 , V_2 ) ;
return 0 ;
}
F_25 ( V_2 ) ;
return V_11 ;
}
static inline struct V_142 * F_145 ( struct V_142 * V_234 ,
T_6 V_235 )
{
return V_234 ? F_107 ( V_234 , ( V_234 -> V_236 + 1 ) * 8 , V_235 ) : NULL ;
}
static inline struct V_237 * F_146 ( struct V_237 * V_234 ,
T_6 V_235 )
{
return V_234 ? F_107 ( V_234 , ( V_234 -> V_236 + 1 ) * 8 , V_235 ) : NULL ;
}
int F_147 ( struct V_43 * V_29 , int F_140 ( void * V_137 , char * V_136 ,
int V_87 , int V_3 , int V_221 , struct V_1 * V_2 ) ,
void * V_137 , int V_222 , int V_225 ,
int V_58 , int V_48 , struct V_46 * V_47 , struct V_44 * V_45 ,
struct V_117 * V_118 , unsigned int V_27 , int V_238 )
{
struct V_239 * V_240 = F_148 ( V_29 ) ;
struct V_50 * V_51 = F_42 ( V_29 ) ;
struct V_241 * V_242 ;
struct V_1 * V_2 ;
unsigned int V_243 , V_224 ;
int V_244 ;
int V_245 ;
int V_223 ;
int V_59 ;
int V_246 ;
int V_11 ;
int V_87 = 0 ;
int V_247 = V_186 ;
T_7 V_248 = 0 ;
if ( V_27 & V_249 )
return 0 ;
V_242 = & V_240 -> V_242 . V_250 ;
if ( F_149 ( & V_29 -> V_226 ) ) {
if ( V_47 ) {
if ( F_12 ( V_51 -> V_242 . V_47 ) )
return - V_39 ;
V_51 -> V_242 . V_47 = F_150 ( V_47 -> V_251 , V_29 -> V_252 ) ;
if ( F_38 ( V_51 -> V_242 . V_47 == NULL ) )
return - V_64 ;
V_51 -> V_242 . V_47 -> V_251 = V_47 -> V_251 ;
V_51 -> V_242 . V_47 -> V_62 = V_47 -> V_62 ;
V_51 -> V_242 . V_47 -> V_61 = V_47 -> V_61 ;
V_51 -> V_242 . V_47 -> V_253 = F_145 ( V_47 -> V_253 ,
V_29 -> V_252 ) ;
if ( V_47 -> V_253 && ! V_51 -> V_242 . V_47 -> V_253 )
return - V_64 ;
V_51 -> V_242 . V_47 -> V_254 = F_145 ( V_47 -> V_254 ,
V_29 -> V_252 ) ;
if ( V_47 -> V_254 && ! V_51 -> V_242 . V_47 -> V_254 )
return - V_64 ;
V_51 -> V_242 . V_47 -> V_255 = F_145 ( V_47 -> V_255 ,
V_29 -> V_252 ) ;
if ( V_47 -> V_255 && ! V_51 -> V_242 . V_47 -> V_255 )
return - V_64 ;
V_51 -> V_242 . V_47 -> V_115 = F_146 ( V_47 -> V_115 ,
V_29 -> V_252 ) ;
if ( V_47 -> V_115 && ! V_51 -> V_242 . V_47 -> V_115 )
return - V_64 ;
}
F_110 ( & V_118 -> V_18 ) ;
V_242 -> V_18 = & V_118 -> V_18 ;
V_240 -> V_242 . V_256 . V_257 . V_258 = * V_45 ;
V_51 -> V_242 . V_34 = V_58 ;
V_51 -> V_242 . V_48 = V_48 ;
V_59 = V_51 -> V_259 == V_260 ?
V_118 -> V_18 . V_9 -> V_59 : F_53 ( & V_118 -> V_18 ) ;
if ( V_51 -> V_172 < V_59 ) {
if ( V_51 -> V_172 )
V_59 = V_51 -> V_172 ;
}
V_242 -> V_261 = V_59 ;
if ( F_35 ( V_118 -> V_18 . V_262 ) )
V_242 -> V_27 |= V_263 ;
V_242 -> V_222 = 0 ;
V_29 -> V_264 = NULL ;
V_29 -> V_265 = 0 ;
V_244 = ( V_47 ? V_47 -> V_62 : 0 ) - V_118 -> V_266 ;
V_222 += V_244 ;
V_225 += V_244 ;
V_245 = V_118 -> V_18 . V_267 ;
} else {
V_118 = (struct V_117 * ) V_242 -> V_18 ;
V_45 = & V_240 -> V_242 . V_256 . V_257 . V_258 ;
V_47 = V_51 -> V_242 . V_47 ;
V_225 = 0 ;
V_244 = 0 ;
V_245 = 0 ;
V_59 = V_242 -> V_261 ;
}
V_223 = F_43 ( V_118 -> V_18 . V_9 ) ;
V_224 = sizeof( struct V_4 ) + V_118 -> V_266 +
( V_47 ? V_47 -> V_61 : 0 ) ;
V_243 = ( ( V_59 - V_224 ) & ~ 7 ) + V_224 - sizeof( struct V_154 ) ;
if ( V_59 <= sizeof( struct V_4 ) + V_5 ) {
if ( V_242 -> V_222 + V_222 > sizeof( struct V_4 ) + V_5 - V_224 ) {
F_151 ( V_29 , V_77 , V_45 , V_59 - V_244 ) ;
return - V_77 ;
}
}
if ( V_29 -> V_268 == V_269 ) {
V_11 = F_152 ( V_29 , & V_248 ) ;
if ( V_11 )
goto error;
}
V_242 -> V_222 += V_222 ;
if ( V_222 > V_59 ) {
int V_55 = V_29 -> V_270 ;
if ( V_238 && ( V_55 == V_271 || V_55 == V_272 ) ) {
F_153 ( V_29 , V_45 , V_59 - V_244 ) ;
return - V_77 ;
}
if ( V_55 == V_271 &&
( V_118 -> V_18 . V_9 -> V_273 & V_274 ) ) {
V_11 = F_139 ( V_29 , F_140 , V_137 , V_222 ,
V_223 , V_224 ,
V_225 , V_59 , V_27 , V_118 ) ;
if ( V_11 )
goto error;
return 0 ;
}
}
if ( ( V_2 = F_141 ( & V_29 -> V_226 ) ) == NULL )
goto V_275;
while ( V_222 > 0 ) {
V_246 = ( V_242 -> V_222 <= V_59 && ! ( V_242 -> V_27 & V_263 ) ? V_59 : V_243 ) - V_2 -> V_3 ;
if ( V_246 < V_222 )
V_246 = V_243 - V_2 -> V_3 ;
if ( V_246 <= 0 ) {
char * V_91 ;
unsigned int V_276 ;
unsigned int V_277 ;
unsigned int V_278 ;
unsigned int V_279 ;
struct V_1 * V_280 ;
V_275:
V_280 = V_2 ;
if ( V_280 )
V_278 = V_280 -> V_3 - V_243 ;
else
V_278 = 0 ;
V_276 = V_222 + V_278 ;
if ( V_276 > ( V_242 -> V_222 <= V_59 && ! ( V_242 -> V_27 & V_263 ) ? V_59 : V_243 ) - V_224 )
V_276 = V_243 - V_224 ;
V_277 = V_276 + V_224 ;
if ( ( V_27 & V_281 ) &&
! ( V_118 -> V_18 . V_9 -> V_273 & V_282 ) )
V_279 = V_59 ;
else
V_279 = V_276 + V_224 ;
V_279 += V_245 ;
if ( V_276 == V_222 + V_278 )
V_279 += V_118 -> V_18 . V_283 ;
V_279 += sizeof( struct V_154 ) ;
if ( V_225 ) {
V_2 = F_142 ( V_29 ,
V_279 + V_223 ,
( V_27 & V_227 ) , & V_11 ) ;
} else {
V_2 = NULL ;
if ( F_96 ( & V_29 -> V_284 ) <=
2 * V_29 -> V_285 )
V_2 = F_154 ( V_29 ,
V_279 + V_223 , 1 ,
V_29 -> V_252 ) ;
if ( F_38 ( V_2 == NULL ) )
V_11 = - V_64 ;
else {
V_248 = 0 ;
}
}
if ( V_2 == NULL )
goto error;
V_2 -> V_15 = V_247 ;
V_2 -> V_229 = 0 ;
F_116 ( V_2 , V_223 + sizeof( struct V_154 ) +
V_245 ) ;
if ( V_29 -> V_268 == V_269 )
F_105 ( V_2 ) -> V_248 = V_248 ;
V_91 = F_58 ( V_2 , V_277 ) ;
F_155 ( V_2 , V_244 ) ;
V_91 += V_224 ;
V_2 -> V_192 = ( V_2 -> V_146 +
V_224 ) ;
if ( V_278 ) {
V_2 -> V_229 = F_156 (
V_280 , V_243 ,
V_91 + V_225 , V_278 , 0 ) ;
V_280 -> V_229 = F_157 ( V_280 -> V_229 ,
V_2 -> V_229 ) ;
V_91 += V_278 ;
F_158 ( V_280 , V_243 ) ;
}
V_246 = V_276 - V_225 - V_278 ;
if ( V_246 < 0 ) {
V_11 = - V_39 ;
F_25 ( V_2 ) ;
goto error;
} else if ( V_246 > 0 && F_140 ( V_137 , V_91 + V_225 , V_87 , V_246 , V_278 , V_2 ) < 0 ) {
V_11 = - V_286 ;
F_25 ( V_2 ) ;
goto error;
}
V_87 += V_246 ;
V_222 -= V_276 - V_278 ;
V_225 = 0 ;
V_244 = 0 ;
V_245 = 0 ;
V_247 = V_186 ;
F_144 ( & V_29 -> V_226 , V_2 ) ;
continue;
}
if ( V_246 > V_222 )
V_246 = V_222 ;
if ( ! ( V_118 -> V_18 . V_9 -> V_273 & V_282 ) ) {
unsigned int V_287 ;
V_287 = V_2 -> V_3 ;
if ( F_140 ( V_137 , F_58 ( V_2 , V_246 ) ,
V_87 , V_246 , V_287 , V_2 ) < 0 ) {
F_159 ( V_2 , V_287 ) ;
V_11 = - V_286 ;
goto error;
}
} else {
int V_288 = F_105 ( V_2 ) -> V_289 ;
T_8 * V_163 = & F_105 ( V_2 ) -> V_290 [ V_288 - 1 ] ;
struct V_291 * V_291 = V_29 -> V_264 ;
int V_287 = V_29 -> V_265 ;
unsigned int V_167 ;
if ( V_291 && ( V_167 = V_292 - V_287 ) > 0 ) {
if ( V_246 >= V_167 )
V_246 = V_167 ;
if ( V_291 != F_160 ( V_163 ) ) {
if ( V_288 == V_293 ) {
V_11 = - V_77 ;
goto error;
}
F_161 ( V_2 , V_288 , V_291 , V_29 -> V_265 , 0 ) ;
F_162 ( V_2 , V_288 ) ;
V_163 = & F_105 ( V_2 ) -> V_290 [ V_288 ] ;
}
} else if( V_288 < V_293 ) {
if ( V_246 > V_292 )
V_246 = V_292 ;
V_291 = F_163 ( V_29 -> V_252 , 0 ) ;
if ( V_291 == NULL ) {
V_11 = - V_182 ;
goto error;
}
V_29 -> V_264 = V_291 ;
V_29 -> V_265 = 0 ;
F_161 ( V_2 , V_288 , V_291 , 0 , 0 ) ;
V_163 = & F_105 ( V_2 ) -> V_290 [ V_288 ] ;
} else {
V_11 = - V_77 ;
goto error;
}
if ( F_140 ( V_137 ,
F_164 ( V_163 ) + F_165 ( V_163 ) ,
V_87 , V_246 , V_2 -> V_3 , V_2 ) < 0 ) {
V_11 = - V_286 ;
goto error;
}
V_29 -> V_265 += V_246 ;
F_166 ( V_163 , V_246 ) ;
V_2 -> V_3 += V_246 ;
V_2 -> V_185 += V_246 ;
V_2 -> V_179 += V_246 ;
F_167 ( V_246 , & V_29 -> V_284 ) ;
}
V_87 += V_246 ;
V_222 -= V_246 ;
}
return 0 ;
error:
V_242 -> V_222 -= V_222 ;
F_24 ( F_41 ( V_29 ) , V_118 -> V_294 , V_35 ) ;
return V_11 ;
}
static void F_168 ( struct V_239 * V_240 , struct V_50 * V_51 )
{
if ( V_51 -> V_242 . V_47 ) {
F_112 ( V_51 -> V_242 . V_47 -> V_253 ) ;
F_112 ( V_51 -> V_242 . V_47 -> V_254 ) ;
F_112 ( V_51 -> V_242 . V_47 -> V_255 ) ;
F_112 ( V_51 -> V_242 . V_47 -> V_115 ) ;
F_112 ( V_51 -> V_242 . V_47 ) ;
V_51 -> V_242 . V_47 = NULL ;
}
if ( V_240 -> V_242 . V_250 . V_18 ) {
F_113 ( V_240 -> V_242 . V_250 . V_18 ) ;
V_240 -> V_242 . V_250 . V_18 = NULL ;
V_240 -> V_242 . V_250 . V_27 &= ~ V_263 ;
}
memset ( & V_240 -> V_242 . V_256 , 0 , sizeof( V_240 -> V_242 . V_256 ) ) ;
}
int F_169 ( struct V_43 * V_29 )
{
struct V_1 * V_2 , * V_295 ;
struct V_1 * * V_296 ;
struct V_52 V_297 , * V_216 = & V_297 ;
struct V_239 * V_240 = F_148 ( V_29 ) ;
struct V_50 * V_51 = F_42 ( V_29 ) ;
struct V_49 * V_49 = F_41 ( V_29 ) ;
struct V_4 * V_54 ;
struct V_46 * V_47 = V_51 -> V_242 . V_47 ;
struct V_117 * V_118 = (struct V_117 * ) V_240 -> V_242 . V_250 . V_18 ;
struct V_44 * V_45 = & V_240 -> V_242 . V_256 . V_257 . V_258 ;
unsigned char V_55 = V_45 -> V_56 ;
int V_11 = 0 ;
if ( ( V_2 = F_170 ( & V_29 -> V_226 ) ) == NULL )
goto V_199;
V_296 = & ( F_105 ( V_2 ) -> V_180 ) ;
if ( V_2 -> V_91 < F_67 ( V_2 ) )
F_10 ( V_2 , F_11 ( V_2 ) ) ;
while ( ( V_295 = F_170 ( & V_29 -> V_226 ) ) != NULL ) {
F_10 ( V_295 , F_171 ( V_2 ) ) ;
* V_296 = V_295 ;
V_296 = & ( V_295 -> V_83 ) ;
V_2 -> V_3 += V_295 -> V_3 ;
V_2 -> V_185 += V_295 -> V_3 ;
V_2 -> V_179 += V_295 -> V_179 ;
V_295 -> V_177 = NULL ;
V_295 -> V_29 = NULL ;
}
if ( V_51 -> V_259 < V_298 )
V_2 -> V_72 = 1 ;
* V_216 = V_45 -> V_24 ;
F_10 ( V_2 , F_171 ( V_2 ) ) ;
if ( V_47 && V_47 -> V_62 )
F_47 ( V_2 , V_47 , & V_55 ) ;
if ( V_47 && V_47 -> V_61 )
F_48 ( V_2 , V_47 , & V_55 , & V_216 ) ;
F_49 ( V_2 , sizeof( struct V_4 ) ) ;
F_50 ( V_2 ) ;
V_54 = F_2 ( V_2 ) ;
* ( V_65 * ) V_54 = V_45 -> V_66 |
F_52 ( 0x60000000 | ( ( int ) V_51 -> V_242 . V_48 << 20 ) ) ;
V_54 -> V_34 = V_51 -> V_242 . V_34 ;
V_54 -> V_67 = V_55 ;
V_54 -> V_31 = V_45 -> V_31 ;
V_54 -> V_24 = * V_216 ;
V_2 -> V_68 = V_29 -> V_69 ;
V_2 -> V_70 = V_29 -> V_71 ;
F_85 ( V_2 , F_86 ( & V_118 -> V_18 ) ) ;
F_26 ( V_49 , V_118 -> V_294 , V_73 , V_2 -> V_3 ) ;
if ( V_55 == V_88 ) {
struct V_25 * V_26 = F_16 ( F_5 ( V_2 ) ) ;
F_172 ( V_49 , V_26 , F_173 ( V_2 ) -> V_92 ) ;
F_174 ( V_49 , V_26 , V_299 ) ;
}
V_11 = F_6 ( V_2 ) ;
if ( V_11 ) {
if ( V_11 > 0 )
V_11 = F_175 ( V_11 ) ;
if ( V_11 )
goto error;
}
V_199:
F_168 ( V_240 , V_51 ) ;
return V_11 ;
error:
F_24 ( V_49 , V_118 -> V_294 , V_35 ) ;
goto V_199;
}
void F_176 ( struct V_43 * V_29 )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_177 ( & V_29 -> V_226 ) ) != NULL ) {
if ( F_5 ( V_2 ) )
F_24 ( F_41 ( V_29 ) , F_16 ( F_5 ( V_2 ) ) ,
V_35 ) ;
F_25 ( V_2 ) ;
}
F_168 ( F_148 ( V_29 ) , F_42 ( V_29 ) ) ;
}
