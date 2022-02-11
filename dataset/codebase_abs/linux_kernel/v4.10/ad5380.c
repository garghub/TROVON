static T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 , const struct V_4 * V_5 , char * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return sprintf ( V_6 , L_1 , V_8 -> V_9 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
T_2 V_3 , const struct V_4 * V_5 , const char * V_6 ,
T_3 V_10 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
bool V_9 ;
int V_11 ;
V_11 = F_4 ( V_6 , & V_9 ) ;
if ( V_11 )
return V_11 ;
F_5 ( & V_2 -> V_12 ) ;
if ( V_9 )
V_11 = F_6 ( V_8 -> V_13 , V_14 , 0 ) ;
else
V_11 = F_6 ( V_8 -> V_13 , V_15 , 0 ) ;
V_8 -> V_9 = V_9 ;
F_7 ( & V_2 -> V_12 ) ;
return V_11 ? V_11 : V_10 ;
}
static int F_8 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_16 ;
int V_11 ;
V_11 = F_9 ( V_8 -> V_13 , V_17 , & V_16 ) ;
if ( V_11 )
return V_11 ;
V_16 = ( V_16 >> V_18 ) & 1 ;
return V_16 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_4 * V_5 , unsigned int V_16 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
V_11 = F_11 ( V_8 -> V_13 , V_17 ,
1 << V_18 ,
V_16 << V_18 ) ;
return V_11 ;
}
static unsigned int F_12 ( struct V_4 const * V_5 ,
long V_19 )
{
switch ( V_19 ) {
case 0 :
return F_13 ( V_5 -> V_20 ) ;
case V_21 :
return F_14 ( V_5 -> V_20 ) ;
case V_22 :
return F_15 ( V_5 -> V_20 ) ;
default:
break;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_4 const * V_5 , int V_23 , int V_24 , long V_19 )
{
const unsigned int V_25 = ( 1 << V_5 -> V_26 . V_27 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
switch ( V_19 ) {
case V_28 :
case V_22 :
if ( V_23 >= V_25 || V_23 < 0 )
return - V_29 ;
return F_6 ( V_8 -> V_13 ,
F_12 ( V_5 , V_19 ) ,
V_23 << V_5 -> V_26 . V_30 ) ;
case V_21 :
V_23 += ( 1 << V_5 -> V_26 . V_27 ) / 2 ;
if ( V_23 >= V_25 || V_23 < 0 )
return - V_29 ;
return F_6 ( V_8 -> V_13 ,
F_14 ( V_5 -> V_20 ) ,
V_23 << V_5 -> V_26 . V_30 ) ;
default:
break;
}
return - V_29 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_4 const * V_5 , int * V_23 , int * V_24 , long V_19 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_11 ;
switch ( V_19 ) {
case V_28 :
case V_22 :
V_11 = F_9 ( V_8 -> V_13 , F_12 ( V_5 , V_19 ) ,
V_23 ) ;
if ( V_11 )
return V_11 ;
* V_23 >>= V_5 -> V_26 . V_30 ;
return V_31 ;
case V_21 :
V_11 = F_9 ( V_8 -> V_13 , F_14 ( V_5 -> V_20 ) ,
V_23 ) ;
if ( V_11 )
return V_11 ;
* V_23 >>= V_5 -> V_26 . V_30 ;
V_23 -= ( 1 << V_5 -> V_26 . V_27 ) / 2 ;
return V_31 ;
case V_32 :
* V_23 = 2 * V_8 -> V_33 ;
* V_24 = V_5 -> V_26 . V_27 ;
return V_34 ;
default:
break;
}
return - V_29 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_35 ;
unsigned int V_36 ;
V_35 = F_19 ( V_8 -> V_37 -> V_38 ,
sizeof( struct V_4 ) , V_39 ) ;
if ( ! V_35 )
return - V_40 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_37 -> V_38 ; ++ V_36 ) {
V_35 [ V_36 ] = V_8 -> V_37 -> V_41 ;
V_35 [ V_36 ] . V_42 = V_36 ;
V_35 [ V_36 ] . V_20 = V_36 ;
}
V_2 -> V_35 = V_35 ;
return 0 ;
}
static int F_20 ( struct V_43 * V_44 , struct V_13 * V_13 ,
enum V_45 type , const char * V_46 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
unsigned int V_47 = 0 ;
int V_11 ;
V_2 = F_21 ( V_44 , sizeof( * V_8 ) ) ;
if ( V_2 == NULL ) {
F_22 ( V_44 , L_2 ) ;
return - V_40 ;
}
V_8 = F_2 ( V_2 ) ;
F_23 ( V_44 , V_2 ) ;
V_8 -> V_37 = & V_48 [ type ] ;
V_8 -> V_13 = V_13 ;
V_2 -> V_44 . V_49 = V_44 ;
V_2 -> V_46 = V_46 ;
V_2 -> V_19 = & V_50 ;
V_2 -> V_51 = V_52 ;
V_2 -> V_38 = V_8 -> V_37 -> V_38 ;
V_11 = F_18 ( V_2 ) ;
if ( V_11 ) {
F_22 ( V_44 , L_3 , V_11 ) ;
return V_11 ;
}
if ( V_8 -> V_37 -> V_53 == 2500 )
V_47 |= V_54 ;
V_8 -> V_55 = F_24 ( V_44 , L_4 ) ;
if ( ! F_25 ( V_8 -> V_55 ) ) {
V_11 = F_26 ( V_8 -> V_55 ) ;
if ( V_11 ) {
F_22 ( V_44 , L_5 ,
V_11 ) ;
goto V_56;
}
V_11 = F_27 ( V_8 -> V_55 ) ;
if ( V_11 < 0 )
goto V_57;
V_8 -> V_33 = V_11 / 1000 ;
} else {
V_8 -> V_33 = V_8 -> V_37 -> V_53 ;
V_47 |= V_58 ;
}
V_11 = F_6 ( V_8 -> V_13 , V_17 , V_47 ) ;
if ( V_11 ) {
F_22 ( V_44 , L_6 , V_11 ) ;
goto V_57;
}
V_11 = F_28 ( V_2 ) ;
if ( V_11 ) {
F_22 ( V_44 , L_7 , V_11 ) ;
goto V_57;
}
return 0 ;
V_57:
if ( ! F_25 ( V_8 -> V_55 ) )
F_29 ( V_8 -> V_55 ) ;
V_56:
F_30 ( V_2 -> V_35 ) ;
return V_11 ;
}
static int F_31 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_32 ( V_44 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_33 ( V_2 ) ;
F_30 ( V_2 -> V_35 ) ;
if ( ! F_25 ( V_8 -> V_55 ) ) {
F_29 ( V_8 -> V_55 ) ;
}
return 0 ;
}
static bool F_34 ( struct V_43 * V_44 , unsigned int V_59 )
{
return false ;
}
static int F_35 ( struct V_60 * V_61 )
{
const struct V_62 * V_63 = F_36 ( V_61 ) ;
struct V_13 * V_13 ;
V_13 = F_37 ( V_61 , & V_64 ) ;
if ( F_25 ( V_13 ) )
return F_38 ( V_13 ) ;
return F_20 ( & V_61 -> V_44 , V_13 , V_63 -> V_65 , V_63 -> V_46 ) ;
}
static int F_39 ( struct V_60 * V_61 )
{
return F_31 ( & V_61 -> V_44 ) ;
}
static inline int F_40 ( void )
{
return F_41 ( & V_66 ) ;
}
static inline void F_42 ( void )
{
F_43 ( & V_66 ) ;
}
static inline int F_40 ( void )
{
return 0 ;
}
static inline void F_42 ( void )
{
}
static int F_44 ( struct V_67 * V_68 ,
const struct V_69 * V_63 )
{
struct V_13 * V_13 ;
V_13 = F_45 ( V_68 , & V_64 ) ;
if ( F_25 ( V_13 ) )
return F_38 ( V_13 ) ;
return F_20 ( & V_68 -> V_44 , V_13 , V_63 -> V_65 , V_63 -> V_46 ) ;
}
static int F_46 ( struct V_67 * V_68 )
{
return F_31 ( & V_68 -> V_44 ) ;
}
static inline int F_47 ( void )
{
return F_48 ( & V_70 ) ;
}
static inline void F_49 ( void )
{
F_50 ( & V_70 ) ;
}
static inline int F_47 ( void )
{
return 0 ;
}
static inline void F_49 ( void )
{
}
static int T_4 F_51 ( void )
{
int V_11 ;
V_11 = F_40 () ;
if ( V_11 )
return V_11 ;
V_11 = F_47 () ;
if ( V_11 ) {
F_42 () ;
return V_11 ;
}
return 0 ;
}
static void T_5 F_52 ( void )
{
F_49 () ;
F_42 () ;
}
