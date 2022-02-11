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
struct V_26 * V_27 = F_10 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
V_21 += F_11 ( V_15 + 8 + V_3 ) ;
if ( F_11 ( V_15 + 8 ) == 0xff
|| F_11 ( V_15 + 9 ) == 0xff
|| ( V_21 & 0xff ) != 0xFF )
return - V_16 ;
if ( ( V_2 -> V_8 % 0x2000 ) || ( V_2 -> V_9 % 0x2000 ) ) {
F_12 ( V_2 ,
L_3 ) ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
}
if ( ( V_28 & V_29 ) && ( V_25 ++ == 0 ) )
F_13 ( V_2 , V_30 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
V_2 -> V_31 [ V_3 ] = F_11 ( V_15 + 8 + V_3 ) ;
F_13 ( V_2 , L_4 , V_15 , V_2 -> V_31 ) ;
if ( F_11 ( V_15 + 0 ) == 'P' && F_11 ( V_15 + 1 ) == 'D' ) {
unsigned char V_32 = F_11 ( V_15 + 5 ) ;
switch ( F_11 ( V_15 + 2 ) ) {
case 0x03 : V_23 = 0 ; V_24 = L_5 ; break;
case 0x05 : V_23 = 0 ; V_24 = L_6 ; break;
case 0x0a : V_23 = 1 ; V_24 = L_7 ; break;
default: V_23 = 0 ; V_24 = L_8 ; break;
}
V_2 -> V_8 = ( ( V_32 & 0x1c ) + 0xc0 ) << 12 ;
V_2 -> V_7 = ( V_32 & 0xe0 ) == 0xe0 ? 10 : ( V_32 >> 5 ) + 1 ;
} else {
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
if ( F_11 ( V_15 + V_3 ) != F_11 ( V_15 + 8 + V_3 ) )
break;
if ( V_3 >= 6 ) {
V_22 = 1 ;
V_24 = L_9 ;
V_23 = 0 ;
} else {
int V_33 = F_11 ( V_15 + 1 ) ;
F_14 ( V_33 ^ 0x01 , V_15 + 1 ) ;
if ( ( ( F_11 ( V_15 + 1 ) & 0x01 ) == 0x01 )
&& ( V_33 & 0x01 ) == 0x01 ) {
int V_34 = F_11 ( V_15 + V_35 ) ;
F_14 ( V_36 | ( V_34 & 0x1f ) , V_15 + V_35 ) ;
F_14 ( V_33 , V_15 + 1 ) ;
V_24 = L_10 ;
V_23 = 1 ;
} else {
V_24 = L_11 ;
V_23 = 0 ;
}
F_14 ( V_33 , V_15 + 1 ) ;
}
#ifndef F_15
if ( ! V_22 && ( F_11 ( V_15 + 1 ) & 0x01 ) != ( V_23 & 0x01 ) )
F_16 ( L_12 ,
V_23 ? 16 : 8 ,
( F_11 ( V_15 + 1 ) & 0x01 ) ? 16 : 8 ) ;
#endif
}
#if F_17 ( V_37 ) && V_37 > 0x80000
V_2 -> V_8 = V_37 ;
#else
if ( V_2 -> V_8 == 0 ) {
int V_38 = F_11 ( V_15 ) ;
if ( V_38 == 0xff || V_38 == 0 ) {
V_2 -> V_8 = 0xd0000 ;
F_16 ( L_13 , V_2 -> V_8 ) ;
} else {
int V_39 = F_11 ( V_15 + V_35 ) & 0x1f ;
if ( V_39 == 0x1f || V_23 == 0 )
V_39 = 0x01 ;
V_2 -> V_8 = ( ( V_38 & 0x3f ) << 13 ) + ( V_39 << 19 ) ;
}
}
#endif
V_2 -> V_6 = V_15 + V_40 ;
if ( V_2 -> V_7 < 2 ) {
static const int V_41 [] = { 9 , 3 , 5 , 7 , 10 , 11 , 15 , 4 } ;
int V_42 = F_11 ( V_15 + 1 ) ;
int V_43 = F_11 ( V_15 + 4 ) ;
if ( V_22 || V_42 == 0xff ) {
short V_44 = V_15 + V_40 ;
unsigned long V_45 ;
F_18 ( V_46 + V_47 , V_44 ) ;
F_14 ( 0x00 , V_44 + V_48 ) ;
V_45 = F_19 () ;
F_18 ( 0xff , V_44 + V_48 ) ;
F_18 ( 0x00 , V_44 + V_49 ) ;
F_18 ( 0x00 , V_44 + V_50 ) ;
F_14 ( V_51 + V_52 , V_44 ) ;
F_20 ( 20 ) ;
V_2 -> V_7 = F_21 ( V_45 ) ;
F_18 ( 0x00 , V_44 + V_48 ) ;
if ( F_22 ( V_27 ) )
F_16 ( L_14 , V_2 -> V_7 ) ;
if ( V_2 -> V_7 < 2 )
V_2 -> V_7 = V_23 ? 10 : 5 ;
} else
V_2 -> V_7 = V_41 [ ( ( V_43 >> 5 ) & 0x03 ) + ( V_42 & 0x04 ) ] ;
} else if ( V_2 -> V_7 == 2 )
V_2 -> V_7 = 9 ;
V_3 = F_23 ( V_2 -> V_7 , V_53 , 0 , V_54 , V_2 ) ;
if ( V_3 ) {
F_16 ( L_15 , V_2 -> V_7 ) ;
return V_3 ;
}
V_55 . V_12 = V_24 ;
V_55 . V_23 = V_23 ;
V_55 . V_56 = V_57 ;
V_55 . V_58 = V_57 + V_59 ;
if ( V_2 -> V_9 != 0 ) {
V_55 . V_60 = ( V_2 -> V_9 - V_2 -> V_8 ) / 256 ;
V_55 . V_61 = V_2 -> V_9 - V_2 -> V_8 ;
} else {
V_55 . V_60 = V_23 ? V_62 : V_63 ;
V_2 -> V_9 = V_2 -> V_8 + ( V_55 . V_60 - V_57 ) * 256 ;
V_55 . V_61 = ( V_55 . V_60 - V_57 ) * 256 ;
}
V_55 . V_64 = F_24 ( V_2 -> V_8 , V_55 . V_61 ) ;
if ( ! V_55 . V_64 ) {
F_25 ( V_2 -> V_7 , V_2 ) ;
return - V_19 ;
}
F_16 ( L_16 ,
V_24 , V_2 -> V_7 , V_2 -> V_8 , V_2 -> V_9 - 1 ) ;
V_55 . V_65 = V_66 ;
V_55 . V_67 = V_68 ;
V_55 . V_69 = V_70 ;
V_55 . V_71 = V_72 ;
V_2 -> V_73 = & V_74 ;
F_26 ( V_2 , 0 ) ;
V_27 -> V_75 = V_28 ;
#if 1
if ( F_11 ( V_15 + 14 ) & 0x20 )
F_14 ( F_11 ( V_15 + 4 ) | 0x80 , V_15 + 4 ) ;
#endif
V_18 = F_27 ( V_2 ) ;
if ( V_18 ) {
F_25 ( V_2 -> V_7 , V_2 ) ;
F_28 ( V_55 . V_64 ) ;
}
return V_18 ;
}
static int
F_29 ( struct V_1 * V_2 )
{
int V_15 = V_2 -> V_6 - V_40 ;
V_55 . V_38 = ( ( V_2 -> V_8 >> 13 ) & 0x3f ) | V_76 ;
V_55 . V_32 = ( ( V_2 -> V_8 >> 19 ) & 0x1f ) | V_36 ;
if ( V_55 . V_23 )
F_14 ( V_55 . V_32 , V_15 + V_35 ) ;
F_14 ( V_55 . V_38 , V_15 ) ;
return F_30 ( V_2 ) ;
}
static void
V_66 ( struct V_1 * V_2 )
{
int V_77 = V_2 -> V_6 - V_40 ;
struct V_26 * V_27 = F_10 ( V_2 ) ;
F_14 ( V_78 , V_77 ) ;
F_31 ( V_27 , V_79 , V_2 , L_17 ,
V_80 ) ;
V_55 . V_81 = 0 ;
F_14 ( ( ( ( V_2 -> V_8 >> 13 ) & 0x3f ) | V_76 ) , V_77 ) ;
if ( V_55 . V_23 )
F_14 ( V_36 | ( ( V_2 -> V_8 >> 19 ) & 0x1f ) , V_77 + V_35 ) ;
F_31 ( V_27 , V_79 , V_2 , L_18 ) ;
}
static void
V_72 ( struct V_1 * V_2 , struct V_82 * V_83 , int V_84 )
{
int V_85 = V_2 -> V_6 - V_40 ;
void T_2 * V_86 = V_55 . V_64 + ( ( V_84 - V_57 ) << 8 ) ;
if ( V_55 . V_23 )
F_14 ( V_87 | V_55 . V_32 , V_85 + V_35 ) ;
#ifdef F_32
F_33 ( V_83 , V_86 , sizeof( struct V_82 ) ) ;
V_83 -> V_88 = F_34 ( V_83 -> V_88 ) ;
#else
( ( unsigned int * ) V_83 ) [ 0 ] = F_35 ( V_86 ) ;
#endif
}
static void
V_68 ( struct V_1 * V_2 , int V_88 , struct V_89 * V_90 , int V_91 )
{
int V_85 = V_2 -> V_6 - V_40 ;
unsigned long V_92 = V_91 - ( V_57 << 8 ) ;
void T_2 * V_93 = V_55 . V_64 + V_92 ;
if ( V_92 + V_88 > V_55 . V_61 ) {
int V_94 = V_55 . V_61 - V_92 ;
F_33 ( V_90 -> V_95 , V_93 , V_94 ) ;
V_88 -= V_94 ;
F_33 ( V_90 -> V_95 + V_94 , V_55 . V_64 + V_59 * 256 , V_88 ) ;
} else {
F_33 ( V_90 -> V_95 , V_93 , V_88 ) ;
}
if ( V_55 . V_23 )
F_14 ( V_55 . V_32 , V_85 + V_35 ) ;
}
static void
V_70 ( struct V_1 * V_2 , int V_88 , const unsigned char * V_96 ,
int V_97 )
{
int V_85 = V_2 -> V_6 - V_40 ;
void T_2 * V_98 = V_55 . V_64 + ( ( V_97 - V_57 ) << 8 ) ;
if ( V_55 . V_23 ) {
F_14 ( V_87 | V_55 . V_32 , V_85 + V_35 ) ;
F_36 ( V_98 , V_96 , V_88 ) ;
F_14 ( V_55 . V_32 , V_85 + V_35 ) ;
} else
F_36 ( V_98 , V_96 , V_88 ) ;
}
static int
F_37 ( struct V_1 * V_2 )
{
int V_85 = V_2 -> V_6 - V_40 ;
struct V_26 * V_27 = F_10 ( V_2 ) ;
F_31 ( V_27 , V_99 , V_2 , L_19 ) ;
F_38 ( V_2 ) ;
if ( V_55 . V_23 )
F_14 ( V_55 . V_32 , V_85 + V_35 ) ;
F_14 ( V_55 . V_38 & ~ V_76 , V_85 ) ;
return 0 ;
}
int T_1 F_39 ( void )
{
struct V_1 * V_2 ;
int V_100 , V_101 = 0 ;
for ( V_100 = 0 ; V_100 < V_102 ; V_100 ++ ) {
if ( V_103 [ V_100 ] == 0 ) {
if ( V_100 != 0 ) break;
F_40 ( V_104 L_20 ) ;
}
V_2 = F_6 () ;
if ( ! V_2 )
break;
V_2 -> V_7 = V_7 [ V_100 ] ;
V_2 -> V_6 = V_103 [ V_100 ] ;
V_2 -> V_8 = V_64 [ V_100 ] ;
V_2 -> V_9 = V_9 [ V_100 ] ;
if ( F_1 ( V_2 ) == 0 ) {
V_105 [ V_101 ++ ] = V_2 ;
continue;
}
F_9 ( V_2 ) ;
F_40 ( V_106 L_21 , V_103 [ V_100 ] ) ;
break;
}
if ( V_101 )
return 0 ;
return - V_13 ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_7 , V_2 ) ;
F_4 ( V_2 -> V_6 - V_40 , V_10 ) ;
F_28 ( V_55 . V_64 ) ;
}
void T_3
F_42 ( void )
{
int V_100 ;
for ( V_100 = 0 ; V_100 < V_102 ; V_100 ++ ) {
struct V_1 * V_2 = V_105 [ V_100 ] ;
if ( V_2 ) {
F_43 ( V_2 ) ;
F_41 ( V_2 ) ;
F_9 ( V_2 ) ;
}
}
}
