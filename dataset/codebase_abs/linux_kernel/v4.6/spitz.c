static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
if ( ! F_3 () )
F_2 ( & V_2 ) ;
}
static void T_2 F_4 ( T_3 V_3 , T_3 V_4 )
{
unsigned short V_5 ;
unsigned long V_6 ;
if ( V_4 & 0x7 ) {
F_5 ( V_7 , 1 ) ;
F_6 ( 5 ) ;
}
F_7 ( V_6 ) ;
V_5 = F_8 ( & V_1 . V_8 , V_9 ) ;
if ( V_3 & V_4 )
V_5 |= V_4 ;
else
V_5 &= ~ V_3 ;
F_9 ( & V_1 . V_8 , V_9 , V_5 ) ;
F_10 ( V_6 ) ;
if ( ! ( V_5 & 0x7 ) ) {
F_6 ( 1 ) ;
F_5 ( V_7 , 0 ) ;
}
}
static inline void F_1 ( void ) {}
static inline void F_4 ( T_3 V_3 , T_3 V_4 ) {}
static void F_11 ( struct V_10 * V_11 , T_4 V_5 , int V_12 )
{
if ( V_12 == 0 )
F_4 (
V_5 & ( V_13 | V_14 ) , V_5 ) ;
else
F_9 ( V_11 , V_9 , V_5 ) ;
}
static void T_1 F_12 ( void )
{
if ( F_3 () )
V_15 . V_16 = 1 ;
V_17 = & V_15 ;
}
static inline void F_12 ( void ) {}
static void T_1 F_13 ( void )
{
F_2 ( & V_18 ) ;
}
static inline void F_13 ( void ) {}
static void T_1 F_14 ( void )
{
F_2 ( & V_19 ) ;
}
static inline void F_14 ( void ) {}
static void T_1 F_15 ( void )
{
F_2 ( & V_20 ) ;
}
static inline void F_15 ( void ) {}
static void F_16 ( void )
{
while ( F_17 ( V_21 ) )
F_18 () ;
while ( ! F_17 ( V_21 ) )
F_18 () ;
}
static void F_19 ( void )
{
void (* F_20)( void );
F_20 = F_21 ( V_22 ) ;
if ( F_20 ) {
F_20 () ;
F_22 ( V_22 ) ;
}
}
static void T_1 F_23 ( void )
{
struct V_23 * V_24 = & V_25 ;
if ( F_3 () ) {
V_24 -> V_26 = V_27 ;
V_24 -> V_28 = V_29 ;
}
F_24 ( 2 , & V_30 ) ;
F_25 ( F_26 ( V_31 ) ) ;
}
static inline void F_23 ( void ) {}
static int F_27 ( struct V_10 * V_8 , unsigned int V_32 )
{
struct V_33 * V_34 = V_8 -> V_35 ;
if ( ( 1 << V_32 ) & V_34 -> V_36 )
F_4 ( V_37 , V_37 ) ;
else
F_4 ( V_37 , 0x0 ) ;
return 0 ;
}
static void T_1 F_28 ( void )
{
F_29 ( & V_38 ) ;
}
static inline void F_28 ( void ) {}
static int F_30 ( struct V_10 * V_8 )
{
int V_39 ;
V_39 = F_31 ( V_40 , L_1 ) ;
if ( V_39 )
return V_39 ;
V_41 = V_42 | V_43 | V_44 | V_45 ;
return F_32 ( V_40 , 1 ) ;
}
static void F_33 ( struct V_10 * V_8 )
{
F_34 ( V_40 ) ;
}
static void T_1 F_35 ( void )
{
F_36 ( & V_46 ) ;
}
static inline void F_35 ( void ) {}
static void T_1 F_37 ( void )
{
if ( F_3 () )
V_47 . V_48 = V_49 ;
else
V_47 . V_48 = V_50 ;
F_38 ( & V_47 ) ;
}
static inline void F_37 ( void ) {}
static void T_1 F_39 ( void )
{
F_40 ( NULL , & V_51 ) ;
}
static inline void F_39 ( void ) {}
static void T_1 F_41 ( void )
{
if ( F_42 () ) {
V_52 [ 1 ] . V_53 = 5 * 1024 * 1024 ;
} else if ( F_3 () ) {
V_52 [ 1 ] . V_53 = 58 * 1024 * 1024 ;
V_54 . V_55 = 1 ;
V_56 . V_57 = & V_58 ;
} else if ( F_43 () ) {
V_52 [ 1 ] . V_53 = 32 * 1024 * 1024 ;
V_54 . V_55 = 1 ;
V_56 . V_57 = & V_58 ;
}
F_2 ( & V_59 ) ;
}
static inline void F_41 ( void ) {}
static void T_1 F_44 ( void )
{
F_2 ( & V_60 ) ;
}
static inline void F_44 ( void ) {}
static void T_1 F_45 ( void )
{
int V_53 = F_46 ( V_61 ) ;
if ( ! F_3 () )
V_53 -- ;
F_47 ( NULL ) ;
F_48 ( NULL ) ;
F_49 ( 0 , V_61 , V_53 ) ;
F_49 ( 1 , F_26 ( V_62 ) ) ;
}
static inline void F_45 ( void ) {}
static inline void F_50 ( void )
{
F_51 ( L_2 , - 1 , NULL , 0 ) ;
}
static void F_52 ( void )
{
F_53 ( V_63 , NULL ) ;
}
static void F_54 ( enum V_64 V_65 , const char * V_66 )
{
T_5 V_67 = F_55 ( V_68 ) ;
if ( ( V_67 & 0xffff0000 ) == 0x7ff00000 )
F_56 ( ( V_67 & 0xffff ) | 0x7ee00000 , V_68 ) ;
F_52 () ;
}
static void T_1 F_57 ( void )
{
F_58 ( V_69 , 1 , 0 ) ;
V_70 = F_52 ;
V_71 = 0x00 ;
V_72 |= V_73 ;
F_59 ( F_26 ( V_74 ) ) ;
F_60 ( NULL ) ;
F_61 ( NULL ) ;
F_62 ( NULL ) ;
F_23 () ;
F_1 () ;
F_13 () ;
F_14 () ;
F_15 () ;
F_28 () ;
F_12 () ;
F_37 () ;
F_35 () ;
F_39 () ;
F_44 () ;
F_41 () ;
F_45 () ;
F_50 () ;
F_63 () ;
}
static void T_1 F_64 ( struct V_75 * V_76 , char * * V_77 )
{
F_65 () ;
F_66 ( 0xa0000000 , V_78 ) ;
}
