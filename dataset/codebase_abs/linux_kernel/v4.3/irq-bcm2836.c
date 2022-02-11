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
if ( V_22 & 0x10 ) {
#ifdef F_20
void T_1 * V_24 = ( V_5 . V_6 +
V_25 + 16 * V_3 ) ;
T_3 V_26 = F_3 ( V_24 ) ;
T_3 V_27 = F_21 ( V_26 ) - 1 ;
F_2 ( 1 << V_27 , V_24 ) ;
F_22 ( V_27 , V_21 ) ;
#endif
} else {
T_3 V_10 = F_21 ( V_22 ) - 1 ;
F_23 ( F_24 ( V_5 . V_17 , V_10 ) , V_21 ) ;
}
}
static void F_25 ( const struct V_28 * V_29 ,
unsigned int V_27 )
{
int V_3 ;
void T_1 * V_30 = V_5 . V_6 + V_31 ;
F_26 () ;
F_27 (cpu, mask) {
F_2 ( 1 << V_27 , V_30 + 16 * V_3 ) ;
}
}
static int F_28 ( struct V_32 * V_33 ,
unsigned long V_34 , void * V_35 )
{
unsigned int V_3 = ( unsigned long ) V_35 ;
unsigned int V_36 = V_37 ;
unsigned int V_38 = 0 ;
if ( V_34 == V_39 || V_34 == V_40 )
F_5 ( V_36 , V_38 , V_3 ) ;
else if ( V_34 == V_41 )
F_1 ( V_36 , V_38 , V_3 ) ;
return V_42 ;
}
static void
F_29 ( void )
{
#ifdef F_20
F_28 ( & V_43 ,
V_39 ,
( void * ) F_7 () ) ;
F_30 ( & V_43 ) ;
F_31 ( F_25 ) ;
#endif
}
static int T_4 F_32 ( struct V_44 * V_45 ,
struct V_44 * V_46 )
{
V_5 . V_6 = F_33 ( V_45 , 0 ) ;
if ( ! V_5 . V_6 ) {
F_34 ( L_1 ,
V_45 -> V_47 ) ;
}
V_5 . V_17 = F_35 ( V_45 , V_48 + 1 ,
& V_49 ,
NULL ) ;
if ( ! V_5 . V_17 )
F_34 ( L_2 , V_45 -> V_47 ) ;
F_13 ( V_11 ,
& V_50 ) ;
F_13 ( V_51 ,
& V_50 ) ;
F_13 ( V_52 ,
& V_50 ) ;
F_13 ( V_53 ,
& V_50 ) ;
F_13 ( V_54 ,
& V_55 ) ;
F_13 ( V_56 ,
& V_57 ) ;
F_29 () ;
F_36 ( F_18 ) ;
return 0 ;
}
