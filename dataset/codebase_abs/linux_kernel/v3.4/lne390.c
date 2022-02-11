static int T_1 F_1 ( struct V_1 * V_2 )
{
unsigned short V_3 = V_2 -> V_4 ;
int V_5 = V_2 -> V_5 ;
int V_6 = V_2 -> V_6 ;
int V_7 ;
if ( V_3 > 0x1ff ) {
if ( ! F_2 ( V_3 , V_8 , V_9 ) )
return - V_10 ;
V_7 = F_3 ( V_2 , V_3 ) ;
if ( V_7 )
F_4 ( V_3 , V_8 ) ;
return V_7 ;
}
else if ( V_3 > 0 )
return - V_11 ;
if ( ! V_12 ) {
#if V_13 & V_14
F_5 ( L_1 ) ;
#endif
return - V_11 ;
}
for ( V_3 = 0x1000 ; V_3 < 0x9000 ; V_3 += 0x1000 ) {
if ( ! F_2 ( V_3 , V_8 , V_9 ) )
continue;
if ( F_3 ( V_2 , V_3 ) == 0 )
return 0 ;
F_4 ( V_3 , V_8 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_6 ;
}
return - V_15 ;
}
struct V_1 * T_1 F_6 ( int V_16 )
{
struct V_1 * V_2 = F_7 () ;
int V_17 ;
if ( ! V_2 )
return F_8 ( - V_18 ) ;
sprintf ( V_2 -> V_19 , L_2 , V_16 ) ;
F_9 ( V_2 ) ;
V_17 = F_1 ( V_2 ) ;
if ( V_17 )
goto V_20;
return V_2 ;
V_20:
F_10 ( V_2 ) ;
return F_8 ( V_17 ) ;
}
static int T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
int V_21 , V_22 , V_7 ;
unsigned long V_23 ;
if ( F_11 ( V_3 + V_24 ) == 0xff ) return - V_15 ;
#if V_13 & V_14
F_5 ( L_3 , V_3 , F_12 ( V_3 + V_24 ) ) ;
F_5 ( L_4 ,
F_13 ( V_3 + V_25 ) , F_13 ( V_3 + V_26 ) ) ;
#endif
V_23 = F_12 ( V_3 + V_24 ) ;
if ( ( V_23 != V_27 ) && ( V_23 != V_28 ) ) {
return - V_15 ;
}
V_22 = ( V_23 >> 24 ) & 0x01 ;
#if 0
if (inb(ioaddr + LNE390_SA_PROM + 0) != LNE390_ADDR0
|| inb(ioaddr + LNE390_SA_PROM + 1) != LNE390_ADDR1
|| inb(ioaddr + LNE390_SA_PROM + 2) != LNE390_ADDR2 ) {
printk("lne390.c: card not found");
for (i = 0; i < ETH_ALEN; i++)
printk(" %02x", inb(ioaddr + LNE390_SA_PROM + i));
printk(" (invalid prefix).\n");
return -ENODEV;
}
#endif
for ( V_21 = 0 ; V_21 < V_29 ; V_21 ++ )
V_2 -> V_30 [ V_21 ] = F_13 ( V_3 + V_31 + V_21 ) ;
F_5 ( L_5 ,
0xa + V_22 , V_3 / 0x1000 , V_2 -> V_30 ) ;
F_5 ( L_6 ) ;
if ( V_2 -> V_5 == 0 ) {
unsigned char V_32 = F_13 ( V_3 + V_26 ) >> 3 ;
V_2 -> V_5 = V_33 [ V_32 & 0x07 ] ;
F_5 ( L_7 ) ;
} else {
if ( V_2 -> V_5 == 2 ) V_2 -> V_5 = 9 ;
F_5 ( L_8 ) ;
}
F_5 ( L_9 , V_2 -> V_5 ) ;
if ( ( V_7 = F_14 ( V_2 -> V_5 , V_34 , 0 , V_9 , V_2 ) ) ) {
F_5 ( L_10 , V_2 -> V_5 ) ;
return V_7 ;
}
if ( V_2 -> V_6 == 0 ) {
unsigned char V_35 = F_13 ( V_3 + V_26 ) & 0x07 ;
if ( V_22 )
V_2 -> V_6 = V_36 [ V_35 ] * 0x10000 ;
else
V_2 -> V_6 = V_37 [ V_35 ] * 0x10000 ;
F_5 ( L_11 ) ;
} else {
V_2 -> V_6 &= 0xfff0000 ;
F_5 ( L_12 ) ;
}
F_5 ( L_13 ,
V_38 / 4 , V_2 -> V_6 ) ;
V_39 . V_40 = F_15 ( V_2 -> V_6 , V_38 * 0x100 ) ;
if ( ! V_39 . V_40 ) {
F_5 ( V_41 L_14 ) ;
F_5 ( V_41 L_15 ) ;
F_5 ( V_41 L_16 ) ;
V_7 = - V_42 ;
goto V_43;
}
F_5 ( L_17 ,
V_38 / 4 , V_39 . V_40 ) ;
V_2 -> V_6 = ( unsigned long ) V_39 . V_40 ;
V_2 -> V_44 = V_2 -> V_6 + ( V_38 - V_45 ) * 256 ;
V_2 -> V_4 = V_3 ;
V_39 . V_19 = L_18 ;
V_39 . V_46 = V_45 ;
V_39 . V_47 = V_45 + V_48 ;
V_39 . V_49 = V_38 ;
V_39 . V_50 = 1 ;
if ( V_51 > 0 )
F_5 ( V_52 ) ;
V_39 . V_53 = & V_54 ;
V_39 . V_55 = & V_56 ;
V_39 . V_57 = & V_58 ;
V_39 . V_59 = & V_60 ;
V_2 -> V_61 = & V_62 ;
F_16 ( V_2 , 0 ) ;
V_7 = F_17 ( V_2 ) ;
if ( V_7 )
goto V_63;
return 0 ;
V_63:
if ( V_39 . V_64 )
F_18 ( V_39 . V_40 ) ;
V_43:
F_19 ( V_2 -> V_5 , V_2 ) ;
return V_7 ;
}
static void V_54 ( struct V_1 * V_2 )
{
unsigned short V_3 = V_2 -> V_4 ;
F_20 ( 0x04 , V_3 + V_65 ) ;
if ( V_51 > 1 ) F_5 ( L_19 , V_2 -> V_19 ) ;
F_21 ( 2 ) ;
V_39 . V_66 = 0 ;
F_20 ( 0x01 , V_3 + V_65 ) ;
if ( V_51 > 1 ) F_5 ( L_20 ) ;
}
static void
V_60 ( struct V_1 * V_2 , struct V_67 * V_68 , int V_69 )
{
void T_2 * V_70 = V_39 . V_40 + ( ( V_69 - V_45 ) << 8 ) ;
F_22 ( V_68 , V_70 , sizeof( struct V_67 ) ) ;
V_68 -> V_71 = ( V_68 -> V_71 + 3 ) & ~ 3 ;
}
static void V_56 ( struct V_1 * V_2 , int V_71 , struct V_72 * V_73 ,
int V_74 )
{
void T_2 * V_75 = V_39 . V_40 + V_74 - ( V_45 << 8 ) ;
if ( V_74 + V_71 > ( V_38 << 8 ) ) {
int V_76 = ( V_38 << 8 ) - V_74 ;
F_22 ( V_73 -> V_77 , V_75 , V_76 ) ;
V_71 -= V_76 ;
F_22 ( V_73 -> V_77 + V_76 ,
V_39 . V_40 + ( V_48 << 8 ) , V_71 ) ;
} else {
F_22 ( V_73 -> V_77 , V_75 , V_71 ) ;
}
}
static void V_58 ( struct V_1 * V_2 , int V_71 ,
const unsigned char * V_78 , int V_79 )
{
void T_2 * V_80 = V_39 . V_40 + ( ( V_79 - V_45 ) << 8 ) ;
V_71 = ( V_71 + 3 ) & ~ 3 ;
F_23 ( V_80 , V_78 , V_71 ) ;
}
int T_1 F_24 ( void )
{
struct V_1 * V_2 ;
int V_81 , V_82 = 0 ;
for ( V_81 = 0 ; V_81 < V_83 ; V_81 ++ ) {
if ( V_84 [ V_81 ] == 0 && V_81 != 0 )
break;
V_2 = F_7 () ;
if ( ! V_2 )
break;
V_2 -> V_5 = V_5 [ V_81 ] ;
V_2 -> V_4 = V_84 [ V_81 ] ;
V_2 -> V_6 = V_40 [ V_81 ] ;
if ( F_1 ( V_2 ) == 0 ) {
V_85 [ V_82 ++ ] = V_2 ;
continue;
}
F_10 ( V_2 ) ;
F_5 ( V_86 L_21 , V_84 [ V_81 ] ) ;
break;
}
if ( V_82 )
return 0 ;
return - V_11 ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_19 ( V_2 -> V_5 , V_2 ) ;
F_4 ( V_2 -> V_4 , V_8 ) ;
F_18 ( V_39 . V_40 ) ;
}
void T_3 F_26 ( void )
{
int V_81 ;
for ( V_81 = 0 ; V_81 < V_83 ; V_81 ++ ) {
struct V_1 * V_2 = V_85 [ V_81 ] ;
if ( V_2 ) {
F_27 ( V_2 ) ;
F_25 ( V_2 ) ;
F_10 ( V_2 ) ;
}
}
}
