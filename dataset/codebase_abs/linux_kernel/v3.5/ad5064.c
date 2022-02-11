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
T_2 V_16 , const struct V_17 * V_18 , char * V_19 )
{
return sprintf ( V_19 , L_1 , V_20 [ 1 ] ,
V_20 [ 2 ] , V_20 [ 3 ] ) ;
}
static T_1 F_8 ( struct V_14 * V_15 ,
T_2 V_16 , const struct V_17 * V_18 , char * V_19 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
return sprintf ( V_19 , L_2 ,
V_20 [ V_2 -> V_12 [ V_18 -> V_9 ] ] ) ;
}
static T_1 F_10 ( struct V_14 * V_15 ,
T_2 V_16 , const struct V_17 * V_18 , const char * V_19 ,
T_3 V_21 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
unsigned int V_22 , V_23 ;
int V_10 ;
V_22 = 0 ;
for ( V_23 = 1 ; V_23 < F_11 ( V_20 ) ; ++ V_23 ) {
if ( F_12 ( V_19 , V_20 [ V_23 ] ) ) {
V_22 = V_23 ;
break;
}
}
if ( V_22 == 0 )
return - V_24 ;
F_13 ( & V_15 -> V_25 ) ;
V_2 -> V_12 [ V_18 -> V_9 ] = V_22 ;
V_10 = F_6 ( V_2 , V_18 -> V_9 ) ;
F_14 ( & V_15 -> V_25 ) ;
return V_10 ? V_10 : V_21 ;
}
static T_1 F_15 ( struct V_14 * V_15 ,
T_2 V_16 , const struct V_17 * V_18 , char * V_19 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
return sprintf ( V_19 , L_3 , V_2 -> V_11 [ V_18 -> V_9 ] ) ;
}
static T_1 F_16 ( struct V_14 * V_15 ,
T_2 V_16 , const struct V_17 * V_18 , const char * V_19 ,
T_3 V_21 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
bool V_11 ;
int V_10 ;
V_10 = F_17 ( V_19 , & V_11 ) ;
if ( V_10 )
return V_10 ;
F_13 ( & V_15 -> V_25 ) ;
V_2 -> V_11 [ V_18 -> V_9 ] = V_11 ;
V_10 = F_6 ( V_2 , V_18 -> V_9 ) ;
F_14 ( & V_15 -> V_25 ) ;
return V_10 ? V_10 : V_21 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_17 const * V_18 )
{
unsigned int V_23 ;
if ( V_2 -> V_26 )
return V_2 -> V_27 -> V_28 ;
V_23 = V_2 -> V_27 -> V_29 ? 0 : V_18 -> V_9 ;
return F_19 ( V_2 -> V_30 [ V_23 ] . V_31 ) ;
}
static int F_20 ( struct V_14 * V_15 ,
struct V_17 const * V_18 ,
int * V_5 ,
int * V_32 ,
long V_33 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
int V_34 ;
switch ( V_33 ) {
case V_35 :
* V_5 = V_2 -> V_36 [ V_18 -> V_9 ] ;
return V_37 ;
case V_38 :
V_34 = F_18 ( V_2 , V_18 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = ( V_34 * 100 ) >> V_18 -> V_39 . V_40 ;
* V_5 = V_34 / 100000 ;
* V_32 = ( V_34 % 100000 ) * 10 ;
return V_41 ;
default:
break;
}
return - V_24 ;
}
static int F_21 ( struct V_14 * V_15 ,
struct V_17 const * V_18 , int V_5 , int V_32 , long V_42 )
{
struct V_1 * V_2 = F_9 ( V_15 ) ;
int V_10 ;
switch ( V_42 ) {
case V_35 :
if ( V_5 > ( 1 << V_18 -> V_39 . V_40 ) || V_5 < 0 )
return - V_24 ;
F_13 ( & V_15 -> V_25 ) ;
V_10 = F_1 ( V_2 , V_43 ,
V_18 -> V_44 , V_5 , V_18 -> V_39 . V_6 ) ;
if ( V_10 == 0 )
V_2 -> V_36 [ V_18 -> V_9 ] = V_5 ;
F_14 ( & V_15 -> V_25 ) ;
break;
default:
V_10 = - V_24 ;
}
return V_10 ;
}
static inline unsigned int F_22 ( struct V_1 * V_2 )
{
return V_2 -> V_27 -> V_29 ? 1 : V_2 -> V_27 -> V_45 ;
}
static const char * const F_23 ( struct V_1 * V_2 ,
unsigned int V_46 )
{
return V_2 -> V_27 -> V_29 ? L_4 : V_47 [ V_46 ] ;
}
static int T_4 F_24 ( struct V_48 * V_8 )
{
enum V_49 type = F_25 ( V_8 ) -> V_50 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
unsigned int V_23 ;
int V_10 ;
V_15 = F_26 ( sizeof( * V_2 ) ) ;
if ( V_15 == NULL )
return - V_51 ;
V_2 = F_9 ( V_15 ) ;
F_27 ( V_8 , V_15 ) ;
V_2 -> V_27 = & V_52 [ type ] ;
V_2 -> V_8 = V_8 ;
for ( V_23 = 0 ; V_23 < F_22 ( V_2 ) ; ++ V_23 )
V_2 -> V_30 [ V_23 ] . V_53 = F_23 ( V_2 , V_23 ) ;
V_10 = F_28 ( & V_2 -> V_8 -> V_54 , F_22 ( V_2 ) ,
V_2 -> V_30 ) ;
if ( V_10 ) {
if ( ! V_2 -> V_27 -> V_28 )
goto V_55;
V_2 -> V_26 = true ;
V_10 = F_1 ( V_2 , V_56 , 0 ,
V_57 , 0 ) ;
if ( V_10 ) {
F_29 ( & V_8 -> V_54 , L_5 ,
V_10 ) ;
goto V_55;
}
} else {
V_10 = F_30 ( F_22 ( V_2 ) , V_2 -> V_30 ) ;
if ( V_10 )
goto V_58;
}
for ( V_23 = 0 ; V_23 < V_2 -> V_27 -> V_45 ; ++ V_23 ) {
V_2 -> V_12 [ V_23 ] = V_59 ;
V_2 -> V_36 [ V_23 ] = 0x8000 ;
}
V_15 -> V_54 . V_60 = & V_8 -> V_54 ;
V_15 -> V_61 = F_25 ( V_8 ) -> V_61 ;
V_15 -> V_62 = & V_63 ;
V_15 -> V_64 = V_65 ;
V_15 -> V_66 = V_2 -> V_27 -> V_66 ;
V_15 -> V_45 = V_2 -> V_27 -> V_45 ;
V_10 = F_31 ( V_15 ) ;
if ( V_10 )
goto V_67;
return 0 ;
V_67:
if ( ! V_2 -> V_26 )
F_32 ( F_22 ( V_2 ) , V_2 -> V_30 ) ;
V_58:
if ( ! V_2 -> V_26 )
F_33 ( F_22 ( V_2 ) , V_2 -> V_30 ) ;
V_55:
F_34 ( V_15 ) ;
return V_10 ;
}
static int T_5 F_35 ( struct V_48 * V_8 )
{
struct V_14 * V_15 = F_36 ( V_8 ) ;
struct V_1 * V_2 = F_9 ( V_15 ) ;
F_37 ( V_15 ) ;
if ( ! V_2 -> V_26 ) {
F_32 ( F_22 ( V_2 ) , V_2 -> V_30 ) ;
F_33 ( F_22 ( V_2 ) , V_2 -> V_30 ) ;
}
F_34 ( V_15 ) ;
return 0 ;
}
