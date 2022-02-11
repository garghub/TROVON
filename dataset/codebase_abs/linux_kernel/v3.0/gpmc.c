static void F_1 ( int V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_3 + V_1 ) ;
}
static T_1 F_3 ( int V_1 )
{
return F_4 ( V_3 + V_1 ) ;
}
static void F_5 ( int V_4 , int V_1 , T_2 V_2 )
{
void T_3 * V_5 ;
V_5 = V_3 + V_6 + ( V_4 * V_7 ) + V_1 ;
F_6 ( V_2 , V_5 ) ;
}
static T_2 F_7 ( int V_4 , int V_1 )
{
void T_3 * V_5 ;
V_5 = V_3 + V_6 + ( V_4 * V_7 ) + V_1 ;
return F_8 ( V_5 ) ;
}
void F_9 ( int V_4 , int V_1 , T_1 V_2 )
{
void T_3 * V_5 ;
V_5 = V_3 + V_6 + ( V_4 * V_7 ) + V_1 ;
F_2 ( V_2 , V_5 ) ;
}
T_1 F_10 ( int V_4 , int V_1 )
{
void T_3 * V_5 ;
V_5 = V_3 + V_6 + ( V_4 * V_7 ) + V_1 ;
return F_4 ( V_5 ) ;
}
unsigned long F_11 ( void )
{
unsigned long V_8 = F_12 ( V_9 ) ;
if ( V_8 == 0 ) {
F_13 ( V_10 L_1 ) ;
return 0 ;
}
V_8 /= 1000 ;
V_8 = 1000000000 / V_8 ;
return V_8 ;
}
unsigned int F_14 ( unsigned int V_11 )
{
unsigned long V_12 ;
V_12 = F_11 () ;
return ( V_11 * 1000 + V_12 - 1 ) / V_12 ;
}
unsigned int F_15 ( unsigned int V_13 )
{
unsigned long V_12 ;
V_12 = F_11 () ;
return ( V_13 + V_12 - 1 ) / V_12 ;
}
unsigned int F_16 ( unsigned int V_14 )
{
return V_14 * F_11 () / 1000 ;
}
unsigned int F_17 ( unsigned int V_11 )
{
unsigned long V_14 = F_14 ( V_11 ) ;
return V_14 * F_11 () / 1000 ;
}
int F_18 ( int V_4 , unsigned int V_15 )
{
int div ;
T_1 V_16 ;
V_16 = V_15 + ( F_11 () - 1 ) ;
div = V_16 / F_11 () ;
if ( div > 4 )
return - 1 ;
if ( div <= 0 )
div = 1 ;
return div ;
}
int F_19 ( int V_4 , const struct V_17 * V_18 )
{
int div ;
T_1 V_16 ;
div = F_18 ( V_4 , V_18 -> V_15 ) ;
if ( div < 0 )
return - 1 ;
F_20 ( V_19 , 0 , 3 , V_20 ) ;
F_20 ( V_19 , 8 , 12 , V_21 ) ;
F_20 ( V_19 , 16 , 20 , V_22 ) ;
F_20 ( V_23 , 0 , 3 , V_24 ) ;
F_20 ( V_23 , 8 , 12 , V_25 ) ;
F_20 ( V_23 , 16 , 20 , V_26 ) ;
F_20 ( V_27 , 0 , 3 , V_28 ) ;
F_20 ( V_27 , 8 , 12 , V_29 ) ;
F_20 ( V_27 , 16 , 19 , V_30 ) ;
F_20 ( V_27 , 24 , 28 , V_31 ) ;
F_20 ( V_32 , 0 , 4 , V_33 ) ;
F_20 ( V_32 , 8 , 12 , V_34 ) ;
F_20 ( V_32 , 16 , 20 , V_35 ) ;
F_20 ( V_32 , 24 , 27 , V_36 ) ;
if ( F_21 () ) {
F_20 ( V_37 , 16 , 19 , V_38 ) ;
F_20 ( V_37 , 24 , 28 , V_39 ) ;
}
V_16 = F_10 ( V_4 , V_40 ) ;
if ( V_16 & ( V_41 | V_42 ) ) {
#ifdef F_22
F_13 ( V_43 L_2 ,
V_4 , ( div * F_11 () ) / 1000 , div ) ;
#endif
V_16 &= ~ 0x03 ;
V_16 |= ( div - 1 ) ;
F_9 ( V_4 , V_40 , V_16 ) ;
}
return 0 ;
}
static void F_23 ( int V_4 , T_1 V_44 , T_1 V_45 )
{
T_1 V_16 ;
T_1 V_46 ;
V_46 = ( 1 << V_47 ) - V_45 ;
V_16 = F_10 ( V_4 , V_48 ) ;
V_16 &= ~ 0x3f ;
V_16 = ( V_44 >> V_49 ) & 0x3f ;
V_16 &= ~ ( 0x0f << 8 ) ;
V_16 |= ( ( V_46 >> V_49 ) & 0x0f ) << 8 ;
V_16 |= V_50 ;
F_9 ( V_4 , V_48 , V_16 ) ;
}
static void F_24 ( int V_4 )
{
T_1 V_16 ;
V_16 = F_10 ( V_4 , V_48 ) ;
V_16 &= ~ V_50 ;
F_9 ( V_4 , V_48 , V_16 ) ;
}
static void F_25 ( int V_4 , T_1 * V_44 , T_1 * V_45 )
{
T_1 V_16 ;
T_1 V_46 ;
V_16 = F_10 ( V_4 , V_48 ) ;
* V_44 = ( V_16 & 0x3f ) << V_49 ;
V_46 = ( V_16 >> 8 ) & 0x0f ;
* V_45 = ( 1 << V_47 ) - ( V_46 << V_49 ) ;
}
static int F_26 ( int V_4 )
{
T_1 V_16 ;
V_16 = F_10 ( V_4 , V_48 ) ;
return V_16 & V_50 ;
}
int F_27 ( int V_4 , int V_51 )
{
if ( V_4 > V_52 )
return - V_53 ;
V_54 &= ~ ( 1 << V_4 ) ;
V_54 |= ( V_51 ? 1 : 0 ) << V_4 ;
return 0 ;
}
int F_28 ( int V_4 )
{
if ( V_4 > V_52 )
return - V_53 ;
return V_54 & ( 1 << V_4 ) ;
}
static unsigned long F_29 ( unsigned long V_45 )
{
int V_55 ;
V_45 = ( V_45 - 1 ) >> ( V_49 - 1 ) ;
V_55 = V_49 - 1 ;
do {
V_45 >>= 1 ;
V_55 ++ ;
} while ( V_45 );
V_45 = 1 << V_55 ;
return V_45 ;
}
static int F_30 ( int V_4 , unsigned long V_44 , unsigned long V_45 )
{
struct V_56 * V_57 = & V_58 [ V_4 ] ;
int V_59 ;
V_45 = F_29 ( V_45 ) ;
F_31 ( & V_60 ) ;
V_57 -> V_61 = V_44 ;
V_57 -> V_62 = V_44 + V_45 - 1 ;
V_59 = F_32 ( & V_63 , V_57 ) ;
F_33 ( & V_60 ) ;
return V_59 ;
}
int F_34 ( int V_4 , unsigned long V_45 , unsigned long * V_44 )
{
struct V_56 * V_57 = & V_58 [ V_4 ] ;
int V_59 = - 1 ;
if ( V_4 > V_52 )
return - V_53 ;
V_45 = F_29 ( V_45 ) ;
if ( V_45 > ( 1 << V_47 ) )
return - V_64 ;
F_31 ( & V_60 ) ;
if ( F_28 ( V_4 ) ) {
V_59 = - V_65 ;
goto V_66;
}
if ( F_26 ( V_4 ) )
V_59 = F_35 ( V_57 , V_57 -> V_61 & ~ ( V_45 - 1 ) , V_45 ) ;
if ( V_59 < 0 )
V_59 = F_36 ( & V_63 , V_57 , V_45 , 0 , ~ 0 ,
V_45 , NULL , NULL ) ;
if ( V_59 < 0 )
goto V_66;
F_23 ( V_4 , V_57 -> V_61 , F_37 ( V_57 ) ) ;
* V_44 = V_57 -> V_61 ;
F_27 ( V_4 , 1 ) ;
V_66:
F_33 ( & V_60 ) ;
return V_59 ;
}
void F_38 ( int V_4 )
{
F_31 ( & V_60 ) ;
if ( V_4 >= V_52 || V_4 < 0 || ! F_28 ( V_4 ) ) {
F_13 ( V_67 L_3 , V_4 ) ;
F_39 () ;
F_33 ( & V_60 ) ;
return;
}
F_24 ( V_4 ) ;
F_40 ( & V_58 [ V_4 ] ) ;
F_27 ( V_4 , 0 ) ;
F_33 ( & V_60 ) ;
}
int F_41 ( int V_68 )
{
int V_69 = - V_70 ;
T_1 V_71 = 0 ;
switch ( V_68 ) {
case V_72 :
V_69 = F_3 ( V_73 ) ;
break;
case V_74 :
V_71 = F_3 ( V_75 ) ;
V_69 = F_42 ( V_71 ) ;
break;
case V_76 :
V_71 = F_3 ( V_75 ) ;
V_69 = F_43 ( V_71 ) ;
break;
case V_77 :
V_71 = F_3 ( V_78 ) ;
V_69 = V_71 & V_79 ;
break;
default:
F_13 ( V_67 L_4 ) ;
}
return V_69 ;
}
int F_44 ( int V_4 , int V_68 , int V_80 )
{
int V_81 = 0 ;
T_1 V_71 = 0 ;
switch ( V_68 ) {
case V_82 :
F_1 ( V_83 , V_80 ) ;
break;
case V_84 :
F_1 ( V_73 , V_80 ) ;
break;
case V_85 :
V_71 = F_3 ( V_86 ) ;
if ( V_80 )
V_71 &= ~ V_87 ;
else
V_71 |= V_87 ;
F_1 ( V_86 , V_71 ) ;
break;
case V_88 :
V_71 = F_10 ( V_4 , V_40 ) ;
if ( V_80 )
V_71 |= V_89 ;
else
V_71 &= ~ V_89 ;
F_9 ( V_4 , V_40 , V_71 ) ;
break;
case V_90 :
V_71 = F_10 ( V_4 , V_40 ) ;
V_71 |= F_45 ( V_80 ) ;
F_9 ( V_4 , V_40 , V_71 ) ;
break;
case V_91 :
V_71 = F_10 ( V_4 , V_40 ) ;
V_71 |= F_46 ( V_80 ) ;
if ( V_80 == V_92 )
V_71 |= V_93 ;
F_9 ( V_4 , V_40 , V_71 ) ;
break;
default:
F_13 ( V_67 L_5 ) ;
V_81 = - V_70 ;
}
return V_81 ;
}
int F_47 ( int V_4 , int V_68 )
{
int V_94 = - V_70 ;
switch ( V_68 ) {
case V_95 :
V_94 = F_7 ( V_4 , V_96 ) ;
break;
default:
F_13 ( V_67 L_6 ) ;
}
return V_94 ;
}
int F_48 ( int V_4 , int V_68 , int V_80 )
{
int V_81 = 0 ;
switch ( V_68 ) {
case V_97 :
F_5 ( V_4 , V_98 , V_80 ) ;
break;
case V_99 :
F_5 ( V_4 , V_100 , V_80 ) ;
break;
case V_95 :
F_5 ( V_4 , V_96 , V_80 ) ;
default:
F_13 ( V_67 L_7 ) ;
V_81 = - V_70 ;
}
return V_81 ;
}
int F_49 ( int V_4 , int V_101 , int V_102 ,
unsigned int V_103 , int V_104 )
{
if ( V_101 > V_105 ) {
F_50 ( L_8 ) ;
return - 1 ;
} else if ( ! ( F_3 ( V_106 ) ) ) {
F_1 ( V_107 , V_103 ) ;
F_1 ( V_108 , ( ( V_4 << V_109 ) |
F_51 ( V_101 ) |
V_110 |
( V_102 << V_111 ) |
( 0x1 & V_104 ) ) ) ;
F_1 ( V_106 , 0x1 ) ;
} else {
return - V_65 ;
}
return 0 ;
}
int F_52 ( int V_4 )
{
T_1 V_112 ;
V_112 = F_3 ( V_108 ) ;
if ( ( ( V_112 >> V_109 ) & 0x7 ) != V_4 )
return - V_70 ;
F_1 ( V_106 , 0x0 ) ;
F_1 ( V_108 , 0x0 ) ;
return 0 ;
}
static void T_4 F_53 ( void )
{
int V_4 ;
unsigned long V_113 = 0 ;
V_113 = V_114 ;
if ( F_54 () )
V_113 = 0 ;
V_63 . V_61 = V_115 + V_113 ;
V_63 . V_62 = V_116 ;
for ( V_4 = 0 ; V_4 < V_52 ; V_4 ++ ) {
T_1 V_44 , V_45 ;
if ( ! F_26 ( V_4 ) )
continue;
F_25 ( V_4 , & V_44 , & V_45 ) ;
if ( F_30 ( V_4 , V_44 , V_45 ) < 0 )
F_39 () ;
}
}
static int T_4 F_55 ( void )
{
T_1 V_16 , V_117 ;
int V_4 , V_118 = - V_70 ;
int V_119 ;
char * V_120 = NULL ;
if ( F_56 () ) {
V_120 = L_9 ;
if ( F_57 () )
V_16 = V_121 ;
else
V_16 = V_122 ;
V_119 = V_123 ;
} else if ( F_21 () ) {
V_120 = L_10 ;
V_16 = V_122 ;
V_119 = V_123 ;
} else if ( F_58 () ) {
V_120 = L_11 ;
V_16 = V_124 ;
V_119 = V_125 ;
}
if ( F_59 ( ! V_120 ) )
return V_118 ;
V_9 = F_60 ( NULL , V_120 ) ;
if ( F_61 ( V_9 ) ) {
F_13 ( V_67 L_12 , V_120 ) ;
F_39 () ;
}
V_3 = F_62 ( V_16 , V_126 ) ;
if ( ! V_3 ) {
F_63 ( V_9 ) ;
F_13 ( V_67 L_13 ) ;
F_39 () ;
}
F_64 ( V_9 ) ;
V_16 = F_3 ( V_127 ) ;
F_13 ( V_43 L_14 , ( V_16 >> 4 ) & 0x0f , V_16 & 0x0f ) ;
V_16 = F_3 ( V_128 ) ;
V_16 &= 0x03 << 3 ;
V_16 |= ( 0x02 << 3 ) | ( 1 << 0 ) ;
F_1 ( V_128 , V_16 ) ;
F_53 () ;
V_117 = V_129 ;
for ( V_4 = 0 ; V_4 < V_52 ; V_4 ++ ) {
F_65 ( V_117 , & V_130 ,
V_131 ) ;
F_66 ( V_117 , V_132 ) ;
V_117 ++ ;
}
V_118 = F_67 ( V_119 ,
V_133 , V_134 , L_15 , V_3 ) ;
if ( V_118 )
F_50 ( L_16 ,
V_119 , V_118 ) ;
return V_118 ;
}
static T_5 V_133 ( int V_117 , void * V_135 )
{
T_2 V_4 ;
V_4 = ( ( F_3 ( V_108 ) ) >> V_109 ) & 0x7 ;
if ( V_129 + V_4 <= V_136 )
F_68 ( V_129 + V_4 ) ;
return V_137 ;
}
void F_69 ( void )
{
int V_138 ;
V_139 . V_140 = F_3 ( V_128 ) ;
V_139 . V_141 = F_3 ( V_83 ) ;
V_139 . V_142 = F_3 ( V_143 ) ;
V_139 . V_144 = F_3 ( V_86 ) ;
V_139 . V_145 = F_3 ( V_108 ) ;
V_139 . V_146 = F_3 ( V_107 ) ;
V_139 . V_147 = F_3 ( V_106 ) ;
for ( V_138 = 0 ; V_138 < V_52 ; V_138 ++ ) {
V_139 . V_148 [ V_138 ] . V_149 = F_26 ( V_138 ) ;
if ( V_139 . V_148 [ V_138 ] . V_149 ) {
V_139 . V_148 [ V_138 ] . V_112 =
F_10 ( V_138 , V_40 ) ;
V_139 . V_148 [ V_138 ] . V_150 =
F_10 ( V_138 , V_19 ) ;
V_139 . V_148 [ V_138 ] . V_151 =
F_10 ( V_138 , V_23 ) ;
V_139 . V_148 [ V_138 ] . V_152 =
F_10 ( V_138 , V_27 ) ;
V_139 . V_148 [ V_138 ] . V_153 =
F_10 ( V_138 , V_32 ) ;
V_139 . V_148 [ V_138 ] . V_154 =
F_10 ( V_138 , V_37 ) ;
V_139 . V_148 [ V_138 ] . V_155 =
F_10 ( V_138 , V_48 ) ;
}
}
}
void F_70 ( void )
{
int V_138 ;
F_1 ( V_128 , V_139 . V_140 ) ;
F_1 ( V_83 , V_139 . V_141 ) ;
F_1 ( V_143 , V_139 . V_142 ) ;
F_1 ( V_86 , V_139 . V_144 ) ;
F_1 ( V_108 , V_139 . V_145 ) ;
F_1 ( V_107 , V_139 . V_146 ) ;
F_1 ( V_106 , V_139 . V_147 ) ;
for ( V_138 = 0 ; V_138 < V_52 ; V_138 ++ ) {
if ( V_139 . V_148 [ V_138 ] . V_149 ) {
F_9 ( V_138 , V_40 ,
V_139 . V_148 [ V_138 ] . V_112 ) ;
F_9 ( V_138 , V_19 ,
V_139 . V_148 [ V_138 ] . V_150 ) ;
F_9 ( V_138 , V_23 ,
V_139 . V_148 [ V_138 ] . V_151 ) ;
F_9 ( V_138 , V_27 ,
V_139 . V_148 [ V_138 ] . V_152 ) ;
F_9 ( V_138 , V_32 ,
V_139 . V_148 [ V_138 ] . V_153 ) ;
F_9 ( V_138 , V_37 ,
V_139 . V_148 [ V_138 ] . V_154 ) ;
F_9 ( V_138 , V_48 ,
V_139 . V_148 [ V_138 ] . V_155 ) ;
}
}
}
int F_71 ( int V_4 , int V_156 , int V_157 , int V_158 )
{
unsigned int V_2 ;
if ( V_159 != - V_70 )
return - V_70 ;
V_159 = V_4 ;
V_2 = ( ( 0x00000001 << 8 ) | 0x00000001 ) ;
F_1 ( V_160 , V_2 ) ;
V_2 = ( ( ( ( V_158 >> 1 ) - 1 ) << 22 ) | ( 0x0000000F ) ) ;
F_1 ( V_161 , V_2 ) ;
switch ( V_156 ) {
case V_162 :
F_1 ( V_160 , 0x101 ) ;
break;
case V_163 :
F_1 ( V_160 , 0x100 ) ;
break;
case V_164 :
F_1 ( V_160 , 0x101 ) ;
break;
default:
F_13 ( V_43 L_17 , V_156 ) ;
break;
}
V_2 = ( V_157 << 7 ) | ( V_4 << 1 ) | ( 0x1 ) ;
F_1 ( V_165 , V_2 ) ;
return 0 ;
}
int F_72 ( int V_4 , const T_6 * V_166 , T_6 * V_167 )
{
unsigned int V_2 = 0x0 ;
if ( V_159 != V_4 )
return - V_70 ;
V_2 = F_3 ( V_168 ) ;
* V_167 ++ = V_2 ;
* V_167 ++ = V_2 >> 16 ;
* V_167 ++ = ( ( V_2 >> 8 ) & 0x0f ) | ( ( V_2 >> 20 ) & 0xf0 ) ;
V_159 = - V_70 ;
return 0 ;
}
