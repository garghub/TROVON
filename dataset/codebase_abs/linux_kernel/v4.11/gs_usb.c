static struct V_1 * F_1 ( struct V_2 * V_3 )
{
int V_4 = 0 ;
unsigned long V_5 ;
F_2 ( & V_3 -> V_6 , V_5 ) ;
for (; V_4 < V_7 ; V_4 ++ ) {
if ( V_3 -> V_8 [ V_4 ] . V_9 == V_7 ) {
V_3 -> V_8 [ V_4 ] . V_9 = V_4 ;
F_3 ( & V_3 -> V_6 , V_5 ) ;
return & V_3 -> V_8 [ V_4 ] ;
}
}
F_3 ( & V_3 -> V_6 , V_5 ) ;
return NULL ;
}
static void F_4 ( struct V_1 * V_10 )
{
V_10 -> V_9 = V_7 ;
}
static struct V_1 * F_5 ( struct V_2 * V_3 ,
unsigned int V_11 )
{
unsigned long V_5 ;
if ( V_11 < V_7 ) {
F_2 ( & V_3 -> V_6 , V_5 ) ;
if ( V_3 -> V_8 [ V_11 ] . V_9 == V_11 ) {
F_3 ( & V_3 -> V_6 , V_5 ) ;
return & V_3 -> V_8 [ V_11 ] ;
}
F_3 ( & V_3 -> V_6 , V_5 ) ;
}
return NULL ;
}
static int F_6 ( struct V_12 * V_13 , struct V_2 * V_14 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 = V_14 -> V_19 ;
int V_20 ;
V_16 = F_7 ( sizeof( * V_16 ) , V_21 ) ;
if ( ! V_16 )
return - V_22 ;
V_16 -> V_23 = V_24 ;
V_20 = F_8 ( F_9 ( V_18 ) ,
F_10 ( F_9 ( V_18 ) , 0 ) ,
V_25 ,
V_26 | V_27 | V_28 ,
V_14 -> V_29 ,
0 ,
V_16 ,
sizeof( * V_16 ) ,
1000 ) ;
return V_20 ;
}
static void F_11 ( struct V_2 * V_3 , struct V_30 * V_31 )
{
struct V_32 * V_33 = & V_3 -> V_34 . V_33 ;
if ( V_31 -> V_35 & V_36 ) {
V_3 -> V_34 . V_37 = V_38 ;
V_33 -> V_39 ++ ;
} else if ( V_31 -> V_35 & V_40 ) {
V_3 -> V_34 . V_37 = V_41 ;
V_33 -> V_42 ++ ;
} else if ( V_31 -> V_35 & V_43 ) {
if ( ( V_31 -> V_44 [ 1 ] & V_45 ) ||
( V_31 -> V_44 [ 1 ] & V_46 ) ) {
V_3 -> V_34 . V_37 = V_47 ;
V_33 -> V_48 ++ ;
} else if ( ( V_31 -> V_44 [ 1 ] & V_49 ) ||
( V_31 -> V_44 [ 1 ] & V_50 ) ) {
V_3 -> V_34 . V_37 = V_51 ;
V_33 -> V_52 ++ ;
} else {
V_3 -> V_34 . V_37 = V_38 ;
}
}
}
static void F_12 ( struct V_53 * V_53 )
{
struct V_12 * V_54 = V_53 -> V_55 ;
struct V_2 * V_3 ;
struct V_56 * V_57 ;
int V_20 ;
struct V_58 * V_59 ;
struct V_60 * V_61 = V_53 -> V_62 ;
struct V_1 * V_10 ;
struct V_30 * V_31 ;
struct V_63 * V_64 ;
F_13 ( ! V_54 ) ;
switch ( V_53 -> V_65 ) {
case 0 :
break;
case - V_66 :
case - V_67 :
return;
default:
return;
}
if ( V_61 -> V_29 >= V_68 )
goto V_69;
V_3 = V_54 -> V_70 [ V_61 -> V_29 ] ;
V_57 = V_3 -> V_57 ;
V_59 = & V_57 -> V_59 ;
if ( ! F_14 ( V_57 ) )
return;
if ( V_61 -> V_9 == - 1 ) {
V_64 = F_15 ( V_3 -> V_57 , & V_31 ) ;
if ( ! V_64 )
return;
V_31 -> V_35 = V_61 -> V_35 ;
V_31 -> V_71 = F_16 ( V_61 -> V_71 ) ;
memcpy ( V_31 -> V_44 , V_61 -> V_44 , 8 ) ;
if ( V_61 -> V_35 & V_72 )
F_11 ( V_3 , V_31 ) ;
V_57 -> V_59 . V_73 ++ ;
V_57 -> V_59 . V_74 += V_61 -> V_71 ;
F_17 ( V_64 ) ;
} else {
if ( V_61 -> V_9 >= V_7 ) {
F_18 ( V_57 ,
L_1 ,
V_61 -> V_9 ) ;
goto V_69;
}
V_57 -> V_59 . V_75 ++ ;
V_57 -> V_59 . V_76 += V_61 -> V_71 ;
V_10 = F_5 ( V_3 , V_61 -> V_9 ) ;
if ( ! V_10 ) {
F_18 ( V_57 ,
L_2 ,
V_61 -> V_9 ) ;
goto V_69;
}
F_19 ( V_57 , V_61 -> V_9 ) ;
F_4 ( V_10 ) ;
F_20 ( V_57 ) ;
}
if ( V_61 -> V_5 & V_77 ) {
V_64 = F_21 ( V_57 , & V_31 ) ;
if ( ! V_64 )
goto V_69;
V_31 -> V_35 |= V_43 ;
V_31 -> V_71 = V_78 ;
V_31 -> V_44 [ 1 ] = V_79 ;
V_59 -> V_80 ++ ;
V_59 -> V_81 ++ ;
F_17 ( V_64 ) ;
}
V_69:
F_22 ( V_53 ,
V_54 -> V_82 ,
F_23 ( V_54 -> V_82 , V_83 ) ,
V_61 ,
sizeof( struct V_60 ) ,
F_12 ,
V_54
) ;
V_20 = F_24 ( V_53 , V_84 ) ;
if ( V_20 == - V_85 ) {
for ( V_20 = 0 ; V_20 < V_68 ; V_20 ++ ) {
if ( V_54 -> V_70 [ V_20 ] )
F_25 ( V_54 -> V_70 [ V_20 ] -> V_57 ) ;
}
}
}
static int F_26 ( struct V_56 * V_57 )
{
struct V_2 * V_3 = F_27 ( V_57 ) ;
struct V_86 * V_87 = & V_3 -> V_34 . V_88 ;
struct V_17 * V_18 = V_3 -> V_19 ;
int V_20 ;
struct V_89 * V_90 ;
V_90 = F_28 ( sizeof( * V_90 ) , V_21 ) ;
if ( ! V_90 )
return - V_22 ;
V_90 -> V_91 = V_87 -> V_91 ;
V_90 -> V_92 = V_87 -> V_92 ;
V_90 -> V_93 = V_87 -> V_93 ;
V_90 -> V_94 = V_87 -> V_94 ;
V_90 -> V_95 = V_87 -> V_95 ;
V_20 = F_8 ( F_9 ( V_18 ) ,
F_10 ( F_9 ( V_18 ) , 0 ) ,
V_96 ,
V_26 | V_27 | V_28 ,
V_3 -> V_29 ,
0 ,
V_90 ,
sizeof( * V_90 ) ,
1000 ) ;
F_29 ( V_90 ) ;
if ( V_20 < 0 )
F_30 ( V_57 -> V_3 . V_97 , L_3 ,
V_20 ) ;
return V_20 ;
}
static void F_31 ( struct V_53 * V_53 )
{
struct V_1 * V_10 = V_53 -> V_55 ;
struct V_2 * V_3 = V_10 -> V_3 ;
struct V_56 * V_57 = V_3 -> V_57 ;
if ( V_53 -> V_65 )
F_32 ( V_57 , L_4 , V_10 -> V_9 ) ;
F_33 ( V_53 -> V_3 ,
V_53 -> V_98 ,
V_53 -> V_62 ,
V_53 -> V_99 ) ;
F_34 ( & V_3 -> V_100 ) ;
if ( ! F_14 ( V_57 ) )
return;
if ( F_35 ( V_57 ) )
F_20 ( V_57 ) ;
}
static T_1 F_36 ( struct V_63 * V_64 ,
struct V_56 * V_57 )
{
struct V_2 * V_3 = F_27 ( V_57 ) ;
struct V_58 * V_59 = & V_3 -> V_57 -> V_59 ;
struct V_53 * V_53 ;
struct V_60 * V_61 ;
struct V_30 * V_31 ;
int V_20 ;
unsigned int V_101 ;
struct V_1 * V_10 ;
if ( F_37 ( V_57 , V_64 ) )
return V_102 ;
V_10 = F_1 ( V_3 ) ;
if ( ! V_10 )
return V_103 ;
V_53 = F_38 ( 0 , V_84 ) ;
if ( ! V_53 )
goto V_104;
V_61 = F_39 ( V_3 -> V_82 , sizeof( * V_61 ) , V_84 ,
& V_53 -> V_99 ) ;
if ( ! V_61 ) {
F_18 ( V_57 , L_5 ) ;
goto V_105;
}
V_101 = V_10 -> V_9 ;
if ( V_101 >= V_7 ) {
F_18 ( V_57 , L_6 , V_101 ) ;
goto V_106;
}
V_61 -> V_9 = V_101 ;
V_61 -> V_29 = V_3 -> V_29 ;
V_31 = (struct V_30 * ) V_64 -> V_44 ;
V_61 -> V_35 = V_31 -> V_35 ;
V_61 -> V_71 = V_31 -> V_71 ;
memcpy ( V_61 -> V_44 , V_31 -> V_44 , V_31 -> V_71 ) ;
F_22 ( V_53 , V_3 -> V_82 ,
F_40 ( V_3 -> V_82 , V_107 ) ,
V_61 ,
sizeof( * V_61 ) ,
F_31 ,
V_10 ) ;
V_53 -> V_108 |= V_109 ;
F_41 ( V_53 , & V_3 -> V_110 ) ;
F_42 ( V_64 , V_57 , V_101 ) ;
F_43 ( & V_3 -> V_100 ) ;
V_20 = F_24 ( V_53 , V_84 ) ;
if ( F_44 ( V_20 ) ) {
F_34 ( & V_3 -> V_100 ) ;
F_45 ( V_57 , V_101 ) ;
F_4 ( V_10 ) ;
F_46 ( V_53 ) ;
F_33 ( V_3 -> V_82 ,
sizeof( * V_61 ) ,
V_61 ,
V_53 -> V_99 ) ;
if ( V_20 == - V_85 ) {
F_25 ( V_57 ) ;
} else {
F_18 ( V_57 , L_7 , V_20 ) ;
V_59 -> V_111 ++ ;
}
} else {
if ( F_47 ( & V_3 -> V_100 ) >= V_7 )
F_48 ( V_57 ) ;
}
F_49 ( V_53 ) ;
return V_102 ;
V_106:
F_33 ( V_3 -> V_82 ,
sizeof( * V_61 ) ,
V_61 ,
V_53 -> V_99 ) ;
V_105:
F_49 ( V_53 ) ;
V_104:
F_4 ( V_10 ) ;
F_50 ( V_64 ) ;
V_59 -> V_111 ++ ;
return V_102 ;
}
static int F_51 ( struct V_56 * V_57 )
{
struct V_2 * V_3 = F_27 ( V_57 ) ;
struct V_12 * V_97 = V_3 -> V_97 ;
int V_20 , V_4 ;
struct V_15 * V_16 ;
T_2 V_112 ;
V_20 = F_52 ( V_57 ) ;
if ( V_20 )
return V_20 ;
if ( F_53 ( 1 , & V_97 -> V_113 ) == 1 ) {
for ( V_4 = 0 ; V_4 < V_114 ; V_4 ++ ) {
struct V_53 * V_53 ;
T_3 * V_115 ;
V_53 = F_38 ( 0 , V_21 ) ;
if ( ! V_53 )
return - V_22 ;
V_115 = F_39 ( V_3 -> V_82 ,
sizeof( struct V_60 ) ,
V_21 ,
& V_53 -> V_99 ) ;
if ( ! V_115 ) {
F_18 ( V_57 ,
L_5 ) ;
F_49 ( V_53 ) ;
return - V_22 ;
}
F_22 ( V_53 ,
V_3 -> V_82 ,
F_23 ( V_3 -> V_82 ,
V_83 ) ,
V_115 ,
sizeof( struct V_60 ) ,
F_12 ,
V_97 ) ;
V_53 -> V_108 |= V_109 ;
F_41 ( V_53 , & V_97 -> V_116 ) ;
V_20 = F_24 ( V_53 , V_21 ) ;
if ( V_20 ) {
if ( V_20 == - V_85 )
F_25 ( V_3 -> V_57 ) ;
F_18 ( V_57 ,
L_7 ,
V_20 ) ;
F_46 ( V_53 ) ;
break;
}
F_49 ( V_53 ) ;
}
}
V_16 = F_28 ( sizeof( * V_16 ) , V_21 ) ;
if ( ! V_16 )
return - V_22 ;
V_112 = V_3 -> V_34 . V_112 ;
V_16 -> V_5 = 0 ;
if ( V_112 & V_117 )
V_16 -> V_5 |= V_118 ;
else if ( V_112 & V_119 )
V_16 -> V_5 |= V_120 ;
if ( V_112 & V_121 )
V_16 -> V_5 |= V_122 ;
if ( V_112 & V_123 )
V_16 -> V_5 |= V_124 ;
V_16 -> V_23 = V_125 ;
V_20 = F_8 ( F_9 ( V_3 -> V_19 ) ,
F_10 ( F_9 ( V_3 -> V_19 ) , 0 ) ,
V_25 ,
V_26 | V_27 |
V_28 ,
V_3 -> V_29 ,
0 ,
V_16 ,
sizeof( * V_16 ) ,
1000 ) ;
if ( V_20 < 0 ) {
F_18 ( V_57 , L_8 , V_20 ) ;
F_29 ( V_16 ) ;
return V_20 ;
}
F_29 ( V_16 ) ;
V_3 -> V_34 . V_37 = V_38 ;
if ( ! ( V_3 -> V_34 . V_112 & V_119 ) )
F_54 ( V_57 ) ;
return 0 ;
}
static int F_55 ( struct V_56 * V_57 )
{
int V_20 ;
struct V_2 * V_3 = F_27 ( V_57 ) ;
struct V_12 * V_97 = V_3 -> V_97 ;
F_48 ( V_57 ) ;
if ( F_56 ( & V_97 -> V_113 ) )
F_57 ( & V_97 -> V_116 ) ;
F_57 ( & V_3 -> V_110 ) ;
F_58 ( & V_3 -> V_100 , 0 ) ;
V_20 = F_6 ( V_97 , V_3 ) ;
if ( V_20 < 0 )
F_59 ( V_57 , L_9 , V_20 ) ;
for ( V_20 = 0 ; V_20 < V_7 ; V_20 ++ ) {
V_3 -> V_8 [ V_20 ] . V_3 = V_3 ;
V_3 -> V_8 [ V_20 ] . V_9 = V_7 ;
}
F_60 ( V_57 ) ;
return 0 ;
}
static int F_61 ( struct V_56 * V_57 , bool V_126 )
{
struct V_2 * V_3 = F_27 ( V_57 ) ;
struct V_127 * V_128 ;
int V_20 ;
V_128 = F_28 ( sizeof( * V_128 ) , V_21 ) ;
if ( ! V_128 )
return - V_22 ;
if ( V_126 )
V_128 -> V_23 = V_129 ;
else
V_128 -> V_23 = V_130 ;
V_20 = F_8 ( F_9 ( V_3 -> V_19 ) ,
F_10 ( F_9 ( V_3 -> V_19 ) ,
0 ) ,
V_131 ,
V_26 | V_27 |
V_28 ,
V_3 -> V_29 ,
0 ,
V_128 ,
sizeof( * V_128 ) ,
100 ) ;
F_29 ( V_128 ) ;
return ( V_20 > 0 ) ? 0 : V_20 ;
}
static int F_62 ( struct V_56 * V_3 ,
enum V_132 V_37 )
{
int V_20 = 0 ;
switch ( V_37 ) {
case V_133 :
V_20 = F_61 ( V_3 , V_129 ) ;
break;
case V_134 :
V_20 = F_61 ( V_3 , V_130 ) ;
break;
default:
break;
}
return V_20 ;
}
static struct V_2 * F_63 ( unsigned int V_29 ,
struct V_17 * V_18 ,
struct V_135 * V_136 )
{
struct V_2 * V_3 ;
struct V_56 * V_57 ;
int V_20 ;
struct V_137 * V_138 ;
V_138 = F_28 ( sizeof( * V_138 ) , V_21 ) ;
if ( ! V_138 )
return F_64 ( - V_22 ) ;
V_20 = F_8 ( F_9 ( V_18 ) ,
F_65 ( F_9 ( V_18 ) , 0 ) ,
V_139 ,
V_140 | V_27 | V_28 ,
V_29 ,
0 ,
V_138 ,
sizeof( * V_138 ) ,
1000 ) ;
if ( V_20 < 0 ) {
F_30 ( & V_18 -> V_3 ,
L_10 ,
V_20 ) ;
F_29 ( V_138 ) ;
return F_64 ( V_20 ) ;
}
V_57 = F_66 ( sizeof( struct V_2 ) , V_7 ) ;
if ( ! V_57 ) {
F_30 ( & V_18 -> V_3 , L_11 ) ;
F_29 ( V_138 ) ;
return F_64 ( - V_22 ) ;
}
V_3 = F_27 ( V_57 ) ;
V_57 -> V_141 = & V_142 ;
V_57 -> V_5 |= V_143 ;
strcpy ( V_3 -> V_138 . V_144 , L_12 ) ;
V_3 -> V_138 . V_145 = V_138 -> V_145 ;
V_3 -> V_138 . V_146 = V_138 -> V_146 ;
V_3 -> V_138 . V_147 = V_138 -> V_147 ;
V_3 -> V_138 . V_148 = V_138 -> V_148 ;
V_3 -> V_138 . V_149 = V_138 -> V_149 ;
V_3 -> V_138 . V_150 = V_138 -> V_150 ;
V_3 -> V_138 . V_151 = V_138 -> V_151 ;
V_3 -> V_138 . V_152 = V_138 -> V_152 ;
V_3 -> V_82 = F_9 ( V_18 ) ;
V_3 -> V_19 = V_18 ;
V_3 -> V_57 = V_57 ;
V_3 -> V_29 = V_29 ;
F_67 ( & V_3 -> V_110 ) ;
F_58 ( & V_3 -> V_100 , 0 ) ;
F_68 ( & V_3 -> V_6 ) ;
for ( V_20 = 0 ; V_20 < V_7 ; V_20 ++ ) {
V_3 -> V_8 [ V_20 ] . V_3 = V_3 ;
V_3 -> V_8 [ V_20 ] . V_9 = V_7 ;
}
V_3 -> V_34 . V_37 = V_153 ;
V_3 -> V_34 . clock . V_154 = V_138 -> V_155 ;
V_3 -> V_34 . V_156 = & V_3 -> V_138 ;
V_3 -> V_34 . V_157 = F_26 ;
V_3 -> V_34 . V_158 = 0 ;
if ( V_138 -> V_159 & V_160 )
V_3 -> V_34 . V_158 |= V_119 ;
if ( V_138 -> V_159 & V_161 )
V_3 -> V_34 . V_158 |= V_117 ;
if ( V_138 -> V_159 & V_162 )
V_3 -> V_34 . V_158 |= V_123 ;
if ( V_138 -> V_159 & V_163 )
V_3 -> V_34 . V_158 |= V_121 ;
F_69 ( V_57 , & V_18 -> V_3 ) ;
if ( V_136 -> V_164 > 1 )
if ( V_138 -> V_159 & V_165 )
V_57 -> V_166 = & V_167 ;
F_29 ( V_138 ) ;
V_20 = F_70 ( V_3 -> V_57 ) ;
if ( V_20 ) {
F_71 ( V_3 -> V_57 ) ;
F_30 ( & V_18 -> V_3 , L_13 , V_20 ) ;
return F_64 ( V_20 ) ;
}
return V_3 ;
}
static void F_72 ( struct V_2 * V_3 )
{
F_73 ( V_3 -> V_57 ) ;
F_57 ( & V_3 -> V_110 ) ;
F_71 ( V_3 -> V_57 ) ;
}
static int F_74 ( struct V_17 * V_18 ,
const struct V_168 * V_11 )
{
struct V_12 * V_3 ;
int V_20 = - V_22 ;
unsigned int V_169 , V_4 ;
struct V_170 * V_171 ;
struct V_135 * V_136 ;
V_171 = F_28 ( sizeof( * V_171 ) , V_21 ) ;
if ( ! V_171 )
return - V_22 ;
V_171 -> V_172 = 0x0000beef ;
V_20 = F_8 ( F_9 ( V_18 ) ,
F_10 ( F_9 ( V_18 ) , 0 ) ,
V_173 ,
V_26 | V_27 | V_28 ,
1 ,
V_18 -> V_174 [ 0 ] . V_175 . V_176 ,
V_171 ,
sizeof( * V_171 ) ,
1000 ) ;
F_29 ( V_171 ) ;
if ( V_20 < 0 ) {
F_30 ( & V_18 -> V_3 , L_14 ,
V_20 ) ;
return V_20 ;
}
V_136 = F_28 ( sizeof( * V_136 ) , V_21 ) ;
if ( ! V_136 )
return - V_22 ;
V_20 = F_8 ( F_9 ( V_18 ) ,
F_65 ( F_9 ( V_18 ) , 0 ) ,
V_177 ,
V_140 | V_27 | V_28 ,
1 ,
V_18 -> V_174 [ 0 ] . V_175 . V_176 ,
V_136 ,
sizeof( * V_136 ) ,
1000 ) ;
if ( V_20 < 0 ) {
F_30 ( & V_18 -> V_3 , L_15 ,
V_20 ) ;
F_29 ( V_136 ) ;
return V_20 ;
}
V_169 = V_136 -> V_169 + 1 ;
F_75 ( & V_18 -> V_3 , L_16 , V_169 ) ;
if ( V_169 > V_68 ) {
F_30 ( & V_18 -> V_3 ,
L_17 ,
V_68 ) ;
F_29 ( V_136 ) ;
return - V_178 ;
}
V_3 = F_7 ( sizeof( * V_3 ) , V_21 ) ;
if ( ! V_3 ) {
F_29 ( V_136 ) ;
return - V_22 ;
}
F_67 ( & V_3 -> V_116 ) ;
F_58 ( & V_3 -> V_113 , 0 ) ;
F_76 ( V_18 , V_3 ) ;
V_3 -> V_82 = F_9 ( V_18 ) ;
for ( V_4 = 0 ; V_4 < V_169 ; V_4 ++ ) {
V_3 -> V_70 [ V_4 ] = F_63 ( V_4 , V_18 , V_136 ) ;
if ( F_77 ( V_3 -> V_70 [ V_4 ] ) ) {
V_20 = F_78 ( V_3 -> V_70 [ V_4 ] ) ;
V_169 = V_4 ;
for ( V_4 = 0 ; V_4 < V_169 ; V_4 ++ )
F_72 ( V_3 -> V_70 [ V_4 ] ) ;
F_57 ( & V_3 -> V_116 ) ;
F_29 ( V_136 ) ;
F_29 ( V_3 ) ;
return V_20 ;
}
V_3 -> V_70 [ V_4 ] -> V_97 = V_3 ;
}
F_29 ( V_136 ) ;
return 0 ;
}
static void F_79 ( struct V_17 * V_18 )
{
unsigned V_4 ;
struct V_12 * V_3 = F_80 ( V_18 ) ;
F_76 ( V_18 , NULL ) ;
if ( ! V_3 ) {
F_30 ( & V_18 -> V_3 , L_18 ) ;
return;
}
for ( V_4 = 0 ; V_4 < V_68 ; V_4 ++ )
if ( V_3 -> V_70 [ V_4 ] )
F_72 ( V_3 -> V_70 [ V_4 ] ) ;
F_57 ( & V_3 -> V_116 ) ;
F_29 ( V_3 ) ;
}
