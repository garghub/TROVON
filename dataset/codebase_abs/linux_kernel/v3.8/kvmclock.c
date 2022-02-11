static int F_1 ( char * V_1 )
{
V_2 = 0 ;
return 0 ;
}
static unsigned long F_2 ( void )
{
struct V_3 * V_4 ;
struct V_5 V_6 ;
int V_7 , V_8 ;
int V_9 ;
V_7 = ( int ) F_3 ( & V_10 ) ;
V_8 = ( ( V_11 ) F_3 ( & V_10 ) >> 32 ) ;
F_4 ( V_12 , V_7 , V_8 ) ;
F_5 () ;
V_9 = F_6 () ;
V_4 = & V_13 [ V_9 ] . V_14 ;
F_7 ( & V_10 , V_4 , & V_6 ) ;
F_8 () ;
return V_6 . V_15 ;
}
static int F_9 ( unsigned long V_16 )
{
return - 1 ;
}
static T_1 F_10 ( void )
{
struct V_3 * V_17 ;
T_1 V_18 ;
int V_9 ;
F_11 () ;
V_9 = F_6 () ;
V_17 = & V_13 [ V_9 ] . V_14 ;
V_18 = F_12 ( V_17 ) ;
F_13 () ;
return V_18 ;
}
static T_1 F_14 ( struct V_19 * V_20 )
{
return F_10 () ;
}
static unsigned long F_15 ( void )
{
struct V_3 * V_17 ;
int V_9 ;
unsigned long V_21 ;
F_5 () ;
V_9 = F_6 () ;
V_17 = & V_13 [ V_9 ] . V_14 ;
V_21 = F_16 ( V_17 ) ;
F_8 () ;
return V_21 ;
}
static void F_17 ( void )
{
unsigned long V_22 ;
V_11 V_23 ;
V_22 = F_15 () ;
V_23 = ( ( V_11 ) V_22 * 1000 ) ;
F_18 ( V_23 , V_24 ) ;
V_25 = V_23 ;
}
bool F_19 ( void )
{
bool V_18 = false ;
struct V_3 * V_17 ;
int V_9 = F_6 () ;
if ( ! V_13 )
return V_18 ;
V_17 = & V_13 [ V_9 ] . V_14 ;
if ( ( V_17 -> V_26 & V_27 ) != 0 ) {
V_17 -> V_26 &= ~ V_27 ;
V_18 = true ;
}
return V_18 ;
}
int F_20 ( char * V_28 )
{
int V_9 = F_6 () ;
int V_7 , V_8 , V_18 ;
struct V_3 * V_17 = & V_13 [ V_9 ] . V_14 ;
V_7 = ( int ) F_21 ( V_17 ) | 1 ;
V_8 = ( ( V_11 ) F_21 ( V_17 ) >> 32 ) ;
V_18 = F_22 ( V_29 , V_7 , V_8 ) ;
F_23 ( V_30 L_1 ,
V_9 , V_8 , V_7 , V_28 ) ;
return V_18 ;
}
static void F_24 ( void )
{
}
static void F_25 ( void )
{
F_20 ( L_2 ) ;
}
static void T_2 F_26 ( void )
{
F_27 ( F_20 ( L_3 ) ) ;
}
static void F_28 ( struct V_31 * V_32 )
{
F_4 ( V_29 , 0 , 0 ) ;
F_29 () ;
F_30 ( V_32 ) ;
}
static void F_31 ( void )
{
F_4 ( V_29 , 0 , 0 ) ;
F_29 () ;
F_32 () ;
}
void T_3 F_33 ( void )
{
unsigned long V_33 ;
if ( ! F_34 () )
return;
if ( V_2 && F_35 ( V_34 ) ) {
V_29 = V_35 ;
V_12 = V_36 ;
} else if ( ! ( V_2 && F_35 ( V_37 ) ) )
return;
F_23 ( V_30 L_4 ,
V_29 , V_12 ) ;
V_33 = F_36 ( sizeof( struct V_38 ) * V_39 ,
V_40 ) ;
if ( ! V_33 )
return;
V_13 = F_37 ( V_33 ) ;
if ( F_20 ( L_5 ) ) {
V_13 = NULL ;
F_38 ( V_33 ,
sizeof( struct V_38 ) * V_39 ) ;
return;
}
V_41 . V_42 = F_10 ;
V_43 . V_44 = F_15 ;
V_43 . V_45 = F_2 ;
V_43 . V_46 = F_9 ;
#ifdef F_39
V_47 . V_48 =
F_26 ;
#endif
V_43 . V_49 = F_24 ;
V_43 . V_50 = F_25 ;
V_51 . V_52 = F_31 ;
#ifdef F_40
V_51 . V_53 = F_28 ;
#endif
F_17 () ;
F_41 ( & V_54 , V_55 ) ;
V_56 . V_57 = 1 ;
V_56 . V_58 = L_6 ;
if ( F_35 ( V_59 ) )
F_42 ( V_60 ) ;
}
int T_3 F_43 ( void )
{
#ifdef F_44
int V_9 ;
int V_18 ;
T_4 V_26 ;
struct V_3 * V_4 ;
unsigned int V_61 ;
V_61 = sizeof( struct V_38 ) * V_39 ;
F_5 () ;
V_9 = F_6 () ;
V_4 = & V_13 [ V_9 ] . V_14 ;
V_26 = F_45 ( V_4 ) ;
if ( ! ( V_26 & V_60 ) ) {
F_8 () ;
return 1 ;
}
if ( ( V_18 = F_46 ( V_13 , V_61 ) ) ) {
F_8 () ;
return V_18 ;
}
F_8 () ;
V_54 . V_62 . V_63 = V_64 ;
#endif
return 0 ;
}
