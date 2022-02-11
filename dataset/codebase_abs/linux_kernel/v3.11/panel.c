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
static void F_8 ( int V_22 , unsigned char * V_23 , unsigned char * V_24 )
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
if ( * V_68 == 'x' ) {
V_68 ++ ;
if ( F_34 ( V_68 , 10 , & V_54 ) < 0 )
break;
} else if ( * V_68 == 'y' ) {
V_68 ++ ;
if ( F_34 ( V_68 , 10 , & V_52 ) < 0 )
break;
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
static T_1 F_35 ( struct V_84 * V_84 ,
const char * V_85 , T_2 V_86 , T_3 * V_87 )
{
const char * V_88 = V_85 ;
char V_56 ;
for (; V_86 -- > 0 ; ( V_87 ? ( * V_87 ) ++ : 0 ) , ++ V_88 ) {
if ( ! F_10 () && ( ( ( V_86 + 1 ) & 0x1f ) == 0 ) )
F_36 () ;
if ( V_87 == NULL && V_84 == NULL )
V_56 = * V_88 ;
else if ( F_37 ( V_56 , V_88 ) )
return - V_89 ;
if ( ( V_56 != '\n' ) && V_90 >= 0 ) {
V_69 [ V_90 ++ ] = V_56 ;
V_69 [ V_90 ] = 0 ;
} else {
V_90 = - 1 ;
switch ( V_56 ) {
case V_91 :
V_90 = 0 ;
V_69 [ V_90 ] = 0 ;
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
if ( V_90 >= 2 ) {
int V_67 = 0 ;
if ( ! strcmp ( V_69 , L_1 ) ) {
F_38 () ;
V_67 = 1 ;
} else if ( ! strcmp ( V_69 , L_2 ) ) {
V_54 = V_52 = 0 ;
F_24 () ;
V_67 = 1 ;
}
else if ( ( V_90 >= 3 ) &&
( V_69 [ 0 ] == '[' ) &&
( V_69 [ 1 ] == 'L' ) ) {
V_67 = F_33 () ;
}
if ( V_67 || ( V_90 >= V_92 ) )
V_90 = - 1 ;
}
}
return V_88 - V_85 ;
}
static int F_39 ( struct V_93 * V_93 , struct V_84 * V_84 )
{
if ( V_94 )
return - V_95 ;
if ( V_84 -> V_96 & V_97 )
return - V_98 ;
if ( V_99 ) {
F_31 () ;
V_99 = 0 ;
}
V_94 ++ ;
return F_40 ( V_93 , V_84 ) ;
}
static int F_41 ( struct V_93 * V_93 , struct V_84 * V_84 )
{
V_94 -- ;
return 0 ;
}
static void F_42 ( const char * V_100 )
{
if ( V_101 && V_102 )
F_35 ( NULL , V_100 , strlen ( V_100 ) , NULL ) ;
}
static void F_43 ( void )
{
switch ( V_103 ) {
case V_104 :
if ( V_105 < 0 )
V_105 = V_106 ;
if ( V_107 < 0 )
V_107 = V_108 ;
if ( V_109 == V_110 )
V_109 = V_28 ;
if ( V_111 == V_110 )
V_111 = V_32 ;
if ( V_75 < 0 )
V_75 = 40 ;
if ( V_55 < 0 )
V_55 = 40 ;
if ( V_53 < 0 )
V_53 = 64 ;
if ( V_59 < 0 )
V_59 = 2 ;
break;
case V_112 :
if ( V_105 < 0 )
V_105 = V_113 ;
if ( V_107 < 0 )
V_107 = V_114 ;
if ( V_47 == V_110 )
V_47 = V_32 ;
if ( V_115 == V_110 )
V_115 = V_28 ;
if ( V_116 == V_110 )
V_116 = V_30 ;
if ( V_75 < 0 )
V_75 = 16 ;
if ( V_55 < 0 )
V_55 = 40 ;
if ( V_53 < 0 )
V_53 = 16 ;
if ( V_59 < 0 )
V_59 = 2 ;
break;
case V_117 :
if ( V_105 < 0 )
V_105 = V_106 ;
if ( V_107 < 0 )
V_107 = V_108 ;
if ( V_109 == V_110 )
V_109 = V_32 ;
if ( V_111 == V_110 )
V_111 = V_36 ;
if ( V_118 == V_110 )
V_118 = V_34 ;
if ( V_75 < 0 )
V_75 = 16 ;
if ( V_55 < 0 )
V_55 = 40 ;
if ( V_53 < 0 )
V_53 = 64 ;
if ( V_59 < 0 )
V_59 = 2 ;
break;
case V_119 :
if ( V_105 < 0 )
V_105 = V_120 ;
if ( V_107 < 0 )
V_107 = V_121 ;
break;
case V_122 :
default:
if ( V_105 < 0 )
V_105 = V_106 ;
if ( V_107 < 0 )
V_107 = V_108 ;
if ( V_109 == V_110 )
V_109 = V_28 ;
if ( V_111 == V_110 )
V_111 = V_36 ;
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
V_75 = V_123 ;
if ( V_55 <= 0 )
V_55 = V_124 ;
if ( V_53 <= 0 )
V_53 = V_125 ;
if ( V_59 <= 0 )
V_59 = V_126 ;
if ( V_105 == V_113 ) {
F_25 = F_18 ;
F_27 = F_19 ;
F_38 = F_28 ;
if ( V_115 == V_110 )
V_115 = V_127 ;
if ( V_116 == V_110 )
V_116 = V_128 ;
} else if ( V_105 == V_106 ) {
F_25 = F_20 ;
F_27 = F_21 ;
F_38 = F_29 ;
if ( V_109 == V_110 )
V_109 = V_129 ;
if ( V_111 == V_110 )
V_111 = V_130 ;
if ( V_118 == V_110 )
V_118 = V_131 ;
} else {
F_25 = F_22 ;
F_27 = F_23 ;
F_38 = F_30 ;
}
if ( V_47 == V_110 )
V_47 = V_132 ;
if ( V_109 == V_110 )
V_109 = V_48 ;
if ( V_111 == V_110 )
V_111 = V_48 ;
if ( V_118 == V_110 )
V_118 = V_48 ;
if ( V_47 == V_110 )
V_47 = V_48 ;
if ( V_115 == V_110 )
V_115 = V_48 ;
if ( V_116 == V_110 )
V_116 = V_48 ;
if ( V_107 < 0 )
V_107 = V_121 ;
if ( V_107 == V_114 )
V_57 = V_133 ;
else
V_57 = NULL ;
if ( V_47 != V_48 )
F_44 () ;
F_8 ( V_109 , V_5 [ V_6 ] [ V_8 ] ,
V_5 [ V_21 ] [ V_8 ] ) ;
F_8 ( V_111 , V_5 [ V_6 ] [ V_11 ] ,
V_5 [ V_21 ] [ V_11 ] ) ;
F_8 ( V_118 , V_5 [ V_6 ] [ V_13 ] ,
V_5 [ V_21 ] [ V_13 ] ) ;
F_8 ( V_47 , V_5 [ V_6 ] [ V_15 ] ,
V_5 [ V_21 ] [ V_15 ] ) ;
F_8 ( V_115 , V_5 [ V_6 ] [ V_17 ] ,
V_5 [ V_21 ] [ V_17 ] ) ;
F_8 ( V_116 , V_5 [ V_6 ] [ V_19 ] ,
V_5 [ V_21 ] [ V_19 ] ) ;
V_102 = 1 ;
F_32 () ;
#ifdef F_45
#ifdef F_46
F_42 ( L_3 F_46 ) ;
#endif
#else
F_42 ( L_4 V_134 L_5
V_135 ) ;
#endif
V_54 = V_52 = 0 ;
V_99 = 1 ;
F_24 () ;
}
static T_1 F_47 ( struct V_84 * V_84 ,
char * V_85 , T_2 V_86 , T_3 * V_87 )
{
unsigned V_136 = * V_87 ;
char * V_88 = V_85 ;
if ( V_137 == 0 ) {
if ( V_84 -> V_138 & V_139 )
return - V_140 ;
F_48 ( & V_141 ) ;
if ( F_49 ( V_39 ) )
return - V_142 ;
}
for (; V_86 -- > 0 && ( V_137 > 0 ) ;
++ V_136 , ++ V_88 , -- V_137 ) {
F_50 ( V_143 [ V_144 ] , V_88 ) ;
V_144 = ( V_144 + 1 ) % V_145 ;
}
* V_87 = V_136 ;
return V_88 - V_85 ;
}
static int F_51 ( struct V_93 * V_93 , struct V_84 * V_84 )
{
if ( V_146 )
return - V_95 ;
if ( V_84 -> V_96 & V_147 )
return - V_98 ;
V_137 = 0 ;
V_146 ++ ;
return 0 ;
}
static int F_52 ( struct V_93 * V_93 , struct V_84 * V_84 )
{
V_146 -- ;
return 0 ;
}
static void F_53 ( const char * string , int V_148 )
{
if ( V_149 )
return;
if ( V_146 > 0 ) {
while ( V_148 -- && V_137 < V_145 && * string ) {
V_143 [ ( V_144 + V_137 ++ ) %
V_145 ] = * string ++ ;
}
F_54 ( & V_141 ) ;
}
}
static void F_55 ( void )
{
int V_2 , V_150 ;
char V_151 ;
char V_152 ;
char V_153 ;
V_154 = V_155 ;
V_156 = V_157 ;
V_157 = 0 ;
V_151 = F_2 ( V_3 ) | V_158 ;
F_3 ( V_3 , V_151 & ~ V_158 ) ;
V_152 = F_56 ( F_57 ( V_3 ) ) & V_159 ;
F_3 ( V_3 , V_151 ) ;
V_153 = F_56 ( F_57 ( V_3 ) ) & V_159 ;
V_157 |= ( V_160 ) V_153 << 40 ;
if ( V_152 != V_153 ) {
for ( V_2 = 0 ; V_2 < 8 ; V_2 ++ ) {
V_150 = 1 << V_2 ;
if ( ! ( V_158 & V_150 ) )
continue;
F_3 ( V_3 , V_151 & ~ V_150 ) ;
V_152 = F_56 ( F_57 ( V_3 ) ) & ~ V_153 ;
V_157 |= ( V_160 ) V_152 << ( 5 * V_2 ) ;
}
F_3 ( V_3 , V_151 ) ;
}
V_155 = ( V_154 & ( V_157 ^ V_156 ) ) |
( V_157 & ~ ( V_157 ^ V_156 ) ) ;
}
static inline int F_58 ( struct V_161 * V_162 )
{
#if 0
if (((phys_prev & input->mask) == input->value)
&& ((phys_curr & input->mask) > input->value)) {
input->state = INPUT_ST_LOW;
return 1;
}
#endif
if ( ( V_155 & V_162 -> V_163 ) == V_162 -> V_82 ) {
if ( ( V_162 -> type == V_164 ) &&
( V_162 -> V_165 == 0 ) ) {
V_162 -> V_165 ++ ;
if ( V_162 -> V_166 . V_167 . V_168 != NULL )
V_162 -> V_166 . V_167 . V_168 ( V_162 -> V_166 . V_167 . V_169 ) ;
} else if ( V_162 -> type == V_170 ) {
V_171 = 1 ;
if ( V_162 -> V_165 == 0 ) {
char * V_172 = V_162 -> V_166 . V_173 . V_172 ;
if ( V_172 [ 0 ] ) {
int V_100 = sizeof( V_162 -> V_166 . V_173 . V_172 ) ;
F_53 ( V_172 , V_100 ) ;
}
}
if ( V_162 -> V_166 . V_173 . V_174 [ 0 ] ) {
char * V_174 = V_162 -> V_166 . V_173 . V_174 ;
if ( V_162 -> V_165 >= V_175 ) {
int V_100 = sizeof( V_162 -> V_166 . V_173 . V_174 ) ;
V_162 -> V_165 -= V_176 ;
F_53 ( V_174 , V_100 ) ;
}
V_177 = 0 ;
}
if ( V_162 -> V_165 < 255 )
V_162 -> V_165 ++ ;
}
return 1 ;
} else {
V_162 -> V_40 = V_178 ;
V_162 -> V_179 = 0 ;
}
return 0 ;
}
static inline void F_59 ( struct V_161 * V_162 )
{
#if 0
if (((phys_prev & input->mask) == input->value)
&& ((phys_curr & input->mask) > input->value)) {
input->state = INPUT_ST_LOW;
return;
}
#endif
if ( ( V_155 & V_162 -> V_163 ) == V_162 -> V_82 ) {
if ( V_162 -> type == V_170 ) {
V_171 = 1 ;
if ( V_162 -> V_166 . V_173 . V_174 [ 0 ] ) {
char * V_174 = V_162 -> V_166 . V_173 . V_174 ;
if ( V_162 -> V_165 >= V_175 ) {
int V_100 = sizeof( V_162 -> V_166 . V_173 . V_174 ) ;
V_162 -> V_165 -= V_176 ;
F_53 ( V_174 , V_100 ) ;
}
V_177 = 0 ;
}
if ( V_162 -> V_165 < 255 )
V_162 -> V_165 ++ ;
}
V_162 -> V_40 = V_180 ;
} else if ( V_162 -> V_179 >= V_162 -> V_181 ) {
if ( V_162 -> type == V_164 ) {
void (* F_60)( int ) = V_162 -> V_166 . V_167 . F_60 ;
if ( F_60 != NULL )
F_60 ( V_162 -> V_166 . V_167 . V_182 ) ;
} else if ( V_162 -> type == V_170 ) {
char * V_183 = V_162 -> V_166 . V_173 . V_183 ;
if ( V_183 [ 0 ] ) {
int V_100 = sizeof( V_162 -> V_166 . V_173 . V_183 ) ;
F_53 ( V_183 , V_100 ) ;
}
}
V_162 -> V_40 = V_184 ;
} else {
V_162 -> V_179 ++ ;
V_177 = 0 ;
}
}
static void F_61 ( void )
{
struct V_185 * V_186 ;
struct V_161 * V_162 ;
V_171 = 0 ;
V_177 = 1 ;
F_62 (item, &logical_inputs) {
V_162 = F_63 ( V_186 , struct V_161 , V_187 ) ;
switch ( V_162 -> V_40 ) {
case V_184 :
if ( ( V_155 & V_162 -> V_163 ) != V_162 -> V_82 )
break;
if ( ( V_154 & V_162 -> V_163 ) == V_162 -> V_82 )
break;
V_162 -> V_188 = 0 ;
V_162 -> V_40 = V_189 ;
case V_189 :
if ( ( V_155 & V_162 -> V_163 ) != V_162 -> V_82 ) {
V_162 -> V_40 = V_184 ;
break;
}
if ( V_162 -> V_188 < V_162 -> V_190 ) {
V_177 = 0 ;
V_162 -> V_188 ++ ;
break;
}
V_162 -> V_165 = 0 ;
V_162 -> V_40 = V_180 ;
case V_180 :
if ( F_58 ( V_162 ) )
break;
case V_178 :
F_59 ( V_162 ) ;
}
}
}
static void F_64 ( void )
{
if ( V_191 && V_192 ) {
if ( F_65 ( & V_49 ) ) {
F_55 () ;
F_17 ( & V_49 ) ;
}
if ( ! V_177 || V_155 != V_154 )
F_61 () ;
}
if ( V_101 && V_102 ) {
if ( V_171 ) {
if ( V_73 == 0 && ( ( V_60 & V_66 ) == 0 ) )
F_15 ( 1 ) ;
V_73 = V_74 ;
} else if ( V_73 > 0 ) {
V_73 -- ;
if ( V_73 == 0 && ( ( V_60 & V_66 ) == 0 ) )
F_15 ( 0 ) ;
}
}
F_66 ( & V_71 , V_193 + V_194 ) ;
}
static void F_44 ( void )
{
if ( V_71 . V_72 != NULL )
return;
F_67 ( & V_71 ) ;
V_71 . V_195 = V_193 + V_194 ;
V_71 . V_51 = 0 ;
V_71 . V_72 = ( void * ) & F_64 ;
F_68 ( & V_71 ) ;
}
static int F_69 ( const char * V_196 , V_160 * V_163 , V_160 * V_82 ,
char * V_197 , char * V_198 )
{
static char V_199 [ 10 ] = L_6 ;
char V_200 , V_201 ;
V_160 V_202 , V_203 ;
V_201 = V_200 = V_202 = V_203 = 0ULL ;
while ( * V_196 ) {
int V_204 , V_205 , V_2 , V_206 ;
for ( V_204 = 0 ; ( V_204 < sizeof( V_199 ) ) &&
( V_199 [ V_204 ] != * V_196 ) ; V_204 ++ )
;
if ( V_204 >= sizeof( V_199 ) )
return 0 ;
V_206 = ( V_204 & 1 ) ;
V_204 >>= 1 ;
V_200 |= ( 1 << V_204 ) ;
V_196 ++ ;
if ( isdigit ( * V_196 ) ) {
V_205 = * V_196 - '0' ;
V_201 |= ( 1 << V_205 ) ;
} else if ( * V_196 == '-' )
V_205 = 8 ;
else
return 0 ;
V_2 = ( V_205 * 5 ) + V_204 ;
V_202 |= 1ULL << V_2 ;
if ( ! V_206 )
V_203 |= 1ULL << V_2 ;
V_196 ++ ;
}
* V_163 = V_202 ;
* V_82 = V_203 ;
if ( V_197 )
* V_197 |= V_200 ;
if ( V_198 )
* V_198 |= V_201 ;
return 1 ;
}
static struct V_161 * F_70 ( const char * V_196 , const char * V_207 ,
const char * V_208 ,
const char * V_209 )
{
struct V_161 * V_210 ;
V_210 = F_71 ( sizeof( struct V_161 ) , V_211 ) ;
if ( ! V_210 )
return NULL ;
if ( ! F_69 ( V_196 , & V_210 -> V_163 , & V_210 -> V_82 , & V_159 ,
& V_158 ) ) {
F_72 ( V_210 ) ;
return NULL ;
}
V_210 -> type = V_170 ;
V_210 -> V_40 = V_184 ;
V_210 -> V_190 = 1 ;
V_210 -> V_181 = 1 ;
strncpy ( V_210 -> V_166 . V_173 . V_172 , V_207 , sizeof( V_210 -> V_166 . V_173 . V_172 ) ) ;
strncpy ( V_210 -> V_166 . V_173 . V_174 , V_208 , sizeof( V_210 -> V_166 . V_173 . V_174 ) ) ;
strncpy ( V_210 -> V_166 . V_173 . V_183 , V_209 ,
sizeof( V_210 -> V_166 . V_173 . V_183 ) ) ;
F_73 ( & V_210 -> V_187 , & V_212 ) ;
return V_210 ;
}
static void F_74 ( void )
{
int V_213 ;
F_75 ( & V_141 ) ;
V_137 = 0 ;
for ( V_213 = 0 ; V_214 [ V_213 ] [ 0 ] [ 0 ] ; V_213 ++ ) {
F_70 ( V_214 [ V_213 ] [ 0 ] ,
V_214 [ V_213 ] [ 1 ] ,
V_214 [ V_213 ] [ 2 ] ,
V_214 [ V_213 ] [ 3 ] ) ;
}
F_44 () ;
V_192 = 1 ;
}
static int F_76 ( struct V_215 * V_216 , unsigned long V_217 ,
void * V_218 )
{
if ( V_101 && V_102 ) {
switch ( V_217 ) {
case V_219 :
F_42
( L_7 ) ;
break;
case V_220 :
F_42
( L_8 ) ;
break;
case V_221 :
F_42 ( L_9 ) ;
break;
default:
break;
}
}
return V_222 ;
}
static void F_77 ( struct V_223 * V_224 )
{
if ( V_224 -> V_225 != V_223 )
return;
if ( V_3 ) {
F_78 ( L_10 ,
V_226 , V_224 -> V_225 , V_223 ) ;
return;
}
V_3 = F_79 ( V_224 , L_11 , NULL , NULL ,
NULL ,
0 , ( void * ) & V_3 ) ;
if ( V_3 == NULL ) {
F_78 ( L_12 ,
V_226 , V_224 -> V_225 , V_223 ) ;
return;
}
if ( F_80 ( V_3 ) ) {
F_78 ( L_13 ,
V_223 ) ;
goto V_227;
}
if ( V_101 ) {
F_43 () ;
if ( F_81 ( & V_228 ) )
goto V_227;
}
if ( V_191 ) {
F_74 () ;
if ( F_81 ( & V_229 ) )
goto V_230;
}
return;
V_230:
if ( V_101 )
F_82 ( & V_228 ) ;
V_227:
F_83 ( V_3 ) ;
V_3 = NULL ;
}
static void F_84 ( struct V_223 * V_224 )
{
if ( V_224 -> V_225 != V_223 )
return;
if ( ! V_3 ) {
F_78 ( L_14 ,
V_226 , V_224 -> V_225 , V_223 ) ;
return;
}
if ( V_191 && V_192 ) {
F_82 ( & V_229 ) ;
V_192 = 0 ;
}
if ( V_101 && V_102 ) {
F_82 ( & V_228 ) ;
V_102 = 0 ;
}
F_85 ( V_3 ) ;
F_83 ( V_3 ) ;
V_3 = NULL ;
}
static int F_86 ( void )
{
if ( V_231 < 0 )
V_231 = V_191 ;
if ( V_103 < 0 )
V_103 = V_101 ;
if ( V_223 < 0 )
V_223 = V_232 ;
switch ( V_233 ) {
case V_234 :
if ( V_231 < 0 )
V_231 = V_235 ;
if ( V_103 < 0 )
V_103 = V_236 ;
break;
case V_237 :
if ( V_231 < 0 )
V_231 = V_238 ;
if ( V_103 < 0 )
V_103 = V_104 ;
if ( V_75 < 0 )
V_75 = 16 ;
if ( V_53 < 0 )
V_53 = 16 ;
break;
case V_239 :
if ( V_231 < 0 )
V_231 = V_240 ;
if ( V_103 < 0 )
V_103 = V_112 ;
break;
case V_241 :
if ( V_231 < 0 )
V_231 = V_242 ;
if ( V_103 < 0 )
V_103 = V_122 ;
break;
case V_243 :
if ( V_231 < 0 )
V_231 = V_244 ;
if ( V_103 < 0 )
V_103 = V_117 ;
break;
case V_245 :
if ( V_231 < 0 )
V_231 = V_238 ;
if ( V_103 < 0 )
V_103 = V_104 ;
break;
}
V_101 = ( V_103 > 0 ) ;
V_191 = ( V_231 > 0 ) ;
switch ( V_231 ) {
case V_238 :
V_214 = V_246 ;
break;
case V_240 :
V_214 = V_247 ;
break;
case V_244 :
V_214 = V_248 ;
break;
default:
V_214 = NULL ;
break;
}
V_149 = 1 ;
if ( F_87 ( & V_249 ) ) {
F_78 ( L_15 ) ;
return - V_250 ;
}
if ( ! V_101 && ! V_191 ) {
if ( V_3 ) {
F_85 ( V_3 ) ;
F_83 ( V_3 ) ;
V_3 = NULL ;
}
F_88 ( & V_249 ) ;
F_78 ( L_16 V_135 L_17 ) ;
return - V_251 ;
}
F_89 ( & V_252 ) ;
if ( V_3 )
F_90 ( L_16 V_135
L_18 , V_223 ,
V_3 -> V_224 -> V_253 ) ;
else
F_90 ( L_16 V_135
L_19 ) ;
V_149 = 0 ;
return 0 ;
}
static int T_4 F_91 ( void )
{
return F_86 () ;
}
static void T_5 F_92 ( void )
{
F_93 ( & V_252 ) ;
if ( V_71 . V_72 != NULL )
F_94 ( & V_71 ) ;
if ( V_3 != NULL ) {
if ( V_191 ) {
F_82 ( & V_229 ) ;
V_192 = 0 ;
}
if ( V_101 ) {
F_42 ( L_20 V_135
L_21 ) ;
F_82 ( & V_228 ) ;
V_102 = 0 ;
}
F_85 ( V_3 ) ;
F_83 ( V_3 ) ;
V_3 = NULL ;
}
F_88 ( & V_249 ) ;
}
