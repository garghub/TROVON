static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_6 )
return V_3 ;
if ( V_2 -> V_7 -> V_8 -> V_9 == V_10 ) {
if ( V_3 > 4800 ) {
F_3 ( L_1
L_2 , V_11 , V_3 ) ;
return - 1 ;
}
}
switch ( V_5 -> V_12 ) {
case V_13 :
if ( V_3 <= 600 ) {
F_3 ( L_3
L_4 , V_11 , V_3 ) ;
return - 1 ;
}
break;
default:
break;
}
return V_3 ;
}
static int F_4 ( struct V_14 * V_15 ,
struct V_1 * V_2 , T_1 V_16 , int V_17 ,
int V_18 , int V_19 , int V_20 , int V_21 ,
int V_22 )
{
int V_23 = 0 , V_24 = 0 , V_25 = 0 ;
struct V_4 * V_5 ;
T_2 * V_26 ;
const unsigned int V_27 = 5 ;
unsigned long V_28 ;
V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_29 )
return - V_30 ;
V_26 = F_5 ( V_27 , sizeof( T_2 ) , V_31 ) ;
if ( ! V_26 )
return - V_32 ;
switch ( V_22 ) {
case V_33 :
V_23 = V_5 -> V_16 ;
if ( V_16 && V_16 != V_5 -> V_16 ) {
F_3 ( L_5 , V_11 ) ;
V_24 = F_1 ( V_2 , V_16 ) ;
if ( V_24 >= 0 ) {
V_23 = V_24 ;
F_3 ( L_6 ,
V_11 , V_23 ) ;
}
}
F_3 ( L_7 ,
V_11 , V_23 ) ;
F_6 ( V_23 , V_26 ) ;
V_26 [ 4 ] |= V_17 ;
V_26 [ 4 ] |= ( V_18 << 3 ) ;
V_26 [ 4 ] |= ( V_19 << 4 ) ;
V_26 [ 4 ] |= ( V_20 << 5 ) ;
V_26 [ 4 ] |= ( V_21 << 7 ) ;
F_3 ( L_8 ,
V_11 ) ;
F_3 ( L_9 , V_11 ,
V_26 [ 0 ] , V_26 [ 1 ] ,
V_26 [ 2 ] , V_26 [ 3 ] ,
V_26 [ 4 ] ) ;
do {
V_24 = F_7 ( V_2 -> V_7 -> V_8 ,
F_8 ( V_2 -> V_7 -> V_8 , 0 ) ,
V_34 ,
V_35 | V_36 | V_37 ,
0x0300 , 0 , V_26 ,
V_27 , 500 ) ;
if ( V_25 ++ >= 3 )
break;
} while ( V_24 != V_27 &&
V_24 != - V_30 );
if ( V_24 != V_27 ) {
F_9 ( & V_2 -> V_8 , L_10
L_11 , V_11 , V_24 ) ;
F_10 ( V_2 ) ;
} else {
F_11 ( & V_5 -> V_38 , V_28 ) ;
V_5 -> V_16 = V_23 ;
V_5 -> V_39 = V_26 [ 4 ] ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
if ( V_16 )
F_13 ( V_15 ,
V_23 , V_23 ) ;
}
break;
case V_40 :
if ( V_5 -> V_41 ) {
V_24 = - V_42 ;
goto V_43;
}
F_3 ( L_12 , V_11 ) ;
do {
V_24 = F_7 ( V_2 -> V_7 -> V_8 ,
F_14 ( V_2 -> V_7 -> V_8 , 0 ) ,
V_44 ,
V_45 | V_36 | V_37 ,
0x0300 , 0 , V_26 ,
V_27 , 500 ) ;
if ( V_25 ++ >= 3 )
break;
} while ( V_24 != V_27
&& V_24 != - V_30 );
if ( V_24 != V_27 ) {
F_9 ( & V_2 -> V_8 , L_13
L_11 , V_11 , V_24 ) ;
F_10 ( V_2 ) ;
goto V_43;
} else {
F_11 ( & V_5 -> V_38 , V_28 ) ;
V_5 -> V_39 = V_26 [ 4 ] ;
V_5 -> V_16 = F_15 ( V_26 ) ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
}
}
F_11 ( & V_5 -> V_38 , V_28 ) ;
++ V_5 -> V_46 ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
V_43:
F_16 ( V_26 ) ;
return V_24 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_28 ;
F_11 ( & V_5 -> V_38 , V_28 ) ;
if ( ! V_5 -> V_29 ) {
F_12 ( & V_5 -> V_38 , V_28 ) ;
return;
}
V_5 -> V_29 = 0 ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
F_9 ( & V_2 -> V_8 , L_14
L_15 , V_2 -> V_47 ) ;
}
static int F_17 ( struct V_48 * V_7 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 = V_7 -> V_2 [ 0 ] ;
V_5 = F_18 ( sizeof( struct V_4 ) , V_31 ) ;
if ( ! V_5 )
return - V_32 ;
V_5 -> V_29 = ! 0 ;
F_19 ( & V_5 -> V_38 ) ;
if ( F_20 ( & V_5 -> V_49 , V_50 , V_31 ) ) {
F_16 ( V_5 ) ;
return - V_32 ;
}
F_21 ( & V_5 -> V_51 ) ;
F_22 ( V_7 -> V_8 ) ;
V_5 -> V_52 = 0 ;
V_5 -> V_53 = 0 ;
V_5 -> V_54 = 0 ;
V_5 -> V_55 = 0 ;
if ( V_2 -> V_56 > 9 )
V_5 -> V_57 = V_58 ;
else
V_5 -> V_57 = V_59 ;
if ( V_60 > 0 ) {
V_5 -> V_61 = V_60 ;
V_5 -> V_62 = V_60 ;
F_3 ( L_16 ,
V_11 , V_2 -> V_47 , V_60 ) ;
} else {
V_5 -> V_61 = V_2 -> V_63 -> V_60 ;
V_5 -> V_62 = V_2 -> V_64 -> V_60 ;
F_3 ( L_17 ,
V_11 , V_2 -> V_47 ,
V_5 -> V_62 , V_5 -> V_61 ) ;
}
F_23 ( V_2 , V_5 ) ;
return 0 ;
}
static int F_24 ( struct V_48 * V_7 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 = V_7 -> V_2 [ 0 ] ;
if ( F_17 ( V_7 ) ) {
F_3 ( L_18 , V_11 ,
V_2 -> V_47 ) ;
return 1 ;
}
V_5 = F_2 ( V_2 ) ;
V_5 -> V_12 = V_13 ;
V_5 -> V_57 = V_58 ;
if ( V_7 -> V_8 -> V_65 . V_66 !=
F_25 ( V_67 ) ) {
F_3 ( L_19
L_20 , V_11 ) ;
V_5 -> V_41 = ! 0 ;
}
return 0 ;
}
static int F_26 ( struct V_48 * V_7 )
{
struct V_4 * V_5 ;
if ( F_17 ( V_7 ) ) {
F_3 ( L_18 , V_11 ,
V_7 -> V_2 [ 0 ] -> V_47 ) ;
return 1 ;
}
V_5 = F_2 ( V_7 -> V_2 [ 0 ] ) ;
V_5 -> V_12 = V_68 ;
return 0 ;
}
static int F_27 ( struct V_48 * V_7 )
{
struct V_4 * V_5 ;
if ( F_17 ( V_7 ) ) {
F_3 ( L_18 , V_11 ,
V_7 -> V_2 [ 0 ] -> V_47 ) ;
return 1 ;
}
V_5 = F_2 ( V_7 -> V_2 [ 0 ] ) ;
V_5 -> V_12 = V_69 ;
return 0 ;
}
static void F_28 ( struct V_48 * V_7 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_7 -> V_2 [ 0 ] ) ;
if ( V_5 ) {
F_29 ( & V_5 -> V_49 ) ;
F_16 ( V_5 ) ;
}
}
static int F_30 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_48 * V_7 = V_2 -> V_7 ;
unsigned long V_28 ;
int V_70 = 0 ;
if ( ! V_5 -> V_29 )
return - V_71 ;
F_31 ( V_7 -> V_8 , 0x81 ) ;
F_31 ( V_7 -> V_8 , 0x02 ) ;
F_11 ( & V_5 -> V_38 , V_28 ) ;
V_5 -> V_72 = 0 ;
V_5 -> V_73 = 0 ;
V_5 -> V_46 = 0 ;
V_5 -> V_55 = 0 ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
F_32 ( V_2 ) ;
if ( V_15 )
F_33 ( V_15 , V_2 , & V_5 -> V_74 ) ;
if ( ! V_2 -> V_64 ) {
F_9 ( & V_2 -> V_8 , L_21 ,
V_11 ) ;
return - 1 ;
}
F_34 ( V_2 -> V_64 , V_7 -> V_8 ,
F_35 ( V_7 -> V_8 , V_2 -> V_75 ) ,
V_2 -> V_64 -> V_76 ,
V_2 -> V_64 -> V_77 ,
V_78 , V_2 , V_5 -> V_62 ) ;
V_70 = F_36 ( V_2 -> V_64 , V_31 ) ;
if ( V_70 ) {
F_9 ( & V_2 -> V_8 ,
L_22 ,
V_11 , V_70 ) ;
F_10 ( V_2 ) ;
}
V_2 -> V_2 . V_79 = 256 ;
return V_70 ;
}
static void F_37 ( struct V_1 * V_2 , int V_80 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_38 ( & V_5 -> V_38 ) ;
if ( V_80 == 0 )
V_5 -> V_53 = 0 ;
else
V_5 -> V_53 = V_81 | V_82 ;
V_5 -> V_52 = 1 ;
F_39 ( & V_5 -> V_38 ) ;
F_40 ( NULL , V_2 , NULL , 0 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_28 ;
F_42 ( & V_2 -> V_7 -> V_83 ) ;
if ( V_2 -> V_7 -> V_84 ) {
F_43 ( & V_2 -> V_7 -> V_83 ) ;
return;
}
F_11 ( & V_5 -> V_38 , V_28 ) ;
F_44 ( & V_5 -> V_49 ) ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
F_3 ( L_23 , V_11 ) ;
F_45 ( V_2 -> V_64 ) ;
F_45 ( V_2 -> V_63 ) ;
if ( V_85 )
F_46 ( & V_2 -> V_8 , L_24 ,
V_5 -> V_72 , V_5 -> V_73 , V_5 -> V_46 ) ;
F_43 ( & V_2 -> V_7 -> V_83 ) ;
}
static int F_40 ( struct V_14 * V_15 , struct V_1 * V_2 ,
const unsigned char * V_86 , int V_87 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( L_25 , V_11 , V_2 -> V_47 , V_87 ) ;
if ( V_5 -> V_52 ) {
V_87 = 0 ;
goto V_88;
}
if ( ! V_87 )
return V_87 ;
V_87 = F_47 ( & V_5 -> V_49 , V_86 , V_87 , & V_5 -> V_38 ) ;
V_88:
F_32 ( V_2 ) ;
return V_87 ;
}
static void F_32 ( struct V_1 * V_2 )
{
int V_87 = 0 , V_70 , V_89 , V_90 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_28 ;
if ( ! V_5 -> V_29 )
return;
F_3 ( L_26 , V_11 ,
V_2 -> V_56 ) ;
F_11 ( & V_5 -> V_38 , V_28 ) ;
if ( V_5 -> V_91 ) {
F_3 ( L_27 , V_11 ) ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
return;
}
F_12 ( & V_5 -> V_38 , V_28 ) ;
memset ( V_2 -> V_63 -> V_76 , 0 ,
V_2 -> V_56 ) ;
F_11 ( & V_5 -> V_38 , V_28 ) ;
switch ( V_5 -> V_57 ) {
default:
case V_58 :
V_89 = 2 ;
V_2 -> V_92 [ 0 ] = V_5 -> V_53 ;
break;
case V_59 :
V_89 = 1 ;
V_2 -> V_92 [ 0 ] = V_5 -> V_53 ;
break;
}
if ( V_5 -> V_53 & V_93 )
V_5 -> V_53 &= ~ V_93 ;
if ( V_5 -> V_52 ) {
V_5 -> V_46 ++ ;
F_3 ( L_28 , V_11 ) ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
goto V_94;
} else
F_12 ( & V_5 -> V_38 , V_28 ) ;
V_87 = F_48 ( & V_5 -> V_49 ,
& V_2 -> V_92 [ V_89 ] ,
V_2 -> V_56 - V_89 ,
& V_5 -> V_38 ) ;
if ( V_87 == 0 )
return;
switch ( V_5 -> V_57 ) {
default:
case V_58 :
V_2 -> V_92 [ 1 ] = V_87 ;
break;
case V_59 :
V_2 -> V_92 [ 0 ] |= V_87 ;
}
F_3 ( L_29 , V_11 , V_87 ) ;
V_94:
F_11 ( & V_5 -> V_38 , V_28 ) ;
V_5 -> V_91 = 1 ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
if ( V_5 -> V_52 )
V_90 = 1 ;
else
V_90 = V_87 +
( V_5 -> V_57 == V_58 ? 2 : 1 ) ;
F_49 ( V_95 , & V_2 -> V_8 , V_11 ,
V_2 -> V_56 ,
V_2 -> V_63 -> V_76 ) ;
F_34 ( V_2 -> V_63 , V_2 -> V_7 -> V_8 ,
F_50 ( V_2 -> V_7 -> V_8 , V_2 -> V_96 ) ,
V_2 -> V_92 , V_2 -> V_56 ,
V_97 , V_2 , V_5 -> V_61 ) ;
V_70 = F_36 ( V_2 -> V_63 , V_98 ) ;
if ( V_70 ) {
F_51 ( V_2 ,
L_30 ,
V_11 , V_70 ) ;
V_5 -> V_91 = 0 ;
F_10 ( V_2 ) ;
}
F_11 ( & V_5 -> V_38 , V_28 ) ;
if ( V_5 -> V_52 )
V_5 -> V_52 = 0 ;
V_5 -> V_73 += V_87 ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
F_52 ( V_2 ) ;
}
static int F_53 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_99 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_100 = 0 ;
unsigned long V_28 ;
F_11 ( & V_5 -> V_38 , V_28 ) ;
V_100 = F_54 ( & V_5 -> V_49 ) ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
F_3 ( L_31 , V_11 , V_100 ) ;
return V_100 ;
}
static int F_55 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_99 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_101 , V_102 ;
unsigned int V_70 = 0 ;
unsigned long V_28 ;
F_11 ( & V_5 -> V_38 , V_28 ) ;
V_102 = V_5 -> V_53 ;
V_101 = V_5 -> V_103 ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
V_70 = ( ( V_102 & V_81 ) ? V_104 : 0 )
| ( ( V_102 & V_82 ) ? V_105 : 0 )
| ( ( V_101 & V_106 ) ? V_107 : 0 )
| ( ( V_101 & V_108 ) ? V_109 : 0 )
| ( ( V_101 & V_110 ) ? V_111 : 0 )
| ( ( V_101 & V_112 ) ? V_113 : 0 ) ;
F_3 ( L_32 , V_11 , V_70 ) ;
return V_70 ;
}
static int F_56 ( struct V_14 * V_15 ,
unsigned int V_114 , unsigned int V_115 )
{
struct V_1 * V_2 = V_15 -> V_99 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_28 ;
F_11 ( & V_5 -> V_38 , V_28 ) ;
if ( V_114 & V_105 )
V_5 -> V_53 |= V_82 ;
if ( V_114 & V_104 )
V_5 -> V_53 |= V_81 ;
if ( V_115 & V_105 )
V_5 -> V_53 &= ~ V_82 ;
if ( V_115 & V_104 )
V_5 -> V_53 &= ~ V_81 ;
V_5 -> V_52 = 1 ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
return F_40 ( V_15 , V_2 , NULL , 0 ) ;
}
static int F_57 ( struct V_14 * V_15 ,
unsigned int V_116 , unsigned long V_117 )
{
struct V_1 * V_2 = V_15 -> V_99 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( L_33 , V_11 , V_2 -> V_47 , V_116 ) ;
switch ( V_116 ) {
case V_118 :
while ( V_5 != NULL ) {
F_58 ( & V_5 -> V_51 ) ;
if ( F_59 ( V_119 ) )
return - V_120 ;
else {
char V_121 = V_5 -> V_122 ;
if ( V_121 == 0 )
return - V_71 ;
V_5 -> V_122 = 0 ;
if ( ( ( V_117 & V_123 ) && ( V_121 & V_110 ) ) ||
( ( V_117 & V_109 ) && ( V_121 & V_108 ) ) ||
( ( V_117 & V_113 ) && ( V_121 & V_112 ) ) ||
( ( V_117 & V_107 ) && ( V_121 & V_106 ) ) )
return 0 ;
}
}
return 0 ;
default:
break;
}
F_3 ( L_34 , V_11 , V_116 ) ;
return - V_124 ;
}
static void F_33 ( struct V_14 * V_15 ,
struct V_1 * V_2 , struct V_125 * V_126 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_17 , V_18 , V_20 , V_19 ;
unsigned V_127 , V_128 ;
unsigned long V_28 ;
T_3 V_129 ;
int V_130 = 0 ;
F_11 ( & V_5 -> V_38 , V_28 ) ;
if ( ! V_5 -> V_54 ) {
if ( V_5 -> V_12 == V_13 ) {
* ( V_15 -> V_131 ) = V_132 ;
V_15 -> V_131 -> V_133 = V_134 | V_135 | V_136 | V_137 |
V_138 ;
V_15 -> V_131 -> V_139 = 4800 ;
V_15 -> V_131 -> V_140 = 4800 ;
} else if ( V_5 -> V_12 == V_68 ) {
* ( V_15 -> V_131 ) = V_132 ;
V_15 -> V_131 -> V_133 = V_141 | V_135 | V_136 | V_137 |
V_138 ;
V_15 -> V_131 -> V_139 = 9600 ;
V_15 -> V_131 -> V_140 = 9600 ;
} else if ( V_5 -> V_12 == V_69 ) {
* ( V_15 -> V_131 ) = V_132 ;
V_15 -> V_131 -> V_133 = V_141 | V_135 | V_136 | V_137 |
V_138 ;
V_15 -> V_131 -> V_139 = 9600 ;
V_15 -> V_131 -> V_140 = 9600 ;
}
V_5 -> V_54 = 1 ;
}
F_12 ( & V_5 -> V_38 , V_28 ) ;
V_15 -> V_131 -> V_133 &= ~ ( V_142 | V_143 ) ;
V_127 = V_15 -> V_131 -> V_133 ;
V_128 = V_15 -> V_131 -> V_144 ;
if ( V_126 ) {
F_11 ( & V_5 -> V_38 , V_28 ) ;
V_5 -> V_74 = * ( V_15 -> V_131 ) ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
}
V_18 = V_127 & V_145 ? 1 : 0 ;
if ( V_127 & V_146 ) {
V_19 = 1 ;
V_20 = V_127 & V_147 ? 1 : 0 ;
} else
V_19 = V_20 = 0 ;
switch ( V_127 & V_148 ) {
case V_149 :
V_17 = 0 ;
break;
case V_150 :
V_17 = 1 ;
break;
case V_151 :
V_17 = 2 ;
break;
case V_135 :
V_17 = 3 ;
break;
default:
F_9 ( & V_2 -> V_8 , L_35 ,
V_11 ) ;
V_17 = 3 ;
}
F_11 ( & V_5 -> V_38 , V_28 ) ;
V_129 = V_5 -> V_53 ;
if ( ( V_127 & V_152 ) == V_153 ) {
F_3 ( L_36 , V_11 ) ;
V_5 -> V_53 &= ~ ( V_81 | V_82 ) ;
} else
V_5 -> V_53 = ( V_81 | V_82 ) ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
F_3 ( L_37
L_38 , V_11 , V_18 ,
V_19 , V_20 , V_17 ) ;
F_4 ( V_15 , V_2 , F_60 ( V_15 ) ,
V_17 , V_18 ,
V_19 , V_20 ,
0 , V_33 ) ;
F_4 ( V_15 , V_2 , 0 , 0 , 0 , 0 , 0 , 0 , V_40 ) ;
F_11 ( & V_5 -> V_38 , V_28 ) ;
if ( V_5 -> V_12 == V_13 && V_5 -> V_16 == 4800 ) {
F_3 ( L_39
L_40 ) ;
V_15 -> V_131 -> V_144
&= ~ ( V_154
| V_155
| V_156
| V_157
| V_158
| V_159
| V_160
| V_161 ) ;
V_15 -> V_131 -> V_162
&= ~ V_163 ;
V_15 -> V_131 -> V_164
&= ~ ( V_165
| V_166
| V_167
| V_168
| V_169 ) ;
}
V_130 = ( V_5 -> V_53 != V_129 ) ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
if ( V_130 ) {
V_5 -> V_52 = 1 ;
F_40 ( V_15 , V_2 , NULL , 0 ) ;
}
}
static int F_61 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_99 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_170 = 0 ;
unsigned long V_28 ;
F_11 ( & V_5 -> V_38 , V_28 ) ;
V_170 = F_62 ( & V_5 -> V_49 ) ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
F_3 ( L_31 , V_11 , V_170 ) ;
return V_170 ;
}
static void F_63 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_99 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_38 ( & V_5 -> V_38 ) ;
V_5 -> V_55 = V_171 ;
F_39 ( & V_5 -> V_38 ) ;
}
static void F_64 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_99 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_172 , V_70 ;
F_38 ( & V_5 -> V_38 ) ;
V_172 = V_5 -> V_55 & V_173 ;
V_5 -> V_55 = 0 ;
F_39 ( & V_5 -> V_38 ) ;
if ( ! V_5 -> V_29 )
return;
if ( V_172 ) {
V_70 = F_36 ( V_2 -> V_64 , V_31 ) ;
if ( V_70 ) {
F_9 ( & V_2 -> V_8 , L_41
L_42 , V_11 , V_70 ) ;
F_10 ( V_2 ) ;
}
}
}
static void V_78 ( struct V_174 * V_174 )
{
struct V_1 * V_2 = V_174 -> V_175 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
unsigned char * V_176 = V_174 -> V_76 ;
unsigned long V_28 ;
char V_177 = V_178 ;
int V_179 = 0 ;
int V_180 = 0 ;
int V_70 ;
int V_181 = 0 ;
int V_101 = V_174 -> V_101 ;
switch ( V_101 ) {
case 0 :
break;
case - V_182 :
case - V_183 :
case - V_184 :
return;
case - V_185 :
default:
F_9 ( & V_174 -> V_8 -> V_8 ,
L_43 ,
V_11 , V_101 ) ;
F_10 ( V_2 ) ;
return;
}
F_11 ( & V_5 -> V_38 , V_28 ) ;
if ( V_5 -> V_55 & V_171 ) {
F_3 ( L_44 , V_11 ) ;
V_5 -> V_55 |= V_173 ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
return;
}
F_12 ( & V_5 -> V_38 , V_28 ) ;
V_15 = F_65 ( & V_2 -> V_2 ) ;
if ( ! V_15 ) {
F_3 ( L_45 , V_11 ) ;
return;
}
F_11 ( & V_5 -> V_38 , V_28 ) ;
V_70 = V_174 -> V_186 ;
switch ( V_5 -> V_57 ) {
default:
case V_58 :
V_5 -> V_103 = V_176 [ 0 ] & 0xF8 ;
V_180 = V_176 [ 1 ] + 2 ;
V_181 = 2 ;
if ( V_180 > 2 )
V_179 = 1 ;
break;
case V_59 :
V_5 -> V_103 = V_176 [ 0 ] & 0xF8 ;
V_180 = ( V_176 [ 0 ] & 0x07 ) + 1 ;
V_181 = 1 ;
if ( V_180 > 1 )
V_179 = 1 ;
break;
}
F_12 ( & V_5 -> V_38 , V_28 ) ;
if ( V_70 < V_180 ) {
F_3 ( L_46
L_47 , V_11 , V_70 , V_180 ) ;
goto V_187;
}
F_49 ( V_95 , & V_2 -> V_8 , V_11 ,
V_174 -> V_186 , V_176 ) ;
F_11 ( & V_5 -> V_38 , V_28 ) ;
if ( V_5 -> V_103 != V_5 -> V_188 ) {
V_5 -> V_122 |= V_5 -> V_103 ^
V_5 -> V_188 ;
F_66 ( & V_5 -> V_51 ) ;
V_5 -> V_188 = V_5 -> V_103 ;
}
F_12 ( & V_5 -> V_38 , V_28 ) ;
if ( V_15 && ! ( V_15 -> V_131 -> V_133 & V_138 ) &&
! ( V_5 -> V_103 & V_112 ) ) {
F_3 ( L_48 , V_11 ) ;
F_67 ( V_15 ) ;
goto V_187;
}
F_11 ( & V_5 -> V_38 , V_28 ) ;
if ( V_5 -> V_103 & V_189 ) {
F_12 ( & V_5 -> V_38 , V_28 ) ;
V_177 = V_190 ;
F_3 ( L_49 , V_11 ) ;
} else
F_12 ( & V_5 -> V_38 , V_28 ) ;
if ( V_15 && V_180 > V_181 ) {
F_68 ( V_15 , V_176 + V_181 ,
V_177 , V_180 - V_181 ) ;
F_69 ( V_15 ) ;
}
F_11 ( & V_5 -> V_38 , V_28 ) ;
V_5 -> V_72 += V_180 ;
F_12 ( & V_5 -> V_38 , V_28 ) ;
V_187:
F_70 ( V_15 ) ;
if ( V_5 -> V_29 ) {
F_34 ( V_2 -> V_64 , V_2 -> V_7 -> V_8 ,
F_35 ( V_2 -> V_7 -> V_8 ,
V_2 -> V_75 ) ,
V_2 -> V_64 -> V_76 ,
V_2 -> V_64 -> V_77 ,
V_78 , V_2 ,
V_5 -> V_62 ) ;
V_70 = F_36 ( V_2 -> V_64 , V_98 ) ;
if ( V_70 && V_70 != - V_191 ) {
F_9 ( & V_174 -> V_8 -> V_8 , L_50
L_51 , V_11 ,
V_70 ) ;
F_10 ( V_2 ) ;
}
}
}
static void V_97 ( struct V_174 * V_174 )
{
struct V_1 * V_2 = V_174 -> V_175 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_70 ;
int V_101 = V_174 -> V_101 ;
switch ( V_101 ) {
case 0 :
break;
case - V_182 :
case - V_183 :
case - V_184 :
F_3 ( L_52 ,
V_11 , V_101 ) ;
V_5 -> V_91 = 0 ;
return;
case - V_185 :
if ( ! V_5 -> V_29 )
break;
F_31 ( V_2 -> V_7 -> V_8 , 0x02 ) ;
F_3 ( L_53 ,
V_11 , V_101 ) ;
V_2 -> V_63 -> V_77 = 1 ;
V_70 = F_36 ( V_2 -> V_63 , V_98 ) ;
if ( ! V_70 )
return;
F_9 ( & V_174 -> V_8 -> V_8 ,
L_54 ,
V_11 , V_70 ) ;
F_10 ( V_2 ) ;
break;
default:
F_9 ( & V_174 -> V_8 -> V_8 ,
L_55 ,
V_11 , V_101 ) ;
F_10 ( V_2 ) ;
break;
}
V_5 -> V_91 = 0 ;
F_32 ( V_2 ) ;
}
