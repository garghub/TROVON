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
V_35 = F_27 ( V_38 , V_33 , 0 ,
L_2 , V_34 ) ;
if ( V_35 )
F_25 ( V_30 L_3 ) ;
return V_35 ;
}
static int F_28 ( struct V_31 * V_32 , unsigned int V_39 )
{
struct V_40 * V_41 = V_32 -> V_42 ;
if ( ( 1 << V_39 ) & V_41 -> V_43 ) {
F_25 ( V_44 L_4 , V_45 ) ;
V_36 |= V_46 ;
V_36 &= ~ V_37 ;
} else {
F_25 ( V_44 L_5 , V_45 ) ;
V_36 &= ~ V_46 ;
}
return 0 ;
}
static void F_29 ( struct V_31 * V_32 , void * V_34 )
{
F_30 ( V_38 , V_34 ) ;
}
static void F_31 ( struct V_31 * V_32 , int V_47 )
{
unsigned long V_48 ;
F_32 ( V_48 ) ;
if ( V_47 & V_49 ) {
V_36 &= ~ V_50 ;
} else if ( V_47 & V_51 ) {
V_36 |= V_50 ;
}
F_33 ( V_32 , V_47 ) ;
if ( V_47 & V_52 ) {
V_36 = ( V_36 & ~ V_53 ) | V_54 ;
} else {
V_36 = ( V_36 & ~ V_53 ) | V_55 ;
}
F_34 ( V_48 ) ;
}
static void T_1 F_35 ( void )
{
F_36 ( & V_56 ) ;
}
static inline void F_35 ( void ) {}
static void T_1 F_37 ( void )
{
int V_57 = 0 ;
F_38 ( F_39 ( V_58 ) ) ;
F_40 ( NULL ) ;
F_41 ( NULL ) ;
F_42 ( NULL ) ;
V_59 [ 0 ] . V_60 = ( F_43 ( V_61 ) & 1 ) ? 2 : 4 ;
V_59 [ 1 ] . V_60 = 4 ;
V_59 [ V_57 ] . V_62 = L_6 ;
V_59 [ V_57 ^ 1 ] . V_62 = L_7 ;
F_25 ( V_63 L_8 ,
V_59 [ 0 ] . V_62 ) ;
V_64 = V_65 | 0x234 ;
F_44 ( V_66 , F_45 ( V_66 ) ) ;
if ( 0 )
V_67 . V_68 = & V_69 ;
else
V_67 . V_68 = & V_70 ;
F_46 ( NULL , & V_67 ) ;
F_23 () ;
F_47 ( & V_71 ) ;
F_48 ( & V_72 ) ;
F_49 ( & V_73 ) ;
F_50 ( NULL ) ;
F_51 ( & V_74 ) ;
F_35 () ;
}
static void T_1 F_52 ( void )
{
F_53 () ;
F_54 ( V_75 , F_45 ( V_75 ) ) ;
V_76 |= 0xF04 ;
V_77 = 0x66 ;
}
static void F_55 ( struct V_78 * V_79 ,
enum V_80 V_81 )
{
struct V_82 * V_83 = F_56 ( V_79 ,
struct V_82 , V_79 ) ;
T_3 V_84 = V_85 ;
if ( V_81 != V_86 )
V_84 |= V_83 -> V_87 ;
else
V_84 &= ~ V_83 -> V_87 ;
V_85 = V_84 ;
}
static enum V_80 F_57 ( struct V_78 * V_79 )
{
struct V_82 * V_83 = F_56 ( V_79 ,
struct V_82 , V_79 ) ;
T_3 V_84 = V_85 ;
return ( V_84 & V_83 -> V_87 ) ? V_88 : V_86 ;
}
static int T_1 F_58 ( void )
{
int V_89 ;
if ( ! F_17 () )
return - V_90 ;
V_85 |= 0xff ;
for ( V_89 = 0 ; V_89 < F_45 ( V_91 ) ; V_89 ++ ) {
struct V_82 * V_83 ;
V_83 = F_59 ( sizeof( * V_83 ) , V_92 ) ;
if ( ! V_83 )
break;
V_83 -> V_79 . V_62 = V_91 [ V_89 ] . V_62 ;
V_83 -> V_79 . V_93 = F_55 ;
V_83 -> V_79 . V_94 = F_57 ;
V_83 -> V_79 . V_95 = V_91 [ V_89 ] . V_96 ;
V_83 -> V_87 = F_60 ( V_89 ) ;
if ( F_61 ( NULL , & V_83 -> V_79 ) < 0 ) {
F_62 ( V_83 ) ;
break;
}
}
return 0 ;
}
