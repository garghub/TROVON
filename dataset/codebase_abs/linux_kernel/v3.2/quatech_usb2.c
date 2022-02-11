static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
switch ( V_2 -> V_5 -> V_6 . V_7 ) {
case V_8 :
V_3 = 1 ;
break;
case V_9 :
V_4 = true ;
case V_10 :
V_3 = 2 ;
break;
case V_11 :
V_4 = true ;
case V_12 :
V_3 = 4 ;
break;
case V_13 :
V_4 = true ;
case V_14 :
V_3 = 8 ;
break;
default:
V_3 = 1 ;
break;
}
return V_3 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
int V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_15 * V_26 ;
F_3 ( L_1 ,
V_27 , V_2 -> V_28 ,
V_2 -> V_29 , V_2 -> V_30 ) ;
if ( ( V_2 -> V_28 != 1 ) || ( V_2 -> V_29 != 1 ) ) {
F_3 ( L_2 ) ;
return - V_31 ;
}
V_25 = V_2 -> V_32 -> V_33 ;
V_20 = F_4 ( sizeof( * V_20 ) , V_34 ) ;
if ( ! V_20 ) {
F_3 ( L_3 ,
V_27 ) ;
return - V_35 ;
}
V_20 -> V_36 = 0 ;
F_5 ( V_2 , V_20 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_3 ; V_21 ++ ) {
V_16 = V_2 -> V_16 [ V_21 ] ;
V_18 = F_4 ( sizeof( * V_18 ) , V_34 ) ;
if ( ! V_18 ) {
F_3 ( L_4 ,
V_27 , V_21 ) ;
return - V_35 ;
}
V_18 -> V_37 = 0 ;
F_6 ( & V_18 -> V_38 ) ;
F_7 ( & V_18 -> V_39 ) ;
F_8 ( V_16 , V_18 ) ;
}
if ( F_9 ( V_2 , V_27 ) )
return - V_31 ;
V_26 = V_2 -> V_16 [ 0 ] ;
for ( V_21 = 0 ; V_21 < V_25 -> V_40 . V_41 ; ++ V_21 ) {
V_23 = & V_25 -> V_23 [ V_21 ] . V_40 ;
if ( ( V_23 -> V_42 & 0x80 ) &&
( ( V_23 -> V_43 & 3 ) == 0x02 ) ) {
F_3 ( L_5 ,
V_23 -> V_42 ) ;
}
if ( ( ( V_23 -> V_42 & 0x80 ) == 0x00 ) &&
( ( V_23 -> V_43 & 3 ) == 0x02 ) ) {
F_3 ( L_6 ,
V_23 -> V_42 ) ;
V_20 -> V_44 = V_23 -> V_45 ;
}
}
if ( F_10 ( V_2 ) < 0 ) {
F_3 ( L_7 ) ;
goto V_46;
}
for ( V_21 = 0 ; V_21 < V_2 -> V_3 ; ++ V_21 ) {
if ( F_11 ( V_2 , V_21 , V_47 ) < 0 ) {
F_3 ( L_8 ,
V_21 ) ;
goto V_46;
}
}
return 0 ;
V_46:
for ( V_21 = 0 ; V_21 < V_2 -> V_3 ; V_21 ++ ) {
V_16 = V_2 -> V_16 [ V_21 ] ;
V_18 = F_12 ( V_16 ) ;
F_13 ( V_18 ) ;
F_8 ( V_16 , NULL ) ;
}
V_20 = F_14 ( V_2 ) ;
F_13 ( V_20 ) ;
F_5 ( V_2 , NULL ) ;
F_3 ( L_9 , V_27 ) ;
return - V_48 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_17 * V_49 ;
int V_21 ;
F_3 ( L_10 , V_27 ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_3 ; V_21 ++ ) {
V_16 = V_2 -> V_16 [ V_21 ] ;
if ( ! V_16 )
continue;
V_49 = F_16 ( V_16 ) ;
F_13 ( V_49 ) ;
F_17 ( V_16 , NULL ) ;
}
}
int F_18 ( struct V_50 * V_51 , struct V_15 * V_16 )
{
struct V_1 * V_2 ;
struct V_15 * V_26 ;
struct V_17 * V_52 ;
struct V_17 * V_53 ;
struct V_19 * V_54 ;
struct V_55 V_56 ;
unsigned short V_57 = V_58 ;
unsigned char V_59 = V_60 ;
int V_61 ;
int V_62 ;
if ( F_19 ( V_16 , V_27 ) )
return - V_31 ;
F_3 ( L_11 , V_27 , V_16 -> V_63 ) ;
V_2 = V_16 -> V_2 ;
if ( F_9 ( V_2 , V_27 ) ) {
F_3 ( L_12 ) ;
return - V_31 ;
}
V_54 = F_14 ( V_2 ) ;
if ( V_54 == NULL ) {
F_3 ( L_13 ) ;
return - V_31 ;
}
V_26 = V_2 -> V_16 [ 0 ] ;
if ( F_19 ( V_26 , V_27 ) ) {
F_3 ( L_14 ) ;
return - V_31 ;
}
V_52 = F_12 ( V_16 ) ;
V_53 = F_12 ( V_26 ) ;
if ( V_52 == NULL || V_53 == NULL ) {
F_3 ( L_15 ) ;
return - V_31 ;
}
V_61 = F_20 ( V_2 , V_16 -> V_63 ,
& V_56 ) ;
if ( V_61 < 0 ) {
F_3 ( L_16 ,
V_16 -> V_63 ) ;
return V_61 ;
}
V_52 -> V_64 = V_56 . V_65 &
( V_66 | V_67 |
V_68 | V_69 ) ;
V_52 -> V_70 = V_56 . V_71 &
( V_72 | V_73 |
V_74 | V_75 ) ;
F_3 ( L_17 ,
V_16 -> V_63 ) ;
V_61 = F_21 ( V_2 , V_16 -> V_63 , V_57 ,
V_59 ) ;
if ( V_61 < 0 ) {
F_3 ( L_18 ,
V_16 -> V_63 ) ;
return V_61 ;
}
F_3 ( L_19 ,
V_16 -> V_63 ) ;
F_3 ( L_20 , V_26 -> V_76 ) ;
F_3 ( L_21 ,
V_26 -> V_77 ) ;
if ( V_16 -> V_78 == NULL ) {
F_3 ( L_22 ) ;
V_16 -> V_78 = F_22 ( 0 , V_34 ) ;
if ( ! V_16 -> V_78 ) {
F_23 ( L_23 ) ;
return - V_35 ;
}
V_16 -> V_79 = V_54 -> V_44 ;
V_16 -> V_80 = F_24 ( V_16 -> V_79 ,
V_34 ) ;
if ( ! V_16 -> V_80 ) {
F_23 ( L_24 ) ;
return - V_35 ;
}
}
if ( V_2 -> V_5 == NULL )
F_3 ( L_25 ) ;
F_3 ( L_26 , V_16 -> V_79 ) ;
F_25 ( V_16 -> V_78 , V_2 -> V_5 ,
F_26 ( V_2 -> V_5 ,
V_26 -> V_77 ) ,
V_16 -> V_80 ,
V_16 -> V_79 ,
V_81 ,
V_16 ) ;
V_52 -> V_82 = 0 ;
if ( V_54 -> V_36 == 0 ) {
F_25 ( V_26 -> V_83 , V_2 -> V_5 ,
F_27 ( V_2 -> V_5 ,
V_26 -> V_76 ) ,
V_26 -> V_84 ,
V_26 -> V_85 ,
V_86 , V_2 ) ;
F_3 ( L_27 ) ;
V_54 -> V_87 = false ;
V_52 -> V_88 = true ;
V_62 = F_28 ( V_16 -> V_83 , V_34 ) ;
if ( V_62 ) {
F_29 ( & V_16 -> V_5 ,
L_28 ,
V_27 , V_62 ) ;
V_52 -> V_88 = false ;
V_54 -> V_87 = true ;
}
V_54 -> V_89 = V_16 ;
}
F_30 ( & V_52 -> V_90 ) ;
V_52 -> V_37 ++ ;
F_8 ( V_16 , V_52 ) ;
F_8 ( V_2 -> V_16 [ 0 ] , V_53 ) ;
F_5 ( V_2 , V_54 ) ;
V_54 -> V_36 ++ ;
return 0 ;
}
static void F_31 ( struct V_15 * V_16 )
{
unsigned long V_91 ;
struct V_17 * V_52 ;
struct V_1 * V_2 ;
struct V_19 * V_54 ;
T_1 V_92 = 0 ;
int V_61 ;
F_3 ( L_11 , V_27 , V_16 -> V_63 ) ;
V_2 = V_16 -> V_2 ;
V_54 = F_14 ( V_2 ) ;
V_52 = F_12 ( V_16 ) ;
V_52 -> V_93 = true ;
F_3 ( L_29 , V_27 ) ;
V_91 = V_94 + ( 10 * V_95 ) ;
do {
V_61 = F_32 ( V_2 , V_16 -> V_63 ,
V_96 , & V_92 ) ;
if ( V_61 < 0 ) {
F_3 ( L_30 , V_27 ) ;
break;
}
if ( ( V_92 & V_97 ) ) {
F_3 ( L_31 ) ;
break;
}
F_33 () ;
} while ( V_94 <= V_91 );
V_61 = F_34 ( V_2 , V_16 -> V_63 ) ;
if ( V_61 < 0 )
F_3 ( L_32 ,
V_27 , V_16 -> V_63 ) ;
F_35 ( V_16 -> V_78 ) ;
F_13 ( V_16 -> V_80 ) ;
V_16 -> V_80 = NULL ;
V_16 -> V_79 = 0 ;
V_52 -> V_37 -- ;
V_54 -> V_36 -- ;
F_3 ( L_33 , V_27 ,
V_54 -> V_36 ) ;
}
static int F_36 ( struct V_50 * V_51 , struct V_15 * V_16 ,
const unsigned char * V_98 , int V_99 )
{
struct V_1 * V_2 ;
T_1 V_100 [ 5 ] ;
struct V_17 * V_52 ;
int V_62 ;
V_2 = V_16 -> V_2 ;
V_52 = F_12 ( V_16 ) ;
if ( V_2 == NULL )
return - V_31 ;
F_3 ( L_34 ,
V_27 , V_16 -> V_63 , V_99 , V_52 -> V_82 ) ;
if ( V_99 <= 0 ) {
F_3 ( L_35 , V_27 ) ;
return 0 ;
}
if ( ( V_16 -> V_78 -> V_61 == - V_101 ) ) {
F_3 ( L_36
L_37 , V_27 ) ;
return 0 ;
} else if ( V_52 -> V_82 >= V_102 ) {
F_3 ( L_38 , V_27 ) ;
return 0 ;
}
if ( V_99 > V_16 -> V_79 - V_103 ) {
V_99 = V_16 -> V_79 - V_103 ;
F_3 ( L_39
L_40 , V_27 , V_99 ) ;
}
if ( V_99 > ( V_102 - V_52 -> V_82 ) ) {
V_99 = V_102 - V_52 -> V_82 ;
F_3 ( L_41 ,
V_27 , V_99 ) ;
}
V_100 [ 0 ] = 0x1b ;
V_100 [ 1 ] = 0x1b ;
V_100 [ 2 ] = ( T_1 ) V_16 -> V_63 ;
V_100 [ 3 ] = ( T_1 ) V_99 ;
V_100 [ 4 ] = ( T_1 ) V_99 >> 8 ;
memcpy ( V_16 -> V_78 -> V_104 , V_100 ,
V_103 ) ;
memcpy ( V_16 -> V_78 -> V_104 + 5 , V_98 , V_99 ) ;
F_3 ( L_42 , V_27 , * V_98 ) ;
F_25 ( V_16 -> V_78 , V_2 -> V_5 ,
F_26 ( V_2 -> V_5 ,
V_16 -> V_77 ) ,
V_16 -> V_78 -> V_104 , V_99 + 5 ,
( V_81 ) , V_16 ) ;
V_62 = F_28 ( V_16 -> V_78 , V_105 ) ;
if ( V_62 ) {
V_62 = 0 ;
F_3 ( L_43 ,
V_27 , V_62 ) ;
} else {
V_52 -> V_82 += V_99 ;
V_62 = V_99 ;
F_3 ( L_44
L_45 ,
V_27 , V_62 , V_52 -> V_82 ) ;
}
return V_62 ;
}
static int F_37 ( struct V_50 * V_51 )
{
struct V_15 * V_16 = V_51 -> V_106 ;
struct V_17 * V_52 ;
int V_107 = 0 ;
V_52 = F_12 ( V_16 ) ;
if ( V_52 -> V_93 == true ) {
F_3 ( L_46 , V_27 ) ;
return - V_31 ;
}
V_107 = ( V_102 - V_52 -> V_82 ) ;
if ( V_107 > V_16 -> V_79 - V_103 )
V_107 = V_16 -> V_79 - V_103 ;
F_3 ( L_47 , V_27 , V_16 -> V_63 , V_107 ) ;
return V_107 ;
}
static int F_38 ( struct V_50 * V_51 )
{
struct V_15 * V_16 = V_51 -> V_106 ;
struct V_17 * V_52 ;
V_52 = F_12 ( V_16 ) ;
F_3 ( L_48 , V_27 ,
V_16 -> V_63 , V_52 -> V_82 ) ;
return V_52 -> V_82 ;
}
static int F_39 ( struct V_50 * V_51 ,
unsigned int V_108 , unsigned long V_109 )
{
struct V_15 * V_16 = V_51 -> V_106 ;
struct V_1 * V_2 = V_16 -> V_2 ;
T_1 V_110 ;
T_1 V_111 ;
unsigned short V_112 ;
struct V_17 * V_52 ;
F_40 ( V_90 , V_113 ) ;
unsigned int V_114 ;
unsigned int V_115 ;
if ( V_2 == NULL )
return - V_31 ;
V_115 = V_51 -> V_116 - V_2 -> V_117 ;
V_52 = F_12 ( V_16 ) ;
F_3 ( L_49 , V_27 ,
V_16 -> V_63 , V_115 , V_51 ) ;
if ( V_108 == V_118 || V_108 == V_119 ) {
if ( F_32 ( V_16 -> V_2 , V_115 ,
V_120 , & V_110 ) < 0 )
return - V_121 ;
if ( F_41 ( & V_114 , ( unsigned int * ) V_109 ,
sizeof( V_114 ) ) )
return - V_122 ;
switch ( V_108 ) {
case V_118 :
if ( V_114 & V_123 )
V_110 |= V_124 ;
if ( V_114 & V_125 )
V_110 |= V_126 ;
if ( V_114 & V_127 )
V_110 |= V_128 ;
break;
case V_119 :
if ( V_114 & V_123 )
V_110 &= ~ V_124 ;
if ( V_114 & V_125 )
V_110 &= ~ V_126 ;
if ( V_114 & V_127 )
V_110 &= ~ V_128 ;
break;
default:
break;
}
if ( F_42 ( V_16 -> V_2 , V_115 ,
V_120 , V_110 ) < 0 ) {
return - V_121 ;
} else {
V_52 -> V_129 = V_110 ;
return 0 ;
}
} else if ( V_108 == V_130 ) {
F_3 ( L_50 ,
V_27 , V_16 -> V_63 ) ;
V_112 = V_52 -> V_70 & V_131 ;
F_43 () ;
F_44 ( V_132 ) ;
while ( 1 ) {
F_45 ( & V_52 -> V_90 , & V_90 ) ;
F_33 () ;
F_3 ( L_51 ,
V_27 , V_16 -> V_63 ) ;
F_46 ( & V_52 -> V_90 , & V_90 ) ;
if ( F_47 ( V_113 ) )
return - V_133 ;
F_48 ( V_132 ) ;
V_111 = V_52 -> V_70 & V_131 ;
if ( V_111 == V_112 ) {
F_44 ( V_134 ) ;
return - V_48 ;
}
if ( ( V_109 & V_135 &&
( ( V_112 & V_74 ) ==
( V_111 & V_74 ) ) ) ||
( V_109 & V_136 &&
( ( V_112 & V_73 ) ==
( V_111 & V_73 ) ) ) ||
( V_109 & V_137 &&
( ( V_112 & V_75 ) ==
( V_111 & V_75 ) ) ) ||
( V_109 & V_138 &&
( ( V_112 & V_72 ) ==
( V_111 & V_72 ) ) ) ) {
F_44 ( V_134 ) ;
return 0 ;
}
}
} else {
F_3 ( L_52 , V_27 ,
V_16 -> V_63 ) ;
return - V_139 ;
}
}
static void F_49 ( struct V_50 * V_51 ,
struct V_15 * V_16 , struct V_140 * V_141 )
{
struct V_1 * V_2 ;
int V_142 , V_143 , V_144 ;
unsigned char V_145 = 0 ;
int V_61 ;
T_2 V_115 ;
F_3 ( L_11 , V_27 , V_16 -> V_63 ) ;
V_2 = V_16 -> V_2 ;
V_115 = V_16 -> V_63 ;
if ( V_141 && ! F_50 ( V_141 , V_51 -> V_146 ) )
return;
switch ( V_51 -> V_146 -> V_147 ) {
case V_148 :
V_145 |= V_149 ;
break;
case V_150 :
V_145 |= V_151 ;
break;
case V_152 :
V_145 |= V_153 ;
break;
default:
case V_154 :
V_145 |= V_60 ;
break;
}
if ( V_51 -> V_146 -> V_147 & V_155 ) {
if ( V_51 -> V_146 -> V_147 & V_156 )
V_145 |= V_157 ;
else
V_145 |= V_158 ;
}
V_51 -> V_146 -> V_147 &= ~ V_159 ;
if ( V_51 -> V_146 -> V_147 & V_160 )
V_145 |= V_161 ;
else
V_145 |= V_162 ;
V_142 = F_51 ( V_51 ) ;
if ( ! V_142 ) {
V_142 = 9600 ;
}
F_3 ( L_53 , V_27 , V_142 ) ;
V_143 = V_163 / V_142 ;
V_144 = V_163 % V_142 ;
if ( ( ( V_144 * 2 ) >= V_142 ) && ( V_142 != 110 ) )
V_143 ++ ;
F_3 ( L_54 ,
V_27 , V_143 , V_163 , V_145 ) ;
V_61 = F_52 ( V_2 , V_115 , ( unsigned short ) V_143 ,
V_145 ) ;
if ( V_61 < 0 ) {
F_3 ( L_55 ) ;
return;
} else {
V_142 = V_163 / V_143 ;
F_53 ( V_51 , V_142 , V_142 ) ;
}
if ( V_51 -> V_146 -> V_147 & V_164 ) {
F_3 ( L_56 , V_27 ,
V_16 -> V_63 ) ;
V_61 = F_54 ( V_2 , V_115 , true ) ;
if ( V_61 < 0 ) {
F_3 ( L_57 ) ;
return;
}
} else {
F_3 ( L_58 , V_27 ,
V_16 -> V_63 ) ;
V_61 = F_54 ( V_2 , V_115 , false ) ;
if ( V_61 < 0 ) {
F_3 ( L_59 ) ;
return;
}
}
if ( F_55 ( V_51 ) || F_56 ( V_51 ) ) {
unsigned char V_165 = F_57 ( V_51 ) ;
unsigned char V_166 = F_58 ( V_51 ) ;
V_61 = F_59 ( V_2 , V_115 , V_165 ,
V_166 ) ;
if ( V_61 < 0 )
F_3 ( L_60 ) ;
} else {
V_61 = F_60 ( V_2 , V_115 ) ;
if ( V_61 < 0 )
F_3 ( L_61 ) ;
}
}
static int F_61 ( struct V_50 * V_51 )
{
struct V_15 * V_16 = V_51 -> V_106 ;
struct V_1 * V_2 = V_16 -> V_2 ;
T_1 V_110 ;
T_1 V_111 ;
unsigned int V_62 = 0 ;
int V_61 ;
unsigned int V_115 ;
if ( V_2 == NULL )
return - V_31 ;
F_3 ( L_62 , V_27 , V_16 -> V_63 , V_51 ) ;
V_115 = V_51 -> V_116 - V_2 -> V_117 ;
F_3 ( L_63 , V_115 ) ;
V_61 = F_32 ( V_16 -> V_2 , V_115 ,
V_120 , & V_110 ) ;
if ( V_61 >= 0 ) {
V_61 = F_32 ( V_16 -> V_2 , V_115 ,
V_167 , & V_111 ) ;
}
if ( V_61 >= 0 ) {
V_62 = ( ( V_110 & V_126 ) ? V_125 : 0 )
| ( ( V_110 & V_124 ) ? V_123 : 0 )
| ( ( V_111 & V_72 ) ? V_138 : 0 )
| ( ( V_111 & V_75 ) ? V_168 : 0 )
| ( ( V_111 & V_74 ) ? V_169 : 0 )
| ( ( V_111 & V_73 ) ? V_136 : 0 ) ;
return V_62 ;
} else {
return - V_121 ;
}
}
static int F_62 ( struct V_50 * V_51 ,
unsigned int V_170 , unsigned int V_171 )
{
struct V_15 * V_16 = V_51 -> V_106 ;
struct V_1 * V_2 = V_16 -> V_2 ;
T_1 V_110 ;
int V_61 ;
unsigned int V_115 ;
if ( V_2 == NULL )
return - V_31 ;
V_115 = V_51 -> V_116 - V_2 -> V_117 ;
F_3 ( L_64 , V_27 , V_16 -> V_63 , V_115 ) ;
V_61 = F_32 ( V_16 -> V_2 , V_115 ,
V_120 , & V_110 ) ;
if ( V_61 < 0 )
return - V_121 ;
V_110 &= ~ ( V_124 | V_126 |
V_128 ) ;
if ( V_170 & V_123 )
V_110 |= V_124 ;
if ( V_170 & V_125 )
V_110 |= V_126 ;
if ( V_170 & V_127 )
V_110 |= V_128 ;
V_61 = F_42 ( V_16 -> V_2 , V_115 ,
V_120 , V_110 ) ;
if ( V_61 < 0 )
return - V_121 ;
else
return 0 ;
}
static void F_63 ( struct V_50 * V_51 , int V_172 )
{
struct V_15 * V_16 = V_51 -> V_106 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_17 * V_52 ;
T_2 V_173 ;
unsigned int V_62 ;
V_52 = F_12 ( V_16 ) ;
if ( ! V_2 ) {
F_3 ( L_65 , V_27 , V_16 -> V_63 ) ;
return;
}
if ( V_172 == - 1 )
V_173 = 1 ;
else
V_173 = 0 ;
F_3 ( L_66 , V_27 , V_16 -> V_63 ,
V_173 ) ;
F_64 ( & V_52 -> V_39 ) ;
if ( ! V_52 -> V_37 ) {
F_3 ( L_67 , V_27 ) ;
goto exit;
}
V_62 = F_65 ( V_2 -> V_5 , F_66 ( V_2 -> V_5 , 0 ) ,
V_174 , 0x40 , V_173 ,
V_16 -> V_63 , NULL , 0 , 300 ) ;
exit:
F_67 ( & V_52 -> V_39 ) ;
F_3 ( L_68 , V_27 , V_16 -> V_63 ) ;
}
static void F_68 ( struct V_50 * V_51 )
{
struct V_15 * V_16 = V_51 -> V_106 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_17 * V_52 ;
F_3 ( L_11 , V_27 , V_16 -> V_63 ) ;
V_52 = F_12 ( V_16 ) ;
if ( ! V_2 ) {
F_3 ( L_69 , V_27 ,
V_16 -> V_63 ) ;
return;
}
F_64 ( & V_52 -> V_39 ) ;
if ( ! V_52 -> V_37 ) {
F_3 ( L_67 , V_27 ) ;
goto exit;
}
if ( V_2 -> V_5 -> V_6 . V_7 != V_8 )
F_69 ( V_2 , V_16 -> V_63 , 1 ) ;
V_16 -> V_175 = 1 ;
exit:
F_67 ( & V_52 -> V_39 ) ;
F_3 ( L_70 , V_27 , V_16 -> V_63 ) ;
return;
}
static void F_70 ( struct V_50 * V_51 )
{
struct V_15 * V_16 = V_51 -> V_106 ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_17 * V_52 ;
struct V_15 * V_26 ;
struct V_19 * V_54 ;
if ( ! V_2 ) {
F_3 ( L_71 , V_27 ,
V_16 -> V_63 ) ;
return;
}
F_3 ( L_72 , V_27 , V_16 -> V_63 ) ;
V_54 = F_14 ( V_2 ) ;
V_52 = F_12 ( V_16 ) ;
V_26 = V_2 -> V_16 [ 0 ] ;
F_64 ( & V_52 -> V_39 ) ;
if ( ! V_52 -> V_37 ) {
F_3 ( L_73 , V_27 , V_16 -> V_63 ) ;
goto exit;
}
if ( V_16 -> V_175 != 0 ) {
F_3 ( L_74 , V_27 ,
V_16 -> V_63 ) ;
V_16 -> V_175 = 0 ;
if ( V_2 -> V_5 -> V_6 . V_7 != V_8 ) {
F_69 ( V_2 , V_16 -> V_63 , 0 ) ;
} else if ( V_54 -> V_87 == true ) {
F_25 ( V_26 -> V_83 , V_2 -> V_5 ,
F_27 ( V_2 -> V_5 ,
V_26 -> V_76 ) ,
V_26 -> V_84 ,
V_26 -> V_85 ,
V_86 ,
V_2 ) ;
}
}
exit:
F_67 ( & V_52 -> V_39 ) ;
F_3 ( L_68 , V_27 , V_16 -> V_63 ) ;
return;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_62 ;
T_1 V_176 ;
unsigned int V_177 ;
V_176 = V_178 ;
V_177 = F_71 ( V_2 -> V_5 , 0 ) ;
V_62 = F_65 ( V_2 -> V_5 , V_177 , V_179 ,
V_176 , V_180 , 0x00 , NULL , 0x00 ,
5000 ) ;
return V_62 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_181 ,
T_1 V_182 )
{
int V_62 ;
T_2 V_183 ;
V_183 = ( T_2 ) ( V_182 ) ;
F_3 ( L_75 , V_27 ,
V_181 , V_183 ) ;
V_62 = F_65 ( V_2 -> V_5 , F_66 ( V_2 -> V_5 , 0 ) ,
V_184 , 0x40 , V_183 ,
( T_2 ) V_181 , NULL , 0 , 5000 ) ;
return V_62 ;
}
static int F_19 ( struct V_15 * V_16 ,
const char * V_185 )
{
if ( ! V_16 ) {
F_3 ( L_76 , V_185 ) ;
return - 1 ;
}
if ( ! V_16 -> V_2 ) {
F_3 ( L_77 , V_185 ) ;
return - 1 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
const char * V_185 )
{
if ( ! V_2 ) {
F_3 ( L_78 , V_185 ) ;
return - 1 ;
}
if ( ! V_2 -> type ) {
F_3 ( L_79 , V_185 ) ;
return - 1 ;
}
return 0 ;
}
static inline struct V_17 * F_12 ( struct V_15
* V_16 )
{
return (struct V_17 * ) F_16 ( V_16 ) ;
}
static inline void F_8 ( struct V_15 * V_16 ,
struct V_17 * V_186 )
{
F_17 ( V_16 , ( void * ) V_186 ) ;
}
static inline struct V_19 * F_14 ( struct V_1
* V_2 )
{
return (struct V_19 * ) F_72 ( V_2 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
struct V_19 * V_186 )
{
F_73 ( V_2 , ( void * ) V_186 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_2
V_181 , struct V_55 * V_61 )
{
int V_62 ;
T_2 V_187 ;
T_1 V_176 ;
unsigned int V_177 ;
V_187 = sizeof( struct V_55 ) ;
V_176 = V_188 ;
V_177 = F_71 ( V_2 -> V_5 , 0 ) ;
V_62 = F_65 ( V_2 -> V_5 , V_177 , V_189 ,
V_176 , 0x00 , V_181 , V_61 , V_187 , 5000 ) ;
return V_62 ;
}
static int F_34 ( struct V_1 * V_2 , T_2 V_181 )
{
int V_62 ;
T_1 V_190 ;
unsigned int V_177 ;
V_190 = V_178 ;
V_177 = F_66 ( V_2 -> V_5 , 0 ) ;
V_62 = F_65 ( V_2 -> V_5 , V_177 , V_189 ,
V_190 , 0 , V_181 , NULL , 0 , 5000 ) ;
return V_62 ;
}
static int F_21 ( struct V_1 * V_2 , unsigned short V_181 ,
unsigned short V_143 , unsigned char V_191 )
{
int V_62 ;
unsigned short V_192 ;
V_192 = ( V_191 << 8 ) + V_181 ;
V_62 = F_65 ( V_2 -> V_5 , F_66 ( V_2 -> V_5 , 0 ) ,
V_193 , 0x40 , V_143 , V_192 ,
NULL , 0 , 300 ) ;
return V_62 ;
}
static void V_86 ( struct V_194 * V_194 )
{
struct V_1 * V_2 = V_194 -> V_195 ;
struct V_19 * V_54 = F_14 ( V_2 ) ;
struct V_15 * V_26 = V_2 -> V_16 [ 0 ] ;
struct V_15 * V_196 = V_54 -> V_89 ;
struct V_17 * V_53 = F_12 ( V_26 ) ;
struct V_17 * V_197 = F_12 ( V_196 ) ;
struct V_50 * V_198 ;
unsigned int V_199 ;
unsigned int V_21 ;
int V_62 ;
bool V_200 ;
F_3 ( L_80 , V_27 ,
V_196 -> V_63 ) ;
if ( V_194 -> V_61 ) {
V_54 -> V_87 = true ;
F_3 ( L_81 ,
V_27 , V_194 -> V_61 ) ;
return;
}
if ( F_19 ( V_26 , V_27 ) != 0 ) {
F_3 ( L_82 ,
V_27 ) ;
return;
}
if ( F_19 ( V_196 , V_27 ) != 0 ) {
F_3 ( L_83
L_84 , V_27 ) ;
return;
}
if ( V_197 -> V_93 == true ) {
F_3 ( L_85 , V_27 ) ;
if ( V_54 -> V_36 <= 0 ) {
V_54 -> V_87 = true ;
F_3 ( L_86 , V_27 ) ;
return;
}
}
if ( ( V_53 -> V_201 == true ) &&
( V_2 -> V_5 -> V_6 . V_7 == V_8 ) ) {
V_54 -> V_87 = true ;
return;
}
V_198 = F_74 ( & V_196 -> V_16 ) ;
if ( ! V_198 ) {
F_3 ( L_87 , V_27 ) ;
return;
}
V_199 = V_194 -> V_202 ;
if ( V_199 ) {
for ( V_21 = 0 ; V_21 < V_199 ; ++ V_21 ) {
if ( ( V_21 <= ( V_199 - 3 ) ) && ( V_203 == 0x1b )
&& ( V_204 == 0x1b ) ) {
V_200 = false ;
switch ( V_205 ) {
case 0x00 :
if ( V_21 > ( V_199 - 4 ) ) {
F_3 ( L_88
L_89 ) ;
break;
}
F_75 ( V_196 ,
V_206 ) ;
V_21 += 3 ;
V_200 = true ;
break;
case 0x01 :
if ( V_21 > ( V_199 - 4 ) ) {
F_3 ( L_88
L_89 ) ;
break;
}
F_76 ( V_196 ,
V_206 ) ;
V_21 += 3 ;
V_200 = true ;
break;
case 0x02 :
if ( V_21 > ( V_199 - 4 ) ) {
F_3 ( L_88
L_89 ) ;
break;
}
F_77 ( V_196 ,
V_206 , V_207 ) ;
V_21 += 4 ;
V_200 = true ;
break;
case 0x03 :
if ( V_21 > ( V_199 - 4 ) ) {
F_3 ( L_88
L_89 ) ;
break;
}
if ( V_197 -> V_37 > 0 )
F_78 ( V_198 ) ;
F_3 ( L_90 ,
V_206 ) ;
F_79 ( V_196 ,
V_206 ) ;
V_21 += 3 ;
V_200 = true ;
V_196 = V_54 -> V_89 ;
V_197 =
F_12 ( V_196 ) ;
V_198 = F_74 (
& V_196 -> V_16 ) ;
break;
case 0x04 :
if ( V_21 > ( V_199 - 3 ) ) {
F_3 ( L_88
L_89 ) ;
break;
}
F_80 ( V_196 ) ;
V_21 += 2 ;
V_200 = true ;
break;
case 0x05 :
if ( V_21 > ( V_199 - 3 ) ) {
F_3 ( L_88
L_89 ) ;
break;
}
F_81 ( V_196 ) ;
V_21 += 2 ;
V_200 = true ;
break;
case 0xff :
F_3 ( L_91 ) ;
F_82 ( V_196 , V_203 ) ;
F_82 ( V_196 , V_204 ) ;
V_21 += 2 ;
break;
default:
F_82 ( V_196 , V_203 ) ;
V_21 += 1 ;
break;
}
if ( V_200 == true )
continue;
}
if ( V_198 && V_194 -> V_202 ) {
F_83 ( V_198 , 1 ) ;
F_84 ( V_198 , & (
( unsigned char * )
( V_194 -> V_104 )
) [ V_21 ] , 1 ) ;
}
}
F_78 ( V_198 ) ;
}
F_25 ( V_26 -> V_83 , V_2 -> V_5 ,
F_27 ( V_2 -> V_5 , V_26 -> V_76 ) ,
V_26 -> V_84 , V_26 -> V_85 ,
V_86 , V_2 ) ;
V_62 = F_28 ( V_26 -> V_83 , V_105 ) ;
if ( V_62 ) {
F_3 ( L_92 ,
V_27 , V_62 ) ;
} else {
F_3 ( L_93 , V_27 ) ;
if ( V_198 && V_199 ) {
F_78 ( V_198 ) ;
F_85 ( V_198 ) ;
}
}
F_3 ( L_94 , V_27 ) ;
return;
}
static void V_81 ( struct V_194 * V_194 )
{
struct V_15 * V_16 = (struct V_15 * ) V_194 -> V_195 ;
struct V_1 * V_2 = V_16 -> V_2 ;
F_3 ( L_11 , V_27 , V_16 -> V_63 ) ;
if ( ! V_2 ) {
F_3 ( L_95 , V_27 ) ;
return;
}
if ( V_194 -> V_61 ) {
F_3 ( L_96 ,
V_27 , V_194 -> V_61 ) ;
return;
}
F_86 ( & V_16 -> V_208 ) ;
F_3 ( L_97 , V_27 , V_16 -> V_63 ) ;
return;
}
static void F_75 ( struct V_15 * V_16 ,
unsigned char V_209 )
{
struct V_17 * V_52 = F_12 ( V_16 ) ;
V_52 -> V_64 = V_209 & ( V_66 |
V_67 | V_68 | V_69 ) ;
}
static void F_76 ( struct V_15 * V_16 ,
unsigned char V_210 )
{
struct V_17 * V_52 = F_12 ( V_16 ) ;
V_52 -> V_70 = V_210 ;
F_87 ( & V_52 -> V_90 ) ;
}
static void F_77 ( struct V_15 * V_16 ,
unsigned char V_211 , unsigned char V_212 )
{
int V_213 ;
struct V_17 * V_52 = F_12 ( V_16 ) ;
V_213 = ( int ) ( V_212 * 16 ) ;
V_213 += ( int ) V_211 ;
V_52 -> V_82 -= V_213 ;
F_3 ( L_98 , V_16 -> V_63 ,
V_213 , V_52 -> V_82 ) ;
}
static void F_79 ( struct V_15 * V_16 ,
unsigned char V_214 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_19 * V_54 = F_14 ( V_2 ) ;
V_54 -> V_89 = V_2 -> V_16 [ V_214 ] ;
}
static void F_80 ( struct V_15 * V_16 )
{
struct V_17 * V_52 = F_12 ( V_16 ) ;
V_52 -> V_215 = true ;
}
static void F_81 ( struct V_15 * V_16 )
{
struct V_17 * V_52 = F_12 ( V_16 ) ;
V_52 -> V_216 = true ;
}
static void F_82 ( struct V_15 * V_16 ,
unsigned char V_186 )
{
struct V_50 * V_51 = F_74 ( & ( V_16 -> V_16 ) ) ;
struct V_194 * V_194 = V_16 -> V_2 -> V_16 [ 0 ] -> V_83 ;
if ( V_51 && V_194 -> V_202 ) {
F_83 ( V_51 , 1 ) ;
F_84 ( V_51 , & V_186 , 1 ) ;
}
}
static int F_32 ( struct V_1 * V_2 ,
unsigned char V_217 , unsigned short V_218 ,
T_1 * V_219 )
{
int V_62 ;
V_62 = F_65 ( V_2 -> V_5 , F_71 ( V_2 -> V_5 , 0 ) ,
V_220 , 0xC0 , V_218 ,
V_217 , ( void * ) V_219 , sizeof( * V_219 ) , 300 ) ;
return V_62 ;
}
static int F_42 ( struct V_1 * V_2 ,
unsigned short V_181 , unsigned short V_221 ,
unsigned short V_222 )
{
int V_62 ;
unsigned short V_223 ;
V_223 = V_222 ;
V_223 = V_223 << 8 ;
V_223 = V_223 + V_221 ;
V_62 = F_65 ( V_2 -> V_5 , F_66 ( V_2 -> V_5 , 0 ) ,
V_220 , 0x40 , V_223 ,
V_181 , NULL , 0 , 300 ) ;
return V_62 ;
}
static int F_52 ( struct V_1 * V_2 , unsigned short V_181 ,
unsigned short V_57 , unsigned char V_59 )
{
unsigned short V_192 ;
V_192 = ( V_59 << 8 ) + V_181 ;
return F_65 ( V_2 -> V_5 , F_66 ( V_2 -> V_5 , 0 ) ,
V_193 , 0x40 , V_57 , V_192 ,
NULL , 0 , 300 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
unsigned int V_115 , bool V_224 )
{
T_1 V_225 = 0 ;
T_1 V_226 = 0 ;
T_2 V_227 = 0 ;
if ( V_224 == true ) {
V_225 = V_124 ;
} else {
V_225 = 0 ;
}
V_227 = V_225 << 8 ;
if ( V_224 == true ) {
V_226 = V_72 ;
} else {
V_226 = 0 ;
}
V_227 |= V_226 ;
return F_65 ( V_2 -> V_5 , F_66 ( V_2 -> V_5 , 0 ) ,
V_228 , 0x40 , V_227 , V_115 ,
NULL , 0 , 300 ) ;
}
static int F_59 ( struct V_1 * V_2 , T_2 V_115 ,
unsigned char V_165 , unsigned char V_166 )
{
T_2 V_229 ;
V_229 = V_166 << 8 ;
V_229 = ( unsigned short ) V_165 ;
return F_65 ( V_2 -> V_5 , F_66 ( V_2 -> V_5 , 0 ) ,
V_230 , 0x40 , V_229 , V_115 ,
NULL , 0 , 300 ) ;
}
static int F_60 ( struct V_1 * V_2 , T_2 V_115 )
{
return F_65 ( V_2 -> V_5 , F_66 ( V_2 -> V_5 , 0 ) ,
V_231 , 0x40 , 0 , V_115 , NULL ,
0 , 300 ) ;
}
static int F_69 ( struct V_1 * V_2 , unsigned short V_217 ,
unsigned short V_232 )
{
return F_65 ( V_2 -> V_5 , F_66 ( V_2 -> V_5 , 0 ) ,
V_233 , 0x40 , V_232 , V_217 , NULL , 0 , 300 ) ;
}
static int T_3 F_88 ( void )
{
int V_234 ;
F_3 ( L_99 , V_27 ) ;
V_234 = F_89 ( & V_235 ) ;
if ( V_234 )
goto V_236;
F_90 (KERN_INFO KBUILD_MODNAME L_100 DRIVER_VERSION L_101
DRIVER_DESC L_102 ) ;
V_234 = F_91 ( & V_237 ) ;
if ( V_234 == 0 )
return 0 ;
F_92 ( & V_235 ) ;
V_236:
return V_234 ;
}
static void T_4 F_93 ( void )
{
F_94 ( & V_237 ) ;
F_92 ( & V_235 ) ;
}
