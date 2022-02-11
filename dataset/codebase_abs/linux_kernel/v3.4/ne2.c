static void T_1 F_1 ( unsigned char V_1 , unsigned int V_2 )
{
int V_3 ;
unsigned char V_4 , V_5 ;
F_2 ( V_1 , V_2 + 0x1e ) ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
do {
V_4 = F_3 ( V_2 + 0x1e ) ;
V_5 = F_3 ( V_2 + 0x1e ) ;
}
while ( ! ( ( V_4 ^ V_5 ) & 0x80 ) );
}
}
static void T_1 F_4 ( unsigned int V_6 , unsigned int V_2 )
{
V_6 = V_6 << 1 ;
F_1 ( 0x09 | V_6 , V_2 ) ;
F_1 ( 0x0d | V_6 , V_2 ) ;
F_1 ( 0x0d | V_6 , V_2 ) ;
F_1 ( 0x09 | V_6 , V_2 ) ;
}
static void T_1 F_5 ( unsigned int V_1 , unsigned int V_7 , unsigned int V_2 )
{
int V_3 ;
V_1 = V_1 << ( 16 - V_7 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
F_4 ( ( V_1 & 0x8000 ) >> 15 , V_2 ) ;
V_1 = V_1 << 1 ;
}
}
static unsigned int T_1 F_6 ( unsigned int V_8 , unsigned int V_2 )
{
int V_3 ;
unsigned int V_1 = 0 ;
F_1 ( 0x01 , V_2 ) ;
F_1 ( 0x09 , V_2 ) ;
F_5 ( 0x0180 | ( V_8 & 0x3f ) , 9 , V_2 ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
F_4 ( 0 , V_2 ) ;
V_1 = ( V_1 << 1 ) | ( F_3 ( V_2 + 0x1e ) & 0x01 ) ;
}
return V_1 ;
}
static int T_1 F_7 ( struct V_9 * V_10 )
{
static int V_11 = - 1 ;
int V_12 ;
int V_13 = 0 ;
for( V_12 = 0 ; ( V_14 [ V_12 ] . V_15 != NULL ) && ! V_13 ; V_12 ++ ) {
V_11 =
F_8 ( V_14 [ V_12 ] . V_16 , 0 ) ;
if( ( V_11 != V_17 ) && ! V_13 ) {
int V_18 ;
F_9 ( V_11 ,
V_14 [ V_12 ] . V_15 ) ;
F_10 ( V_11 ) ;
V_18 = F_11 ( V_10 , V_11 ) ;
if ( V_18 )
F_12 ( V_11 ) ;
return V_18 ;
}
}
return - V_19 ;
}
struct V_9 * T_1 F_13 ( int V_20 )
{
struct V_9 * V_10 = F_14 () ;
int V_21 ;
if ( ! V_10 )
return F_15 ( - V_22 ) ;
sprintf ( V_10 -> V_15 , L_1 , V_20 ) ;
F_16 ( V_10 ) ;
V_21 = F_7 ( V_10 ) ;
if ( V_21 )
goto V_23;
return V_10 ;
V_23:
F_17 ( V_10 ) ;
return F_15 ( V_21 ) ;
}
static int F_18 ( char * V_24 , int V_25 , struct V_9 * V_10 )
{
int V_7 = 0 ;
V_7 += sprintf ( V_24 + V_7 , L_2 ) ;
V_7 += sprintf ( V_24 + V_7 , L_3 ) ;
V_7 += sprintf ( V_24 + V_7 , L_4 ) ;
V_7 += sprintf ( V_24 + V_7 , L_5 ) ;
V_7 += sprintf ( V_24 + V_7 , L_6 ) ;
V_7 += sprintf ( V_24 + V_7 , L_7 ) ;
V_7 += sprintf ( V_24 + V_7 , L_8 ) ;
V_7 += sprintf ( V_24 + V_7 , L_9 , ( unsigned int ) V_10 -> V_26 ) ;
V_7 += sprintf ( V_24 + V_7 , L_10 , V_10 -> V_27 ) ;
V_7 += sprintf ( V_24 + V_7 , L_11 , V_10 -> V_28 ) ;
return V_7 ;
}
static int T_1 F_11 ( struct V_9 * V_10 , int V_25 )
{
int V_12 , V_26 , V_27 , V_29 ;
unsigned char V_30 ;
unsigned char V_31 [ 32 ] ;
const char * V_15 = L_12 ;
int V_32 , V_33 ;
static unsigned V_34 ;
if ( V_35 && V_34 ++ == 0 )
F_19 ( V_36 ) ;
F_19 ( L_13 , V_25 ) ;
V_30 = F_20 ( V_25 , 2 ) ;
if( ! ( V_30 % 2 ) ) {
F_19 ( L_14 ) ;
return - V_19 ;
}
if ( F_20 ( V_25 , 0 ) == 0xea ) {
V_26 = V_37 [ ( V_30 >> 5 ) & 0x03 ] ;
V_27 = V_38 [ ( V_30 >> 2 ) & 0x07 ] ;
}
else {
V_12 = ( V_30 & 0xE ) >> 1 ;
V_26 = V_39 [ V_12 - 1 ] ;
V_27 = V_40 [ ( V_30 & 0x60 ) >> 5 ] ;
}
if ( ! F_21 ( V_26 , V_41 , V_42 ) )
return - V_43 ;
#ifdef F_22
F_19 ( L_15 , V_30 ,
V_26 , V_27 ) ;
#endif
#ifndef F_23
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ )
F_2 ( 0x0 , V_26 + V_44 ) ;
F_3 ( V_26 + V_44 ) ;
F_2 ( 0x21 , V_26 + V_45 ) ;
if ( F_3 ( V_26 + V_45 ) != 0x21 ) {
F_19 ( L_16 ) ;
V_29 = - V_19 ;
goto V_23;
}
#else
{
unsigned long V_46 = V_47 ;
F_2 ( F_3 ( V_26 + V_44 ) , V_26 + V_44 ) ;
while ( ( F_24 ( V_26 + V_48 ) & V_49 ) == 0 )
if ( F_25 ( V_47 , V_46 + 2 * V_50 / 100 ) ) {
F_19 ( L_17 ) ;
V_29 = - V_19 ;
goto V_23;
}
F_26 ( 0xff , V_26 + V_48 ) ;
}
#endif
{
struct {
unsigned char V_1 , V_51 ;
} V_52 [] = {
{ V_53 + V_54 + V_55 , V_56 } ,
{ 0x49 , V_57 } ,
{ 0x00 , V_58 } ,
{ 0x00 , V_59 } ,
{ 0x00 , V_60 } ,
{ 0xFF , V_48 } ,
{ V_61 , V_62 } ,
{ V_63 , V_64 } ,
{ 32 , V_58 } ,
{ 0x00 , V_59 } ,
{ 0x00 , V_65 } ,
{ 0x00 , V_66 } ,
{ V_67 + V_68 , V_56 } ,
} ;
for ( V_12 = 0 ; V_12 < F_27 ( V_52 ) ; V_12 ++ )
F_26 ( V_52 [ V_12 ] . V_1 , V_26 +
V_52 [ V_12 ] . V_51 ) ;
}
for( V_12 = 0 ; V_12 < 6 ; V_12 += 1 ) {
V_31 [ V_12 ] = F_3 ( V_26 + V_69 ) ;
}
if ( F_20 ( V_25 , 0 ) == 0xea ) {
unsigned int V_70 ;
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ ) {
V_70 = F_6 ( V_12 , V_26 ) ;
V_31 [ ( V_12 << 1 ) ] = V_70 & 0xff ;
V_31 [ ( V_12 << 1 ) + 1 ] = ( V_70 >> 8 ) & 0xff ;
}
}
V_32 = V_71 ;
V_33 = V_72 ;
V_10 -> V_27 = V_27 ;
V_29 = F_28 ( V_10 -> V_27 , V_73 , 0 , V_42 , V_10 ) ;
if ( V_29 ) {
F_19 ( L_18 ,
V_10 -> V_27 , V_29 ) ;
goto V_23;
}
V_10 -> V_26 = V_26 ;
for ( V_12 = 0 ; V_12 < V_74 ; V_12 ++ )
V_10 -> V_28 [ V_12 ] = V_31 [ V_12 ] ;
F_19 ( L_19 , V_10 -> V_28 ) ;
F_19 ( L_20 ,
V_10 -> V_15 , V_15 , V_26 , V_10 -> V_27 ) ;
F_29 ( V_25 , ( V_75 ) F_18 , V_10 ) ;
V_76 . V_15 = V_15 ;
V_76 . V_77 = V_32 ;
V_76 . V_33 = V_33 ;
V_76 . V_78 = ( 2 == 2 ) ;
V_76 . V_79 = V_32 + V_80 ;
#ifdef F_30
V_76 . V_33 = V_76 . V_77 + F_30 ;
#endif
V_76 . V_81 = & V_82 ;
V_76 . V_83 = & V_84 ;
V_76 . V_85 = & V_86 ;
V_76 . V_87 = & V_88 ;
V_76 . V_89 = V_25 ;
V_10 -> V_90 = & V_91 ;
F_31 ( V_10 , 0 ) ;
V_29 = F_32 ( V_10 ) ;
if ( V_29 )
goto V_92;
return 0 ;
V_92:
F_29 ( V_76 . V_89 , NULL , NULL ) ;
F_33 ( V_10 -> V_27 , V_10 ) ;
V_23:
F_34 ( V_26 , V_41 ) ;
return V_29 ;
}
static void V_82 ( struct V_9 * V_10 )
{
unsigned long V_46 = V_47 ;
if ( V_35 > 1 )
F_19 ( L_21 , V_47 ) ;
F_2 ( F_3 ( V_93 + V_44 ) , V_93 + V_44 ) ;
V_76 . V_94 = 0 ;
V_76 . V_95 = 0 ;
while ( ( F_24 ( V_93 + V_48 ) & V_49 ) == 0 )
if ( F_25 ( V_47 , V_46 + 2 * V_50 / 100 ) ) {
F_19 ( L_22 ,
V_10 -> V_15 ) ;
break;
}
F_26 ( V_49 , V_93 + V_48 ) ;
}
static void V_88 ( struct V_9 * V_10 , struct V_96 * V_97 ,
int V_98 )
{
int V_99 = V_10 -> V_26 ;
if ( V_76 . V_95 ) {
F_19 ( L_23
L_24 ,
V_10 -> V_15 , V_76 . V_95 , V_76 . V_100 ) ;
return;
}
V_76 . V_95 |= 0x01 ;
F_26 ( V_53 + V_54 + V_68 , V_99 + V_45 ) ;
F_26 ( sizeof( struct V_96 ) , V_99 + V_58 ) ;
F_26 ( 0 , V_99 + V_59 ) ;
F_26 ( 0 , V_99 + V_65 ) ;
F_26 ( V_98 , V_99 + V_66 ) ;
F_26 ( V_67 + V_68 , V_99 + V_45 ) ;
if ( V_76 . V_78 )
F_35 ( V_93 + V_69 , V_97 ,
sizeof( struct V_96 ) >> 1 ) ;
else
F_36 ( V_93 + V_69 , V_97 ,
sizeof( struct V_96 ) ) ;
F_26 ( V_101 , V_99 + V_48 ) ;
V_76 . V_95 &= ~ 0x01 ;
}
static void V_84 ( struct V_9 * V_10 , int V_102 , struct V_103 * V_104 ,
int V_105 )
{
#ifdef F_37
int V_106 = V_102 ;
#endif
int V_99 = V_10 -> V_26 ;
char * V_24 = V_104 -> V_107 ;
if ( V_76 . V_95 ) {
F_19 ( L_25
L_24 ,
V_10 -> V_15 , V_76 . V_95 , V_76 . V_100 ) ;
return;
}
V_76 . V_95 |= 0x01 ;
F_26 ( V_53 + V_54 + V_68 , V_99 + V_45 ) ;
F_26 ( V_102 & 0xff , V_99 + V_58 ) ;
F_26 ( V_102 >> 8 , V_99 + V_59 ) ;
F_26 ( V_105 & 0xff , V_99 + V_65 ) ;
F_26 ( V_105 >> 8 , V_99 + V_66 ) ;
F_26 ( V_67 + V_68 , V_99 + V_45 ) ;
if ( V_76 . V_78 ) {
F_35 ( V_93 + V_69 , V_24 , V_102 >> 1 ) ;
if ( V_102 & 0x01 ) {
V_24 [ V_102 - 1 ] = F_3 ( V_93 + V_69 ) ;
#ifdef F_37
V_106 ++ ;
#endif
}
} else {
F_36 ( V_93 + V_69 , V_24 , V_102 ) ;
}
#ifdef F_37
if ( V_35 > 1 ) {
int V_2 , V_108 = 20 ;
do {
int V_109 = F_24 ( V_99 + V_66 ) ;
int V_110 = F_24 ( V_99 + V_65 ) ;
V_2 = ( V_109 << 8 ) + V_110 ;
if ( ( ( V_105 + V_106 ) & 0xff ) == V_110 )
break;
} while ( -- V_108 > 0 );
if ( V_108 <= 0 )
F_19 ( L_26
L_27 ,
V_10 -> V_15 , V_105 + V_106 , V_2 ) ;
}
#endif
F_26 ( V_101 , V_99 + V_48 ) ;
V_76 . V_95 &= ~ 0x01 ;
}
static void V_86 ( struct V_9 * V_10 , int V_102 ,
const unsigned char * V_24 , const int V_32 )
{
int V_99 = V_93 ;
unsigned long V_111 ;
#ifdef F_37
int V_112 = 0 ;
#endif
if ( V_76 . V_78 && ( V_102 & 0x01 ) )
V_102 ++ ;
if ( V_76 . V_95 ) {
F_19 ( L_28
L_29 ,
V_10 -> V_15 , V_76 . V_95 , V_76 . V_100 ) ;
return;
}
V_76 . V_95 |= 0x01 ;
F_26 ( V_54 + V_68 + V_53 , V_99 + V_45 ) ;
#ifdef F_37
V_113:
#endif
#ifdef F_38
F_26 ( 0x42 , V_99 + V_58 ) ;
F_26 ( 0x00 , V_99 + V_59 ) ;
F_26 ( 0x42 , V_99 + V_65 ) ;
F_26 ( 0x00 , V_99 + V_66 ) ;
F_26 ( V_67 + V_68 , V_99 + V_45 ) ;
V_114 ;
V_114 ;
V_114 ;
#endif
F_26 ( V_101 , V_99 + V_48 ) ;
F_26 ( V_102 & 0xff , V_99 + V_58 ) ;
F_26 ( V_102 >> 8 , V_99 + V_59 ) ;
F_26 ( 0x00 , V_99 + V_65 ) ;
F_26 ( V_32 , V_99 + V_66 ) ;
F_26 ( V_115 + V_68 , V_99 + V_45 ) ;
if ( V_76 . V_78 ) {
F_39 ( V_93 + V_69 , V_24 , V_102 >> 1 ) ;
} else {
F_40 ( V_93 + V_69 , V_24 , V_102 ) ;
}
V_111 = V_47 ;
#ifdef F_37
if ( V_35 > 1 ) {
int V_2 , V_108 = 20 ;
do {
int V_109 = F_24 ( V_99 + V_66 ) ;
int V_110 = F_24 ( V_99 + V_65 ) ;
V_2 = ( V_109 << 8 ) + V_110 ;
if ( ( V_32 << 8 ) + V_102 == V_2 )
break;
} while ( -- V_108 > 0 );
if ( V_108 <= 0 ) {
F_19 ( L_30
L_27 ,
V_10 -> V_15 , ( V_32 << 8 ) + V_102 , V_2 ) ;
if ( V_112 ++ == 0 )
goto V_113;
}
}
#endif
while ( ( F_24 ( V_99 + V_48 ) & V_101 ) == 0 )
if ( F_25 ( V_47 , V_111 + 2 * V_50 / 100 ) ) {
F_19 ( L_31 , V_10 -> V_15 ) ;
V_82 ( V_10 ) ;
F_31 ( V_10 , 1 ) ;
break;
}
F_26 ( V_101 , V_99 + V_48 ) ;
V_76 . V_95 &= ~ 0x01 ;
}
int T_1 F_41 ( void )
{
struct V_9 * V_10 ;
int V_116 , V_117 = 0 ;
for ( V_116 = 0 ; V_116 < V_118 ; V_116 ++ ) {
V_10 = F_14 () ;
if ( ! V_10 )
break;
V_10 -> V_27 = V_27 [ V_116 ] ;
V_10 -> V_119 = V_120 [ V_116 ] ;
V_10 -> V_26 = V_121 [ V_116 ] ;
if ( F_7 ( V_10 ) == 0 ) {
V_122 [ V_117 ++ ] = V_10 ;
continue;
}
F_17 ( V_10 ) ;
break;
}
if ( V_117 )
return 0 ;
F_19 ( V_123 L_32 ) ;
return - V_124 ;
}
static void F_42 ( struct V_9 * V_10 )
{
F_12 ( V_76 . V_89 ) ;
F_29 ( V_76 . V_89 , NULL , NULL ) ;
F_33 ( V_10 -> V_27 , V_10 ) ;
F_34 ( V_10 -> V_26 , V_41 ) ;
}
void T_2 F_43 ( void )
{
int V_116 ;
for ( V_116 = 0 ; V_116 < V_118 ; V_116 ++ ) {
struct V_9 * V_10 = V_122 [ V_116 ] ;
if ( V_10 ) {
F_44 ( V_10 ) ;
F_42 ( V_10 ) ;
F_17 ( V_10 ) ;
}
}
}
