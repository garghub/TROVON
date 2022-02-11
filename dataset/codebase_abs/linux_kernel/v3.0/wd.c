static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 ;
int V_6 = V_2 -> V_6 ;
int V_7 = V_2 -> V_7 ;
int V_8 = V_2 -> V_8 ;
int V_9 = V_2 -> V_9 ;
if ( V_6 > 0x1ff ) {
V_5 = F_2 ( V_6 , V_10 , L_1 ) ;
if ( V_5 == NULL )
return - V_11 ;
V_3 = F_3 ( V_2 , V_6 ) ;
if ( V_3 != 0 )
F_4 ( V_6 , V_10 ) ;
else
V_5 -> V_12 = V_2 -> V_12 ;
return V_3 ;
}
else if ( V_6 != 0 )
return - V_13 ;
for ( V_3 = 0 ; V_14 [ V_3 ] ; V_3 ++ ) {
int V_15 = V_14 [ V_3 ] ;
V_5 = F_2 ( V_15 , V_10 , L_1 ) ;
if ( V_5 == NULL )
continue;
if ( F_3 ( V_2 , V_15 ) == 0 ) {
V_5 -> V_12 = V_2 -> V_12 ;
return 0 ;
}
F_4 ( V_15 , V_10 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_9 = V_9 ;
}
return - V_16 ;
}
struct V_1 * T_1 F_5 ( int V_17 )
{
struct V_1 * V_2 = F_6 () ;
int V_18 ;
if ( ! V_2 )
return F_7 ( - V_19 ) ;
sprintf ( V_2 -> V_12 , L_2 , V_17 ) ;
F_8 ( V_2 ) ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 )
goto V_20;
return V_2 ;
V_20:
F_9 ( V_2 ) ;
return F_7 ( V_18 ) ;
}
static int T_1 F_3 ( struct V_1 * V_2 , int V_15 )
{
int V_3 ;
int V_18 ;
int V_21 = 0 ;
int V_22 = 0 ;
int V_23 = 0 ;
const char * V_24 ;
static unsigned V_25 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
V_21 += F_10 ( V_15 + 8 + V_3 ) ;
if ( F_10 ( V_15 + 8 ) == 0xff
|| F_10 ( V_15 + 9 ) == 0xff
|| ( V_21 & 0xff ) != 0xFF )
return - V_16 ;
if ( ( V_2 -> V_8 % 0x2000 ) || ( V_2 -> V_9 % 0x2000 ) ) {
F_11 ( V_26 L_3 ) ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
}
if ( V_27 && V_25 ++ == 0 )
F_11 ( V_28 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
V_2 -> V_29 [ V_3 ] = F_10 ( V_15 + 8 + V_3 ) ;
F_11 ( L_4 ,
V_2 -> V_12 , V_15 , V_2 -> V_29 ) ;
if ( F_10 ( V_15 + 0 ) == 'P' && F_10 ( V_15 + 1 ) == 'D' ) {
unsigned char V_30 = F_10 ( V_15 + 5 ) ;
switch ( F_10 ( V_15 + 2 ) ) {
case 0x03 : V_23 = 0 ; V_24 = L_5 ; break;
case 0x05 : V_23 = 0 ; V_24 = L_6 ; break;
case 0x0a : V_23 = 1 ; V_24 = L_7 ; break;
default: V_23 = 0 ; V_24 = L_8 ; break;
}
V_2 -> V_8 = ( ( V_30 & 0x1c ) + 0xc0 ) << 12 ;
V_2 -> V_7 = ( V_30 & 0xe0 ) == 0xe0 ? 10 : ( V_30 >> 5 ) + 1 ;
} else {
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
if ( F_10 ( V_15 + V_3 ) != F_10 ( V_15 + 8 + V_3 ) )
break;
if ( V_3 >= 6 ) {
V_22 = 1 ;
V_24 = L_9 ;
V_23 = 0 ;
} else {
int V_31 = F_10 ( V_15 + 1 ) ;
F_12 ( V_31 ^ 0x01 , V_15 + 1 ) ;
if ( ( ( F_10 ( V_15 + 1 ) & 0x01 ) == 0x01 )
&& ( V_31 & 0x01 ) == 0x01 ) {
int V_32 = F_10 ( V_15 + V_33 ) ;
F_12 ( V_34 | ( V_32 & 0x1f ) , V_15 + V_33 ) ;
F_12 ( V_31 , V_15 + 1 ) ;
V_24 = L_10 ;
V_23 = 1 ;
} else {
V_24 = L_11 ;
V_23 = 0 ;
}
F_12 ( V_31 , V_15 + 1 ) ;
}
#ifndef F_13
if ( ! V_22 && ( F_10 ( V_15 + 1 ) & 0x01 ) != ( V_23 & 0x01 ) )
F_11 ( L_12 ,
V_23 ? 16 : 8 , ( F_10 ( V_15 + 1 ) & 0x01 ) ? 16 : 8 ) ;
#endif
}
#if F_14 ( V_35 ) && V_35 > 0x80000
V_2 -> V_8 = V_35 ;
#else
if ( V_2 -> V_8 == 0 ) {
int V_36 = F_10 ( V_15 ) ;
if ( V_36 == 0xff || V_36 == 0 ) {
V_2 -> V_8 = 0xd0000 ;
F_11 ( L_13 , V_2 -> V_8 ) ;
} else {
int V_37 = F_10 ( V_15 + V_33 ) & 0x1f ;
if ( V_37 == 0x1f || V_23 == 0 )
V_37 = 0x01 ;
V_2 -> V_8 = ( ( V_36 & 0x3f ) << 13 ) + ( V_37 << 19 ) ;
}
}
#endif
V_2 -> V_6 = V_15 + V_38 ;
if ( V_2 -> V_7 < 2 ) {
static const int V_39 [] = { 9 , 3 , 5 , 7 , 10 , 11 , 15 , 4 } ;
int V_40 = F_10 ( V_15 + 1 ) ;
int V_41 = F_10 ( V_15 + 4 ) ;
if ( V_22 || V_40 == 0xff ) {
short V_42 = V_15 + V_38 ;
unsigned long V_43 ;
F_15 ( V_44 + V_45 , V_42 ) ;
F_12 ( 0x00 , V_42 + V_46 ) ;
V_43 = F_16 () ;
F_15 ( 0xff , V_42 + V_46 ) ;
F_15 ( 0x00 , V_42 + V_47 ) ;
F_15 ( 0x00 , V_42 + V_48 ) ;
F_12 ( V_49 + V_50 , V_42 ) ;
F_17 ( 20 ) ;
V_2 -> V_7 = F_18 ( V_43 ) ;
F_15 ( 0x00 , V_42 + V_46 ) ;
if ( V_27 > 2 )
F_11 ( L_14 , V_2 -> V_7 ) ;
if ( V_2 -> V_7 < 2 )
V_2 -> V_7 = V_23 ? 10 : 5 ;
} else
V_2 -> V_7 = V_39 [ ( ( V_41 >> 5 ) & 0x03 ) + ( V_40 & 0x04 ) ] ;
} else if ( V_2 -> V_7 == 2 )
V_2 -> V_7 = 9 ;
V_3 = F_19 ( V_2 -> V_7 , V_51 , 0 , V_52 , V_2 ) ;
if ( V_3 ) {
F_11 ( L_15 , V_2 -> V_7 ) ;
return V_3 ;
}
V_53 . V_12 = V_24 ;
V_53 . V_23 = V_23 ;
V_53 . V_54 = V_55 ;
V_53 . V_56 = V_55 + V_57 ;
if ( V_2 -> V_9 != 0 ) {
V_53 . V_58 = ( V_2 -> V_9 - V_2 -> V_8 ) / 256 ;
V_53 . V_59 = V_2 -> V_9 - V_2 -> V_8 ;
} else {
V_53 . V_58 = V_23 ? V_60 : V_61 ;
V_2 -> V_9 = V_2 -> V_8 + ( V_53 . V_58 - V_55 ) * 256 ;
V_53 . V_59 = ( V_53 . V_58 - V_55 ) * 256 ;
}
V_53 . V_62 = F_20 ( V_2 -> V_8 , V_53 . V_59 ) ;
if ( ! V_53 . V_62 ) {
F_21 ( V_2 -> V_7 , V_2 ) ;
return - V_19 ;
}
F_11 ( L_16 ,
V_24 , V_2 -> V_7 , V_2 -> V_8 , V_2 -> V_9 - 1 ) ;
V_53 . V_63 = V_64 ;
V_53 . V_65 = V_66 ;
V_53 . V_67 = V_68 ;
V_53 . V_69 = V_70 ;
V_2 -> V_71 = & V_72 ;
F_22 ( V_2 , 0 ) ;
#if 1
if ( F_10 ( V_15 + 14 ) & 0x20 )
F_12 ( F_10 ( V_15 + 4 ) | 0x80 , V_15 + 4 ) ;
#endif
V_18 = F_23 ( V_2 ) ;
if ( V_18 ) {
F_21 ( V_2 -> V_7 , V_2 ) ;
F_24 ( V_53 . V_62 ) ;
}
return V_18 ;
}
static int
F_25 ( struct V_1 * V_2 )
{
int V_15 = V_2 -> V_6 - V_38 ;
V_53 . V_36 = ( ( V_2 -> V_8 >> 13 ) & 0x3f ) | V_73 ;
V_53 . V_30 = ( ( V_2 -> V_8 >> 19 ) & 0x1f ) | V_34 ;
if ( V_53 . V_23 )
F_12 ( V_53 . V_30 , V_15 + V_33 ) ;
F_12 ( V_53 . V_36 , V_15 ) ;
return F_26 ( V_2 ) ;
}
static void
V_64 ( struct V_1 * V_2 )
{
int V_74 = V_2 -> V_6 - V_38 ;
F_12 ( V_75 , V_74 ) ;
if ( V_27 > 1 ) F_11 ( L_17 , V_76 ) ;
V_53 . V_77 = 0 ;
F_12 ( ( ( ( V_2 -> V_8 >> 13 ) & 0x3f ) | V_73 ) , V_74 ) ;
if ( V_53 . V_23 )
F_12 ( V_34 | ( ( V_2 -> V_8 >> 19 ) & 0x1f ) , V_74 + V_33 ) ;
if ( V_27 > 1 ) F_11 ( L_18 ) ;
}
static void
V_70 ( struct V_1 * V_2 , struct V_78 * V_79 , int V_80 )
{
int V_81 = V_2 -> V_6 - V_38 ;
void T_2 * V_82 = V_53 . V_62 + ( ( V_80 - V_55 ) << 8 ) ;
if ( V_53 . V_23 )
F_12 ( V_83 | V_53 . V_30 , V_81 + V_33 ) ;
#ifdef F_27
F_28 ( V_79 , V_82 , sizeof( struct V_78 ) ) ;
V_79 -> V_84 = F_29 ( V_79 -> V_84 ) ;
#else
( ( unsigned int * ) V_79 ) [ 0 ] = F_30 ( V_82 ) ;
#endif
}
static void
V_66 ( struct V_1 * V_2 , int V_84 , struct V_85 * V_86 , int V_87 )
{
int V_81 = V_2 -> V_6 - V_38 ;
unsigned long V_88 = V_87 - ( V_55 << 8 ) ;
void T_2 * V_89 = V_53 . V_62 + V_88 ;
if ( V_88 + V_84 > V_53 . V_59 ) {
int V_90 = V_53 . V_59 - V_88 ;
F_28 ( V_86 -> V_91 , V_89 , V_90 ) ;
V_84 -= V_90 ;
F_28 ( V_86 -> V_91 + V_90 , V_53 . V_62 + V_57 * 256 , V_84 ) ;
} else {
F_28 ( V_86 -> V_91 , V_89 , V_84 ) ;
}
if ( V_53 . V_23 )
F_12 ( V_53 . V_30 , V_81 + V_33 ) ;
}
static void
V_68 ( struct V_1 * V_2 , int V_84 , const unsigned char * V_92 ,
int V_93 )
{
int V_81 = V_2 -> V_6 - V_38 ;
void T_2 * V_94 = V_53 . V_62 + ( ( V_93 - V_55 ) << 8 ) ;
if ( V_53 . V_23 ) {
F_12 ( V_83 | V_53 . V_30 , V_81 + V_33 ) ;
F_31 ( V_94 , V_92 , V_84 ) ;
F_12 ( V_53 . V_30 , V_81 + V_33 ) ;
} else
F_31 ( V_94 , V_92 , V_84 ) ;
}
static int
F_32 ( struct V_1 * V_2 )
{
int V_81 = V_2 -> V_6 - V_38 ;
if ( V_27 > 1 )
F_11 ( L_19 , V_2 -> V_12 ) ;
F_33 ( V_2 ) ;
if ( V_53 . V_23 )
F_12 ( V_53 . V_30 , V_81 + V_33 ) ;
F_12 ( V_53 . V_36 & ~ V_73 , V_81 ) ;
return 0 ;
}
int T_1 F_34 ( void )
{
struct V_1 * V_2 ;
int V_95 , V_96 = 0 ;
for ( V_95 = 0 ; V_95 < V_97 ; V_95 ++ ) {
if ( V_98 [ V_95 ] == 0 ) {
if ( V_95 != 0 ) break;
F_11 ( V_99 L_20 ) ;
}
V_2 = F_6 () ;
if ( ! V_2 )
break;
V_2 -> V_7 = V_7 [ V_95 ] ;
V_2 -> V_6 = V_98 [ V_95 ] ;
V_2 -> V_8 = V_62 [ V_95 ] ;
V_2 -> V_9 = V_9 [ V_95 ] ;
if ( F_1 ( V_2 ) == 0 ) {
V_100 [ V_96 ++ ] = V_2 ;
continue;
}
F_9 ( V_2 ) ;
F_11 ( V_26 L_21 , V_98 [ V_95 ] ) ;
break;
}
if ( V_96 )
return 0 ;
return - V_13 ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_7 , V_2 ) ;
F_4 ( V_2 -> V_6 - V_38 , V_10 ) ;
F_24 ( V_53 . V_62 ) ;
}
void T_3
F_36 ( void )
{
int V_95 ;
for ( V_95 = 0 ; V_95 < V_97 ; V_95 ++ ) {
struct V_1 * V_2 = V_100 [ V_95 ] ;
if ( V_2 ) {
F_37 ( V_2 ) ;
F_35 ( V_2 ) ;
F_9 ( V_2 ) ;
}
}
}
