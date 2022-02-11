static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 ;
unsigned int V_6 ;
for ( V_5 = V_7 ; V_5 < V_8 ; V_5 ++ )
if ( V_4 -> V_9 == V_10 [ V_5 ] . V_11 )
break;
if ( V_5 == V_8 )
return - V_12 ;
V_6 = V_2 -> V_13 [ V_5 ] ;
F_2 ( V_6 , V_14 ) ;
do {
V_6 = F_3 ( V_15 ) ;
} while ( V_6 & 0x11111111 );
V_6 = V_2 -> V_16 [ V_5 ] ;
F_2 ( V_6 , V_17 ) ;
do {
V_6 = F_3 ( V_18 ) ;
} while ( V_6 & 0x11111 );
V_6 = F_3 ( V_19 ) ;
V_6 &= ~ ( V_20 | V_21 ) ;
V_6 |= ( ( V_22 [ V_5 ] [ 0 ] <<
V_23 ) |
( V_22 [ V_5 ] [ 1 ] <<
V_24 ) ) ;
F_2 ( V_6 , V_19 ) ;
do {
V_6 = F_3 ( V_25 ) ;
} while ( V_6 & 0x11 );
V_6 = F_3 ( V_26 ) ;
V_6 &= ~ ( V_20 | V_21 ) ;
V_6 |= ( ( V_22 [ V_5 ] [ 0 ] <<
V_23 ) |
( V_22 [ V_5 ] [ 1 ] <<
V_24 ) ) ;
F_2 ( V_6 , V_26 ) ;
do {
V_6 = F_3 ( V_27 ) ;
} while ( V_6 & 0x11 );
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 ;
unsigned int V_6 ;
for ( V_5 = V_7 ; V_5 < V_28 ; V_5 ++ )
if ( V_4 -> V_9 == V_29 [ V_5 ] . V_11 )
break;
if ( V_5 == V_28 )
return - V_12 ;
V_6 = V_2 -> V_13 [ V_5 ] ;
F_2 ( V_6 , V_14 ) ;
do {
V_6 = F_3 ( V_15 ) ;
} while ( V_6 & 0x11111111 );
V_6 = F_3 ( V_30 ) ;
V_6 &= ~ ( V_31 |
V_32 |
V_33 ) ;
V_6 |= ( ( V_34 [ V_5 ] [ 0 ] <<
V_35 ) |
( V_34 [ V_5 ] [ 1 ] <<
V_36 ) |
( V_34 [ V_5 ] [ 2 ] <<
V_37 ) ) ;
F_2 ( V_6 , V_30 ) ;
do {
V_6 = F_3 ( V_38 ) ;
} while ( V_6 & 0x111111 );
V_6 = F_3 ( V_17 ) ;
V_6 &= ~ ( V_39 |
V_40 |
V_41 |
V_42 |
V_43 ) ;
V_6 |= ( ( V_44 [ V_5 ] [ 0 ] <<
V_45 ) |
( V_44 [ V_5 ] [ 1 ] <<
V_46 ) |
( V_44 [ V_5 ] [ 2 ] <<
V_47 ) |
( V_44 [ V_5 ] [ 3 ] <<
V_48 ) |
( V_44 [ V_5 ] [ 4 ] <<
V_49 ) ) ;
F_2 ( V_6 , V_17 ) ;
do {
V_6 = F_3 ( V_18 ) ;
} while ( V_6 & 0x11111 );
V_6 = F_3 ( V_19 ) ;
V_6 &= ~ ( V_20 | V_21 ) ;
V_6 |= ( ( V_50 [ V_5 ] [ 0 ] <<
V_23 ) |
( V_50 [ V_5 ] [ 1 ] <<
V_24 ) ) ;
F_2 ( V_6 , V_19 ) ;
do {
V_6 = F_3 ( V_25 ) ;
} while ( V_6 & 0x11 );
V_6 = F_3 ( V_26 ) ;
V_6 &= ~ ( V_20 | V_21 ) ;
V_6 |= ( ( V_50 [ V_5 ] [ 0 ] <<
V_23 ) |
( V_50 [ V_5 ] [ 1 ] <<
V_24 ) ) ;
F_2 ( V_6 , V_26 ) ;
do {
V_6 = F_3 ( V_27 ) ;
} while ( V_6 & 0x11 );
V_6 = F_3 ( V_51 ) ;
V_6 &= ~ ( V_52 ) ;
V_6 |= ( ( V_53 [ V_5 ] [ 0 ] <<
V_54 ) ) ;
F_2 ( V_6 , V_51 ) ;
do {
V_6 = F_3 ( V_55 ) ;
} while ( V_6 & 0x1 );
V_6 = F_3 ( V_56 ) ;
V_6 &= ~ ( V_57 ) ;
V_6 |= ( ( V_53 [ V_5 ] [ 1 ] <<
V_58 ) ) ;
F_2 ( V_6 , V_56 ) ;
do {
V_6 = F_3 ( V_59 ) ;
} while ( V_6 & 0x1 );
V_6 = F_3 ( V_60 ) ;
V_6 &= ~ ( V_61 | V_62 |
V_63 | V_64 ) ;
V_6 |= ( ( V_53 [ V_5 ] [ 2 ] <<
V_65 ) |
( V_53 [ V_5 ] [ 2 ] <<
V_66 ) |
( V_53 [ V_5 ] [ 2 ] <<
V_67 ) |
( V_53 [ V_5 ] [ 2 ] <<
V_68 ) ) ;
F_2 ( V_6 , V_60 ) ;
do {
V_6 = F_3 ( V_59 ) ;
} while ( V_6 & 0x1111 );
return 0 ;
}
static int F_5 ( unsigned long V_69 )
{
int V_70 = 0 ;
while ( V_71 [ V_70 ] . V_11 ) {
if ( V_71 [ V_70 ] . V_11 <= V_69 )
return V_70 ;
V_70 ++ ;
}
return - V_12 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_72 )
{
int V_73 = 0 , V_6 ;
unsigned long V_74 = V_4 -> V_74 ;
switch ( V_2 -> type ) {
case V_75 :
V_73 = F_7 ( V_2 -> V_76 , V_74 ,
V_77 ) ;
break;
case V_78 :
V_73 = F_7 ( V_2 -> V_79 , V_74 ,
V_77 ) ;
if ( V_73 )
break;
V_6 = F_5 ( V_4 -> V_9 ) ;
if ( V_6 < 0 ) {
V_73 = V_6 ;
F_7 ( V_2 -> V_79 ,
V_72 -> V_74 ,
V_77 ) ;
break;
}
V_73 = F_7 ( V_2 -> V_76 ,
V_71 [ V_6 ] . V_74 ,
V_77 ) ;
if ( V_73 )
F_7 ( V_2 -> V_79 ,
V_72 -> V_74 ,
V_77 ) ;
break;
default:
V_73 = - V_12 ;
}
return V_73 ;
}
static int F_8 ( struct V_80 * V_81 , unsigned long * V_82 ,
T_1 V_83 )
{
int V_73 = 0 ;
struct V_84 * V_85 = F_9 ( V_81 , struct V_84 ,
V_81 ) ;
struct V_1 * V_2 = F_10 ( V_85 ) ;
struct V_86 * V_87 ;
unsigned long V_88 ;
unsigned long V_89 = V_2 -> V_90 . V_9 ;
struct V_3 V_91 ;
F_11 () ;
V_87 = F_12 ( V_81 , V_82 , V_83 ) ;
if ( F_13 ( V_87 ) ) {
F_14 () ;
return F_15 ( V_87 ) ;
}
V_91 . V_9 = F_16 ( V_87 ) ;
V_91 . V_74 = F_17 ( V_87 ) ;
F_14 () ;
V_88 = V_91 . V_9 ;
if ( V_89 == V_88 )
return 0 ;
F_18 ( V_81 , L_1 , V_88 , V_91 . V_74 ) ;
F_19 ( & V_2 -> V_92 ) ;
if ( V_2 -> V_93 )
goto V_94;
if ( V_89 < V_88 )
V_73 = F_6 ( V_2 , & V_91 ,
& V_2 -> V_90 ) ;
if ( V_73 )
goto V_94;
if ( V_89 != V_88 ) {
switch ( V_2 -> type ) {
case V_75 :
V_73 = F_1 ( V_2 , & V_91 ) ;
break;
case V_78 :
V_73 = F_4 ( V_2 , & V_91 ) ;
break;
default:
V_73 = - V_12 ;
}
}
if ( V_73 )
goto V_94;
if ( V_89 > V_88 )
V_73 = F_6 ( V_2 , & V_91 ,
& V_2 -> V_90 ) ;
if ( V_73 )
goto V_94;
V_2 -> V_90 = V_91 ;
V_94:
F_20 ( & V_2 -> V_92 ) ;
return V_73 ;
}
static int F_21 ( struct V_80 * V_81 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = F_22 ( V_81 ) ;
struct V_97 * V_98 = & V_2 -> V_98 ;
int V_99 ;
F_23 ( V_98 ) ;
V_99 = F_24 ( V_98 ) ;
V_96 -> V_100 = V_2 -> V_90 . V_9 ;
V_96 -> V_101 = V_98 -> V_102 [ V_99 ] . V_103 [ V_104 ] ;
V_96 -> V_101 *= 100 / V_105 ;
V_96 -> V_106 = V_98 -> V_102 [ V_99 ] . V_107 ;
if ( V_98 -> V_102 [ V_99 ] . V_108 ||
V_98 -> V_102 [ V_99 ] . V_109 [ 0 ] )
return - V_110 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_1 V_6 ;
int V_111 ;
int V_70 , V_73 = 0 ;
V_6 = F_3 ( V_14 ) ;
for ( V_70 = V_7 ; V_70 < V_8 ; V_70 ++ ) {
V_6 &= ~ ( V_112 |
V_113 |
V_114 |
V_115 |
V_116 |
V_117 |
V_118 |
V_119 ) ;
V_6 |= ( ( V_120 [ V_70 ] [ 0 ] <<
V_121 ) |
( V_120 [ V_70 ] [ 1 ] <<
V_122 ) |
( V_120 [ V_70 ] [ 2 ] <<
V_123 ) |
( V_120 [ V_70 ] [ 3 ] <<
V_124 ) |
( V_120 [ V_70 ] [ 4 ] <<
V_125 ) |
( V_120 [ V_70 ] [ 5 ] <<
V_126 ) |
( V_120 [ V_70 ] [ 6 ] <<
V_127 ) |
( V_120 [ V_70 ] [ 7 ] <<
V_128 ) ) ;
V_2 -> V_13 [ V_70 ] = V_6 ;
}
V_6 = F_3 ( V_17 ) ;
for ( V_70 = V_7 ; V_70 < V_8 ; V_70 ++ ) {
V_6 &= ~ ( V_129 |
V_40 |
V_41 |
V_42 |
V_43 ) ;
V_6 |= ( ( V_130 [ V_70 ] [ 0 ] <<
V_131 ) |
( V_130 [ V_70 ] [ 1 ] <<
V_46 ) |
( V_130 [ V_70 ] [ 2 ] <<
V_47 ) |
( V_130 [ V_70 ] [ 3 ] <<
V_48 ) |
( V_130 [ V_70 ] [ 4 ] <<
V_49 ) ) ;
V_2 -> V_16 [ V_70 ] = V_6 ;
}
V_6 = 0 ;
F_26 ( L_2 , V_6 ) ;
switch ( V_6 ) {
case 0 :
V_111 = 0 ;
break;
case 1 :
case 2 :
V_111 = 1 ;
break;
case 3 :
case 4 :
V_111 = 2 ;
break;
case 5 :
case 6 :
V_111 = 3 ;
break;
case 7 :
V_111 = 4 ;
break;
default:
F_27 ( L_3 ) ;
V_111 = 0 ;
}
for ( V_70 = V_7 ; V_70 < V_8 ; V_70 ++ )
V_10 [ V_70 ] . V_74 = V_132 [ V_111 ] [ V_70 ] ;
for ( V_70 = V_7 ; V_70 < V_8 ; V_70 ++ ) {
V_73 = F_28 ( V_2 -> V_81 , V_10 [ V_70 ] . V_11 ,
V_10 [ V_70 ] . V_74 ) ;
if ( V_73 ) {
F_29 ( V_2 -> V_81 , L_4 ) ;
return V_73 ;
}
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
unsigned int V_70 ;
unsigned int V_6 ;
int V_133 ;
V_6 = F_3 ( V_134 ) ;
V_6 |= V_135 ;
F_2 ( V_6 , V_134 ) ;
V_6 = F_3 ( V_14 ) ;
for ( V_70 = 0 ; V_70 < V_28 ; V_70 ++ ) {
V_6 &= ~ ( V_112 |
V_113 |
V_114 |
V_115 |
V_116 |
V_117 ) ;
V_6 |= ( ( V_136 [ V_70 ] [ 0 ] <<
V_121 ) |
( V_136 [ V_70 ] [ 1 ] <<
V_122 ) |
( V_136 [ V_70 ] [ 2 ] <<
V_123 ) |
( V_136 [ V_70 ] [ 3 ] <<
V_124 ) |
( V_136 [ V_70 ] [ 4 ] <<
V_125 ) |
( V_136 [ V_70 ] [ 5 ] <<
V_126 ) ) ;
V_2 -> V_13 [ V_70 ] = V_6 ;
}
V_6 = 0 ;
if ( V_6 > 8 )
V_6 = 0 ;
F_26 ( L_5 , V_6 ) ;
for ( V_70 = 0 ; V_70 < V_28 ; V_70 ++ ) {
V_29 [ V_70 ] . V_74 =
V_137 [ V_6 ] [ V_70 ] ;
V_71 [ V_70 ] . V_74 =
V_138 [ V_6 ] [ V_70 ] ;
}
for ( V_70 = 0 ; V_70 < V_28 ; V_70 ++ ) {
V_133 = F_28 ( V_2 -> V_81 , V_29 [ V_70 ] . V_11 ,
V_29 [ V_70 ] . V_74 ) ;
if ( V_133 ) {
F_29 ( V_2 -> V_81 , L_6 ) ;
return V_133 ;
}
}
return 0 ;
}
static int F_31 ( struct V_139 * V_140 ,
unsigned long V_141 , void * V_142 )
{
struct V_1 * V_2 = F_9 ( V_140 , struct V_1 ,
V_143 ) ;
struct V_86 * V_87 ;
struct V_3 V_91 ;
unsigned long V_144 = V_145 ;
int V_73 = 0 ;
switch ( V_141 ) {
case V_146 :
F_19 ( & V_2 -> V_92 ) ;
V_2 -> V_93 = true ;
F_11 () ;
V_87 = F_32 ( V_2 -> V_81 , & V_144 ) ;
if ( F_13 ( V_87 ) ) {
F_14 () ;
F_29 ( V_2 -> V_81 , L_7 ,
V_147 ) ;
F_20 ( & V_2 -> V_92 ) ;
return F_15 ( V_87 ) ;
}
V_91 . V_9 = F_16 ( V_87 ) ;
V_91 . V_74 = F_17 ( V_87 ) ;
F_14 () ;
V_73 = F_6 ( V_2 , & V_91 ,
& V_2 -> V_90 ) ;
if ( V_73 )
goto V_148;
switch ( V_2 -> type ) {
case V_75 :
V_73 = F_1 ( V_2 , & V_91 ) ;
break;
case V_78 :
V_73 = F_4 ( V_2 , & V_91 ) ;
break;
default:
V_73 = - V_12 ;
}
if ( V_73 )
goto V_148;
V_2 -> V_90 = V_91 ;
V_148:
F_20 ( & V_2 -> V_92 ) ;
if ( V_73 )
return V_73 ;
return V_149 ;
case V_150 :
case V_151 :
F_19 ( & V_2 -> V_92 ) ;
V_2 -> V_93 = false ;
F_20 ( & V_2 -> V_92 ) ;
return V_149 ;
}
return V_152 ;
}
static int F_33 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
struct V_97 * V_98 ;
struct V_86 * V_87 ;
struct V_80 * V_81 = & V_85 -> V_81 ;
int V_73 = 0 ;
V_2 = F_34 ( & V_85 -> V_81 , sizeof( struct V_1 ) , V_153 ) ;
if ( V_2 == NULL ) {
F_29 ( V_81 , L_8 ) ;
return - V_154 ;
}
V_98 = & V_2 -> V_98 ;
V_98 -> V_155 = V_156 ;
V_98 -> V_102 = F_34 ( V_81 ,
sizeof( struct V_157 ) * V_156 ,
V_153 ) ;
if ( ! V_98 -> V_102 ) {
F_29 ( V_81 , L_9 ) ;
return - V_154 ;
}
V_2 -> type = V_85 -> V_158 -> V_159 ;
V_98 -> V_102 [ V_160 ] . V_161 = V_162 ;
V_98 -> V_102 [ V_163 ] . V_161 = V_164 ;
V_2 -> V_143 . V_165 = F_31 ;
V_2 -> V_81 = V_81 ;
F_35 ( & V_2 -> V_92 ) ;
switch ( V_2 -> type ) {
case V_75 :
V_73 = F_25 ( V_2 ) ;
break;
case V_78 :
V_73 = F_30 ( V_2 ) ;
break;
default:
F_29 ( V_81 , L_10 , V_2 -> type ) ;
V_73 = - V_12 ;
}
if ( V_73 ) {
F_29 ( V_81 , L_11 ,
V_2 -> type ) ;
return V_73 ;
}
V_2 -> V_76 = F_36 ( V_81 , L_12 ) ;
if ( F_13 ( V_2 -> V_76 ) ) {
F_29 ( V_81 , L_13 ) ;
return F_15 ( V_2 -> V_76 ) ;
}
if ( V_2 -> type == V_78 ) {
V_2 -> V_79 = F_36 ( V_81 , L_14 ) ;
if ( F_13 ( V_2 -> V_79 ) ) {
F_29 ( V_81 , L_15 ) ;
return F_15 ( V_2 -> V_79 ) ;
}
}
F_11 () ;
V_87 = F_32 ( V_81 ,
& V_166 . V_167 ) ;
if ( F_13 ( V_87 ) ) {
F_14 () ;
F_29 ( V_81 , L_16 ,
V_166 . V_167 ) ;
return F_15 ( V_87 ) ;
}
V_2 -> V_90 . V_9 = F_16 ( V_87 ) ;
V_2 -> V_90 . V_74 = F_17 ( V_87 ) ;
F_14 () ;
F_37 ( V_85 , V_2 ) ;
V_2 -> V_168 = F_38 ( V_81 , & V_166 ,
L_17 , NULL ) ;
if ( F_13 ( V_2 -> V_168 ) )
return F_15 ( V_2 -> V_168 ) ;
F_39 ( V_98 ) ;
V_73 = F_40 ( V_81 , V_2 -> V_168 ) ;
if ( V_73 < 0 ) {
F_29 ( V_81 , L_18 ) ;
return V_73 ;
}
V_73 = F_41 ( & V_2 -> V_143 ) ;
if ( V_73 ) {
F_29 ( V_81 , L_19 ) ;
return V_73 ;
}
return 0 ;
}
static int F_42 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = F_10 ( V_85 ) ;
F_43 ( & V_2 -> V_143 ) ;
return 0 ;
}
static int F_44 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_22 ( V_81 ) ;
struct V_97 * V_98 = & V_2 -> V_98 ;
F_39 ( V_98 ) ;
return 0 ;
}
static int T_2 F_45 ( void )
{
return F_46 ( & V_169 ) ;
}
static void T_3 F_47 ( void )
{
F_48 ( & V_169 ) ;
}
