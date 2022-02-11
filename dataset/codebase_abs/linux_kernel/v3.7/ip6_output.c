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
V_18 = (struct V_17 * ) V_13 ;
V_16 = V_18 -> V_36 ;
if ( V_16 )
return F_21 ( V_13 , V_16 , V_2 ) ;
F_22 ( F_13 ( V_13 -> V_9 ) ,
F_10 ( V_13 ) , V_37 ) ;
F_19 ( V_2 ) ;
return - V_38 ;
}
static int F_23 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 > F_24 ( V_2 ) && ! F_25 ( V_2 ) ) ||
F_26 ( F_5 ( V_2 ) ) )
return F_27 ( V_2 , F_8 ) ;
else
return F_8 ( V_2 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_14 * V_9 = F_5 ( V_2 ) -> V_9 ;
struct V_22 * V_23 = F_10 ( F_5 ( V_2 ) ) ;
if ( F_29 ( V_23 -> V_39 . V_40 ) ) {
F_18 ( F_13 ( V_9 ) , V_23 ,
V_34 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
return F_30 ( V_7 , V_31 , V_2 , NULL , V_9 ,
F_23 ,
! ( F_14 ( V_2 ) -> V_24 & V_41 ) ) ;
}
int F_31 ( struct V_42 * V_26 , struct V_1 * V_2 , struct V_43 * V_44 ,
struct V_45 * V_46 , int V_47 )
{
struct V_48 * V_48 = F_32 ( V_26 ) ;
struct V_49 * V_50 = F_33 ( V_26 ) ;
struct V_51 * V_52 = & V_44 -> V_21 ;
struct V_12 * V_13 = F_5 ( V_2 ) ;
struct V_4 * V_53 ;
T_1 V_54 = V_44 -> V_55 ;
int V_56 = V_2 -> V_3 ;
int V_57 = - 1 ;
T_2 V_58 ;
if ( V_46 ) {
unsigned int V_59 ;
V_59 = V_46 -> V_60 + V_46 -> V_61 ;
V_56 += V_59 ;
V_59 += sizeof( struct V_4 ) + F_34 ( V_13 -> V_9 ) ;
if ( F_35 ( V_2 ) < V_59 ) {
struct V_1 * V_62 = F_36 ( V_2 , V_59 ) ;
if ( V_62 == NULL ) {
F_18 ( V_48 , F_10 ( F_5 ( V_2 ) ) ,
V_34 ) ;
F_19 ( V_2 ) ;
return - V_63 ;
}
F_37 ( V_2 ) ;
V_2 = V_62 ;
F_38 ( V_2 , V_26 ) ;
}
if ( V_46 -> V_61 )
F_39 ( V_2 , V_46 , & V_54 ) ;
if ( V_46 -> V_60 )
F_40 ( V_2 , V_46 , & V_54 , & V_52 ) ;
}
F_41 ( V_2 , sizeof( struct V_4 ) ) ;
F_42 ( V_2 ) ;
V_53 = F_2 ( V_2 ) ;
if ( V_50 )
V_57 = V_50 -> V_33 ;
if ( V_57 < 0 )
V_57 = F_43 ( V_13 ) ;
* ( V_64 * ) V_53 = F_44 ( 0x60000000 | ( V_47 << 20 ) ) | V_44 -> V_65 ;
V_53 -> V_6 = F_3 ( V_56 ) ;
V_53 -> V_66 = V_54 ;
V_53 -> V_33 = V_57 ;
V_53 -> V_28 = V_44 -> V_28 ;
V_53 -> V_21 = * V_52 ;
V_2 -> V_67 = V_26 -> V_68 ;
V_2 -> V_69 = V_26 -> V_70 ;
V_58 = F_45 ( V_13 ) ;
if ( ( V_2 -> V_3 <= V_58 ) || V_2 -> V_71 || F_25 ( V_2 ) ) {
F_20 ( V_48 , F_10 ( F_5 ( V_2 ) ) ,
V_72 , V_2 -> V_3 ) ;
return F_17 ( V_7 , V_8 , V_2 , NULL ,
V_13 -> V_9 , V_10 ) ;
}
F_46 ( L_1 ) ;
V_2 -> V_9 = V_13 -> V_9 ;
F_47 ( V_2 , V_73 , 0 , V_58 ) ;
F_18 ( V_48 , F_10 ( F_5 ( V_2 ) ) , V_74 ) ;
F_19 ( V_2 ) ;
return - V_75 ;
}
int F_48 ( struct V_42 * V_26 , struct V_1 * V_2 , struct V_14 * V_9 ,
const struct V_51 * V_28 , const struct V_51 * V_21 ,
int V_54 , int V_3 )
{
struct V_49 * V_50 = F_33 ( V_26 ) ;
struct V_4 * V_53 ;
V_2 -> V_19 = F_3 ( V_20 ) ;
V_2 -> V_9 = V_9 ;
F_42 ( V_2 ) ;
F_49 ( V_2 , sizeof( struct V_4 ) ) ;
V_53 = F_2 ( V_2 ) ;
* ( V_64 * ) V_53 = F_44 ( 0x60000000 ) ;
V_53 -> V_6 = F_3 ( V_3 ) ;
V_53 -> V_66 = V_54 ;
V_53 -> V_33 = V_50 -> V_33 ;
V_53 -> V_28 = * V_28 ;
V_53 -> V_21 = * V_21 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , int V_76 )
{
struct V_77 * V_78 ;
struct V_42 * V_79 = NULL ;
F_51 ( & V_80 ) ;
for ( V_78 = V_77 ; V_78 ; V_78 = V_78 -> V_81 ) {
struct V_42 * V_26 = V_78 -> V_26 ;
if ( V_26 && V_78 -> V_76 == V_76 &&
( ! V_26 -> V_82 ||
V_26 -> V_82 == V_2 -> V_9 -> V_83 ) ) {
if ( V_79 ) {
struct V_1 * V_62 = F_16 ( V_2 , V_30 ) ;
if ( V_62 )
F_52 ( V_79 , V_62 ) ;
}
V_79 = V_26 ;
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
struct V_4 * V_53 = F_2 ( V_2 ) ;
T_1 V_66 = V_53 -> V_66 ;
T_3 V_84 ;
int V_85 ;
if ( F_55 ( V_66 ) ) {
V_85 = F_56 ( V_2 , sizeof( * V_53 ) , & V_66 , & V_84 ) ;
if ( V_85 < 0 )
return 0 ;
} else
V_85 = sizeof( struct V_4 ) ;
if ( V_66 == V_86 ) {
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
if ( F_59 ( & V_53 -> V_21 ) & V_96 ) {
F_60 ( V_2 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_61 ( struct V_1 * V_2 )
{
return V_10 ( V_2 ) ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_5 ( V_2 ) ;
struct V_4 * V_53 = F_2 ( V_2 ) ;
struct V_97 * V_46 = F_14 ( V_2 ) ;
struct V_48 * V_48 = F_13 ( V_13 -> V_9 ) ;
T_2 V_58 ;
if ( V_48 -> V_98 . V_99 -> V_100 == 0 )
goto error;
if ( F_63 ( V_2 ) )
goto V_101;
if ( ! F_64 ( NULL , V_102 , V_2 ) ) {
F_18 ( V_48 , F_10 ( V_13 ) , V_103 ) ;
goto V_101;
}
if ( V_2 -> V_104 != V_105 )
goto V_101;
F_65 ( V_2 ) ;
if ( V_46 -> V_78 ) {
T_1 * V_106 = F_58 ( V_2 ) + V_46 -> V_78 ;
if ( F_50 ( V_2 , ( V_106 [ 2 ] << 8 ) + V_106 [ 3 ] ) )
return 0 ;
}
if ( V_53 -> V_33 <= 1 ) {
V_2 -> V_9 = V_13 -> V_9 ;
F_47 ( V_2 , V_107 , V_108 , 0 ) ;
F_22 ( V_48 ,
F_10 ( V_13 ) , V_109 ) ;
F_19 ( V_2 ) ;
return - V_110 ;
}
if ( V_48 -> V_98 . V_99 -> V_111 &&
F_66 ( & V_112 , V_48 , & V_53 -> V_21 , V_2 -> V_9 , 0 ) ) {
int V_113 = F_54 ( V_2 ) ;
if ( V_113 > 0 )
return F_67 ( V_2 ) ;
else if ( V_113 < 0 ) {
F_18 ( V_48 , F_10 ( V_13 ) ,
V_103 ) ;
goto V_101;
}
}
if ( ! F_68 ( V_2 ) ) {
F_18 ( V_48 , F_10 ( V_13 ) , V_103 ) ;
goto V_101;
}
V_13 = F_5 ( V_2 ) ;
if ( V_2 -> V_9 == V_13 -> V_9 && V_46 -> V_114 == 0 && ! F_69 ( V_2 ) ) {
struct V_51 * V_115 = NULL ;
struct V_116 * V_117 ;
struct V_17 * V_18 ;
V_18 = (struct V_17 * ) V_13 ;
if ( V_18 -> V_118 & V_119 )
V_115 = & V_18 -> V_120 ;
else
V_115 = & V_53 -> V_21 ;
V_117 = F_70 ( V_48 -> V_98 . V_121 , & V_18 -> V_122 . V_123 , 1 ) ;
if ( F_71 ( V_117 , 1 * V_124 ) )
F_72 ( V_2 , V_115 ) ;
if ( V_117 )
F_73 ( V_117 ) ;
} else {
int V_125 = F_59 ( & V_53 -> V_28 ) ;
if ( V_125 == V_126 ||
V_125 & ( V_127 | V_128 ) )
goto error;
if ( V_125 & V_96 ) {
F_47 ( V_2 , V_129 ,
V_130 , 0 ) ;
goto error;
}
}
V_58 = F_45 ( V_13 ) ;
if ( V_58 < V_131 )
V_58 = V_131 ;
if ( ( ! V_2 -> V_71 && V_2 -> V_3 > V_58 && ! F_25 ( V_2 ) ) ||
( F_14 ( V_2 ) -> V_132 && F_14 ( V_2 ) -> V_132 > V_58 ) ) {
V_2 -> V_9 = V_13 -> V_9 ;
F_47 ( V_2 , V_73 , 0 , V_58 ) ;
F_22 ( V_48 ,
F_10 ( V_13 ) , V_133 ) ;
F_22 ( V_48 ,
F_10 ( V_13 ) , V_74 ) ;
F_19 ( V_2 ) ;
return - V_75 ;
}
if ( F_74 ( V_2 , V_13 -> V_9 -> V_134 ) ) {
F_18 ( V_48 , F_10 ( V_13 ) , V_34 ) ;
goto V_101;
}
V_53 = F_2 ( V_2 ) ;
V_53 -> V_33 -- ;
F_22 ( V_48 , F_10 ( V_13 ) , V_135 ) ;
F_75 ( V_48 , F_10 ( V_13 ) , V_136 , V_2 -> V_3 ) ;
return F_17 ( V_7 , V_137 , V_2 , V_2 -> V_9 , V_13 -> V_9 ,
F_61 ) ;
error:
F_22 ( V_48 , F_10 ( V_13 ) , V_138 ) ;
V_101:
F_19 ( V_2 ) ;
return - V_38 ;
}
static void F_76 ( struct V_1 * V_139 , struct V_1 * V_140 )
{
V_139 -> V_104 = V_140 -> V_104 ;
V_139 -> V_67 = V_140 -> V_67 ;
V_139 -> V_19 = V_140 -> V_19 ;
F_77 ( V_139 ) ;
F_78 ( V_139 , F_79 ( F_5 ( V_140 ) ) ) ;
V_139 -> V_9 = V_140 -> V_9 ;
V_139 -> V_69 = V_140 -> V_69 ;
#ifdef F_80
V_139 -> V_141 = V_140 -> V_141 ;
#endif
F_81 ( V_139 , V_140 ) ;
#if F_82 ( V_142 ) || \
F_82 ( V_143 )
V_139 -> V_144 = V_140 -> V_144 ;
#endif
F_83 ( V_139 , V_140 ) ;
}
int F_84 ( struct V_1 * V_2 , T_1 * * V_66 )
{
T_4 V_85 = sizeof( struct V_4 ) ;
struct V_145 * V_146 =
(struct V_145 * ) ( F_2 ( V_2 ) + 1 ) ;
unsigned int V_147 = V_2 -> V_148 - V_2 -> V_149 ;
int V_150 = 0 ;
* V_66 = & F_2 ( V_2 ) -> V_66 ;
while ( V_85 + 1 <= V_147 ) {
switch ( * * V_66 ) {
case V_151 :
break;
case V_152 :
V_150 = 1 ;
break;
case V_153 :
#if F_82 ( V_154 ) || F_82 ( V_155 )
if ( F_85 ( V_2 , V_85 , V_156 ) >= 0 )
break;
#endif
if ( V_150 )
return V_85 ;
break;
default :
return V_85 ;
}
V_85 += F_86 ( V_146 ) ;
* V_66 = & V_146 -> V_66 ;
V_146 = (struct V_145 * ) ( F_58 ( V_2 ) +
V_85 ) ;
}
return V_85 ;
}
void F_87 ( struct V_157 * V_158 , struct V_17 * V_18 )
{
static T_5 V_159 ;
int V_160 , V_161 ;
if ( V_18 && ! ( V_18 -> V_13 . V_24 & V_162 ) ) {
struct V_116 * V_117 ;
struct V_48 * V_48 ;
V_48 = F_13 ( V_18 -> V_13 . V_9 ) ;
V_117 = F_70 ( V_48 -> V_98 . V_121 , & V_18 -> V_122 . V_123 , 1 ) ;
if ( V_117 ) {
V_158 -> V_163 = F_44 ( F_88 ( V_117 , 0 ) ) ;
F_73 ( V_117 ) ;
return;
}
}
do {
V_160 = F_89 ( & V_159 ) ;
V_161 = V_160 + 1 ;
if ( ! V_161 )
V_161 = 1 ;
} while ( F_90 ( & V_159 , V_160 , V_161 ) != V_160 );
V_158 -> V_163 = F_44 ( V_161 ) ;
}
int F_27 ( struct V_1 * V_2 , int (* F_91)( struct V_1 * ) )
{
struct V_1 * V_164 ;
struct V_17 * V_18 = (struct V_17 * ) F_5 ( V_2 ) ;
struct V_49 * V_50 = V_2 -> V_26 ? F_33 ( V_2 -> V_26 ) : NULL ;
struct V_4 * V_165 ;
struct V_157 * V_166 ;
unsigned int V_58 , V_167 , V_168 , V_3 ;
int V_169 , V_170 ;
V_64 V_171 = 0 ;
int V_106 , V_85 = 0 , V_11 = 0 ;
T_1 * V_172 , V_66 = 0 ;
struct V_48 * V_48 = F_13 ( F_5 ( V_2 ) -> V_9 ) ;
V_167 = F_84 ( V_2 , & V_172 ) ;
V_66 = * V_172 ;
V_58 = F_24 ( V_2 ) ;
if ( F_29 ( ! V_2 -> V_71 && V_2 -> V_3 > V_58 ) ||
( F_14 ( V_2 ) -> V_132 &&
F_14 ( V_2 ) -> V_132 > V_58 ) ) {
if ( V_2 -> V_26 && F_26 ( F_5 ( V_2 ) ) )
F_92 ( V_2 -> V_26 , V_173 ) ;
V_2 -> V_9 = F_5 ( V_2 ) -> V_9 ;
F_47 ( V_2 , V_73 , 0 , V_58 ) ;
F_18 ( V_48 , F_10 ( F_5 ( V_2 ) ) ,
V_74 ) ;
F_19 ( V_2 ) ;
return - V_75 ;
}
if ( V_50 && V_50 -> V_174 < V_58 ) {
if ( V_50 -> V_174 )
V_58 = V_50 -> V_174 ;
}
V_58 -= V_167 + sizeof( struct V_157 ) ;
if ( F_93 ( V_2 ) ) {
int V_175 = F_94 ( V_2 ) ;
struct V_1 * V_176 ;
if ( V_175 - V_167 > V_58 ||
( ( V_175 - V_167 ) & 7 ) ||
F_95 ( V_2 ) )
goto V_177;
F_96 (skb, frag) {
if ( V_164 -> V_3 > V_58 ||
( ( V_164 -> V_3 & 7 ) && V_164 -> V_81 ) ||
F_35 ( V_164 ) < V_167 )
goto V_178;
if ( F_97 ( V_164 ) )
goto V_178;
F_98 ( V_164 -> V_26 ) ;
if ( V_2 -> V_26 ) {
V_164 -> V_26 = V_2 -> V_26 ;
V_164 -> V_179 = V_180 ;
}
V_2 -> V_181 -= V_164 -> V_181 ;
}
V_11 = 0 ;
V_85 = 0 ;
V_164 = F_99 ( V_2 ) -> V_182 ;
F_100 ( V_2 ) ;
* V_172 = V_183 ;
V_165 = F_101 ( F_58 ( V_2 ) , V_167 , V_30 ) ;
if ( ! V_165 ) {
F_18 ( V_48 , F_10 ( F_5 ( V_2 ) ) ,
V_74 ) ;
return - V_184 ;
}
F_102 ( V_2 , V_167 ) ;
V_166 = (struct V_157 * ) F_103 ( V_2 , sizeof( struct V_157 ) ) ;
F_103 ( V_2 , V_167 ) ;
F_42 ( V_2 ) ;
memcpy ( F_58 ( V_2 ) , V_165 , V_167 ) ;
F_87 ( V_166 , V_18 ) ;
V_166 -> V_66 = V_66 ;
V_166 -> V_185 = 0 ;
V_166 -> V_84 = F_3 ( V_186 ) ;
V_171 = V_166 -> V_163 ;
V_175 = F_94 ( V_2 ) ;
V_2 -> V_187 = V_175 - F_104 ( V_2 ) ;
V_2 -> V_3 = V_175 ;
F_2 ( V_2 ) -> V_6 = F_3 ( V_175 -
sizeof( struct V_4 ) ) ;
F_105 ( & V_18 -> V_13 ) ;
for (; ; ) {
if ( V_164 ) {
V_164 -> V_188 = V_189 ;
F_106 ( V_164 ) ;
V_166 = (struct V_157 * ) F_103 ( V_164 , sizeof( struct V_157 ) ) ;
F_103 ( V_164 , V_167 ) ;
F_42 ( V_164 ) ;
memcpy ( F_58 ( V_164 ) , V_165 ,
V_167 ) ;
V_85 += V_2 -> V_3 - V_167 - sizeof( struct V_157 ) ;
V_166 -> V_66 = V_66 ;
V_166 -> V_185 = 0 ;
V_166 -> V_84 = F_3 ( V_85 ) ;
if ( V_164 -> V_81 != NULL )
V_166 -> V_84 |= F_3 ( V_186 ) ;
V_166 -> V_163 = V_171 ;
F_2 ( V_164 ) -> V_6 =
F_3 ( V_164 -> V_3 -
sizeof( struct V_4 ) ) ;
F_76 ( V_164 , V_2 ) ;
}
V_11 = F_91 ( V_2 ) ;
if( ! V_11 )
F_18 ( V_48 , F_10 ( & V_18 -> V_13 ) ,
V_190 ) ;
if ( V_11 || ! V_164 )
break;
V_2 = V_164 ;
V_164 = V_2 -> V_81 ;
V_2 -> V_81 = NULL ;
}
F_107 ( V_165 ) ;
if ( V_11 == 0 ) {
F_18 ( V_48 , F_10 ( & V_18 -> V_13 ) ,
V_191 ) ;
F_108 ( & V_18 -> V_13 ) ;
return 0 ;
}
while ( V_164 ) {
V_2 = V_164 -> V_81 ;
F_19 ( V_164 ) ;
V_164 = V_2 ;
}
F_18 ( V_48 , F_10 ( & V_18 -> V_13 ) ,
V_74 ) ;
F_108 ( & V_18 -> V_13 ) ;
return V_11 ;
V_178:
F_96 (skb, frag2) {
if ( V_176 == V_164 )
break;
V_176 -> V_26 = NULL ;
V_176 -> V_179 = NULL ;
V_2 -> V_181 += V_176 -> V_181 ;
}
}
V_177:
if ( ( V_2 -> V_188 == V_192 ) &&
F_109 ( V_2 ) )
goto V_193;
V_168 = V_2 -> V_3 - V_167 ;
V_106 = V_167 ;
* V_172 = V_183 ;
V_169 = F_34 ( V_18 -> V_13 . V_9 ) ;
V_170 = V_18 -> V_13 . V_9 -> V_194 ;
while( V_168 > 0 ) {
V_3 = V_168 ;
if ( V_3 > V_58 )
V_3 = V_58 ;
if ( V_3 < V_168 ) {
V_3 &= ~ 7 ;
}
if ( ( V_164 = F_110 ( V_3 + V_167 + sizeof( struct V_157 ) +
V_169 + V_170 , V_30 ) ) == NULL ) {
F_111 ( V_195 L_2 ) ;
F_18 ( V_48 , F_10 ( F_5 ( V_2 ) ) ,
V_74 ) ;
V_11 = - V_184 ;
goto V_193;
}
F_76 ( V_164 , V_2 ) ;
F_112 ( V_164 , V_169 ) ;
F_49 ( V_164 , V_3 + V_167 + sizeof( struct V_157 ) ) ;
F_42 ( V_164 ) ;
V_166 = (struct V_157 * ) ( F_58 ( V_164 ) + V_167 ) ;
V_164 -> V_196 = ( V_164 -> V_149 + V_167 +
sizeof( struct V_157 ) ) ;
if ( V_2 -> V_26 )
F_38 ( V_164 , V_2 -> V_26 ) ;
F_113 ( V_2 , F_58 ( V_164 ) , V_167 ) ;
V_166 -> V_66 = V_66 ;
V_166 -> V_185 = 0 ;
if ( ! V_171 ) {
F_87 ( V_166 , V_18 ) ;
V_171 = V_166 -> V_163 ;
} else
V_166 -> V_163 = V_171 ;
if ( F_114 ( V_2 , V_106 , F_115 ( V_164 ) , V_3 ) )
F_116 () ;
V_168 -= V_3 ;
V_166 -> V_84 = F_3 ( V_85 ) ;
if ( V_168 > 0 )
V_166 -> V_84 |= F_3 ( V_186 ) ;
F_2 ( V_164 ) -> V_6 = F_3 ( V_164 -> V_3 -
sizeof( struct V_4 ) ) ;
V_106 += V_3 ;
V_85 += V_3 ;
V_11 = F_91 ( V_164 ) ;
if ( V_11 )
goto V_193;
F_18 ( V_48 , F_10 ( F_5 ( V_2 ) ) ,
V_190 ) ;
}
F_18 ( V_48 , F_10 ( F_5 ( V_2 ) ) ,
V_191 ) ;
F_37 ( V_2 ) ;
return V_11 ;
V_193:
F_18 ( V_48 , F_10 ( F_5 ( V_2 ) ) ,
V_74 ) ;
F_19 ( V_2 ) ;
return V_11 ;
}
static inline int F_117 ( const struct V_197 * V_198 ,
const struct V_51 * V_199 ,
const struct V_51 * V_200 )
{
return ( V_198 -> V_201 != 128 || ! F_118 ( V_199 , & V_198 -> V_123 ) ) &&
( V_200 == NULL || ! F_118 ( V_199 , V_200 ) ) ;
}
static struct V_12 * F_119 ( struct V_42 * V_26 ,
struct V_12 * V_13 ,
const struct V_43 * V_44 )
{
struct V_49 * V_50 = F_33 ( V_26 ) ;
struct V_17 * V_18 = (struct V_17 * ) V_13 ;
if ( ! V_13 )
goto V_202;
if ( F_117 ( & V_18 -> V_122 , & V_44 -> V_21 , V_50 -> V_203 ) ||
#ifdef F_120
F_117 ( & V_18 -> V_204 , & V_44 -> V_28 , V_50 -> V_205 ) ||
#endif
( V_44 -> V_206 && V_44 -> V_206 != V_13 -> V_9 -> V_83 ) ) {
F_108 ( V_13 ) ;
V_13 = NULL ;
}
V_202:
return V_13 ;
}
static int F_121 ( struct V_42 * V_26 ,
struct V_12 * * V_13 , struct V_43 * V_44 )
{
struct V_48 * V_48 = F_32 ( V_26 ) ;
#ifdef F_122
struct V_15 * V_36 ;
struct V_17 * V_18 ;
#endif
int V_11 ;
if ( * V_13 == NULL )
* V_13 = F_123 ( V_48 , V_26 , V_44 ) ;
if ( ( V_11 = ( * V_13 ) -> error ) )
goto V_207;
if ( F_124 ( & V_44 -> V_28 ) ) {
struct V_17 * V_18 = (struct V_17 * ) * V_13 ;
V_11 = F_125 ( V_48 , V_18 , & V_44 -> V_21 ,
V_26 ? F_33 ( V_26 ) -> V_208 : 0 ,
& V_44 -> V_28 ) ;
if ( V_11 )
goto V_207;
}
#ifdef F_122
V_18 = (struct V_17 * ) * V_13 ;
V_36 = V_18 -> V_36 ;
if ( V_36 && ! ( V_36 -> V_209 & V_210 ) ) {
struct V_211 * V_212 ;
struct V_43 V_213 ;
int V_214 ;
V_212 = F_126 ( V_48 , & V_44 -> V_28 ,
( * V_13 ) -> V_9 , 1 ) ;
V_214 = ( V_212 && V_212 -> V_24 & V_215 ) ;
if ( V_212 )
F_127 ( V_212 ) ;
if ( V_214 ) {
F_108 ( * V_13 ) ;
memcpy ( & V_213 , V_44 , sizeof( struct V_43 ) ) ;
memset ( & V_213 . V_21 , 0 , sizeof( struct V_51 ) ) ;
* V_13 = F_123 ( V_48 , V_26 , & V_213 ) ;
if ( ( V_11 = ( * V_13 ) -> error ) )
goto V_207;
}
}
#endif
return 0 ;
V_207:
if ( V_11 == - V_216 )
F_22 ( V_48 , NULL , V_37 ) ;
F_108 ( * V_13 ) ;
* V_13 = NULL ;
return V_11 ;
}
int F_128 ( struct V_42 * V_26 , struct V_12 * * V_13 , struct V_43 * V_44 )
{
* V_13 = NULL ;
return F_121 ( V_26 , V_13 , V_44 ) ;
}
struct V_12 * F_129 ( struct V_42 * V_26 , struct V_43 * V_44 ,
const struct V_51 * V_217 ,
bool V_218 )
{
struct V_12 * V_13 = NULL ;
int V_11 ;
V_11 = F_121 ( V_26 , & V_13 , V_44 ) ;
if ( V_11 )
return F_130 ( V_11 ) ;
if ( V_217 )
V_44 -> V_21 = * V_217 ;
if ( V_218 )
V_44 -> V_219 |= V_220 ;
return F_131 ( F_32 ( V_26 ) , V_13 , F_132 ( V_44 ) , V_26 , 0 ) ;
}
struct V_12 * F_133 ( struct V_42 * V_26 , struct V_43 * V_44 ,
const struct V_51 * V_217 ,
bool V_218 )
{
struct V_12 * V_13 = F_134 ( V_26 , F_33 ( V_26 ) -> V_221 ) ;
int V_11 ;
V_13 = F_119 ( V_26 , V_13 , V_44 ) ;
V_11 = F_121 ( V_26 , & V_13 , V_44 ) ;
if ( V_11 )
return F_130 ( V_11 ) ;
if ( V_217 )
V_44 -> V_21 = * V_217 ;
if ( V_218 )
V_44 -> V_219 |= V_220 ;
return F_131 ( F_32 ( V_26 ) , V_13 , F_132 ( V_44 ) , V_26 , 0 ) ;
}
static inline int F_135 ( struct V_42 * V_26 ,
int F_136 ( void * V_140 , char * V_139 , int V_85 , int V_3 ,
int V_222 , struct V_1 * V_2 ) ,
void * V_140 , int V_223 , int V_224 , int V_225 ,
int V_226 , int V_58 , unsigned int V_24 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 ;
int V_11 ;
if ( ( V_2 = F_137 ( & V_26 -> V_227 ) ) == NULL ) {
V_2 = F_138 ( V_26 ,
V_224 + V_225 + V_226 + 20 ,
( V_24 & V_228 ) , & V_11 ) ;
if ( V_2 == NULL )
return V_11 ;
F_112 ( V_2 , V_224 ) ;
F_49 ( V_2 , V_225 + V_226 ) ;
F_42 ( V_2 ) ;
V_2 -> V_196 = V_2 -> V_149 + V_225 ;
V_2 -> V_188 = V_192 ;
V_2 -> V_229 = 0 ;
}
V_11 = F_139 ( V_26 , V_2 , F_136 , V_140 ,
( V_223 - V_226 ) ) ;
if ( ! V_11 ) {
struct V_157 V_158 ;
F_99 ( V_2 ) -> V_230 = ( V_58 - V_225 -
sizeof( struct V_157 ) ) & ~ 7 ;
F_99 ( V_2 ) -> V_231 = V_232 ;
F_87 ( & V_158 , V_18 ) ;
F_99 ( V_2 ) -> V_233 = V_158 . V_163 ;
F_140 ( & V_26 -> V_227 , V_2 ) ;
return 0 ;
}
F_19 ( V_2 ) ;
return V_11 ;
}
static inline struct V_145 * F_141 ( struct V_145 * V_234 ,
T_6 V_235 )
{
return V_234 ? F_101 ( V_234 , ( V_234 -> V_236 + 1 ) * 8 , V_235 ) : NULL ;
}
static inline struct V_237 * F_142 ( struct V_237 * V_234 ,
T_6 V_235 )
{
return V_234 ? F_101 ( V_234 , ( V_234 -> V_236 + 1 ) * 8 , V_235 ) : NULL ;
}
static void F_143 ( int * V_58 ,
int * V_238 ,
unsigned int V_225 ,
struct V_1 * V_2 ,
struct V_17 * V_18 )
{
if ( ! ( V_18 -> V_13 . V_24 & V_239 ) ) {
if ( V_2 == NULL ) {
* V_58 = * V_58 - V_18 -> V_13 . V_240 ;
} else {
* V_58 = F_45 ( V_18 -> V_13 . V_241 ) ;
}
* V_238 = ( ( * V_58 - V_225 ) & ~ 7 )
+ V_225 - sizeof( struct V_157 ) ;
}
}
int F_144 ( struct V_42 * V_26 , int F_136 ( void * V_140 , char * V_139 ,
int V_85 , int V_3 , int V_222 , struct V_1 * V_2 ) ,
void * V_140 , int V_223 , int V_226 ,
int V_57 , int V_47 , struct V_45 * V_46 , struct V_43 * V_44 ,
struct V_17 * V_18 , unsigned int V_24 , int V_242 )
{
struct V_243 * V_244 = F_145 ( V_26 ) ;
struct V_49 * V_50 = F_33 ( V_26 ) ;
struct V_245 * V_246 ;
struct V_1 * V_2 , * V_247 = NULL ;
unsigned int V_238 , V_225 ;
int V_248 ;
int V_249 ;
int V_224 ;
int V_58 ;
int V_250 ;
int V_11 ;
int V_85 = 0 ;
T_7 V_251 = 0 ;
if ( V_24 & V_252 )
return 0 ;
V_246 = & V_244 -> V_246 . V_253 ;
if ( F_146 ( & V_26 -> V_227 ) ) {
if ( V_46 ) {
if ( F_147 ( V_50 -> V_246 . V_46 ) )
return - V_38 ;
V_50 -> V_246 . V_46 = F_148 ( V_46 -> V_254 , V_26 -> V_255 ) ;
if ( F_29 ( V_50 -> V_246 . V_46 == NULL ) )
return - V_63 ;
V_50 -> V_246 . V_46 -> V_254 = V_46 -> V_254 ;
V_50 -> V_246 . V_46 -> V_61 = V_46 -> V_61 ;
V_50 -> V_246 . V_46 -> V_60 = V_46 -> V_60 ;
V_50 -> V_246 . V_46 -> V_256 = F_141 ( V_46 -> V_256 ,
V_26 -> V_255 ) ;
if ( V_46 -> V_256 && ! V_50 -> V_246 . V_46 -> V_256 )
return - V_63 ;
V_50 -> V_246 . V_46 -> V_257 = F_141 ( V_46 -> V_257 ,
V_26 -> V_255 ) ;
if ( V_46 -> V_257 && ! V_50 -> V_246 . V_46 -> V_257 )
return - V_63 ;
V_50 -> V_246 . V_46 -> V_258 = F_141 ( V_46 -> V_258 ,
V_26 -> V_255 ) ;
if ( V_46 -> V_258 && ! V_50 -> V_246 . V_46 -> V_258 )
return - V_63 ;
V_50 -> V_246 . V_46 -> V_114 = F_142 ( V_46 -> V_114 ,
V_26 -> V_255 ) ;
if ( V_46 -> V_114 && ! V_50 -> V_246 . V_46 -> V_114 )
return - V_63 ;
}
F_105 ( & V_18 -> V_13 ) ;
V_246 -> V_13 = & V_18 -> V_13 ;
V_244 -> V_246 . V_259 . V_260 . V_261 = * V_44 ;
V_50 -> V_246 . V_33 = V_57 ;
V_50 -> V_246 . V_47 = V_47 ;
if ( V_18 -> V_13 . V_24 & V_239 )
V_58 = V_50 -> V_262 == V_263 ?
V_18 -> V_13 . V_9 -> V_58 : F_45 ( & V_18 -> V_13 ) ;
else
V_58 = V_50 -> V_262 == V_263 ?
V_18 -> V_13 . V_9 -> V_58 : F_45 ( V_18 -> V_13 . V_241 ) ;
if ( V_50 -> V_174 < V_58 ) {
if ( V_50 -> V_174 )
V_58 = V_50 -> V_174 ;
}
V_246 -> V_264 = V_58 ;
if ( F_26 ( V_18 -> V_13 . V_241 ) )
V_246 -> V_24 |= V_265 ;
V_246 -> V_223 = 0 ;
V_248 = ( V_46 ? V_46 -> V_61 : 0 ) - V_18 -> V_266 ;
V_223 += V_248 ;
V_226 += V_248 ;
V_249 = V_18 -> V_13 . V_240 ;
} else {
V_18 = (struct V_17 * ) V_246 -> V_13 ;
V_44 = & V_244 -> V_246 . V_259 . V_260 . V_261 ;
V_46 = V_50 -> V_246 . V_46 ;
V_226 = 0 ;
V_248 = 0 ;
V_249 = 0 ;
V_58 = V_246 -> V_264 ;
}
V_224 = F_34 ( V_18 -> V_13 . V_9 ) ;
V_225 = sizeof( struct V_4 ) + V_18 -> V_266 +
( V_46 ? V_46 -> V_60 : 0 ) ;
V_238 = ( ( V_58 - V_225 ) & ~ 7 ) + V_225 - sizeof( struct V_157 ) ;
if ( V_58 <= sizeof( struct V_4 ) + V_5 ) {
if ( V_246 -> V_223 + V_223 > sizeof( struct V_4 ) + V_5 - V_225 ) {
F_149 ( V_26 , V_75 , V_44 , V_58 - V_248 ) ;
return - V_75 ;
}
}
if ( V_26 -> V_267 == V_268 ) {
V_11 = F_150 ( V_26 , & V_251 ) ;
if ( V_11 )
goto error;
}
V_246 -> V_223 += V_223 ;
if ( V_223 > V_58 ) {
int V_54 = V_26 -> V_269 ;
if ( V_242 && ( V_54 == V_270 || V_54 == V_271 ) ) {
F_151 ( V_26 , V_44 , V_58 - V_248 ) ;
return - V_75 ;
}
if ( V_54 == V_270 &&
( V_18 -> V_13 . V_9 -> V_272 & V_273 ) ) {
V_11 = F_135 ( V_26 , F_136 , V_140 , V_223 ,
V_224 , V_225 ,
V_226 , V_58 , V_24 , V_18 ) ;
if ( V_11 )
goto error;
return 0 ;
}
}
if ( ( V_2 = F_137 ( & V_26 -> V_227 ) ) == NULL )
goto V_274;
while ( V_223 > 0 ) {
V_250 = ( V_246 -> V_223 <= V_58 && ! ( V_246 -> V_24 & V_265 ) ? V_58 : V_238 ) - V_2 -> V_3 ;
if ( V_250 < V_223 )
V_250 = V_238 - V_2 -> V_3 ;
if ( V_250 <= 0 ) {
char * V_89 ;
unsigned int V_275 ;
unsigned int V_276 ;
unsigned int V_277 ;
unsigned int V_278 ;
V_274:
if ( V_2 )
V_277 = V_2 -> V_3 - V_238 ;
else
V_277 = 0 ;
if ( V_2 == NULL || V_247 == NULL )
F_143 ( & V_58 , & V_238 ,
V_225 , V_2 , V_18 ) ;
V_247 = V_2 ;
V_275 = V_223 + V_277 ;
if ( V_275 > ( V_246 -> V_223 <= V_58 && ! ( V_246 -> V_24 & V_265 ) ? V_58 : V_238 ) - V_225 )
V_275 = V_238 - V_225 - V_18 -> V_13 . V_279 ;
if ( ( V_24 & V_280 ) &&
! ( V_18 -> V_13 . V_9 -> V_272 & V_281 ) )
V_278 = V_58 ;
else
V_278 = V_275 + V_225 ;
V_278 += V_249 ;
if ( V_275 != V_223 + V_277 ) {
V_275 += V_18 -> V_13 . V_279 ;
}
V_278 += V_18 -> V_13 . V_279 ;
V_276 = V_275 + V_225 ;
V_278 += sizeof( struct V_157 ) ;
if ( V_226 ) {
V_2 = F_138 ( V_26 ,
V_278 + V_224 ,
( V_24 & V_228 ) , & V_11 ) ;
} else {
V_2 = NULL ;
if ( F_89 ( & V_26 -> V_282 ) <=
2 * V_26 -> V_283 )
V_2 = F_152 ( V_26 ,
V_278 + V_224 , 1 ,
V_26 -> V_255 ) ;
if ( F_29 ( V_2 == NULL ) )
V_11 = - V_63 ;
else {
V_251 = 0 ;
}
}
if ( V_2 == NULL )
goto error;
V_2 -> V_188 = V_189 ;
V_2 -> V_229 = 0 ;
F_112 ( V_2 , V_224 + sizeof( struct V_157 ) +
V_249 ) ;
if ( V_26 -> V_267 == V_268 )
F_99 ( V_2 ) -> V_251 = V_251 ;
V_89 = F_49 ( V_2 , V_276 ) ;
F_153 ( V_2 , V_248 ) ;
V_89 += V_225 ;
V_2 -> V_196 = ( V_2 -> V_149 +
V_225 ) ;
if ( V_277 ) {
V_2 -> V_229 = F_154 (
V_247 , V_238 ,
V_89 + V_226 , V_277 , 0 ) ;
V_247 -> V_229 = F_155 ( V_247 -> V_229 ,
V_2 -> V_229 ) ;
V_89 += V_277 ;
F_156 ( V_247 , V_238 ) ;
}
V_250 = V_275 - V_226 - V_277 ;
if ( V_250 < 0 ) {
V_11 = - V_38 ;
F_19 ( V_2 ) ;
goto error;
} else if ( V_250 > 0 && F_136 ( V_140 , V_89 + V_226 , V_85 , V_250 , V_277 , V_2 ) < 0 ) {
V_11 = - V_284 ;
F_19 ( V_2 ) ;
goto error;
}
V_85 += V_250 ;
V_223 -= V_275 - V_277 ;
V_226 = 0 ;
V_248 = 0 ;
V_249 = 0 ;
F_140 ( & V_26 -> V_227 , V_2 ) ;
continue;
}
if ( V_250 > V_223 )
V_250 = V_223 ;
if ( ! ( V_18 -> V_13 . V_9 -> V_272 & V_281 ) ) {
unsigned int V_285 ;
V_285 = V_2 -> V_3 ;
if ( F_136 ( V_140 , F_49 ( V_2 , V_250 ) ,
V_85 , V_250 , V_285 , V_2 ) < 0 ) {
F_157 ( V_2 , V_285 ) ;
V_11 = - V_284 ;
goto error;
}
} else {
int V_286 = F_99 ( V_2 ) -> V_287 ;
struct V_288 * V_289 = F_158 ( V_26 ) ;
V_11 = - V_184 ;
if ( ! F_159 ( V_26 , V_289 ) )
goto error;
if ( ! F_160 ( V_2 , V_286 , V_289 -> V_290 ,
V_289 -> V_85 ) ) {
V_11 = - V_75 ;
if ( V_286 == V_291 )
goto error;
F_161 ( V_2 , V_286 , V_289 -> V_290 ,
V_289 -> V_85 , 0 ) ;
F_99 ( V_2 ) -> V_287 = ++ V_286 ;
F_162 ( V_289 -> V_290 ) ;
}
V_250 = F_163 ( int , V_250 , V_289 -> V_292 - V_289 -> V_85 ) ;
if ( F_136 ( V_140 ,
F_164 ( V_289 -> V_290 ) + V_289 -> V_85 ,
V_85 , V_250 , V_2 -> V_3 , V_2 ) < 0 )
goto V_293;
V_289 -> V_85 += V_250 ;
F_165 ( & F_99 ( V_2 ) -> V_294 [ V_286 - 1 ] , V_250 ) ;
V_2 -> V_3 += V_250 ;
V_2 -> V_187 += V_250 ;
V_2 -> V_181 += V_250 ;
F_166 ( V_250 , & V_26 -> V_282 ) ;
}
V_85 += V_250 ;
V_223 -= V_250 ;
}
return 0 ;
V_293:
V_11 = - V_284 ;
error:
V_246 -> V_223 -= V_223 ;
F_18 ( F_32 ( V_26 ) , V_18 -> V_295 , V_34 ) ;
return V_11 ;
}
static void F_167 ( struct V_243 * V_244 , struct V_49 * V_50 )
{
if ( V_50 -> V_246 . V_46 ) {
F_107 ( V_50 -> V_246 . V_46 -> V_256 ) ;
F_107 ( V_50 -> V_246 . V_46 -> V_257 ) ;
F_107 ( V_50 -> V_246 . V_46 -> V_258 ) ;
F_107 ( V_50 -> V_246 . V_46 -> V_114 ) ;
F_107 ( V_50 -> V_246 . V_46 ) ;
V_50 -> V_246 . V_46 = NULL ;
}
if ( V_244 -> V_246 . V_253 . V_13 ) {
F_108 ( V_244 -> V_246 . V_253 . V_13 ) ;
V_244 -> V_246 . V_253 . V_13 = NULL ;
V_244 -> V_246 . V_253 . V_24 &= ~ V_265 ;
}
memset ( & V_244 -> V_246 . V_259 , 0 , sizeof( V_244 -> V_246 . V_259 ) ) ;
}
int F_168 ( struct V_42 * V_26 )
{
struct V_1 * V_2 , * V_296 ;
struct V_1 * * V_297 ;
struct V_51 V_298 , * V_217 = & V_298 ;
struct V_243 * V_244 = F_145 ( V_26 ) ;
struct V_49 * V_50 = F_33 ( V_26 ) ;
struct V_48 * V_48 = F_32 ( V_26 ) ;
struct V_4 * V_53 ;
struct V_45 * V_46 = V_50 -> V_246 . V_46 ;
struct V_17 * V_18 = (struct V_17 * ) V_244 -> V_246 . V_253 . V_13 ;
struct V_43 * V_44 = & V_244 -> V_246 . V_259 . V_260 . V_261 ;
unsigned char V_54 = V_44 -> V_55 ;
int V_11 = 0 ;
if ( ( V_2 = F_169 ( & V_26 -> V_227 ) ) == NULL )
goto V_202;
V_297 = & ( F_99 ( V_2 ) -> V_182 ) ;
if ( V_2 -> V_89 < F_58 ( V_2 ) )
F_102 ( V_2 , F_170 ( V_2 ) ) ;
while ( ( V_296 = F_169 ( & V_26 -> V_227 ) ) != NULL ) {
F_102 ( V_296 , F_171 ( V_2 ) ) ;
* V_297 = V_296 ;
V_297 = & ( V_296 -> V_81 ) ;
V_2 -> V_3 += V_296 -> V_3 ;
V_2 -> V_187 += V_296 -> V_3 ;
V_2 -> V_181 += V_296 -> V_181 ;
V_296 -> V_179 = NULL ;
V_296 -> V_26 = NULL ;
}
if ( V_50 -> V_262 < V_299 )
V_2 -> V_71 = 1 ;
* V_217 = V_44 -> V_21 ;
F_102 ( V_2 , F_171 ( V_2 ) ) ;
if ( V_46 && V_46 -> V_61 )
F_39 ( V_2 , V_46 , & V_54 ) ;
if ( V_46 && V_46 -> V_60 )
F_40 ( V_2 , V_46 , & V_54 , & V_217 ) ;
F_41 ( V_2 , sizeof( struct V_4 ) ) ;
F_42 ( V_2 ) ;
V_53 = F_2 ( V_2 ) ;
* ( V_64 * ) V_53 = V_44 -> V_65 |
F_44 ( 0x60000000 | ( ( int ) V_50 -> V_246 . V_47 << 20 ) ) ;
V_53 -> V_33 = V_50 -> V_246 . V_33 ;
V_53 -> V_66 = V_54 ;
V_53 -> V_28 = V_44 -> V_28 ;
V_53 -> V_21 = * V_217 ;
V_2 -> V_67 = V_26 -> V_68 ;
V_2 -> V_69 = V_26 -> V_70 ;
F_78 ( V_2 , F_79 ( & V_18 -> V_13 ) ) ;
F_20 ( V_48 , V_18 -> V_295 , V_72 , V_2 -> V_3 ) ;
if ( V_54 == V_86 ) {
struct V_22 * V_23 = F_10 ( F_5 ( V_2 ) ) ;
F_172 ( V_48 , V_23 , F_173 ( V_2 ) -> V_90 ) ;
F_174 ( V_48 , V_23 , V_300 ) ;
}
V_11 = F_6 ( V_2 ) ;
if ( V_11 ) {
if ( V_11 > 0 )
V_11 = F_175 ( V_11 ) ;
if ( V_11 )
goto error;
}
V_202:
F_167 ( V_244 , V_50 ) ;
return V_11 ;
error:
F_18 ( V_48 , V_18 -> V_295 , V_34 ) ;
goto V_202;
}
void F_176 ( struct V_42 * V_26 )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_177 ( & V_26 -> V_227 ) ) != NULL ) {
if ( F_5 ( V_2 ) )
F_18 ( F_32 ( V_26 ) , F_10 ( F_5 ( V_2 ) ) ,
V_34 ) ;
F_19 ( V_2 ) ;
}
F_167 ( F_145 ( V_26 ) , F_33 ( V_26 ) ) ;
}
