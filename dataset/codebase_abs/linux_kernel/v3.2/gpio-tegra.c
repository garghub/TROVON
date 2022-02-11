static inline void F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( V_1 , V_3 + V_2 ) ;
}
static inline T_1 F_3 ( T_1 V_2 )
{
return F_4 ( V_3 + V_2 ) ;
}
static int F_5 ( int V_4 , int V_5 , int V_6 )
{
return ( V_4 << 5 ) | ( ( V_5 & 0x3 ) << 3 ) | ( V_6 & 0x7 ) ;
}
static void F_6 ( T_1 V_2 , int V_7 , int V_8 )
{
T_1 V_1 ;
V_1 = 0x100 << F_7 ( V_7 ) ;
if ( V_8 )
V_1 |= 1 << F_7 ( V_7 ) ;
F_1 ( V_1 , V_2 ) ;
}
void F_8 ( int V_7 )
{
F_6 ( F_9 ( V_7 ) , V_7 , 1 ) ;
}
void F_10 ( int V_7 )
{
F_6 ( F_9 ( V_7 ) , V_7 , 0 ) ;
}
static void F_11 ( struct V_9 * V_10 , unsigned V_11 , int V_8 )
{
F_6 ( F_12 ( V_11 ) , V_11 , V_8 ) ;
}
static int F_13 ( struct V_9 * V_10 , unsigned V_11 )
{
return ( F_3 ( F_14 ( V_11 ) ) >> F_7 ( V_11 ) ) & 0x1 ;
}
static int F_15 ( struct V_9 * V_10 , unsigned V_11 )
{
F_6 ( F_16 ( V_11 ) , V_11 , 0 ) ;
return 0 ;
}
static int F_17 ( struct V_9 * V_10 , unsigned V_11 ,
int V_8 )
{
F_11 ( V_10 , V_11 , V_8 ) ;
F_6 ( F_16 ( V_11 ) , V_11 , 1 ) ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 , unsigned V_11 )
{
return F_19 ( V_11 ) ;
}
static void F_20 ( struct V_12 * V_13 )
{
int V_7 = V_13 -> V_14 - V_15 ;
F_1 ( 1 << F_7 ( V_7 ) , F_21 ( V_7 ) ) ;
}
static void F_22 ( struct V_12 * V_13 )
{
int V_7 = V_13 -> V_14 - V_15 ;
F_6 ( F_23 ( V_7 ) , V_7 , 0 ) ;
}
static void F_24 ( struct V_12 * V_13 )
{
int V_7 = V_13 -> V_14 - V_15 ;
F_6 ( F_23 ( V_7 ) , V_7 , 1 ) ;
}
static int F_25 ( struct V_12 * V_13 , unsigned int type )
{
int V_7 = V_13 -> V_14 - V_15 ;
struct V_16 * V_4 = F_26 ( V_13 ) ;
int V_5 = F_27 ( V_7 ) ;
int V_17 ;
int V_1 ;
unsigned long V_18 ;
switch ( type & V_19 ) {
case V_20 :
V_17 = V_21 ;
break;
case V_22 :
V_17 = V_23 ;
break;
case V_24 :
V_17 = V_25 ;
break;
case V_26 :
V_17 = V_27 ;
break;
case V_28 :
V_17 = V_29 ;
break;
default:
return - V_30 ;
}
F_28 ( & V_4 -> V_31 [ V_5 ] , V_18 ) ;
V_1 = F_3 ( F_29 ( V_7 ) ) ;
V_1 &= ~ ( V_32 << F_7 ( V_7 ) ) ;
V_1 |= V_17 << F_7 ( V_7 ) ;
F_1 ( V_1 , F_29 ( V_7 ) ) ;
F_30 ( & V_4 -> V_31 [ V_5 ] , V_18 ) ;
if ( type & ( V_28 | V_26 ) )
F_31 ( V_13 -> V_14 , V_33 ) ;
else if ( type & ( V_22 | V_20 ) )
F_31 ( V_13 -> V_14 , V_34 ) ;
return 0 ;
}
static void F_32 ( unsigned int V_14 , struct V_35 * V_36 )
{
struct V_16 * V_4 ;
int V_5 ;
int V_37 ;
int V_38 = 0 ;
struct V_39 * V_10 = F_33 ( V_36 ) ;
F_34 ( V_10 , V_36 ) ;
V_4 = F_35 ( V_14 ) ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
int V_7 = F_5 ( V_4 -> V_4 , V_5 , 0 ) ;
unsigned long V_40 = F_3 ( F_36 ( V_7 ) ) &
F_3 ( F_37 ( V_7 ) ) ;
T_1 V_41 = F_3 ( F_29 ( V_7 ) ) ;
F_38 (pin, &sta, 8 ) {
F_1 ( 1 << V_37 , F_21 ( V_7 ) ) ;
if ( V_41 & ( 0x100 << V_37 ) ) {
V_38 = 1 ;
F_39 ( V_10 , V_36 ) ;
}
F_40 ( F_41 ( V_7 + V_37 ) ) ;
}
}
if ( ! V_38 )
F_39 ( V_10 , V_36 ) ;
}
void F_42 ( void )
{
unsigned long V_18 ;
int V_42 ;
int V_43 ;
F_43 ( V_18 ) ;
for ( V_42 = 0 ; V_42 < F_44 ( V_44 ) ; V_42 ++ ) {
struct V_16 * V_4 = & V_44 [ V_42 ] ;
for ( V_43 = 0 ; V_43 < F_44 ( V_4 -> V_45 ) ; V_43 ++ ) {
unsigned int V_7 = ( V_42 << 5 ) | ( V_43 << 3 ) ;
F_1 ( V_4 -> V_46 [ V_43 ] , F_45 ( V_7 ) ) ;
F_1 ( V_4 -> V_47 [ V_43 ] , F_46 ( V_7 ) ) ;
F_1 ( V_4 -> V_45 [ V_43 ] , F_47 ( V_7 ) ) ;
F_1 ( V_4 -> V_48 [ V_43 ] , F_29 ( V_7 ) ) ;
F_1 ( V_4 -> V_49 [ V_43 ] , F_37 ( V_7 ) ) ;
}
}
F_48 ( V_18 ) ;
}
void F_49 ( void )
{
unsigned long V_18 ;
int V_42 ;
int V_43 ;
F_43 ( V_18 ) ;
for ( V_42 = 0 ; V_42 < F_44 ( V_44 ) ; V_42 ++ ) {
struct V_16 * V_4 = & V_44 [ V_42 ] ;
for ( V_43 = 0 ; V_43 < F_44 ( V_4 -> V_45 ) ; V_43 ++ ) {
unsigned int V_7 = ( V_42 << 5 ) | ( V_43 << 3 ) ;
V_4 -> V_46 [ V_43 ] = F_3 ( F_45 ( V_7 ) ) ;
V_4 -> V_47 [ V_43 ] = F_3 ( F_46 ( V_7 ) ) ;
V_4 -> V_45 [ V_43 ] = F_3 ( F_47 ( V_7 ) ) ;
V_4 -> V_49 [ V_43 ] = F_3 ( F_37 ( V_7 ) ) ;
V_4 -> V_48 [ V_43 ] = F_3 ( F_29 ( V_7 ) ) ;
}
}
F_48 ( V_18 ) ;
}
static int F_50 ( struct V_12 * V_13 , unsigned int V_50 )
{
struct V_16 * V_4 = F_26 ( V_13 ) ;
return F_51 ( V_4 -> V_14 , V_50 ) ;
}
static int T_2 F_52 ( struct V_51 * V_52 )
{
struct V_53 * V_54 ;
struct V_16 * V_4 ;
int V_7 ;
int V_55 ;
int V_56 ;
for ( V_55 = 0 ; V_55 < F_44 ( V_44 ) ; V_55 ++ ) {
V_54 = F_53 ( V_52 , V_57 , V_55 ) ;
if ( ! V_54 ) {
F_54 ( & V_52 -> V_58 , L_1 ) ;
return - V_59 ;
}
V_4 = & V_44 [ V_55 ] ;
V_4 -> V_4 = V_55 ;
V_4 -> V_14 = V_54 -> V_60 ;
}
V_54 = F_53 ( V_52 , V_61 , 0 ) ;
if ( ! V_54 ) {
F_54 ( & V_52 -> V_58 , L_2 ) ;
return - V_59 ;
}
if ( ! F_55 ( & V_52 -> V_58 , V_54 -> V_60 ,
F_56 ( V_54 ) ,
F_57 ( & V_52 -> V_58 ) ) ) {
F_54 ( & V_52 -> V_58 , L_3 ) ;
return - V_59 ;
}
V_3 = F_58 ( & V_52 -> V_58 , V_54 -> V_60 , F_56 ( V_54 ) ) ;
if ( ! V_3 ) {
F_54 ( & V_52 -> V_58 , L_4 ) ;
return - V_59 ;
}
for ( V_55 = 0 ; V_55 < 7 ; V_55 ++ ) {
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ ) {
int V_7 = F_5 ( V_55 , V_56 , 0 ) ;
F_1 ( 0x00 , F_37 ( V_7 ) ) ;
}
}
#ifdef F_59
V_62 . V_63 = V_52 -> V_58 . V_63 ;
#endif
F_60 ( & V_62 ) ;
for ( V_7 = 0 ; V_7 < V_64 ; V_7 ++ ) {
int V_14 = F_19 ( V_7 ) ;
V_4 = & V_44 [ F_61 ( V_7 ) ] ;
F_62 ( V_14 , & V_65 ) ;
F_63 ( V_14 , V_4 ) ;
F_64 ( V_14 , & V_66 ,
V_67 ) ;
F_65 ( V_14 , V_68 ) ;
}
for ( V_55 = 0 ; V_55 < F_44 ( V_44 ) ; V_55 ++ ) {
V_4 = & V_44 [ V_55 ] ;
F_66 ( V_4 -> V_14 , F_32 ) ;
F_67 ( V_4 -> V_14 , V_4 ) ;
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ )
F_68 ( & V_4 -> V_31 [ V_56 ] ) ;
}
return 0 ;
}
static int T_3 F_69 ( void )
{
return F_70 ( & V_69 ) ;
}
void T_3 F_71 ( struct V_70 * V_71 , int V_72 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_72 ; V_55 ++ ) {
int V_7 = V_71 [ V_55 ] . V_7 ;
if ( V_71 [ V_55 ] . V_50 )
F_8 ( V_7 ) ;
else
F_10 ( V_7 ) ;
}
}
static int F_72 ( struct V_73 * V_74 , void * V_75 )
{
int V_55 ;
int V_56 ;
for ( V_55 = 0 ; V_55 < 7 ; V_55 ++ ) {
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ ) {
int V_7 = F_5 ( V_55 , V_56 , 0 ) ;
F_73 ( V_74 ,
L_5 ,
V_55 , V_56 ,
F_3 ( F_45 ( V_7 ) ) ,
F_3 ( F_47 ( V_7 ) ) ,
F_3 ( F_46 ( V_7 ) ) ,
F_3 ( F_14 ( V_7 ) ) ,
F_3 ( F_36 ( V_7 ) ) ,
F_3 ( F_37 ( V_7 ) ) ,
F_3 ( F_29 ( V_7 ) ) ) ;
}
}
return 0 ;
}
static int F_74 ( struct V_76 * V_76 , struct V_77 * V_77 )
{
return F_75 ( V_77 , F_72 , & V_76 -> V_78 ) ;
}
static int T_3 F_76 ( void )
{
( void ) F_77 ( L_6 , V_79 ,
NULL , NULL , & V_80 ) ;
return 0 ;
}
