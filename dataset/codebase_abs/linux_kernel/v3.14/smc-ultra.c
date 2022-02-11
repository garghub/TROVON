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
struct V_26 * V_27 = F_16 ( V_2 ) ;
if ( ! F_17 ( V_14 , V_28 , V_29 ) )
return - V_30 ;
if ( ( V_24 & 0xF0 ) != 0x20
&& ( V_24 & 0xF0 ) != 0x40 ) {
V_15 = - V_8 ;
goto V_13;
}
F_18 ( V_25 , V_14 + 4 ) ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ )
V_16 += F_15 ( V_14 + 8 + V_4 ) ;
if ( ( V_16 & 0xff ) != 0xFF ) {
V_15 = - V_8 ;
goto V_13;
}
if ( ( V_31 & V_32 ) && ( V_19 ++ == 0 ) )
F_19 ( V_2 , V_33 ) ;
V_17 = ( V_24 & 0xF0 ) == 0x20 ? L_2 : L_3 ;
for ( V_4 = 0 ; V_4 < 6 ; V_4 ++ )
V_2 -> V_34 [ V_4 ] = F_15 ( V_14 + 8 + V_4 ) ;
F_19 ( V_2 , L_4 , V_17 ,
V_14 , V_2 -> V_34 ) ;
F_18 ( 0x80 | V_25 , V_14 + 4 ) ;
F_18 ( 0x80 | F_15 ( V_14 + 0x0c ) , V_14 + 0x0c ) ;
V_23 = F_15 ( V_14 + 0x8 ) ;
V_22 = F_15 ( V_14 + 0xb ) ;
V_21 = F_15 ( V_14 + 0xd ) ;
F_18 ( V_25 , V_14 + 4 ) ;
if ( V_2 -> V_3 < 2 ) {
unsigned char V_35 [] = { 0 , 9 , 3 , 5 , 7 , 10 , 11 , 15 } ;
int V_3 ;
V_3 = V_35 [ ( ( V_21 & 0x40 ) >> 4 ) + ( ( V_21 & 0x0c ) >> 2 ) ] ;
if ( V_3 == 0 ) {
F_20 ( L_5 ) ;
V_15 = - V_36 ;
goto V_13;
}
V_2 -> V_3 = V_3 ;
V_18 = 1 ;
}
V_2 -> V_5 = V_14 + V_37 ;
{
static const int V_38 [ 4 ] = {
0x0C0000 , 0x0E0000 , 0xFC0000 , 0xFE0000
} ;
static const short V_39 [ 4 ] = {
0x20 , 0x40 , 0x80 , 0xff
} ;
V_2 -> V_40 = ( ( V_22 & 0x0f ) << 13 ) + V_38 [ ( V_22 >> 6 ) & 3 ] ;
V_20 = V_39 [ ( V_22 >> 4 ) & 3 ] ;
}
V_41 . V_12 = V_17 ;
V_41 . V_42 = 1 ;
V_41 . V_43 = V_44 ;
V_41 . V_45 = V_44 + V_46 ;
V_41 . V_47 = V_20 ;
V_41 . V_48 = F_21 ( V_2 -> V_40 , ( V_41 . V_47 - V_44 ) * 256 ) ;
if ( ! V_41 . V_48 ) {
F_20 ( L_6 ) ;
V_15 = - V_11 ;
goto V_13;
}
V_2 -> V_49 = V_2 -> V_40 + ( V_41 . V_47 - V_44 ) * 256 ;
if ( V_23 ) {
F_20 ( L_7 ,
V_18 ? L_8 : L_9 , V_2 -> V_3 ) ;
V_41 . V_50 = & V_51 ;
V_41 . V_52 = & V_53 ;
V_41 . V_54 = & V_55 ;
} else {
F_20 ( L_10 ,
V_18 ? L_11 : L_9 , V_2 -> V_3 , V_2 -> V_40 ,
V_2 -> V_49 - 1 ) ;
V_41 . V_50 = & V_56 ;
V_41 . V_52 = & V_57 ;
V_41 . V_54 = & V_58 ;
}
V_41 . V_59 = & V_60 ;
V_2 -> V_61 = & V_62 ;
F_22 ( V_2 , 0 ) ;
V_27 -> V_63 = V_31 ;
V_15 = F_23 ( V_2 ) ;
if ( V_15 )
goto V_13;
return 0 ;
V_13:
F_24 ( V_14 , V_28 ) ;
return V_15 ;
}
static int T_1 F_9 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_64 [ V_4 ] . V_65 != 0 ; V_4 ++ ) {
struct V_66 * V_67 = NULL ;
while ( ( V_67 = F_25 ( NULL ,
V_64 [ V_4 ] . V_65 ,
V_64 [ V_4 ] . V_68 ,
V_67 ) ) ) {
if ( F_26 ( V_67 ) < 0 )
continue;
if ( F_27 ( V_67 ) < 0 ) {
V_69:
F_28 ( V_67 ) ;
continue;
}
if ( ! F_29 ( V_67 , 0 ) || ! F_30 ( V_67 , 0 ) )
goto V_69;
V_2 -> V_5 = F_31 ( V_67 , 0 ) ;
V_2 -> V_3 = F_32 ( V_67 , 0 ) ;
F_19 ( V_2 ,
L_12 ,
( char * ) V_64 [ V_4 ] . V_70 ,
V_2 -> V_5 , V_2 -> V_3 ) ;
if ( F_6 ( V_2 , V_2 -> V_5 ) != 0 ) {
F_33 ( V_2 ,
L_13 ,
V_2 -> V_5 ) ;
F_28 ( V_67 ) ;
return - V_6 ;
}
V_41 . V_71 = ( unsigned long ) V_67 ;
break;
}
if ( ! V_67 )
continue;
return 0 ;
}
return - V_8 ;
}
static int
F_34 ( struct V_1 * V_2 )
{
int V_15 ;
int V_14 = V_2 -> V_5 - V_37 ;
unsigned char V_72 [] = { 0 , 0 , 0x04 , 0x08 , 0 , 0x0C , 0 , 0x40 ,
0 , 0x04 , 0x44 , 0x48 , 0 , 0 , 0 , 0x4C , } ;
V_15 = F_35 ( V_2 -> V_3 , F_3 , 0 , V_2 -> V_12 , V_2 ) ;
if ( V_15 )
return V_15 ;
F_18 ( 0x00 , V_14 ) ;
F_18 ( 0x80 , V_14 + 5 ) ;
F_18 ( F_15 ( V_14 + 4 ) | 0x80 , V_14 + 4 ) ;
F_18 ( ( F_15 ( V_14 + 13 ) & ~ 0x4C ) | V_72 [ V_2 -> V_3 ] , V_14 + 13 ) ;
F_18 ( F_15 ( V_14 + 4 ) & 0x7f , V_14 + 4 ) ;
if ( V_41 . V_50 == & V_51 ) {
F_18 ( 0x11 , V_14 + 6 ) ;
F_18 ( 0x01 , V_14 + 0x19 ) ;
} else
F_18 ( 0x01 , V_14 + 6 ) ;
F_36 ( V_73 + V_74 , V_2 -> V_5 ) ;
F_18 ( 0xff , V_2 -> V_5 + V_75 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static void
V_60 ( struct V_1 * V_2 )
{
int V_76 = V_2 -> V_5 - V_37 ;
struct V_26 * V_27 = F_16 ( V_2 ) ;
F_18 ( V_77 , V_76 ) ;
F_38 ( V_27 , V_78 , V_2 , L_14 , V_79 ) ;
V_41 . V_80 = 0 ;
F_18 ( 0x00 , V_76 ) ;
F_18 ( 0x80 , V_76 + 5 ) ;
if ( V_41 . V_50 == & V_51 )
F_18 ( 0x11 , V_76 + 6 ) ;
else
F_18 ( 0x01 , V_76 + 6 ) ;
F_38 ( V_27 , V_78 , V_2 , L_15 ) ;
}
static void
V_58 ( struct V_1 * V_2 , struct V_81 * V_82 , int V_83 )
{
void T_2 * V_84 = V_41 . V_48 + ( ( V_83 - V_44 ) << 8 ) ;
F_18 ( V_85 , V_2 -> V_5 - V_37 ) ;
#ifdef F_39
F_40 ( V_82 , V_84 , sizeof( struct V_81 ) ) ;
V_82 -> V_86 = F_41 ( V_82 -> V_86 ) ;
#else
( ( unsigned int * ) V_82 ) [ 0 ] = F_42 ( V_84 ) ;
#endif
F_18 ( 0x00 , V_2 -> V_5 - V_37 ) ;
}
static void
V_56 ( struct V_1 * V_2 , int V_86 , struct V_87 * V_88 , int V_89 )
{
void T_2 * V_90 = V_41 . V_48 + V_89 - ( V_44 << 8 ) ;
F_18 ( V_85 , V_2 -> V_5 - V_37 ) ;
if ( V_89 + V_86 > V_41 . V_47 * 256 ) {
int V_91 = V_41 . V_47 * 256 - V_89 ;
F_40 ( V_88 -> V_92 , V_90 , V_91 ) ;
V_86 -= V_91 ;
F_40 ( V_88 -> V_92 + V_91 , V_41 . V_48 + V_46 * 256 , V_86 ) ;
} else {
F_40 ( V_88 -> V_92 , V_90 , V_86 ) ;
}
F_18 ( 0x00 , V_2 -> V_5 - V_37 ) ;
}
static void
V_57 ( struct V_1 * V_2 , int V_86 , const unsigned char * V_93 ,
int V_94 )
{
void T_2 * V_95 = V_41 . V_48 + ( ( V_94 - V_44 ) << 8 ) ;
F_18 ( V_85 , V_2 -> V_5 - V_37 ) ;
F_43 ( V_95 , V_93 , V_86 ) ;
F_18 ( 0x00 , V_2 -> V_5 - V_37 ) ;
}
static void V_55 ( struct V_1 * V_2 , struct V_81 * V_82 ,
int V_83 )
{
int V_14 = V_2 -> V_5 - V_37 ;
F_18 ( 0x00 , V_14 + V_96 ) ;
F_18 ( V_83 , V_14 + V_96 ) ;
F_44 ( V_14 + V_97 , V_82 , sizeof( struct V_81 ) >> 1 ) ;
}
static void V_51 ( struct V_1 * V_2 , int V_86 ,
struct V_87 * V_88 , int V_89 )
{
int V_14 = V_2 -> V_5 - V_37 ;
char * V_93 = V_88 -> V_92 ;
F_18 ( V_89 , V_14 + V_96 ) ;
F_18 ( V_89 >> 8 , V_14 + V_96 ) ;
F_44 ( V_14 + V_97 , V_93 , ( V_86 + 1 ) >> 1 ) ;
}
static void V_53 ( struct V_1 * V_2 , int V_86 ,
const unsigned char * V_93 , const int V_94 )
{
int V_14 = V_2 -> V_5 - V_37 ;
F_18 ( 0x00 , V_14 + V_96 ) ;
F_18 ( V_94 , V_14 + V_96 ) ;
F_45 ( V_14 + V_97 , V_93 , ( V_86 + 1 ) >> 1 ) ;
}
static int
F_46 ( struct V_1 * V_2 )
{
int V_14 = V_2 -> V_5 - V_37 ;
struct V_26 * V_27 = F_16 ( V_2 ) ;
F_47 ( V_2 ) ;
F_38 ( V_27 , V_98 , V_2 , L_16 ) ;
F_18 ( 0x00 , V_14 + 6 ) ;
F_48 ( V_2 -> V_3 , V_2 ) ;
F_22 ( V_2 , 0 ) ;
return 0 ;
}
int T_1
F_49 ( void )
{
struct V_1 * V_2 ;
int V_99 , V_100 = 0 ;
for ( V_99 = 0 ; V_99 < V_101 ; V_99 ++ ) {
if ( V_102 [ V_99 ] == 0 ) {
if ( V_99 != 0 ) break;
F_50 ( V_103 L_17 ) ;
}
V_2 = F_11 () ;
if ( ! V_2 )
break;
V_2 -> V_3 = V_3 [ V_99 ] ;
V_2 -> V_5 = V_102 [ V_99 ] ;
if ( F_5 ( V_2 ) == 0 ) {
V_104 [ V_100 ++ ] = V_2 ;
continue;
}
F_14 ( V_2 ) ;
F_50 ( V_105 L_18 , V_102 [ V_99 ] ) ;
break;
}
if ( V_100 )
return 0 ;
return - V_6 ;
}
static void F_51 ( struct V_1 * V_2 )
{
#ifdef F_7
struct V_66 * V_67 = (struct V_66 * ) V_41 . V_71 ;
if ( V_67 )
F_28 ( V_67 ) ;
#endif
F_24 ( V_2 -> V_5 - V_37 , V_28 ) ;
F_52 ( V_41 . V_48 ) ;
}
void T_3
F_53 ( void )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < V_101 ; V_99 ++ ) {
struct V_1 * V_2 = V_104 [ V_99 ] ;
if ( V_2 ) {
F_54 ( V_2 ) ;
F_51 ( V_2 ) ;
F_14 ( V_2 ) ;
}
}
}
