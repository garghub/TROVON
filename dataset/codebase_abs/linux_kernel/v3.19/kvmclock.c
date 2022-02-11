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
static unsigned long F_15 ( void )
{
struct V_5 * V_15 ;
int V_9 ;
unsigned long V_19 ;
V_9 = F_5 () ;
V_15 = & V_13 [ V_9 ] . V_14 ;
V_19 = F_16 ( V_15 ) ;
F_7 () ;
return V_19 ;
}
static void F_17 ( void )
{
unsigned long V_20 ;
V_11 V_21 ;
V_20 = F_15 () ;
V_21 = ( ( V_11 ) V_20 * 1000 ) ;
F_18 ( V_21 , V_22 ) ;
V_23 = V_21 ;
}
bool F_19 ( void )
{
bool V_16 = false ;
struct V_5 * V_15 ;
int V_9 = F_11 () ;
if ( ! V_13 )
return V_16 ;
V_15 = & V_13 [ V_9 ] . V_14 ;
if ( ( V_15 -> V_24 & V_25 ) != 0 ) {
V_15 -> V_24 &= ~ V_25 ;
F_20 () ;
V_16 = true ;
}
return V_16 ;
}
int F_21 ( char * V_26 )
{
int V_9 = F_11 () ;
int V_7 , V_8 , V_16 ;
struct V_5 * V_15 ;
if ( ! V_13 )
return 0 ;
V_15 = & V_13 [ V_9 ] . V_14 ;
V_7 = ( int ) F_22 ( V_15 ) | 1 ;
V_8 = ( ( V_11 ) F_22 ( V_15 ) >> 32 ) ;
V_16 = F_23 ( V_27 , V_7 , V_8 ) ;
F_24 ( V_28 L_1 ,
V_9 , V_8 , V_7 , V_26 ) ;
return V_16 ;
}
static void F_25 ( void )
{
}
static void F_26 ( void )
{
F_21 ( L_2 ) ;
}
static void F_27 ( void )
{
F_28 ( F_21 ( L_3 ) ) ;
}
static void F_29 ( struct V_29 * V_30 )
{
F_4 ( V_27 , 0 , 0 ) ;
F_30 () ;
F_31 ( V_30 ) ;
}
static void F_32 ( void )
{
F_4 ( V_27 , 0 , 0 ) ;
F_30 () ;
F_33 () ;
}
void T_2 F_34 ( void )
{
unsigned long V_31 ;
int V_32 ;
V_32 = F_35 ( sizeof( struct V_33 ) * V_34 ) ;
if ( ! F_36 () )
return;
if ( V_2 && F_37 ( V_35 ) ) {
V_27 = V_36 ;
V_12 = V_37 ;
} else if ( ! ( V_2 && F_37 ( V_38 ) ) )
return;
F_24 ( V_28 L_4 ,
V_27 , V_12 ) ;
V_31 = F_38 ( V_32 , V_39 ) ;
if ( ! V_31 )
return;
V_13 = F_39 ( V_31 ) ;
memset ( V_13 , 0 , V_32 ) ;
if ( F_21 ( L_5 ) ) {
V_13 = NULL ;
F_40 ( V_31 , V_32 ) ;
return;
}
V_40 . V_41 = F_9 ;
V_42 . V_43 = F_15 ;
V_42 . V_44 = F_2 ;
V_42 . V_45 = F_8 ;
#ifdef F_41
V_46 . V_47 =
F_27 ;
#endif
V_42 . V_48 = F_25 ;
V_42 . V_49 = F_26 ;
V_50 . V_51 = F_32 ;
#ifdef F_42
V_50 . V_52 = F_29 ;
#endif
F_17 () ;
F_43 ( & V_53 , V_54 ) ;
V_55 . V_56 = L_6 ;
if ( F_37 ( V_57 ) )
F_44 ( V_58 ) ;
}
int T_2 F_45 ( void )
{
#ifdef F_46
int V_9 ;
int V_16 ;
T_3 V_24 ;
struct V_5 * V_6 ;
unsigned int V_32 ;
if ( ! V_13 )
return 0 ;
V_32 = F_35 ( sizeof( struct V_33 ) * V_34 ) ;
V_9 = F_5 () ;
V_6 = & V_13 [ V_9 ] . V_14 ;
V_24 = F_47 ( V_6 ) ;
if ( ! ( V_24 & V_58 ) ) {
F_7 () ;
return 1 ;
}
if ( ( V_16 = F_48 ( V_13 , V_32 ) ) ) {
F_7 () ;
return V_16 ;
}
F_7 () ;
V_53 . V_59 . V_60 = V_61 ;
#endif
return 0 ;
}
