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
static void F_27 ( enum V_22 V_23 ,
struct V_20 * V_21 )
{
switch ( V_23 ) {
case V_24 : {
#ifndef F_12
F_14 ( V_10 , \
V_11 | V_25 | \
V_15 | V_16 ) ;
#else
F_14 ( V_10 , V_11
| V_12 | V_13 | V_14 ) ;
#endif
F_15 ( V_10 , F_23 () / V_26 ) ;
F_16 ( V_10 , F_23 () / V_26 - 1 ) ;
F_18 ( V_8 ) ;
break;
}
case V_27 :
F_11 ( V_8 ) ;
#ifndef F_12
F_14 ( V_10 , \
V_11 | V_25 | V_16 ) ;
#else
F_14 ( V_10 , V_11 | V_16
| V_13 | V_28 ) ;
#endif
F_15 ( V_10 , 0 ) ;
break;
case V_29 :
case V_30 :
F_11 ( V_8 ) ;
break;
case V_31 :
break;
}
}
static void F_28 ( void )
{
F_29 ( V_10 ) ;
}
static void T_3 F_30 ( void )
{
F_11 ( V_8 ) ;
}
T_4 F_31 ( int V_32 , void * V_33 )
{
struct V_20 * V_21 = V_33 ;
F_32 () ;
F_28 () ;
V_21 -> V_34 ( V_21 ) ;
return V_35 ;
}
static void T_3 F_33 ( struct V_20 * V_21 )
{
unsigned long V_36 ;
V_36 = F_23 () ;
V_21 -> V_6 = F_34 ( V_36 , V_37 , V_21 -> V_7 ) ;
V_21 -> V_38 = F_35 ( - 1 , V_21 ) ;
V_21 -> V_39 = F_35 ( 100 , V_21 ) ;
V_21 -> V_40 = F_36 ( 0 ) ;
F_37 ( V_21 ) ;
}
static int F_38 ( unsigned long V_19 ,
struct V_20 * V_21 )
{
F_39 ( V_41 ) ;
F_40 () ;
F_41 ( V_19 ) ;
F_40 () ;
F_39 ( V_41 | V_42 ) ;
return 0 ;
}
static void F_42 ( enum V_22 V_23 ,
struct V_20 * V_21 )
{
switch ( V_23 ) {
case V_24 : {
unsigned long V_43 = ( ( F_8 () / ( V_26 * V_44 ) ) - 1 ) ;
F_39 ( V_41 ) ;
F_40 () ;
F_43 ( V_44 - 1 ) ;
F_44 ( V_43 ) ;
F_41 ( V_43 ) ;
F_40 () ;
F_39 ( V_41 | V_42 | V_45 ) ;
break;
}
case V_27 :
F_39 ( V_41 ) ;
F_40 () ;
F_43 ( V_44 - 1 ) ;
F_44 ( 0 ) ;
F_41 ( 0 ) ;
break;
case V_29 :
case V_30 :
F_39 ( 0 ) ;
F_40 () ;
break;
case V_31 :
break;
}
}
void F_45 ( void )
{
F_39 ( V_41 ) ;
F_40 () ;
F_43 ( V_44 - 1 ) ;
F_44 ( 0 ) ;
F_41 ( 0 ) ;
F_40 () ;
}
T_4 F_46 ( int V_32 , void * V_33 )
{
int V_46 = F_47 () ;
struct V_20 * V_21 = & F_48 ( V_47 , V_46 ) ;
F_32 () ;
V_21 -> V_34 ( V_21 ) ;
F_49 () ;
return V_35 ;
}
void F_50 ( void )
{
unsigned long V_36 ;
unsigned int V_46 = F_47 () ;
struct V_20 * V_21 = & F_48 ( V_47 , V_46 ) ;
#ifdef F_51
V_21 -> V_48 = V_49 ;
#endif
V_21 -> V_50 = L_2 ;
V_21 -> V_51 = 350 ;
V_21 -> V_32 = - 1 ;
V_21 -> V_7 = 32 ;
V_21 -> V_52 = V_53 | V_54 ;
V_21 -> V_55 = F_38 ;
V_21 -> V_56 = F_42 ;
V_36 = F_8 () / V_44 ;
V_21 -> V_6 = F_34 ( V_36 , V_37 , V_21 -> V_7 ) ;
V_21 -> V_38 = F_35 ( - 1 , V_21 ) ;
V_21 -> V_39 = F_35 ( 100 , V_21 ) ;
V_21 -> V_40 = F_36 ( V_46 ) ;
F_37 ( V_21 ) ;
}
void F_52 ( struct V_57 * V_58 )
{
T_5 V_59 = ( 365 * 37 + 9 ) * 24 * 60 * 60 ;
V_58 -> V_60 = V_59 ;
V_58 -> V_61 = 0 ;
}
void T_3 F_53 ( void )
{
#ifdef F_54
if ( ( F_55 () & 0xC0000000 ) == 0xC0000000 ) {
F_56 ( V_62 L_3 ) ;
F_57 ( 0 ) ;
}
#endif
F_6 () ;
F_22 () ;
#if F_25 ( V_63 )
F_45 () ;
F_58 ( V_64 , & V_65 ) ;
F_50 () ;
#endif
#if F_25 ( V_66 )
F_30 () ;
F_58 ( V_67 , & V_68 ) ;
V_68 . V_33 = & V_69 ;
F_33 ( & V_69 ) ;
#endif
#if ! F_25 ( V_63 ) && ! F_25 ( V_66 )
# error at least one clock event device is required
#endif
}
