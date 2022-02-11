static int F_1 ( T_1 * V_1 )
{
int V_2 = 0 ;
int V_3 , V_4 ;
if ( ! F_2 () )
return 0 ;
V_3 = V_1 -> V_3 ;
V_4 = V_1 -> V_4 ;
if ( ( V_3 == - 1 ) || ( V_4 == - 1 ) )
return 0 ;
V_2 = F_3 ( V_5 , V_3 , V_4 ) ;
if ( V_2 )
F_4 ( L_1 ,
V_3 , V_4 ) ;
return V_2 ;
}
static T_2 void F_5 ( void )
{
V_5 = F_6 ( NULL , L_2 ) ;
if ( F_7 ( V_5 ) ) {
F_8 ( L_3 ) ;
V_5 = NULL ;
} else {
F_8 ( L_4 ) ;
}
}
static int F_1 ( T_1 * V_1 )
{
return 0 ;
}
static T_2 void F_5 ( void ) { }
static void F_9 ( struct V_6 * * V_7 ,
T_1 * * V_8 )
{
if ( F_10 () ) {
if ( ! V_9 ) {
* V_8 = V_10 ;
* V_7 = V_11 ;
} else {
* V_8 = V_12 ;
* V_7 = V_13 ;
}
} else if ( F_2 () ) {
* V_8 = V_14 ;
* V_7 = V_15 ;
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
T_3 V_18 = F_15 ( V_19 ) ;
unsigned int V_20 = 0 , V_21 = 0 ;
if ( V_18 & ( V_22 | V_23 ) )
V_20 = F_16 ( V_18 ) ;
if ( V_18 & ( V_24 | V_25 ) )
V_21 = F_17 ( V_18 ) ;
V_26 = 1 << ( 11 + F_18 ( V_21 , V_20 ) ) ;
}
static T_4 F_19 ( unsigned int V_27 )
{
T_4 V_28 = V_27 * V_29 / V_26 ;
return ( V_28 - ( F_2 () ? 31 : 0 ) ) / 32 ;
}
static int F_20 ( struct V_30 * V_31 )
{
struct V_6 * V_32 ;
T_1 * V_8 ;
int V_2 ;
F_9 ( & V_32 , & V_8 ) ;
V_2 = F_21 ( V_31 , V_32 ) ;
if ( V_33 )
F_22 ( L_7 ,
V_31 -> V_34 , V_31 -> F_18 ) ;
return V_2 ;
}
static unsigned int F_23 ( unsigned int V_35 )
{
return F_24 ( 0 ) ;
}
static int F_25 ( struct V_30 * V_31 ,
unsigned int V_36 ,
unsigned int V_37 )
{
struct V_6 * V_32 ;
T_1 * V_38 ;
struct V_39 V_40 ;
unsigned int V_41 ;
unsigned long V_42 ;
unsigned int V_43 , V_44 ;
unsigned int V_45 , V_46 , V_47 , V_48 ;
int V_2 = 0 ;
F_9 ( & V_32 , & V_38 ) ;
if ( F_26 ( V_31 , V_32 ,
V_36 , V_37 , & V_41 ) ) {
return - V_49 ;
}
V_43 = V_38 [ V_41 ] . V_50 ;
V_44 = V_38 [ V_41 ] . V_51 ;
V_40 . V_52 = V_31 -> V_53 ;
V_40 . V_54 = V_43 ;
if ( V_33 )
F_22 ( L_8 ,
V_40 . V_54 / 1000 , ( V_38 [ V_41 ] . V_55 ) ?
( V_44 / 2000 ) : ( V_44 / 1000 ) ) ;
if ( V_5 && V_40 . V_54 > V_40 . V_52 )
V_2 = F_1 ( & V_38 [ V_41 ] ) ;
if ( V_2 )
return V_2 ;
F_27 ( V_31 , & V_40 , V_56 ) ;
V_46 = V_47 = F_15 ( V_57 ) ;
if ( ( V_46 & V_58 ) > F_19 ( V_44 ) ) {
V_46 = ( V_46 & ~ V_58 ) ;
V_46 |= F_19 ( V_44 ) ;
}
V_47 =
( V_47 & ~ V_58 ) | F_19 ( V_44 ) ;
if ( V_38 [ V_41 ] . V_55 ) {
V_46 |= V_59 ;
V_47 |= V_59 ;
} else {
V_47 &= ~ V_59 ;
}
F_28 ( V_42 ) ;
V_60 = V_38 [ V_41 ] . V_61 ;
V_48 = V_38 [ V_41 ] . V_48 ;
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
F_29 ( V_42 ) ;
F_27 ( V_31 , & V_40 , V_62 ) ;
if ( V_5 && V_40 . V_54 < V_40 . V_52 )
V_2 = F_1 ( & V_38 [ V_41 ] ) ;
return 0 ;
}
static int F_30 ( struct V_30 * V_31 )
{
int V_63 ;
unsigned int V_27 ;
struct V_6 * V_64 ;
T_1 * V_65 ;
if ( F_2 () )
F_12 () ;
F_5 () ;
F_14 () ;
V_31 -> V_66 . V_67 = 1000 ;
V_31 -> V_53 = F_24 ( 0 ) ;
V_31 -> V_34 = V_31 -> F_18 = V_31 -> V_53 ;
for ( V_63 = 0 ; V_63 < V_68 ; V_63 ++ ) {
V_11 [ V_63 ] . V_69 = V_10 [ V_63 ] . V_50 ;
V_11 [ V_63 ] . V_70 = V_63 ;
}
V_11 [ V_63 ] . V_69 = V_71 ;
for ( V_63 = 0 ; V_63 < V_72 ; V_63 ++ ) {
V_13 [ V_63 ] . V_69 =
V_12 [ V_63 ] . V_50 ;
V_13 [ V_63 ] . V_70 = V_63 ;
}
V_13 [ V_63 ] . V_69 = V_71 ;
V_9 = ! ! V_9 ;
for ( V_63 = 0 ; V_63 < V_73 ; V_63 ++ ) {
V_27 = V_14 [ V_63 ] . V_50 ;
if ( V_27 > V_16 )
break;
V_15 [ V_63 ] . V_69 = V_27 ;
V_15 [ V_63 ] . V_70 = V_63 ;
}
V_15 [ V_63 ] . V_70 = V_63 ;
V_15 [ V_63 ] . V_69 = V_71 ;
if ( F_10 () ) {
F_9 ( & V_64 , & V_65 ) ;
F_8 ( L_9 ,
V_9 ? L_10 : L_11 ) ;
F_31 ( V_31 , V_64 ) ;
}
else if ( F_2 () )
F_31 ( V_31 , V_15 ) ;
F_13 ( V_17 L_12 ) ;
return 0 ;
}
static int T_2 F_32 ( void )
{
int V_2 = - V_74 ;
if ( F_10 () || F_2 () )
V_2 = F_33 ( & V_75 ) ;
return V_2 ;
}
static void T_5 F_34 ( void )
{
F_35 ( & V_75 ) ;
}
