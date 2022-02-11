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
static T_1 F_7 ( struct V_12 * V_13 , struct V_14 * V_14 )
{
T_2 * V_15 = V_14 -> V_16 -> V_17 ;
struct V_18 V_19 ;
struct V_20 V_21 ;
unsigned int V_22 ;
unsigned long V_1 ;
unsigned long V_23 ;
F_8 ( V_13 , & V_14 ) ;
if ( ( V_14 -> V_24 . V_25 & 7 ) != 0 ||
( V_14 -> V_24 . V_26 & 4095 ) != 0 )
goto V_27;
if ( ( V_14 -> V_24 . V_26 >> 12 ) > V_15 -> V_28 )
goto V_27;
if ( ( V_14 -> V_24 . V_25 >> 3 ) > 0xffffffffU - V_15 -> V_29 )
goto V_27;
V_22 = ( V_14 -> V_24 . V_25 >> 3 ) + V_15 -> V_29 ;
F_9 (bvec, bio, iter) {
V_1 = ( unsigned long )
F_10 ( V_19 . V_30 ) + V_19 . V_31 ;
V_23 = V_19 . V_32 ;
if ( ( V_1 & 4095 ) != 0 || ( V_23 & 4095 ) != 0 )
goto V_27;
while ( V_23 > 0 ) {
if ( F_11 ( V_14 ) == V_33 ) {
if ( F_1 ( V_1 , V_22 ) != 0 )
goto V_27;
} else {
if ( F_2 ( V_1 , V_22 ) != 0 )
goto V_27;
}
V_1 += 4096 ;
V_23 -= 4096 ;
V_22 ++ ;
}
}
F_12 ( V_14 ) ;
return V_34 ;
V_27:
F_13 ( V_14 ) ;
return V_34 ;
}
static int F_14 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
unsigned long V_28 ;
V_28 = ( V_39 * 8 ) & ~ 0x3f ;
V_38 -> V_40 = V_28 >> 6 ;
V_38 -> V_41 = 4 ;
V_38 -> V_42 = 16 ;
V_38 -> V_43 = 4 ;
return 0 ;
}
static int T_3 F_15 ( unsigned long V_44 )
{
unsigned long V_45 ;
unsigned long V_46 ;
unsigned long long V_28 ;
char * V_47 ;
int V_48 ;
int V_49 ;
if ( V_50 <= 0 || V_50 > V_51 ) {
F_16 ( L_1 , V_50 ) ;
return - V_52 ;
}
V_53 = V_50 ;
V_45 = 0 ;
V_48 = 0 ;
for ( V_49 = 0 ; V_49 < V_53 ; V_49 ++ ) {
if ( V_54 [ V_49 ] ) {
V_28 = F_17 ( V_54 [ V_49 ] , & V_47 , 0 ) ;
switch ( * V_47 ) {
case 'g' :
case 'G' :
V_28 <<= 20 ;
break;
case 'm' :
case 'M' :
V_28 <<= 10 ;
}
V_55 [ V_49 ] = ( V_28 + 3 ) & - 4UL ;
}
if ( V_55 [ V_49 ] )
V_45 += V_55 [ V_49 ] ;
else
V_48 ++ ;
}
F_18 ( L_2 , V_53 ) ;
for ( V_49 = 0 ; V_49 < V_53 ; V_49 ++ ) {
if ( V_55 [ V_49 ] )
F_18 ( L_3 ,
V_49 , V_55 [ V_49 ] ) ;
else
F_18 ( L_4
L_5 , V_49 ) ;
}
F_18 ( L_6 ,
V_45 ) ;
F_18 ( L_7 ,
V_48 ) ;
if ( V_45 > V_44 * 4 ) {
F_16 ( L_8 ) ;
return - V_52 ;
}
if ( V_48 ) {
V_46 = ( ( V_44 - V_45 / 4 ) / V_48 ) * 4 ;
F_18 ( L_9
L_10 , V_46 ) ;
for ( V_49 = 0 ; V_49 < V_53 ; V_49 ++ )
if ( V_55 [ V_49 ] == 0 )
V_55 [ V_49 ] = V_46 ;
}
return 0 ;
}
static int T_3 F_19 ( void )
{
unsigned long V_29 ;
int V_49 , V_7 = - V_9 ;
for ( V_49 = 0 ; V_49 < V_53 ; V_49 ++ ) {
V_56 [ V_49 ] = F_20 ( 1 ) ;
if ( ! V_56 [ V_49 ] )
goto V_57;
V_58 [ V_49 ] = F_21 ( V_8 ) ;
if ( ! V_58 [ V_49 ] ) {
F_22 ( V_56 [ V_49 ] ) ;
goto V_57;
}
F_23 ( V_59 , V_58 [ V_49 ] ) ;
F_24 ( V_60 , V_58 [ V_49 ] ) ;
F_25 ( V_58 [ V_49 ] , F_7 ) ;
F_26 ( V_58 [ V_49 ] , 4096 ) ;
}
V_7 = F_27 ( V_61 , V_62 ) ;
if ( V_7 < 0 )
goto V_57;
V_29 = 0 ;
for ( V_49 = 0 ; V_49 < V_53 ; V_49 ++ ) {
struct V_63 * V_64 = V_56 [ V_49 ] ;
V_65 [ V_49 ] . V_28 = V_55 [ V_49 ] / 4 ;
V_65 [ V_49 ] . V_29 = V_29 ;
V_29 += V_65 [ V_49 ] . V_28 ;
V_64 -> V_66 = V_61 ;
V_64 -> V_67 = V_49 ;
V_64 -> V_68 = & V_69 ;
V_64 -> V_17 = & V_65 [ V_49 ] ;
V_64 -> V_70 = V_58 [ V_49 ] ;
sprintf ( V_64 -> V_71 , L_11 , V_49 ) ;
F_28 ( V_64 , V_55 [ V_49 ] << 1 ) ;
F_29 ( V_64 ) ;
}
return 0 ;
V_57:
while ( V_49 -- ) {
F_30 ( V_58 [ V_49 ] ) ;
F_22 ( V_56 [ V_49 ] ) ;
}
return V_7 ;
}
static void F_31 ( const char * V_72 )
{
F_16 ( L_12 , V_72 ) ;
F_32 ( L_13 ) ;
}
static int F_33 ( struct V_73 * V_74 )
{
if ( ! V_39 )
return 0 ;
if ( F_3 () != 0 )
F_31 ( L_14 ) ;
if ( V_39 != F_6 () + 1 )
F_31 ( L_15 ) ;
return 0 ;
}
static void T_4 F_34 ( void )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_53 ; V_49 ++ ) {
F_35 ( V_56 [ V_49 ] ) ;
F_30 ( V_58 [ V_49 ] ) ;
F_22 ( V_56 [ V_49 ] ) ;
}
F_36 ( V_61 , V_62 ) ;
F_37 ( V_75 ) ;
F_38 ( & V_76 ) ;
}
static int T_3 F_39 ( void )
{
int V_7 ;
if ( F_3 () != 0 ) {
F_16 ( L_16 ) ;
return - V_77 ;
}
V_39 = F_6 () + 1 ;
F_18 ( L_17 ,
V_39 , ( unsigned long ) V_39 * 4 ) ;
V_7 = F_15 ( V_39 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_40 ( & V_76 ) ;
if ( V_7 )
return V_7 ;
V_75 = F_41 ( V_62 , - 1 , NULL , 0 ) ;
if ( F_42 ( V_75 ) ) {
V_7 = F_43 ( V_75 ) ;
goto V_78;
}
V_7 = F_19 () ;
if ( V_7 )
goto V_79;
return 0 ;
V_79:
F_37 ( V_75 ) ;
V_78:
F_38 ( & V_76 ) ;
return V_7 ;
}
