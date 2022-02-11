void F_1 ( T_1 V_1 )
{
V_2 = V_1 ;
}
void F_2 ( unsigned int V_3 , unsigned int V_4 )
{
unsigned long V_5 ;
F_3 ( V_5 ) ;
V_6 = ( V_6 & ~ V_3 ) | ( V_4 & V_3 ) ;
F_4 ( V_5 ) ;
}
static int F_5 ( void )
{
return ( V_7 & ( 1 << 9 ) ) == 0 ;
}
static int F_6 ( void )
{
return 0 ;
}
static void F_7 ( T_2 V_8 )
{
static const unsigned V_9 = 1 << 11 ;
F_2 ( V_9 , ( V_8 == V_10 ) ? 0 : V_9 ) ;
}
static void F_8 ( unsigned long V_11 )
{
unsigned long V_5 ;
F_3 ( V_5 ) ;
V_12 &= ~ ( 1 << 0 ) ;
F_4 ( V_5 ) ;
if ( V_12 & ( 1 << 0 ) )
F_9 ( & V_13 , V_14 + V_15 ) ;
else {
( void ) F_10 ( V_16 , ( void * ) V_11 ) ;
F_11 ( V_16 ) ;
}
}
static T_3 F_12 ( int V_17 , void * V_11 )
{
F_13 ( V_17 ) ;
F_9 ( & V_13 , V_14 + V_15 ) ;
return F_10 ( V_17 , V_11 ) ;
}
static int F_14 ( struct V_18 * V_19 ,
T_4 V_20 ,
void * V_11 )
{
F_10 = V_20 ;
F_15 ( & V_13 ) ;
V_13 . V_11 = ( unsigned long ) V_11 ;
return F_16 ( V_16 , F_12 ,
0 , L_1 , V_11 ) ;
}
static int F_17 ( struct V_18 * V_19 )
{
return ( V_7 & ( 1 << 2 ) ) != 0 ;
}
static void F_18 ( struct V_18 * V_19 , void * V_11 )
{
F_19 ( V_16 , V_11 ) ;
F_20 ( & V_13 ) ;
}
static void F_21 ( struct V_18 * V_19 , int V_21 )
{
unsigned long V_5 ;
F_3 ( V_5 ) ;
if ( V_21 & V_22 ) {
V_6 &= ~ ( 1 << 4 ) ;
} else if ( V_21 & V_23 ) {
V_6 |= 1 << 4 ;
}
F_22 ( V_19 , V_21 ) ;
F_4 ( V_5 ) ;
}
static void T_5 F_23 ( void )
{
int V_24 = ( V_25 & 1 ) ;
F_24 ( F_25 ( V_26 ) ) ;
F_26 ( NULL ) ;
F_27 ( NULL ) ;
F_28 ( NULL ) ;
F_29 ( L_2 , NULL , L_3 , NULL ) ;
F_30 ( & V_27 ) ;
F_31 ( NULL , & V_28 ) ;
F_32 ( & V_29 ) ;
F_33 ( & V_30 ) ;
F_34 ( NULL ) ;
V_31 [ 0 ] . V_32 = V_31 [ 1 ] . V_32 =
( F_35 ( V_33 ) & 1 ) ? 2 : 4 ;
F_36 ( V_34 L_4 ,
V_24 ? L_5 : L_6 , V_24 ) ;
V_31 [ V_24 ^ 1 ] . V_35 = L_7 ;
V_31 [ V_24 ] . V_35 = L_8 ;
( void ) F_37 ( V_36 , F_38 ( V_36 ) ) ;
F_39 ( 1 , & V_37 ) ;
F_40 ( V_38 , F_38 ( V_38 ) ) ;
}
static void T_5 F_41 ( void )
{
F_42 () ;
F_43 ( V_39 , F_38 ( V_39 ) ) ;
V_40 |= V_41 ;
}
static void F_44 ( struct V_42 * V_43 ,
enum V_44 V_45 )
{
struct V_46 * V_47 = F_45 ( V_43 ,
struct V_46 , V_43 ) ;
T_2 V_48 = V_49 ;
if ( V_45 != V_50 )
V_48 |= V_47 -> V_3 ;
else
V_48 &= ~ V_47 -> V_3 ;
V_49 = V_48 ;
}
static enum V_44 F_46 ( struct V_42 * V_43 )
{
struct V_46 * V_47 = F_45 ( V_43 ,
struct V_46 , V_43 ) ;
T_2 V_48 = V_49 ;
return ( V_48 & V_47 -> V_3 ) ? V_51 : V_50 ;
}
static int T_5 F_47 ( void )
{
int V_52 ;
if ( ! F_48 () )
return - V_53 ;
V_49 |= 0xff ;
for ( V_52 = 0 ; V_52 < F_38 ( V_54 ) ; V_52 ++ ) {
struct V_46 * V_47 ;
V_47 = F_49 ( sizeof( * V_47 ) , V_55 ) ;
if ( ! V_47 )
break;
V_47 -> V_43 . V_35 = V_54 [ V_52 ] . V_35 ;
V_47 -> V_43 . V_56 = F_44 ;
V_47 -> V_43 . V_57 = F_46 ;
V_47 -> V_43 . V_58 = V_54 [ V_52 ] . V_59 ;
V_47 -> V_3 = F_50 ( V_52 ) ;
if ( F_51 ( NULL , & V_47 -> V_43 ) < 0 ) {
F_52 ( V_47 ) ;
break;
}
}
return 0 ;
}
