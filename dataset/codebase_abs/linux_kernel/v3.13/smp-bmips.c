static void T_1 F_1 ( void )
{
int V_1 , V_2 = 1 , V_3 = 0 ;
#if F_2 ( V_4 ) || F_2 ( V_5 )
int V_6 ;
F_3 ( 0x30 ) ;
F_4 ( 0x30000 ) ;
V_3 = ! ! ( F_5 () & ( 1 << 31 ) ) ;
if ( V_3 == 0 )
V_6 = 0x02 ;
else
V_6 = 0x1d ;
F_6 ( 0xf8018000 , ( V_6 << 27 ) | ( 0x03 << 15 ) ) ;
V_7 = 2 ;
#elif F_2 ( V_8 )
F_7 ( 0x03 << 22 ) ;
F_8 ( 0x1f << 27 , 0x02 << 27 ) ;
V_7 = ( ( ( F_9 () >> 6 ) & 0x03 ) + 1 ) << 1 ;
for ( V_1 = 0 ; V_1 < V_7 ; V_1 ++ ) {
F_10 ( F_11 ( V_1 , 0 ) ) ;
F_10 ( F_11 ( V_1 , 1 ) ) ;
}
#endif
if ( ! V_9 )
V_7 = 1 ;
if ( ! V_10 )
V_10 = & V_11 ;
V_12 [ V_3 ] = 0 ;
V_13 [ 0 ] = V_3 ;
for ( V_1 = 0 ; V_1 < V_7 ; V_1 ++ ) {
if ( V_1 != V_3 ) {
V_12 [ V_1 ] = V_2 ;
V_13 [ V_2 ] = V_1 ;
V_2 ++ ;
}
F_12 ( V_1 , 1 ) ;
F_13 ( V_1 , 1 ) ;
}
}
static void F_14 ( unsigned int V_7 )
{
if ( F_15 ( V_14 , V_15 , V_16 ,
L_1 , NULL ) )
F_16 ( L_2 ) ;
if ( F_15 ( V_17 , V_15 , V_16 ,
L_3 , NULL ) )
F_16 ( L_4 ) ;
}
static void F_17 ( int V_2 , struct V_18 * V_19 )
{
V_20 = F_18 ( V_19 ) ;
V_21 = ( unsigned long ) F_19 ( V_19 ) ;
F_20 () ;
F_21 ( L_5 , V_2 ) ;
if ( F_22 ( V_2 , & V_22 ) )
F_23 ( V_2 , 0 ) ;
else {
#if F_2 ( V_4 ) || F_2 ( V_5 )
if ( F_24 ( V_2 ) == 1 )
F_25 ( 0x01 ) ;
#elif F_2 ( V_8 )
if ( V_2 & 0x01 )
F_10 ( F_26 ( V_2 ) ) ;
else {
F_27 ( 0x210 , 0xc0000000 ) ;
F_28 ( 10 ) ;
F_27 ( 0x210 , 0x00 ) ;
}
#endif
F_29 ( V_2 , & V_22 ) ;
}
}
static void F_30 ( void )
{
#if F_2 ( V_4 ) || F_2 ( V_5 )
void T_2 * V_23 = F_31 () ;
unsigned long V_24 ;
unsigned long V_25 ;
int V_3 ;
V_3 = ! ! ( F_5 () & ( 1 << 31 ) ) ;
V_25 = V_3 ? V_26 :
V_27 ;
V_24 = F_32 ( V_23 + V_25 ) ;
F_33 ( V_24 & ~ 0x20000000 , V_23 + V_25 ) ;
F_34 ( F_35 () ? V_28 : V_29 ) ;
#elif F_2 ( V_8 )
F_36 ( F_37 () &
( F_35 () & 0x01 ? ~ 0x20000000 : ~ 0x2000 ) ) ;
F_10 ( F_11 ( F_35 () , 0 ) ) ;
#endif
}
static void F_38 ( void )
{
F_21 ( L_6 , F_35 () ) ;
F_39 ( F_40 () + V_30 / V_31 ) ;
F_41 () ;
F_42 ( V_32 | V_33 | V_34 | V_35 | V_36 ) ;
F_41 () ;
}
static void F_43 ( void )
{
}
static void F_23 ( int V_2 , unsigned int V_37 )
{
F_10 ( F_44 ( V_2 , V_37 == V_38 ) ) ;
}
static T_3 V_15 ( int V_39 , void * V_40 )
{
int V_37 = V_39 - V_14 ;
F_10 ( F_11 ( F_35 () , V_37 ) ) ;
if ( V_37 == 0 )
F_45 () ;
else
F_46 () ;
return V_41 ;
}
static void F_23 ( int V_2 , unsigned int V_37 )
{
unsigned long V_42 ;
F_47 ( & V_43 , V_42 ) ;
F_48 ( V_2 ? V_28 : V_29 ) ;
F_49 ( V_44 , V_2 ) |= V_37 ;
F_41 () ;
F_50 ( & V_43 , V_42 ) ;
}
static T_3 V_15 ( int V_39 , void * V_40 )
{
unsigned long V_42 ;
int V_37 , V_2 = V_39 - V_14 ;
F_47 ( & V_43 , V_42 ) ;
V_37 = F_51 ( V_44 ) ;
F_49 ( V_44 , V_2 ) = 0 ;
F_34 ( V_2 ? V_28 : V_29 ) ;
F_50 ( & V_43 , V_42 ) ;
if ( V_37 & V_45 )
F_45 () ;
if ( V_37 & V_38 )
F_46 () ;
return V_41 ;
}
static void F_52 ( const struct V_46 * V_47 ,
unsigned int V_37 )
{
unsigned int V_1 ;
F_53 (i, mask)
F_23 ( V_1 , V_37 ) ;
}
static int F_54 ( void )
{
unsigned int V_2 = F_35 () ;
if ( V_2 == 0 )
return - V_48 ;
F_21 ( L_7 , V_2 ) ;
F_55 ( V_2 , false ) ;
F_56 ( V_2 , V_49 ) ;
F_57 () ;
F_58 ( 0 , ~ 0 ) ;
return 0 ;
}
static void F_59 ( unsigned int V_2 )
{
}
void T_4 F_60 ( void )
{
F_61 () ;
F_62 ( 0 , ~ 0 ) ;
F_34 ( V_50 | V_29 | V_28 ) ;
F_63 ( V_35 | V_34 | V_32 | V_33 | V_36 | V_51 ,
V_32 | V_33 | V_36 | V_51 ) ;
F_64 () ;
__asm__ __volatile__(
" wait\n"
" j bmips_secondary_reentry\n"
: : : "memory");
}
static void F_65 ( unsigned long V_52 , char * V_53 , char * V_54 )
{
memcpy ( ( void * ) V_52 , V_53 , V_54 - V_53 ) ;
F_66 ( ( unsigned long ) V_53 , V_54 - V_53 ) ;
F_58 ( V_52 , V_52 + ( V_54 - V_53 ) ) ;
F_67 () ;
}
static inline void F_68 ( void )
{
F_65 ( V_55 , & V_56 ,
& V_57 ) ;
F_65 ( V_58 , & V_59 ,
& V_60 ) ;
}
void V_11 ( void )
{
unsigned long V_61 = V_62 ;
void T_2 T_5 * V_23 ;
F_69 ( V_62 != V_63 ) ;
#if F_2 ( V_4 )
F_70 ( V_58 - V_63 ,
& V_59 , 0x80 ) ;
F_71 () ;
return;
#elif F_2 ( V_5 )
V_61 = 0x80000400 ;
V_23 = F_31 () ;
F_33 ( 0x80080800 , V_23 + V_26 ) ;
F_33 ( 0xa0080800 , V_23 + V_27 ) ;
#elif F_2 ( V_8 )
V_61 = 0x80001000 ;
F_36 ( 0xa0088008 ) ;
F_72 ( V_61 ) ;
if ( V_7 > 2 )
F_27 ( 0xa0 , 0xa008a008 ) ;
#else
return;
#endif
V_64 = & F_68 ;
V_62 = V_61 ;
}
T_6 void __weak F_73 ( void )
{
}
