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
return - V_16 ;
}
static V_13 F_10 ( void )
{
struct V_7 * V_17 ;
V_13 V_18 ;
int V_11 ;
F_11 () ;
V_11 = F_12 () ;
V_17 = & V_4 [ V_11 ] . V_15 ;
V_18 = F_13 ( V_17 ) ;
F_14 () ;
return V_18 ;
}
static V_13 F_15 ( struct V_19 * V_20 )
{
return F_10 () ;
}
static V_13 F_16 ( void )
{
return F_10 () - V_21 ;
}
static inline void F_17 ( bool V_22 )
{
if ( ! V_22 ) {
V_23 . V_24 = F_10 ;
F_18 () ;
return;
}
V_21 = F_10 () ;
V_23 . V_24 = F_16 ;
F_19 ( V_25 L_1 ,
V_21 ) ;
F_20 ( sizeof( V_21 ) >
sizeof( ( (struct V_7 * ) NULL ) -> V_26 ) ) ;
}
static unsigned long F_21 ( void )
{
struct V_7 * V_17 ;
int V_11 ;
unsigned long V_27 ;
V_11 = F_6 () ;
V_17 = & V_4 [ V_11 ] . V_15 ;
V_27 = F_22 ( V_17 ) ;
F_8 () ;
return V_27 ;
}
static void F_23 ( void )
{
unsigned long V_28 ;
V_13 V_29 ;
V_28 = F_21 () ;
V_29 = ( ( V_13 ) V_28 * 1000 ) ;
F_24 ( V_29 , V_30 ) ;
V_31 = V_29 ;
}
bool F_25 ( void )
{
bool V_18 = false ;
struct V_7 * V_17 ;
int V_11 = F_12 () ;
if ( ! V_4 )
return V_18 ;
V_17 = & V_4 [ V_11 ] . V_15 ;
if ( ( V_17 -> V_32 & V_33 ) != 0 ) {
V_17 -> V_32 &= ~ V_33 ;
F_26 () ;
V_18 = true ;
}
return V_18 ;
}
int F_27 ( char * V_34 )
{
int V_11 = F_12 () ;
int V_9 , V_10 , V_18 ;
struct V_7 * V_17 ;
if ( ! V_4 )
return 0 ;
V_17 = & V_4 [ V_11 ] . V_15 ;
V_9 = ( int ) F_28 ( V_17 ) | 1 ;
V_10 = ( ( V_13 ) F_28 ( V_17 ) >> 32 ) ;
V_18 = F_29 ( V_35 , V_9 , V_10 ) ;
F_19 ( V_25 L_2 ,
V_11 , V_10 , V_9 , V_34 ) ;
return V_18 ;
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
static void F_34 ( struct V_36 * V_37 )
{
F_5 ( V_35 , 0 , 0 ) ;
F_35 () ;
F_36 ( V_37 ) ;
}
static void F_37 ( void )
{
F_5 ( V_35 , 0 , 0 ) ;
F_35 () ;
F_38 () ;
}
void T_1 F_39 ( void )
{
struct V_7 * V_8 ;
unsigned long V_38 ;
int V_39 , V_11 ;
T_2 V_32 ;
V_39 = F_40 ( sizeof( struct V_3 ) * V_40 ) ;
if ( ! F_41 () )
return;
if ( V_2 && F_42 ( V_41 ) ) {
V_35 = V_42 ;
V_14 = V_43 ;
} else if ( ! ( V_2 && F_42 ( V_44 ) ) )
return;
F_19 ( V_25 L_5 ,
V_35 , V_14 ) ;
V_38 = F_43 ( V_39 , V_45 ) ;
if ( ! V_38 )
return;
V_4 = F_44 ( V_38 ) ;
memset ( V_4 , 0 , V_39 ) ;
if ( F_27 ( L_6 ) ) {
V_4 = NULL ;
F_45 ( V_38 , V_39 ) ;
return;
}
if ( F_42 ( V_46 ) )
F_46 ( V_47 ) ;
V_11 = F_6 () ;
V_8 = & V_4 [ V_11 ] . V_15 ;
V_32 = F_47 ( V_8 ) ;
F_17 ( V_32 & V_47 ) ;
F_8 () ;
V_48 . V_49 = F_21 ;
V_48 . V_50 = F_21 ;
V_48 . V_51 = F_3 ;
V_48 . V_52 = F_9 ;
#ifdef F_48
V_53 . V_54 =
F_32 ;
#endif
V_48 . V_55 = F_30 ;
V_48 . V_56 = F_31 ;
V_57 . V_58 = F_37 ;
#ifdef F_49
V_57 . V_59 = F_34 ;
#endif
F_23 () ;
F_50 ( & V_60 , V_61 ) ;
V_62 . V_63 = L_7 ;
}
int T_1 F_51 ( void )
{
#ifdef F_52
int V_11 ;
T_2 V_32 ;
struct V_7 * V_8 ;
unsigned int V_39 ;
if ( ! V_4 )
return 0 ;
V_39 = F_40 ( sizeof( struct V_3 ) * V_40 ) ;
V_11 = F_6 () ;
V_8 = & V_4 [ V_11 ] . V_15 ;
V_32 = F_47 ( V_8 ) ;
if ( ! ( V_32 & V_47 ) ) {
F_8 () ;
return 1 ;
}
F_8 () ;
V_60 . V_64 . V_65 = V_66 ;
#endif
return 0 ;
}
