static int F_1 ( T_1 * V_1 )
{
switch ( F_2 ( * V_1 ) ) {
case V_2 :
switch ( F_3 ( * V_1 ) ) {
case V_3 :
case V_4 :
return 1 ;
}
break;
case V_5 :
switch ( F_4 ( * V_1 ) ) {
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
return 1 ;
}
break;
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
return 1 ;
case V_25 :
case V_26 :
case V_27 :
case V_28 :
if ( F_5 ( * V_1 ) == V_29 )
return 1 ;
break;
}
return 0 ;
}
static inline int F_6 ( struct V_30 * V_31 )
{
if ( V_32 )
return V_31 -> V_33 & V_34 ;
#ifdef F_7
return ! F_8 ( V_35 ) ;
#else
return 0 ;
#endif
}
static int F_9 ( struct V_30 * V_31 , struct V_36 * V_37 ,
void * T_2 * V_38 )
{
T_1 V_39 ;
unsigned long V_40 , V_41 ;
unsigned int V_42 ;
if ( ! F_10 ( V_43 , V_31 -> V_44 , sizeof( T_1 ) ) ) {
F_11 ( V_45 ) ;
* V_38 = ( T_1 T_2 * ) V_31 -> V_44 ;
return V_46 ;
}
if ( F_12 ( V_39 , ( T_1 T_2 * ) V_31 -> V_44 ) ) {
F_11 ( V_45 ) ;
* V_38 = ( T_1 T_2 * ) V_31 -> V_44 ;
return V_47 ;
}
if ( ( V_31 -> V_48 & V_49 ) && ! F_1 ( & V_39 ) )
V_31 -> V_48 &= ~ V_49 ;
if ( V_31 -> V_48 & V_49 ) {
V_40 = V_31 -> V_44 + 4 ;
if ( F_13 ( V_31 ) < 0 ) {
#ifdef F_14
F_15 ( L_1 ,
( void * ) ( V_31 -> V_44 ) ) ;
#endif
return V_50 ;
}
if ( ! F_10 ( V_43 , V_40 , sizeof( T_1 ) ) ) {
F_11 ( V_45 ) ;
* V_38 = ( T_1 T_2 * ) V_40 ;
return V_46 ;
}
if ( F_12 ( V_39 , ( T_1 T_2 * ) V_40 ) ) {
F_11 ( V_45 ) ;
* V_38 = ( T_1 T_2 * ) V_40 ;
return V_47 ;
}
V_41 = V_31 -> V_44 ;
V_31 -> V_44 = V_40 - 4 ;
} else {
V_40 = V_31 -> V_44 ;
V_41 = V_31 -> V_44 + 4 ;
}
V_51:
F_16 ( V_52 , 1 , V_31 , 0 ) ;
F_11 ( V_53 ) ;
switch ( F_2 ( V_39 ) ) {
case V_54 : {
T_3 T_2 * V_55 = ( T_3 T_2 * ) ( V_31 -> V_56 [ F_5 ( V_39 ) ] +
F_17 ( V_39 ) ) ;
T_3 V_57 ;
F_11 ( V_58 ) ;
if ( ! F_10 ( V_43 , V_55 , sizeof( T_3 ) ) ) {
F_11 ( V_45 ) ;
* V_38 = V_55 ;
return V_46 ;
}
if ( F_12 ( V_57 , V_55 ) ) {
F_11 ( V_45 ) ;
* V_38 = V_55 ;
return V_47 ;
}
F_18 ( V_57 , F_4 ( V_39 ) ) ;
break;
}
case V_59 : {
T_3 T_2 * V_55 = ( T_3 T_2 * ) ( V_31 -> V_56 [ F_5 ( V_39 ) ] +
F_17 ( V_39 ) ) ;
T_3 V_57 ;
F_11 ( V_60 ) ;
F_19 ( V_57 , F_4 ( V_39 ) ) ;
if ( ! F_10 ( V_61 , V_55 , sizeof( T_3 ) ) ) {
F_11 ( V_45 ) ;
* V_38 = V_55 ;
return V_46 ;
}
if ( F_20 ( V_57 , V_55 ) ) {
F_11 ( V_45 ) ;
* V_38 = V_55 ;
return V_47 ;
}
break;
}
case V_62 : {
T_4 T_2 * V_55 = ( T_4 T_2 * ) ( V_31 -> V_56 [ F_5 ( V_39 ) ] +
F_17 ( V_39 ) ) ;
T_4 V_57 ;
F_11 ( V_58 ) ;
if ( ! F_10 ( V_43 , V_55 , sizeof( T_4 ) ) ) {
F_11 ( V_45 ) ;
* V_38 = V_55 ;
return V_46 ;
}
if ( F_12 ( V_57 , V_55 ) ) {
F_11 ( V_45 ) ;
* V_38 = V_55 ;
return V_47 ;
}
F_21 ( V_57 , F_4 ( V_39 ) ) ;
break;
}
case V_63 : {
T_4 T_2 * V_55 = ( T_4 T_2 * ) ( V_31 -> V_56 [ F_5 ( V_39 ) ] +
F_17 ( V_39 ) ) ;
T_4 V_57 ;
F_11 ( V_60 ) ;
F_22 ( V_57 , F_4 ( V_39 ) ) ;
if ( ! F_10 ( V_61 , V_55 , sizeof( T_4 ) ) ) {
F_11 ( V_45 ) ;
* V_38 = V_55 ;
return V_46 ;
}
if ( F_20 ( V_57 , V_55 ) ) {
F_11 ( V_45 ) ;
* V_38 = V_55 ;
return V_47 ;
}
break;
}
case V_26 :
switch ( F_5 ( V_39 ) ) {
#if F_23 ( V_64 )
case V_65 :
if ( F_4 ( V_39 ) != 0 ) {
F_19 ( V_31 -> V_56 [ F_4 ( V_39 ) ] ,
F_24 ( V_39 ) ) ;
}
break;
case V_66 :
F_18 ( V_31 -> V_56 [ F_4 ( V_39 ) ] , F_24 ( V_39 ) ) ;
break;
#endif
case V_67 :
if ( F_4 ( V_39 ) != 0 ) {
F_22 ( V_31 -> V_56 [ F_4 ( V_39 ) ] ,
F_24 ( V_39 ) ) ;
}
break;
case V_68 :
F_21 ( V_31 -> V_56 [ F_4 ( V_39 ) ] , F_24 ( V_39 ) ) ;
break;
case V_69 : {
T_4 V_70 ;
if ( F_24 ( V_39 ) == V_71 ) {
V_70 = V_37 -> V_72 ;
V_70 = ( V_70 & ~ V_73 ) |
V_74 [ F_25 ( V_70 ) ] ;
#ifdef F_26
F_15 ( L_2 ,
( void * ) ( V_31 -> V_44 ) ,
F_4 ( V_39 ) , V_70 ) ;
#endif
}
else if ( F_24 ( V_39 ) == V_75 )
V_70 = 0 ;
else
V_70 = 0 ;
if ( F_4 ( V_39 ) )
V_31 -> V_56 [ F_4 ( V_39 ) ] = V_70 ;
break;
}
case V_76 : {
T_4 V_70 ;
if ( F_4 ( V_39 ) == 0 )
V_70 = 0 ;
else
V_70 = V_31 -> V_56 [ F_4 ( V_39 ) ] ;
if ( F_24 ( V_39 ) == V_71 ) {
#ifdef F_26
F_15 ( L_3 ,
( void * ) ( V_31 -> V_44 ) ,
F_4 ( V_39 ) , V_70 ) ;
#endif
V_37 -> V_72 = ( V_70 &
~ ( V_77 | V_73 ) ) |
V_78 [ F_25 ( V_70 ) ] ;
}
if ( ( V_37 -> V_72 >> 5 ) & V_37 -> V_72 & V_79 ) {
return V_80 ;
}
break;
}
case V_29 : {
int V_81 = 0 ;
if ( V_31 -> V_48 & V_49 )
return V_50 ;
#if V_82 >= 4
V_42 = V_37 -> V_72 & V_83 [ F_4 ( V_39 ) >> 2 ] ;
#else
V_42 = V_37 -> V_72 & V_84 ;
#endif
switch ( F_4 ( V_39 ) & 3 ) {
case V_85 :
V_81 = 1 ;
case V_86 :
V_42 = ! V_42 ;
break;
case V_87 :
V_81 = 1 ;
case V_88 :
break;
default:
return V_50 ;
}
V_31 -> V_48 |= V_49 ;
if ( V_42 ) {
V_31 -> V_44 += 4 ;
V_41 = ( V_31 -> V_44 +
( F_17 ( V_39 ) << 2 ) ) ;
if ( ! F_10 ( V_43 , V_31 -> V_44 ,
sizeof( T_1 ) ) ) {
F_11 ( V_45 ) ;
* V_38 = ( T_1 T_2 * ) V_31 -> V_44 ;
return V_46 ;
}
if ( F_12 ( V_39 ,
( T_1 T_2 * ) V_31 -> V_44 ) ) {
F_11 ( V_45 ) ;
* V_38 = ( T_1 T_2 * ) V_31 -> V_44 ;
return V_47 ;
}
switch ( F_2 ( V_39 ) ) {
case V_62 :
case V_63 :
#if ( V_82 >= 2 || F_23 ( V_64 ) )
case V_54 :
case V_59 :
#endif
case V_26 :
#if V_82 >= 4 && V_82 != 32
case V_28 :
#endif
goto V_51;
#if V_82 >= 4
case V_2 :
if ( F_3 ( V_39 ) == V_89 )
goto V_51;
break;
#endif
}
return F_27 ( V_31 , V_39 , V_41 ) ;
}
else {
if ( V_81 ) {
V_31 -> V_44 += 4 ;
V_41 += 4 ;
}
}
break;
}
default:
if ( ! ( F_5 ( V_39 ) & 0x10 ) )
return V_50 ;
{
int V_90 ;
if ( ( V_90 = F_28 ( V_31 , V_37 , V_39 ) ) )
return V_90 ;
}
}
break;
#if V_82 >= 4 && V_82 != 32
case V_28 : {
int V_90 = F_29 ( V_31 , V_37 , V_39 , V_38 ) ;
if ( V_90 )
return V_90 ;
break;
}
#endif
#if V_82 >= 4
case V_2 :
if ( F_3 ( V_39 ) != V_89 )
return V_50 ;
V_42 = V_83 [ F_4 ( V_39 ) >> 2 ] ;
if ( ( ( V_37 -> V_72 & V_42 ) != 0 ) == ( ( F_4 ( V_39 ) & 1 ) != 0 ) )
V_31 -> V_56 [ F_24 ( V_39 ) ] =
V_31 -> V_56 [ F_5 ( V_39 ) ] ;
break;
#endif
default:
return V_50 ;
}
V_31 -> V_44 = V_41 ;
V_31 -> V_48 &= ~ V_49 ;
return 0 ;
}
static T_5 F_30 ( T_5 V_91 )
{
return F_31 ( F_32 ( 0 ) , V_91 ) ;
}
static T_5 F_33 ( T_5 V_91 )
{
return F_31 ( F_32 ( 0 ) , F_34 ( V_91 ) ) ;
}
static T_6 F_35 ( T_6 V_92 )
{
return F_36 ( F_37 ( 0 ) , V_92 ) ;
}
static T_6 F_38 ( T_6 V_92 )
{
return F_36 ( F_37 ( 0 ) , F_39 ( V_92 ) ) ;
}
static int F_29 ( struct V_30 * V_31 , struct V_36 * V_37 ,
T_1 V_39 , void * T_2 * V_38 )
{
unsigned V_93 = 0 ;
F_11 ( V_94 ) ;
switch ( F_40 ( V_39 ) ) {
case V_95 : {
T_6 (* F_41) ( T_6 , T_6 , T_6 );
T_6 V_96 , V_97 , V_98 , V_99 ;
T_4 T_2 * V_55 ;
T_4 V_57 ;
switch ( F_3 ( V_39 ) ) {
case V_100 :
V_55 = ( void T_2 * ) ( V_31 -> V_56 [ F_42 ( V_39 ) ] +
V_31 -> V_56 [ F_43 ( V_39 ) ] ) ;
F_11 ( V_58 ) ;
if ( ! F_10 ( V_43 , V_55 , sizeof( T_4 ) ) ) {
F_11 ( V_45 ) ;
* V_38 = V_55 ;
return V_46 ;
}
if ( F_12 ( V_57 , V_55 ) ) {
F_11 ( V_45 ) ;
* V_38 = V_55 ;
return V_47 ;
}
F_21 ( V_57 , F_44 ( V_39 ) ) ;
break;
case V_101 :
V_55 = ( void T_2 * ) ( V_31 -> V_56 [ F_42 ( V_39 ) ] +
V_31 -> V_56 [ F_43 ( V_39 ) ] ) ;
F_11 ( V_60 ) ;
F_22 ( V_57 , F_45 ( V_39 ) ) ;
if ( ! F_10 ( V_61 , V_55 , sizeof( T_4 ) ) ) {
F_11 ( V_45 ) ;
* V_38 = V_55 ;
return V_46 ;
}
if ( F_46 ( V_57 , V_55 ) ) {
F_11 ( V_45 ) ;
* V_38 = V_55 ;
return V_47 ;
}
break;
case V_102 :
F_41 = V_103 ;
goto V_104;
case V_105 :
F_41 = V_106 ;
goto V_104;
case V_107 :
F_41 = V_108 ;
goto V_104;
case V_109 :
F_41 = V_110 ;
goto V_104;
V_104:
F_47 ( V_97 , F_42 ( V_39 ) ) ;
F_47 ( V_98 , F_45 ( V_39 ) ) ;
F_47 ( V_99 , F_43 ( V_39 ) ) ;
V_96 = (* F_41) ( V_97 , V_98 , V_99 ) ;
F_48 ( V_96 , F_44 ( V_39 ) ) ;
V_111:
if ( F_49 ( V_112 ) )
V_93 |= V_113 | V_114 ;
if ( F_49 ( V_115 ) )
V_93 |= V_116 | V_117 ;
if ( F_49 ( V_118 ) )
V_93 |= V_119 | V_120 ;
if ( F_49 ( V_121 ) )
V_93 |= V_122 | V_123 ;
V_37 -> V_72 = ( V_37 -> V_72 & ~ V_124 ) | V_93 ;
if ( ( V_37 -> V_72 >> 5 ) & V_37 -> V_72 & V_79 ) {
return V_80 ;
}
break;
default:
return V_50 ;
}
break;
}
case V_125 : {
T_5 (* F_41) ( T_5 , T_5 , T_5 );
T_5 V_96 , V_97 , V_98 , V_99 ;
T_3 T_2 * V_55 ;
T_3 V_57 ;
switch ( F_3 ( V_39 ) ) {
case V_126 :
V_55 = ( void T_2 * ) ( V_31 -> V_56 [ F_42 ( V_39 ) ] +
V_31 -> V_56 [ F_43 ( V_39 ) ] ) ;
F_11 ( V_58 ) ;
if ( ! F_10 ( V_43 , V_55 , sizeof( T_3 ) ) ) {
F_11 ( V_45 ) ;
* V_38 = V_55 ;
return V_46 ;
}
if ( F_12 ( V_57 , V_55 ) ) {
F_11 ( V_45 ) ;
* V_38 = V_55 ;
return V_47 ;
}
F_18 ( V_57 , F_44 ( V_39 ) ) ;
break;
case V_127 :
V_55 = ( void T_2 * ) ( V_31 -> V_56 [ F_42 ( V_39 ) ] +
V_31 -> V_56 [ F_43 ( V_39 ) ] ) ;
F_11 ( V_60 ) ;
F_19 ( V_57 , F_45 ( V_39 ) ) ;
if ( ! F_10 ( V_61 , V_55 , sizeof( T_3 ) ) ) {
F_11 ( V_45 ) ;
* V_38 = V_55 ;
return V_46 ;
}
if ( F_20 ( V_57 , V_55 ) ) {
F_11 ( V_45 ) ;
* V_38 = V_55 ;
return V_47 ;
}
break;
case V_128 :
F_41 = V_129 ;
goto V_130;
case V_131 :
F_41 = V_132 ;
goto V_130;
case V_133 :
F_41 = V_134 ;
goto V_130;
case V_135 :
F_41 = V_136 ;
goto V_130;
V_130:
F_50 ( V_97 , F_42 ( V_39 ) ) ;
F_50 ( V_98 , F_45 ( V_39 ) ) ;
F_50 ( V_99 , F_43 ( V_39 ) ) ;
V_96 = (* F_41) ( V_97 , V_98 , V_99 ) ;
F_51 ( V_96 , F_44 ( V_39 ) ) ;
goto V_111;
default:
return V_50 ;
}
break;
}
case 0x7 :
if ( F_3 ( V_39 ) != V_137 ) {
return V_50 ;
}
break;
default:
return V_50 ;
}
return 0 ;
}
static int F_28 ( struct V_30 * V_31 , struct V_36 * V_37 ,
T_1 V_39 )
{
int V_138 ;
unsigned V_93 = 0 ;
unsigned V_42 ;
union {
T_5 V_91 ;
T_6 V_92 ;
int V_139 ;
#ifdef V_64
T_7 V_140 ;
#endif
} V_141 ;
F_11 ( V_142 ) ;
switch ( V_138 = ( F_52 ( V_39 ) & 0xf ) ) {
case V_95 : {
union {
T_6 (* F_53) ( T_6 , T_6 );
T_6 (* F_54) ( T_6 );
} F_41 ;
switch ( F_3 ( V_39 ) ) {
case V_143 :
F_41 . F_53 = V_144 ;
goto V_145;
case V_146 :
F_41 . F_53 = V_147 ;
goto V_145;
case V_148 :
F_41 . F_53 = V_149 ;
goto V_145;
case V_150 :
F_41 . F_53 = F_36 ;
goto V_145;
#if V_82 >= 2 || F_23 ( V_64 )
case V_151 :
F_41 . F_54 = F_39 ;
goto V_152;
#endif
#if V_82 >= 4 && V_82 != 32
case V_153 :
F_41 . F_54 = F_38 ;
goto V_152;
case V_154 :
F_41 . F_54 = F_35 ;
goto V_152;
#endif
#if V_82 >= 4
case V_155 :
V_42 = V_83 [ F_43 ( V_39 ) >> 2 ] ;
if ( ( ( V_37 -> V_72 & V_42 ) != 0 ) !=
( ( F_43 ( V_39 ) & 1 ) != 0 ) )
return 0 ;
F_47 ( V_141 . V_92 , F_45 ( V_39 ) ) ;
break;
case V_156 :
if ( V_31 -> V_56 [ F_43 ( V_39 ) ] != 0 )
return 0 ;
F_47 ( V_141 . V_92 , F_45 ( V_39 ) ) ;
break;
case V_157 :
if ( V_31 -> V_56 [ F_43 ( V_39 ) ] == 0 )
return 0 ;
F_47 ( V_141 . V_92 , F_45 ( V_39 ) ) ;
break;
#endif
case V_158 :
F_41 . F_54 = V_159 ;
goto V_152;
case V_160 :
F_41 . F_54 = V_161 ;
goto V_152;
case V_162 :
F_47 ( V_141 . V_92 , F_45 ( V_39 ) ) ;
goto V_111;
V_145:
{
T_6 V_98 , V_99 ;
F_47 ( V_98 , F_45 ( V_39 ) ) ;
F_47 ( V_99 , F_43 ( V_39 ) ) ;
V_141 . V_92 = (* F_41 . F_53 ) ( V_98 , V_99 ) ;
goto V_111;
}
V_152:
{
T_6 V_98 ;
F_47 ( V_98 , F_45 ( V_39 ) ) ;
V_141 . V_92 = (* F_41 . F_54 ) ( V_98 ) ;
goto V_111;
}
V_111:
if ( F_49 ( V_112 ) )
V_93 |= V_113 | V_114 ;
if ( F_49 ( V_115 ) )
V_93 |= V_116 | V_117 ;
if ( F_49 ( V_118 ) )
V_93 |= V_119 | V_120 ;
if ( F_49 ( V_163 ) )
V_93 |= V_164 | V_165 ;
if ( F_49 ( V_121 ) )
V_93 |= V_122 | V_123 ;
break;
case V_166 :
return V_50 ;
case V_167 : {
T_6 V_98 ;
F_47 ( V_98 , F_45 ( V_39 ) ) ;
V_141 . V_91 = F_55 ( V_98 ) ;
V_138 = V_125 ;
goto V_111;
}
case V_168 : {
T_6 V_98 ;
F_47 ( V_98 , F_45 ( V_39 ) ) ;
V_141 . V_139 = F_56 ( V_98 ) ;
V_138 = V_169 ;
goto V_111;
}
#if V_82 >= 2 || F_23 ( V_64 )
case V_170 :
case V_171 :
case V_172 :
case V_173 : {
unsigned int V_174 = V_175 . V_176 ;
T_6 V_98 ;
F_47 ( V_98 , F_45 ( V_39 ) ) ;
V_175 . V_176 = V_78 [ F_25 ( F_3 ( V_39 ) ) ] ;
V_141 . V_139 = F_56 ( V_98 ) ;
V_175 . V_176 = V_174 ;
V_138 = V_169 ;
goto V_111;
}
#endif
#if F_23 ( V_64 )
case V_177 : {
T_6 V_98 ;
F_47 ( V_98 , F_45 ( V_39 ) ) ;
V_141 . V_140 = F_57 ( V_98 ) ;
V_138 = V_178 ;
goto V_111;
}
case V_179 :
case V_180 :
case V_181 :
case V_182 : {
unsigned int V_174 = V_175 . V_176 ;
T_6 V_98 ;
F_47 ( V_98 , F_45 ( V_39 ) ) ;
V_175 . V_176 = V_78 [ F_25 ( F_3 ( V_39 ) ) ] ;
V_141 . V_140 = F_57 ( V_98 ) ;
V_175 . V_176 = V_174 ;
V_138 = V_178 ;
goto V_111;
}
#endif
default:
if ( F_3 ( V_39 ) >= V_183 ) {
unsigned V_184 = F_3 ( V_39 ) - V_183 ;
T_6 V_98 , V_99 ;
F_47 ( V_98 , F_45 ( V_39 ) ) ;
F_47 ( V_99 , F_43 ( V_39 ) ) ;
V_141 . V_139 = F_58 ( V_98 , V_99 ,
V_185 [ V_184 & 0x7 ] , V_184 & 0x8 ) ;
V_138 = - 1 ;
if ( ( V_184 & 0x8 ) && F_49
( V_121 ) )
V_93 = V_122 | V_123 ;
else
goto V_111;
}
else {
return V_50 ;
}
break;
}
break;
}
case V_125 : {
union {
T_5 (* F_53) ( T_5 , T_5 );
T_5 (* F_54) ( T_5 );
} F_41 ;
switch ( F_3 ( V_39 ) ) {
case V_143 :
F_41 . F_53 = V_186 ;
goto V_187;
case V_146 :
F_41 . F_53 = V_188 ;
goto V_187;
case V_148 :
F_41 . F_53 = V_189 ;
goto V_187;
case V_150 :
F_41 . F_53 = F_31 ;
goto V_187;
#if V_82 >= 2 || F_23 ( V_64 )
case V_151 :
F_41 . F_54 = F_34 ;
goto V_190;
#endif
#if V_82 >= 4 && V_82 != 32
case V_153 :
F_41 . F_54 = F_33 ;
goto V_190;
case V_154 :
F_41 . F_54 = F_30 ;
goto V_190;
#endif
#if V_82 >= 4
case V_155 :
V_42 = V_83 [ F_43 ( V_39 ) >> 2 ] ;
if ( ( ( V_37 -> V_72 & V_42 ) != 0 ) !=
( ( F_43 ( V_39 ) & 1 ) != 0 ) )
return 0 ;
F_50 ( V_141 . V_91 , F_45 ( V_39 ) ) ;
break;
case V_156 :
if ( V_31 -> V_56 [ F_43 ( V_39 ) ] != 0 )
return 0 ;
F_50 ( V_141 . V_91 , F_45 ( V_39 ) ) ;
break;
case V_157 :
if ( V_31 -> V_56 [ F_43 ( V_39 ) ] == 0 )
return 0 ;
F_50 ( V_141 . V_91 , F_45 ( V_39 ) ) ;
break;
#endif
case V_158 :
F_41 . F_54 = V_191 ;
goto V_190;
case V_160 :
F_41 . F_54 = V_192 ;
goto V_190;
case V_162 :
F_50 ( V_141 . V_91 , F_45 ( V_39 ) ) ;
goto V_111;
V_187: {
T_5 V_98 , V_99 ;
F_50 ( V_98 , F_45 ( V_39 ) ) ;
F_50 ( V_99 , F_43 ( V_39 ) ) ;
V_141 . V_91 = (* F_41 . F_53 ) ( V_98 , V_99 ) ;
goto V_111;
}
V_190: {
T_5 V_98 ;
F_50 ( V_98 , F_45 ( V_39 ) ) ;
V_141 . V_91 = (* F_41 . F_54 ) ( V_98 ) ;
goto V_111;
}
case V_166 : {
T_5 V_98 ;
F_50 ( V_98 , F_45 ( V_39 ) ) ;
V_141 . V_92 = F_59 ( V_98 ) ;
V_138 = V_95 ;
goto V_111;
}
case V_167 :
return V_50 ;
case V_168 : {
T_5 V_98 ;
F_50 ( V_98 , F_45 ( V_39 ) ) ;
V_141 . V_139 = F_60 ( V_98 ) ;
V_138 = V_169 ;
goto V_111;
}
#if V_82 >= 2 || F_23 ( V_64 )
case V_170 :
case V_171 :
case V_172 :
case V_173 : {
unsigned int V_174 = V_175 . V_176 ;
T_5 V_98 ;
F_50 ( V_98 , F_45 ( V_39 ) ) ;
V_175 . V_176 = V_78 [ F_25 ( F_3 ( V_39 ) ) ] ;
V_141 . V_139 = F_60 ( V_98 ) ;
V_175 . V_176 = V_174 ;
V_138 = V_169 ;
goto V_111;
}
#endif
#if F_23 ( V_64 )
case V_177 : {
T_5 V_98 ;
F_50 ( V_98 , F_45 ( V_39 ) ) ;
V_141 . V_140 = F_61 ( V_98 ) ;
V_138 = V_178 ;
goto V_111;
}
case V_179 :
case V_180 :
case V_181 :
case V_182 : {
unsigned int V_174 = V_175 . V_176 ;
T_5 V_98 ;
F_50 ( V_98 , F_45 ( V_39 ) ) ;
V_175 . V_176 = V_78 [ F_25 ( F_3 ( V_39 ) ) ] ;
V_141 . V_140 = F_61 ( V_98 ) ;
V_175 . V_176 = V_174 ;
V_138 = V_178 ;
goto V_111;
}
#endif
default:
if ( F_3 ( V_39 ) >= V_183 ) {
unsigned V_184 = F_3 ( V_39 ) - V_183 ;
T_5 V_98 , V_99 ;
F_50 ( V_98 , F_45 ( V_39 ) ) ;
F_50 ( V_99 , F_43 ( V_39 ) ) ;
V_141 . V_139 = F_62 ( V_98 , V_99 ,
V_185 [ V_184 & 0x7 ] , V_184 & 0x8 ) ;
V_138 = - 1 ;
if ( ( V_184 & 0x8 )
&&
F_49
( V_121 ) )
V_93 = V_122 | V_123 ;
else
goto V_111;
}
else {
return V_50 ;
}
break;
}
break;
}
case V_169 : {
T_6 V_98 ;
switch ( F_3 ( V_39 ) ) {
case V_166 :
F_47 ( V_98 , F_45 ( V_39 ) ) ;
V_141 . V_92 = F_63 ( V_98 . V_193 ) ;
V_138 = V_95 ;
goto V_111;
case V_167 :
F_47 ( V_98 , F_45 ( V_39 ) ) ;
V_141 . V_91 = F_64 ( V_98 . V_193 ) ;
V_138 = V_125 ;
goto V_111;
default:
return V_50 ;
}
break;
}
#if F_23 ( V_64 )
case V_178 : {
switch ( F_3 ( V_39 ) ) {
case V_166 :
V_141 . V_92 = F_65 ( V_37 -> V_194 [ F_45 ( V_39 ) ] ) ;
V_138 = V_95 ;
goto V_111;
case V_167 :
V_141 . V_91 = F_66 ( V_37 -> V_194 [ F_45 ( V_39 ) ] ) ;
V_138 = V_125 ;
goto V_111;
default:
return V_50 ;
}
break;
}
#endif
default:
return V_50 ;
}
V_37 -> V_72 = ( V_37 -> V_72 & ~ V_124 ) | V_93 ;
if ( ( V_37 -> V_72 >> 5 ) & V_37 -> V_72 & V_79 ) {
return V_80 ;
}
switch ( V_138 ) {
case - 1 : {
#if V_82 >= 4
V_42 = V_83 [ F_44 ( V_39 ) >> 2 ] ;
#else
V_42 = V_84 ;
#endif
if ( V_141 . V_139 )
V_37 -> V_72 |= V_42 ;
else
V_37 -> V_72 &= ~ V_42 ;
break;
}
case V_125 :
F_51 ( V_141 . V_91 , F_44 ( V_39 ) ) ;
break;
case V_95 :
F_48 ( V_141 . V_92 , F_44 ( V_39 ) ) ;
break;
case V_169 :
F_21 ( V_141 . V_139 , F_44 ( V_39 ) ) ;
break;
#if F_23 ( V_64 )
case V_178 :
F_18 ( V_141 . V_140 , F_44 ( V_39 ) ) ;
break;
#endif
default:
return V_50 ;
}
return 0 ;
}
int F_67 ( struct V_30 * V_31 , struct V_36 * V_37 ,
int V_195 , void * T_2 * V_38 )
{
unsigned long V_196 , V_197 ;
T_1 V_198 ;
int V_90 = 0 ;
V_196 = V_31 -> V_44 ;
do {
V_197 = V_31 -> V_44 ;
if ( ! F_10 ( V_43 , V_31 -> V_44 , sizeof( T_1 ) ) ) {
F_11 ( V_45 ) ;
* V_38 = ( T_1 T_2 * ) V_31 -> V_44 ;
return V_46 ;
}
if ( F_12 ( V_198 , ( T_1 T_2 * ) V_31 -> V_44 ) ) {
F_11 ( V_45 ) ;
* V_38 = ( T_1 T_2 * ) V_31 -> V_44 ;
return V_47 ;
}
if ( V_198 == 0 )
V_31 -> V_44 += 4 ;
else {
V_175 . V_176 = V_78 [ V_175 . V_176 ] ;
V_90 = F_9 ( V_31 , V_37 , V_38 ) ;
V_175 . V_176 = V_74 [ V_175 . V_176 ] ;
}
if ( V_195 )
break;
if ( V_90 )
break;
F_68 () ;
} while ( V_31 -> V_44 > V_197 );
if ( V_90 == V_50 && V_31 -> V_44 != V_196 )
V_90 = 0 ;
return V_90 ;
}
static int F_69 ( void * V_199 , T_3 * V_57 )
{
int V_200 ;
unsigned long V_201 = 0 ;
F_70 (cpu) {
struct V_202 * V_203 ;
T_8 * V_204 ;
V_203 = & F_71 ( V_205 , V_200 ) ;
V_204 = ( void * ) V_203 + ( unsigned long ) V_199 ;
V_201 += F_72 ( V_204 ) ;
}
* V_57 = V_201 ;
return 0 ;
}
static int T_9 F_73 ( void )
{
struct V_206 * V_91 , * V_207 ;
if ( ! V_208 )
return - V_209 ;
V_207 = F_74 ( L_4 , V_208 ) ;
if ( ! V_207 )
return - V_210 ;
#define F_75 ( T_10 ) \
do { \
d = debugfs_create_file(#M , S_IRUGO, dir, \
(void *)offsetof(struct mips_fpu_emulator_stats, M), \
&fops_fpuemu_stat); \
if (!d) \
return -ENOMEM; \
} while (0)
F_75 ( V_53 ) ;
F_75 ( V_58 ) ;
F_75 ( V_60 ) ;
F_75 ( V_142 ) ;
F_75 ( V_94 ) ;
F_75 ( V_45 ) ;
return 0 ;
}
