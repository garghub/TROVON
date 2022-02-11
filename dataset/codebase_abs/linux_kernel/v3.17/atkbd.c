static bool F_1 ( unsigned long V_1 , unsigned char V_2 )
{
int V_3 ;
if ( V_2 == V_4 || V_2 == V_5 )
return false ;
for ( V_3 = 0 ; V_3 < F_2 ( V_6 ) ; V_3 ++ )
if ( V_2 == V_6 [ V_3 ] )
return F_3 ( V_3 , & V_1 ) ;
return true ;
}
static void F_4 ( struct V_7 * V_7 , unsigned char V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_6 ) ; V_3 ++ ) {
if ( ! ( ( V_2 ^ V_6 [ V_3 ] ) & 0x7f ) ) {
if ( V_2 & 0x80 )
F_5 ( V_3 , & V_7 -> V_1 ) ;
else
F_6 ( V_3 , & V_7 -> V_1 ) ;
break;
}
}
}
static unsigned int F_7 ( struct V_7 * V_7 , unsigned int V_2 )
{
if ( V_7 -> V_8 == 3 ) {
if ( V_7 -> V_9 == 1 )
V_2 |= 0x100 ;
} else {
V_2 = ( V_2 & 0x7f ) | ( ( V_2 & 0x80 ) << 1 ) ;
if ( V_7 -> V_9 == 1 )
V_2 |= 0x80 ;
}
return V_2 ;
}
static T_1 F_8 ( struct V_10 * V_10 , unsigned char V_11 ,
unsigned int V_12 )
{
struct V_7 * V_7 = F_9 ( V_10 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
unsigned int V_2 = V_11 ;
int V_15 = 0 , V_16 = 0 , V_17 = - 1 ;
int V_18 ;
unsigned short V_19 ;
F_10 ( & V_10 -> V_14 , L_1 , V_11 , V_12 ) ;
#if ! F_11 ( V_20 ) && ! F_11 ( V_21 )
if ( ( V_12 & ( V_22 | V_23 ) ) && ( ~ V_12 & V_24 ) && ! V_7 -> V_25 && V_7 -> V_26 ) {
F_12 ( & V_10 -> V_14 , L_2 , V_12 ) ;
F_13 ( V_10 , V_27 ) ;
V_7 -> V_25 = true ;
goto V_28;
}
if ( ! V_12 && V_11 == V_29 )
V_7 -> V_25 = false ;
#endif
if ( F_14 ( V_7 -> V_30 . V_12 & V_31 ) )
if ( F_15 ( & V_7 -> V_30 , V_11 ) )
goto V_28;
if ( F_14 ( V_7 -> V_30 . V_12 & V_32 ) )
if ( F_16 ( & V_7 -> V_30 , V_11 ) )
goto V_28;
if ( ! V_7 -> V_33 )
goto V_28;
F_17 ( V_14 , V_34 , V_35 , V_2 ) ;
if ( V_36 )
V_2 = V_36 ( V_7 , V_2 ) ;
if ( V_7 -> V_37 ) {
if ( V_7 -> V_9 || F_1 ( V_7 -> V_1 , V_2 ) ) {
V_7 -> V_38 = V_2 >> 7 ;
V_2 &= 0x7f ;
}
if ( ! V_7 -> V_9 )
F_4 ( V_7 , V_11 ) ;
}
switch ( V_2 ) {
case V_39 :
V_7 -> V_33 = false ;
F_18 ( V_7 -> V_30 . V_10 ) ;
goto V_28;
case V_4 :
V_7 -> V_9 = 1 ;
goto V_28;
case V_5 :
V_7 -> V_9 = 2 ;
goto V_28;
case V_40 :
V_7 -> V_38 = true ;
goto V_28;
case V_29 :
case V_41 :
if ( F_19 () )
F_12 ( & V_10 -> V_14 ,
L_3
L_4 ,
V_11 == V_29 ? L_5 : L_6 , V_10 -> V_42 ) ;
goto V_28;
case V_43 :
V_7 -> V_44 ++ ;
F_10 ( & V_10 -> V_14 , L_7 ,
V_10 -> V_42 ) ;
goto V_28;
}
V_2 = F_7 ( V_7 , V_2 ) ;
if ( V_7 -> V_9 && -- V_7 -> V_9 )
goto V_28;
V_19 = V_7 -> V_19 [ V_2 ] ;
if ( V_19 != V_45 )
F_17 ( V_14 , V_34 , V_46 , V_2 ) ;
switch ( V_19 ) {
case V_45 :
break;
case V_47 :
F_12 ( & V_10 -> V_14 ,
L_8 ,
V_7 -> V_38 ? L_9 : L_10 ,
V_7 -> V_37 ? L_11 : L_12 ,
V_7 -> V_8 , V_2 , V_10 -> V_42 ) ;
F_12 ( & V_10 -> V_14 ,
L_13 ,
V_2 & 0x80 ? L_14 : L_15 , V_2 & 0x7f ) ;
F_20 ( V_14 ) ;
break;
case V_48 :
V_15 = 1 ;
break;
case V_49 :
V_15 = 2 ;
break;
case V_50 :
V_15 = 4 ;
break;
case V_51 :
V_15 = 8 ;
break;
case V_52 :
V_17 = ! V_7 -> V_38 ;
break;
case V_53 :
V_16 = - 1 ;
break;
case V_54 :
V_16 = 1 ;
break;
default:
if ( V_7 -> V_38 ) {
V_18 = 0 ;
V_7 -> V_55 = 0 ;
} else if ( ! V_7 -> V_56 && F_3 ( V_19 , V_14 -> V_57 ) ) {
V_18 = F_21 ( V_58 , V_7 -> time ) && V_7 -> V_55 == V_2 ? 1 : 2 ;
} else {
V_18 = 1 ;
V_7 -> V_55 = V_2 ;
V_7 -> time = V_58 + F_22 ( V_14 -> V_59 [ V_60 ] ) / 2 ;
}
F_17 ( V_14 , V_61 , V_19 , V_18 ) ;
F_20 ( V_14 ) ;
if ( V_18 && F_3 ( V_2 , V_7 -> V_62 ) ) {
F_23 ( V_14 , V_19 , 0 ) ;
F_20 ( V_14 ) ;
}
}
if ( V_7 -> V_15 ) {
if ( V_17 != - 1 )
F_23 ( V_14 , V_63 , V_17 ) ;
F_24 ( V_14 , V_64 ,
V_7 -> V_38 ? - V_15 : V_15 ) ;
F_24 ( V_14 , V_65 , V_16 ) ;
F_20 ( V_14 ) ;
}
V_7 -> V_38 = false ;
V_28:
return V_66 ;
}
static int F_25 ( struct V_7 * V_7 )
{
const short V_67 [ 32 ] =
{ 33 , 37 , 42 , 46 , 50 , 54 , 58 , 63 , 67 , 75 , 83 , 92 , 100 , 109 , 116 , 125 ,
133 , 149 , 167 , 182 , 200 , 217 , 232 , 250 , 270 , 303 , 333 , 370 , 400 , 435 , 470 , 500 } ;
const short V_68 [ 4 ] =
{ 250 , 500 , 750 , 1000 } ;
struct V_13 * V_14 = V_7 -> V_14 ;
unsigned char V_69 ;
int V_3 = 0 , V_70 = 0 ;
while ( V_3 < F_2 ( V_67 ) - 1 && V_67 [ V_3 ] < V_14 -> V_59 [ V_71 ] )
V_3 ++ ;
V_14 -> V_59 [ V_71 ] = V_67 [ V_3 ] ;
while ( V_70 < F_2 ( V_68 ) - 1 && V_68 [ V_70 ] < V_14 -> V_59 [ V_60 ] )
V_70 ++ ;
V_14 -> V_59 [ V_60 ] = V_68 [ V_70 ] ;
V_69 = V_3 | ( V_70 << 5 ) ;
return F_26 ( & V_7 -> V_30 , & V_69 , V_72 ) ;
}
static int F_27 ( struct V_7 * V_7 )
{
struct V_13 * V_14 = V_7 -> V_14 ;
unsigned char V_69 [ 2 ] ;
V_69 [ 0 ] = ( F_3 ( V_73 , V_14 -> V_74 ) ? 1 : 0 )
| ( F_3 ( V_75 , V_14 -> V_74 ) ? 2 : 0 )
| ( F_3 ( V_76 , V_14 -> V_74 ) ? 4 : 0 ) ;
if ( F_26 ( & V_7 -> V_30 , V_69 , V_77 ) )
return - 1 ;
if ( V_7 -> V_78 ) {
V_69 [ 0 ] = 0 ;
V_69 [ 1 ] = ( F_3 ( V_79 , V_14 -> V_74 ) ? 0x01 : 0 )
| ( F_3 ( V_80 , V_14 -> V_74 ) ? 0x02 : 0 )
| ( F_3 ( V_81 , V_14 -> V_74 ) ? 0x04 : 0 )
| ( F_3 ( V_82 , V_14 -> V_74 ) ? 0x10 : 0 )
| ( F_3 ( V_83 , V_14 -> V_74 ) ? 0x20 : 0 ) ;
if ( F_26 ( & V_7 -> V_30 , V_69 , V_84 ) )
return - 1 ;
}
return 0 ;
}
static void F_28 ( struct V_85 * V_86 )
{
struct V_7 * V_7 = F_29 ( V_86 , struct V_7 , V_87 . V_86 ) ;
F_30 ( & V_7 -> V_88 ) ;
if ( ! V_7 -> V_33 ) {
F_31 ( & V_7 -> V_87 ,
F_22 ( 100 ) ) ;
} else {
if ( F_32 ( V_89 , & V_7 -> V_90 ) )
F_27 ( V_7 ) ;
if ( F_32 ( V_91 , & V_7 -> V_90 ) )
F_25 ( V_7 ) ;
}
F_33 ( & V_7 -> V_88 ) ;
}
static void F_34 ( struct V_7 * V_7 , int V_92 )
{
unsigned long V_68 = F_22 ( 50 ) ;
if ( F_35 ( V_58 , V_7 -> V_93 + V_68 ) )
V_68 = 0 ;
V_7 -> V_93 = V_58 ;
F_36 ( V_92 , & V_7 -> V_90 ) ;
F_37 () ;
F_31 ( & V_7 -> V_87 , V_68 ) ;
}
static int F_38 ( struct V_13 * V_14 ,
unsigned int type , unsigned int V_2 , int V_18 )
{
struct V_7 * V_7 = F_39 ( V_14 ) ;
if ( ! V_7 -> V_26 )
return - 1 ;
switch ( type ) {
case V_94 :
F_34 ( V_7 , V_89 ) ;
return 0 ;
case V_95 :
if ( ! V_7 -> V_56 )
F_34 ( V_7 , V_91 ) ;
return 0 ;
default:
return - 1 ;
}
}
static inline void F_40 ( struct V_7 * V_7 )
{
F_41 ( V_7 -> V_30 . V_10 ) ;
V_7 -> V_33 = true ;
F_42 ( V_7 -> V_30 . V_10 ) ;
}
static inline void F_43 ( struct V_7 * V_7 )
{
F_41 ( V_7 -> V_30 . V_10 ) ;
V_7 -> V_33 = false ;
F_42 ( V_7 -> V_30 . V_10 ) ;
}
static int F_44 ( struct V_7 * V_7 )
{
struct V_30 * V_30 = & V_7 -> V_30 ;
if ( F_26 ( V_30 , NULL , V_96 ) ) {
F_45 ( & V_30 -> V_10 -> V_14 ,
L_16 ,
V_30 -> V_10 -> V_42 ) ;
return - 1 ;
}
return 0 ;
}
static void F_46 ( struct V_7 * V_7 )
{
struct V_30 * V_30 = & V_7 -> V_30 ;
if ( F_26 ( V_30 , NULL , V_97 ) )
F_45 ( & V_30 -> V_10 -> V_14 ,
L_17 ,
V_30 -> V_10 -> V_42 ) ;
}
static int F_47 ( struct V_7 * V_7 )
{
struct V_30 * V_30 = & V_7 -> V_30 ;
unsigned char V_69 [ 2 ] ;
if ( V_98 )
if ( F_26 ( V_30 , NULL , V_99 ) )
F_12 ( & V_30 -> V_10 -> V_14 ,
L_18 ,
V_30 -> V_10 -> V_42 ) ;
V_69 [ 0 ] = V_69 [ 1 ] = 0xa5 ;
if ( F_26 ( V_30 , V_69 , V_100 ) ) {
V_69 [ 0 ] = 0 ;
if ( F_26 ( V_30 , V_69 , V_77 ) )
return - 1 ;
V_7 -> V_101 = 0xabba ;
return 0 ;
}
if ( ! F_48 ( V_69 [ 0 ] ) )
return - 1 ;
V_7 -> V_101 = ( V_69 [ 0 ] << 8 ) | V_69 [ 1 ] ;
if ( V_7 -> V_101 == 0xaca1 && V_7 -> V_37 ) {
F_45 ( & V_30 -> V_10 -> V_14 ,
L_19
L_20 ) ;
return - 1 ;
}
if ( ! V_102 )
F_46 ( V_7 ) ;
return 0 ;
}
static int F_49 ( struct V_7 * V_7 , int V_103 , int V_104 )
{
struct V_30 * V_30 = & V_7 -> V_30 ;
unsigned char V_69 [ 2 ] ;
V_7 -> V_78 = false ;
if ( V_7 -> V_37 )
return 2 ;
if ( V_7 -> V_101 == 0xaca1 ) {
V_69 [ 0 ] = 3 ;
F_26 ( V_30 , V_69 , V_105 ) ;
return 3 ;
}
if ( V_104 ) {
V_69 [ 0 ] = 0x71 ;
if ( ! F_26 ( V_30 , V_69 , V_106 ) ) {
V_7 -> V_78 = true ;
return 2 ;
}
}
if ( V_107 ) {
F_26 ( V_30 , V_69 , V_108 ) ;
return 3 ;
}
if ( V_103 != 3 )
return 2 ;
if ( ! F_26 ( V_30 , V_69 , V_109 ) ) {
V_7 -> V_101 = V_69 [ 0 ] << 8 | V_69 [ 1 ] ;
return 2 ;
}
V_69 [ 0 ] = 3 ;
if ( F_26 ( V_30 , V_69 , V_105 ) )
return 2 ;
V_69 [ 0 ] = 0 ;
if ( F_26 ( V_30 , V_69 , V_110 ) )
return 2 ;
if ( V_69 [ 0 ] != 3 ) {
V_69 [ 0 ] = 2 ;
if ( F_26 ( V_30 , V_69 , V_105 ) )
return 2 ;
}
F_26 ( V_30 , V_69 , V_111 ) ;
return 3 ;
}
static int F_50 ( struct V_7 * V_7 )
{
struct V_30 * V_30 = & V_7 -> V_30 ;
unsigned char V_69 [ 1 ] ;
V_69 [ 0 ] = 0 ;
if ( F_26 ( V_30 , V_69 , V_77 ) )
return - 1 ;
V_69 [ 0 ] = 0 ;
if ( F_26 ( V_30 , V_69 , V_72 ) )
return - 1 ;
return 0 ;
}
static void F_51 ( struct V_10 * V_10 )
{
struct V_7 * V_7 = F_9 ( V_10 ) ;
F_43 ( V_7 ) ;
F_26 ( & V_7 -> V_30 , NULL , V_112 ) ;
}
static void F_52 ( struct V_10 * V_10 )
{
struct V_7 * V_7 = F_9 ( V_10 ) ;
F_53 ( & V_10 -> V_14 . V_113 , & V_114 ) ;
F_43 ( V_7 ) ;
F_54 ( V_7 -> V_14 ) ;
F_55 ( & V_7 -> V_87 ) ;
F_56 ( V_10 ) ;
F_57 ( V_10 , NULL ) ;
F_58 ( V_7 ) ;
}
static void F_59 ( struct V_7 * V_7 ,
const void * V_11 )
{
const unsigned int * V_115 = V_11 ;
unsigned int V_3 ;
if ( V_7 -> V_8 == 2 )
for ( V_3 = 0 ; V_115 [ V_3 ] != - 1U ; V_3 ++ )
F_6 ( V_115 [ V_3 ] , V_7 -> V_62 ) ;
}
static unsigned int F_60 ( struct V_7 * V_7 ,
unsigned int V_2 )
{
if ( V_7 -> V_37 && V_7 -> V_9 == 1 &&
( V_2 == 0x64 || V_2 == 0x65 || V_2 == 0x66 ) ) {
V_7 -> V_9 = 0 ;
V_2 |= 0x80 ;
}
return V_2 ;
}
static void F_61 ( struct V_7 * V_7 )
{
unsigned int V_116 ;
int V_3 , V_70 ;
memset ( V_7 -> V_19 , 0 , sizeof( V_7 -> V_19 ) ) ;
F_62 ( V_7 -> V_62 , V_117 ) ;
if ( V_7 -> V_37 ) {
for ( V_3 = 0 ; V_3 < 128 ; V_3 ++ ) {
V_116 = V_118 [ V_3 ] ;
V_7 -> V_19 [ V_3 ] = V_119 [ V_116 ] ;
V_7 -> V_19 [ V_3 | 0x80 ] = V_119 [ V_116 | 0x80 ] ;
if ( V_7 -> V_15 )
for ( V_70 = 0 ; V_70 < F_2 ( V_120 ) ; V_70 ++ )
if ( ( V_116 | 0x80 ) == V_120 [ V_70 ] . V_121 )
V_7 -> V_19 [ V_3 | 0x80 ] = V_120 [ V_70 ] . V_19 ;
}
} else if ( V_7 -> V_8 == 3 ) {
memcpy ( V_7 -> V_19 , V_122 , sizeof( V_7 -> V_19 ) ) ;
} else {
memcpy ( V_7 -> V_19 , V_119 , sizeof( V_7 -> V_19 ) ) ;
if ( V_7 -> V_15 )
for ( V_3 = 0 ; V_3 < F_2 ( V_120 ) ; V_3 ++ ) {
V_116 = V_120 [ V_3 ] . V_121 ;
V_7 -> V_19 [ V_116 ] = V_120 [ V_3 ] . V_19 ;
}
}
V_116 = F_7 ( V_7 , V_123 ) ;
V_7 -> V_19 [ V_116 ] = V_124 ;
F_6 ( V_116 , V_7 -> V_62 ) ;
V_116 = F_7 ( V_7 , V_125 ) ;
V_7 -> V_19 [ V_116 ] = V_126 ;
F_6 ( V_116 , V_7 -> V_62 ) ;
if ( V_127 )
V_127 ( V_7 , V_128 ) ;
}
static void F_63 ( struct V_7 * V_7 )
{
struct V_13 * V_13 = V_7 -> V_14 ;
int V_3 ;
if ( V_7 -> V_78 )
snprintf ( V_7 -> V_129 , sizeof( V_7 -> V_129 ) ,
L_21 ) ;
else
snprintf ( V_7 -> V_129 , sizeof( V_7 -> V_129 ) ,
L_22 ,
V_7 -> V_37 ? L_23 : L_24 , V_7 -> V_8 ) ;
snprintf ( V_7 -> V_42 , sizeof( V_7 -> V_42 ) ,
L_25 , V_7 -> V_30 . V_10 -> V_42 ) ;
V_13 -> V_129 = V_7 -> V_129 ;
V_13 -> V_42 = V_7 -> V_42 ;
V_13 -> V_101 . V_130 = V_131 ;
V_13 -> V_101 . V_132 = 0x0001 ;
V_13 -> V_101 . V_133 = V_7 -> V_37 ? 1 : V_7 -> V_8 ;
V_13 -> V_101 . V_134 = V_7 -> V_101 ;
V_13 -> V_135 = F_38 ;
V_13 -> V_14 . V_136 = & V_7 -> V_30 . V_10 -> V_14 ;
F_64 ( V_13 , V_7 ) ;
V_13 -> V_137 [ 0 ] = F_65 ( V_61 ) | F_65 ( V_95 ) |
F_65 ( V_34 ) ;
if ( V_7 -> V_26 ) {
V_13 -> V_137 [ 0 ] |= F_65 ( V_94 ) ;
V_13 -> V_138 [ 0 ] = F_65 ( V_75 ) |
F_65 ( V_76 ) | F_65 ( V_73 ) ;
}
if ( V_7 -> V_78 )
V_13 -> V_138 [ 0 ] |= F_65 ( V_79 ) |
F_65 ( V_81 ) | F_65 ( V_80 ) |
F_65 ( V_83 ) | F_65 ( V_82 ) ;
if ( ! V_7 -> V_56 ) {
V_13 -> V_59 [ V_60 ] = 250 ;
V_13 -> V_59 [ V_71 ] = 33 ;
}
V_13 -> V_139 [ 0 ] = V_7 -> V_140 ? F_65 ( V_46 ) :
F_65 ( V_35 ) | F_65 ( V_46 ) ;
if ( V_7 -> V_15 ) {
V_13 -> V_137 [ 0 ] |= F_65 ( V_141 ) ;
V_13 -> V_142 [ 0 ] = F_65 ( V_64 ) |
F_65 ( V_65 ) ;
F_6 ( V_63 , V_13 -> V_143 ) ;
}
V_13 -> V_19 = V_7 -> V_19 ;
V_13 -> V_144 = sizeof( unsigned short ) ;
V_13 -> V_145 = F_2 ( V_119 ) ;
for ( V_3 = 0 ; V_3 < V_117 ; V_3 ++ ) {
if ( V_7 -> V_19 [ V_3 ] != V_146 &&
V_7 -> V_19 [ V_3 ] != V_45 &&
V_7 -> V_19 [ V_3 ] < V_147 ) {
F_6 ( V_7 -> V_19 [ V_3 ] , V_13 -> V_143 ) ;
}
}
}
static int F_66 ( struct V_10 * V_10 , struct V_148 * V_149 )
{
struct V_7 * V_7 ;
struct V_13 * V_14 ;
int V_150 = - V_151 ;
V_7 = F_67 ( sizeof( struct V_7 ) , V_152 ) ;
V_14 = F_68 () ;
if ( ! V_7 || ! V_14 )
goto V_153;
V_7 -> V_14 = V_14 ;
F_69 ( & V_7 -> V_30 , V_10 ) ;
F_70 ( & V_7 -> V_87 , F_28 ) ;
F_71 ( & V_7 -> V_88 ) ;
switch ( V_10 -> V_101 . type ) {
case V_154 :
V_7 -> V_37 = true ;
case V_155 :
if ( V_10 -> V_26 )
V_7 -> V_26 = true ;
break;
}
V_7 -> V_140 = V_156 ;
V_7 -> V_56 = V_157 ;
V_7 -> V_15 = V_158 ;
if ( V_7 -> V_56 )
V_7 -> V_140 = true ;
F_57 ( V_10 , V_7 ) ;
V_150 = F_72 ( V_10 , V_149 ) ;
if ( V_150 )
goto V_159;
if ( V_7 -> V_26 ) {
if ( F_47 ( V_7 ) ) {
V_150 = - V_160 ;
goto V_161;
}
V_7 -> V_8 = F_49 ( V_7 , V_162 , V_163 ) ;
F_50 ( V_7 ) ;
} else {
V_7 -> V_8 = 2 ;
V_7 -> V_101 = 0xab00 ;
}
F_61 ( V_7 ) ;
F_63 ( V_7 ) ;
V_150 = F_73 ( & V_10 -> V_14 . V_113 , & V_114 ) ;
if ( V_150 )
goto V_161;
F_40 ( V_7 ) ;
if ( V_10 -> V_26 )
F_44 ( V_7 ) ;
V_150 = F_74 ( V_7 -> V_14 ) ;
if ( V_150 )
goto V_164;
return 0 ;
V_164: F_53 ( & V_10 -> V_14 . V_113 , & V_114 ) ;
V_161: F_56 ( V_10 ) ;
V_159: F_57 ( V_10 , NULL ) ;
V_153: F_75 ( V_14 ) ;
F_58 ( V_7 ) ;
return V_150 ;
}
static int F_76 ( struct V_10 * V_10 )
{
struct V_7 * V_7 = F_9 ( V_10 ) ;
struct V_148 * V_149 = V_10 -> V_149 ;
int V_165 = - 1 ;
if ( ! V_7 || ! V_149 ) {
F_10 ( & V_10 -> V_14 ,
L_26 ) ;
return - 1 ;
}
F_30 ( & V_7 -> V_88 ) ;
F_43 ( V_7 ) ;
if ( V_7 -> V_26 ) {
if ( F_47 ( V_7 ) )
goto V_28;
if ( V_7 -> V_8 != F_49 ( V_7 , V_7 -> V_8 , V_7 -> V_78 ) )
goto V_28;
F_27 ( V_7 ) ;
if ( ! V_7 -> V_56 )
F_25 ( V_7 ) ;
}
V_7 -> V_1 = 0 ;
V_7 -> V_9 = 0 ;
F_40 ( V_7 ) ;
if ( V_7 -> V_26 )
F_44 ( V_7 ) ;
V_165 = 0 ;
V_28:
F_33 ( & V_7 -> V_88 ) ;
return V_165 ;
}
static T_2 F_77 ( struct V_166 * V_14 , char * V_167 ,
T_2 (* F_78)( struct V_7 * , char * ) )
{
struct V_10 * V_10 = F_79 ( V_14 ) ;
struct V_7 * V_7 = F_9 ( V_10 ) ;
return F_78 ( V_7 , V_167 ) ;
}
static T_2 F_80 ( struct V_166 * V_14 , const char * V_167 , T_3 V_168 ,
T_2 (* F_78)( struct V_7 * , const char * , T_3 ) )
{
struct V_10 * V_10 = F_79 ( V_14 ) ;
struct V_7 * V_7 = F_9 ( V_10 ) ;
int V_165 ;
V_165 = F_81 ( & V_7 -> V_88 ) ;
if ( V_165 )
return V_165 ;
F_43 ( V_7 ) ;
V_165 = F_78 ( V_7 , V_167 , V_168 ) ;
F_40 ( V_7 ) ;
F_33 ( & V_7 -> V_88 ) ;
return V_165 ;
}
static T_2 F_82 ( struct V_7 * V_7 , char * V_167 )
{
return sprintf ( V_167 , L_27 , V_7 -> V_78 ? 1 : 0 ) ;
}
static T_2 F_83 ( struct V_7 * V_7 , const char * V_167 , T_3 V_168 )
{
struct V_13 * V_169 , * V_170 ;
unsigned int V_18 ;
int V_150 ;
bool V_171 ;
unsigned char V_172 ;
if ( ! V_7 -> V_26 )
return - V_173 ;
V_150 = F_84 ( V_167 , 10 , & V_18 ) ;
if ( V_150 )
return V_150 ;
if ( V_18 > 1 )
return - V_174 ;
if ( V_7 -> V_78 != V_18 ) {
V_169 = V_7 -> V_14 ;
V_171 = V_7 -> V_78 ;
V_172 = V_7 -> V_8 ;
V_170 = F_68 () ;
if ( ! V_170 )
return - V_151 ;
V_7 -> V_14 = V_170 ;
V_7 -> V_8 = F_49 ( V_7 , V_7 -> V_8 , V_18 ) ;
F_50 ( V_7 ) ;
F_44 ( V_7 ) ;
F_61 ( V_7 ) ;
F_63 ( V_7 ) ;
V_150 = F_74 ( V_7 -> V_14 ) ;
if ( V_150 ) {
F_75 ( V_170 ) ;
V_7 -> V_14 = V_169 ;
V_7 -> V_8 = F_49 ( V_7 , V_172 , V_171 ) ;
F_61 ( V_7 ) ;
F_63 ( V_7 ) ;
return V_150 ;
}
F_54 ( V_169 ) ;
}
return V_168 ;
}
static T_2 F_85 ( struct V_7 * V_7 , char * V_167 )
{
T_3 V_175 = F_86 ( V_167 , V_176 - 2 ,
V_7 -> V_62 , V_117 ) ;
V_167 [ V_175 ++ ] = '\n' ;
V_167 [ V_175 ] = '\0' ;
return V_175 ;
}
static T_2 F_87 ( struct V_7 * V_7 ,
const char * V_167 , T_3 V_168 )
{
F_88 ( V_177 , V_117 ) ;
int V_150 ;
V_150 = F_89 ( V_167 , V_177 , V_117 ) ;
if ( V_150 )
return V_150 ;
memcpy ( V_7 -> V_62 , V_177 , sizeof( V_7 -> V_62 ) ) ;
return V_168 ;
}
static T_2 F_90 ( struct V_7 * V_7 , char * V_167 )
{
return sprintf ( V_167 , L_27 , V_7 -> V_15 ? 1 : 0 ) ;
}
static T_2 F_91 ( struct V_7 * V_7 , const char * V_167 , T_3 V_168 )
{
struct V_13 * V_169 , * V_170 ;
unsigned int V_18 ;
int V_150 ;
bool V_178 ;
V_150 = F_84 ( V_167 , 10 , & V_18 ) ;
if ( V_150 )
return V_150 ;
if ( V_18 > 1 )
return - V_174 ;
if ( V_7 -> V_15 != V_18 ) {
V_169 = V_7 -> V_14 ;
V_178 = V_7 -> V_15 ;
V_170 = F_68 () ;
if ( ! V_170 )
return - V_151 ;
V_7 -> V_14 = V_170 ;
V_7 -> V_15 = V_18 ;
F_61 ( V_7 ) ;
F_63 ( V_7 ) ;
V_150 = F_74 ( V_7 -> V_14 ) ;
if ( V_150 ) {
F_75 ( V_170 ) ;
V_7 -> V_15 = V_178 ;
V_7 -> V_14 = V_169 ;
F_61 ( V_7 ) ;
F_63 ( V_7 ) ;
return V_150 ;
}
F_54 ( V_169 ) ;
}
return V_168 ;
}
static T_2 F_92 ( struct V_7 * V_7 , char * V_167 )
{
return sprintf ( V_167 , L_27 , V_7 -> V_8 ) ;
}
static T_2 F_93 ( struct V_7 * V_7 , const char * V_167 , T_3 V_168 )
{
struct V_13 * V_169 , * V_170 ;
unsigned int V_18 ;
int V_150 ;
unsigned char V_172 ;
bool V_171 ;
if ( ! V_7 -> V_26 )
return - V_173 ;
V_150 = F_84 ( V_167 , 10 , & V_18 ) ;
if ( V_150 )
return V_150 ;
if ( V_18 != 2 && V_18 != 3 )
return - V_174 ;
if ( V_7 -> V_8 != V_18 ) {
V_169 = V_7 -> V_14 ;
V_171 = V_7 -> V_78 ;
V_172 = V_7 -> V_8 ;
V_170 = F_68 () ;
if ( ! V_170 )
return - V_151 ;
V_7 -> V_14 = V_170 ;
V_7 -> V_8 = F_49 ( V_7 , V_18 , V_7 -> V_78 ) ;
F_50 ( V_7 ) ;
F_44 ( V_7 ) ;
F_61 ( V_7 ) ;
F_63 ( V_7 ) ;
V_150 = F_74 ( V_7 -> V_14 ) ;
if ( V_150 ) {
F_75 ( V_170 ) ;
V_7 -> V_14 = V_169 ;
V_7 -> V_8 = F_49 ( V_7 , V_172 , V_171 ) ;
F_61 ( V_7 ) ;
F_63 ( V_7 ) ;
return V_150 ;
}
F_54 ( V_169 ) ;
}
return V_168 ;
}
static T_2 F_94 ( struct V_7 * V_7 , char * V_167 )
{
return sprintf ( V_167 , L_27 , V_7 -> V_56 ? 1 : 0 ) ;
}
static T_2 F_95 ( struct V_7 * V_7 , const char * V_167 , T_3 V_168 )
{
struct V_13 * V_169 , * V_170 ;
unsigned int V_18 ;
int V_150 ;
bool V_179 , V_180 ;
if ( ! V_7 -> V_26 )
return - V_173 ;
V_150 = F_84 ( V_167 , 10 , & V_18 ) ;
if ( V_150 )
return V_150 ;
if ( V_18 > 1 )
return - V_174 ;
if ( V_7 -> V_56 != V_18 ) {
V_169 = V_7 -> V_14 ;
V_179 = V_7 -> V_56 ;
V_180 = V_7 -> V_140 ;
V_170 = F_68 () ;
if ( ! V_170 )
return - V_151 ;
V_7 -> V_14 = V_170 ;
V_7 -> V_56 = V_18 ;
if ( V_7 -> V_56 )
V_7 -> V_140 = true ;
F_63 ( V_7 ) ;
V_150 = F_74 ( V_7 -> V_14 ) ;
if ( V_150 ) {
F_75 ( V_170 ) ;
V_7 -> V_14 = V_169 ;
V_7 -> V_56 = V_179 ;
V_7 -> V_140 = V_180 ;
F_63 ( V_7 ) ;
return V_150 ;
}
F_54 ( V_169 ) ;
}
return V_168 ;
}
static T_2 F_96 ( struct V_7 * V_7 , char * V_167 )
{
return sprintf ( V_167 , L_27 , V_7 -> V_140 ? 1 : 0 ) ;
}
static T_2 F_97 ( struct V_7 * V_7 , const char * V_167 , T_3 V_168 )
{
struct V_13 * V_169 , * V_170 ;
unsigned int V_18 ;
int V_150 ;
bool V_180 ;
V_150 = F_84 ( V_167 , 10 , & V_18 ) ;
if ( V_150 )
return V_150 ;
if ( V_18 > 1 )
return - V_174 ;
if ( V_7 -> V_140 != V_18 ) {
V_169 = V_7 -> V_14 ;
V_180 = V_7 -> V_140 ;
V_170 = F_68 () ;
if ( ! V_170 )
return - V_151 ;
V_7 -> V_14 = V_170 ;
V_7 -> V_140 = V_18 ;
F_63 ( V_7 ) ;
V_150 = F_74 ( V_7 -> V_14 ) ;
if ( V_150 ) {
F_75 ( V_170 ) ;
V_7 -> V_14 = V_169 ;
V_7 -> V_140 = V_180 ;
F_63 ( V_7 ) ;
return V_150 ;
}
F_54 ( V_169 ) ;
}
return V_168 ;
}
static T_2 F_98 ( struct V_7 * V_7 , char * V_167 )
{
return sprintf ( V_167 , L_28 , V_7 -> V_44 ) ;
}
static int T_4 F_99 ( const struct V_181 * V_101 )
{
V_127 = F_59 ;
V_128 = V_101 -> V_182 ;
return 1 ;
}
static int T_4 F_100 ( const struct V_181 * V_101 )
{
V_36 = V_101 -> V_182 ;
return 1 ;
}
static int T_4 F_101 ( const struct V_181 * V_101 )
{
V_102 = true ;
return 1 ;
}
static int T_4 F_102 ( void )
{
F_103 ( V_183 ) ;
return F_104 ( & V_184 ) ;
}
static void T_5 F_105 ( void )
{
F_106 ( & V_184 ) ;
}
