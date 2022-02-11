static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
int V_6 ;
V_7 = V_4 -> V_8 ;
V_9 = V_4 -> V_10 ;
V_11 = V_4 -> V_12 ;
for ( V_6 = 0 ; V_6 < V_13 -> V_14 ; ++ V_6 )
V_15 [ V_6 ] = 0x80000000UL - V_2 [ V_6 ] . V_16 ;
if ( V_4 -> V_17 )
V_7 &= ~ V_18 ;
else
V_7 |= V_18 ;
if ( V_4 -> V_19 )
V_7 &= ~ V_20 ;
else
V_7 |= V_20 ;
if ( F_2 ( V_21 ) || F_2 ( V_22 ) ||
F_2 ( V_23 ) || F_2 ( V_24 ) ||
F_2 ( V_25 ) || F_2 ( V_26 ) ||
F_2 ( V_27 ) || F_2 ( V_28 ) )
V_29 = 1 ;
return 0 ;
}
static inline int F_3 ( void )
{
if ( F_2 ( V_21 ) || F_2 ( V_22 ) ||
F_2 ( V_23 ) || F_2 ( V_24 ) ||
F_2 ( V_25 ) || F_2 ( V_26 ) )
return 1 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned int V_8 = V_7 ;
unsigned long V_12 = V_11 ;
F_5 () ;
V_8 |= V_30 ;
F_6 ( V_31 , V_8 ) ;
V_8 |= V_32 | V_33 | V_34 ;
V_8 |= V_35 | V_36 ;
F_6 ( V_31 , V_8 ) ;
F_6 ( V_37 , V_9 ) ;
if ( F_3 () )
V_12 |= V_38 ;
F_6 ( V_39 , V_12 ) ;
F_7 ( L_1 , F_8 () ,
F_9 ( V_31 ) ) ;
F_7 ( L_2 , F_8 () ,
F_9 ( V_37 ) ) ;
F_7 ( L_3 , F_8 () ,
F_9 ( V_39 ) ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_6 ;
unsigned int V_8 ;
F_11 ( F_12 () | V_40 ) ;
for ( V_6 = 0 ; V_6 < V_13 -> V_14 ; ++ V_6 ) {
if ( V_2 [ V_6 ] . V_41 ) {
F_13 ( V_6 , V_15 [ V_6 ] ) ;
} else {
F_13 ( V_6 , 0 ) ;
}
}
V_8 = F_9 ( V_31 ) ;
V_8 &= ~ V_42 ;
V_8 &= ~ V_30 ;
F_6 ( V_31 , V_8 ) ;
V_43 = 1 ;
F_7 ( L_4 , F_8 () , V_8 ) ;
return 0 ;
}
static void F_14 ( void )
{
unsigned int V_8 ;
V_8 = F_9 ( V_31 ) ;
V_8 |= V_30 ;
F_6 ( V_31 , V_8 ) ;
V_43 = 0 ;
F_7 ( L_5 , F_8 () , V_8 ) ;
F_15 () ;
}
static void T_1 F_16 ( void )
{
}
static void T_1 F_17 ( void )
{
}
static void T_1 F_18 ( void )
{
}
static unsigned long F_19 ( struct V_44 * V_45 )
{
unsigned long V_46 = F_9 ( V_47 ) ;
unsigned long V_12 ;
unsigned long V_48 ;
if ( ! V_13 -> V_49 )
return V_46 ;
V_12 = F_9 ( V_39 ) ;
if ( V_29 && ( V_12 & V_38 ) ) {
V_48 = ( ( V_12 & V_50 ) >> V_51 ) ;
if ( V_48 > 1 )
V_46 += 4 * ( V_48 - 1 ) ;
}
if ( F_20 ( V_52 ) &&
( V_12 & V_13 -> V_49 ) )
return * ( ( unsigned long * ) F_16 ) ;
if ( V_12 & V_13 -> V_53 )
return V_46 ;
#ifdef F_21
if ( V_46 >= V_54 . V_55 && V_46 < ( V_54 . V_55 + V_54 . V_56 ) )
return * ( ( unsigned long * ) F_17 ) ;
#endif
if ( V_46 < 0x1000000UL )
return ( unsigned long ) F_22 ( V_46 ) ;
if ( ! F_23 ( V_46 ) )
return * ( ( unsigned long * ) F_18 ) ;
return V_46 ;
}
static int F_24 ( unsigned long V_46 , unsigned long V_12 )
{
int V_57 ;
if ( ! V_13 -> V_49 ) {
V_57 = F_23 ( V_46 ) ;
} else {
V_57 = ( ( V_12 & V_13 -> V_53 ) == 0 ) ;
}
return V_57 ;
}
static bool F_25 ( unsigned long V_58 )
{
if ( ( int ) V_58 < 0 )
return true ;
if ( F_2 ( V_59 ) && ( ( 0x80000000 - V_58 ) <= 256 ) )
return true ;
return false ;
}
static void F_26 ( struct V_44 * V_45 ,
struct V_1 * V_2 )
{
unsigned long V_46 ;
int V_57 ;
int V_58 ;
int V_6 ;
unsigned int V_8 ;
unsigned long V_12 ;
V_12 = F_9 ( V_39 ) ;
V_46 = F_19 ( V_45 ) ;
V_57 = F_24 ( V_46 , V_12 ) ;
F_11 ( F_12 () | V_40 ) ;
for ( V_6 = 0 ; V_6 < V_13 -> V_14 ; ++ V_6 ) {
V_58 = F_27 ( V_6 ) ;
if ( F_25 ( V_58 ) ) {
if ( V_43 && V_2 [ V_6 ] . V_41 ) {
F_28 ( V_46 , V_45 , V_6 , V_57 ) ;
F_13 ( V_6 , V_15 [ V_6 ] ) ;
} else {
F_13 ( V_6 , 0 ) ;
}
}
}
V_8 = F_9 ( V_31 ) ;
V_8 |= V_33 ;
V_8 &= ~ V_42 ;
V_12 &= ~ V_13 -> V_60 ;
F_6 ( V_39 , V_12 ) ;
V_8 &= ~ V_30 ;
F_6 ( V_31 , V_8 ) ;
}
