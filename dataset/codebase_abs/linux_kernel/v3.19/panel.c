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
V_23 [ 0 ] = 0 ;
V_24 [ 0 ] = 0 ;
V_23 [ 1 ] = 0 ;
V_24 [ 1 ] = 0 ;
V_23 [ 2 ] = 0xFF ;
V_24 [ 2 ] = 0xFF ;
if ( V_22 == 0 )
return;
V_27 = ( V_22 < 0 ) ;
if ( V_27 )
V_22 = - V_22 ;
V_25 = 0 ;
V_26 = 0 ;
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
if ( F_10 () ) {
F_11 ( V_38 ) ;
} else {
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
if ( V_47 . V_48 . V_16 == V_49 )
return;
F_16 ( & V_50 ) ;
V_9 . V_16 = V_46 ;
F_7 () ;
F_17 ( & V_50 ) ;
}
static void F_18 ( int V_51 )
{
F_16 ( & V_50 ) ;
F_13 ( 0x1F ) ;
F_13 ( V_51 & 0x0F ) ;
F_13 ( ( V_51 >> 4 ) & 0x0F ) ;
F_14 ( 40 ) ;
F_17 ( & V_50 ) ;
}
static void F_19 ( int V_52 )
{
F_16 ( & V_50 ) ;
F_13 ( 0x5F ) ;
F_13 ( V_52 & 0x0F ) ;
F_13 ( ( V_52 >> 4 ) & 0x0F ) ;
F_14 ( 40 ) ;
F_17 ( & V_50 ) ;
}
static void F_20 ( int V_51 )
{
F_16 ( & V_50 ) ;
F_3 ( V_3 , V_51 ) ;
F_14 ( 20 ) ;
V_9 . V_10 = V_45 ;
V_9 . V_12 = V_44 ;
V_9 . V_14 = V_44 ;
F_4 () ;
F_14 ( 40 ) ;
V_9 . V_10 = V_44 ;
F_4 () ;
F_14 ( 120 ) ;
F_17 ( & V_50 ) ;
}
static void F_21 ( int V_52 )
{
F_16 ( & V_50 ) ;
F_3 ( V_3 , V_52 ) ;
F_14 ( 20 ) ;
V_9 . V_10 = V_45 ;
V_9 . V_12 = V_45 ;
V_9 . V_14 = V_44 ;
F_4 () ;
F_14 ( 40 ) ;
V_9 . V_10 = V_44 ;
F_4 () ;
F_14 ( 45 ) ;
F_17 ( & V_50 ) ;
}
static void F_22 ( int V_51 )
{
F_16 ( & V_50 ) ;
F_6 ( V_3 , V_51 ) ;
F_14 ( 60 ) ;
F_17 ( & V_50 ) ;
}
static void F_23 ( int V_52 )
{
F_16 ( & V_50 ) ;
F_3 ( V_3 , V_52 ) ;
F_14 ( 60 ) ;
F_17 ( & V_50 ) ;
}
static void F_24 ( void )
{
F_25 ( 0x80
| ( V_47 . V_53 . V_54 ? V_47 . V_55 : 0 )
| ( ( V_47 . V_53 . V_56 < V_47 . V_57 ) ? V_47 . V_53 . V_56 &
( V_47 . V_55 - 1 ) : V_47 . V_57 - 1 ) ) ;
}
static void F_26 ( char V_58 )
{
if ( V_47 . V_53 . V_56 < V_47 . V_57 ) {
if ( V_59 != NULL )
V_58 = V_59 [ ( unsigned char ) V_58 ] ;
F_27 ( V_58 ) ;
V_47 . V_53 . V_56 ++ ;
}
if ( V_47 . V_53 . V_56 == V_47 . V_57 )
F_24 () ;
}
static void F_28 ( void )
{
int V_60 ;
V_47 . V_53 . V_56 = 0 ;
V_47 . V_53 . V_54 = 0 ;
F_24 () ;
F_16 ( & V_50 ) ;
for ( V_60 = 0 ; V_60 < V_47 . V_61 * V_47 . V_55 ; V_60 ++ ) {
F_13 ( 0x5F ) ;
F_13 ( ' ' & 0x0F ) ;
F_13 ( ( ' ' >> 4 ) & 0x0F ) ;
F_14 ( 40 ) ;
}
F_17 ( & V_50 ) ;
V_47 . V_53 . V_56 = 0 ;
V_47 . V_53 . V_54 = 0 ;
F_24 () ;
}
static void F_29 ( void )
{
int V_60 ;
V_47 . V_53 . V_56 = 0 ;
V_47 . V_53 . V_54 = 0 ;
F_24 () ;
F_16 ( & V_50 ) ;
for ( V_60 = 0 ; V_60 < V_47 . V_61 * V_47 . V_55 ; V_60 ++ ) {
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
F_17 ( & V_50 ) ;
V_47 . V_53 . V_56 = 0 ;
V_47 . V_53 . V_54 = 0 ;
F_24 () ;
}
static void F_30 ( void )
{
int V_60 ;
V_47 . V_53 . V_56 = 0 ;
V_47 . V_53 . V_54 = 0 ;
F_24 () ;
F_16 ( & V_50 ) ;
for ( V_60 = 0 ; V_60 < V_47 . V_61 * V_47 . V_55 ; V_60 ++ ) {
F_3 ( V_3 , ' ' ) ;
F_14 ( 60 ) ;
}
F_17 ( & V_50 ) ;
V_47 . V_53 . V_56 = 0 ;
V_47 . V_53 . V_54 = 0 ;
F_24 () ;
}
static void F_31 ( void )
{
F_25 ( 0x01 ) ;
V_47 . V_53 . V_56 = 0 ;
V_47 . V_53 . V_54 = 0 ;
F_9 ( 15 ) ;
}
static void F_32 ( void )
{
V_47 . V_62 = ( ( V_47 . V_61 > 1 ) ? V_63 : 0 )
| V_64 | V_65 | V_66 ;
F_9 ( 20 ) ;
F_25 ( 0x30 ) ;
F_9 ( 10 ) ;
F_25 ( 0x30 ) ;
F_9 ( 10 ) ;
F_25 ( 0x30 ) ;
F_9 ( 10 ) ;
F_25 ( 0x30
| ( ( V_47 . V_62 & V_67 ) ? 4 : 0 )
| ( ( V_47 . V_62 & V_63 ) ? 8 : 0 )
) ;
F_9 ( 10 ) ;
F_25 ( 0x08 ) ;
F_9 ( 10 ) ;
F_25 ( 0x08
| ( ( V_47 . V_62 & V_64 ) ? 4 : 0 )
| ( ( V_47 . V_62 & V_65 ) ? 2 : 0 )
| ( ( V_47 . V_62 & V_66 ) ? 1 : 0 )
) ;
F_15 ( ( V_47 . V_62 & V_68 ) ? 1 : 0 ) ;
F_9 ( 10 ) ;
F_25 ( 0x06 ) ;
F_31 () ;
}
static inline int F_33 ( void )
{
int V_69 = 0 ;
char * V_70 = V_47 . V_71 . V_72 + 2 ;
int V_73 = V_47 . V_62 ;
switch ( * V_70 ) {
case 'D' :
V_47 . V_62 |= V_64 ;
V_69 = 1 ;
break;
case 'd' :
V_47 . V_62 &= ~ V_64 ;
V_69 = 1 ;
break;
case 'C' :
V_47 . V_62 |= V_65 ;
V_69 = 1 ;
break;
case 'c' :
V_47 . V_62 &= ~ V_65 ;
V_69 = 1 ;
break;
case 'B' :
V_47 . V_62 |= V_66 ;
V_69 = 1 ;
break;
case 'b' :
V_47 . V_62 &= ~ V_66 ;
V_69 = 1 ;
break;
case '+' :
V_47 . V_62 |= V_68 ;
V_69 = 1 ;
break;
case '-' :
V_47 . V_62 &= ~ V_68 ;
V_69 = 1 ;
break;
case '*' :
if ( V_74 . V_75 != NULL ) {
if ( V_47 . V_76 == 0
&& ( ( V_47 . V_62 & V_68 ) == 0 ) )
F_15 ( 1 ) ;
V_47 . V_76 = V_77 ;
}
V_69 = 1 ;
break;
case 'f' :
V_47 . V_62 &= ~ V_67 ;
V_69 = 1 ;
break;
case 'F' :
V_47 . V_62 |= V_67 ;
V_69 = 1 ;
break;
case 'n' :
V_47 . V_62 &= ~ V_63 ;
V_69 = 1 ;
break;
case 'N' :
V_47 . V_62 |= V_63 ;
break;
case 'l' :
if ( V_47 . V_53 . V_56 > 0 ) {
if ( V_47 . V_53 . V_56 < V_47 . V_57 )
F_25 ( 0x10 ) ;
V_47 . V_53 . V_56 -- ;
}
V_69 = 1 ;
break;
case 'r' :
if ( V_47 . V_53 . V_56 < V_47 . V_78 ) {
if ( V_47 . V_53 . V_56 <
( V_47 . V_57 - 1 ) )
F_25 ( 0x14 ) ;
V_47 . V_53 . V_56 ++ ;
}
V_69 = 1 ;
break;
case 'L' :
V_47 . V_79 ++ ;
F_25 ( 0x18 ) ;
V_69 = 1 ;
break;
case 'R' :
V_47 . V_79 -- ;
F_25 ( 0x1C ) ;
V_69 = 1 ;
break;
case 'k' : {
int V_56 ;
for ( V_56 = V_47 . V_53 . V_56 ; V_56 < V_47 . V_57 ; V_56 ++ )
F_27 ( ' ' ) ;
F_24 () ;
V_69 = 1 ;
break;
}
case 'I' :
F_32 () ;
V_47 . V_79 = 0 ;
V_69 = 1 ;
break;
case 'G' : {
unsigned char V_80 [ 8 ] ;
unsigned char V_81 ;
int V_82 ;
int V_83 ;
char V_84 ;
int V_53 ;
if ( strchr ( V_70 , ';' ) == NULL )
break;
V_70 ++ ;
V_81 = * ( V_70 ++ ) - '0' ;
if ( V_81 > 7 ) {
V_69 = 1 ;
break;
}
V_82 = 0 ;
V_83 = 0 ;
V_84 = 0 ;
while ( * V_70 && V_82 < 8 ) {
V_83 ^= 4 ;
if ( * V_70 >= '0' && * V_70 <= '9' ) {
V_84 |= ( * V_70 - '0' ) << V_83 ;
} else if ( * V_70 >= 'A' && * V_70 <= 'Z' ) {
V_84 |= ( * V_70 - 'A' + 10 ) << V_83 ;
} else if ( * V_70 >= 'a' && * V_70 <= 'z' ) {
V_84 |= ( * V_70 - 'a' + 10 ) << V_83 ;
} else {
V_70 ++ ;
continue;
}
if ( V_83 == 0 ) {
V_80 [ V_82 ++ ] = V_84 ;
V_84 = 0 ;
}
V_70 ++ ;
}
F_25 ( 0x40 | ( V_81 * 8 ) ) ;
for ( V_53 = 0 ; V_53 < V_82 ; V_53 ++ )
F_27 ( V_80 [ V_53 ] ) ;
F_24 () ;
V_69 = 1 ;
break;
}
case 'x' :
case 'y' :
if ( strchr ( V_70 , ';' ) == NULL )
break;
while ( * V_70 ) {
if ( * V_70 == 'x' ) {
V_70 ++ ;
if ( F_34 ( V_70 , 10 , & V_47 . V_53 . V_56 ) < 0 )
break;
} else if ( * V_70 == 'y' ) {
V_70 ++ ;
if ( F_34 ( V_70 , 10 , & V_47 . V_53 . V_54 ) < 0 )
break;
} else {
break;
}
}
F_24 () ;
V_69 = 1 ;
break;
}
if ( V_73 != V_47 . V_62 ) {
if ( ( V_73 ^ V_47 . V_62 ) &
( V_66 | V_65 | V_64 ) )
F_25 ( 0x08
| ( ( V_47 . V_62 & V_64 ) ? 4 : 0 )
| ( ( V_47 . V_62 & V_65 ) ? 2 : 0 )
| ( ( V_47 . V_62 & V_66 ) ? 1 : 0 ) ) ;
else if ( ( V_73 ^ V_47 . V_62 ) & ( V_67 | V_63 ) )
F_25 ( 0x30
| ( ( V_47 . V_62 & V_67 ) ? 4 : 0 )
| ( ( V_47 . V_62 & V_63 ) ? 8 : 0 ) ) ;
else if ( ( V_73 ^ V_47 . V_62 ) & ( V_68 ) ) {
if ( V_47 . V_62 & ( V_68 ) )
F_15 ( 1 ) ;
else if ( V_47 . V_76 == 0 )
F_15 ( 0 ) ;
}
}
return V_69 ;
}
static void F_35 ( char V_58 )
{
if ( ( V_58 != '\n' ) && V_47 . V_71 . V_85 >= 0 ) {
V_47 . V_71 . V_72 [ V_47 . V_71 . V_85 ++ ] = V_58 ;
V_47 . V_71 . V_72 [ V_47 . V_71 . V_85 ] = 0 ;
} else {
V_47 . V_71 . V_85 = - 1 ;
switch ( V_58 ) {
case V_86 :
V_47 . V_71 . V_85 = 0 ;
V_47 . V_71 . V_72 [ V_47 . V_71 . V_85 ] = 0 ;
break;
case '\b' :
if ( V_47 . V_53 . V_56 > 0 ) {
if ( V_47 . V_53 . V_56 < V_47 . V_57 )
F_25 ( 0x10 ) ;
V_47 . V_53 . V_56 -- ;
}
F_27 ( ' ' ) ;
F_25 ( 0x10 ) ;
break;
case '\014' :
F_36 () ;
break;
case '\n' :
for (; V_47 . V_53 . V_56 < V_47 . V_57 ; V_47 . V_53 . V_56 ++ )
F_27 ( ' ' ) ;
V_47 . V_53 . V_56 = 0 ;
V_47 . V_53 . V_54 = ( V_47 . V_53 . V_54 + 1 ) % V_47 . V_61 ;
F_24 () ;
break;
case '\r' :
V_47 . V_53 . V_56 = 0 ;
F_24 () ;
break;
case '\t' :
F_26 ( ' ' ) ;
break;
default:
F_26 ( V_58 ) ;
break;
}
}
if ( V_47 . V_71 . V_85 >= 2 ) {
int V_69 = 0 ;
if ( ! strcmp ( V_47 . V_71 . V_72 , L_1 ) ) {
F_36 () ;
V_69 = 1 ;
} else if ( ! strcmp ( V_47 . V_71 . V_72 , L_2 ) ) {
V_47 . V_53 . V_56 = 0 ;
V_47 . V_53 . V_54 = 0 ;
F_24 () ;
V_69 = 1 ;
}
else if ( ( V_47 . V_71 . V_85 >= 3 ) &&
( V_47 . V_71 . V_72 [ 0 ] == '[' ) &&
( V_47 . V_71 . V_72 [ 1 ] == 'L' ) ) {
V_69 = F_33 () ;
}
if ( V_69 || ( V_47 . V_71 . V_85 >= V_87 ) )
V_47 . V_71 . V_85 = - 1 ;
}
}
static T_1 F_37 ( struct V_88 * V_88 ,
const char T_2 * V_72 , T_3 V_89 , T_4 * V_90 )
{
const char T_2 * V_91 = V_72 ;
char V_58 ;
for (; V_89 -- > 0 ; ( * V_90 ) ++ , V_91 ++ ) {
if ( ! F_10 () && ( ( ( V_89 + 1 ) & 0x1f ) == 0 ) )
F_38 () ;
if ( F_39 ( V_58 , V_91 ) )
return - V_92 ;
F_35 ( V_58 ) ;
}
return V_91 - V_72 ;
}
static int F_40 ( struct V_93 * V_93 , struct V_88 * V_88 )
{
if ( ! F_41 ( & V_94 ) )
return - V_95 ;
if ( V_88 -> V_96 & V_97 )
return - V_98 ;
if ( V_47 . V_99 ) {
F_31 () ;
V_47 . V_99 = false ;
}
return F_42 ( V_93 , V_88 ) ;
}
static int F_43 ( struct V_93 * V_93 , struct V_88 * V_88 )
{
F_44 ( & V_94 ) ;
return 0 ;
}
static void F_45 ( const char * V_100 )
{
const char * V_91 = V_100 ;
int V_89 = strlen ( V_100 ) ;
if ( V_47 . V_101 && V_47 . V_102 ) {
for (; V_89 -- > 0 ; V_91 ++ ) {
if ( ! F_10 () && ( ( ( V_89 + 1 ) & 0x1f ) == 0 ) )
F_38 () ;
F_35 ( * V_91 ) ;
}
}
}
static void F_46 ( void )
{
switch ( V_103 ) {
case V_104 :
V_47 . V_105 = V_106 ;
V_47 . V_107 = V_108 ;
V_47 . V_48 . V_10 = V_28 ;
V_47 . V_48 . V_12 = V_32 ;
V_47 . V_78 = 40 ;
V_47 . V_57 = 40 ;
V_47 . V_55 = 64 ;
V_47 . V_61 = 2 ;
break;
case V_109 :
V_47 . V_105 = V_110 ;
V_47 . V_107 = V_111 ;
V_47 . V_48 . V_16 = V_32 ;
V_47 . V_48 . V_18 = V_28 ;
V_47 . V_48 . V_20 = V_30 ;
V_47 . V_78 = 16 ;
V_47 . V_57 = 40 ;
V_47 . V_55 = 16 ;
V_47 . V_61 = 2 ;
break;
case V_112 :
V_47 . V_105 = V_106 ;
V_47 . V_107 = V_108 ;
V_47 . V_48 . V_10 = V_32 ;
V_47 . V_48 . V_12 = V_36 ;
V_47 . V_48 . V_14 = V_34 ;
V_47 . V_78 = 16 ;
V_47 . V_57 = 40 ;
V_47 . V_55 = 64 ;
V_47 . V_61 = 2 ;
break;
case V_113 :
V_47 . V_105 = V_114 ;
V_47 . V_107 = V_115 ;
break;
case V_116 :
default:
V_47 . V_105 = V_106 ;
V_47 . V_107 = V_108 ;
V_47 . V_48 . V_10 = V_28 ;
V_47 . V_48 . V_12 = V_36 ;
V_47 . V_78 = 16 ;
V_47 . V_57 = 40 ;
V_47 . V_55 = 64 ;
V_47 . V_61 = 2 ;
break;
}
if ( V_117 != V_118 )
V_47 . V_61 = V_117 ;
if ( V_119 != V_118 )
V_47 . V_78 = V_119 ;
if ( V_120 != V_118 )
V_47 . V_57 = V_120 ;
if ( V_121 != V_118 )
V_47 . V_55 = V_121 ;
if ( V_122 != V_118 )
V_47 . V_107 = V_122 ;
if ( V_123 != V_118 )
V_47 . V_105 = V_123 ;
if ( V_124 != V_125 )
V_47 . V_48 . V_10 = V_124 ;
if ( V_126 != V_125 )
V_47 . V_48 . V_12 = V_126 ;
if ( V_127 != V_125 )
V_47 . V_48 . V_14 = V_127 ;
if ( V_128 != V_125 )
V_47 . V_48 . V_18 = V_128 ;
if ( V_129 != V_125 )
V_47 . V_48 . V_20 = V_129 ;
if ( V_130 != V_125 )
V_47 . V_48 . V_16 = V_130 ;
if ( V_47 . V_78 <= 0 )
V_47 . V_78 = V_131 ;
if ( V_47 . V_57 <= 0 )
V_47 . V_57 = V_132 ;
if ( V_47 . V_55 <= 0 )
V_47 . V_55 = V_133 ;
if ( V_47 . V_61 <= 0 )
V_47 . V_61 = V_134 ;
if ( V_47 . V_105 == V_110 ) {
F_25 = F_18 ;
F_27 = F_19 ;
F_36 = F_28 ;
if ( V_47 . V_48 . V_18 == V_125 )
V_47 . V_48 . V_18 = V_135 ;
if ( V_47 . V_48 . V_20 == V_125 )
V_47 . V_48 . V_20 = V_136 ;
} else if ( V_47 . V_105 == V_106 ) {
F_25 = F_20 ;
F_27 = F_21 ;
F_36 = F_29 ;
if ( V_47 . V_48 . V_10 == V_125 )
V_47 . V_48 . V_10 = V_137 ;
if ( V_47 . V_48 . V_12 == V_125 )
V_47 . V_48 . V_12 = V_138 ;
if ( V_47 . V_48 . V_14 == V_125 )
V_47 . V_48 . V_14 = V_139 ;
} else {
F_25 = F_22 ;
F_27 = F_23 ;
F_36 = F_30 ;
}
if ( V_47 . V_48 . V_16 == V_125 )
V_47 . V_48 . V_16 = V_140 ;
if ( V_47 . V_48 . V_10 == V_125 )
V_47 . V_48 . V_10 = V_49 ;
if ( V_47 . V_48 . V_12 == V_125 )
V_47 . V_48 . V_12 = V_49 ;
if ( V_47 . V_48 . V_14 == V_125 )
V_47 . V_48 . V_14 = V_49 ;
if ( V_47 . V_48 . V_16 == V_125 )
V_47 . V_48 . V_16 = V_49 ;
if ( V_47 . V_48 . V_18 == V_125 )
V_47 . V_48 . V_18 = V_49 ;
if ( V_47 . V_48 . V_20 == V_125 )
V_47 . V_48 . V_20 = V_49 ;
if ( V_47 . V_107 == V_118 )
V_47 . V_107 = V_115 ;
if ( V_47 . V_107 == V_111 )
V_59 = V_141 ;
else
V_59 = NULL ;
if ( V_47 . V_48 . V_16 != V_49 )
F_47 () ;
F_8 ( V_47 . V_48 . V_10 , V_5 [ V_6 ] [ V_8 ] ,
V_5 [ V_21 ] [ V_8 ] ) ;
F_8 ( V_47 . V_48 . V_12 , V_5 [ V_6 ] [ V_11 ] ,
V_5 [ V_21 ] [ V_11 ] ) ;
F_8 ( V_47 . V_48 . V_14 , V_5 [ V_6 ] [ V_13 ] ,
V_5 [ V_21 ] [ V_13 ] ) ;
F_8 ( V_47 . V_48 . V_16 , V_5 [ V_6 ] [ V_15 ] ,
V_5 [ V_21 ] [ V_15 ] ) ;
F_8 ( V_47 . V_48 . V_18 , V_5 [ V_6 ] [ V_17 ] ,
V_5 [ V_21 ] [ V_17 ] ) ;
F_8 ( V_47 . V_48 . V_20 , V_5 [ V_6 ] [ V_19 ] ,
V_5 [ V_21 ] [ V_19 ] ) ;
V_47 . V_102 = true ;
F_32 () ;
#ifdef F_48
#ifdef F_49
F_45 ( L_3 F_49 ) ;
#endif
#else
F_45 ( L_4 V_142 L_5
V_143 ) ;
#endif
V_47 . V_53 . V_56 = 0 ;
V_47 . V_53 . V_54 = 0 ;
V_47 . V_99 = true ;
F_24 () ;
}
static T_1 F_50 ( struct V_88 * V_88 ,
char T_2 * V_72 , T_3 V_89 , T_4 * V_90 )
{
unsigned V_144 = * V_90 ;
char T_2 * V_91 = V_72 ;
if ( V_145 == 0 ) {
if ( V_88 -> V_146 & V_147 )
return - V_148 ;
if ( F_51 ( V_149 ,
V_145 != 0 ) )
return - V_150 ;
}
for (; V_89 -- > 0 && ( V_145 > 0 ) ;
++ V_144 , ++ V_91 , -- V_145 ) {
F_52 ( V_151 [ V_152 ] , V_91 ) ;
V_152 = ( V_152 + 1 ) % V_153 ;
}
* V_90 = V_144 ;
return V_91 - V_72 ;
}
static int F_53 ( struct V_93 * V_93 , struct V_88 * V_88 )
{
if ( ! F_41 ( & V_154 ) )
return - V_95 ;
if ( V_88 -> V_96 & V_155 )
return - V_98 ;
V_145 = 0 ;
return 0 ;
}
static int F_54 ( struct V_93 * V_93 , struct V_88 * V_88 )
{
F_44 ( & V_154 ) ;
return 0 ;
}
static void F_55 ( const char * string , int V_156 )
{
if ( V_157 )
return;
if ( ! F_56 ( & V_154 ) ) {
while ( V_156 -- && V_145 < V_153 && * string ) {
V_151 [ ( V_152 + V_145 ++ ) %
V_153 ] = * string ++ ;
}
F_57 ( & V_149 ) ;
}
}
static void F_58 ( void )
{
int V_2 , V_158 ;
char V_159 ;
char V_160 ;
char V_161 ;
V_162 = V_163 ;
V_164 = V_165 ;
V_165 = 0 ;
V_159 = F_2 ( V_3 ) | V_166 ;
F_3 ( V_3 , V_159 & ~ V_166 ) ;
V_160 = F_59 ( F_60 ( V_3 ) ) & V_167 ;
F_3 ( V_3 , V_159 ) ;
V_161 = F_59 ( F_60 ( V_3 ) ) & V_167 ;
V_165 |= ( V_168 ) V_161 << 40 ;
if ( V_160 != V_161 ) {
for ( V_2 = 0 ; V_2 < 8 ; V_2 ++ ) {
V_158 = 1 << V_2 ;
if ( ! ( V_166 & V_158 ) )
continue;
F_3 ( V_3 , V_159 & ~ V_158 ) ;
V_160 = F_59 ( F_60 ( V_3 ) ) & ~ V_161 ;
V_165 |= ( V_168 ) V_160 << ( 5 * V_2 ) ;
}
F_3 ( V_3 , V_159 ) ;
}
V_163 = ( V_162 & ( V_165 ^ V_164 ) ) |
( V_165 & ~ ( V_165 ^ V_164 ) ) ;
}
static inline int F_61 ( struct V_169 * V_170 )
{
#if 0
if (((phys_prev & input->mask) == input->value) &&
((phys_curr & input->mask) > input->value)) {
input->state = INPUT_ST_LOW;
return 1;
}
#endif
if ( ( V_163 & V_170 -> V_171 ) == V_170 -> V_84 ) {
if ( ( V_170 -> type == V_172 ) &&
( V_170 -> V_173 == 0 ) ) {
V_170 -> V_173 ++ ;
if ( V_170 -> V_174 . V_175 . V_176 != NULL )
V_170 -> V_174 . V_175 . V_176 ( V_170 -> V_174 . V_175 . V_177 ) ;
} else if ( V_170 -> type == V_178 ) {
V_179 = 1 ;
if ( V_170 -> V_173 == 0 ) {
char * V_180 = V_170 -> V_174 . V_181 . V_180 ;
if ( V_180 [ 0 ] ) {
int V_100 = sizeof( V_170 -> V_174 . V_181 . V_180 ) ;
F_55 ( V_180 , V_100 ) ;
}
}
if ( V_170 -> V_174 . V_181 . V_182 [ 0 ] ) {
char * V_182 = V_170 -> V_174 . V_181 . V_182 ;
if ( V_170 -> V_173 >= V_183 ) {
int V_100 = sizeof( V_170 -> V_174 . V_181 . V_182 ) ;
V_170 -> V_173 -= V_184 ;
F_55 ( V_182 , V_100 ) ;
}
V_185 = 0 ;
}
if ( V_170 -> V_173 < 255 )
V_170 -> V_173 ++ ;
}
return 1 ;
}
V_170 -> V_40 = V_186 ;
V_170 -> V_187 = 0 ;
return 0 ;
}
static inline void F_62 ( struct V_169 * V_170 )
{
#if 0
if (((phys_prev & input->mask) == input->value) &&
((phys_curr & input->mask) > input->value)) {
input->state = INPUT_ST_LOW;
return;
}
#endif
if ( ( V_163 & V_170 -> V_171 ) == V_170 -> V_84 ) {
if ( V_170 -> type == V_178 ) {
V_179 = 1 ;
if ( V_170 -> V_174 . V_181 . V_182 [ 0 ] ) {
char * V_182 = V_170 -> V_174 . V_181 . V_182 ;
if ( V_170 -> V_173 >= V_183 ) {
int V_100 = sizeof( V_170 -> V_174 . V_181 . V_182 ) ;
V_170 -> V_173 -= V_184 ;
F_55 ( V_182 , V_100 ) ;
}
V_185 = 0 ;
}
if ( V_170 -> V_173 < 255 )
V_170 -> V_173 ++ ;
}
V_170 -> V_40 = V_188 ;
} else if ( V_170 -> V_187 >= V_170 -> V_189 ) {
if ( V_170 -> type == V_172 ) {
void (* F_63)( int ) = V_170 -> V_174 . V_175 . F_63 ;
if ( F_63 != NULL )
F_63 ( V_170 -> V_174 . V_175 . V_190 ) ;
} else if ( V_170 -> type == V_178 ) {
char * V_191 = V_170 -> V_174 . V_181 . V_191 ;
if ( V_191 [ 0 ] ) {
int V_100 = sizeof( V_170 -> V_174 . V_181 . V_191 ) ;
F_55 ( V_191 , V_100 ) ;
}
}
V_170 -> V_40 = V_192 ;
} else {
V_170 -> V_187 ++ ;
V_185 = 0 ;
}
}
static void F_64 ( void )
{
struct V_193 * V_194 ;
struct V_169 * V_170 ;
V_179 = 0 ;
V_185 = 1 ;
F_65 (item, &logical_inputs) {
V_170 = F_66 ( V_194 , struct V_169 , V_195 ) ;
switch ( V_170 -> V_40 ) {
case V_192 :
if ( ( V_163 & V_170 -> V_171 ) != V_170 -> V_84 )
break;
if ( ( V_162 & V_170 -> V_171 ) == V_170 -> V_84 )
break;
V_170 -> V_196 = 0 ;
V_170 -> V_40 = V_197 ;
case V_197 :
if ( ( V_163 & V_170 -> V_171 ) != V_170 -> V_84 ) {
V_170 -> V_40 = V_192 ;
break;
}
if ( V_170 -> V_196 < V_170 -> V_198 ) {
V_185 = 0 ;
V_170 -> V_196 ++ ;
break;
}
V_170 -> V_173 = 0 ;
V_170 -> V_40 = V_188 ;
case V_188 :
if ( F_61 ( V_170 ) )
break;
case V_186 :
F_62 ( V_170 ) ;
}
}
}
static void F_67 ( void )
{
if ( V_199 . V_101 && V_200 ) {
if ( F_68 ( & V_50 ) ) {
F_58 () ;
F_17 ( & V_50 ) ;
}
if ( ! V_185 || V_163 != V_162 )
F_64 () ;
}
if ( V_47 . V_101 && V_47 . V_102 ) {
if ( V_179 ) {
if ( V_47 . V_76 == 0
&& ( ( V_47 . V_62 & V_68 ) == 0 ) )
F_15 ( 1 ) ;
V_47 . V_76 = V_77 ;
} else if ( V_47 . V_76 > 0 ) {
V_47 . V_76 -- ;
if ( V_47 . V_76 == 0
&& ( ( V_47 . V_62 & V_68 ) == 0 ) )
F_15 ( 0 ) ;
}
}
F_69 ( & V_74 , V_201 + V_202 ) ;
}
static void F_47 ( void )
{
if ( V_74 . V_75 != NULL )
return;
F_70 ( & V_74 ) ;
V_74 . V_203 = V_201 + V_202 ;
V_74 . V_52 = 0 ;
V_74 . V_75 = ( void * ) & F_67 ;
F_71 ( & V_74 ) ;
}
static int F_72 ( const char * V_204 , V_168 * V_171 , V_168 * V_84 ,
char * V_205 , char * V_206 )
{
static char V_207 [ 10 ] = L_6 ;
char V_208 , V_209 ;
V_168 V_210 , V_211 ;
V_209 = 0ULL ;
V_208 = 0ULL ;
V_210 = 0ULL ;
V_211 = 0ULL ;
while ( * V_204 ) {
int V_212 , V_213 , V_2 , V_214 ;
for ( V_212 = 0 ; ( V_212 < sizeof( V_207 ) ) && ( V_207 [ V_212 ] != * V_204 ) ;
V_212 ++ )
;
if ( V_212 >= sizeof( V_207 ) )
return 0 ;
V_214 = ( V_212 & 1 ) ;
V_212 >>= 1 ;
V_208 |= ( 1 << V_212 ) ;
V_204 ++ ;
if ( isdigit ( * V_204 ) ) {
V_213 = * V_204 - '0' ;
V_209 |= ( 1 << V_213 ) ;
} else if ( * V_204 == '-' ) {
V_213 = 8 ;
} else {
return 0 ;
}
V_2 = ( V_213 * 5 ) + V_212 ;
V_210 |= 1ULL << V_2 ;
if ( ! V_214 )
V_211 |= 1ULL << V_2 ;
V_204 ++ ;
}
* V_171 = V_210 ;
* V_84 = V_211 ;
if ( V_205 )
* V_205 |= V_208 ;
if ( V_206 )
* V_206 |= V_209 ;
return 1 ;
}
static struct V_169 * F_73 ( const char * V_204 , const char * V_215 ,
const char * V_216 ,
const char * V_217 )
{
struct V_169 * V_218 ;
V_218 = F_74 ( sizeof( * V_218 ) , V_219 ) ;
if ( ! V_218 )
return NULL ;
if ( ! F_72 ( V_204 , & V_218 -> V_171 , & V_218 -> V_84 , & V_167 ,
& V_166 ) ) {
F_75 ( V_218 ) ;
return NULL ;
}
V_218 -> type = V_178 ;
V_218 -> V_40 = V_192 ;
V_218 -> V_198 = 1 ;
V_218 -> V_189 = 1 ;
strncpy ( V_218 -> V_174 . V_181 . V_180 , V_215 , sizeof( V_218 -> V_174 . V_181 . V_180 ) ) ;
strncpy ( V_218 -> V_174 . V_181 . V_182 , V_216 , sizeof( V_218 -> V_174 . V_181 . V_182 ) ) ;
strncpy ( V_218 -> V_174 . V_181 . V_191 , V_217 ,
sizeof( V_218 -> V_174 . V_181 . V_191 ) ) ;
F_76 ( & V_218 -> V_195 , & V_220 ) ;
return V_218 ;
}
static void F_77 ( void )
{
int V_221 ;
F_78 ( & V_149 ) ;
V_145 = 0 ;
for ( V_221 = 0 ; V_222 [ V_221 ] [ 0 ] [ 0 ] ; V_221 ++ ) {
F_73 ( V_222 [ V_221 ] [ 0 ] ,
V_222 [ V_221 ] [ 1 ] ,
V_222 [ V_221 ] [ 2 ] ,
V_222 [ V_221 ] [ 3 ] ) ;
}
F_47 () ;
V_200 = 1 ;
}
static int F_79 ( struct V_223 * V_224 , unsigned long V_225 ,
void * V_226 )
{
if ( V_47 . V_101 && V_47 . V_102 ) {
switch ( V_225 ) {
case V_227 :
F_45
( L_7 ) ;
break;
case V_228 :
F_45
( L_8 ) ;
break;
case V_229 :
F_45 ( L_9 ) ;
break;
default:
break;
}
}
return V_230 ;
}
static void F_80 ( struct V_231 * V_232 )
{
if ( V_232 -> V_233 != V_231 )
return;
if ( V_3 ) {
F_81 ( L_10 ,
V_234 , V_232 -> V_233 , V_231 ) ;
return;
}
V_3 = F_82 ( V_232 , L_11 , NULL , NULL ,
NULL ,
0 , ( void * ) & V_3 ) ;
if ( V_3 == NULL ) {
F_81 ( L_12 ,
V_234 , V_232 -> V_233 , V_231 ) ;
return;
}
if ( F_83 ( V_3 ) ) {
F_81 ( L_13 ,
V_231 ) ;
goto V_235;
}
if ( V_47 . V_101 ) {
F_46 () ;
if ( F_84 ( & V_236 ) )
goto V_235;
}
if ( V_199 . V_101 ) {
F_77 () ;
if ( F_84 ( & V_237 ) )
goto V_238;
}
return;
V_238:
if ( V_47 . V_101 )
F_85 ( & V_236 ) ;
V_235:
F_86 ( V_3 ) ;
V_3 = NULL ;
}
static void F_87 ( struct V_231 * V_232 )
{
if ( V_232 -> V_233 != V_231 )
return;
if ( ! V_3 ) {
F_81 ( L_14 ,
V_234 , V_232 -> V_233 , V_231 ) ;
return;
}
if ( V_199 . V_101 && V_200 ) {
F_85 ( & V_237 ) ;
V_200 = 0 ;
}
if ( V_47 . V_101 && V_47 . V_102 ) {
F_85 ( & V_236 ) ;
V_47 . V_102 = false ;
}
F_88 ( V_3 ) ;
F_86 ( V_3 ) ;
V_3 = NULL ;
}
static int T_5 F_89 ( void )
{
int V_239 = V_118 ;
switch ( V_240 ) {
case V_241 :
V_239 = V_242 ;
V_103 = V_243 ;
break;
case V_244 :
V_239 = V_245 ;
V_103 = V_104 ;
if ( V_119 == V_118 )
V_119 = 16 ;
if ( V_121 == V_118 )
V_121 = 16 ;
break;
case V_246 :
V_239 = V_247 ;
V_103 = V_109 ;
break;
case V_248 :
V_239 = V_249 ;
V_103 = V_116 ;
break;
case V_250 :
V_239 = V_251 ;
V_103 = V_112 ;
break;
case V_252 :
V_239 = V_245 ;
V_103 = V_104 ;
break;
}
V_47 . V_61 = V_117 ;
V_47 . V_78 = V_119 ;
V_47 . V_57 = V_120 ;
V_47 . V_55 = V_121 ;
V_47 . V_107 = V_122 ;
V_47 . V_105 = V_123 ;
V_47 . V_48 . V_10 = V_124 ;
V_47 . V_48 . V_12 = V_126 ;
V_47 . V_48 . V_14 = V_127 ;
V_47 . V_48 . V_18 = V_128 ;
V_47 . V_48 . V_20 = V_129 ;
V_47 . V_48 . V_16 = V_130 ;
V_47 . V_71 . V_85 = - 1 ;
if ( V_253 != V_118 )
V_239 = V_253 ;
if ( V_254 != V_118 )
V_239 = V_254 ;
V_199 . V_101 = ( V_239 > 0 ) ;
if ( V_255 != V_118 )
V_103 = V_255 ;
if ( V_256 != V_118 )
V_103 = V_256 ;
V_47 . V_101 = ( V_103 > 0 ) ;
switch ( V_239 ) {
case V_245 :
V_222 = V_257 ;
break;
case V_247 :
V_222 = V_258 ;
break;
case V_251 :
V_222 = V_259 ;
break;
default:
V_222 = NULL ;
break;
}
V_157 = 1 ;
if ( F_90 ( & V_260 ) ) {
F_81 ( L_15 ) ;
return - V_261 ;
}
if ( ! V_47 . V_101 && ! V_199 . V_101 ) {
if ( V_3 ) {
F_88 ( V_3 ) ;
F_86 ( V_3 ) ;
V_3 = NULL ;
}
F_91 ( & V_260 ) ;
F_81 ( L_16 V_143 L_17 ) ;
return - V_262 ;
}
F_92 ( & V_263 ) ;
if ( V_3 )
F_93 ( L_16 V_143
L_18 , V_231 ,
V_3 -> V_232 -> V_264 ) ;
else
F_93 ( L_16 V_143
L_19 ) ;
V_157 = 0 ;
return 0 ;
}
static void T_6 F_94 ( void )
{
F_95 ( & V_263 ) ;
if ( V_74 . V_75 != NULL )
F_96 ( & V_74 ) ;
if ( V_3 != NULL ) {
if ( V_199 . V_101 ) {
F_85 ( & V_237 ) ;
V_200 = 0 ;
}
if ( V_47 . V_101 ) {
F_45 ( L_20 V_143
L_21 ) ;
F_85 ( & V_236 ) ;
V_47 . V_102 = false ;
}
F_88 ( V_3 ) ;
F_86 ( V_3 ) ;
V_3 = NULL ;
}
F_91 ( & V_260 ) ;
}
