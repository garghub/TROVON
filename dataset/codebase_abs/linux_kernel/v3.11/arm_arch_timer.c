static inline T_1 F_1 ( const int V_1 ,
struct V_2 * V_3 )
{
unsigned long V_4 ;
V_4 = F_2 ( V_1 , V_5 ) ;
if ( V_4 & V_6 ) {
V_4 |= V_7 ;
F_3 ( V_1 , V_5 , V_4 ) ;
V_3 -> V_8 ( V_3 ) ;
return V_9 ;
}
return V_10 ;
}
static T_1 F_4 ( int V_11 , void * V_12 )
{
struct V_2 * V_3 = V_12 ;
return F_1 ( V_13 , V_3 ) ;
}
static T_1 F_5 ( int V_11 , void * V_12 )
{
struct V_2 * V_3 = V_12 ;
return F_1 ( V_14 , V_3 ) ;
}
static inline void F_6 ( const int V_1 , int V_15 )
{
unsigned long V_4 ;
switch ( V_15 ) {
case V_16 :
case V_17 :
V_4 = F_2 ( V_1 , V_5 ) ;
V_4 &= ~ V_18 ;
F_3 ( V_1 , V_5 , V_4 ) ;
break;
default:
break;
}
}
static void F_7 ( enum V_19 V_15 ,
struct V_2 * V_20 )
{
F_6 ( V_13 , V_15 ) ;
}
static void F_8 ( enum V_19 V_15 ,
struct V_2 * V_20 )
{
F_6 ( V_14 , V_15 ) ;
}
static inline void F_9 ( const int V_1 , unsigned long V_3 )
{
unsigned long V_4 ;
V_4 = F_2 ( V_1 , V_5 ) ;
V_4 |= V_18 ;
V_4 &= ~ V_7 ;
F_3 ( V_1 , V_21 , V_3 ) ;
F_3 ( V_1 , V_5 , V_4 ) ;
}
static int F_10 ( unsigned long V_3 ,
struct V_2 * V_22 )
{
F_9 ( V_13 , V_3 ) ;
return 0 ;
}
static int F_11 ( unsigned long V_3 ,
struct V_2 * V_22 )
{
F_9 ( V_14 , V_3 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_20 )
{
V_20 -> V_23 = V_24 | V_25 ;
V_20 -> V_26 = L_1 ;
V_20 -> V_27 = 450 ;
if ( V_28 ) {
V_20 -> V_11 = V_29 [ V_30 ] ;
V_20 -> V_31 = F_7 ;
V_20 -> F_9 = F_10 ;
} else {
V_20 -> V_11 = V_29 [ V_32 ] ;
V_20 -> V_31 = F_8 ;
V_20 -> F_9 = F_11 ;
}
V_20 -> V_33 = F_13 ( F_14 () ) ;
V_20 -> V_31 ( V_17 , NULL ) ;
F_15 ( V_20 , V_34 ,
0xf , 0x7fffffff ) ;
if ( V_28 )
F_16 ( V_29 [ V_30 ] , 0 ) ;
else {
F_16 ( V_29 [ V_32 ] , 0 ) ;
if ( V_29 [ V_35 ] )
F_16 ( V_29 [ V_35 ] , 0 ) ;
}
F_17 () ;
return 0 ;
}
static int F_18 ( void )
{
T_2 V_36 ;
if ( V_34 == 0 ) {
V_36 = F_19 () ;
if ( V_36 == 0 ) {
F_20 ( L_2 ) ;
return - V_37 ;
}
V_34 = V_36 ;
}
F_21 ( L_3 ,
( unsigned long ) V_34 / 1000000 ,
( unsigned long ) ( V_34 / 10000 ) % 100 ,
V_28 ? L_4 : L_5 ) ;
return 0 ;
}
T_2 F_22 ( void )
{
return V_34 ;
}
T_3 F_23 ( void )
{
return F_24 () ;
}
static T_4 F_25 ( struct V_38 * V_39 )
{
return F_24 () ;
}
static T_4 F_26 ( const struct V_40 * V_41 )
{
return F_24 () ;
}
struct V_42 * F_27 ( void )
{
return & V_42 ;
}
static void F_28 ( struct V_2 * V_20 )
{
F_29 ( L_6 ,
V_20 -> V_11 , F_14 () ) ;
if ( V_28 )
F_30 ( V_29 [ V_30 ] ) ;
else {
F_30 ( V_29 [ V_32 ] ) ;
if ( V_29 [ V_35 ] )
F_30 ( V_29 [ V_35 ] ) ;
}
V_20 -> V_31 ( V_16 , V_20 ) ;
}
static int F_31 ( struct V_43 * V_44 ,
unsigned long V_45 , void * V_46 )
{
switch ( V_45 & ~ V_47 ) {
case V_48 :
F_12 ( F_32 ( V_49 ) ) ;
break;
case V_50 :
F_28 ( F_32 ( V_49 ) ) ;
break;
}
return V_51 ;
}
static int T_5 F_33 ( void )
{
int V_52 ;
int V_53 ;
V_52 = F_18 () ;
if ( V_52 )
goto V_54;
V_49 = F_34 ( struct V_2 ) ;
if ( ! V_49 ) {
V_52 = - V_55 ;
goto V_54;
}
F_35 ( & V_56 , V_34 ) ;
V_40 . V_57 = V_56 . V_57 ;
V_40 . V_58 = V_56 . V_58 ;
F_36 ( & V_42 , & V_40 ,
F_24 () ) ;
if ( V_28 ) {
V_53 = V_29 [ V_30 ] ;
V_52 = F_37 ( V_53 , F_4 ,
L_7 , V_49 ) ;
} else {
V_53 = V_29 [ V_32 ] ;
V_52 = F_37 ( V_53 , F_5 ,
L_7 , V_49 ) ;
if ( ! V_52 && V_29 [ V_35 ] ) {
V_53 = V_29 [ V_35 ] ;
V_52 = F_37 ( V_53 , F_5 ,
L_7 , V_49 ) ;
if ( V_52 )
F_38 ( V_29 [ V_32 ] ,
V_49 ) ;
}
}
if ( V_52 ) {
F_39 ( L_8 ,
V_53 , V_52 ) ;
goto V_59;
}
V_52 = F_40 ( & V_60 ) ;
if ( V_52 )
goto V_61;
F_12 ( F_32 ( V_49 ) ) ;
return 0 ;
V_61:
if ( V_28 )
F_38 ( V_29 [ V_30 ] , V_49 ) ;
else {
F_38 ( V_29 [ V_32 ] ,
V_49 ) ;
if ( V_29 [ V_35 ] )
F_38 ( V_29 [ V_35 ] ,
V_49 ) ;
}
V_59:
F_41 ( V_49 ) ;
V_54:
return V_52 ;
}
static void T_5 F_42 ( struct V_62 * V_63 )
{
T_2 V_36 ;
int V_64 ;
if ( F_22 () ) {
F_20 ( L_9 ) ;
return;
}
if ( ! F_43 ( V_63 , L_10 , & V_36 ) )
V_34 = V_36 ;
for ( V_64 = V_32 ; V_64 < V_65 ; V_64 ++ )
V_29 [ V_64 ] = F_44 ( V_63 , V_64 ) ;
F_45 ( V_63 ) ;
if ( F_46 () || ! V_29 [ V_30 ] ) {
V_28 = false ;
if ( ! V_29 [ V_32 ] ||
! V_29 [ V_35 ] ) {
F_20 ( L_11 ) ;
return;
}
}
F_33 () ;
F_47 () ;
}
