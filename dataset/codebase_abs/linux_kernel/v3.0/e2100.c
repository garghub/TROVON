static inline void F_1 ( short V_1 , volatile char T_1 * V_2 ,
unsigned char V_3 )
{
F_2 ( V_2 + V_3 ) ;
F_3 ( V_1 + V_4 ) ;
F_4 ( V_5 , V_1 + V_4 + V_5 ) ;
}
static inline void F_5 ( short V_1 )
{
F_3 ( V_1 + V_4 ) ;
F_4 ( 0x00 , V_1 + V_4 ) ;
}
static int T_2 F_6 ( struct V_6 * V_7 )
{
int * V_1 ;
int V_8 = V_7 -> V_8 ;
int V_9 = V_7 -> V_9 ;
if ( V_8 > 0x1ff )
return F_7 ( V_7 , V_8 ) ;
else if ( V_8 != 0 )
return - V_10 ;
for ( V_1 = V_11 ; * V_1 ; V_1 ++ ) {
V_7 -> V_9 = V_9 ;
if ( F_7 ( V_7 , * V_1 ) == 0 )
return 0 ;
}
return - V_12 ;
}
struct V_6 * T_2 F_8 ( int V_13 )
{
struct V_6 * V_7 = F_9 () ;
int V_14 ;
if ( ! V_7 )
return F_10 ( - V_15 ) ;
sprintf ( V_7 -> V_16 , L_1 , V_13 ) ;
F_11 ( V_7 ) ;
V_14 = F_6 ( V_7 ) ;
if ( V_14 )
goto V_17;
return V_7 ;
V_17:
F_12 ( V_7 ) ;
return F_10 ( V_14 ) ;
}
static int T_2 F_7 ( struct V_6 * V_7 , int V_18 )
{
int V_19 , V_20 , V_21 ;
unsigned char * V_22 = V_7 -> V_23 ;
static unsigned V_24 ;
if ( ! F_13 ( V_18 , V_25 , V_26 ) )
return - V_27 ;
if ( F_3 ( V_18 + V_28 + 0 ) != 0x00 ||
F_3 ( V_18 + V_28 + 1 ) != 0x00 ||
F_3 ( V_18 + V_28 + 2 ) != 0x1d ) {
V_21 = - V_12 ;
goto V_17;
}
F_4 ( V_29 + V_30 , V_18 ) ;
F_14 ( 1 ) ;
V_20 = F_3 ( V_18 ) ;
if ( V_20 != 0x21 && V_20 != 0x23 ) {
V_21 = - V_12 ;
goto V_17;
}
for ( V_19 = 0 ; V_19 < 6 ; V_19 ++ )
V_22 [ V_19 ] = F_3 ( V_18 + V_28 + V_19 ) ;
F_3 ( V_18 + V_31 ) ;
F_4 ( 0 , V_18 + V_32 ) ;
if ( V_33 && V_24 ++ == 0 )
F_15 ( V_34 ) ;
for ( V_19 = 0 ; V_19 < 6 ; V_19 ++ )
F_15 ( L_2 , V_22 [ V_19 ] ) ;
if ( V_7 -> V_9 < 2 ) {
static const int V_35 [] = { 15 , 11 , 10 , 12 , 5 , 9 , 3 , 4 } ;
for ( V_19 = 0 ; V_19 < F_16 ( V_35 ) ; V_19 ++ )
if ( F_17 ( V_35 [ V_19 ] , NULL , 0 , L_3 , NULL ) != - V_27 ) {
V_7 -> V_9 = V_35 [ V_19 ] ;
break;
}
if ( V_19 >= F_16 ( V_35 ) ) {
F_15 ( L_4 , V_7 -> V_9 ) ;
V_21 = - V_36 ;
goto V_17;
}
} else if ( V_7 -> V_9 == 2 )
V_7 -> V_9 = 9 ;
V_7 -> V_8 = V_18 ;
V_37 . V_16 = L_5 ;
V_37 . V_38 = 1 ;
V_37 . V_39 = V_40 ;
V_37 . V_41 = V_42 ;
V_37 . V_43 = V_44 ;
V_37 . V_45 = V_7 -> V_9 ;
if ( V_7 -> V_46 & 15 )
V_7 -> V_47 = V_7 -> V_46 & 7 ;
else {
V_7 -> V_47 = 0 ;
F_3 ( V_18 + V_31 ) ;
for( V_19 = 0 ; V_19 < 6 ; V_19 ++ )
if ( V_22 [ V_19 ] != F_3 ( V_18 + V_28 + 8 + V_19 ) ) {
V_7 -> V_47 = 1 ;
break;
}
}
if ( V_7 -> V_48 == 0 )
V_7 -> V_48 = 0xd0000 ;
V_37 . V_49 = F_18 ( V_7 -> V_48 , 2 * 1024 ) ;
if ( ! V_37 . V_49 ) {
F_15 ( L_6 ) ;
V_21 = - V_36 ;
goto V_17;
}
#ifdef F_19
V_37 . V_50 = V_7 -> V_48 + V_51 * 256 ;
V_7 -> V_46 = V_37 . V_52 = V_7 -> V_48 + 2 * 1024 ;
#endif
F_15 ( L_7 , V_7 -> V_9 ,
V_7 -> V_47 ? L_8 : L_9 , V_7 -> V_48 ) ;
V_37 . V_53 = & V_54 ;
V_37 . V_55 = & V_56 ;
V_37 . V_57 = & V_58 ;
V_37 . V_59 = & V_60 ;
V_7 -> V_61 = & V_62 ;
F_20 ( V_7 , 0 ) ;
V_21 = F_21 ( V_7 ) ;
if ( V_21 )
goto V_17;
return 0 ;
V_17:
F_22 ( V_18 , V_25 ) ;
return V_21 ;
}
static int
F_23 ( struct V_6 * V_7 )
{
short V_18 = V_7 -> V_8 ;
int V_21 ;
if ( ( V_21 = F_17 ( V_7 -> V_9 , V_63 , 0 , V_7 -> V_16 , V_7 ) ) )
return V_21 ;
F_3 ( V_18 + V_64 ) ;
F_4 ( 0 , V_18 + V_32 + ( V_7 -> V_9 & 7 ) ) ;
F_3 ( V_18 + V_65 ) ;
F_4 ( 0 , V_18 + V_32 + ( V_7 -> V_9 > 7 ? 1 : 0 )
+ ( V_7 -> V_47 ? V_66 : 0 ) ) ;
F_3 ( V_18 + V_67 ) ;
F_4 ( 0 , V_18 + V_32 + ( ( V_7 -> V_48 >> 17 ) & 7 ) ) ;
F_24 ( V_7 ) ;
return 0 ;
}
static void
V_54 ( struct V_6 * V_7 )
{
short V_18 = V_7 -> V_8 ;
F_4 ( 0x01 , V_18 ) ;
if ( V_33 > 1 ) F_15 ( L_10 , V_68 ) ;
V_37 . V_69 = 0 ;
if ( V_33 > 1 ) F_15 ( L_11 ) ;
}
static void
V_60 ( struct V_6 * V_7 , struct V_70 * V_71 , int V_72 )
{
short V_18 = V_7 -> V_8 ;
char T_1 * V_73 = V_37 . V_49 ;
F_1 ( V_18 , V_73 , V_72 ) ;
#ifdef F_19
F_25 ( V_71 , V_73 , sizeof( struct V_70 ) ) ;
#else
( ( unsigned int * ) V_71 ) [ 0 ] = F_26 ( V_73 ) ;
#endif
F_5 ( V_18 ) ;
}
static void
V_56 ( struct V_6 * V_7 , int V_74 , struct V_75 * V_76 , int V_77 )
{
short V_18 = V_7 -> V_8 ;
char T_1 * V_73 = V_37 . V_49 ;
F_1 ( V_18 , V_73 , ( V_77 >> 8 ) ) ;
F_25 ( V_76 -> V_78 , V_37 . V_49 + ( V_77 & 0xff ) , V_74 ) ;
F_5 ( V_18 ) ;
}
static void
V_58 ( struct V_6 * V_7 , int V_74 , const unsigned char * V_79 ,
int V_3 )
{
short V_18 = V_7 -> V_8 ;
volatile char T_1 * V_73 = V_37 . V_49 ;
F_2 ( V_73 + V_3 ) ;
F_1 ( V_18 , V_73 , V_3 ) ;
F_27 ( V_73 , V_79 , V_74 ) ;
F_5 ( V_18 ) ;
}
static int
F_28 ( struct V_6 * V_7 )
{
short V_18 = V_7 -> V_8 ;
if ( V_33 > 1 )
F_15 ( L_12 , V_7 -> V_16 ) ;
F_29 ( V_7 -> V_9 , V_7 ) ;
V_7 -> V_9 = V_37 . V_45 ;
F_3 ( V_18 + V_64 ) ;
F_4 ( 0 , V_18 + V_32 ) ;
F_3 ( V_18 + V_65 ) ;
F_4 ( 0 , V_18 + V_32 ) ;
F_30 ( V_7 ) ;
F_5 ( V_18 ) ;
return 0 ;
}
int T_2 F_31 ( void )
{
struct V_6 * V_7 ;
int V_80 , V_81 = 0 ;
for ( V_80 = 0 ; V_80 < V_82 ; V_80 ++ ) {
if ( V_83 [ V_80 ] == 0 ) {
if ( V_80 != 0 ) break;
F_15 ( V_84 L_13 ) ;
}
V_7 = F_9 () ;
if ( ! V_7 )
break;
V_7 -> V_9 = V_9 [ V_80 ] ;
V_7 -> V_8 = V_83 [ V_80 ] ;
V_7 -> V_48 = V_49 [ V_80 ] ;
V_7 -> V_46 = V_85 [ V_80 ] ;
if ( F_6 ( V_7 ) == 0 ) {
V_86 [ V_81 ++ ] = V_7 ;
continue;
}
F_12 ( V_7 ) ;
F_15 ( V_87 L_14 , V_83 [ V_80 ] ) ;
break;
}
if ( V_81 )
return 0 ;
return - V_10 ;
}
static void F_32 ( struct V_6 * V_7 )
{
F_33 ( V_37 . V_49 ) ;
F_22 ( V_7 -> V_8 , V_25 ) ;
}
void T_3
F_34 ( void )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_82 ; V_80 ++ ) {
struct V_6 * V_7 = V_86 [ V_80 ] ;
if ( V_7 ) {
F_35 ( V_7 ) ;
F_32 ( V_7 ) ;
F_12 ( V_7 ) ;
}
}
}
