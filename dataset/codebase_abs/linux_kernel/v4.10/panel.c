static void F_1 ( unsigned int V_1 , int * V_2 )
{
unsigned int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_4 = F_2 ( V_3 , V_6 ) ? V_7 : V_8 ;
* V_2 &= V_9 [ V_1 ] [ V_3 ] [ V_10 ] ;
* V_2 |= V_9 [ V_1 ] [ V_3 ] [ V_4 ] ;
}
}
static int F_3 ( void )
{
int V_2 ;
V_2 = F_4 ( V_11 ) ;
F_1 ( V_12 , & V_2 ) ;
F_5 ( V_11 , V_2 ) ;
return V_2 ;
}
static int F_6 ( void )
{
int V_2 ;
V_2 = F_7 ( V_11 ) ;
F_1 ( V_13 , & V_2 ) ;
F_8 ( V_11 , V_2 ) ;
return V_2 ;
}
static void F_9 ( void )
{
F_3 () ;
F_6 () ;
}
static void F_10 ( int V_14 , unsigned char * V_15 , unsigned char * V_16 )
{
int V_17 , V_18 , V_19 ;
V_15 [ 0 ] = 0 ;
V_16 [ 0 ] = 0 ;
V_15 [ 1 ] = 0 ;
V_16 [ 1 ] = 0 ;
V_15 [ 2 ] = 0xFF ;
V_16 [ 2 ] = 0xFF ;
if ( V_14 == 0 )
return;
V_19 = ( V_14 < 0 ) ;
if ( V_19 )
V_14 = - V_14 ;
V_17 = 0 ;
V_18 = 0 ;
switch ( V_14 ) {
case V_20 :
V_18 = V_21 ;
V_19 = ! V_19 ;
break;
case V_22 ... V_23 :
V_17 = 1 << ( V_14 - 2 ) ;
break;
case V_24 :
V_18 = V_25 ;
V_19 = ! V_19 ;
break;
case V_26 :
V_18 = V_27 ;
break;
case V_28 :
V_18 = V_29 ;
V_19 = ! V_19 ;
break;
default:
break;
}
if ( V_18 ) {
V_16 [ 2 ] &= ~ V_18 ;
V_16 [ ! V_19 ] = V_18 ;
} else if ( V_17 ) {
V_15 [ 2 ] &= ~ V_17 ;
V_15 [ ! V_19 ] = V_17 ;
}
}
static void F_11 ( int V_30 )
{
if ( F_12 () )
F_13 ( V_30 ) ;
else
F_14 ( F_15 ( V_30 ) ) ;
}
static void F_16 ( int V_31 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
F_17 ( V_32 , V_6 ) ;
F_9 () ;
if ( V_31 & 1 ) {
F_18 ( V_33 , V_6 ) ;
} else {
F_17 ( V_33 , V_6 ) ;
}
F_9 () ;
F_19 ( 2 ) ;
F_18 ( V_32 , V_6 ) ;
F_9 () ;
F_19 ( 1 ) ;
V_31 >>= 1 ;
}
}
static void F_20 ( int V_34 )
{
if ( V_35 . V_36 . V_37 == V_38 )
return;
F_21 ( & V_39 ) ;
if ( V_34 )
F_18 ( V_40 , V_6 ) ;
else
F_17 ( V_40 , V_6 ) ;
F_9 () ;
F_22 ( & V_39 ) ;
}
static void F_23 ( int V_41 )
{
F_21 ( & V_39 ) ;
F_16 ( 0x1F ) ;
F_16 ( V_41 & 0x0F ) ;
F_16 ( ( V_41 >> 4 ) & 0x0F ) ;
F_19 ( 40 ) ;
F_22 ( & V_39 ) ;
}
static void F_24 ( int V_42 )
{
F_21 ( & V_39 ) ;
F_16 ( 0x5F ) ;
F_16 ( V_42 & 0x0F ) ;
F_16 ( ( V_42 >> 4 ) & 0x0F ) ;
F_19 ( 40 ) ;
F_22 ( & V_39 ) ;
}
static void F_25 ( int V_41 )
{
F_21 ( & V_39 ) ;
F_5 ( V_11 , V_41 ) ;
F_19 ( 20 ) ;
F_18 ( V_43 , V_6 ) ;
F_17 ( V_44 , V_6 ) ;
F_17 ( V_45 , V_6 ) ;
F_6 () ;
F_19 ( 40 ) ;
F_17 ( V_43 , V_6 ) ;
F_6 () ;
F_19 ( 120 ) ;
F_22 ( & V_39 ) ;
}
static void F_26 ( int V_42 )
{
F_21 ( & V_39 ) ;
F_5 ( V_11 , V_42 ) ;
F_19 ( 20 ) ;
F_18 ( V_43 , V_6 ) ;
F_18 ( V_44 , V_6 ) ;
F_17 ( V_45 , V_6 ) ;
F_6 () ;
F_19 ( 40 ) ;
F_17 ( V_43 , V_6 ) ;
F_6 () ;
F_19 ( 45 ) ;
F_22 ( & V_39 ) ;
}
static void F_27 ( int V_41 )
{
F_21 ( & V_39 ) ;
F_8 ( V_11 , V_41 ) ;
F_19 ( 60 ) ;
F_22 ( & V_39 ) ;
}
static void F_28 ( int V_42 )
{
F_21 ( & V_39 ) ;
F_5 ( V_11 , V_42 ) ;
F_19 ( 60 ) ;
F_22 ( & V_39 ) ;
}
static void F_29 ( void )
{
F_30 ( V_46
| ( V_35 . V_47 . V_48 ? V_35 . V_49 : 0 )
| ( ( V_35 . V_47 . V_50 < V_35 . V_51 ) ? V_35 . V_47 . V_50 &
( V_35 . V_49 - 1 ) : V_35 . V_51 - 1 ) ) ;
}
static void F_31 ( char V_52 )
{
if ( V_35 . V_47 . V_50 < V_35 . V_51 ) {
if ( V_53 )
V_52 = V_53 [ ( unsigned char ) V_52 ] ;
F_32 ( V_52 ) ;
V_35 . V_47 . V_50 ++ ;
}
if ( V_35 . V_47 . V_50 == V_35 . V_51 )
F_29 () ;
}
static void F_33 ( void )
{
int V_54 ;
V_35 . V_47 . V_50 = 0 ;
V_35 . V_47 . V_48 = 0 ;
F_29 () ;
F_21 ( & V_39 ) ;
for ( V_54 = 0 ; V_54 < V_35 . V_55 * V_35 . V_49 ; V_54 ++ ) {
F_16 ( 0x5F ) ;
F_16 ( ' ' & 0x0F ) ;
F_16 ( ( ' ' >> 4 ) & 0x0F ) ;
F_19 ( 40 ) ;
}
F_22 ( & V_39 ) ;
V_35 . V_47 . V_50 = 0 ;
V_35 . V_47 . V_48 = 0 ;
F_29 () ;
}
static void F_34 ( void )
{
int V_54 ;
V_35 . V_47 . V_50 = 0 ;
V_35 . V_47 . V_48 = 0 ;
F_29 () ;
F_21 ( & V_39 ) ;
for ( V_54 = 0 ; V_54 < V_35 . V_55 * V_35 . V_49 ; V_54 ++ ) {
F_5 ( V_11 , ' ' ) ;
F_19 ( 20 ) ;
F_18 ( V_43 , V_6 ) ;
F_18 ( V_44 , V_6 ) ;
F_17 ( V_45 , V_6 ) ;
F_6 () ;
F_19 ( 40 ) ;
F_17 ( V_43 , V_6 ) ;
F_6 () ;
F_19 ( 45 ) ;
}
F_22 ( & V_39 ) ;
V_35 . V_47 . V_50 = 0 ;
V_35 . V_47 . V_48 = 0 ;
F_29 () ;
}
static void F_35 ( void )
{
int V_54 ;
V_35 . V_47 . V_50 = 0 ;
V_35 . V_47 . V_48 = 0 ;
F_29 () ;
F_21 ( & V_39 ) ;
for ( V_54 = 0 ; V_54 < V_35 . V_55 * V_35 . V_49 ; V_54 ++ ) {
F_5 ( V_11 , ' ' ) ;
F_19 ( 60 ) ;
}
F_22 ( & V_39 ) ;
V_35 . V_47 . V_50 = 0 ;
V_35 . V_47 . V_48 = 0 ;
F_29 () ;
}
static void F_36 ( void )
{
F_30 ( V_56 ) ;
V_35 . V_47 . V_50 = 0 ;
V_35 . V_47 . V_48 = 0 ;
F_11 ( 15 ) ;
}
static void F_37 ( void )
{
V_35 . V_57 = ( ( V_35 . V_55 > 1 ) ? V_58 : 0 )
| V_59 | V_60 | V_61 ;
F_11 ( 20 ) ;
F_30 ( V_62 | V_63 ) ;
F_11 ( 10 ) ;
F_30 ( V_62 | V_63 ) ;
F_11 ( 10 ) ;
F_30 ( V_62 | V_63 ) ;
F_11 ( 10 ) ;
F_30 ( V_62 | V_63
| ( ( V_35 . V_57 & V_64 ) ? V_65 : 0 )
| ( ( V_35 . V_57 & V_58 ) ? V_66 : 0 )
) ;
F_11 ( 10 ) ;
F_30 ( V_67 ) ;
F_11 ( 10 ) ;
F_30 ( V_67
| ( ( V_35 . V_57 & V_59 ) ? V_68 : 0 )
| ( ( V_35 . V_57 & V_60 ) ? V_69 : 0 )
| ( ( V_35 . V_57 & V_61 ) ? V_70 : 0 )
) ;
F_20 ( ( V_35 . V_57 & V_71 ) ? 1 : 0 ) ;
F_11 ( 10 ) ;
F_30 ( V_72 | V_73 ) ;
F_36 () ;
}
static inline int F_38 ( void )
{
int V_74 = 0 ;
char * V_75 = V_35 . V_76 . V_77 + 2 ;
int V_78 = V_35 . V_57 ;
switch ( * V_75 ) {
case 'D' :
V_35 . V_57 |= V_59 ;
V_74 = 1 ;
break;
case 'd' :
V_35 . V_57 &= ~ V_59 ;
V_74 = 1 ;
break;
case 'C' :
V_35 . V_57 |= V_60 ;
V_74 = 1 ;
break;
case 'c' :
V_35 . V_57 &= ~ V_60 ;
V_74 = 1 ;
break;
case 'B' :
V_35 . V_57 |= V_61 ;
V_74 = 1 ;
break;
case 'b' :
V_35 . V_57 &= ~ V_61 ;
V_74 = 1 ;
break;
case '+' :
V_35 . V_57 |= V_71 ;
V_74 = 1 ;
break;
case '-' :
V_35 . V_57 &= ~ V_71 ;
V_74 = 1 ;
break;
case '*' :
if ( V_79 . V_80 ) {
if ( V_35 . V_81 == 0 &&
( ( V_35 . V_57 & V_71 ) == 0 ) )
F_20 ( 1 ) ;
V_35 . V_81 = V_82 ;
}
V_74 = 1 ;
break;
case 'f' :
V_35 . V_57 &= ~ V_64 ;
V_74 = 1 ;
break;
case 'F' :
V_35 . V_57 |= V_64 ;
V_74 = 1 ;
break;
case 'n' :
V_35 . V_57 &= ~ V_58 ;
V_74 = 1 ;
break;
case 'N' :
V_35 . V_57 |= V_58 ;
break;
case 'l' :
if ( V_35 . V_47 . V_50 > 0 ) {
if ( V_35 . V_47 . V_50 < V_35 . V_51 )
F_30 ( V_83 ) ;
V_35 . V_47 . V_50 -- ;
}
V_74 = 1 ;
break;
case 'r' :
if ( V_35 . V_47 . V_50 < V_35 . V_84 ) {
if ( V_35 . V_47 . V_50 < ( V_35 . V_51 - 1 ) )
F_30 ( V_83 |
V_85 ) ;
V_35 . V_47 . V_50 ++ ;
}
V_74 = 1 ;
break;
case 'L' :
F_30 ( V_83 | V_86 ) ;
V_74 = 1 ;
break;
case 'R' :
F_30 ( V_83 | V_86 |
V_85 ) ;
V_74 = 1 ;
break;
case 'k' : {
int V_50 ;
for ( V_50 = V_35 . V_47 . V_50 ; V_50 < V_35 . V_51 ; V_50 ++ )
F_32 ( ' ' ) ;
F_29 () ;
V_74 = 1 ;
break;
}
case 'I' :
F_37 () ;
V_74 = 1 ;
break;
case 'G' : {
unsigned char V_87 [ 8 ] ;
unsigned char V_88 ;
int V_89 ;
int V_90 ;
char V_91 ;
int V_47 ;
if ( ! strchr ( V_75 , ';' ) )
break;
V_75 ++ ;
V_88 = * ( V_75 ++ ) - '0' ;
if ( V_88 > 7 ) {
V_74 = 1 ;
break;
}
V_89 = 0 ;
V_90 = 0 ;
V_91 = 0 ;
while ( * V_75 && V_89 < 8 ) {
V_90 ^= 4 ;
if ( * V_75 >= '0' && * V_75 <= '9' ) {
V_91 |= ( * V_75 - '0' ) << V_90 ;
} else if ( * V_75 >= 'A' && * V_75 <= 'Z' ) {
V_91 |= ( * V_75 - 'A' + 10 ) << V_90 ;
} else if ( * V_75 >= 'a' && * V_75 <= 'z' ) {
V_91 |= ( * V_75 - 'a' + 10 ) << V_90 ;
} else {
V_75 ++ ;
continue;
}
if ( V_90 == 0 ) {
V_87 [ V_89 ++ ] = V_91 ;
V_91 = 0 ;
}
V_75 ++ ;
}
F_30 ( V_92 | ( V_88 * 8 ) ) ;
for ( V_47 = 0 ; V_47 < V_89 ; V_47 ++ )
F_32 ( V_87 [ V_47 ] ) ;
F_29 () ;
V_74 = 1 ;
break;
}
case 'x' :
case 'y' :
if ( ! strchr ( V_75 , ';' ) )
break;
while ( * V_75 ) {
if ( * V_75 == 'x' ) {
V_75 ++ ;
if ( F_39 ( V_75 , 10 , & V_35 . V_47 . V_50 ) < 0 )
break;
} else if ( * V_75 == 'y' ) {
V_75 ++ ;
if ( F_39 ( V_75 , 10 , & V_35 . V_47 . V_48 ) < 0 )
break;
} else {
break;
}
}
F_29 () ;
V_74 = 1 ;
break;
}
if ( V_78 != V_35 . V_57 ) {
if ( ( V_78 ^ V_35 . V_57 ) &
( V_61 | V_60 | V_59 ) )
F_30 ( V_67
| ( ( V_35 . V_57 & V_59 )
? V_68 : 0 )
| ( ( V_35 . V_57 & V_60 )
? V_69 : 0 )
| ( ( V_35 . V_57 & V_61 )
? V_70 : 0 ) ) ;
else if ( ( V_78 ^ V_35 . V_57 ) & ( V_64 | V_58 ) )
F_30 ( V_62
| V_63
| ( ( V_35 . V_57 & V_64 )
? V_66 : 0 )
| ( ( V_35 . V_57 & V_58 )
? V_65
: 0 ) ) ;
else if ( ( V_78 ^ V_35 . V_57 ) & ( V_71 ) ) {
if ( V_35 . V_57 & ( V_71 ) )
F_20 ( 1 ) ;
else if ( V_35 . V_81 == 0 )
F_20 ( 0 ) ;
}
}
return V_74 ;
}
static void F_40 ( char V_52 )
{
if ( ( V_52 != '\n' ) && V_35 . V_76 . V_93 >= 0 ) {
V_35 . V_76 . V_77 [ V_35 . V_76 . V_93 ++ ] = V_52 ;
V_35 . V_76 . V_77 [ V_35 . V_76 . V_93 ] = 0 ;
} else {
V_35 . V_76 . V_93 = - 1 ;
switch ( V_52 ) {
case V_94 :
V_35 . V_76 . V_93 = 0 ;
V_35 . V_76 . V_77 [ V_35 . V_76 . V_93 ] = 0 ;
break;
case '\b' :
if ( V_35 . V_47 . V_50 > 0 ) {
if ( V_35 . V_47 . V_50 < V_35 . V_51 )
F_30 ( V_83 ) ;
V_35 . V_47 . V_50 -- ;
}
F_32 ( ' ' ) ;
F_30 ( V_83 ) ;
break;
case '\014' :
F_41 () ;
break;
case '\n' :
for (; V_35 . V_47 . V_50 < V_35 . V_51 ; V_35 . V_47 . V_50 ++ )
F_32 ( ' ' ) ;
V_35 . V_47 . V_50 = 0 ;
V_35 . V_47 . V_48 = ( V_35 . V_47 . V_48 + 1 ) % V_35 . V_55 ;
F_29 () ;
break;
case '\r' :
V_35 . V_47 . V_50 = 0 ;
F_29 () ;
break;
case '\t' :
F_31 ( ' ' ) ;
break;
default:
F_31 ( V_52 ) ;
break;
}
}
if ( V_35 . V_76 . V_93 >= 2 ) {
int V_74 = 0 ;
if ( ! strcmp ( V_35 . V_76 . V_77 , L_1 ) ) {
F_41 () ;
V_74 = 1 ;
} else if ( ! strcmp ( V_35 . V_76 . V_77 , L_2 ) ) {
V_35 . V_47 . V_50 = 0 ;
V_35 . V_47 . V_48 = 0 ;
F_29 () ;
V_74 = 1 ;
}
else if ( ( V_35 . V_76 . V_93 >= 3 ) &&
( V_35 . V_76 . V_77 [ 0 ] == '[' ) &&
( V_35 . V_76 . V_77 [ 1 ] == 'L' ) ) {
V_74 = F_38 () ;
}
if ( V_74 || ( V_35 . V_76 . V_93 >= V_95 ) )
V_35 . V_76 . V_93 = - 1 ;
}
}
static T_1 F_42 ( struct V_96 * V_96 ,
const char T_2 * V_77 , T_3 V_97 , T_4 * V_98 )
{
const char T_2 * V_99 = V_77 ;
char V_52 ;
for (; V_97 -- > 0 ; ( * V_98 ) ++ , V_99 ++ ) {
if ( ! F_12 () && ( ( ( V_97 + 1 ) & 0x1f ) == 0 ) )
F_43 () ;
if ( F_44 ( V_52 , V_99 ) )
return - V_100 ;
F_40 ( V_52 ) ;
}
return V_99 - V_77 ;
}
static int F_45 ( struct V_101 * V_101 , struct V_96 * V_96 )
{
if ( ! F_46 ( & V_102 ) )
return - V_103 ;
if ( V_96 -> V_104 & V_105 )
return - V_106 ;
if ( V_35 . V_107 ) {
F_36 () ;
V_35 . V_107 = false ;
}
return F_47 ( V_101 , V_96 ) ;
}
static int F_48 ( struct V_101 * V_101 , struct V_96 * V_96 )
{
F_49 ( & V_102 ) ;
return 0 ;
}
static void F_50 ( const char * V_108 )
{
const char * V_99 = V_108 ;
int V_97 = strlen ( V_108 ) ;
if ( V_35 . V_109 && V_35 . V_110 ) {
for (; V_97 -- > 0 ; V_99 ++ ) {
if ( ! F_12 () && ( ( ( V_97 + 1 ) & 0x1f ) == 0 ) )
F_43 () ;
F_40 ( * V_99 ) ;
}
}
}
static void F_51 ( void )
{
switch ( V_111 ) {
case V_112 :
V_35 . V_113 = V_114 ;
V_35 . V_115 = V_116 ;
V_35 . V_36 . V_117 = V_20 ;
V_35 . V_36 . V_118 = V_24 ;
V_35 . V_84 = 40 ;
V_35 . V_51 = 40 ;
V_35 . V_49 = 64 ;
V_35 . V_55 = 2 ;
break;
case V_119 :
V_35 . V_113 = V_120 ;
V_35 . V_115 = V_121 ;
V_35 . V_36 . V_37 = V_24 ;
V_35 . V_36 . V_122 = V_20 ;
V_35 . V_36 . V_123 = V_22 ;
V_35 . V_84 = 16 ;
V_35 . V_51 = 40 ;
V_35 . V_49 = 16 ;
V_35 . V_55 = 2 ;
break;
case V_124 :
V_35 . V_113 = V_114 ;
V_35 . V_115 = V_116 ;
V_35 . V_36 . V_117 = V_24 ;
V_35 . V_36 . V_118 = V_28 ;
V_35 . V_36 . V_125 = V_26 ;
V_35 . V_84 = 16 ;
V_35 . V_51 = 40 ;
V_35 . V_49 = 64 ;
V_35 . V_55 = 2 ;
break;
case V_126 :
V_35 . V_113 = V_127 ;
V_35 . V_115 = V_128 ;
break;
case V_129 :
default:
V_35 . V_113 = V_114 ;
V_35 . V_115 = V_116 ;
V_35 . V_36 . V_117 = V_20 ;
V_35 . V_36 . V_118 = V_28 ;
V_35 . V_84 = 16 ;
V_35 . V_51 = 40 ;
V_35 . V_49 = 64 ;
V_35 . V_55 = 2 ;
break;
}
if ( V_130 != V_131 )
V_35 . V_55 = V_130 ;
if ( V_132 != V_131 )
V_35 . V_84 = V_132 ;
if ( V_133 != V_131 )
V_35 . V_51 = V_133 ;
if ( V_134 != V_131 )
V_35 . V_49 = V_134 ;
if ( V_135 != V_131 )
V_35 . V_115 = V_135 ;
if ( V_136 != V_131 )
V_35 . V_113 = V_136 ;
if ( V_137 != V_138 )
V_35 . V_36 . V_117 = V_137 ;
if ( V_139 != V_138 )
V_35 . V_36 . V_118 = V_139 ;
if ( V_140 != V_138 )
V_35 . V_36 . V_125 = V_140 ;
if ( V_141 != V_138 )
V_35 . V_36 . V_122 = V_141 ;
if ( V_142 != V_138 )
V_35 . V_36 . V_123 = V_142 ;
if ( V_143 != V_138 )
V_35 . V_36 . V_37 = V_143 ;
if ( V_35 . V_84 <= 0 )
V_35 . V_84 = V_144 ;
if ( V_35 . V_51 <= 0 )
V_35 . V_51 = V_145 ;
if ( V_35 . V_49 <= 0 )
V_35 . V_49 = V_146 ;
if ( V_35 . V_55 <= 0 )
V_35 . V_55 = V_147 ;
if ( V_35 . V_113 == V_120 ) {
F_30 = F_23 ;
F_32 = F_24 ;
F_41 = F_33 ;
if ( V_35 . V_36 . V_122 == V_138 )
V_35 . V_36 . V_122 = V_148 ;
if ( V_35 . V_36 . V_123 == V_138 )
V_35 . V_36 . V_123 = V_149 ;
} else if ( V_35 . V_113 == V_114 ) {
F_30 = F_25 ;
F_32 = F_26 ;
F_41 = F_34 ;
if ( V_35 . V_36 . V_117 == V_138 )
V_35 . V_36 . V_117 = V_150 ;
if ( V_35 . V_36 . V_118 == V_138 )
V_35 . V_36 . V_118 = V_151 ;
if ( V_35 . V_36 . V_125 == V_138 )
V_35 . V_36 . V_125 = V_152 ;
} else {
F_30 = F_27 ;
F_32 = F_28 ;
F_41 = F_35 ;
}
if ( V_35 . V_36 . V_37 == V_138 )
V_35 . V_36 . V_37 = V_153 ;
if ( V_35 . V_36 . V_117 == V_138 )
V_35 . V_36 . V_117 = V_38 ;
if ( V_35 . V_36 . V_118 == V_138 )
V_35 . V_36 . V_118 = V_38 ;
if ( V_35 . V_36 . V_125 == V_138 )
V_35 . V_36 . V_125 = V_38 ;
if ( V_35 . V_36 . V_37 == V_138 )
V_35 . V_36 . V_37 = V_38 ;
if ( V_35 . V_36 . V_122 == V_138 )
V_35 . V_36 . V_122 = V_38 ;
if ( V_35 . V_36 . V_123 == V_138 )
V_35 . V_36 . V_123 = V_38 ;
if ( V_35 . V_115 == V_131 )
V_35 . V_115 = V_128 ;
if ( V_35 . V_115 == V_121 )
V_53 = V_154 ;
else
V_53 = NULL ;
if ( V_35 . V_36 . V_37 != V_38 )
F_52 () ;
F_10 ( V_35 . V_36 . V_117 , V_9 [ V_12 ] [ V_43 ] ,
V_9 [ V_13 ] [ V_43 ] ) ;
F_10 ( V_35 . V_36 . V_118 , V_9 [ V_12 ] [ V_44 ] ,
V_9 [ V_13 ] [ V_44 ] ) ;
F_10 ( V_35 . V_36 . V_125 , V_9 [ V_12 ] [ V_45 ] ,
V_9 [ V_13 ] [ V_45 ] ) ;
F_10 ( V_35 . V_36 . V_37 , V_9 [ V_12 ] [ V_40 ] ,
V_9 [ V_13 ] [ V_40 ] ) ;
F_10 ( V_35 . V_36 . V_122 , V_9 [ V_12 ] [ V_32 ] ,
V_9 [ V_13 ] [ V_32 ] ) ;
F_10 ( V_35 . V_36 . V_123 , V_9 [ V_12 ] [ V_33 ] ,
V_9 [ V_13 ] [ V_33 ] ) ;
V_35 . V_110 = true ;
F_37 () ;
#ifdef F_53
#ifdef F_54
F_50 ( L_3 F_54 ) ;
#endif
#else
F_50 ( L_4 V_155 L_5
V_156 ) ;
#endif
V_35 . V_47 . V_50 = 0 ;
V_35 . V_47 . V_48 = 0 ;
V_35 . V_107 = true ;
F_29 () ;
}
static T_1 F_55 ( struct V_96 * V_96 ,
char T_2 * V_77 , T_3 V_97 , T_4 * V_98 )
{
unsigned V_157 = * V_98 ;
char T_2 * V_99 = V_77 ;
if ( V_158 == 0 ) {
if ( V_96 -> V_159 & V_160 )
return - V_161 ;
if ( F_56 ( V_162 ,
V_158 != 0 ) )
return - V_163 ;
}
for (; V_97 -- > 0 && ( V_158 > 0 ) ;
++ V_157 , ++ V_99 , -- V_158 ) {
F_57 ( V_164 [ V_165 ] , V_99 ) ;
V_165 = ( V_165 + 1 ) % V_166 ;
}
* V_98 = V_157 ;
return V_99 - V_77 ;
}
static int F_58 ( struct V_101 * V_101 , struct V_96 * V_96 )
{
if ( ! F_46 ( & V_167 ) )
return - V_103 ;
if ( V_96 -> V_104 & V_168 )
return - V_106 ;
V_158 = 0 ;
return 0 ;
}
static int F_59 ( struct V_101 * V_101 , struct V_96 * V_96 )
{
F_49 ( & V_167 ) ;
return 0 ;
}
static void F_60 ( const char * string , int V_169 )
{
if ( ! F_61 ( & V_167 ) ) {
while ( V_169 -- && V_158 < V_166 && * string ) {
V_164 [ ( V_165 + V_158 ++ ) %
V_166 ] = * string ++ ;
}
F_62 ( & V_162 ) ;
}
}
static void F_63 ( void )
{
int V_3 , V_170 ;
char V_171 ;
char V_172 ;
char V_173 ;
V_174 = V_175 ;
V_176 = V_177 ;
V_177 = 0 ;
V_171 = F_4 ( V_11 ) | V_178 ;
F_5 ( V_11 , V_171 & ~ V_178 ) ;
V_172 = F_64 ( F_65 ( V_11 ) ) & V_179 ;
F_5 ( V_11 , V_171 ) ;
V_173 = F_64 ( F_65 ( V_11 ) ) & V_179 ;
V_177 |= ( V_180 ) V_173 << 40 ;
if ( V_172 != V_173 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_170 = F_66 ( V_3 ) ;
if ( ! ( V_178 & V_170 ) )
continue;
F_5 ( V_11 , V_171 & ~ V_170 ) ;
V_172 = F_64 ( F_65 ( V_11 ) ) & ~ V_173 ;
V_177 |= ( V_180 ) V_172 << ( 5 * V_3 ) ;
}
F_5 ( V_11 , V_171 ) ;
}
V_175 = ( V_174 & ( V_177 ^ V_176 ) ) |
( V_177 & ~ ( V_177 ^ V_176 ) ) ;
}
static inline int F_67 ( struct V_181 * V_182 )
{
#if 0
if (((phys_prev & input->mask) == input->value) &&
((phys_curr & input->mask) > input->value)) {
input->state = INPUT_ST_LOW;
return 1;
}
#endif
if ( ( V_175 & V_182 -> V_183 ) == V_182 -> V_91 ) {
if ( ( V_182 -> type == V_184 ) &&
( V_182 -> V_185 == 0 ) ) {
V_182 -> V_185 ++ ;
if ( V_182 -> V_186 . V_187 . V_188 )
V_182 -> V_186 . V_187 . V_188 ( V_182 -> V_186 . V_187 . V_189 ) ;
} else if ( V_182 -> type == V_190 ) {
V_191 = 1 ;
if ( V_182 -> V_185 == 0 ) {
char * V_192 = V_182 -> V_186 . V_193 . V_192 ;
if ( V_192 [ 0 ] ) {
int V_108 = sizeof( V_182 -> V_186 . V_193 . V_192 ) ;
F_60 ( V_192 , V_108 ) ;
}
}
if ( V_182 -> V_186 . V_193 . V_194 [ 0 ] ) {
char * V_194 = V_182 -> V_186 . V_193 . V_194 ;
if ( V_182 -> V_185 >= V_195 ) {
int V_108 = sizeof( V_182 -> V_186 . V_193 . V_194 ) ;
V_182 -> V_185 -= V_196 ;
F_60 ( V_194 , V_108 ) ;
}
V_197 = 0 ;
}
if ( V_182 -> V_185 < 255 )
V_182 -> V_185 ++ ;
}
return 1 ;
}
V_182 -> V_4 = V_198 ;
V_182 -> V_199 = 0 ;
return 0 ;
}
static inline void F_68 ( struct V_181 * V_182 )
{
#if 0
if (((phys_prev & input->mask) == input->value) &&
((phys_curr & input->mask) > input->value)) {
input->state = INPUT_ST_LOW;
return;
}
#endif
if ( ( V_175 & V_182 -> V_183 ) == V_182 -> V_91 ) {
if ( V_182 -> type == V_190 ) {
V_191 = 1 ;
if ( V_182 -> V_186 . V_193 . V_194 [ 0 ] ) {
char * V_194 = V_182 -> V_186 . V_193 . V_194 ;
if ( V_182 -> V_185 >= V_195 ) {
int V_108 = sizeof( V_182 -> V_186 . V_193 . V_194 ) ;
V_182 -> V_185 -= V_196 ;
F_60 ( V_194 , V_108 ) ;
}
V_197 = 0 ;
}
if ( V_182 -> V_185 < 255 )
V_182 -> V_185 ++ ;
}
V_182 -> V_4 = V_200 ;
} else if ( V_182 -> V_199 >= V_182 -> V_201 ) {
if ( V_182 -> type == V_184 ) {
void (* F_69)( int ) = V_182 -> V_186 . V_187 . F_69 ;
if ( F_69 )
F_69 ( V_182 -> V_186 . V_187 . V_202 ) ;
} else if ( V_182 -> type == V_190 ) {
char * V_203 = V_182 -> V_186 . V_193 . V_203 ;
if ( V_203 [ 0 ] ) {
int V_108 = sizeof( V_182 -> V_186 . V_193 . V_203 ) ;
F_60 ( V_203 , V_108 ) ;
}
}
V_182 -> V_4 = V_204 ;
} else {
V_182 -> V_199 ++ ;
V_197 = 0 ;
}
}
static void F_70 ( void )
{
struct V_205 * V_206 ;
struct V_181 * V_182 ;
V_191 = 0 ;
V_197 = 1 ;
F_71 (item, &logical_inputs) {
V_182 = F_72 ( V_206 , struct V_181 , V_207 ) ;
switch ( V_182 -> V_4 ) {
case V_204 :
if ( ( V_175 & V_182 -> V_183 ) != V_182 -> V_91 )
break;
if ( ( V_174 & V_182 -> V_183 ) == V_182 -> V_91 )
break;
V_182 -> V_208 = 0 ;
V_182 -> V_4 = V_209 ;
case V_209 :
if ( ( V_175 & V_182 -> V_183 ) != V_182 -> V_91 ) {
V_182 -> V_4 = V_204 ;
break;
}
if ( V_182 -> V_208 < V_182 -> V_210 ) {
V_197 = 0 ;
V_182 -> V_208 ++ ;
break;
}
V_182 -> V_185 = 0 ;
V_182 -> V_4 = V_200 ;
case V_200 :
if ( F_67 ( V_182 ) )
break;
case V_198 :
F_68 ( V_182 ) ;
}
}
}
static void F_73 ( void )
{
if ( V_211 . V_109 && V_212 ) {
if ( F_74 ( & V_39 ) ) {
F_63 () ;
F_22 ( & V_39 ) ;
}
if ( ! V_197 || V_175 != V_174 )
F_70 () ;
}
if ( V_35 . V_109 && V_35 . V_110 ) {
if ( V_191 ) {
if ( V_35 . V_81 == 0 &&
( ( V_35 . V_57 & V_71 ) == 0 ) )
F_20 ( 1 ) ;
V_35 . V_81 = V_82 ;
} else if ( V_35 . V_81 > 0 ) {
V_35 . V_81 -- ;
if ( V_35 . V_81 == 0 &&
( ( V_35 . V_57 & V_71 ) == 0 ) )
F_20 ( 0 ) ;
}
}
F_75 ( & V_79 , V_213 + V_214 ) ;
}
static void F_52 ( void )
{
if ( V_79 . V_80 )
return;
F_76 ( & V_79 , ( void * ) & F_73 , 0 ) ;
V_79 . V_215 = V_213 + V_214 ;
F_77 ( & V_79 ) ;
}
static T_5 F_78 ( const char * V_216 , V_180 * V_183 , V_180 * V_91 ,
T_5 * V_217 , T_5 * V_218 )
{
const char V_219 [] = L_6 ;
T_5 V_220 , V_221 ;
V_180 V_222 , V_223 ;
V_221 = 0 ;
V_220 = 0 ;
V_222 = 0ULL ;
V_223 = 0ULL ;
while ( * V_216 ) {
int V_224 , V_225 , V_3 , V_226 ;
const char * V_227 ;
V_227 = strchr ( V_219 , * V_216 ) ;
if ( ! V_227 )
return 0 ;
V_224 = V_227 - V_219 ;
V_226 = ( V_224 & 1 ) ;
V_224 >>= 1 ;
V_220 |= F_66 ( V_224 ) ;
V_216 ++ ;
if ( * V_216 >= '0' && * V_216 <= '7' ) {
V_225 = * V_216 - '0' ;
V_221 |= F_66 ( V_225 ) ;
} else if ( * V_216 == '-' ) {
V_225 = 8 ;
} else {
return 0 ;
}
V_3 = ( V_225 * 5 ) + V_224 ;
V_222 |= 1ULL << V_3 ;
if ( ! V_226 )
V_223 |= 1ULL << V_3 ;
V_216 ++ ;
}
* V_183 = V_222 ;
* V_91 = V_223 ;
if ( V_217 )
* V_217 |= V_220 ;
if ( V_218 )
* V_218 |= V_221 ;
return 1 ;
}
static struct V_181 * F_79 ( const char * V_216 , const char * V_228 ,
const char * V_229 ,
const char * V_230 )
{
struct V_181 * V_231 ;
V_231 = F_80 ( sizeof( * V_231 ) , V_232 ) ;
if ( ! V_231 )
return NULL ;
if ( ! F_78 ( V_216 , & V_231 -> V_183 , & V_231 -> V_91 , & V_179 ,
& V_178 ) ) {
F_81 ( V_231 ) ;
return NULL ;
}
V_231 -> type = V_190 ;
V_231 -> V_4 = V_204 ;
V_231 -> V_210 = 1 ;
V_231 -> V_201 = 1 ;
strncpy ( V_231 -> V_186 . V_193 . V_192 , V_228 , sizeof( V_231 -> V_186 . V_193 . V_192 ) ) ;
strncpy ( V_231 -> V_186 . V_193 . V_194 , V_229 , sizeof( V_231 -> V_186 . V_193 . V_194 ) ) ;
strncpy ( V_231 -> V_186 . V_193 . V_203 , V_230 ,
sizeof( V_231 -> V_186 . V_193 . V_203 ) ) ;
F_82 ( & V_231 -> V_207 , & V_233 ) ;
return V_231 ;
}
static void F_83 ( void )
{
int V_234 ;
F_84 ( & V_162 ) ;
V_158 = 0 ;
for ( V_234 = 0 ; V_235 [ V_234 ] [ 0 ] [ 0 ] ; V_234 ++ ) {
F_79 ( V_235 [ V_234 ] [ 0 ] ,
V_235 [ V_234 ] [ 1 ] ,
V_235 [ V_234 ] [ 2 ] ,
V_235 [ V_234 ] [ 3 ] ) ;
}
F_52 () ;
V_212 = 1 ;
}
static int F_85 ( struct V_236 * V_237 , unsigned long V_238 ,
void * V_239 )
{
if ( V_35 . V_109 && V_35 . V_110 ) {
switch ( V_238 ) {
case V_240 :
F_50
( L_7 ) ;
break;
case V_241 :
F_50
( L_8 ) ;
break;
case V_242 :
F_50 ( L_9 ) ;
break;
default:
break;
}
}
return V_243 ;
}
static void F_86 ( struct V_244 * V_1 )
{
struct V_245 V_246 ;
if ( V_1 -> V_247 != V_244 )
return;
if ( V_11 ) {
F_87 ( L_10 ,
V_248 , V_1 -> V_247 , V_244 ) ;
return;
}
memset ( & V_246 , 0 , sizeof( V_246 ) ) ;
V_246 . V_249 = & V_11 ;
V_11 = F_88 ( V_1 , L_11 , & V_246 , 0 ) ;
if ( ! V_11 ) {
F_87 ( L_12 ,
V_248 , V_1 -> V_247 , V_244 ) ;
return;
}
if ( F_89 ( V_11 ) ) {
F_87 ( L_13 ,
V_244 ) ;
goto V_250;
}
if ( V_35 . V_109 ) {
F_51 () ;
if ( F_90 ( & V_251 ) )
goto V_250;
}
if ( V_211 . V_109 ) {
F_83 () ;
if ( F_90 ( & V_252 ) )
goto V_253;
}
F_91 ( & V_254 ) ;
return;
V_253:
if ( V_35 . V_109 )
F_92 ( & V_251 ) ;
V_250:
F_93 ( V_11 ) ;
V_11 = NULL ;
}
static void F_94 ( struct V_244 * V_1 )
{
if ( V_1 -> V_247 != V_244 )
return;
if ( ! V_11 ) {
F_87 ( L_14 ,
V_248 , V_1 -> V_247 , V_244 ) ;
return;
}
if ( V_79 . V_80 )
F_95 ( & V_79 ) ;
if ( V_11 ) {
if ( V_211 . V_109 ) {
F_92 ( & V_252 ) ;
V_212 = 0 ;
}
if ( V_35 . V_109 ) {
F_50 ( L_15 V_156
L_16 ) ;
F_92 ( & V_251 ) ;
V_35 . V_110 = false ;
}
F_96 ( V_11 ) ;
F_93 ( V_11 ) ;
V_11 = NULL ;
F_97 ( & V_254 ) ;
}
}
static int T_6 F_98 ( void )
{
int V_255 = V_131 , V_256 ;
switch ( V_257 ) {
case V_258 :
V_255 = V_259 ;
V_111 = V_260 ;
break;
case V_261 :
V_255 = V_262 ;
V_111 = V_112 ;
if ( V_132 == V_131 )
V_132 = 16 ;
if ( V_134 == V_131 )
V_134 = 16 ;
break;
case V_263 :
V_255 = V_264 ;
V_111 = V_119 ;
break;
case V_265 :
V_255 = V_266 ;
V_111 = V_129 ;
break;
case V_267 :
V_255 = V_268 ;
V_111 = V_124 ;
break;
case V_269 :
V_255 = V_262 ;
V_111 = V_112 ;
break;
}
if ( V_270 != V_131 )
V_255 = V_270 ;
if ( V_271 != V_131 )
V_255 = V_271 ;
V_211 . V_109 = ( V_255 > 0 ) ;
if ( V_272 != V_131 )
V_111 = V_272 ;
if ( V_273 != V_131 )
V_111 = V_273 ;
V_35 . V_109 = ( V_111 > 0 ) ;
if ( V_35 . V_109 ) {
V_35 . V_55 = V_130 ;
V_35 . V_84 = V_132 ;
V_35 . V_51 = V_133 ;
V_35 . V_49 = V_134 ;
V_35 . V_115 = V_135 ;
V_35 . V_113 = V_136 ;
V_35 . V_36 . V_117 = V_137 ;
V_35 . V_36 . V_118 = V_139 ;
V_35 . V_36 . V_125 = V_140 ;
V_35 . V_36 . V_122 = V_141 ;
V_35 . V_36 . V_123 = V_142 ;
V_35 . V_36 . V_37 = V_143 ;
V_35 . V_76 . V_93 = - 1 ;
}
switch ( V_255 ) {
case V_262 :
V_235 = V_274 ;
break;
case V_264 :
V_235 = V_275 ;
break;
case V_268 :
V_235 = V_276 ;
break;
default:
V_235 = NULL ;
break;
}
if ( ! V_35 . V_109 && ! V_211 . V_109 ) {
F_87 ( L_17 V_156 L_18 ) ;
return - V_277 ;
}
V_256 = F_99 ( & V_278 ) ;
if ( V_256 ) {
F_87 ( L_19 ) ;
return V_256 ;
}
if ( V_11 )
F_100 ( L_17 V_156
L_20 , V_244 ,
V_11 -> V_1 -> V_279 ) ;
else
F_100 ( L_17 V_156
L_21 ) ;
return 0 ;
}
static void T_7 F_101 ( void )
{
F_102 ( & V_278 ) ;
}
