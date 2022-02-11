static inline unsigned long
F_1 ( volatile unsigned long * V_1 , unsigned long V_2 )
{
__asm__ __volatile__("swap [%1], %0\n\t" :
"=&r" (val), "=&r" (ptr) :
"0" (val), "1" (ptr));
return V_2 ;
}
void F_2 ( void * V_3 )
{
}
void F_3 ( void * V_3 )
{
int V_4 = F_4 () ;
F_1 ( & V_5 [ V_4 ] , 1 ) ;
V_6 -> V_7 () ;
V_6 -> V_8 () ;
__asm__ __volatile__("ld [%0], %%g6\n\t"
: : "r" (&current_set[cpuid])
: "memory" );
F_5 ( & V_9 ) ;
V_10 -> V_11 = & V_9 ;
while ( ! F_6 ( V_4 , & V_12 ) )
F_7 () ;
}
void T_1 F_8 ( void )
{
F_9 () ;
V_6 -> V_7 () ;
}
int F_10 ( int V_13 , struct V_14 * V_15 )
{
unsigned long * V_16 = & V_17 ;
int V_18 ;
int V_19 ;
F_11 ( V_13 , & V_19 ) ;
V_20 [ V_13 ] = F_12 ( V_15 ) ;
V_16 += ( ( V_13 - 1 ) * 3 ) ;
V_21 . V_22 = 0 ;
V_21 . V_23 = ( unsigned int ) V_24 ;
V_21 . V_25 = 0 ;
F_13 ( V_26 L_1 , V_13 , V_16 ) ;
V_6 -> V_7 () ;
F_14 ( V_19 , & V_21 , 0 , ( char * ) V_16 ) ;
for ( V_18 = 0 ; V_18 < 10000 ; V_18 ++ ) {
if ( V_5 [ V_13 ] )
break;
F_15 ( 200 ) ;
}
if ( ! ( V_5 [ V_13 ] ) ) {
F_13 ( V_27 L_2 , V_13 ) ;
return - V_28 ;
}
V_6 -> V_7 () ;
return 0 ;
}
void T_1 F_16 ( void )
{
int V_13 , V_29 ;
int * V_30 ;
V_29 = 0 ;
V_30 = & V_29 ;
F_17 (i) {
* V_30 = V_13 ;
V_30 = & F_18 ( V_13 ) . V_31 ;
}
* V_30 = V_29 ;
V_6 -> V_7 () ;
}
static void F_19 ( int V_32 , int V_33 )
{
F_20 ( F_21 ( V_33 ) , & V_34 [ V_32 ] -> V_35 ) ;
}
static void F_22 ( int V_32 )
{
F_19 ( V_32 , V_36 ) ;
}
static void F_23 ( int V_32 )
{
F_19 ( V_32 , V_37 ) ;
}
static void F_24 ( int V_32 )
{
F_19 ( V_32 , V_38 ) ;
}
static void F_25 ( T_2 V_39 , T_3 V_40 , unsigned long V_41 ,
unsigned long V_42 , unsigned long V_43 ,
unsigned long V_44 )
{
register int V_45 = V_46 ;
unsigned long V_47 ;
F_26 ( & V_48 , V_47 ) ;
V_49 . V_39 = V_39 ;
V_49 . V_41 = V_41 ;
V_49 . V_42 = V_42 ;
V_49 . V_43 = V_43 ;
V_49 . V_44 = V_44 ;
V_49 . V_50 = 0 ;
{
register int V_13 ;
F_27 ( F_28 () , & V_40 ) ;
F_29 ( & V_40 , V_51 , & V_40 ) ;
for ( V_13 = 0 ; V_13 < V_45 ; V_13 ++ ) {
if ( F_6 ( V_13 , & V_40 ) ) {
V_49 . V_52 [ V_13 ] = 0 ;
V_49 . V_53 [ V_13 ] = 0 ;
F_19 ( V_13 , V_54 ) ;
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
if ( ! F_6 ( V_13 , & V_40 ) )
continue;
while ( ! V_49 . V_52 [ V_13 ] )
F_30 () ;
} while ( ++ V_13 < V_45 );
V_13 = 0 ;
do {
if ( ! F_6 ( V_13 , & V_40 ) )
continue;
while ( ! V_49 . V_53 [ V_13 ] )
F_30 () ;
} while ( ++ V_13 < V_45 );
}
F_31 ( & V_48 , V_47 ) ;
}
void F_32 ( void )
{
int V_13 = F_28 () ;
V_49 . V_52 [ V_13 ] = 1 ;
V_49 . V_39 ( V_49 . V_41 , V_49 . V_42 , V_49 . V_43 ,
V_49 . V_44 , V_49 . V_50 ) ;
V_49 . V_53 [ V_13 ] = 1 ;
}
void F_33 ( struct V_55 * V_56 )
{
struct V_55 * V_57 ;
struct V_58 * V_59 ;
int V_32 = F_28 () ;
V_57 = F_34 ( V_56 ) ;
V_59 = & F_35 ( V_60 , V_32 ) ;
if ( F_36 ( V_59 ) )
F_37 ( V_32 ) ;
else
V_61 . V_62 ( V_32 , 0 ) ;
F_38 () ;
V_59 -> V_63 ( V_59 ) ;
F_39 () ;
F_34 ( V_57 ) ;
}
void T_1 F_40 ( void )
{
V_64 = & V_65 ;
}
