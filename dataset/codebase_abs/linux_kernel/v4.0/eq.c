static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
if ( V_2 -> V_5 . V_6 & V_7 )
V_3 |= ( 1ull << V_8 ) ;
if ( V_2 -> V_5 . V_9 & V_10 )
V_3 |= ( 1ull << V_11 ) ;
return V_3 ;
}
static void F_2 ( struct V_12 * V_13 , int V_14 )
{
F_3 ( ( V_15 V_16 ) F_4 ( ( V_13 -> V_17 & 0xffffff ) |
V_14 << 31 ) ,
V_13 -> V_18 ) ;
F_5 () ;
}
static struct V_19 * F_6 ( struct V_12 * V_13 , V_16 V_20 , T_2 V_21 ,
T_2 V_22 )
{
unsigned long V_23 = ( V_20 & ( V_13 -> V_24 - 1 ) ) * V_22 ;
return V_13 -> V_25 [ V_23 / V_26 ] . V_27 + ( V_23 + ( V_21 ? V_28 : 0 ) ) % V_26 ;
}
static struct V_19 * F_7 ( struct V_12 * V_13 , T_2 V_21 , T_2 V_29 )
{
struct V_19 * V_30 = F_6 ( V_13 , V_13 -> V_17 , V_21 , V_29 ) ;
return ! ! ( V_30 -> V_31 & 0x80 ) ^ ! ! ( V_13 -> V_17 & V_13 -> V_24 ) ? NULL : V_30 ;
}
static struct V_19 * F_8 ( struct V_32 * V_33 )
{
struct V_19 * V_30 =
& V_33 -> V_34 [ V_33 -> V_35 & ( V_36 - 1 ) ] ;
return ( ! ! ( V_30 -> V_31 & 0x80 ) ^
! ! ( V_33 -> V_35 & V_36 ) ) ?
V_30 : NULL ;
}
void F_9 ( struct V_37 * V_38 )
{
struct V_39 * V_40 =
F_10 ( V_38 , struct V_39 ,
V_41 ) ;
struct V_42 * V_43 =
F_10 ( V_40 , struct V_42 , V_40 ) ;
struct V_44 * V_45 = F_10 ( V_43 , struct V_44 , V_43 ) ;
struct V_1 * V_2 = & V_45 -> V_2 ;
struct V_32 * V_33 = & V_43 -> V_40 . V_33 ;
struct V_19 * V_30 ;
T_2 V_46 ;
int V_47 ;
for ( V_30 = F_8 ( V_33 ) ; V_30 ;
V_30 = F_8 ( V_33 ) ) {
V_46 = V_30 -> V_48 ;
if ( V_46 == V_49 ) {
for ( V_47 = 0 ; V_47 <= V_2 -> V_50 -> V_51 ; V_47 ++ ) {
if ( F_11 ( V_2 , V_47 , V_30 ) )
F_12 ( V_2 , L_1 ,
V_47 ) ;
}
} else {
if ( F_11 ( V_2 , V_46 , V_30 ) )
F_12 ( V_2 , L_1 ,
V_46 ) ;
}
++ V_33 -> V_35 ;
}
}
static void F_13 ( struct V_1 * V_2 , T_2 V_46 , struct V_19 * V_30 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
struct V_32 * V_33 = & V_45 -> V_43 . V_40 . V_33 ;
struct V_19 * V_52 ;
unsigned long V_6 ;
F_14 ( & V_33 -> V_53 , V_6 ) ;
V_52 = & V_33 -> V_34 [ V_33 -> V_54 & ( V_36 - 1 ) ] ;
if ( ( ! ! ( V_52 -> V_31 & 0x80 ) ) ^
( ! ! ( V_33 -> V_54 & V_36 ) ) ) {
F_12 ( V_2 , L_2 ,
V_46 ) ;
F_15 ( & V_33 -> V_53 , V_6 ) ;
return;
}
memcpy ( V_52 , V_30 , V_2 -> V_5 . V_22 - 1 ) ;
V_52 -> V_48 = V_46 ;
F_16 () ;
V_52 -> V_31 = ! ! ( V_33 -> V_54 & V_36 ) ? 0x0 : 0x80 ;
++ V_33 -> V_54 ;
F_17 ( V_45 -> V_43 . V_40 . V_55 ,
& V_45 -> V_43 . V_40 . V_41 ) ;
F_15 ( & V_33 -> V_53 , V_6 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_46 ,
struct V_19 * V_30 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
if ( V_46 < 0 || V_46 > V_2 -> V_50 -> V_51 ||
V_46 == V_2 -> V_5 . V_56 ||
! V_45 -> V_43 . V_40 . V_57 [ V_46 ] . V_58 )
return;
F_13 ( V_2 , V_46 , V_30 ) ;
}
int F_19 ( struct V_1 * V_2 , int V_46 , T_2 V_59 )
{
struct V_19 V_30 ;
struct V_44 * V_45 = V_44 ( V_2 ) ;
struct V_60 * V_61 = & V_45 -> V_43 . V_40 . V_57 [ V_46 ] ;
if ( ! V_61 -> V_58 )
return 0 ;
memset ( & V_30 , 0 , sizeof V_30 ) ;
V_30 . type = V_8 ;
V_30 . V_62 = V_63 ;
V_30 . V_64 . V_65 . V_59 = V_59 ;
return F_11 ( V_2 , V_46 , & V_30 ) ;
}
int F_20 ( struct V_1 * V_2 , int V_46 , T_2 V_59 )
{
struct V_19 V_30 ;
if ( V_2 -> V_50 -> V_51 < V_46 )
return 0 ;
memset ( & V_30 , 0 , sizeof V_30 ) ;
V_30 . type = V_8 ;
V_30 . V_62 = V_66 ;
V_30 . V_64 . V_65 . V_59 = V_59 ;
return F_11 ( V_2 , V_46 , & V_30 ) ;
}
int F_21 ( struct V_1 * V_2 , int V_46 , T_2 V_59 ,
T_2 V_67 )
{
struct V_19 V_30 ;
if ( V_2 -> V_50 -> V_51 < V_46 )
return 0 ;
memset ( & V_30 , 0 , sizeof V_30 ) ;
V_30 . type = V_68 ;
V_30 . V_62 = V_67 ;
V_30 . V_64 . V_69 . V_59 = F_4 ( V_59 << 28 ) ;
F_22 ( V_2 , L_3 , V_70 ,
V_67 , V_46 , V_59 ) ;
return F_11 ( V_2 , V_46 , & V_30 ) ;
}
enum V_71 F_23 ( struct V_1 * V_2 , int V_46 , T_2 V_59 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
struct V_60 * V_72 = V_45 -> V_43 . V_40 . V_57 ;
struct V_73 V_74 = F_24 ( V_2 , V_46 ) ;
if ( V_46 >= V_2 -> V_75 || V_59 > V_2 -> V_5 . V_76 ||
V_59 <= 0 || ! F_25 ( V_59 - 1 , V_74 . V_77 ) ) {
F_26 ( L_4 ,
V_70 , V_46 , V_59 ) ;
return V_78 ;
}
return V_72 [ V_46 ] . V_79 [ V_59 ] ;
}
static int F_27 ( struct V_1 * V_2 , int V_46 , T_2 V_59 ,
enum V_71 V_80 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
struct V_60 * V_72 = V_45 -> V_43 . V_40 . V_57 ;
struct V_73 V_74 = F_24 ( V_2 , V_46 ) ;
if ( V_46 >= V_2 -> V_75 || V_59 > V_2 -> V_5 . V_76 ||
V_59 <= 0 || ! F_25 ( V_59 - 1 , V_74 . V_77 ) ) {
F_26 ( L_4 ,
V_70 , V_46 , V_59 ) ;
return - 1 ;
}
V_72 [ V_46 ] . V_79 [ V_59 ] = V_80 ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 , T_2 V_59 , int V_64 )
{
int V_47 ;
enum V_81 V_82 ;
struct V_83 V_84 = F_29 ( V_2 ,
V_59 ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_50 -> V_51 + 1 ; V_47 ++ )
if ( F_25 ( V_47 , V_84 . V_85 ) )
F_30 ( V_2 , V_47 , V_59 ,
V_64 , & V_82 ) ;
}
int F_30 ( struct V_1 * V_2 , int V_46 ,
T_2 V_59 , int V_64 ,
enum V_81 * V_82 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
struct V_60 * V_86 = NULL ;
unsigned long V_6 ;
int V_87 = - 1 ;
struct V_73 V_74 = F_24 ( V_2 , V_46 ) ;
enum V_71 V_88 =
F_23 ( V_2 , V_46 , V_59 ) ;
* V_82 = V_89 ;
if ( V_46 >= V_2 -> V_75 || V_59 > V_2 -> V_5 . V_76 ||
V_59 <= 0 || ! F_25 ( V_59 - 1 , V_74 . V_77 ) ) {
F_26 ( L_4 ,
V_70 , V_46 , V_59 ) ;
return V_87 ;
}
V_86 = & V_45 -> V_43 . V_40 . V_57 [ V_46 ] ;
F_14 ( & V_86 -> V_90 , V_6 ) ;
switch ( V_88 ) {
case V_78 :
if ( V_91 == V_64 )
F_27 ( V_2 , V_46 , V_59 ,
V_92 ) ;
break;
case V_92 :
if ( V_93 == V_64 )
F_27 ( V_2 , V_46 , V_59 ,
V_78 ) ;
else if ( V_94 == V_64 ) {
F_27 ( V_2 , V_46 , V_59 ,
V_95 ) ;
* V_82 = V_96 ;
}
break;
case V_95 :
if ( V_93 == V_64 ) {
F_27 ( V_2 , V_46 , V_59 ,
V_78 ) ;
* V_82 = V_97 ;
} else if ( V_98 ==
V_64 ) {
F_27 ( V_2 , V_46 , V_59 ,
V_92 ) ;
* V_82 = V_97 ;
}
break;
default:
F_26 ( L_5 ,
V_70 , V_46 , V_59 ) ;
goto V_99;
}
V_87 = F_23 ( V_2 , V_46 , V_59 ) ;
V_99:
F_15 ( & V_86 -> V_90 , V_6 ) ;
return V_87 ;
}
int F_31 ( struct V_1 * V_2 , T_2 V_59 , int V_100 )
{
struct V_19 V_30 ;
memset ( & V_30 , 0 , sizeof V_30 ) ;
V_30 . type = V_8 ;
V_30 . V_62 = V_101 ;
V_30 . V_64 . V_65 . V_59 = V_59 ;
V_30 . V_64 . V_65 . V_102 . V_103 . V_104 =
F_4 ( ( V_16 ) V_100 ) ;
F_13 ( V_2 , V_49 , & V_30 ) ;
return 0 ;
}
void F_32 ( struct V_37 * V_38 )
{
struct V_39 * V_40 =
F_10 ( V_38 , struct V_39 ,
V_105 ) ;
struct V_42 * V_43 =
F_10 ( V_40 , struct V_42 , V_40 ) ;
struct V_44 * V_45 =
F_10 ( V_43 , struct V_44 , V_43 ) ;
struct V_1 * V_2 = & V_45 -> V_2 ;
struct V_60 * V_57 = V_45 -> V_43 . V_40 . V_57 ;
int V_47 ;
int V_106 ;
unsigned long V_6 ;
F_22 ( V_2 , L_6 ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_75 ; V_47 ++ ) {
if ( V_107 == V_57 [ V_47 ] . V_108 ) {
F_22 ( V_2 , L_7 ,
V_47 ) ;
if ( V_2 -> V_50 -> V_109 &
V_110 )
F_33 ( V_2 , V_47 ) ;
F_14 ( & V_45 -> V_43 . V_40 . V_111 , V_6 ) ;
V_57 [ V_47 ] . V_108 = V_112 ;
V_57 [ V_47 ] . V_113 = 0 ;
F_15 ( & V_45 -> V_43 . V_40 . V_111 , V_6 ) ;
V_106 = F_34 ( V_2 , 0 , V_47 , 0 , V_114 ,
V_115 , V_116 ) ;
if ( V_106 )
F_12 ( V_2 , L_8 ,
V_47 ) ;
}
}
}
static int F_35 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
struct V_19 * V_30 ;
int V_117 = - 1 ;
int V_118 = 0 ;
int V_119 = 0 ;
int V_59 ;
int V_46 = 0 ;
int V_87 ;
V_16 V_120 ;
T_2 V_121 ;
int V_47 ;
enum V_81 V_82 ;
unsigned long V_6 ;
struct V_122 * V_123 ;
int V_22 = V_2 -> V_5 . V_22 ;
while ( ( V_30 = F_7 ( V_13 , V_2 -> V_5 . V_21 , V_22 ) ) ) {
F_36 () ;
switch ( V_30 -> type ) {
case V_124 :
V_117 = F_37 ( V_30 -> V_64 . V_125 . V_117 ) & 0xffffff ;
F_38 ( V_2 , V_117 ) ;
break;
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
F_22 ( V_2 , L_9 , V_30 -> type ) ;
if ( F_39 ( V_2 ) ) {
V_87 = F_40 ( V_2 ,
V_134 ,
F_37 ( V_30 -> V_64 . V_135 . V_136 )
& 0xffffff , & V_46 ) ;
if ( V_87 && V_87 != - V_137 ) {
F_22 ( V_2 , L_10 ,
V_30 -> type , V_30 -> V_62 ,
V_13 -> V_138 , V_13 -> V_17 , V_87 ) ;
break;
}
if ( ! V_87 && V_46 != V_2 -> V_5 . V_56 ) {
F_18 ( V_2 , V_46 , V_30 ) ;
break;
}
}
F_41 ( V_2 , F_37 ( V_30 -> V_64 . V_135 . V_136 ) &
0xffffff , V_30 -> type ) ;
break;
case V_139 :
F_22 ( V_2 , L_11 ,
V_70 ) ;
case V_140 :
if ( F_39 ( V_2 ) ) {
V_87 = F_40 ( V_2 ,
V_141 ,
F_37 ( V_30 -> V_64 . V_142 . V_143 )
& 0xffffff ,
& V_46 ) ;
if ( V_87 && V_87 != - V_137 ) {
F_12 ( V_2 , L_12 ,
V_30 -> type , V_30 -> V_62 ,
V_13 -> V_138 , V_13 -> V_17 , V_87 ) ;
break;
}
F_12 ( V_2 , L_13 ,
V_70 , V_46 ,
F_37 ( V_30 -> V_64 . V_142 . V_143 ) ,
V_30 -> type , V_30 -> V_62 ) ;
if ( ! V_87 && V_46 != V_2 -> V_5 . V_56 ) {
F_12 ( V_2 , L_14 ,
V_70 , V_30 -> type ,
V_30 -> V_62 , V_46 ) ;
F_18 ( V_2 , V_46 , V_30 ) ;
break;
}
}
F_42 ( V_2 , F_37 ( V_30 -> V_64 . V_142 . V_143 ) &
0xffffff , V_30 -> type ) ;
break;
case V_144 :
F_43 ( V_2 ,
F_44 ( V_30 -> V_64 . V_145 . V_146 ) ,
V_30 -> V_64 . V_145 . V_147 ,
F_45 ( V_30 -> V_64 . V_145 . V_148 ) ) ;
break;
case V_68 : {
struct V_83 V_149 ;
V_59 = F_37 ( V_30 -> V_64 . V_69 . V_59 ) >> 28 ;
V_149 = F_29 ( V_2 , V_59 ) ;
if ( V_30 -> V_62 == V_150 ) {
F_46 ( V_2 , V_151 ,
V_59 ) ;
V_44 ( V_2 ) -> V_152 . V_153 [ V_59 ] = 1 ;
if ( ! F_39 ( V_2 ) )
break;
for ( V_47 = 0 ; V_47 < V_2 -> V_50 -> V_51 + 1 ;
V_47 ++ ) {
if ( ! F_25 ( V_47 , V_149 . V_85 ) )
continue;
if ( V_2 -> V_5 . V_154 [ V_59 ] == V_155 ) {
if ( V_47 == F_47 ( V_2 ) )
continue;
F_22 ( V_2 , L_15 ,
V_70 , V_47 , V_59 ) ;
V_123 = & V_45 -> V_43 . V_40 . V_156 [ V_46 ] . V_157 [ V_59 ] . V_80 ;
if ( V_158 == V_123 -> V_159 ) {
V_30 -> V_64 . V_69 . V_59 =
F_4 (
( F_37 ( V_30 -> V_64 . V_69 . V_59 ) & 0xFFFFFFF )
| ( F_48 ( V_2 , V_47 , V_59 ) << 28 ) ) ;
F_18 ( V_2 , V_47 , V_30 ) ;
}
} else {
F_30 ( V_2 , V_47 , V_59 ,
V_93 ,
& V_82 ) ;
if ( V_97 == V_82 ) {
if ( V_47 == F_47 ( V_2 ) )
continue;
F_18 ( V_2 , V_47 , V_30 ) ;
}
}
}
} else {
F_46 ( V_2 , V_160 , V_59 ) ;
V_44 ( V_2 ) -> V_152 . V_153 [ V_59 ] = 0 ;
if ( ! F_39 ( V_2 ) )
break;
if ( V_2 -> V_5 . V_154 [ V_59 ] == V_155 )
for ( V_47 = 0 ;
V_47 < V_2 -> V_50 -> V_51 + 1 ;
V_47 ++ ) {
if ( ! F_25 ( V_47 , V_149 . V_85 ) )
continue;
if ( V_47 == F_47 ( V_2 ) )
continue;
V_123 = & V_45 -> V_43 . V_40 . V_156 [ V_46 ] . V_157 [ V_59 ] . V_80 ;
if ( V_158 == V_123 -> V_159 ) {
V_30 -> V_64 . V_69 . V_59 =
F_4 (
( F_37 ( V_30 -> V_64 . V_69 . V_59 ) & 0xFFFFFFF )
| ( F_48 ( V_2 , V_47 , V_59 ) << 28 ) ) ;
F_18 ( V_2 , V_47 , V_30 ) ;
}
}
else
F_28 ( V_2 , V_59 , V_160 ) ;
}
break;
}
case V_161 :
F_12 ( V_2 , L_16 ,
V_30 -> V_64 . V_162 . V_163 == 1 ?
L_17 : L_18 ,
F_37 ( V_30 -> V_64 . V_162 . V_117 ) & 0xffffff ) ;
if ( F_39 ( V_2 ) ) {
V_87 = F_40 ( V_2 ,
V_164 ,
F_37 ( V_30 -> V_64 . V_162 . V_117 )
& 0xffffff , & V_46 ) ;
if ( V_87 && V_87 != - V_137 ) {
F_22 ( V_2 , L_19 ,
V_30 -> type , V_30 -> V_62 ,
V_13 -> V_138 , V_13 -> V_17 , V_87 ) ;
break;
}
if ( ! V_87 && V_46 != V_2 -> V_5 . V_56 ) {
F_18 ( V_2 , V_46 , V_30 ) ;
break;
}
}
F_49 ( V_2 ,
F_37 ( V_30 -> V_64 . V_162 . V_117 )
& 0xffffff ,
V_30 -> type ) ;
break;
case V_165 :
F_12 ( V_2 , L_20 , V_13 -> V_138 ) ;
break;
case V_166 :
F_50 ( & V_45 -> V_167 ) ;
F_17 ( V_168 , & V_45 -> V_169 ) ;
break;
case V_170 :
if ( ! F_39 ( V_2 ) ) {
F_12 ( V_2 , L_21 ) ;
break;
}
memcpy ( & V_45 -> V_43 . V_40 . V_171 ,
V_30 -> V_64 . V_172 . V_173 ,
sizeof V_30 -> V_64 . V_172 . V_173 ) ;
F_17 ( V_45 -> V_43 . V_40 . V_55 ,
& V_45 -> V_43 . V_40 . V_174 ) ;
break;
case V_175 :
V_120 = F_37 ( V_30 -> V_64 . V_176 . V_48 ) ;
if ( ! F_39 ( V_2 ) ) {
F_12 ( V_2 , L_22 ) ;
break;
}
F_22 ( V_2 , L_23 , V_120 ) ;
if ( V_120 >= V_2 -> V_75 ) {
F_12 ( V_2 ,
L_24 ,
V_120 ) ;
V_121 = 0 ;
} else
V_121 = 1 ;
F_14 ( & V_45 -> V_43 . V_40 . V_111 , V_6 ) ;
if ( V_121 ) {
V_45 -> V_43 . V_40 . V_57 [ V_120 ] . V_58 = false ;
V_45 -> V_43 . V_40 . V_57 [ V_120 ] . V_108 = V_107 ;
V_45 -> V_43 . V_40 . V_57 [ V_120 ] . V_113 = 1 ;
}
F_15 ( & V_45 -> V_43 . V_40 . V_111 , V_6 ) ;
F_17 ( V_45 -> V_43 . V_40 . V_55 ,
& V_45 -> V_43 . V_40 . V_105 ) ;
break;
case V_177 :
if ( V_30 -> V_62 == V_178 ) {
if ( F_39 ( V_2 ) )
for ( V_47 = 0 ; V_47 < V_2 -> V_75 ; V_47 ++ ) {
F_22 ( V_2 , L_25 ,
V_70 , V_47 ) ;
if ( V_47 == V_2 -> V_5 . V_56 )
continue;
F_18 ( V_2 , V_47 , V_30 ) ;
}
F_51 ( V_2 , L_26 ,
F_44 ( V_30 -> V_64 . V_179 . V_180 ) ,
F_44 ( V_30 -> V_64 . V_179 . V_181 ) ) ;
} else
F_12 ( V_2 , L_27 ,
V_30 -> type , V_30 -> V_62 , V_13 -> V_138 ,
V_13 -> V_17 , V_30 -> V_31 , V_13 -> V_24 ,
V_30 -> V_48 ,
! ! ( V_30 -> V_31 & 0x80 ) ^
! ! ( V_13 -> V_17 & V_13 -> V_24 ) ? L_28 : L_29 ) ;
break;
case V_8 :
F_46 ( V_2 , V_182 ,
( unsigned long ) V_30 ) ;
break;
case V_11 :
switch ( V_30 -> V_62 ) {
case V_183 :
F_12 ( V_2 , L_30 ,
V_30 -> V_64 . V_184 . V_59 ) ;
break;
case V_185 :
F_12 ( V_2 , L_31 ) ;
break;
default:
F_22 ( V_2 ,
L_32 ,
V_30 -> type , V_30 -> V_62 , V_13 -> V_138 ,
V_13 -> V_17 , V_30 -> V_31 , V_13 -> V_24 ,
! ! ( V_30 -> V_31 & 0x80 ) ^
! ! ( V_13 -> V_17 & V_13 -> V_24 ) ? L_28 : L_29 ) ;
break;
}
break;
case V_186 :
case V_187 :
default:
F_12 ( V_2 , L_33 ,
V_30 -> type , V_30 -> V_62 , V_13 -> V_138 ,
V_13 -> V_17 , V_30 -> V_31 , V_13 -> V_24 ,
V_30 -> V_48 ,
! ! ( V_30 -> V_31 & 0x80 ) ^
! ! ( V_13 -> V_17 & V_13 -> V_24 ) ? L_28 : L_29 ) ;
break;
} ;
++ V_13 -> V_17 ;
V_118 = 1 ;
++ V_119 ;
if ( F_52 ( V_119 >= V_188 ) ) {
F_2 ( V_13 , 0 ) ;
V_119 = 0 ;
}
}
F_2 ( V_13 , 1 ) ;
if ( ! ( V_117 & ~ 0xffffff ) )
F_53 ( & V_13 -> V_189 . V_190 ) ;
return V_118 ;
}
static T_3 F_54 ( int V_191 , void * V_192 )
{
struct V_1 * V_2 = V_192 ;
struct V_44 * V_45 = V_44 ( V_2 ) ;
int V_38 = 0 ;
int V_47 ;
F_55 ( V_45 -> V_193 . V_194 , V_45 -> V_193 . V_195 ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_5 . V_196 + 1 ; ++ V_47 )
V_38 |= F_35 ( V_2 , & V_45 -> V_193 . V_13 [ V_47 ] ) ;
return F_56 ( V_38 ) ;
}
static T_3 F_57 ( int V_191 , void * V_197 )
{
struct V_12 * V_13 = V_197 ;
struct V_1 * V_2 = V_13 -> V_2 ;
F_35 ( V_2 , V_13 ) ;
return V_198 ;
}
int F_58 ( struct V_1 * V_2 , int V_46 ,
struct V_199 * V_200 ,
struct V_201 * V_202 ,
struct V_201 * V_203 ,
struct V_204 * V_145 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
struct V_205 * V_206 =
V_45 -> V_43 . V_40 . V_57 [ V_46 ] . V_206 ;
V_16 V_207 = V_200 -> V_207 ;
V_16 V_138 = V_207 & 0x3FF ;
T_1 V_208 = V_200 -> V_208 ;
int V_106 = 0 ;
int V_47 ;
if ( V_46 == V_2 -> V_5 . V_56 )
V_106 = F_34 ( V_2 , V_208 , ( V_207 & 0x80000000 ) | V_138 ,
0 , V_209 , V_210 ,
V_211 ) ;
if ( ! V_106 )
for ( V_47 = 0 ; V_47 < V_212 ; ++ V_47 )
if ( V_208 & ( 1LL << V_47 ) )
V_206 [ V_47 ] . V_138 = V_207 >> 31 ? - 1 : V_138 ;
return V_106 ;
}
static int F_59 ( struct V_1 * V_2 , T_1 V_213 , int V_214 ,
int V_215 )
{
return F_34 ( V_2 , V_213 , ( V_214 << 31 ) | V_215 ,
0 , V_209 , V_210 ,
V_116 ) ;
}
static int F_60 ( struct V_1 * V_2 , struct V_201 * V_216 ,
int V_215 )
{
return F_34 ( V_2 , V_216 -> V_217 , V_215 , 0 ,
V_218 , V_115 ,
V_116 ) ;
}
static int F_61 ( struct V_1 * V_2 , int V_215 )
{
return F_34 ( V_2 , 0 , V_215 , 1 , V_219 ,
V_115 , V_116 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_196 + 1 + V_2 -> V_5 . V_220 +
V_2 -> V_5 . V_221 ) / 4 - V_2 -> V_5 . V_220 / 4 + 1 ;
}
static void T_4 * F_63 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
int V_222 ;
V_222 = V_13 -> V_138 / 4 - V_2 -> V_5 . V_220 / 4 ;
if ( ! V_45 -> V_193 . V_223 [ V_222 ] ) {
V_45 -> V_193 . V_223 [ V_222 ] =
F_64 ( F_65 ( V_2 -> V_50 -> V_224 , 2 ) +
( ( V_13 -> V_138 / 4 ) << V_225 ) ,
V_26 ) ;
if ( ! V_45 -> V_193 . V_223 [ V_222 ] ) {
F_51 ( V_2 , L_34 ,
V_13 -> V_138 ) ;
return NULL ;
}
}
return V_45 -> V_193 . V_223 [ V_222 ] + 0x800 + 8 * ( V_13 -> V_138 % 4 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
int V_47 ;
for ( V_47 = 0 ; V_47 < F_62 ( V_2 ) ; ++ V_47 )
if ( V_45 -> V_193 . V_223 [ V_47 ] ) {
F_67 ( V_45 -> V_193 . V_223 [ V_47 ] ) ;
V_45 -> V_193 . V_223 [ V_47 ] = NULL ;
}
}
static int F_68 ( struct V_1 * V_2 , int V_24 ,
T_2 V_226 , struct V_12 * V_13 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
struct V_201 * V_216 ;
struct V_227 * V_228 ;
int V_229 ;
T_1 * V_230 = NULL ;
T_5 V_231 ;
T_1 V_232 ;
int V_106 = - V_233 ;
int V_47 ;
V_13 -> V_2 = V_2 ;
V_13 -> V_24 = F_69 ( F_70 ( V_24 , 2 ) ) ;
V_229 = F_71 ( V_13 -> V_24 * V_2 -> V_5 . V_22 ) / V_26 ;
V_13 -> V_25 = F_72 ( V_229 * sizeof * V_13 -> V_25 ,
V_234 ) ;
if ( ! V_13 -> V_25 )
goto V_235;
for ( V_47 = 0 ; V_47 < V_229 ; ++ V_47 )
V_13 -> V_25 [ V_47 ] . V_27 = NULL ;
V_230 = F_72 ( V_229 * sizeof *V_230 , V_234 ) ;
if ( ! V_230 )
goto V_236;
V_216 = F_73 ( V_2 ) ;
if ( F_74 ( V_216 ) )
goto V_236;
V_228 = V_216 -> V_27 ;
for ( V_47 = 0 ; V_47 < V_229 ; ++ V_47 ) {
V_13 -> V_25 [ V_47 ] . V_27 = F_75 ( & V_2 -> V_50 ->
V_224 -> V_2 ,
V_26 , & V_231 ,
V_234 ) ;
if ( ! V_13 -> V_25 [ V_47 ] . V_27 )
goto V_237;
V_230 [ V_47 ] = V_231 ;
V_13 -> V_25 [ V_47 ] . V_238 = V_231 ;
memset ( V_13 -> V_25 [ V_47 ] . V_27 , 0 , V_26 ) ;
}
V_13 -> V_138 = F_76 ( & V_45 -> V_193 . V_239 ) ;
if ( V_13 -> V_138 == - 1 )
goto V_237;
V_13 -> V_18 = F_63 ( V_2 , V_13 ) ;
if ( ! V_13 -> V_18 ) {
V_106 = - V_233 ;
goto V_240;
}
V_106 = F_77 ( V_2 , V_229 , V_225 , & V_13 -> V_241 ) ;
if ( V_106 )
goto V_240;
V_106 = F_78 ( V_2 , & V_13 -> V_241 , 0 , V_229 , V_230 ) ;
if ( V_106 )
goto V_242;
V_228 -> V_6 = F_4 ( V_243 |
V_244 ) ;
V_228 -> V_245 = F_79 ( V_13 -> V_24 ) ;
V_228 -> V_226 = V_226 ;
V_228 -> V_246 = V_225 - V_247 ;
V_232 = F_80 ( V_2 , & V_13 -> V_241 ) ;
V_228 -> V_248 = V_232 >> 32 ;
V_228 -> V_249 = F_4 ( V_232 & 0xffffffff ) ;
V_106 = F_60 ( V_2 , V_216 , V_13 -> V_138 ) ;
if ( V_106 ) {
F_12 ( V_2 , L_35 , V_106 ) ;
goto V_242;
}
F_81 ( V_230 ) ;
F_82 ( V_2 , V_216 ) ;
V_13 -> V_17 = 0 ;
F_83 ( & V_13 -> V_189 . V_250 ) ;
F_83 ( & V_13 -> V_189 . V_251 ) ;
F_84 ( & V_13 -> V_189 . V_90 ) ;
F_85 ( & V_13 -> V_189 . V_190 , V_252 ,
( unsigned long ) & V_13 -> V_189 ) ;
return V_106 ;
V_242:
F_86 ( V_2 , & V_13 -> V_241 ) ;
V_240:
F_87 ( & V_45 -> V_193 . V_239 , V_13 -> V_138 , V_253 ) ;
V_237:
for ( V_47 = 0 ; V_47 < V_229 ; ++ V_47 )
if ( V_13 -> V_25 [ V_47 ] . V_27 )
F_88 ( & V_2 -> V_50 -> V_224 -> V_2 , V_26 ,
V_13 -> V_25 [ V_47 ] . V_27 ,
V_13 -> V_25 [ V_47 ] . V_238 ) ;
F_82 ( V_2 , V_216 ) ;
V_236:
F_81 ( V_13 -> V_25 ) ;
F_81 ( V_230 ) ;
V_235:
return V_106 ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
int V_106 ;
int V_47 ;
int V_229 = F_71 ( V_2 -> V_5 . V_22 * V_13 -> V_24 ) / V_26 ;
V_106 = F_61 ( V_2 , V_13 -> V_138 ) ;
if ( V_106 )
F_12 ( V_2 , L_36 , V_106 ) ;
F_90 ( V_13 -> V_191 ) ;
F_91 ( & V_13 -> V_189 . V_190 ) ;
F_86 ( V_2 , & V_13 -> V_241 ) ;
for ( V_47 = 0 ; V_47 < V_229 ; ++ V_47 )
F_88 ( & V_2 -> V_50 -> V_224 -> V_2 , V_26 ,
V_13 -> V_25 [ V_47 ] . V_27 ,
V_13 -> V_25 [ V_47 ] . V_238 ) ;
F_81 ( V_13 -> V_25 ) ;
F_87 ( & V_45 -> V_193 . V_239 , V_13 -> V_138 , V_253 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_254 * V_193 = & V_44 ( V_2 ) -> V_193 ;
struct V_44 * V_45 = V_44 ( V_2 ) ;
int V_47 , V_255 ;
if ( V_193 -> V_256 )
F_93 ( V_2 -> V_50 -> V_224 -> V_191 , V_2 ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_5 . V_196 + 1 ; ++ V_47 )
if ( V_193 -> V_13 [ V_47 ] . V_256 ) {
F_93 ( V_193 -> V_13 [ V_47 ] . V_191 , V_193 -> V_13 + V_47 ) ;
V_193 -> V_13 [ V_47 ] . V_256 = 0 ;
}
for ( V_47 = 0 ; V_47 < V_2 -> V_5 . V_221 ; V_47 ++ ) {
if ( V_45 -> V_257 . V_258 & 1ULL << V_47 ) {
V_255 = V_2 -> V_5 . V_196 + 1 + V_47 ;
F_93 ( V_45 -> V_193 . V_13 [ V_255 ] . V_191 ,
& V_45 -> V_193 . V_13 [ V_255 ] ) ;
}
}
F_81 ( V_193 -> V_259 ) ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
V_45 -> V_260 = F_64 ( F_65 ( V_2 -> V_50 -> V_224 ,
V_45 -> V_261 . V_262 ) +
V_45 -> V_261 . V_263 , V_264 ) ;
if ( ! V_45 -> V_260 ) {
F_51 ( V_2 , L_37 ) ;
return - V_233 ;
}
return 0 ;
}
static void F_95 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
F_67 ( V_45 -> V_260 ) ;
}
int F_96 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
V_45 -> V_193 . V_13 = F_97 ( V_2 -> V_5 . V_265 - V_2 -> V_5 . V_220 ,
sizeof * V_45 -> V_193 . V_13 , V_234 ) ;
if ( ! V_45 -> V_193 . V_13 )
return - V_233 ;
return 0 ;
}
void F_98 ( struct V_1 * V_2 )
{
F_81 ( V_44 ( V_2 ) -> V_193 . V_13 ) ;
}
int F_99 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
int V_106 ;
int V_47 ;
V_45 -> V_193 . V_223 = F_97 ( F_62 ( V_2 ) ,
sizeof * V_45 -> V_193 . V_223 ,
V_234 ) ;
if ( ! V_45 -> V_193 . V_223 ) {
V_106 = - V_233 ;
goto V_236;
}
V_106 = F_100 ( & V_45 -> V_193 . V_239 ,
F_69 ( V_2 -> V_5 . V_265 ) ,
V_2 -> V_5 . V_265 - 1 ,
V_2 -> V_5 . V_220 ,
F_69 ( V_2 -> V_5 . V_265 ) -
V_2 -> V_5 . V_265 ) ;
if ( V_106 )
goto V_236;
for ( V_47 = 0 ; V_47 < F_62 ( V_2 ) ; ++ V_47 )
V_45 -> V_193 . V_223 [ V_47 ] = NULL ;
if ( ! F_101 ( V_2 ) ) {
V_106 = F_94 ( V_2 ) ;
if ( V_106 )
goto V_266;
V_45 -> V_193 . V_194 =
F_102 ( 1 << ( V_45 -> V_193 . V_267 & 31 ) ) ;
V_45 -> V_193 . V_195 = V_45 -> V_260 +
( V_45 -> V_193 . V_267 < 32 ? 4 : 0 ) ;
}
V_45 -> V_193 . V_259 =
F_72 ( V_268 * ( V_2 -> V_5 . V_196 + 1 +
V_2 -> V_5 . V_221 ) ,
V_234 ) ;
if ( ! V_45 -> V_193 . V_259 ) {
V_106 = - V_233 ;
goto V_266;
}
for ( V_47 = 0 ; V_47 < V_2 -> V_5 . V_196 ; ++ V_47 ) {
V_106 = F_68 ( V_2 , V_2 -> V_5 . V_269 -
V_2 -> V_5 . V_270 +
V_188 ,
( V_2 -> V_6 & V_271 ) ? V_47 : 0 ,
& V_45 -> V_193 . V_13 [ V_47 ] ) ;
if ( V_106 ) {
-- V_47 ;
goto V_272;
}
}
V_106 = F_68 ( V_2 , V_273 + V_188 ,
( V_2 -> V_6 & V_271 ) ? V_2 -> V_5 . V_196 : 0 ,
& V_45 -> V_193 . V_13 [ V_2 -> V_5 . V_196 ] ) ;
if ( V_106 )
goto V_274;
for ( V_47 = V_2 -> V_5 . V_196 + 1 ;
V_47 < V_2 -> V_5 . V_196 + V_2 -> V_5 . V_221 + 1 ; ++ V_47 ) {
V_106 = F_68 ( V_2 , V_2 -> V_5 . V_269 -
V_2 -> V_5 . V_270 +
V_188 ,
( V_2 -> V_6 & V_271 ) ? V_47 : 0 ,
& V_45 -> V_193 . V_13 [ V_47 ] ) ;
if ( V_106 ) {
-- V_47 ;
goto V_272;
}
}
if ( V_2 -> V_6 & V_271 ) {
const char * V_275 ;
for ( V_47 = 0 ; V_47 < V_2 -> V_5 . V_196 + 1 ; ++ V_47 ) {
if ( V_47 < V_2 -> V_5 . V_196 ) {
snprintf ( V_45 -> V_193 . V_259 +
V_47 * V_268 ,
V_268 ,
L_38 , V_47 ,
F_103 ( V_2 -> V_50 -> V_224 ) ) ;
} else {
snprintf ( V_45 -> V_193 . V_259 +
V_47 * V_268 ,
V_268 ,
L_39 ,
F_103 ( V_2 -> V_50 -> V_224 ) ) ;
}
V_275 = V_45 -> V_193 . V_259 +
V_47 * V_268 ;
V_106 = F_104 ( V_45 -> V_193 . V_13 [ V_47 ] . V_191 ,
F_57 , 0 , V_275 ,
V_45 -> V_193 . V_13 + V_47 ) ;
if ( V_106 )
goto V_276;
V_45 -> V_193 . V_13 [ V_47 ] . V_256 = 1 ;
}
} else {
snprintf ( V_45 -> V_193 . V_259 ,
V_268 ,
V_277 L_40 ,
F_103 ( V_2 -> V_50 -> V_224 ) ) ;
V_106 = F_104 ( V_2 -> V_50 -> V_224 -> V_191 , F_54 ,
V_278 , V_45 -> V_193 . V_259 , V_2 ) ;
if ( V_106 )
goto V_276;
V_45 -> V_193 . V_256 = 1 ;
}
V_106 = F_59 ( V_2 , F_1 ( V_2 ) , 0 ,
V_45 -> V_193 . V_13 [ V_2 -> V_5 . V_196 ] . V_138 ) ;
if ( V_106 )
F_12 ( V_2 , L_41 ,
V_45 -> V_193 . V_13 [ V_2 -> V_5 . V_196 ] . V_138 , V_106 ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_5 . V_196 + 1 ; ++ V_47 )
F_2 ( & V_45 -> V_193 . V_13 [ V_47 ] , 1 ) ;
return 0 ;
V_276:
F_89 ( V_2 , & V_45 -> V_193 . V_13 [ V_2 -> V_5 . V_196 ] ) ;
V_274:
V_47 = V_2 -> V_5 . V_196 - 1 ;
V_272:
while ( V_47 >= 0 ) {
F_89 ( V_2 , & V_45 -> V_193 . V_13 [ V_47 ] ) ;
-- V_47 ;
}
if ( ! F_101 ( V_2 ) )
F_95 ( V_2 ) ;
F_92 ( V_2 ) ;
V_266:
F_66 ( V_2 ) ;
F_105 ( & V_45 -> V_193 . V_239 ) ;
V_236:
F_81 ( V_45 -> V_193 . V_223 ) ;
return V_106 ;
}
void F_106 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
int V_47 ;
F_59 ( V_2 , F_1 ( V_2 ) , 1 ,
V_45 -> V_193 . V_13 [ V_2 -> V_5 . V_196 ] . V_138 ) ;
F_92 ( V_2 ) ;
for ( V_47 = 0 ; V_47 < V_2 -> V_5 . V_196 + V_2 -> V_5 . V_221 + 1 ; ++ V_47 )
F_89 ( V_2 , & V_45 -> V_193 . V_13 [ V_47 ] ) ;
if ( ! F_101 ( V_2 ) )
F_95 ( V_2 ) ;
F_66 ( V_2 ) ;
F_105 ( & V_45 -> V_193 . V_239 ) ;
F_81 ( V_45 -> V_193 . V_223 ) ;
}
int F_107 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
int V_47 ;
int V_106 ;
V_106 = F_108 ( V_2 ) ;
if ( ! ( V_2 -> V_6 & V_271 ) || F_101 ( V_2 ) )
return V_106 ;
for( V_47 = 0 ; ! V_106 && ( V_47 < V_2 -> V_5 . V_196 ) ; ++ V_47 ) {
F_109 ( V_2 ) ;
V_106 = F_59 ( V_2 , F_1 ( V_2 ) , 0 ,
V_45 -> V_193 . V_13 [ V_47 ] . V_138 ) ;
if ( V_106 ) {
F_12 ( V_2 , L_42 ) ;
F_110 ( V_2 ) ;
break;
}
F_110 ( V_2 ) ;
V_106 = F_108 ( V_2 ) ;
}
F_59 ( V_2 , F_1 ( V_2 ) , 0 ,
V_45 -> V_193 . V_13 [ V_2 -> V_5 . V_196 ] . V_138 ) ;
return V_106 ;
}
int F_111 ( struct V_1 * V_2 , char * V_279 , struct V_280 * V_281 ,
int * V_282 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
int V_255 = 0 , V_106 = 0 , V_47 ;
F_112 ( & V_45 -> V_257 . V_283 ) ;
for ( V_47 = 0 ; ! V_255 && V_47 < V_2 -> V_5 . V_221 ; V_47 ++ ) {
if ( ~ V_45 -> V_257 . V_258 & 1ULL << V_47 ) {
V_45 -> V_257 . V_258 |= 1ULL << V_47 ;
V_255 = V_2 -> V_5 . V_196 + 1 + V_47 ;
snprintf ( V_45 -> V_193 . V_259 +
V_255 * V_268 ,
V_268 , L_43 , V_279 ) ;
#ifdef F_113
if ( V_281 ) {
V_106 = F_114 ( V_281 ,
V_45 -> V_193 . V_13 [ V_255 ] . V_191 ) ;
if ( V_106 )
F_12 ( V_2 , L_44 ) ;
}
#endif
V_106 = F_104 ( V_45 -> V_193 . V_13 [ V_255 ] . V_191 ,
F_57 , 0 ,
& V_45 -> V_193 . V_259 [ V_255 << 5 ] ,
V_45 -> V_193 . V_13 + V_255 ) ;
if ( V_106 ) {
V_45 -> V_257 . V_258 ^= 1 << V_47 ;
V_255 = 0 ;
continue;
}
F_2 ( & V_45 -> V_193 . V_13 [ V_255 ] , 1 ) ;
}
}
F_115 ( & V_45 -> V_257 . V_283 ) ;
if ( V_255 ) {
* V_282 = V_255 ;
} else {
* V_282 = 0 ;
V_106 = ( V_47 == V_2 -> V_5 . V_221 ) ? - V_284 : V_106 ;
}
return V_106 ;
}
int F_116 ( struct V_1 * V_2 , int V_255 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
return V_45 -> V_193 . V_13 [ V_255 ] . V_191 ;
}
void F_117 ( struct V_1 * V_2 , int V_255 )
{
struct V_44 * V_45 = V_44 ( V_2 ) ;
int V_47 = V_255 - V_2 -> V_5 . V_196 - 1 ;
if ( F_118 ( V_47 >= 0 ) ) {
F_112 ( & V_45 -> V_257 . V_283 ) ;
if ( V_45 -> V_257 . V_258 & 1ULL << V_47 ) {
F_93 ( V_45 -> V_193 . V_13 [ V_255 ] . V_191 ,
& V_45 -> V_193 . V_13 [ V_255 ] ) ;
V_45 -> V_257 . V_258 &= ~ ( 1ULL << V_47 ) ;
}
F_115 ( & V_45 -> V_257 . V_283 ) ;
}
}
