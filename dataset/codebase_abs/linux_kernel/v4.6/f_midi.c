static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 ,
unsigned V_8 )
{
return F_4 ( V_7 , V_8 , V_8 ) ;
}
static void F_5 ( struct V_6 * V_7 , int V_9 ,
T_1 * V_10 , int V_8 )
{
struct V_1 * V_11 = V_7 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_15 [ V_9 ] ;
if ( ! V_14 )
return;
if ( ! F_6 ( V_9 , & V_11 -> V_16 ) )
return;
F_7 ( V_14 , V_10 , V_8 ) ;
}
static void F_8 ( struct V_6 * V_7 , struct V_5 * V_17 )
{
unsigned int V_18 ;
T_2 * V_19 = V_17 -> V_19 ;
for ( V_18 = 0 ; V_18 + 3 < V_17 -> V_20 ; V_18 += 4 )
if ( V_19 [ V_18 ] != 0 ) {
int V_9 = V_19 [ V_18 ] >> 4 ;
int V_8 = V_21 [ V_19 [ V_18 ] & 0x0f ] ;
F_5 ( V_7 , V_9 , & V_19 [ V_18 + 1 ] , V_8 ) ;
}
}
static void
F_9 ( struct V_6 * V_7 , struct V_5 * V_17 )
{
struct V_1 * V_11 = V_7 -> V_12 ;
struct V_22 * V_23 = V_11 -> V_4 . V_24 -> V_23 ;
int V_25 = V_17 -> V_25 ;
switch ( V_25 ) {
case 0 :
if ( V_7 == V_11 -> V_26 ) {
F_8 ( V_7 , V_17 ) ;
} else if ( V_7 == V_11 -> V_27 ) {
V_17 -> V_8 = 0 ;
F_10 ( V_11 ) ;
return;
}
break;
case - V_28 :
case - V_29 :
case - V_30 :
F_11 ( V_23 , L_1 , V_7 -> V_31 , V_25 ,
V_17 -> V_20 , V_17 -> V_8 ) ;
if ( V_7 == V_11 -> V_26 ) {
F_8 ( V_7 , V_17 ) ;
F_12 ( V_7 , V_17 ) ;
}
return;
case - V_32 :
default:
F_13 ( V_23 , L_2 , V_7 -> V_31 ,
V_25 , V_17 -> V_20 , V_17 -> V_8 ) ;
break;
case - V_33 :
break;
}
V_25 = F_14 ( V_7 , V_17 , V_34 ) ;
if ( V_25 ) {
ERROR ( V_23 , L_3 ,
V_7 -> V_31 , V_17 -> V_8 , V_25 ) ;
F_15 ( V_7 ) ;
}
}
static int F_16 ( struct V_1 * V_11 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
int V_35 ;
struct V_22 * V_23 = V_3 -> V_24 -> V_23 ;
F_17 ( V_7 ) ;
V_35 = F_18 ( V_11 -> V_36 , V_3 , V_7 ) ;
if ( V_35 ) {
ERROR ( V_23 , L_4 , V_7 -> V_31 , V_35 ) ;
return V_35 ;
}
V_35 = F_19 ( V_7 ) ;
if ( V_35 ) {
ERROR ( V_23 , L_5 , V_7 -> V_31 , V_35 ) ;
return V_35 ;
}
V_7 -> V_12 = V_11 ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , unsigned V_37 , unsigned V_38 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
unsigned V_18 ;
int V_35 ;
if ( V_37 != V_11 -> V_39 )
return 0 ;
V_35 = F_16 ( V_11 , V_3 , V_11 -> V_27 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_16 ( V_11 , V_3 , V_11 -> V_26 ) ;
if ( V_35 )
return V_35 ;
while ( F_21 ( & V_11 -> V_40 ) ) {
struct V_5 * V_17 =
F_3 ( V_11 -> V_27 , V_11 -> V_41 ) ;
if ( V_17 == NULL )
return - V_42 ;
V_17 -> V_8 = 0 ;
V_17 -> V_43 = F_9 ;
F_22 ( & V_11 -> V_40 , V_17 ) ;
}
for ( V_18 = 0 ; V_18 < V_11 -> V_44 && V_35 == 0 ; V_18 ++ ) {
struct V_5 * V_17 =
F_3 ( V_11 -> V_26 ,
F_23 ( unsigned , V_11 -> V_41 ,
V_45 . V_46 ) ) ;
if ( V_17 == NULL )
return - V_42 ;
V_17 -> V_43 = F_9 ;
V_35 = F_14 ( V_11 -> V_26 , V_17 , V_34 ) ;
if ( V_35 ) {
ERROR ( V_11 , L_6 ,
V_11 -> V_26 -> V_31 , V_35 ) ;
F_12 ( V_11 -> V_26 , V_17 ) ;
return V_35 ;
}
}
return 0 ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_22 * V_23 = V_3 -> V_24 -> V_23 ;
struct V_5 * V_17 = NULL ;
F_13 ( V_23 , L_7 ) ;
F_17 ( V_11 -> V_27 ) ;
F_17 ( V_11 -> V_26 ) ;
while ( F_25 ( & V_11 -> V_40 , & V_17 ) )
F_12 ( V_11 -> V_27 , V_17 ) ;
}
static int F_26 ( struct V_47 * V_48 )
{
return 0 ;
}
static void F_27 ( struct V_5 * V_17 , T_1 V_49 ,
T_1 V_50 , T_1 V_51 , T_1 V_52 )
{
unsigned V_8 = V_17 -> V_8 ;
T_2 * V_19 = ( T_2 * ) V_17 -> V_19 + V_8 ;
V_19 [ 0 ] = V_49 ;
V_19 [ 1 ] = V_50 ;
V_19 [ 2 ] = V_51 ;
V_19 [ 3 ] = V_52 ;
V_17 -> V_8 = V_8 + 4 ;
}
static void F_28 ( struct V_5 * V_17 ,
struct V_53 * V_54 , T_1 V_55 )
{
T_1 V_49 = V_54 -> V_9 << 4 ;
if ( V_55 >= 0xf8 ) {
F_27 ( V_17 , V_49 | 0x0f , V_55 , 0 , 0 ) ;
} else if ( V_55 >= 0xf0 ) {
switch ( V_55 ) {
case 0xf0 :
V_54 -> V_10 [ 0 ] = V_55 ;
V_54 -> V_56 = V_57 ;
break;
case 0xf1 :
case 0xf3 :
V_54 -> V_10 [ 0 ] = V_55 ;
V_54 -> V_56 = V_58 ;
break;
case 0xf2 :
V_54 -> V_10 [ 0 ] = V_55 ;
V_54 -> V_56 = V_59 ;
break;
case 0xf4 :
case 0xf5 :
V_54 -> V_56 = V_60 ;
break;
case 0xf6 :
F_27 ( V_17 , V_49 | 0x05 , 0xf6 , 0 , 0 ) ;
V_54 -> V_56 = V_60 ;
break;
case 0xf7 :
switch ( V_54 -> V_56 ) {
case V_61 :
F_27 ( V_17 ,
V_49 | 0x05 , 0xf7 , 0 , 0 ) ;
break;
case V_57 :
F_27 ( V_17 ,
V_49 | 0x06 , V_54 -> V_10 [ 0 ] , 0xf7 , 0 ) ;
break;
case V_62 :
F_27 ( V_17 ,
V_49 | 0x07 , V_54 -> V_10 [ 0 ] ,
V_54 -> V_10 [ 1 ] , 0xf7 ) ;
break;
}
V_54 -> V_56 = V_60 ;
break;
}
} else if ( V_55 >= 0x80 ) {
V_54 -> V_10 [ 0 ] = V_55 ;
if ( V_55 >= 0xc0 && V_55 <= 0xdf )
V_54 -> V_56 = V_58 ;
else
V_54 -> V_56 = V_59 ;
} else {
switch ( V_54 -> V_56 ) {
case V_58 :
if ( V_54 -> V_10 [ 0 ] < 0xf0 ) {
V_49 |= V_54 -> V_10 [ 0 ] >> 4 ;
} else {
V_49 |= 0x02 ;
V_54 -> V_56 = V_60 ;
}
F_27 ( V_17 , V_49 , V_54 -> V_10 [ 0 ] , V_55 , 0 ) ;
break;
case V_59 :
V_54 -> V_10 [ 1 ] = V_55 ;
V_54 -> V_56 = V_63 ;
break;
case V_63 :
if ( V_54 -> V_10 [ 0 ] < 0xf0 ) {
V_49 |= V_54 -> V_10 [ 0 ] >> 4 ;
V_54 -> V_56 = V_59 ;
} else {
V_49 |= 0x03 ;
V_54 -> V_56 = V_60 ;
}
F_27 ( V_17 ,
V_49 , V_54 -> V_10 [ 0 ] , V_54 -> V_10 [ 1 ] , V_55 ) ;
break;
case V_61 :
V_54 -> V_10 [ 0 ] = V_55 ;
V_54 -> V_56 = V_57 ;
break;
case V_57 :
V_54 -> V_10 [ 1 ] = V_55 ;
V_54 -> V_56 = V_62 ;
break;
case V_62 :
F_27 ( V_17 ,
V_49 | 0x04 , V_54 -> V_10 [ 0 ] , V_54 -> V_10 [ 1 ] , V_55 ) ;
V_54 -> V_56 = V_61 ;
break;
}
}
}
static void F_29 ( struct V_1 * V_11 )
{
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_11 -> V_64 ; V_18 ++ ) {
struct V_53 * V_54 = V_11 -> V_65 + V_18 ;
struct V_13 * V_14 = V_54 -> V_14 ;
if ( V_54 -> V_66 && V_14 )
F_30 ( V_14 ) ;
}
}
static int F_31 ( struct V_1 * V_11 , struct V_6 * V_7 )
{
struct V_5 * V_17 = NULL ;
unsigned int V_67 , V_18 ;
bool V_66 = false ;
int V_35 ;
V_67 = F_32 ( & V_11 -> V_40 , & V_17 ) ;
if ( V_67 != 1 ) {
ERROR ( V_11 , L_8 , V_68 ) ;
return - 1 ;
}
if ( V_17 -> V_8 > 0 )
return 0 ;
for ( V_18 = V_11 -> V_69 ; V_18 < V_11 -> V_64 ; ++ V_18 ) {
struct V_53 * V_54 = V_11 -> V_65 + V_18 ;
struct V_13 * V_14 = V_54 -> V_14 ;
if ( ! V_54 -> V_66 || ! V_14 )
continue;
while ( V_17 -> V_8 + 3 < V_11 -> V_41 ) {
T_1 V_55 ;
if ( F_33 ( V_14 , & V_55 , 1 ) != 1 ) {
V_54 -> V_66 = 0 ;
break;
}
F_28 ( V_17 , V_54 , V_55 ) ;
}
V_66 = ! ! V_54 -> V_66 ;
if ( V_66 )
break;
}
V_11 -> V_69 = V_66 ? V_18 : 0 ;
if ( V_17 -> V_8 <= 0 )
goto V_70;
V_35 = F_14 ( V_7 , V_17 , V_34 ) ;
if ( V_35 < 0 ) {
ERROR ( V_11 , L_9 ,
V_11 -> V_27 -> V_31 , V_35 ) ;
V_17 -> V_8 = 0 ;
} else {
F_34 ( & V_11 -> V_40 ) ;
F_22 ( & V_11 -> V_40 , V_17 ) ;
}
V_70:
return V_66 ;
}
static void F_10 ( struct V_1 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_27 ;
int V_71 ;
unsigned long V_72 ;
if ( ! V_7 || ! V_7 -> V_73 )
goto V_74;
F_35 ( & V_11 -> V_75 , V_72 ) ;
do {
V_71 = F_31 ( V_11 , V_7 ) ;
if ( V_71 < 0 ) {
F_36 ( & V_11 -> V_75 , V_72 ) ;
goto V_74;
}
} while ( V_71 );
F_36 ( & V_11 -> V_75 , V_72 ) ;
return;
V_74:
F_29 ( V_11 ) ;
}
static void F_37 ( unsigned long V_10 )
{
struct V_1 * V_11 = (struct V_1 * ) V_10 ;
F_10 ( V_11 ) ;
}
static int F_38 ( struct V_13 * V_14 )
{
struct V_1 * V_11 = V_14 -> V_76 -> V_77 ;
struct V_53 * V_54 ;
if ( V_14 -> V_78 >= V_11 -> V_64 )
return - V_79 ;
F_11 ( V_11 , L_10 , V_68 ) ;
V_54 = V_11 -> V_65 + V_14 -> V_78 ;
V_54 -> V_14 = V_14 ;
V_54 -> V_56 = V_60 ;
return 0 ;
}
static int F_39 ( struct V_13 * V_14 )
{
struct V_1 * V_11 = V_14 -> V_76 -> V_77 ;
F_11 ( V_11 , L_10 , V_68 ) ;
return 0 ;
}
static void F_40 ( struct V_13 * V_14 , int V_80 )
{
struct V_1 * V_11 = V_14 -> V_76 -> V_77 ;
if ( V_14 -> V_78 >= V_11 -> V_64 )
return;
F_11 ( V_11 , L_11 , V_68 , V_80 ) ;
V_11 -> V_65 [ V_14 -> V_78 ] . V_66 = V_80 ;
if ( V_80 )
F_41 ( & V_11 -> V_81 ) ;
}
static int F_42 ( struct V_13 * V_14 )
{
struct V_1 * V_11 = V_14 -> V_76 -> V_77 ;
if ( V_14 -> V_78 >= V_82 )
return - V_79 ;
F_11 ( V_11 , L_10 , V_68 ) ;
V_11 -> V_15 [ V_14 -> V_78 ] = V_14 ;
return 0 ;
}
static int F_43 ( struct V_13 * V_14 )
{
struct V_1 * V_11 = V_14 -> V_76 -> V_77 ;
F_11 ( V_11 , L_10 , V_68 ) ;
return 0 ;
}
static void F_44 ( struct V_13 * V_14 , int V_80 )
{
struct V_1 * V_11 = V_14 -> V_76 -> V_77 ;
F_11 ( V_11 , L_10 , V_68 ) ;
if ( V_80 )
F_45 ( V_14 -> V_78 , & V_11 -> V_16 ) ;
else
F_46 ( V_14 -> V_78 , & V_11 -> V_16 ) ;
}
static inline void F_47 ( struct V_1 * V_11 )
{
if ( V_11 -> V_83 ) {
F_48 ( V_11 -> V_83 ) ;
V_11 -> V_83 = NULL ;
}
}
static int F_49 ( struct V_1 * V_11 )
{
struct V_84 * V_83 ;
struct V_85 * V_76 ;
int V_35 ;
static struct V_86 V_87 = {
. V_88 = F_26 ,
} ;
V_35 = F_50 ( & V_11 -> V_36 -> V_89 , V_11 -> V_90 , V_11 -> V_91 ,
V_92 , 0 , & V_83 ) ;
if ( V_35 < 0 ) {
ERROR ( V_11 , L_12 ) ;
goto V_93;
}
V_11 -> V_83 = V_83 ;
V_35 = F_51 ( V_83 , V_94 , V_11 , & V_87 ) ;
if ( V_35 < 0 ) {
ERROR ( V_11 , L_13 , V_35 ) ;
goto V_93;
}
strcpy ( V_83 -> V_95 , V_96 ) ;
strcpy ( V_83 -> V_97 , V_96 ) ;
strcpy ( V_83 -> V_98 , V_99 ) ;
F_52 ( V_83 , L_14 ) ;
V_35 = F_53 ( V_83 , V_83 -> V_97 , 0 ,
V_11 -> V_100 , V_11 -> V_64 , & V_76 ) ;
if ( V_35 < 0 ) {
ERROR ( V_11 , L_15 , V_35 ) ;
goto V_93;
}
V_11 -> V_76 = V_76 ;
V_11 -> V_69 = 0 ;
strcpy ( V_76 -> V_31 , V_83 -> V_98 ) ;
V_76 -> V_101 = V_102 |
V_103 |
V_104 ;
V_76 -> V_77 = V_11 ;
F_54 ( V_76 , V_105 , & V_106 ) ;
F_54 ( V_76 , V_107 , & V_108 ) ;
V_35 = F_55 ( V_83 ) ;
if ( V_35 < 0 ) {
ERROR ( V_11 , L_16 ) ;
goto V_93;
}
F_11 ( V_11 , L_17 , V_68 ) ;
return 0 ;
V_93:
F_47 ( V_11 ) ;
return V_35 ;
}
static int F_56 ( struct V_109 * V_110 , struct V_2 * V_3 )
{
struct V_111 * * V_112 ;
struct V_113 V_114 [ V_82 ] ;
struct V_113 V_115 [ V_82 ] ;
struct V_116 V_117 [ V_82 ] ;
struct V_116 V_118 [ V_82 ] ;
struct V_22 * V_23 = V_110 -> V_23 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_119 * V_120 ;
int V_25 , V_121 , V_122 = 1 , V_18 = 0 ;
V_11 -> V_36 = V_23 -> V_36 ;
F_57 ( & V_11 -> V_81 , F_37 , ( unsigned long ) V_11 ) ;
V_25 = F_49 ( V_11 ) ;
if ( V_25 < 0 )
goto V_123;
V_120 = F_58 ( V_110 -> V_23 , V_124 ,
F_59 ( V_125 ) ) ;
if ( F_60 ( V_120 ) ) {
V_25 = F_61 ( V_120 ) ;
goto V_93;
}
V_126 . V_127 = V_120 [ V_128 ] . V_91 ;
V_25 = F_62 ( V_110 , V_3 ) ;
if ( V_25 < 0 )
goto V_93;
V_126 . V_129 = V_25 ;
V_25 = F_62 ( V_110 , V_3 ) ;
if ( V_25 < 0 )
goto V_93;
V_130 . V_129 = V_25 ;
V_131 . V_132 [ 0 ] = V_25 ;
V_11 -> V_39 = V_25 ;
V_25 = - V_133 ;
V_11 -> V_27 = F_63 ( V_23 -> V_36 , & V_134 ) ;
if ( ! V_11 -> V_27 )
goto V_93;
V_11 -> V_26 = F_63 ( V_23 -> V_36 , & V_45 ) ;
if ( ! V_11 -> V_26 )
goto V_93;
V_112 = F_64 ( ( V_82 * 4 ) + 9 , sizeof( * V_112 ) ,
V_135 ) ;
if ( ! V_112 ) {
V_25 = - V_42 ;
goto V_93;
}
V_112 [ V_18 ++ ] = (struct V_111 * ) & V_126 ;
V_112 [ V_18 ++ ] = (struct V_111 * ) & V_131 ;
V_112 [ V_18 ++ ] = (struct V_111 * ) & V_130 ;
V_121 = V_136
+ ( V_11 -> V_64 + V_11 -> V_100 ) *
( V_137 + F_65 ( 1 ) ) ;
V_138 . V_139 = F_66 ( V_121 ) ;
V_112 [ V_18 ++ ] = (struct V_111 * ) & V_138 ;
for ( V_121 = 0 ; V_121 < V_11 -> V_64 ; V_121 ++ ) {
struct V_113 * V_140 = & V_114 [ V_121 ] ;
struct V_116 * V_141 = & V_118 [ V_121 ] ;
V_140 -> V_142 = V_137 ;
V_140 -> V_143 = V_144 ;
V_140 -> V_145 = V_146 ;
V_140 -> V_147 = V_148 ;
V_140 -> V_149 = V_122 ++ ;
V_140 -> V_150 = 0 ;
V_112 [ V_18 ++ ] = (struct V_111 * ) V_140 ;
V_141 -> V_142 = F_65 ( 1 ) ;
V_141 -> V_143 = V_144 ;
V_141 -> V_145 = V_151 ;
V_141 -> V_147 = V_152 ;
V_141 -> V_149 = V_122 ++ ;
V_141 -> V_153 = 1 ;
V_141 -> V_154 [ 0 ] . V_155 = 1 ;
V_141 -> V_154 [ 0 ] . V_156 = V_140 -> V_149 ;
V_141 -> V_150 = 0 ;
V_112 [ V_18 ++ ] = (struct V_111 * ) V_141 ;
V_157 . V_158 [ V_121 ] = V_141 -> V_149 ;
}
for ( V_121 = 0 ; V_121 < V_11 -> V_100 ; V_121 ++ ) {
struct V_113 * V_159 = & V_115 [ V_121 ] ;
struct V_116 * V_160 = & V_117 [ V_121 ] ;
V_159 -> V_142 = V_137 ;
V_159 -> V_143 = V_144 ;
V_159 -> V_145 = V_146 ;
V_159 -> V_147 = V_152 ;
V_159 -> V_149 = V_122 ++ ;
V_159 -> V_150 = 0 ;
V_112 [ V_18 ++ ] = (struct V_111 * ) V_159 ;
V_160 -> V_142 = F_65 ( 1 ) ;
V_160 -> V_143 = V_144 ;
V_160 -> V_145 = V_151 ;
V_160 -> V_147 = V_148 ;
V_160 -> V_149 = V_122 ++ ;
V_160 -> V_153 = 1 ;
V_160 -> V_150 = 0 ;
V_160 -> V_154 [ 0 ] . V_156 = V_159 -> V_149 ;
V_160 -> V_154 [ 0 ] . V_155 = 1 ;
V_112 [ V_18 ++ ] = (struct V_111 * ) V_160 ;
V_161 . V_158 [ V_121 ] = V_159 -> V_149 ;
}
V_161 . V_142 = F_67 ( V_11 -> V_64 ) ;
V_161 . V_162 = V_11 -> V_64 ;
V_157 . V_142 = F_67 ( V_11 -> V_100 ) ;
V_157 . V_162 = V_11 -> V_100 ;
V_112 [ V_18 ++ ] = (struct V_111 * ) & V_45 ;
V_112 [ V_18 ++ ] = (struct V_111 * ) & V_161 ;
V_112 [ V_18 ++ ] = (struct V_111 * ) & V_134 ;
V_112 [ V_18 ++ ] = (struct V_111 * ) & V_157 ;
V_112 [ V_18 ++ ] = NULL ;
V_3 -> V_163 = F_68 ( V_112 ) ;
if ( ! V_3 -> V_163 )
goto V_164;
if ( F_69 ( V_110 -> V_23 -> V_36 ) ) {
V_134 . V_46 = F_66 ( 512 ) ;
V_45 . V_46 = F_66 ( 512 ) ;
V_3 -> V_165 = F_68 ( V_112 ) ;
if ( ! V_3 -> V_165 )
goto V_164;
}
F_70 ( V_112 ) ;
return 0 ;
V_164:
F_70 ( V_112 ) ;
F_71 ( V_3 -> V_165 ) ;
V_93:
F_47 ( V_11 ) ;
V_123:
ERROR ( V_23 , L_18 , V_3 -> V_31 , V_25 ) ;
return V_25 ;
}
static inline struct V_166 * F_72 ( struct V_167 * V_168 )
{
return F_2 ( F_73 ( V_168 ) , struct V_166 ,
V_169 . V_170 ) ;
}
static void F_74 ( struct V_167 * V_168 )
{
struct V_166 * V_171 = F_72 ( V_168 ) ;
F_75 ( & V_171 -> V_169 ) ;
}
static T_3 F_76 ( struct V_167 * V_168 , char * V_172 )
{
struct V_166 * V_171 = F_72 ( V_168 ) ;
int V_173 ;
F_77 ( & V_171 -> V_174 ) ;
if ( V_171 -> V_91 ) {
V_173 = F_78 ( V_172 , V_171 -> V_91 , V_175 ) ;
} else {
V_172 [ 0 ] = 0 ;
V_173 = 0 ;
}
F_79 ( & V_171 -> V_174 ) ;
return V_173 ;
}
static T_3 F_80 ( struct V_167 * V_168 ,
const char * V_172 , T_4 V_67 )
{
struct V_166 * V_171 = F_72 ( V_168 ) ;
int V_71 ;
char * V_110 ;
F_77 ( & V_171 -> V_174 ) ;
if ( V_171 -> V_176 ) {
V_71 = - V_177 ;
goto V_178;
}
V_110 = F_81 ( V_172 , V_67 , V_135 ) ;
if ( ! V_110 ) {
V_71 = - V_42 ;
goto V_178;
}
if ( V_171 -> V_179 )
F_70 ( V_171 -> V_91 ) ;
V_171 -> V_91 = V_110 ;
V_171 -> V_179 = true ;
V_71 = V_67 ;
V_178:
F_79 ( & V_171 -> V_174 ) ;
return V_71 ;
}
static void F_82 ( struct V_180 * V_3 )
{
struct V_166 * V_171 ;
V_171 = F_2 ( V_3 , struct V_166 , V_169 ) ;
if ( V_171 -> V_179 )
F_70 ( V_171 -> V_91 ) ;
F_70 ( V_171 ) ;
}
static struct V_180 * F_83 ( void )
{
struct V_166 * V_171 ;
V_171 = F_84 ( sizeof( * V_171 ) , V_135 ) ;
if ( ! V_171 )
return F_85 ( - V_42 ) ;
F_86 ( & V_171 -> V_174 ) ;
V_171 -> V_169 . V_181 = F_82 ;
V_171 -> V_90 = V_182 ;
V_171 -> V_91 = V_183 ;
V_171 -> V_41 = 256 ;
V_171 -> V_44 = 32 ;
V_171 -> V_64 = 1 ;
V_171 -> V_100 = 1 ;
F_87 ( & V_171 -> V_169 . V_170 , L_19 ,
& V_184 ) ;
return & V_171 -> V_169 ;
}
static void F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_11 ;
struct V_166 * V_171 ;
V_11 = F_1 ( V_3 ) ;
V_171 = F_2 ( V_3 -> V_185 , struct V_166 , V_169 ) ;
F_70 ( V_11 -> V_91 ) ;
F_77 ( & V_171 -> V_174 ) ;
F_89 ( & V_11 -> V_40 ) ;
F_70 ( V_11 ) ;
-- V_171 -> V_176 ;
F_79 ( & V_171 -> V_174 ) ;
}
static void F_90 ( struct V_109 * V_110 , struct V_2 * V_3 )
{
struct V_22 * V_23 = V_3 -> V_24 -> V_23 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_84 * V_83 ;
F_13 ( V_23 , L_20 ) ;
F_24 ( V_3 ) ;
V_83 = V_11 -> V_83 ;
V_11 -> V_83 = NULL ;
if ( V_83 )
F_48 ( V_83 ) ;
F_91 ( V_3 ) ;
}
static struct V_2 * F_92 ( struct V_180 * V_185 )
{
struct V_1 * V_11 = NULL ;
struct V_166 * V_171 ;
int V_25 , V_18 ;
V_171 = F_2 ( V_185 , struct V_166 , V_169 ) ;
F_77 ( & V_171 -> V_174 ) ;
if ( V_171 -> V_64 > V_82 || V_171 -> V_100 > V_82 ) {
V_25 = - V_79 ;
goto V_186;
}
V_11 = F_84 (
sizeof( * V_11 ) + V_171 -> V_64 * sizeof( * V_11 -> V_65 ) ,
V_135 ) ;
if ( ! V_11 ) {
V_25 = - V_42 ;
goto V_186;
}
for ( V_18 = 0 ; V_18 < V_171 -> V_64 ; V_18 ++ )
V_11 -> V_65 [ V_18 ] . V_9 = V_18 ;
V_11 -> V_91 = F_93 ( V_171 -> V_91 , V_135 ) ;
if ( V_171 -> V_91 && ! V_11 -> V_91 ) {
V_25 = - V_42 ;
goto V_186;
}
V_11 -> V_64 = V_171 -> V_64 ;
V_11 -> V_100 = V_171 -> V_100 ;
V_11 -> V_90 = V_171 -> V_90 ;
V_11 -> V_41 = V_171 -> V_41 ;
V_11 -> V_44 = V_171 -> V_44 ;
V_11 -> V_69 = 0 ;
V_25 = F_94 ( & V_11 -> V_40 , V_11 -> V_44 , V_135 ) ;
if ( V_25 )
goto V_186;
F_95 ( & V_11 -> V_75 ) ;
++ V_171 -> V_176 ;
F_79 ( & V_171 -> V_174 ) ;
V_11 -> V_4 . V_31 = L_21 ;
V_11 -> V_4 . V_187 = F_56 ;
V_11 -> V_4 . V_188 = F_90 ;
V_11 -> V_4 . V_189 = F_20 ;
V_11 -> V_4 . V_190 = F_24 ;
V_11 -> V_4 . V_191 = F_88 ;
return & V_11 -> V_4 ;
V_186:
F_79 ( & V_171 -> V_174 ) ;
F_70 ( V_11 ) ;
return F_85 ( V_25 ) ;
}
