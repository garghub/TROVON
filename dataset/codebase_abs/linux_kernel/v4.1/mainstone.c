static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( V_2 -> V_4 == V_5 )
V_6 &= ~ V_7 ;
return 0 ;
}
static void F_2 ( struct V_1 * V_2 , void * V_3 )
{
if ( V_2 -> V_4 == V_5 )
V_6 |= V_7 ;
}
static void F_3 ( void * V_3 )
{
V_8 = V_6 ;
V_6 |= V_7 ;
}
static void F_4 ( void * V_3 )
{
V_6 &= V_8 | ~ V_7 ;
}
static void T_1 F_5 ( void )
{
int V_9 = F_6 ( & V_10 ) ;
if ( V_9 )
F_7 ( V_11 L_1 , V_9 ) ;
}
static int F_8 ( struct V_12 * V_13 , T_2 V_14 , void * V_15 )
{
int V_16 ;
V_17 &= ~ V_18 ;
V_16 = F_9 ( V_19 , V_14 , 0 ,
L_2 , V_15 ) ;
if ( V_16 )
F_7 ( V_11 L_3 ) ;
return V_16 ;
}
static int F_10 ( struct V_12 * V_13 , unsigned int V_20 )
{
struct V_21 * V_22 = V_13 -> V_23 ;
if ( ( 1 << V_20 ) & V_22 -> V_24 ) {
F_7 ( V_25 L_4 , V_26 ) ;
V_17 |= V_27 ;
V_17 &= ~ V_18 ;
} else {
F_7 ( V_25 L_5 , V_26 ) ;
V_17 &= ~ V_27 ;
}
return 0 ;
}
static void F_11 ( struct V_12 * V_13 , void * V_15 )
{
F_12 ( V_19 , V_15 ) ;
}
static void F_13 ( struct V_12 * V_13 , int V_28 )
{
unsigned long V_29 ;
F_14 ( V_29 ) ;
if ( V_28 & V_30 ) {
V_17 &= ~ V_31 ;
} else if ( V_28 & V_32 ) {
V_17 |= V_31 ;
}
F_15 ( V_13 , V_28 ) ;
if ( V_28 & V_33 ) {
V_17 = ( V_17 & ~ V_34 ) | V_35 ;
} else {
V_17 = ( V_17 & ~ V_34 ) | V_36 ;
}
F_16 ( V_29 ) ;
}
static void T_1 F_17 ( void )
{
F_18 ( & V_37 ) ;
}
static inline void F_17 ( void ) {}
static void T_1 F_19 ( void )
{
int V_38 = 0 ;
F_20 ( F_21 ( V_39 ) ) ;
F_22 ( NULL ) ;
F_23 ( NULL ) ;
F_24 ( NULL ) ;
V_40 [ 0 ] . V_41 = ( F_25 ( V_42 ) & 1 ) ? 2 : 4 ;
V_40 [ 1 ] . V_41 = 4 ;
V_40 [ V_38 ] . V_43 = L_6 ;
V_40 [ V_38 ^ 1 ] . V_43 = L_7 ;
F_7 ( V_44 L_8 ,
V_40 [ 0 ] . V_43 ) ;
V_45 = V_46 | 0x234 ;
F_26 ( V_47 , F_27 ( V_47 ) ) ;
if ( 0 )
V_48 . V_49 = & V_50 ;
else
V_48 . V_49 = & V_51 ;
F_28 ( NULL , & V_48 ) ;
F_5 () ;
F_29 ( & V_52 ) ;
F_30 ( & V_53 ) ;
F_31 ( & V_54 ) ;
F_32 ( NULL ) ;
F_33 ( & V_55 ) ;
F_17 () ;
}
static void T_1 F_34 ( void )
{
F_35 () ;
F_36 ( V_56 , F_27 ( V_56 ) ) ;
V_57 |= 0xF04 ;
V_58 = 0x66 ;
}
static void F_37 ( struct V_59 * V_60 ,
enum V_61 V_62 )
{
struct V_63 * V_64 = F_38 ( V_60 ,
struct V_63 , V_60 ) ;
T_3 V_65 = V_66 ;
if ( V_62 != V_67 )
V_65 |= V_64 -> V_68 ;
else
V_65 &= ~ V_64 -> V_68 ;
V_66 = V_65 ;
}
static enum V_61 F_39 ( struct V_59 * V_60 )
{
struct V_63 * V_64 = F_38 ( V_60 ,
struct V_63 , V_60 ) ;
T_3 V_65 = V_66 ;
return ( V_65 & V_64 -> V_68 ) ? V_69 : V_67 ;
}
static int T_1 F_40 ( void )
{
int V_70 ;
if ( ! F_41 () )
return - V_71 ;
V_66 |= 0xff ;
for ( V_70 = 0 ; V_70 < F_27 ( V_72 ) ; V_70 ++ ) {
struct V_63 * V_64 ;
V_64 = F_42 ( sizeof( * V_64 ) , V_73 ) ;
if ( ! V_64 )
break;
V_64 -> V_60 . V_43 = V_72 [ V_70 ] . V_43 ;
V_64 -> V_60 . V_74 = F_37 ;
V_64 -> V_60 . V_75 = F_39 ;
V_64 -> V_60 . V_76 = V_72 [ V_70 ] . V_77 ;
V_64 -> V_68 = F_43 ( V_70 ) ;
if ( F_44 ( NULL , & V_64 -> V_60 ) < 0 ) {
F_45 ( V_64 ) ;
break;
}
}
return 0 ;
}
