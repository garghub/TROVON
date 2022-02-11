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
return V_16 ;
V_16 = F_15 ( V_38 ) ;
if ( V_16 < 0 )
goto V_40;
V_39 = V_16 ;
}
V_2 = F_16 ( V_34 , sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_16 = - V_41 ;
goto V_40;
}
V_7 = F_2 ( V_2 ) ;
V_7 -> V_21 = V_21 ;
F_17 ( V_34 , V_2 ) ;
V_7 -> V_38 = V_38 ;
V_7 -> V_34 = V_34 ;
V_2 -> V_34 . V_42 = V_34 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_43 = & V_44 ;
V_2 -> V_45 = V_46 ;
V_2 -> V_47 = & V_7 -> V_21 -> V_48 ;
V_2 -> V_49 = 1 ;
V_7 -> V_8 = V_50 ;
if ( V_7 -> V_21 -> V_51 )
V_7 -> V_29 = V_7 -> V_21 -> V_51 ;
else if ( V_39 )
V_7 -> V_29 = V_39 / 1000 ;
else
F_18 ( V_34 , L_3 ) ;
V_16 = F_19 ( V_2 ) ;
if ( V_16 )
goto V_40;
return 0 ;
V_40:
if ( ! F_13 ( V_38 ) )
F_20 ( V_38 ) ;
return V_16 ;
}
static int F_21 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_22 ( V_34 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_23 ( V_2 ) ;
if ( ! F_13 ( V_7 -> V_38 ) )
F_20 ( V_7 -> V_38 ) ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 , unsigned V_14 )
{
struct V_52 * V_53 = F_25 ( V_7 -> V_34 ) ;
T_4 V_54 = F_26 ( V_14 ) ;
return F_27 ( V_53 , & V_54 , sizeof( V_54 ) ) ;
}
static int F_28 ( struct V_6 * V_7 , unsigned V_14 )
{
struct V_52 * V_53 = F_25 ( V_7 -> V_34 ) ;
T_5 V_54 [ 3 ] ;
V_54 [ 0 ] = ( V_14 >> 16 ) & 0xFF ;
V_54 [ 1 ] = ( V_14 >> 8 ) & 0xFF ;
V_54 [ 2 ] = V_14 & 0xFF ;
return F_27 ( V_53 , V_54 , sizeof( V_54 ) ) ;
}
static int F_29 ( struct V_52 * V_53 )
{
const struct V_55 * V_56 = F_30 ( V_53 ) ;
return F_11 ( & V_53 -> V_34 , V_56 -> V_35 ,
& V_57 [ V_56 -> V_58 ] ) ;
}
static int F_31 ( struct V_52 * V_53 )
{
return F_21 ( & V_53 -> V_34 ) ;
}
static int T_6 F_32 ( void )
{
return F_33 ( & V_59 ) ;
}
static void F_34 ( void )
{
F_35 ( & V_59 ) ;
}
static inline int F_32 ( void ) { return 0 ; }
static inline void F_34 ( void ) { }
static int F_36 ( struct V_6 * V_7 , unsigned V_14 )
{
struct V_60 * V_61 = F_37 ( V_7 -> V_34 ) ;
T_4 V_54 = F_26 ( V_14 ) ;
return F_38 ( V_61 , ( char * ) & V_54 , sizeof( V_54 ) ) ;
}
static int F_39 ( struct V_60 * V_62 ,
const struct V_63 * V_56 )
{
return F_11 ( & V_62 -> V_34 , V_56 -> V_35 ,
& V_64 [ V_56 -> V_58 ] ) ;
}
static int F_40 ( struct V_60 * V_62 )
{
return F_21 ( & V_62 -> V_34 ) ;
}
static int T_6 F_41 ( void )
{
return F_42 ( & V_65 ) ;
}
static void T_7 F_43 ( void )
{
F_44 ( & V_65 ) ;
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
