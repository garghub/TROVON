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
static void F_6 ( void )
{
struct V_8 * V_8 ;
V_8 = F_7 ( L_1 , NULL ) ;
if ( ! F_8 ( V_8 ) ) {
F_9 ( V_8 , NULL , L_2 ) ;
F_10 ( V_8 ) ;
}
}
static int F_11 ( void )
{
return 0 ;
}
static void F_12 ( T_2 V_9 )
{
static const unsigned V_10 = 1 << 11 ;
F_2 ( V_10 , ( V_9 == V_11 ) ? 0 : V_10 ) ;
}
static void F_13 ( unsigned long V_12 )
{
unsigned long V_5 ;
F_3 ( V_5 ) ;
V_13 &= ~ ( 1 << 0 ) ;
F_4 ( V_5 ) ;
if ( V_13 & ( 1 << 0 ) )
F_14 ( & V_14 , V_15 + V_16 ) ;
else {
( void ) F_15 ( V_17 , ( void * ) V_12 ) ;
F_16 ( V_17 ) ;
}
}
static T_3 F_17 ( int V_18 , void * V_12 )
{
F_18 ( V_18 ) ;
F_14 ( & V_14 , V_15 + V_16 ) ;
return F_15 ( V_18 , V_12 ) ;
}
static int F_19 ( struct V_19 * V_20 ,
T_4 V_21 ,
void * V_12 )
{
F_15 = V_21 ;
F_20 ( & V_14 ) ;
V_14 . V_12 = ( unsigned long ) V_12 ;
return F_21 ( V_17 , F_17 ,
0 , L_3 , V_12 ) ;
}
static int F_22 ( struct V_19 * V_20 )
{
return ( V_7 & ( 1 << 2 ) ) != 0 ;
}
static void F_23 ( struct V_19 * V_20 , void * V_12 )
{
F_24 ( V_17 , V_12 ) ;
F_25 ( & V_14 ) ;
}
static void F_26 ( struct V_19 * V_20 , int V_22 )
{
unsigned long V_5 ;
F_3 ( V_5 ) ;
if ( V_22 & V_23 ) {
V_6 &= ~ ( 1 << 4 ) ;
} else if ( V_22 & V_24 ) {
V_6 |= 1 << 4 ;
}
F_27 ( V_20 , V_22 ) ;
F_4 ( V_5 ) ;
}
static void T_5 F_28 ( void )
{
int V_25 = ( V_26 & 1 ) ;
F_29 ( F_30 ( V_27 ) ) ;
F_31 ( NULL ) ;
F_32 ( NULL ) ;
F_33 ( NULL ) ;
F_6 () ;
F_34 ( L_4 , NULL , L_5 , NULL ) ;
F_35 ( & V_28 ) ;
F_36 ( NULL , & V_29 ) ;
F_37 ( & V_30 ) ;
F_38 ( & V_31 ) ;
F_39 ( NULL ) ;
V_32 [ 0 ] . V_33 = V_32 [ 1 ] . V_33 =
( F_40 ( V_34 ) & 1 ) ? 2 : 4 ;
F_41 ( V_35 L_6 ,
V_25 ? L_7 : L_8 , V_25 ) ;
V_32 [ V_25 ^ 1 ] . V_36 = L_9 ;
V_32 [ V_25 ] . V_36 = L_10 ;
( void ) F_42 ( V_37 , F_43 ( V_37 ) ) ;
F_44 ( 1 , & V_38 ) ;
F_45 ( V_39 , F_43 ( V_39 ) ) ;
}
static void T_5 F_46 ( void )
{
F_47 () ;
F_48 ( V_40 , F_43 ( V_40 ) ) ;
V_41 |= V_42 ;
}
static void F_49 ( struct V_43 * V_44 ,
enum V_45 V_46 )
{
struct V_47 * V_48 = F_50 ( V_44 ,
struct V_47 , V_44 ) ;
T_2 V_49 = V_50 ;
if ( V_46 != V_51 )
V_49 |= V_48 -> V_3 ;
else
V_49 &= ~ V_48 -> V_3 ;
V_50 = V_49 ;
}
static enum V_45 F_51 ( struct V_43 * V_44 )
{
struct V_47 * V_48 = F_50 ( V_44 ,
struct V_47 , V_44 ) ;
T_2 V_49 = V_50 ;
return ( V_49 & V_48 -> V_3 ) ? V_52 : V_51 ;
}
static int T_5 F_52 ( void )
{
int V_53 ;
if ( ! F_53 () )
return - V_54 ;
V_50 |= 0xff ;
for ( V_53 = 0 ; V_53 < F_43 ( V_55 ) ; V_53 ++ ) {
struct V_47 * V_48 ;
V_48 = F_54 ( sizeof( * V_48 ) , V_56 ) ;
if ( ! V_48 )
break;
V_48 -> V_44 . V_36 = V_55 [ V_53 ] . V_36 ;
V_48 -> V_44 . V_57 = F_49 ;
V_48 -> V_44 . V_58 = F_51 ;
V_48 -> V_44 . V_59 = V_55 [ V_53 ] . V_60 ;
V_48 -> V_3 = F_55 ( V_53 ) ;
if ( F_56 ( NULL , & V_48 -> V_44 ) < 0 ) {
F_57 ( V_48 ) ;
break;
}
}
return 0 ;
}
