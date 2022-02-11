static int T_1 F_1 ( struct V_1 * V_2 )
{
unsigned short V_3 = V_2 -> V_4 ;
int V_5 = V_2 -> V_5 ;
int V_6 = V_2 -> V_6 ;
if ( V_3 > 0x1ff )
return F_2 ( V_3 , V_2 ) ;
else if ( V_3 > 0 )
return - V_7 ;
if ( ! V_8 )
return - V_7 ;
for ( V_3 = 0x1000 ; V_3 < 0x9000 ; V_3 += 0x1000 ) {
if ( F_2 ( V_3 , V_2 ) == 0 )
return 0 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_6 ;
}
return - V_9 ;
}
struct V_1 * T_1 F_3 ( int V_10 )
{
struct V_1 * V_2 = F_4 () ;
int V_11 ;
if ( ! V_2 )
return F_5 ( - V_12 ) ;
sprintf ( V_2 -> V_13 , L_1 , V_10 ) ;
F_6 ( V_2 ) ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 )
goto V_14;
return V_2 ;
V_14:
F_7 ( V_2 ) ;
return F_5 ( V_11 ) ;
}
static int T_1 F_2 ( int V_3 , struct V_1 * V_2 )
{
int V_15 , V_16 ;
if ( ! F_8 ( V_3 , V_17 , V_18 ) )
return - V_19 ;
if ( F_9 ( V_3 + V_20 ) == 0xff ) {
V_16 = - V_9 ;
goto V_14;
}
if ( F_10 ( V_3 + V_20 ) != V_21 ) {
V_16 = - V_9 ;
goto V_14;
}
#ifndef F_11
F_12 ( V_22 L_2
L_3 , F_13 ( V_3 + V_23 ) ,
F_13 ( V_3 + V_20 + 0 ) , F_13 ( V_3 + V_20 + 1 ) ,
F_13 ( V_3 + V_20 + 2 ) , F_13 ( V_3 + V_20 + 3 ) ) ;
#endif
for ( V_15 = 0 ; V_15 < 6 ; V_15 ++ )
V_2 -> V_24 [ V_15 ] = F_13 ( V_3 + V_25 + V_15 ) ;
F_12 ( V_22 L_4 ,
V_3 / 0x1000 , V_2 -> V_24 ) ;
#if 0
if (inb(ioaddr + AC_SA_PROM + 0) != AC_ADDR0
|| inb(ioaddr + AC_SA_PROM + 1) != AC_ADDR1
|| inb(ioaddr + AC_SA_PROM + 2) != AC_ADDR2 ) {
printk(", not found (invalid prefix).\n");
retval = -ENODEV;
goto out;
}
#endif
if ( V_2 -> V_5 == 0 ) {
V_2 -> V_5 = F_14 ( F_13 ( V_3 + V_23 ) ) ;
F_12 ( L_5 ) ;
} else {
V_2 -> V_5 = F_15 ( V_2 -> V_5 ) ;
F_12 ( L_6 ) ;
}
V_16 = F_16 ( V_2 -> V_5 , V_26 , 0 , V_18 , V_2 ) ;
if ( V_16 ) {
F_12 ( L_7 , V_2 -> V_5 ) ;
goto V_14;
}
F_12 ( L_8 , V_2 -> V_5 , V_27 [ V_2 -> V_28 ] ) ;
V_2 -> V_4 = V_3 ;
#ifdef F_17
if ( V_2 -> V_6 ) {
for ( V_15 = 0 ; V_15 < 7 ; V_15 ++ )
if ( V_29 [ V_15 ] == V_2 -> V_6 )
break;
if ( V_15 >= 7 )
V_15 = 0 ;
F_18 ( ( F_13 ( V_3 + V_23 ) & ~ 7 ) | V_15 , V_3 + V_23 ) ;
}
#endif
V_2 -> V_28 = F_13 ( V_3 + V_23 ) >> 6 ;
V_2 -> V_6 = F_19 ( F_13 ( V_3 + V_23 ) ) ;
F_12 ( L_9 ,
V_2 -> V_13 , V_3 , V_30 / 4 , V_2 -> V_6 ) ;
V_31 . V_32 = F_20 ( V_2 -> V_6 , V_30 * 0x100 ) ;
if ( ! V_31 . V_32 ) {
F_12 ( V_33 L_10 ) ;
F_12 ( V_33 L_11 ) ;
F_12 ( V_33 L_12 ) ;
V_16 = - V_34 ;
goto V_35;
}
F_12 ( L_13 ,
V_30 / 4 , V_31 . V_32 ) ;
V_2 -> V_6 = ( unsigned long ) V_31 . V_32 ;
V_2 -> V_36 = V_2 -> V_6 + ( V_30 - V_37 ) * 256 ;
V_31 . V_13 = L_14 ;
V_31 . V_38 = V_37 ;
V_31 . V_39 = V_37 + V_40 ;
V_31 . V_41 = V_30 ;
V_31 . V_42 = 1 ;
if ( V_43 > 0 )
F_12 ( V_44 ) ;
V_31 . V_45 = & V_46 ;
V_31 . V_47 = & V_48 ;
V_31 . V_49 = & V_50 ;
V_31 . V_51 = & V_52 ;
V_2 -> V_53 = & V_54 ;
F_21 ( V_2 , 0 ) ;
V_16 = F_22 ( V_2 ) ;
if ( V_16 )
goto V_55;
return 0 ;
V_55:
if ( V_31 . V_56 )
F_23 ( V_31 . V_32 ) ;
V_35:
F_24 ( V_2 -> V_5 , V_2 ) ;
V_14:
F_25 ( V_3 , V_17 ) ;
return V_16 ;
}
static int F_26 ( struct V_1 * V_2 )
{
#ifdef F_17
int V_3 = V_2 -> V_4 ;
#endif
F_27 ( V_2 ) ;
return 0 ;
}
static void V_46 ( struct V_1 * V_2 )
{
T_2 V_3 = V_2 -> V_4 ;
F_18 ( V_57 , V_3 + V_58 ) ;
if ( V_43 > 1 ) F_12 ( L_15 , V_59 ) ;
V_31 . V_60 = 0 ;
F_18 ( V_61 , V_3 + V_58 ) ;
if ( V_43 > 1 ) F_12 ( L_16 ) ;
}
static void
V_52 ( struct V_1 * V_2 , struct V_62 * V_63 , int V_64 )
{
void T_3 * V_65 = V_31 . V_32 + ( ( V_64 - V_37 ) << 8 ) ;
F_28 ( V_63 , V_65 , sizeof( struct V_62 ) ) ;
}
static void V_48 ( struct V_1 * V_2 , int V_66 , struct V_67 * V_68 ,
int V_69 )
{
void T_3 * V_70 = V_31 . V_32 + V_69 - V_37 * 256 ;
if ( V_69 + V_66 > V_30 * 256 ) {
int V_71 = V_30 * 256 - V_69 ;
F_28 ( V_68 -> V_72 , V_70 , V_71 ) ;
V_66 -= V_71 ;
F_28 ( V_68 -> V_72 + V_71 ,
V_31 . V_32 + V_40 * 256 , V_66 ) ;
} else {
F_28 ( V_68 -> V_72 , V_70 , V_66 ) ;
}
}
static void V_50 ( struct V_1 * V_2 , int V_66 ,
const unsigned char * V_73 , int V_74 )
{
void T_3 * V_75 = V_31 . V_32 + ( ( V_74 - V_37 ) << 8 ) ;
F_29 ( V_75 , V_73 , V_66 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
if ( V_43 > 1 )
F_12 ( L_17 , V_2 -> V_13 ) ;
#ifdef F_17
F_18 ( 0x00 , V_3 + 6 ) ;
F_24 ( V_2 -> V_5 , V_2 ) ;
#endif
F_31 ( V_2 ) ;
return 0 ;
}
static int T_1 F_32 ( void )
{
struct V_1 * V_2 ;
int V_76 , V_77 = 0 ;
for ( V_76 = 0 ; V_76 < V_78 ; V_76 ++ ) {
if ( V_79 [ V_76 ] == 0 && V_76 != 0 )
break;
V_2 = F_4 () ;
if ( ! V_2 )
break;
V_2 -> V_5 = V_5 [ V_76 ] ;
V_2 -> V_4 = V_79 [ V_76 ] ;
V_2 -> V_6 = V_32 [ V_76 ] ;
if ( F_1 ( V_2 ) == 0 ) {
V_80 [ V_77 ++ ] = V_2 ;
continue;
}
F_7 ( V_2 ) ;
F_12 ( V_81 L_18 , V_79 [ V_76 ] ) ;
break;
}
if ( V_77 )
return 0 ;
return - V_7 ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_5 , V_2 ) ;
F_25 ( V_2 -> V_4 , V_17 ) ;
F_23 ( V_31 . V_32 ) ;
}
static void T_4 F_34 ( void )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_78 ; V_76 ++ ) {
struct V_1 * V_2 = V_80 [ V_76 ] ;
if ( V_2 ) {
F_35 ( V_2 ) ;
F_33 ( V_2 ) ;
F_7 ( V_2 ) ;
}
}
}
