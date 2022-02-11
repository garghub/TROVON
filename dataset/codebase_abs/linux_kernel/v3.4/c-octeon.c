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
V_9 = * V_11 ;
F_10 ( V_7 , & V_9 ) ;
F_11 (cpu, &mask)
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
static void F_20 ( unsigned long V_20 , int V_21 )
{
F_21 () ;
}
static void T_2 F_22 ( void )
{
unsigned long V_22 ;
unsigned long V_23 ;
unsigned int V_24 ;
struct V_25 * V_26 = & V_27 ;
V_24 = F_23 () ;
switch ( V_26 -> V_28 ) {
case V_29 :
case V_30 :
V_26 -> V_31 . V_32 = 2 << ( ( V_24 >> 19 ) & 7 ) ;
V_26 -> V_31 . V_33 = 64 << ( ( V_24 >> 22 ) & 7 ) ;
V_26 -> V_31 . V_34 = 1 + ( ( V_24 >> 16 ) & 7 ) ;
V_26 -> V_31 . V_35 |= V_36 ;
V_22 =
V_26 -> V_31 . V_33 * V_26 -> V_31 . V_34 * V_26 -> V_31 . V_32 ;
V_26 -> V_31 . V_37 = F_24 ( V_22 / V_26 -> V_31 . V_34 ) - 1 ;
V_26 -> V_38 . V_32 = 128 ;
if ( V_26 -> V_28 == V_30 )
V_26 -> V_38 . V_33 = 2 ;
else
V_26 -> V_38 . V_33 = 1 ;
V_26 -> V_38 . V_34 = 64 ;
V_23 =
V_26 -> V_38 . V_33 * V_26 -> V_38 . V_34 * V_26 -> V_38 . V_32 ;
V_26 -> V_38 . V_37 = F_24 ( V_23 / V_26 -> V_38 . V_34 ) - 1 ;
V_26 -> V_39 |= V_40 ;
break;
case V_41 :
V_26 -> V_31 . V_32 = 2 << ( ( V_24 >> 19 ) & 7 ) ;
V_26 -> V_31 . V_33 = 8 ;
V_26 -> V_31 . V_34 = 37 ;
V_26 -> V_31 . V_35 |= V_36 ;
V_22 = V_26 -> V_31 . V_33 * V_26 -> V_31 . V_34 * V_26 -> V_31 . V_32 ;
V_26 -> V_38 . V_32 = 128 ;
V_26 -> V_38 . V_34 = 32 ;
V_26 -> V_38 . V_33 = 8 ;
V_23 = V_26 -> V_38 . V_33 * V_26 -> V_38 . V_34 * V_26 -> V_38 . V_32 ;
V_26 -> V_39 |= V_40 ;
break;
default:
F_25 ( L_1 ) ;
break;
}
V_26 -> V_31 . V_42 = V_22 / V_26 -> V_31 . V_34 ;
V_26 -> V_38 . V_42 = V_23 / V_26 -> V_38 . V_34 ;
V_26 -> V_31 . V_33 = V_22 / ( V_26 -> V_31 . V_32 * V_26 -> V_31 . V_34 ) ;
V_26 -> V_38 . V_33 = V_23 / ( V_26 -> V_38 . V_32 * V_26 -> V_38 . V_34 ) ;
if ( F_8 () == 0 ) {
F_26 ( L_2
L_3 ,
V_22 >> 10 ,
V_43 ?
L_4 : L_5 ,
V_26 -> V_31 . V_34 , V_26 -> V_31 . V_33 , V_26 -> V_31 . V_32 ) ;
F_26 ( L_6
L_7 ,
V_23 >> 10 , V_26 -> V_38 . V_34 ,
V_26 -> V_38 . V_33 , V_26 -> V_38 . V_32 ) ;
}
}
void T_2 F_27 ( void )
{
extern unsigned long V_44 ;
extern char V_45 ;
memcpy ( ( void * ) ( V_44 + 0x100 ) , & V_45 , 0x80 ) ;
F_16 ( V_44 + 0x100 ) ;
F_22 () ;
V_46 = V_47 - 1 ;
V_48 = F_13 ;
V_49 = F_13 ;
V_50 = F_14 ;
V_51 = F_19 ;
V_52 = F_18 ;
V_53 = F_16 ;
V_54 = F_13 ;
V_55 = F_1 ;
V_56 = F_15 ;
V_57 = F_3 ;
V_58 = F_20 ;
F_28 () ;
F_29 () ;
}
static void F_30 ( int V_59 )
{
unsigned long V_60 = F_31 () ;
T_3 V_61 = F_32 () ;
F_33 ( L_8 ) ;
F_33 ( L_9 , F_34 () ) ;
if ( V_61 & 1 ) {
F_33 ( L_10 ,
( unsigned long long ) V_61 ) ;
F_35 ( 0 ) ;
}
if ( V_62 [ V_60 ] & 1 ) {
F_33 ( L_11 ,
( unsigned long long ) V_62 [ V_60 ] ) ;
V_62 [ V_60 ] = 0 ;
}
if ( V_59 )
F_25 ( L_12 ) ;
}
T_4 void F_36 ( void )
{
F_30 ( 0 ) ;
}
T_4 void F_37 ( void )
{
F_30 ( 1 ) ;
}
