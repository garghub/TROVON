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
int V_3 , V_15 , V_16 , V_17 ;
const char * V_12 ;
static unsigned V_18 ;
if ( ! F_8 ( V_14 , V_19 , V_20 ) )
return - V_21 ;
if ( F_9 ( V_14 ) != 0x08
|| F_9 ( V_14 + 1 ) != 0x00
|| F_9 ( V_14 + 2 ) != 0x09
|| F_9 ( V_14 + 14 ) == 0x57 ) {
V_15 = - V_8 ;
goto V_13;
}
if ( ( V_16 = F_9 ( V_14 + V_22 ) ) & 0x80 ) {
V_12 = L_2 ;
V_17 = 1 ;
} else {
V_12 = L_3 ;
V_17 = 0 ;
}
if ( V_23 && V_18 ++ == 0 )
F_10 ( V_24 ) ;
F_10 ( L_4 , V_2 -> V_12 , V_12 , V_16 , V_14 ) ;
for( V_3 = 0 ; V_3 < V_25 ; V_3 ++ )
V_2 -> V_26 [ V_3 ] = F_9 ( V_14 + V_3 ) ;
F_10 ( L_5 , V_2 -> V_26 ) ;
if ( V_2 -> V_5 < 2 ) {
static const int V_27 [] = { 11 , 10 , 5 , 3 , 4 , 7 , 9 , 0 } ;
static const int V_28 [] = { 7 , 5 , 3 , 4 , 9 , 0 } ;
const int * V_29 = V_17 ? V_27 : V_28 ;
do {
int V_5 = * V_29 ;
if ( F_11 ( V_5 , NULL , 0 , L_6 , NULL ) != - V_21 ) {
unsigned long V_30 = F_12 () ;
F_13 ( V_31 [ V_5 ] | V_32 , V_14 + V_33 ) ;
F_13 ( 0x00 | V_32 , V_14 + V_33 ) ;
if ( V_5 == F_14 ( V_30 )
&& F_11 ( V_5 , V_34 , 0 , V_20 , V_2 ) == 0 ) {
F_10 ( L_7 , V_5 ) ;
V_2 -> V_5 = * V_29 ;
break;
}
}
} while ( * ++ V_29 );
if ( * V_29 == 0 ) {
F_10 ( L_8 ) ;
V_15 = - V_21 ;
goto V_13;
}
} else {
if ( V_2 -> V_5 == 2 )
V_2 -> V_5 = 9 ;
if ( ( V_15 = F_11 ( V_2 -> V_5 , V_34 , 0 , V_20 , V_2 ) ) ) {
F_10 ( L_9 , V_2 -> V_5 ) ;
goto V_13;
}
}
V_2 -> V_4 = V_14 + V_35 ;
V_2 -> V_36 = & V_37 ;
V_38 . V_12 = V_12 ;
V_38 . V_39 = V_17 ;
V_38 . V_40 = V_41 ;
V_38 . V_42 = V_41 + V_43 ;
V_38 . V_44 = V_17 ? V_45 : V_46 ;
V_38 . V_47 = V_48 ;
V_38 . V_49 = V_50 ;
V_38 . V_51 = V_52 ;
V_38 . V_53 = V_54 ;
F_15 ( V_2 ) ;
V_15 = F_16 ( V_2 ) ;
if ( V_15 )
goto V_55;
return 0 ;
V_55:
F_17 ( V_2 -> V_5 , V_2 ) ;
V_13:
F_18 ( V_14 , V_19 ) ;
return V_15 ;
}
static void
V_48 ( struct V_1 * V_2 )
{
int V_56 = V_2 -> V_4 - V_35 ;
int V_57 = F_19 ( V_56 + V_33 ) ;
if ( V_23 > 1 ) F_10 ( L_10 , V_58 ) ;
F_13 ( 0x00 , V_56 + V_33 ) ;
V_38 . V_59 = 0 ;
F_20 ( 5 ) ;
F_13 ( V_57 , V_56 + V_33 ) ;
F_20 ( 5 ) ;
if ( ( F_19 ( V_56 + V_35 + V_60 ) & V_61 ) == 0 )
F_10 ( L_11 , V_2 -> V_12 ) ;
if ( V_23 > 1 ) F_10 ( L_12 , V_58 ) ;
}
static void
V_50 ( struct V_1 * V_2 , struct V_62 * V_63 , int V_64 )
{
int V_65 = V_2 -> V_4 ;
int V_57 = F_19 ( V_65 - V_35 + V_33 ) ;
F_13 ( V_57 | V_66 , V_65 - V_35 + V_33 ) ;
F_13 ( V_67 + V_68 + V_69 , V_65 ) ;
F_13 ( sizeof( struct V_62 ) , V_65 + V_70 ) ;
F_13 ( 0 , V_65 + V_71 ) ;
F_13 ( 0 , V_65 + V_72 ) ;
F_13 ( V_64 , V_65 + V_73 ) ;
F_13 ( V_74 + V_69 , V_65 ) ;
if ( V_38 . V_39 )
F_21 ( V_65 - V_35 + V_75 , V_63 , sizeof( struct V_62 ) >> 1 ) ;
else
F_22 ( V_65 - V_35 + V_75 , V_63 , sizeof( struct V_62 ) ) ;
F_13 ( V_57 & ( ~ V_66 ) , V_65 - V_35 + V_33 ) ;
}
static void
V_52 ( struct V_1 * V_2 , int V_76 , struct V_77 * V_78 , int V_79 )
{
int V_65 = V_2 -> V_4 ;
int V_57 = F_19 ( V_65 - V_35 + V_33 ) ;
int V_80 = V_76 ;
char * V_81 = V_78 -> V_82 ;
F_13 ( V_57 | V_66 , V_65 - V_35 + V_33 ) ;
F_13 ( V_67 + V_68 + V_69 , V_65 ) ;
F_13 ( V_76 & 0xff , V_65 + V_70 ) ;
F_13 ( V_76 >> 8 , V_65 + V_71 ) ;
F_13 ( V_79 & 0xff , V_65 + V_72 ) ;
F_13 ( V_79 >> 8 , V_65 + V_73 ) ;
F_13 ( V_74 + V_69 , V_65 ) ;
if ( V_38 . V_39 ) {
F_21 ( V_65 - V_35 + V_75 , V_81 , V_76 >> 1 ) ;
if ( V_76 & 0x01 )
V_81 [ V_76 - 1 ] = F_9 ( V_65 - V_35 + V_75 ) , V_80 ++ ;
} else {
F_22 ( V_65 - V_35 + V_75 , V_81 , V_76 ) ;
}
if ( V_23 > 0 ) {
int V_83 = F_19 ( V_65 + V_73 ) ;
int V_84 = F_19 ( V_65 + V_72 ) ;
int V_85 = ( V_83 << 8 ) + V_84 ;
if ( ( ( V_79 + V_80 ) & 0xff ) != ( V_85 & 0xff ) )
F_10 ( L_13 ,
V_2 -> V_12 , V_79 + V_80 , V_85 ) ;
}
F_13 ( V_57 & ( ~ V_66 ) , V_65 - V_35 + V_33 ) ;
}
static void
V_54 ( struct V_1 * V_2 , int V_76 ,
const unsigned char * V_81 , int V_86 )
{
int V_65 = V_2 -> V_4 ;
int V_57 = F_19 ( V_65 - V_35 + V_33 ) ;
F_13 ( V_57 | V_66 , V_65 - V_35 + V_33 ) ;
if ( V_38 . V_39 && ( V_76 & 0x01 ) )
V_76 ++ ;
F_13 ( V_68 + V_69 + V_67 , V_65 ) ;
#ifdef F_23
F_13 ( 0x42 , V_65 + V_70 ) ;
F_13 ( 0 , V_65 + V_71 ) ;
F_13 ( 0xff , V_65 + V_72 ) ;
F_13 ( 0x00 , V_65 + V_73 ) ;
#define F_24 0x00
F_13 ( V_74 + V_69 , V_65 + F_24 ) ;
F_19 ( 0x61 ) ;
F_19 ( 0x61 ) ;
#endif
F_13 ( V_76 & 0xff , V_65 + V_70 ) ;
F_13 ( V_76 >> 8 , V_65 + V_71 ) ;
F_13 ( 0x00 , V_65 + V_72 ) ;
F_13 ( V_86 , V_65 + V_73 ) ;
F_13 ( V_87 + V_69 , V_65 ) ;
if ( V_38 . V_39 ) {
F_25 ( V_65 - V_35 + V_75 , V_81 , V_76 >> 1 ) ;
} else {
F_26 ( V_65 - V_35 + V_75 , V_81 , V_76 ) ;
}
if ( V_23 > 0 ) {
int V_83 = F_19 ( V_65 + V_73 ) ;
int V_84 = F_19 ( V_65 + V_72 ) ;
int V_85 = ( V_83 << 8 ) + V_84 ;
if ( ( V_86 << 8 ) + V_76 != V_85 )
F_10 ( L_14 ,
V_2 -> V_12 , ( V_86 << 8 ) + V_76 , V_85 ) ;
}
F_13 ( V_57 & ( ~ V_66 ) , V_65 - V_35 + V_33 ) ;
}
static void T_1
F_15 ( struct V_1 * V_2 )
{
int V_5 = V_2 -> V_5 ;
F_27 ( V_2 , 0 ) ;
F_13 ( V_31 [ V_5 & 0x0f ] | V_32 ,
V_2 -> V_4 - V_35 + V_33 ) ;
}
int T_1
F_28 ( void )
{
struct V_1 * V_2 ;
int V_88 , V_89 = 0 ;
for ( V_88 = 0 ; V_88 < V_90 ; V_88 ++ ) {
if ( V_91 [ V_88 ] == 0 ) {
if ( V_88 != 0 ) break;
F_10 ( V_92 L_15 ) ;
}
V_2 = F_4 () ;
if ( ! V_2 )
break;
V_2 -> V_5 = V_5 [ V_88 ] ;
V_2 -> V_4 = V_91 [ V_88 ] ;
if ( F_1 ( V_2 ) == 0 ) {
V_93 [ V_89 ++ ] = V_2 ;
continue;
}
F_7 ( V_2 ) ;
F_10 ( V_94 L_16 , V_91 [ V_88 ] ) ;
break;
}
if ( V_89 )
return 0 ;
return - V_6 ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_5 , V_2 ) ;
F_18 ( V_2 -> V_4 - V_35 , V_19 ) ;
}
void T_2
F_30 ( void )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_90 ; V_88 ++ ) {
struct V_1 * V_2 = V_93 [ V_88 ] ;
if ( V_2 ) {
F_31 ( V_2 ) ;
F_29 ( V_2 ) ;
F_7 ( V_2 ) ;
}
}
}
