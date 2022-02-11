static T_1 T_2 F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
return V_3 + ( F_3 () << V_4 ) ;
#else
return F_3 () ;
#endif
}
static inline unsigned long long F_4 ( void )
{
return F_5 ( F_1 ( & V_5 ) ,
V_5 . V_6 , V_5 . V_7 ) ;
}
static int T_3 F_6 ( void )
{
if ( F_7 ( & V_5 , F_8 () ) )
F_9 ( L_1 ) ;
return 0 ;
}
void T_3 F_10 ( void )
{
F_11 ( V_8 ) ;
#ifdef F_12
F_13 ( V_9 , 0 ) ;
F_14 ( V_10 , V_11
| V_12 | V_13 | V_14 ) ;
#else
F_14 ( V_10 , \
V_11 | V_15 | V_16 ) ;
#endif
F_15 ( V_10 , - 1 ) ;
F_16 ( V_10 , - 2 ) ;
F_17 () ;
F_18 ( V_8 ) ;
}
static T_2 F_19 ( struct V_1 * V_2 )
{
return F_20 () ;
}
static inline unsigned long long F_21 ( void )
{
return F_5 ( F_20 () ,
V_17 . V_6 , V_17 . V_7 ) ;
}
static int T_3 F_22 ( void )
{
F_10 () ;
if ( F_7 ( & V_17 , F_23 () ) )
F_9 ( L_1 ) ;
return 0 ;
}
T_1 unsigned long long F_24 ( void )
{
#if F_25 ( V_18 )
return F_4 () ;
#else
return F_21 () ;
#endif
}
static int F_26 ( unsigned long V_19 ,
struct V_20 * V_21 )
{
F_11 ( V_8 ) ;
F_16 ( V_10 , V_19 - 3 ) ;
F_18 ( V_8 ) ;
return 0 ;
}
static int F_27 ( struct V_20 * V_21 )
{
#ifndef F_12
F_14 ( V_10 ,
V_11 | V_22 |
V_15 | V_16 ) ;
#else
F_14 ( V_10 ,
V_11 | V_12 |
V_13 | V_14 ) ;
#endif
F_15 ( V_10 , F_23 () / V_23 ) ;
F_16 ( V_10 , F_23 () / V_23 - 1 ) ;
F_18 ( V_8 ) ;
return 0 ;
}
static int F_28 ( struct V_20 * V_21 )
{
F_11 ( V_8 ) ;
#ifndef F_12
F_14 ( V_10 ,
V_11 | V_22 | V_16 ) ;
#else
F_14 ( V_10 ,
V_11 | V_16 | V_13 |
V_24 ) ;
#endif
F_15 ( V_10 , 0 ) ;
return 0 ;
}
static int F_29 ( struct V_20 * V_21 )
{
F_11 ( V_8 ) ;
return 0 ;
}
static void F_30 ( void )
{
F_31 ( V_10 ) ;
}
static void T_3 F_32 ( void )
{
F_11 ( V_8 ) ;
}
T_4 F_33 ( int V_25 , void * V_26 )
{
struct V_20 * V_21 = V_26 ;
F_34 () ;
F_30 () ;
V_21 -> V_27 ( V_21 ) ;
return V_28 ;
}
static void T_3 F_35 ( struct V_20 * V_21 )
{
unsigned long V_29 ;
V_29 = F_23 () ;
V_21 -> V_6 = F_36 ( V_29 , V_30 , V_21 -> V_7 ) ;
V_21 -> V_31 = F_37 ( - 1 , V_21 ) ;
V_21 -> V_32 = F_37 ( 100 , V_21 ) ;
V_21 -> V_33 = F_38 ( 0 ) ;
F_39 ( V_21 ) ;
}
static int F_40 ( unsigned long V_19 ,
struct V_20 * V_21 )
{
F_41 ( V_34 ) ;
F_42 () ;
F_43 ( V_19 ) ;
F_42 () ;
F_41 ( V_34 | V_35 ) ;
return 0 ;
}
static int F_44 ( struct V_20 * V_21 )
{
unsigned long V_36 = ( ( F_8 () / ( V_23 * V_37 ) ) - 1 ) ;
F_41 ( V_34 ) ;
F_42 () ;
F_45 ( V_37 - 1 ) ;
F_46 ( V_36 ) ;
F_43 ( V_36 ) ;
F_42 () ;
F_41 ( V_34 | V_35 | V_38 ) ;
return 0 ;
}
static int F_47 ( struct V_20 * V_21 )
{
F_41 ( V_34 ) ;
F_42 () ;
F_45 ( V_37 - 1 ) ;
F_46 ( 0 ) ;
F_43 ( 0 ) ;
return 0 ;
}
static int F_48 ( struct V_20 * V_21 )
{
F_41 ( 0 ) ;
F_42 () ;
return 0 ;
}
void F_49 ( void )
{
F_41 ( V_34 ) ;
F_42 () ;
F_45 ( V_37 - 1 ) ;
F_46 ( 0 ) ;
F_43 ( 0 ) ;
F_42 () ;
}
T_4 F_50 ( int V_25 , void * V_26 )
{
int V_39 = F_51 () ;
struct V_20 * V_21 = & F_52 ( V_40 , V_39 ) ;
F_34 () ;
V_21 -> V_27 ( V_21 ) ;
F_53 () ;
return V_28 ;
}
void F_54 ( void )
{
unsigned long V_29 ;
unsigned int V_39 = F_51 () ;
struct V_20 * V_21 = & F_52 ( V_40 , V_39 ) ;
#ifdef F_55
V_21 -> V_41 = V_42 ;
#endif
V_21 -> V_43 = L_2 ;
V_21 -> V_44 = 350 ;
V_21 -> V_25 = - 1 ;
V_21 -> V_7 = 32 ;
V_21 -> V_45 = V_46 | V_47 ;
V_21 -> V_48 = F_40 ;
V_21 -> V_49 = F_48 ;
V_21 -> V_50 = F_44 ;
V_21 -> V_51 = F_47 ;
V_29 = F_8 () / V_37 ;
V_21 -> V_6 = F_36 ( V_29 , V_30 , V_21 -> V_7 ) ;
V_21 -> V_31 = F_37 ( - 1 , V_21 ) ;
V_21 -> V_32 = F_37 ( 100 , V_21 ) ;
V_21 -> V_33 = F_38 ( V_39 ) ;
F_39 ( V_21 ) ;
}
void F_56 ( struct V_52 * V_53 )
{
T_5 V_54 = ( 365 * 37 + 9 ) * 24 * 60 * 60 ;
V_53 -> V_55 = V_54 ;
V_53 -> V_56 = 0 ;
}
void T_3 F_57 ( void )
{
#ifdef F_58
if ( ( F_59 () & 0xC0000000 ) == 0xC0000000 ) {
F_60 ( V_57 L_3 ) ;
F_61 ( 0 ) ;
}
#endif
F_6 () ;
F_22 () ;
#if F_25 ( V_58 )
F_49 () ;
F_62 ( V_59 , & V_60 ) ;
F_54 () ;
#endif
#if F_25 ( V_61 )
F_32 () ;
F_62 ( V_62 , & V_63 ) ;
V_63 . V_26 = & V_64 ;
F_35 ( & V_64 ) ;
#endif
#if ! F_25 ( V_58 ) && ! F_25 ( V_61 )
# error at least one clock event device is required
#endif
}
