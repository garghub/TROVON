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
F_17 ( & V_15 -> V_14 -> V_16 ) ;
V_5 = F_18 ( V_15 -> V_14 , V_1 ) ;
F_4 ( V_5 ) ;
F_19 ( & V_15 -> V_14 -> V_16 ) ;
}
static void F_20 ( struct V_4 * V_5 ,
unsigned long V_2 , unsigned long V_3 )
{
if ( V_5 -> V_17 & V_18 )
F_4 ( V_5 ) ;
}
static void F_21 ( struct V_4 * V_5 ,
unsigned long V_19 , unsigned long V_20 )
{
if ( V_5 -> V_17 & V_18 )
F_4 ( V_5 ) ;
}
static void F_22 ( unsigned long V_21 , int V_22 )
{
F_23 () ;
}
static void F_24 ( void )
{
unsigned long V_23 ;
unsigned long V_24 ;
unsigned int V_25 ;
struct V_26 * V_27 = & V_28 ;
int V_29 = F_25 () ;
V_25 = F_26 () ;
switch ( V_29 ) {
case V_30 :
case V_31 :
V_27 -> V_32 . V_33 = 2 << ( ( V_25 >> 19 ) & 7 ) ;
V_27 -> V_32 . V_34 = 64 << ( ( V_25 >> 22 ) & 7 ) ;
V_27 -> V_32 . V_35 = 1 + ( ( V_25 >> 16 ) & 7 ) ;
V_27 -> V_32 . V_36 |= V_37 ;
V_23 =
V_27 -> V_32 . V_34 * V_27 -> V_32 . V_35 * V_27 -> V_32 . V_33 ;
V_27 -> V_32 . V_38 = F_27 ( V_23 / V_27 -> V_32 . V_35 ) - 1 ;
V_27 -> V_39 . V_33 = 128 ;
if ( V_29 == V_31 )
V_27 -> V_39 . V_34 = 2 ;
else
V_27 -> V_39 . V_34 = 1 ;
V_27 -> V_39 . V_35 = 64 ;
V_24 =
V_27 -> V_39 . V_34 * V_27 -> V_39 . V_35 * V_27 -> V_39 . V_33 ;
V_27 -> V_39 . V_38 = F_27 ( V_24 / V_27 -> V_39 . V_35 ) - 1 ;
V_27 -> V_40 |= V_41 ;
break;
case V_42 :
V_27 -> V_32 . V_33 = 2 << ( ( V_25 >> 19 ) & 7 ) ;
V_27 -> V_32 . V_34 = 8 ;
V_27 -> V_32 . V_35 = 37 ;
V_27 -> V_32 . V_36 |= V_37 ;
V_23 = V_27 -> V_32 . V_34 * V_27 -> V_32 . V_35 * V_27 -> V_32 . V_33 ;
V_27 -> V_39 . V_33 = 128 ;
V_27 -> V_39 . V_35 = 32 ;
V_27 -> V_39 . V_34 = 8 ;
V_24 = V_27 -> V_39 . V_34 * V_27 -> V_39 . V_35 * V_27 -> V_39 . V_33 ;
V_27 -> V_40 |= V_41 ;
break;
case V_43 :
V_27 -> V_32 . V_33 = 128 ;
V_27 -> V_32 . V_34 = 16 ;
V_27 -> V_32 . V_35 = 39 ;
V_27 -> V_32 . V_36 |= V_37 ;
V_23 = V_27 -> V_32 . V_34 * V_27 -> V_32 . V_35 * V_27 -> V_32 . V_33 ;
V_27 -> V_39 . V_33 = 128 ;
V_27 -> V_39 . V_35 = 32 ;
V_27 -> V_39 . V_34 = 8 ;
V_24 = V_27 -> V_39 . V_34 * V_27 -> V_39 . V_35 * V_27 -> V_39 . V_33 ;
V_27 -> V_40 |= V_41 ;
break;
default:
F_28 ( L_1 ) ;
break;
}
V_27 -> V_32 . V_44 = V_23 / V_27 -> V_32 . V_35 ;
V_27 -> V_39 . V_44 = V_24 / V_27 -> V_39 . V_35 ;
V_27 -> V_32 . V_34 = V_23 / ( V_27 -> V_32 . V_33 * V_27 -> V_32 . V_35 ) ;
V_27 -> V_39 . V_34 = V_24 / ( V_27 -> V_39 . V_33 * V_27 -> V_39 . V_35 ) ;
if ( F_8 () == 0 ) {
F_29 ( L_2
L_3 ,
V_23 >> 10 ,
V_45 ?
L_4 : L_5 ,
V_27 -> V_32 . V_35 , V_27 -> V_32 . V_34 , V_27 -> V_32 . V_33 ) ;
F_29 ( L_6
L_7 ,
V_24 >> 10 , V_27 -> V_39 . V_35 ,
V_27 -> V_39 . V_34 , V_27 -> V_39 . V_33 ) ;
}
}
static void F_30 ( void )
{
extern char V_46 ;
F_31 ( 0x100 , & V_46 , 0x80 ) ;
}
void F_32 ( void )
{
F_24 () ;
V_47 = V_48 - 1 ;
V_49 = F_13 ;
V_50 = F_13 ;
V_51 = F_14 ;
V_52 = F_21 ;
V_53 = F_20 ;
V_54 = F_16 ;
V_55 = F_13 ;
V_56 = F_1 ;
V_57 = F_15 ;
V_58 = F_3 ;
V_59 = F_15 ;
V_60 = F_3 ;
V_61 = F_22 ;
F_33 () ;
F_34 () ;
V_62 = F_30 ;
}
int F_35 ( struct V_63 * V_64 )
{
return F_36 ( & V_65 , V_64 ) ;
}
int F_37 ( struct V_63 * V_64 )
{
return F_38 ( & V_65 , V_64 ) ;
}
static void F_39 ( unsigned long V_66 )
{
int V_67 = F_40 ( & V_65 , V_66 , NULL ) ;
if ( ( V_67 & ~ V_68 ) != V_69 ) {
T_2 V_70 ;
unsigned long V_71 = F_41 () ;
T_2 V_72 = F_42 () ;
if ( V_66 ) {
V_70 = V_73 [ V_71 ] ;
V_73 [ V_71 ] = 0 ;
} else {
V_70 = F_43 () ;
}
F_44 ( L_8 , V_71 ) ;
F_44 ( L_9 , F_45 () ) ;
if ( V_72 & 1 ) {
F_44 ( L_10 ,
( unsigned long long ) V_72 ) ;
F_46 ( 0 ) ;
}
if ( V_70 & 1 ) {
F_44 ( L_11 ,
( unsigned long long ) V_70 ) ;
}
}
}
T_3 void F_47 ( void )
{
F_39 ( 0 ) ;
}
T_3 void F_48 ( void )
{
F_39 ( 1 ) ;
F_28 ( L_12 ) ;
}
