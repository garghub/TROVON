static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 , unsigned int V_6 )
{
V_5 <<= V_6 ;
return V_2 -> V_7 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static int F_2 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
unsigned int V_5 ;
int V_9 ;
V_5 = ( 0x1 << V_8 ) ;
if ( V_2 -> V_10 [ V_8 ] )
V_5 |= V_2 -> V_11 [ V_8 ] << 8 ;
V_9 = F_1 ( V_2 , V_12 , 0 , V_5 , 0 ) ;
return V_9 ;
}
static int F_3 ( struct V_13 * V_14 ,
const struct V_15 * V_16 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
return V_2 -> V_11 [ V_16 -> V_8 ] - 1 ;
}
static int F_5 ( struct V_13 * V_14 ,
const struct V_15 * V_16 , unsigned int V_17 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
int V_9 ;
F_6 ( & V_14 -> V_18 ) ;
V_2 -> V_11 [ V_16 -> V_8 ] = V_17 + 1 ;
V_9 = F_2 ( V_2 , V_16 -> V_8 ) ;
F_7 ( & V_14 -> V_18 ) ;
return V_9 ;
}
static T_1 F_8 ( struct V_13 * V_14 ,
T_2 V_19 , const struct V_15 * V_16 , char * V_20 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
return sprintf ( V_20 , L_1 , V_2 -> V_10 [ V_16 -> V_8 ] ) ;
}
static T_1 F_9 ( struct V_13 * V_14 ,
T_2 V_19 , const struct V_15 * V_16 , const char * V_20 ,
T_3 V_21 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
bool V_10 ;
int V_9 ;
V_9 = F_10 ( V_20 , & V_10 ) ;
if ( V_9 )
return V_9 ;
F_6 ( & V_14 -> V_18 ) ;
V_2 -> V_10 [ V_16 -> V_8 ] = V_10 ;
V_9 = F_2 ( V_2 , V_16 -> V_8 ) ;
F_7 ( & V_14 -> V_18 ) ;
return V_9 ? V_9 : V_21 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_15 const * V_16 )
{
unsigned int V_22 ;
if ( V_2 -> V_23 )
return V_2 -> V_24 -> V_25 ;
V_22 = V_2 -> V_24 -> V_26 ? 0 : V_16 -> V_8 ;
return F_12 ( V_2 -> V_27 [ V_22 ] . V_28 ) ;
}
static int F_13 ( struct V_13 * V_14 ,
struct V_15 const * V_16 ,
int * V_5 ,
int * V_29 ,
long V_30 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
int V_31 ;
switch ( V_30 ) {
case V_32 :
* V_5 = V_2 -> V_33 [ V_16 -> V_8 ] ;
return V_34 ;
case V_35 :
V_31 = F_11 ( V_2 , V_16 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = ( V_31 * 100 ) >> V_16 -> V_36 . V_37 ;
* V_5 = V_31 / 100000 ;
* V_29 = ( V_31 % 100000 ) * 10 ;
return V_38 ;
default:
break;
}
return - V_39 ;
}
static int F_14 ( struct V_13 * V_14 ,
struct V_15 const * V_16 , int V_5 , int V_29 , long V_40 )
{
struct V_1 * V_2 = F_4 ( V_14 ) ;
int V_9 ;
switch ( V_40 ) {
case V_32 :
if ( V_5 > ( 1 << V_16 -> V_36 . V_37 ) || V_5 < 0 )
return - V_39 ;
F_6 ( & V_14 -> V_18 ) ;
V_9 = F_1 ( V_2 , V_41 ,
V_16 -> V_42 , V_5 , V_16 -> V_36 . V_6 ) ;
if ( V_9 == 0 )
V_2 -> V_33 [ V_16 -> V_8 ] = V_5 ;
F_7 ( & V_14 -> V_18 ) ;
break;
default:
V_9 = - V_39 ;
}
return V_9 ;
}
static inline unsigned int F_15 ( struct V_1 * V_2 )
{
return V_2 -> V_24 -> V_26 ? 1 : V_2 -> V_24 -> V_43 ;
}
static const char * const F_16 ( struct V_1 * V_2 ,
unsigned int V_44 )
{
return V_2 -> V_24 -> V_26 ? L_2 : V_45 [ V_44 ] ;
}
static int F_17 ( struct V_46 * V_47 , enum V_48 type ,
const char * V_49 , T_4 V_7 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
unsigned int V_22 ;
int V_9 ;
V_14 = F_18 ( sizeof( * V_2 ) ) ;
if ( V_14 == NULL )
return - V_50 ;
V_2 = F_4 ( V_14 ) ;
F_19 ( V_47 , V_14 ) ;
V_2 -> V_24 = & V_51 [ type ] ;
V_2 -> V_47 = V_47 ;
V_2 -> V_7 = V_7 ;
for ( V_22 = 0 ; V_22 < F_15 ( V_2 ) ; ++ V_22 )
V_2 -> V_27 [ V_22 ] . V_52 = F_16 ( V_2 , V_22 ) ;
V_9 = F_20 ( V_47 , F_15 ( V_2 ) ,
V_2 -> V_27 ) ;
if ( V_9 ) {
if ( ! V_2 -> V_24 -> V_25 )
goto V_53;
V_2 -> V_23 = true ;
V_9 = F_1 ( V_2 , V_54 , 0 ,
V_55 , 0 ) ;
if ( V_9 ) {
F_21 ( V_47 , L_3 ,
V_9 ) ;
goto V_53;
}
} else {
V_9 = F_22 ( F_15 ( V_2 ) , V_2 -> V_27 ) ;
if ( V_9 )
goto V_56;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_24 -> V_43 ; ++ V_22 ) {
V_2 -> V_11 [ V_22 ] = V_57 ;
V_2 -> V_33 [ V_22 ] = 0x8000 ;
}
V_14 -> V_47 . V_58 = V_47 ;
V_14 -> V_49 = V_49 ;
V_14 -> V_59 = & V_60 ;
V_14 -> V_61 = V_62 ;
V_14 -> V_63 = V_2 -> V_24 -> V_63 ;
V_14 -> V_43 = V_2 -> V_24 -> V_43 ;
V_9 = F_23 ( V_14 ) ;
if ( V_9 )
goto V_64;
return 0 ;
V_64:
if ( ! V_2 -> V_23 )
F_24 ( F_15 ( V_2 ) , V_2 -> V_27 ) ;
V_56:
if ( ! V_2 -> V_23 )
F_25 ( F_15 ( V_2 ) , V_2 -> V_27 ) ;
V_53:
F_26 ( V_14 ) ;
return V_9 ;
}
static int F_27 ( struct V_46 * V_47 )
{
struct V_13 * V_14 = F_28 ( V_47 ) ;
struct V_1 * V_2 = F_4 ( V_14 ) ;
F_29 ( V_14 ) ;
if ( ! V_2 -> V_23 ) {
F_24 ( F_15 ( V_2 ) , V_2 -> V_27 ) ;
F_25 ( F_15 ( V_2 ) , V_2 -> V_27 ) ;
}
F_26 ( V_14 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
struct V_65 * V_66 = F_31 ( V_2 -> V_47 ) ;
V_2 -> V_67 . V_66 = F_32 ( F_33 ( V_3 ) | F_34 ( V_4 ) | V_5 ) ;
return F_35 ( V_66 , & V_2 -> V_67 . V_66 , sizeof( V_2 -> V_67 . V_66 ) ) ;
}
static int F_36 ( struct V_65 * V_66 )
{
const struct V_68 * V_69 = F_37 ( V_66 ) ;
return F_17 ( & V_66 -> V_47 , V_69 -> V_70 , V_69 -> V_49 ,
F_30 ) ;
}
static int F_38 ( struct V_65 * V_66 )
{
return F_27 ( & V_66 -> V_47 ) ;
}
static int T_5 F_39 ( void )
{
return F_40 ( & V_71 ) ;
}
static void F_41 ( void )
{
F_42 ( & V_71 ) ;
}
static inline int F_39 ( void ) { return 0 ; }
static inline void F_41 ( void ) { }
static int F_43 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
struct V_72 * V_73 = F_44 ( V_2 -> V_47 ) ;
V_2 -> V_67 . V_73 [ 0 ] = ( V_3 << 4 ) | V_4 ;
F_45 ( V_5 , & V_2 -> V_67 . V_73 [ 1 ] ) ;
return F_46 ( V_73 , V_2 -> V_67 . V_73 , 3 ) ;
}
static int F_47 ( struct V_72 * V_73 ,
const struct V_74 * V_69 )
{
return F_17 ( & V_73 -> V_47 , V_69 -> V_70 , V_69 -> V_49 ,
F_43 ) ;
}
static int F_48 ( struct V_72 * V_73 )
{
return F_27 ( & V_73 -> V_47 ) ;
}
static int T_5 F_49 ( void )
{
return F_50 ( & V_75 ) ;
}
static void T_6 F_51 ( void )
{
F_52 ( & V_75 ) ;
}
static inline int F_49 ( void ) { return 0 ; }
static inline void F_51 ( void ) { }
static int T_5 F_53 ( void )
{
int V_9 ;
V_9 = F_39 () ;
if ( V_9 )
return V_9 ;
V_9 = F_49 () ;
if ( V_9 ) {
F_41 () ;
return V_9 ;
}
return 0 ;
}
static void T_6 F_54 ( void )
{
F_51 () ;
F_41 () ;
}
