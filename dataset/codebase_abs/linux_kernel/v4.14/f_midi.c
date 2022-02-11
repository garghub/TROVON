static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 ,
unsigned V_8 )
{
return F_4 ( V_7 , V_8 ) ;
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
static void F_16 ( struct V_1 * V_11 )
{
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_11 -> V_35 ; V_18 ++ ) {
struct V_36 * V_37 = V_11 -> V_38 + V_18 ;
struct V_13 * V_14 = V_37 -> V_14 ;
if ( V_37 -> V_39 && V_14 )
F_17 ( V_14 ) ;
}
}
static int F_18 ( struct V_1 * V_11 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
int V_40 ;
struct V_22 * V_23 = V_3 -> V_24 -> V_23 ;
F_19 ( V_7 ) ;
V_40 = F_20 ( V_11 -> V_41 , V_3 , V_7 ) ;
if ( V_40 ) {
ERROR ( V_23 , L_4 , V_7 -> V_31 , V_40 ) ;
return V_40 ;
}
V_40 = F_21 ( V_7 ) ;
if ( V_40 ) {
ERROR ( V_23 , L_5 , V_7 -> V_31 , V_40 ) ;
return V_40 ;
}
V_7 -> V_12 = V_11 ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , unsigned V_42 , unsigned V_43 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
unsigned V_18 ;
int V_40 ;
if ( V_42 != V_11 -> V_44 )
return 0 ;
V_40 = F_18 ( V_11 , V_3 , V_11 -> V_27 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_18 ( V_11 , V_3 , V_11 -> V_26 ) ;
if ( V_40 )
return V_40 ;
while ( F_23 ( & V_11 -> V_45 ) ) {
struct V_5 * V_17 =
F_3 ( V_11 -> V_27 , V_11 -> V_46 ) ;
if ( V_17 == NULL )
return - V_47 ;
V_17 -> V_8 = 0 ;
V_17 -> V_48 = F_9 ;
F_24 ( & V_11 -> V_45 , V_17 ) ;
}
for ( V_18 = 0 ; V_18 < V_11 -> V_49 && V_40 == 0 ; V_18 ++ ) {
struct V_5 * V_17 =
F_3 ( V_11 -> V_26 , V_11 -> V_46 ) ;
if ( V_17 == NULL )
return - V_47 ;
V_17 -> V_48 = F_9 ;
V_40 = F_14 ( V_11 -> V_26 , V_17 , V_34 ) ;
if ( V_40 ) {
ERROR ( V_11 , L_6 ,
V_11 -> V_26 -> V_31 , V_40 ) ;
F_12 ( V_11 -> V_26 , V_17 ) ;
return V_40 ;
}
}
return 0 ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_22 * V_23 = V_3 -> V_24 -> V_23 ;
struct V_5 * V_17 = NULL ;
F_13 ( V_23 , L_7 ) ;
F_19 ( V_11 -> V_27 ) ;
F_19 ( V_11 -> V_26 ) ;
while ( F_26 ( & V_11 -> V_45 , & V_17 ) )
F_12 ( V_11 -> V_27 , V_17 ) ;
F_16 ( V_11 ) ;
}
static int F_27 ( struct V_50 * V_51 )
{
return 0 ;
}
static void F_28 ( struct V_5 * V_17 ,
struct V_36 * V_37 , T_1 V_52 )
{
T_1 V_53 [ 4 ] = { V_37 -> V_9 << 4 , 0 , 0 , 0 } ;
T_1 V_54 = V_55 ;
switch ( V_52 ) {
case 0xf8 ... 0xff :
V_53 [ 0 ] |= 0x0f ;
V_53 [ 1 ] = V_52 ;
V_54 = V_37 -> V_56 ;
V_37 -> V_56 = V_57 ;
break;
case 0xf7 :
switch ( V_37 -> V_56 ) {
case V_58 :
V_53 [ 0 ] |= 0x05 ;
V_53 [ 1 ] = 0xf7 ;
V_54 = V_59 ;
break;
case V_60 :
V_53 [ 0 ] |= 0x06 ;
V_53 [ 1 ] = V_37 -> V_10 [ 0 ] ;
V_53 [ 2 ] = 0xf7 ;
V_54 = V_59 ;
break;
case V_61 :
V_53 [ 0 ] |= 0x07 ;
V_53 [ 1 ] = V_37 -> V_10 [ 0 ] ;
V_53 [ 2 ] = V_37 -> V_10 [ 1 ] ;
V_53 [ 3 ] = 0xf7 ;
V_54 = V_59 ;
break;
default:
V_54 = V_37 -> V_56 ;
V_37 -> V_56 = V_55 ;
}
break;
case 0xf0 ... 0xf6 :
V_37 -> V_10 [ 0 ] = V_37 -> V_10 [ 1 ] = 0 ;
V_37 -> V_56 = V_55 ;
switch ( V_52 ) {
case 0xf0 :
V_37 -> V_10 [ 0 ] = V_52 ;
V_37 -> V_10 [ 1 ] = 0 ;
V_54 = V_60 ;
break;
case 0xf1 :
case 0xf3 :
V_37 -> V_10 [ 0 ] = V_52 ;
V_54 = V_62 ;
break;
case 0xf2 :
V_37 -> V_10 [ 0 ] = V_52 ;
V_54 = V_63 ;
break;
case 0xf4 :
case 0xf5 :
V_54 = V_55 ;
break;
case 0xf6 :
V_53 [ 0 ] |= 0x05 ;
V_53 [ 1 ] = 0xf6 ;
V_54 = V_59 ;
break;
}
break;
case 0x80 ... 0xef :
V_37 -> V_10 [ 0 ] = V_52 ;
V_37 -> V_10 [ 1 ] = 0 ;
V_37 -> V_56 = V_55 ;
if ( V_52 >= 0xc0 && V_52 <= 0xdf )
V_54 = V_62 ;
else
V_54 = V_63 ;
break;
case 0x00 ... 0x7f :
switch ( V_37 -> V_56 ) {
case V_62 :
if ( V_37 -> V_10 [ 0 ] < 0xf0 )
V_53 [ 0 ] |= V_37 -> V_10 [ 0 ] >> 4 ;
else
V_53 [ 0 ] |= 0x02 ;
V_53 [ 1 ] = V_37 -> V_10 [ 0 ] ;
V_53 [ 2 ] = V_52 ;
V_54 = V_62 ;
break;
case V_63 :
V_37 -> V_10 [ 1 ] = V_52 ;
V_54 = V_64 ;
break;
case V_64 :
if ( V_37 -> V_10 [ 0 ] < 0xf0 )
V_53 [ 0 ] |= V_37 -> V_10 [ 0 ] >> 4 ;
else
V_53 [ 0 ] |= 0x03 ;
V_53 [ 1 ] = V_37 -> V_10 [ 0 ] ;
V_53 [ 2 ] = V_37 -> V_10 [ 1 ] ;
V_53 [ 3 ] = V_52 ;
V_54 = V_63 ;
break;
case V_58 :
V_37 -> V_10 [ 0 ] = V_52 ;
V_54 = V_60 ;
break;
case V_60 :
V_37 -> V_10 [ 1 ] = V_52 ;
V_54 = V_61 ;
break;
case V_61 :
V_53 [ 0 ] |= 0x04 ;
V_53 [ 1 ] = V_37 -> V_10 [ 0 ] ;
V_53 [ 2 ] = V_37 -> V_10 [ 1 ] ;
V_53 [ 3 ] = V_52 ;
V_54 = V_58 ;
break;
}
break;
}
if ( V_54 == V_59 ||
V_37 -> V_56 == V_61 ||
V_37 -> V_56 == V_62 ||
V_37 -> V_56 == V_64 ||
V_37 -> V_56 == V_57 ) {
unsigned int V_8 = V_17 -> V_8 ;
T_2 * V_19 = ( T_2 * ) V_17 -> V_19 + V_8 ;
memcpy ( V_19 , V_53 , sizeof( V_53 ) ) ;
V_17 -> V_8 = V_8 + sizeof( V_53 ) ;
if ( V_54 == V_59 ) {
V_54 = V_55 ;
V_37 -> V_10 [ 0 ] = V_37 -> V_10 [ 1 ] = 0 ;
}
}
V_37 -> V_56 = V_54 ;
}
static int F_29 ( struct V_1 * V_11 , struct V_6 * V_7 )
{
struct V_5 * V_17 = NULL ;
unsigned int V_65 , V_18 ;
bool V_39 = false ;
int V_40 ;
V_65 = F_30 ( & V_11 -> V_45 , & V_17 ) ;
if ( V_65 != 1 ) {
ERROR ( V_11 , L_8 , V_66 ) ;
return - 1 ;
}
if ( V_17 -> V_8 > 0 )
return 0 ;
for ( V_18 = V_11 -> V_67 ; V_18 < V_11 -> V_35 ; ++ V_18 ) {
struct V_36 * V_37 = V_11 -> V_38 + V_18 ;
struct V_13 * V_14 = V_37 -> V_14 ;
if ( ! V_37 -> V_39 || ! V_14 )
continue;
while ( V_17 -> V_8 + 3 < V_11 -> V_46 ) {
T_1 V_52 ;
if ( F_31 ( V_14 , & V_52 , 1 ) != 1 ) {
V_37 -> V_39 = 0 ;
break;
}
F_28 ( V_17 , V_37 , V_52 ) ;
}
V_39 = ! ! V_37 -> V_39 ;
if ( V_39 )
break;
}
V_11 -> V_67 = V_39 ? V_18 : 0 ;
if ( V_17 -> V_8 <= 0 )
goto V_68;
V_40 = F_14 ( V_7 , V_17 , V_34 ) ;
if ( V_40 < 0 ) {
ERROR ( V_11 , L_9 ,
V_11 -> V_27 -> V_31 , V_40 ) ;
V_17 -> V_8 = 0 ;
} else {
F_32 ( & V_11 -> V_45 ) ;
F_24 ( & V_11 -> V_45 , V_17 ) ;
}
V_68:
return V_39 ;
}
static void F_10 ( struct V_1 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_27 ;
int V_69 ;
unsigned long V_70 ;
if ( ! V_7 || ! V_7 -> V_71 )
goto V_72;
F_33 ( & V_11 -> V_73 , V_70 ) ;
do {
V_69 = F_29 ( V_11 , V_7 ) ;
if ( V_69 < 0 ) {
F_34 ( & V_11 -> V_73 , V_70 ) ;
goto V_72;
}
} while ( V_69 );
F_34 ( & V_11 -> V_73 , V_70 ) ;
return;
V_72:
F_16 ( V_11 ) ;
}
static void F_35 ( unsigned long V_10 )
{
struct V_1 * V_11 = (struct V_1 * ) V_10 ;
F_10 ( V_11 ) ;
}
static int F_36 ( struct V_13 * V_14 )
{
struct V_1 * V_11 = V_14 -> V_74 -> V_75 ;
struct V_36 * V_37 ;
if ( V_14 -> V_76 >= V_11 -> V_35 )
return - V_77 ;
F_11 ( V_11 , L_10 , V_66 ) ;
V_37 = V_11 -> V_38 + V_14 -> V_76 ;
V_37 -> V_14 = V_14 ;
V_37 -> V_56 = V_55 ;
return 0 ;
}
static int F_37 ( struct V_13 * V_14 )
{
struct V_1 * V_11 = V_14 -> V_74 -> V_75 ;
F_11 ( V_11 , L_10 , V_66 ) ;
return 0 ;
}
static void F_38 ( struct V_13 * V_14 , int V_78 )
{
struct V_1 * V_11 = V_14 -> V_74 -> V_75 ;
if ( V_14 -> V_76 >= V_11 -> V_35 )
return;
F_11 ( V_11 , L_11 , V_66 , V_78 ) ;
V_11 -> V_38 [ V_14 -> V_76 ] . V_39 = V_78 ;
if ( V_78 )
F_39 ( & V_11 -> V_79 ) ;
}
static int F_40 ( struct V_13 * V_14 )
{
struct V_1 * V_11 = V_14 -> V_74 -> V_75 ;
if ( V_14 -> V_76 >= V_80 )
return - V_77 ;
F_11 ( V_11 , L_10 , V_66 ) ;
V_11 -> V_15 [ V_14 -> V_76 ] = V_14 ;
return 0 ;
}
static int F_41 ( struct V_13 * V_14 )
{
struct V_1 * V_11 = V_14 -> V_74 -> V_75 ;
F_11 ( V_11 , L_10 , V_66 ) ;
return 0 ;
}
static void F_42 ( struct V_13 * V_14 , int V_78 )
{
struct V_1 * V_11 = V_14 -> V_74 -> V_75 ;
F_11 ( V_11 , L_10 , V_66 ) ;
if ( V_78 )
F_43 ( V_14 -> V_76 , & V_11 -> V_16 ) ;
else
F_44 ( V_14 -> V_76 , & V_11 -> V_16 ) ;
}
static inline void F_45 ( struct V_1 * V_11 )
{
if ( V_11 -> V_81 ) {
F_46 ( V_11 -> V_81 ) ;
V_11 -> V_81 = NULL ;
}
}
static int F_47 ( struct V_1 * V_11 )
{
struct V_82 * V_81 ;
struct V_83 * V_74 ;
int V_40 ;
static struct V_84 V_85 = {
. V_86 = F_27 ,
} ;
V_40 = F_48 ( & V_11 -> V_41 -> V_87 , V_11 -> V_88 , V_11 -> V_89 ,
V_90 , 0 , & V_81 ) ;
if ( V_40 < 0 ) {
ERROR ( V_11 , L_12 ) ;
goto V_91;
}
V_11 -> V_81 = V_81 ;
V_40 = F_49 ( V_81 , V_92 , V_11 , & V_85 ) ;
if ( V_40 < 0 ) {
ERROR ( V_11 , L_13 , V_40 ) ;
goto V_91;
}
strcpy ( V_81 -> V_93 , V_94 ) ;
strcpy ( V_81 -> V_95 , V_94 ) ;
strcpy ( V_81 -> V_96 , V_97 ) ;
F_50 ( V_81 , L_14 ) ;
V_40 = F_51 ( V_81 , V_81 -> V_95 , 0 ,
V_11 -> V_98 , V_11 -> V_35 , & V_74 ) ;
if ( V_40 < 0 ) {
ERROR ( V_11 , L_15 , V_40 ) ;
goto V_91;
}
V_11 -> V_74 = V_74 ;
V_11 -> V_67 = 0 ;
strcpy ( V_74 -> V_31 , V_81 -> V_96 ) ;
V_74 -> V_99 = V_100 |
V_101 |
V_102 ;
V_74 -> V_75 = V_11 ;
V_74 -> V_103 = V_104 ;
V_11 -> V_105 ++ ;
F_52 ( V_74 , V_106 , & V_107 ) ;
F_52 ( V_74 , V_108 , & V_109 ) ;
V_40 = F_53 ( V_81 ) ;
if ( V_40 < 0 ) {
ERROR ( V_11 , L_16 ) ;
goto V_91;
}
F_11 ( V_11 , L_17 , V_66 ) ;
return 0 ;
V_91:
F_45 ( V_11 ) ;
return V_40 ;
}
static int F_54 ( struct V_110 * V_111 , struct V_2 * V_3 )
{
struct V_112 * * V_113 ;
struct V_114 V_115 [ V_80 ] ;
struct V_114 V_116 [ V_80 ] ;
struct V_117 V_118 [ V_80 ] ;
struct V_117 V_119 [ V_80 ] ;
struct V_22 * V_23 = V_111 -> V_23 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_120 * V_121 ;
int V_25 , V_122 , V_123 = 1 , V_18 = 0 , V_124 = 0 ;
V_11 -> V_41 = V_23 -> V_41 ;
F_55 ( & V_11 -> V_79 , F_35 , ( unsigned long ) V_11 ) ;
V_25 = F_47 ( V_11 ) ;
if ( V_25 < 0 )
goto V_125;
V_121 = F_56 ( V_111 -> V_23 , V_126 ,
F_57 ( V_127 ) ) ;
if ( F_58 ( V_121 ) ) {
V_25 = F_59 ( V_121 ) ;
goto V_91;
}
V_128 . V_129 = V_121 [ V_130 ] . V_89 ;
V_25 = F_60 ( V_111 , V_3 ) ;
if ( V_25 < 0 )
goto V_91;
V_128 . V_131 = V_25 ;
V_25 = F_60 ( V_111 , V_3 ) ;
if ( V_25 < 0 )
goto V_91;
V_132 . V_131 = V_25 ;
V_133 . V_134 [ 0 ] = V_25 ;
V_11 -> V_44 = V_25 ;
V_25 = - V_135 ;
V_11 -> V_27 = F_61 ( V_23 -> V_41 , & V_136 ) ;
if ( ! V_11 -> V_27 )
goto V_91;
V_11 -> V_26 = F_61 ( V_23 -> V_41 , & V_137 ) ;
if ( ! V_11 -> V_26 )
goto V_91;
V_113 = F_62 ( ( V_80 * 4 ) + 11 , sizeof( * V_113 ) ,
V_138 ) ;
if ( ! V_113 ) {
V_25 = - V_47 ;
goto V_91;
}
V_113 [ V_18 ++ ] = (struct V_112 * ) & V_128 ;
V_113 [ V_18 ++ ] = (struct V_112 * ) & V_133 ;
V_113 [ V_18 ++ ] = (struct V_112 * ) & V_132 ;
V_122 = V_139
+ ( V_11 -> V_35 + V_11 -> V_98 ) *
( V_140 + F_63 ( 1 ) ) ;
V_141 . V_142 = F_64 ( V_122 ) ;
V_113 [ V_18 ++ ] = (struct V_112 * ) & V_141 ;
for ( V_122 = 0 ; V_122 < V_11 -> V_35 ; V_122 ++ ) {
struct V_114 * V_143 = & V_115 [ V_122 ] ;
struct V_117 * V_144 = & V_119 [ V_122 ] ;
V_143 -> V_145 = V_140 ;
V_143 -> V_146 = V_147 ;
V_143 -> V_148 = V_149 ;
V_143 -> V_150 = V_151 ;
V_143 -> V_152 = V_123 ++ ;
V_143 -> V_153 = 0 ;
V_113 [ V_18 ++ ] = (struct V_112 * ) V_143 ;
V_144 -> V_145 = F_63 ( 1 ) ;
V_144 -> V_146 = V_147 ;
V_144 -> V_148 = V_154 ;
V_144 -> V_150 = V_155 ;
V_144 -> V_152 = V_123 ++ ;
V_144 -> V_156 = 1 ;
V_144 -> V_157 [ 0 ] . V_158 = 1 ;
V_144 -> V_157 [ 0 ] . V_159 = V_143 -> V_152 ;
V_144 -> V_153 = 0 ;
V_113 [ V_18 ++ ] = (struct V_112 * ) V_144 ;
V_160 . V_161 [ V_122 ] = V_144 -> V_152 ;
}
for ( V_122 = 0 ; V_122 < V_11 -> V_98 ; V_122 ++ ) {
struct V_114 * V_162 = & V_116 [ V_122 ] ;
struct V_117 * V_163 = & V_118 [ V_122 ] ;
V_162 -> V_145 = V_140 ;
V_162 -> V_146 = V_147 ;
V_162 -> V_148 = V_149 ;
V_162 -> V_150 = V_155 ;
V_162 -> V_152 = V_123 ++ ;
V_162 -> V_153 = 0 ;
V_113 [ V_18 ++ ] = (struct V_112 * ) V_162 ;
V_163 -> V_145 = F_63 ( 1 ) ;
V_163 -> V_146 = V_147 ;
V_163 -> V_148 = V_154 ;
V_163 -> V_150 = V_151 ;
V_163 -> V_152 = V_123 ++ ;
V_163 -> V_156 = 1 ;
V_163 -> V_153 = 0 ;
V_163 -> V_157 [ 0 ] . V_159 = V_162 -> V_152 ;
V_163 -> V_157 [ 0 ] . V_158 = 1 ;
V_113 [ V_18 ++ ] = (struct V_112 * ) V_163 ;
V_164 . V_161 [ V_122 ] = V_162 -> V_152 ;
}
V_164 . V_145 = F_65 ( V_11 -> V_35 ) ;
V_164 . V_165 = V_11 -> V_35 ;
V_160 . V_145 = F_65 ( V_11 -> V_98 ) ;
V_160 . V_165 = V_11 -> V_98 ;
V_124 = V_18 ;
V_113 [ V_18 ++ ] = (struct V_112 * ) & V_137 ;
V_113 [ V_18 ++ ] = (struct V_112 * ) & V_164 ;
V_113 [ V_18 ++ ] = (struct V_112 * ) & V_136 ;
V_113 [ V_18 ++ ] = (struct V_112 * ) & V_160 ;
V_113 [ V_18 ++ ] = NULL ;
V_3 -> V_166 = F_66 ( V_113 ) ;
if ( ! V_3 -> V_166 )
goto V_167;
if ( F_67 ( V_111 -> V_23 -> V_41 ) ) {
V_136 . V_168 = F_64 ( 512 ) ;
V_137 . V_168 = F_64 ( 512 ) ;
V_3 -> V_169 = F_66 ( V_113 ) ;
if ( ! V_3 -> V_169 )
goto V_167;
}
if ( F_68 ( V_111 -> V_23 -> V_41 ) ) {
V_136 . V_168 = F_64 ( 1024 ) ;
V_137 . V_168 = F_64 ( 1024 ) ;
V_18 = V_124 ;
V_113 [ V_18 ++ ] = (struct V_112 * )
& V_137 ;
V_113 [ V_18 ++ ] = (struct V_112 * )
& V_170 ;
V_113 [ V_18 ++ ] = (struct V_112 * )
& V_164 ;
V_113 [ V_18 ++ ] = (struct V_112 * )
& V_136 ;
V_113 [ V_18 ++ ] = (struct V_112 * )
& V_171 ;
V_113 [ V_18 ++ ] = (struct V_112 * )
& V_160 ;
V_3 -> V_172 = F_66 ( V_113 ) ;
if ( ! V_3 -> V_172 )
goto V_167;
}
F_69 ( V_113 ) ;
return 0 ;
V_167:
F_69 ( V_113 ) ;
F_70 ( V_3 ) ;
V_91:
F_45 ( V_11 ) ;
V_125:
ERROR ( V_23 , L_18 , V_3 -> V_31 , V_25 ) ;
return V_25 ;
}
static inline struct V_173 * F_71 ( struct V_174 * V_175 )
{
return F_2 ( F_72 ( V_175 ) , struct V_173 ,
V_176 . V_177 ) ;
}
static void F_73 ( struct V_174 * V_175 )
{
struct V_173 * V_178 = F_71 ( V_175 ) ;
F_74 ( & V_178 -> V_176 ) ;
}
static T_3 F_75 ( struct V_174 * V_175 , char * V_179 )
{
struct V_173 * V_178 = F_71 ( V_175 ) ;
int V_180 ;
F_76 ( & V_178 -> V_181 ) ;
if ( V_178 -> V_89 ) {
V_180 = F_77 ( V_179 , V_178 -> V_89 , V_182 ) ;
} else {
V_179 [ 0 ] = 0 ;
V_180 = 0 ;
}
F_78 ( & V_178 -> V_181 ) ;
return V_180 ;
}
static T_3 F_79 ( struct V_174 * V_175 ,
const char * V_179 , T_4 V_65 )
{
struct V_173 * V_178 = F_71 ( V_175 ) ;
int V_69 ;
char * V_111 ;
F_76 ( & V_178 -> V_181 ) ;
if ( V_178 -> V_183 ) {
V_69 = - V_184 ;
goto V_185;
}
V_111 = F_80 ( V_179 , V_65 , V_138 ) ;
if ( ! V_111 ) {
V_69 = - V_47 ;
goto V_185;
}
if ( V_178 -> V_186 )
F_69 ( V_178 -> V_89 ) ;
V_178 -> V_89 = V_111 ;
V_178 -> V_186 = true ;
V_69 = V_65 ;
V_185:
F_78 ( & V_178 -> V_181 ) ;
return V_69 ;
}
static void F_81 ( struct V_187 * V_3 )
{
struct V_173 * V_178 ;
V_178 = F_2 ( V_3 , struct V_173 , V_176 ) ;
if ( V_178 -> V_186 )
F_69 ( V_178 -> V_89 ) ;
F_69 ( V_178 ) ;
}
static struct V_187 * F_82 ( void )
{
struct V_173 * V_178 ;
V_178 = F_83 ( sizeof( * V_178 ) , V_138 ) ;
if ( ! V_178 )
return F_84 ( - V_47 ) ;
F_85 ( & V_178 -> V_181 ) ;
V_178 -> V_176 . V_188 = F_81 ;
V_178 -> V_88 = V_189 ;
V_178 -> V_89 = V_190 ;
V_178 -> V_46 = 512 ;
V_178 -> V_49 = 32 ;
V_178 -> V_35 = 1 ;
V_178 -> V_98 = 1 ;
F_86 ( & V_178 -> V_176 . V_177 , L_19 ,
& V_191 ) ;
return & V_178 -> V_176 ;
}
static void F_87 ( struct V_2 * V_3 )
{
struct V_1 * V_11 ;
struct V_173 * V_178 ;
V_11 = F_1 ( V_3 ) ;
V_178 = F_2 ( V_3 -> V_192 , struct V_173 , V_176 ) ;
F_76 ( & V_178 -> V_181 ) ;
if ( ! -- V_11 -> V_105 ) {
F_69 ( V_11 -> V_89 ) ;
F_88 ( & V_11 -> V_45 ) ;
F_69 ( V_11 ) ;
-- V_178 -> V_183 ;
}
F_78 ( & V_178 -> V_181 ) ;
}
static void V_104 ( struct V_83 * V_74 )
{
F_87 ( V_74 -> V_75 ) ;
}
static void F_89 ( struct V_110 * V_111 , struct V_2 * V_3 )
{
struct V_22 * V_23 = V_3 -> V_24 -> V_23 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_82 * V_81 ;
F_13 ( V_23 , L_20 ) ;
F_25 ( V_3 ) ;
V_81 = V_11 -> V_81 ;
V_11 -> V_81 = NULL ;
if ( V_81 )
F_90 ( V_81 ) ;
F_70 ( V_3 ) ;
}
static struct V_2 * F_91 ( struct V_187 * V_192 )
{
struct V_1 * V_11 = NULL ;
struct V_173 * V_178 ;
int V_25 , V_18 ;
V_178 = F_2 ( V_192 , struct V_173 , V_176 ) ;
F_76 ( & V_178 -> V_181 ) ;
if ( V_178 -> V_35 > V_80 || V_178 -> V_98 > V_80 ) {
V_25 = - V_77 ;
goto V_193;
}
V_11 = F_83 (
sizeof( * V_11 ) + V_178 -> V_35 * sizeof( * V_11 -> V_38 ) ,
V_138 ) ;
if ( ! V_11 ) {
V_25 = - V_47 ;
goto V_193;
}
for ( V_18 = 0 ; V_18 < V_178 -> V_35 ; V_18 ++ )
V_11 -> V_38 [ V_18 ] . V_9 = V_18 ;
V_11 -> V_89 = F_92 ( V_178 -> V_89 , V_138 ) ;
if ( V_178 -> V_89 && ! V_11 -> V_89 ) {
V_25 = - V_47 ;
goto V_193;
}
V_11 -> V_35 = V_178 -> V_35 ;
V_11 -> V_98 = V_178 -> V_98 ;
V_11 -> V_88 = V_178 -> V_88 ;
V_11 -> V_46 = V_178 -> V_46 ;
V_11 -> V_49 = V_178 -> V_49 ;
V_11 -> V_67 = 0 ;
V_11 -> V_105 = 1 ;
V_25 = F_93 ( & V_11 -> V_45 , V_11 -> V_49 , V_138 ) ;
if ( V_25 )
goto V_193;
F_94 ( & V_11 -> V_73 ) ;
++ V_178 -> V_183 ;
F_78 ( & V_178 -> V_181 ) ;
V_11 -> V_4 . V_31 = L_21 ;
V_11 -> V_4 . V_194 = F_54 ;
V_11 -> V_4 . V_195 = F_89 ;
V_11 -> V_4 . V_196 = F_22 ;
V_11 -> V_4 . V_197 = F_25 ;
V_11 -> V_4 . V_198 = F_87 ;
return & V_11 -> V_4 ;
V_193:
F_78 ( & V_178 -> V_181 ) ;
F_69 ( V_11 ) ;
return F_84 ( V_25 ) ;
}
