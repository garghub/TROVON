static int F_1 ( const struct V_1 * V_2 )
{
int V_3 = 0 ;
int V_4 , V_5 ;
if ( ! F_2 () )
return 0 ;
V_4 = V_2 -> V_4 ;
V_5 = V_2 -> V_5 ;
if ( ( V_4 == - 1 ) || ( V_5 == - 1 ) )
return 0 ;
V_3 = F_3 ( V_6 , V_4 , V_5 ) ;
if ( V_3 )
F_4 ( L_1 ,
V_4 , V_5 ) ;
return V_3 ;
}
static void T_1 F_5 ( void )
{
V_6 = F_6 ( NULL , L_2 ) ;
if ( F_7 ( V_6 ) ) {
F_8 ( L_3 ) ;
V_6 = NULL ;
} else {
F_8 ( L_4 ) ;
}
}
static int F_1 ( const struct V_1 * V_2 )
{
return 0 ;
}
static void T_1 F_5 ( void ) { }
static void F_9 ( struct V_7 * * V_8 ,
const struct V_1 * * V_1 )
{
if ( F_10 () ) {
if ( ! V_9 ) {
* V_1 = V_10 ;
* V_8 = V_11 ;
} else {
* V_1 = V_12 ;
* V_8 = V_13 ;
}
} else if ( F_2 () ) {
* V_1 = V_14 ;
* V_8 = V_15 ;
} else {
F_11 () ;
}
}
static void F_12 ( void )
{
if ( ! V_16 ) {
V_16 = 416000 ;
F_13 ( V_17 L_5
L_6 ,
V_16 ) ;
} else {
V_16 *= 1000 ;
}
}
static void F_14 ( void )
{
T_2 V_18 = F_15 ( V_19 ) ;
unsigned int V_20 = 0 , V_21 = 0 ;
if ( V_18 & ( V_22 | V_23 ) )
V_20 = F_16 ( V_18 ) ;
if ( V_18 & ( V_24 | V_25 ) )
V_21 = F_17 ( V_18 ) ;
V_26 = 1 << ( 11 + F_18 ( V_21 , V_20 ) ) ;
}
static T_3 F_19 ( unsigned int V_27 )
{
T_3 V_28 = V_27 * V_29 / V_26 ;
return ( V_28 - ( F_2 () ? 31 : 0 ) ) / 32 ;
}
static unsigned int F_20 ( unsigned int V_30 )
{
return F_21 ( 0 ) ;
}
static int F_22 ( struct V_31 * V_32 , unsigned int V_33 )
{
struct V_7 * V_34 ;
const struct V_1 * V_35 ;
unsigned long V_36 ;
unsigned int V_37 , V_38 ;
unsigned int V_39 , V_40 , V_41 , V_42 ;
int V_3 = 0 ;
F_9 ( & V_34 , & V_35 ) ;
V_37 = V_35 [ V_33 ] . V_43 ;
V_38 = V_35 [ V_33 ] . V_44 ;
if ( V_45 )
F_23 ( L_7 ,
V_37 / 1000 , ( V_35 [ V_33 ] . V_46 ) ?
( V_38 / 2000 ) : ( V_38 / 1000 ) ) ;
if ( V_6 && V_37 > V_32 -> V_47 ) {
V_3 = F_1 ( & V_35 [ V_33 ] ) ;
if ( V_3 )
return V_3 ;
}
V_40 = V_41 = F_15 ( V_48 ) ;
if ( ( V_40 & V_49 ) > F_19 ( V_38 ) ) {
V_40 = ( V_40 & ~ V_49 ) ;
V_40 |= F_19 ( V_38 ) ;
}
V_41 =
( V_41 & ~ V_49 ) | F_19 ( V_38 ) ;
if ( V_35 [ V_33 ] . V_46 ) {
V_40 |= V_50 ;
V_41 |= V_50 ;
} else {
V_41 &= ~ V_50 ;
}
F_24 ( V_36 ) ;
F_25 ( V_35 [ V_33 ] . V_51 , V_52 ) ;
V_42 = V_35 [ V_33 ] . V_42 ;
asm volatile(" \n\
ldr r4, [%1] /* load MDREFR */ \n\
b 2f \n\
.align 5 \n\
1: \n\
str %3, [%1] /* preset the MDREFR */ \n\
mcr p14, 0, %2, c6, c0, 0 /* set CCLKCFG[FCS] */ \n\
str %4, [%1] /* postset the MDREFR */ \n\
\n\
b 3f \n\
2: b 1b \n\
3: nop \n\
"
: "=&r" (unused)
: "r" (MDREFR), "r" (cclkcfg),
"r" (preset_mdrefr), "r" (postset_mdrefr)
: "r4", "r5");
F_26 ( V_36 ) ;
if ( V_6 && V_37 < V_32 -> V_47 )
V_3 = F_1 ( & V_35 [ V_33 ] ) ;
return 0 ;
}
static int F_27 ( struct V_31 * V_32 )
{
int V_53 ;
unsigned int V_27 ;
struct V_7 * V_54 ;
const struct V_1 * V_55 ;
if ( F_2 () )
F_12 () ;
F_5 () ;
F_14 () ;
V_32 -> V_56 . V_57 = 1000 ;
for ( V_53 = 0 ; V_53 < V_58 ; V_53 ++ ) {
V_11 [ V_53 ] . V_59 = V_10 [ V_53 ] . V_43 ;
V_11 [ V_53 ] . V_60 = V_53 ;
}
V_11 [ V_53 ] . V_59 = V_61 ;
for ( V_53 = 0 ; V_53 < V_62 ; V_53 ++ ) {
V_13 [ V_53 ] . V_59 =
V_12 [ V_53 ] . V_43 ;
V_13 [ V_53 ] . V_60 = V_53 ;
}
V_13 [ V_53 ] . V_59 = V_61 ;
V_9 = ! ! V_9 ;
for ( V_53 = 0 ; V_53 < V_63 ; V_53 ++ ) {
V_27 = V_14 [ V_53 ] . V_43 ;
if ( V_27 > V_16 )
break;
V_15 [ V_53 ] . V_59 = V_27 ;
V_15 [ V_53 ] . V_60 = V_53 ;
}
V_15 [ V_53 ] . V_60 = V_53 ;
V_15 [ V_53 ] . V_59 = V_61 ;
if ( F_10 () ) {
F_9 ( & V_54 , & V_55 ) ;
F_8 ( L_8 ,
V_9 ? L_9 : L_10 ) ;
F_28 ( V_32 , V_54 ) ;
}
else if ( F_2 () ) {
F_28 ( V_32 , V_15 ) ;
}
F_13 ( V_17 L_11 ) ;
return 0 ;
}
static int T_1 F_29 ( void )
{
int V_3 = - V_64 ;
if ( F_10 () || F_2 () )
V_3 = F_30 ( & V_65 ) ;
return V_3 ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_65 ) ;
}
