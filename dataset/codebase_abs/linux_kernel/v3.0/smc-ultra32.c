static void F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 - V_5 ;
F_2 ( V_3 , V_6 ) ;
F_3 ( V_7 . V_8 ) ;
}
struct V_1 * T_1 F_4 ( int V_9 )
{
struct V_1 * V_2 ;
int V_10 ;
int V_11 ;
int V_12 = - V_13 ;
if ( ! V_14 )
return F_5 ( - V_13 ) ;
V_2 = F_6 () ;
if ( ! V_2 )
return F_5 ( - V_15 ) ;
if ( V_9 >= 0 ) {
sprintf ( V_2 -> V_16 , L_1 , V_9 ) ;
F_7 ( V_2 ) ;
}
V_11 = V_2 -> V_11 ;
for ( V_10 = 0x1000 + V_17 ; V_10 < 0x9000 ; V_10 += 0x1000 ) {
if ( F_8 ( V_2 , V_10 ) == 0 )
break;
V_2 -> V_11 = V_11 ;
}
if ( V_10 >= 0x9000 )
goto V_18;
V_12 = F_9 ( V_2 ) ;
if ( V_12 )
goto V_19;
return V_2 ;
V_19:
F_1 ( V_2 ) ;
V_18:
F_10 ( V_2 ) ;
return F_5 ( V_12 ) ;
}
static int T_1 F_8 ( struct V_1 * V_2 , int V_3 )
{
int V_20 , V_21 , V_22 , V_23 ;
int V_24 = 0 ;
const char * V_25 ;
static unsigned V_26 ;
unsigned char V_27 ;
unsigned char V_28 ;
const char * V_29 [] = { L_2 , L_3 , L_4 , L_5 } ;
if ( ! F_11 ( V_3 , V_6 , V_30 ) )
return - V_31 ;
if ( F_12 ( V_3 + V_32 ) == 0xff ||
F_13 ( V_3 + V_32 ) != V_33 ) {
V_23 = - V_13 ;
goto V_18;
}
V_22 = F_12 ( V_3 + V_34 ) & 0x03 ;
V_21 = F_12 ( V_3 + V_35 ) & 0x08 ;
F_14 ( L_6 ,
V_3 >> 12 , V_29 [ V_22 ] ,
( V_21 ? L_7 : L_8 ) ) ;
V_27 = F_12 ( V_3 + 7 ) ;
V_28 = F_12 ( V_3 + 4 ) & 0x7f ;
if ( ( V_27 & 0xf0 ) != 0x20 ) {
V_23 = - V_13 ;
goto V_18;
}
F_15 ( V_28 , V_3 + 4 ) ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ )
V_24 += F_12 ( V_3 + 8 + V_20 ) ;
if ( ( V_24 & 0xff ) != 0xff ) {
V_23 = - V_13 ;
goto V_18;
}
if ( V_36 && V_26 ++ == 0 )
F_14 ( V_37 ) ;
V_25 = L_9 ;
for ( V_20 = 0 ; V_20 < 6 ; V_20 ++ )
V_2 -> V_38 [ V_20 ] = F_12 ( V_3 + 8 + V_20 ) ;
F_14 ( L_10 ,
V_2 -> V_16 , V_25 , V_3 , V_2 -> V_38 ) ;
F_15 ( 0x80 | V_28 , V_3 + 4 ) ;
F_15 ( 0x80 | F_12 ( V_3 + 0x0c ) , V_3 + 0x0c ) ;
F_15 ( 0x00 , V_3 + 0x0b ) ;
F_15 ( V_28 , V_3 + 4 ) ;
if ( ( F_12 ( V_3 + V_35 ) & 0x40 ) == 0 ) {
F_14 ( L_11
L_12 ) ;
V_23 = - V_13 ;
goto V_18;
}
if ( ( F_12 ( V_3 + V_39 ) & 0x04 ) == 0 )
F_14 ( L_13
L_12 ) ;
if ( V_2 -> V_11 < 2 ) {
unsigned char V_40 [] = { 0 , 9 , 3 , 5 , 7 , 10 , 11 , 15 } ;
int V_11 = V_40 [ F_12 ( V_3 + V_35 ) & 0x07 ] ;
if ( V_11 == 0 ) {
F_14 ( L_14 ) ;
V_23 = - V_41 ;
goto V_18;
}
V_2 -> V_11 = V_11 ;
}
V_2 -> V_4 = V_3 + V_5 ;
V_7 . V_42 = F_12 ( V_3 + V_43 ) & 0xfc ;
V_2 -> V_44 = 0xc0000 + ( ( V_7 . V_42 & 0x7c ) << 11 ) ;
V_7 . V_16 = V_25 ;
V_7 . V_45 = 1 ;
V_7 . V_46 = 0 ;
V_7 . V_47 = V_48 ;
V_7 . V_49 = 128 ;
V_7 . V_8 = F_16 ( V_2 -> V_44 , 0x2000 ) ;
if ( ! V_7 . V_8 ) {
F_14 ( L_15 ) ;
V_23 = - V_15 ;
goto V_18;
}
V_2 -> V_50 = V_2 -> V_44 + 0x1fff ;
F_14 ( L_16 ,
V_2 -> V_11 , V_2 -> V_44 , V_2 -> V_50 ) ;
V_7 . V_51 = & V_52 ;
V_7 . V_53 = & V_54 ;
V_7 . V_55 = & V_56 ;
V_7 . V_57 = & V_58 ;
V_2 -> V_59 = & V_60 ;
F_17 ( V_2 , 0 ) ;
return 0 ;
V_18:
F_2 ( V_3 , V_6 ) ;
return V_23 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 - V_5 ;
int V_61 = ( F_12 ( V_3 + V_35 ) & 0x08 ) ? 0 : V_62 ;
int V_23 ;
V_23 = F_19 ( V_2 -> V_11 , V_63 , V_61 , V_2 -> V_16 , V_2 ) ;
if ( V_23 )
return V_23 ;
F_15 ( V_64 , V_3 ) ;
F_15 ( 0x80 , V_3 + V_65 ) ;
F_15 ( 0x84 , V_3 + 5 ) ;
F_15 ( 0x01 , V_3 + 6 ) ;
F_20 ( V_66 + V_67 , V_2 -> V_4 ) ;
F_15 ( 0xff , V_2 -> V_4 + V_68 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 - V_5 ;
F_23 ( V_2 ) ;
if ( V_36 > 1 )
F_14 ( L_17 , V_2 -> V_16 ) ;
F_15 ( 0x00 , V_3 + V_65 ) ;
F_15 ( 0x00 , V_3 + 6 ) ;
F_24 ( V_2 -> V_11 , V_2 ) ;
F_17 ( V_2 , 0 ) ;
return 0 ;
}
static void V_58 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 - V_5 ;
F_15 ( V_69 , V_3 ) ;
if ( V_36 > 1 ) F_14 ( L_18 , V_70 ) ;
V_7 . V_71 = 0 ;
F_15 ( V_64 , V_3 ) ;
F_15 ( 0x80 , V_3 + V_65 ) ;
F_15 ( 0x84 , V_3 + 5 ) ;
F_15 ( 0x01 , V_3 + 6 ) ;
if ( V_36 > 1 ) F_14 ( L_19 ) ;
}
static void V_56 ( struct V_1 * V_2 ,
struct V_72 * V_73 ,
int V_74 )
{
void T_2 * V_75 = V_7 . V_8 + ( ( V_74 & 0x1f ) << 8 ) ;
unsigned int V_76 = V_2 -> V_4 - V_5 + V_43 ;
F_15 ( V_7 . V_42 | ( ( V_74 & 0x60 ) >> 5 ) , V_76 ) ;
#ifdef F_25
F_26 ( V_73 , V_75 , sizeof( struct V_72 ) ) ;
V_73 -> V_77 = F_27 ( V_73 -> V_77 ) ;
#else
( ( unsigned int * ) V_73 ) [ 0 ] = F_28 ( V_75 ) ;
#endif
}
static void V_52 ( struct V_1 * V_2 ,
int V_77 ,
struct V_78 * V_79 ,
int V_80 )
{
void T_2 * V_81 = V_7 . V_8 + ( V_80 & 0x1fff ) ;
unsigned int V_76 = V_2 -> V_4 - V_5 + V_43 ;
if ( ( V_80 & ~ 0x1fff ) != ( ( V_80 + V_77 - 1 ) & ~ 0x1fff ) ) {
int V_82 = 8192 - ( V_80 & 0x1FFF ) ;
F_26 ( V_79 -> V_83 , V_81 , V_82 ) ;
V_77 -= V_82 ;
if ( V_80 < 96 * 256 ) {
V_80 += V_82 ;
F_15 ( V_7 . V_42 | ( ( V_80 & 0x6000 ) >> 13 ) , V_76 ) ;
F_26 ( V_79 -> V_83 + V_82 , V_7 . V_8 , V_77 ) ;
} else {
F_15 ( V_7 . V_42 , V_76 ) ;
F_26 ( V_79 -> V_83 + V_82 , V_7 . V_8 + V_48 * 256 , V_77 ) ;
}
} else {
F_26 ( V_79 -> V_83 , V_81 , V_77 ) ;
}
}
static void V_54 ( struct V_1 * V_2 ,
int V_77 ,
const unsigned char * V_84 ,
int V_85 )
{
void T_2 * V_81 = V_7 . V_8 + ( V_85 << 8 ) ;
unsigned int V_76 = V_2 -> V_4 - V_5 + V_43 ;
F_15 ( V_7 . V_42 , V_76 ) ;
F_29 ( V_81 , V_84 , V_77 ) ;
}
int T_1 F_30 ( void )
{
int V_86 , V_87 = 0 ;
for ( V_86 = 0 ; V_86 < V_88 ; V_86 ++ ) {
struct V_1 * V_2 = F_4 ( - 1 ) ;
if ( F_31 ( V_2 ) )
break;
V_89 [ V_87 ++ ] = V_2 ;
}
if ( V_87 )
return 0 ;
F_14 ( V_90 L_20 ) ;
return - V_91 ;
}
void T_3 F_32 ( void )
{
int V_86 ;
for ( V_86 = 0 ; V_86 < V_88 ; V_86 ++ ) {
struct V_1 * V_2 = V_89 [ V_86 ] ;
if ( V_2 ) {
F_33 ( V_2 ) ;
F_1 ( V_2 ) ;
F_10 ( V_2 ) ;
}
}
}
