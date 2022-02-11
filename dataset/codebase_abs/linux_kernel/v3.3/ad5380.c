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
case 0 :
case V_28 :
if ( V_29 >= V_31 || V_29 < 0 )
return - V_22 ;
return F_7 ( V_9 -> V_14 ,
F_15 ( V_24 , V_25 ) ,
V_29 << V_24 -> V_32 . V_34 ) ;
case V_27 :
V_29 += ( 1 << V_24 -> V_32 . V_33 ) / 2 ;
if ( V_29 >= V_31 || V_29 < 0 )
return - V_22 ;
return F_7 ( V_9 -> V_14 ,
F_17 ( V_24 -> V_26 ) ,
V_29 << V_24 -> V_32 . V_34 ) ;
default:
break;
}
return - V_22 ;
}
static int F_20 ( struct V_6 * V_7 ,
struct V_23 const * V_24 , int * V_29 , int * V_30 , long V_25 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned long V_35 ;
int V_12 ;
switch ( V_25 ) {
case 0 :
case V_28 :
V_12 = F_10 ( V_9 -> V_14 , F_15 ( V_24 , V_25 ) ,
V_29 ) ;
if ( V_12 )
return V_12 ;
* V_29 >>= V_24 -> V_32 . V_34 ;
return V_36 ;
case V_27 :
V_12 = F_10 ( V_9 -> V_14 , F_17 ( V_24 -> V_26 ) ,
V_29 ) ;
if ( V_12 )
return V_12 ;
* V_29 >>= V_24 -> V_32 . V_34 ;
V_29 -= ( 1 << V_24 -> V_32 . V_33 ) / 2 ;
return V_36 ;
case V_37 :
V_35 = ( ( 2 * V_9 -> V_38 ) >> V_24 -> V_32 . V_33 ) * 100 ;
* V_29 = V_35 / 100000 ;
* V_30 = ( V_35 % 100000 ) * 10 ;
return V_39 ;
default:
break;
}
return - V_22 ;
}
static int T_3 F_21 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_23 * V_40 ;
unsigned int V_21 ;
V_40 = F_22 ( sizeof( struct V_23 ) ,
V_9 -> V_41 -> V_42 , V_43 ) ;
if ( ! V_40 )
return - V_44 ;
for ( V_21 = 0 ; V_21 < V_9 -> V_41 -> V_42 ; ++ V_21 ) {
V_40 [ V_21 ] = V_9 -> V_41 -> V_45 ;
V_40 [ V_21 ] . V_46 = V_21 ;
V_40 [ V_21 ] . V_26 = V_21 ;
}
V_7 -> V_40 = V_40 ;
return 0 ;
}
static int T_3 F_23 ( struct V_1 * V_2 , struct V_14 * V_14 ,
enum V_47 type , const char * V_48 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
unsigned int V_49 = 0 ;
int V_12 ;
V_7 = F_24 ( sizeof( * V_9 ) ) ;
if ( V_7 == NULL ) {
F_25 ( V_2 , L_3 ) ;
V_12 = - V_44 ;
goto V_50;
}
V_9 = F_3 ( V_7 ) ;
F_26 ( V_2 , V_7 ) ;
V_9 -> V_41 = & V_51 [ type ] ;
V_9 -> V_14 = V_14 ;
V_7 -> V_2 . V_52 = V_2 ;
V_7 -> V_48 = V_48 ;
V_7 -> V_25 = & V_53 ;
V_7 -> V_54 = V_55 ;
V_7 -> V_42 = V_9 -> V_41 -> V_42 ;
V_12 = F_21 ( V_7 ) ;
if ( V_12 ) {
F_25 ( V_2 , L_4 , V_12 ) ;
goto V_56;
}
if ( V_9 -> V_41 -> V_57 == 2500000 )
V_49 |= V_58 ;
V_9 -> V_59 = F_27 ( V_2 , L_5 ) ;
if ( ! F_28 ( V_9 -> V_59 ) ) {
V_12 = F_29 ( V_9 -> V_59 ) ;
if ( V_12 ) {
F_25 ( V_2 , L_6 ,
V_12 ) ;
goto V_60;
}
V_9 -> V_38 = F_30 ( V_9 -> V_59 ) ;
} else {
V_9 -> V_38 = V_9 -> V_41 -> V_57 ;
V_49 |= V_61 ;
}
V_12 = F_7 ( V_9 -> V_14 , V_18 , V_49 ) ;
if ( V_12 ) {
F_25 ( V_2 , L_7 , V_12 ) ;
goto V_62;
}
V_12 = F_31 ( V_7 ) ;
if ( V_12 ) {
F_25 ( V_2 , L_8 , V_12 ) ;
goto V_62;
}
return 0 ;
V_62:
if ( ! F_28 ( V_9 -> V_59 ) )
F_32 ( V_9 -> V_59 ) ;
V_60:
if ( ! F_28 ( V_9 -> V_59 ) )
F_33 ( V_9 -> V_59 ) ;
F_34 ( V_7 -> V_40 ) ;
V_56:
F_35 ( V_7 ) ;
V_50:
F_36 ( V_14 ) ;
return V_12 ;
}
static int T_4 F_37 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_38 ( V_7 ) ;
F_34 ( V_7 -> V_40 ) ;
if ( ! F_28 ( V_9 -> V_59 ) ) {
F_32 ( V_9 -> V_59 ) ;
F_33 ( V_9 -> V_59 ) ;
}
F_36 ( V_9 -> V_14 ) ;
F_35 ( V_7 ) ;
return 0 ;
}
static bool F_39 ( struct V_1 * V_2 , unsigned int V_63 )
{
return false ;
}
static int T_3 F_40 ( struct V_64 * V_65 )
{
const struct V_66 * V_67 = F_41 ( V_65 ) ;
struct V_14 * V_14 ;
V_14 = F_42 ( V_65 , & V_68 ) ;
if ( F_28 ( V_14 ) )
return F_43 ( V_14 ) ;
return F_23 ( & V_65 -> V_2 , V_14 , V_67 -> V_69 , V_67 -> V_48 ) ;
}
static int T_4 F_44 ( struct V_64 * V_65 )
{
return F_37 ( & V_65 -> V_2 ) ;
}
static inline int F_45 ( void )
{
return F_46 ( & V_70 ) ;
}
static inline void F_47 ( void )
{
F_48 ( & V_70 ) ;
}
static inline int F_45 ( void )
{
return 0 ;
}
static inline void F_47 ( void )
{
}
static int T_3 F_49 ( struct V_71 * V_72 ,
const struct V_73 * V_67 )
{
struct V_14 * V_14 ;
V_14 = F_50 ( V_72 , & V_68 ) ;
if ( F_28 ( V_14 ) )
return F_43 ( V_14 ) ;
return F_23 ( & V_72 -> V_2 , V_14 , V_67 -> V_69 , V_67 -> V_48 ) ;
}
static int T_4 F_51 ( struct V_71 * V_72 )
{
return F_37 ( & V_72 -> V_2 ) ;
}
static inline int F_52 ( void )
{
return F_53 ( & V_74 ) ;
}
static inline void F_54 ( void )
{
F_55 ( & V_74 ) ;
}
static inline int F_52 ( void )
{
return 0 ;
}
static inline void F_54 ( void )
{
}
static int T_5 F_56 ( void )
{
int V_12 ;
V_12 = F_45 () ;
if ( V_12 )
return V_12 ;
V_12 = F_52 () ;
if ( V_12 ) {
F_47 () ;
return V_12 ;
}
return 0 ;
}
static void T_6 F_57 ( void )
{
F_54 () ;
F_47 () ;
}
