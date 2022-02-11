static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , unsigned int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_8 = V_5 + 1 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_7 -> V_8 - 1 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
T_2 V_9 ,
const struct V_3 * V_4 ,
char * V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_10 , L_1 , V_7 -> V_11 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
T_2 V_9 ,
const struct V_3 * V_4 ,
const char * V_10 , T_3 V_12 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_13 ;
unsigned int V_14 ;
bool V_15 ;
int V_16 ;
V_16 = F_6 ( V_10 , & V_15 ) ;
if ( V_16 )
return V_16 ;
F_7 ( & V_2 -> V_17 ) ;
V_7 -> V_11 = V_15 ;
if ( V_7 -> V_11 ) {
V_13 = V_4 -> V_18 . V_19 + V_4 -> V_18 . V_13 ;
V_14 = V_7 -> V_8 << V_13 ;
} else {
V_14 = V_7 -> V_20 ;
}
V_16 = V_7 -> V_21 -> V_22 ( V_7 , V_14 ) ;
F_8 ( & V_2 -> V_17 ) ;
return V_16 ? V_16 : V_12 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_14 ,
int * V_23 ,
long V_24 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_25 ;
switch ( V_24 ) {
case V_26 :
* V_14 = V_7 -> V_20 ;
return V_27 ;
case V_28 :
V_25 = ( V_7 -> V_29 * 1000 ) >> V_4 -> V_18 . V_19 ;
* V_14 = V_25 / 1000 ;
* V_23 = ( V_25 % 1000 ) * 1000 ;
return V_30 ;
}
return - V_31 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_14 ,
int V_23 ,
long V_32 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_16 = 0 ;
switch ( V_32 ) {
case V_26 :
if ( V_14 >= ( 1 << V_4 -> V_18 . V_19 ) || V_14 < 0 )
return - V_31 ;
V_14 <<= V_4 -> V_18 . V_13 ;
F_7 ( & V_2 -> V_17 ) ;
V_7 -> V_20 = V_14 ;
if ( ! V_7 -> V_11 )
V_16 = V_7 -> V_21 -> V_22 ( V_7 , V_14 ) ;
F_8 ( & V_2 -> V_17 ) ;
break;
default:
V_16 = - V_31 ;
}
return V_16 ;
}
static int F_11 ( struct V_33 * V_34 , const char * V_35 ,
const struct V_36 * V_21 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_37 * V_38 ;
int V_16 , V_39 = 0 ;
V_38 = F_12 ( V_34 , L_2 ) ;
if ( ! F_13 ( V_38 ) ) {
V_16 = F_14 ( V_38 ) ;
if ( V_16 )
goto V_40;
V_16 = F_15 ( V_38 ) ;
if ( V_16 < 0 )
goto V_41;
V_39 = V_16 ;
}
V_2 = F_16 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_16 = - V_42 ;
goto V_41;
}
V_7 = F_2 ( V_2 ) ;
V_7 -> V_21 = V_21 ;
F_17 ( V_34 , V_2 ) ;
V_7 -> V_38 = V_38 ;
V_7 -> V_34 = V_34 ;
V_2 -> V_34 . V_43 = V_34 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_44 = & V_45 ;
V_2 -> V_46 = V_47 ;
V_2 -> V_48 = & V_7 -> V_21 -> V_49 ;
V_2 -> V_50 = 1 ;
V_7 -> V_8 = V_51 ;
if ( V_7 -> V_21 -> V_52 )
V_7 -> V_29 = V_7 -> V_21 -> V_52 ;
else if ( V_39 )
V_7 -> V_29 = V_39 / 1000 ;
else
F_18 ( V_34 , L_3 ) ;
V_16 = F_19 ( V_2 ) ;
if ( V_16 )
goto V_53;
return 0 ;
V_53:
F_20 ( V_2 ) ;
V_41:
if ( ! F_13 ( V_38 ) )
F_21 ( V_38 ) ;
V_40:
if ( ! F_13 ( V_38 ) )
F_22 ( V_38 ) ;
return V_16 ;
}
static int F_23 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_24 ( V_34 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_25 ( V_2 ) ;
if ( ! F_13 ( V_7 -> V_38 ) ) {
F_21 ( V_7 -> V_38 ) ;
F_22 ( V_7 -> V_38 ) ;
}
F_20 ( V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_6 * V_7 , unsigned V_14 )
{
struct V_54 * V_55 = F_27 ( V_7 -> V_34 ) ;
T_4 V_56 = F_28 ( V_14 ) ;
return F_29 ( V_55 , & V_56 , sizeof( V_56 ) ) ;
}
static int F_30 ( struct V_6 * V_7 , unsigned V_14 )
{
struct V_54 * V_55 = F_27 ( V_7 -> V_34 ) ;
T_5 V_56 [ 3 ] ;
V_56 [ 0 ] = ( V_14 >> 16 ) & 0xFF ;
V_56 [ 1 ] = ( V_14 >> 8 ) & 0xFF ;
V_56 [ 2 ] = V_14 & 0xFF ;
return F_29 ( V_55 , V_56 , sizeof( V_56 ) ) ;
}
static int F_31 ( struct V_54 * V_55 )
{
const struct V_57 * V_58 = F_32 ( V_55 ) ;
return F_11 ( & V_55 -> V_34 , V_58 -> V_35 ,
& V_59 [ V_58 -> V_60 ] ) ;
}
static int F_33 ( struct V_54 * V_55 )
{
return F_23 ( & V_55 -> V_34 ) ;
}
static int T_6 F_34 ( void )
{
return F_35 ( & V_61 ) ;
}
static void F_36 ( void )
{
F_37 ( & V_61 ) ;
}
static inline int F_34 ( void ) { return 0 ; }
static inline void F_36 ( void ) { }
static int F_38 ( struct V_6 * V_7 , unsigned V_14 )
{
struct V_62 * V_63 = F_39 ( V_7 -> V_34 ) ;
T_4 V_56 = F_28 ( V_14 ) ;
return F_40 ( V_63 , ( char * ) & V_56 , sizeof( V_56 ) ) ;
}
static int F_41 ( struct V_62 * V_64 ,
const struct V_65 * V_58 )
{
return F_11 ( & V_64 -> V_34 , V_58 -> V_35 ,
& V_66 [ V_58 -> V_60 ] ) ;
}
static int F_42 ( struct V_62 * V_64 )
{
return F_23 ( & V_64 -> V_34 ) ;
}
static int T_6 F_43 ( void )
{
return F_44 ( & V_67 ) ;
}
static void T_7 F_45 ( void )
{
F_46 ( & V_67 ) ;
}
static inline int F_43 ( void ) { return 0 ; }
static inline void F_45 ( void ) { }
static int T_6 F_47 ( void )
{
int V_16 ;
V_16 = F_34 () ;
if ( V_16 )
return V_16 ;
V_16 = F_43 () ;
if ( V_16 ) {
F_36 () ;
return V_16 ;
}
return 0 ;
}
static void T_7 F_48 ( void )
{
F_45 () ;
F_36 () ;
}
