static int F_1 ( char * V_1 )
{
V_2 = 0 ;
return 0 ;
}
struct V_3 * F_2 ( void )
{
return V_4 ;
}
static void F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_9 , V_10 ;
int V_11 ;
V_9 = ( int ) F_4 ( & V_12 ) ;
V_10 = ( ( V_13 ) F_4 ( & V_12 ) >> 32 ) ;
F_5 ( V_14 , V_9 , V_10 ) ;
V_11 = F_6 () ;
V_8 = & V_4 [ V_11 ] . V_15 ;
F_7 ( & V_12 , V_8 , V_6 ) ;
F_8 () ;
}
static int F_9 ( const struct V_5 * V_6 )
{
return - 1 ;
}
static T_1 F_10 ( void )
{
struct V_7 * V_16 ;
T_1 V_17 ;
int V_11 ;
F_11 () ;
V_11 = F_12 () ;
V_16 = & V_4 [ V_11 ] . V_15 ;
V_17 = F_13 ( V_16 ) ;
F_14 () ;
return V_17 ;
}
static T_1 F_15 ( struct V_18 * V_19 )
{
return F_10 () ;
}
static T_1 F_16 ( void )
{
return F_10 () - V_20 ;
}
static inline void F_17 ( bool V_21 )
{
if ( ! V_21 ) {
V_22 . V_23 = F_10 ;
return;
}
V_20 = F_10 () ;
V_22 . V_23 = F_16 ;
F_18 () ;
F_19 ( V_24 L_1 ,
V_20 ) ;
F_20 ( sizeof( V_20 ) >
sizeof( ( (struct V_7 * ) NULL ) -> V_25 ) ) ;
}
static unsigned long F_21 ( void )
{
struct V_7 * V_16 ;
int V_11 ;
unsigned long V_26 ;
V_11 = F_6 () ;
V_16 = & V_4 [ V_11 ] . V_15 ;
V_26 = F_22 ( V_16 ) ;
F_8 () ;
return V_26 ;
}
static void F_23 ( void )
{
unsigned long V_27 ;
V_13 V_28 ;
V_27 = F_21 () ;
V_28 = ( ( V_13 ) V_27 * 1000 ) ;
F_24 ( V_28 , V_29 ) ;
V_30 = V_28 ;
}
bool F_25 ( void )
{
bool V_17 = false ;
struct V_7 * V_16 ;
int V_11 = F_12 () ;
if ( ! V_4 )
return V_17 ;
V_16 = & V_4 [ V_11 ] . V_15 ;
if ( ( V_16 -> V_31 & V_32 ) != 0 ) {
V_16 -> V_31 &= ~ V_32 ;
F_26 () ;
V_17 = true ;
}
return V_17 ;
}
int F_27 ( char * V_33 )
{
int V_11 = F_12 () ;
int V_9 , V_10 , V_17 ;
struct V_7 * V_16 ;
if ( ! V_4 )
return 0 ;
V_16 = & V_4 [ V_11 ] . V_15 ;
V_9 = ( int ) F_28 ( V_16 ) | 1 ;
V_10 = ( ( V_13 ) F_28 ( V_16 ) >> 32 ) ;
V_17 = F_29 ( V_34 , V_9 , V_10 ) ;
F_19 ( V_24 L_2 ,
V_11 , V_10 , V_9 , V_33 ) ;
return V_17 ;
}
static void F_30 ( void )
{
}
static void F_31 ( void )
{
F_27 ( L_3 ) ;
}
static void F_32 ( void )
{
F_33 ( F_27 ( L_4 ) ) ;
}
static void F_34 ( struct V_35 * V_36 )
{
F_5 ( V_34 , 0 , 0 ) ;
F_35 () ;
F_36 ( V_36 ) ;
}
static void F_37 ( void )
{
F_5 ( V_34 , 0 , 0 ) ;
F_35 () ;
F_38 () ;
}
void T_2 F_39 ( void )
{
struct V_7 * V_8 ;
unsigned long V_37 ;
int V_38 , V_11 ;
T_3 V_31 ;
V_38 = F_40 ( sizeof( struct V_3 ) * V_39 ) ;
if ( ! F_41 () )
return;
if ( V_2 && F_42 ( V_40 ) ) {
V_34 = V_41 ;
V_14 = V_42 ;
} else if ( ! ( V_2 && F_42 ( V_43 ) ) )
return;
F_19 ( V_24 L_5 ,
V_34 , V_14 ) ;
V_37 = F_43 ( V_38 , V_44 ) ;
if ( ! V_37 )
return;
V_4 = F_44 ( V_37 ) ;
memset ( V_4 , 0 , V_38 ) ;
if ( F_27 ( L_6 ) ) {
V_4 = NULL ;
F_45 ( V_37 , V_38 ) ;
return;
}
if ( F_42 ( V_45 ) )
F_46 ( V_46 ) ;
V_11 = F_6 () ;
V_8 = & V_4 [ V_11 ] . V_15 ;
V_31 = F_47 ( V_8 ) ;
F_17 ( V_31 & V_46 ) ;
F_8 () ;
V_47 . V_48 = F_21 ;
V_47 . V_49 = F_21 ;
V_47 . V_50 = F_3 ;
V_47 . V_51 = F_9 ;
#ifdef F_48
V_52 . V_53 =
F_32 ;
#endif
V_47 . V_54 = F_30 ;
V_47 . V_55 = F_31 ;
V_56 . V_57 = F_37 ;
#ifdef F_49
V_56 . V_58 = F_34 ;
#endif
F_23 () ;
F_50 ( & V_59 , V_60 ) ;
V_61 . V_62 = L_7 ;
}
int T_2 F_51 ( void )
{
#ifdef F_52
int V_11 ;
T_3 V_31 ;
struct V_7 * V_8 ;
unsigned int V_38 ;
if ( ! V_4 )
return 0 ;
V_38 = F_40 ( sizeof( struct V_3 ) * V_39 ) ;
V_11 = F_6 () ;
V_8 = & V_4 [ V_11 ] . V_15 ;
V_31 = F_47 ( V_8 ) ;
if ( ! ( V_31 & V_46 ) ) {
F_8 () ;
return 1 ;
}
F_8 () ;
V_59 . V_63 . V_64 = V_65 ;
#endif
return 0 ;
}
