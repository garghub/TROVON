static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 ,
unsigned V_8 )
{
return F_4 ( V_7 , V_8 , V_8 ) ;
}
static void F_5 ( struct V_6 * V_7 , struct V_5 * V_9 )
{
F_6 ( V_9 -> V_10 ) ;
F_7 ( V_7 , V_9 ) ;
}
static void F_8 ( struct V_6 * V_7 , int V_11 ,
T_1 * V_12 , int V_8 )
{
struct V_1 * V_13 = V_7 -> V_14 ;
struct V_15 * V_16 = V_13 -> V_17 [ V_11 ] ;
if ( ! V_16 )
return;
if ( ! F_9 ( V_11 , & V_13 -> V_18 ) )
return;
F_10 ( V_16 , V_12 , V_8 ) ;
}
static void F_11 ( struct V_6 * V_7 , struct V_5 * V_9 )
{
unsigned int V_19 ;
T_2 * V_10 = V_9 -> V_10 ;
for ( V_19 = 0 ; V_19 + 3 < V_9 -> V_20 ; V_19 += 4 )
if ( V_10 [ V_19 ] != 0 ) {
int V_11 = V_10 [ V_19 ] >> 4 ;
int V_8 = V_21 [ V_10 [ V_19 ] & 0x0f ] ;
F_8 ( V_7 , V_11 , & V_10 [ V_19 + 1 ] , V_8 ) ;
}
}
static void
F_12 ( struct V_6 * V_7 , struct V_5 * V_9 )
{
struct V_1 * V_13 = V_7 -> V_14 ;
struct V_22 * V_23 = V_13 -> V_4 . V_24 -> V_23 ;
int V_25 = V_9 -> V_25 ;
switch ( V_25 ) {
case 0 :
if ( V_7 == V_13 -> V_26 ) {
F_11 ( V_7 , V_9 ) ;
} else if ( V_7 == V_13 -> V_27 ) {
F_13 ( V_13 , V_9 ) ;
return;
}
break;
case - V_28 :
case - V_29 :
case - V_30 :
F_14 ( V_23 , L_1 , V_7 -> V_31 , V_25 ,
V_9 -> V_20 , V_9 -> V_8 ) ;
if ( V_7 == V_13 -> V_26 )
F_11 ( V_7 , V_9 ) ;
F_5 ( V_7 , V_9 ) ;
return;
case - V_32 :
default:
F_15 ( V_23 , L_2 , V_7 -> V_31 ,
V_25 , V_9 -> V_20 , V_9 -> V_8 ) ;
break;
case - V_33 :
break;
}
V_25 = F_16 ( V_7 , V_9 , V_34 ) ;
if ( V_25 ) {
ERROR ( V_23 , L_3 ,
V_7 -> V_31 , V_9 -> V_8 , V_25 ) ;
F_17 ( V_7 ) ;
}
}
static int F_18 ( struct V_1 * V_13 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
int V_35 ;
struct V_22 * V_23 = V_3 -> V_24 -> V_23 ;
F_19 ( V_7 ) ;
V_35 = F_20 ( V_13 -> V_36 , V_3 , V_7 ) ;
if ( V_35 ) {
ERROR ( V_23 , L_4 , V_7 -> V_31 , V_35 ) ;
return V_35 ;
}
V_35 = F_21 ( V_7 ) ;
if ( V_35 ) {
ERROR ( V_23 , L_5 , V_7 -> V_31 , V_35 ) ;
return V_35 ;
}
V_7 -> V_14 = V_13 ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , unsigned V_37 , unsigned V_38 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_22 * V_23 = V_3 -> V_24 -> V_23 ;
unsigned V_19 ;
int V_35 ;
if ( V_37 == 0 )
return 0 ;
V_35 = F_18 ( V_13 , V_3 , V_13 -> V_27 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_18 ( V_13 , V_3 , V_13 -> V_26 ) ;
if ( V_35 )
return V_35 ;
F_19 ( V_13 -> V_26 ) ;
V_35 = F_20 ( V_13 -> V_36 , V_3 , V_13 -> V_26 ) ;
if ( V_35 ) {
ERROR ( V_23 , L_4 ,
V_13 -> V_26 -> V_31 , V_35 ) ;
return V_35 ;
}
V_35 = F_21 ( V_13 -> V_26 ) ;
if ( V_35 ) {
ERROR ( V_23 , L_5 ,
V_13 -> V_26 -> V_31 , V_35 ) ;
return V_35 ;
}
V_13 -> V_26 -> V_14 = V_13 ;
for ( V_19 = 0 ; V_19 < V_13 -> V_39 && V_35 == 0 ; V_19 ++ ) {
struct V_5 * V_9 =
F_3 ( V_13 -> V_26 , V_13 -> V_40 ) ;
if ( V_9 == NULL )
return - V_41 ;
V_9 -> V_42 = F_12 ;
V_35 = F_16 ( V_13 -> V_26 , V_9 , V_34 ) ;
if ( V_35 ) {
ERROR ( V_13 , L_6 ,
V_13 -> V_26 -> V_31 , V_35 ) ;
F_5 ( V_13 -> V_26 , V_9 ) ;
}
}
return 0 ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_22 * V_23 = V_3 -> V_24 -> V_23 ;
F_15 ( V_23 , L_7 ) ;
F_19 ( V_13 -> V_27 ) ;
F_19 ( V_13 -> V_26 ) ;
}
static int F_24 ( struct V_43 * V_44 )
{
return 0 ;
}
static void F_25 ( struct V_5 * V_9 , T_1 V_45 ,
T_1 V_46 , T_1 V_47 , T_1 V_48 )
{
unsigned V_8 = V_9 -> V_8 ;
T_2 * V_10 = ( T_2 * ) V_9 -> V_10 + V_8 ;
V_10 [ 0 ] = V_45 ;
V_10 [ 1 ] = V_46 ;
V_10 [ 2 ] = V_47 ;
V_10 [ 3 ] = V_48 ;
V_9 -> V_8 = V_8 + 4 ;
}
static void F_26 ( struct V_5 * V_9 ,
struct V_49 * V_50 , T_1 V_51 )
{
T_1 V_45 = V_50 -> V_11 << 4 ;
if ( V_51 >= 0xf8 ) {
F_25 ( V_9 , V_45 | 0x0f , V_51 , 0 , 0 ) ;
} else if ( V_51 >= 0xf0 ) {
switch ( V_51 ) {
case 0xf0 :
V_50 -> V_12 [ 0 ] = V_51 ;
V_50 -> V_52 = V_53 ;
break;
case 0xf1 :
case 0xf3 :
V_50 -> V_12 [ 0 ] = V_51 ;
V_50 -> V_52 = V_54 ;
break;
case 0xf2 :
V_50 -> V_12 [ 0 ] = V_51 ;
V_50 -> V_52 = V_55 ;
break;
case 0xf4 :
case 0xf5 :
V_50 -> V_52 = V_56 ;
break;
case 0xf6 :
F_25 ( V_9 , V_45 | 0x05 , 0xf6 , 0 , 0 ) ;
V_50 -> V_52 = V_56 ;
break;
case 0xf7 :
switch ( V_50 -> V_52 ) {
case V_57 :
F_25 ( V_9 ,
V_45 | 0x05 , 0xf7 , 0 , 0 ) ;
break;
case V_53 :
F_25 ( V_9 ,
V_45 | 0x06 , V_50 -> V_12 [ 0 ] , 0xf7 , 0 ) ;
break;
case V_58 :
F_25 ( V_9 ,
V_45 | 0x07 , V_50 -> V_12 [ 0 ] ,
V_50 -> V_12 [ 1 ] , 0xf7 ) ;
break;
}
V_50 -> V_52 = V_56 ;
break;
}
} else if ( V_51 >= 0x80 ) {
V_50 -> V_12 [ 0 ] = V_51 ;
if ( V_51 >= 0xc0 && V_51 <= 0xdf )
V_50 -> V_52 = V_54 ;
else
V_50 -> V_52 = V_55 ;
} else {
switch ( V_50 -> V_52 ) {
case V_54 :
if ( V_50 -> V_12 [ 0 ] < 0xf0 ) {
V_45 |= V_50 -> V_12 [ 0 ] >> 4 ;
} else {
V_45 |= 0x02 ;
V_50 -> V_52 = V_56 ;
}
F_25 ( V_9 , V_45 , V_50 -> V_12 [ 0 ] , V_51 , 0 ) ;
break;
case V_55 :
V_50 -> V_12 [ 1 ] = V_51 ;
V_50 -> V_52 = V_59 ;
break;
case V_59 :
if ( V_50 -> V_12 [ 0 ] < 0xf0 ) {
V_45 |= V_50 -> V_12 [ 0 ] >> 4 ;
V_50 -> V_52 = V_55 ;
} else {
V_45 |= 0x03 ;
V_50 -> V_52 = V_56 ;
}
F_25 ( V_9 ,
V_45 , V_50 -> V_12 [ 0 ] , V_50 -> V_12 [ 1 ] , V_51 ) ;
break;
case V_57 :
V_50 -> V_12 [ 0 ] = V_51 ;
V_50 -> V_52 = V_53 ;
break;
case V_53 :
V_50 -> V_12 [ 1 ] = V_51 ;
V_50 -> V_52 = V_58 ;
break;
case V_58 :
F_25 ( V_9 ,
V_45 | 0x04 , V_50 -> V_12 [ 0 ] , V_50 -> V_12 [ 1 ] , V_51 ) ;
V_50 -> V_52 = V_57 ;
break;
}
}
}
static void F_13 ( struct V_1 * V_13 , struct V_5 * V_9 )
{
struct V_6 * V_7 = V_13 -> V_27 ;
int V_19 ;
if ( ! V_7 )
return;
if ( ! V_9 )
V_9 = F_3 ( V_7 , V_13 -> V_40 ) ;
if ( ! V_9 ) {
ERROR ( V_13 , L_8 , V_60 ) ;
return;
}
V_9 -> V_8 = 0 ;
V_9 -> V_42 = F_12 ;
for ( V_19 = 0 ; V_19 < V_61 ; V_19 ++ ) {
struct V_49 * V_50 = V_13 -> V_62 [ V_19 ] ;
struct V_15 * V_16 = V_13 -> V_63 [ V_19 ] ;
if ( ! V_50 || ! V_50 -> V_64 || ! V_16 )
continue;
while ( V_9 -> V_8 + 3 < V_13 -> V_40 ) {
T_1 V_51 ;
if ( F_27 ( V_16 , & V_51 , 1 ) != 1 ) {
V_50 -> V_64 = 0 ;
break;
}
F_26 ( V_9 , V_50 , V_51 ) ;
}
}
if ( V_9 -> V_8 > 0 && V_7 -> V_65 ) {
int V_35 ;
V_35 = F_16 ( V_7 , V_9 , V_34 ) ;
if ( V_35 < 0 )
ERROR ( V_13 , L_6 ,
V_13 -> V_27 -> V_31 , V_35 ) ;
} else {
F_5 ( V_7 , V_9 ) ;
}
}
static void F_28 ( unsigned long V_12 )
{
struct V_1 * V_13 = (struct V_1 * ) V_12 ;
F_13 ( V_13 , NULL ) ;
}
static int F_29 ( struct V_15 * V_16 )
{
struct V_1 * V_13 = V_16 -> V_66 -> V_67 ;
if ( ! V_13 -> V_62 [ V_16 -> V_68 ] )
return - V_69 ;
F_14 ( V_13 , L_9 , V_60 ) ;
V_13 -> V_63 [ V_16 -> V_68 ] = V_16 ;
V_13 -> V_62 [ V_16 -> V_68 ] -> V_52 = V_56 ;
return 0 ;
}
static int F_30 ( struct V_15 * V_16 )
{
struct V_1 * V_13 = V_16 -> V_66 -> V_67 ;
F_14 ( V_13 , L_9 , V_60 ) ;
return 0 ;
}
static void F_31 ( struct V_15 * V_16 , int V_70 )
{
struct V_1 * V_13 = V_16 -> V_66 -> V_67 ;
if ( ! V_13 -> V_62 [ V_16 -> V_68 ] )
return;
F_14 ( V_13 , L_10 , V_60 , V_70 ) ;
V_13 -> V_62 [ V_16 -> V_68 ] -> V_64 = V_70 ;
if ( V_70 )
F_32 ( & V_13 -> V_71 ) ;
}
static int F_33 ( struct V_15 * V_16 )
{
struct V_1 * V_13 = V_16 -> V_66 -> V_67 ;
if ( V_16 -> V_68 >= V_61 )
return - V_69 ;
F_14 ( V_13 , L_9 , V_60 ) ;
V_13 -> V_17 [ V_16 -> V_68 ] = V_16 ;
return 0 ;
}
static int F_34 ( struct V_15 * V_16 )
{
struct V_1 * V_13 = V_16 -> V_66 -> V_67 ;
F_14 ( V_13 , L_9 , V_60 ) ;
return 0 ;
}
static void F_35 ( struct V_15 * V_16 , int V_70 )
{
struct V_1 * V_13 = V_16 -> V_66 -> V_67 ;
F_14 ( V_13 , L_9 , V_60 ) ;
if ( V_70 )
F_36 ( V_16 -> V_68 , & V_13 -> V_18 ) ;
else
F_37 ( V_16 -> V_68 , & V_13 -> V_18 ) ;
}
static inline void F_38 ( struct V_1 * V_13 )
{
if ( V_13 -> V_72 ) {
F_39 ( V_13 -> V_72 ) ;
V_13 -> V_72 = NULL ;
}
}
static int F_40 ( struct V_1 * V_13 )
{
struct V_73 * V_72 ;
struct V_74 * V_66 ;
int V_35 ;
static struct V_75 V_76 = {
. V_77 = F_24 ,
} ;
V_35 = F_41 ( & V_13 -> V_36 -> V_78 , V_13 -> V_79 , V_13 -> V_80 ,
V_81 , 0 , & V_72 ) ;
if ( V_35 < 0 ) {
ERROR ( V_13 , L_11 ) ;
goto V_82;
}
V_13 -> V_72 = V_72 ;
V_35 = F_42 ( V_72 , V_83 , V_13 , & V_76 ) ;
if ( V_35 < 0 ) {
ERROR ( V_13 , L_12 , V_35 ) ;
goto V_82;
}
strcpy ( V_72 -> V_84 , V_85 ) ;
strcpy ( V_72 -> V_86 , V_85 ) ;
strcpy ( V_72 -> V_87 , V_88 ) ;
F_43 ( V_72 , L_13 ) ;
V_35 = F_44 ( V_72 , V_72 -> V_86 , 0 ,
V_13 -> V_89 , V_13 -> V_90 , & V_66 ) ;
if ( V_35 < 0 ) {
ERROR ( V_13 , L_14 , V_35 ) ;
goto V_82;
}
V_13 -> V_66 = V_66 ;
strcpy ( V_66 -> V_31 , V_72 -> V_87 ) ;
V_66 -> V_91 = V_92 |
V_93 |
V_94 ;
V_66 -> V_67 = V_13 ;
F_45 ( V_66 , V_95 , & V_96 ) ;
F_45 ( V_66 , V_97 , & V_98 ) ;
V_35 = F_46 ( V_72 ) ;
if ( V_35 < 0 ) {
ERROR ( V_13 , L_15 ) ;
goto V_82;
}
F_14 ( V_13 , L_16 , V_60 ) ;
return 0 ;
V_82:
F_38 ( V_13 ) ;
return V_35 ;
}
static int F_47 ( struct V_99 * V_100 , struct V_2 * V_3 )
{
struct V_101 * * V_102 ;
struct V_103 V_104 [ V_61 ] ;
struct V_103 V_105 [ V_61 ] ;
struct V_106 V_107 [ V_61 ] ;
struct V_106 V_108 [ V_61 ] ;
struct V_22 * V_23 = V_100 -> V_23 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_109 * V_110 ;
int V_25 , V_111 , V_112 = 1 , V_19 = 0 ;
V_13 -> V_36 = V_23 -> V_36 ;
F_48 ( & V_13 -> V_71 , F_28 , ( unsigned long ) V_13 ) ;
V_25 = F_40 ( V_13 ) ;
if ( V_25 < 0 )
goto V_113;
V_110 = F_49 ( V_100 -> V_23 , V_114 ,
F_50 ( V_115 ) ) ;
if ( F_51 ( V_110 ) ) {
V_25 = F_52 ( V_110 ) ;
goto V_82;
}
V_116 . V_117 = V_110 [ V_118 ] . V_80 ;
V_25 = F_53 ( V_100 , V_3 ) ;
if ( V_25 < 0 )
goto V_82;
V_116 . V_119 = V_25 ;
V_25 = F_53 ( V_100 , V_3 ) ;
if ( V_25 < 0 )
goto V_82;
V_120 . V_119 = V_25 ;
V_121 . V_122 [ 0 ] = V_25 ;
V_25 = - V_123 ;
V_13 -> V_27 = F_54 ( V_23 -> V_36 , & V_124 ) ;
if ( ! V_13 -> V_27 )
goto V_82;
V_13 -> V_26 = F_54 ( V_23 -> V_36 , & V_125 ) ;
if ( ! V_13 -> V_26 )
goto V_82;
V_102 = F_55 ( ( V_61 * 4 ) + 9 , sizeof( * V_102 ) ,
V_126 ) ;
if ( ! V_102 ) {
V_25 = - V_41 ;
goto V_82;
}
V_102 [ V_19 ++ ] = (struct V_101 * ) & V_116 ;
V_102 [ V_19 ++ ] = (struct V_101 * ) & V_121 ;
V_102 [ V_19 ++ ] = (struct V_101 * ) & V_120 ;
V_111 = V_127
+ ( V_13 -> V_90 + V_13 -> V_89 ) *
( V_128 + F_56 ( 1 ) ) ;
V_129 . V_130 = F_57 ( V_111 ) ;
V_102 [ V_19 ++ ] = (struct V_101 * ) & V_129 ;
for ( V_111 = 0 ; V_111 < V_13 -> V_90 ; V_111 ++ ) {
struct V_103 * V_131 = & V_104 [ V_111 ] ;
struct V_106 * V_132 = & V_108 [ V_111 ] ;
V_131 -> V_133 = V_128 ;
V_131 -> V_134 = V_135 ;
V_131 -> V_136 = V_137 ;
V_131 -> V_138 = V_139 ;
V_131 -> V_140 = V_112 ++ ;
V_131 -> V_141 = 0 ;
V_102 [ V_19 ++ ] = (struct V_101 * ) V_131 ;
V_132 -> V_133 = F_56 ( 1 ) ;
V_132 -> V_134 = V_135 ;
V_132 -> V_136 = V_142 ;
V_132 -> V_138 = V_143 ;
V_132 -> V_140 = V_112 ++ ;
V_132 -> V_144 = 1 ;
V_132 -> V_145 [ 0 ] . V_146 = 1 ;
V_132 -> V_145 [ 0 ] . V_147 = V_131 -> V_140 ;
V_132 -> V_141 = 0 ;
V_102 [ V_19 ++ ] = (struct V_101 * ) V_132 ;
V_148 . V_149 [ V_111 ] = V_132 -> V_140 ;
}
for ( V_111 = 0 ; V_111 < V_13 -> V_89 ; V_111 ++ ) {
struct V_103 * V_150 = & V_105 [ V_111 ] ;
struct V_106 * V_151 = & V_107 [ V_111 ] ;
V_150 -> V_133 = V_128 ;
V_150 -> V_134 = V_135 ;
V_150 -> V_136 = V_137 ;
V_150 -> V_138 = V_143 ;
V_150 -> V_140 = V_112 ++ ;
V_150 -> V_141 = 0 ;
V_102 [ V_19 ++ ] = (struct V_101 * ) V_150 ;
V_151 -> V_133 = F_56 ( 1 ) ;
V_151 -> V_134 = V_135 ;
V_151 -> V_136 = V_142 ;
V_151 -> V_138 = V_139 ;
V_151 -> V_140 = V_112 ++ ;
V_151 -> V_144 = 1 ;
V_151 -> V_141 = 0 ;
V_151 -> V_145 [ 0 ] . V_147 = V_150 -> V_140 ;
V_151 -> V_145 [ 0 ] . V_146 = 1 ;
V_102 [ V_19 ++ ] = (struct V_101 * ) V_151 ;
V_152 . V_149 [ V_111 ] = V_150 -> V_140 ;
}
V_152 . V_133 = F_58 ( V_13 -> V_90 ) ;
V_152 . V_153 = V_13 -> V_90 ;
V_148 . V_133 = F_58 ( V_13 -> V_89 ) ;
V_148 . V_153 = V_13 -> V_89 ;
V_102 [ V_19 ++ ] = (struct V_101 * ) & V_125 ;
V_102 [ V_19 ++ ] = (struct V_101 * ) & V_152 ;
V_102 [ V_19 ++ ] = (struct V_101 * ) & V_124 ;
V_102 [ V_19 ++ ] = (struct V_101 * ) & V_148 ;
V_102 [ V_19 ++ ] = NULL ;
V_3 -> V_154 = F_59 ( V_102 ) ;
if ( ! V_3 -> V_154 )
goto V_155;
if ( F_60 ( V_100 -> V_23 -> V_36 ) ) {
V_124 . V_156 = F_57 ( 512 ) ;
V_125 . V_156 = F_57 ( 512 ) ;
V_3 -> V_157 = F_59 ( V_102 ) ;
if ( ! V_3 -> V_157 )
goto V_155;
}
F_6 ( V_102 ) ;
return 0 ;
V_155:
F_6 ( V_102 ) ;
F_61 ( V_3 -> V_157 ) ;
V_82:
F_38 ( V_13 ) ;
V_113:
ERROR ( V_23 , L_17 , V_3 -> V_31 , V_25 ) ;
return V_25 ;
}
static inline struct V_158 * F_62 ( struct V_159 * V_160 )
{
return F_2 ( F_63 ( V_160 ) , struct V_158 ,
V_161 . V_162 ) ;
}
static void F_64 ( struct V_159 * V_160 )
{
struct V_158 * V_163 = F_62 ( V_160 ) ;
F_65 ( & V_163 -> V_161 ) ;
}
static T_3 F_66 ( struct V_159 * V_160 , char * V_164 )
{
struct V_158 * V_163 = F_62 ( V_160 ) ;
int V_165 ;
F_67 ( & V_163 -> V_166 ) ;
if ( V_163 -> V_80 ) {
V_165 = F_68 ( V_164 , V_163 -> V_80 , V_167 ) ;
} else {
V_164 [ 0 ] = 0 ;
V_165 = 0 ;
}
F_69 ( & V_163 -> V_166 ) ;
return V_165 ;
}
static T_3 F_70 ( struct V_159 * V_160 ,
const char * V_164 , T_4 V_168 )
{
struct V_158 * V_163 = F_62 ( V_160 ) ;
int V_169 ;
char * V_100 ;
F_67 ( & V_163 -> V_166 ) ;
if ( V_163 -> V_170 ) {
V_169 = - V_171 ;
goto V_172;
}
V_100 = F_71 ( V_164 , V_168 , V_126 ) ;
if ( ! V_100 ) {
V_169 = - V_41 ;
goto V_172;
}
if ( V_163 -> V_173 )
F_6 ( V_163 -> V_80 ) ;
V_163 -> V_80 = V_100 ;
V_163 -> V_173 = true ;
V_169 = V_168 ;
V_172:
F_69 ( & V_163 -> V_166 ) ;
return V_169 ;
}
static void F_72 ( struct V_174 * V_3 )
{
struct V_158 * V_163 ;
V_163 = F_2 ( V_3 , struct V_158 , V_161 ) ;
if ( V_163 -> V_173 )
F_6 ( V_163 -> V_80 ) ;
F_6 ( V_163 ) ;
}
static struct V_174 * F_73 ( void )
{
struct V_158 * V_163 ;
V_163 = F_74 ( sizeof( * V_163 ) , V_126 ) ;
if ( ! V_163 )
return F_75 ( - V_41 ) ;
F_76 ( & V_163 -> V_166 ) ;
V_163 -> V_161 . V_175 = F_72 ;
V_163 -> V_79 = V_176 ;
V_163 -> V_80 = V_177 ;
V_163 -> V_40 = 256 ;
V_163 -> V_39 = 32 ;
V_163 -> V_90 = 1 ;
V_163 -> V_89 = 1 ;
F_77 ( & V_163 -> V_161 . V_162 , L_18 ,
& V_178 ) ;
return & V_163 -> V_161 ;
}
static void F_78 ( struct V_2 * V_3 )
{
struct V_1 * V_13 ;
struct V_158 * V_163 ;
int V_19 ;
V_13 = F_1 ( V_3 ) ;
V_163 = F_2 ( V_3 -> V_179 , struct V_158 , V_161 ) ;
F_6 ( V_13 -> V_80 ) ;
F_67 ( & V_163 -> V_166 ) ;
for ( V_19 = V_163 -> V_90 - 1 ; V_19 >= 0 ; -- V_19 )
F_6 ( V_13 -> V_62 [ V_19 ] ) ;
F_6 ( V_13 ) ;
-- V_163 -> V_170 ;
F_69 ( & V_163 -> V_166 ) ;
}
static void F_79 ( struct V_99 * V_100 , struct V_2 * V_3 )
{
struct V_22 * V_23 = V_3 -> V_24 -> V_23 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_73 * V_72 ;
F_15 ( V_23 , L_19 ) ;
F_23 ( V_3 ) ;
V_72 = V_13 -> V_72 ;
V_13 -> V_72 = NULL ;
if ( V_72 )
F_39 ( V_72 ) ;
F_80 ( V_3 ) ;
}
static struct V_2 * F_81 ( struct V_174 * V_179 )
{
struct V_1 * V_13 ;
struct V_158 * V_163 ;
int V_25 , V_19 ;
V_163 = F_2 ( V_179 , struct V_158 , V_161 ) ;
F_67 ( & V_163 -> V_166 ) ;
if ( V_163 -> V_90 > V_61 || V_163 -> V_89 > V_61 ) {
F_69 ( & V_163 -> V_166 ) ;
return F_75 ( - V_69 ) ;
}
V_13 = F_74 ( sizeof( * V_13 ) , V_126 ) ;
if ( ! V_13 ) {
F_69 ( & V_163 -> V_166 ) ;
return F_75 ( - V_41 ) ;
}
for ( V_19 = 0 ; V_19 < V_163 -> V_90 ; V_19 ++ ) {
struct V_49 * V_50 = F_74 ( sizeof( * V_50 ) , V_126 ) ;
if ( ! V_50 ) {
V_25 = - V_41 ;
F_69 ( & V_163 -> V_166 ) ;
goto V_180;
}
V_50 -> V_13 = V_13 ;
V_50 -> V_64 = 0 ;
V_50 -> V_11 = V_19 ;
V_13 -> V_62 [ V_19 ] = V_50 ;
}
V_13 -> V_80 = F_82 ( V_163 -> V_80 , V_126 ) ;
if ( V_163 -> V_80 && ! V_13 -> V_80 ) {
V_25 = - V_41 ;
F_69 ( & V_163 -> V_166 ) ;
goto V_180;
}
V_13 -> V_90 = V_163 -> V_90 ;
V_13 -> V_89 = V_163 -> V_89 ;
V_13 -> V_79 = V_163 -> V_79 ;
V_13 -> V_40 = V_163 -> V_40 ;
V_13 -> V_39 = V_163 -> V_39 ;
++ V_163 -> V_170 ;
F_69 ( & V_163 -> V_166 ) ;
V_13 -> V_4 . V_31 = L_20 ;
V_13 -> V_4 . V_181 = F_47 ;
V_13 -> V_4 . V_182 = F_79 ;
V_13 -> V_4 . V_183 = F_22 ;
V_13 -> V_4 . V_184 = F_23 ;
V_13 -> V_4 . V_185 = F_78 ;
return & V_13 -> V_4 ;
V_180:
for ( -- V_19 ; V_19 >= 0 ; V_19 -- )
F_6 ( V_13 -> V_62 [ V_19 ] ) ;
F_6 ( V_13 ) ;
return F_75 ( V_25 ) ;
}
