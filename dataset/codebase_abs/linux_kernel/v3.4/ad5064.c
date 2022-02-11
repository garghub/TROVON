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
const struct V_16 * V_17 , char * V_18 )
{
return sprintf ( V_18 , L_1 , V_19 [ 1 ] ,
V_19 [ 2 ] , V_19 [ 3 ] ) ;
}
static T_1 F_8 ( struct V_14 * V_15 ,
const struct V_16 * V_17 , char * V_18 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
return sprintf ( V_18 , L_2 ,
V_19 [ V_2 -> V_12 [ V_17 -> V_9 ] ] ) ;
}
static T_1 F_10 ( struct V_14 * V_15 ,
const struct V_16 * V_17 , const char * V_18 , T_2 V_20 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
unsigned int V_21 , V_22 ;
int V_10 ;
V_21 = 0 ;
for ( V_22 = 1 ; V_22 < F_11 ( V_19 ) ; ++ V_22 ) {
if ( F_12 ( V_18 , V_19 [ V_22 ] ) ) {
V_21 = V_22 ;
break;
}
}
if ( V_21 == 0 )
return - V_23 ;
F_13 ( & V_15 -> V_24 ) ;
V_2 -> V_12 [ V_17 -> V_9 ] = V_21 ;
V_10 = F_6 ( V_2 , V_17 -> V_9 ) ;
F_14 ( & V_15 -> V_24 ) ;
return V_10 ? V_10 : V_20 ;
}
static T_1 F_15 ( struct V_14 * V_15 ,
const struct V_16 * V_17 , char * V_18 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
return sprintf ( V_18 , L_3 , V_2 -> V_11 [ V_17 -> V_9 ] ) ;
}
static T_1 F_16 ( struct V_14 * V_15 ,
const struct V_16 * V_17 , const char * V_18 , T_2 V_20 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
bool V_11 ;
int V_10 ;
V_10 = F_17 ( V_18 , & V_11 ) ;
if ( V_10 )
return V_10 ;
F_13 ( & V_15 -> V_24 ) ;
V_2 -> V_11 [ V_17 -> V_9 ] = V_11 ;
V_10 = F_6 ( V_2 , V_17 -> V_9 ) ;
F_14 ( & V_15 -> V_24 ) ;
return V_10 ? V_10 : V_20 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_16 const * V_17 )
{
unsigned int V_22 ;
if ( V_2 -> V_25 )
return V_2 -> V_26 -> V_27 ;
V_22 = V_2 -> V_26 -> V_28 ? 0 : V_17 -> V_9 ;
return F_19 ( V_2 -> V_29 [ V_22 ] . V_30 ) ;
}
static int F_20 ( struct V_14 * V_15 ,
struct V_16 const * V_17 ,
int * V_5 ,
int * V_31 ,
long V_32 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
int V_33 ;
switch ( V_32 ) {
case 0 :
* V_5 = V_2 -> V_34 [ V_17 -> V_9 ] ;
return V_35 ;
case V_36 :
V_33 = F_18 ( V_2 , V_17 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = ( V_33 * 100 ) >> V_17 -> V_37 . V_38 ;
* V_5 = V_33 / 100000 ;
* V_31 = ( V_33 % 100000 ) * 10 ;
return V_39 ;
default:
break;
}
return - V_23 ;
}
static int F_21 ( struct V_14 * V_15 ,
struct V_16 const * V_17 , int V_5 , int V_31 , long V_40 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
int V_10 ;
switch ( V_40 ) {
case 0 :
if ( V_5 > ( 1 << V_17 -> V_37 . V_38 ) || V_5 < 0 )
return - V_23 ;
F_13 ( & V_15 -> V_24 ) ;
V_10 = F_1 ( V_2 , V_41 ,
V_17 -> V_42 , V_5 , V_17 -> V_37 . V_6 ) ;
if ( V_10 == 0 )
V_2 -> V_34 [ V_17 -> V_9 ] = V_5 ;
F_14 ( & V_15 -> V_24 ) ;
break;
default:
V_10 = - V_23 ;
}
return V_10 ;
}
static inline unsigned int F_22 ( struct V_1 * V_2 )
{
return V_2 -> V_26 -> V_28 ? 1 : V_2 -> V_26 -> V_43 ;
}
static const char * const F_23 ( struct V_1 * V_2 ,
unsigned int V_44 )
{
return V_2 -> V_26 -> V_28 ? L_4 : V_45 [ V_44 ] ;
}
static int T_3 F_24 ( struct V_46 * V_8 )
{
enum V_47 type = F_25 ( V_8 ) -> V_48 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
unsigned int V_22 ;
int V_10 ;
V_15 = F_26 ( sizeof( * V_2 ) ) ;
if ( V_15 == NULL )
return - V_49 ;
V_2 = F_9 ( V_15 ) ;
F_27 ( V_8 , V_15 ) ;
V_2 -> V_26 = & V_50 [ type ] ;
V_2 -> V_8 = V_8 ;
for ( V_22 = 0 ; V_22 < F_22 ( V_2 ) ; ++ V_22 )
V_2 -> V_29 [ V_22 ] . V_51 = F_23 ( V_2 , V_22 ) ;
V_10 = F_28 ( & V_2 -> V_8 -> V_52 , F_22 ( V_2 ) ,
V_2 -> V_29 ) ;
if ( V_10 ) {
if ( ! V_2 -> V_26 -> V_27 )
goto V_53;
V_2 -> V_25 = true ;
V_10 = F_1 ( V_2 , V_54 , 0 ,
V_55 , 0 ) ;
if ( V_10 ) {
F_29 ( & V_8 -> V_52 , L_5 ,
V_10 ) ;
goto V_53;
}
} else {
V_10 = F_30 ( F_22 ( V_2 ) , V_2 -> V_29 ) ;
if ( V_10 )
goto V_56;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_26 -> V_43 ; ++ V_22 ) {
V_2 -> V_12 [ V_22 ] = V_57 ;
V_2 -> V_34 [ V_22 ] = 0x8000 ;
}
V_15 -> V_52 . V_58 = & V_8 -> V_52 ;
V_15 -> V_59 = F_25 ( V_8 ) -> V_59 ;
V_15 -> V_60 = & V_61 ;
V_15 -> V_62 = V_63 ;
V_15 -> V_64 = V_2 -> V_26 -> V_64 ;
V_15 -> V_43 = V_2 -> V_26 -> V_43 ;
V_10 = F_31 ( V_15 ) ;
if ( V_10 )
goto V_65;
return 0 ;
V_65:
if ( ! V_2 -> V_25 )
F_32 ( F_22 ( V_2 ) , V_2 -> V_29 ) ;
V_56:
if ( ! V_2 -> V_25 )
F_33 ( F_22 ( V_2 ) , V_2 -> V_29 ) ;
V_53:
F_34 ( V_15 ) ;
return V_10 ;
}
static int T_4 F_35 ( struct V_46 * V_8 )
{
struct V_14 * V_15 = F_36 ( V_8 ) ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
F_37 ( V_15 ) ;
if ( ! V_2 -> V_25 ) {
F_32 ( F_22 ( V_2 ) , V_2 -> V_29 ) ;
F_33 ( F_22 ( V_2 ) , V_2 -> V_29 ) ;
}
F_34 ( V_15 ) ;
return 0 ;
}
