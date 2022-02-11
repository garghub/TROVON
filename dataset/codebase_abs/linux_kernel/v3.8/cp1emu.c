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
#if F_7 ( V_32 ) && ! F_7 ( V_33 )
return 1 ;
#elif F_7 ( V_32 ) && F_7 ( V_33 )
return ! F_8 ( V_34 ) ;
#else
return 0 ;
#endif
}
static int F_9 ( struct V_30 * V_31 , struct V_35 * V_36 ,
void * T_2 * V_37 )
{
T_1 V_38 ;
unsigned long V_39 , V_40 ;
unsigned int V_41 ;
if ( ! F_10 ( V_42 , V_31 -> V_43 , sizeof( T_1 ) ) ) {
F_11 ( V_44 ) ;
* V_37 = ( T_1 T_2 * ) V_31 -> V_43 ;
return V_45 ;
}
if ( F_12 ( V_38 , ( T_1 T_2 * ) V_31 -> V_43 ) ) {
F_11 ( V_44 ) ;
* V_37 = ( T_1 T_2 * ) V_31 -> V_43 ;
return V_46 ;
}
if ( ( V_31 -> V_47 & V_48 ) && ! F_1 ( & V_38 ) )
V_31 -> V_47 &= ~ V_48 ;
if ( V_31 -> V_47 & V_48 ) {
V_39 = V_31 -> V_43 + 4 ;
if ( F_13 ( V_31 ) < 0 ) {
#ifdef F_14
F_15 ( L_1 ,
( void * ) ( V_31 -> V_43 ) ) ;
#endif
return V_49 ;
}
if ( ! F_10 ( V_42 , V_39 , sizeof( T_1 ) ) ) {
F_11 ( V_44 ) ;
* V_37 = ( T_1 T_2 * ) V_39 ;
return V_45 ;
}
if ( F_12 ( V_38 , ( T_1 T_2 * ) V_39 ) ) {
F_11 ( V_44 ) ;
* V_37 = ( T_1 T_2 * ) V_39 ;
return V_46 ;
}
V_40 = V_31 -> V_43 ;
V_31 -> V_43 = V_39 - 4 ;
} else {
V_39 = V_31 -> V_43 ;
V_40 = V_31 -> V_43 + 4 ;
}
V_50:
F_16 ( V_51 , 1 , V_31 , 0 ) ;
F_11 ( V_52 ) ;
switch ( F_2 ( V_38 ) ) {
case V_53 : {
T_3 T_2 * V_54 = ( T_3 T_2 * ) ( V_31 -> V_55 [ F_5 ( V_38 ) ] +
F_17 ( V_38 ) ) ;
T_3 V_56 ;
F_11 ( V_57 ) ;
if ( ! F_10 ( V_42 , V_54 , sizeof( T_3 ) ) ) {
F_11 ( V_44 ) ;
* V_37 = V_54 ;
return V_45 ;
}
if ( F_12 ( V_56 , V_54 ) ) {
F_11 ( V_44 ) ;
* V_37 = V_54 ;
return V_46 ;
}
F_18 ( V_56 , F_4 ( V_38 ) ) ;
break;
}
case V_58 : {
T_3 T_2 * V_54 = ( T_3 T_2 * ) ( V_31 -> V_55 [ F_5 ( V_38 ) ] +
F_17 ( V_38 ) ) ;
T_3 V_56 ;
F_11 ( V_59 ) ;
F_19 ( V_56 , F_4 ( V_38 ) ) ;
if ( ! F_10 ( V_60 , V_54 , sizeof( T_3 ) ) ) {
F_11 ( V_44 ) ;
* V_37 = V_54 ;
return V_45 ;
}
if ( F_20 ( V_56 , V_54 ) ) {
F_11 ( V_44 ) ;
* V_37 = V_54 ;
return V_46 ;
}
break;
}
case V_61 : {
T_4 T_2 * V_54 = ( T_4 T_2 * ) ( V_31 -> V_55 [ F_5 ( V_38 ) ] +
F_17 ( V_38 ) ) ;
T_4 V_56 ;
F_11 ( V_57 ) ;
if ( ! F_10 ( V_42 , V_54 , sizeof( T_4 ) ) ) {
F_11 ( V_44 ) ;
* V_37 = V_54 ;
return V_45 ;
}
if ( F_12 ( V_56 , V_54 ) ) {
F_11 ( V_44 ) ;
* V_37 = V_54 ;
return V_46 ;
}
F_21 ( V_56 , F_4 ( V_38 ) ) ;
break;
}
case V_62 : {
T_4 T_2 * V_54 = ( T_4 T_2 * ) ( V_31 -> V_55 [ F_5 ( V_38 ) ] +
F_17 ( V_38 ) ) ;
T_4 V_56 ;
F_11 ( V_59 ) ;
F_22 ( V_56 , F_4 ( V_38 ) ) ;
if ( ! F_10 ( V_60 , V_54 , sizeof( T_4 ) ) ) {
F_11 ( V_44 ) ;
* V_37 = V_54 ;
return V_45 ;
}
if ( F_20 ( V_56 , V_54 ) ) {
F_11 ( V_44 ) ;
* V_37 = V_54 ;
return V_46 ;
}
break;
}
case V_26 :
switch ( F_5 ( V_38 ) ) {
#if F_7 ( V_63 )
case V_64 :
if ( F_4 ( V_38 ) != 0 ) {
F_19 ( V_31 -> V_55 [ F_4 ( V_38 ) ] ,
F_23 ( V_38 ) ) ;
}
break;
case V_65 :
F_18 ( V_31 -> V_55 [ F_4 ( V_38 ) ] , F_23 ( V_38 ) ) ;
break;
#endif
case V_66 :
if ( F_4 ( V_38 ) != 0 ) {
F_22 ( V_31 -> V_55 [ F_4 ( V_38 ) ] ,
F_23 ( V_38 ) ) ;
}
break;
case V_67 :
F_21 ( V_31 -> V_55 [ F_4 ( V_38 ) ] , F_23 ( V_38 ) ) ;
break;
case V_68 : {
T_4 V_69 ;
if ( F_23 ( V_38 ) == V_70 ) {
V_69 = V_36 -> V_71 ;
V_69 = ( V_69 & ~ V_72 ) |
V_73 [ F_24 ( V_69 ) ] ;
#ifdef F_25
F_15 ( L_2 ,
( void * ) ( V_31 -> V_43 ) ,
F_4 ( V_38 ) , V_69 ) ;
#endif
}
else if ( F_23 ( V_38 ) == V_74 )
V_69 = 0 ;
else
V_69 = 0 ;
if ( F_4 ( V_38 ) )
V_31 -> V_55 [ F_4 ( V_38 ) ] = V_69 ;
break;
}
case V_75 : {
T_4 V_69 ;
if ( F_4 ( V_38 ) == 0 )
V_69 = 0 ;
else
V_69 = V_31 -> V_55 [ F_4 ( V_38 ) ] ;
if ( F_23 ( V_38 ) == V_70 ) {
#ifdef F_25
F_15 ( L_3 ,
( void * ) ( V_31 -> V_43 ) ,
F_4 ( V_38 ) , V_69 ) ;
#endif
V_36 -> V_71 = ( V_69 &
~ ( V_76 | V_72 ) ) |
V_77 [ F_24 ( V_69 ) ] ;
}
if ( ( V_36 -> V_71 >> 5 ) & V_36 -> V_71 & V_78 ) {
return V_79 ;
}
break;
}
case V_29 : {
int V_80 = 0 ;
if ( V_31 -> V_47 & V_48 )
return V_49 ;
#if V_81 >= 4
V_41 = V_36 -> V_71 & V_82 [ F_4 ( V_38 ) >> 2 ] ;
#else
V_41 = V_36 -> V_71 & V_83 ;
#endif
switch ( F_4 ( V_38 ) & 3 ) {
case V_84 :
V_80 = 1 ;
case V_85 :
V_41 = ! V_41 ;
break;
case V_86 :
V_80 = 1 ;
case V_87 :
break;
default:
return V_49 ;
}
V_31 -> V_47 |= V_48 ;
if ( V_41 ) {
V_31 -> V_43 += 4 ;
V_40 = ( V_31 -> V_43 +
( F_17 ( V_38 ) << 2 ) ) ;
if ( ! F_10 ( V_42 , V_31 -> V_43 ,
sizeof( T_1 ) ) ) {
F_11 ( V_44 ) ;
* V_37 = ( T_1 T_2 * ) V_31 -> V_43 ;
return V_45 ;
}
if ( F_12 ( V_38 ,
( T_1 T_2 * ) V_31 -> V_43 ) ) {
F_11 ( V_44 ) ;
* V_37 = ( T_1 T_2 * ) V_31 -> V_43 ;
return V_46 ;
}
switch ( F_2 ( V_38 ) ) {
case V_61 :
case V_62 :
#if ( V_81 >= 2 || F_7 ( V_63 ) )
case V_53 :
case V_58 :
#endif
case V_26 :
#if V_81 >= 4 && V_81 != 32
case V_28 :
#endif
goto V_50;
#if V_81 >= 4
case V_2 :
if ( F_3 ( V_38 ) == V_88 )
goto V_50;
break;
#endif
}
return F_26 ( V_31 , V_38 , V_40 ) ;
}
else {
if ( V_80 ) {
V_31 -> V_43 += 4 ;
V_40 += 4 ;
}
}
break;
}
default:
if ( ! ( F_5 ( V_38 ) & 0x10 ) )
return V_49 ;
{
int V_89 ;
if ( ( V_89 = F_27 ( V_31 , V_36 , V_38 ) ) )
return V_89 ;
}
}
break;
#if V_81 >= 4 && V_81 != 32
case V_28 : {
int V_89 = F_28 ( V_31 , V_36 , V_38 , V_37 ) ;
if ( V_89 )
return V_89 ;
break;
}
#endif
#if V_81 >= 4
case V_2 :
if ( F_3 ( V_38 ) != V_88 )
return V_49 ;
V_41 = V_82 [ F_4 ( V_38 ) >> 2 ] ;
if ( ( ( V_36 -> V_71 & V_41 ) != 0 ) == ( ( F_4 ( V_38 ) & 1 ) != 0 ) )
V_31 -> V_55 [ F_23 ( V_38 ) ] =
V_31 -> V_55 [ F_5 ( V_38 ) ] ;
break;
#endif
default:
return V_49 ;
}
V_31 -> V_43 = V_40 ;
V_31 -> V_47 &= ~ V_48 ;
return 0 ;
}
static T_5 F_29 ( T_5 V_90 )
{
return F_30 ( F_31 ( 0 ) , V_90 ) ;
}
static T_5 F_32 ( T_5 V_90 )
{
return F_30 ( F_31 ( 0 ) , F_33 ( V_90 ) ) ;
}
static T_6 F_34 ( T_6 V_91 )
{
return F_35 ( F_36 ( 0 ) , V_91 ) ;
}
static T_6 F_37 ( T_6 V_91 )
{
return F_35 ( F_36 ( 0 ) , F_38 ( V_91 ) ) ;
}
static int F_28 ( struct V_30 * V_31 , struct V_35 * V_36 ,
T_1 V_38 , void * T_2 * V_37 )
{
unsigned V_92 = 0 ;
F_11 ( V_93 ) ;
switch ( F_39 ( V_38 ) ) {
case V_94 : {
T_6 (* F_40) ( T_6 , T_6 , T_6 );
T_6 V_95 , V_96 , V_97 , V_98 ;
T_4 T_2 * V_54 ;
T_4 V_56 ;
switch ( F_3 ( V_38 ) ) {
case V_99 :
V_54 = ( void T_2 * ) ( V_31 -> V_55 [ F_41 ( V_38 ) ] +
V_31 -> V_55 [ F_42 ( V_38 ) ] ) ;
F_11 ( V_57 ) ;
if ( ! F_10 ( V_42 , V_54 , sizeof( T_4 ) ) ) {
F_11 ( V_44 ) ;
* V_37 = V_54 ;
return V_45 ;
}
if ( F_12 ( V_56 , V_54 ) ) {
F_11 ( V_44 ) ;
* V_37 = V_54 ;
return V_46 ;
}
F_21 ( V_56 , F_43 ( V_38 ) ) ;
break;
case V_100 :
V_54 = ( void T_2 * ) ( V_31 -> V_55 [ F_41 ( V_38 ) ] +
V_31 -> V_55 [ F_42 ( V_38 ) ] ) ;
F_11 ( V_59 ) ;
F_22 ( V_56 , F_44 ( V_38 ) ) ;
if ( ! F_10 ( V_60 , V_54 , sizeof( T_4 ) ) ) {
F_11 ( V_44 ) ;
* V_37 = V_54 ;
return V_45 ;
}
if ( F_45 ( V_56 , V_54 ) ) {
F_11 ( V_44 ) ;
* V_37 = V_54 ;
return V_46 ;
}
break;
case V_101 :
F_40 = V_102 ;
goto V_103;
case V_104 :
F_40 = V_105 ;
goto V_103;
case V_106 :
F_40 = V_107 ;
goto V_103;
case V_108 :
F_40 = V_109 ;
goto V_103;
V_103:
F_46 ( V_96 , F_41 ( V_38 ) ) ;
F_46 ( V_97 , F_44 ( V_38 ) ) ;
F_46 ( V_98 , F_42 ( V_38 ) ) ;
V_95 = (* F_40) ( V_96 , V_97 , V_98 ) ;
F_47 ( V_95 , F_43 ( V_38 ) ) ;
V_110:
if ( F_48 ( V_111 ) )
V_92 |= V_112 | V_113 ;
if ( F_48 ( V_114 ) )
V_92 |= V_115 | V_116 ;
if ( F_48 ( V_117 ) )
V_92 |= V_118 | V_119 ;
if ( F_48 ( V_120 ) )
V_92 |= V_121 | V_122 ;
V_36 -> V_71 = ( V_36 -> V_71 & ~ V_123 ) | V_92 ;
if ( ( V_36 -> V_71 >> 5 ) & V_36 -> V_71 & V_78 ) {
return V_79 ;
}
break;
default:
return V_49 ;
}
break;
}
case V_124 : {
T_5 (* F_40) ( T_5 , T_5 , T_5 );
T_5 V_95 , V_96 , V_97 , V_98 ;
T_3 T_2 * V_54 ;
T_3 V_56 ;
switch ( F_3 ( V_38 ) ) {
case V_125 :
V_54 = ( void T_2 * ) ( V_31 -> V_55 [ F_41 ( V_38 ) ] +
V_31 -> V_55 [ F_42 ( V_38 ) ] ) ;
F_11 ( V_57 ) ;
if ( ! F_10 ( V_42 , V_54 , sizeof( T_3 ) ) ) {
F_11 ( V_44 ) ;
* V_37 = V_54 ;
return V_45 ;
}
if ( F_12 ( V_56 , V_54 ) ) {
F_11 ( V_44 ) ;
* V_37 = V_54 ;
return V_46 ;
}
F_18 ( V_56 , F_43 ( V_38 ) ) ;
break;
case V_126 :
V_54 = ( void T_2 * ) ( V_31 -> V_55 [ F_41 ( V_38 ) ] +
V_31 -> V_55 [ F_42 ( V_38 ) ] ) ;
F_11 ( V_59 ) ;
F_19 ( V_56 , F_44 ( V_38 ) ) ;
if ( ! F_10 ( V_60 , V_54 , sizeof( T_3 ) ) ) {
F_11 ( V_44 ) ;
* V_37 = V_54 ;
return V_45 ;
}
if ( F_20 ( V_56 , V_54 ) ) {
F_11 ( V_44 ) ;
* V_37 = V_54 ;
return V_46 ;
}
break;
case V_127 :
F_40 = V_128 ;
goto V_129;
case V_130 :
F_40 = V_131 ;
goto V_129;
case V_132 :
F_40 = V_133 ;
goto V_129;
case V_134 :
F_40 = V_135 ;
goto V_129;
V_129:
F_49 ( V_96 , F_41 ( V_38 ) ) ;
F_49 ( V_97 , F_44 ( V_38 ) ) ;
F_49 ( V_98 , F_42 ( V_38 ) ) ;
V_95 = (* F_40) ( V_96 , V_97 , V_98 ) ;
F_50 ( V_95 , F_43 ( V_38 ) ) ;
goto V_110;
default:
return V_49 ;
}
break;
}
case 0x7 :
if ( F_3 ( V_38 ) != V_136 ) {
return V_49 ;
}
break;
default:
return V_49 ;
}
return 0 ;
}
static int F_27 ( struct V_30 * V_31 , struct V_35 * V_36 ,
T_1 V_38 )
{
int V_137 ;
unsigned V_92 = 0 ;
unsigned V_41 ;
union {
T_5 V_90 ;
T_6 V_91 ;
int V_138 ;
#ifdef V_63
T_7 V_139 ;
#endif
} V_140 ;
F_11 ( V_141 ) ;
switch ( V_137 = ( F_51 ( V_38 ) & 0xf ) ) {
case V_94 : {
union {
T_6 (* F_52) ( T_6 , T_6 );
T_6 (* F_53) ( T_6 );
} F_40 ;
switch ( F_3 ( V_38 ) ) {
case V_142 :
F_40 . F_52 = V_143 ;
goto V_144;
case V_145 :
F_40 . F_52 = V_146 ;
goto V_144;
case V_147 :
F_40 . F_52 = V_148 ;
goto V_144;
case V_149 :
F_40 . F_52 = F_35 ;
goto V_144;
#if V_81 >= 2 || F_7 ( V_63 )
case V_150 :
F_40 . F_53 = F_38 ;
goto V_151;
#endif
#if V_81 >= 4 && V_81 != 32
case V_152 :
F_40 . F_53 = F_37 ;
goto V_151;
case V_153 :
F_40 . F_53 = F_34 ;
goto V_151;
#endif
#if V_81 >= 4
case V_154 :
V_41 = V_82 [ F_42 ( V_38 ) >> 2 ] ;
if ( ( ( V_36 -> V_71 & V_41 ) != 0 ) !=
( ( F_42 ( V_38 ) & 1 ) != 0 ) )
return 0 ;
F_46 ( V_140 . V_91 , F_44 ( V_38 ) ) ;
break;
case V_155 :
if ( V_31 -> V_55 [ F_42 ( V_38 ) ] != 0 )
return 0 ;
F_46 ( V_140 . V_91 , F_44 ( V_38 ) ) ;
break;
case V_156 :
if ( V_31 -> V_55 [ F_42 ( V_38 ) ] == 0 )
return 0 ;
F_46 ( V_140 . V_91 , F_44 ( V_38 ) ) ;
break;
#endif
case V_157 :
F_40 . F_53 = V_158 ;
goto V_151;
case V_159 :
F_40 . F_53 = V_160 ;
goto V_151;
case V_161 :
F_46 ( V_140 . V_91 , F_44 ( V_38 ) ) ;
goto V_110;
V_144:
{
T_6 V_97 , V_98 ;
F_46 ( V_97 , F_44 ( V_38 ) ) ;
F_46 ( V_98 , F_42 ( V_38 ) ) ;
V_140 . V_91 = (* F_40 . F_52 ) ( V_97 , V_98 ) ;
goto V_110;
}
V_151:
{
T_6 V_97 ;
F_46 ( V_97 , F_44 ( V_38 ) ) ;
V_140 . V_91 = (* F_40 . F_53 ) ( V_97 ) ;
goto V_110;
}
V_110:
if ( F_48 ( V_111 ) )
V_92 |= V_112 | V_113 ;
if ( F_48 ( V_114 ) )
V_92 |= V_115 | V_116 ;
if ( F_48 ( V_117 ) )
V_92 |= V_118 | V_119 ;
if ( F_48 ( V_162 ) )
V_92 |= V_163 | V_164 ;
if ( F_48 ( V_120 ) )
V_92 |= V_121 | V_122 ;
break;
case V_165 :
return V_49 ;
case V_166 : {
T_6 V_97 ;
F_46 ( V_97 , F_44 ( V_38 ) ) ;
V_140 . V_90 = F_54 ( V_97 ) ;
V_137 = V_124 ;
goto V_110;
}
case V_167 : {
T_6 V_97 ;
F_46 ( V_97 , F_44 ( V_38 ) ) ;
V_140 . V_138 = F_55 ( V_97 ) ;
V_137 = V_168 ;
goto V_110;
}
#if V_81 >= 2 || F_7 ( V_63 )
case V_169 :
case V_170 :
case V_171 :
case V_172 : {
unsigned int V_173 = V_174 . V_175 ;
T_6 V_97 ;
F_46 ( V_97 , F_44 ( V_38 ) ) ;
V_174 . V_175 = V_77 [ F_24 ( F_3 ( V_38 ) ) ] ;
V_140 . V_138 = F_55 ( V_97 ) ;
V_174 . V_175 = V_173 ;
V_137 = V_168 ;
goto V_110;
}
#endif
#if F_7 ( V_63 )
case V_176 : {
T_6 V_97 ;
F_46 ( V_97 , F_44 ( V_38 ) ) ;
V_140 . V_139 = F_56 ( V_97 ) ;
V_137 = V_177 ;
goto V_110;
}
case V_178 :
case V_179 :
case V_180 :
case V_181 : {
unsigned int V_173 = V_174 . V_175 ;
T_6 V_97 ;
F_46 ( V_97 , F_44 ( V_38 ) ) ;
V_174 . V_175 = V_77 [ F_24 ( F_3 ( V_38 ) ) ] ;
V_140 . V_139 = F_56 ( V_97 ) ;
V_174 . V_175 = V_173 ;
V_137 = V_177 ;
goto V_110;
}
#endif
default:
if ( F_3 ( V_38 ) >= V_182 ) {
unsigned V_183 = F_3 ( V_38 ) - V_182 ;
T_6 V_97 , V_98 ;
F_46 ( V_97 , F_44 ( V_38 ) ) ;
F_46 ( V_98 , F_42 ( V_38 ) ) ;
V_140 . V_138 = F_57 ( V_97 , V_98 ,
V_184 [ V_183 & 0x7 ] , V_183 & 0x8 ) ;
V_137 = - 1 ;
if ( ( V_183 & 0x8 ) && F_48
( V_120 ) )
V_92 = V_121 | V_122 ;
else
goto V_110;
}
else {
return V_49 ;
}
break;
}
break;
}
case V_124 : {
union {
T_5 (* F_52) ( T_5 , T_5 );
T_5 (* F_53) ( T_5 );
} F_40 ;
switch ( F_3 ( V_38 ) ) {
case V_142 :
F_40 . F_52 = V_185 ;
goto V_186;
case V_145 :
F_40 . F_52 = V_187 ;
goto V_186;
case V_147 :
F_40 . F_52 = V_188 ;
goto V_186;
case V_149 :
F_40 . F_52 = F_30 ;
goto V_186;
#if V_81 >= 2 || F_7 ( V_63 )
case V_150 :
F_40 . F_53 = F_33 ;
goto V_189;
#endif
#if V_81 >= 4 && V_81 != 32
case V_152 :
F_40 . F_53 = F_32 ;
goto V_189;
case V_153 :
F_40 . F_53 = F_29 ;
goto V_189;
#endif
#if V_81 >= 4
case V_154 :
V_41 = V_82 [ F_42 ( V_38 ) >> 2 ] ;
if ( ( ( V_36 -> V_71 & V_41 ) != 0 ) !=
( ( F_42 ( V_38 ) & 1 ) != 0 ) )
return 0 ;
F_49 ( V_140 . V_90 , F_44 ( V_38 ) ) ;
break;
case V_155 :
if ( V_31 -> V_55 [ F_42 ( V_38 ) ] != 0 )
return 0 ;
F_49 ( V_140 . V_90 , F_44 ( V_38 ) ) ;
break;
case V_156 :
if ( V_31 -> V_55 [ F_42 ( V_38 ) ] == 0 )
return 0 ;
F_49 ( V_140 . V_90 , F_44 ( V_38 ) ) ;
break;
#endif
case V_157 :
F_40 . F_53 = V_190 ;
goto V_189;
case V_159 :
F_40 . F_53 = V_191 ;
goto V_189;
case V_161 :
F_49 ( V_140 . V_90 , F_44 ( V_38 ) ) ;
goto V_110;
V_186: {
T_5 V_97 , V_98 ;
F_49 ( V_97 , F_44 ( V_38 ) ) ;
F_49 ( V_98 , F_42 ( V_38 ) ) ;
V_140 . V_90 = (* F_40 . F_52 ) ( V_97 , V_98 ) ;
goto V_110;
}
V_189: {
T_5 V_97 ;
F_49 ( V_97 , F_44 ( V_38 ) ) ;
V_140 . V_90 = (* F_40 . F_53 ) ( V_97 ) ;
goto V_110;
}
case V_165 : {
T_5 V_97 ;
F_49 ( V_97 , F_44 ( V_38 ) ) ;
V_140 . V_91 = F_58 ( V_97 ) ;
V_137 = V_94 ;
goto V_110;
}
case V_166 :
return V_49 ;
case V_167 : {
T_5 V_97 ;
F_49 ( V_97 , F_44 ( V_38 ) ) ;
V_140 . V_138 = F_59 ( V_97 ) ;
V_137 = V_168 ;
goto V_110;
}
#if V_81 >= 2 || F_7 ( V_63 )
case V_169 :
case V_170 :
case V_171 :
case V_172 : {
unsigned int V_173 = V_174 . V_175 ;
T_5 V_97 ;
F_49 ( V_97 , F_44 ( V_38 ) ) ;
V_174 . V_175 = V_77 [ F_24 ( F_3 ( V_38 ) ) ] ;
V_140 . V_138 = F_59 ( V_97 ) ;
V_174 . V_175 = V_173 ;
V_137 = V_168 ;
goto V_110;
}
#endif
#if F_7 ( V_63 )
case V_176 : {
T_5 V_97 ;
F_49 ( V_97 , F_44 ( V_38 ) ) ;
V_140 . V_139 = F_60 ( V_97 ) ;
V_137 = V_177 ;
goto V_110;
}
case V_178 :
case V_179 :
case V_180 :
case V_181 : {
unsigned int V_173 = V_174 . V_175 ;
T_5 V_97 ;
F_49 ( V_97 , F_44 ( V_38 ) ) ;
V_174 . V_175 = V_77 [ F_24 ( F_3 ( V_38 ) ) ] ;
V_140 . V_139 = F_60 ( V_97 ) ;
V_174 . V_175 = V_173 ;
V_137 = V_177 ;
goto V_110;
}
#endif
default:
if ( F_3 ( V_38 ) >= V_182 ) {
unsigned V_183 = F_3 ( V_38 ) - V_182 ;
T_5 V_97 , V_98 ;
F_49 ( V_97 , F_44 ( V_38 ) ) ;
F_49 ( V_98 , F_42 ( V_38 ) ) ;
V_140 . V_138 = F_61 ( V_97 , V_98 ,
V_184 [ V_183 & 0x7 ] , V_183 & 0x8 ) ;
V_137 = - 1 ;
if ( ( V_183 & 0x8 )
&&
F_48
( V_120 ) )
V_92 = V_121 | V_122 ;
else
goto V_110;
}
else {
return V_49 ;
}
break;
}
break;
}
case V_168 : {
T_6 V_97 ;
switch ( F_3 ( V_38 ) ) {
case V_165 :
F_46 ( V_97 , F_44 ( V_38 ) ) ;
V_140 . V_91 = F_62 ( V_97 . V_192 ) ;
V_137 = V_94 ;
goto V_110;
case V_166 :
F_46 ( V_97 , F_44 ( V_38 ) ) ;
V_140 . V_90 = F_63 ( V_97 . V_192 ) ;
V_137 = V_124 ;
goto V_110;
default:
return V_49 ;
}
break;
}
#if F_7 ( V_63 )
case V_177 : {
switch ( F_3 ( V_38 ) ) {
case V_165 :
V_140 . V_91 = F_64 ( V_36 -> V_193 [ F_44 ( V_38 ) ] ) ;
V_137 = V_94 ;
goto V_110;
case V_166 :
V_140 . V_90 = F_65 ( V_36 -> V_193 [ F_44 ( V_38 ) ] ) ;
V_137 = V_124 ;
goto V_110;
default:
return V_49 ;
}
break;
}
#endif
default:
return V_49 ;
}
V_36 -> V_71 = ( V_36 -> V_71 & ~ V_123 ) | V_92 ;
if ( ( V_36 -> V_71 >> 5 ) & V_36 -> V_71 & V_78 ) {
return V_79 ;
}
switch ( V_137 ) {
case - 1 : {
#if V_81 >= 4
V_41 = V_82 [ F_43 ( V_38 ) >> 2 ] ;
#else
V_41 = V_83 ;
#endif
if ( V_140 . V_138 )
V_36 -> V_71 |= V_41 ;
else
V_36 -> V_71 &= ~ V_41 ;
break;
}
case V_124 :
F_50 ( V_140 . V_90 , F_43 ( V_38 ) ) ;
break;
case V_94 :
F_47 ( V_140 . V_91 , F_43 ( V_38 ) ) ;
break;
case V_168 :
F_21 ( V_140 . V_138 , F_43 ( V_38 ) ) ;
break;
#if F_7 ( V_63 )
case V_177 :
F_18 ( V_140 . V_139 , F_43 ( V_38 ) ) ;
break;
#endif
default:
return V_49 ;
}
return 0 ;
}
int F_66 ( struct V_30 * V_31 , struct V_35 * V_36 ,
int V_194 , void * T_2 * V_37 )
{
unsigned long V_195 , V_196 ;
T_1 V_197 ;
int V_89 = 0 ;
V_195 = V_31 -> V_43 ;
do {
V_196 = V_31 -> V_43 ;
if ( ! F_10 ( V_42 , V_31 -> V_43 , sizeof( T_1 ) ) ) {
F_11 ( V_44 ) ;
* V_37 = ( T_1 T_2 * ) V_31 -> V_43 ;
return V_45 ;
}
if ( F_12 ( V_197 , ( T_1 T_2 * ) V_31 -> V_43 ) ) {
F_11 ( V_44 ) ;
* V_37 = ( T_1 T_2 * ) V_31 -> V_43 ;
return V_46 ;
}
if ( V_197 == 0 )
V_31 -> V_43 += 4 ;
else {
V_174 . V_175 = V_77 [ V_174 . V_175 ] ;
V_89 = F_9 ( V_31 , V_36 , V_37 ) ;
V_174 . V_175 = V_73 [ V_174 . V_175 ] ;
}
if ( V_194 )
break;
if ( V_89 )
break;
F_67 () ;
} while ( V_31 -> V_43 > V_196 );
if ( V_89 == V_49 && V_31 -> V_43 != V_195 )
V_89 = 0 ;
return V_89 ;
}
static int F_68 ( void * V_198 , T_3 * V_56 )
{
int V_199 ;
unsigned long V_200 = 0 ;
F_69 (cpu) {
struct V_201 * V_202 ;
T_8 * V_203 ;
V_202 = & F_70 ( V_204 , V_199 ) ;
V_203 = ( void * ) V_202 + ( unsigned long ) V_198 ;
V_200 += F_71 ( V_203 ) ;
}
* V_56 = V_200 ;
return 0 ;
}
static int T_9 F_72 ( void )
{
struct V_205 * V_90 , * V_206 ;
if ( ! V_207 )
return - V_208 ;
V_206 = F_73 ( L_4 , V_207 ) ;
if ( ! V_206 )
return - V_209 ;
#define F_74 ( T_10 ) \
do { \
d = debugfs_create_file(#M , S_IRUGO, dir, \
(void *)offsetof(struct mips_fpu_emulator_stats, M), \
&fops_fpuemu_stat); \
if (!d) \
return -ENOMEM; \
} while (0)
F_74 ( V_52 ) ;
F_74 ( V_57 ) ;
F_74 ( V_59 ) ;
F_74 ( V_141 ) ;
F_74 ( V_93 ) ;
F_74 ( V_44 ) ;
return 0 ;
}
