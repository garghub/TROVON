static int F_1 ( char * V_1 )
{
V_2 = 0 ;
return 0 ;
}
static void F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 , V_8 ;
int V_9 ;
V_7 = ( int ) F_3 ( & V_10 ) ;
V_8 = ( ( V_11 ) F_3 ( & V_10 ) >> 32 ) ;
F_4 ( V_12 , V_7 , V_8 ) ;
V_9 = F_5 () ;
V_6 = & V_13 [ V_9 ] . V_14 ;
F_6 ( & V_10 , V_6 , V_4 ) ;
F_7 () ;
}
static int F_8 ( const struct V_3 * V_4 )
{
return - 1 ;
}
static T_1 F_9 ( void )
{
struct V_5 * V_15 ;
T_1 V_16 ;
int V_9 ;
F_10 () ;
V_9 = F_11 () ;
V_15 = & V_13 [ V_9 ] . V_14 ;
V_16 = F_12 ( V_15 ) ;
F_13 () ;
return V_16 ;
}
static T_1 F_14 ( struct V_17 * V_18 )
{
return F_9 () ;
}
static T_1 F_15 ( void )
{
return F_9 () - V_19 ;
}
static inline void F_16 ( bool V_20 )
{
if ( ! V_20 ) {
V_21 . V_22 = F_9 ;
return;
}
V_19 = F_9 () ;
V_21 . V_22 = F_15 ;
F_17 () ;
F_18 ( V_23 L_1 ,
V_19 ) ;
F_19 ( sizeof( V_19 ) >
sizeof( ( (struct V_5 * ) NULL ) -> V_24 ) ) ;
}
static unsigned long F_20 ( void )
{
struct V_5 * V_15 ;
int V_9 ;
unsigned long V_25 ;
V_9 = F_5 () ;
V_15 = & V_13 [ V_9 ] . V_14 ;
V_25 = F_21 ( V_15 ) ;
F_7 () ;
return V_25 ;
}
static void F_22 ( void )
{
unsigned long V_26 ;
V_11 V_27 ;
V_26 = F_20 () ;
V_27 = ( ( V_11 ) V_26 * 1000 ) ;
F_23 ( V_27 , V_28 ) ;
V_29 = V_27 ;
}
bool F_24 ( void )
{
bool V_16 = false ;
struct V_5 * V_15 ;
int V_9 = F_11 () ;
if ( ! V_13 )
return V_16 ;
V_15 = & V_13 [ V_9 ] . V_14 ;
if ( ( V_15 -> V_30 & V_31 ) != 0 ) {
V_15 -> V_30 &= ~ V_31 ;
F_25 () ;
V_16 = true ;
}
return V_16 ;
}
int F_26 ( char * V_32 )
{
int V_9 = F_11 () ;
int V_7 , V_8 , V_16 ;
struct V_5 * V_15 ;
if ( ! V_13 )
return 0 ;
V_15 = & V_13 [ V_9 ] . V_14 ;
V_7 = ( int ) F_27 ( V_15 ) | 1 ;
V_8 = ( ( V_11 ) F_27 ( V_15 ) >> 32 ) ;
V_16 = F_28 ( V_33 , V_7 , V_8 ) ;
F_18 ( V_23 L_2 ,
V_9 , V_8 , V_7 , V_32 ) ;
return V_16 ;
}
static void F_29 ( void )
{
}
static void F_30 ( void )
{
F_26 ( L_3 ) ;
}
static void F_31 ( void )
{
F_32 ( F_26 ( L_4 ) ) ;
}
static void F_33 ( struct V_34 * V_35 )
{
F_4 ( V_33 , 0 , 0 ) ;
F_34 () ;
F_35 ( V_35 ) ;
}
static void F_36 ( void )
{
F_4 ( V_33 , 0 , 0 ) ;
F_34 () ;
F_37 () ;
}
void T_2 F_38 ( void )
{
struct V_5 * V_6 ;
unsigned long V_36 ;
int V_37 , V_9 ;
T_3 V_30 ;
V_37 = F_39 ( sizeof( struct V_38 ) * V_39 ) ;
if ( ! F_40 () )
return;
if ( V_2 && F_41 ( V_40 ) ) {
V_33 = V_41 ;
V_12 = V_42 ;
} else if ( ! ( V_2 && F_41 ( V_43 ) ) )
return;
F_18 ( V_23 L_5 ,
V_33 , V_12 ) ;
V_36 = F_42 ( V_37 , V_44 ) ;
if ( ! V_36 )
return;
V_13 = F_43 ( V_36 ) ;
memset ( V_13 , 0 , V_37 ) ;
if ( F_26 ( L_6 ) ) {
V_13 = NULL ;
F_44 ( V_36 , V_37 ) ;
return;
}
if ( F_41 ( V_45 ) )
F_45 ( V_46 ) ;
V_9 = F_5 () ;
V_6 = & V_13 [ V_9 ] . V_14 ;
V_30 = F_46 ( V_6 ) ;
F_16 ( V_30 & V_46 ) ;
F_7 () ;
V_47 . V_48 = F_20 ;
V_47 . V_49 = F_2 ;
V_47 . V_50 = F_8 ;
#ifdef F_47
V_51 . V_52 =
F_31 ;
#endif
V_47 . V_53 = F_29 ;
V_47 . V_54 = F_30 ;
V_55 . V_56 = F_36 ;
#ifdef F_48
V_55 . V_57 = F_33 ;
#endif
F_22 () ;
F_49 ( & V_58 , V_59 ) ;
V_60 . V_61 = L_7 ;
}
int T_2 F_50 ( void )
{
#ifdef F_51
int V_9 ;
int V_16 ;
T_3 V_30 ;
struct V_5 * V_6 ;
unsigned int V_37 ;
if ( ! V_13 )
return 0 ;
V_37 = F_39 ( sizeof( struct V_38 ) * V_39 ) ;
V_9 = F_5 () ;
V_6 = & V_13 [ V_9 ] . V_14 ;
V_30 = F_46 ( V_6 ) ;
if ( ! ( V_30 & V_46 ) ) {
F_7 () ;
return 1 ;
}
if ( ( V_16 = F_52 ( V_13 , V_37 ) ) ) {
F_7 () ;
return V_16 ;
}
F_7 () ;
V_58 . V_62 . V_63 = V_64 ;
#endif
return 0 ;
}
