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
struct V_21 * V_22 = V_18 -> V_23 . V_24 ;
int V_25 ;
int V_26 ;
int V_27 ;
T_3 V_28 = F_17 () + 10 * V_29 ;
int V_30 = V_31 ;
F_18 ( V_18 -> V_23 . V_32 , & V_22 -> V_33 ) ;
while ( ( F_17 () < V_28 ) && ! F_19 ( V_22 ) ) {
V_25 = F_20 ( V_22 ) ;
V_26 = V_22 -> V_34 ;
V_27 = V_22 -> V_33 ;
if ( ( V_26 | V_27 ) == V_25 ) {
V_30 = V_35 ;
break;
}
}
F_21 ( V_18 -> V_23 . V_32 , & V_22 -> V_33 ) ;
return V_30 ;
}
void F_22 ( void )
{
F_23 () ;
F_24 ( & V_36 ) ;
F_25 () ;
}
void F_26 ( void )
{
F_23 () ;
F_27 ( & V_36 ) ;
F_25 () ;
}
bool F_28 ( void )
{
return F_29 ( & V_36 ) != 0 ;
}
int F_30 ( unsigned long V_37 )
{
V_37 /= 4 ;
if ( V_37 < V_38 - V_39 &&
V_39 [ V_37 ] )
return 1 ;
return 0 ;
}
int F_31 ( void )
{
return F_32 () ;
}
long F_33 ( struct V_17 * V_18 )
{
if ( F_34 ( & V_18 -> V_23 . V_40 [ 4 ] ) )
return V_31 ;
return V_41 ;
}
static inline void F_35 ( unsigned long V_42 , T_4 V_43 )
{
__asm__ __volatile__("stbcix %0,0,%1"
: : "r" (val), "r" (paddr) : "memory");
}
void F_36 ( int V_44 )
{
unsigned long V_45 ;
if ( F_11 ( V_46 ) &&
F_37 ( V_44 ) ==
F_37 ( F_38 () ) ) {
unsigned long V_47 = F_39 ( V_48 ) ;
V_47 |= F_40 ( V_44 ) ;
__asm__ __volatile__ (PPC_MSGSND(%0) : : "r" (msg));
return;
}
V_45 = V_49 [ V_44 ] . V_50 . V_45 ;
F_35 ( V_45 + V_51 , V_52 ) ;
}
static void F_41 ( struct V_21 * V_22 , int V_53 )
{
int V_44 = V_22 -> V_54 ;
F_42 () ;
for (; V_53 ; V_53 >>= 1 , ++ V_44 )
if ( V_53 & 1 )
F_36 ( V_44 ) ;
}
void F_43 ( int V_55 )
{
struct V_21 * V_22 = V_56 -> V_50 . V_57 ;
int V_32 = V_56 -> V_50 . V_32 ;
int V_58 , V_59 ;
V_58 = 0x100 << V_32 ;
do {
V_59 = V_22 -> V_60 ;
} while ( F_44 ( & V_22 -> V_60 , V_59 , V_59 | V_58 ) != V_59 );
if ( ( V_59 >> 8 ) != 0 )
return;
if ( V_55 != V_61 )
F_41 ( V_22 , V_59 & ~ ( 1 << V_32 ) ) ;
}
