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
while ( ( V_25 = F_7 ( V_10 , V_2 -> V_5 . V_18 ) ) ) {
F_33 () ;
switch ( V_25 -> type ) {
case V_109 :
V_104 = F_34 ( V_25 -> V_59 . V_110 . V_104 ) & 0xffffff ;
F_35 ( V_2 , V_104 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
F_22 ( V_2 , L_16 , V_25 -> type ) ;
if ( F_36 ( V_2 ) ) {
V_76 = F_37 ( V_2 ,
V_119 ,
F_34 ( V_25 -> V_59 . V_120 . V_121 )
& 0xffffff , & V_41 ) ;
if ( V_76 && V_76 != - V_122 ) {
F_22 ( V_2 , L_17
L_18
L_19 ,
V_25 -> type , V_25 -> V_57 ,
V_10 -> V_123 , V_10 -> V_14 , V_76 ) ;
break;
}
if ( ! V_76 && V_41 != V_2 -> V_5 . V_46 ) {
F_18 ( V_2 , V_41 , V_25 ) ;
break;
}
}
F_38 ( V_2 , F_34 ( V_25 -> V_59 . V_120 . V_121 ) &
0xffffff , V_25 -> type ) ;
break;
case V_124 :
F_12 ( V_2 , L_20 ,
V_66 ) ;
case V_125 :
if ( F_36 ( V_2 ) ) {
V_76 = F_37 ( V_2 ,
V_126 ,
F_34 ( V_25 -> V_59 . V_127 . V_128 )
& 0xffffff ,
& V_41 ) ;
if ( V_76 && V_76 != - V_122 ) {
F_12 ( V_2 , L_21
L_22
L_23 ,
V_25 -> type , V_25 -> V_57 ,
V_10 -> V_123 , V_10 -> V_14 , V_76 ) ;
break;
}
F_12 ( V_2 , L_24
L_25 , V_66 ,
V_41 ,
F_34 ( V_25 -> V_59 . V_127 . V_128 ) ,
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
F_39 ( V_2 , F_34 ( V_25 -> V_59 . V_127 . V_128 ) &
0xffffff , V_25 -> type ) ;
break;
case V_129 :
F_40 ( V_2 ,
F_41 ( V_25 -> V_59 . V_130 . V_131 ) ,
V_25 -> V_59 . V_130 . V_132 ,
F_42 ( V_25 -> V_59 . V_130 . V_133 ) ) ;
break;
case V_64 :
V_56 = F_34 ( V_25 -> V_59 . V_65 . V_56 ) >> 28 ;
if ( V_25 -> V_57 == V_134 ) {
F_43 ( V_2 , V_135 ,
V_56 ) ;
V_39 ( V_2 ) -> V_136 . V_137 [ V_56 ] = 1 ;
if ( ! F_36 ( V_2 ) )
break;
for ( V_42 = 0 ; V_42 < V_2 -> V_45 ; V_42 ++ ) {
if ( V_2 -> V_5 . V_138 [ V_56 ] == V_139 ) {
if ( V_42 == F_44 ( V_2 ) )
continue;
F_22 ( V_2 , L_28
L_29 ,
V_66 , V_42 , V_56 ) ;
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
F_43 ( V_2 , V_140 , V_56 ) ;
V_39 ( V_2 ) -> V_136 . V_137 [ V_56 ] = 0 ;
if ( ! F_36 ( V_2 ) )
break;
if ( V_2 -> V_5 . V_138 [ V_56 ] == V_139 )
for ( V_42 = 0 ; V_42 < V_2 -> V_45 ; V_42 ++ ) {
if ( V_42 == F_44 ( V_2 ) )
continue;
F_18 ( V_2 , V_42 , V_25 ) ;
}
else
F_26 ( V_2 , V_56 , V_140 ) ;
}
break;
case V_141 :
F_12 ( V_2 , L_30 ,
V_25 -> V_59 . V_142 . V_143 == 1 ?
L_31 : L_32 ,
F_34 ( V_25 -> V_59 . V_142 . V_104 ) & 0xffffff ) ;
if ( F_36 ( V_2 ) ) {
V_76 = F_37 ( V_2 ,
V_144 ,
F_34 ( V_25 -> V_59 . V_142 . V_104 )
& 0xffffff , & V_41 ) ;
if ( V_76 && V_76 != - V_122 ) {
F_22 ( V_2 , L_33
L_18
L_19 ,
V_25 -> type , V_25 -> V_57 ,
V_10 -> V_123 , V_10 -> V_14 , V_76 ) ;
break;
}
if ( ! V_76 && V_41 != V_2 -> V_5 . V_46 ) {
F_18 ( V_2 , V_41 , V_25 ) ;
break;
}
}
F_45 ( V_2 ,
F_34 ( V_25 -> V_59 . V_142 . V_104 )
& 0xffffff ,
V_25 -> type ) ;
break;
case V_145 :
F_12 ( V_2 , L_34 , V_10 -> V_123 ) ;
break;
case V_146 :
if ( ! F_36 ( V_2 ) ) {
F_12 ( V_2 , L_35
L_36 ) ;
break;
}
memcpy ( & V_40 -> V_38 . V_35 . V_147 ,
V_25 -> V_59 . V_148 . V_149 ,
sizeof V_25 -> V_59 . V_148 . V_149 ) ;
F_17 ( V_40 -> V_38 . V_35 . V_53 ,
& V_40 -> V_38 . V_35 . V_150 ) ;
break;
case V_151 :
V_107 = F_34 ( V_25 -> V_59 . V_152 . V_43 ) ;
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
case V_153 :
if ( V_25 -> V_57 == V_154 ) {
if ( F_36 ( V_2 ) )
for ( V_42 = 0 ; V_42 < V_2 -> V_45 ; V_42 ++ ) {
F_22 ( V_2 , L_41
L_42
L_43 , V_66 , V_42 ) ;
if ( V_42 == V_2 -> V_5 . V_46 )
continue;
F_18 ( V_2 , V_42 , V_25 ) ;
}
F_46 ( V_2 , L_44
L_45
L_46 ,
F_41 ( V_25 -> V_59 . V_155 . V_156 ) ,
F_41 ( V_25 -> V_59 . V_155 . V_157 ) ) ;
} else
F_12 ( V_2 , L_47
L_48
L_49 ,
V_25 -> type , V_25 -> V_57 , V_10 -> V_123 ,
V_10 -> V_14 , V_25 -> V_26 , V_10 -> V_20 ,
V_25 -> V_43 ,
! ! ( V_25 -> V_26 & 0x80 ) ^
! ! ( V_10 -> V_14 & V_10 -> V_20 ) ? L_50 : L_51 ) ;
break;
case V_8 :
F_43 ( V_2 , V_158 ,
( unsigned long ) V_25 ) ;
break;
case V_159 :
case V_160 :
default:
F_12 ( V_2 , L_52
L_53
L_54 ,
V_25 -> type , V_25 -> V_57 , V_10 -> V_123 ,
V_10 -> V_14 , V_25 -> V_26 , V_10 -> V_20 ,
V_25 -> V_43 ,
! ! ( V_25 -> V_26 & 0x80 ) ^
! ! ( V_10 -> V_14 & V_10 -> V_20 ) ? L_50 : L_51 ) ;
break;
} ;
++ V_10 -> V_14 ;
V_105 = 1 ;
++ V_106 ;
if ( F_47 ( V_106 >= V_161 ) ) {
F_2 ( V_10 , 0 ) ;
V_106 = 0 ;
}
}
F_2 ( V_10 , 1 ) ;
return V_105 ;
}
static T_3 F_48 ( int V_162 , void * V_163 )
{
struct V_1 * V_2 = V_163 ;
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_33 = 0 ;
int V_42 ;
F_49 ( V_40 -> V_164 . V_165 , V_40 -> V_164 . V_166 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_167 + 1 ; ++ V_42 )
V_33 |= F_32 ( V_2 , & V_40 -> V_164 . V_10 [ V_42 ] ) ;
return F_50 ( V_33 ) ;
}
static T_3 F_51 ( int V_162 , void * V_168 )
{
struct V_9 * V_10 = V_168 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_32 ( V_2 , V_10 ) ;
return V_169 ;
}
int F_52 ( struct V_1 * V_2 , int V_41 ,
struct V_170 * V_171 ,
struct V_172 * V_173 ,
struct V_172 * V_174 ,
struct V_175 * V_130 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_176 * V_177 =
V_40 -> V_38 . V_35 . V_47 [ V_41 ] . V_177 ;
V_13 V_178 = V_171 -> V_178 ;
V_13 V_123 = V_178 & 0x3FF ;
T_1 V_179 = V_171 -> V_179 ;
int V_95 = 0 ;
int V_42 ;
if ( V_41 == V_2 -> V_5 . V_46 )
V_95 = F_31 ( V_2 , V_179 , ( V_178 & 0x80000000 ) | V_123 ,
0 , V_180 , V_181 ,
V_182 ) ;
if ( ! V_95 )
for ( V_42 = 0 ; V_42 < V_183 ; ++ V_42 )
if ( V_179 & ( 1LL << V_42 ) )
V_177 [ V_42 ] . V_123 = V_178 >> 31 ? - 1 : V_123 ;
return V_95 ;
}
static int F_53 ( struct V_1 * V_2 , T_1 V_184 , int V_185 ,
int V_186 )
{
return F_31 ( V_2 , V_184 , ( V_185 << 31 ) | V_186 ,
0 , V_180 , V_181 ,
V_103 ) ;
}
static int F_54 ( struct V_1 * V_2 , struct V_172 * V_187 ,
int V_186 )
{
return F_31 ( V_2 , V_187 -> V_188 , V_186 , 0 ,
V_189 , V_102 ,
V_103 ) ;
}
static int F_55 ( struct V_1 * V_2 , struct V_172 * V_187 ,
int V_186 )
{
return F_56 ( V_2 , 0 , V_187 -> V_188 , V_186 ,
0 , V_190 , V_102 ,
V_103 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_167 + 1 + V_2 -> V_5 . V_191 +
V_2 -> V_5 . V_192 ) / 4 - V_2 -> V_5 . V_191 / 4 + 1 ;
}
static void T_4 * F_58 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_193 ;
V_193 = V_10 -> V_123 / 4 - V_2 -> V_5 . V_191 / 4 ;
if ( ! V_40 -> V_164 . V_194 [ V_193 ] ) {
V_40 -> V_164 . V_194 [ V_193 ] =
F_59 ( F_60 ( V_2 -> V_195 , 2 ) +
( ( V_10 -> V_123 / 4 ) << V_196 ) ,
V_23 ) ;
if ( ! V_40 -> V_164 . V_194 [ V_193 ] ) {
F_46 ( V_2 , L_55 ,
V_10 -> V_123 ) ;
return NULL ;
}
}
return V_40 -> V_164 . V_194 [ V_193 ] + 0x800 + 8 * ( V_10 -> V_123 % 4 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < F_57 ( V_2 ) ; ++ V_42 )
if ( V_40 -> V_164 . V_194 [ V_42 ] ) {
F_62 ( V_40 -> V_164 . V_194 [ V_42 ] ) ;
V_40 -> V_164 . V_194 [ V_42 ] = NULL ;
}
}
static int F_63 ( struct V_1 * V_2 , int V_20 ,
T_2 V_197 , struct V_9 * V_10 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_172 * V_187 ;
struct V_198 * V_199 ;
int V_200 ;
T_1 * V_201 = NULL ;
T_5 V_202 ;
T_1 V_203 ;
int V_95 = - V_204 ;
int V_42 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_20 = F_64 ( F_65 ( V_20 , 2 ) ) ;
V_200 = F_66 ( V_10 -> V_20 * ( V_21 << V_2 -> V_5 . V_18 ) ) / V_23 ;
V_10 -> V_22 = F_67 ( V_200 * sizeof * V_10 -> V_22 ,
V_205 ) ;
if ( ! V_10 -> V_22 )
goto V_206;
for ( V_42 = 0 ; V_42 < V_200 ; ++ V_42 )
V_10 -> V_22 [ V_42 ] . V_24 = NULL ;
V_201 = F_67 ( V_200 * sizeof *V_201 , V_205 ) ;
if ( ! V_201 )
goto V_207;
V_187 = F_68 ( V_2 ) ;
if ( F_69 ( V_187 ) )
goto V_207;
V_199 = V_187 -> V_24 ;
for ( V_42 = 0 ; V_42 < V_200 ; ++ V_42 ) {
V_10 -> V_22 [ V_42 ] . V_24 = F_70 ( & V_2 -> V_195 -> V_2 ,
V_23 , & V_202 , V_205 ) ;
if ( ! V_10 -> V_22 [ V_42 ] . V_24 )
goto V_208;
V_201 [ V_42 ] = V_202 ;
V_10 -> V_22 [ V_42 ] . V_209 = V_202 ;
memset ( V_10 -> V_22 [ V_42 ] . V_24 , 0 , V_23 ) ;
}
V_10 -> V_123 = F_71 ( & V_40 -> V_164 . V_210 ) ;
if ( V_10 -> V_123 == - 1 )
goto V_208;
V_10 -> V_15 = F_58 ( V_2 , V_10 ) ;
if ( ! V_10 -> V_15 ) {
V_95 = - V_204 ;
goto V_211;
}
V_95 = F_72 ( V_2 , V_200 , V_196 , & V_10 -> V_212 ) ;
if ( V_95 )
goto V_211;
V_95 = F_73 ( V_2 , & V_10 -> V_212 , 0 , V_200 , V_201 ) ;
if ( V_95 )
goto V_213;
memset ( V_199 , 0 , sizeof *V_199 ) ;
V_199 -> V_6 = F_4 ( V_214 |
V_215 ) ;
V_199 -> V_216 = F_74 ( V_10 -> V_20 ) ;
V_199 -> V_197 = V_197 ;
V_199 -> V_217 = V_196 - V_218 ;
V_203 = F_75 ( V_2 , & V_10 -> V_212 ) ;
V_199 -> V_219 = V_203 >> 32 ;
V_199 -> V_220 = F_4 ( V_203 & 0xffffffff ) ;
V_95 = F_54 ( V_2 , V_187 , V_10 -> V_123 ) ;
if ( V_95 ) {
F_12 ( V_2 , L_56 , V_95 ) ;
goto V_213;
}
F_76 ( V_201 ) ;
F_77 ( V_2 , V_187 ) ;
V_10 -> V_14 = 0 ;
return V_95 ;
V_213:
F_78 ( V_2 , & V_10 -> V_212 ) ;
V_211:
F_79 ( & V_40 -> V_164 . V_210 , V_10 -> V_123 ) ;
V_208:
for ( V_42 = 0 ; V_42 < V_200 ; ++ V_42 )
if ( V_10 -> V_22 [ V_42 ] . V_24 )
F_80 ( & V_2 -> V_195 -> V_2 , V_23 ,
V_10 -> V_22 [ V_42 ] . V_24 ,
V_10 -> V_22 [ V_42 ] . V_209 ) ;
F_77 ( V_2 , V_187 ) ;
V_207:
F_76 ( V_10 -> V_22 ) ;
F_76 ( V_201 ) ;
V_206:
return V_95 ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
struct V_172 * V_187 ;
int V_95 ;
int V_42 ;
int V_200 = F_66 ( ( V_21 << V_2 -> V_5 . V_18 ) * V_10 -> V_20 ) / V_23 ;
V_187 = F_68 ( V_2 ) ;
if ( F_69 ( V_187 ) )
return;
V_95 = F_55 ( V_2 , V_187 , V_10 -> V_123 ) ;
if ( V_95 )
F_12 ( V_2 , L_57 , V_95 ) ;
if ( 0 ) {
F_22 ( V_2 , L_58 , V_10 -> V_123 ) ;
for ( V_42 = 0 ; V_42 < sizeof ( struct V_198 ) / 4 ; ++ V_42 ) {
if ( V_42 % 4 == 0 )
F_82 ( L_59 , V_42 * 4 ) ;
F_82 ( L_60 , F_83 ( V_187 -> V_24 + V_42 * 4 ) ) ;
if ( ( V_42 + 1 ) % 4 == 0 )
F_82 ( L_61 ) ;
}
}
F_78 ( V_2 , & V_10 -> V_212 ) ;
for ( V_42 = 0 ; V_42 < V_200 ; ++ V_42 )
F_80 ( & V_2 -> V_195 -> V_2 , V_23 ,
V_10 -> V_22 [ V_42 ] . V_24 ,
V_10 -> V_22 [ V_42 ] . V_209 ) ;
F_76 ( V_10 -> V_22 ) ;
F_79 ( & V_40 -> V_164 . V_210 , V_10 -> V_123 ) ;
F_77 ( V_2 , V_187 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_221 * V_164 = & V_39 ( V_2 ) -> V_164 ;
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_42 , V_222 ;
if ( V_164 -> V_223 )
F_85 ( V_2 -> V_195 -> V_162 , V_2 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_167 + 1 ; ++ V_42 )
if ( V_164 -> V_10 [ V_42 ] . V_223 ) {
F_85 ( V_164 -> V_10 [ V_42 ] . V_162 , V_164 -> V_10 + V_42 ) ;
V_164 -> V_10 [ V_42 ] . V_223 = 0 ;
}
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_192 ; V_42 ++ ) {
if ( V_40 -> V_224 . V_225 & 1ULL << V_42 ) {
V_222 = V_2 -> V_5 . V_167 + 1 + V_42 ;
F_85 ( V_40 -> V_164 . V_10 [ V_222 ] . V_162 ,
& V_40 -> V_164 . V_10 [ V_222 ] ) ;
}
}
F_76 ( V_164 -> V_226 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
V_40 -> V_227 = F_59 ( F_60 ( V_2 -> V_195 , V_40 -> V_228 . V_229 ) +
V_40 -> V_228 . V_230 , V_231 ) ;
if ( ! V_40 -> V_227 ) {
F_46 ( V_2 , L_62 ) ;
return - V_204 ;
}
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
F_62 ( V_40 -> V_227 ) ;
}
int F_88 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
V_40 -> V_164 . V_10 = F_89 ( V_2 -> V_5 . V_232 - V_2 -> V_5 . V_191 ,
sizeof * V_40 -> V_164 . V_10 , V_205 ) ;
if ( ! V_40 -> V_164 . V_10 )
return - V_204 ;
return 0 ;
}
void F_90 ( struct V_1 * V_2 )
{
F_76 ( V_39 ( V_2 ) -> V_164 . V_10 ) ;
}
int F_91 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_95 ;
int V_42 ;
V_40 -> V_164 . V_194 = F_89 ( F_57 ( V_2 ) ,
sizeof * V_40 -> V_164 . V_194 ,
V_205 ) ;
if ( ! V_40 -> V_164 . V_194 ) {
V_95 = - V_204 ;
goto V_207;
}
V_95 = F_92 ( & V_40 -> V_164 . V_210 , V_2 -> V_5 . V_232 ,
V_2 -> V_5 . V_232 - 1 , V_2 -> V_5 . V_191 , 0 ) ;
if ( V_95 )
goto V_207;
for ( V_42 = 0 ; V_42 < F_57 ( V_2 ) ; ++ V_42 )
V_40 -> V_164 . V_194 [ V_42 ] = NULL ;
if ( ! F_93 ( V_2 ) ) {
V_95 = F_86 ( V_2 ) ;
if ( V_95 )
goto V_233;
V_40 -> V_164 . V_165 =
F_94 ( 1 << ( V_40 -> V_164 . V_234 & 31 ) ) ;
V_40 -> V_164 . V_166 = V_40 -> V_227 +
( V_40 -> V_164 . V_234 < 32 ? 4 : 0 ) ;
}
V_40 -> V_164 . V_226 =
F_67 ( V_235 * ( V_2 -> V_5 . V_167 + 1 +
V_2 -> V_5 . V_192 ) ,
V_205 ) ;
if ( ! V_40 -> V_164 . V_226 ) {
V_95 = - V_204 ;
goto V_233;
}
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_167 ; ++ V_42 ) {
V_95 = F_63 ( V_2 , V_2 -> V_5 . V_236 -
V_2 -> V_5 . V_237 +
V_161 ,
( V_2 -> V_6 & V_238 ) ? V_42 : 0 ,
& V_40 -> V_164 . V_10 [ V_42 ] ) ;
if ( V_95 ) {
-- V_42 ;
goto V_239;
}
}
V_95 = F_63 ( V_2 , V_240 + V_161 ,
( V_2 -> V_6 & V_238 ) ? V_2 -> V_5 . V_167 : 0 ,
& V_40 -> V_164 . V_10 [ V_2 -> V_5 . V_167 ] ) ;
if ( V_95 )
goto V_241;
for ( V_42 = V_2 -> V_5 . V_167 + 1 ;
V_42 < V_2 -> V_5 . V_167 + V_2 -> V_5 . V_192 + 1 ; ++ V_42 ) {
V_95 = F_63 ( V_2 , V_2 -> V_5 . V_236 -
V_2 -> V_5 . V_237 +
V_161 ,
( V_2 -> V_6 & V_238 ) ? V_42 : 0 ,
& V_40 -> V_164 . V_10 [ V_42 ] ) ;
if ( V_95 ) {
-- V_42 ;
goto V_239;
}
}
if ( V_2 -> V_6 & V_238 ) {
const char * V_242 ;
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_167 + 1 ; ++ V_42 ) {
if ( V_42 < V_2 -> V_5 . V_167 ) {
snprintf ( V_40 -> V_164 . V_226 +
V_42 * V_235 ,
V_235 ,
L_63 , V_42 ,
F_95 ( V_2 -> V_195 ) ) ;
} else {
snprintf ( V_40 -> V_164 . V_226 +
V_42 * V_235 ,
V_235 ,
L_64 ,
F_95 ( V_2 -> V_195 ) ) ;
}
V_242 = V_40 -> V_164 . V_226 +
V_42 * V_235 ;
V_95 = F_96 ( V_40 -> V_164 . V_10 [ V_42 ] . V_162 ,
F_51 , 0 , V_242 ,
V_40 -> V_164 . V_10 + V_42 ) ;
if ( V_95 )
goto V_243;
V_40 -> V_164 . V_10 [ V_42 ] . V_223 = 1 ;
}
} else {
snprintf ( V_40 -> V_164 . V_226 ,
V_235 ,
V_244 L_65 ,
F_95 ( V_2 -> V_195 ) ) ;
V_95 = F_96 ( V_2 -> V_195 -> V_162 , F_48 ,
V_245 , V_40 -> V_164 . V_226 , V_2 ) ;
if ( V_95 )
goto V_243;
V_40 -> V_164 . V_223 = 1 ;
}
V_95 = F_53 ( V_2 , F_1 ( V_2 ) , 0 ,
V_40 -> V_164 . V_10 [ V_2 -> V_5 . V_167 ] . V_123 ) ;
if ( V_95 )
F_12 ( V_2 , L_66 ,
V_40 -> V_164 . V_10 [ V_2 -> V_5 . V_167 ] . V_123 , V_95 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_167 + 1 ; ++ V_42 )
F_2 ( & V_40 -> V_164 . V_10 [ V_42 ] , 1 ) ;
return 0 ;
V_243:
F_81 ( V_2 , & V_40 -> V_164 . V_10 [ V_2 -> V_5 . V_167 ] ) ;
V_241:
V_42 = V_2 -> V_5 . V_167 - 1 ;
V_239:
while ( V_42 >= 0 ) {
F_81 ( V_2 , & V_40 -> V_164 . V_10 [ V_42 ] ) ;
-- V_42 ;
}
if ( ! F_93 ( V_2 ) )
F_87 ( V_2 ) ;
F_84 ( V_2 ) ;
V_233:
F_61 ( V_2 ) ;
F_97 ( & V_40 -> V_164 . V_210 ) ;
V_207:
F_76 ( V_40 -> V_164 . V_194 ) ;
return V_95 ;
}
void F_98 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_42 ;
F_53 ( V_2 , F_1 ( V_2 ) , 1 ,
V_40 -> V_164 . V_10 [ V_2 -> V_5 . V_167 ] . V_123 ) ;
F_84 ( V_2 ) ;
for ( V_42 = 0 ; V_42 < V_2 -> V_5 . V_167 + V_2 -> V_5 . V_192 + 1 ; ++ V_42 )
F_81 ( V_2 , & V_40 -> V_164 . V_10 [ V_42 ] ) ;
if ( ! F_93 ( V_2 ) )
F_87 ( V_2 ) ;
F_61 ( V_2 ) ;
F_97 ( & V_40 -> V_164 . V_210 ) ;
F_76 ( V_40 -> V_164 . V_194 ) ;
}
int F_99 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_42 ;
int V_95 ;
V_95 = F_100 ( V_2 ) ;
if ( ! ( V_2 -> V_6 & V_238 ) || F_93 ( V_2 ) )
return V_95 ;
for( V_42 = 0 ; ! V_95 && ( V_42 < V_2 -> V_5 . V_167 ) ; ++ V_42 ) {
F_101 ( V_2 ) ;
V_95 = F_53 ( V_2 , F_1 ( V_2 ) , 0 ,
V_40 -> V_164 . V_10 [ V_42 ] . V_123 ) ;
if ( V_95 ) {
F_12 ( V_2 , L_67 ) ;
F_102 ( V_2 ) ;
break;
}
F_102 ( V_2 ) ;
V_95 = F_100 ( V_2 ) ;
}
F_53 ( V_2 , F_1 ( V_2 ) , 0 ,
V_40 -> V_164 . V_10 [ V_2 -> V_5 . V_167 ] . V_123 ) ;
return V_95 ;
}
int F_103 ( struct V_1 * V_2 , char * V_246 , struct V_247 * V_248 ,
int * V_249 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_222 = 0 , V_95 = 0 , V_42 ;
F_104 ( & V_40 -> V_224 . V_250 ) ;
for ( V_42 = 0 ; ! V_222 && V_42 < V_2 -> V_5 . V_192 ; V_42 ++ ) {
if ( ~ V_40 -> V_224 . V_225 & 1ULL << V_42 ) {
V_40 -> V_224 . V_225 |= 1ULL << V_42 ;
V_222 = V_2 -> V_5 . V_167 + 1 + V_42 ;
snprintf ( V_40 -> V_164 . V_226 +
V_222 * V_235 ,
V_235 , L_68 , V_246 ) ;
#ifdef F_105
if ( V_248 ) {
V_95 = F_106 ( V_248 ,
V_40 -> V_164 . V_10 [ V_222 ] . V_162 ) ;
if ( V_95 )
F_12 ( V_2 , L_69 ) ;
}
#endif
V_95 = F_96 ( V_40 -> V_164 . V_10 [ V_222 ] . V_162 ,
F_51 , 0 ,
& V_40 -> V_164 . V_226 [ V_222 << 5 ] ,
V_40 -> V_164 . V_10 + V_222 ) ;
if ( V_95 ) {
V_40 -> V_224 . V_225 ^= 1 << V_42 ;
V_222 = 0 ;
continue;
}
F_2 ( & V_40 -> V_164 . V_10 [ V_222 ] , 1 ) ;
}
}
F_107 ( & V_40 -> V_224 . V_250 ) ;
if ( V_222 ) {
* V_249 = V_222 ;
} else {
* V_249 = 0 ;
V_95 = ( V_42 == V_2 -> V_5 . V_192 ) ? - V_251 : V_95 ;
}
return V_95 ;
}
void F_108 ( struct V_1 * V_2 , int V_222 )
{
struct V_39 * V_40 = V_39 ( V_2 ) ;
int V_42 = V_222 - V_2 -> V_5 . V_167 - 1 ;
if ( F_109 ( V_42 >= 0 ) ) {
F_104 ( & V_40 -> V_224 . V_250 ) ;
if ( V_40 -> V_224 . V_225 & 1ULL << V_42 ) {
F_85 ( V_40 -> V_164 . V_10 [ V_222 ] . V_162 ,
& V_40 -> V_164 . V_10 [ V_222 ] ) ;
V_40 -> V_224 . V_225 &= ~ ( 1ULL << V_42 ) ;
}
F_107 ( & V_40 -> V_224 . V_250 ) ;
}
}
