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
struct V_46 * V_47 )
{
struct V_48 * V_48 = F_41 ( V_29 ) ;
struct V_49 * V_50 = F_42 ( V_29 ) ;
struct V_51 * V_52 = & V_45 -> V_24 ;
struct V_17 * V_18 = F_5 ( V_2 ) ;
struct V_4 * V_53 ;
T_1 V_54 = V_45 -> V_55 ;
int V_56 = V_2 -> V_3 ;
int V_57 = - 1 ;
int V_58 = 0 ;
T_2 V_59 ;
if ( V_47 ) {
unsigned int V_60 ;
V_60 = V_47 -> V_61 + V_47 -> V_62 ;
V_56 += V_60 ;
V_60 += sizeof( struct V_4 ) + F_43 ( V_18 -> V_9 ) ;
if ( F_44 ( V_2 ) < V_60 ) {
struct V_1 * V_63 = F_45 ( V_2 , V_60 ) ;
if ( V_63 == NULL ) {
F_24 ( V_48 , F_16 ( F_5 ( V_2 ) ) ,
V_35 ) ;
F_25 ( V_2 ) ;
return - V_64 ;
}
F_25 ( V_2 ) ;
V_2 = V_63 ;
F_46 ( V_2 , V_29 ) ;
}
if ( V_47 -> V_62 )
F_47 ( V_2 , V_47 , & V_54 ) ;
if ( V_47 -> V_61 )
F_48 ( V_2 , V_47 , & V_54 , & V_52 ) ;
}
F_49 ( V_2 , sizeof( struct V_4 ) ) ;
F_50 ( V_2 ) ;
V_53 = F_2 ( V_2 ) ;
if ( V_50 ) {
V_58 = V_50 -> V_58 ;
V_57 = V_50 -> V_34 ;
}
if ( V_57 < 0 )
V_57 = F_51 ( V_18 ) ;
* ( V_65 * ) V_53 = F_52 ( 0x60000000 | ( V_58 << 20 ) ) | V_45 -> V_66 ;
V_53 -> V_6 = F_3 ( V_56 ) ;
V_53 -> V_67 = V_54 ;
V_53 -> V_34 = V_57 ;
F_53 ( & V_53 -> V_31 , & V_45 -> V_31 ) ;
F_53 ( & V_53 -> V_24 , V_52 ) ;
V_2 -> V_68 = V_29 -> V_69 ;
V_2 -> V_70 = V_29 -> V_71 ;
V_59 = F_54 ( V_18 ) ;
if ( ( V_2 -> V_3 <= V_59 ) || V_2 -> V_72 || F_34 ( V_2 ) ) {
F_26 ( V_48 , F_16 ( F_5 ( V_2 ) ) ,
V_73 , V_2 -> V_3 ) ;
return F_23 ( V_7 , V_8 , V_2 , NULL ,
V_18 -> V_9 , V_10 ) ;
}
if ( F_55 () )
F_56 ( V_74 L_1 ) ;
V_2 -> V_9 = V_18 -> V_9 ;
F_57 ( V_2 , V_75 , 0 , V_59 ) ;
F_24 ( V_48 , F_16 ( F_5 ( V_2 ) ) , V_76 ) ;
F_25 ( V_2 ) ;
return - V_77 ;
}
int F_58 ( struct V_43 * V_29 , struct V_1 * V_2 , struct V_19 * V_9 ,
const struct V_51 * V_31 , const struct V_51 * V_24 ,
int V_54 , int V_3 )
{
struct V_49 * V_50 = F_42 ( V_29 ) ;
struct V_4 * V_53 ;
V_2 -> V_22 = F_3 ( V_23 ) ;
V_2 -> V_9 = V_9 ;
F_50 ( V_2 ) ;
F_59 ( V_2 , sizeof( struct V_4 ) ) ;
V_53 = F_2 ( V_2 ) ;
* ( V_65 * ) V_53 = F_52 ( 0x60000000 ) ;
V_53 -> V_6 = F_3 ( V_3 ) ;
V_53 -> V_67 = V_54 ;
V_53 -> V_34 = V_50 -> V_34 ;
F_53 ( & V_53 -> V_31 , V_31 ) ;
F_53 ( & V_53 -> V_24 , V_24 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , int V_78 )
{
struct V_79 * V_80 ;
struct V_43 * V_81 = NULL ;
F_61 ( & V_82 ) ;
for ( V_80 = V_79 ; V_80 ; V_80 = V_80 -> V_83 ) {
struct V_43 * V_29 = V_80 -> V_29 ;
if ( V_29 && V_80 -> V_78 == V_78 &&
( ! V_29 -> V_84 ||
V_29 -> V_84 == V_2 -> V_9 -> V_85 ) ) {
if ( V_81 ) {
struct V_1 * V_63 = F_22 ( V_2 , V_32 ) ;
if ( V_63 )
F_62 ( V_81 , V_63 ) ;
}
V_81 = V_29 ;
}
}
if ( V_81 ) {
F_62 ( V_81 , V_2 ) ;
F_63 ( & V_82 ) ;
return 1 ;
}
F_63 ( & V_82 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_4 * V_53 = F_2 ( V_2 ) ;
T_1 V_67 = V_53 -> V_67 ;
int V_86 ;
if ( F_65 ( V_67 ) ) {
V_86 = F_66 ( V_2 , sizeof( * V_53 ) , & V_67 ) ;
if ( V_86 < 0 )
return 0 ;
} else
V_86 = sizeof( struct V_4 ) ;
if ( V_67 == V_87 ) {
struct V_88 * V_89 ;
if ( ! F_67 ( V_2 , ( F_68 ( V_2 ) +
V_86 + 1 - V_2 -> V_90 ) ) )
return 0 ;
V_89 = (struct V_88 * ) ( F_68 ( V_2 ) + V_86 ) ;
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
if ( F_69 ( & V_53 -> V_24 ) & V_97 ) {
F_70 ( V_2 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_71 ( struct V_1 * V_2 )
{
return V_10 ( V_2 ) ;
}
int F_72 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_5 ( V_2 ) ;
struct V_4 * V_53 = F_2 ( V_2 ) ;
struct V_98 * V_47 = F_20 ( V_2 ) ;
struct V_48 * V_48 = F_19 ( V_18 -> V_9 ) ;
struct V_20 * V_99 ;
T_2 V_59 ;
if ( V_48 -> V_100 . V_101 -> V_102 == 0 )
goto error;
if ( F_73 ( V_2 ) )
goto V_103;
if ( ! F_74 ( NULL , V_104 , V_2 ) ) {
F_24 ( V_48 , F_16 ( V_18 ) , V_105 ) ;
goto V_103;
}
if ( V_2 -> V_13 != V_106 )
goto V_103;
F_75 ( V_2 ) ;
if ( V_47 -> V_80 ) {
T_1 * V_107 = F_68 ( V_2 ) + V_47 -> V_80 ;
if ( F_60 ( V_2 , ( V_107 [ 2 ] << 8 ) + V_107 [ 3 ] ) )
return 0 ;
}
if ( V_53 -> V_34 <= 1 ) {
V_2 -> V_9 = V_18 -> V_9 ;
F_57 ( V_2 , V_108 , V_109 , 0 ) ;
F_31 ( V_48 ,
F_16 ( V_18 ) , V_110 ) ;
F_25 ( V_2 ) ;
return - V_111 ;
}
if ( V_48 -> V_100 . V_101 -> V_112 &&
F_76 ( & V_113 , V_48 , & V_53 -> V_24 , V_2 -> V_9 , 0 ) ) {
int V_114 = F_64 ( V_2 ) ;
if ( V_114 > 0 )
return F_77 ( V_2 ) ;
else if ( V_114 < 0 ) {
F_24 ( V_48 , F_16 ( V_18 ) ,
V_105 ) ;
goto V_103;
}
}
if ( ! F_78 ( V_2 ) ) {
F_24 ( V_48 , F_16 ( V_18 ) , V_105 ) ;
goto V_103;
}
V_18 = F_5 ( V_2 ) ;
V_99 = F_28 ( V_18 ) ;
if ( V_2 -> V_9 == V_18 -> V_9 && V_99 && V_47 -> V_115 == 0 && ! F_79 ( V_2 ) ) {
struct V_51 * V_116 = NULL ;
struct V_117 * V_118 ;
V_118 = (struct V_117 * ) V_18 ;
if ( ( V_118 -> V_119 & V_120 ) )
V_116 = (struct V_51 * ) & V_99 -> V_121 ;
else
V_116 = & V_53 -> V_24 ;
if ( ! V_118 -> V_122 )
F_80 ( V_118 , 1 ) ;
if ( F_81 ( V_118 -> V_122 , 1 * V_123 ) )
F_82 ( V_2 , V_99 , V_116 ) ;
} else {
int V_124 = F_69 ( & V_53 -> V_31 ) ;
if ( V_124 == V_125 ||
V_124 & ( V_126 | V_127 ) )
goto error;
if ( V_124 & V_97 ) {
F_57 ( V_2 , V_128 ,
V_129 , 0 ) ;
goto error;
}
}
V_59 = F_54 ( V_18 ) ;
if ( V_59 < V_130 )
V_59 = V_130 ;
if ( V_2 -> V_3 > V_59 && ! F_34 ( V_2 ) ) {
V_2 -> V_9 = V_18 -> V_9 ;
F_57 ( V_2 , V_75 , 0 , V_59 ) ;
F_31 ( V_48 ,
F_16 ( V_18 ) , V_131 ) ;
F_31 ( V_48 ,
F_16 ( V_18 ) , V_76 ) ;
F_25 ( V_2 ) ;
return - V_77 ;
}
if ( F_83 ( V_2 , V_18 -> V_9 -> V_132 ) ) {
F_24 ( V_48 , F_16 ( V_18 ) , V_35 ) ;
goto V_103;
}
V_53 = F_2 ( V_2 ) ;
V_53 -> V_34 -- ;
F_31 ( V_48 , F_16 ( V_18 ) , V_133 ) ;
return F_23 ( V_7 , V_134 , V_2 , V_2 -> V_9 , V_18 -> V_9 ,
F_71 ) ;
error:
F_31 ( V_48 , F_16 ( V_18 ) , V_135 ) ;
V_103:
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
T_3 V_86 = sizeof( struct V_4 ) ;
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
V_143 = (struct V_142 * ) ( F_68 ( V_2 ) +
V_86 ) ;
}
return V_86 ;
}
void F_95 ( struct V_154 * V_155 , struct V_117 * V_118 )
{
static T_4 V_156 ;
int V_157 , V_158 ;
if ( V_118 ) {
struct V_159 * V_160 ;
if ( ! V_118 -> V_122 )
F_80 ( V_118 , 1 ) ;
V_160 = V_118 -> V_122 ;
if ( V_160 ) {
V_155 -> V_161 = F_52 ( F_96 ( V_160 , 0 ) ) ;
return;
}
}
do {
V_157 = F_97 ( & V_156 ) ;
V_158 = V_157 + 1 ;
if ( ! V_158 )
V_158 = 1 ;
} while ( F_98 ( & V_156 , V_157 , V_158 ) != V_157 );
V_155 -> V_161 = F_52 ( V_158 ) ;
}
int F_36 ( struct V_1 * V_2 , int (* F_99)( struct V_1 * ) )
{
struct V_1 * V_162 ;
struct V_117 * V_118 = (struct V_117 * ) F_5 ( V_2 ) ;
struct V_49 * V_50 = V_2 -> V_29 ? F_42 ( V_2 -> V_29 ) : NULL ;
struct V_4 * V_163 ;
struct V_154 * V_164 ;
unsigned int V_59 , V_165 , V_166 , V_3 ;
V_65 V_167 = 0 ;
int V_107 , V_86 = 0 , V_11 = 0 ;
T_1 * V_168 , V_67 = 0 ;
struct V_48 * V_48 = F_19 ( F_5 ( V_2 ) -> V_9 ) ;
V_165 = F_92 ( V_2 , & V_168 ) ;
V_67 = * V_168 ;
V_59 = F_33 ( V_2 ) ;
if ( ! V_2 -> V_72 && V_2 -> V_3 > V_59 ) {
V_2 -> V_9 = F_5 ( V_2 ) -> V_9 ;
F_57 ( V_2 , V_75 , 0 , V_59 ) ;
F_24 ( V_48 , F_16 ( F_5 ( V_2 ) ) ,
V_76 ) ;
F_25 ( V_2 ) ;
return - V_77 ;
}
if ( V_50 && V_50 -> V_169 < V_59 ) {
if ( V_50 -> V_169 )
V_59 = V_50 -> V_169 ;
}
V_59 -= V_165 + sizeof( struct V_154 ) ;
if ( F_100 ( V_2 ) ) {
int V_170 = F_101 ( V_2 ) ;
struct V_1 * V_171 ;
if ( V_170 - V_165 > V_59 ||
( ( V_170 - V_165 ) & 7 ) ||
F_102 ( V_2 ) )
goto V_172;
F_103 (skb, frag) {
if ( V_162 -> V_3 > V_59 ||
( ( V_162 -> V_3 & 7 ) && V_162 -> V_83 ) ||
F_44 ( V_162 ) < V_165 )
goto V_173;
if ( F_104 ( V_162 ) )
goto V_173;
F_105 ( V_162 -> V_29 ) ;
if ( V_2 -> V_29 ) {
V_162 -> V_29 = V_2 -> V_29 ;
V_162 -> V_174 = V_175 ;
}
V_2 -> V_176 -= V_162 -> V_176 ;
}
V_11 = 0 ;
V_86 = 0 ;
V_162 = F_106 ( V_2 ) -> V_177 ;
F_107 ( V_2 ) ;
* V_168 = V_178 ;
V_163 = F_108 ( F_68 ( V_2 ) , V_165 , V_32 ) ;
if ( ! V_163 ) {
F_24 ( V_48 , F_16 ( F_5 ( V_2 ) ) ,
V_76 ) ;
return - V_179 ;
}
F_10 ( V_2 , V_165 ) ;
V_164 = (struct V_154 * ) F_109 ( V_2 , sizeof( struct V_154 ) ) ;
F_109 ( V_2 , V_165 ) ;
F_50 ( V_2 ) ;
memcpy ( F_68 ( V_2 ) , V_163 , V_165 ) ;
F_95 ( V_164 , V_118 ) ;
V_164 -> V_67 = V_67 ;
V_164 -> V_180 = 0 ;
V_164 -> V_181 = F_3 ( V_182 ) ;
V_167 = V_164 -> V_161 ;
V_170 = F_101 ( V_2 ) ;
V_2 -> V_183 = V_170 - F_110 ( V_2 ) ;
V_2 -> V_3 = V_170 ;
F_2 ( V_2 ) -> V_6 = F_3 ( V_170 -
sizeof( struct V_4 ) ) ;
F_111 ( & V_118 -> V_18 ) ;
for (; ; ) {
if ( V_162 ) {
V_162 -> V_15 = V_184 ;
F_112 ( V_162 ) ;
V_164 = (struct V_154 * ) F_109 ( V_162 , sizeof( struct V_154 ) ) ;
F_109 ( V_162 , V_165 ) ;
F_50 ( V_162 ) ;
memcpy ( F_68 ( V_162 ) , V_163 ,
V_165 ) ;
V_86 += V_2 -> V_3 - V_165 - sizeof( struct V_154 ) ;
V_164 -> V_67 = V_67 ;
V_164 -> V_180 = 0 ;
V_164 -> V_181 = F_3 ( V_86 ) ;
if ( V_162 -> V_83 != NULL )
V_164 -> V_181 |= F_3 ( V_182 ) ;
V_164 -> V_161 = V_167 ;
F_2 ( V_162 ) -> V_6 =
F_3 ( V_162 -> V_3 -
sizeof( struct V_4 ) ) ;
F_84 ( V_162 , V_2 ) ;
}
V_11 = F_99 ( V_2 ) ;
if( ! V_11 )
F_24 ( V_48 , F_16 ( & V_118 -> V_18 ) ,
V_185 ) ;
if ( V_11 || ! V_162 )
break;
V_2 = V_162 ;
V_162 = V_2 -> V_83 ;
V_2 -> V_83 = NULL ;
}
F_113 ( V_163 ) ;
if ( V_11 == 0 ) {
F_24 ( V_48 , F_16 ( & V_118 -> V_18 ) ,
V_186 ) ;
F_114 ( & V_118 -> V_18 ) ;
return 0 ;
}
while ( V_162 ) {
V_2 = V_162 -> V_83 ;
F_25 ( V_162 ) ;
V_162 = V_2 ;
}
F_24 ( V_48 , F_16 ( & V_118 -> V_18 ) ,
V_76 ) ;
F_114 ( & V_118 -> V_18 ) ;
return V_11 ;
V_173:
F_103 (skb, frag2) {
if ( V_171 == V_162 )
break;
V_171 -> V_29 = NULL ;
V_171 -> V_174 = NULL ;
V_2 -> V_176 += V_171 -> V_176 ;
}
}
V_172:
V_166 = V_2 -> V_3 - V_165 ;
V_107 = V_165 ;
* V_168 = V_178 ;
while( V_166 > 0 ) {
V_3 = V_166 ;
if ( V_3 > V_59 )
V_3 = V_59 ;
if ( V_3 < V_166 ) {
V_3 &= ~ 7 ;
}
if ( ( V_162 = F_115 ( V_3 + V_165 + sizeof( struct V_154 ) + F_116 ( V_118 -> V_18 . V_9 ) , V_32 ) ) == NULL ) {
F_117 ( V_187 L_2 ) ;
F_24 ( V_48 , F_16 ( F_5 ( V_2 ) ) ,
V_76 ) ;
V_11 = - V_179 ;
goto V_188;
}
F_84 ( V_162 , V_2 ) ;
F_118 ( V_162 , F_43 ( V_118 -> V_18 . V_9 ) ) ;
F_59 ( V_162 , V_3 + V_165 + sizeof( struct V_154 ) ) ;
F_50 ( V_162 ) ;
V_164 = (struct V_154 * ) ( F_68 ( V_162 ) + V_165 ) ;
V_162 -> V_189 = ( V_162 -> V_146 + V_165 +
sizeof( struct V_154 ) ) ;
if ( V_2 -> V_29 )
F_46 ( V_162 , V_2 -> V_29 ) ;
F_119 ( V_2 , F_68 ( V_162 ) , V_165 ) ;
V_164 -> V_67 = V_67 ;
V_164 -> V_180 = 0 ;
if ( ! V_167 ) {
F_95 ( V_164 , V_118 ) ;
V_167 = V_164 -> V_161 ;
} else
V_164 -> V_161 = V_167 ;
if ( F_120 ( V_2 , V_107 , F_121 ( V_162 ) , V_3 ) )
F_122 () ;
V_166 -= V_3 ;
V_164 -> V_181 = F_3 ( V_86 ) ;
if ( V_166 > 0 )
V_164 -> V_181 |= F_3 ( V_182 ) ;
F_2 ( V_162 ) -> V_6 = F_3 ( V_162 -> V_3 -
sizeof( struct V_4 ) ) ;
V_107 += V_3 ;
V_86 += V_3 ;
V_11 = F_99 ( V_162 ) ;
if ( V_11 )
goto V_188;
F_24 ( V_48 , F_16 ( F_5 ( V_2 ) ) ,
V_185 ) ;
}
F_24 ( V_48 , F_16 ( F_5 ( V_2 ) ) ,
V_186 ) ;
F_25 ( V_2 ) ;
return V_11 ;
V_188:
F_24 ( V_48 , F_16 ( F_5 ( V_2 ) ) ,
V_76 ) ;
F_25 ( V_2 ) ;
return V_11 ;
}
static inline int F_123 ( const struct V_190 * V_191 ,
const struct V_51 * V_192 ,
const struct V_51 * V_193 )
{
return ( V_191 -> V_194 != 128 || ! F_124 ( V_192 , & V_191 -> V_195 ) ) &&
( V_193 == NULL || ! F_124 ( V_192 , V_193 ) ) ;
}
static struct V_17 * F_125 ( struct V_43 * V_29 ,
struct V_17 * V_18 ,
const struct V_44 * V_45 )
{
struct V_49 * V_50 = F_42 ( V_29 ) ;
struct V_117 * V_118 = (struct V_117 * ) V_18 ;
if ( ! V_18 )
goto V_196;
if ( F_123 ( & V_118 -> V_197 , & V_45 -> V_24 , V_50 -> V_198 ) ||
#ifdef F_126
F_123 ( & V_118 -> V_199 , & V_45 -> V_31 , V_50 -> V_200 ) ||
#endif
( V_45 -> V_201 && V_45 -> V_201 != V_18 -> V_9 -> V_85 ) ) {
F_114 ( V_18 ) ;
V_18 = NULL ;
}
V_196:
return V_18 ;
}
static int F_127 ( struct V_43 * V_29 ,
struct V_17 * * V_18 , struct V_44 * V_45 )
{
struct V_48 * V_48 = F_41 ( V_29 ) ;
#ifdef F_128
struct V_20 * V_99 ;
#endif
int V_11 ;
if ( * V_18 == NULL )
* V_18 = F_129 ( V_48 , V_29 , V_45 ) ;
if ( ( V_11 = ( * V_18 ) -> error ) )
goto V_202;
if ( F_130 ( & V_45 -> V_31 ) ) {
struct V_117 * V_118 = (struct V_117 * ) * V_18 ;
V_11 = F_131 ( V_48 , V_118 , & V_45 -> V_24 ,
V_29 ? F_42 ( V_29 ) -> V_203 : 0 ,
& V_45 -> V_31 ) ;
if ( V_11 )
goto V_202;
}
#ifdef F_128
F_27 () ;
V_99 = F_28 ( * V_18 ) ;
if ( V_99 && ! ( V_99 -> V_204 & V_205 ) ) {
struct V_206 * V_207 ;
struct V_44 V_208 ;
int V_209 ;
F_30 () ;
V_207 = F_132 ( V_48 , & V_45 -> V_31 ,
( * V_18 ) -> V_9 , 1 ) ;
V_209 = ( V_207 && V_207 -> V_27 & V_210 ) ;
if ( V_207 )
F_133 ( V_207 ) ;
if ( V_209 ) {
F_114 ( * V_18 ) ;
memcpy ( & V_208 , V_45 , sizeof( struct V_44 ) ) ;
memset ( & V_208 . V_24 , 0 , sizeof( struct V_51 ) ) ;
* V_18 = F_129 ( V_48 , V_29 , & V_208 ) ;
if ( ( V_11 = ( * V_18 ) -> error ) )
goto V_202;
}
} else {
F_30 () ;
}
#endif
return 0 ;
V_202:
if ( V_11 == - V_211 )
F_31 ( V_48 , NULL , V_38 ) ;
F_114 ( * V_18 ) ;
* V_18 = NULL ;
return V_11 ;
}
int F_134 ( struct V_43 * V_29 , struct V_17 * * V_18 , struct V_44 * V_45 )
{
* V_18 = NULL ;
return F_127 ( V_29 , V_18 , V_45 ) ;
}
struct V_17 * F_135 ( struct V_43 * V_29 , struct V_44 * V_45 ,
const struct V_51 * V_212 ,
bool V_213 )
{
struct V_17 * V_18 = NULL ;
int V_11 ;
V_11 = F_127 ( V_29 , & V_18 , V_45 ) ;
if ( V_11 )
return F_136 ( V_11 ) ;
if ( V_212 )
F_53 ( & V_45 -> V_24 , V_212 ) ;
if ( V_213 )
V_45 -> V_214 |= V_215 ;
return F_137 ( F_41 ( V_29 ) , V_18 , F_138 ( V_45 ) , V_29 , 0 ) ;
}
struct V_17 * F_139 ( struct V_43 * V_29 , struct V_44 * V_45 ,
const struct V_51 * V_212 ,
bool V_213 )
{
struct V_17 * V_18 = F_140 ( V_29 , F_42 ( V_29 ) -> V_216 ) ;
int V_11 ;
V_18 = F_125 ( V_29 , V_18 , V_45 ) ;
V_11 = F_127 ( V_29 , & V_18 , V_45 ) ;
if ( V_11 )
return F_136 ( V_11 ) ;
if ( V_212 )
F_53 ( & V_45 -> V_24 , V_212 ) ;
if ( V_213 )
V_45 -> V_214 |= V_215 ;
return F_137 ( F_41 ( V_29 ) , V_18 , F_138 ( V_45 ) , V_29 , 0 ) ;
}
static inline int F_141 ( struct V_43 * V_29 ,
int F_142 ( void * V_137 , char * V_136 , int V_86 , int V_3 ,
int V_217 , struct V_1 * V_2 ) ,
void * V_137 , int V_218 , int V_219 , int V_220 ,
int V_221 , int V_59 , unsigned int V_27 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 ;
int V_11 ;
if ( ( V_2 = F_143 ( & V_29 -> V_222 ) ) == NULL ) {
V_2 = F_144 ( V_29 ,
V_219 + V_220 + V_221 + 20 ,
( V_27 & V_223 ) , & V_11 ) ;
if ( V_2 == NULL )
return - V_179 ;
F_118 ( V_2 , V_219 ) ;
F_59 ( V_2 , V_220 + V_221 ) ;
F_50 ( V_2 ) ;
V_2 -> V_189 = V_2 -> V_146 + V_220 ;
V_2 -> V_15 = V_224 ;
V_2 -> V_225 = 0 ;
}
V_11 = F_145 ( V_29 , V_2 , F_142 , V_137 ,
( V_218 - V_221 ) ) ;
if ( ! V_11 ) {
struct V_154 V_155 ;
F_106 ( V_2 ) -> V_226 = ( V_59 - V_220 -
sizeof( struct V_154 ) ) & ~ 7 ;
F_106 ( V_2 ) -> V_227 = V_228 ;
F_95 ( & V_155 , V_118 ) ;
F_106 ( V_2 ) -> V_229 = V_155 . V_161 ;
F_146 ( & V_29 -> V_222 , V_2 ) ;
return 0 ;
}
F_25 ( V_2 ) ;
return V_11 ;
}
static inline struct V_142 * F_147 ( struct V_142 * V_230 ,
T_5 V_231 )
{
return V_230 ? F_108 ( V_230 , ( V_230 -> V_232 + 1 ) * 8 , V_231 ) : NULL ;
}
static inline struct V_233 * F_148 ( struct V_233 * V_230 ,
T_5 V_231 )
{
return V_230 ? F_108 ( V_230 , ( V_230 -> V_232 + 1 ) * 8 , V_231 ) : NULL ;
}
int F_149 ( struct V_43 * V_29 , int F_142 ( void * V_137 , char * V_136 ,
int V_86 , int V_3 , int V_217 , struct V_1 * V_2 ) ,
void * V_137 , int V_218 , int V_221 ,
int V_57 , int V_58 , struct V_46 * V_47 , struct V_44 * V_45 ,
struct V_117 * V_118 , unsigned int V_27 , int V_234 )
{
struct V_235 * V_236 = F_150 ( V_29 ) ;
struct V_49 * V_50 = F_42 ( V_29 ) ;
struct V_237 * V_238 ;
struct V_1 * V_2 ;
unsigned int V_239 , V_220 ;
int V_240 ;
int V_219 ;
int V_59 ;
int V_241 ;
int V_11 ;
int V_86 = 0 ;
int V_242 = V_184 ;
T_6 V_243 = 0 ;
if ( V_27 & V_244 )
return 0 ;
V_238 = & V_236 -> V_238 . V_245 ;
if ( F_151 ( & V_29 -> V_222 ) ) {
if ( V_47 ) {
if ( F_12 ( V_50 -> V_238 . V_47 ) )
return - V_39 ;
V_50 -> V_238 . V_47 = F_152 ( V_47 -> V_246 , V_29 -> V_247 ) ;
if ( F_38 ( V_50 -> V_238 . V_47 == NULL ) )
return - V_64 ;
V_50 -> V_238 . V_47 -> V_246 = V_47 -> V_246 ;
V_50 -> V_238 . V_47 -> V_62 = V_47 -> V_62 ;
V_50 -> V_238 . V_47 -> V_61 = V_47 -> V_61 ;
V_50 -> V_238 . V_47 -> V_248 = F_147 ( V_47 -> V_248 ,
V_29 -> V_247 ) ;
if ( V_47 -> V_248 && ! V_50 -> V_238 . V_47 -> V_248 )
return - V_64 ;
V_50 -> V_238 . V_47 -> V_249 = F_147 ( V_47 -> V_249 ,
V_29 -> V_247 ) ;
if ( V_47 -> V_249 && ! V_50 -> V_238 . V_47 -> V_249 )
return - V_64 ;
V_50 -> V_238 . V_47 -> V_250 = F_147 ( V_47 -> V_250 ,
V_29 -> V_247 ) ;
if ( V_47 -> V_250 && ! V_50 -> V_238 . V_47 -> V_250 )
return - V_64 ;
V_50 -> V_238 . V_47 -> V_115 = F_148 ( V_47 -> V_115 ,
V_29 -> V_247 ) ;
if ( V_47 -> V_115 && ! V_50 -> V_238 . V_47 -> V_115 )
return - V_64 ;
}
F_111 ( & V_118 -> V_18 ) ;
V_238 -> V_18 = & V_118 -> V_18 ;
V_236 -> V_238 . V_251 . V_252 . V_253 = * V_45 ;
V_50 -> V_238 . V_34 = V_57 ;
V_50 -> V_238 . V_58 = V_58 ;
V_59 = V_50 -> V_254 == V_255 ?
V_118 -> V_18 . V_9 -> V_59 : F_54 ( V_118 -> V_18 . V_256 ) ;
if ( V_50 -> V_169 < V_59 ) {
if ( V_50 -> V_169 )
V_59 = V_50 -> V_169 ;
}
V_238 -> V_257 = V_59 ;
if ( F_35 ( V_118 -> V_18 . V_256 ) )
V_238 -> V_27 |= V_258 ;
V_238 -> V_218 = 0 ;
V_29 -> V_259 = NULL ;
V_29 -> V_260 = 0 ;
V_240 = V_118 -> V_18 . V_261 + ( V_47 ? V_47 -> V_62 : 0 ) -
V_118 -> V_262 ;
V_218 += V_240 ;
V_221 += V_240 ;
} else {
V_118 = (struct V_117 * ) V_238 -> V_18 ;
V_45 = & V_236 -> V_238 . V_251 . V_252 . V_253 ;
V_47 = V_50 -> V_238 . V_47 ;
V_221 = 0 ;
V_240 = 0 ;
V_59 = V_238 -> V_257 ;
}
V_219 = F_43 ( V_118 -> V_18 . V_9 ) ;
V_220 = sizeof( struct V_4 ) + V_118 -> V_262 +
( V_47 ? V_47 -> V_61 : 0 ) ;
V_239 = ( ( V_59 - V_220 ) & ~ 7 ) + V_220 - sizeof( struct V_154 ) ;
if ( V_59 <= sizeof( struct V_4 ) + V_5 ) {
if ( V_238 -> V_218 + V_218 > sizeof( struct V_4 ) + V_5 - V_220 ) {
F_153 ( V_29 , V_77 , V_45 , V_59 - V_240 ) ;
return - V_77 ;
}
}
if ( V_29 -> V_263 == V_264 ) {
V_11 = F_154 ( V_29 , & V_243 ) ;
if ( V_11 )
goto error;
}
V_238 -> V_218 += V_218 ;
if ( V_218 > V_59 ) {
int V_54 = V_29 -> V_265 ;
if ( V_234 && ( V_54 == V_266 || V_54 == V_267 ) ) {
F_155 ( V_29 , V_45 , V_59 - V_240 ) ;
return - V_77 ;
}
if ( V_54 == V_266 &&
( V_118 -> V_18 . V_9 -> V_268 & V_269 ) ) {
V_11 = F_141 ( V_29 , F_142 , V_137 , V_218 ,
V_219 , V_220 ,
V_221 , V_59 , V_27 , V_118 ) ;
if ( V_11 )
goto error;
return 0 ;
}
}
if ( ( V_2 = F_143 ( & V_29 -> V_222 ) ) == NULL )
goto V_270;
while ( V_218 > 0 ) {
V_241 = ( V_238 -> V_218 <= V_59 && ! ( V_238 -> V_27 & V_258 ) ? V_59 : V_239 ) - V_2 -> V_3 ;
if ( V_241 < V_218 )
V_241 = V_239 - V_2 -> V_3 ;
if ( V_241 <= 0 ) {
char * V_90 ;
unsigned int V_271 ;
unsigned int V_272 ;
unsigned int V_273 ;
unsigned int V_274 ;
struct V_1 * V_275 ;
V_270:
V_275 = V_2 ;
if ( V_275 )
V_273 = V_275 -> V_3 - V_239 ;
else
V_273 = 0 ;
V_271 = V_218 + V_273 ;
if ( V_271 > ( V_238 -> V_218 <= V_59 && ! ( V_238 -> V_27 & V_258 ) ? V_59 : V_239 ) - V_220 )
V_271 = V_239 - V_220 ;
V_272 = V_271 + V_220 ;
if ( ( V_27 & V_276 ) &&
! ( V_118 -> V_18 . V_9 -> V_268 & V_277 ) )
V_274 = V_59 ;
else
V_274 = V_271 + V_220 ;
if ( V_271 == V_218 + V_273 )
V_274 += V_118 -> V_18 . V_278 ;
V_274 += sizeof( struct V_154 ) ;
if ( V_221 ) {
V_2 = F_144 ( V_29 ,
V_274 + V_219 ,
( V_27 & V_223 ) , & V_11 ) ;
} else {
V_2 = NULL ;
if ( F_97 ( & V_29 -> V_279 ) <=
2 * V_29 -> V_280 )
V_2 = F_156 ( V_29 ,
V_274 + V_219 , 1 ,
V_29 -> V_247 ) ;
if ( F_38 ( V_2 == NULL ) )
V_11 = - V_64 ;
else {
V_243 = 0 ;
}
}
if ( V_2 == NULL )
goto error;
V_2 -> V_15 = V_242 ;
V_2 -> V_225 = 0 ;
F_118 ( V_2 , V_219 + sizeof( struct V_154 ) ) ;
if ( V_29 -> V_263 == V_264 )
F_106 ( V_2 ) -> V_243 = V_243 ;
V_90 = F_59 ( V_2 , V_272 ) ;
F_157 ( V_2 , V_240 ) ;
V_90 += V_220 ;
V_2 -> V_189 = ( V_2 -> V_146 +
V_220 ) ;
if ( V_273 ) {
V_2 -> V_225 = F_158 (
V_275 , V_239 ,
V_90 + V_221 , V_273 , 0 ) ;
V_275 -> V_225 = F_159 ( V_275 -> V_225 ,
V_2 -> V_225 ) ;
V_90 += V_273 ;
F_160 ( V_275 , V_239 ) ;
}
V_241 = V_271 - V_221 - V_273 ;
if ( V_241 < 0 ) {
V_11 = - V_39 ;
F_25 ( V_2 ) ;
goto error;
} else if ( V_241 > 0 && F_142 ( V_137 , V_90 + V_221 , V_86 , V_241 , V_273 , V_2 ) < 0 ) {
V_11 = - V_281 ;
F_25 ( V_2 ) ;
goto error;
}
V_86 += V_241 ;
V_218 -= V_271 - V_273 ;
V_221 = 0 ;
V_240 = 0 ;
V_242 = V_184 ;
F_146 ( & V_29 -> V_222 , V_2 ) ;
continue;
}
if ( V_241 > V_218 )
V_241 = V_218 ;
if ( ! ( V_118 -> V_18 . V_9 -> V_268 & V_277 ) ) {
unsigned int V_282 ;
V_282 = V_2 -> V_3 ;
if ( F_142 ( V_137 , F_59 ( V_2 , V_241 ) ,
V_86 , V_241 , V_282 , V_2 ) < 0 ) {
F_161 ( V_2 , V_282 ) ;
V_11 = - V_281 ;
goto error;
}
} else {
int V_283 = F_106 ( V_2 ) -> V_284 ;
T_7 * V_162 = & F_106 ( V_2 ) -> V_285 [ V_283 - 1 ] ;
struct V_286 * V_286 = V_29 -> V_259 ;
int V_282 = V_29 -> V_260 ;
unsigned int V_166 ;
if ( V_286 && ( V_166 = V_287 - V_282 ) > 0 ) {
if ( V_241 >= V_166 )
V_241 = V_166 ;
if ( V_286 != V_162 -> V_286 ) {
if ( V_283 == V_288 ) {
V_11 = - V_77 ;
goto error;
}
F_162 ( V_286 ) ;
F_163 ( V_2 , V_283 , V_286 , V_29 -> V_260 , 0 ) ;
V_162 = & F_106 ( V_2 ) -> V_285 [ V_283 ] ;
}
} else if( V_283 < V_288 ) {
if ( V_241 > V_287 )
V_241 = V_287 ;
V_286 = F_164 ( V_29 -> V_247 , 0 ) ;
if ( V_286 == NULL ) {
V_11 = - V_179 ;
goto error;
}
V_29 -> V_259 = V_286 ;
V_29 -> V_260 = 0 ;
F_163 ( V_2 , V_283 , V_286 , 0 , 0 ) ;
V_162 = & F_106 ( V_2 ) -> V_285 [ V_283 ] ;
} else {
V_11 = - V_77 ;
goto error;
}
if ( F_142 ( V_137 , F_165 ( V_162 -> V_286 ) + V_162 -> V_289 + V_162 -> V_290 , V_86 , V_241 , V_2 -> V_3 , V_2 ) < 0 ) {
V_11 = - V_281 ;
goto error;
}
V_29 -> V_260 += V_241 ;
V_162 -> V_290 += V_241 ;
V_2 -> V_3 += V_241 ;
V_2 -> V_183 += V_241 ;
V_2 -> V_176 += V_241 ;
F_166 ( V_241 , & V_29 -> V_279 ) ;
}
V_86 += V_241 ;
V_218 -= V_241 ;
}
return 0 ;
error:
V_238 -> V_218 -= V_218 ;
F_24 ( F_41 ( V_29 ) , V_118 -> V_291 , V_35 ) ;
return V_11 ;
}
static void F_167 ( struct V_235 * V_236 , struct V_49 * V_50 )
{
if ( V_50 -> V_238 . V_47 ) {
F_113 ( V_50 -> V_238 . V_47 -> V_248 ) ;
F_113 ( V_50 -> V_238 . V_47 -> V_249 ) ;
F_113 ( V_50 -> V_238 . V_47 -> V_250 ) ;
F_113 ( V_50 -> V_238 . V_47 -> V_115 ) ;
F_113 ( V_50 -> V_238 . V_47 ) ;
V_50 -> V_238 . V_47 = NULL ;
}
if ( V_236 -> V_238 . V_245 . V_18 ) {
F_114 ( V_236 -> V_238 . V_245 . V_18 ) ;
V_236 -> V_238 . V_245 . V_18 = NULL ;
V_236 -> V_238 . V_245 . V_27 &= ~ V_258 ;
}
memset ( & V_236 -> V_238 . V_251 , 0 , sizeof( V_236 -> V_238 . V_251 ) ) ;
}
int F_168 ( struct V_43 * V_29 )
{
struct V_1 * V_2 , * V_292 ;
struct V_1 * * V_293 ;
struct V_51 V_294 , * V_212 = & V_294 ;
struct V_235 * V_236 = F_150 ( V_29 ) ;
struct V_49 * V_50 = F_42 ( V_29 ) ;
struct V_48 * V_48 = F_41 ( V_29 ) ;
struct V_4 * V_53 ;
struct V_46 * V_47 = V_50 -> V_238 . V_47 ;
struct V_117 * V_118 = (struct V_117 * ) V_236 -> V_238 . V_245 . V_18 ;
struct V_44 * V_45 = & V_236 -> V_238 . V_251 . V_252 . V_253 ;
unsigned char V_54 = V_45 -> V_55 ;
int V_11 = 0 ;
if ( ( V_2 = F_169 ( & V_29 -> V_222 ) ) == NULL )
goto V_196;
V_293 = & ( F_106 ( V_2 ) -> V_177 ) ;
if ( V_2 -> V_90 < F_68 ( V_2 ) )
F_10 ( V_2 , F_11 ( V_2 ) ) ;
while ( ( V_292 = F_169 ( & V_29 -> V_222 ) ) != NULL ) {
F_10 ( V_292 , F_170 ( V_2 ) ) ;
* V_293 = V_292 ;
V_293 = & ( V_292 -> V_83 ) ;
V_2 -> V_3 += V_292 -> V_3 ;
V_2 -> V_183 += V_292 -> V_3 ;
V_2 -> V_176 += V_292 -> V_176 ;
V_292 -> V_174 = NULL ;
V_292 -> V_29 = NULL ;
}
if ( V_50 -> V_254 < V_295 )
V_2 -> V_72 = 1 ;
F_53 ( V_212 , & V_45 -> V_24 ) ;
F_10 ( V_2 , F_170 ( V_2 ) ) ;
if ( V_47 && V_47 -> V_62 )
F_47 ( V_2 , V_47 , & V_54 ) ;
if ( V_47 && V_47 -> V_61 )
F_48 ( V_2 , V_47 , & V_54 , & V_212 ) ;
F_49 ( V_2 , sizeof( struct V_4 ) ) ;
F_50 ( V_2 ) ;
V_53 = F_2 ( V_2 ) ;
* ( V_65 * ) V_53 = V_45 -> V_66 |
F_52 ( 0x60000000 | ( ( int ) V_50 -> V_238 . V_58 << 20 ) ) ;
V_53 -> V_34 = V_50 -> V_238 . V_34 ;
V_53 -> V_67 = V_54 ;
F_53 ( & V_53 -> V_31 , & V_45 -> V_31 ) ;
F_53 ( & V_53 -> V_24 , V_212 ) ;
V_2 -> V_68 = V_29 -> V_69 ;
V_2 -> V_70 = V_29 -> V_71 ;
F_86 ( V_2 , F_87 ( & V_118 -> V_18 ) ) ;
F_26 ( V_48 , V_118 -> V_291 , V_73 , V_2 -> V_3 ) ;
if ( V_54 == V_87 ) {
struct V_25 * V_26 = F_16 ( F_5 ( V_2 ) ) ;
F_171 ( V_48 , V_26 , F_172 ( V_2 ) -> V_91 ) ;
F_173 ( V_48 , V_26 , V_296 ) ;
}
V_11 = F_6 ( V_2 ) ;
if ( V_11 ) {
if ( V_11 > 0 )
V_11 = F_174 ( V_11 ) ;
if ( V_11 )
goto error;
}
V_196:
F_167 ( V_236 , V_50 ) ;
return V_11 ;
error:
F_24 ( V_48 , V_118 -> V_291 , V_35 ) ;
goto V_196;
}
void F_175 ( struct V_43 * V_29 )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_176 ( & V_29 -> V_222 ) ) != NULL ) {
if ( F_5 ( V_2 ) )
F_24 ( F_41 ( V_29 ) , F_16 ( F_5 ( V_2 ) ) ,
V_35 ) ;
F_25 ( V_2 ) ;
}
F_167 ( F_150 ( V_29 ) , F_42 ( V_29 ) ) ;
}
