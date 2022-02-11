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
F_12 ( V_9 , \
V_10 | V_11 | V_12 ) ;
F_13 ( V_9 , - 1 ) ;
F_14 ( V_9 , - 2 ) ;
F_15 () ;
F_16 ( V_8 ) ;
}
static T_2 F_17 ( struct V_1 * V_2 )
{
return F_18 () ;
}
static inline unsigned long long F_19 ( void )
{
return F_5 ( F_18 () ,
V_13 . V_6 , V_13 . V_7 ) ;
}
static int T_3 F_20 ( void )
{
F_10 () ;
if ( F_7 ( & V_13 , F_21 () ) )
F_9 ( L_1 ) ;
return 0 ;
}
T_1 unsigned long long F_22 ( void )
{
#if F_23 ( V_14 )
return F_4 () ;
#else
return F_19 () ;
#endif
}
static int F_24 ( unsigned long V_15 ,
struct V_16 * V_17 )
{
F_11 ( V_8 ) ;
F_14 ( V_9 , V_15 - 3 ) ;
F_16 ( V_8 ) ;
return 0 ;
}
static void F_25 ( enum V_18 V_19 ,
struct V_16 * V_17 )
{
switch ( V_19 ) {
case V_20 : {
F_12 ( V_9 , \
V_10 | V_21 | \
V_11 | V_12 ) ;
F_13 ( V_9 , F_21 () / V_22 ) ;
F_14 ( V_9 , F_21 () / V_22 - 1 ) ;
F_16 ( V_8 ) ;
break;
}
case V_23 :
F_11 ( V_8 ) ;
F_12 ( V_9 , \
V_10 | V_21 | V_12 ) ;
F_13 ( V_9 , 0 ) ;
break;
case V_24 :
case V_25 :
F_11 ( V_8 ) ;
break;
case V_26 :
break;
}
}
static void F_26 ( void )
{
F_27 ( V_27 , V_28 ) ;
}
static void T_3 F_28 ( void )
{
F_11 ( V_8 ) ;
}
T_4 F_29 ( int V_29 , void * V_30 )
{
struct V_16 * V_17 = V_30 ;
F_30 () ;
F_26 () ;
V_17 -> V_31 ( V_17 ) ;
return V_32 ;
}
static void T_3 F_31 ( struct V_16 * V_17 )
{
unsigned long V_33 ;
V_33 = F_21 () ;
V_17 -> V_6 = F_32 ( V_33 , V_34 , V_17 -> V_7 ) ;
V_17 -> V_35 = F_33 ( - 1 , V_17 ) ;
V_17 -> V_36 = F_33 ( 100 , V_17 ) ;
V_17 -> V_37 = F_34 ( 0 ) ;
F_35 ( V_17 ) ;
}
static int F_36 ( unsigned long V_15 ,
struct V_16 * V_17 )
{
F_37 ( V_38 ) ;
F_38 () ;
F_39 ( V_15 ) ;
F_38 () ;
F_37 ( V_38 | V_39 ) ;
return 0 ;
}
static void F_40 ( enum V_18 V_19 ,
struct V_16 * V_17 )
{
switch ( V_19 ) {
case V_20 : {
unsigned long V_40 = ( ( F_8 () / ( V_22 * V_41 ) ) - 1 ) ;
F_37 ( V_38 ) ;
F_38 () ;
F_41 ( V_41 - 1 ) ;
F_42 ( V_40 ) ;
F_39 ( V_40 ) ;
F_38 () ;
F_37 ( V_38 | V_39 | V_42 ) ;
break;
}
case V_23 :
F_37 ( V_38 ) ;
F_38 () ;
F_41 ( V_41 - 1 ) ;
F_42 ( 0 ) ;
F_39 ( 0 ) ;
break;
case V_24 :
case V_25 :
F_37 ( 0 ) ;
F_38 () ;
break;
case V_26 :
break;
}
}
void F_43 ( void )
{
F_37 ( V_38 ) ;
F_38 () ;
F_41 ( V_41 - 1 ) ;
F_42 ( 0 ) ;
F_39 ( 0 ) ;
F_38 () ;
}
T_4 F_44 ( int V_29 , void * V_30 )
{
int V_43 = F_45 () ;
struct V_16 * V_17 = & F_46 ( V_44 , V_43 ) ;
F_30 () ;
V_17 -> V_31 ( V_17 ) ;
F_47 () ;
return V_32 ;
}
void F_48 ( void )
{
unsigned long V_33 ;
unsigned int V_43 = F_45 () ;
struct V_16 * V_17 = & F_46 ( V_44 , V_43 ) ;
V_17 -> V_45 = L_2 ;
V_17 -> V_46 = 350 ;
V_17 -> V_29 = - 1 ;
V_17 -> V_7 = 32 ;
V_17 -> V_47 = V_48 | V_49 ;
V_17 -> V_50 = F_36 ;
V_17 -> V_51 = F_40 ;
V_33 = F_8 () / V_41 ;
V_17 -> V_6 = F_32 ( V_33 , V_34 , V_17 -> V_7 ) ;
V_17 -> V_35 = F_33 ( - 1 , V_17 ) ;
V_17 -> V_36 = F_33 ( 100 , V_17 ) ;
V_17 -> V_37 = F_34 ( V_43 ) ;
F_35 ( V_17 ) ;
}
void F_49 ( struct V_52 * V_53 )
{
T_5 V_54 = ( 365 * 37 + 9 ) * 24 * 60 * 60 ;
V_53 -> V_55 = V_54 ;
V_53 -> V_56 = 0 ;
}
void T_3 F_50 ( void )
{
#ifdef F_51
if ( ( F_52 () & 0xC0000000 ) == 0xC0000000 ) {
F_53 ( V_57 L_3 ) ;
F_54 ( 0 ) ;
}
#endif
F_6 () ;
F_20 () ;
#if F_23 ( V_58 )
F_43 () ;
F_55 ( V_59 , & V_60 ) ;
F_48 () ;
#endif
#if F_23 ( V_61 )
F_28 () ;
F_55 ( V_62 , & V_63 ) ;
V_63 . V_30 = & V_64 ;
F_31 ( & V_64 ) ;
#endif
#if ! F_23 ( V_58 ) && ! F_23 ( V_61 )
# error at least one clock event device is required
#endif
}
