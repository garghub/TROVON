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
static struct V_16 * F_6 ( struct V_9 * V_10 , V_13 V_17 , T_2 V_18 )
{
unsigned long V_19 = ( V_17 & ( V_10 -> V_20 - 1 ) ) * ( V_21 << V_18 ) ;
return V_10 -> V_22 [ V_19 / V_23 ] . V_24 + ( V_19 + ( V_18 ? V_21 : 0 ) ) % V_23 ;
}
static struct V_16 * F_7 ( struct V_9 * V_10 , T_2 V_18 )
{
struct V_16 * V_25 = F_6 ( V_10 , V_10 -> V_14 , V_18 ) ;
return ! ! ( V_25 -> V_26 & 0x80 ) ^ ! ! ( V_10 -> V_14 & V_10 -> V_20 ) ? NULL : V_25 ;
}
static struct V_16 * F_8 ( struct V_27 * V_28 )
{
struct V_16 * V_25 =
& V_28 -> V_29 [ V_28 -> V_30 & ( V_31 - 1 ) ] ;
return ( ! ! ( V_25 -> V_26 & 0x80 ) ^
! ! ( V_28 -> V_30 & V_31 ) ) ?
V_25 : NULL ;
}
void F_9 ( struct V_32 * V_33 )
{
struct V_34 * V_35 =
F_10 ( V_33 , struct V_34 ,
V_36 ) ;
struct V_37 * V_38 =
F_10 ( V_35 , struct V_37 , V_35 ) ;
struct V_39 * V_40 = F_10 ( V_38 , struct V_39 , V_38 ) ;
struct V_1 * V_2 = & V_40 -> V_2 ;
struct V_27 * V_28 = & V_38 -> V_35 . V_28 ;
struct V_16 * V_25 ;
T_2 V_41 ;
int V_42 ;
for ( V_25 = F_8 ( V_28 ) ; V_25 ;
V_25 = F_8 ( V_28 ) ) {
V_41 = V_25 -> V_43 ;
if ( V_41 == V_44 ) {
for ( V_42 = 0 ; V_42 < V_2 -> V_45 ; V_42 ++ ) {
if ( V_42 != V_2 -> V_5 . V_46 &&
V_35 -> V_47 [ V_42 ] . V_48 )
if ( F_11 ( V_2 , V_42 , V_25 ) )
F_12 ( V_2 , L_1
L_2
L_3 , V_42 ) ;
}
} else {
if ( F_11 ( V_2 , V_41 , V_25 ) )
F_12 ( V_2 , L_4
L_3 , V_41 ) ;
}
++ V_28 -> V_30 ;
}
}
static void F_13 ( struct V_1 * V_2 , T_2 V_41 , struct V_16 * V_25 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_27 * V_28 = & V_40 -> V_38 . V_35 . V_28 ;
struct V_16 * V_49 ;
unsigned long V_6 ;
F_14 ( & V_28 -> V_50 , V_6 ) ;
V_49 = & V_28 -> V_29 [ V_28 -> V_51 & ( V_31 - 1 ) ] ;
if ( ( ! ! ( V_49 -> V_26 & 0x80 ) ) ^
( ! ! ( V_28 -> V_51 & V_31 ) ) ) {
F_12 ( V_2 , L_5
L_6 , V_41 ) ;
F_15 ( & V_28 -> V_50 , V_6 ) ;
return;
}
memcpy ( V_49 , V_25 , V_2 -> V_5 . V_52 - 1 ) ;
V_49 -> V_43 = V_41 ;
F_16 () ;
V_49 -> V_26 = ! ! ( V_28 -> V_51 & V_31 ) ? 0x0 : 0x80 ;
++ V_28 -> V_51 ;
F_17 ( V_40 -> V_38 . V_35 . V_53 ,
& V_40 -> V_38 . V_35 . V_36 ) ;
F_15 ( & V_28 -> V_50 , V_6 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_41 ,
struct V_16 * V_25 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_54 * V_55 =
& V_40 -> V_38 . V_35 . V_47 [ V_41 ] ;
if ( ! V_55 -> V_48 ) {
return;
}
F_13 ( V_2 , V_41 , V_25 ) ;
}
int F_19 ( struct V_1 * V_2 , int V_41 , T_2 V_56 )
{
struct V_16 V_25 ;
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_54 * V_55 = & V_40 -> V_38 . V_35 . V_47 [ V_41 ] ;
if ( ! V_55 -> V_48 )
return 0 ;
memset ( & V_25 , 0 , sizeof V_25 ) ;
V_25 . type = V_8 ;
V_25 . V_57 = V_58 ;
V_25 . V_59 . V_60 . V_56 = V_56 ;
return F_11 ( V_2 , V_41 , & V_25 ) ;
}
int F_20 ( struct V_1 * V_2 , int V_41 , T_2 V_56 )
{
struct V_16 V_25 ;
if ( V_2 -> V_61 < V_41 )
return 0 ;
memset ( & V_25 , 0 , sizeof V_25 ) ;
V_25 . type = V_8 ;
V_25 . V_57 = V_62 ;
V_25 . V_59 . V_60 . V_56 = V_56 ;
return F_11 ( V_2 , V_41 , & V_25 ) ;
}
int F_21 ( struct V_1 * V_2 , int V_41 , T_2 V_56 ,
T_2 V_63 )
{
struct V_16 V_25 ;
if ( V_2 -> V_61 < V_41 )
return 0 ;
memset ( & V_25 , 0 , sizeof V_25 ) ;
V_25 . type = V_64 ;
V_25 . V_57 = V_63 ;
V_25 . V_59 . V_65 . V_56 = F_4 ( V_56 << 28 ) ;
F_22 ( V_2 , L_7 , V_66 ,
V_63 , V_41 , V_56 ) ;
return F_11 ( V_2 , V_41 , & V_25 ) ;
}
enum V_67 F_23 ( struct V_1 * V_2 , int V_41 , T_2 V_56 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_54 * V_68 = V_40 -> V_38 . V_35 . V_47 ;
struct V_69 V_70 = F_24 ( V_2 , V_41 ) ;
if ( V_41 >= V_2 -> V_45 || V_56 > V_2 -> V_5 . V_71 ||
V_56 <= 0 || ! F_25 ( V_56 - 1 , V_70 . V_72 ) ) {
F_26 ( L_8 ,
V_66 , V_41 , V_56 ) ;
return V_73 ;
}
return V_68 [ V_41 ] . V_74 [ V_56 ] ;
}
static int F_27 ( struct V_1 * V_2 , int V_41 , T_2 V_56 ,
enum V_67 V_75 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_54 * V_68 = V_40 -> V_38 . V_35 . V_47 ;
struct V_69 V_70 = F_24 ( V_2 , V_41 ) ;
if ( V_41 >= V_2 -> V_45 || V_56 > V_2 -> V_5 . V_71 ||
V_56 <= 0 || ! F_25 ( V_56 - 1 , V_70 . V_72 ) ) {
F_26 ( L_8 ,
V_66 , V_41 , V_56 ) ;
return - 1 ;
}
V_68 [ V_41 ] . V_74 [ V_56 ] = V_75 ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 , T_2 V_56 , int V_59 )
{
int V_42 ;
enum V_76 V_77 ;
struct V_78 V_79 = F_29 ( V_2 ,
V_56 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_61 + 1 ; V_42 ++ )
if ( F_25 ( V_42 , V_79 . V_80 ) )
F_30 ( V_2 , V_42 , V_56 ,
V_59 , & V_77 ) ;
}
int F_30 ( struct V_1 * V_2 , int V_41 ,
T_2 V_56 , int V_59 ,
enum V_76 * V_77 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_54 * V_81 = NULL ;
unsigned long V_6 ;
int V_82 = - 1 ;
struct V_69 V_70 = F_24 ( V_2 , V_41 ) ;
enum V_67 V_83 =
F_23 ( V_2 , V_41 , V_56 ) ;
* V_77 = V_84 ;
if ( V_41 >= V_2 -> V_45 || V_56 > V_2 -> V_5 . V_71 ||
V_56 <= 0 || ! F_25 ( V_56 - 1 , V_70 . V_72 ) ) {
F_26 ( L_8 ,
V_66 , V_41 , V_56 ) ;
return V_82 ;
}
V_81 = & V_40 -> V_38 . V_35 . V_47 [ V_41 ] ;
F_14 ( & V_81 -> V_85 , V_6 ) ;
switch ( V_83 ) {
case V_73 :
if ( V_86 == V_59 )
F_27 ( V_2 , V_41 , V_56 ,
V_87 ) ;
break;
case V_87 :
if ( V_88 == V_59 )
F_27 ( V_2 , V_41 , V_56 ,
V_73 ) ;
else if ( V_89 == V_59 ) {
F_27 ( V_2 , V_41 , V_56 ,
V_90 ) ;
* V_77 = V_91 ;
}
break;
case V_90 :
if ( V_88 == V_59 ) {
F_27 ( V_2 , V_41 , V_56 ,
V_73 ) ;
* V_77 = V_92 ;
} else if ( V_93 ==
V_59 ) {
F_27 ( V_2 , V_41 , V_56 ,
V_87 ) ;
* V_77 = V_92 ;
}
break;
default:
F_26 ( L_9
L_10 , V_66 , V_41 , V_56 ) ;
goto V_94;
}
V_82 = F_23 ( V_2 , V_41 , V_56 ) ;
V_94:
F_15 ( & V_81 -> V_85 , V_6 ) ;
return V_82 ;
}
int F_31 ( struct V_1 * V_2 , T_2 V_56 , int V_95 )
{
struct V_16 V_25 ;
memset ( & V_25 , 0 , sizeof V_25 ) ;
V_25 . type = V_8 ;
V_25 . V_57 = V_96 ;
V_25 . V_59 . V_60 . V_56 = V_56 ;
V_25 . V_59 . V_60 . V_97 . V_98 . V_99 =
F_4 ( ( V_13 ) V_95 ) ;
F_13 ( V_2 , V_44 , & V_25 ) ;
return 0 ;
}
void F_32 ( struct V_32 * V_33 )
{
struct V_34 * V_35 =
F_10 ( V_33 , struct V_34 ,
V_100 ) ;
struct V_37 * V_38 =
F_10 ( V_35 , struct V_37 , V_35 ) ;
struct V_39 * V_40 =
F_10 ( V_38 , struct V_39 , V_38 ) ;
struct V_1 * V_2 = & V_40 -> V_2 ;
struct V_54 * V_47 = V_40 -> V_38 . V_35 . V_47 ;
int V_42 ;
int V_101 ;
unsigned long V_6 ;
F_22 ( V_2 , L_11 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_45 ; V_42 ++ ) {
if ( V_102 == V_47 [ V_42 ] . V_103 ) {
F_22 ( V_2 , L_12
L_13 , V_42 ) ;
F_33 ( V_2 , V_42 ) ;
F_14 ( & V_40 -> V_38 . V_35 . V_104 , V_6 ) ;
V_47 [ V_42 ] . V_103 = V_105 ;
V_47 [ V_42 ] . V_106 = 0 ;
F_15 ( & V_40 -> V_38 . V_35 . V_104 , V_6 ) ;
V_101 = F_34 ( V_2 , 0 , V_42 , 0 , V_107 ,
V_108 , V_109 ) ;
if ( V_101 )
F_12 ( V_2 , L_14
L_15 , V_42 ) ;
}
}
}
static int F_35 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_16 * V_25 ;
int V_110 ;
int V_111 = 0 ;
int V_112 = 0 ;
int V_56 ;
int V_41 = 0 ;
int V_82 ;
V_13 V_113 ;
T_2 V_114 ;
int V_42 ;
enum V_76 V_77 ;
unsigned long V_6 ;
struct V_115 * V_116 ;
while ( ( V_25 = F_7 ( V_10 , V_2 -> V_5 . V_18 ) ) ) {
F_36 () ;
switch ( V_25 -> type ) {
case V_117 :
V_110 = F_37 ( V_25 -> V_59 . V_118 . V_110 ) & 0xffffff ;
F_38 ( V_2 , V_110 ) ;
break;
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
F_22 ( V_2 , L_16 , V_25 -> type ) ;
if ( F_39 ( V_2 ) ) {
V_82 = F_40 ( V_2 ,
V_127 ,
F_37 ( V_25 -> V_59 . V_128 . V_129 )
& 0xffffff , & V_41 ) ;
if ( V_82 && V_82 != - V_130 ) {
F_22 ( V_2 , L_17
L_18
L_19 ,
V_25 -> type , V_25 -> V_57 ,
V_10 -> V_131 , V_10 -> V_14 , V_82 ) ;
break;
}
if ( ! V_82 && V_41 != V_2 -> V_5 . V_46 ) {
F_18 ( V_2 , V_41 , V_25 ) ;
break;
}
}
F_41 ( V_2 , F_37 ( V_25 -> V_59 . V_128 . V_129 ) &
0xffffff , V_25 -> type ) ;
break;
case V_132 :
F_22 ( V_2 , L_20 ,
V_66 ) ;
case V_133 :
if ( F_39 ( V_2 ) ) {
V_82 = F_40 ( V_2 ,
V_134 ,
F_37 ( V_25 -> V_59 . V_135 . V_136 )
& 0xffffff ,
& V_41 ) ;
if ( V_82 && V_82 != - V_130 ) {
F_12 ( V_2 , L_21
L_22
L_23 ,
V_25 -> type , V_25 -> V_57 ,
V_10 -> V_131 , V_10 -> V_14 , V_82 ) ;
break;
}
F_12 ( V_2 , L_24
L_25 , V_66 ,
V_41 ,
F_37 ( V_25 -> V_59 . V_135 . V_136 ) ,
V_25 -> type , V_25 -> V_57 ) ;
if ( ! V_82 && V_41 != V_2 -> V_5 . V_46 ) {
F_12 ( V_2 , L_26
L_27 ,
V_66 , V_25 -> type ,
V_25 -> V_57 , V_41 ) ;
F_18 ( V_2 , V_41 , V_25 ) ;
break;
}
}
F_42 ( V_2 , F_37 ( V_25 -> V_59 . V_135 . V_136 ) &
0xffffff , V_25 -> type ) ;
break;
case V_137 :
F_43 ( V_2 ,
F_44 ( V_25 -> V_59 . V_138 . V_139 ) ,
V_25 -> V_59 . V_138 . V_140 ,
F_45 ( V_25 -> V_59 . V_138 . V_141 ) ) ;
break;
case V_64 : {
struct V_78 V_142 ;
V_56 = F_37 ( V_25 -> V_59 . V_65 . V_56 ) >> 28 ;
V_142 = F_29 ( V_2 , V_56 ) ;
if ( V_25 -> V_57 == V_143 ) {
F_46 ( V_2 , V_144 ,
V_56 ) ;
V_39 ( V_2 ) -> V_145 . V_146 [ V_56 ] = 1 ;
if ( ! F_39 ( V_2 ) )
break;
for ( V_42 = 0 ; V_42 < V_2 -> V_61 + 1 ; V_42 ++ ) {
if ( ! F_25 ( V_42 , V_142 . V_80 ) )
continue;
if ( V_2 -> V_5 . V_147 [ V_56 ] == V_148 ) {
if ( V_42 == F_47 ( V_2 ) )
continue;
F_22 ( V_2 , L_28
L_29 ,
V_66 , V_42 , V_56 ) ;
V_116 = & V_40 -> V_38 . V_35 . V_149 [ V_41 ] . V_150 [ V_56 ] . V_75 ;
if ( V_151 == V_116 -> V_152 ) {
V_25 -> V_59 . V_65 . V_56 =
F_4 (
( F_37 ( V_25 -> V_59 . V_65 . V_56 ) & 0xFFFFFFF )
| ( F_48 ( V_2 , V_42 , V_56 ) << 28 ) ) ;
F_18 ( V_2 , V_42 , V_25 ) ;
}
} else {
F_30 ( V_2 , V_42 , V_56 ,
V_88 ,
& V_77 ) ;
if ( V_92 == V_77 ) {
if ( V_42 == F_47 ( V_2 ) )
continue;
F_18 ( V_2 , V_42 , V_25 ) ;
}
}
}
} else {
F_46 ( V_2 , V_153 , V_56 ) ;
V_39 ( V_2 ) -> V_145 . V_146 [ V_56 ] = 0 ;
if ( ! F_39 ( V_2 ) )
break;
if ( V_2 -> V_5 . V_147 [ V_56 ] == V_148 )
for ( V_42 = 0 ; V_42 < V_2 -> V_61 + 1 ; V_42 ++ ) {
if ( ! F_25 ( V_42 , V_142 . V_80 ) )
continue;
if ( V_42 == F_47 ( V_2 ) )
continue;
V_116 = & V_40 -> V_38 . V_35 . V_149 [ V_41 ] . V_150 [ V_56 ] . V_75 ;
if ( V_151 == V_116 -> V_152 ) {
V_25 -> V_59 . V_65 . V_56 =
F_4 (
( F_37 ( V_25 -> V_59 . V_65 . V_56 ) & 0xFFFFFFF )
| ( F_48 ( V_2 , V_42 , V_56 ) << 28 ) ) ;
F_18 ( V_2 , V_42 , V_25 ) ;
}
}
else
F_28 ( V_2 , V_56 , V_153 ) ;
}
break;
}
case V_154 :
F_12 ( V_2 , L_30 ,
V_25 -> V_59 . V_155 . V_156 == 1 ?
L_31 : L_32 ,
F_37 ( V_25 -> V_59 . V_155 . V_110 ) & 0xffffff ) ;
if ( F_39 ( V_2 ) ) {
V_82 = F_40 ( V_2 ,
V_157 ,
F_37 ( V_25 -> V_59 . V_155 . V_110 )
& 0xffffff , & V_41 ) ;
if ( V_82 && V_82 != - V_130 ) {
F_22 ( V_2 , L_33
L_18
L_19 ,
V_25 -> type , V_25 -> V_57 ,
V_10 -> V_131 , V_10 -> V_14 , V_82 ) ;
break;
}
if ( ! V_82 && V_41 != V_2 -> V_5 . V_46 ) {
F_18 ( V_2 , V_41 , V_25 ) ;
break;
}
}
F_49 ( V_2 ,
F_37 ( V_25 -> V_59 . V_155 . V_110 )
& 0xffffff ,
V_25 -> type ) ;
break;
case V_158 :
F_12 ( V_2 , L_34 , V_10 -> V_131 ) ;
break;
case V_159 :
F_50 ( & V_40 -> V_160 ) ;
F_17 ( V_161 , & V_40 -> V_162 ) ;
break;
case V_163 :
if ( ! F_39 ( V_2 ) ) {
F_12 ( V_2 , L_35
L_36 ) ;
break;
}
memcpy ( & V_40 -> V_38 . V_35 . V_164 ,
V_25 -> V_59 . V_165 . V_166 ,
sizeof V_25 -> V_59 . V_165 . V_166 ) ;
F_17 ( V_40 -> V_38 . V_35 . V_53 ,
& V_40 -> V_38 . V_35 . V_167 ) ;
break;
case V_168 :
V_113 = F_37 ( V_25 -> V_59 . V_169 . V_43 ) ;
if ( ! F_39 ( V_2 ) ) {
F_12 ( V_2 , L_37
L_38 ) ;
break;
}
F_22 ( V_2 , L_39 , V_113 ) ;
if ( V_113 >= V_2 -> V_45 ) {
F_12 ( V_2 ,
L_40 ,
V_113 ) ;
V_114 = 0 ;
} else
V_114 = 1 ;
F_14 ( & V_40 -> V_38 . V_35 . V_104 , V_6 ) ;
if ( V_114 ) {
V_40 -> V_38 . V_35 . V_47 [ V_113 ] . V_48 = false ;
V_40 -> V_38 . V_35 . V_47 [ V_113 ] . V_103 = V_102 ;
V_40 -> V_38 . V_35 . V_47 [ V_113 ] . V_106 = 1 ;
}
F_15 ( & V_40 -> V_38 . V_35 . V_104 , V_6 ) ;
F_17 ( V_40 -> V_38 . V_35 . V_53 ,
& V_40 -> V_38 . V_35 . V_100 ) ;
break;
case V_170 :
if ( V_25 -> V_57 == V_171 ) {
if ( F_39 ( V_2 ) )
for ( V_42 = 0 ; V_42 < V_2 -> V_45 ; V_42 ++ ) {
F_22 ( V_2 , L_41
L_42
L_43 , V_66 , V_42 ) ;
if ( V_42 == V_2 -> V_5 . V_46 )
continue;
F_18 ( V_2 , V_42 , V_25 ) ;
}
F_51 ( V_2 , L_44
L_45
L_46 ,
F_44 ( V_25 -> V_59 . V_172 . V_173 ) ,
F_44 ( V_25 -> V_59 . V_172 . V_174 ) ) ;
} else
F_12 ( V_2 , L_47
L_48
L_49 ,
V_25 -> type , V_25 -> V_57 , V_10 -> V_131 ,
V_10 -> V_14 , V_25 -> V_26 , V_10 -> V_20 ,
V_25 -> V_43 ,
! ! ( V_25 -> V_26 & 0x80 ) ^
! ! ( V_10 -> V_14 & V_10 -> V_20 ) ? L_50 : L_51 ) ;
break;
case V_8 :
F_46 ( V_2 , V_175 ,
( unsigned long ) V_25 ) ;
break;
case V_176 :
case V_177 :
default:
F_12 ( V_2 , L_52
L_53
L_54 ,
V_25 -> type , V_25 -> V_57 , V_10 -> V_131 ,
V_10 -> V_14 , V_25 -> V_26 , V_10 -> V_20 ,
V_25 -> V_43 ,
! ! ( V_25 -> V_26 & 0x80 ) ^
! ! ( V_10 -> V_14 & V_10 -> V_20 ) ? L_50 : L_51 ) ;
break;
} ;
++ V_10 -> V_14 ;
V_111 = 1 ;
++ V_112 ;
if ( F_52 ( V_112 >= V_178 ) ) {
F_2 ( V_10 , 0 ) ;
V_112 = 0 ;
}
}
F_2 ( V_10 , 1 ) ;
return V_111 ;
}
static T_3 F_53 ( int V_179 , void * V_180 )
{
struct V_1 * V_2 = V_180 ;
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_33 = 0 ;
int V_42 ;
F_54 ( V_40 -> V_181 . V_182 , V_40 -> V_181 . V_183 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_184 + 1 ; ++ V_42 )
V_33 |= F_35 ( V_2 , & V_40 -> V_181 . V_10 [ V_42 ] ) ;
return F_55 ( V_33 ) ;
}
static T_3 F_56 ( int V_179 , void * V_185 )
{
struct V_9 * V_10 = V_185 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_35 ( V_2 , V_10 ) ;
return V_186 ;
}
int F_57 ( struct V_1 * V_2 , int V_41 ,
struct V_187 * V_188 ,
struct V_189 * V_190 ,
struct V_189 * V_191 ,
struct V_192 * V_138 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_193 * V_194 =
V_40 -> V_38 . V_35 . V_47 [ V_41 ] . V_194 ;
V_13 V_195 = V_188 -> V_195 ;
V_13 V_131 = V_195 & 0x3FF ;
T_1 V_196 = V_188 -> V_196 ;
int V_101 = 0 ;
int V_42 ;
if ( V_41 == V_2 -> V_5 . V_46 )
V_101 = F_34 ( V_2 , V_196 , ( V_195 & 0x80000000 ) | V_131 ,
0 , V_197 , V_198 ,
V_199 ) ;
if ( ! V_101 )
for ( V_42 = 0 ; V_42 < V_200 ; ++ V_42 )
if ( V_196 & ( 1LL << V_42 ) )
V_194 [ V_42 ] . V_131 = V_195 >> 31 ? - 1 : V_131 ;
return V_101 ;
}
static int F_58 ( struct V_1 * V_2 , T_1 V_201 , int V_202 ,
int V_203 )
{
return F_34 ( V_2 , V_201 , ( V_202 << 31 ) | V_203 ,
0 , V_197 , V_198 ,
V_109 ) ;
}
static int F_59 ( struct V_1 * V_2 , struct V_189 * V_204 ,
int V_203 )
{
return F_34 ( V_2 , V_204 -> V_205 , V_203 , 0 ,
V_206 , V_108 ,
V_109 ) ;
}
static int F_60 ( struct V_1 * V_2 , struct V_189 * V_204 ,
int V_203 )
{
return F_61 ( V_2 , 0 , V_204 -> V_205 , V_203 ,
0 , V_207 , V_108 ,
V_109 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_184 + 1 + V_2 -> V_5 . V_208 +
V_2 -> V_5 . V_209 ) / 4 - V_2 -> V_5 . V_208 / 4 + 1 ;
}
static void T_4 * F_63 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_210 ;
V_210 = V_10 -> V_131 / 4 - V_2 -> V_5 . V_208 / 4 ;
if ( ! V_40 -> V_181 . V_211 [ V_210 ] ) {
V_40 -> V_181 . V_211 [ V_210 ] =
F_64 ( F_65 ( V_2 -> V_212 , 2 ) +
( ( V_10 -> V_131 / 4 ) << V_213 ) ,
V_23 ) ;
if ( ! V_40 -> V_181 . V_211 [ V_210 ] ) {
F_51 ( V_2 , L_55 ,
V_10 -> V_131 ) ;
return NULL ;
}
}
return V_40 -> V_181 . V_211 [ V_210 ] + 0x800 + 8 * ( V_10 -> V_131 % 4 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < F_62 ( V_2 ) ; ++ V_42 )
if ( V_40 -> V_181 . V_211 [ V_42 ] ) {
F_67 ( V_40 -> V_181 . V_211 [ V_42 ] ) ;
V_40 -> V_181 . V_211 [ V_42 ] = NULL ;
}
}
static int F_68 ( struct V_1 * V_2 , int V_20 ,
T_2 V_214 , struct V_9 * V_10 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_189 * V_204 ;
struct V_215 * V_216 ;
int V_217 ;
T_1 * V_218 = NULL ;
T_5 V_219 ;
T_1 V_220 ;
int V_101 = - V_221 ;
int V_42 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_20 = F_69 ( F_70 ( V_20 , 2 ) ) ;
V_217 = F_71 ( V_10 -> V_20 * ( V_21 << V_2 -> V_5 . V_18 ) ) / V_23 ;
V_10 -> V_22 = F_72 ( V_217 * sizeof * V_10 -> V_22 ,
V_222 ) ;
if ( ! V_10 -> V_22 )
goto V_223;
for ( V_42 = 0 ; V_42 < V_217 ; ++ V_42 )
V_10 -> V_22 [ V_42 ] . V_24 = NULL ;
V_218 = F_72 ( V_217 * sizeof *V_218 , V_222 ) ;
if ( ! V_218 )
goto V_224;
V_204 = F_73 ( V_2 ) ;
if ( F_74 ( V_204 ) )
goto V_224;
V_216 = V_204 -> V_24 ;
for ( V_42 = 0 ; V_42 < V_217 ; ++ V_42 ) {
V_10 -> V_22 [ V_42 ] . V_24 = F_75 ( & V_2 -> V_212 -> V_2 ,
V_23 , & V_219 , V_222 ) ;
if ( ! V_10 -> V_22 [ V_42 ] . V_24 )
goto V_225;
V_218 [ V_42 ] = V_219 ;
V_10 -> V_22 [ V_42 ] . V_226 = V_219 ;
memset ( V_10 -> V_22 [ V_42 ] . V_24 , 0 , V_23 ) ;
}
V_10 -> V_131 = F_76 ( & V_40 -> V_181 . V_227 ) ;
if ( V_10 -> V_131 == - 1 )
goto V_225;
V_10 -> V_15 = F_63 ( V_2 , V_10 ) ;
if ( ! V_10 -> V_15 ) {
V_101 = - V_221 ;
goto V_228;
}
V_101 = F_77 ( V_2 , V_217 , V_213 , & V_10 -> V_229 ) ;
if ( V_101 )
goto V_228;
V_101 = F_78 ( V_2 , & V_10 -> V_229 , 0 , V_217 , V_218 ) ;
if ( V_101 )
goto V_230;
V_216 -> V_6 = F_4 ( V_231 |
V_232 ) ;
V_216 -> V_233 = F_79 ( V_10 -> V_20 ) ;
V_216 -> V_214 = V_214 ;
V_216 -> V_234 = V_213 - V_235 ;
V_220 = F_80 ( V_2 , & V_10 -> V_229 ) ;
V_216 -> V_236 = V_220 >> 32 ;
V_216 -> V_237 = F_4 ( V_220 & 0xffffffff ) ;
V_101 = F_59 ( V_2 , V_204 , V_10 -> V_131 ) ;
if ( V_101 ) {
F_12 ( V_2 , L_56 , V_101 ) ;
goto V_230;
}
F_81 ( V_218 ) ;
F_82 ( V_2 , V_204 ) ;
V_10 -> V_14 = 0 ;
return V_101 ;
V_230:
F_83 ( V_2 , & V_10 -> V_229 ) ;
V_228:
F_84 ( & V_40 -> V_181 . V_227 , V_10 -> V_131 , V_238 ) ;
V_225:
for ( V_42 = 0 ; V_42 < V_217 ; ++ V_42 )
if ( V_10 -> V_22 [ V_42 ] . V_24 )
F_85 ( & V_2 -> V_212 -> V_2 , V_23 ,
V_10 -> V_22 [ V_42 ] . V_24 ,
V_10 -> V_22 [ V_42 ] . V_226 ) ;
F_82 ( V_2 , V_204 ) ;
V_224:
F_81 ( V_10 -> V_22 ) ;
F_81 ( V_218 ) ;
V_223:
return V_101 ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_189 * V_204 ;
int V_101 ;
int V_42 ;
int V_217 = F_71 ( ( V_21 << V_2 -> V_5 . V_18 ) * V_10 -> V_20 ) / V_23 ;
V_204 = F_73 ( V_2 ) ;
if ( F_74 ( V_204 ) )
return;
V_101 = F_60 ( V_2 , V_204 , V_10 -> V_131 ) ;
if ( V_101 )
F_12 ( V_2 , L_57 , V_101 ) ;
if ( 0 ) {
F_22 ( V_2 , L_58 , V_10 -> V_131 ) ;
for ( V_42 = 0 ; V_42 < sizeof ( struct V_215 ) / 4 ; ++ V_42 ) {
if ( V_42 % 4 == 0 )
F_87 ( L_59 , V_42 * 4 ) ;
F_87 ( L_60 , F_88 ( V_204 -> V_24 + V_42 * 4 ) ) ;
if ( ( V_42 + 1 ) % 4 == 0 )
F_87 ( L_61 ) ;
}
}
F_83 ( V_2 , & V_10 -> V_229 ) ;
for ( V_42 = 0 ; V_42 < V_217 ; ++ V_42 )
F_85 ( & V_2 -> V_212 -> V_2 , V_23 ,
V_10 -> V_22 [ V_42 ] . V_24 ,
V_10 -> V_22 [ V_42 ] . V_226 ) ;
F_81 ( V_10 -> V_22 ) ;
F_84 ( & V_40 -> V_181 . V_227 , V_10 -> V_131 , V_238 ) ;
F_82 ( V_2 , V_204 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_239 * V_181 = & V_39 ( V_2 ) -> V_181 ;
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_42 , V_240 ;
if ( V_181 -> V_241 )
F_90 ( V_2 -> V_212 -> V_179 , V_2 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_184 + 1 ; ++ V_42 )
if ( V_181 -> V_10 [ V_42 ] . V_241 ) {
F_90 ( V_181 -> V_10 [ V_42 ] . V_179 , V_181 -> V_10 + V_42 ) ;
V_181 -> V_10 [ V_42 ] . V_241 = 0 ;
}
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_209 ; V_42 ++ ) {
if ( V_40 -> V_242 . V_243 & 1ULL << V_42 ) {
V_240 = V_2 -> V_5 . V_184 + 1 + V_42 ;
F_90 ( V_40 -> V_181 . V_10 [ V_240 ] . V_179 ,
& V_40 -> V_181 . V_10 [ V_240 ] ) ;
}
}
F_81 ( V_181 -> V_244 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
V_40 -> V_245 = F_64 ( F_65 ( V_2 -> V_212 , V_40 -> V_246 . V_247 ) +
V_40 -> V_246 . V_248 , V_249 ) ;
if ( ! V_40 -> V_245 ) {
F_51 ( V_2 , L_62 ) ;
return - V_221 ;
}
return 0 ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
F_67 ( V_40 -> V_245 ) ;
}
int F_93 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
V_40 -> V_181 . V_10 = F_94 ( V_2 -> V_5 . V_250 - V_2 -> V_5 . V_208 ,
sizeof * V_40 -> V_181 . V_10 , V_222 ) ;
if ( ! V_40 -> V_181 . V_10 )
return - V_221 ;
return 0 ;
}
void F_95 ( struct V_1 * V_2 )
{
F_81 ( V_39 ( V_2 ) -> V_181 . V_10 ) ;
}
int F_96 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_101 ;
int V_42 ;
V_40 -> V_181 . V_211 = F_94 ( F_62 ( V_2 ) ,
sizeof * V_40 -> V_181 . V_211 ,
V_222 ) ;
if ( ! V_40 -> V_181 . V_211 ) {
V_101 = - V_221 ;
goto V_224;
}
V_101 = F_97 ( & V_40 -> V_181 . V_227 , V_2 -> V_5 . V_250 ,
V_2 -> V_5 . V_250 - 1 , V_2 -> V_5 . V_208 , 0 ) ;
if ( V_101 )
goto V_224;
for ( V_42 = 0 ; V_42 < F_62 ( V_2 ) ; ++ V_42 )
V_40 -> V_181 . V_211 [ V_42 ] = NULL ;
if ( ! F_98 ( V_2 ) ) {
V_101 = F_91 ( V_2 ) ;
if ( V_101 )
goto V_251;
V_40 -> V_181 . V_182 =
F_99 ( 1 << ( V_40 -> V_181 . V_252 & 31 ) ) ;
V_40 -> V_181 . V_183 = V_40 -> V_245 +
( V_40 -> V_181 . V_252 < 32 ? 4 : 0 ) ;
}
V_40 -> V_181 . V_244 =
F_72 ( V_253 * ( V_2 -> V_5 . V_184 + 1 +
V_2 -> V_5 . V_209 ) ,
V_222 ) ;
if ( ! V_40 -> V_181 . V_244 ) {
V_101 = - V_221 ;
goto V_251;
}
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_184 ; ++ V_42 ) {
V_101 = F_68 ( V_2 , V_2 -> V_5 . V_254 -
V_2 -> V_5 . V_255 +
V_178 ,
( V_2 -> V_6 & V_256 ) ? V_42 : 0 ,
& V_40 -> V_181 . V_10 [ V_42 ] ) ;
if ( V_101 ) {
-- V_42 ;
goto V_257;
}
}
V_101 = F_68 ( V_2 , V_258 + V_178 ,
( V_2 -> V_6 & V_256 ) ? V_2 -> V_5 . V_184 : 0 ,
& V_40 -> V_181 . V_10 [ V_2 -> V_5 . V_184 ] ) ;
if ( V_101 )
goto V_259;
for ( V_42 = V_2 -> V_5 . V_184 + 1 ;
V_42 < V_2 -> V_5 . V_184 + V_2 -> V_5 . V_209 + 1 ; ++ V_42 ) {
V_101 = F_68 ( V_2 , V_2 -> V_5 . V_254 -
V_2 -> V_5 . V_255 +
V_178 ,
( V_2 -> V_6 & V_256 ) ? V_42 : 0 ,
& V_40 -> V_181 . V_10 [ V_42 ] ) ;
if ( V_101 ) {
-- V_42 ;
goto V_257;
}
}
if ( V_2 -> V_6 & V_256 ) {
const char * V_260 ;
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_184 + 1 ; ++ V_42 ) {
if ( V_42 < V_2 -> V_5 . V_184 ) {
snprintf ( V_40 -> V_181 . V_244 +
V_42 * V_253 ,
V_253 ,
L_63 , V_42 ,
F_100 ( V_2 -> V_212 ) ) ;
} else {
snprintf ( V_40 -> V_181 . V_244 +
V_42 * V_253 ,
V_253 ,
L_64 ,
F_100 ( V_2 -> V_212 ) ) ;
}
V_260 = V_40 -> V_181 . V_244 +
V_42 * V_253 ;
V_101 = F_101 ( V_40 -> V_181 . V_10 [ V_42 ] . V_179 ,
F_56 , 0 , V_260 ,
V_40 -> V_181 . V_10 + V_42 ) ;
if ( V_101 )
goto V_261;
V_40 -> V_181 . V_10 [ V_42 ] . V_241 = 1 ;
}
} else {
snprintf ( V_40 -> V_181 . V_244 ,
V_253 ,
V_262 L_65 ,
F_100 ( V_2 -> V_212 ) ) ;
V_101 = F_101 ( V_2 -> V_212 -> V_179 , F_53 ,
V_263 , V_40 -> V_181 . V_244 , V_2 ) ;
if ( V_101 )
goto V_261;
V_40 -> V_181 . V_241 = 1 ;
}
V_101 = F_58 ( V_2 , F_1 ( V_2 ) , 0 ,
V_40 -> V_181 . V_10 [ V_2 -> V_5 . V_184 ] . V_131 ) ;
if ( V_101 )
F_12 ( V_2 , L_66 ,
V_40 -> V_181 . V_10 [ V_2 -> V_5 . V_184 ] . V_131 , V_101 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_184 + 1 ; ++ V_42 )
F_2 ( & V_40 -> V_181 . V_10 [ V_42 ] , 1 ) ;
return 0 ;
V_261:
F_86 ( V_2 , & V_40 -> V_181 . V_10 [ V_2 -> V_5 . V_184 ] ) ;
V_259:
V_42 = V_2 -> V_5 . V_184 - 1 ;
V_257:
while ( V_42 >= 0 ) {
F_86 ( V_2 , & V_40 -> V_181 . V_10 [ V_42 ] ) ;
-- V_42 ;
}
if ( ! F_98 ( V_2 ) )
F_92 ( V_2 ) ;
F_89 ( V_2 ) ;
V_251:
F_66 ( V_2 ) ;
F_102 ( & V_40 -> V_181 . V_227 ) ;
V_224:
F_81 ( V_40 -> V_181 . V_211 ) ;
return V_101 ;
}
void F_103 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_42 ;
F_58 ( V_2 , F_1 ( V_2 ) , 1 ,
V_40 -> V_181 . V_10 [ V_2 -> V_5 . V_184 ] . V_131 ) ;
F_89 ( V_2 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_184 + V_2 -> V_5 . V_209 + 1 ; ++ V_42 )
F_86 ( V_2 , & V_40 -> V_181 . V_10 [ V_42 ] ) ;
if ( ! F_98 ( V_2 ) )
F_92 ( V_2 ) ;
F_66 ( V_2 ) ;
F_102 ( & V_40 -> V_181 . V_227 ) ;
F_81 ( V_40 -> V_181 . V_211 ) ;
}
int F_104 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_42 ;
int V_101 ;
V_101 = F_105 ( V_2 ) ;
if ( ! ( V_2 -> V_6 & V_256 ) || F_98 ( V_2 ) )
return V_101 ;
for( V_42 = 0 ; ! V_101 && ( V_42 < V_2 -> V_5 . V_184 ) ; ++ V_42 ) {
F_106 ( V_2 ) ;
V_101 = F_58 ( V_2 , F_1 ( V_2 ) , 0 ,
V_40 -> V_181 . V_10 [ V_42 ] . V_131 ) ;
if ( V_101 ) {
F_12 ( V_2 , L_67 ) ;
F_107 ( V_2 ) ;
break;
}
F_107 ( V_2 ) ;
V_101 = F_105 ( V_2 ) ;
}
F_58 ( V_2 , F_1 ( V_2 ) , 0 ,
V_40 -> V_181 . V_10 [ V_2 -> V_5 . V_184 ] . V_131 ) ;
return V_101 ;
}
int F_108 ( struct V_1 * V_2 , char * V_264 , struct V_265 * V_266 ,
int * V_267 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_240 = 0 , V_101 = 0 , V_42 ;
F_109 ( & V_40 -> V_242 . V_268 ) ;
for ( V_42 = 0 ; ! V_240 && V_42 < V_2 -> V_5 . V_209 ; V_42 ++ ) {
if ( ~ V_40 -> V_242 . V_243 & 1ULL << V_42 ) {
V_40 -> V_242 . V_243 |= 1ULL << V_42 ;
V_240 = V_2 -> V_5 . V_184 + 1 + V_42 ;
snprintf ( V_40 -> V_181 . V_244 +
V_240 * V_253 ,
V_253 , L_68 , V_264 ) ;
#ifdef F_110
if ( V_266 ) {
V_101 = F_111 ( V_266 ,
V_40 -> V_181 . V_10 [ V_240 ] . V_179 ) ;
if ( V_101 )
F_12 ( V_2 , L_69 ) ;
}
#endif
V_101 = F_101 ( V_40 -> V_181 . V_10 [ V_240 ] . V_179 ,
F_56 , 0 ,
& V_40 -> V_181 . V_244 [ V_240 << 5 ] ,
V_40 -> V_181 . V_10 + V_240 ) ;
if ( V_101 ) {
V_40 -> V_242 . V_243 ^= 1 << V_42 ;
V_240 = 0 ;
continue;
}
F_2 ( & V_40 -> V_181 . V_10 [ V_240 ] , 1 ) ;
}
}
F_112 ( & V_40 -> V_242 . V_268 ) ;
if ( V_240 ) {
* V_267 = V_240 ;
} else {
* V_267 = 0 ;
V_101 = ( V_42 == V_2 -> V_5 . V_209 ) ? - V_269 : V_101 ;
}
return V_101 ;
}
void F_113 ( struct V_1 * V_2 , int V_240 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_42 = V_240 - V_2 -> V_5 . V_184 - 1 ;
if ( F_114 ( V_42 >= 0 ) ) {
F_109 ( & V_40 -> V_242 . V_268 ) ;
if ( V_40 -> V_242 . V_243 & 1ULL << V_42 ) {
F_90 ( V_40 -> V_181 . V_10 [ V_240 ] . V_179 ,
& V_40 -> V_181 . V_10 [ V_240 ] ) ;
V_40 -> V_242 . V_243 &= ~ ( 1ULL << V_42 ) ;
}
F_112 ( & V_40 -> V_242 . V_268 ) ;
}
}
