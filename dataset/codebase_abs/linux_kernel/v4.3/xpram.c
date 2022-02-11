static int F_1 ( unsigned long V_1 , unsigned int V_2 )
{
int V_3 = 2 ;
asm volatile(
" .insn rre,0xb22e0000,%1,%2\n"
"0: ipm %0\n"
" srl %0,28\n"
"1:\n"
EX_TABLE(0b,1b)
: "+d" (cc) : "a" (__pa(page_addr)), "d" (xpage_index) : "cc");
if ( V_3 == 3 )
return - V_4 ;
if ( V_3 == 2 )
return - V_4 ;
if ( V_3 == 1 )
return - V_5 ;
return 0 ;
}
static long F_2 ( unsigned long V_1 , unsigned int V_2 )
{
int V_3 = 2 ;
asm volatile(
" .insn rre,0xb22f0000,%1,%2\n"
"0: ipm %0\n"
" srl %0,28\n"
"1:\n"
EX_TABLE(0b,1b)
: "+d" (cc) : "a" (__pa(page_addr)), "d" (xpage_index) : "cc");
if ( V_3 == 3 )
return - V_4 ;
if ( V_3 == 2 )
return - V_4 ;
if ( V_3 == 1 )
return - V_5 ;
return 0 ;
}
static int F_3 ( void )
{
unsigned long V_6 ;
int V_7 ;
V_6 = ( unsigned long ) F_4 ( V_8 ) ;
if ( ! V_6 )
return - V_9 ;
V_7 = F_1 ( V_6 , 0 ) ;
F_5 ( V_6 ) ;
return V_7 ? - V_4 : 0 ;
}
static unsigned long F_6 ( void )
{
unsigned int V_10 , V_11 ;
unsigned long V_6 ;
V_6 = ( unsigned long ) F_4 ( V_8 ) ;
if ( ! V_6 )
return 0 ;
V_10 = 0 ;
V_11 = 1ULL << (sizeof( unsigned int ) * 8 - 1 ) ;
while ( V_11 > 0 ) {
if ( F_1 ( V_6 , V_10 | V_11 ) == 0 )
V_10 |= V_11 ;
V_11 >>= 1 ;
}
F_5 ( V_6 ) ;
return V_10 ;
}
static void F_7 ( struct V_12 * V_13 , struct V_14 * V_14 )
{
T_1 * V_15 = V_14 -> V_16 -> V_17 -> V_18 ;
struct V_19 V_20 ;
struct V_21 V_22 ;
unsigned int V_23 ;
unsigned long V_1 ;
unsigned long V_24 ;
F_8 ( V_13 , & V_14 , V_13 -> V_25 ) ;
if ( ( V_14 -> V_26 . V_27 & 7 ) != 0 ||
( V_14 -> V_26 . V_28 & 4095 ) != 0 )
goto V_29;
if ( ( V_14 -> V_26 . V_28 >> 12 ) > V_15 -> V_30 )
goto V_29;
if ( ( V_14 -> V_26 . V_27 >> 3 ) > 0xffffffffU - V_15 -> V_31 )
goto V_29;
V_23 = ( V_14 -> V_26 . V_27 >> 3 ) + V_15 -> V_31 ;
F_9 (bvec, bio, iter) {
V_1 = ( unsigned long )
F_10 ( V_20 . V_32 ) + V_20 . V_33 ;
V_24 = V_20 . V_34 ;
if ( ( V_1 & 4095 ) != 0 || ( V_24 & 4095 ) != 0 )
goto V_29;
while ( V_24 > 0 ) {
if ( F_11 ( V_14 ) == V_35 ) {
if ( F_1 ( V_1 , V_23 ) != 0 )
goto V_29;
} else {
if ( F_2 ( V_1 , V_23 ) != 0 )
goto V_29;
}
V_1 += 4096 ;
V_24 -= 4096 ;
V_23 ++ ;
}
}
F_12 ( V_14 ) ;
return;
V_29:
F_13 ( V_14 ) ;
}
static int F_14 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
unsigned long V_30 ;
V_30 = ( V_40 * 8 ) & ~ 0x3f ;
V_39 -> V_41 = V_30 >> 6 ;
V_39 -> V_42 = 4 ;
V_39 -> V_43 = 16 ;
V_39 -> V_44 = 4 ;
return 0 ;
}
static int T_2 F_15 ( unsigned long V_45 )
{
unsigned long V_46 ;
unsigned long V_47 ;
unsigned long long V_30 ;
char * V_48 ;
int V_49 ;
int V_50 ;
if ( V_51 <= 0 || V_51 > V_52 ) {
F_16 ( L_1 , V_51 ) ;
return - V_53 ;
}
V_54 = V_51 ;
V_46 = 0 ;
V_49 = 0 ;
for ( V_50 = 0 ; V_50 < V_54 ; V_50 ++ ) {
if ( V_55 [ V_50 ] ) {
V_30 = F_17 ( V_55 [ V_50 ] , & V_48 , 0 ) ;
switch ( * V_48 ) {
case 'g' :
case 'G' :
V_30 <<= 20 ;
break;
case 'm' :
case 'M' :
V_30 <<= 10 ;
}
V_56 [ V_50 ] = ( V_30 + 3 ) & - 4UL ;
}
if ( V_56 [ V_50 ] )
V_46 += V_56 [ V_50 ] ;
else
V_49 ++ ;
}
F_18 ( L_2 , V_54 ) ;
for ( V_50 = 0 ; V_50 < V_54 ; V_50 ++ ) {
if ( V_56 [ V_50 ] )
F_18 ( L_3 ,
V_50 , V_56 [ V_50 ] ) ;
else
F_18 ( L_4
L_5 , V_50 ) ;
}
F_18 ( L_6 ,
V_46 ) ;
F_18 ( L_7 ,
V_49 ) ;
if ( V_46 > V_45 * 4 ) {
F_16 ( L_8 ) ;
return - V_53 ;
}
if ( V_49 ) {
V_47 = ( ( V_45 - V_46 / 4 ) / V_49 ) * 4 ;
F_18 ( L_9
L_10 , V_47 ) ;
for ( V_50 = 0 ; V_50 < V_54 ; V_50 ++ )
if ( V_56 [ V_50 ] == 0 )
V_56 [ V_50 ] = V_47 ;
}
return 0 ;
}
static int T_2 F_19 ( void )
{
unsigned long V_31 ;
int V_50 , V_7 = - V_9 ;
for ( V_50 = 0 ; V_50 < V_54 ; V_50 ++ ) {
V_57 [ V_50 ] = F_20 ( 1 ) ;
if ( ! V_57 [ V_50 ] )
goto V_58;
V_59 [ V_50 ] = F_21 ( V_8 ) ;
if ( ! V_59 [ V_50 ] ) {
F_22 ( V_57 [ V_50 ] ) ;
goto V_58;
}
F_23 ( V_60 , V_59 [ V_50 ] ) ;
F_24 ( V_61 , V_59 [ V_50 ] ) ;
F_25 ( V_59 [ V_50 ] , F_7 ) ;
F_26 ( V_59 [ V_50 ] , 4096 ) ;
}
V_7 = F_27 ( V_62 , V_63 ) ;
if ( V_7 < 0 )
goto V_58;
V_31 = 0 ;
for ( V_50 = 0 ; V_50 < V_54 ; V_50 ++ ) {
struct V_64 * V_65 = V_57 [ V_50 ] ;
V_66 [ V_50 ] . V_30 = V_56 [ V_50 ] / 4 ;
V_66 [ V_50 ] . V_31 = V_31 ;
V_31 += V_66 [ V_50 ] . V_30 ;
V_65 -> V_67 = V_62 ;
V_65 -> V_68 = V_50 ;
V_65 -> V_69 = & V_70 ;
V_65 -> V_18 = & V_66 [ V_50 ] ;
V_65 -> V_71 = V_59 [ V_50 ] ;
sprintf ( V_65 -> V_72 , L_11 , V_50 ) ;
F_28 ( V_65 , V_56 [ V_50 ] << 1 ) ;
F_29 ( V_65 ) ;
}
return 0 ;
V_58:
while ( V_50 -- ) {
F_30 ( V_59 [ V_50 ] ) ;
F_22 ( V_57 [ V_50 ] ) ;
}
return V_7 ;
}
static void F_31 ( const char * V_73 )
{
F_16 ( L_12 , V_73 ) ;
F_32 ( L_13 ) ;
}
static int F_33 ( struct V_74 * V_75 )
{
if ( ! V_40 )
return 0 ;
if ( F_3 () != 0 )
F_31 ( L_14 ) ;
if ( V_40 != F_6 () + 1 )
F_31 ( L_15 ) ;
return 0 ;
}
static void T_3 F_34 ( void )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_54 ; V_50 ++ ) {
F_35 ( V_57 [ V_50 ] ) ;
F_30 ( V_59 [ V_50 ] ) ;
F_22 ( V_57 [ V_50 ] ) ;
}
F_36 ( V_62 , V_63 ) ;
F_37 ( V_76 ) ;
F_38 ( & V_77 ) ;
}
static int T_2 F_39 ( void )
{
int V_7 ;
if ( F_3 () != 0 ) {
F_16 ( L_16 ) ;
return - V_78 ;
}
V_40 = F_6 () + 1 ;
F_18 ( L_17 ,
V_40 , ( unsigned long ) V_40 * 4 ) ;
V_7 = F_15 ( V_40 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_40 ( & V_77 ) ;
if ( V_7 )
return V_7 ;
V_76 = F_41 ( V_63 , - 1 , NULL , 0 ) ;
if ( F_42 ( V_76 ) ) {
V_7 = F_43 ( V_76 ) ;
goto V_79;
}
V_7 = F_19 () ;
if ( V_7 )
goto V_80;
return 0 ;
V_80:
F_37 ( V_76 ) ;
V_79:
F_38 ( & V_77 ) ;
return V_7 ;
}
