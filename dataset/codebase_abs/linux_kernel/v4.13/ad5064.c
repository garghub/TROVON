static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 , unsigned int V_6 )
{
V_5 <<= V_6 ;
return V_2 -> V_7 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_2 ( struct V_1 * V_2 ,
const struct V_8 * V_9 )
{
unsigned int V_5 , V_10 ;
unsigned int V_6 ;
int V_11 ;
if ( V_2 -> V_12 -> V_13 == V_14 ) {
V_5 = 0 ;
V_10 = V_9 -> V_10 ;
} else {
if ( V_2 -> V_12 -> V_13 == V_15 )
V_6 = 4 ;
else
V_6 = 8 ;
V_5 = ( 0x1 << V_9 -> V_10 ) ;
V_10 = 0 ;
if ( V_2 -> V_16 [ V_9 -> V_17 ] )
V_5 |= V_2 -> V_18 [ V_9 -> V_17 ] << V_6 ;
}
V_11 = F_1 ( V_2 , V_19 , V_10 , V_5 , 0 ) ;
return V_11 ;
}
static int F_3 ( struct V_20 * V_21 ,
const struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
return V_2 -> V_18 [ V_9 -> V_17 ] - 1 ;
}
static int F_5 ( struct V_20 * V_21 ,
const struct V_8 * V_9 , unsigned int V_22 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
int V_11 ;
F_6 ( & V_21 -> V_23 ) ;
V_2 -> V_18 [ V_9 -> V_17 ] = V_22 + 1 ;
V_11 = F_2 ( V_2 , V_9 ) ;
F_7 ( & V_21 -> V_23 ) ;
return V_11 ;
}
static T_1 F_8 ( struct V_20 * V_21 ,
T_2 V_24 , const struct V_8 * V_9 , char * V_25 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
return sprintf ( V_25 , L_1 , V_2 -> V_16 [ V_9 -> V_17 ] ) ;
}
static T_1 F_9 ( struct V_20 * V_21 ,
T_2 V_24 , const struct V_8 * V_9 , const char * V_25 ,
T_3 V_26 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
bool V_16 ;
int V_11 ;
V_11 = F_10 ( V_25 , & V_16 ) ;
if ( V_11 )
return V_11 ;
F_6 ( & V_21 -> V_23 ) ;
V_2 -> V_16 [ V_9 -> V_17 ] = V_16 ;
V_11 = F_2 ( V_2 , V_9 ) ;
F_7 ( & V_21 -> V_23 ) ;
return V_11 ? V_11 : V_26 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_8 const * V_9 )
{
unsigned int V_27 ;
if ( V_2 -> V_28 )
return V_2 -> V_12 -> V_29 ;
V_27 = V_2 -> V_12 -> V_30 ? 0 : V_9 -> V_17 ;
return F_12 ( V_2 -> V_31 [ V_27 ] . V_32 ) ;
}
static int F_13 ( struct V_20 * V_21 ,
struct V_8 const * V_9 ,
int * V_5 ,
int * V_33 ,
long V_34 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
int V_35 ;
switch ( V_34 ) {
case V_36 :
* V_5 = V_2 -> V_37 [ V_9 -> V_17 ] ;
return V_38 ;
case V_39 :
V_35 = F_11 ( V_2 , V_9 ) ;
if ( V_35 < 0 )
return V_35 ;
* V_5 = V_35 / 1000 ;
* V_33 = V_9 -> V_40 . V_41 ;
return V_42 ;
default:
break;
}
return - V_43 ;
}
static int F_14 ( struct V_20 * V_21 ,
struct V_8 const * V_9 , int V_5 , int V_33 , long V_44 )
{
struct V_1 * V_2 = F_4 ( V_21 ) ;
int V_11 ;
switch ( V_44 ) {
case V_36 :
if ( V_5 >= ( 1 << V_9 -> V_40 . V_41 ) || V_5 < 0 )
return - V_43 ;
F_6 ( & V_21 -> V_23 ) ;
V_11 = F_1 ( V_2 , V_45 ,
V_9 -> V_10 , V_5 , V_9 -> V_40 . V_6 ) ;
if ( V_11 == 0 )
V_2 -> V_37 [ V_9 -> V_17 ] = V_5 ;
F_7 ( & V_21 -> V_23 ) ;
break;
default:
V_11 = - V_43 ;
}
return V_11 ;
}
static inline unsigned int F_15 ( struct V_1 * V_2 )
{
return V_2 -> V_12 -> V_30 ? 1 : V_2 -> V_12 -> V_46 ;
}
static const char * const F_16 ( struct V_1 * V_2 ,
unsigned int V_47 )
{
return V_2 -> V_12 -> V_30 ? L_2 : V_48 [ V_47 ] ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_5 )
{
unsigned int V_3 ;
switch ( V_2 -> V_12 -> V_13 ) {
case V_15 :
V_3 = V_49 ;
break;
default:
V_3 = V_50 ;
break;
}
return F_1 ( V_2 , V_3 , 0 , V_5 , 0 ) ;
}
static int F_18 ( struct V_51 * V_52 , enum V_53 type ,
const char * V_54 , T_4 V_7 )
{
struct V_20 * V_21 ;
struct V_1 * V_2 ;
unsigned int V_55 ;
unsigned int V_27 ;
int V_11 ;
V_21 = F_19 ( V_52 , sizeof( * V_2 ) ) ;
if ( V_21 == NULL )
return - V_56 ;
V_2 = F_4 ( V_21 ) ;
F_20 ( V_52 , V_21 ) ;
V_2 -> V_12 = & V_57 [ type ] ;
V_2 -> V_52 = V_52 ;
V_2 -> V_7 = V_7 ;
for ( V_27 = 0 ; V_27 < F_15 ( V_2 ) ; ++ V_27 )
V_2 -> V_31 [ V_27 ] . V_58 = F_16 ( V_2 , V_27 ) ;
V_11 = F_21 ( V_52 , F_15 ( V_2 ) ,
V_2 -> V_31 ) ;
if ( V_11 ) {
if ( ! V_2 -> V_12 -> V_29 )
return V_11 ;
V_2 -> V_28 = true ;
V_11 = F_17 ( V_2 , V_59 ) ;
if ( V_11 ) {
F_22 ( V_52 , L_3 ,
V_11 ) ;
return V_11 ;
}
} else {
V_11 = F_23 ( F_15 ( V_2 ) , V_2 -> V_31 ) ;
if ( V_11 )
return V_11 ;
}
V_21 -> V_52 . V_60 = V_52 ;
V_21 -> V_54 = V_54 ;
V_21 -> V_61 = & V_62 ;
V_21 -> V_63 = V_64 ;
V_21 -> V_65 = V_2 -> V_12 -> V_65 ;
V_21 -> V_46 = V_2 -> V_12 -> V_46 ;
V_55 = ( 1 << V_21 -> V_65 [ 0 ] . V_40 . V_41 ) / 2 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_12 -> V_46 ; ++ V_27 ) {
V_2 -> V_18 [ V_27 ] = V_66 ;
V_2 -> V_37 [ V_27 ] = V_55 ;
}
V_11 = F_24 ( V_21 ) ;
if ( V_11 )
goto V_67;
return 0 ;
V_67:
if ( ! V_2 -> V_28 )
F_25 ( F_15 ( V_2 ) , V_2 -> V_31 ) ;
return V_11 ;
}
static int F_26 ( struct V_51 * V_52 )
{
struct V_20 * V_21 = F_27 ( V_52 ) ;
struct V_1 * V_2 = F_4 ( V_21 ) ;
F_28 ( V_21 ) ;
if ( ! V_2 -> V_28 )
F_25 ( F_15 ( V_2 ) , V_2 -> V_31 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
struct V_68 * V_69 = F_30 ( V_2 -> V_52 ) ;
V_2 -> V_70 . V_69 = F_31 ( F_32 ( V_3 ) | F_33 ( V_4 ) | V_5 ) ;
return F_34 ( V_69 , & V_2 -> V_70 . V_69 , sizeof( V_2 -> V_70 . V_69 ) ) ;
}
static int F_35 ( struct V_68 * V_69 )
{
const struct V_71 * V_72 = F_36 ( V_69 ) ;
return F_18 ( & V_69 -> V_52 , V_72 -> V_73 , V_72 -> V_54 ,
F_29 ) ;
}
static int F_37 ( struct V_68 * V_69 )
{
return F_26 ( & V_69 -> V_52 ) ;
}
static int T_5 F_38 ( void )
{
return F_39 ( & V_74 ) ;
}
static void F_40 ( void )
{
F_41 ( & V_74 ) ;
}
static inline int F_38 ( void ) { return 0 ; }
static inline void F_40 ( void ) { }
static int F_42 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
struct V_75 * V_76 = F_43 ( V_2 -> V_52 ) ;
unsigned int V_77 ;
int V_11 ;
switch ( V_2 -> V_12 -> V_13 ) {
case V_15 :
V_77 = 3 ;
break;
default:
V_77 = 4 ;
break;
}
V_2 -> V_70 . V_76 [ 0 ] = ( V_3 << V_77 ) | V_4 ;
F_44 ( V_5 , & V_2 -> V_70 . V_76 [ 1 ] ) ;
V_11 = F_45 ( V_76 , V_2 -> V_70 . V_76 , 3 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_46 ( struct V_75 * V_76 ,
const struct V_78 * V_72 )
{
return F_18 ( & V_76 -> V_52 , V_72 -> V_73 , V_72 -> V_54 ,
F_42 ) ;
}
static int F_47 ( struct V_75 * V_76 )
{
return F_26 ( & V_76 -> V_52 ) ;
}
static int T_5 F_48 ( void )
{
return F_49 ( & V_79 ) ;
}
static void T_6 F_50 ( void )
{
F_51 ( & V_79 ) ;
}
static inline int F_48 ( void ) { return 0 ; }
static inline void F_50 ( void ) { }
static int T_5 F_52 ( void )
{
int V_11 ;
V_11 = F_38 () ;
if ( V_11 )
return V_11 ;
V_11 = F_48 () ;
if ( V_11 ) {
F_40 () ;
return V_11 ;
}
return 0 ;
}
static void T_6 F_53 ( void )
{
F_50 () ;
F_40 () ;
}
