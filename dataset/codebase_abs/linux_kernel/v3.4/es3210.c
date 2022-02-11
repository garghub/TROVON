static int T_1 F_1 ( struct V_1 * V_2 )
{
unsigned short V_3 = V_2 -> V_4 ;
int V_5 = V_2 -> V_5 ;
int V_6 = V_2 -> V_6 ;
if ( V_3 > 0x1ff )
return F_2 ( V_2 , V_3 ) ;
else if ( V_3 > 0 )
return - V_7 ;
if ( ! V_8 ) {
#if V_9 & V_10
F_3 ( L_1 ) ;
#endif
return - V_7 ;
}
for ( V_3 = 0x1000 ; V_3 < 0x9000 ; V_3 += 0x1000 ) {
if ( F_2 ( V_2 , V_3 ) == 0 )
return 0 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_6 ;
}
return - V_11 ;
}
struct V_1 * T_1 F_4 ( int V_12 )
{
struct V_1 * V_2 = F_5 () ;
int V_13 ;
if ( ! V_2 )
return F_6 ( - V_14 ) ;
sprintf ( V_2 -> V_15 , L_2 , V_12 ) ;
F_7 ( V_2 ) ;
V_13 = F_1 ( V_2 ) ;
if ( V_13 )
goto V_16;
return V_2 ;
V_16:
F_8 ( V_2 ) ;
return F_6 ( V_13 ) ;
}
static int T_1 F_2 ( struct V_1 * V_2 , int V_3 )
{
int V_17 , V_18 ;
unsigned long V_19 ;
if ( ! F_9 ( V_3 + V_20 , V_21 , L_3 ) )
return - V_11 ;
#if V_9 & V_10
F_3 ( L_4 , V_3 , F_10 ( V_3 + V_22 ) ) ;
F_3 ( L_5 ,
F_11 ( V_3 + V_23 ) , F_11 ( V_3 + V_24 ) , F_11 ( V_3 + V_25 ) ,
F_11 ( V_3 + V_26 ) , F_11 ( V_3 + V_27 ) , F_11 ( V_3 + V_28 ) ) ;
#endif
V_19 = F_10 ( V_3 + V_22 ) ;
if ( ( V_19 != V_29 ) && ( V_19 != V_30 ) ) {
V_18 = - V_11 ;
goto V_16;
}
for ( V_17 = 0 ; V_17 < V_31 ; V_17 ++ )
V_2 -> V_32 [ V_17 ] = F_11 ( V_3 + V_20 + V_17 ) ;
if ( V_2 -> V_32 [ 0 ] != V_33 ||
V_2 -> V_32 [ 1 ] != V_34 ||
V_2 -> V_32 [ 2 ] != V_35 ) {
F_3 ( L_6 ,
V_2 -> V_32 ) ;
V_18 = - V_11 ;
goto V_16;
}
F_3 ( L_7 ,
V_19 >> 24 , V_3 , V_2 -> V_32 ) ;
if ( V_2 -> V_5 == 0 ) {
unsigned char V_36 = F_11 ( V_3 + V_24 ) & 0x07 ;
unsigned char V_37 = F_11 ( V_3 + V_23 ) & 0xfe ;
if ( V_36 != 0 ) {
V_2 -> V_5 = V_38 [ V_36 - 1 ] ;
} else {
int V_17 = 0 ;
while ( V_37 > ( 1 << V_17 ) ) V_17 ++ ;
V_2 -> V_5 = V_39 [ V_17 ] ;
}
F_3 ( L_8 , V_2 -> V_5 ) ;
#if V_9 & V_10
F_3 ( L_9 ,
V_36 , V_37 , V_2 -> V_5 ) ;
#endif
} else {
if ( V_2 -> V_5 == 2 )
V_2 -> V_5 = 9 ;
F_3 ( L_10 , V_2 -> V_5 ) ;
}
if ( F_12 ( V_2 -> V_5 , V_40 , 0 , L_3 , V_2 ) ) {
F_3 ( L_11 , V_2 -> V_5 ) ;
V_18 = - V_41 ;
goto V_16;
}
if ( V_2 -> V_6 == 0 ) {
unsigned char V_42 = F_11 ( V_3 + V_24 ) & 0xc0 ;
unsigned char V_43 = F_11 ( V_3 + V_25 ) & 0x07 ;
if ( V_42 != 0x80 ) {
F_3 ( L_12 ) ;
V_18 = - V_7 ;
goto V_44;
}
V_2 -> V_6 = 0xC0000 + V_43 * 0x4000 ;
F_3 ( L_13 ) ;
} else {
F_3 ( L_14 ) ;
}
V_45 . V_46 = F_13 ( V_2 -> V_6 , ( V_47 - V_48 ) * 256 ) ;
if ( ! V_45 . V_46 ) {
F_3 ( L_15 ) ;
V_18 = - V_7 ;
goto V_44;
}
V_2 -> V_49 = V_2 -> V_6 + ( V_47 - V_48 ) * 256 ;
F_3 ( L_16 , V_2 -> V_6 , V_2 -> V_49 - 1 ) ;
#if V_9 & V_10
if ( F_11 ( V_3 + V_27 ) )
F_3 ( L_17 ) ;
#endif
V_2 -> V_4 = V_3 + V_50 ;
V_45 . V_15 = L_18 ;
V_45 . V_51 = V_48 ;
V_45 . V_52 = V_48 + V_53 ;
V_45 . V_54 = V_47 ;
V_45 . V_55 = 1 ;
if ( V_56 > 0 )
F_3 ( V_57 ) ;
V_45 . V_58 = & V_59 ;
V_45 . V_60 = & V_61 ;
V_45 . V_62 = & V_63 ;
V_45 . V_64 = & V_65 ;
V_2 -> V_66 = & V_67 ;
F_14 ( V_2 , 0 ) ;
V_18 = F_15 ( V_2 ) ;
if ( V_18 )
goto V_44;
return 0 ;
V_44:
F_16 ( V_2 -> V_5 , V_2 ) ;
V_16:
F_17 ( V_3 + V_20 , V_21 ) ;
return V_18 ;
}
static void V_59 ( struct V_1 * V_2 )
{
unsigned short V_3 = V_2 -> V_4 ;
unsigned long V_68 ;
F_18 ( 0x04 , V_3 + V_69 ) ;
if ( V_56 > 1 ) F_3 ( L_19 , V_2 -> V_15 ) ;
V_68 = V_70 + 2 * V_71 / 100 ;
while ( ( signed ) ( V_68 - V_70 ) > 0 ) continue;
V_45 . V_72 = 0 ;
F_18 ( 0x01 , V_3 + V_69 ) ;
if ( V_56 > 1 ) F_3 ( L_20 ) ;
}
static void
V_65 ( struct V_1 * V_2 , struct V_73 * V_74 , int V_75 )
{
void T_2 * V_76 = V_45 . V_46 + ( ( V_75 - V_48 ) << 8 ) ;
F_19 ( V_74 , V_76 , sizeof( struct V_73 ) ) ;
V_74 -> V_77 = ( V_74 -> V_77 + 3 ) & ~ 3 ;
}
static void V_61 ( struct V_1 * V_2 , int V_77 , struct V_78 * V_79 ,
int V_80 )
{
void T_2 * V_81 = V_45 . V_46 + V_80 - V_48 * 256 ;
if ( V_80 + V_77 > V_47 * 256 ) {
int V_82 = V_47 * 256 - V_80 ;
F_19 ( V_79 -> V_83 , V_81 , V_82 ) ;
V_77 -= V_82 ;
F_19 ( V_79 -> V_83 + V_82 , V_45 . V_46 , V_77 ) ;
} else {
F_19 ( V_79 -> V_83 , V_81 , V_77 ) ;
}
}
static void V_63 ( struct V_1 * V_2 , int V_77 ,
const unsigned char * V_84 , int V_85 )
{
void T_2 * V_86 = V_45 . V_46 + ( ( V_85 - V_48 ) << 8 ) ;
V_77 = ( V_77 + 3 ) & ~ 3 ;
F_20 ( V_86 , V_84 , V_77 ) ;
}
int T_1 F_21 ( void )
{
struct V_1 * V_2 ;
int V_87 , V_88 = 0 ;
for ( V_87 = 0 ; V_87 < V_89 ; V_87 ++ ) {
if ( V_90 [ V_87 ] == 0 && V_87 != 0 )
break;
V_2 = F_5 () ;
if ( ! V_2 )
break;
V_2 -> V_5 = V_5 [ V_87 ] ;
V_2 -> V_4 = V_90 [ V_87 ] ;
V_2 -> V_6 = V_46 [ V_87 ] ;
if ( F_1 ( V_2 ) == 0 ) {
V_91 [ V_88 ++ ] = V_2 ;
continue;
}
F_8 ( V_2 ) ;
F_3 ( V_92 L_21 , V_90 [ V_87 ] ) ;
break;
}
if ( V_88 )
return 0 ;
return - V_7 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_5 , V_2 ) ;
F_17 ( V_2 -> V_4 , V_21 ) ;
F_23 ( V_45 . V_46 ) ;
}
void T_3
F_24 ( void )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < V_89 ; V_87 ++ ) {
struct V_1 * V_2 = V_91 [ V_87 ] ;
if ( V_2 ) {
F_25 ( V_2 ) ;
F_22 ( V_2 ) ;
F_8 ( V_2 ) ;
}
}
}
