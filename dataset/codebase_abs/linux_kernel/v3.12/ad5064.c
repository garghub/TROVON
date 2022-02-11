static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 , unsigned int V_6 )
{
V_5 <<= V_6 ;
return V_2 -> V_7 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_2 ( struct V_1 * V_2 ,
const struct V_8 * V_9 )
{
unsigned int V_5 ;
int V_10 ;
V_5 = ( 0x1 << V_9 -> V_11 ) ;
if ( V_2 -> V_12 [ V_9 -> V_13 ] )
V_5 |= V_2 -> V_14 [ V_9 -> V_13 ] << 8 ;
V_10 = F_1 ( V_2 , V_15 , 0 , V_5 , 0 ) ;
return V_10 ;
}
static int F_3 ( struct V_16 * V_17 ,
const struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_17 ) ;
return V_2 -> V_14 [ V_9 -> V_13 ] - 1 ;
}
static int F_5 ( struct V_16 * V_17 ,
const struct V_8 * V_9 , unsigned int V_18 )
{
struct V_1 * V_2 = F_4 ( V_17 ) ;
int V_10 ;
F_6 ( & V_17 -> V_19 ) ;
V_2 -> V_14 [ V_9 -> V_13 ] = V_18 + 1 ;
V_10 = F_2 ( V_2 , V_9 ) ;
F_7 ( & V_17 -> V_19 ) ;
return V_10 ;
}
static T_1 F_8 ( struct V_16 * V_17 ,
T_2 V_20 , const struct V_8 * V_9 , char * V_21 )
{
struct V_1 * V_2 = F_4 ( V_17 ) ;
return sprintf ( V_21 , L_1 , V_2 -> V_12 [ V_9 -> V_13 ] ) ;
}
static T_1 F_9 ( struct V_16 * V_17 ,
T_2 V_20 , const struct V_8 * V_9 , const char * V_21 ,
T_3 V_22 )
{
struct V_1 * V_2 = F_4 ( V_17 ) ;
bool V_12 ;
int V_10 ;
V_10 = F_10 ( V_21 , & V_12 ) ;
if ( V_10 )
return V_10 ;
F_6 ( & V_17 -> V_19 ) ;
V_2 -> V_12 [ V_9 -> V_13 ] = V_12 ;
V_10 = F_2 ( V_2 , V_9 ) ;
F_7 ( & V_17 -> V_19 ) ;
return V_10 ? V_10 : V_22 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_8 const * V_9 )
{
unsigned int V_23 ;
if ( V_2 -> V_24 )
return V_2 -> V_25 -> V_26 ;
V_23 = V_2 -> V_25 -> V_27 ? 0 : V_9 -> V_13 ;
return F_12 ( V_2 -> V_28 [ V_23 ] . V_29 ) ;
}
static int F_13 ( struct V_16 * V_17 ,
struct V_8 const * V_9 ,
int * V_5 ,
int * V_30 ,
long V_31 )
{
struct V_1 * V_2 = F_4 ( V_17 ) ;
int V_32 ;
switch ( V_31 ) {
case V_33 :
* V_5 = V_2 -> V_34 [ V_9 -> V_13 ] ;
return V_35 ;
case V_36 :
V_32 = F_11 ( V_2 , V_9 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = ( V_32 * 100 ) >> V_9 -> V_37 . V_38 ;
* V_5 = V_32 / 100000 ;
* V_30 = ( V_32 % 100000 ) * 10 ;
return V_39 ;
default:
break;
}
return - V_40 ;
}
static int F_14 ( struct V_16 * V_17 ,
struct V_8 const * V_9 , int V_5 , int V_30 , long V_41 )
{
struct V_1 * V_2 = F_4 ( V_17 ) ;
int V_10 ;
switch ( V_41 ) {
case V_33 :
if ( V_5 >= ( 1 << V_9 -> V_37 . V_38 ) || V_5 < 0 )
return - V_40 ;
F_6 ( & V_17 -> V_19 ) ;
V_10 = F_1 ( V_2 , V_42 ,
V_9 -> V_11 , V_5 , V_9 -> V_37 . V_6 ) ;
if ( V_10 == 0 )
V_2 -> V_34 [ V_9 -> V_13 ] = V_5 ;
F_7 ( & V_17 -> V_19 ) ;
break;
default:
V_10 = - V_40 ;
}
return V_10 ;
}
static inline unsigned int F_15 ( struct V_1 * V_2 )
{
return V_2 -> V_25 -> V_27 ? 1 : V_2 -> V_25 -> V_43 ;
}
static const char * const F_16 ( struct V_1 * V_2 ,
unsigned int V_44 )
{
return V_2 -> V_25 -> V_27 ? L_2 : V_45 [ V_44 ] ;
}
static int F_17 ( struct V_46 * V_47 , enum V_48 type ,
const char * V_49 , T_4 V_7 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 ;
unsigned int V_50 ;
unsigned int V_23 ;
int V_10 ;
V_17 = F_18 ( V_47 , sizeof( * V_2 ) ) ;
if ( V_17 == NULL )
return - V_51 ;
V_2 = F_4 ( V_17 ) ;
F_19 ( V_47 , V_17 ) ;
V_2 -> V_25 = & V_52 [ type ] ;
V_2 -> V_47 = V_47 ;
V_2 -> V_7 = V_7 ;
for ( V_23 = 0 ; V_23 < F_15 ( V_2 ) ; ++ V_23 )
V_2 -> V_28 [ V_23 ] . V_53 = F_16 ( V_2 , V_23 ) ;
V_10 = F_20 ( V_47 , F_15 ( V_2 ) ,
V_2 -> V_28 ) ;
if ( V_10 ) {
if ( ! V_2 -> V_25 -> V_26 )
return V_10 ;
V_2 -> V_24 = true ;
V_10 = F_1 ( V_2 , V_54 , 0 ,
V_55 , 0 ) ;
if ( V_10 ) {
F_21 ( V_47 , L_3 ,
V_10 ) ;
return V_10 ;
}
} else {
V_10 = F_22 ( F_15 ( V_2 ) , V_2 -> V_28 ) ;
if ( V_10 )
return V_10 ;
}
V_17 -> V_47 . V_56 = V_47 ;
V_17 -> V_49 = V_49 ;
V_17 -> V_57 = & V_58 ;
V_17 -> V_59 = V_60 ;
V_17 -> V_61 = V_2 -> V_25 -> V_61 ;
V_17 -> V_43 = V_2 -> V_25 -> V_43 ;
V_50 = ( 1 << V_17 -> V_61 [ 0 ] . V_37 . V_38 ) / 2 ;
for ( V_23 = 0 ; V_23 < V_2 -> V_25 -> V_43 ; ++ V_23 ) {
V_2 -> V_14 [ V_23 ] = V_62 ;
V_2 -> V_34 [ V_23 ] = V_50 ;
}
V_10 = F_23 ( V_17 ) ;
if ( V_10 )
goto V_63;
return 0 ;
V_63:
if ( ! V_2 -> V_24 )
F_24 ( F_15 ( V_2 ) , V_2 -> V_28 ) ;
return V_10 ;
}
static int F_25 ( struct V_46 * V_47 )
{
struct V_16 * V_17 = F_26 ( V_47 ) ;
struct V_1 * V_2 = F_4 ( V_17 ) ;
F_27 ( V_17 ) ;
if ( ! V_2 -> V_24 )
F_24 ( F_15 ( V_2 ) , V_2 -> V_28 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
struct V_64 * V_65 = F_29 ( V_2 -> V_47 ) ;
V_2 -> V_66 . V_65 = F_30 ( F_31 ( V_3 ) | F_32 ( V_4 ) | V_5 ) ;
return F_33 ( V_65 , & V_2 -> V_66 . V_65 , sizeof( V_2 -> V_66 . V_65 ) ) ;
}
static int F_34 ( struct V_64 * V_65 )
{
const struct V_67 * V_68 = F_35 ( V_65 ) ;
return F_17 ( & V_65 -> V_47 , V_68 -> V_69 , V_68 -> V_49 ,
F_28 ) ;
}
static int F_36 ( struct V_64 * V_65 )
{
return F_25 ( & V_65 -> V_47 ) ;
}
static int T_5 F_37 ( void )
{
return F_38 ( & V_70 ) ;
}
static void F_39 ( void )
{
F_40 ( & V_70 ) ;
}
static inline int F_37 ( void ) { return 0 ; }
static inline void F_39 ( void ) { }
static int F_41 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
struct V_71 * V_72 = F_42 ( V_2 -> V_47 ) ;
V_2 -> V_66 . V_72 [ 0 ] = ( V_3 << 4 ) | V_4 ;
F_43 ( V_5 , & V_2 -> V_66 . V_72 [ 1 ] ) ;
return F_44 ( V_72 , V_2 -> V_66 . V_72 , 3 ) ;
}
static int F_45 ( struct V_71 * V_72 ,
const struct V_73 * V_68 )
{
return F_17 ( & V_72 -> V_47 , V_68 -> V_69 , V_68 -> V_49 ,
F_41 ) ;
}
static int F_46 ( struct V_71 * V_72 )
{
return F_25 ( & V_72 -> V_47 ) ;
}
static int T_5 F_47 ( void )
{
return F_48 ( & V_74 ) ;
}
static void T_6 F_49 ( void )
{
F_50 ( & V_74 ) ;
}
static inline int F_47 ( void ) { return 0 ; }
static inline void F_49 ( void ) { }
static int T_5 F_51 ( void )
{
int V_10 ;
V_10 = F_37 () ;
if ( V_10 )
return V_10 ;
V_10 = F_47 () ;
if ( V_10 ) {
F_39 () ;
return V_10 ;
}
return 0 ;
}
static void T_6 F_52 ( void )
{
F_49 () ;
F_39 () ;
}
