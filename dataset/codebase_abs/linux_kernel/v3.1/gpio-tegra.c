static int F_1 ( int V_1 , int V_2 , int V_3 )
{
return ( V_1 << 5 ) | ( ( V_2 & 0x3 ) << 3 ) | ( V_3 & 0x7 ) ;
}
static void F_2 ( T_1 V_4 , int V_5 , int V_6 )
{
T_1 V_7 ;
V_7 = 0x100 << F_3 ( V_5 ) ;
if ( V_6 )
V_7 |= 1 << F_3 ( V_5 ) ;
F_4 ( V_7 , V_4 ) ;
}
void F_5 ( int V_5 )
{
F_2 ( F_6 ( V_5 ) , V_5 , 1 ) ;
}
void F_7 ( int V_5 )
{
F_2 ( F_6 ( V_5 ) , V_5 , 0 ) ;
}
static void F_8 ( struct V_8 * V_9 , unsigned V_10 , int V_6 )
{
F_2 ( F_9 ( V_10 ) , V_10 , V_6 ) ;
}
static int F_10 ( struct V_8 * V_9 , unsigned V_10 )
{
return ( F_11 ( F_12 ( V_10 ) ) >> F_3 ( V_10 ) ) & 0x1 ;
}
static int F_13 ( struct V_8 * V_9 , unsigned V_10 )
{
F_2 ( F_14 ( V_10 ) , V_10 , 0 ) ;
return 0 ;
}
static int F_15 ( struct V_8 * V_9 , unsigned V_10 ,
int V_6 )
{
F_8 ( V_9 , V_10 , V_6 ) ;
F_2 ( F_14 ( V_10 ) , V_10 , 1 ) ;
return 0 ;
}
static void F_16 ( struct V_11 * V_12 )
{
int V_5 = V_12 -> V_13 - V_14 ;
F_4 ( 1 << F_3 ( V_5 ) , F_17 ( V_5 ) ) ;
}
static void F_18 ( struct V_11 * V_12 )
{
int V_5 = V_12 -> V_13 - V_14 ;
F_2 ( F_19 ( V_5 ) , V_5 , 0 ) ;
}
static void F_20 ( struct V_11 * V_12 )
{
int V_5 = V_12 -> V_13 - V_14 ;
F_2 ( F_19 ( V_5 ) , V_5 , 1 ) ;
}
static int F_21 ( struct V_11 * V_12 , unsigned int type )
{
int V_5 = V_12 -> V_13 - V_14 ;
struct V_15 * V_1 = F_22 ( V_12 ) ;
int V_2 = F_23 ( V_5 ) ;
int V_16 ;
int V_7 ;
unsigned long V_17 ;
switch ( type & V_18 ) {
case V_19 :
V_16 = V_20 ;
break;
case V_21 :
V_16 = V_22 ;
break;
case V_23 :
V_16 = V_24 ;
break;
case V_25 :
V_16 = V_26 ;
break;
case V_27 :
V_16 = V_28 ;
break;
default:
return - V_29 ;
}
F_24 ( & V_1 -> V_30 [ V_2 ] , V_17 ) ;
V_7 = F_11 ( F_25 ( V_5 ) ) ;
V_7 &= ~ ( V_31 << F_3 ( V_5 ) ) ;
V_7 |= V_16 << F_3 ( V_5 ) ;
F_4 ( V_7 , F_25 ( V_5 ) ) ;
F_26 ( & V_1 -> V_30 [ V_2 ] , V_17 ) ;
if ( type & ( V_27 | V_25 ) )
F_27 ( V_12 -> V_13 , V_32 ) ;
else if ( type & ( V_21 | V_19 ) )
F_27 ( V_12 -> V_13 , V_33 ) ;
return 0 ;
}
static void F_28 ( unsigned int V_13 , struct V_34 * V_35 )
{
struct V_15 * V_1 ;
int V_2 ;
int V_36 ;
int V_37 = 0 ;
struct V_38 * V_9 = F_29 ( V_35 ) ;
F_30 ( V_9 , V_35 ) ;
V_1 = F_31 ( V_13 ) ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ ) {
int V_5 = F_1 ( V_1 -> V_1 , V_2 , 0 ) ;
unsigned long V_39 = F_11 ( F_32 ( V_5 ) ) &
F_11 ( F_33 ( V_5 ) ) ;
T_1 V_40 = F_11 ( F_25 ( V_5 ) ) ;
F_34 (pin, &sta, 8 ) {
F_4 ( 1 << V_36 , F_17 ( V_5 ) ) ;
if ( V_40 & ( 0x100 << V_36 ) ) {
V_37 = 1 ;
F_35 ( V_9 , V_35 ) ;
}
F_36 ( F_37 ( V_5 + V_36 ) ) ;
}
}
if ( ! V_37 )
F_35 ( V_9 , V_35 ) ;
}
void F_38 ( void )
{
unsigned long V_17 ;
int V_41 ;
int V_42 ;
F_39 ( V_17 ) ;
for ( V_41 = 0 ; V_41 < F_40 ( V_43 ) ; V_41 ++ ) {
struct V_15 * V_1 = & V_43 [ V_41 ] ;
for ( V_42 = 0 ; V_42 < F_40 ( V_1 -> V_44 ) ; V_42 ++ ) {
unsigned int V_5 = ( V_41 << 5 ) | ( V_42 << 3 ) ;
F_4 ( V_1 -> V_45 [ V_42 ] , F_41 ( V_5 ) ) ;
F_4 ( V_1 -> V_46 [ V_42 ] , F_42 ( V_5 ) ) ;
F_4 ( V_1 -> V_44 [ V_42 ] , F_43 ( V_5 ) ) ;
F_4 ( V_1 -> V_47 [ V_42 ] , F_25 ( V_5 ) ) ;
F_4 ( V_1 -> V_48 [ V_42 ] , F_33 ( V_5 ) ) ;
}
}
F_44 ( V_17 ) ;
}
void F_45 ( void )
{
unsigned long V_17 ;
int V_41 ;
int V_42 ;
F_39 ( V_17 ) ;
for ( V_41 = 0 ; V_41 < F_40 ( V_43 ) ; V_41 ++ ) {
struct V_15 * V_1 = & V_43 [ V_41 ] ;
for ( V_42 = 0 ; V_42 < F_40 ( V_1 -> V_44 ) ; V_42 ++ ) {
unsigned int V_5 = ( V_41 << 5 ) | ( V_42 << 3 ) ;
V_1 -> V_45 [ V_42 ] = F_11 ( F_41 ( V_5 ) ) ;
V_1 -> V_46 [ V_42 ] = F_11 ( F_42 ( V_5 ) ) ;
V_1 -> V_44 [ V_42 ] = F_11 ( F_43 ( V_5 ) ) ;
V_1 -> V_48 [ V_42 ] = F_11 ( F_33 ( V_5 ) ) ;
V_1 -> V_47 [ V_42 ] = F_11 ( F_25 ( V_5 ) ) ;
}
}
F_44 ( V_17 ) ;
}
static int F_46 ( struct V_11 * V_12 , unsigned int V_49 )
{
struct V_15 * V_1 = F_22 ( V_12 ) ;
return F_47 ( V_1 -> V_13 , V_49 ) ;
}
static int T_2 F_48 ( void )
{
struct V_15 * V_1 ;
int V_50 ;
int V_51 ;
for ( V_50 = 0 ; V_50 < 7 ; V_50 ++ ) {
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
int V_5 = F_1 ( V_50 , V_51 , 0 ) ;
F_4 ( 0x00 , F_33 ( V_5 ) ) ;
}
}
#ifdef F_49
V_52 . V_53 = F_50 ( NULL , NULL ,
L_1 ) ;
#endif
F_51 ( & V_52 ) ;
for ( V_50 = V_14 ; V_50 < ( V_14 + V_54 ) ; V_50 ++ ) {
V_1 = & V_43 [ F_52 ( F_53 ( V_50 ) ) ] ;
F_54 ( V_50 , & V_55 ) ;
F_55 ( V_50 , V_1 ) ;
F_56 ( V_50 , & V_56 ,
V_57 ) ;
F_57 ( V_50 , V_58 ) ;
}
for ( V_50 = 0 ; V_50 < F_40 ( V_43 ) ; V_50 ++ ) {
V_1 = & V_43 [ V_50 ] ;
F_58 ( V_1 -> V_13 , F_28 ) ;
F_59 ( V_1 -> V_13 , V_1 ) ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ )
F_60 ( & V_1 -> V_30 [ V_51 ] ) ;
}
return 0 ;
}
void T_2 F_61 ( struct V_59 * V_60 , int V_61 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_61 ; V_50 ++ ) {
int V_5 = V_60 [ V_50 ] . V_5 ;
if ( V_60 [ V_50 ] . V_49 )
F_5 ( V_5 ) ;
else
F_7 ( V_5 ) ;
}
}
static int F_62 ( struct V_62 * V_63 , void * V_64 )
{
int V_50 ;
int V_51 ;
for ( V_50 = 0 ; V_50 < 7 ; V_50 ++ ) {
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
int V_5 = F_1 ( V_50 , V_51 , 0 ) ;
F_63 ( V_63 ,
L_2 ,
V_50 , V_51 ,
F_11 ( F_41 ( V_5 ) ) ,
F_11 ( F_43 ( V_5 ) ) ,
F_11 ( F_42 ( V_5 ) ) ,
F_11 ( F_12 ( V_5 ) ) ,
F_11 ( F_32 ( V_5 ) ) ,
F_11 ( F_33 ( V_5 ) ) ,
F_11 ( F_25 ( V_5 ) ) ) ;
}
}
return 0 ;
}
static int F_64 ( struct V_65 * V_65 , struct V_66 * V_66 )
{
return F_65 ( V_66 , F_62 , & V_65 -> V_67 ) ;
}
static int T_2 F_66 ( void )
{
( void ) F_67 ( L_3 , V_68 ,
NULL , NULL , & V_69 ) ;
return 0 ;
}
