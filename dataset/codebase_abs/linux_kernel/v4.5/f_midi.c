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
F_3 ( V_11 -> V_26 , V_11 -> V_41 ) ;
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
static void F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_22 * V_23 = V_3 -> V_24 -> V_23 ;
struct V_5 * V_17 = NULL ;
F_13 ( V_23 , L_7 ) ;
F_17 ( V_11 -> V_27 ) ;
F_17 ( V_11 -> V_26 ) ;
while ( F_24 ( & V_11 -> V_40 , & V_17 ) )
F_12 ( V_11 -> V_27 , V_17 ) ;
}
static int F_25 ( struct V_45 * V_46 )
{
return 0 ;
}
static void F_26 ( struct V_5 * V_17 , T_1 V_47 ,
T_1 V_48 , T_1 V_49 , T_1 V_50 )
{
unsigned V_8 = V_17 -> V_8 ;
T_2 * V_19 = ( T_2 * ) V_17 -> V_19 + V_8 ;
V_19 [ 0 ] = V_47 ;
V_19 [ 1 ] = V_48 ;
V_19 [ 2 ] = V_49 ;
V_19 [ 3 ] = V_50 ;
V_17 -> V_8 = V_8 + 4 ;
}
static void F_27 ( struct V_5 * V_17 ,
struct V_51 * V_52 , T_1 V_53 )
{
T_1 V_47 = V_52 -> V_9 << 4 ;
if ( V_53 >= 0xf8 ) {
F_26 ( V_17 , V_47 | 0x0f , V_53 , 0 , 0 ) ;
} else if ( V_53 >= 0xf0 ) {
switch ( V_53 ) {
case 0xf0 :
V_52 -> V_10 [ 0 ] = V_53 ;
V_52 -> V_54 = V_55 ;
break;
case 0xf1 :
case 0xf3 :
V_52 -> V_10 [ 0 ] = V_53 ;
V_52 -> V_54 = V_56 ;
break;
case 0xf2 :
V_52 -> V_10 [ 0 ] = V_53 ;
V_52 -> V_54 = V_57 ;
break;
case 0xf4 :
case 0xf5 :
V_52 -> V_54 = V_58 ;
break;
case 0xf6 :
F_26 ( V_17 , V_47 | 0x05 , 0xf6 , 0 , 0 ) ;
V_52 -> V_54 = V_58 ;
break;
case 0xf7 :
switch ( V_52 -> V_54 ) {
case V_59 :
F_26 ( V_17 ,
V_47 | 0x05 , 0xf7 , 0 , 0 ) ;
break;
case V_55 :
F_26 ( V_17 ,
V_47 | 0x06 , V_52 -> V_10 [ 0 ] , 0xf7 , 0 ) ;
break;
case V_60 :
F_26 ( V_17 ,
V_47 | 0x07 , V_52 -> V_10 [ 0 ] ,
V_52 -> V_10 [ 1 ] , 0xf7 ) ;
break;
}
V_52 -> V_54 = V_58 ;
break;
}
} else if ( V_53 >= 0x80 ) {
V_52 -> V_10 [ 0 ] = V_53 ;
if ( V_53 >= 0xc0 && V_53 <= 0xdf )
V_52 -> V_54 = V_56 ;
else
V_52 -> V_54 = V_57 ;
} else {
switch ( V_52 -> V_54 ) {
case V_56 :
if ( V_52 -> V_10 [ 0 ] < 0xf0 ) {
V_47 |= V_52 -> V_10 [ 0 ] >> 4 ;
} else {
V_47 |= 0x02 ;
V_52 -> V_54 = V_58 ;
}
F_26 ( V_17 , V_47 , V_52 -> V_10 [ 0 ] , V_53 , 0 ) ;
break;
case V_57 :
V_52 -> V_10 [ 1 ] = V_53 ;
V_52 -> V_54 = V_61 ;
break;
case V_61 :
if ( V_52 -> V_10 [ 0 ] < 0xf0 ) {
V_47 |= V_52 -> V_10 [ 0 ] >> 4 ;
V_52 -> V_54 = V_57 ;
} else {
V_47 |= 0x03 ;
V_52 -> V_54 = V_58 ;
}
F_26 ( V_17 ,
V_47 , V_52 -> V_10 [ 0 ] , V_52 -> V_10 [ 1 ] , V_53 ) ;
break;
case V_59 :
V_52 -> V_10 [ 0 ] = V_53 ;
V_52 -> V_54 = V_55 ;
break;
case V_55 :
V_52 -> V_10 [ 1 ] = V_53 ;
V_52 -> V_54 = V_60 ;
break;
case V_60 :
F_26 ( V_17 ,
V_47 | 0x04 , V_52 -> V_10 [ 0 ] , V_52 -> V_10 [ 1 ] , V_53 ) ;
V_52 -> V_54 = V_59 ;
break;
}
}
}
static void F_28 ( struct V_1 * V_11 )
{
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_62 ; V_18 ++ ) {
struct V_51 * V_52 = V_11 -> V_63 [ V_18 ] ;
struct V_13 * V_14 = V_11 -> V_64 [ V_18 ] ;
if ( ! V_52 )
break;
if ( ! V_52 -> V_65 || ! V_14 )
continue;
F_29 ( V_14 ) ;
}
}
static void F_10 ( struct V_1 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_27 ;
bool V_65 ;
if ( ! V_7 || ! V_7 -> V_66 )
goto V_67;
do {
struct V_5 * V_17 = NULL ;
unsigned int V_68 , V_18 ;
V_65 = false ;
V_68 = F_30 ( & V_11 -> V_40 , & V_17 ) ;
if ( V_68 != 1 ) {
ERROR ( V_11 , L_8 , V_69 ) ;
goto V_67;
}
if ( V_17 -> V_8 > 0 )
return;
for ( V_18 = V_11 -> V_70 ; V_18 < V_62 ; V_18 ++ ) {
struct V_51 * V_52 = V_11 -> V_63 [ V_18 ] ;
struct V_13 * V_14 = V_11 -> V_64 [ V_18 ] ;
if ( ! V_52 ) {
V_11 -> V_70 = 0 ;
break;
}
if ( ! V_52 -> V_65 || ! V_14 )
continue;
while ( V_17 -> V_8 + 3 < V_11 -> V_41 ) {
T_1 V_53 ;
if ( F_31 ( V_14 , & V_53 , 1 ) != 1 ) {
V_52 -> V_65 = 0 ;
break;
}
F_27 ( V_17 , V_52 , V_53 ) ;
}
V_65 = ! ! V_52 -> V_65 ;
if ( V_65 ) {
V_11 -> V_70 = V_18 ;
break;
}
}
if ( V_17 -> V_8 > 0 ) {
int V_35 ;
V_35 = F_14 ( V_7 , V_17 , V_34 ) ;
if ( V_35 < 0 ) {
ERROR ( V_11 , L_9 ,
V_11 -> V_27 -> V_31 , V_35 ) ;
V_17 -> V_8 = 0 ;
} else {
F_32 ( & V_11 -> V_40 ) ;
F_22 ( & V_11 -> V_40 , V_17 ) ;
}
}
} while ( V_65 );
return;
V_67:
F_28 ( V_11 ) ;
}
static void F_33 ( unsigned long V_10 )
{
struct V_1 * V_11 = (struct V_1 * ) V_10 ;
F_10 ( V_11 ) ;
}
static int F_34 ( struct V_13 * V_14 )
{
struct V_1 * V_11 = V_14 -> V_71 -> V_72 ;
if ( ! V_11 -> V_63 [ V_14 -> V_73 ] )
return - V_74 ;
F_11 ( V_11 , L_10 , V_69 ) ;
V_11 -> V_64 [ V_14 -> V_73 ] = V_14 ;
V_11 -> V_63 [ V_14 -> V_73 ] -> V_54 = V_58 ;
return 0 ;
}
static int F_35 ( struct V_13 * V_14 )
{
struct V_1 * V_11 = V_14 -> V_71 -> V_72 ;
F_11 ( V_11 , L_10 , V_69 ) ;
return 0 ;
}
static void F_36 ( struct V_13 * V_14 , int V_75 )
{
struct V_1 * V_11 = V_14 -> V_71 -> V_72 ;
if ( ! V_11 -> V_63 [ V_14 -> V_73 ] )
return;
F_11 ( V_11 , L_11 , V_69 , V_75 ) ;
V_11 -> V_63 [ V_14 -> V_73 ] -> V_65 = V_75 ;
if ( V_75 )
F_37 ( & V_11 -> V_76 ) ;
}
static int F_38 ( struct V_13 * V_14 )
{
struct V_1 * V_11 = V_14 -> V_71 -> V_72 ;
if ( V_14 -> V_73 >= V_62 )
return - V_74 ;
F_11 ( V_11 , L_10 , V_69 ) ;
V_11 -> V_15 [ V_14 -> V_73 ] = V_14 ;
return 0 ;
}
static int F_39 ( struct V_13 * V_14 )
{
struct V_1 * V_11 = V_14 -> V_71 -> V_72 ;
F_11 ( V_11 , L_10 , V_69 ) ;
return 0 ;
}
static void F_40 ( struct V_13 * V_14 , int V_75 )
{
struct V_1 * V_11 = V_14 -> V_71 -> V_72 ;
F_11 ( V_11 , L_10 , V_69 ) ;
if ( V_75 )
F_41 ( V_14 -> V_73 , & V_11 -> V_16 ) ;
else
F_42 ( V_14 -> V_73 , & V_11 -> V_16 ) ;
}
static inline void F_43 ( struct V_1 * V_11 )
{
if ( V_11 -> V_77 ) {
F_44 ( V_11 -> V_77 ) ;
V_11 -> V_77 = NULL ;
}
}
static int F_45 ( struct V_1 * V_11 )
{
struct V_78 * V_77 ;
struct V_79 * V_71 ;
int V_35 ;
static struct V_80 V_81 = {
. V_82 = F_25 ,
} ;
V_35 = F_46 ( & V_11 -> V_36 -> V_83 , V_11 -> V_84 , V_11 -> V_85 ,
V_86 , 0 , & V_77 ) ;
if ( V_35 < 0 ) {
ERROR ( V_11 , L_12 ) ;
goto V_87;
}
V_11 -> V_77 = V_77 ;
V_35 = F_47 ( V_77 , V_88 , V_11 , & V_81 ) ;
if ( V_35 < 0 ) {
ERROR ( V_11 , L_13 , V_35 ) ;
goto V_87;
}
strcpy ( V_77 -> V_89 , V_90 ) ;
strcpy ( V_77 -> V_91 , V_90 ) ;
strcpy ( V_77 -> V_92 , V_93 ) ;
F_48 ( V_77 , L_14 ) ;
V_35 = F_49 ( V_77 , V_77 -> V_91 , 0 ,
V_11 -> V_94 , V_11 -> V_95 , & V_71 ) ;
if ( V_35 < 0 ) {
ERROR ( V_11 , L_15 , V_35 ) ;
goto V_87;
}
V_11 -> V_71 = V_71 ;
V_11 -> V_70 = 0 ;
strcpy ( V_71 -> V_31 , V_77 -> V_92 ) ;
V_71 -> V_96 = V_97 |
V_98 |
V_99 ;
V_71 -> V_72 = V_11 ;
F_50 ( V_71 , V_100 , & V_101 ) ;
F_50 ( V_71 , V_102 , & V_103 ) ;
V_35 = F_51 ( V_77 ) ;
if ( V_35 < 0 ) {
ERROR ( V_11 , L_16 ) ;
goto V_87;
}
F_11 ( V_11 , L_17 , V_69 ) ;
return 0 ;
V_87:
F_43 ( V_11 ) ;
return V_35 ;
}
static int F_52 ( struct V_104 * V_105 , struct V_2 * V_3 )
{
struct V_106 * * V_107 ;
struct V_108 V_109 [ V_62 ] ;
struct V_108 V_110 [ V_62 ] ;
struct V_111 V_112 [ V_62 ] ;
struct V_111 V_113 [ V_62 ] ;
struct V_22 * V_23 = V_105 -> V_23 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_114 * V_115 ;
int V_25 , V_116 , V_117 = 1 , V_18 = 0 ;
V_11 -> V_36 = V_23 -> V_36 ;
F_53 ( & V_11 -> V_76 , F_33 , ( unsigned long ) V_11 ) ;
V_25 = F_45 ( V_11 ) ;
if ( V_25 < 0 )
goto V_118;
V_115 = F_54 ( V_105 -> V_23 , V_119 ,
F_55 ( V_120 ) ) ;
if ( F_56 ( V_115 ) ) {
V_25 = F_57 ( V_115 ) ;
goto V_87;
}
V_121 . V_122 = V_115 [ V_123 ] . V_85 ;
V_25 = F_58 ( V_105 , V_3 ) ;
if ( V_25 < 0 )
goto V_87;
V_121 . V_124 = V_25 ;
V_25 = F_58 ( V_105 , V_3 ) ;
if ( V_25 < 0 )
goto V_87;
V_125 . V_124 = V_25 ;
V_126 . V_127 [ 0 ] = V_25 ;
V_11 -> V_39 = V_25 ;
V_25 = - V_128 ;
V_11 -> V_27 = F_59 ( V_23 -> V_36 , & V_129 ) ;
if ( ! V_11 -> V_27 )
goto V_87;
V_11 -> V_26 = F_59 ( V_23 -> V_36 , & V_130 ) ;
if ( ! V_11 -> V_26 )
goto V_87;
V_107 = F_60 ( ( V_62 * 4 ) + 9 , sizeof( * V_107 ) ,
V_131 ) ;
if ( ! V_107 ) {
V_25 = - V_42 ;
goto V_87;
}
V_107 [ V_18 ++ ] = (struct V_106 * ) & V_121 ;
V_107 [ V_18 ++ ] = (struct V_106 * ) & V_126 ;
V_107 [ V_18 ++ ] = (struct V_106 * ) & V_125 ;
V_116 = V_132
+ ( V_11 -> V_95 + V_11 -> V_94 ) *
( V_133 + F_61 ( 1 ) ) ;
V_134 . V_135 = F_62 ( V_116 ) ;
V_107 [ V_18 ++ ] = (struct V_106 * ) & V_134 ;
for ( V_116 = 0 ; V_116 < V_11 -> V_95 ; V_116 ++ ) {
struct V_108 * V_136 = & V_109 [ V_116 ] ;
struct V_111 * V_137 = & V_113 [ V_116 ] ;
V_136 -> V_138 = V_133 ;
V_136 -> V_139 = V_140 ;
V_136 -> V_141 = V_142 ;
V_136 -> V_143 = V_144 ;
V_136 -> V_145 = V_117 ++ ;
V_136 -> V_146 = 0 ;
V_107 [ V_18 ++ ] = (struct V_106 * ) V_136 ;
V_137 -> V_138 = F_61 ( 1 ) ;
V_137 -> V_139 = V_140 ;
V_137 -> V_141 = V_147 ;
V_137 -> V_143 = V_148 ;
V_137 -> V_145 = V_117 ++ ;
V_137 -> V_149 = 1 ;
V_137 -> V_150 [ 0 ] . V_151 = 1 ;
V_137 -> V_150 [ 0 ] . V_152 = V_136 -> V_145 ;
V_137 -> V_146 = 0 ;
V_107 [ V_18 ++ ] = (struct V_106 * ) V_137 ;
V_153 . V_154 [ V_116 ] = V_137 -> V_145 ;
}
for ( V_116 = 0 ; V_116 < V_11 -> V_94 ; V_116 ++ ) {
struct V_108 * V_155 = & V_110 [ V_116 ] ;
struct V_111 * V_156 = & V_112 [ V_116 ] ;
V_155 -> V_138 = V_133 ;
V_155 -> V_139 = V_140 ;
V_155 -> V_141 = V_142 ;
V_155 -> V_143 = V_148 ;
V_155 -> V_145 = V_117 ++ ;
V_155 -> V_146 = 0 ;
V_107 [ V_18 ++ ] = (struct V_106 * ) V_155 ;
V_156 -> V_138 = F_61 ( 1 ) ;
V_156 -> V_139 = V_140 ;
V_156 -> V_141 = V_147 ;
V_156 -> V_143 = V_144 ;
V_156 -> V_145 = V_117 ++ ;
V_156 -> V_149 = 1 ;
V_156 -> V_146 = 0 ;
V_156 -> V_150 [ 0 ] . V_152 = V_155 -> V_145 ;
V_156 -> V_150 [ 0 ] . V_151 = 1 ;
V_107 [ V_18 ++ ] = (struct V_106 * ) V_156 ;
V_157 . V_154 [ V_116 ] = V_155 -> V_145 ;
}
V_157 . V_138 = F_63 ( V_11 -> V_95 ) ;
V_157 . V_158 = V_11 -> V_95 ;
V_153 . V_138 = F_63 ( V_11 -> V_94 ) ;
V_153 . V_158 = V_11 -> V_94 ;
V_107 [ V_18 ++ ] = (struct V_106 * ) & V_130 ;
V_107 [ V_18 ++ ] = (struct V_106 * ) & V_157 ;
V_107 [ V_18 ++ ] = (struct V_106 * ) & V_129 ;
V_107 [ V_18 ++ ] = (struct V_106 * ) & V_153 ;
V_107 [ V_18 ++ ] = NULL ;
V_3 -> V_159 = F_64 ( V_107 ) ;
if ( ! V_3 -> V_159 )
goto V_160;
if ( F_65 ( V_105 -> V_23 -> V_36 ) ) {
V_129 . V_161 = F_62 ( 512 ) ;
V_130 . V_161 = F_62 ( 512 ) ;
V_3 -> V_162 = F_64 ( V_107 ) ;
if ( ! V_3 -> V_162 )
goto V_160;
}
F_66 ( V_107 ) ;
return 0 ;
V_160:
F_66 ( V_107 ) ;
F_67 ( V_3 -> V_162 ) ;
V_87:
F_43 ( V_11 ) ;
V_118:
ERROR ( V_23 , L_18 , V_3 -> V_31 , V_25 ) ;
return V_25 ;
}
static inline struct V_163 * F_68 ( struct V_164 * V_165 )
{
return F_2 ( F_69 ( V_165 ) , struct V_163 ,
V_166 . V_167 ) ;
}
static void F_70 ( struct V_164 * V_165 )
{
struct V_163 * V_168 = F_68 ( V_165 ) ;
F_71 ( & V_168 -> V_166 ) ;
}
static T_3 F_72 ( struct V_164 * V_165 , char * V_169 )
{
struct V_163 * V_168 = F_68 ( V_165 ) ;
int V_170 ;
F_73 ( & V_168 -> V_171 ) ;
if ( V_168 -> V_85 ) {
V_170 = F_74 ( V_169 , V_168 -> V_85 , V_172 ) ;
} else {
V_169 [ 0 ] = 0 ;
V_170 = 0 ;
}
F_75 ( & V_168 -> V_171 ) ;
return V_170 ;
}
static T_3 F_76 ( struct V_164 * V_165 ,
const char * V_169 , T_4 V_68 )
{
struct V_163 * V_168 = F_68 ( V_165 ) ;
int V_173 ;
char * V_105 ;
F_73 ( & V_168 -> V_171 ) ;
if ( V_168 -> V_174 ) {
V_173 = - V_175 ;
goto V_176;
}
V_105 = F_77 ( V_169 , V_68 , V_131 ) ;
if ( ! V_105 ) {
V_173 = - V_42 ;
goto V_176;
}
if ( V_168 -> V_177 )
F_66 ( V_168 -> V_85 ) ;
V_168 -> V_85 = V_105 ;
V_168 -> V_177 = true ;
V_173 = V_68 ;
V_176:
F_75 ( & V_168 -> V_171 ) ;
return V_173 ;
}
static void F_78 ( struct V_178 * V_3 )
{
struct V_163 * V_168 ;
V_168 = F_2 ( V_3 , struct V_163 , V_166 ) ;
if ( V_168 -> V_177 )
F_66 ( V_168 -> V_85 ) ;
F_66 ( V_168 ) ;
}
static struct V_178 * F_79 ( void )
{
struct V_163 * V_168 ;
V_168 = F_80 ( sizeof( * V_168 ) , V_131 ) ;
if ( ! V_168 )
return F_81 ( - V_42 ) ;
F_82 ( & V_168 -> V_171 ) ;
V_168 -> V_166 . V_179 = F_78 ;
V_168 -> V_84 = V_180 ;
V_168 -> V_85 = V_181 ;
V_168 -> V_41 = 256 ;
V_168 -> V_44 = 32 ;
V_168 -> V_95 = 1 ;
V_168 -> V_94 = 1 ;
F_83 ( & V_168 -> V_166 . V_167 , L_19 ,
& V_182 ) ;
return & V_168 -> V_166 ;
}
static void F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_11 ;
struct V_163 * V_168 ;
int V_18 ;
V_11 = F_1 ( V_3 ) ;
V_168 = F_2 ( V_3 -> V_183 , struct V_163 , V_166 ) ;
F_66 ( V_11 -> V_85 ) ;
F_73 ( & V_168 -> V_171 ) ;
for ( V_18 = V_168 -> V_95 - 1 ; V_18 >= 0 ; -- V_18 )
F_66 ( V_11 -> V_63 [ V_18 ] ) ;
F_85 ( & V_11 -> V_40 ) ;
F_66 ( V_11 ) ;
-- V_168 -> V_174 ;
F_75 ( & V_168 -> V_171 ) ;
}
static void F_86 ( struct V_104 * V_105 , struct V_2 * V_3 )
{
struct V_22 * V_23 = V_3 -> V_24 -> V_23 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_78 * V_77 ;
F_13 ( V_23 , L_20 ) ;
F_23 ( V_3 ) ;
V_77 = V_11 -> V_77 ;
V_11 -> V_77 = NULL ;
if ( V_77 )
F_44 ( V_77 ) ;
F_87 ( V_3 ) ;
}
static struct V_2 * F_88 ( struct V_178 * V_183 )
{
struct V_1 * V_11 ;
struct V_163 * V_168 ;
int V_25 , V_18 ;
V_168 = F_2 ( V_183 , struct V_163 , V_166 ) ;
F_73 ( & V_168 -> V_171 ) ;
if ( V_168 -> V_95 > V_62 || V_168 -> V_94 > V_62 ) {
F_75 ( & V_168 -> V_171 ) ;
return F_81 ( - V_74 ) ;
}
V_11 = F_80 ( sizeof( * V_11 ) , V_131 ) ;
if ( ! V_11 ) {
F_75 ( & V_168 -> V_171 ) ;
return F_81 ( - V_42 ) ;
}
for ( V_18 = 0 ; V_18 < V_168 -> V_95 ; V_18 ++ ) {
struct V_51 * V_52 = F_80 ( sizeof( * V_52 ) , V_131 ) ;
if ( ! V_52 ) {
V_25 = - V_42 ;
F_75 ( & V_168 -> V_171 ) ;
goto V_184;
}
V_52 -> V_11 = V_11 ;
V_52 -> V_65 = 0 ;
V_52 -> V_9 = V_18 ;
V_11 -> V_63 [ V_18 ] = V_52 ;
}
V_11 -> V_85 = F_89 ( V_168 -> V_85 , V_131 ) ;
if ( V_168 -> V_85 && ! V_11 -> V_85 ) {
V_25 = - V_42 ;
F_75 ( & V_168 -> V_171 ) ;
goto V_184;
}
V_11 -> V_95 = V_168 -> V_95 ;
V_11 -> V_94 = V_168 -> V_94 ;
V_11 -> V_84 = V_168 -> V_84 ;
V_11 -> V_41 = V_168 -> V_41 ;
V_11 -> V_44 = V_168 -> V_44 ;
V_11 -> V_70 = 0 ;
V_25 = F_90 ( & V_11 -> V_40 , V_11 -> V_44 , V_131 ) ;
if ( V_25 )
goto V_184;
++ V_168 -> V_174 ;
F_75 ( & V_168 -> V_171 ) ;
V_11 -> V_4 . V_31 = L_21 ;
V_11 -> V_4 . V_185 = F_52 ;
V_11 -> V_4 . V_186 = F_86 ;
V_11 -> V_4 . V_187 = F_20 ;
V_11 -> V_4 . V_188 = F_23 ;
V_11 -> V_4 . V_189 = F_84 ;
return & V_11 -> V_4 ;
V_184:
for ( -- V_18 ; V_18 >= 0 ; V_18 -- )
F_66 ( V_11 -> V_63 [ V_18 ] ) ;
F_66 ( V_11 ) ;
return F_81 ( V_25 ) ;
}
