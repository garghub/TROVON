static int F_1 ( void )
{
int V_1 , V_2 ;
V_1 = F_2 ( V_3 ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ )
V_1 &= V_5 [ V_6 ] [ V_2 ] [ V_7 ] ;
V_1 |= V_5 [ V_6 ] [ V_8 ] [ V_9 . V_10 ]
| V_5 [ V_6 ] [ V_11 ] [ V_9 . V_12 ]
| V_5 [ V_6 ] [ V_13 ] [ V_9 . V_14 ]
| V_5 [ V_6 ] [ V_15 ] [ V_9 . V_16 ]
| V_5 [ V_6 ] [ V_17 ] [ V_9 . V_18 ]
| V_5 [ V_6 ] [ V_19 ] [ V_9 . V_20 ] ;
F_3 ( V_3 , V_1 ) ;
return V_1 ;
}
static int F_4 ( void )
{
int V_1 , V_2 ;
V_1 = F_5 ( V_3 ) ;
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ )
V_1 &= V_5 [ V_21 ] [ V_2 ] [ V_7 ] ;
V_1 |= V_5 [ V_21 ] [ V_8 ] [ V_9 . V_10 ]
| V_5 [ V_21 ] [ V_11 ] [ V_9 . V_12 ]
| V_5 [ V_21 ] [ V_13 ] [ V_9 . V_14 ]
| V_5 [ V_21 ] [ V_15 ] [ V_9 . V_16 ]
| V_5 [ V_21 ] [ V_17 ] [ V_9 . V_18 ]
| V_5 [ V_21 ] [ V_19 ] [ V_9 . V_20 ] ;
F_6 ( V_3 , V_1 ) ;
return V_1 ;
}
static void F_7 ( void )
{
F_1 () ;
F_4 () ;
}
void F_8 ( int V_22 , unsigned char * V_23 , unsigned char * V_24 )
{
int V_25 , V_26 , V_27 ;
V_23 [ 0 ] = V_24 [ 0 ] = V_23 [ 1 ] = V_24 [ 1 ] = 0 ;
V_23 [ 2 ] = V_24 [ 2 ] = 0xFF ;
if ( V_22 == 0 )
return;
V_27 = ( V_22 < 0 ) ;
if ( V_27 )
V_22 = - V_22 ;
V_25 = V_26 = 0 ;
switch ( V_22 ) {
case V_28 :
V_26 = V_29 ;
V_27 = ! V_27 ;
break;
case V_30 ... V_31 :
V_25 = 1 << ( V_22 - 2 ) ;
break;
case V_32 :
V_26 = V_33 ;
V_27 = ! V_27 ;
break;
case V_34 :
V_26 = V_35 ;
break;
case V_36 :
V_26 = V_37 ;
V_27 = ! V_27 ;
break;
default:
break;
}
if ( V_26 ) {
V_24 [ 2 ] &= ~ V_26 ;
V_24 [ ! V_27 ] = V_26 ;
} else if ( V_25 ) {
V_23 [ 2 ] &= ~ V_25 ;
V_23 [ ! V_27 ] = V_25 ;
}
}
static void F_9 ( int V_38 )
{
if ( F_10 () )
F_11 ( V_38 ) ;
else {
V_39 -> V_40 = V_41 ;
F_12 ( ( V_38 * V_42 + 999 ) / 1000 ) ;
}
}
static void F_13 ( int V_43 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < 8 ; V_2 ++ ) {
V_9 . V_18 = V_44 ;
F_7 () ;
V_9 . V_20 = V_43 & 1 ;
F_7 () ;
F_14 ( 2 ) ;
V_9 . V_18 = V_45 ;
F_7 () ;
F_14 ( 1 ) ;
V_43 >>= 1 ;
}
}
static void F_15 ( int V_46 )
{
if ( V_47 == V_48 )
return;
F_16 ( & V_49 ) ;
V_9 . V_16 = V_46 ;
F_7 () ;
F_17 ( & V_49 ) ;
}
static void F_18 ( int V_50 )
{
F_16 ( & V_49 ) ;
F_13 ( 0x1F ) ;
F_13 ( V_50 & 0x0F ) ;
F_13 ( ( V_50 >> 4 ) & 0x0F ) ;
F_14 ( 40 ) ;
F_17 ( & V_49 ) ;
}
static void F_19 ( int V_51 )
{
F_16 ( & V_49 ) ;
F_13 ( 0x5F ) ;
F_13 ( V_51 & 0x0F ) ;
F_13 ( ( V_51 >> 4 ) & 0x0F ) ;
F_14 ( 40 ) ;
F_17 ( & V_49 ) ;
}
static void F_20 ( int V_50 )
{
F_16 ( & V_49 ) ;
F_3 ( V_3 , V_50 ) ;
F_14 ( 20 ) ;
V_9 . V_10 = V_45 ;
V_9 . V_12 = V_44 ;
V_9 . V_14 = V_44 ;
F_4 () ;
F_14 ( 40 ) ;
V_9 . V_10 = V_44 ;
F_4 () ;
F_14 ( 120 ) ;
F_17 ( & V_49 ) ;
}
static void F_21 ( int V_51 )
{
F_16 ( & V_49 ) ;
F_3 ( V_3 , V_51 ) ;
F_14 ( 20 ) ;
V_9 . V_10 = V_45 ;
V_9 . V_12 = V_45 ;
V_9 . V_14 = V_44 ;
F_4 () ;
F_14 ( 40 ) ;
V_9 . V_10 = V_44 ;
F_4 () ;
F_14 ( 45 ) ;
F_17 ( & V_49 ) ;
}
static void F_22 ( int V_50 )
{
F_16 ( & V_49 ) ;
F_6 ( V_3 , V_50 ) ;
F_14 ( 60 ) ;
F_17 ( & V_49 ) ;
}
static void F_23 ( int V_51 )
{
F_16 ( & V_49 ) ;
F_3 ( V_3 , V_51 ) ;
F_14 ( 60 ) ;
F_17 ( & V_49 ) ;
}
static void F_24 ( void )
{
F_25 ( 0x80
| ( V_52 ? V_53 : 0 )
| ( ( V_54 < V_55 ) ? V_54 &
( V_53 - 1 ) : V_55 - 1 ) ) ;
}
static void F_26 ( char V_56 )
{
if ( V_54 < V_55 ) {
if ( V_57 != NULL )
V_56 = V_57 [ ( unsigned char ) V_56 ] ;
F_27 ( V_56 ) ;
V_54 ++ ;
}
if ( V_54 == V_55 )
F_24 () ;
}
static void F_28 ( void )
{
int V_58 ;
V_54 = V_52 = 0 ;
F_24 () ;
F_16 ( & V_49 ) ;
for ( V_58 = 0 ; V_58 < V_59 * V_53 ; V_58 ++ ) {
F_13 ( 0x5F ) ;
F_13 ( ' ' & 0x0F ) ;
F_13 ( ( ' ' >> 4 ) & 0x0F ) ;
F_14 ( 40 ) ;
}
F_17 ( & V_49 ) ;
V_54 = V_52 = 0 ;
F_24 () ;
}
static void F_29 ( void )
{
int V_58 ;
V_54 = V_52 = 0 ;
F_24 () ;
F_16 ( & V_49 ) ;
for ( V_58 = 0 ; V_58 < V_59 * V_53 ; V_58 ++ ) {
F_3 ( V_3 , ' ' ) ;
F_14 ( 20 ) ;
V_9 . V_10 = V_45 ;
V_9 . V_12 = V_45 ;
V_9 . V_14 = V_44 ;
F_4 () ;
F_14 ( 40 ) ;
V_9 . V_10 = V_44 ;
F_4 () ;
F_14 ( 45 ) ;
}
F_17 ( & V_49 ) ;
V_54 = V_52 = 0 ;
F_24 () ;
}
static void F_30 ( void )
{
int V_58 ;
V_54 = V_52 = 0 ;
F_24 () ;
F_16 ( & V_49 ) ;
for ( V_58 = 0 ; V_58 < V_59 * V_53 ; V_58 ++ ) {
F_3 ( V_3 , ' ' ) ;
F_14 ( 60 ) ;
}
F_17 ( & V_49 ) ;
V_54 = V_52 = 0 ;
F_24 () ;
}
static void F_31 ( void )
{
F_25 ( 0x01 ) ;
V_54 = V_52 = 0 ;
F_9 ( 15 ) ;
}
static void F_32 ( void )
{
V_60 = ( ( V_59 > 1 ) ? V_61 : 0 )
| V_62 | V_63 | V_64 ;
F_9 ( 20 ) ;
F_25 ( 0x30 ) ;
F_9 ( 10 ) ;
F_25 ( 0x30 ) ;
F_9 ( 10 ) ;
F_25 ( 0x30 ) ;
F_9 ( 10 ) ;
F_25 ( 0x30
| ( ( V_60 & V_65 ) ? 4 : 0 )
| ( ( V_60 & V_61 ) ? 8 : 0 )
) ;
F_9 ( 10 ) ;
F_25 ( 0x08 ) ;
F_9 ( 10 ) ;
F_25 ( 0x08
| ( ( V_60 & V_62 ) ? 4 : 0 )
| ( ( V_60 & V_63 ) ? 2 : 0 )
| ( ( V_60 & V_64 ) ? 1 : 0 )
) ;
F_15 ( ( V_60 & V_66 ) ? 1 : 0 ) ;
F_9 ( 10 ) ;
F_25 ( 0x06 ) ;
F_31 () ;
}
static inline int F_33 ( void )
{
int V_67 = 0 ;
char * V_68 = V_69 + 2 ;
int V_70 = V_60 ;
switch ( * V_68 ) {
case 'D' :
V_60 |= V_62 ;
V_67 = 1 ;
break;
case 'd' :
V_60 &= ~ V_62 ;
V_67 = 1 ;
break;
case 'C' :
V_60 |= V_63 ;
V_67 = 1 ;
break;
case 'c' :
V_60 &= ~ V_63 ;
V_67 = 1 ;
break;
case 'B' :
V_60 |= V_64 ;
V_67 = 1 ;
break;
case 'b' :
V_60 &= ~ V_64 ;
V_67 = 1 ;
break;
case '+' :
V_60 |= V_66 ;
V_67 = 1 ;
break;
case '-' :
V_60 &= ~ V_66 ;
V_67 = 1 ;
break;
case '*' :
if ( V_71 . V_72 != NULL ) {
if ( V_73 == 0 && ( ( V_60 & V_66 ) == 0 ) )
F_15 ( 1 ) ;
V_73 = V_74 ;
}
V_67 = 1 ;
break;
case 'f' :
V_60 &= ~ V_65 ;
V_67 = 1 ;
break;
case 'F' :
V_60 |= V_65 ;
V_67 = 1 ;
break;
case 'n' :
V_60 &= ~ V_61 ;
V_67 = 1 ;
break;
case 'N' :
V_60 |= V_61 ;
break;
case 'l' :
if ( V_54 > 0 ) {
if ( V_54 < V_55 )
F_25 ( 0x10 ) ;
V_54 -- ;
}
V_67 = 1 ;
break;
case 'r' :
if ( V_54 < V_75 ) {
if ( V_54 <
( V_55 - 1 ) )
F_25 ( 0x14 ) ;
V_54 ++ ;
}
V_67 = 1 ;
break;
case 'L' :
V_76 ++ ;
F_25 ( 0x18 ) ;
V_67 = 1 ;
break;
case 'R' :
V_76 -- ;
F_25 ( 0x1C ) ;
V_67 = 1 ;
break;
case 'k' : {
int V_77 ;
for ( V_77 = V_54 ; V_77 < V_55 ; V_77 ++ )
F_27 ( ' ' ) ;
F_24 () ;
V_67 = 1 ;
break;
}
case 'I' :
F_32 () ;
V_76 = 0 ;
V_67 = 1 ;
break;
case 'G' : {
unsigned char V_78 [ 8 ] ;
unsigned char V_79 ;
int V_80 ;
int V_81 ;
char V_82 ;
int V_83 ;
if ( strchr ( V_68 , ';' ) == NULL )
break;
V_68 ++ ;
V_79 = * ( V_68 ++ ) - '0' ;
if ( V_79 > 7 ) {
V_67 = 1 ;
break;
}
V_80 = 0 ;
V_81 = 0 ;
V_82 = 0 ;
while ( * V_68 && V_80 < 8 ) {
V_81 ^= 4 ;
if ( * V_68 >= '0' && * V_68 <= '9' )
V_82 |= ( * V_68 - '0' ) << V_81 ;
else if ( * V_68 >= 'A' && * V_68 <= 'Z' )
V_82 |= ( * V_68 - 'A' + 10 ) << V_81 ;
else if ( * V_68 >= 'a' && * V_68 <= 'z' )
V_82 |= ( * V_68 - 'a' + 10 ) << V_81 ;
else {
V_68 ++ ;
continue;
}
if ( V_81 == 0 ) {
V_78 [ V_80 ++ ] = V_82 ;
V_82 = 0 ;
}
V_68 ++ ;
}
F_25 ( 0x40 | ( V_79 * 8 ) ) ;
for ( V_83 = 0 ; V_83 < V_80 ; V_83 ++ )
F_27 ( V_78 [ V_83 ] ) ;
F_24 () ;
V_67 = 1 ;
break;
}
case 'x' :
case 'y' :
if ( strchr ( V_68 , ';' ) == NULL )
break;
while ( * V_68 ) {
char * V_84 ;
if ( * V_68 == 'x' ) {
V_68 ++ ;
V_54 = F_34 ( V_68 , & V_84 , 10 ) ;
V_68 = V_84 ;
} else if ( * V_68 == 'y' ) {
V_68 ++ ;
V_52 = F_34 ( V_68 , & V_84 , 10 ) ;
V_68 = V_84 ;
} else
break;
}
F_24 () ;
V_67 = 1 ;
break;
}
if ( V_70 != V_60 ) {
if ( ( V_70 ^ V_60 ) &
( V_64 | V_63 | V_62 ) )
F_25 ( 0x08
| ( ( V_60 & V_62 ) ? 4 : 0 )
| ( ( V_60 & V_63 ) ? 2 : 0 )
| ( ( V_60 & V_64 ) ? 1 : 0 ) ) ;
else if ( ( V_70 ^ V_60 ) & ( V_65 | V_61 ) )
F_25 ( 0x30
| ( ( V_60 & V_65 ) ? 4 : 0 )
| ( ( V_60 & V_61 ) ? 8 : 0 ) ) ;
else if ( ( V_70 ^ V_60 ) & ( V_66 ) ) {
if ( V_60 & ( V_66 ) )
F_15 ( 1 ) ;
else if ( V_73 == 0 )
F_15 ( 0 ) ;
}
}
return V_67 ;
}
static T_1 F_35 ( struct V_85 * V_85 ,
const char * V_86 , T_2 V_87 , T_3 * V_88 )
{
const char * V_89 = V_86 ;
char V_56 ;
for (; V_87 -- > 0 ; ( V_88 ? ( * V_88 ) ++ : 0 ) , ++ V_89 ) {
if ( ! F_10 () && ( ( ( V_87 + 1 ) & 0x1f ) == 0 ) )
F_36 () ;
if ( V_88 == NULL && V_85 == NULL )
V_56 = * V_89 ;
else if ( F_37 ( V_56 , V_89 ) )
return - V_90 ;
if ( ( V_56 != '\n' ) && V_91 >= 0 ) {
V_69 [ V_91 ++ ] = V_56 ;
V_69 [ V_91 ] = 0 ;
} else {
V_91 = - 1 ;
switch ( V_56 ) {
case V_92 :
V_91 = 0 ;
V_69 [ V_91 ] = 0 ;
break;
case '\b' :
if ( V_54 > 0 ) {
if ( V_54 < V_55 )
F_25 ( 0x10 ) ;
V_54 -- ;
}
F_27 ( ' ' ) ;
F_25 ( 0x10 ) ;
break;
case '\014' :
F_38 () ;
break;
case '\n' :
for (; V_54 < V_55 ; V_54 ++ )
F_27 ( ' ' ) ;
V_54 = 0 ;
V_52 = ( V_52 + 1 ) % V_59 ;
F_24 () ;
break;
case '\r' :
V_54 = 0 ;
F_24 () ;
break;
case '\t' :
F_26 ( ' ' ) ;
break;
default:
F_26 ( V_56 ) ;
break;
}
}
if ( V_91 >= 2 ) {
int V_67 = 0 ;
if ( ! strcmp ( V_69 , L_1 ) ) {
F_38 () ;
V_67 = 1 ;
} else if ( ! strcmp ( V_69 , L_2 ) ) {
V_54 = V_52 = 0 ;
F_24 () ;
V_67 = 1 ;
}
else if ( ( V_91 >= 3 ) &&
( V_69 [ 0 ] == '[' ) &&
( V_69 [ 1 ] == 'L' ) ) {
V_67 = F_33 () ;
}
if ( V_67 || ( V_91 >= V_93 ) )
V_91 = - 1 ;
}
}
return V_89 - V_86 ;
}
static int F_39 ( struct V_94 * V_94 , struct V_85 * V_85 )
{
if ( V_95 )
return - V_96 ;
if ( V_85 -> V_97 & V_98 )
return - V_99 ;
if ( V_100 ) {
F_31 () ;
V_100 = 0 ;
}
V_95 ++ ;
return F_40 ( V_94 , V_85 ) ;
}
static int F_41 ( struct V_94 * V_94 , struct V_85 * V_85 )
{
V_95 -- ;
return 0 ;
}
void F_42 ( char * V_101 )
{
if ( V_102 && V_103 )
F_35 ( NULL , V_101 , strlen ( V_101 ) , NULL ) ;
}
void F_43 ( void )
{
switch ( V_104 ) {
case V_105 :
if ( V_106 < 0 )
V_106 = V_107 ;
if ( V_108 < 0 )
V_108 = V_109 ;
if ( V_110 == V_111 )
V_110 = V_28 ;
if ( V_112 == V_111 )
V_112 = V_32 ;
if ( V_75 < 0 )
V_75 = 40 ;
if ( V_55 < 0 )
V_55 = 40 ;
if ( V_53 < 0 )
V_53 = 64 ;
if ( V_59 < 0 )
V_59 = 2 ;
break;
case V_113 :
if ( V_106 < 0 )
V_106 = V_114 ;
if ( V_108 < 0 )
V_108 = V_115 ;
if ( V_47 == V_111 )
V_47 = V_32 ;
if ( V_116 == V_111 )
V_116 = V_28 ;
if ( V_117 == V_111 )
V_117 = V_30 ;
if ( V_75 < 0 )
V_75 = 16 ;
if ( V_55 < 0 )
V_55 = 40 ;
if ( V_53 < 0 )
V_53 = 16 ;
if ( V_59 < 0 )
V_59 = 2 ;
break;
case V_118 :
if ( V_106 < 0 )
V_106 = V_107 ;
if ( V_108 < 0 )
V_108 = V_109 ;
if ( V_110 == V_111 )
V_110 = V_32 ;
if ( V_112 == V_111 )
V_112 = V_36 ;
if ( V_119 == V_111 )
V_119 = V_34 ;
if ( V_75 < 0 )
V_75 = 16 ;
if ( V_55 < 0 )
V_55 = 40 ;
if ( V_53 < 0 )
V_53 = 64 ;
if ( V_59 < 0 )
V_59 = 2 ;
break;
case V_120 :
if ( V_106 < 0 )
V_106 = V_121 ;
if ( V_108 < 0 )
V_108 = V_122 ;
break;
case V_123 :
default:
if ( V_106 < 0 )
V_106 = V_107 ;
if ( V_108 < 0 )
V_108 = V_109 ;
if ( V_110 == V_111 )
V_110 = V_28 ;
if ( V_112 == V_111 )
V_112 = V_36 ;
if ( V_75 < 0 )
V_75 = 16 ;
if ( V_55 < 0 )
V_55 = 40 ;
if ( V_53 < 0 )
V_53 = 64 ;
if ( V_59 < 0 )
V_59 = 2 ;
break;
}
if ( V_75 <= 0 )
V_75 = V_124 ;
if ( V_55 <= 0 )
V_55 = V_125 ;
if ( V_53 <= 0 )
V_53 = V_126 ;
if ( V_59 <= 0 )
V_59 = V_127 ;
if ( V_106 == V_114 ) {
F_25 = F_18 ;
F_27 = F_19 ;
F_38 = F_28 ;
if ( V_116 == V_111 )
V_116 = V_128 ;
if ( V_117 == V_111 )
V_117 = V_129 ;
} else if ( V_106 == V_107 ) {
F_25 = F_20 ;
F_27 = F_21 ;
F_38 = F_29 ;
if ( V_110 == V_111 )
V_110 = V_130 ;
if ( V_112 == V_111 )
V_112 = V_131 ;
if ( V_119 == V_111 )
V_119 = V_132 ;
} else {
F_25 = F_22 ;
F_27 = F_23 ;
F_38 = F_30 ;
}
if ( V_47 == V_111 )
V_47 = V_133 ;
if ( V_110 == V_111 )
V_110 = V_48 ;
if ( V_112 == V_111 )
V_112 = V_48 ;
if ( V_119 == V_111 )
V_119 = V_48 ;
if ( V_47 == V_111 )
V_47 = V_48 ;
if ( V_116 == V_111 )
V_116 = V_48 ;
if ( V_117 == V_111 )
V_117 = V_48 ;
if ( V_108 < 0 )
V_108 = V_122 ;
if ( V_108 == V_115 )
V_57 = V_134 ;
else
V_57 = NULL ;
if ( V_47 != V_48 )
F_44 () ;
F_8 ( V_110 , V_5 [ V_6 ] [ V_8 ] ,
V_5 [ V_21 ] [ V_8 ] ) ;
F_8 ( V_112 , V_5 [ V_6 ] [ V_11 ] ,
V_5 [ V_21 ] [ V_11 ] ) ;
F_8 ( V_119 , V_5 [ V_6 ] [ V_13 ] ,
V_5 [ V_21 ] [ V_13 ] ) ;
F_8 ( V_47 , V_5 [ V_6 ] [ V_15 ] ,
V_5 [ V_21 ] [ V_15 ] ) ;
F_8 ( V_116 , V_5 [ V_6 ] [ V_17 ] ,
V_5 [ V_21 ] [ V_17 ] ) ;
F_8 ( V_117 , V_5 [ V_6 ] [ V_19 ] ,
V_5 [ V_21 ] [ V_19 ] ) ;
V_103 = 1 ;
F_32 () ;
#ifdef F_45
#ifdef F_46
F_42 ( L_3 F_46 ) ;
#endif
#else
F_42 ( L_4 V_135 L_5
V_136 ) ;
#endif
V_54 = V_52 = 0 ;
V_100 = 1 ;
F_24 () ;
}
static T_1 F_47 ( struct V_85 * V_85 ,
char * V_86 , T_2 V_87 , T_3 * V_88 )
{
unsigned V_137 = * V_88 ;
char * V_89 = V_86 ;
if ( V_138 == 0 ) {
if ( V_85 -> V_139 & V_140 )
return - V_141 ;
F_48 ( & V_142 ) ;
if ( F_49 ( V_39 ) )
return - V_143 ;
}
for (; V_87 -- > 0 && ( V_138 > 0 ) ;
++ V_137 , ++ V_89 , -- V_138 ) {
F_50 ( V_144 [ V_145 ] , V_89 ) ;
V_145 = ( V_145 + 1 ) % V_146 ;
}
* V_88 = V_137 ;
return V_89 - V_86 ;
}
static int F_51 ( struct V_94 * V_94 , struct V_85 * V_85 )
{
if ( V_147 )
return - V_96 ;
if ( V_85 -> V_97 & V_148 )
return - V_99 ;
V_138 = 0 ;
V_147 ++ ;
return 0 ;
}
static int F_52 ( struct V_94 * V_94 , struct V_85 * V_85 )
{
V_147 -- ;
return 0 ;
}
static void F_53 ( char * string , int V_149 )
{
if ( V_150 )
return;
if ( V_147 > 0 ) {
while ( V_149 -- && V_138 < V_146 && * string ) {
V_144 [ ( V_145 + V_138 ++ ) %
V_146 ] = * string ++ ;
}
F_54 ( & V_142 ) ;
}
}
static void F_55 ( void )
{
int V_2 , V_151 ;
char V_152 ;
char V_153 ;
char V_154 ;
V_155 = V_156 ;
V_157 = V_158 ;
V_158 = 0 ;
V_152 = F_2 ( V_3 ) | V_159 ;
F_3 ( V_3 , V_152 & ~ V_159 ) ;
V_153 = F_56 ( F_57 ( V_3 ) ) & V_160 ;
F_3 ( V_3 , V_152 ) ;
V_154 = F_56 ( F_57 ( V_3 ) ) & V_160 ;
V_158 |= ( V_161 ) V_154 << 40 ;
if ( V_153 != V_154 ) {
for ( V_2 = 0 ; V_2 < 8 ; V_2 ++ ) {
V_151 = 1 << V_2 ;
if ( ! ( V_159 & V_151 ) )
continue;
F_3 ( V_3 , V_152 & ~ V_151 ) ;
V_153 = F_56 ( F_57 ( V_3 ) ) & ~ V_154 ;
V_158 |= ( V_161 ) V_153 << ( 5 * V_2 ) ;
}
F_3 ( V_3 , V_152 ) ;
}
V_156 = ( V_155 & ( V_158 ^ V_157 ) ) |
( V_158 & ~ ( V_158 ^ V_157 ) ) ;
}
static inline int F_58 ( struct V_162 * V_163 )
{
#if 0
if (((phys_prev & input->mask) == input->value)
&& ((phys_curr & input->mask) > input->value)) {
input->state = INPUT_ST_LOW;
return 1;
}
#endif
if ( ( V_156 & V_163 -> V_164 ) == V_163 -> V_82 ) {
if ( ( V_163 -> type == V_165 ) &&
( V_163 -> V_166 == 0 ) ) {
V_163 -> V_166 ++ ;
if ( V_163 -> V_167 . V_168 . V_169 != NULL )
V_163 -> V_167 . V_168 . V_169 ( V_163 -> V_167 . V_168 . V_170 ) ;
} else if ( V_163 -> type == V_171 ) {
V_172 = 1 ;
if ( V_163 -> V_166 == 0 ) {
char * V_173 = V_163 -> V_167 . V_174 . V_173 ;
if ( V_173 [ 0 ] )
F_53 ( V_173 ,
sizeof( V_173 ) ) ;
}
if ( V_163 -> V_167 . V_174 . V_175 [ 0 ] ) {
char * V_175 = V_163 -> V_167 . V_174 . V_175 ;
if ( V_163 -> V_166 >= V_176 ) {
V_163 -> V_166 -= V_177 ;
F_53 ( V_175 ,
sizeof( V_175 ) ) ;
}
V_178 = 0 ;
}
if ( V_163 -> V_166 < 255 )
V_163 -> V_166 ++ ;
}
return 1 ;
} else {
V_163 -> V_40 = V_179 ;
V_163 -> V_180 = 0 ;
}
return 0 ;
}
static inline void F_59 ( struct V_162 * V_163 )
{
#if 0
if (((phys_prev & input->mask) == input->value)
&& ((phys_curr & input->mask) > input->value)) {
input->state = INPUT_ST_LOW;
return;
}
#endif
if ( ( V_156 & V_163 -> V_164 ) == V_163 -> V_82 ) {
if ( V_163 -> type == V_171 ) {
V_172 = 1 ;
if ( V_163 -> V_167 . V_174 . V_175 [ 0 ] ) {
char * V_175 = V_163 -> V_167 . V_174 . V_175 ;
if ( V_163 -> V_166 >= V_176 )
V_163 -> V_166 -= V_177 ;
F_53 ( V_175 ,
sizeof( V_175 ) ) ;
V_178 = 0 ;
}
if ( V_163 -> V_166 < 255 )
V_163 -> V_166 ++ ;
}
V_163 -> V_40 = V_181 ;
} else if ( V_163 -> V_180 >= V_163 -> V_182 ) {
if ( V_163 -> type == V_165 ) {
void (* F_60)( int ) = V_163 -> V_167 . V_168 . F_60 ;
if ( F_60 != NULL )
F_60 ( V_163 -> V_167 . V_168 . V_183 ) ;
} else if ( V_163 -> type == V_171 ) {
char * V_184 = V_163 -> V_167 . V_174 . V_184 ;
if ( V_184 [ 0 ] )
F_53 ( V_184 ,
sizeof( V_184 ) ) ;
}
V_163 -> V_40 = V_185 ;
} else {
V_163 -> V_180 ++ ;
V_178 = 0 ;
}
}
static void F_61 ( void )
{
struct V_186 * V_187 ;
struct V_162 * V_163 ;
#if 0
printk(KERN_DEBUG
"entering panel_process_inputs with pp=%016Lx & pc=%016Lx\n",
phys_prev, phys_curr);
#endif
V_172 = 0 ;
V_178 = 1 ;
F_62 (item, &logical_inputs) {
V_163 = F_63 ( V_187 , struct V_162 , V_188 ) ;
switch ( V_163 -> V_40 ) {
case V_185 :
if ( ( V_156 & V_163 -> V_164 ) != V_163 -> V_82 )
break;
if ( ( V_155 & V_163 -> V_164 ) == V_163 -> V_82 )
break;
V_163 -> V_189 = 0 ;
V_163 -> V_40 = V_190 ;
case V_190 :
if ( ( V_156 & V_163 -> V_164 ) != V_163 -> V_82 ) {
V_163 -> V_40 = V_185 ;
break;
}
if ( V_163 -> V_189 < V_163 -> V_191 ) {
V_178 = 0 ;
V_163 -> V_189 ++ ;
break;
}
V_163 -> V_166 = 0 ;
V_163 -> V_40 = V_181 ;
case V_181 :
if ( F_58 ( V_163 ) )
break;
case V_179 :
F_59 ( V_163 ) ;
}
}
}
static void F_64 ( void )
{
if ( V_192 && V_193 ) {
if ( F_65 ( & V_49 ) ) {
F_55 () ;
F_17 ( & V_49 ) ;
}
if ( ! V_178 || V_156 != V_155 )
F_61 () ;
}
if ( V_102 && V_103 ) {
if ( V_172 ) {
if ( V_73 == 0 && ( ( V_60 & V_66 ) == 0 ) )
F_15 ( 1 ) ;
V_73 = V_74 ;
} else if ( V_73 > 0 ) {
V_73 -- ;
if ( V_73 == 0 && ( ( V_60 & V_66 ) == 0 ) )
F_15 ( 0 ) ;
}
}
F_66 ( & V_71 , V_194 + V_195 ) ;
}
static void F_44 ( void )
{
if ( V_71 . V_72 != NULL )
return;
F_67 ( & V_71 ) ;
V_71 . V_196 = V_194 + V_195 ;
V_71 . V_51 = 0 ;
V_71 . V_72 = ( void * ) & F_64 ;
F_68 ( & V_71 ) ;
}
static int F_69 ( char * V_197 , V_161 * V_164 , V_161 * V_82 ,
char * V_198 , char * V_199 )
{
static char V_200 [ 10 ] = L_6 ;
char V_201 , V_202 ;
V_161 V_203 , V_204 ;
V_202 = V_201 = V_203 = V_204 = 0ULL ;
while ( * V_197 ) {
int V_205 , V_206 , V_2 , V_207 ;
for ( V_205 = 0 ; ( V_205 < sizeof( V_200 ) ) &&
( V_200 [ V_205 ] != * V_197 ) ; V_205 ++ )
;
if ( V_205 >= sizeof( V_200 ) )
return 0 ;
V_207 = ( V_205 & 1 ) ;
V_205 >>= 1 ;
V_201 |= ( 1 << V_205 ) ;
V_197 ++ ;
if ( isdigit ( * V_197 ) ) {
V_206 = * V_197 - '0' ;
V_202 |= ( 1 << V_206 ) ;
} else if ( * V_197 == '-' )
V_206 = 8 ;
else
return 0 ;
V_2 = ( V_206 * 5 ) + V_205 ;
V_203 |= 1ULL << V_2 ;
if ( ! V_207 )
V_204 |= 1ULL << V_2 ;
V_197 ++ ;
}
* V_164 = V_203 ;
* V_82 = V_204 ;
if ( V_198 )
* V_198 |= V_201 ;
if ( V_199 )
* V_199 |= V_202 ;
return 1 ;
}
static struct V_162 * F_70 ( char * V_197 , char * V_208 ,
char * V_209 , char * V_210 )
{
struct V_162 * V_211 ;
V_211 = F_71 ( sizeof( struct V_162 ) , V_212 ) ;
if ( ! V_211 ) {
F_72 ( V_213 L_7 ) ;
return NULL ;
}
if ( ! F_69 ( V_197 , & V_211 -> V_164 , & V_211 -> V_82 , & V_160 ,
& V_159 ) ) {
F_73 ( V_211 ) ;
return NULL ;
}
V_211 -> type = V_171 ;
V_211 -> V_40 = V_185 ;
V_211 -> V_191 = 1 ;
V_211 -> V_182 = 1 ;
#if 0
printk(KERN_DEBUG "bind: <%s> : m=%016Lx v=%016Lx\n", name, key->mask,
key->value);
#endif
strncpy ( V_211 -> V_167 . V_174 . V_173 , V_208 , sizeof( V_211 -> V_167 . V_174 . V_173 ) ) ;
strncpy ( V_211 -> V_167 . V_174 . V_175 , V_209 , sizeof( V_211 -> V_167 . V_174 . V_175 ) ) ;
strncpy ( V_211 -> V_167 . V_174 . V_184 , V_210 ,
sizeof( V_211 -> V_167 . V_174 . V_184 ) ) ;
F_74 ( & V_211 -> V_188 , & V_214 ) ;
return V_211 ;
}
static void F_75 ( void )
{
int V_215 ;
F_76 ( & V_142 ) ;
V_138 = 0 ;
for ( V_215 = 0 ; V_216 [ V_215 ] [ 0 ] [ 0 ] ; V_215 ++ ) {
F_70 ( V_216 [ V_215 ] [ 0 ] ,
V_216 [ V_215 ] [ 1 ] ,
V_216 [ V_215 ] [ 2 ] ,
V_216 [ V_215 ] [ 3 ] ) ;
}
F_44 () ;
V_193 = 1 ;
}
static int F_77 ( struct V_217 * V_218 , unsigned long V_219 ,
void * V_220 )
{
if ( V_102 && V_103 ) {
switch ( V_219 ) {
case V_221 :
F_42
( L_8 ) ;
break;
case V_222 :
F_42
( L_9 ) ;
break;
case V_223 :
F_42 ( L_10 ) ;
break;
default:
break;
}
}
return V_224 ;
}
static void F_78 ( struct V_225 * V_226 )
{
if ( V_226 -> V_227 != V_225 )
return;
if ( V_3 ) {
F_72 ( V_213
L_11
L_12 ,
V_226 -> V_227 , V_225 ) ;
return;
}
V_3 = F_79 ( V_226 , L_13 , NULL , NULL ,
NULL ,
0 , ( void * ) & V_3 ) ;
if ( V_3 == NULL ) {
F_80 ( L_11
L_14 ,
V_226 -> V_227 , V_225 ) ;
return;
}
if ( F_81 ( V_3 ) ) {
F_72 ( V_213
L_15
L_16 , V_225 ) ;
goto V_228;
}
if ( V_102 ) {
F_43 () ;
if ( F_82 ( & V_229 ) )
goto V_228;
}
if ( V_192 ) {
F_75 () ;
if ( F_82 ( & V_230 ) )
goto V_231;
}
return;
V_231:
if ( V_102 )
F_83 ( & V_229 ) ;
V_228:
F_84 ( V_3 ) ;
V_3 = NULL ;
}
static void F_85 ( struct V_225 * V_226 )
{
if ( V_226 -> V_227 != V_225 )
return;
if ( ! V_3 ) {
F_72 ( V_213
L_17
L_18 ,
V_226 -> V_227 , V_225 ) ;
return;
}
if ( V_192 && V_193 ) {
F_83 ( & V_230 ) ;
V_193 = 0 ;
}
if ( V_102 && V_103 ) {
F_83 ( & V_229 ) ;
V_103 = 0 ;
}
F_86 ( V_3 ) ;
F_84 ( V_3 ) ;
V_3 = NULL ;
}
int F_87 ( void )
{
if ( V_232 < 0 )
V_232 = V_192 ;
if ( V_104 < 0 )
V_104 = V_102 ;
if ( V_225 < 0 )
V_225 = V_233 ;
switch ( V_234 ) {
case V_235 :
if ( V_232 < 0 )
V_232 = V_236 ;
if ( V_104 < 0 )
V_104 = V_237 ;
break;
case V_238 :
if ( V_232 < 0 )
V_232 = V_239 ;
if ( V_104 < 0 )
V_104 = V_105 ;
if ( V_75 < 0 )
V_75 = 16 ;
if ( V_53 < 0 )
V_53 = 16 ;
break;
case V_240 :
if ( V_232 < 0 )
V_232 = V_241 ;
if ( V_104 < 0 )
V_104 = V_113 ;
break;
case V_242 :
if ( V_232 < 0 )
V_232 = V_243 ;
if ( V_104 < 0 )
V_104 = V_123 ;
break;
case V_244 :
if ( V_232 < 0 )
V_232 = V_245 ;
if ( V_104 < 0 )
V_104 = V_118 ;
break;
case V_246 :
if ( V_232 < 0 )
V_232 = V_239 ;
if ( V_104 < 0 )
V_104 = V_105 ;
break;
}
V_102 = ( V_104 > 0 ) ;
V_192 = ( V_232 > 0 ) ;
switch ( V_232 ) {
case V_239 :
V_216 = V_247 ;
break;
case V_241 :
V_216 = V_248 ;
break;
case V_245 :
V_216 = V_249 ;
break;
default:
V_216 = NULL ;
break;
}
V_150 = 1 ;
if ( F_88 ( & V_250 ) ) {
F_72 ( V_213
L_19 ) ;
return - V_251 ;
}
if ( ! V_102 && ! V_192 ) {
if ( V_3 ) {
F_86 ( V_3 ) ;
F_84 ( V_3 ) ;
V_3 = NULL ;
}
F_89 ( & V_250 ) ;
F_72 ( V_213 L_20 V_136
L_21 ) ;
return - V_252 ;
}
F_90 ( & V_253 ) ;
if ( V_3 )
F_72 ( V_254 L_20 V_136
L_22 , V_225 ,
V_3 -> V_226 -> V_255 ) ;
else
F_72 ( V_254 L_20 V_136
L_23 ) ;
V_150 = 0 ;
return 0 ;
}
static int T_4 F_91 ( void )
{
return F_87 () ;
}
static void T_5 F_92 ( void )
{
F_93 ( & V_253 ) ;
if ( V_71 . V_72 != NULL )
F_94 ( & V_71 ) ;
if ( V_3 != NULL ) {
if ( V_192 ) {
F_83 ( & V_230 ) ;
V_193 = 0 ;
}
if ( V_102 ) {
F_42 ( L_24 V_136
L_25 ) ;
F_83 ( & V_229 ) ;
V_103 = 0 ;
}
F_86 ( V_3 ) ;
F_84 ( V_3 ) ;
V_3 = NULL ;
}
F_89 ( & V_250 ) ;
}
