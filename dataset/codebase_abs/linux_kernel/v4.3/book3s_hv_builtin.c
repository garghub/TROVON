static int T_1 F_1 ( char * V_1 )
{
F_2 ( L_1 , V_2 , V_1 ) ;
if ( ! V_1 )
return - V_3 ;
return F_3 ( V_1 , 0 , & V_4 ) ;
}
struct V_5 * F_4 ( unsigned long V_6 )
{
F_5 ( F_6 ( V_6 ) < V_7 - V_8 ) ;
return F_7 ( V_9 , V_6 , F_6 ( V_10 ) ) ;
}
void F_8 ( struct V_5 * V_5 , unsigned long V_6 )
{
F_9 ( V_9 , V_5 , V_6 ) ;
}
void T_1 F_10 ( void )
{
unsigned long V_11 ;
struct V_12 * V_13 ;
T_2 V_14 = 0 ;
if ( ! F_11 ( V_15 ) )
return;
F_12 (memory, reg)
V_14 += F_13 ( V_13 ) -
F_14 ( V_13 ) ;
V_14 = ( V_14 * V_4 / 100 ) << V_8 ;
if ( V_14 ) {
F_2 ( L_2 , V_2 ,
( unsigned long ) V_14 / V_16 ) ;
V_11 = V_10 << V_8 ;
F_15 ( 0 , V_14 , 0 , V_11 ,
V_7 - V_8 , false , & V_9 ) ;
}
}
long int F_16 ( struct V_17 * V_18 , int V_19 ,
unsigned int V_20 )
{
struct V_21 * V_22 = V_23 -> V_24 . V_25 ;
int V_26 = V_23 -> V_24 . V_26 ;
int V_27 ;
int V_28 ;
int V_29 ;
T_3 V_30 = F_17 () + 10 * V_31 ;
int V_32 = V_33 ;
F_18 ( V_26 , & V_22 -> V_34 ) ;
while ( ( F_17 () < V_30 ) && ! F_19 ( V_22 ) ) {
V_27 = F_20 ( V_22 ) ;
V_28 = V_22 -> V_35 ;
V_29 = V_22 -> V_34 ;
if ( ( V_28 | V_29 ) == V_27 ) {
V_32 = V_36 ;
break;
}
}
F_21 ( V_26 , & V_22 -> V_34 ) ;
return V_32 ;
}
void F_22 ( void )
{
F_23 () ;
F_24 ( & V_37 ) ;
F_25 () ;
}
void F_26 ( void )
{
F_23 () ;
F_27 ( & V_37 ) ;
F_25 () ;
}
bool F_28 ( void )
{
return F_29 ( & V_37 ) != 0 ;
}
int F_30 ( unsigned long V_38 )
{
V_38 /= 4 ;
if ( V_38 < V_39 - V_40 &&
V_40 [ V_38 ] )
return 1 ;
return 0 ;
}
int F_31 ( void )
{
return F_32 () ;
}
long F_33 ( struct V_17 * V_18 )
{
if ( F_34 ( & V_18 -> V_41 . V_42 [ 4 ] ) )
return V_33 ;
return V_43 ;
}
static inline void F_35 ( unsigned long V_44 , T_4 V_45 )
{
__asm__ __volatile__("stbcix %0,0,%1"
: : "r" (val), "r" (paddr) : "memory");
}
void F_36 ( int V_46 )
{
unsigned long V_47 ;
if ( F_11 ( V_48 ) &&
F_37 ( V_46 ) ==
F_37 ( F_38 () ) ) {
unsigned long V_49 = F_39 ( V_50 ) ;
V_49 |= F_40 ( V_46 ) ;
__asm__ __volatile__ (PPC_MSGSND(%0) : : "r" (msg));
return;
}
V_47 = V_51 [ V_46 ] . V_24 . V_47 ;
F_35 ( V_47 + V_52 , V_53 ) ;
}
static void F_41 ( struct V_21 * V_22 , int V_54 )
{
int V_46 = V_22 -> V_55 ;
F_42 () ;
for (; V_54 ; V_54 >>= 1 , ++ V_46 )
if ( V_54 & 1 )
F_36 ( V_46 ) ;
}
void F_43 ( int V_56 )
{
struct V_21 * V_22 = V_23 -> V_24 . V_25 ;
int V_26 = V_23 -> V_24 . V_26 ;
struct V_57 * V_58 = V_23 -> V_24 . V_57 ;
int V_59 , V_60 , V_61 ;
V_59 = 0x100 << V_26 ;
do {
V_60 = V_22 -> V_62 ;
} while ( F_44 ( & V_22 -> V_62 , V_60 , V_60 | V_59 ) != V_60 );
if ( ( V_60 >> 8 ) != 0 )
return;
if ( V_56 != V_63 )
F_41 ( V_22 , V_60 & ~ ( 1 << V_26 ) ) ;
if ( ! V_58 )
return;
for ( V_61 = 0 ; V_61 < V_64 ; ++ V_61 ) {
V_22 = V_58 -> V_65 [ V_61 ] ;
if ( ! V_22 )
break;
do {
V_60 = V_22 -> V_62 ;
if ( ( V_60 >> 8 ) != 0 )
break;
} while ( F_44 ( & V_22 -> V_62 , V_60 ,
V_60 | V_66 ) != V_60 );
if ( ( V_60 >> 8 ) == 0 )
F_41 ( V_22 , V_60 ) ;
}
}
