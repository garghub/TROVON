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
F_21 ( & V_35 ) ;
if ( V_34 )
F_18 ( V_36 , V_6 ) ;
else
F_17 ( V_36 , V_6 ) ;
F_9 () ;
F_22 ( & V_35 ) ;
}
static void F_23 ( int V_34 )
{
if ( V_37 . V_38 . V_39 == V_40 )
return;
F_24 ( & V_37 . V_41 ) ;
if ( ! V_37 . V_42 )
F_20 ( V_34 ) ;
F_25 ( & V_37 . V_41 ) ;
}
static void F_26 ( struct V_43 * V_44 )
{
F_24 ( & V_37 . V_41 ) ;
if ( V_37 . V_42 ) {
V_37 . V_42 = false ;
if ( ! ( V_37 . V_45 & V_46 ) )
F_20 ( 0 ) ;
}
F_25 ( & V_37 . V_41 ) ;
}
static void F_27 ( void )
{
if ( V_37 . V_38 . V_39 == V_40 )
return;
F_28 ( & V_37 . V_47 ) ;
F_24 ( & V_37 . V_41 ) ;
if ( ! V_37 . V_42 && ! ( V_37 . V_45 & V_46 ) )
F_20 ( 1 ) ;
V_37 . V_42 = true ;
F_29 ( & V_37 . V_47 , V_48 * V_49 ) ;
F_25 ( & V_37 . V_41 ) ;
}
static void F_30 ( int V_50 )
{
F_21 ( & V_35 ) ;
F_16 ( 0x1F ) ;
F_16 ( V_50 & 0x0F ) ;
F_16 ( ( V_50 >> 4 ) & 0x0F ) ;
F_19 ( 40 ) ;
F_22 ( & V_35 ) ;
}
static void F_31 ( int V_51 )
{
F_21 ( & V_35 ) ;
F_16 ( 0x5F ) ;
F_16 ( V_51 & 0x0F ) ;
F_16 ( ( V_51 >> 4 ) & 0x0F ) ;
F_19 ( 40 ) ;
F_22 ( & V_35 ) ;
}
static void F_32 ( int V_50 )
{
F_21 ( & V_35 ) ;
F_5 ( V_11 , V_50 ) ;
F_19 ( 20 ) ;
F_18 ( V_52 , V_6 ) ;
F_17 ( V_53 , V_6 ) ;
F_17 ( V_54 , V_6 ) ;
F_6 () ;
F_19 ( 40 ) ;
F_17 ( V_52 , V_6 ) ;
F_6 () ;
F_19 ( 120 ) ;
F_22 ( & V_35 ) ;
}
static void F_33 ( int V_51 )
{
F_21 ( & V_35 ) ;
F_5 ( V_11 , V_51 ) ;
F_19 ( 20 ) ;
F_18 ( V_52 , V_6 ) ;
F_18 ( V_53 , V_6 ) ;
F_17 ( V_54 , V_6 ) ;
F_6 () ;
F_19 ( 40 ) ;
F_17 ( V_52 , V_6 ) ;
F_6 () ;
F_19 ( 45 ) ;
F_22 ( & V_35 ) ;
}
static void F_34 ( int V_50 )
{
F_21 ( & V_35 ) ;
F_8 ( V_11 , V_50 ) ;
F_19 ( 60 ) ;
F_22 ( & V_35 ) ;
}
static void F_35 ( int V_51 )
{
F_21 ( & V_35 ) ;
F_5 ( V_11 , V_51 ) ;
F_19 ( 60 ) ;
F_22 ( & V_35 ) ;
}
static void F_36 ( void )
{
F_37 ( V_55
| ( V_37 . V_56 . V_57 ? V_37 . V_58 : 0 )
| ( ( V_37 . V_56 . V_59 < V_37 . V_60 ) ? V_37 . V_56 . V_59 &
( V_37 . V_58 - 1 ) : V_37 . V_60 - 1 ) ) ;
}
static void F_38 ( void )
{
V_37 . V_56 . V_59 = 0 ;
V_37 . V_56 . V_57 = 0 ;
F_36 () ;
}
static void F_39 ( char V_61 )
{
if ( V_37 . V_56 . V_59 < V_37 . V_60 ) {
if ( V_62 )
V_61 = V_62 [ ( unsigned char ) V_61 ] ;
F_40 ( V_61 ) ;
V_37 . V_56 . V_59 ++ ;
}
if ( V_37 . V_56 . V_59 == V_37 . V_60 )
F_36 () ;
}
static void F_41 ( void )
{
int V_63 ;
F_38 () ;
F_21 ( & V_35 ) ;
for ( V_63 = 0 ; V_63 < V_37 . V_64 * V_37 . V_58 ; V_63 ++ ) {
F_16 ( 0x5F ) ;
F_16 ( ' ' & 0x0F ) ;
F_16 ( ( ' ' >> 4 ) & 0x0F ) ;
F_19 ( 40 ) ;
}
F_22 ( & V_35 ) ;
F_38 () ;
}
static void F_42 ( void )
{
int V_63 ;
F_38 () ;
F_21 ( & V_35 ) ;
for ( V_63 = 0 ; V_63 < V_37 . V_64 * V_37 . V_58 ; V_63 ++ ) {
F_5 ( V_11 , ' ' ) ;
F_19 ( 20 ) ;
F_18 ( V_52 , V_6 ) ;
F_18 ( V_53 , V_6 ) ;
F_17 ( V_54 , V_6 ) ;
F_6 () ;
F_19 ( 40 ) ;
F_17 ( V_52 , V_6 ) ;
F_6 () ;
F_19 ( 45 ) ;
}
F_22 ( & V_35 ) ;
F_38 () ;
}
static void F_43 ( void )
{
int V_63 ;
F_38 () ;
F_21 ( & V_35 ) ;
for ( V_63 = 0 ; V_63 < V_37 . V_64 * V_37 . V_58 ; V_63 ++ ) {
F_5 ( V_11 , ' ' ) ;
F_19 ( 60 ) ;
}
F_22 ( & V_35 ) ;
F_38 () ;
}
static void F_44 ( void )
{
F_37 ( V_65 ) ;
V_37 . V_56 . V_59 = 0 ;
V_37 . V_56 . V_57 = 0 ;
F_11 ( 15 ) ;
}
static void F_45 ( void )
{
V_37 . V_45 = ( ( V_37 . V_64 > 1 ) ? V_66 : 0 )
| V_67 | V_68 | V_69 ;
F_11 ( 20 ) ;
F_37 ( V_70 | V_71 ) ;
F_11 ( 10 ) ;
F_37 ( V_70 | V_71 ) ;
F_11 ( 10 ) ;
F_37 ( V_70 | V_71 ) ;
F_11 ( 10 ) ;
F_37 ( V_70 | V_71
| ( ( V_37 . V_45 & V_72 ) ? V_73 : 0 )
| ( ( V_37 . V_45 & V_66 ) ? V_74 : 0 )
) ;
F_11 ( 10 ) ;
F_37 ( V_75 ) ;
F_11 ( 10 ) ;
F_37 ( V_75
| ( ( V_37 . V_45 & V_67 ) ? V_76 : 0 )
| ( ( V_37 . V_45 & V_68 ) ? V_77 : 0 )
| ( ( V_37 . V_45 & V_69 ) ? V_78 : 0 )
) ;
F_23 ( ( V_37 . V_45 & V_46 ) ? 1 : 0 ) ;
F_11 ( 10 ) ;
F_37 ( V_79 | V_80 ) ;
F_44 () ;
}
static inline int F_46 ( void )
{
int V_81 = 0 ;
char * V_82 = V_37 . V_83 . V_84 + 2 ;
int V_85 = V_37 . V_45 ;
switch ( * V_82 ) {
case 'D' :
V_37 . V_45 |= V_67 ;
V_81 = 1 ;
break;
case 'd' :
V_37 . V_45 &= ~ V_67 ;
V_81 = 1 ;
break;
case 'C' :
V_37 . V_45 |= V_68 ;
V_81 = 1 ;
break;
case 'c' :
V_37 . V_45 &= ~ V_68 ;
V_81 = 1 ;
break;
case 'B' :
V_37 . V_45 |= V_69 ;
V_81 = 1 ;
break;
case 'b' :
V_37 . V_45 &= ~ V_69 ;
V_81 = 1 ;
break;
case '+' :
V_37 . V_45 |= V_46 ;
V_81 = 1 ;
break;
case '-' :
V_37 . V_45 &= ~ V_46 ;
V_81 = 1 ;
break;
case '*' :
F_27 () ;
V_81 = 1 ;
break;
case 'f' :
V_37 . V_45 &= ~ V_72 ;
V_81 = 1 ;
break;
case 'F' :
V_37 . V_45 |= V_72 ;
V_81 = 1 ;
break;
case 'n' :
V_37 . V_45 &= ~ V_66 ;
V_81 = 1 ;
break;
case 'N' :
V_37 . V_45 |= V_66 ;
break;
case 'l' :
if ( V_37 . V_56 . V_59 > 0 ) {
if ( V_37 . V_56 . V_59 < V_37 . V_60 )
F_37 ( V_86 ) ;
V_37 . V_56 . V_59 -- ;
}
V_81 = 1 ;
break;
case 'r' :
if ( V_37 . V_56 . V_59 < V_37 . V_87 ) {
if ( V_37 . V_56 . V_59 < ( V_37 . V_60 - 1 ) )
F_37 ( V_86 |
V_88 ) ;
V_37 . V_56 . V_59 ++ ;
}
V_81 = 1 ;
break;
case 'L' :
F_37 ( V_86 | V_89 ) ;
V_81 = 1 ;
break;
case 'R' :
F_37 ( V_86 | V_89 |
V_88 ) ;
V_81 = 1 ;
break;
case 'k' : {
int V_59 ;
for ( V_59 = V_37 . V_56 . V_59 ; V_59 < V_37 . V_60 ; V_59 ++ )
F_40 ( ' ' ) ;
F_36 () ;
V_81 = 1 ;
break;
}
case 'I' :
F_45 () ;
V_81 = 1 ;
break;
case 'G' : {
unsigned char V_90 [ 8 ] ;
unsigned char V_91 ;
int V_92 ;
int V_93 ;
char V_94 ;
int V_56 ;
if ( ! strchr ( V_82 , ';' ) )
break;
V_82 ++ ;
V_91 = * ( V_82 ++ ) - '0' ;
if ( V_91 > 7 ) {
V_81 = 1 ;
break;
}
V_92 = 0 ;
V_93 = 0 ;
V_94 = 0 ;
while ( * V_82 && V_92 < 8 ) {
V_93 ^= 4 ;
if ( * V_82 >= '0' && * V_82 <= '9' ) {
V_94 |= ( * V_82 - '0' ) << V_93 ;
} else if ( * V_82 >= 'A' && * V_82 <= 'Z' ) {
V_94 |= ( * V_82 - 'A' + 10 ) << V_93 ;
} else if ( * V_82 >= 'a' && * V_82 <= 'z' ) {
V_94 |= ( * V_82 - 'a' + 10 ) << V_93 ;
} else {
V_82 ++ ;
continue;
}
if ( V_93 == 0 ) {
V_90 [ V_92 ++ ] = V_94 ;
V_94 = 0 ;
}
V_82 ++ ;
}
F_37 ( V_95 | ( V_91 * 8 ) ) ;
for ( V_56 = 0 ; V_56 < V_92 ; V_56 ++ )
F_40 ( V_90 [ V_56 ] ) ;
F_36 () ;
V_81 = 1 ;
break;
}
case 'x' :
case 'y' :
if ( ! strchr ( V_82 , ';' ) )
break;
while ( * V_82 ) {
if ( * V_82 == 'x' ) {
V_82 ++ ;
if ( F_47 ( V_82 , 10 , & V_37 . V_56 . V_59 ) < 0 )
break;
} else if ( * V_82 == 'y' ) {
V_82 ++ ;
if ( F_47 ( V_82 , 10 , & V_37 . V_56 . V_57 ) < 0 )
break;
} else {
break;
}
}
F_36 () ;
V_81 = 1 ;
break;
}
if ( V_85 != V_37 . V_45 ) {
if ( ( V_85 ^ V_37 . V_45 ) &
( V_69 | V_68 | V_67 ) )
F_37 ( V_75
| ( ( V_37 . V_45 & V_67 )
? V_76 : 0 )
| ( ( V_37 . V_45 & V_68 )
? V_77 : 0 )
| ( ( V_37 . V_45 & V_69 )
? V_78 : 0 ) ) ;
else if ( ( V_85 ^ V_37 . V_45 ) & ( V_72 | V_66 ) )
F_37 ( V_70
| V_71
| ( ( V_37 . V_45 & V_72 )
? V_73
: 0 )
| ( ( V_37 . V_45 & V_66 )
? V_74
: 0 ) ) ;
else if ( ( V_85 ^ V_37 . V_45 ) & ( V_46 ) )
F_23 ( ! ! ( V_37 . V_45 & V_46 ) ) ;
}
return V_81 ;
}
static void F_48 ( char V_61 )
{
if ( ( V_61 != '\n' ) && V_37 . V_83 . V_96 >= 0 ) {
V_37 . V_83 . V_84 [ V_37 . V_83 . V_96 ++ ] = V_61 ;
V_37 . V_83 . V_84 [ V_37 . V_83 . V_96 ] = 0 ;
} else {
V_37 . V_83 . V_96 = - 1 ;
switch ( V_61 ) {
case V_97 :
V_37 . V_83 . V_96 = 0 ;
V_37 . V_83 . V_84 [ V_37 . V_83 . V_96 ] = 0 ;
break;
case '\b' :
if ( V_37 . V_56 . V_59 > 0 ) {
if ( V_37 . V_56 . V_59 < V_37 . V_60 )
F_37 ( V_86 ) ;
V_37 . V_56 . V_59 -- ;
}
F_40 ( ' ' ) ;
F_37 ( V_86 ) ;
break;
case '\014' :
F_49 () ;
break;
case '\n' :
for (; V_37 . V_56 . V_59 < V_37 . V_60 ; V_37 . V_56 . V_59 ++ )
F_40 ( ' ' ) ;
V_37 . V_56 . V_59 = 0 ;
V_37 . V_56 . V_57 = ( V_37 . V_56 . V_57 + 1 ) % V_37 . V_64 ;
F_36 () ;
break;
case '\r' :
V_37 . V_56 . V_59 = 0 ;
F_36 () ;
break;
case '\t' :
F_39 ( ' ' ) ;
break;
default:
F_39 ( V_61 ) ;
break;
}
}
if ( V_37 . V_83 . V_96 >= 2 ) {
int V_81 = 0 ;
if ( ! strcmp ( V_37 . V_83 . V_84 , L_1 ) ) {
F_49 () ;
V_81 = 1 ;
} else if ( ! strcmp ( V_37 . V_83 . V_84 , L_2 ) ) {
F_38 () ;
V_81 = 1 ;
}
else if ( ( V_37 . V_83 . V_96 >= 3 ) &&
( V_37 . V_83 . V_84 [ 0 ] == '[' ) &&
( V_37 . V_83 . V_84 [ 1 ] == 'L' ) ) {
V_81 = F_46 () ;
}
if ( V_81 || ( V_37 . V_83 . V_96 >= V_98 ) )
V_37 . V_83 . V_96 = - 1 ;
}
}
static T_1 F_50 ( struct V_99 * V_99 ,
const char T_2 * V_84 , T_3 V_100 , T_4 * V_101 )
{
const char T_2 * V_102 = V_84 ;
char V_61 ;
for (; V_100 -- > 0 ; ( * V_101 ) ++ , V_102 ++ ) {
if ( ! F_12 () && ( ( ( V_100 + 1 ) & 0x1f ) == 0 ) )
F_51 () ;
if ( F_52 ( V_61 , V_102 ) )
return - V_103 ;
F_48 ( V_61 ) ;
}
return V_102 - V_84 ;
}
static int F_53 ( struct V_104 * V_104 , struct V_99 * V_99 )
{
if ( ! F_54 ( & V_105 ) )
return - V_106 ;
if ( V_99 -> V_107 & V_108 )
return - V_109 ;
if ( V_37 . V_110 ) {
F_44 () ;
V_37 . V_110 = false ;
}
return F_55 ( V_104 , V_99 ) ;
}
static int F_56 ( struct V_104 * V_104 , struct V_99 * V_99 )
{
F_57 ( & V_105 ) ;
return 0 ;
}
static void F_58 ( const char * V_111 )
{
const char * V_102 = V_111 ;
int V_100 = strlen ( V_111 ) ;
if ( V_37 . V_112 && V_37 . V_113 ) {
for (; V_100 -- > 0 ; V_102 ++ ) {
if ( ! F_12 () && ( ( ( V_100 + 1 ) & 0x1f ) == 0 ) )
F_51 () ;
F_48 ( * V_102 ) ;
}
}
}
static void F_59 ( void )
{
switch ( V_114 ) {
case V_115 :
V_37 . V_116 = V_117 ;
V_37 . V_118 = V_119 ;
V_37 . V_38 . V_120 = V_20 ;
V_37 . V_38 . V_121 = V_24 ;
V_37 . V_87 = 40 ;
V_37 . V_60 = 40 ;
V_37 . V_58 = 64 ;
V_37 . V_64 = 2 ;
break;
case V_122 :
V_37 . V_116 = V_123 ;
V_37 . V_118 = V_124 ;
V_37 . V_38 . V_39 = V_24 ;
V_37 . V_38 . V_125 = V_20 ;
V_37 . V_38 . V_126 = V_22 ;
V_37 . V_87 = 16 ;
V_37 . V_60 = 40 ;
V_37 . V_58 = 16 ;
V_37 . V_64 = 2 ;
break;
case V_127 :
V_37 . V_116 = V_117 ;
V_37 . V_118 = V_119 ;
V_37 . V_38 . V_120 = V_24 ;
V_37 . V_38 . V_121 = V_28 ;
V_37 . V_38 . V_128 = V_26 ;
V_37 . V_87 = 16 ;
V_37 . V_60 = 40 ;
V_37 . V_58 = 64 ;
V_37 . V_64 = 2 ;
break;
case V_129 :
V_37 . V_116 = V_130 ;
V_37 . V_118 = V_131 ;
break;
case V_132 :
default:
V_37 . V_116 = V_117 ;
V_37 . V_118 = V_119 ;
V_37 . V_38 . V_120 = V_20 ;
V_37 . V_38 . V_121 = V_28 ;
V_37 . V_87 = 16 ;
V_37 . V_60 = 40 ;
V_37 . V_58 = 64 ;
V_37 . V_64 = 2 ;
break;
}
if ( V_133 != V_134 )
V_37 . V_64 = V_133 ;
if ( V_135 != V_134 )
V_37 . V_87 = V_135 ;
if ( V_136 != V_134 )
V_37 . V_60 = V_136 ;
if ( V_137 != V_134 )
V_37 . V_58 = V_137 ;
if ( V_138 != V_134 )
V_37 . V_118 = V_138 ;
if ( V_139 != V_134 )
V_37 . V_116 = V_139 ;
if ( V_140 != V_141 )
V_37 . V_38 . V_120 = V_140 ;
if ( V_142 != V_141 )
V_37 . V_38 . V_121 = V_142 ;
if ( V_143 != V_141 )
V_37 . V_38 . V_128 = V_143 ;
if ( V_144 != V_141 )
V_37 . V_38 . V_125 = V_144 ;
if ( V_145 != V_141 )
V_37 . V_38 . V_126 = V_145 ;
if ( V_146 != V_141 )
V_37 . V_38 . V_39 = V_146 ;
if ( V_37 . V_87 <= 0 )
V_37 . V_87 = V_147 ;
if ( V_37 . V_60 <= 0 )
V_37 . V_60 = V_148 ;
if ( V_37 . V_58 <= 0 )
V_37 . V_58 = V_149 ;
if ( V_37 . V_64 <= 0 )
V_37 . V_64 = V_150 ;
if ( V_37 . V_116 == V_123 ) {
F_37 = F_30 ;
F_40 = F_31 ;
F_49 = F_41 ;
if ( V_37 . V_38 . V_125 == V_141 )
V_37 . V_38 . V_125 = V_151 ;
if ( V_37 . V_38 . V_126 == V_141 )
V_37 . V_38 . V_126 = V_152 ;
} else if ( V_37 . V_116 == V_117 ) {
F_37 = F_32 ;
F_40 = F_33 ;
F_49 = F_42 ;
if ( V_37 . V_38 . V_120 == V_141 )
V_37 . V_38 . V_120 = V_153 ;
if ( V_37 . V_38 . V_121 == V_141 )
V_37 . V_38 . V_121 = V_154 ;
if ( V_37 . V_38 . V_128 == V_141 )
V_37 . V_38 . V_128 = V_155 ;
} else {
F_37 = F_34 ;
F_40 = F_35 ;
F_49 = F_43 ;
}
if ( V_37 . V_38 . V_39 == V_141 )
V_37 . V_38 . V_39 = V_156 ;
if ( V_37 . V_38 . V_120 == V_141 )
V_37 . V_38 . V_120 = V_40 ;
if ( V_37 . V_38 . V_121 == V_141 )
V_37 . V_38 . V_121 = V_40 ;
if ( V_37 . V_38 . V_128 == V_141 )
V_37 . V_38 . V_128 = V_40 ;
if ( V_37 . V_38 . V_39 == V_141 )
V_37 . V_38 . V_39 = V_40 ;
if ( V_37 . V_38 . V_125 == V_141 )
V_37 . V_38 . V_125 = V_40 ;
if ( V_37 . V_38 . V_126 == V_141 )
V_37 . V_38 . V_126 = V_40 ;
if ( V_37 . V_118 == V_134 )
V_37 . V_118 = V_131 ;
if ( V_37 . V_118 == V_124 )
V_62 = V_157 ;
else
V_62 = NULL ;
if ( V_37 . V_38 . V_39 != V_40 ) {
F_60 ( & V_37 . V_41 ) ;
F_61 ( & V_37 . V_47 , F_26 ) ;
}
F_10 ( V_37 . V_38 . V_120 , V_9 [ V_12 ] [ V_52 ] ,
V_9 [ V_13 ] [ V_52 ] ) ;
F_10 ( V_37 . V_38 . V_121 , V_9 [ V_12 ] [ V_53 ] ,
V_9 [ V_13 ] [ V_53 ] ) ;
F_10 ( V_37 . V_38 . V_128 , V_9 [ V_12 ] [ V_54 ] ,
V_9 [ V_13 ] [ V_54 ] ) ;
F_10 ( V_37 . V_38 . V_39 , V_9 [ V_12 ] [ V_36 ] ,
V_9 [ V_13 ] [ V_36 ] ) ;
F_10 ( V_37 . V_38 . V_125 , V_9 [ V_12 ] [ V_32 ] ,
V_9 [ V_13 ] [ V_32 ] ) ;
F_10 ( V_37 . V_38 . V_126 , V_9 [ V_12 ] [ V_33 ] ,
V_9 [ V_13 ] [ V_33 ] ) ;
V_37 . V_113 = true ;
F_45 () ;
#ifdef F_62
#ifdef F_63
F_58 ( L_3 F_63 ) ;
#endif
#else
F_58 ( L_4 V_158 ) ;
#endif
V_37 . V_110 = true ;
F_38 () ;
}
static T_1 F_64 ( struct V_99 * V_99 ,
char T_2 * V_84 , T_3 V_100 , T_4 * V_101 )
{
unsigned V_159 = * V_101 ;
char T_2 * V_102 = V_84 ;
if ( V_160 == 0 ) {
if ( V_99 -> V_161 & V_162 )
return - V_163 ;
if ( F_65 ( V_164 ,
V_160 != 0 ) )
return - V_165 ;
}
for (; V_100 -- > 0 && ( V_160 > 0 ) ;
++ V_159 , ++ V_102 , -- V_160 ) {
F_66 ( V_166 [ V_167 ] , V_102 ) ;
V_167 = ( V_167 + 1 ) % V_168 ;
}
* V_101 = V_159 ;
return V_102 - V_84 ;
}
static int F_67 ( struct V_104 * V_104 , struct V_99 * V_99 )
{
if ( ! F_54 ( & V_169 ) )
return - V_106 ;
if ( V_99 -> V_107 & V_170 )
return - V_109 ;
V_160 = 0 ;
return 0 ;
}
static int F_68 ( struct V_104 * V_104 , struct V_99 * V_99 )
{
F_57 ( & V_169 ) ;
return 0 ;
}
static void F_69 ( const char * string , int V_171 )
{
if ( ! F_70 ( & V_169 ) ) {
while ( V_171 -- && V_160 < V_168 && * string ) {
V_166 [ ( V_167 + V_160 ++ ) %
V_168 ] = * string ++ ;
}
F_71 ( & V_164 ) ;
}
}
static void F_72 ( void )
{
int V_3 , V_172 ;
char V_173 ;
char V_174 ;
char V_175 ;
V_176 = V_177 ;
V_178 = V_179 ;
V_179 = 0 ;
V_173 = F_4 ( V_11 ) | V_180 ;
F_5 ( V_11 , V_173 & ~ V_180 ) ;
V_174 = F_73 ( F_74 ( V_11 ) ) & V_181 ;
F_5 ( V_11 , V_173 ) ;
V_175 = F_73 ( F_74 ( V_11 ) ) & V_181 ;
V_179 |= ( V_182 ) V_175 << 40 ;
if ( V_174 != V_175 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_172 = F_75 ( V_3 ) ;
if ( ! ( V_180 & V_172 ) )
continue;
F_5 ( V_11 , V_173 & ~ V_172 ) ;
V_174 = F_73 ( F_74 ( V_11 ) ) & ~ V_175 ;
V_179 |= ( V_182 ) V_174 << ( 5 * V_3 ) ;
}
F_5 ( V_11 , V_173 ) ;
}
V_177 = ( V_176 & ( V_179 ^ V_178 ) ) |
( V_179 & ~ ( V_179 ^ V_178 ) ) ;
}
static inline int F_76 ( struct V_183 * V_184 )
{
#if 0
if (((phys_prev & input->mask) == input->value) &&
((phys_curr & input->mask) > input->value)) {
input->state = INPUT_ST_LOW;
return 1;
}
#endif
if ( ( V_177 & V_184 -> V_185 ) == V_184 -> V_94 ) {
if ( ( V_184 -> type == V_186 ) &&
( V_184 -> V_187 == 0 ) ) {
V_184 -> V_187 ++ ;
if ( V_184 -> V_188 . V_189 . V_190 )
V_184 -> V_188 . V_189 . V_190 ( V_184 -> V_188 . V_189 . V_191 ) ;
} else if ( V_184 -> type == V_192 ) {
V_193 = 1 ;
if ( V_184 -> V_187 == 0 ) {
char * V_194 = V_184 -> V_188 . V_195 . V_194 ;
if ( V_194 [ 0 ] ) {
int V_111 = sizeof( V_184 -> V_188 . V_195 . V_194 ) ;
F_69 ( V_194 , V_111 ) ;
}
}
if ( V_184 -> V_188 . V_195 . V_196 [ 0 ] ) {
char * V_196 = V_184 -> V_188 . V_195 . V_196 ;
if ( V_184 -> V_187 >= V_197 ) {
int V_111 = sizeof( V_184 -> V_188 . V_195 . V_196 ) ;
V_184 -> V_187 -= V_198 ;
F_69 ( V_196 , V_111 ) ;
}
V_199 = 0 ;
}
if ( V_184 -> V_187 < 255 )
V_184 -> V_187 ++ ;
}
return 1 ;
}
V_184 -> V_4 = V_200 ;
V_184 -> V_201 = 0 ;
return 0 ;
}
static inline void F_77 ( struct V_183 * V_184 )
{
#if 0
if (((phys_prev & input->mask) == input->value) &&
((phys_curr & input->mask) > input->value)) {
input->state = INPUT_ST_LOW;
return;
}
#endif
if ( ( V_177 & V_184 -> V_185 ) == V_184 -> V_94 ) {
if ( V_184 -> type == V_192 ) {
V_193 = 1 ;
if ( V_184 -> V_188 . V_195 . V_196 [ 0 ] ) {
char * V_196 = V_184 -> V_188 . V_195 . V_196 ;
if ( V_184 -> V_187 >= V_197 ) {
int V_111 = sizeof( V_184 -> V_188 . V_195 . V_196 ) ;
V_184 -> V_187 -= V_198 ;
F_69 ( V_196 , V_111 ) ;
}
V_199 = 0 ;
}
if ( V_184 -> V_187 < 255 )
V_184 -> V_187 ++ ;
}
V_184 -> V_4 = V_202 ;
} else if ( V_184 -> V_201 >= V_184 -> V_203 ) {
if ( V_184 -> type == V_186 ) {
void (* F_78)( int ) = V_184 -> V_188 . V_189 . F_78 ;
if ( F_78 )
F_78 ( V_184 -> V_188 . V_189 . V_204 ) ;
} else if ( V_184 -> type == V_192 ) {
char * V_205 = V_184 -> V_188 . V_195 . V_205 ;
if ( V_205 [ 0 ] ) {
int V_111 = sizeof( V_184 -> V_188 . V_195 . V_205 ) ;
F_69 ( V_205 , V_111 ) ;
}
}
V_184 -> V_4 = V_206 ;
} else {
V_184 -> V_201 ++ ;
V_199 = 0 ;
}
}
static void F_79 ( void )
{
struct V_207 * V_208 ;
struct V_183 * V_184 ;
V_193 = 0 ;
V_199 = 1 ;
F_80 (item, &logical_inputs) {
V_184 = F_81 ( V_208 , struct V_183 , V_209 ) ;
switch ( V_184 -> V_4 ) {
case V_206 :
if ( ( V_177 & V_184 -> V_185 ) != V_184 -> V_94 )
break;
if ( ( V_176 & V_184 -> V_185 ) == V_184 -> V_94 )
break;
V_184 -> V_210 = 0 ;
V_184 -> V_4 = V_211 ;
case V_211 :
if ( ( V_177 & V_184 -> V_185 ) != V_184 -> V_94 ) {
V_184 -> V_4 = V_206 ;
break;
}
if ( V_184 -> V_210 < V_184 -> V_212 ) {
V_199 = 0 ;
V_184 -> V_210 ++ ;
break;
}
V_184 -> V_187 = 0 ;
V_184 -> V_4 = V_202 ;
case V_202 :
if ( F_76 ( V_184 ) )
break;
case V_200 :
F_77 ( V_184 ) ;
}
}
}
static void F_82 ( void )
{
if ( V_213 . V_112 && V_214 ) {
if ( F_83 ( & V_35 ) ) {
F_72 () ;
F_22 ( & V_35 ) ;
}
if ( ! V_199 || V_177 != V_176 )
F_79 () ;
}
if ( V_193 && V_37 . V_112 && V_37 . V_113 )
F_27 () ;
F_84 ( & V_215 , V_216 + V_217 ) ;
}
static void F_85 ( void )
{
if ( V_215 . V_218 )
return;
F_86 ( & V_215 , ( void * ) & F_82 , 0 ) ;
V_215 . V_219 = V_216 + V_217 ;
F_87 ( & V_215 ) ;
}
static T_5 F_88 ( const char * V_220 , V_182 * V_185 , V_182 * V_94 ,
T_5 * V_221 , T_5 * V_222 )
{
const char V_223 [] = L_5 ;
T_5 V_224 , V_225 ;
V_182 V_226 , V_227 ;
V_225 = 0 ;
V_224 = 0 ;
V_226 = 0ULL ;
V_227 = 0ULL ;
while ( * V_220 ) {
int V_228 , V_229 , V_3 , V_230 ;
const char * V_231 ;
V_231 = strchr ( V_223 , * V_220 ) ;
if ( ! V_231 )
return 0 ;
V_228 = V_231 - V_223 ;
V_230 = ( V_228 & 1 ) ;
V_228 >>= 1 ;
V_224 |= F_75 ( V_228 ) ;
V_220 ++ ;
if ( * V_220 >= '0' && * V_220 <= '7' ) {
V_229 = * V_220 - '0' ;
V_225 |= F_75 ( V_229 ) ;
} else if ( * V_220 == '-' ) {
V_229 = 8 ;
} else {
return 0 ;
}
V_3 = ( V_229 * 5 ) + V_228 ;
V_226 |= 1ULL << V_3 ;
if ( ! V_230 )
V_227 |= 1ULL << V_3 ;
V_220 ++ ;
}
* V_185 = V_226 ;
* V_94 = V_227 ;
if ( V_221 )
* V_221 |= V_224 ;
if ( V_222 )
* V_222 |= V_225 ;
return 1 ;
}
static struct V_183 * F_89 ( const char * V_220 , const char * V_232 ,
const char * V_233 ,
const char * V_234 )
{
struct V_183 * V_235 ;
V_235 = F_90 ( sizeof( * V_235 ) , V_236 ) ;
if ( ! V_235 )
return NULL ;
if ( ! F_88 ( V_220 , & V_235 -> V_185 , & V_235 -> V_94 , & V_181 ,
& V_180 ) ) {
F_91 ( V_235 ) ;
return NULL ;
}
V_235 -> type = V_192 ;
V_235 -> V_4 = V_206 ;
V_235 -> V_212 = 1 ;
V_235 -> V_203 = 1 ;
strncpy ( V_235 -> V_188 . V_195 . V_194 , V_232 , sizeof( V_235 -> V_188 . V_195 . V_194 ) ) ;
strncpy ( V_235 -> V_188 . V_195 . V_196 , V_233 , sizeof( V_235 -> V_188 . V_195 . V_196 ) ) ;
strncpy ( V_235 -> V_188 . V_195 . V_205 , V_234 ,
sizeof( V_235 -> V_188 . V_195 . V_205 ) ) ;
F_92 ( & V_235 -> V_209 , & V_237 ) ;
return V_235 ;
}
static void F_93 ( void )
{
int V_238 ;
F_94 ( & V_164 ) ;
V_160 = 0 ;
for ( V_238 = 0 ; V_239 [ V_238 ] [ 0 ] [ 0 ] ; V_238 ++ ) {
F_89 ( V_239 [ V_238 ] [ 0 ] ,
V_239 [ V_238 ] [ 1 ] ,
V_239 [ V_238 ] [ 2 ] ,
V_239 [ V_238 ] [ 3 ] ) ;
}
F_85 () ;
V_214 = 1 ;
}
static int F_95 ( struct V_240 * V_241 , unsigned long V_242 ,
void * V_243 )
{
if ( V_37 . V_112 && V_37 . V_113 ) {
switch ( V_242 ) {
case V_244 :
F_58
( L_6 ) ;
break;
case V_245 :
F_58
( L_7 ) ;
break;
case V_246 :
F_58 ( L_8 ) ;
break;
default:
break;
}
}
return V_247 ;
}
static void F_96 ( struct V_248 * V_1 )
{
struct V_249 V_250 ;
if ( V_1 -> V_251 != V_248 )
return;
if ( V_11 ) {
F_97 ( L_9 ,
V_252 , V_1 -> V_251 , V_248 ) ;
return;
}
memset ( & V_250 , 0 , sizeof( V_250 ) ) ;
V_250 . V_253 = & V_11 ;
V_11 = F_98 ( V_1 , L_10 , & V_250 , 0 ) ;
if ( ! V_11 ) {
F_97 ( L_11 ,
V_252 , V_1 -> V_251 , V_248 ) ;
return;
}
if ( F_99 ( V_11 ) ) {
F_97 ( L_12 ,
V_248 ) ;
goto V_254;
}
if ( V_37 . V_112 ) {
F_59 () ;
if ( F_100 ( & V_255 ) )
goto V_254;
}
if ( V_213 . V_112 ) {
F_93 () ;
if ( F_100 ( & V_256 ) )
goto V_257;
}
F_101 ( & V_258 ) ;
return;
V_257:
if ( V_37 . V_112 )
F_102 ( & V_255 ) ;
V_254:
F_103 ( V_11 ) ;
V_11 = NULL ;
}
static void F_104 ( struct V_248 * V_1 )
{
if ( V_1 -> V_251 != V_248 )
return;
if ( ! V_11 ) {
F_97 ( L_13 ,
V_252 , V_1 -> V_251 , V_248 ) ;
return;
}
if ( V_215 . V_218 )
F_105 ( & V_215 ) ;
if ( V_213 . V_112 ) {
F_102 ( & V_256 ) ;
V_214 = 0 ;
}
if ( V_37 . V_112 ) {
F_58 ( L_14 ) ;
F_102 ( & V_255 ) ;
if ( V_37 . V_38 . V_39 != V_40 ) {
F_28 ( & V_37 . V_47 ) ;
F_20 ( 0 ) ;
}
V_37 . V_113 = false ;
}
F_106 ( V_11 ) ;
F_103 ( V_11 ) ;
V_11 = NULL ;
F_107 ( & V_258 ) ;
}
static int T_6 F_108 ( void )
{
int V_259 = V_134 , V_260 ;
switch ( V_261 ) {
case V_262 :
V_259 = V_263 ;
V_114 = V_264 ;
break;
case V_265 :
V_259 = V_266 ;
V_114 = V_115 ;
if ( V_135 == V_134 )
V_135 = 16 ;
if ( V_137 == V_134 )
V_137 = 16 ;
break;
case V_267 :
V_259 = V_268 ;
V_114 = V_122 ;
break;
case V_269 :
V_259 = V_270 ;
V_114 = V_132 ;
break;
case V_271 :
V_259 = V_272 ;
V_114 = V_127 ;
break;
case V_273 :
V_259 = V_266 ;
V_114 = V_115 ;
break;
}
if ( V_274 != V_134 )
V_259 = V_274 ;
if ( V_275 != V_134 )
V_259 = V_275 ;
V_213 . V_112 = ( V_259 > 0 ) ;
if ( V_276 != V_134 )
V_114 = V_276 ;
if ( V_277 != V_134 )
V_114 = V_277 ;
V_37 . V_112 = ( V_114 > 0 ) ;
if ( V_37 . V_112 ) {
V_37 . V_64 = V_133 ;
V_37 . V_87 = V_135 ;
V_37 . V_60 = V_136 ;
V_37 . V_58 = V_137 ;
V_37 . V_118 = V_138 ;
V_37 . V_116 = V_139 ;
V_37 . V_38 . V_120 = V_140 ;
V_37 . V_38 . V_121 = V_142 ;
V_37 . V_38 . V_128 = V_143 ;
V_37 . V_38 . V_125 = V_144 ;
V_37 . V_38 . V_126 = V_145 ;
V_37 . V_38 . V_39 = V_146 ;
V_37 . V_83 . V_96 = - 1 ;
}
switch ( V_259 ) {
case V_266 :
V_239 = V_278 ;
break;
case V_268 :
V_239 = V_279 ;
break;
case V_272 :
V_239 = V_280 ;
break;
default:
V_239 = NULL ;
break;
}
if ( ! V_37 . V_112 && ! V_213 . V_112 ) {
F_97 ( L_15 ) ;
return - V_281 ;
}
V_260 = F_109 ( & V_282 ) ;
if ( V_260 ) {
F_97 ( L_16 ) ;
return V_260 ;
}
if ( V_11 )
F_110 ( L_17 ,
V_248 , V_11 -> V_1 -> V_283 ) ;
else
F_110 ( L_18 ) ;
return 0 ;
}
static void T_7 F_111 ( void )
{
F_112 ( & V_282 ) ;
}
