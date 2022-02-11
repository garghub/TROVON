static int T_1 F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
unsigned char V_7 ;
V_7 = * ( volatile unsigned char * ) V_8 ;
V_7 &= 1 << ( ( V_3 >> 21 ) & 7 ) ;
for ( V_6 = 0 ; V_6 < F_3 ( V_9 ) ; V_6 ++ )
if ( V_7 == 0 )
V_9 [ V_6 ] = V_6 * 2 + 1 ;
else
V_9 [ V_6 ] = V_6 ;
V_5 -> V_9 = V_9 ;
return 0 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
if ( V_10 < F_3 ( V_11 ) ) {
V_2 -> V_3 = V_11 [ V_10 ] ;
V_2 -> V_12 = V_13 [ V_10 ] ;
V_10 ++ ;
return 0 ;
} else
return - V_14 ;
}
static int T_1 F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( V_3 > 0x1ff )
return F_6 ( V_2 , V_3 ) ;
else if ( V_3 != 0 )
return - V_15 ;
return - V_14 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_12 , V_2 ) ;
F_9 ( V_2 -> V_3 , V_16 ) ;
}
struct V_1 * T_1 F_10 ( int V_17 )
{
struct V_1 * V_2 = F_11 ( 0 ) ;
int V_18 ;
if ( ! V_2 )
return F_12 ( - V_19 ) ;
if ( F_4 ( V_2 ) )
return F_12 ( - V_14 ) ;
sprintf ( V_2 -> V_20 , L_1 , V_17 ) ;
F_13 ( V_2 ) ;
V_18 = F_1 ( V_2 , V_2 -> V_3 ) ;
if ( V_18 )
goto V_21;
V_18 = F_5 ( V_2 ) ;
if ( V_18 )
goto V_21;
return V_2 ;
V_21:
F_14 ( V_2 ) ;
return F_12 ( V_18 ) ;
}
static int T_1 F_6 ( struct V_1 * V_2 , int V_22 )
{
int V_6 ;
unsigned char V_23 [ 16 ] ;
int V_24 = 2 ;
const char * V_20 = NULL ;
int V_25 , V_26 ;
int V_27 , V_28 ;
static unsigned V_29 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned char V_7 ;
if ( ! F_15 ( V_22 , V_16 , V_30 ) )
return - V_31 ;
V_27 = F_16 ( V_22 ) ;
if ( V_27 == 0xFF ) {
V_28 = - V_14 ;
goto V_32;
}
{
int V_33 ;
F_17 ( V_34 + V_35 + V_36 , V_22 + V_37 ) ;
V_33 = F_16 ( V_22 + F_18 ( 0x0d ) ) ;
F_17 ( 0xff , V_22 + F_18 ( 0x0d ) ) ;
F_17 ( V_34 + V_38 , V_22 + V_37 ) ;
F_16 ( V_22 + V_39 ) ;
if ( F_16 ( V_22 + V_39 ) != 0 ) {
F_17 ( V_27 , V_22 + F_18 ( 0 ) ) ;
F_17 ( V_33 , V_22 + F_18 ( 0x0d ) ) ;
V_28 = - V_14 ;
goto V_32;
}
}
if ( V_40 && V_29 ++ == 0 )
F_19 ( V_41 L_2 , V_42 ) ;
F_19 ( V_41 L_3 , V_22 ) ;
{
struct { unsigned char V_43 , V_44 ; } V_45 [] =
{
{ V_34 + V_38 + V_36 , V_37 } ,
{ 0x48 , V_46 } ,
{ 0x00 , V_47 } ,
{ 0x00 , V_48 } ,
{ 0x00 , V_49 } ,
{ 0xFF , V_50 } ,
{ V_51 , V_52 } ,
{ V_53 , V_54 } ,
{ 32 , V_47 } ,
{ 0x00 , V_48 } ,
{ 0x00 , V_55 } ,
{ 0x00 , V_56 } ,
{ V_57 + V_58 , V_37 } ,
} ;
for ( V_6 = 0 ; V_6 < F_3 ( V_45 ) ; V_6 ++ )
F_17 ( V_45 [ V_6 ] . V_43 , V_22 + V_45 [ V_6 ] . V_44 ) ;
}
V_7 = * ( volatile unsigned char * ) V_8 ;
V_7 &= 1 << ( ( V_22 >> 21 ) & 7 ) ;
V_59 . V_60 = ( V_7 == 0 ) ;
for( V_6 = 0 ; V_6 < 16 ; V_6 ++ ) {
V_23 [ V_6 ] = F_16 ( V_22 + V_61 ) ;
F_16 ( V_22 + V_61 ) ;
}
V_25 = V_62 ;
V_26 = V_63 ;
if ( V_7 )
V_24 = 1 ;
else
F_17 ( 0x49 , V_22 + V_46 ) ;
V_20 = ( V_24 == 2 ) ? L_4 : L_5 ;
if ( ! V_2 -> V_12 ) {
F_19 ( L_6 ) ;
V_28 = - V_64 ;
goto V_32;
}
V_28 = F_20 ( V_2 -> V_12 , V_65 , 0 , V_20 , V_2 ) ;
if ( V_28 ) {
F_19 ( L_7 , V_2 -> V_12 , V_28 ) ;
goto V_32;
}
V_2 -> V_3 = V_22 ;
for ( V_6 = 0 ; V_6 < V_66 ; V_6 ++ )
V_2 -> V_67 [ V_6 ] = V_23 [ V_6 ] ;
F_19 ( L_8 , V_2 -> V_67 ) ;
F_19 ( L_9 ,
V_2 -> V_20 , V_20 , V_22 , V_2 -> V_12 ) ;
V_59 . V_20 = V_20 ;
V_59 . V_68 = V_25 ;
V_59 . V_26 = V_26 ;
V_59 . V_60 = ( V_24 == 2 ) ;
V_59 . V_69 = V_25 + V_70 ;
#ifdef F_21
V_59 . V_26 = V_59 . V_68 + F_21 ;
#endif
V_59 . V_71 = & V_72 ;
V_59 . V_73 = & V_74 ;
V_59 . V_75 = & V_76 ;
V_59 . V_77 = & V_78 ;
V_59 . V_79 = 0 ;
V_2 -> V_80 = & V_81 ;
F_22 ( V_2 , 0 ) ;
V_28 = F_23 ( V_2 ) ;
if ( V_28 )
goto V_82;
return 0 ;
V_82:
F_8 ( V_2 -> V_12 , V_2 ) ;
V_32:
F_9 ( V_22 , V_16 ) ;
return V_28 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
if ( V_40 > 1 )
F_19 ( V_83 L_10 , V_2 -> V_20 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static void V_72 ( struct V_1 * V_2 )
{
unsigned long V_84 = V_85 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_40 > 1 )
F_19 ( V_83 L_11 , V_85 ) ;
F_28 ( F_29 ( V_86 + V_87 ) , V_86 + V_87 ) ;
V_59 . V_88 = 0 ;
V_59 . V_89 = 0 ;
while ( ( F_16 ( V_86 + V_50 ) & V_90 ) == 0 )
if ( F_30 ( V_85 , V_84 + 2 * V_91 / 100 ) ) {
F_19 ( V_92 L_12 , V_2 -> V_20 ) ;
break;
}
F_17 ( V_90 , V_86 + V_50 ) ;
}
static void V_78 ( struct V_1 * V_2 , struct V_93 * V_94 , int V_95 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_59 . V_89 )
{
F_19 ( V_96 L_13
L_14 ,
V_2 -> V_20 , V_59 . V_89 , V_59 . V_97 ) ;
return;
}
V_59 . V_89 |= 0x01 ;
F_17 ( V_34 + V_38 + V_58 , V_86 + V_98 ) ;
F_17 ( sizeof( struct V_93 ) , V_86 + V_47 ) ;
F_17 ( 0 , V_86 + V_48 ) ;
F_17 ( 0 , V_86 + V_55 ) ;
F_17 ( V_95 , V_86 + V_56 ) ;
F_17 ( V_57 + V_58 , V_86 + V_98 ) ;
if ( V_59 . V_60 ) {
int V_99 ;
unsigned short * V_100 = ( unsigned short * ) V_94 ;
for ( V_99 = sizeof( struct V_93 ) >> 1 ; V_99 > 0 ; V_99 -- )
* V_100 ++ = F_31 ( V_86 + V_61 ) ;
} else
F_32 ( V_86 + V_61 , V_94 , sizeof( struct V_93 ) ) ;
F_17 ( V_101 , V_86 + V_50 ) ;
V_59 . V_89 &= ~ 0x01 ;
F_33 ( & V_94 -> V_102 ) ;
}
static void V_74 ( struct V_1 * V_2 , int V_102 , struct V_103 * V_104 , int V_105 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
#ifdef F_34
int V_106 = V_102 ;
#endif
char * V_107 = V_104 -> V_108 ;
if ( V_59 . V_89 )
{
F_19 ( V_96 L_15
L_14 ,
V_2 -> V_20 , V_59 . V_89 , V_59 . V_97 ) ;
return;
}
V_59 . V_89 |= 0x01 ;
F_17 ( V_34 + V_38 + V_58 , V_86 + V_98 ) ;
F_17 ( V_102 & 0xff , V_86 + V_47 ) ;
F_17 ( V_102 >> 8 , V_86 + V_48 ) ;
F_17 ( V_105 & 0xff , V_86 + V_55 ) ;
F_17 ( V_105 >> 8 , V_86 + V_56 ) ;
F_17 ( V_57 + V_58 , V_86 + V_98 ) ;
if ( V_59 . V_60 )
{
int V_99 ;
unsigned short * V_100 = ( unsigned short * ) V_107 ;
for ( V_99 = V_102 >> 1 ; V_99 > 0 ; V_99 -- )
* V_100 ++ = F_31 ( V_86 + V_61 ) ;
if ( V_102 & 0x01 )
{
V_107 [ V_102 - 1 ] = F_29 ( V_86 + V_61 ) ;
#ifdef F_34
V_106 ++ ;
#endif
}
} else {
F_32 ( V_86 + V_61 , V_107 , V_102 ) ;
}
#ifdef F_34
if ( V_40 > 1 )
{
int V_109 , V_110 = 20 ;
do {
int V_111 = F_16 ( V_86 + V_56 ) ;
int V_112 = F_16 ( V_86 + V_55 ) ;
V_109 = ( V_111 << 8 ) + V_112 ;
if ( ( ( V_105 + V_106 ) & 0xff ) == V_112 )
break;
} while ( -- V_110 > 0 );
if ( V_110 <= 0 )
F_19 ( V_92 L_16
L_17 ,
V_2 -> V_20 , V_105 + V_106 , V_109 ) ;
}
#endif
F_17 ( V_101 , V_86 + V_50 ) ;
V_59 . V_89 &= ~ 0x01 ;
}
static void V_76 ( struct V_1 * V_2 , int V_102 ,
const unsigned char * V_107 , const int V_25 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_113 ;
#ifdef F_34
int V_114 = 0 ;
#endif
if ( V_59 . V_60 && ( V_102 & 0x01 ) )
V_102 ++ ;
if ( V_59 . V_89 )
{
F_19 ( V_96 L_18
L_19 ,
V_2 -> V_20 , V_59 . V_89 , V_59 . V_97 ) ;
return;
}
V_59 . V_89 |= 0x01 ;
F_17 ( V_38 + V_58 + V_34 , V_86 + V_98 ) ;
#ifdef F_34
V_115:
#endif
#ifdef F_35
F_17 ( 0x42 , V_86 + V_47 ) ;
F_17 ( 0x00 , V_86 + V_48 ) ;
F_17 ( 0x42 , V_86 + V_55 ) ;
F_17 ( 0x00 , V_86 + V_56 ) ;
F_17 ( V_57 + V_58 , V_86 + V_98 ) ;
F_36 ( 6 ) ;
#endif
F_17 ( V_101 , V_86 + V_50 ) ;
F_17 ( V_102 & 0xff , V_86 + V_47 ) ;
F_17 ( V_102 >> 8 , V_86 + V_48 ) ;
F_17 ( 0x00 , V_86 + V_55 ) ;
F_17 ( V_25 , V_86 + V_56 ) ;
F_17 ( V_116 + V_58 , V_86 + V_98 ) ;
if ( V_59 . V_60 ) {
int V_99 ;
unsigned short * V_100 = ( unsigned short * ) V_107 ;
for ( V_99 = V_102 >> 1 ; V_99 > 0 ; V_99 -- )
F_37 ( * V_100 ++ , V_86 + V_61 ) ;
} else {
F_38 ( V_86 + V_61 , V_107 , V_102 ) ;
}
V_113 = V_85 ;
#ifdef F_34
if ( V_40 > 1 )
{
int V_109 , V_110 = 20 ;
do {
int V_111 = F_16 ( V_86 + V_56 ) ;
int V_112 = F_16 ( V_86 + V_55 ) ;
V_109 = ( V_111 << 8 ) + V_112 ;
if ( ( V_25 << 8 ) + V_102 == V_109 )
break;
} while ( -- V_110 > 0 );
if ( V_110 <= 0 )
{
F_19 ( V_92 L_20
L_17 ,
V_2 -> V_20 , ( V_25 << 8 ) + V_102 , V_109 ) ;
if ( V_114 ++ == 0 )
goto V_115;
}
}
#endif
while ( ( F_16 ( V_86 + V_50 ) & V_101 ) == 0 )
if ( F_30 ( V_85 , V_113 + 2 * V_91 / 100 ) ) {
F_19 ( V_92 L_21 , V_2 -> V_20 ) ;
V_72 ( V_2 ) ;
F_22 ( V_2 , 1 ) ;
break;
}
F_17 ( V_101 , V_86 + V_50 ) ;
V_59 . V_89 &= ~ 0x01 ;
}
int F_39 ( void )
{
int V_117 , V_118 = 0 ;
int V_18 ;
for ( V_117 = 0 ; V_117 < V_119 ; V_117 ++ ) {
struct V_1 * V_2 = F_11 ( 0 ) ;
if ( ! V_2 )
break;
if ( V_120 [ V_117 ] ) {
V_2 -> V_12 = V_12 [ V_117 ] ;
V_2 -> V_121 = V_122 [ V_117 ] ;
V_2 -> V_3 = V_120 [ V_117 ] ;
} else {
V_2 -> V_3 = V_11 [ V_117 ] ;
V_2 -> V_12 = V_13 [ V_117 ] ;
}
V_18 = F_1 ( V_2 , V_2 -> V_3 ) ;
if ( ! V_18 ) {
if ( F_5 ( V_2 ) == 0 ) {
V_123 [ V_118 ++ ] = V_2 ;
continue;
}
}
F_14 ( V_2 ) ;
if ( V_118 )
break;
if ( V_120 [ V_117 ] != 0 )
F_19 ( V_92 L_22 , V_2 -> V_3 ) ;
else
F_19 ( V_124 L_23 ) ;
return - V_15 ;
}
if ( V_118 )
return 0 ;
return - V_14 ;
}
void F_40 ( void )
{
int V_117 ;
for ( V_117 = 0 ; V_117 < V_119 ; V_117 ++ ) {
struct V_1 * V_2 = V_123 [ V_117 ] ;
if ( V_2 ) {
F_41 ( V_2 ) ;
F_7 ( V_2 ) ;
F_14 ( V_2 ) ;
}
}
}
