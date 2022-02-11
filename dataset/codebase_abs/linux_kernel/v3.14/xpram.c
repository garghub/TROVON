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
if ( ( V_14 -> V_25 . V_26 & 7 ) != 0 ||
( V_14 -> V_25 . V_27 & 4095 ) != 0 )
goto V_28;
if ( ( V_14 -> V_25 . V_27 >> 12 ) > V_15 -> V_29 )
goto V_28;
if ( ( V_14 -> V_25 . V_26 >> 3 ) > 0xffffffffU - V_15 -> V_30 )
goto V_28;
V_23 = ( V_14 -> V_25 . V_26 >> 3 ) + V_15 -> V_30 ;
F_8 (bvec, bio, iter) {
V_1 = ( unsigned long )
F_9 ( V_20 . V_31 ) + V_20 . V_32 ;
V_24 = V_20 . V_33 ;
if ( ( V_1 & 4095 ) != 0 || ( V_24 & 4095 ) != 0 )
goto V_28;
while ( V_24 > 0 ) {
if ( F_10 ( V_14 ) == V_34 ) {
if ( F_1 ( V_1 , V_23 ) != 0 )
goto V_28;
} else {
if ( F_2 ( V_1 , V_23 ) != 0 )
goto V_28;
}
V_1 += 4096 ;
V_24 -= 4096 ;
V_23 ++ ;
}
}
F_11 ( V_35 , & V_14 -> V_36 ) ;
F_12 ( V_14 , 0 ) ;
return;
V_28:
F_13 ( V_14 ) ;
}
static int F_14 ( struct V_37 * V_38 , struct V_39 * V_40 )
{
unsigned long V_29 ;
V_29 = ( V_41 * 8 ) & ~ 0x3f ;
V_40 -> V_42 = V_29 >> 6 ;
V_40 -> V_43 = 4 ;
V_40 -> V_44 = 16 ;
V_40 -> V_45 = 4 ;
return 0 ;
}
static int T_2 F_15 ( unsigned long V_46 )
{
unsigned long V_47 ;
unsigned long V_48 ;
unsigned long long V_29 ;
char * V_49 ;
int V_50 ;
int V_51 ;
if ( V_52 <= 0 || V_52 > V_53 ) {
F_16 ( L_1 , V_52 ) ;
return - V_54 ;
}
V_55 = V_52 ;
V_47 = 0 ;
V_50 = 0 ;
for ( V_51 = 0 ; V_51 < V_55 ; V_51 ++ ) {
if ( V_56 [ V_51 ] ) {
V_29 = F_17 ( V_56 [ V_51 ] , & V_49 , 0 ) ;
switch ( * V_49 ) {
case 'g' :
case 'G' :
V_29 <<= 20 ;
break;
case 'm' :
case 'M' :
V_29 <<= 10 ;
}
V_57 [ V_51 ] = ( V_29 + 3 ) & - 4UL ;
}
if ( V_57 [ V_51 ] )
V_47 += V_57 [ V_51 ] ;
else
V_50 ++ ;
}
F_18 ( L_2 , V_55 ) ;
for ( V_51 = 0 ; V_51 < V_55 ; V_51 ++ ) {
if ( V_57 [ V_51 ] )
F_18 ( L_3 ,
V_51 , V_57 [ V_51 ] ) ;
else
F_18 ( L_4
L_5 , V_51 ) ;
}
F_18 ( L_6 ,
V_47 ) ;
F_18 ( L_7 ,
V_50 ) ;
if ( V_47 > V_46 * 4 ) {
F_16 ( L_8 ) ;
return - V_54 ;
}
if ( V_50 ) {
V_48 = ( ( V_46 - V_47 / 4 ) / V_50 ) * 4 ;
F_18 ( L_9
L_10 , V_48 ) ;
for ( V_51 = 0 ; V_51 < V_55 ; V_51 ++ )
if ( V_57 [ V_51 ] == 0 )
V_57 [ V_51 ] = V_48 ;
}
return 0 ;
}
static int T_2 F_19 ( void )
{
unsigned long V_30 ;
int V_51 , V_7 = - V_9 ;
for ( V_51 = 0 ; V_51 < V_55 ; V_51 ++ ) {
V_58 [ V_51 ] = F_20 ( 1 ) ;
if ( ! V_58 [ V_51 ] )
goto V_59;
V_60 [ V_51 ] = F_21 ( V_8 ) ;
if ( ! V_60 [ V_51 ] ) {
F_22 ( V_58 [ V_51 ] ) ;
goto V_59;
}
F_23 ( V_61 , V_60 [ V_51 ] ) ;
F_24 ( V_60 [ V_51 ] , F_7 ) ;
F_25 ( V_60 [ V_51 ] , 4096 ) ;
}
V_7 = F_26 ( V_62 , V_63 ) ;
if ( V_7 < 0 )
goto V_59;
V_30 = 0 ;
for ( V_51 = 0 ; V_51 < V_55 ; V_51 ++ ) {
struct V_64 * V_65 = V_58 [ V_51 ] ;
V_66 [ V_51 ] . V_29 = V_57 [ V_51 ] / 4 ;
V_66 [ V_51 ] . V_30 = V_30 ;
V_30 += V_66 [ V_51 ] . V_29 ;
V_65 -> V_67 = V_62 ;
V_65 -> V_68 = V_51 ;
V_65 -> V_69 = & V_70 ;
V_65 -> V_18 = & V_66 [ V_51 ] ;
V_65 -> V_71 = V_60 [ V_51 ] ;
sprintf ( V_65 -> V_72 , L_11 , V_51 ) ;
F_27 ( V_65 , V_57 [ V_51 ] << 1 ) ;
F_28 ( V_65 ) ;
}
return 0 ;
V_59:
while ( V_51 -- ) {
F_29 ( V_60 [ V_51 ] ) ;
F_22 ( V_58 [ V_51 ] ) ;
}
return V_7 ;
}
static void F_30 ( const char * V_73 )
{
F_16 ( L_12 , V_73 ) ;
F_31 ( L_13 ) ;
}
static int F_32 ( struct V_74 * V_75 )
{
if ( ! V_41 )
return 0 ;
if ( F_3 () != 0 )
F_30 ( L_14 ) ;
if ( V_41 != F_6 () + 1 )
F_30 ( L_15 ) ;
return 0 ;
}
static void T_3 F_33 ( void )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_55 ; V_51 ++ ) {
F_34 ( V_58 [ V_51 ] ) ;
F_29 ( V_60 [ V_51 ] ) ;
F_22 ( V_58 [ V_51 ] ) ;
}
F_35 ( V_62 , V_63 ) ;
F_36 ( V_76 ) ;
F_37 ( & V_77 ) ;
}
static int T_2 F_38 ( void )
{
int V_7 ;
if ( F_3 () != 0 ) {
F_16 ( L_16 ) ;
return - V_78 ;
}
V_41 = F_6 () + 1 ;
F_18 ( L_17 ,
V_41 , ( unsigned long ) V_41 * 4 ) ;
V_7 = F_15 ( V_41 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_39 ( & V_77 ) ;
if ( V_7 )
return V_7 ;
V_76 = F_40 ( V_63 , - 1 , NULL , 0 ) ;
if ( F_41 ( V_76 ) ) {
V_7 = F_42 ( V_76 ) ;
goto V_79;
}
V_7 = F_19 () ;
if ( V_7 )
goto V_80;
return 0 ;
V_80:
F_36 ( V_76 ) ;
V_79:
F_37 ( & V_77 ) ;
return V_7 ;
}
