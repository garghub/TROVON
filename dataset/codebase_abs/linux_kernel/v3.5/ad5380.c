static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return sprintf ( V_5 , L_1 , V_9 -> V_10 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
bool V_10 ;
int V_12 ;
V_12 = F_5 ( V_5 , & V_10 ) ;
if ( V_12 )
return V_12 ;
F_6 ( & V_7 -> V_13 ) ;
if ( V_10 )
V_12 = F_7 ( V_9 -> V_14 , V_15 , 0 ) ;
else
V_12 = F_7 ( V_9 -> V_14 , V_16 , 0 ) ;
V_9 -> V_10 = V_10 ;
F_8 ( & V_7 -> V_13 ) ;
return V_12 ? V_12 : V_11 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned int V_17 ;
int V_12 ;
V_12 = F_10 ( V_9 -> V_14 , V_18 , & V_17 ) ;
if ( V_12 )
return V_12 ;
V_17 = ( V_17 >> V_19 ) & 1 ;
return sprintf ( V_5 , L_2 , V_20 [ V_17 ] ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned int V_21 ;
int V_12 ;
for ( V_21 = 0 ; V_21 < F_12 ( V_20 ) ; ++ V_21 ) {
if ( F_13 ( V_5 , V_20 [ V_21 ] ) )
break;
}
if ( V_21 == F_12 ( V_20 ) )
return - V_22 ;
V_12 = F_14 ( V_9 -> V_14 , V_18 ,
1 << V_19 ,
V_21 << V_19 ) ;
return V_12 ? V_12 : V_11 ;
}
static unsigned int F_15 ( struct V_23 const * V_24 ,
long V_25 )
{
switch ( V_25 ) {
case 0 :
return F_16 ( V_24 -> V_26 ) ;
case V_27 :
return F_17 ( V_24 -> V_26 ) ;
case V_28 :
return F_18 ( V_24 -> V_26 ) ;
default:
break;
}
return 0 ;
}
static int F_19 ( struct V_6 * V_7 ,
struct V_23 const * V_24 , int V_29 , int V_30 , long V_25 )
{
const unsigned int V_31 = ( 1 << V_24 -> V_32 . V_33 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
switch ( V_25 ) {
case V_34 :
case V_28 :
if ( V_29 >= V_31 || V_29 < 0 )
return - V_22 ;
return F_7 ( V_9 -> V_14 ,
F_15 ( V_24 , V_25 ) ,
V_29 << V_24 -> V_32 . V_35 ) ;
case V_27 :
V_29 += ( 1 << V_24 -> V_32 . V_33 ) / 2 ;
if ( V_29 >= V_31 || V_29 < 0 )
return - V_22 ;
return F_7 ( V_9 -> V_14 ,
F_17 ( V_24 -> V_26 ) ,
V_29 << V_24 -> V_32 . V_35 ) ;
default:
break;
}
return - V_22 ;
}
static int F_20 ( struct V_6 * V_7 ,
struct V_23 const * V_24 , int * V_29 , int * V_30 , long V_25 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned long V_36 ;
int V_12 ;
switch ( V_25 ) {
case V_34 :
case V_28 :
V_12 = F_10 ( V_9 -> V_14 , F_15 ( V_24 , V_25 ) ,
V_29 ) ;
if ( V_12 )
return V_12 ;
* V_29 >>= V_24 -> V_32 . V_35 ;
return V_37 ;
case V_27 :
V_12 = F_10 ( V_9 -> V_14 , F_17 ( V_24 -> V_26 ) ,
V_29 ) ;
if ( V_12 )
return V_12 ;
* V_29 >>= V_24 -> V_32 . V_35 ;
V_29 -= ( 1 << V_24 -> V_32 . V_33 ) / 2 ;
return V_37 ;
case V_38 :
V_36 = ( ( 2 * V_9 -> V_39 ) >> V_24 -> V_32 . V_33 ) * 100 ;
* V_29 = V_36 / 100000 ;
* V_30 = ( V_36 % 100000 ) * 10 ;
return V_40 ;
default:
break;
}
return - V_22 ;
}
static int T_3 F_21 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_23 * V_41 ;
unsigned int V_21 ;
V_41 = F_22 ( V_9 -> V_42 -> V_43 ,
sizeof( struct V_23 ) , V_44 ) ;
if ( ! V_41 )
return - V_45 ;
for ( V_21 = 0 ; V_21 < V_9 -> V_42 -> V_43 ; ++ V_21 ) {
V_41 [ V_21 ] = V_9 -> V_42 -> V_46 ;
V_41 [ V_21 ] . V_47 = V_21 ;
V_41 [ V_21 ] . V_26 = V_21 ;
}
V_7 -> V_41 = V_41 ;
return 0 ;
}
static int T_3 F_23 ( struct V_1 * V_2 , struct V_14 * V_14 ,
enum V_48 type , const char * V_49 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned int V_50 = 0 ;
int V_12 ;
V_7 = F_24 ( sizeof( * V_9 ) ) ;
if ( V_7 == NULL ) {
F_25 ( V_2 , L_3 ) ;
V_12 = - V_45 ;
goto V_51;
}
V_9 = F_3 ( V_7 ) ;
F_26 ( V_2 , V_7 ) ;
V_9 -> V_42 = & V_52 [ type ] ;
V_9 -> V_14 = V_14 ;
V_7 -> V_2 . V_53 = V_2 ;
V_7 -> V_49 = V_49 ;
V_7 -> V_25 = & V_54 ;
V_7 -> V_55 = V_56 ;
V_7 -> V_43 = V_9 -> V_42 -> V_43 ;
V_12 = F_21 ( V_7 ) ;
if ( V_12 ) {
F_25 ( V_2 , L_4 , V_12 ) ;
goto V_57;
}
if ( V_9 -> V_42 -> V_58 == 2500000 )
V_50 |= V_59 ;
V_9 -> V_60 = F_27 ( V_2 , L_5 ) ;
if ( ! F_28 ( V_9 -> V_60 ) ) {
V_12 = F_29 ( V_9 -> V_60 ) ;
if ( V_12 ) {
F_25 ( V_2 , L_6 ,
V_12 ) ;
goto V_61;
}
V_9 -> V_39 = F_30 ( V_9 -> V_60 ) ;
} else {
V_9 -> V_39 = V_9 -> V_42 -> V_58 ;
V_50 |= V_62 ;
}
V_12 = F_7 ( V_9 -> V_14 , V_18 , V_50 ) ;
if ( V_12 ) {
F_25 ( V_2 , L_7 , V_12 ) ;
goto V_63;
}
V_12 = F_31 ( V_7 ) ;
if ( V_12 ) {
F_25 ( V_2 , L_8 , V_12 ) ;
goto V_63;
}
return 0 ;
V_63:
if ( ! F_28 ( V_9 -> V_60 ) )
F_32 ( V_9 -> V_60 ) ;
V_61:
if ( ! F_28 ( V_9 -> V_60 ) )
F_33 ( V_9 -> V_60 ) ;
F_34 ( V_7 -> V_41 ) ;
V_57:
F_35 ( V_7 ) ;
V_51:
F_36 ( V_14 ) ;
return V_12 ;
}
static int T_4 F_37 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_38 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_39 ( V_7 ) ;
F_34 ( V_7 -> V_41 ) ;
if ( ! F_28 ( V_9 -> V_60 ) ) {
F_32 ( V_9 -> V_60 ) ;
F_33 ( V_9 -> V_60 ) ;
}
F_36 ( V_9 -> V_14 ) ;
F_35 ( V_7 ) ;
return 0 ;
}
static bool F_40 ( struct V_1 * V_2 , unsigned int V_64 )
{
return false ;
}
static int T_3 F_41 ( struct V_65 * V_66 )
{
const struct V_67 * V_68 = F_42 ( V_66 ) ;
struct V_14 * V_14 ;
V_14 = F_43 ( V_66 , & V_69 ) ;
if ( F_28 ( V_14 ) )
return F_44 ( V_14 ) ;
return F_23 ( & V_66 -> V_2 , V_14 , V_68 -> V_70 , V_68 -> V_49 ) ;
}
static int T_4 F_45 ( struct V_65 * V_66 )
{
return F_37 ( & V_66 -> V_2 ) ;
}
static inline int F_46 ( void )
{
return F_47 ( & V_71 ) ;
}
static inline void F_48 ( void )
{
F_49 ( & V_71 ) ;
}
static inline int F_46 ( void )
{
return 0 ;
}
static inline void F_48 ( void )
{
}
static int T_3 F_50 ( struct V_72 * V_73 ,
const struct V_74 * V_68 )
{
struct V_14 * V_14 ;
V_14 = F_51 ( V_73 , & V_69 ) ;
if ( F_28 ( V_14 ) )
return F_44 ( V_14 ) ;
return F_23 ( & V_73 -> V_2 , V_14 , V_68 -> V_70 , V_68 -> V_49 ) ;
}
static int T_4 F_52 ( struct V_72 * V_73 )
{
return F_37 ( & V_73 -> V_2 ) ;
}
static inline int F_53 ( void )
{
return F_54 ( & V_75 ) ;
}
static inline void F_55 ( void )
{
F_56 ( & V_75 ) ;
}
static inline int F_53 ( void )
{
return 0 ;
}
static inline void F_55 ( void )
{
}
static int T_5 F_57 ( void )
{
int V_12 ;
V_12 = F_46 () ;
if ( V_12 )
return V_12 ;
V_12 = F_53 () ;
if ( V_12 ) {
F_48 () ;
return V_12 ;
}
return 0 ;
}
static void T_6 F_58 ( void )
{
F_55 () ;
F_48 () ;
}
