static void F_1 ( unsigned int V_1 ,
unsigned int V_2 ,
int V_3 )
{
void T_1 * V_4 = V_5 . V_6 + V_1 + 4 * V_3 ;
F_2 ( F_3 ( V_4 ) & ~ F_4 ( V_2 ) , V_4 ) ;
}
static void F_5 ( unsigned int V_1 ,
unsigned int V_2 ,
int V_3 )
{
void T_1 * V_4 = V_5 . V_6 + V_1 + 4 * V_3 ;
F_2 ( F_3 ( V_4 ) | F_4 ( V_2 ) , V_4 ) ;
}
static void F_6 ( struct V_7 * V_8 )
{
F_1 ( V_9 ,
V_8 -> V_10 - V_11 ,
F_7 () ) ;
}
static void F_8 ( struct V_7 * V_8 )
{
F_5 ( V_9 ,
V_8 -> V_10 - V_11 ,
F_7 () ) ;
}
static void F_9 ( struct V_7 * V_8 )
{
F_2 ( 1 << F_7 () , V_5 . V_6 + V_12 ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
F_2 ( 1 << F_7 () , V_5 . V_6 + V_13 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
}
static void F_12 ( struct V_7 * V_8 )
{
}
static void F_13 ( int V_10 , struct V_14 * V_15 )
{
int V_16 = F_14 ( V_5 . V_17 , V_10 ) ;
F_15 ( V_16 ) ;
F_16 ( V_16 , V_15 , V_18 ) ;
F_17 ( V_16 , V_19 ) ;
}
static void
T_2 F_18 ( struct V_20 * V_21 )
{
int V_3 = F_7 () ;
T_3 V_22 ;
V_22 = F_19 ( V_5 . V_6 + V_23 + 4 * V_3 ) ;
if ( V_22 & F_4 ( V_24 ) ) {
#ifdef F_20
void T_1 * V_25 = ( V_5 . V_6 +
V_26 + 16 * V_3 ) ;
T_3 V_27 = F_3 ( V_25 ) ;
T_3 V_28 = F_21 ( V_27 ) - 1 ;
F_2 ( 1 << V_28 , V_25 ) ;
F_22 ( V_28 , V_21 ) ;
#endif
} else if ( V_22 ) {
T_3 V_10 = F_21 ( V_22 ) - 1 ;
F_23 ( F_24 ( V_5 . V_17 , V_10 ) , V_21 ) ;
}
}
static void F_25 ( const struct V_29 * V_30 ,
unsigned int V_28 )
{
int V_3 ;
void T_1 * V_31 = V_5 . V_6 + V_32 ;
F_26 () ;
F_27 (cpu, mask) {
F_2 ( 1 << V_28 , V_31 + 16 * V_3 ) ;
}
}
static int F_28 ( struct V_33 * V_34 ,
unsigned long V_35 , void * V_36 )
{
unsigned int V_3 = ( unsigned long ) V_36 ;
unsigned int V_37 = V_38 ;
unsigned int V_39 = 0 ;
if ( V_35 == V_40 || V_35 == V_41 )
F_5 ( V_37 , V_39 , V_3 ) ;
else if ( V_35 == V_42 )
F_1 ( V_37 , V_39 , V_3 ) ;
return V_43 ;
}
int T_4 F_29 ( unsigned int V_3 ,
struct V_44 * V_45 )
{
unsigned long V_46 =
( unsigned long ) F_30 ( ( void * ) V_47 ) ;
F_2 ( V_46 ,
V_5 . V_6 + V_48 + 16 * V_3 ) ;
return 0 ;
}
static void
F_31 ( void )
{
#ifdef F_20
F_28 ( & V_49 ,
V_40 ,
( void * ) F_7 () ) ;
F_32 ( & V_49 ) ;
F_33 ( F_25 ) ;
F_34 ( & V_50 ) ;
#endif
}
static void F_35 ( void )
{
F_2 ( 0 , V_5 . V_6 + V_51 ) ;
F_2 ( 0x80000000 , V_5 . V_6 + V_52 ) ;
}
static int T_4 F_36 ( struct V_53 * V_54 ,
struct V_53 * V_55 )
{
V_5 . V_6 = F_37 ( V_54 , 0 ) ;
if ( ! V_5 . V_6 ) {
F_38 ( L_1 ,
V_54 -> V_56 ) ;
}
F_35 () ;
V_5 . V_17 = F_39 ( V_54 , V_57 + 1 ,
& V_58 ,
NULL ) ;
if ( ! V_5 . V_17 )
F_38 ( L_2 , V_54 -> V_56 ) ;
F_13 ( V_11 ,
& V_59 ) ;
F_13 ( V_60 ,
& V_59 ) ;
F_13 ( V_61 ,
& V_59 ) ;
F_13 ( V_62 ,
& V_59 ) ;
F_13 ( V_63 ,
& V_64 ) ;
F_13 ( V_65 ,
& V_66 ) ;
F_31 () ;
F_40 ( F_18 ) ;
return 0 ;
}
