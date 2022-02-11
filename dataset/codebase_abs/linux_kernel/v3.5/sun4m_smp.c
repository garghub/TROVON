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
V_4 -> V_5 () ;
V_4 -> V_6 () ;
F_4 ( V_3 ) ;
F_5 ( V_3 ) ;
F_6 () ;
F_7 ( V_3 ) ;
V_4 -> V_5 () ;
V_4 -> V_6 () ;
F_1 ( & V_7 [ V_3 ] , 1 ) ;
V_4 -> V_5 () ;
V_4 -> V_6 () ;
__asm__ __volatile__("ld [%0], %%g6\n\t"
: : "r" (&current_set[cpuid])
: "memory" );
F_8 ( & V_8 . V_9 ) ;
V_10 -> V_11 = & V_8 ;
while ( ! F_9 ( V_3 , & V_12 ) )
F_10 () ;
F_11 () ;
F_12 ( V_3 , true ) ;
}
void T_2 F_13 ( void )
{
F_14 () ;
V_4 -> V_5 () ;
}
int T_1 F_15 ( int V_13 , struct V_14 * V_15 )
{
unsigned long * V_16 = & V_17 ;
int V_18 ;
int V_19 ;
F_16 ( V_13 , & V_19 ) ;
V_20 [ V_13 ] = F_17 ( V_15 ) ;
V_16 += ( ( V_13 - 1 ) * 3 ) ;
V_21 . V_22 = 0 ;
V_21 . V_23 = ( unsigned int ) V_24 ;
V_21 . V_25 = 0 ;
F_18 ( V_26 L_1 , V_13 , V_16 ) ;
V_4 -> V_5 () ;
F_19 ( V_19 , & V_21 , 0 , ( char * ) V_16 ) ;
for ( V_18 = 0 ; V_18 < 10000 ; V_18 ++ ) {
if ( V_7 [ V_13 ] )
break;
F_20 ( 200 ) ;
}
if ( ! ( V_7 [ V_13 ] ) ) {
F_18 ( V_27 L_2 , V_13 ) ;
return - V_28 ;
}
V_4 -> V_5 () ;
return 0 ;
}
void T_2 F_21 ( void )
{
int V_13 , V_29 ;
int * V_30 ;
V_29 = 0 ;
V_30 = & V_29 ;
F_22 (i) {
* V_30 = V_13 ;
V_30 = & F_23 ( V_13 ) . V_31 ;
}
* V_30 = V_29 ;
V_4 -> V_5 () ;
}
static void F_24 ( int V_32 , int V_33 )
{
F_25 ( F_26 ( V_33 ) , & V_34 [ V_32 ] -> V_35 ) ;
}
static void F_27 ( int V_32 )
{
F_24 ( V_32 , V_36 ) ;
}
static void F_28 ( int V_32 )
{
F_24 ( V_32 , V_37 ) ;
}
static void F_29 ( int V_32 )
{
F_24 ( V_32 , V_38 ) ;
}
static void F_30 ( T_3 V_39 , T_4 V_40 , unsigned long V_41 ,
unsigned long V_42 , unsigned long V_43 ,
unsigned long V_44 )
{
register int V_45 = V_46 ;
unsigned long V_47 ;
F_31 ( & V_48 , V_47 ) ;
V_49 . V_39 = V_39 ;
V_49 . V_41 = V_41 ;
V_49 . V_42 = V_42 ;
V_49 . V_43 = V_43 ;
V_49 . V_44 = V_44 ;
V_49 . V_50 = 0 ;
{
register int V_13 ;
F_32 ( F_33 () , & V_40 ) ;
F_34 ( & V_40 , V_51 , & V_40 ) ;
for ( V_13 = 0 ; V_13 < V_45 ; V_13 ++ ) {
if ( F_9 ( V_13 , & V_40 ) ) {
V_49 . V_52 [ V_13 ] = 0 ;
V_49 . V_53 [ V_13 ] = 0 ;
F_24 ( V_13 , V_54 ) ;
} else {
V_49 . V_52 [ V_13 ] = 1 ;
V_49 . V_53 [ V_13 ] = 1 ;
}
}
}
{
register int V_13 ;
V_13 = 0 ;
do {
if ( ! F_9 ( V_13 , & V_40 ) )
continue;
while ( ! V_49 . V_52 [ V_13 ] )
F_35 () ;
} while ( ++ V_13 < V_45 );
V_13 = 0 ;
do {
if ( ! F_9 ( V_13 , & V_40 ) )
continue;
while ( ! V_49 . V_53 [ V_13 ] )
F_35 () ;
} while ( ++ V_13 < V_45 );
}
F_36 ( & V_48 , V_47 ) ;
}
void F_37 ( void )
{
int V_13 = F_33 () ;
V_49 . V_52 [ V_13 ] = 1 ;
V_49 . V_39 ( V_49 . V_41 , V_49 . V_42 , V_49 . V_43 ,
V_49 . V_44 , V_49 . V_50 ) ;
V_49 . V_53 [ V_13 ] = 1 ;
}
void F_38 ( struct V_55 * V_56 )
{
struct V_55 * V_57 ;
struct V_58 * V_59 ;
int V_32 = F_33 () ;
V_57 = F_39 ( V_56 ) ;
V_59 = & F_40 ( V_60 , V_32 ) ;
if ( V_59 -> V_61 & V_62 )
F_41 ( V_32 ) ;
else
V_63 . V_64 ( V_32 , 0 ) ;
F_42 () ;
V_59 -> V_65 ( V_59 ) ;
F_43 () ;
F_39 ( V_57 ) ;
}
void T_2 F_44 ( void )
{
V_66 = & V_67 ;
}
