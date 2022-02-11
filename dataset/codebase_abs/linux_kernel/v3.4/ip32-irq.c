static void inline F_1 ( void )
{
V_1 -> V_2 ;
}
static void inline F_2 ( void )
{
V_3 -> V_4 . V_5 . V_6 ;
}
static inline void F_3 ( struct V_7 * V_8 )
{
unsigned int V_9 = V_8 -> V_10 - V_11 ;
V_12 |= 1 << V_9 ;
V_1 -> V_13 = V_12 ;
}
static inline void F_4 ( struct V_7 * V_8 )
{
unsigned int V_9 = V_8 -> V_10 - V_11 ;
V_12 &= ~ ( 1 << V_9 ) ;
V_1 -> V_13 = V_12 ;
F_1 () ;
}
static void F_5 ( struct V_7 * V_8 )
{
unsigned int V_9 = V_8 -> V_10 - V_11 ;
T_1 V_14 ;
V_14 = V_1 -> V_15 ;
V_14 &= ~ ( 1 << V_9 ) ;
V_1 -> V_15 = V_14 ;
F_4 ( V_8 ) ;
}
static void F_6 ( struct V_7 * V_8 )
{
V_16 |= F_7 ( V_8 -> V_10 - V_17 ) ;
V_3 -> V_18 . V_2 = V_16 ;
V_12 |= 1 << ( V_8 -> V_10 - V_11 ) ;
V_1 -> V_13 = V_12 ;
}
static void F_8 ( struct V_7 * V_8 )
{
V_12 &= ~ ( 1 << ( V_8 -> V_10 - V_11 ) ) ;
V_1 -> V_13 = V_12 ;
F_1 () ;
V_16 &= ~ F_7 ( V_8 -> V_10 - V_17 ) ;
V_3 -> V_18 . V_2 = V_16 ;
F_2 () ;
}
static void F_9 ( struct V_7 * V_8 )
{
unsigned int V_14 = 0 ;
F_10 ( L_1 , V_8 -> V_10 ) ;
switch ( V_8 -> V_10 ) {
case V_19 ... V_20 :
V_14 = V_21 ;
break;
case V_22 ... V_23 :
V_14 = V_24 ;
break;
case V_25 ... V_26 :
V_14 = V_27 ;
break;
}
F_10 ( L_2 , V_14 ) ;
V_12 |= V_14 ;
V_1 -> V_13 = V_12 ;
V_28 |= 1 << ( V_8 -> V_10 - V_19 ) ;
V_3 -> V_4 . V_5 . V_13 = V_28 ;
}
static void F_11 ( struct V_7 * V_8 )
{
unsigned int V_14 = 0 ;
V_28 &= ~ ( 1 << ( V_8 -> V_10 - V_19 ) ) ;
if ( ! ( V_28 & V_29 ) )
V_14 |= V_21 ;
if ( ! ( V_28 & V_30 ) )
V_14 |= V_24 ;
if ( ! ( V_28 & V_31 ) )
V_14 |= V_27 ;
V_12 &= ~ V_14 ;
V_1 -> V_13 = V_12 ;
F_1 () ;
V_3 -> V_4 . V_5 . V_13 = V_28 ;
F_2 () ;
}
static void F_12 ( struct V_7 * V_8 )
{
unsigned long V_32 ;
V_32 = V_3 -> V_4 . V_5 . V_33 ;
V_32 &= ~ ( 1 << ( V_8 -> V_10 - V_19 ) ) ;
V_3 -> V_4 . V_5 . V_33 = V_32 ;
F_11 ( V_8 ) ;
}
static void F_13 ( struct V_7 * V_8 )
{
unsigned int V_9 = V_8 -> V_10 - V_11 ;
V_12 |= ( 1 << V_9 ) ;
V_1 -> V_13 = V_12 ;
}
static void F_14 ( struct V_7 * V_8 )
{
unsigned int V_9 = V_8 -> V_10 - V_11 ;
V_12 &= ~ ( 1 << V_9 ) ;
V_1 -> V_13 = V_12 ;
F_1 () ;
}
static void F_15 ( void )
{
F_16 ( L_3 ) ;
F_16 ( L_4 , F_17 () ) ;
F_16 ( L_5 , F_18 () ) ;
F_16 ( L_6 , V_1 -> V_13 ) ;
F_16 ( L_7 , V_1 -> V_33 ) ;
F_16 ( L_8 , V_1 -> V_15 ) ;
F_16 ( L_9 , V_3 -> V_4 . V_5 . V_13 ) ;
F_16 ( L_10 , V_3 -> V_4 . V_5 . V_33 ) ;
F_16 ( L_11 , V_3 -> V_18 . V_2 ) ;
F_16 ( L_12 ) ;
F_19 ( F_20 () ) ;
F_16 ( L_13 ) ;
F_16 ( L_14 ) ;
while( 1 ) ;
}
static void F_21 ( void )
{
T_1 V_14 ;
int V_10 = 0 ;
F_22 ( V_34 - V_35 != 31 ) ;
F_22 ( V_26 - V_19 != 31 ) ;
V_14 = V_1 -> V_33 & V_12 ;
if ( F_23 ( V_14 == 0 ) )
return;
V_10 = V_35 + F_24 ( V_14 ) ;
if ( V_14 & V_36 ) {
unsigned long V_32 = V_3 -> V_4 . V_5 . V_33 ;
V_10 = F_24 ( V_32 & V_28 ) + V_19 ;
}
F_10 ( L_15 , V_10 ) ;
F_25 ( V_10 ) ;
}
static void F_26 ( void )
{
F_15 () ;
}
static void F_27 ( void )
{
F_15 () ;
}
static void F_28 ( void )
{
F_15 () ;
}
static void F_29 ( void )
{
F_15 () ;
}
static void F_30 ( void )
{
F_25 ( V_37 + 7 ) ;
}
T_2 void F_31 ( void )
{
unsigned int V_38 = F_17 () & F_18 () ;
if ( F_32 ( V_38 & V_39 ) )
F_21 () ;
else if ( F_23 ( V_38 & V_40 ) )
F_26 () ;
else if ( F_23 ( V_38 & V_41 ) )
F_27 () ;
else if ( F_23 ( V_38 & V_42 ) )
F_28 () ;
else if ( F_23 ( V_38 & V_43 ) )
F_29 () ;
else if ( F_32 ( V_38 & V_44 ) )
F_30 () ;
}
void T_3 F_33 ( void )
{
unsigned int V_10 ;
V_1 -> V_13 = 0 ;
V_1 -> V_15 = 0 ;
V_1 -> V_45 = 0 ;
V_3 -> V_4 . V_5 . V_33 = 0 ;
V_3 -> V_4 . V_5 . V_13 = 0 ;
F_34 () ;
for ( V_10 = V_11 ; V_10 <= V_46 ; V_10 ++ ) {
switch ( V_10 ) {
case V_35 ... V_47 :
F_35 ( V_10 ,
& V_48 ,
V_49 ,
L_16 ) ;
break;
case V_17 ... V_50 :
F_35 ( V_10 ,
& V_51 ,
V_49 ,
L_16 ) ;
break;
case V_52 :
case V_53 :
F_35 ( V_10 ,
& V_54 ,
V_49 ,
L_16 ) ;
break;
case V_55 ... V_56 :
case V_57 ... V_58 :
case V_59 ... V_60 :
case V_34 :
F_35 ( V_10 ,
& V_61 ,
V_62 ,
L_17 ) ;
break;
case V_25 :
case V_63 :
case V_64 :
F_35 ( V_10 ,
& V_65 ,
V_62 ,
L_17 ) ;
break;
default:
F_35 ( V_10 ,
& V_66 ,
V_49 ,
L_16 ) ;
break;
}
}
F_36 ( V_53 , & V_67 ) ;
F_36 ( V_52 , & V_68 ) ;
#define F_37 (IE_IRQ0 | IE_IRQ1 | IE_IRQ2 | IE_IRQ3 | IE_IRQ4 | IE_IRQ5)
F_38 ( V_69 , F_37 ) ;
}
