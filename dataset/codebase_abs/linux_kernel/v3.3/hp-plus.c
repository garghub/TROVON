static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = V_2 -> V_4 ;
int V_5 = V_2 -> V_5 ;
if ( V_4 > 0x1ff )
return F_2 ( V_2 , V_4 ) ;
else if ( V_4 != 0 )
return - V_6 ;
for ( V_3 = 0 ; V_7 [ V_3 ] ; V_3 ++ ) {
if ( F_2 ( V_2 , V_7 [ V_3 ] ) == 0 )
return 0 ;
V_2 -> V_5 = V_5 ;
}
return - V_8 ;
}
struct V_1 * T_1 F_3 ( int V_9 )
{
struct V_1 * V_2 = F_4 () ;
int V_10 ;
if ( ! V_2 )
return F_5 ( - V_11 ) ;
sprintf ( V_2 -> V_12 , L_1 , V_9 ) ;
F_6 ( V_2 ) ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 )
goto V_13;
return V_2 ;
V_13:
F_7 ( V_2 ) ;
return F_5 ( V_10 ) ;
}
static int T_1 F_2 ( struct V_1 * V_2 , int V_14 )
{
int V_3 , V_15 ;
unsigned char V_16 = 0 ;
const char V_12 [] = L_2 ;
int V_17 ;
static unsigned V_18 ;
if ( ! F_8 ( V_14 , V_19 , V_20 ) )
return - V_21 ;
if ( F_9 ( V_14 + V_22 ) != 0x4850 ||
( F_9 ( V_14 + V_23 ) & 0xfff0 ) != 0x5300 ) {
V_15 = - V_8 ;
goto V_13;
}
if ( V_24 && V_18 ++ == 0 )
F_10 ( V_25 ) ;
F_10 ( L_3 , V_2 -> V_12 , V_12 , V_14 ) ;
F_11 ( V_26 , V_14 + V_23 ) ;
for( V_3 = 0 ; V_3 < V_27 ; V_3 ++ ) {
unsigned char V_28 = F_12 ( V_14 + 8 + V_3 ) ;
V_2 -> V_29 [ V_3 ] = V_28 ;
V_16 += V_28 ;
}
V_16 += F_12 ( V_14 + 14 ) ;
F_10 ( L_4 , V_2 -> V_29 ) ;
if ( V_16 != 0xff ) {
F_10 ( L_5 , V_16 ) ;
V_15 = - V_8 ;
goto V_13;
} else {
F_11 ( V_30 , V_14 + V_23 ) ;
F_10 ( L_6 , F_9 ( V_14 + 12 ) ) ;
}
F_11 ( V_31 , V_14 + V_23 ) ;
{
int V_5 = F_12 ( V_14 + 13 ) & 0x0f ;
int V_32 = F_9 ( V_14 + V_33 ) ;
V_2 -> V_5 = V_5 ;
if ( V_32 & V_34 ) {
V_17 = F_9 ( V_14 + 9 ) << 8 ;
F_10 ( L_7 , V_5 , V_17 ) ;
} else {
V_17 = 0 ;
F_10 ( L_8 , V_5 ) ;
}
}
F_11 ( ( V_35 + V_36 / 2 ) | ( ( V_37 - 1 ) << 8 ) , V_14 + 14 ) ;
V_2 -> V_4 = V_14 + V_38 ;
V_2 -> V_39 = & V_40 ;
V_41 . V_12 = V_12 ;
V_41 . V_42 = 0 ;
V_41 . V_43 = V_35 ;
V_41 . V_44 = V_35 + V_36 / 2 ;
V_41 . V_45 = V_37 ;
V_41 . V_46 = & V_47 ;
V_41 . V_48 = & V_49 ;
V_41 . V_50 = & V_51 ;
V_41 . V_52 = & V_53 ;
if ( V_17 ) {
V_41 . V_48 = & V_54 ;
V_41 . V_50 = & V_55 ;
V_41 . V_52 = & V_56 ;
V_2 -> V_17 = V_17 ;
V_41 . V_57 = F_13 ( V_17 ,
( V_37 - V_35 ) * 256 ) ;
if ( ! V_41 . V_57 ) {
V_15 = - V_11 ;
goto V_13;
}
V_41 . V_58 = V_2 -> V_17 + V_36 / 2 * 256 ;
V_2 -> V_59 = V_41 . V_60
= V_2 -> V_17 + ( V_37 - V_35 ) * 256 ;
}
F_11 ( V_61 , V_14 + V_23 ) ;
F_14 ( V_2 , 0 ) ;
F_11 ( F_9 ( V_14 + V_33 ) & ~ V_62 , V_14 + V_33 ) ;
V_15 = F_15 ( V_2 ) ;
if ( V_15 )
goto V_63;
return 0 ;
V_63:
F_16 ( V_41 . V_57 ) ;
V_13:
F_17 ( V_14 , V_19 ) ;
return V_15 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_14 = V_2 -> V_4 - V_38 ;
int V_64 ;
int V_15 ;
if ( ( V_15 = F_19 ( V_2 -> V_5 , V_65 , 0 , V_2 -> V_12 , V_2 ) ) ) {
return V_15 ;
}
V_64 = F_9 ( V_14 + V_33 ) ;
F_11 ( V_64 & ~ ( V_66 + V_67 ) , V_14 + V_33 ) ;
F_20 ( 5 ) ;
F_11 ( V_64 | ( V_62 + V_66 + V_67 ) , V_14 + V_33 ) ;
F_11 ( V_31 , V_14 + V_23 ) ;
F_11 ( ( V_35 + V_36 / 2 ) | ( ( V_37 - 1 ) << 8 ) , V_14 + 14 ) ;
F_11 ( V_61 , V_14 + V_23 ) ;
return F_21 ( V_2 ) ;
}
static int
F_22 ( struct V_1 * V_2 )
{
int V_14 = V_2 -> V_4 - V_38 ;
int V_64 = F_9 ( V_14 + V_33 ) ;
F_23 ( V_2 -> V_5 , V_2 ) ;
F_24 ( V_2 ) ;
F_11 ( ( V_64 & ~ V_62 ) | V_68 | V_66 | V_67 ,
V_14 + V_33 ) ;
return 0 ;
}
static void
V_47 ( struct V_1 * V_2 )
{
int V_14 = V_2 -> V_4 - V_38 ;
int V_64 = F_9 ( V_14 + V_33 ) ;
if ( V_24 > 1 ) F_10 ( L_9 , V_69 ) ;
F_11 ( V_64 & ~ ( V_66 + V_67 ) , V_14 + V_33 ) ;
F_20 ( 5 ) ;
V_41 . V_70 = 0 ;
F_11 ( V_64 | ( V_62 + V_66 + V_67 ) , V_14 + V_33 ) ;
F_20 ( 5 ) ;
if ( ( F_25 ( V_14 + V_38 + V_71 ) & V_72 ) == 0 )
F_10 ( L_10 , V_2 -> V_12 ) ;
if ( V_24 > 1 ) F_10 ( L_11 , V_69 ) ;
}
static void
V_53 ( struct V_1 * V_2 , struct V_73 * V_74 , int V_75 )
{
int V_14 = V_2 -> V_4 - V_38 ;
F_11 ( ( V_75 << 8 ) , V_14 + V_76 ) ;
F_26 ( V_14 + V_77 , V_74 , sizeof( struct V_73 ) >> 1 ) ;
}
static void
V_49 ( struct V_1 * V_2 , int V_78 , struct V_79 * V_80 , int V_81 )
{
int V_14 = V_2 -> V_4 - V_38 ;
char * V_82 = V_80 -> V_83 ;
F_11 ( V_81 , V_14 + V_76 ) ;
F_26 ( V_14 + V_77 , V_82 , V_78 >> 1 ) ;
if ( V_78 & 0x01 )
V_82 [ V_78 - 1 ] = F_9 ( V_14 + V_77 ) ;
}
static void
V_56 ( struct V_1 * V_2 , struct V_73 * V_74 , int V_75 )
{
int V_14 = V_2 -> V_4 - V_38 ;
int V_64 = F_9 ( V_14 + V_33 ) ;
F_11 ( ( V_75 << 8 ) , V_14 + V_76 ) ;
F_11 ( V_64 & ~ ( V_68 + V_84 ) , V_14 + V_33 ) ;
F_27 ( V_74 , V_41 . V_57 , sizeof( struct V_73 ) ) ;
F_11 ( V_64 , V_14 + V_33 ) ;
V_74 -> V_78 = ( F_28 ( V_74 -> V_78 ) + 3 ) & ~ 3 ;
}
static void
V_54 ( struct V_1 * V_2 , int V_78 , struct V_79 * V_80 , int V_81 )
{
int V_14 = V_2 -> V_4 - V_38 ;
int V_64 = F_9 ( V_14 + V_33 ) ;
F_11 ( V_81 , V_14 + V_76 ) ;
F_11 ( V_64 & ~ ( V_68 + V_84 ) , V_14 + V_33 ) ;
F_27 ( V_80 -> V_83 , V_41 . V_57 , V_78 ) ;
F_11 ( V_64 , V_14 + V_33 ) ;
}
static void
V_51 ( struct V_1 * V_2 , int V_78 ,
const unsigned char * V_82 , int V_85 )
{
int V_14 = V_2 -> V_4 - V_38 ;
F_11 ( V_85 << 8 , V_14 + V_86 ) ;
F_29 ( V_14 + V_77 , V_82 , ( V_78 + 3 ) >> 2 ) ;
}
static void
V_55 ( struct V_1 * V_2 , int V_78 ,
const unsigned char * V_82 , int V_85 )
{
int V_14 = V_2 -> V_4 - V_38 ;
int V_64 = F_9 ( V_14 + V_33 ) ;
F_11 ( V_85 << 8 , V_14 + V_86 ) ;
F_11 ( V_64 & ~ ( V_68 + V_84 ) , V_14 + V_33 ) ;
F_30 ( V_41 . V_57 , V_82 , ( V_78 + 3 ) & ~ 3 ) ;
F_11 ( V_64 , V_14 + V_33 ) ;
}
int T_1
F_31 ( void )
{
struct V_1 * V_2 ;
int V_87 , V_88 = 0 ;
for ( V_87 = 0 ; V_87 < V_89 ; V_87 ++ ) {
if ( V_90 [ V_87 ] == 0 ) {
if ( V_87 != 0 ) break;
F_10 ( V_91 L_12 ) ;
}
V_2 = F_4 () ;
if ( ! V_2 )
break;
V_2 -> V_5 = V_5 [ V_87 ] ;
V_2 -> V_4 = V_90 [ V_87 ] ;
if ( F_1 ( V_2 ) == 0 ) {
V_92 [ V_88 ++ ] = V_2 ;
continue;
}
F_7 ( V_2 ) ;
F_10 ( V_93 L_13 , V_90 [ V_87 ] ) ;
break;
}
if ( V_88 )
return 0 ;
return - V_6 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_16 ( V_41 . V_57 ) ;
F_17 ( V_2 -> V_4 - V_38 , V_19 ) ;
}
void T_2
F_33 ( void )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < V_89 ; V_87 ++ ) {
struct V_1 * V_2 = V_92 [ V_87 ] ;
if ( V_2 ) {
F_34 ( V_2 ) ;
F_32 ( V_2 ) ;
F_7 ( V_2 ) ;
}
}
}
