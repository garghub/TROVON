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
static int F_7 ( struct V_12 * V_13 , struct V_14 * V_14 )
{
T_1 * V_15 = V_14 -> V_16 -> V_17 -> V_18 ;
struct V_19 * V_20 ;
unsigned int V_21 ;
unsigned long V_1 ;
unsigned long V_22 ;
int V_23 ;
if ( ( V_14 -> V_24 & 7 ) != 0 || ( V_14 -> V_25 & 4095 ) != 0 )
goto V_26;
if ( ( V_14 -> V_25 >> 12 ) > V_15 -> V_27 )
goto V_26;
if ( ( V_14 -> V_24 >> 3 ) > 0xffffffffU - V_15 -> V_28 )
goto V_26;
V_21 = ( V_14 -> V_24 >> 3 ) + V_15 -> V_28 ;
F_8 (bvec, bio, i) {
V_1 = ( unsigned long )
F_9 ( V_20 -> V_29 ) + V_20 -> V_30 ;
V_22 = V_20 -> V_31 ;
if ( ( V_1 & 4095 ) != 0 || ( V_22 & 4095 ) != 0 )
goto V_26;
while ( V_22 > 0 ) {
if ( F_10 ( V_14 ) == V_32 ) {
if ( F_1 ( V_1 , V_21 ) != 0 )
goto V_26;
} else {
if ( F_2 ( V_1 , V_21 ) != 0 )
goto V_26;
}
V_1 += 4096 ;
V_22 -= 4096 ;
V_21 ++ ;
}
}
F_11 ( V_33 , & V_14 -> V_34 ) ;
F_12 ( V_14 , 0 ) ;
return 0 ;
V_26:
F_13 ( V_14 ) ;
return 0 ;
}
static int F_14 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
unsigned long V_27 ;
V_27 = ( V_39 * 8 ) & ~ 0x3f ;
V_38 -> V_40 = V_27 >> 6 ;
V_38 -> V_41 = 4 ;
V_38 -> V_42 = 16 ;
V_38 -> V_43 = 4 ;
return 0 ;
}
static int T_2 F_15 ( unsigned long V_44 )
{
unsigned long V_45 ;
unsigned long V_46 ;
unsigned long long V_27 ;
int V_47 ;
int V_23 ;
if ( V_48 <= 0 || V_48 > V_49 ) {
F_16 ( L_1 , V_48 ) ;
return - V_50 ;
}
V_51 = V_48 ;
V_45 = 0 ;
V_47 = 0 ;
for ( V_23 = 0 ; V_23 < V_51 ; V_23 ++ ) {
if ( V_52 [ V_23 ] ) {
V_27 = F_17 ( V_52 [ V_23 ] , & V_52 [ V_23 ] , 0 ) ;
switch ( V_52 [ V_23 ] [ 0 ] ) {
case 'g' :
case 'G' :
V_27 <<= 20 ;
break;
case 'm' :
case 'M' :
V_27 <<= 10 ;
}
V_53 [ V_23 ] = ( V_27 + 3 ) & - 4UL ;
}
if ( V_53 [ V_23 ] )
V_45 += V_53 [ V_23 ] ;
else
V_47 ++ ;
}
F_18 ( L_2 , V_51 ) ;
for ( V_23 = 0 ; V_23 < V_51 ; V_23 ++ ) {
if ( V_53 [ V_23 ] )
F_18 ( L_3 ,
V_23 , V_53 [ V_23 ] ) ;
else
F_18 ( L_4
L_5 , V_23 ) ;
}
F_18 ( L_6 ,
V_45 ) ;
F_18 ( L_7 ,
V_47 ) ;
if ( V_45 > V_44 * 4 ) {
F_16 ( L_8 ) ;
return - V_50 ;
}
if ( V_47 ) {
V_46 = ( ( V_44 - V_45 / 4 ) / V_47 ) * 4 ;
F_18 ( L_9
L_10 , V_46 ) ;
for ( V_23 = 0 ; V_23 < V_51 ; V_23 ++ )
if ( V_53 [ V_23 ] == 0 )
V_53 [ V_23 ] = V_46 ;
}
return 0 ;
}
static int T_2 F_19 ( void )
{
unsigned long V_28 ;
int V_23 , V_7 = - V_9 ;
for ( V_23 = 0 ; V_23 < V_51 ; V_23 ++ ) {
V_54 [ V_23 ] = F_20 ( 1 ) ;
if ( ! V_54 [ V_23 ] )
goto V_55;
V_56 [ V_23 ] = F_21 ( V_8 ) ;
if ( ! V_56 [ V_23 ] ) {
F_22 ( V_54 [ V_23 ] ) ;
goto V_55;
}
F_23 ( V_56 [ V_23 ] , F_7 ) ;
F_24 ( V_56 [ V_23 ] , 4096 ) ;
}
V_7 = F_25 ( V_57 , V_58 ) ;
if ( V_7 < 0 )
goto V_55;
V_28 = 0 ;
for ( V_23 = 0 ; V_23 < V_51 ; V_23 ++ ) {
struct V_59 * V_60 = V_54 [ V_23 ] ;
V_61 [ V_23 ] . V_27 = V_53 [ V_23 ] / 4 ;
V_61 [ V_23 ] . V_28 = V_28 ;
V_28 += V_61 [ V_23 ] . V_27 ;
V_60 -> V_62 = V_57 ;
V_60 -> V_63 = V_23 ;
V_60 -> V_64 = & V_65 ;
V_60 -> V_18 = & V_61 [ V_23 ] ;
V_60 -> V_66 = V_56 [ V_23 ] ;
sprintf ( V_60 -> V_67 , L_11 , V_23 ) ;
F_26 ( V_60 , V_53 [ V_23 ] << 1 ) ;
F_27 ( V_60 ) ;
}
return 0 ;
V_55:
while ( V_23 -- ) {
F_28 ( V_56 [ V_23 ] ) ;
F_22 ( V_54 [ V_23 ] ) ;
}
return V_7 ;
}
static void F_29 ( const char * V_68 )
{
F_16 ( L_12 , V_68 ) ;
F_30 ( L_13 ) ;
}
static int F_31 ( struct V_69 * V_70 )
{
if ( ! V_39 )
return 0 ;
if ( F_3 () != 0 )
F_29 ( L_14 ) ;
if ( V_39 != F_6 () + 1 )
F_29 ( L_15 ) ;
return 0 ;
}
static void T_3 F_32 ( void )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_51 ; V_23 ++ ) {
F_33 ( V_54 [ V_23 ] ) ;
F_28 ( V_56 [ V_23 ] ) ;
F_22 ( V_54 [ V_23 ] ) ;
}
F_34 ( V_57 , V_58 ) ;
F_35 ( V_71 ) ;
F_36 ( & V_72 ) ;
}
static int T_2 F_37 ( void )
{
int V_7 ;
if ( F_3 () != 0 ) {
F_16 ( L_16 ) ;
return - V_73 ;
}
V_39 = F_6 () + 1 ;
F_18 ( L_17 ,
V_39 , ( unsigned long ) V_39 * 4 ) ;
V_7 = F_15 ( V_39 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_38 ( & V_72 ) ;
if ( V_7 )
return V_7 ;
V_71 = F_39 ( V_58 , - 1 , NULL , 0 ) ;
if ( F_40 ( V_71 ) ) {
V_7 = F_41 ( V_71 ) ;
goto V_74;
}
V_7 = F_19 () ;
if ( V_7 )
goto V_75;
return 0 ;
V_75:
F_35 ( V_71 ) ;
V_74:
F_36 ( & V_72 ) ;
return V_7 ;
}
