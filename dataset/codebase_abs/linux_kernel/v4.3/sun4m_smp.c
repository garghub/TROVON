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
F_5 ( & V_9 . V_10 ) ;
V_11 -> V_12 = & V_9 ;
while ( ! F_6 ( V_4 , & V_13 ) )
F_7 () ;
}
void T_1 F_8 ( void )
{
F_9 () ;
V_6 -> V_7 () ;
}
int F_10 ( int V_14 , struct V_15 * V_16 )
{
unsigned long * V_17 = & V_18 ;
int V_19 ;
int V_20 ;
F_11 ( V_14 , & V_20 ) ;
V_21 [ V_14 ] = F_12 ( V_16 ) ;
V_17 += ( ( V_14 - 1 ) * 3 ) ;
V_22 . V_23 = 0 ;
V_22 . V_24 = ( unsigned int ) V_25 ;
V_22 . V_26 = 0 ;
F_13 ( V_27 L_1 , V_14 , V_17 ) ;
V_6 -> V_7 () ;
F_14 ( V_20 , & V_22 , 0 , ( char * ) V_17 ) ;
for ( V_19 = 0 ; V_19 < 10000 ; V_19 ++ ) {
if ( V_5 [ V_14 ] )
break;
F_15 ( 200 ) ;
}
if ( ! ( V_5 [ V_14 ] ) ) {
F_13 ( V_28 L_2 , V_14 ) ;
return - V_29 ;
}
V_6 -> V_7 () ;
return 0 ;
}
void T_1 F_16 ( void )
{
int V_14 , V_30 ;
int * V_31 ;
V_30 = 0 ;
V_31 = & V_30 ;
F_17 (i) {
* V_31 = V_14 ;
V_31 = & F_18 ( V_14 ) . V_32 ;
}
* V_31 = V_30 ;
V_6 -> V_7 () ;
}
static void F_19 ( int V_33 , int V_34 )
{
F_20 ( F_21 ( V_34 ) , & V_35 [ V_33 ] -> V_36 ) ;
}
static void F_22 ( int V_33 )
{
F_19 ( V_33 , V_37 ) ;
}
static void F_23 ( int V_33 )
{
F_19 ( V_33 , V_38 ) ;
}
static void F_24 ( int V_33 )
{
F_19 ( V_33 , V_39 ) ;
}
static void F_25 ( T_2 V_40 , T_3 V_41 , unsigned long V_42 ,
unsigned long V_43 , unsigned long V_44 ,
unsigned long V_45 )
{
register int V_46 = V_47 ;
unsigned long V_48 ;
F_26 ( & V_49 , V_48 ) ;
V_50 . V_40 = V_40 ;
V_50 . V_42 = V_42 ;
V_50 . V_43 = V_43 ;
V_50 . V_44 = V_44 ;
V_50 . V_45 = V_45 ;
V_50 . V_51 = 0 ;
{
register int V_14 ;
F_27 ( F_28 () , & V_41 ) ;
F_29 ( & V_41 , V_52 , & V_41 ) ;
for ( V_14 = 0 ; V_14 < V_46 ; V_14 ++ ) {
if ( F_6 ( V_14 , & V_41 ) ) {
V_50 . V_53 [ V_14 ] = 0 ;
V_50 . V_54 [ V_14 ] = 0 ;
F_19 ( V_14 , V_55 ) ;
} else {
V_50 . V_53 [ V_14 ] = 1 ;
V_50 . V_54 [ V_14 ] = 1 ;
}
}
}
{
register int V_14 ;
V_14 = 0 ;
do {
if ( ! F_6 ( V_14 , & V_41 ) )
continue;
while ( ! V_50 . V_53 [ V_14 ] )
F_30 () ;
} while ( ++ V_14 < V_46 );
V_14 = 0 ;
do {
if ( ! F_6 ( V_14 , & V_41 ) )
continue;
while ( ! V_50 . V_54 [ V_14 ] )
F_30 () ;
} while ( ++ V_14 < V_46 );
}
F_31 ( & V_49 , V_48 ) ;
}
void F_32 ( void )
{
int V_14 = F_28 () ;
V_50 . V_53 [ V_14 ] = 1 ;
V_50 . V_40 ( V_50 . V_42 , V_50 . V_43 , V_50 . V_44 ,
V_50 . V_45 , V_50 . V_51 ) ;
V_50 . V_54 [ V_14 ] = 1 ;
}
void F_33 ( struct V_56 * V_57 )
{
struct V_56 * V_58 ;
struct V_59 * V_60 ;
int V_33 = F_28 () ;
V_58 = F_34 ( V_57 ) ;
V_60 = & F_35 ( V_61 , V_33 ) ;
if ( F_36 ( V_60 ) )
F_37 ( V_33 ) ;
else
V_62 . V_63 ( V_33 , 0 ) ;
F_38 () ;
V_60 -> V_64 ( V_60 ) ;
F_39 () ;
F_34 ( V_58 ) ;
}
void T_1 F_40 ( void )
{
V_65 = & V_66 ;
}
