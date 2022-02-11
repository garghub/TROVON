static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_3 , V_2 ) ;
F_4 ( V_2 -> V_3 ) ;
}
static int T_1 F_5 ( struct V_1 * V_2 )
{
int V_4 ;
int V_5 = V_2 -> V_5 ;
int V_3 = V_2 -> V_3 ;
if ( V_5 > 0x1ff )
return F_6 ( V_2 , V_5 ) ;
else if ( V_5 != 0 )
return - V_6 ;
#ifdef F_7
if ( F_8 () && ( F_9 ( V_2 ) == 0 ) )
return 0 ;
#endif
for ( V_4 = 0 ; V_7 [ V_4 ] ; V_4 ++ ) {
V_2 -> V_3 = V_3 ;
if ( F_6 ( V_2 , V_7 [ V_4 ] ) == 0 )
return 0 ;
}
return - V_8 ;
}
struct V_1 * T_1 F_10 ( int V_9 )
{
struct V_1 * V_2 = F_11 () ;
int V_10 ;
if ( ! V_2 )
return F_12 ( - V_11 ) ;
sprintf ( V_2 -> V_12 , L_1 , V_9 ) ;
F_13 ( V_2 ) ;
V_10 = F_5 ( V_2 ) ;
if ( V_10 )
goto V_13;
return V_2 ;
V_13:
F_14 ( V_2 ) ;
return F_12 ( V_10 ) ;
}
static int T_1 F_6 ( struct V_1 * V_2 , int V_14 )
{
int V_4 , V_15 ;
int V_16 = 0 ;
const char * V_17 ;
unsigned char V_18 = 0 ;
static unsigned V_19 ;
unsigned char V_20 , V_21 , V_22 , V_23 ;
unsigned char V_24 = F_15 ( V_14 + 7 ) ;
unsigned char V_25 = F_15 ( V_14 + 4 ) & 0x7f ;
if ( ! F_16 ( V_14 , V_26 , V_27 ) )
return - V_28 ;
if ( ( V_24 & 0xF0 ) != 0x20
&& ( V_24 & 0xF0 ) != 0x40 ) {
V_15 = - V_8 ;
goto V_13;
}
F_17 ( V_25 , V_14 + 4 ) ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ )
V_16 += F_15 ( V_14 + 8 + V_4 ) ;
if ( ( V_16 & 0xff ) != 0xFF ) {
V_15 = - V_8 ;
goto V_13;
}
if ( V_29 && V_19 ++ == 0 )
F_18 ( V_30 ) ;
V_17 = ( V_24 & 0xF0 ) == 0x20 ? L_2 : L_3 ;
for ( V_4 = 0 ; V_4 < 6 ; V_4 ++ )
V_2 -> V_31 [ V_4 ] = F_15 ( V_14 + 8 + V_4 ) ;
F_18 ( L_4 , V_2 -> V_12 , V_17 ,
V_14 , V_2 -> V_31 ) ;
F_17 ( 0x80 | V_25 , V_14 + 4 ) ;
F_17 ( 0x80 | F_15 ( V_14 + 0x0c ) , V_14 + 0x0c ) ;
V_23 = F_15 ( V_14 + 0x8 ) ;
V_22 = F_15 ( V_14 + 0xb ) ;
V_21 = F_15 ( V_14 + 0xd ) ;
F_17 ( V_25 , V_14 + 4 ) ;
if ( V_2 -> V_3 < 2 ) {
unsigned char V_32 [] = { 0 , 9 , 3 , 5 , 7 , 10 , 11 , 15 } ;
int V_3 ;
V_3 = V_32 [ ( ( V_21 & 0x40 ) >> 4 ) + ( ( V_21 & 0x0c ) >> 2 ) ] ;
if ( V_3 == 0 ) {
F_18 ( L_5 ) ;
V_15 = - V_33 ;
goto V_13;
}
V_2 -> V_3 = V_3 ;
V_18 = 1 ;
}
V_2 -> V_5 = V_14 + V_34 ;
{
static const int V_35 [ 4 ] = {
0x0C0000 , 0x0E0000 , 0xFC0000 , 0xFE0000
} ;
static const short V_36 [ 4 ] = {
0x20 , 0x40 , 0x80 , 0xff
} ;
V_2 -> V_37 = ( ( V_22 & 0x0f ) << 13 ) + V_35 [ ( V_22 >> 6 ) & 3 ] ;
V_20 = V_36 [ ( V_22 >> 4 ) & 3 ] ;
}
V_38 . V_12 = V_17 ;
V_38 . V_39 = 1 ;
V_38 . V_40 = V_41 ;
V_38 . V_42 = V_41 + V_43 ;
V_38 . V_44 = V_20 ;
V_38 . V_45 = F_19 ( V_2 -> V_37 , ( V_38 . V_44 - V_41 ) * 256 ) ;
if ( ! V_38 . V_45 ) {
F_18 ( L_6 ) ;
V_15 = - V_11 ;
goto V_13;
}
V_2 -> V_46 = V_2 -> V_37 + ( V_38 . V_44 - V_41 ) * 256 ;
if ( V_23 ) {
F_18 ( L_7 ,
V_18 ? L_8 : L_9 , V_2 -> V_3 ) ;
V_38 . V_47 = & V_48 ;
V_38 . V_49 = & V_50 ;
V_38 . V_51 = & V_52 ;
} else {
F_18 ( L_10 , V_18 ? L_11 : L_9 ,
V_2 -> V_3 , V_2 -> V_37 , V_2 -> V_46 - 1 ) ;
V_38 . V_47 = & V_53 ;
V_38 . V_49 = & V_54 ;
V_38 . V_51 = & V_55 ;
}
V_38 . V_56 = & V_57 ;
V_2 -> V_58 = & V_59 ;
F_20 ( V_2 , 0 ) ;
V_15 = F_21 ( V_2 ) ;
if ( V_15 )
goto V_13;
return 0 ;
V_13:
F_22 ( V_14 , V_26 ) ;
return V_15 ;
}
static int T_1 F_9 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_60 [ V_4 ] . V_61 != 0 ; V_4 ++ ) {
struct V_62 * V_63 = NULL ;
while ( ( V_63 = F_23 ( NULL ,
V_60 [ V_4 ] . V_61 ,
V_60 [ V_4 ] . V_64 ,
V_63 ) ) ) {
if ( F_24 ( V_63 ) < 0 )
continue;
if ( F_25 ( V_63 ) < 0 ) {
V_65:
F_26 ( V_63 ) ;
continue;
}
if ( ! F_27 ( V_63 , 0 ) || ! F_28 ( V_63 , 0 ) )
goto V_65;
V_2 -> V_5 = F_29 ( V_63 , 0 ) ;
V_2 -> V_3 = F_30 ( V_63 , 0 ) ;
F_18 ( V_66 L_12 ,
( char * ) V_60 [ V_4 ] . V_67 ,
V_2 -> V_5 , V_2 -> V_3 ) ;
if ( F_6 ( V_2 , V_2 -> V_5 ) != 0 ) {
F_18 ( V_68 L_13 , V_2 -> V_5 ) ;
F_26 ( V_63 ) ;
return - V_6 ;
}
V_38 . V_69 = ( unsigned long ) V_63 ;
break;
}
if ( ! V_63 )
continue;
return 0 ;
}
return - V_8 ;
}
static int
F_31 ( struct V_1 * V_2 )
{
int V_15 ;
int V_14 = V_2 -> V_5 - V_34 ;
unsigned char V_70 [] = { 0 , 0 , 0x04 , 0x08 , 0 , 0x0C , 0 , 0x40 ,
0 , 0x04 , 0x44 , 0x48 , 0 , 0 , 0 , 0x4C , } ;
V_15 = F_32 ( V_2 -> V_3 , F_3 , 0 , V_2 -> V_12 , V_2 ) ;
if ( V_15 )
return V_15 ;
F_17 ( 0x00 , V_14 ) ;
F_17 ( 0x80 , V_14 + 5 ) ;
F_17 ( F_15 ( V_14 + 4 ) | 0x80 , V_14 + 4 ) ;
F_17 ( ( F_15 ( V_14 + 13 ) & ~ 0x4C ) | V_70 [ V_2 -> V_3 ] , V_14 + 13 ) ;
F_17 ( F_15 ( V_14 + 4 ) & 0x7f , V_14 + 4 ) ;
if ( V_38 . V_47 == & V_48 ) {
F_17 ( 0x11 , V_14 + 6 ) ;
F_17 ( 0x01 , V_14 + 0x19 ) ;
} else
F_17 ( 0x01 , V_14 + 6 ) ;
F_33 ( V_71 + V_72 , V_2 -> V_5 ) ;
F_17 ( 0xff , V_2 -> V_5 + V_73 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
static void
V_57 ( struct V_1 * V_2 )
{
int V_74 = V_2 -> V_5 - V_34 ;
F_17 ( V_75 , V_74 ) ;
if ( V_29 > 1 ) F_18 ( L_14 , V_76 ) ;
V_38 . V_77 = 0 ;
F_17 ( 0x00 , V_74 ) ;
F_17 ( 0x80 , V_74 + 5 ) ;
if ( V_38 . V_47 == & V_48 )
F_17 ( 0x11 , V_74 + 6 ) ;
else
F_17 ( 0x01 , V_74 + 6 ) ;
if ( V_29 > 1 ) F_18 ( L_15 ) ;
}
static void
V_55 ( struct V_1 * V_2 , struct V_78 * V_79 , int V_80 )
{
void T_2 * V_81 = V_38 . V_45 + ( ( V_80 - V_41 ) << 8 ) ;
F_17 ( V_82 , V_2 -> V_5 - V_34 ) ;
#ifdef F_35
F_36 ( V_79 , V_81 , sizeof( struct V_78 ) ) ;
V_79 -> V_83 = F_37 ( V_79 -> V_83 ) ;
#else
( ( unsigned int * ) V_79 ) [ 0 ] = F_38 ( V_81 ) ;
#endif
F_17 ( 0x00 , V_2 -> V_5 - V_34 ) ;
}
static void
V_53 ( struct V_1 * V_2 , int V_83 , struct V_84 * V_85 , int V_86 )
{
void T_2 * V_87 = V_38 . V_45 + V_86 - ( V_41 << 8 ) ;
F_17 ( V_82 , V_2 -> V_5 - V_34 ) ;
if ( V_86 + V_83 > V_38 . V_44 * 256 ) {
int V_88 = V_38 . V_44 * 256 - V_86 ;
F_36 ( V_85 -> V_89 , V_87 , V_88 ) ;
V_83 -= V_88 ;
F_36 ( V_85 -> V_89 + V_88 , V_38 . V_45 + V_43 * 256 , V_83 ) ;
} else {
F_36 ( V_85 -> V_89 , V_87 , V_83 ) ;
}
F_17 ( 0x00 , V_2 -> V_5 - V_34 ) ;
}
static void
V_54 ( struct V_1 * V_2 , int V_83 , const unsigned char * V_90 ,
int V_91 )
{
void T_2 * V_92 = V_38 . V_45 + ( ( V_91 - V_41 ) << 8 ) ;
F_17 ( V_82 , V_2 -> V_5 - V_34 ) ;
F_39 ( V_92 , V_90 , V_83 ) ;
F_17 ( 0x00 , V_2 -> V_5 - V_34 ) ;
}
static void V_52 ( struct V_1 * V_2 , struct V_78 * V_79 ,
int V_80 )
{
int V_14 = V_2 -> V_5 - V_34 ;
F_17 ( 0x00 , V_14 + V_93 ) ;
F_17 ( V_80 , V_14 + V_93 ) ;
F_40 ( V_14 + V_94 , V_79 , sizeof( struct V_78 ) >> 1 ) ;
}
static void V_48 ( struct V_1 * V_2 , int V_83 ,
struct V_84 * V_85 , int V_86 )
{
int V_14 = V_2 -> V_5 - V_34 ;
char * V_90 = V_85 -> V_89 ;
F_17 ( V_86 , V_14 + V_93 ) ;
F_17 ( V_86 >> 8 , V_14 + V_93 ) ;
F_40 ( V_14 + V_94 , V_90 , ( V_83 + 1 ) >> 1 ) ;
}
static void V_50 ( struct V_1 * V_2 , int V_83 ,
const unsigned char * V_90 , const int V_91 )
{
int V_14 = V_2 -> V_5 - V_34 ;
F_17 ( 0x00 , V_14 + V_93 ) ;
F_17 ( V_91 , V_14 + V_93 ) ;
F_41 ( V_14 + V_94 , V_90 , ( V_83 + 1 ) >> 1 ) ;
}
static int
F_42 ( struct V_1 * V_2 )
{
int V_14 = V_2 -> V_5 - V_34 ;
F_43 ( V_2 ) ;
if ( V_29 > 1 )
F_18 ( L_16 , V_2 -> V_12 ) ;
F_17 ( 0x00 , V_14 + 6 ) ;
F_44 ( V_2 -> V_3 , V_2 ) ;
F_20 ( V_2 , 0 ) ;
return 0 ;
}
int T_1
F_45 ( void )
{
struct V_1 * V_2 ;
int V_95 , V_96 = 0 ;
for ( V_95 = 0 ; V_95 < V_97 ; V_95 ++ ) {
if ( V_98 [ V_95 ] == 0 ) {
if ( V_95 != 0 ) break;
F_18 ( V_99 L_17 ) ;
}
V_2 = F_11 () ;
if ( ! V_2 )
break;
V_2 -> V_3 = V_3 [ V_95 ] ;
V_2 -> V_5 = V_98 [ V_95 ] ;
if ( F_5 ( V_2 ) == 0 ) {
V_100 [ V_96 ++ ] = V_2 ;
continue;
}
F_14 ( V_2 ) ;
F_18 ( V_101 L_18 , V_98 [ V_95 ] ) ;
break;
}
if ( V_96 )
return 0 ;
return - V_6 ;
}
static void F_46 ( struct V_1 * V_2 )
{
#ifdef F_7
struct V_62 * V_63 = (struct V_62 * ) V_38 . V_69 ;
if ( V_63 )
F_26 ( V_63 ) ;
#endif
F_22 ( V_2 -> V_5 - V_34 , V_26 ) ;
F_47 ( V_38 . V_45 ) ;
}
void T_3
F_48 ( void )
{
int V_95 ;
for ( V_95 = 0 ; V_95 < V_97 ; V_95 ++ ) {
struct V_1 * V_2 = V_100 [ V_95 ] ;
if ( V_2 ) {
F_49 ( V_2 ) ;
F_46 ( V_2 ) ;
F_14 ( V_2 ) ;
}
}
}
