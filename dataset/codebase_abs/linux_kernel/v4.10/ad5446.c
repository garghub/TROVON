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
switch ( V_24 ) {
case V_25 :
* V_14 = V_7 -> V_20 ;
return V_26 ;
case V_27 :
* V_14 = V_7 -> V_28 ;
* V_23 = V_4 -> V_18 . V_19 ;
return V_29 ;
}
return - V_30 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_14 ,
int V_23 ,
long V_31 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_16 = 0 ;
switch ( V_31 ) {
case V_25 :
if ( V_14 >= ( 1 << V_4 -> V_18 . V_19 ) || V_14 < 0 )
return - V_30 ;
V_14 <<= V_4 -> V_18 . V_13 ;
F_7 ( & V_2 -> V_17 ) ;
V_7 -> V_20 = V_14 ;
if ( ! V_7 -> V_11 )
V_16 = V_7 -> V_21 -> V_22 ( V_7 , V_14 ) ;
F_8 ( & V_2 -> V_17 ) ;
break;
default:
V_16 = - V_30 ;
}
return V_16 ;
}
static int F_11 ( struct V_32 * V_33 , const char * V_34 ,
const struct V_35 * V_21 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_36 * V_37 ;
int V_16 , V_38 = 0 ;
V_37 = F_12 ( V_33 , L_2 ) ;
if ( ! F_13 ( V_37 ) ) {
V_16 = F_14 ( V_37 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_15 ( V_37 ) ;
if ( V_16 < 0 )
goto V_39;
V_38 = V_16 ;
}
V_2 = F_16 ( V_33 , sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_16 = - V_40 ;
goto V_39;
}
V_7 = F_2 ( V_2 ) ;
V_7 -> V_21 = V_21 ;
F_17 ( V_33 , V_2 ) ;
V_7 -> V_37 = V_37 ;
V_7 -> V_33 = V_33 ;
V_2 -> V_33 . V_41 = V_33 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_42 = & V_43 ;
V_2 -> V_44 = V_45 ;
V_2 -> V_46 = & V_7 -> V_21 -> V_47 ;
V_2 -> V_48 = 1 ;
V_7 -> V_8 = V_49 ;
if ( V_7 -> V_21 -> V_50 )
V_7 -> V_28 = V_7 -> V_21 -> V_50 ;
else if ( V_38 )
V_7 -> V_28 = V_38 / 1000 ;
else
F_18 ( V_33 , L_3 ) ;
V_16 = F_19 ( V_2 ) ;
if ( V_16 )
goto V_39;
return 0 ;
V_39:
if ( ! F_13 ( V_37 ) )
F_20 ( V_37 ) ;
return V_16 ;
}
static int F_21 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_22 ( V_33 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_23 ( V_2 ) ;
if ( ! F_13 ( V_7 -> V_37 ) )
F_20 ( V_7 -> V_37 ) ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 , unsigned V_14 )
{
struct V_51 * V_52 = F_25 ( V_7 -> V_33 ) ;
T_4 V_53 = F_26 ( V_14 ) ;
return F_27 ( V_52 , & V_53 , sizeof( V_53 ) ) ;
}
static int F_28 ( struct V_6 * V_7 , unsigned V_14 )
{
struct V_51 * V_52 = F_25 ( V_7 -> V_33 ) ;
T_5 V_53 [ 3 ] ;
V_53 [ 0 ] = ( V_14 >> 16 ) & 0xFF ;
V_53 [ 1 ] = ( V_14 >> 8 ) & 0xFF ;
V_53 [ 2 ] = V_14 & 0xFF ;
return F_27 ( V_52 , V_53 , sizeof( V_53 ) ) ;
}
static int F_29 ( struct V_51 * V_52 )
{
const struct V_54 * V_55 = F_30 ( V_52 ) ;
return F_11 ( & V_52 -> V_33 , V_55 -> V_34 ,
& V_56 [ V_55 -> V_57 ] ) ;
}
static int F_31 ( struct V_51 * V_52 )
{
return F_21 ( & V_52 -> V_33 ) ;
}
static int T_6 F_32 ( void )
{
return F_33 ( & V_58 ) ;
}
static void F_34 ( void )
{
F_35 ( & V_58 ) ;
}
static inline int F_32 ( void ) { return 0 ; }
static inline void F_34 ( void ) { }
static int F_36 ( struct V_6 * V_7 , unsigned V_14 )
{
struct V_59 * V_60 = F_37 ( V_7 -> V_33 ) ;
T_4 V_53 = F_26 ( V_14 ) ;
return F_38 ( V_60 , ( char * ) & V_53 , sizeof( V_53 ) ) ;
}
static int F_39 ( struct V_59 * V_61 ,
const struct V_62 * V_55 )
{
return F_11 ( & V_61 -> V_33 , V_55 -> V_34 ,
& V_63 [ V_55 -> V_57 ] ) ;
}
static int F_40 ( struct V_59 * V_61 )
{
return F_21 ( & V_61 -> V_33 ) ;
}
static int T_6 F_41 ( void )
{
return F_42 ( & V_64 ) ;
}
static void T_7 F_43 ( void )
{
F_44 ( & V_64 ) ;
}
static inline int F_41 ( void ) { return 0 ; }
static inline void F_43 ( void ) { }
static int T_6 F_45 ( void )
{
int V_16 ;
V_16 = F_32 () ;
if ( V_16 )
return V_16 ;
V_16 = F_41 () ;
if ( V_16 ) {
F_34 () ;
return V_16 ;
}
return 0 ;
}
static void T_7 F_46 ( void )
{
F_43 () ;
F_34 () ;
}
