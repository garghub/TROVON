static void F_1 ( char * V_1 )
{
char * V_2 ;
while ( V_1 ) {
V_2 = strchr ( V_1 , '\n' ) ;
if ( V_2 )
* V_2 = 0 ;
F_2 ( V_3 L_1 , V_1 ) ;
V_1 = V_2 ;
if ( V_1 )
V_1 ++ ;
}
}
static int F_3 ( struct V_4 * V_5 , struct V_6 * V_7 , char * V_1 ,
int V_8 , int V_9 )
{
char * V_10 = V_1 ;
char * V_11 ;
T_1 V_12 , V_13 ;
V_12 = F_4 ( V_5 , V_7 ) ;
V_10 += sprintf ( V_10 , L_2 , V_9 , L_3 , V_7 ,
F_5 ( V_5 , V_7 -> V_14 ) ) ;
V_10 += sprintf ( V_10 , L_4 ,
( ( V_12 >> 27 ) & 3 ) ,
( V_12 & V_15 ) ? L_5 : L_3 ,
( V_12 & V_16 ) ? L_6 : L_3 ,
( V_12 & V_17 ) ? L_7 : L_3 ,
( V_12 & V_18 ) ? L_8 : L_3 ,
( V_12 & V_19 ) ? L_9 : L_3 ,
( V_12 & V_20 ) ? L_10 : L_3 ,
( V_12 & V_21 ) ? L_11 : L_3 ,
( V_12 & V_22 ) ? L_12 : L_3 ,
( V_12 & V_23 ) ? L_13 : L_3 ,
( V_12 & V_24 ) ? L_14 : L_3 ,
V_12 & 0x7ff ) ;
if ( V_10 - V_1 > V_8 )
goto V_25;
V_13 = F_6 ( V_5 , V_7 ) ;
switch ( F_7 ( V_13 ) ) {
case V_26 :
V_11 = L_15 ;
break;
case V_27 :
V_11 = L_16 ;
break;
case V_28 :
V_11 = L_17 ;
break;
default:
V_11 = L_18 ;
break;
}
V_10 += sprintf ( V_10 , L_19 ,
V_13 >> 21 ,
( ( V_13 >> 19 ) & 1 ) ,
( V_13 >> 15 ) & 15 ,
( V_13 >> 8 ) & 127 ,
( V_13 & 0xff ) ,
V_11 ) ;
V_10 += sprintf ( V_10 , L_20 , F_5 ( V_5 , V_7 -> V_29 ) ) ;
V_25:
if ( V_10 - V_1 > V_8 )
V_10 += sprintf ( V_10 , L_21 ) ;
return V_10 - V_1 ;
}
static int F_8 ( struct V_4 * V_5 , struct V_30 * V_31 ,
char * V_1 , int V_8 , int V_9 )
{
char * V_10 = V_1 ;
struct V_6 * V_7 ;
int V_32 , V_33 , V_34 ;
char * V_35 ;
V_10 += sprintf ( V_10 , L_22 , V_31 ) ;
V_10 += sprintf ( V_10 , L_23 , V_31 -> V_36 ) ;
V_10 += sprintf ( V_10 , L_24 , V_31 -> V_37 ) ;
V_10 += sprintf ( V_10 , L_25 , F_9 ( V_31 -> V_36 -> V_38 ) ) ;
V_10 += sprintf ( V_10 , L_26 , F_10 ( V_31 -> V_36 -> V_38 ) ,
( F_11 ( V_31 -> V_36 -> V_38 ) ? L_17 : L_16 ) ) ;
if ( V_10 - V_1 > V_8 )
goto V_25;
switch ( F_12 ( V_31 -> V_36 -> V_38 ) ) {
case V_39 : V_35 = L_27 ; break;
case V_40 : V_35 = L_28 ; break;
case V_41 : V_35 = L_29 ; break;
default:
case V_42 : V_35 = L_30 ; break;
}
V_10 += sprintf ( V_10 , L_31 , V_35 , ( V_31 -> V_43 ? L_32 : L_3 ) ) ;
V_10 += sprintf ( V_10 , L_33 , V_31 -> V_36 -> V_44 ,
( V_31 -> V_37 -> type == V_45 ?
L_34 : L_3 ) ) ;
if ( V_31 -> V_36 -> V_46 )
V_10 += sprintf ( V_10 , L_35 , V_31 -> V_36 -> V_46 ) ;
V_10 += sprintf ( V_10 , L_36 ) ;
if ( V_10 - V_1 > V_8 )
goto V_25;
V_32 = V_33 = V_34 = 0 ;
F_13 (td, &urbp->td_list, list) {
if ( V_31 -> V_37 -> type != V_47 &&
( ++ V_32 <= 10 || V_48 > 2 ) ) {
V_10 += sprintf ( V_10 , L_37 , V_9 + 2 , L_3 , V_32 ) ;
V_10 += F_3 ( V_5 , V_7 , V_10 ,
V_8 - ( V_10 - V_1 ) , 0 ) ;
if ( V_10 - V_1 > V_8 )
goto V_49;
} else {
if ( F_4 ( V_5 , V_7 ) & V_18 )
++ V_33 ;
else
++ V_34 ;
}
}
if ( V_33 + V_34 > 0 )
V_10 += sprintf ( V_10 ,
L_38 ,
V_9 , L_3 , V_34 , V_33 ) ;
V_25:
if ( V_10 - V_1 > V_8 )
V_10 += sprintf ( V_10 , L_21 ) ;
V_49:
return V_10 - V_1 ;
}
static int F_14 ( struct V_4 * V_5 ,
struct V_50 * V_37 , char * V_1 , int V_8 , int V_9 )
{
char * V_10 = V_1 ;
int V_32 , V_51 ;
T_2 V_52 = F_15 ( V_37 ) ;
char * V_53 ;
switch ( V_37 -> type ) {
case V_47 : V_53 = L_27 ; break;
case V_54 : V_53 = L_28 ; break;
case V_55 : V_53 = L_29 ; break;
case V_45 : V_53 = L_30 ; break;
default: V_53 = L_39 ; break;
}
V_10 += sprintf ( V_10 , L_40 ,
V_9 , L_3 , V_37 , V_53 ,
F_5 ( V_5 , V_37 -> V_14 ) ,
F_5 ( V_5 , V_52 ) ) ;
if ( V_37 -> type == V_47 )
V_10 += sprintf ( V_10 ,
L_41 ,
V_9 , L_3 , V_37 -> V_56 , V_37 -> V_57 , V_37 -> V_58 ,
V_37 -> V_59 , V_37 -> V_60 ) ;
else if ( V_37 -> type == V_54 )
V_10 += sprintf ( V_10 , L_42 ,
V_9 , L_3 , V_37 -> V_56 , V_37 -> V_57 , V_37 -> V_58 ) ;
if ( V_10 - V_1 > V_8 )
goto V_25;
if ( V_52 & F_16 ( V_5 ) )
V_10 += sprintf ( V_10 , L_43 , V_9 , L_3 ) ;
if ( V_52 & F_17 ( V_5 ) )
V_10 += sprintf ( V_10 , L_44 , V_9 , L_3 ) ;
if ( V_52 & F_18 ( V_5 , 8 ) )
V_10 += sprintf ( V_10 , L_45 , V_9 , L_3 ) ;
if ( ! ( V_52 & ~ ( F_16 ( V_5 ) | F_17 ( V_5 ) ) ) )
V_10 += sprintf ( V_10 , L_46 , V_9 , L_3 ) ;
if ( V_10 - V_1 > V_8 )
goto V_25;
if ( F_19 ( & V_37 -> V_61 ) ) {
V_10 += sprintf ( V_10 , L_47 , V_9 , L_3 ) ;
if ( V_37 == V_5 -> V_62 ) {
V_10 += F_3 ( V_5 , V_5 -> V_63 , V_10 ,
V_8 - ( V_10 - V_1 ) , 0 ) ;
if ( V_10 - V_1 > V_8 )
goto V_49;
}
} else {
struct V_30 * V_31 = F_20 ( V_37 -> V_61 . V_64 ,
struct V_30 , V_65 ) ;
struct V_6 * V_7 = F_20 ( V_31 -> V_66 . V_64 ,
struct V_6 , V_67 ) ;
if ( V_52 != F_21 ( V_5 , V_7 ) )
V_10 += sprintf ( V_10 , L_48 ,
V_9 , L_3 ) ;
V_32 = V_51 = 0 ;
F_13 (urbp, &qh->queue, node) {
if ( ++ V_32 <= 10 ) {
V_10 += F_8 ( V_5 , V_31 , V_10 ,
V_8 - ( V_10 - V_1 ) , V_9 + 2 ) ;
if ( V_10 - V_1 > V_8 )
goto V_49;
}
else
++ V_51 ;
}
if ( V_51 > 0 )
V_10 += sprintf ( V_10 , L_49 ,
V_9 , L_3 , V_51 ) ;
}
if ( V_10 - V_1 > V_8 )
goto V_25;
if ( V_37 -> V_68 ) {
V_10 += sprintf ( V_10 , L_50 , V_9 , L_3 ) ;
V_10 += F_3 ( V_5 , V_37 -> V_68 , V_10 ,
V_8 - ( V_10 - V_1 ) , 0 ) ;
if ( V_10 - V_1 > V_8 )
goto V_49;
}
V_25:
if ( V_10 - V_1 > V_8 )
V_10 += sprintf ( V_10 , L_21 ) ;
V_49:
return V_10 - V_1 ;
}
static int F_22 ( int V_69 , unsigned short V_12 , char * V_1 )
{
return sprintf ( V_1 , L_51 ,
V_69 ,
V_12 ,
( V_12 & V_70 ) ? L_52 : L_3 ,
( V_12 & V_71 ) ? L_53 : L_3 ,
( V_12 & V_72 ) ? L_54 : L_3 ,
( V_12 & V_73 ) ? L_55 : L_3 ,
( V_12 & V_74 ) ? L_56 : L_3 ,
( V_12 & V_75 ) ? L_57 : L_3 ,
( V_12 & V_76 ) ? L_58 : L_3 ,
( V_12 & V_77 ) ? L_59 : L_3 ,
( V_12 & V_78 ) ? L_60 : L_3 ,
( V_12 & V_79 ) ? L_61 : L_3 ) ;
}
static int F_23 ( struct V_4 * V_5 , char * V_1 )
{
char * V_80 ;
switch ( V_5 -> V_80 ) {
case V_81 :
V_80 = L_62 ; break;
case V_82 :
V_80 = L_63 ; break;
case V_83 :
V_80 = L_64 ; break;
case V_84 :
V_80 = L_65 ; break;
case V_85 :
V_80 = L_66 ; break;
case V_86 :
V_80 = L_67 ; break;
case V_87 :
V_80 = L_68 ; break;
default:
V_80 = L_18 ; break;
}
return sprintf ( V_1 , L_69 ,
V_80 , V_5 -> V_88 ) ;
}
static int F_24 ( struct V_4 * V_5 , char * V_1 , int V_8 )
{
char * V_10 = V_1 ;
unsigned short V_89 , V_90 , V_91 , V_92 ;
unsigned int V_93 ;
unsigned char V_94 ;
unsigned short V_95 , V_96 ;
V_89 = F_25 ( V_5 , V_97 ) ;
V_90 = F_25 ( V_5 , V_98 ) ;
V_91 = F_25 ( V_5 , V_99 ) ;
V_92 = F_25 ( V_5 , V_100 ) ;
V_93 = F_26 ( V_5 , V_101 ) ;
V_94 = F_27 ( V_5 , V_102 ) ;
V_95 = F_25 ( V_5 , V_103 ) ;
V_96 = F_25 ( V_5 , V_104 ) ;
V_10 += sprintf ( V_10 , L_70 ,
V_89 ,
( V_89 & V_105 ) ? L_71 : L_72 ,
( V_89 & V_106 ) ? L_73 : L_3 ,
( V_89 & V_107 ) ? L_74 : L_3 ,
( V_89 & V_108 ) ? L_75 : L_3 ,
( V_89 & V_109 ) ? L_76 : L_3 ,
( V_89 & V_110 ) ? L_77 : L_3 ,
( V_89 & V_111 ) ? L_78 : L_3 ,
( V_89 & V_112 ) ? L_79 : L_3 ) ;
if ( V_10 - V_1 > V_8 )
goto V_25;
V_10 += sprintf ( V_10 , L_80 ,
V_90 ,
( V_90 & V_113 ) ? L_81 : L_3 ,
( V_90 & V_114 ) ? L_82 : L_3 ,
( V_90 & V_115 ) ? L_83 : L_3 ,
( V_90 & V_116 ) ? L_84 : L_3 ,
( V_90 & V_117 ) ? L_85 : L_3 ,
( V_90 & V_118 ) ? L_86 : L_3 ) ;
if ( V_10 - V_1 > V_8 )
goto V_25;
V_10 += sprintf ( V_10 , L_87 , V_91 ) ;
V_10 += sprintf ( V_10 , L_88 , ( V_92 >> 10 ) & 1 ,
0xfff & ( 4 * ( unsigned int ) V_92 ) ) ;
V_10 += sprintf ( V_10 , L_89 , V_93 ) ;
V_10 += sprintf ( V_10 , L_90 , V_94 ) ;
if ( V_10 - V_1 > V_8 )
goto V_25;
V_10 += F_22 ( 1 , V_95 , V_10 ) ;
if ( V_10 - V_1 > V_8 )
goto V_25;
V_10 += F_22 ( 2 , V_96 , V_10 ) ;
if ( V_10 - V_1 > V_8 )
goto V_25;
V_10 += sprintf ( V_10 ,
L_91 ,
V_5 -> V_119 , V_5 -> V_119 & 1023 ,
V_5 -> V_120 , V_5 -> V_120 & 1023 ) ;
V_25:
if ( V_10 - V_1 > V_8 )
V_10 += sprintf ( V_10 , L_21 ) ;
return V_10 - V_1 ;
}
static int F_28 ( struct V_4 * V_5 , char * V_1 , int V_8 )
{
char * V_10 = V_1 ;
int V_32 , V_121 ;
struct V_50 * V_37 ;
struct V_6 * V_7 ;
struct V_122 * V_123 , * V_124 ;
int V_125 , V_126 ;
T_2 V_14 ;
T_2 V_127 ;
static const char * const V_128 [] = {
L_92 , L_93 , L_94 , L_95 , L_96 , L_97 ,
L_98 , L_99 , L_100 , L_101 , L_102
} ;
V_10 += F_23 ( V_5 , V_10 ) ;
if ( V_10 - V_1 > V_8 )
goto V_25;
V_10 += sprintf ( V_10 , L_103 ) ;
V_10 += F_24 ( V_5 , V_10 , V_8 - ( V_10 - V_1 ) ) ;
if ( V_10 - V_1 > V_8 )
goto V_49;
V_10 += sprintf ( V_10 , L_104 ) ;
for ( V_32 = 0 ; V_32 < V_129 ; ++ V_32 ) {
V_10 += sprintf ( V_10 , L_105 , V_5 -> V_58 [ V_32 ] ) ;
if ( V_32 % 8 == 7 )
* V_10 ++ = '\n' ;
}
V_10 += sprintf ( V_10 , L_106 ,
V_5 -> V_130 ,
F_29 ( V_5 ) -> V_131 . V_132 ,
F_29 ( V_5 ) -> V_131 . V_133 ) ;
if ( V_48 <= 1 )
goto V_49;
V_10 += sprintf ( V_10 , L_107 ) ;
V_125 = 10 ;
V_126 = 0 ;
for ( V_32 = 0 ; V_32 < V_134 ; ++ V_32 ) {
T_2 V_135 ;
if ( V_10 - V_1 > V_8 )
goto V_25;
V_121 = 0 ;
V_7 = V_5 -> V_136 [ V_32 ] ;
V_14 = V_5 -> V_137 [ V_32 ] ;
if ( ! V_7 )
goto V_138;
if ( V_125 > 0 ) {
V_10 += sprintf ( V_10 , L_108 ,
V_32 , F_5 ( V_5 , V_14 ) ) ;
V_121 = 1 ;
}
V_124 = & V_7 -> V_139 ;
V_123 = V_124 ;
do {
V_7 = F_20 ( V_123 , struct V_6 , V_139 ) ;
V_123 = V_123 -> V_64 ;
if ( V_14 != F_21 ( V_5 , V_7 ) ) {
if ( V_125 > 0 ) {
V_10 += sprintf ( V_10 ,
L_109 ) ;
if ( V_10 - V_1 > V_8 )
goto V_25;
} else
++ V_126 ;
}
if ( V_125 > 0 ) {
V_10 += F_3 ( V_5 , V_7 , V_10 ,
V_8 - ( V_10 - V_1 ) , 4 ) ;
if ( V_10 - V_1 > V_8 )
goto V_49;
}
V_14 = V_7 -> V_14 ;
} while ( V_123 != V_124 );
V_138:
V_135 = F_30 ( V_5 , V_32 ) ;
if ( V_14 != V_135 ) {
if ( V_125 > 0 ) {
if ( ! V_121 ) {
V_10 += sprintf ( V_10 ,
L_108 ,
V_32 , F_5 ( V_5 , V_14 ) ) ;
V_121 = 1 ;
}
V_10 += sprintf ( V_10 ,
L_110 ,
F_5 ( V_5 , V_135 ) ) ;
if ( V_10 - V_1 > V_8 )
goto V_25;
} else
++ V_126 ;
}
V_125 -= V_121 ;
}
if ( V_126 > 0 )
V_10 += sprintf ( V_10 , L_111 , V_126 ) ;
V_10 += sprintf ( V_10 , L_112 ) ;
if ( V_10 - V_1 > V_8 )
goto V_25;
V_127 = 0 ;
for ( V_32 = 0 ; V_32 < V_140 ; ++ V_32 ) {
int V_141 = 0 ;
V_37 = V_5 -> V_142 [ V_32 ] ;
V_10 += sprintf ( V_10 , L_113 , V_128 [ V_32 ] ) ;
V_10 += F_14 ( V_5 , V_37 , V_10 , V_8 - ( V_10 - V_1 ) , 4 ) ;
if ( V_10 - V_1 > V_8 )
goto V_49;
if ( V_32 == V_143 ) {
if ( F_15 ( V_37 ) != F_21 ( V_5 , V_5 -> V_63 ) ) {
V_10 += sprintf ( V_10 ,
L_114 ) ;
if ( V_10 - V_1 > V_8 )
goto V_25;
}
V_14 = V_127 ;
if ( ! V_14 )
V_14 = F_31 ( V_5 , V_5 -> V_144 ) ;
goto V_145;
}
V_124 = & V_37 -> V_65 ;
V_123 = V_124 -> V_64 ;
while ( V_123 != V_124 ) {
V_37 = F_20 ( V_123 , struct V_50 , V_65 ) ;
V_123 = V_123 -> V_64 ;
if ( ++ V_141 <= 10 ) {
V_10 += F_14 ( V_5 , V_37 , V_10 ,
V_8 - ( V_10 - V_1 ) , 4 ) ;
if ( V_10 - V_1 > V_8 )
goto V_49;
}
if ( ! V_127 && V_37 -> V_146 >= V_147 )
V_127 = F_31 ( V_5 , V_37 ) ;
}
if ( ( V_141 -= 10 ) > 0 )
V_10 += sprintf ( V_10 , L_115 , V_141 ) ;
V_14 = F_32 ( V_5 ) ;
if ( V_32 <= V_148 )
;
else if ( V_32 < V_149 )
V_14 = F_31 ( V_5 , V_5 -> V_62 ) ;
else if ( ! V_5 -> V_88 )
;
else
V_14 = F_31 ( V_5 , V_5 -> V_144 ) ;
V_145:
if ( V_37 -> V_14 != V_14 )
V_10 += sprintf ( V_10 ,
L_116 ) ;
if ( V_10 - V_1 > V_8 )
goto V_25;
}
V_25:
if ( V_10 - V_1 > V_8 )
V_10 += sprintf ( V_10 , L_21 ) ;
V_49:
return V_10 - V_1 ;
}
static int F_33 ( struct V_150 * V_150 , struct V_151 * V_151 )
{
struct V_4 * V_5 = V_150 -> V_152 ;
struct V_153 * V_154 ;
unsigned long V_155 ;
V_154 = F_34 ( sizeof( * V_154 ) , V_156 ) ;
if ( ! V_154 )
return - V_157 ;
V_154 -> V_158 = F_34 ( V_159 , V_156 ) ;
if ( ! V_154 -> V_158 ) {
F_35 ( V_154 ) ;
return - V_157 ;
}
V_154 -> V_160 = 0 ;
F_36 ( & V_5 -> V_161 , V_155 ) ;
if ( V_5 -> V_162 )
V_154 -> V_160 = F_28 ( V_5 , V_154 -> V_158 ,
V_159 - V_163 ) ;
F_37 ( & V_5 -> V_161 , V_155 ) ;
V_151 -> V_164 = V_154 ;
return 0 ;
}
static T_3 F_38 ( struct V_151 * V_151 , T_3 V_165 , int V_166 )
{
struct V_153 * V_154 = V_151 -> V_164 ;
return F_39 ( V_151 , V_165 , V_166 , V_154 -> V_160 ) ;
}
static T_4 F_40 ( struct V_151 * V_151 , char T_5 * V_1 ,
T_6 V_167 , T_3 * V_168 )
{
struct V_153 * V_154 = V_151 -> V_164 ;
return F_41 ( V_1 , V_167 , V_168 , V_154 -> V_158 , V_154 -> V_160 ) ;
}
static int F_42 ( struct V_150 * V_150 , struct V_151 * V_151 )
{
struct V_153 * V_154 = V_151 -> V_164 ;
F_35 ( V_154 -> V_158 ) ;
F_35 ( V_154 ) ;
return 0 ;
}
static inline void F_1 ( char * V_1 )
{}
static inline int F_14 ( struct V_4 * V_5 ,
struct V_50 * V_37 , char * V_1 , int V_8 , int V_9 )
{
return 0 ;
}
static inline int F_28 ( struct V_4 * V_5 ,
char * V_1 , int V_8 )
{
return 0 ;
}
