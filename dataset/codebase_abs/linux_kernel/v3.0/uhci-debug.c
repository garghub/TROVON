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
if ( V_8 < 160 )
return 0 ;
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
V_13 = F_6 ( V_5 , V_7 ) ;
switch ( F_7 ( V_13 ) ) {
case V_25 :
V_11 = L_15 ;
break;
case V_26 :
V_11 = L_16 ;
break;
case V_27 :
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
V_10 += sprintf ( V_10 , L_20 , F_5 ( V_5 , V_7 -> V_28 ) ) ;
return V_10 - V_1 ;
}
static int F_8 ( struct V_4 * V_5 , struct V_29 * V_30 ,
char * V_1 , int V_8 , int V_9 )
{
char * V_10 = V_1 ;
struct V_6 * V_7 ;
int V_31 , V_32 , V_33 ;
char * V_34 ;
if ( V_8 < 200 )
return 0 ;
V_10 += sprintf ( V_10 , L_21 , V_30 ) ;
V_10 += sprintf ( V_10 , L_22 , V_30 -> V_35 ) ;
V_10 += sprintf ( V_10 , L_23 , V_30 -> V_36 ) ;
V_10 += sprintf ( V_10 , L_24 , F_9 ( V_30 -> V_35 -> V_37 ) ) ;
V_10 += sprintf ( V_10 , L_25 , F_10 ( V_30 -> V_35 -> V_37 ) ,
( F_11 ( V_30 -> V_35 -> V_37 ) ? L_17 : L_16 ) ) ;
switch ( F_12 ( V_30 -> V_35 -> V_37 ) ) {
case V_38 : V_34 = L_26 ; break;
case V_39 : V_34 = L_27 ; break;
case V_40 : V_34 = L_28 ; break;
default:
case V_41 : V_34 = L_29 ; break;
}
V_10 += sprintf ( V_10 , L_30 , V_34 , ( V_30 -> V_42 ? L_31 : L_3 ) ) ;
V_10 += sprintf ( V_10 , L_32 , V_30 -> V_35 -> V_43 ,
( V_30 -> V_36 -> type == V_44 ?
L_33 : L_3 ) ) ;
if ( V_30 -> V_35 -> V_45 )
V_10 += sprintf ( V_10 , L_34 , V_30 -> V_35 -> V_45 ) ;
V_10 += sprintf ( V_10 , L_35 ) ;
V_31 = V_32 = V_33 = 0 ;
F_13 (td, &urbp->td_list, list) {
if ( V_30 -> V_36 -> type != V_46 &&
( ++ V_31 <= 10 || V_47 > 2 ) ) {
V_10 += sprintf ( V_10 , L_36 , V_9 + 2 , L_3 , V_31 ) ;
V_10 += F_3 ( V_5 , V_7 , V_10 ,
V_8 - ( V_10 - V_1 ) , 0 ) ;
} else {
if ( F_4 ( V_5 , V_7 ) & V_18 )
++ V_32 ;
else
++ V_33 ;
}
}
if ( V_32 + V_33 > 0 )
V_10 += sprintf ( V_10 , L_37
L_38 ,
V_9 , L_3 , V_33 , V_32 ) ;
return V_10 - V_1 ;
}
static int F_14 ( struct V_4 * V_5 ,
struct V_48 * V_36 , char * V_1 , int V_8 , int V_9 )
{
char * V_10 = V_1 ;
int V_31 , V_49 ;
T_2 V_50 = F_15 ( V_36 ) ;
char * V_51 ;
if ( V_8 < 80 * 7 )
return 0 ;
switch ( V_36 -> type ) {
case V_46 : V_51 = L_26 ; break;
case V_52 : V_51 = L_27 ; break;
case V_53 : V_51 = L_28 ; break;
case V_44 : V_51 = L_29 ; break;
default: V_51 = L_39 ; break;
}
V_10 += sprintf ( V_10 , L_40 ,
V_9 , L_3 , V_36 , V_51 ,
F_5 ( V_5 , V_36 -> V_14 ) ,
F_5 ( V_5 , V_50 ) ) ;
if ( V_36 -> type == V_46 )
V_10 += sprintf ( V_10 , L_41
L_42 ,
V_9 , L_3 , V_36 -> V_54 , V_36 -> V_55 , V_36 -> V_56 ,
V_36 -> V_57 , V_36 -> V_58 ) ;
else if ( V_36 -> type == V_52 )
V_10 += sprintf ( V_10 , L_43 ,
V_9 , L_3 , V_36 -> V_54 , V_36 -> V_55 , V_36 -> V_56 ) ;
if ( V_50 & F_16 ( V_5 ) )
V_10 += sprintf ( V_10 , L_44 , V_9 , L_3 ) ;
if ( V_50 & F_17 ( V_5 ) )
V_10 += sprintf ( V_10 , L_45 , V_9 , L_3 ) ;
if ( V_50 & F_18 ( V_5 , 8 ) )
V_10 += sprintf ( V_10 , L_46 , V_9 , L_3 ) ;
if ( ! ( V_50 & ~ ( F_16 ( V_5 ) | F_17 ( V_5 ) ) ) )
V_10 += sprintf ( V_10 , L_47 , V_9 , L_3 ) ;
if ( F_19 ( & V_36 -> V_59 ) ) {
V_10 += sprintf ( V_10 , L_48 , V_9 , L_3 ) ;
if ( V_36 == V_5 -> V_60 )
V_10 += F_3 ( V_5 , V_5 -> V_61 , V_10 ,
V_8 - ( V_10 - V_1 ) , 0 ) ;
} else {
struct V_29 * V_30 = F_20 ( V_36 -> V_59 . V_62 ,
struct V_29 , V_63 ) ;
struct V_6 * V_7 = F_20 ( V_30 -> V_64 . V_62 ,
struct V_6 , V_65 ) ;
if ( V_50 != F_21 ( V_5 , V_7 ) )
V_10 += sprintf ( V_10 , L_49 ,
V_9 , L_3 ) ;
V_31 = V_49 = 0 ;
F_13 (urbp, &qh->queue, node) {
if ( ++ V_31 <= 10 )
V_10 += F_8 ( V_5 , V_30 , V_10 ,
V_8 - ( V_10 - V_1 ) , V_9 + 2 ) ;
else
++ V_49 ;
}
if ( V_49 > 0 )
V_10 += sprintf ( V_10 , L_50 ,
V_9 , L_3 , V_49 ) ;
}
if ( V_36 -> V_66 ) {
V_10 += sprintf ( V_10 , L_51 , V_9 , L_3 ) ;
V_10 += F_3 ( V_5 , V_36 -> V_66 , V_10 ,
V_8 - ( V_10 - V_1 ) , 0 ) ;
}
return V_10 - V_1 ;
}
static int F_22 ( int V_67 , unsigned short V_12 , char * V_1 , int V_8 )
{
char * V_10 = V_1 ;
if ( V_8 < 160 )
return 0 ;
V_10 += sprintf ( V_10 , L_52 ,
V_67 ,
V_12 ,
( V_12 & V_68 ) ? L_53 : L_3 ,
( V_12 & V_69 ) ? L_54 : L_3 ,
( V_12 & V_70 ) ? L_55 : L_3 ,
( V_12 & V_71 ) ? L_56 : L_3 ,
( V_12 & V_72 ) ? L_57 : L_3 ,
( V_12 & V_73 ) ? L_58 : L_3 ,
( V_12 & V_74 ) ? L_59 : L_3 ,
( V_12 & V_75 ) ? L_60 : L_3 ,
( V_12 & V_76 ) ? L_61 : L_3 ,
( V_12 & V_77 ) ? L_62 : L_3 ) ;
return V_10 - V_1 ;
}
static int F_23 ( struct V_4 * V_5 , char * V_1 , int V_8 )
{
char * V_10 = V_1 ;
char * V_78 ;
if ( V_8 < 60 )
return 0 ;
switch ( V_5 -> V_78 ) {
case V_79 :
V_78 = L_63 ; break;
case V_80 :
V_78 = L_64 ; break;
case V_81 :
V_78 = L_65 ; break;
case V_82 :
V_78 = L_66 ; break;
case V_83 :
V_78 = L_67 ; break;
case V_84 :
V_78 = L_68 ; break;
case V_85 :
V_78 = L_69 ; break;
default:
V_78 = L_18 ; break;
}
V_10 += sprintf ( V_10 , L_70 ,
V_78 , V_5 -> V_86 ) ;
return V_10 - V_1 ;
}
static int F_24 ( struct V_4 * V_5 , char * V_1 , int V_8 )
{
char * V_10 = V_1 ;
unsigned short V_87 , V_88 , V_89 , V_90 ;
unsigned int V_91 ;
unsigned char V_92 ;
unsigned short V_93 , V_94 ;
if ( V_8 < 80 * 9 )
return 0 ;
V_87 = F_25 ( V_5 , 0 ) ;
V_88 = F_25 ( V_5 , 2 ) ;
V_89 = F_25 ( V_5 , 4 ) ;
V_90 = F_25 ( V_5 , 6 ) ;
V_91 = F_26 ( V_5 , 8 ) ;
V_92 = F_27 ( V_5 , 12 ) ;
V_93 = F_25 ( V_5 , 16 ) ;
V_94 = F_25 ( V_5 , 18 ) ;
V_10 += sprintf ( V_10 , L_71 ,
V_87 ,
( V_87 & V_95 ) ? L_72 : L_73 ,
( V_87 & V_96 ) ? L_74 : L_3 ,
( V_87 & V_97 ) ? L_75 : L_3 ,
( V_87 & V_98 ) ? L_76 : L_3 ,
( V_87 & V_99 ) ? L_77 : L_3 ,
( V_87 & V_100 ) ? L_78 : L_3 ,
( V_87 & V_101 ) ? L_79 : L_3 ,
( V_87 & V_102 ) ? L_80 : L_3 ) ;
V_10 += sprintf ( V_10 , L_81 ,
V_88 ,
( V_88 & V_103 ) ? L_82 : L_3 ,
( V_88 & V_104 ) ? L_83 : L_3 ,
( V_88 & V_105 ) ? L_84 : L_3 ,
( V_88 & V_106 ) ? L_85 : L_3 ,
( V_88 & V_107 ) ? L_86 : L_3 ,
( V_88 & V_108 ) ? L_87 : L_3 ) ;
V_10 += sprintf ( V_10 , L_88 , V_89 ) ;
V_10 += sprintf ( V_10 , L_89 , ( V_90 >> 10 ) & 1 ,
0xfff & ( 4 * ( unsigned int ) V_90 ) ) ;
V_10 += sprintf ( V_10 , L_90 , V_91 ) ;
V_10 += sprintf ( V_10 , L_91 , V_92 ) ;
V_10 += F_22 ( 1 , V_93 , V_10 , V_8 - ( V_10 - V_1 ) ) ;
V_10 += F_22 ( 2 , V_94 , V_10 , V_8 - ( V_10 - V_1 ) ) ;
V_10 += sprintf ( V_10 , L_92
L_93 ,
V_5 -> V_109 , V_5 -> V_109 & 1023 ,
V_5 -> V_110 , V_5 -> V_110 & 1023 ) ;
return V_10 - V_1 ;
}
static int F_28 ( struct V_4 * V_5 , char * V_1 , int V_8 )
{
char * V_10 = V_1 ;
int V_31 , V_111 ;
struct V_48 * V_36 ;
struct V_6 * V_7 ;
struct V_112 * V_113 , * V_114 ;
int V_115 , V_116 ;
T_2 V_14 ;
T_2 V_117 ;
static const char * const V_118 [] = {
L_94 , L_95 , L_96 , L_97 , L_98 , L_99 ,
L_100 , L_101 , L_102 , L_103 , L_104
} ;
V_10 += F_23 ( V_5 , V_10 , V_8 - ( V_10 - V_1 ) ) ;
V_10 += sprintf ( V_10 , L_105 ) ;
V_10 += F_24 ( V_5 , V_10 , V_8 - ( V_10 - V_1 ) ) ;
V_10 += sprintf ( V_10 , L_106 ) ;
for ( V_31 = 0 ; V_31 < V_119 ; ++ V_31 ) {
V_10 += sprintf ( V_10 , L_107 , V_5 -> V_56 [ V_31 ] ) ;
if ( V_31 % 8 == 7 )
* V_10 ++ = '\n' ;
}
V_10 += sprintf ( V_10 , L_108 ,
V_5 -> V_120 ,
F_29 ( V_5 ) -> V_121 . V_122 ,
F_29 ( V_5 ) -> V_121 . V_123 ) ;
if ( V_47 <= 1 )
return V_10 - V_1 ;
V_10 += sprintf ( V_10 , L_109 ) ;
V_115 = 10 ;
V_116 = 0 ;
for ( V_31 = 0 ; V_31 < V_124 ; ++ V_31 ) {
T_2 V_125 ;
V_111 = 0 ;
V_7 = V_5 -> V_126 [ V_31 ] ;
V_14 = V_5 -> V_127 [ V_31 ] ;
if ( ! V_7 )
goto V_128;
if ( V_115 > 0 ) {
V_10 += sprintf ( V_10 , L_110 ,
V_31 , F_5 ( V_5 , V_14 ) ) ;
V_111 = 1 ;
}
V_114 = & V_7 -> V_129 ;
V_113 = V_114 ;
do {
V_7 = F_20 ( V_113 , struct V_6 , V_129 ) ;
V_113 = V_113 -> V_62 ;
if ( V_14 != F_21 ( V_5 , V_7 ) ) {
if ( V_115 > 0 )
V_10 += sprintf ( V_10 , L_111
L_112 ) ;
else
++ V_116 ;
}
if ( V_115 > 0 )
V_10 += F_3 ( V_5 , V_7 , V_10 ,
V_8 - ( V_10 - V_1 ) , 4 ) ;
V_14 = V_7 -> V_14 ;
} while ( V_113 != V_114 );
V_128:
V_125 = F_30 ( V_5 , V_31 ) ;
if ( V_14 != V_125 ) {
if ( V_115 > 0 ) {
if ( ! V_111 ) {
V_10 += sprintf ( V_10 ,
L_110 ,
V_31 , F_5 ( V_5 , V_14 ) ) ;
V_111 = 1 ;
}
V_10 += sprintf ( V_10 , L_113
L_114 ,
F_5 ( V_5 , V_125 ) ) ;
} else
++ V_116 ;
}
V_115 -= V_111 ;
}
if ( V_116 > 0 )
V_10 += sprintf ( V_10 , L_115 , V_116 ) ;
V_10 += sprintf ( V_10 , L_116 ) ;
V_117 = 0 ;
for ( V_31 = 0 ; V_31 < V_130 ; ++ V_31 ) {
int V_131 = 0 ;
V_36 = V_5 -> V_132 [ V_31 ] ;
V_10 += sprintf ( V_10 , L_117 , V_118 [ V_31 ] ) ; \
V_10 += F_14 ( V_5 , V_36 , V_10 , V_8 - ( V_10 - V_1 ) , 4 ) ;
if ( V_31 == V_133 ) {
if ( F_15 ( V_36 ) != F_21 ( V_5 , V_5 -> V_61 ) )
V_10 += sprintf ( V_10 , L_118 ) ;
V_14 = V_117 ;
if ( ! V_14 )
V_14 = F_31 ( V_5 , V_5 -> V_134 ) ;
goto V_135;
}
V_114 = & V_36 -> V_63 ;
V_113 = V_114 -> V_62 ;
while ( V_113 != V_114 ) {
V_36 = F_20 ( V_113 , struct V_48 , V_63 ) ;
V_113 = V_113 -> V_62 ;
if ( ++ V_131 <= 10 )
V_10 += F_14 ( V_5 , V_36 , V_10 ,
V_8 - ( V_10 - V_1 ) , 4 ) ;
if ( ! V_117 && V_36 -> V_136 >= V_137 )
V_117 = F_31 ( V_5 , V_36 ) ;
}
if ( ( V_131 -= 10 ) > 0 )
V_10 += sprintf ( V_10 , L_119 , V_131 ) ;
V_14 = F_32 ( V_5 ) ;
if ( V_31 <= V_138 )
;
else if ( V_31 < V_139 )
V_14 = F_31 ( V_5 , V_5 -> V_60 ) ;
else if ( ! V_5 -> V_86 )
;
else
V_14 = F_31 ( V_5 , V_5 -> V_134 ) ;
V_135:
if ( V_36 -> V_14 != V_14 )
V_10 += sprintf ( V_10 , L_120 ) ;
}
return V_10 - V_1 ;
}
static int F_33 ( struct V_140 * V_140 , struct V_141 * V_141 )
{
struct V_4 * V_5 = V_140 -> V_142 ;
struct V_143 * V_144 ;
unsigned long V_145 ;
V_144 = F_34 ( sizeof( * V_144 ) , V_146 ) ;
if ( ! V_144 )
return - V_147 ;
V_144 -> V_148 = F_34 ( V_149 , V_146 ) ;
if ( ! V_144 -> V_148 ) {
F_35 ( V_144 ) ;
return - V_147 ;
}
V_144 -> V_150 = 0 ;
F_36 ( & V_5 -> V_151 , V_145 ) ;
if ( V_5 -> V_152 )
V_144 -> V_150 = F_28 ( V_5 , V_144 -> V_148 , V_149 ) ;
F_37 ( & V_5 -> V_151 , V_145 ) ;
V_141 -> V_153 = V_144 ;
return 0 ;
}
static T_3 F_38 ( struct V_141 * V_141 , T_3 V_154 , int V_155 )
{
struct V_143 * V_144 ;
T_3 V_156 = - 1 ;
V_144 = V_141 -> V_153 ;
switch ( V_155 ) {
case 0 :
V_156 = V_154 ;
break;
case 1 :
V_156 = V_141 -> V_157 + V_154 ;
break;
}
if ( V_156 < 0 || V_156 > V_144 -> V_150 )
return - V_158 ;
return ( V_141 -> V_157 = V_156 ) ;
}
static T_4 F_39 ( struct V_141 * V_141 , char T_5 * V_1 ,
T_6 V_159 , T_3 * V_160 )
{
struct V_143 * V_144 = V_141 -> V_153 ;
return F_40 ( V_1 , V_159 , V_160 , V_144 -> V_148 , V_144 -> V_150 ) ;
}
static int F_41 ( struct V_140 * V_140 , struct V_141 * V_141 )
{
struct V_143 * V_144 = V_141 -> V_153 ;
F_35 ( V_144 -> V_148 ) ;
F_35 ( V_144 ) ;
return 0 ;
}
static inline void F_1 ( char * V_1 )
{}
static inline int F_14 ( struct V_4 * V_5 ,
struct V_48 * V_36 , char * V_1 , int V_8 , int V_9 )
{
return 0 ;
}
static inline int F_28 ( struct V_4 * V_5 ,
char * V_1 , int V_8 )
{
return 0 ;
}
