static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
if ( V_2 -> V_5 . V_6 & V_7 )
V_3 |= ( 1ull << V_8 ) ;
return V_3 ;
}
static void F_2 ( struct V_9 * V_10 , int V_11 )
{
F_3 ( ( V_12 V_13 ) F_4 ( ( V_10 -> V_14 & 0xffffff ) |
V_11 << 31 ) ,
V_10 -> V_15 ) ;
F_5 () ;
}
static struct V_16 * F_6 ( struct V_9 * V_10 , V_13 V_17 )
{
unsigned long V_18 = ( V_17 & ( V_10 -> V_19 - 1 ) ) * V_20 ;
return V_10 -> V_21 [ V_18 / V_22 ] . V_23 + V_18 % V_22 ;
}
static struct V_16 * F_7 ( struct V_9 * V_10 )
{
struct V_16 * V_24 = F_6 ( V_10 , V_10 -> V_14 ) ;
return ! ! ( V_24 -> V_25 & 0x80 ) ^ ! ! ( V_10 -> V_14 & V_10 -> V_19 ) ? NULL : V_24 ;
}
static struct V_16 * F_8 ( struct V_26 * V_27 )
{
struct V_16 * V_24 =
& V_27 -> V_28 [ V_27 -> V_29 & ( V_30 - 1 ) ] ;
return ( ! ! ( V_24 -> V_25 & 0x80 ) ^
! ! ( V_27 -> V_29 & V_30 ) ) ?
V_24 : NULL ;
}
void F_9 ( struct V_31 * V_32 )
{
struct V_33 * V_34 =
F_10 ( V_32 , struct V_33 ,
V_35 ) ;
struct V_36 * V_37 =
F_10 ( V_34 , struct V_36 , V_34 ) ;
struct V_38 * V_39 = F_10 ( V_37 , struct V_38 , V_37 ) ;
struct V_1 * V_2 = & V_39 -> V_2 ;
struct V_26 * V_27 = & V_37 -> V_34 . V_27 ;
struct V_16 * V_24 ;
T_2 V_40 ;
int V_41 ;
for ( V_24 = F_8 ( V_27 ) ; V_24 ;
V_24 = F_8 ( V_27 ) ) {
V_40 = V_24 -> V_42 ;
if ( V_40 == V_43 ) {
for ( V_41 = 0 ; V_41 < V_2 -> V_44 ; V_41 ++ ) {
if ( V_41 != V_2 -> V_5 . V_45 &&
V_34 -> V_46 [ V_41 ] . V_47 )
if ( F_11 ( V_2 , V_41 , V_24 ) )
F_12 ( V_2 , L_1
L_2
L_3 , V_41 ) ;
}
} else {
if ( F_11 ( V_2 , V_40 , V_24 ) )
F_12 ( V_2 , L_4
L_3 , V_40 ) ;
}
++ V_27 -> V_29 ;
}
}
static void F_13 ( struct V_1 * V_2 , T_2 V_40 , struct V_16 * V_24 )
{
struct V_38 * V_39 = V_38 ( V_2 ) ;
struct V_26 * V_27 = & V_39 -> V_37 . V_34 . V_27 ;
struct V_16 * V_48 =
& V_27 -> V_28 [ V_27 -> V_49 & ( V_30 - 1 ) ] ;
if ( ( ! ! ( V_48 -> V_25 & 0x80 ) ) ^
( ! ! ( V_27 -> V_49 & V_30 ) ) ) {
F_12 ( V_2 , L_5
L_6 , V_40 ) ;
return;
}
memcpy ( V_48 , V_24 , sizeof( struct V_16 ) - 1 ) ;
V_48 -> V_42 = V_40 ;
F_14 () ;
V_48 -> V_25 = ! ! ( V_27 -> V_49 & V_30 ) ? 0x0 : 0x80 ;
++ V_27 -> V_49 ;
F_15 ( V_39 -> V_37 . V_34 . V_50 ,
& V_39 -> V_37 . V_34 . V_35 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_40 ,
struct V_16 * V_24 )
{
struct V_38 * V_39 = V_38 ( V_2 ) ;
struct V_51 * V_52 =
& V_39 -> V_37 . V_34 . V_46 [ V_40 ] ;
if ( ! V_52 -> V_47 ) {
return;
}
F_13 ( V_2 , V_40 , V_24 ) ;
}
void F_17 ( struct V_31 * V_32 )
{
struct V_33 * V_34 =
F_10 ( V_32 , struct V_33 ,
V_53 ) ;
struct V_36 * V_37 =
F_10 ( V_34 , struct V_36 , V_34 ) ;
struct V_38 * V_39 =
F_10 ( V_37 , struct V_38 , V_37 ) ;
struct V_1 * V_2 = & V_39 -> V_2 ;
struct V_51 * V_46 = V_39 -> V_37 . V_34 . V_46 ;
int V_41 ;
int V_54 ;
F_18 ( V_2 , L_7 ) ;
for ( V_41 = 0 ; V_41 < V_2 -> V_44 ; V_41 ++ ) {
if ( V_55 == V_46 [ V_41 ] . V_56 ) {
F_18 ( V_2 , L_8
L_9 , V_41 ) ;
F_19 ( V_2 , V_41 ) ;
F_20 ( & V_39 -> V_37 . V_34 . V_57 ) ;
V_46 [ V_41 ] . V_56 = V_58 ;
V_46 [ V_41 ] . V_59 = 0 ;
F_21 ( & V_39 -> V_37 . V_34 . V_57 ) ;
V_54 = F_22 ( V_2 , 0 , V_41 , 0 , V_60 ,
V_61 , V_62 ) ;
if ( V_54 )
F_12 ( V_2 , L_10
L_11 , V_41 ) ;
}
}
}
static int F_23 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_38 * V_39 = V_38 ( V_2 ) ;
struct V_16 * V_24 ;
int V_63 ;
int V_64 = 0 ;
int V_65 = 0 ;
int V_66 ;
int V_40 = 0 ;
int V_67 ;
V_13 V_68 ;
T_2 V_69 ;
int V_41 ;
while ( ( V_24 = F_7 ( V_10 ) ) ) {
F_24 () ;
switch ( V_24 -> type ) {
case V_70 :
V_63 = F_25 ( V_24 -> V_71 . V_72 . V_63 ) & 0xffffff ;
F_26 ( V_2 , V_63 ) ;
break;
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
F_18 ( V_2 , L_12 , V_24 -> type ) ;
if ( F_27 ( V_2 ) ) {
V_67 = F_28 ( V_2 ,
V_81 ,
F_25 ( V_24 -> V_71 . V_82 . V_83 )
& 0xffffff , & V_40 ) ;
if ( V_67 && V_67 != - V_84 ) {
F_18 ( V_2 , L_13
L_14
L_15 ,
V_24 -> type , V_24 -> V_85 ,
V_10 -> V_86 , V_10 -> V_14 , V_67 ) ;
break;
}
if ( ! V_67 && V_40 != V_2 -> V_5 . V_45 ) {
F_16 ( V_2 , V_40 , V_24 ) ;
break;
}
}
F_29 ( V_2 , F_25 ( V_24 -> V_71 . V_82 . V_83 ) &
0xffffff , V_24 -> type ) ;
break;
case V_87 :
F_12 ( V_2 , L_16 ,
V_88 ) ;
case V_89 :
if ( F_27 ( V_2 ) ) {
V_67 = F_28 ( V_2 ,
V_90 ,
F_25 ( V_24 -> V_71 . V_91 . V_92 )
& 0xffffff ,
& V_40 ) ;
if ( V_67 && V_67 != - V_84 ) {
F_12 ( V_2 , L_17
L_18
L_19 ,
V_24 -> type , V_24 -> V_85 ,
V_10 -> V_86 , V_10 -> V_14 , V_67 ) ;
break;
}
F_12 ( V_2 , L_20
L_21 , V_88 ,
V_40 ,
F_25 ( V_24 -> V_71 . V_91 . V_92 ) ,
V_24 -> type , V_24 -> V_85 ) ;
if ( ! V_67 && V_40 != V_2 -> V_5 . V_45 ) {
F_12 ( V_2 , L_22
L_23 ,
V_88 , V_24 -> type ,
V_24 -> V_85 , V_40 ) ;
F_16 ( V_2 , V_40 , V_24 ) ;
break;
}
}
F_30 ( V_2 , F_25 ( V_24 -> V_71 . V_91 . V_92 ) &
0xffffff , V_24 -> type ) ;
break;
case V_93 :
F_31 ( V_2 ,
F_32 ( V_24 -> V_71 . V_94 . V_95 ) ,
V_24 -> V_71 . V_94 . V_96 ,
F_33 ( V_24 -> V_71 . V_94 . V_97 ) ) ;
break;
case V_98 :
V_66 = F_25 ( V_24 -> V_71 . V_99 . V_66 ) >> 28 ;
if ( V_24 -> V_85 == V_100 ) {
F_34 ( V_2 ,
V_101 ,
V_66 ) ;
V_38 ( V_2 ) -> V_102 . V_103 [ V_66 ] = 1 ;
if ( F_27 ( V_2 ) )
for ( V_41 = 0 ; V_41 < V_2 -> V_44 ; V_41 ++ ) {
F_18 ( V_2 , L_24
L_25
L_26 ,
V_88 , V_41 , V_66 ) ;
if ( V_41 == V_2 -> V_5 . V_45 )
continue;
F_16 ( V_2 , V_41 , V_24 ) ;
}
} else {
F_34 ( V_2 ,
V_104 ,
V_66 ) ;
V_38 ( V_2 ) -> V_102 . V_103 [ V_66 ] = 0 ;
if ( F_27 ( V_2 ) ) {
for ( V_41 = 0 ; V_41 < V_2 -> V_44 ; V_41 ++ ) {
if ( V_41 == V_2 -> V_5 . V_45 )
continue;
F_16 ( V_2 , V_41 , V_24 ) ;
}
}
}
break;
case V_105 :
F_12 ( V_2 , L_27 ,
V_24 -> V_71 . V_106 . V_107 == 1 ?
L_28 : L_29 ,
F_25 ( V_24 -> V_71 . V_106 . V_63 ) & 0xffffff ) ;
if ( F_27 ( V_2 ) ) {
V_67 = F_28 ( V_2 ,
V_108 ,
F_25 ( V_24 -> V_71 . V_106 . V_63 )
& 0xffffff , & V_40 ) ;
if ( V_67 && V_67 != - V_84 ) {
F_18 ( V_2 , L_30
L_14
L_15 ,
V_24 -> type , V_24 -> V_85 ,
V_10 -> V_86 , V_10 -> V_14 , V_67 ) ;
break;
}
if ( ! V_67 && V_40 != V_2 -> V_5 . V_45 ) {
F_16 ( V_2 , V_40 , V_24 ) ;
break;
}
}
F_35 ( V_2 ,
F_25 ( V_24 -> V_71 . V_106 . V_63 )
& 0xffffff ,
V_24 -> type ) ;
break;
case V_109 :
F_12 ( V_2 , L_31 , V_10 -> V_86 ) ;
break;
case V_110 :
if ( ! F_27 ( V_2 ) ) {
F_12 ( V_2 , L_32
L_33 ) ;
break;
}
memcpy ( & V_39 -> V_37 . V_34 . V_111 ,
V_24 -> V_71 . V_112 . V_113 ,
sizeof V_24 -> V_71 . V_112 . V_113 ) ;
F_15 ( V_39 -> V_37 . V_34 . V_50 ,
& V_39 -> V_37 . V_34 . V_114 ) ;
break;
case V_115 :
V_68 = F_25 ( V_24 -> V_71 . V_116 . V_42 ) ;
if ( ! F_27 ( V_2 ) ) {
F_12 ( V_2 , L_34
L_35 ) ;
break;
}
F_18 ( V_2 , L_36 , V_68 ) ;
if ( V_68 >= V_2 -> V_44 ) {
F_12 ( V_2 ,
L_37 ,
V_68 ) ;
V_69 = 0 ;
} else
V_69 = 1 ;
F_20 ( & V_39 -> V_37 . V_34 . V_57 ) ;
if ( V_69 ) {
V_39 -> V_37 . V_34 . V_46 [ V_68 ] . V_47 = false ;
V_39 -> V_37 . V_34 . V_46 [ V_68 ] . V_56 = V_55 ;
V_39 -> V_37 . V_34 . V_46 [ V_68 ] . V_59 = 1 ;
}
F_21 ( & V_39 -> V_37 . V_34 . V_57 ) ;
F_15 ( V_39 -> V_37 . V_34 . V_50 ,
& V_39 -> V_37 . V_34 . V_53 ) ;
break;
case V_117 :
if ( V_24 -> V_85 == V_118 ) {
if ( F_27 ( V_2 ) )
for ( V_41 = 0 ; V_41 < V_2 -> V_44 ; V_41 ++ ) {
F_18 ( V_2 , L_24
L_38
L_39 , V_88 , V_41 ) ;
if ( V_41 == V_2 -> V_5 . V_45 )
continue;
F_16 ( V_2 , V_41 , V_24 ) ;
}
F_36 ( V_2 , L_40
L_41
L_42 ,
F_32 ( V_24 -> V_71 . V_119 . V_120 ) ,
F_32 ( V_24 -> V_71 . V_119 . V_121 ) ) ;
} else
F_12 ( V_2 , L_43
L_44
L_45 ,
V_24 -> type , V_24 -> V_85 , V_10 -> V_86 ,
V_10 -> V_14 , V_24 -> V_25 , V_10 -> V_19 ,
V_24 -> V_42 ,
! ! ( V_24 -> V_25 & 0x80 ) ^
! ! ( V_10 -> V_14 & V_10 -> V_19 ) ? L_46 : L_47 ) ;
break;
case V_8 :
F_34 ( V_2 , V_122 ,
( unsigned long ) V_24 ) ;
break;
case V_123 :
case V_124 :
default:
F_12 ( V_2 , L_48
L_49
L_50 ,
V_24 -> type , V_24 -> V_85 , V_10 -> V_86 ,
V_10 -> V_14 , V_24 -> V_25 , V_10 -> V_19 ,
V_24 -> V_42 ,
! ! ( V_24 -> V_25 & 0x80 ) ^
! ! ( V_10 -> V_14 & V_10 -> V_19 ) ? L_46 : L_47 ) ;
break;
} ;
++ V_10 -> V_14 ;
V_64 = 1 ;
++ V_65 ;
if ( F_37 ( V_65 >= V_125 ) ) {
F_2 ( V_10 , 0 ) ;
V_65 = 0 ;
}
}
F_2 ( V_10 , 1 ) ;
return V_64 ;
}
static T_3 F_38 ( int V_126 , void * V_127 )
{
struct V_1 * V_2 = V_127 ;
struct V_38 * V_39 = V_38 ( V_2 ) ;
int V_32 = 0 ;
int V_41 ;
F_39 ( V_39 -> V_128 . V_129 , V_39 -> V_128 . V_130 ) ;
for ( V_41 = 0 ; V_41 < V_2 -> V_5 . V_131 + 1 ; ++ V_41 )
V_32 |= F_23 ( V_2 , & V_39 -> V_128 . V_10 [ V_41 ] ) ;
return F_40 ( V_32 ) ;
}
static T_3 F_41 ( int V_126 , void * V_132 )
{
struct V_9 * V_10 = V_132 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_23 ( V_2 , V_10 ) ;
return V_133 ;
}
int F_42 ( struct V_1 * V_2 , int V_40 ,
struct V_134 * V_135 ,
struct V_136 * V_137 ,
struct V_136 * V_138 ,
struct V_139 * V_94 )
{
struct V_38 * V_39 = V_38 ( V_2 ) ;
struct V_140 * V_141 =
V_39 -> V_37 . V_34 . V_46 [ V_40 ] . V_141 ;
V_13 V_142 = V_135 -> V_142 ;
V_13 V_86 = V_142 & 0x1FF ;
T_1 V_143 = V_135 -> V_143 ;
int V_54 = 0 ;
int V_41 ;
if ( V_40 == V_2 -> V_5 . V_45 )
V_54 = F_22 ( V_2 , V_143 , ( V_142 & 0x80000000 ) | V_86 ,
0 , V_144 , V_145 ,
V_146 ) ;
if ( ! V_54 )
for ( V_41 = 0 ; V_41 < V_147 ; ++ V_41 )
if ( V_143 & ( 1LL << V_41 ) )
V_141 [ V_41 ] . V_86 = V_142 >> 31 ? - 1 : V_86 ;
return V_54 ;
}
static int F_43 ( struct V_1 * V_2 , T_1 V_148 , int V_149 ,
int V_150 )
{
return F_22 ( V_2 , V_148 , ( V_149 << 31 ) | V_150 ,
0 , V_144 , V_145 ,
V_62 ) ;
}
static int F_44 ( struct V_1 * V_2 , struct V_136 * V_151 ,
int V_150 )
{
return F_22 ( V_2 , V_151 -> V_152 , V_150 , 0 ,
V_153 , V_61 ,
V_62 ) ;
}
static int F_45 ( struct V_1 * V_2 , struct V_136 * V_151 ,
int V_150 )
{
return F_46 ( V_2 , 0 , V_151 -> V_152 , V_150 ,
0 , V_154 , V_61 ,
V_62 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_131 + 1 + V_2 -> V_5 . V_155 +
V_2 -> V_5 . V_156 ) / 4 - V_2 -> V_5 . V_155 / 4 + 1 ;
}
static void T_4 * F_48 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_38 * V_39 = V_38 ( V_2 ) ;
int V_157 ;
V_157 = V_10 -> V_86 / 4 - V_2 -> V_5 . V_155 / 4 ;
if ( ! V_39 -> V_128 . V_158 [ V_157 ] ) {
V_39 -> V_128 . V_158 [ V_157 ] =
F_49 ( F_50 ( V_2 -> V_159 , 2 ) +
( ( V_10 -> V_86 / 4 ) << V_160 ) ,
V_22 ) ;
if ( ! V_39 -> V_128 . V_158 [ V_157 ] ) {
F_36 ( V_2 , L_51 ,
V_10 -> V_86 ) ;
return NULL ;
}
}
return V_39 -> V_128 . V_158 [ V_157 ] + 0x800 + 8 * ( V_10 -> V_86 % 4 ) ;
}
static int F_51 ( struct V_1 * V_2 , int V_19 ,
T_2 V_161 , struct V_9 * V_10 )
{
struct V_38 * V_39 = V_38 ( V_2 ) ;
struct V_136 * V_151 ;
struct V_162 * V_163 ;
int V_164 ;
T_1 * V_165 = NULL ;
T_5 V_166 ;
T_1 V_167 ;
int V_54 = - V_168 ;
int V_41 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_19 = F_52 ( F_53 ( V_19 , 2 ) ) ;
V_164 = F_54 ( V_10 -> V_19 * V_20 ) / V_22 ;
V_10 -> V_21 = F_55 ( V_164 * sizeof * V_10 -> V_21 ,
V_169 ) ;
if ( ! V_10 -> V_21 )
goto V_170;
for ( V_41 = 0 ; V_41 < V_164 ; ++ V_41 )
V_10 -> V_21 [ V_41 ] . V_23 = NULL ;
V_165 = F_55 ( V_164 * sizeof *V_165 , V_169 ) ;
if ( ! V_165 )
goto V_171;
V_151 = F_56 ( V_2 ) ;
if ( F_57 ( V_151 ) )
goto V_171;
V_163 = V_151 -> V_23 ;
for ( V_41 = 0 ; V_41 < V_164 ; ++ V_41 ) {
V_10 -> V_21 [ V_41 ] . V_23 = F_58 ( & V_2 -> V_159 -> V_2 ,
V_22 , & V_166 , V_169 ) ;
if ( ! V_10 -> V_21 [ V_41 ] . V_23 )
goto V_172;
V_165 [ V_41 ] = V_166 ;
V_10 -> V_21 [ V_41 ] . V_173 = V_166 ;
memset ( V_10 -> V_21 [ V_41 ] . V_23 , 0 , V_22 ) ;
}
V_10 -> V_86 = F_59 ( & V_39 -> V_128 . V_174 ) ;
if ( V_10 -> V_86 == - 1 )
goto V_172;
V_10 -> V_15 = F_48 ( V_2 , V_10 ) ;
if ( ! V_10 -> V_15 ) {
V_54 = - V_168 ;
goto V_175;
}
V_54 = F_60 ( V_2 , V_164 , V_160 , & V_10 -> V_176 ) ;
if ( V_54 )
goto V_175;
V_54 = F_61 ( V_2 , & V_10 -> V_176 , 0 , V_164 , V_165 ) ;
if ( V_54 )
goto V_177;
memset ( V_163 , 0 , sizeof *V_163 ) ;
V_163 -> V_6 = F_4 ( V_178 |
V_179 ) ;
V_163 -> V_180 = F_62 ( V_10 -> V_19 ) ;
V_163 -> V_161 = V_161 ;
V_163 -> V_181 = V_160 - V_182 ;
V_167 = F_63 ( V_2 , & V_10 -> V_176 ) ;
V_163 -> V_183 = V_167 >> 32 ;
V_163 -> V_184 = F_4 ( V_167 & 0xffffffff ) ;
V_54 = F_44 ( V_2 , V_151 , V_10 -> V_86 ) ;
if ( V_54 ) {
F_12 ( V_2 , L_52 , V_54 ) ;
goto V_177;
}
F_64 ( V_165 ) ;
F_65 ( V_2 , V_151 ) ;
V_10 -> V_14 = 0 ;
return V_54 ;
V_177:
F_66 ( V_2 , & V_10 -> V_176 ) ;
V_175:
F_67 ( & V_39 -> V_128 . V_174 , V_10 -> V_86 ) ;
V_172:
for ( V_41 = 0 ; V_41 < V_164 ; ++ V_41 )
if ( V_10 -> V_21 [ V_41 ] . V_23 )
F_68 ( & V_2 -> V_159 -> V_2 , V_22 ,
V_10 -> V_21 [ V_41 ] . V_23 ,
V_10 -> V_21 [ V_41 ] . V_173 ) ;
F_65 ( V_2 , V_151 ) ;
V_171:
F_64 ( V_10 -> V_21 ) ;
F_64 ( V_165 ) ;
V_170:
return V_54 ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_38 * V_39 = V_38 ( V_2 ) ;
struct V_136 * V_151 ;
int V_54 ;
int V_164 = F_54 ( V_20 * V_10 -> V_19 ) / V_22 ;
int V_41 ;
V_151 = F_56 ( V_2 ) ;
if ( F_57 ( V_151 ) )
return;
V_54 = F_45 ( V_2 , V_151 , V_10 -> V_86 ) ;
if ( V_54 )
F_12 ( V_2 , L_53 , V_54 ) ;
if ( 0 ) {
F_18 ( V_2 , L_54 , V_10 -> V_86 ) ;
for ( V_41 = 0 ; V_41 < sizeof ( struct V_162 ) / 4 ; ++ V_41 ) {
if ( V_41 % 4 == 0 )
F_70 ( L_55 , V_41 * 4 ) ;
F_70 ( L_56 , F_71 ( V_151 -> V_23 + V_41 * 4 ) ) ;
if ( ( V_41 + 1 ) % 4 == 0 )
F_70 ( L_57 ) ;
}
}
F_66 ( V_2 , & V_10 -> V_176 ) ;
for ( V_41 = 0 ; V_41 < V_164 ; ++ V_41 )
F_68 ( & V_2 -> V_159 -> V_2 , V_22 ,
V_10 -> V_21 [ V_41 ] . V_23 ,
V_10 -> V_21 [ V_41 ] . V_173 ) ;
F_64 ( V_10 -> V_21 ) ;
F_67 ( & V_39 -> V_128 . V_174 , V_10 -> V_86 ) ;
F_65 ( V_2 , V_151 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_185 * V_128 = & V_38 ( V_2 ) -> V_128 ;
struct V_38 * V_39 = V_38 ( V_2 ) ;
int V_41 , V_186 ;
if ( V_128 -> V_187 )
F_73 ( V_2 -> V_159 -> V_126 , V_2 ) ;
for ( V_41 = 0 ; V_41 < V_2 -> V_5 . V_131 + 1 ; ++ V_41 )
if ( V_128 -> V_10 [ V_41 ] . V_187 ) {
F_73 ( V_128 -> V_10 [ V_41 ] . V_126 , V_128 -> V_10 + V_41 ) ;
V_128 -> V_10 [ V_41 ] . V_187 = 0 ;
}
for ( V_41 = 0 ; V_41 < V_2 -> V_5 . V_156 ; V_41 ++ ) {
if ( V_39 -> V_188 . V_189 & 1ULL << V_41 ) {
V_186 = V_2 -> V_5 . V_131 + 1 + V_41 ;
F_73 ( V_39 -> V_128 . V_10 [ V_186 ] . V_126 ,
& V_39 -> V_128 . V_10 [ V_186 ] ) ;
}
}
F_64 ( V_128 -> V_190 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_38 ( V_2 ) ;
V_39 -> V_191 = F_49 ( F_50 ( V_2 -> V_159 , V_39 -> V_192 . V_193 ) +
V_39 -> V_192 . V_194 , V_195 ) ;
if ( ! V_39 -> V_191 ) {
F_36 ( V_2 , L_58 ) ;
return - V_168 ;
}
return 0 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_38 ( V_2 ) ;
F_76 ( V_39 -> V_191 ) ;
}
int F_77 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_38 ( V_2 ) ;
V_39 -> V_128 . V_10 = F_78 ( V_2 -> V_5 . V_196 - V_2 -> V_5 . V_155 ,
sizeof * V_39 -> V_128 . V_10 , V_169 ) ;
if ( ! V_39 -> V_128 . V_10 )
return - V_168 ;
return 0 ;
}
void F_79 ( struct V_1 * V_2 )
{
F_64 ( V_38 ( V_2 ) -> V_128 . V_10 ) ;
}
int F_80 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_38 ( V_2 ) ;
int V_54 ;
int V_41 ;
V_39 -> V_128 . V_158 = F_78 ( F_47 ( V_2 ) ,
sizeof * V_39 -> V_128 . V_158 ,
V_169 ) ;
if ( ! V_39 -> V_128 . V_158 ) {
V_54 = - V_168 ;
goto V_171;
}
V_54 = F_81 ( & V_39 -> V_128 . V_174 , V_2 -> V_5 . V_196 ,
V_2 -> V_5 . V_196 - 1 , V_2 -> V_5 . V_155 , 0 ) ;
if ( V_54 )
goto V_171;
for ( V_41 = 0 ; V_41 < F_47 ( V_2 ) ; ++ V_41 )
V_39 -> V_128 . V_158 [ V_41 ] = NULL ;
if ( ! F_82 ( V_2 ) ) {
V_54 = F_74 ( V_2 ) ;
if ( V_54 )
goto V_197;
V_39 -> V_128 . V_129 =
F_83 ( 1 << ( V_39 -> V_128 . V_198 & 31 ) ) ;
V_39 -> V_128 . V_130 = V_39 -> V_191 +
( V_39 -> V_128 . V_198 < 32 ? 4 : 0 ) ;
}
V_39 -> V_128 . V_190 =
F_55 ( V_199 * ( V_2 -> V_5 . V_131 + 1 +
V_2 -> V_5 . V_156 ) ,
V_169 ) ;
if ( ! V_39 -> V_128 . V_190 ) {
V_54 = - V_168 ;
goto V_197;
}
for ( V_41 = 0 ; V_41 < V_2 -> V_5 . V_131 ; ++ V_41 ) {
V_54 = F_51 ( V_2 , V_2 -> V_5 . V_200 -
V_2 -> V_5 . V_201 +
V_125 ,
( V_2 -> V_6 & V_202 ) ? V_41 : 0 ,
& V_39 -> V_128 . V_10 [ V_41 ] ) ;
if ( V_54 ) {
-- V_41 ;
goto V_203;
}
}
V_54 = F_51 ( V_2 , V_204 + V_125 ,
( V_2 -> V_6 & V_202 ) ? V_2 -> V_5 . V_131 : 0 ,
& V_39 -> V_128 . V_10 [ V_2 -> V_5 . V_131 ] ) ;
if ( V_54 )
goto V_205;
for ( V_41 = V_2 -> V_5 . V_131 + 1 ;
V_41 < V_2 -> V_5 . V_131 + V_2 -> V_5 . V_156 + 1 ; ++ V_41 ) {
V_54 = F_51 ( V_2 , V_2 -> V_5 . V_200 -
V_2 -> V_5 . V_201 +
V_125 ,
( V_2 -> V_6 & V_202 ) ? V_41 : 0 ,
& V_39 -> V_128 . V_10 [ V_41 ] ) ;
if ( V_54 ) {
-- V_41 ;
goto V_203;
}
}
if ( V_2 -> V_6 & V_202 ) {
const char * V_206 ;
for ( V_41 = 0 ; V_41 < V_2 -> V_5 . V_131 + 1 ; ++ V_41 ) {
if ( V_41 < V_2 -> V_5 . V_131 ) {
snprintf ( V_39 -> V_128 . V_190 +
V_41 * V_199 ,
V_199 ,
L_59 , V_41 ,
F_84 ( V_2 -> V_159 ) ) ;
} else {
snprintf ( V_39 -> V_128 . V_190 +
V_41 * V_199 ,
V_199 ,
L_60 ,
F_84 ( V_2 -> V_159 ) ) ;
}
V_206 = V_39 -> V_128 . V_190 +
V_41 * V_199 ;
V_54 = F_85 ( V_39 -> V_128 . V_10 [ V_41 ] . V_126 ,
F_41 , 0 , V_206 ,
V_39 -> V_128 . V_10 + V_41 ) ;
if ( V_54 )
goto V_207;
V_39 -> V_128 . V_10 [ V_41 ] . V_187 = 1 ;
}
} else {
snprintf ( V_39 -> V_128 . V_190 ,
V_199 ,
V_208 L_61 ,
F_84 ( V_2 -> V_159 ) ) ;
V_54 = F_85 ( V_2 -> V_159 -> V_126 , F_38 ,
V_209 , V_39 -> V_128 . V_190 , V_2 ) ;
if ( V_54 )
goto V_207;
V_39 -> V_128 . V_187 = 1 ;
}
V_54 = F_43 ( V_2 , F_1 ( V_2 ) , 0 ,
V_39 -> V_128 . V_10 [ V_2 -> V_5 . V_131 ] . V_86 ) ;
if ( V_54 )
F_12 ( V_2 , L_62 ,
V_39 -> V_128 . V_10 [ V_2 -> V_5 . V_131 ] . V_86 , V_54 ) ;
for ( V_41 = 0 ; V_41 < V_2 -> V_5 . V_131 + 1 ; ++ V_41 )
F_2 ( & V_39 -> V_128 . V_10 [ V_41 ] , 1 ) ;
return 0 ;
V_207:
F_69 ( V_2 , & V_39 -> V_128 . V_10 [ V_2 -> V_5 . V_131 ] ) ;
V_205:
V_41 = V_2 -> V_5 . V_131 - 1 ;
V_203:
while ( V_41 >= 0 ) {
F_69 ( V_2 , & V_39 -> V_128 . V_10 [ V_41 ] ) ;
-- V_41 ;
}
if ( ! F_82 ( V_2 ) )
F_75 ( V_2 ) ;
F_72 ( V_2 ) ;
V_197:
F_86 ( & V_39 -> V_128 . V_174 ) ;
V_171:
F_64 ( V_39 -> V_128 . V_158 ) ;
return V_54 ;
}
void F_87 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_38 ( V_2 ) ;
int V_41 ;
F_43 ( V_2 , F_1 ( V_2 ) , 1 ,
V_39 -> V_128 . V_10 [ V_2 -> V_5 . V_131 ] . V_86 ) ;
F_72 ( V_2 ) ;
for ( V_41 = 0 ; V_41 < V_2 -> V_5 . V_131 + V_2 -> V_5 . V_156 + 1 ; ++ V_41 )
F_69 ( V_2 , & V_39 -> V_128 . V_10 [ V_41 ] ) ;
if ( ! F_82 ( V_2 ) )
F_75 ( V_2 ) ;
for ( V_41 = 0 ; V_41 < F_47 ( V_2 ) ; ++ V_41 )
if ( V_39 -> V_128 . V_158 [ V_41 ] )
F_76 ( V_39 -> V_128 . V_158 [ V_41 ] ) ;
F_86 ( & V_39 -> V_128 . V_174 ) ;
F_64 ( V_39 -> V_128 . V_158 ) ;
}
int F_88 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = V_38 ( V_2 ) ;
int V_41 ;
int V_54 ;
V_54 = F_89 ( V_2 ) ;
if ( ! ( V_2 -> V_6 & V_202 ) || F_82 ( V_2 ) )
return V_54 ;
for( V_41 = 0 ; ! V_54 && ( V_41 < V_2 -> V_5 . V_131 ) ; ++ V_41 ) {
F_90 ( V_2 ) ;
V_54 = F_43 ( V_2 , F_1 ( V_2 ) , 0 ,
V_39 -> V_128 . V_10 [ V_41 ] . V_86 ) ;
if ( V_54 ) {
F_12 ( V_2 , L_63 ) ;
F_91 ( V_2 ) ;
break;
}
F_91 ( V_2 ) ;
V_54 = F_89 ( V_2 ) ;
}
F_43 ( V_2 , F_1 ( V_2 ) , 0 ,
V_39 -> V_128 . V_10 [ V_2 -> V_5 . V_131 ] . V_86 ) ;
return V_54 ;
}
int F_92 ( struct V_1 * V_2 , char * V_210 , struct V_211 * V_212 ,
int * V_213 )
{
struct V_38 * V_39 = V_38 ( V_2 ) ;
int V_186 = 0 , V_54 = 0 , V_41 ;
F_93 ( & V_39 -> V_188 . V_214 ) ;
for ( V_41 = 0 ; ! V_186 && V_41 < V_2 -> V_5 . V_156 ; V_41 ++ ) {
if ( ~ V_39 -> V_188 . V_189 & 1ULL << V_41 ) {
V_39 -> V_188 . V_189 |= 1ULL << V_41 ;
V_186 = V_2 -> V_5 . V_131 + 1 + V_41 ;
snprintf ( V_39 -> V_128 . V_190 +
V_186 * V_199 ,
V_199 , L_64 , V_210 ) ;
#ifdef F_94
if ( V_212 ) {
V_54 = F_95 ( V_212 ,
V_39 -> V_128 . V_10 [ V_186 ] . V_126 ) ;
if ( V_54 )
F_12 ( V_2 , L_65 ) ;
}
#endif
V_54 = F_85 ( V_39 -> V_128 . V_10 [ V_186 ] . V_126 ,
F_41 , 0 ,
& V_39 -> V_128 . V_190 [ V_186 << 5 ] ,
V_39 -> V_128 . V_10 + V_186 ) ;
if ( V_54 ) {
V_39 -> V_188 . V_189 ^= 1 << V_41 ;
V_186 = 0 ;
continue;
}
F_2 ( & V_39 -> V_128 . V_10 [ V_186 ] , 1 ) ;
}
}
F_96 ( & V_39 -> V_188 . V_214 ) ;
if ( V_186 ) {
* V_213 = V_186 ;
} else {
* V_213 = 0 ;
V_54 = ( V_41 == V_2 -> V_5 . V_156 ) ? - V_215 : V_54 ;
}
return V_54 ;
}
void F_97 ( struct V_1 * V_2 , int V_186 )
{
struct V_38 * V_39 = V_38 ( V_2 ) ;
int V_41 = V_186 - V_2 -> V_5 . V_131 - 1 ;
if ( F_98 ( V_41 >= 0 ) ) {
F_93 ( & V_39 -> V_188 . V_214 ) ;
if ( V_39 -> V_188 . V_189 & 1ULL << V_41 ) {
F_73 ( V_39 -> V_128 . V_10 [ V_186 ] . V_126 ,
& V_39 -> V_128 . V_10 [ V_186 ] ) ;
V_39 -> V_188 . V_189 &= ~ ( 1ULL << V_41 ) ;
}
F_96 ( & V_39 -> V_188 . V_214 ) ;
}
}
