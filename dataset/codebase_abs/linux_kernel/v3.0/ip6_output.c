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
V_2 -> V_20 = F_3 ( V_21 ) ;
V_2 -> V_9 = V_9 ;
if ( F_15 ( & F_2 ( V_2 ) -> V_22 ) ) {
struct V_23 * V_24 = F_16 ( F_5 ( V_2 ) ) ;
if ( ! ( V_9 -> V_25 & V_26 ) && F_17 ( V_2 -> V_27 ) &&
( ( F_18 ( F_19 ( V_9 ) , V_2 ) &&
! ( F_20 ( V_2 ) -> V_25 & V_28 ) ) ||
F_21 ( V_9 , & F_2 ( V_2 ) -> V_22 ,
& F_2 ( V_2 ) -> V_29 ) ) ) {
struct V_1 * V_12 = F_22 ( V_2 , V_30 ) ;
if ( V_12 )
F_23 ( V_7 , V_31 ,
V_12 , NULL , V_12 -> V_9 ,
F_8 ) ;
if ( F_2 ( V_2 ) -> V_32 == 0 ) {
F_24 ( F_19 ( V_9 ) , V_24 ,
V_33 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
}
F_26 ( F_19 ( V_9 ) , V_24 , V_34 ,
V_2 -> V_3 ) ;
}
if ( V_18 -> V_35 )
return F_27 ( V_18 -> V_35 , V_2 ) ;
else if ( V_18 -> V_36 )
return V_18 -> V_36 -> V_37 ( V_2 ) ;
F_28 ( F_19 ( V_18 -> V_9 ) ,
F_16 ( V_18 ) , V_38 ) ;
F_25 ( V_2 ) ;
return - V_39 ;
}
static int F_29 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 > F_30 ( V_2 ) && ! F_31 ( V_2 ) ) ||
F_32 ( F_5 ( V_2 ) ) )
return F_33 ( V_2 , F_14 ) ;
else
return F_14 ( V_2 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
struct V_19 * V_9 = F_5 ( V_2 ) -> V_9 ;
struct V_23 * V_24 = F_16 ( F_5 ( V_2 ) ) ;
if ( F_35 ( V_24 -> V_40 . V_41 ) ) {
F_24 ( F_19 ( V_9 ) , V_24 ,
V_33 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
return F_36 ( V_7 , V_31 , V_2 , NULL , V_9 ,
F_29 ,
! ( F_20 ( V_2 ) -> V_25 & V_42 ) ) ;
}
int F_37 ( struct V_43 * V_27 , struct V_1 * V_2 , struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_48 * V_48 = F_38 ( V_27 ) ;
struct V_49 * V_50 = F_39 ( V_27 ) ;
struct V_51 * V_52 = & V_45 -> V_22 ;
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
V_60 += sizeof( struct V_4 ) + F_40 ( V_18 -> V_9 ) ;
if ( F_41 ( V_2 ) < V_60 ) {
struct V_1 * V_63 = F_42 ( V_2 , V_60 ) ;
if ( V_63 == NULL ) {
F_24 ( V_48 , F_16 ( F_5 ( V_2 ) ) ,
V_33 ) ;
F_25 ( V_2 ) ;
return - V_64 ;
}
F_25 ( V_2 ) ;
V_2 = V_63 ;
F_43 ( V_2 , V_27 ) ;
}
if ( V_47 -> V_62 )
F_44 ( V_2 , V_47 , & V_54 ) ;
if ( V_47 -> V_61 )
F_45 ( V_2 , V_47 , & V_54 , & V_52 ) ;
}
F_46 ( V_2 , sizeof( struct V_4 ) ) ;
F_47 ( V_2 ) ;
V_53 = F_2 ( V_2 ) ;
if ( V_50 ) {
V_58 = V_50 -> V_58 ;
V_57 = V_50 -> V_32 ;
}
if ( V_57 < 0 )
V_57 = F_48 ( V_18 ) ;
* ( V_65 * ) V_53 = F_49 ( 0x60000000 | ( V_58 << 20 ) ) | V_45 -> V_66 ;
V_53 -> V_6 = F_3 ( V_56 ) ;
V_53 -> V_67 = V_54 ;
V_53 -> V_32 = V_57 ;
F_50 ( & V_53 -> V_29 , & V_45 -> V_29 ) ;
F_50 ( & V_53 -> V_22 , V_52 ) ;
V_2 -> V_68 = V_27 -> V_69 ;
V_2 -> V_70 = V_27 -> V_71 ;
V_59 = F_51 ( V_18 ) ;
if ( ( V_2 -> V_3 <= V_59 ) || V_2 -> V_72 || F_31 ( V_2 ) ) {
F_26 ( V_48 , F_16 ( F_5 ( V_2 ) ) ,
V_73 , V_2 -> V_3 ) ;
return F_23 ( V_7 , V_8 , V_2 , NULL ,
V_18 -> V_9 , V_10 ) ;
}
if ( F_52 () )
F_53 ( V_74 L_1 ) ;
V_2 -> V_9 = V_18 -> V_9 ;
F_54 ( V_2 , V_75 , 0 , V_59 ) ;
F_24 ( V_48 , F_16 ( F_5 ( V_2 ) ) , V_76 ) ;
F_25 ( V_2 ) ;
return - V_77 ;
}
int F_55 ( struct V_43 * V_27 , struct V_1 * V_2 , struct V_19 * V_9 ,
const struct V_51 * V_29 , const struct V_51 * V_22 ,
int V_54 , int V_3 )
{
struct V_49 * V_50 = F_39 ( V_27 ) ;
struct V_4 * V_53 ;
V_2 -> V_20 = F_3 ( V_21 ) ;
V_2 -> V_9 = V_9 ;
F_47 ( V_2 ) ;
F_56 ( V_2 , sizeof( struct V_4 ) ) ;
V_53 = F_2 ( V_2 ) ;
* ( V_65 * ) V_53 = F_49 ( 0x60000000 ) ;
V_53 -> V_6 = F_3 ( V_3 ) ;
V_53 -> V_67 = V_54 ;
V_53 -> V_32 = V_50 -> V_32 ;
F_50 ( & V_53 -> V_29 , V_29 ) ;
F_50 ( & V_53 -> V_22 , V_22 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , int V_78 )
{
struct V_79 * V_80 ;
struct V_43 * V_81 = NULL ;
F_58 ( & V_82 ) ;
for ( V_80 = V_79 ; V_80 ; V_80 = V_80 -> V_83 ) {
struct V_43 * V_27 = V_80 -> V_27 ;
if ( V_27 && V_80 -> V_78 == V_78 &&
( ! V_27 -> V_84 ||
V_27 -> V_84 == V_2 -> V_9 -> V_85 ) ) {
if ( V_81 ) {
struct V_1 * V_63 = F_22 ( V_2 , V_30 ) ;
if ( V_63 )
F_59 ( V_81 , V_63 ) ;
}
V_81 = V_27 ;
}
}
if ( V_81 ) {
F_59 ( V_81 , V_2 ) ;
F_60 ( & V_82 ) ;
return 1 ;
}
F_60 ( & V_82 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_4 * V_53 = F_2 ( V_2 ) ;
T_1 V_67 = V_53 -> V_67 ;
int V_86 ;
if ( F_62 ( V_67 ) ) {
V_86 = F_63 ( V_2 , sizeof( * V_53 ) , & V_67 ) ;
if ( V_86 < 0 )
return 0 ;
} else
V_86 = sizeof( struct V_4 ) ;
if ( V_67 == V_87 ) {
struct V_88 * V_89 ;
if ( ! F_64 ( V_2 , ( F_65 ( V_2 ) +
V_86 + 1 - V_2 -> V_90 ) ) )
return 0 ;
V_89 = (struct V_88 * ) ( F_65 ( V_2 ) + V_86 ) ;
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
if ( F_66 ( & V_53 -> V_22 ) & V_97 ) {
F_67 ( V_2 ) ;
return - 1 ;
}
return 0 ;
}
static inline int F_68 ( struct V_1 * V_2 )
{
return V_10 ( V_2 ) ;
}
int F_69 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_5 ( V_2 ) ;
struct V_4 * V_53 = F_2 ( V_2 ) ;
struct V_98 * V_47 = F_20 ( V_2 ) ;
struct V_48 * V_48 = F_19 ( V_18 -> V_9 ) ;
T_2 V_59 ;
if ( V_48 -> V_99 . V_100 -> V_101 == 0 )
goto error;
if ( F_70 ( V_2 ) )
goto V_102;
if ( ! F_71 ( NULL , V_103 , V_2 ) ) {
F_24 ( V_48 , F_16 ( V_18 ) , V_104 ) ;
goto V_102;
}
if ( V_2 -> V_13 != V_105 )
goto V_102;
F_72 ( V_2 ) ;
if ( V_47 -> V_80 ) {
T_1 * V_106 = F_65 ( V_2 ) + V_47 -> V_80 ;
if ( F_57 ( V_2 , ( V_106 [ 2 ] << 8 ) + V_106 [ 3 ] ) )
return 0 ;
}
if ( V_53 -> V_32 <= 1 ) {
V_2 -> V_9 = V_18 -> V_9 ;
F_54 ( V_2 , V_107 , V_108 , 0 ) ;
F_28 ( V_48 ,
F_16 ( V_18 ) , V_109 ) ;
F_25 ( V_2 ) ;
return - V_110 ;
}
if ( V_48 -> V_99 . V_100 -> V_111 &&
F_73 ( & V_112 , V_48 , & V_53 -> V_22 , V_2 -> V_9 , 0 ) ) {
int V_113 = F_61 ( V_2 ) ;
if ( V_113 > 0 )
return F_74 ( V_2 ) ;
else if ( V_113 < 0 ) {
F_24 ( V_48 , F_16 ( V_18 ) ,
V_104 ) ;
goto V_102;
}
}
if ( ! F_75 ( V_2 ) ) {
F_24 ( V_48 , F_16 ( V_18 ) , V_104 ) ;
goto V_102;
}
V_18 = F_5 ( V_2 ) ;
if ( V_2 -> V_9 == V_18 -> V_9 && V_18 -> V_36 && V_47 -> V_114 == 0 &&
! F_76 ( V_2 ) ) {
struct V_51 * V_115 = NULL ;
struct V_116 * V_117 ;
struct V_36 * V_118 = V_18 -> V_36 ;
V_117 = (struct V_116 * ) V_18 ;
if ( ( V_117 -> V_119 & V_120 ) )
V_115 = (struct V_51 * ) & V_118 -> V_121 ;
else
V_115 = & V_53 -> V_22 ;
if ( ! V_117 -> V_122 )
F_77 ( V_117 , 1 ) ;
if ( F_78 ( V_117 -> V_122 , 1 * V_123 ) )
F_79 ( V_2 , V_118 , V_115 ) ;
} else {
int V_124 = F_66 ( & V_53 -> V_29 ) ;
if ( V_124 == V_125 ||
V_124 & ( V_126 | V_127 ) )
goto error;
if ( V_124 & V_97 ) {
F_54 ( V_2 , V_128 ,
V_129 , 0 ) ;
goto error;
}
}
V_59 = F_51 ( V_18 ) ;
if ( V_59 < V_130 )
V_59 = V_130 ;
if ( V_2 -> V_3 > V_59 && ! F_31 ( V_2 ) ) {
V_2 -> V_9 = V_18 -> V_9 ;
F_54 ( V_2 , V_75 , 0 , V_59 ) ;
F_28 ( V_48 ,
F_16 ( V_18 ) , V_131 ) ;
F_28 ( V_48 ,
F_16 ( V_18 ) , V_76 ) ;
F_25 ( V_2 ) ;
return - V_77 ;
}
if ( F_80 ( V_2 , V_18 -> V_9 -> V_132 ) ) {
F_24 ( V_48 , F_16 ( V_18 ) , V_33 ) ;
goto V_102;
}
V_53 = F_2 ( V_2 ) ;
V_53 -> V_32 -- ;
F_28 ( V_48 , F_16 ( V_18 ) , V_133 ) ;
return F_23 ( V_7 , V_134 , V_2 , V_2 -> V_9 , V_18 -> V_9 ,
F_68 ) ;
error:
F_28 ( V_48 , F_16 ( V_18 ) , V_135 ) ;
V_102:
F_25 ( V_2 ) ;
return - V_39 ;
}
static void F_81 ( struct V_1 * V_136 , struct V_1 * V_137 )
{
V_136 -> V_13 = V_137 -> V_13 ;
V_136 -> V_68 = V_137 -> V_68 ;
V_136 -> V_20 = V_137 -> V_20 ;
F_82 ( V_136 ) ;
F_83 ( V_136 , F_84 ( F_5 ( V_137 ) ) ) ;
V_136 -> V_9 = V_137 -> V_9 ;
V_136 -> V_70 = V_137 -> V_70 ;
#ifdef F_85
V_136 -> V_138 = V_137 -> V_138 ;
#endif
F_86 ( V_136 , V_137 ) ;
#if F_87 ( V_139 ) || \
F_87 ( V_140 )
V_136 -> V_141 = V_137 -> V_141 ;
#endif
F_88 ( V_136 , V_137 ) ;
}
int F_89 ( struct V_1 * V_2 , T_1 * * V_67 )
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
#if F_87 ( V_151 ) || F_87 ( V_152 )
if ( F_90 ( V_2 , V_86 , V_153 ) >= 0 )
break;
#endif
if ( V_147 )
return V_86 ;
break;
default :
return V_86 ;
}
V_86 += F_91 ( V_143 ) ;
* V_67 = & V_143 -> V_67 ;
V_143 = (struct V_142 * ) ( F_65 ( V_2 ) +
V_86 ) ;
}
return V_86 ;
}
int F_33 ( struct V_1 * V_2 , int (* V_37)( struct V_1 * ) )
{
struct V_1 * V_154 ;
struct V_116 * V_117 = (struct V_116 * ) F_5 ( V_2 ) ;
struct V_49 * V_50 = V_2 -> V_27 ? F_39 ( V_2 -> V_27 ) : NULL ;
struct V_4 * V_155 ;
struct V_156 * V_157 ;
unsigned int V_59 , V_158 , V_159 , V_3 ;
V_65 V_160 = 0 ;
int V_106 , V_86 = 0 , V_11 = 0 ;
T_1 * V_161 , V_67 = 0 ;
struct V_48 * V_48 = F_19 ( F_5 ( V_2 ) -> V_9 ) ;
V_158 = F_89 ( V_2 , & V_161 ) ;
V_67 = * V_161 ;
V_59 = F_30 ( V_2 ) ;
if ( ! V_2 -> V_72 && V_2 -> V_3 > V_59 ) {
V_2 -> V_9 = F_5 ( V_2 ) -> V_9 ;
F_54 ( V_2 , V_75 , 0 , V_59 ) ;
F_24 ( V_48 , F_16 ( F_5 ( V_2 ) ) ,
V_76 ) ;
F_25 ( V_2 ) ;
return - V_77 ;
}
if ( V_50 && V_50 -> V_162 < V_59 ) {
if ( V_50 -> V_162 )
V_59 = V_50 -> V_162 ;
}
V_59 -= V_158 + sizeof( struct V_156 ) ;
if ( F_92 ( V_2 ) ) {
int V_163 = F_93 ( V_2 ) ;
struct V_1 * V_164 ;
if ( V_163 - V_158 > V_59 ||
( ( V_163 - V_158 ) & 7 ) ||
F_94 ( V_2 ) )
goto V_165;
F_95 (skb, frag) {
if ( V_154 -> V_3 > V_59 ||
( ( V_154 -> V_3 & 7 ) && V_154 -> V_83 ) ||
F_41 ( V_154 ) < V_158 )
goto V_166;
if ( F_96 ( V_154 ) )
goto V_166;
F_97 ( V_154 -> V_27 ) ;
if ( V_2 -> V_27 ) {
V_154 -> V_27 = V_2 -> V_27 ;
V_154 -> V_167 = V_168 ;
}
V_2 -> V_169 -= V_154 -> V_169 ;
}
V_11 = 0 ;
V_86 = 0 ;
V_154 = F_98 ( V_2 ) -> V_170 ;
F_99 ( V_2 ) ;
* V_161 = V_171 ;
V_155 = F_100 ( F_65 ( V_2 ) , V_158 , V_30 ) ;
if ( ! V_155 ) {
F_24 ( V_48 , F_16 ( F_5 ( V_2 ) ) ,
V_76 ) ;
return - V_172 ;
}
F_10 ( V_2 , V_158 ) ;
V_157 = (struct V_156 * ) F_101 ( V_2 , sizeof( struct V_156 ) ) ;
F_101 ( V_2 , V_158 ) ;
F_47 ( V_2 ) ;
memcpy ( F_65 ( V_2 ) , V_155 , V_158 ) ;
F_102 ( V_157 ) ;
V_157 -> V_67 = V_67 ;
V_157 -> V_173 = 0 ;
V_157 -> V_174 = F_3 ( V_175 ) ;
V_160 = V_157 -> V_176 ;
V_163 = F_93 ( V_2 ) ;
V_2 -> V_177 = V_163 - F_103 ( V_2 ) ;
V_2 -> V_3 = V_163 ;
F_2 ( V_2 ) -> V_6 = F_3 ( V_163 -
sizeof( struct V_4 ) ) ;
F_104 ( & V_117 -> V_18 ) ;
for (; ; ) {
if ( V_154 ) {
V_154 -> V_15 = V_178 ;
F_105 ( V_154 ) ;
V_157 = (struct V_156 * ) F_101 ( V_154 , sizeof( struct V_156 ) ) ;
F_101 ( V_154 , V_158 ) ;
F_47 ( V_154 ) ;
memcpy ( F_65 ( V_154 ) , V_155 ,
V_158 ) ;
V_86 += V_2 -> V_3 - V_158 - sizeof( struct V_156 ) ;
V_157 -> V_67 = V_67 ;
V_157 -> V_173 = 0 ;
V_157 -> V_174 = F_3 ( V_86 ) ;
if ( V_154 -> V_83 != NULL )
V_157 -> V_174 |= F_3 ( V_175 ) ;
V_157 -> V_176 = V_160 ;
F_2 ( V_154 ) -> V_6 =
F_3 ( V_154 -> V_3 -
sizeof( struct V_4 ) ) ;
F_81 ( V_154 , V_2 ) ;
}
V_11 = V_37 ( V_2 ) ;
if( ! V_11 )
F_24 ( V_48 , F_16 ( & V_117 -> V_18 ) ,
V_179 ) ;
if ( V_11 || ! V_154 )
break;
V_2 = V_154 ;
V_154 = V_2 -> V_83 ;
V_2 -> V_83 = NULL ;
}
F_106 ( V_155 ) ;
if ( V_11 == 0 ) {
F_24 ( V_48 , F_16 ( & V_117 -> V_18 ) ,
V_180 ) ;
F_107 ( & V_117 -> V_18 ) ;
return 0 ;
}
while ( V_154 ) {
V_2 = V_154 -> V_83 ;
F_25 ( V_154 ) ;
V_154 = V_2 ;
}
F_24 ( V_48 , F_16 ( & V_117 -> V_18 ) ,
V_76 ) ;
F_107 ( & V_117 -> V_18 ) ;
return V_11 ;
V_166:
F_95 (skb, frag2) {
if ( V_164 == V_154 )
break;
V_164 -> V_27 = NULL ;
V_164 -> V_167 = NULL ;
V_2 -> V_169 += V_164 -> V_169 ;
}
}
V_165:
V_159 = V_2 -> V_3 - V_158 ;
V_106 = V_158 ;
* V_161 = V_171 ;
while( V_159 > 0 ) {
V_3 = V_159 ;
if ( V_3 > V_59 )
V_3 = V_59 ;
if ( V_3 < V_159 ) {
V_3 &= ~ 7 ;
}
if ( ( V_154 = F_108 ( V_3 + V_158 + sizeof( struct V_156 ) + F_109 ( V_117 -> V_18 . V_9 ) , V_30 ) ) == NULL ) {
F_110 ( V_181 L_2 ) ;
F_24 ( V_48 , F_16 ( F_5 ( V_2 ) ) ,
V_76 ) ;
V_11 = - V_172 ;
goto V_182;
}
F_81 ( V_154 , V_2 ) ;
F_111 ( V_154 , F_40 ( V_117 -> V_18 . V_9 ) ) ;
F_56 ( V_154 , V_3 + V_158 + sizeof( struct V_156 ) ) ;
F_47 ( V_154 ) ;
V_157 = (struct V_156 * ) ( F_65 ( V_154 ) + V_158 ) ;
V_154 -> V_183 = ( V_154 -> V_146 + V_158 +
sizeof( struct V_156 ) ) ;
if ( V_2 -> V_27 )
F_43 ( V_154 , V_2 -> V_27 ) ;
F_112 ( V_2 , F_65 ( V_154 ) , V_158 ) ;
V_157 -> V_67 = V_67 ;
V_157 -> V_173 = 0 ;
if ( ! V_160 ) {
F_102 ( V_157 ) ;
V_160 = V_157 -> V_176 ;
} else
V_157 -> V_176 = V_160 ;
if ( F_113 ( V_2 , V_106 , F_114 ( V_154 ) , V_3 ) )
F_115 () ;
V_159 -= V_3 ;
V_157 -> V_174 = F_3 ( V_86 ) ;
if ( V_159 > 0 )
V_157 -> V_174 |= F_3 ( V_175 ) ;
F_2 ( V_154 ) -> V_6 = F_3 ( V_154 -> V_3 -
sizeof( struct V_4 ) ) ;
V_106 += V_3 ;
V_86 += V_3 ;
V_11 = V_37 ( V_154 ) ;
if ( V_11 )
goto V_182;
F_24 ( V_48 , F_16 ( F_5 ( V_2 ) ) ,
V_179 ) ;
}
F_24 ( V_48 , F_16 ( F_5 ( V_2 ) ) ,
V_180 ) ;
F_25 ( V_2 ) ;
return V_11 ;
V_182:
F_24 ( V_48 , F_16 ( F_5 ( V_2 ) ) ,
V_76 ) ;
F_25 ( V_2 ) ;
return V_11 ;
}
static inline int F_116 ( const struct V_184 * V_185 ,
const struct V_51 * V_186 ,
const struct V_51 * V_187 )
{
return ( V_185 -> V_188 != 128 || ! F_117 ( V_186 , & V_185 -> V_189 ) ) &&
( V_187 == NULL || ! F_117 ( V_186 , V_187 ) ) ;
}
static struct V_17 * F_118 ( struct V_43 * V_27 ,
struct V_17 * V_18 ,
const struct V_44 * V_45 )
{
struct V_49 * V_50 = F_39 ( V_27 ) ;
struct V_116 * V_117 = (struct V_116 * ) V_18 ;
if ( ! V_18 )
goto V_190;
if ( F_116 ( & V_117 -> V_191 , & V_45 -> V_22 , V_50 -> V_192 ) ||
#ifdef F_119
F_116 ( & V_117 -> V_193 , & V_45 -> V_29 , V_50 -> V_194 ) ||
#endif
( V_45 -> V_195 && V_45 -> V_195 != V_18 -> V_9 -> V_85 ) ) {
F_107 ( V_18 ) ;
V_18 = NULL ;
}
V_190:
return V_18 ;
}
static int F_120 ( struct V_43 * V_27 ,
struct V_17 * * V_18 , struct V_44 * V_45 )
{
int V_11 ;
struct V_48 * V_48 = F_38 ( V_27 ) ;
if ( * V_18 == NULL )
* V_18 = F_121 ( V_48 , V_27 , V_45 ) ;
if ( ( V_11 = ( * V_18 ) -> error ) )
goto V_196;
if ( F_122 ( & V_45 -> V_29 ) ) {
struct V_116 * V_117 = (struct V_116 * ) * V_18 ;
V_11 = F_123 ( V_48 , V_117 , & V_45 -> V_22 ,
V_27 ? F_39 ( V_27 ) -> V_197 : 0 ,
& V_45 -> V_29 ) ;
if ( V_11 )
goto V_196;
}
#ifdef F_124
if ( ( * V_18 ) -> V_36 && ! ( ( * V_18 ) -> V_36 -> V_198 & V_199 ) ) {
struct V_200 * V_201 ;
struct V_44 V_202 ;
int V_203 ;
V_201 = F_125 ( V_48 , & V_45 -> V_29 ,
( * V_18 ) -> V_9 , 1 ) ;
V_203 = ( V_201 && V_201 -> V_25 & V_204 ) ;
if ( V_201 )
F_126 ( V_201 ) ;
if ( V_203 ) {
F_107 ( * V_18 ) ;
memcpy ( & V_202 , V_45 , sizeof( struct V_44 ) ) ;
memset ( & V_202 . V_22 , 0 , sizeof( struct V_51 ) ) ;
* V_18 = F_121 ( V_48 , V_27 , & V_202 ) ;
if ( ( V_11 = ( * V_18 ) -> error ) )
goto V_196;
}
}
#endif
return 0 ;
V_196:
if ( V_11 == - V_205 )
F_28 ( V_48 , NULL , V_38 ) ;
F_107 ( * V_18 ) ;
* V_18 = NULL ;
return V_11 ;
}
int F_127 ( struct V_43 * V_27 , struct V_17 * * V_18 , struct V_44 * V_45 )
{
* V_18 = NULL ;
return F_120 ( V_27 , V_18 , V_45 ) ;
}
struct V_17 * F_128 ( struct V_43 * V_27 , struct V_44 * V_45 ,
const struct V_51 * V_206 ,
bool V_207 )
{
struct V_17 * V_18 = NULL ;
int V_11 ;
V_11 = F_120 ( V_27 , & V_18 , V_45 ) ;
if ( V_11 )
return F_129 ( V_11 ) ;
if ( V_206 )
F_50 ( & V_45 -> V_22 , V_206 ) ;
if ( V_207 )
V_45 -> V_208 |= V_209 ;
return F_130 ( F_38 ( V_27 ) , V_18 , F_131 ( V_45 ) , V_27 , 0 ) ;
}
struct V_17 * F_132 ( struct V_43 * V_27 , struct V_44 * V_45 ,
const struct V_51 * V_206 ,
bool V_207 )
{
struct V_17 * V_18 = F_133 ( V_27 , F_39 ( V_27 ) -> V_210 ) ;
int V_11 ;
V_18 = F_118 ( V_27 , V_18 , V_45 ) ;
V_11 = F_120 ( V_27 , & V_18 , V_45 ) ;
if ( V_11 )
return F_129 ( V_11 ) ;
if ( V_206 )
F_50 ( & V_45 -> V_22 , V_206 ) ;
if ( V_207 )
V_45 -> V_208 |= V_209 ;
return F_130 ( F_38 ( V_27 ) , V_18 , F_131 ( V_45 ) , V_27 , 0 ) ;
}
static inline int F_134 ( struct V_43 * V_27 ,
int F_135 ( void * V_137 , char * V_136 , int V_86 , int V_3 ,
int V_211 , struct V_1 * V_2 ) ,
void * V_137 , int V_212 , int V_213 , int V_214 ,
int V_215 , int V_59 , unsigned int V_25 )
{
struct V_1 * V_2 ;
int V_11 ;
if ( ( V_2 = F_136 ( & V_27 -> V_216 ) ) == NULL ) {
V_2 = F_137 ( V_27 ,
V_213 + V_214 + V_215 + 20 ,
( V_25 & V_217 ) , & V_11 ) ;
if ( V_2 == NULL )
return - V_172 ;
F_111 ( V_2 , V_213 ) ;
F_56 ( V_2 , V_214 + V_215 ) ;
F_47 ( V_2 ) ;
V_2 -> V_183 = V_2 -> V_146 + V_214 ;
V_2 -> V_15 = V_218 ;
V_2 -> V_219 = 0 ;
}
V_11 = F_138 ( V_27 , V_2 , F_135 , V_137 ,
( V_212 - V_215 ) ) ;
if ( ! V_11 ) {
struct V_156 V_220 ;
F_98 ( V_2 ) -> V_221 = ( V_59 - V_214 -
sizeof( struct V_156 ) ) & ~ 7 ;
F_98 ( V_2 ) -> V_222 = V_223 ;
F_102 ( & V_220 ) ;
F_98 ( V_2 ) -> V_224 = V_220 . V_176 ;
F_139 ( & V_27 -> V_216 , V_2 ) ;
return 0 ;
}
F_25 ( V_2 ) ;
return V_11 ;
}
static inline struct V_142 * F_140 ( struct V_142 * V_225 ,
T_4 V_226 )
{
return V_225 ? F_100 ( V_225 , ( V_225 -> V_227 + 1 ) * 8 , V_226 ) : NULL ;
}
static inline struct V_228 * F_141 ( struct V_228 * V_225 ,
T_4 V_226 )
{
return V_225 ? F_100 ( V_225 , ( V_225 -> V_227 + 1 ) * 8 , V_226 ) : NULL ;
}
int F_142 ( struct V_43 * V_27 , int F_135 ( void * V_137 , char * V_136 ,
int V_86 , int V_3 , int V_211 , struct V_1 * V_2 ) ,
void * V_137 , int V_212 , int V_215 ,
int V_57 , int V_58 , struct V_46 * V_47 , struct V_44 * V_45 ,
struct V_116 * V_117 , unsigned int V_25 , int V_229 )
{
struct V_230 * V_231 = F_143 ( V_27 ) ;
struct V_49 * V_50 = F_39 ( V_27 ) ;
struct V_232 * V_233 ;
struct V_1 * V_2 ;
unsigned int V_234 , V_214 ;
int V_235 ;
int V_213 ;
int V_59 ;
int V_236 ;
int V_11 ;
int V_86 = 0 ;
int V_237 = V_178 ;
T_5 V_238 = 0 ;
if ( V_25 & V_239 )
return 0 ;
V_233 = & V_231 -> V_233 . V_240 ;
if ( F_144 ( & V_27 -> V_216 ) ) {
if ( V_47 ) {
if ( F_12 ( V_50 -> V_233 . V_47 ) )
return - V_39 ;
V_50 -> V_233 . V_47 = F_145 ( V_47 -> V_241 , V_27 -> V_242 ) ;
if ( F_35 ( V_50 -> V_233 . V_47 == NULL ) )
return - V_64 ;
V_50 -> V_233 . V_47 -> V_241 = V_47 -> V_241 ;
V_50 -> V_233 . V_47 -> V_62 = V_47 -> V_62 ;
V_50 -> V_233 . V_47 -> V_61 = V_47 -> V_61 ;
V_50 -> V_233 . V_47 -> V_243 = F_140 ( V_47 -> V_243 ,
V_27 -> V_242 ) ;
if ( V_47 -> V_243 && ! V_50 -> V_233 . V_47 -> V_243 )
return - V_64 ;
V_50 -> V_233 . V_47 -> V_244 = F_140 ( V_47 -> V_244 ,
V_27 -> V_242 ) ;
if ( V_47 -> V_244 && ! V_50 -> V_233 . V_47 -> V_244 )
return - V_64 ;
V_50 -> V_233 . V_47 -> V_245 = F_140 ( V_47 -> V_245 ,
V_27 -> V_242 ) ;
if ( V_47 -> V_245 && ! V_50 -> V_233 . V_47 -> V_245 )
return - V_64 ;
V_50 -> V_233 . V_47 -> V_114 = F_141 ( V_47 -> V_114 ,
V_27 -> V_242 ) ;
if ( V_47 -> V_114 && ! V_50 -> V_233 . V_47 -> V_114 )
return - V_64 ;
}
F_104 ( & V_117 -> V_18 ) ;
V_233 -> V_18 = & V_117 -> V_18 ;
V_231 -> V_233 . V_246 . V_247 . V_248 = * V_45 ;
V_50 -> V_233 . V_32 = V_57 ;
V_50 -> V_233 . V_58 = V_58 ;
V_59 = V_50 -> V_249 == V_250 ?
V_117 -> V_18 . V_9 -> V_59 : F_51 ( V_117 -> V_18 . V_251 ) ;
if ( V_50 -> V_162 < V_59 ) {
if ( V_50 -> V_162 )
V_59 = V_50 -> V_162 ;
}
V_233 -> V_252 = V_59 ;
if ( F_32 ( V_117 -> V_18 . V_251 ) )
V_233 -> V_25 |= V_253 ;
V_233 -> V_212 = 0 ;
V_27 -> V_254 = NULL ;
V_27 -> V_255 = 0 ;
V_235 = V_117 -> V_18 . V_256 + ( V_47 ? V_47 -> V_62 : 0 ) -
V_117 -> V_257 ;
V_212 += V_235 ;
V_215 += V_235 ;
} else {
V_117 = (struct V_116 * ) V_233 -> V_18 ;
V_45 = & V_231 -> V_233 . V_246 . V_247 . V_248 ;
V_47 = V_50 -> V_233 . V_47 ;
V_215 = 0 ;
V_235 = 0 ;
V_59 = V_233 -> V_252 ;
}
V_213 = F_40 ( V_117 -> V_18 . V_9 ) ;
V_214 = sizeof( struct V_4 ) + V_117 -> V_257 +
( V_47 ? V_47 -> V_61 : 0 ) ;
V_234 = ( ( V_59 - V_214 ) & ~ 7 ) + V_214 - sizeof( struct V_156 ) ;
if ( V_59 <= sizeof( struct V_4 ) + V_5 ) {
if ( V_233 -> V_212 + V_212 > sizeof( struct V_4 ) + V_5 - V_214 ) {
F_146 ( V_27 , V_77 , V_45 , V_59 - V_235 ) ;
return - V_77 ;
}
}
if ( V_27 -> V_258 == V_259 ) {
V_11 = F_147 ( V_27 , & V_238 ) ;
if ( V_11 )
goto error;
}
V_233 -> V_212 += V_212 ;
if ( V_212 > V_59 ) {
int V_54 = V_27 -> V_260 ;
if ( V_229 && ( V_54 == V_261 || V_54 == V_262 ) ) {
F_148 ( V_27 , V_45 , V_59 - V_235 ) ;
return - V_77 ;
}
if ( V_54 == V_261 &&
( V_117 -> V_18 . V_9 -> V_263 & V_264 ) ) {
V_11 = F_134 ( V_27 , F_135 , V_137 , V_212 ,
V_213 , V_214 ,
V_215 , V_59 , V_25 ) ;
if ( V_11 )
goto error;
return 0 ;
}
}
if ( ( V_2 = F_136 ( & V_27 -> V_216 ) ) == NULL )
goto V_265;
while ( V_212 > 0 ) {
V_236 = ( V_233 -> V_212 <= V_59 && ! ( V_233 -> V_25 & V_253 ) ? V_59 : V_234 ) - V_2 -> V_3 ;
if ( V_236 < V_212 )
V_236 = V_234 - V_2 -> V_3 ;
if ( V_236 <= 0 ) {
char * V_90 ;
unsigned int V_266 ;
unsigned int V_267 ;
unsigned int V_268 ;
unsigned int V_269 ;
struct V_1 * V_270 ;
V_265:
V_270 = V_2 ;
if ( V_270 )
V_268 = V_270 -> V_3 - V_234 ;
else
V_268 = 0 ;
V_266 = V_212 + V_268 ;
if ( V_266 > ( V_233 -> V_212 <= V_59 && ! ( V_233 -> V_25 & V_253 ) ? V_59 : V_234 ) - V_214 )
V_266 = V_234 - V_214 ;
V_267 = V_266 + V_214 ;
if ( ( V_25 & V_271 ) &&
! ( V_117 -> V_18 . V_9 -> V_263 & V_272 ) )
V_269 = V_59 ;
else
V_269 = V_266 + V_214 ;
if ( V_266 == V_212 + V_268 )
V_269 += V_117 -> V_18 . V_273 ;
V_269 += sizeof( struct V_156 ) ;
if ( V_215 ) {
V_2 = F_137 ( V_27 ,
V_269 + V_213 ,
( V_25 & V_217 ) , & V_11 ) ;
} else {
V_2 = NULL ;
if ( F_149 ( & V_27 -> V_274 ) <=
2 * V_27 -> V_275 )
V_2 = F_150 ( V_27 ,
V_269 + V_213 , 1 ,
V_27 -> V_242 ) ;
if ( F_35 ( V_2 == NULL ) )
V_11 = - V_64 ;
else {
V_238 = 0 ;
}
}
if ( V_2 == NULL )
goto error;
V_2 -> V_15 = V_237 ;
V_2 -> V_219 = 0 ;
F_111 ( V_2 , V_213 + sizeof( struct V_156 ) ) ;
if ( V_27 -> V_258 == V_259 )
F_98 ( V_2 ) -> V_238 = V_238 ;
V_90 = F_56 ( V_2 , V_267 ) ;
F_151 ( V_2 , V_235 ) ;
V_90 += V_214 ;
V_2 -> V_183 = ( V_2 -> V_146 +
V_214 ) ;
if ( V_268 ) {
V_2 -> V_219 = F_152 (
V_270 , V_234 ,
V_90 + V_215 , V_268 , 0 ) ;
V_270 -> V_219 = F_153 ( V_270 -> V_219 ,
V_2 -> V_219 ) ;
V_90 += V_268 ;
F_154 ( V_270 , V_234 ) ;
}
V_236 = V_266 - V_215 - V_268 ;
if ( V_236 < 0 ) {
V_11 = - V_39 ;
F_25 ( V_2 ) ;
goto error;
} else if ( V_236 > 0 && F_135 ( V_137 , V_90 + V_215 , V_86 , V_236 , V_268 , V_2 ) < 0 ) {
V_11 = - V_276 ;
F_25 ( V_2 ) ;
goto error;
}
V_86 += V_236 ;
V_212 -= V_266 - V_268 ;
V_215 = 0 ;
V_235 = 0 ;
V_237 = V_178 ;
F_139 ( & V_27 -> V_216 , V_2 ) ;
continue;
}
if ( V_236 > V_212 )
V_236 = V_212 ;
if ( ! ( V_117 -> V_18 . V_9 -> V_263 & V_272 ) ) {
unsigned int V_277 ;
V_277 = V_2 -> V_3 ;
if ( F_135 ( V_137 , F_56 ( V_2 , V_236 ) ,
V_86 , V_236 , V_277 , V_2 ) < 0 ) {
F_155 ( V_2 , V_277 ) ;
V_11 = - V_276 ;
goto error;
}
} else {
int V_278 = F_98 ( V_2 ) -> V_279 ;
T_6 * V_154 = & F_98 ( V_2 ) -> V_280 [ V_278 - 1 ] ;
struct V_281 * V_281 = V_27 -> V_254 ;
int V_277 = V_27 -> V_255 ;
unsigned int V_159 ;
if ( V_281 && ( V_159 = V_282 - V_277 ) > 0 ) {
if ( V_236 >= V_159 )
V_236 = V_159 ;
if ( V_281 != V_154 -> V_281 ) {
if ( V_278 == V_283 ) {
V_11 = - V_77 ;
goto error;
}
F_156 ( V_281 ) ;
F_157 ( V_2 , V_278 , V_281 , V_27 -> V_255 , 0 ) ;
V_154 = & F_98 ( V_2 ) -> V_280 [ V_278 ] ;
}
} else if( V_278 < V_283 ) {
if ( V_236 > V_282 )
V_236 = V_282 ;
V_281 = F_158 ( V_27 -> V_242 , 0 ) ;
if ( V_281 == NULL ) {
V_11 = - V_172 ;
goto error;
}
V_27 -> V_254 = V_281 ;
V_27 -> V_255 = 0 ;
F_157 ( V_2 , V_278 , V_281 , 0 , 0 ) ;
V_154 = & F_98 ( V_2 ) -> V_280 [ V_278 ] ;
} else {
V_11 = - V_77 ;
goto error;
}
if ( F_135 ( V_137 , F_159 ( V_154 -> V_281 ) + V_154 -> V_284 + V_154 -> V_285 , V_86 , V_236 , V_2 -> V_3 , V_2 ) < 0 ) {
V_11 = - V_276 ;
goto error;
}
V_27 -> V_255 += V_236 ;
V_154 -> V_285 += V_236 ;
V_2 -> V_3 += V_236 ;
V_2 -> V_177 += V_236 ;
V_2 -> V_169 += V_236 ;
F_160 ( V_236 , & V_27 -> V_274 ) ;
}
V_86 += V_236 ;
V_212 -= V_236 ;
}
return 0 ;
error:
V_233 -> V_212 -= V_212 ;
F_24 ( F_38 ( V_27 ) , V_117 -> V_286 , V_33 ) ;
return V_11 ;
}
static void F_161 ( struct V_230 * V_231 , struct V_49 * V_50 )
{
if ( V_50 -> V_233 . V_47 ) {
F_106 ( V_50 -> V_233 . V_47 -> V_243 ) ;
F_106 ( V_50 -> V_233 . V_47 -> V_244 ) ;
F_106 ( V_50 -> V_233 . V_47 -> V_245 ) ;
F_106 ( V_50 -> V_233 . V_47 -> V_114 ) ;
F_106 ( V_50 -> V_233 . V_47 ) ;
V_50 -> V_233 . V_47 = NULL ;
}
if ( V_231 -> V_233 . V_240 . V_18 ) {
F_107 ( V_231 -> V_233 . V_240 . V_18 ) ;
V_231 -> V_233 . V_240 . V_18 = NULL ;
V_231 -> V_233 . V_240 . V_25 &= ~ V_253 ;
}
memset ( & V_231 -> V_233 . V_246 , 0 , sizeof( V_231 -> V_233 . V_246 ) ) ;
}
int F_162 ( struct V_43 * V_27 )
{
struct V_1 * V_2 , * V_287 ;
struct V_1 * * V_288 ;
struct V_51 V_289 , * V_206 = & V_289 ;
struct V_230 * V_231 = F_143 ( V_27 ) ;
struct V_49 * V_50 = F_39 ( V_27 ) ;
struct V_48 * V_48 = F_38 ( V_27 ) ;
struct V_4 * V_53 ;
struct V_46 * V_47 = V_50 -> V_233 . V_47 ;
struct V_116 * V_117 = (struct V_116 * ) V_231 -> V_233 . V_240 . V_18 ;
struct V_44 * V_45 = & V_231 -> V_233 . V_246 . V_247 . V_248 ;
unsigned char V_54 = V_45 -> V_55 ;
int V_11 = 0 ;
if ( ( V_2 = F_163 ( & V_27 -> V_216 ) ) == NULL )
goto V_190;
V_288 = & ( F_98 ( V_2 ) -> V_170 ) ;
if ( V_2 -> V_90 < F_65 ( V_2 ) )
F_10 ( V_2 , F_11 ( V_2 ) ) ;
while ( ( V_287 = F_163 ( & V_27 -> V_216 ) ) != NULL ) {
F_10 ( V_287 , F_164 ( V_2 ) ) ;
* V_288 = V_287 ;
V_288 = & ( V_287 -> V_83 ) ;
V_2 -> V_3 += V_287 -> V_3 ;
V_2 -> V_177 += V_287 -> V_3 ;
V_2 -> V_169 += V_287 -> V_169 ;
V_287 -> V_167 = NULL ;
V_287 -> V_27 = NULL ;
}
if ( V_50 -> V_249 < V_290 )
V_2 -> V_72 = 1 ;
F_50 ( V_206 , & V_45 -> V_22 ) ;
F_10 ( V_2 , F_164 ( V_2 ) ) ;
if ( V_47 && V_47 -> V_62 )
F_44 ( V_2 , V_47 , & V_54 ) ;
if ( V_47 && V_47 -> V_61 )
F_45 ( V_2 , V_47 , & V_54 , & V_206 ) ;
F_46 ( V_2 , sizeof( struct V_4 ) ) ;
F_47 ( V_2 ) ;
V_53 = F_2 ( V_2 ) ;
* ( V_65 * ) V_53 = V_45 -> V_66 |
F_49 ( 0x60000000 | ( ( int ) V_50 -> V_233 . V_58 << 20 ) ) ;
V_53 -> V_32 = V_50 -> V_233 . V_32 ;
V_53 -> V_67 = V_54 ;
F_50 ( & V_53 -> V_29 , & V_45 -> V_29 ) ;
F_50 ( & V_53 -> V_22 , V_206 ) ;
V_2 -> V_68 = V_27 -> V_69 ;
V_2 -> V_70 = V_27 -> V_71 ;
F_83 ( V_2 , F_84 ( & V_117 -> V_18 ) ) ;
F_26 ( V_48 , V_117 -> V_286 , V_73 , V_2 -> V_3 ) ;
if ( V_54 == V_87 ) {
struct V_23 * V_24 = F_16 ( F_5 ( V_2 ) ) ;
F_165 ( V_48 , V_24 , F_166 ( V_2 ) -> V_91 ) ;
F_167 ( V_48 , V_24 , V_291 ) ;
}
V_11 = F_6 ( V_2 ) ;
if ( V_11 ) {
if ( V_11 > 0 )
V_11 = F_168 ( V_11 ) ;
if ( V_11 )
goto error;
}
V_190:
F_161 ( V_231 , V_50 ) ;
return V_11 ;
error:
F_24 ( V_48 , V_117 -> V_286 , V_33 ) ;
goto V_190;
}
void F_169 ( struct V_43 * V_27 )
{
struct V_1 * V_2 ;
while ( ( V_2 = F_170 ( & V_27 -> V_216 ) ) != NULL ) {
if ( F_5 ( V_2 ) )
F_24 ( F_38 ( V_27 ) , F_16 ( F_5 ( V_2 ) ) ,
V_33 ) ;
F_25 ( V_2 ) ;
}
F_161 ( F_143 ( V_27 ) , F_39 ( V_27 ) ) ;
}
