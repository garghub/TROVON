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
if ( V_41 >= V_2 -> V_45 || V_56 > V_69 ) {
F_24 ( L_8 ,
V_66 , V_41 , V_56 ) ;
return V_70 ;
}
return V_68 [ V_41 ] . V_71 [ V_56 ] ;
}
static int F_25 ( struct V_1 * V_2 , int V_41 , T_2 V_56 ,
enum V_67 V_72 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_54 * V_68 = V_40 -> V_38 . V_35 . V_47 ;
if ( V_41 >= V_2 -> V_45 || V_56 > V_69 || V_56 == 0 ) {
F_24 ( L_8 ,
V_66 , V_41 , V_56 ) ;
return - 1 ;
}
V_68 [ V_41 ] . V_71 [ V_56 ] = V_72 ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 , T_2 V_56 , int V_59 )
{
int V_42 ;
enum V_73 V_74 ;
for ( V_42 = 0 ; V_42 < V_2 -> V_45 ; V_42 ++ )
F_27 ( V_2 , V_42 , V_56 , V_59 , & V_74 ) ;
}
int F_27 ( struct V_1 * V_2 , int V_41 ,
T_2 V_56 , int V_59 ,
enum V_73 * V_74 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_54 * V_75 = NULL ;
unsigned long V_6 ;
int V_76 = - 1 ;
enum V_67 V_77 =
F_23 ( V_2 , V_41 , V_56 ) ;
* V_74 = V_78 ;
if ( V_41 >= V_2 -> V_45 || V_56 > V_69 || V_56 == 0 ) {
F_24 ( L_8 ,
V_66 , V_41 , V_56 ) ;
return V_76 ;
}
V_75 = & V_40 -> V_38 . V_35 . V_47 [ V_41 ] ;
F_14 ( & V_75 -> V_79 , V_6 ) ;
switch ( V_77 ) {
case V_70 :
if ( V_80 == V_59 )
F_25 ( V_2 , V_41 , V_56 ,
V_81 ) ;
break;
case V_81 :
if ( V_82 == V_59 )
F_25 ( V_2 , V_41 , V_56 ,
V_70 ) ;
else if ( V_83 == V_59 ) {
F_25 ( V_2 , V_41 , V_56 ,
V_84 ) ;
* V_74 = V_85 ;
}
break;
case V_84 :
if ( V_82 == V_59 ) {
F_25 ( V_2 , V_41 , V_56 ,
V_70 ) ;
* V_74 = V_86 ;
} else if ( V_87 ==
V_59 ) {
F_25 ( V_2 , V_41 , V_56 ,
V_81 ) ;
* V_74 = V_86 ;
}
break;
default:
F_24 ( L_9
L_10 , V_66 , V_41 , V_56 ) ;
goto V_88;
}
V_76 = F_23 ( V_2 , V_41 , V_56 ) ;
V_88:
F_15 ( & V_75 -> V_79 , V_6 ) ;
return V_76 ;
}
int F_28 ( struct V_1 * V_2 , T_2 V_56 , int V_89 )
{
struct V_16 V_25 ;
memset ( & V_25 , 0 , sizeof V_25 ) ;
V_25 . type = V_8 ;
V_25 . V_57 = V_90 ;
V_25 . V_59 . V_60 . V_56 = V_56 ;
V_25 . V_59 . V_60 . V_91 . V_92 . V_93 =
F_4 ( ( V_13 ) V_89 ) ;
F_13 ( V_2 , V_44 , & V_25 ) ;
return 0 ;
}
void F_29 ( struct V_32 * V_33 )
{
struct V_34 * V_35 =
F_10 ( V_33 , struct V_34 ,
V_94 ) ;
struct V_37 * V_38 =
F_10 ( V_35 , struct V_37 , V_35 ) ;
struct V_39 * V_40 =
F_10 ( V_38 , struct V_39 , V_38 ) ;
struct V_1 * V_2 = & V_40 -> V_2 ;
struct V_54 * V_47 = V_40 -> V_38 . V_35 . V_47 ;
int V_42 ;
int V_95 ;
unsigned long V_6 ;
F_22 ( V_2 , L_11 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_45 ; V_42 ++ ) {
if ( V_96 == V_47 [ V_42 ] . V_97 ) {
F_22 ( V_2 , L_12
L_13 , V_42 ) ;
F_30 ( V_2 , V_42 ) ;
F_14 ( & V_40 -> V_38 . V_35 . V_98 , V_6 ) ;
V_47 [ V_42 ] . V_97 = V_99 ;
V_47 [ V_42 ] . V_100 = 0 ;
F_15 ( & V_40 -> V_38 . V_35 . V_98 , V_6 ) ;
V_95 = F_31 ( V_2 , 0 , V_42 , 0 , V_101 ,
V_102 , V_103 ) ;
if ( V_95 )
F_12 ( V_2 , L_14
L_15 , V_42 ) ;
}
}
}
static int F_32 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_16 * V_25 ;
int V_104 ;
int V_105 = 0 ;
int V_106 = 0 ;
int V_56 ;
int V_41 = 0 ;
int V_76 ;
V_13 V_107 ;
T_2 V_108 ;
int V_42 ;
enum V_73 V_74 ;
unsigned long V_6 ;
struct V_109 * V_110 ;
while ( ( V_25 = F_7 ( V_10 , V_2 -> V_5 . V_18 ) ) ) {
F_33 () ;
switch ( V_25 -> type ) {
case V_111 :
V_104 = F_34 ( V_25 -> V_59 . V_112 . V_104 ) & 0xffffff ;
F_35 ( V_2 , V_104 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
F_22 ( V_2 , L_16 , V_25 -> type ) ;
if ( F_36 ( V_2 ) ) {
V_76 = F_37 ( V_2 ,
V_121 ,
F_34 ( V_25 -> V_59 . V_122 . V_123 )
& 0xffffff , & V_41 ) ;
if ( V_76 && V_76 != - V_124 ) {
F_22 ( V_2 , L_17
L_18
L_19 ,
V_25 -> type , V_25 -> V_57 ,
V_10 -> V_125 , V_10 -> V_14 , V_76 ) ;
break;
}
if ( ! V_76 && V_41 != V_2 -> V_5 . V_46 ) {
F_18 ( V_2 , V_41 , V_25 ) ;
break;
}
}
F_38 ( V_2 , F_34 ( V_25 -> V_59 . V_122 . V_123 ) &
0xffffff , V_25 -> type ) ;
break;
case V_126 :
F_22 ( V_2 , L_20 ,
V_66 ) ;
case V_127 :
if ( F_36 ( V_2 ) ) {
V_76 = F_37 ( V_2 ,
V_128 ,
F_34 ( V_25 -> V_59 . V_129 . V_130 )
& 0xffffff ,
& V_41 ) ;
if ( V_76 && V_76 != - V_124 ) {
F_12 ( V_2 , L_21
L_22
L_23 ,
V_25 -> type , V_25 -> V_57 ,
V_10 -> V_125 , V_10 -> V_14 , V_76 ) ;
break;
}
F_12 ( V_2 , L_24
L_25 , V_66 ,
V_41 ,
F_34 ( V_25 -> V_59 . V_129 . V_130 ) ,
V_25 -> type , V_25 -> V_57 ) ;
if ( ! V_76 && V_41 != V_2 -> V_5 . V_46 ) {
F_12 ( V_2 , L_26
L_27 ,
V_66 , V_25 -> type ,
V_25 -> V_57 , V_41 ) ;
F_18 ( V_2 , V_41 , V_25 ) ;
break;
}
}
F_39 ( V_2 , F_34 ( V_25 -> V_59 . V_129 . V_130 ) &
0xffffff , V_25 -> type ) ;
break;
case V_131 :
F_40 ( V_2 ,
F_41 ( V_25 -> V_59 . V_132 . V_133 ) ,
V_25 -> V_59 . V_132 . V_134 ,
F_42 ( V_25 -> V_59 . V_132 . V_135 ) ) ;
break;
case V_64 :
V_56 = F_34 ( V_25 -> V_59 . V_65 . V_56 ) >> 28 ;
if ( V_25 -> V_57 == V_136 ) {
F_43 ( V_2 , V_137 ,
V_56 ) ;
V_39 ( V_2 ) -> V_138 . V_139 [ V_56 ] = 1 ;
if ( ! F_36 ( V_2 ) )
break;
for ( V_42 = 0 ; V_42 < V_2 -> V_45 ; V_42 ++ ) {
if ( V_2 -> V_5 . V_140 [ V_56 ] == V_141 ) {
if ( V_42 == F_44 ( V_2 ) )
continue;
F_22 ( V_2 , L_28
L_29 ,
V_66 , V_42 , V_56 ) ;
V_110 = & V_40 -> V_38 . V_35 . V_142 [ V_41 ] . V_143 [ V_56 ] . V_72 ;
if ( V_144 == V_110 -> V_145 )
F_18 ( V_2 , V_42 , V_25 ) ;
} else {
F_27 ( V_2 , V_42 , V_56 ,
V_82 ,
& V_74 ) ;
if ( V_86 == V_74 ) {
if ( V_42 == F_44 ( V_2 ) )
continue;
F_18 ( V_2 , V_42 , V_25 ) ;
}
}
}
} else {
F_43 ( V_2 , V_146 , V_56 ) ;
V_39 ( V_2 ) -> V_138 . V_139 [ V_56 ] = 0 ;
if ( ! F_36 ( V_2 ) )
break;
if ( V_2 -> V_5 . V_140 [ V_56 ] == V_141 )
for ( V_42 = 0 ; V_42 < V_2 -> V_45 ; V_42 ++ ) {
if ( V_42 == F_44 ( V_2 ) )
continue;
V_110 = & V_40 -> V_38 . V_35 . V_142 [ V_41 ] . V_143 [ V_56 ] . V_72 ;
if ( V_144 == V_110 -> V_145 )
F_18 ( V_2 , V_42 , V_25 ) ;
}
else
F_26 ( V_2 , V_56 , V_146 ) ;
}
break;
case V_147 :
F_12 ( V_2 , L_30 ,
V_25 -> V_59 . V_148 . V_149 == 1 ?
L_31 : L_32 ,
F_34 ( V_25 -> V_59 . V_148 . V_104 ) & 0xffffff ) ;
if ( F_36 ( V_2 ) ) {
V_76 = F_37 ( V_2 ,
V_150 ,
F_34 ( V_25 -> V_59 . V_148 . V_104 )
& 0xffffff , & V_41 ) ;
if ( V_76 && V_76 != - V_124 ) {
F_22 ( V_2 , L_33
L_18
L_19 ,
V_25 -> type , V_25 -> V_57 ,
V_10 -> V_125 , V_10 -> V_14 , V_76 ) ;
break;
}
if ( ! V_76 && V_41 != V_2 -> V_5 . V_46 ) {
F_18 ( V_2 , V_41 , V_25 ) ;
break;
}
}
F_45 ( V_2 ,
F_34 ( V_25 -> V_59 . V_148 . V_104 )
& 0xffffff ,
V_25 -> type ) ;
break;
case V_151 :
F_12 ( V_2 , L_34 , V_10 -> V_125 ) ;
break;
case V_152 :
F_46 ( & V_40 -> V_153 ) ;
F_17 ( V_154 , & V_40 -> V_155 ) ;
break;
case V_156 :
if ( ! F_36 ( V_2 ) ) {
F_12 ( V_2 , L_35
L_36 ) ;
break;
}
memcpy ( & V_40 -> V_38 . V_35 . V_157 ,
V_25 -> V_59 . V_158 . V_159 ,
sizeof V_25 -> V_59 . V_158 . V_159 ) ;
F_17 ( V_40 -> V_38 . V_35 . V_53 ,
& V_40 -> V_38 . V_35 . V_160 ) ;
break;
case V_161 :
V_107 = F_34 ( V_25 -> V_59 . V_162 . V_43 ) ;
if ( ! F_36 ( V_2 ) ) {
F_12 ( V_2 , L_37
L_38 ) ;
break;
}
F_22 ( V_2 , L_39 , V_107 ) ;
if ( V_107 >= V_2 -> V_45 ) {
F_12 ( V_2 ,
L_40 ,
V_107 ) ;
V_108 = 0 ;
} else
V_108 = 1 ;
F_14 ( & V_40 -> V_38 . V_35 . V_98 , V_6 ) ;
if ( V_108 ) {
V_40 -> V_38 . V_35 . V_47 [ V_107 ] . V_48 = false ;
V_40 -> V_38 . V_35 . V_47 [ V_107 ] . V_97 = V_96 ;
V_40 -> V_38 . V_35 . V_47 [ V_107 ] . V_100 = 1 ;
}
F_15 ( & V_40 -> V_38 . V_35 . V_98 , V_6 ) ;
F_17 ( V_40 -> V_38 . V_35 . V_53 ,
& V_40 -> V_38 . V_35 . V_94 ) ;
break;
case V_163 :
if ( V_25 -> V_57 == V_164 ) {
if ( F_36 ( V_2 ) )
for ( V_42 = 0 ; V_42 < V_2 -> V_45 ; V_42 ++ ) {
F_22 ( V_2 , L_41
L_42
L_43 , V_66 , V_42 ) ;
if ( V_42 == V_2 -> V_5 . V_46 )
continue;
F_18 ( V_2 , V_42 , V_25 ) ;
}
F_47 ( V_2 , L_44
L_45
L_46 ,
F_41 ( V_25 -> V_59 . V_165 . V_166 ) ,
F_41 ( V_25 -> V_59 . V_165 . V_167 ) ) ;
} else
F_12 ( V_2 , L_47
L_48
L_49 ,
V_25 -> type , V_25 -> V_57 , V_10 -> V_125 ,
V_10 -> V_14 , V_25 -> V_26 , V_10 -> V_20 ,
V_25 -> V_43 ,
! ! ( V_25 -> V_26 & 0x80 ) ^
! ! ( V_10 -> V_14 & V_10 -> V_20 ) ? L_50 : L_51 ) ;
break;
case V_8 :
F_43 ( V_2 , V_168 ,
( unsigned long ) V_25 ) ;
break;
case V_169 :
case V_170 :
default:
F_12 ( V_2 , L_52
L_53
L_54 ,
V_25 -> type , V_25 -> V_57 , V_10 -> V_125 ,
V_10 -> V_14 , V_25 -> V_26 , V_10 -> V_20 ,
V_25 -> V_43 ,
! ! ( V_25 -> V_26 & 0x80 ) ^
! ! ( V_10 -> V_14 & V_10 -> V_20 ) ? L_50 : L_51 ) ;
break;
} ;
++ V_10 -> V_14 ;
V_105 = 1 ;
++ V_106 ;
if ( F_48 ( V_106 >= V_171 ) ) {
F_2 ( V_10 , 0 ) ;
V_106 = 0 ;
}
}
F_2 ( V_10 , 1 ) ;
return V_105 ;
}
static T_3 F_49 ( int V_172 , void * V_173 )
{
struct V_1 * V_2 = V_173 ;
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_33 = 0 ;
int V_42 ;
F_50 ( V_40 -> V_174 . V_175 , V_40 -> V_174 . V_176 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_177 + 1 ; ++ V_42 )
V_33 |= F_32 ( V_2 , & V_40 -> V_174 . V_10 [ V_42 ] ) ;
return F_51 ( V_33 ) ;
}
static T_3 F_52 ( int V_172 , void * V_178 )
{
struct V_9 * V_10 = V_178 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_32 ( V_2 , V_10 ) ;
return V_179 ;
}
int F_53 ( struct V_1 * V_2 , int V_41 ,
struct V_180 * V_181 ,
struct V_182 * V_183 ,
struct V_182 * V_184 ,
struct V_185 * V_132 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_186 * V_187 =
V_40 -> V_38 . V_35 . V_47 [ V_41 ] . V_187 ;
V_13 V_188 = V_181 -> V_188 ;
V_13 V_125 = V_188 & 0x3FF ;
T_1 V_189 = V_181 -> V_189 ;
int V_95 = 0 ;
int V_42 ;
if ( V_41 == V_2 -> V_5 . V_46 )
V_95 = F_31 ( V_2 , V_189 , ( V_188 & 0x80000000 ) | V_125 ,
0 , V_190 , V_191 ,
V_192 ) ;
if ( ! V_95 )
for ( V_42 = 0 ; V_42 < V_193 ; ++ V_42 )
if ( V_189 & ( 1LL << V_42 ) )
V_187 [ V_42 ] . V_125 = V_188 >> 31 ? - 1 : V_125 ;
return V_95 ;
}
static int F_54 ( struct V_1 * V_2 , T_1 V_194 , int V_195 ,
int V_196 )
{
return F_31 ( V_2 , V_194 , ( V_195 << 31 ) | V_196 ,
0 , V_190 , V_191 ,
V_103 ) ;
}
static int F_55 ( struct V_1 * V_2 , struct V_182 * V_197 ,
int V_196 )
{
return F_31 ( V_2 , V_197 -> V_198 , V_196 , 0 ,
V_199 , V_102 ,
V_103 ) ;
}
static int F_56 ( struct V_1 * V_2 , struct V_182 * V_197 ,
int V_196 )
{
return F_57 ( V_2 , 0 , V_197 -> V_198 , V_196 ,
0 , V_200 , V_102 ,
V_103 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_177 + 1 + V_2 -> V_5 . V_201 +
V_2 -> V_5 . V_202 ) / 4 - V_2 -> V_5 . V_201 / 4 + 1 ;
}
static void T_4 * F_59 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_203 ;
V_203 = V_10 -> V_125 / 4 - V_2 -> V_5 . V_201 / 4 ;
if ( ! V_40 -> V_174 . V_204 [ V_203 ] ) {
V_40 -> V_174 . V_204 [ V_203 ] =
F_60 ( F_61 ( V_2 -> V_205 , 2 ) +
( ( V_10 -> V_125 / 4 ) << V_206 ) ,
V_23 ) ;
if ( ! V_40 -> V_174 . V_204 [ V_203 ] ) {
F_47 ( V_2 , L_55 ,
V_10 -> V_125 ) ;
return NULL ;
}
}
return V_40 -> V_174 . V_204 [ V_203 ] + 0x800 + 8 * ( V_10 -> V_125 % 4 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < F_58 ( V_2 ) ; ++ V_42 )
if ( V_40 -> V_174 . V_204 [ V_42 ] ) {
F_63 ( V_40 -> V_174 . V_204 [ V_42 ] ) ;
V_40 -> V_174 . V_204 [ V_42 ] = NULL ;
}
}
static int F_64 ( struct V_1 * V_2 , int V_20 ,
T_2 V_207 , struct V_9 * V_10 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_182 * V_197 ;
struct V_208 * V_209 ;
int V_210 ;
T_1 * V_211 = NULL ;
T_5 V_212 ;
T_1 V_213 ;
int V_95 = - V_214 ;
int V_42 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_20 = F_65 ( F_66 ( V_20 , 2 ) ) ;
V_210 = F_67 ( V_10 -> V_20 * ( V_21 << V_2 -> V_5 . V_18 ) ) / V_23 ;
V_10 -> V_22 = F_68 ( V_210 * sizeof * V_10 -> V_22 ,
V_215 ) ;
if ( ! V_10 -> V_22 )
goto V_216;
for ( V_42 = 0 ; V_42 < V_210 ; ++ V_42 )
V_10 -> V_22 [ V_42 ] . V_24 = NULL ;
V_211 = F_68 ( V_210 * sizeof *V_211 , V_215 ) ;
if ( ! V_211 )
goto V_217;
V_197 = F_69 ( V_2 ) ;
if ( F_70 ( V_197 ) )
goto V_217;
V_209 = V_197 -> V_24 ;
for ( V_42 = 0 ; V_42 < V_210 ; ++ V_42 ) {
V_10 -> V_22 [ V_42 ] . V_24 = F_71 ( & V_2 -> V_205 -> V_2 ,
V_23 , & V_212 , V_215 ) ;
if ( ! V_10 -> V_22 [ V_42 ] . V_24 )
goto V_218;
V_211 [ V_42 ] = V_212 ;
V_10 -> V_22 [ V_42 ] . V_219 = V_212 ;
memset ( V_10 -> V_22 [ V_42 ] . V_24 , 0 , V_23 ) ;
}
V_10 -> V_125 = F_72 ( & V_40 -> V_174 . V_220 ) ;
if ( V_10 -> V_125 == - 1 )
goto V_218;
V_10 -> V_15 = F_59 ( V_2 , V_10 ) ;
if ( ! V_10 -> V_15 ) {
V_95 = - V_214 ;
goto V_221;
}
V_95 = F_73 ( V_2 , V_210 , V_206 , & V_10 -> V_222 ) ;
if ( V_95 )
goto V_221;
V_95 = F_74 ( V_2 , & V_10 -> V_222 , 0 , V_210 , V_211 ) ;
if ( V_95 )
goto V_223;
V_209 -> V_6 = F_4 ( V_224 |
V_225 ) ;
V_209 -> V_226 = F_75 ( V_10 -> V_20 ) ;
V_209 -> V_207 = V_207 ;
V_209 -> V_227 = V_206 - V_228 ;
V_213 = F_76 ( V_2 , & V_10 -> V_222 ) ;
V_209 -> V_229 = V_213 >> 32 ;
V_209 -> V_230 = F_4 ( V_213 & 0xffffffff ) ;
V_95 = F_55 ( V_2 , V_197 , V_10 -> V_125 ) ;
if ( V_95 ) {
F_12 ( V_2 , L_56 , V_95 ) ;
goto V_223;
}
F_77 ( V_211 ) ;
F_78 ( V_2 , V_197 ) ;
V_10 -> V_14 = 0 ;
return V_95 ;
V_223:
F_79 ( V_2 , & V_10 -> V_222 ) ;
V_221:
F_80 ( & V_40 -> V_174 . V_220 , V_10 -> V_125 ) ;
V_218:
for ( V_42 = 0 ; V_42 < V_210 ; ++ V_42 )
if ( V_10 -> V_22 [ V_42 ] . V_24 )
F_81 ( & V_2 -> V_205 -> V_2 , V_23 ,
V_10 -> V_22 [ V_42 ] . V_24 ,
V_10 -> V_22 [ V_42 ] . V_219 ) ;
F_78 ( V_2 , V_197 ) ;
V_217:
F_77 ( V_10 -> V_22 ) ;
F_77 ( V_211 ) ;
V_216:
return V_95 ;
}
static void F_82 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_182 * V_197 ;
int V_95 ;
int V_42 ;
int V_210 = F_67 ( ( V_21 << V_2 -> V_5 . V_18 ) * V_10 -> V_20 ) / V_23 ;
V_197 = F_69 ( V_2 ) ;
if ( F_70 ( V_197 ) )
return;
V_95 = F_56 ( V_2 , V_197 , V_10 -> V_125 ) ;
if ( V_95 )
F_12 ( V_2 , L_57 , V_95 ) ;
if ( 0 ) {
F_22 ( V_2 , L_58 , V_10 -> V_125 ) ;
for ( V_42 = 0 ; V_42 < sizeof ( struct V_208 ) / 4 ; ++ V_42 ) {
if ( V_42 % 4 == 0 )
F_83 ( L_59 , V_42 * 4 ) ;
F_83 ( L_60 , F_84 ( V_197 -> V_24 + V_42 * 4 ) ) ;
if ( ( V_42 + 1 ) % 4 == 0 )
F_83 ( L_61 ) ;
}
}
F_79 ( V_2 , & V_10 -> V_222 ) ;
for ( V_42 = 0 ; V_42 < V_210 ; ++ V_42 )
F_81 ( & V_2 -> V_205 -> V_2 , V_23 ,
V_10 -> V_22 [ V_42 ] . V_24 ,
V_10 -> V_22 [ V_42 ] . V_219 ) ;
F_77 ( V_10 -> V_22 ) ;
F_80 ( & V_40 -> V_174 . V_220 , V_10 -> V_125 ) ;
F_78 ( V_2 , V_197 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_231 * V_174 = & V_39 ( V_2 ) -> V_174 ;
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_42 , V_232 ;
if ( V_174 -> V_233 )
F_86 ( V_2 -> V_205 -> V_172 , V_2 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_177 + 1 ; ++ V_42 )
if ( V_174 -> V_10 [ V_42 ] . V_233 ) {
F_86 ( V_174 -> V_10 [ V_42 ] . V_172 , V_174 -> V_10 + V_42 ) ;
V_174 -> V_10 [ V_42 ] . V_233 = 0 ;
}
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_202 ; V_42 ++ ) {
if ( V_40 -> V_234 . V_235 & 1ULL << V_42 ) {
V_232 = V_2 -> V_5 . V_177 + 1 + V_42 ;
F_86 ( V_40 -> V_174 . V_10 [ V_232 ] . V_172 ,
& V_40 -> V_174 . V_10 [ V_232 ] ) ;
}
}
F_77 ( V_174 -> V_236 ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
V_40 -> V_237 = F_60 ( F_61 ( V_2 -> V_205 , V_40 -> V_238 . V_239 ) +
V_40 -> V_238 . V_240 , V_241 ) ;
if ( ! V_40 -> V_237 ) {
F_47 ( V_2 , L_62 ) ;
return - V_214 ;
}
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
F_63 ( V_40 -> V_237 ) ;
}
int F_89 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
V_40 -> V_174 . V_10 = F_90 ( V_2 -> V_5 . V_242 - V_2 -> V_5 . V_201 ,
sizeof * V_40 -> V_174 . V_10 , V_215 ) ;
if ( ! V_40 -> V_174 . V_10 )
return - V_214 ;
return 0 ;
}
void F_91 ( struct V_1 * V_2 )
{
F_77 ( V_39 ( V_2 ) -> V_174 . V_10 ) ;
}
int F_92 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_95 ;
int V_42 ;
V_40 -> V_174 . V_204 = F_90 ( F_58 ( V_2 ) ,
sizeof * V_40 -> V_174 . V_204 ,
V_215 ) ;
if ( ! V_40 -> V_174 . V_204 ) {
V_95 = - V_214 ;
goto V_217;
}
V_95 = F_93 ( & V_40 -> V_174 . V_220 , V_2 -> V_5 . V_242 ,
V_2 -> V_5 . V_242 - 1 , V_2 -> V_5 . V_201 , 0 ) ;
if ( V_95 )
goto V_217;
for ( V_42 = 0 ; V_42 < F_58 ( V_2 ) ; ++ V_42 )
V_40 -> V_174 . V_204 [ V_42 ] = NULL ;
if ( ! F_94 ( V_2 ) ) {
V_95 = F_87 ( V_2 ) ;
if ( V_95 )
goto V_243;
V_40 -> V_174 . V_175 =
F_95 ( 1 << ( V_40 -> V_174 . V_244 & 31 ) ) ;
V_40 -> V_174 . V_176 = V_40 -> V_237 +
( V_40 -> V_174 . V_244 < 32 ? 4 : 0 ) ;
}
V_40 -> V_174 . V_236 =
F_68 ( V_245 * ( V_2 -> V_5 . V_177 + 1 +
V_2 -> V_5 . V_202 ) ,
V_215 ) ;
if ( ! V_40 -> V_174 . V_236 ) {
V_95 = - V_214 ;
goto V_243;
}
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_177 ; ++ V_42 ) {
V_95 = F_64 ( V_2 , V_2 -> V_5 . V_246 -
V_2 -> V_5 . V_247 +
V_171 ,
( V_2 -> V_6 & V_248 ) ? V_42 : 0 ,
& V_40 -> V_174 . V_10 [ V_42 ] ) ;
if ( V_95 ) {
-- V_42 ;
goto V_249;
}
}
V_95 = F_64 ( V_2 , V_250 + V_171 ,
( V_2 -> V_6 & V_248 ) ? V_2 -> V_5 . V_177 : 0 ,
& V_40 -> V_174 . V_10 [ V_2 -> V_5 . V_177 ] ) ;
if ( V_95 )
goto V_251;
for ( V_42 = V_2 -> V_5 . V_177 + 1 ;
V_42 < V_2 -> V_5 . V_177 + V_2 -> V_5 . V_202 + 1 ; ++ V_42 ) {
V_95 = F_64 ( V_2 , V_2 -> V_5 . V_246 -
V_2 -> V_5 . V_247 +
V_171 ,
( V_2 -> V_6 & V_248 ) ? V_42 : 0 ,
& V_40 -> V_174 . V_10 [ V_42 ] ) ;
if ( V_95 ) {
-- V_42 ;
goto V_249;
}
}
if ( V_2 -> V_6 & V_248 ) {
const char * V_252 ;
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_177 + 1 ; ++ V_42 ) {
if ( V_42 < V_2 -> V_5 . V_177 ) {
snprintf ( V_40 -> V_174 . V_236 +
V_42 * V_245 ,
V_245 ,
L_63 , V_42 ,
F_96 ( V_2 -> V_205 ) ) ;
} else {
snprintf ( V_40 -> V_174 . V_236 +
V_42 * V_245 ,
V_245 ,
L_64 ,
F_96 ( V_2 -> V_205 ) ) ;
}
V_252 = V_40 -> V_174 . V_236 +
V_42 * V_245 ;
V_95 = F_97 ( V_40 -> V_174 . V_10 [ V_42 ] . V_172 ,
F_52 , 0 , V_252 ,
V_40 -> V_174 . V_10 + V_42 ) ;
if ( V_95 )
goto V_253;
V_40 -> V_174 . V_10 [ V_42 ] . V_233 = 1 ;
}
} else {
snprintf ( V_40 -> V_174 . V_236 ,
V_245 ,
V_254 L_65 ,
F_96 ( V_2 -> V_205 ) ) ;
V_95 = F_97 ( V_2 -> V_205 -> V_172 , F_49 ,
V_255 , V_40 -> V_174 . V_236 , V_2 ) ;
if ( V_95 )
goto V_253;
V_40 -> V_174 . V_233 = 1 ;
}
V_95 = F_54 ( V_2 , F_1 ( V_2 ) , 0 ,
V_40 -> V_174 . V_10 [ V_2 -> V_5 . V_177 ] . V_125 ) ;
if ( V_95 )
F_12 ( V_2 , L_66 ,
V_40 -> V_174 . V_10 [ V_2 -> V_5 . V_177 ] . V_125 , V_95 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_177 + 1 ; ++ V_42 )
F_2 ( & V_40 -> V_174 . V_10 [ V_42 ] , 1 ) ;
return 0 ;
V_253:
F_82 ( V_2 , & V_40 -> V_174 . V_10 [ V_2 -> V_5 . V_177 ] ) ;
V_251:
V_42 = V_2 -> V_5 . V_177 - 1 ;
V_249:
while ( V_42 >= 0 ) {
F_82 ( V_2 , & V_40 -> V_174 . V_10 [ V_42 ] ) ;
-- V_42 ;
}
if ( ! F_94 ( V_2 ) )
F_88 ( V_2 ) ;
F_85 ( V_2 ) ;
V_243:
F_62 ( V_2 ) ;
F_98 ( & V_40 -> V_174 . V_220 ) ;
V_217:
F_77 ( V_40 -> V_174 . V_204 ) ;
return V_95 ;
}
void F_99 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_42 ;
F_54 ( V_2 , F_1 ( V_2 ) , 1 ,
V_40 -> V_174 . V_10 [ V_2 -> V_5 . V_177 ] . V_125 ) ;
F_85 ( V_2 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_177 + V_2 -> V_5 . V_202 + 1 ; ++ V_42 )
F_82 ( V_2 , & V_40 -> V_174 . V_10 [ V_42 ] ) ;
if ( ! F_94 ( V_2 ) )
F_88 ( V_2 ) ;
F_62 ( V_2 ) ;
F_98 ( & V_40 -> V_174 . V_220 ) ;
F_77 ( V_40 -> V_174 . V_204 ) ;
}
int F_100 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_42 ;
int V_95 ;
V_95 = F_101 ( V_2 ) ;
if ( ! ( V_2 -> V_6 & V_248 ) || F_94 ( V_2 ) )
return V_95 ;
for( V_42 = 0 ; ! V_95 && ( V_42 < V_2 -> V_5 . V_177 ) ; ++ V_42 ) {
F_102 ( V_2 ) ;
V_95 = F_54 ( V_2 , F_1 ( V_2 ) , 0 ,
V_40 -> V_174 . V_10 [ V_42 ] . V_125 ) ;
if ( V_95 ) {
F_12 ( V_2 , L_67 ) ;
F_103 ( V_2 ) ;
break;
}
F_103 ( V_2 ) ;
V_95 = F_101 ( V_2 ) ;
}
F_54 ( V_2 , F_1 ( V_2 ) , 0 ,
V_40 -> V_174 . V_10 [ V_2 -> V_5 . V_177 ] . V_125 ) ;
return V_95 ;
}
int F_104 ( struct V_1 * V_2 , char * V_256 , struct V_257 * V_258 ,
int * V_259 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_232 = 0 , V_95 = 0 , V_42 ;
F_105 ( & V_40 -> V_234 . V_260 ) ;
for ( V_42 = 0 ; ! V_232 && V_42 < V_2 -> V_5 . V_202 ; V_42 ++ ) {
if ( ~ V_40 -> V_234 . V_235 & 1ULL << V_42 ) {
V_40 -> V_234 . V_235 |= 1ULL << V_42 ;
V_232 = V_2 -> V_5 . V_177 + 1 + V_42 ;
snprintf ( V_40 -> V_174 . V_236 +
V_232 * V_245 ,
V_245 , L_68 , V_256 ) ;
#ifdef F_106
if ( V_258 ) {
V_95 = F_107 ( V_258 ,
V_40 -> V_174 . V_10 [ V_232 ] . V_172 ) ;
if ( V_95 )
F_12 ( V_2 , L_69 ) ;
}
#endif
V_95 = F_97 ( V_40 -> V_174 . V_10 [ V_232 ] . V_172 ,
F_52 , 0 ,
& V_40 -> V_174 . V_236 [ V_232 << 5 ] ,
V_40 -> V_174 . V_10 + V_232 ) ;
if ( V_95 ) {
V_40 -> V_234 . V_235 ^= 1 << V_42 ;
V_232 = 0 ;
continue;
}
F_2 ( & V_40 -> V_174 . V_10 [ V_232 ] , 1 ) ;
}
}
F_108 ( & V_40 -> V_234 . V_260 ) ;
if ( V_232 ) {
* V_259 = V_232 ;
} else {
* V_259 = 0 ;
V_95 = ( V_42 == V_2 -> V_5 . V_202 ) ? - V_261 : V_95 ;
}
return V_95 ;
}
void F_109 ( struct V_1 * V_2 , int V_232 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_42 = V_232 - V_2 -> V_5 . V_177 - 1 ;
if ( F_110 ( V_42 >= 0 ) ) {
F_105 ( & V_40 -> V_234 . V_260 ) ;
if ( V_40 -> V_234 . V_235 & 1ULL << V_42 ) {
F_86 ( V_40 -> V_174 . V_10 [ V_232 ] . V_172 ,
& V_40 -> V_174 . V_10 [ V_232 ] ) ;
V_40 -> V_234 . V_235 &= ~ ( 1ULL << V_42 ) ;
}
F_108 ( & V_40 -> V_234 . V_260 ) ;
}
}
