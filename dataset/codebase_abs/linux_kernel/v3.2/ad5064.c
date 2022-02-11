static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 , unsigned int V_6 )
{
V_5 <<= V_6 ;
V_2 -> V_7 = F_2 ( F_3 ( V_3 ) | F_4 ( V_4 ) | V_5 ) ;
return F_5 ( V_2 -> V_8 , & V_2 -> V_7 , sizeof( V_2 -> V_7 ) ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_9 )
{
unsigned int V_5 ;
int V_10 ;
V_5 = ( 0x1 << V_9 ) ;
if ( V_2 -> V_11 [ V_9 ] )
V_5 |= V_2 -> V_12 [ V_9 ] << 8 ;
V_10 = F_1 ( V_2 , V_13 , 0 , V_5 , 0 ) ;
return V_10 ;
}
static T_1 F_7 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_19 * V_20 = F_8 ( V_17 ) ;
struct V_21 * V_22 = F_9 ( V_15 ) ;
struct V_1 * V_2 = F_10 ( V_22 ) ;
return sprintf ( V_18 , L_1 ,
V_23 [ V_2 -> V_12 [ V_20 -> V_24 ] ] ) ;
}
static T_1 F_11 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_18 , T_2 V_25 )
{
struct V_19 * V_20 = F_8 ( V_17 ) ;
struct V_21 * V_22 = F_9 ( V_15 ) ;
struct V_1 * V_2 = F_10 ( V_22 ) ;
unsigned int V_26 , V_27 ;
int V_10 ;
V_26 = 0 ;
for ( V_27 = 1 ; V_27 < F_12 ( V_23 ) ; ++ V_27 ) {
if ( F_13 ( V_18 , V_23 [ V_27 ] ) ) {
V_26 = V_27 ;
break;
}
}
if ( V_26 == 0 )
return - V_28 ;
F_14 ( & V_22 -> V_29 ) ;
V_2 -> V_12 [ V_20 -> V_24 ] = V_26 ;
V_10 = F_6 ( V_2 , V_20 -> V_24 ) ;
F_15 ( & V_22 -> V_29 ) ;
return V_10 ? V_10 : V_25 ;
}
static T_1 F_16 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
struct V_21 * V_22 = F_9 ( V_15 ) ;
struct V_1 * V_2 = F_10 ( V_22 ) ;
struct V_19 * V_20 = F_8 ( V_17 ) ;
return sprintf ( V_18 , L_2 , V_2 -> V_11 [ V_20 -> V_24 ] ) ;
}
static T_1 F_17 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_18 , T_2 V_25 )
{
struct V_21 * V_22 = F_9 ( V_15 ) ;
struct V_1 * V_2 = F_10 ( V_22 ) ;
struct V_19 * V_20 = F_8 ( V_17 ) ;
bool V_11 ;
int V_10 ;
V_10 = F_18 ( V_18 , & V_11 ) ;
if ( V_10 )
return V_10 ;
F_14 ( & V_22 -> V_29 ) ;
V_2 -> V_11 [ V_20 -> V_24 ] = V_11 ;
V_10 = F_6 ( V_2 , V_20 -> V_24 ) ;
F_15 ( & V_22 -> V_29 ) ;
return V_10 ? V_10 : V_25 ;
}
static int F_19 ( struct V_21 * V_22 ,
struct V_30 const * V_31 ,
int * V_5 ,
int * V_32 ,
long V_33 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
unsigned long V_34 ;
unsigned int V_35 ;
switch ( V_33 ) {
case 0 :
* V_5 = V_2 -> V_36 [ V_31 -> V_9 ] ;
return V_37 ;
case ( 1 << V_38 ) :
V_35 = V_2 -> V_39 -> V_40 ? 0 : V_31 -> V_9 ;
V_34 = F_20 ( V_2 -> V_41 [ V_35 ] . V_42 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = ( V_34 * 100 ) >> V_31 -> V_43 . V_44 ;
* V_5 = V_34 / 100000 ;
* V_32 = ( V_34 % 100000 ) * 10 ;
return V_45 ;
default:
break;
}
return - V_28 ;
}
static int F_21 ( struct V_21 * V_22 ,
struct V_30 const * V_31 , int V_5 , int V_32 , long V_46 )
{
struct V_1 * V_2 = F_10 ( V_22 ) ;
int V_10 ;
switch ( V_46 ) {
case 0 :
if ( V_5 > ( 1 << V_31 -> V_43 . V_44 ) || V_5 < 0 )
return - V_28 ;
F_14 ( & V_22 -> V_29 ) ;
V_10 = F_1 ( V_2 , V_47 ,
V_31 -> V_24 , V_5 , V_31 -> V_43 . V_6 ) ;
if ( V_10 == 0 )
V_2 -> V_36 [ V_31 -> V_9 ] = V_5 ;
F_15 ( & V_22 -> V_29 ) ;
break;
default:
V_10 = - V_28 ;
}
return V_10 ;
}
static inline unsigned int F_22 ( struct V_1 * V_2 )
{
return V_2 -> V_39 -> V_40 ? 1 : V_48 ;
}
static const char * const F_23 ( struct V_1 * V_2 ,
unsigned int V_35 )
{
return V_2 -> V_39 -> V_40 ? L_3 : V_49 [ V_35 ] ;
}
static int T_3 F_24 ( struct V_50 * V_8 )
{
enum V_51 type = F_25 ( V_8 ) -> V_52 ;
struct V_21 * V_22 ;
struct V_1 * V_2 ;
unsigned int V_27 ;
int V_10 ;
V_22 = F_26 ( sizeof( * V_2 ) ) ;
if ( V_22 == NULL )
return - V_53 ;
V_2 = F_10 ( V_22 ) ;
F_27 ( V_8 , V_22 ) ;
V_2 -> V_39 = & V_54 [ type ] ;
V_2 -> V_8 = V_8 ;
for ( V_27 = 0 ; V_27 < F_22 ( V_2 ) ; ++ V_27 )
V_2 -> V_41 [ V_27 ] . V_55 = F_23 ( V_2 , V_27 ) ;
V_10 = F_28 ( & V_2 -> V_8 -> V_15 , F_22 ( V_2 ) ,
V_2 -> V_41 ) ;
if ( V_10 )
goto V_56;
V_10 = F_29 ( F_22 ( V_2 ) , V_2 -> V_41 ) ;
if ( V_10 )
goto V_57;
for ( V_27 = 0 ; V_27 < V_48 ; ++ V_27 ) {
V_2 -> V_12 [ V_27 ] = V_58 ;
V_2 -> V_36 [ V_27 ] = 0x8000 ;
}
V_22 -> V_15 . V_59 = & V_8 -> V_15 ;
V_22 -> V_60 = F_25 ( V_8 ) -> V_60 ;
V_22 -> V_61 = & V_62 ;
V_22 -> V_63 = V_64 ;
V_22 -> V_65 = V_2 -> V_39 -> V_9 ;
V_22 -> V_66 = V_48 ;
V_10 = F_30 ( V_22 ) ;
if ( V_10 )
goto V_67;
return 0 ;
V_67:
F_31 ( F_22 ( V_2 ) , V_2 -> V_41 ) ;
V_57:
F_32 ( F_22 ( V_2 ) , V_2 -> V_41 ) ;
V_56:
F_33 ( V_22 ) ;
return V_10 ;
}
static int T_4 F_34 ( struct V_50 * V_8 )
{
struct V_21 * V_22 = F_35 ( V_8 ) ;
struct V_1 * V_2 = F_10 ( V_22 ) ;
F_36 ( V_22 ) ;
F_31 ( F_22 ( V_2 ) , V_2 -> V_41 ) ;
F_32 ( F_22 ( V_2 ) , V_2 -> V_41 ) ;
F_33 ( V_22 ) ;
return 0 ;
}
static T_5 int F_37 ( void )
{
return F_38 ( & V_68 ) ;
}
static T_6 void F_39 ( void )
{
F_40 ( & V_68 ) ;
}
