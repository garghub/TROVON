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
unsigned long V_31 ;
int V_11 ;
switch ( V_19 ) {
case V_28 :
case V_22 :
V_11 = F_9 ( V_8 -> V_13 , F_12 ( V_5 , V_19 ) ,
V_23 ) ;
if ( V_11 )
return V_11 ;
* V_23 >>= V_5 -> V_26 . V_30 ;
return V_32 ;
case V_21 :
V_11 = F_9 ( V_8 -> V_13 , F_14 ( V_5 -> V_20 ) ,
V_23 ) ;
if ( V_11 )
return V_11 ;
* V_23 >>= V_5 -> V_26 . V_30 ;
V_23 -= ( 1 << V_5 -> V_26 . V_27 ) / 2 ;
return V_32 ;
case V_33 :
V_31 = ( ( 2 * V_8 -> V_34 ) >> V_5 -> V_26 . V_27 ) * 100 ;
* V_23 = V_31 / 100000 ;
* V_24 = ( V_31 % 100000 ) * 10 ;
return V_35 ;
default:
break;
}
return - V_29 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_4 * V_36 ;
unsigned int V_37 ;
V_36 = F_19 ( V_8 -> V_38 -> V_39 ,
sizeof( struct V_4 ) , V_40 ) ;
if ( ! V_36 )
return - V_41 ;
for ( V_37 = 0 ; V_37 < V_8 -> V_38 -> V_39 ; ++ V_37 ) {
V_36 [ V_37 ] = V_8 -> V_38 -> V_42 ;
V_36 [ V_37 ] . V_43 = V_37 ;
V_36 [ V_37 ] . V_20 = V_37 ;
}
V_2 -> V_36 = V_36 ;
return 0 ;
}
static int F_20 ( struct V_44 * V_45 , struct V_13 * V_13 ,
enum V_46 type , const char * V_47 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
unsigned int V_48 = 0 ;
int V_11 ;
V_2 = F_21 ( V_45 , sizeof( * V_8 ) ) ;
if ( V_2 == NULL ) {
F_22 ( V_45 , L_2 ) ;
return - V_41 ;
}
V_8 = F_2 ( V_2 ) ;
F_23 ( V_45 , V_2 ) ;
V_8 -> V_38 = & V_49 [ type ] ;
V_8 -> V_13 = V_13 ;
V_2 -> V_45 . V_50 = V_45 ;
V_2 -> V_47 = V_47 ;
V_2 -> V_19 = & V_51 ;
V_2 -> V_52 = V_53 ;
V_2 -> V_39 = V_8 -> V_38 -> V_39 ;
V_11 = F_18 ( V_2 ) ;
if ( V_11 ) {
F_22 ( V_45 , L_3 , V_11 ) ;
return V_11 ;
}
if ( V_8 -> V_38 -> V_54 == 2500000 )
V_48 |= V_55 ;
V_8 -> V_56 = F_24 ( V_45 , L_4 ) ;
if ( ! F_25 ( V_8 -> V_56 ) ) {
V_11 = F_26 ( V_8 -> V_56 ) ;
if ( V_11 ) {
F_22 ( V_45 , L_5 ,
V_11 ) ;
goto V_57;
}
V_11 = F_27 ( V_8 -> V_56 ) ;
if ( V_11 < 0 )
goto V_58;
V_8 -> V_34 = V_11 ;
} else {
V_8 -> V_34 = V_8 -> V_38 -> V_54 ;
V_48 |= V_59 ;
}
V_11 = F_6 ( V_8 -> V_13 , V_17 , V_48 ) ;
if ( V_11 ) {
F_22 ( V_45 , L_6 , V_11 ) ;
goto V_58;
}
V_11 = F_28 ( V_2 ) ;
if ( V_11 ) {
F_22 ( V_45 , L_7 , V_11 ) ;
goto V_58;
}
return 0 ;
V_58:
if ( ! F_25 ( V_8 -> V_56 ) )
F_29 ( V_8 -> V_56 ) ;
V_57:
F_30 ( V_2 -> V_36 ) ;
return V_11 ;
}
static int F_31 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_32 ( V_45 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_33 ( V_2 ) ;
F_30 ( V_2 -> V_36 ) ;
if ( ! F_25 ( V_8 -> V_56 ) ) {
F_29 ( V_8 -> V_56 ) ;
}
return 0 ;
}
static bool F_34 ( struct V_44 * V_45 , unsigned int V_60 )
{
return false ;
}
static int F_35 ( struct V_61 * V_62 )
{
const struct V_63 * V_64 = F_36 ( V_62 ) ;
struct V_13 * V_13 ;
V_13 = F_37 ( V_62 , & V_65 ) ;
if ( F_25 ( V_13 ) )
return F_38 ( V_13 ) ;
return F_20 ( & V_62 -> V_45 , V_13 , V_64 -> V_66 , V_64 -> V_47 ) ;
}
static int F_39 ( struct V_61 * V_62 )
{
return F_31 ( & V_62 -> V_45 ) ;
}
static inline int F_40 ( void )
{
return F_41 ( & V_67 ) ;
}
static inline void F_42 ( void )
{
F_43 ( & V_67 ) ;
}
static inline int F_40 ( void )
{
return 0 ;
}
static inline void F_42 ( void )
{
}
static int F_44 ( struct V_68 * V_69 ,
const struct V_70 * V_64 )
{
struct V_13 * V_13 ;
V_13 = F_45 ( V_69 , & V_65 ) ;
if ( F_25 ( V_13 ) )
return F_38 ( V_13 ) ;
return F_20 ( & V_69 -> V_45 , V_13 , V_64 -> V_66 , V_64 -> V_47 ) ;
}
static int F_46 ( struct V_68 * V_69 )
{
return F_31 ( & V_69 -> V_45 ) ;
}
static inline int F_47 ( void )
{
return F_48 ( & V_71 ) ;
}
static inline void F_49 ( void )
{
F_50 ( & V_71 ) ;
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
