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
F_4 ( L_1 , V_4 , V_5 ) ;
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
F_8 ( L_5 ,
V_16 ) ;
} else {
V_16 *= 1000 ;
}
}
static void F_13 ( void )
{
T_2 V_17 = F_14 ( V_18 ) ;
unsigned int V_19 = 0 , V_20 = 0 ;
if ( V_17 & ( V_21 | V_22 ) )
V_19 = F_15 ( V_17 ) ;
if ( V_17 & ( V_23 | V_24 ) )
V_20 = F_16 ( V_17 ) ;
V_25 = 1 << ( 11 + F_17 ( V_20 , V_19 ) ) ;
}
static T_3 F_18 ( unsigned int V_26 )
{
T_3 V_27 = V_26 * V_28 / V_25 ;
return ( V_27 - ( F_2 () ? 31 : 0 ) ) / 32 ;
}
static unsigned int F_19 ( unsigned int V_29 )
{
return F_20 ( 0 ) ;
}
static int F_21 ( struct V_30 * V_31 , unsigned int V_32 )
{
struct V_7 * V_33 ;
const struct V_1 * V_34 ;
unsigned long V_35 ;
unsigned int V_36 , V_37 ;
unsigned int V_38 , V_39 , V_40 , V_41 ;
int V_3 = 0 ;
F_9 ( & V_33 , & V_34 ) ;
V_36 = V_34 [ V_32 ] . V_42 ;
V_37 = V_34 [ V_32 ] . V_43 ;
if ( V_44 )
F_22 ( L_6 ,
V_36 / 1000 , ( V_34 [ V_32 ] . V_45 ) ?
( V_37 / 2000 ) : ( V_37 / 1000 ) ) ;
if ( V_6 && V_36 > V_31 -> V_46 ) {
V_3 = F_1 ( & V_34 [ V_32 ] ) ;
if ( V_3 )
return V_3 ;
}
V_39 = V_40 = F_14 ( V_47 ) ;
if ( ( V_39 & V_48 ) > F_18 ( V_37 ) ) {
V_39 = ( V_39 & ~ V_48 ) ;
V_39 |= F_18 ( V_37 ) ;
}
V_40 =
( V_40 & ~ V_48 ) | F_18 ( V_37 ) ;
if ( V_34 [ V_32 ] . V_45 ) {
V_39 |= V_49 ;
V_40 |= V_49 ;
} else {
V_40 &= ~ V_49 ;
}
F_23 ( V_35 ) ;
F_24 ( V_34 [ V_32 ] . V_50 , V_51 ) ;
V_41 = V_34 [ V_32 ] . V_41 ;
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
F_25 ( V_35 ) ;
if ( V_6 && V_36 < V_31 -> V_46 )
V_3 = F_1 ( & V_34 [ V_32 ] ) ;
return 0 ;
}
static int F_26 ( struct V_30 * V_31 )
{
int V_52 ;
unsigned int V_26 ;
struct V_7 * V_53 ;
const struct V_1 * V_54 ;
if ( F_2 () )
F_12 () ;
F_5 () ;
F_13 () ;
V_31 -> V_55 . V_56 = 1000 ;
for ( V_52 = 0 ; V_52 < V_57 ; V_52 ++ ) {
V_11 [ V_52 ] . V_58 = V_10 [ V_52 ] . V_42 ;
V_11 [ V_52 ] . V_59 = V_52 ;
}
V_11 [ V_52 ] . V_58 = V_60 ;
for ( V_52 = 0 ; V_52 < V_61 ; V_52 ++ ) {
V_13 [ V_52 ] . V_58 =
V_12 [ V_52 ] . V_42 ;
V_13 [ V_52 ] . V_59 = V_52 ;
}
V_13 [ V_52 ] . V_58 = V_60 ;
V_9 = ! ! V_9 ;
for ( V_52 = 0 ; V_52 < V_62 ; V_52 ++ ) {
V_26 = V_14 [ V_52 ] . V_42 ;
if ( V_26 > V_16 )
break;
V_15 [ V_52 ] . V_58 = V_26 ;
V_15 [ V_52 ] . V_59 = V_52 ;
}
V_15 [ V_52 ] . V_59 = V_52 ;
V_15 [ V_52 ] . V_58 = V_60 ;
if ( F_10 () ) {
F_9 ( & V_53 , & V_54 ) ;
F_8 ( L_7 ,
V_9 ? L_8 : L_9 ) ;
F_27 ( V_31 , V_53 ) ;
}
else if ( F_2 () ) {
F_27 ( V_31 , V_15 ) ;
}
F_8 ( L_10 ) ;
return 0 ;
}
static int T_1 F_28 ( void )
{
int V_3 = - V_63 ;
if ( F_10 () || F_2 () )
V_3 = F_29 ( & V_64 ) ;
return V_3 ;
}
static void T_4 F_30 ( void )
{
F_31 ( & V_64 ) ;
}
