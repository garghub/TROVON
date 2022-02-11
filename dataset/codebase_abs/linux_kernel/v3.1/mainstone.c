static void F_1 ( struct V_1 * V_2 )
{
int V_3 = ( V_2 -> V_4 - F_2 ( 0 ) ) ;
V_5 = ( V_6 &= ~ ( 1 << V_3 ) ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
int V_3 = ( V_2 -> V_4 - F_2 ( 0 ) ) ;
V_7 &= ~ ( 1 << V_3 ) ;
V_5 = ( V_6 |= ( 1 << V_3 ) ) ;
}
static void F_4 ( unsigned int V_4 , struct V_8 * V_9 )
{
unsigned long V_10 = V_7 & V_6 ;
do {
V_9 -> V_1 . V_11 -> V_12 ( & V_9 -> V_1 ) ;
if ( F_5 ( V_10 ) ) {
V_4 = F_2 ( 0 ) + F_6 ( V_10 ) ;
F_7 ( V_4 ) ;
}
V_10 = V_7 & V_6 ;
} while ( V_10 );
}
static void T_1 F_8 ( void )
{
int V_4 ;
F_9 () ;
for( V_4 = F_2 ( 0 ) ; V_4 <= F_2 ( 15 ) ; V_4 ++ ) {
F_10 ( V_4 , & V_13 ,
V_14 ) ;
if ( V_4 == F_2 ( 10 ) || V_4 == F_2 ( 14 ) )
F_11 ( V_4 , V_15 | V_16 | V_17 ) ;
else
F_11 ( V_4 , V_15 | V_16 ) ;
}
F_11 ( F_2 ( 8 ) , 0 ) ;
F_11 ( F_2 ( 12 ) , 0 ) ;
V_5 = 0 ;
V_7 = 0 ;
F_12 ( F_13 ( 0 ) , F_4 ) ;
F_14 ( F_13 ( 0 ) , V_18 ) ;
}
static void F_15 ( void )
{
V_5 = V_6 ;
}
static int T_1 F_16 ( void )
{
if ( F_17 () )
F_18 ( & V_19 ) ;
return 0 ;
}
static int F_19 ( struct V_20 * V_21 , void * V_22 )
{
if ( V_21 -> V_23 == V_24 )
V_25 &= ~ V_26 ;
return 0 ;
}
static void F_20 ( struct V_20 * V_21 , void * V_22 )
{
if ( V_21 -> V_23 == V_24 )
V_25 |= V_26 ;
}
static void F_21 ( void * V_22 )
{
V_27 = V_25 ;
V_25 |= V_26 ;
}
static void F_22 ( void * V_22 )
{
V_25 &= V_27 | ~ V_26 ;
}
static void T_1 F_23 ( void )
{
int V_28 = F_24 ( & V_29 ) ;
if ( V_28 )
F_25 ( V_30 L_1 , V_28 ) ;
}
static int F_26 ( struct V_31 * V_32 , T_2 V_33 , void * V_34 )
{
int V_35 ;
V_36 &= ~ V_37 ;
V_35 = F_27 ( V_38 , V_33 , V_39 ,
L_2 , V_34 ) ;
if ( V_35 )
F_25 ( V_30 L_3 ) ;
return V_35 ;
}
static void F_28 ( struct V_31 * V_32 , unsigned int V_40 )
{
struct V_41 * V_42 = V_32 -> V_43 ;
if ( ( 1 << V_40 ) & V_42 -> V_44 ) {
F_25 ( V_45 L_4 , V_46 ) ;
V_36 |= V_47 ;
V_36 &= ~ V_37 ;
} else {
F_25 ( V_45 L_5 , V_46 ) ;
V_36 &= ~ V_47 ;
}
}
static void F_29 ( struct V_31 * V_32 , void * V_34 )
{
F_30 ( V_38 , V_34 ) ;
}
static void F_31 ( struct V_31 * V_32 , int V_48 )
{
unsigned long V_49 ;
F_32 ( V_49 ) ;
if ( V_48 & V_50 ) {
V_36 &= ~ V_51 ;
} else if ( V_48 & V_52 ) {
V_36 |= V_51 ;
}
F_33 ( V_32 , V_48 ) ;
if ( V_48 & V_53 ) {
V_36 = ( V_36 & ~ V_54 ) | V_55 ;
} else {
V_36 = ( V_36 & ~ V_54 ) | V_56 ;
}
F_34 ( V_49 ) ;
}
static void T_1 F_35 ( void )
{
F_36 ( & V_57 ) ;
}
static inline void F_35 ( void ) {}
static void T_1 F_37 ( void )
{
int V_58 = 0 ;
F_38 ( F_39 ( V_59 ) ) ;
F_40 ( NULL ) ;
F_41 ( NULL ) ;
F_42 ( NULL ) ;
V_60 [ 0 ] . V_61 = ( F_43 ( V_62 ) & 1 ) ? 2 : 4 ;
V_60 [ 1 ] . V_61 = 4 ;
V_60 [ V_58 ] . V_63 = L_6 ;
V_60 [ V_58 ^ 1 ] . V_63 = L_7 ;
F_25 ( V_64 L_8 ,
V_60 [ 0 ] . V_63 ) ;
V_65 = V_66 | 0x234 ;
F_44 ( V_67 , F_45 ( V_67 ) ) ;
if ( 0 )
V_68 . V_69 = & V_70 ;
else
V_68 . V_69 = & V_71 ;
F_46 ( NULL , & V_68 ) ;
F_23 () ;
F_47 ( & V_72 ) ;
F_48 ( & V_73 ) ;
F_49 ( & V_74 ) ;
F_50 ( NULL ) ;
F_51 ( & V_75 ) ;
F_35 () ;
}
static void T_1 F_52 ( void )
{
F_53 () ;
F_54 ( V_76 , F_45 ( V_76 ) ) ;
V_77 |= 0xF04 ;
V_78 = 0x66 ;
}
