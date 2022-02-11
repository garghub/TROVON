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
int V_9 ;
F_6 ( V_10 , F_7 ( V_10 ) ) ;
V_9 = F_8 ( & V_11 ) ;
if ( V_9 ) {
F_9 ( V_12 L_1 , V_9 ) ;
F_10 ( V_10 ,
F_7 ( V_10 ) ) ;
}
}
static int F_11 ( struct V_13 * V_14 , T_2 V_15 , void * V_16 )
{
int V_17 ;
V_18 &= ~ V_19 ;
V_17 = F_12 ( V_20 , V_15 , 0 ,
L_2 , V_16 ) ;
if ( V_17 )
F_9 ( V_12 L_3 ) ;
return V_17 ;
}
static int F_13 ( struct V_13 * V_14 , unsigned int V_21 )
{
struct V_22 * V_23 = V_14 -> V_24 ;
if ( ( 1 << V_21 ) & V_23 -> V_25 ) {
F_9 ( V_26 L_4 , V_27 ) ;
V_18 |= V_28 ;
V_18 &= ~ V_19 ;
} else {
F_9 ( V_26 L_5 , V_27 ) ;
V_18 &= ~ V_28 ;
}
return 0 ;
}
static void F_14 ( struct V_13 * V_14 , void * V_16 )
{
F_15 ( V_20 , V_16 ) ;
}
static void F_16 ( struct V_13 * V_14 , int V_29 )
{
unsigned long V_30 ;
F_17 ( V_30 ) ;
if ( V_29 & V_31 ) {
V_18 &= ~ V_32 ;
} else if ( V_29 & V_33 ) {
V_18 |= V_32 ;
}
F_18 ( V_14 , V_29 ) ;
if ( V_29 & V_34 ) {
V_18 = ( V_18 & ~ V_35 ) | V_36 ;
} else {
V_18 = ( V_18 & ~ V_35 ) | V_37 ;
}
F_19 ( V_30 ) ;
}
static void T_1 F_20 ( void )
{
F_21 ( & V_38 ) ;
}
static inline void F_20 ( void ) {}
static void T_1 F_22 ( void )
{
int V_39 = 0 ;
F_23 ( F_24 ( V_40 ) ) ;
F_25 ( NULL ) ;
F_26 ( NULL ) ;
F_27 ( NULL ) ;
V_41 [ 0 ] . V_42 = ( F_28 ( V_43 ) & 1 ) ? 2 : 4 ;
V_41 [ 1 ] . V_42 = 4 ;
V_41 [ V_39 ] . V_44 = L_6 ;
V_41 [ V_39 ^ 1 ] . V_44 = L_7 ;
F_9 ( V_45 L_8 ,
V_41 [ 0 ] . V_44 ) ;
V_46 = V_47 | 0x234 ;
F_29 ( V_48 , F_7 ( V_48 ) ) ;
if ( 0 )
V_49 . V_50 = & V_51 ;
else
V_49 . V_50 = & V_52 ;
F_30 ( NULL , & V_49 ) ;
F_5 () ;
F_31 ( & V_53 ) ;
F_32 ( & V_54 ) ;
F_33 ( & V_55 ) ;
F_34 ( NULL ) ;
F_35 ( & V_56 ) ;
F_20 () ;
}
static void T_1 F_36 ( void )
{
F_37 () ;
F_38 ( V_57 , F_7 ( V_57 ) ) ;
V_58 |= 0xF04 ;
V_59 = 0x66 ;
}
static void F_39 ( struct V_60 * V_61 ,
enum V_62 V_63 )
{
struct V_64 * V_65 = F_40 ( V_61 ,
struct V_64 , V_61 ) ;
T_3 V_66 = V_67 ;
if ( V_63 != V_68 )
V_66 |= V_65 -> V_69 ;
else
V_66 &= ~ V_65 -> V_69 ;
V_67 = V_66 ;
}
static enum V_62 F_41 ( struct V_60 * V_61 )
{
struct V_64 * V_65 = F_40 ( V_61 ,
struct V_64 , V_61 ) ;
T_3 V_66 = V_67 ;
return ( V_66 & V_65 -> V_69 ) ? V_70 : V_68 ;
}
static int T_1 F_42 ( void )
{
int V_71 ;
if ( ! F_43 () )
return - V_72 ;
V_67 |= 0xff ;
for ( V_71 = 0 ; V_71 < F_7 ( V_73 ) ; V_71 ++ ) {
struct V_64 * V_65 ;
V_65 = F_44 ( sizeof( * V_65 ) , V_74 ) ;
if ( ! V_65 )
break;
V_65 -> V_61 . V_44 = V_73 [ V_71 ] . V_44 ;
V_65 -> V_61 . V_75 = F_39 ;
V_65 -> V_61 . V_76 = F_41 ;
V_65 -> V_61 . V_77 = V_73 [ V_71 ] . V_78 ;
V_65 -> V_69 = F_45 ( V_71 ) ;
if ( F_46 ( NULL , & V_65 -> V_61 ) < 0 ) {
F_47 ( V_65 ) ;
break;
}
}
return 0 ;
}
