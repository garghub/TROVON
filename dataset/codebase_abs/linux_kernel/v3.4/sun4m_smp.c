static inline unsigned long
F_1 ( volatile unsigned long * V_1 , unsigned long V_2 )
{
__asm__ __volatile__("swap [%1], %0\n\t" :
"=&r" (val), "=&r" (ptr) :
"0" (val), "1" (ptr));
return V_2 ;
}
void T_1 F_2 ( void )
{
int V_3 = F_3 () ;
F_4 () ;
F_5 () ;
F_6 ( V_3 ) ;
F_7 () ;
F_8 () ;
F_9 ( V_3 ) ;
F_4 () ;
F_5 () ;
F_1 ( & V_4 [ V_3 ] , 1 ) ;
F_4 () ;
F_5 () ;
__asm__ __volatile__("ld [%0], %%g6\n\t"
: : "r" (&current_set[cpuid])
: "memory" );
F_10 ( & V_5 . V_6 ) ;
V_7 -> V_8 = & V_5 ;
while ( ! F_11 ( V_3 , & V_9 ) )
F_12 () ;
F_13 () ;
F_14 ( V_3 , true ) ;
}
void T_2 F_15 ( void )
{
F_16 () ;
F_7 () ;
F_4 () ;
}
int T_1 F_17 ( int V_10 )
{
unsigned long * V_11 = & V_12 ;
struct V_13 * V_14 ;
int V_15 ;
int V_16 ;
F_18 ( V_10 , & V_16 ) ;
V_14 = F_19 ( V_10 ) ;
V_17 [ V_10 ] = F_20 ( V_14 ) ;
V_11 += ( ( V_10 - 1 ) * 3 ) ;
V_18 . V_19 = 0 ;
V_18 . V_20 = ( unsigned int ) V_21 ;
V_18 . V_22 = 0 ;
F_21 ( V_23 L_1 , V_10 , V_11 ) ;
F_4 () ;
F_22 ( V_16 , & V_18 , 0 , ( char * ) V_11 ) ;
for ( V_15 = 0 ; V_15 < 10000 ; V_15 ++ ) {
if ( V_4 [ V_10 ] )
break;
F_23 ( 200 ) ;
}
if ( ! ( V_4 [ V_10 ] ) ) {
F_21 ( V_24 L_2 , V_10 ) ;
return - V_25 ;
}
F_4 () ;
return 0 ;
}
void T_2 F_24 ( void )
{
int V_10 , V_26 ;
int * V_27 ;
V_26 = 0 ;
V_27 = & V_26 ;
F_25 (i) {
* V_27 = V_10 ;
V_27 = & F_26 ( V_10 ) . V_28 ;
}
* V_27 = V_26 ;
F_4 () ;
}
static void T_2 F_16 ( void )
{
}
static void F_27 ( int V_29 )
{
F_28 ( V_29 , V_30 ) ;
}
static void F_29 ( int V_29 )
{
F_28 ( V_29 , V_31 ) ;
}
static void F_30 ( int V_29 )
{
F_28 ( V_29 , V_32 ) ;
}
static void F_31 ( T_3 V_33 , T_4 V_34 , unsigned long V_35 ,
unsigned long V_36 , unsigned long V_37 ,
unsigned long V_38 )
{
register int V_39 = V_40 ;
unsigned long V_41 ;
F_32 ( & V_42 , V_41 ) ;
V_43 . V_33 = V_33 ;
V_43 . V_35 = V_35 ;
V_43 . V_36 = V_36 ;
V_43 . V_37 = V_37 ;
V_43 . V_38 = V_38 ;
V_43 . V_44 = 0 ;
{
register int V_10 ;
F_33 ( F_34 () , & V_34 ) ;
F_35 ( & V_34 , V_45 , & V_34 ) ;
for ( V_10 = 0 ; V_10 < V_39 ; V_10 ++ ) {
if ( F_11 ( V_10 , & V_34 ) ) {
V_43 . V_46 [ V_10 ] = 0 ;
V_43 . V_47 [ V_10 ] = 0 ;
F_28 ( V_10 , V_48 ) ;
} else {
V_43 . V_46 [ V_10 ] = 1 ;
V_43 . V_47 [ V_10 ] = 1 ;
}
}
}
{
register int V_10 ;
V_10 = 0 ;
do {
if ( ! F_11 ( V_10 , & V_34 ) )
continue;
while ( ! V_43 . V_46 [ V_10 ] )
F_36 () ;
} while ( ++ V_10 < V_39 );
V_10 = 0 ;
do {
if ( ! F_11 ( V_10 , & V_34 ) )
continue;
while ( ! V_43 . V_47 [ V_10 ] )
F_36 () ;
} while ( ++ V_10 < V_39 );
}
F_37 ( & V_42 , V_41 ) ;
}
void F_38 ( void )
{
int V_10 = F_34 () ;
V_43 . V_46 [ V_10 ] = 1 ;
V_43 . V_33 ( V_43 . V_35 , V_43 . V_36 , V_43 . V_37 ,
V_43 . V_38 , V_43 . V_44 ) ;
V_43 . V_47 [ V_10 ] = 1 ;
}
void F_39 ( struct V_49 * V_50 )
{
struct V_49 * V_51 ;
int V_29 = F_34 () ;
V_51 = F_40 ( V_50 ) ;
F_41 ( V_29 ) ;
F_42 ( V_52 ) ;
if ( ! -- F_43 ( V_29 ) ) {
int V_53 = F_44 ( V_50 ) ;
F_45 () ;
F_46 ( V_53 ) ;
F_47 () ;
F_43 ( V_29 ) = F_48 ( V_29 ) ;
}
F_40 ( V_51 ) ;
}
static void T_1 F_7 ( void )
{
int V_29 = F_34 () ;
F_43 ( V_29 ) = F_48 ( V_29 ) = 1 ;
F_49 ( V_29 , V_54 ) ;
if ( V_29 == V_55 )
F_50 () ;
}
static void T_2 F_51 ( unsigned * V_56 )
{
int V_57 = * V_56 & 0x3e000000 ;
int V_58 = V_57 >> 11 ;
V_56 [ 0 ] = 0x81580000 | V_57 ;
V_56 [ 1 ] = 0x8130200c | V_57 | V_58 ;
V_56 [ 2 ] = 0x80082003 | V_57 | V_58 ;
}
static void T_2 F_52 ( unsigned * V_56 )
{
int V_57 = * V_56 & 0x3e000000 ;
int V_58 = V_57 >> 11 ;
V_56 [ 0 ] = 0x81580000 | V_57 ;
V_56 [ 2 ] = 0x8130200a | V_57 | V_58 ;
V_56 [ 4 ] = 0x8008200c | V_57 | V_58 ;
}
void T_2 F_53 ( void )
{
F_54 ( F_3 , F_51 ) ;
F_54 ( V_59 , F_52 ) ;
F_55 ( V_60 , F_31 , V_61 ) ;
F_55 ( V_62 , V_63 , V_61 ) ;
F_55 ( V_64 , F_27 , V_61 ) ;
F_55 ( V_65 , F_29 , V_61 ) ;
F_55 ( V_66 , F_30 , V_61 ) ;
}
