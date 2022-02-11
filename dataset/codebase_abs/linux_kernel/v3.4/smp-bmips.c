static void T_1 F_1 ( void )
{
int V_1 ;
#if F_2 ( V_2 ) || F_2 ( V_3 )
F_3 ( 0x30 ) ;
F_4 ( 0x30000 ) ;
F_5 ( 0xf8018000 ,
( 0x02 << 27 ) | ( 0x03 << 15 ) ) ;
V_4 = 2 ;
#elif F_2 ( V_5 )
F_6 ( 0x03 << 22 ) ;
F_7 ( 0x1f << 27 , 0x02 << 27 ) ;
V_4 = ( ( ( F_8 () >> 6 ) & 0x03 ) + 1 ) << 1 ;
for ( V_1 = 0 ; V_1 < V_4 ; V_1 ++ ) {
F_9 ( F_10 ( V_1 , 0 ) ) ;
F_9 ( F_10 ( V_1 , 1 ) ) ;
}
#endif
if ( ! V_6 )
V_4 = 1 ;
if ( ! V_7 )
V_7 = & V_8 ;
for ( V_1 = 0 ; V_1 < V_4 ; V_1 ++ ) {
V_9 [ V_1 ] = 1 ;
V_10 [ V_1 ] = 1 ;
F_11 ( V_1 , 1 ) ;
F_12 ( V_1 , 1 ) ;
}
}
static void F_13 ( unsigned int V_4 )
{
if ( F_14 ( V_11 , V_12 , V_13 ,
L_1 , NULL ) )
F_15 ( L_2 ) ;
if ( F_14 ( V_14 , V_12 , V_13 ,
L_3 , NULL ) )
F_15 ( L_4 ) ;
}
static void F_16 ( int V_15 , struct V_16 * V_17 )
{
V_18 = F_17 ( V_17 ) ;
V_19 = ( unsigned long ) F_18 ( V_17 ) ;
F_19 () ;
F_20 ( L_5 , V_15 ) ;
if ( F_21 ( V_15 , & V_20 ) )
F_22 ( V_15 , 0 ) ;
else {
#if F_2 ( V_2 ) || F_2 ( V_3 )
F_23 ( 0x01 ) ;
#elif F_2 ( V_5 )
if ( V_15 & 0x01 )
F_9 ( F_24 ( V_15 ) ) ;
else {
F_25 ( 0x210 , 0xc0000000 ) ;
F_26 ( 10 ) ;
F_25 ( 0x210 , 0x00 ) ;
}
#endif
F_27 ( V_15 , & V_20 ) ;
}
}
static void F_28 ( void )
{
#if F_2 ( V_2 ) || F_2 ( V_3 )
void T_2 * V_21 = F_29 () ;
unsigned long V_22 ;
V_22 = F_30 ( V_21 + V_23 ) ;
F_31 ( V_22 & ~ 0x20000000 , V_21 + V_23 ) ;
F_32 ( F_33 () ? V_24 : V_25 ) ;
#elif F_2 ( V_5 )
F_34 ( F_35 () &
( F_33 () & 0x01 ? ~ 0x20000000 : ~ 0x2000 ) ) ;
F_9 ( F_10 ( F_33 () , 0 ) ) ;
#endif
F_36 ( F_37 () + V_26 / V_27 ) ;
F_38 () ;
F_39 ( V_28 | V_29 | V_30 | V_31 | V_32 ) ;
F_38 () ;
}
static void F_40 ( void )
{
F_20 ( L_6 , F_33 () ) ;
}
static void F_41 ( void )
{
}
static void F_22 ( int V_15 , unsigned int V_33 )
{
F_9 ( F_42 ( V_15 , V_33 == V_34 ) ) ;
}
static T_3 V_12 ( int V_35 , void * V_36 )
{
int V_33 = V_35 - V_11 ;
F_9 ( F_10 ( F_33 () , V_33 ) ) ;
if ( V_33 == 0 )
F_43 () ;
else
F_44 () ;
return V_37 ;
}
static void F_22 ( int V_15 , unsigned int V_33 )
{
unsigned long V_38 ;
F_45 ( & V_39 , V_38 ) ;
F_46 ( V_15 ? V_24 : V_25 ) ;
F_47 ( V_40 , V_15 ) |= V_33 ;
F_38 () ;
F_48 ( & V_39 , V_38 ) ;
}
static T_3 V_12 ( int V_35 , void * V_36 )
{
unsigned long V_38 ;
int V_33 , V_15 = V_35 - V_11 ;
F_45 ( & V_39 , V_38 ) ;
V_33 = F_49 ( V_40 ) ;
F_47 ( V_40 , V_15 ) = 0 ;
F_32 ( V_15 ? V_24 : V_25 ) ;
F_48 ( & V_39 , V_38 ) ;
if ( V_33 & V_41 )
F_43 () ;
if ( V_33 & V_34 )
F_44 () ;
return V_37 ;
}
static void F_50 ( const struct V_42 * V_43 ,
unsigned int V_33 )
{
unsigned int V_1 ;
F_51 (i, mask)
F_22 ( V_1 , V_33 ) ;
}
static int F_52 ( void )
{
unsigned int V_15 = F_33 () ;
if ( V_15 == 0 )
return - V_44 ;
F_20 ( L_7 , V_15 ) ;
F_53 ( V_15 , false ) ;
F_54 ( V_15 , V_45 ) ;
F_55 () ;
F_56 ( 0 , ~ 0 ) ;
return 0 ;
}
static void F_57 ( unsigned int V_15 )
{
}
void T_4 F_58 ( void )
{
F_59 () ;
F_60 ( 0 , ~ 0 ) ;
F_32 ( V_46 | V_25 | V_24 ) ;
F_61 ( V_31 | V_30 | V_28 | V_29 | V_32 | V_47 ,
V_28 | V_29 | V_32 | V_47 ) ;
F_62 () ;
__asm__ __volatile__(
" wait\n"
" j bmips_secondary_reentry\n"
: : : "memory");
}
static void T_5 F_63 ( unsigned long V_48 , char * V_49 , char * V_50 )
{
memcpy ( ( void * ) V_48 , V_49 , V_50 - V_49 ) ;
F_64 ( ( unsigned long ) V_49 , V_50 - V_49 ) ;
F_56 ( V_48 , V_48 + ( V_50 - V_49 ) ) ;
F_65 () ;
}
static inline void T_5 F_66 ( void )
{
F_63 ( V_51 , & V_52 ,
& V_53 ) ;
F_63 ( V_54 , & V_55 ,
& V_56 ) ;
}
void T_5 V_8 ( void )
{
unsigned long V_57 = V_58 ;
void T_2 T_6 * V_21 ;
F_67 ( V_58 != V_59 ) ;
#if F_2 ( V_2 )
F_68 ( V_54 - V_59 ,
& V_55 , 0x80 ) ;
F_69 () ;
return;
#elif F_2 ( V_3 )
V_57 = 0x80000400 ;
V_21 = F_29 () ;
F_31 ( 0x80080800 , V_21 + V_60 ) ;
F_31 ( 0xa0080800 , V_21 + V_23 ) ;
#elif F_2 ( V_5 )
V_57 = 0x80001000 ;
F_34 ( 0xa0088008 ) ;
F_70 ( V_57 ) ;
if ( V_4 > 2 )
F_25 ( 0xa0 , 0xa008a008 ) ;
#else
return;
#endif
V_61 = & F_66 ;
V_58 = V_57 ;
}
T_7 void __weak F_71 ( void )
{
}
