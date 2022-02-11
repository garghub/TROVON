static void F_1 ( unsigned long V_1 )
{
}
static inline void F_2 ( void )
{
asm volatile ("synci 0($0)");
}
static void F_3 ( unsigned long V_2 ,
unsigned long V_3 )
{
F_2 () ;
}
static void F_4 ( struct V_4 * V_5 )
{
extern void V_6 ( int V_7 , unsigned int V_8 ) ;
#ifdef F_5
int V_7 ;
T_1 V_9 ;
#endif
F_6 () ;
F_2 () ;
#ifdef F_5
F_7 () ;
V_7 = F_8 () ;
if ( V_5 )
V_9 = * F_9 ( V_5 -> V_10 ) ;
else
V_9 = V_11 ;
F_10 ( V_7 , V_9 ) ;
F_11 (cpu, mask)
V_6 ( V_7 , V_12 ) ;
F_12 () ;
#endif
}
static void F_13 ( void )
{
F_4 ( NULL ) ;
}
static void F_14 ( struct V_13 * V_14 )
{
}
static void F_15 ( unsigned long V_2 , unsigned long V_3 )
{
F_4 ( NULL ) ;
}
static void F_16 ( unsigned long V_1 )
{
struct V_4 * V_5 ;
V_5 = F_17 ( V_15 -> V_14 , V_1 ) ;
F_4 ( V_5 ) ;
}
static void F_18 ( struct V_4 * V_5 ,
unsigned long V_2 , unsigned long V_3 )
{
if ( V_5 -> V_16 & V_17 )
F_4 ( V_5 ) ;
}
static void F_19 ( struct V_4 * V_5 ,
unsigned long V_18 , unsigned long V_19 )
{
if ( V_5 -> V_16 & V_17 )
F_4 ( V_5 ) ;
}
static void T_2 F_20 ( void )
{
unsigned long V_20 ;
unsigned long V_21 ;
unsigned int V_22 ;
struct V_23 * V_24 = & V_25 ;
V_22 = F_21 () ;
switch ( V_24 -> V_26 ) {
case V_27 :
case V_28 :
V_24 -> V_29 . V_30 = 2 << ( ( V_22 >> 19 ) & 7 ) ;
V_24 -> V_29 . V_31 = 64 << ( ( V_22 >> 22 ) & 7 ) ;
V_24 -> V_29 . V_32 = 1 + ( ( V_22 >> 16 ) & 7 ) ;
V_24 -> V_29 . V_33 |= V_34 ;
V_20 =
V_24 -> V_29 . V_31 * V_24 -> V_29 . V_32 * V_24 -> V_29 . V_30 ;
V_24 -> V_29 . V_35 = F_22 ( V_20 / V_24 -> V_29 . V_32 ) - 1 ;
V_24 -> V_36 . V_30 = 128 ;
if ( V_24 -> V_26 == V_28 )
V_24 -> V_36 . V_31 = 2 ;
else
V_24 -> V_36 . V_31 = 1 ;
V_24 -> V_36 . V_32 = 64 ;
V_21 =
V_24 -> V_36 . V_31 * V_24 -> V_36 . V_32 * V_24 -> V_36 . V_30 ;
V_24 -> V_36 . V_35 = F_22 ( V_21 / V_24 -> V_36 . V_32 ) - 1 ;
V_24 -> V_37 |= V_38 ;
break;
case V_39 :
V_24 -> V_29 . V_30 = 2 << ( ( V_22 >> 19 ) & 7 ) ;
V_24 -> V_29 . V_31 = 8 ;
V_24 -> V_29 . V_32 = 37 ;
V_24 -> V_29 . V_33 |= V_34 ;
V_20 = V_24 -> V_29 . V_31 * V_24 -> V_29 . V_32 * V_24 -> V_29 . V_30 ;
V_24 -> V_36 . V_30 = 128 ;
V_24 -> V_36 . V_32 = 32 ;
V_24 -> V_36 . V_31 = 8 ;
V_21 = V_24 -> V_36 . V_31 * V_24 -> V_36 . V_32 * V_24 -> V_36 . V_30 ;
V_24 -> V_37 |= V_38 ;
break;
default:
F_23 ( L_1 ) ;
break;
}
V_24 -> V_29 . V_40 = V_20 / V_24 -> V_29 . V_32 ;
V_24 -> V_36 . V_40 = V_21 / V_24 -> V_36 . V_32 ;
V_24 -> V_29 . V_31 = V_20 / ( V_24 -> V_29 . V_30 * V_24 -> V_29 . V_32 ) ;
V_24 -> V_36 . V_31 = V_21 / ( V_24 -> V_36 . V_30 * V_24 -> V_36 . V_32 ) ;
if ( F_8 () == 0 ) {
F_24 ( L_2
L_3 ,
V_20 >> 10 ,
V_41 ?
L_4 : L_5 ,
V_24 -> V_29 . V_32 , V_24 -> V_29 . V_31 , V_24 -> V_29 . V_30 ) ;
F_24 ( L_6
L_7 ,
V_21 >> 10 , V_24 -> V_36 . V_32 ,
V_24 -> V_36 . V_31 , V_24 -> V_36 . V_30 ) ;
}
}
void T_2 F_25 ( void )
{
extern unsigned long V_42 ;
extern char V_43 ;
memcpy ( ( void * ) ( V_42 + 0x100 ) , & V_43 , 0x80 ) ;
F_16 ( V_42 + 0x100 ) ;
F_20 () ;
V_44 = V_45 - 1 ;
V_46 = F_13 ;
V_47 = F_13 ;
V_48 = F_14 ;
V_49 = F_19 ;
V_50 = F_18 ;
V_51 = F_16 ;
V_52 = F_13 ;
V_53 = F_1 ;
V_54 = F_15 ;
V_55 = F_3 ;
F_26 () ;
F_27 () ;
}
static void F_28 ( int V_56 )
{
unsigned long V_57 = F_29 () ;
T_3 V_58 = F_30 () ;
F_31 ( L_8 ) ;
F_31 ( L_9 , F_32 () ) ;
if ( V_58 & 1 ) {
F_31 ( L_10 ,
( unsigned long long ) V_58 ) ;
F_33 ( 0 ) ;
}
if ( V_59 [ V_57 ] & 1 ) {
F_31 ( L_11 ,
( unsigned long long ) V_59 [ V_57 ] ) ;
V_59 [ V_57 ] = 0 ;
}
if ( V_56 )
F_23 ( L_12 ) ;
}
T_4 void F_34 ( void )
{
F_28 ( 0 ) ;
}
T_4 void F_35 ( void )
{
F_28 ( 1 ) ;
}
