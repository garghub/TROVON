static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_6 , V_7 ,
V_8 , V_3 ) ;
F_4 ( & V_2 -> V_5 ) ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_9 = 150 ;
unsigned int V_10 ;
int V_4 ;
while ( V_9 -- > 0 ) {
V_4 = F_6 ( V_2 -> V_6 , V_11 , & V_10 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_10 & V_12 )
break;
F_7 ( 20 ) ;
}
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_13 , L_1 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
int V_15 , int * V_10 )
{
T_3 V_16 [ 3 ] ;
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_5 ( V_2 ) ;
if ( V_4 < 0 ) {
F_4 ( & V_2 -> V_5 ) ;
return V_4 ;
}
V_4 = F_10 ( V_2 -> V_6 , V_17 ,
V_16 , sizeof( V_16 ) ) ;
F_4 ( & V_2 -> V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_10 = F_11 ( F_12 ( V_16 [ V_15 ] ) , 15 ) ;
return V_18 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_19 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_6 , V_20 ,
V_21 , V_19 ) ;
F_4 ( & V_2 -> V_5 ) ;
return V_4 ;
}
static
T_4 F_14 ( struct V_22 * V_13 ,
struct V_23 * V_24 ,
char * V_25 )
{
struct V_1 * V_2 = F_15 ( F_16 ( V_13 ) ) ;
unsigned int V_10 ;
int V_4 ;
V_4 = F_6 ( V_2 -> V_6 , V_20 , & V_10 ) ;
if ( V_4 )
return V_4 ;
V_10 &= V_21 ;
return sprintf ( V_25 , L_2 , V_10 ) ;
}
static
T_4 F_17 ( struct V_22 * V_13 ,
struct V_23 * V_24 ,
const char * V_25 ,
T_5 V_26 )
{
struct V_1 * V_2 = F_15 ( F_16 ( V_13 ) ) ;
unsigned long V_19 = 0 ;
int V_4 ;
V_4 = F_18 ( V_25 , 10 , & V_19 ) ;
if ( V_4 )
return V_4 ;
if ( V_19 >= V_21 )
return - V_27 ;
V_4 = F_13 ( V_2 , V_19 ) ;
return ( V_4 < 0 ) ? V_4 : V_26 ;
}
static
T_4 F_19 ( struct V_22 * V_13 ,
struct V_23 * V_24 , char * V_25 )
{
struct V_1 * V_2 = F_15 ( F_16 ( V_13 ) ) ;
T_5 V_28 = 0 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_30 -> V_31 ; V_29 ++ )
V_28 += F_20 ( V_25 + V_28 , V_32 - V_28 ,
L_3 , V_2 -> V_30 -> V_33 [ V_29 ] [ 0 ] ,
V_2 -> V_30 -> V_33 [ V_29 ] [ 1 ] ) ;
V_25 [ V_28 - 1 ] = '\n' ;
return V_28 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_34 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_6 , V_20 ,
V_35 ,
V_34 << V_36 ) ;
F_4 ( & V_2 -> V_5 ) ;
return V_4 ;
}
static int F_22 ( struct V_1 * V_2 ,
int V_10 , int V_37 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_30 -> V_31 ; V_29 ++ )
if ( V_10 == V_2 -> V_30 -> V_33 [ V_29 ] [ 0 ] &&
V_37 == V_2 -> V_30 -> V_33 [ V_29 ] [ 1 ] )
return V_29 ;
return - V_27 ;
}
static int F_23 ( struct V_1 * V_2 , T_2 V_38 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_6 , V_39 ,
V_40 ,
V_38 << V_41 ) ;
F_4 ( & V_2 -> V_5 ) ;
return V_4 ;
}
static T_4 F_24 ( struct V_22 * V_13 ,
struct V_23 * V_24 ,
char * V_25 )
{
struct V_1 * V_2 = F_15 ( F_16 ( V_13 ) ) ;
T_5 V_28 = 0 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_30 -> V_42 ; V_29 ++ )
V_28 += F_20 ( V_25 + V_28 , V_32 - V_28 ,
L_4 , V_2 -> V_30 -> V_43 [ V_29 ] ) ;
V_25 [ V_28 - 1 ] = '\n' ;
return V_28 ;
}
static int F_25 ( struct V_1 * V_2 , int V_10 , int V_37 )
{
int V_29 ;
if ( V_10 )
return - V_27 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_30 -> V_42 ; V_29 ++ )
if ( V_37 == V_2 -> V_30 -> V_43 [ V_29 ] )
return V_29 ;
return - V_27 ;
}
static int F_26 ( struct V_44 * V_45 ,
struct V_46 const * V_47 ,
int * V_10 , int * V_37 , long V_48 )
{
struct V_1 * V_2 = F_15 ( V_45 ) ;
unsigned int V_49 ;
int V_4 ;
switch ( V_48 ) {
case V_50 :
return F_9 ( V_2 , V_47 -> V_51 , V_10 ) ;
case V_52 :
V_4 = F_6 ( V_2 -> V_6 , V_39 , & V_49 ) ;
if ( V_4 < 0 )
return V_4 ;
V_49 >>= V_41 ;
* V_10 = 0 ;
* V_37 = V_2 -> V_30 -> V_43 [ V_49 ] ;
return V_53 ;
case V_54 :
V_4 = F_6 ( V_2 -> V_6 , V_20 , & V_49 ) ;
if ( V_4 < 0 )
return V_4 ;
V_49 >>= V_36 ;
* V_10 = V_2 -> V_30 -> V_33 [ V_49 ] [ 0 ] ;
* V_37 = V_2 -> V_30 -> V_33 [ V_49 ] [ 1 ] ;
return V_55 ;
}
return - V_27 ;
}
static int F_27 ( struct V_44 * V_45 ,
struct V_46 const * V_47 ,
int V_10 , int V_37 , long V_48 )
{
struct V_1 * V_2 = F_15 ( V_45 ) ;
int V_34 , V_38 ;
switch ( V_48 ) {
case V_54 :
V_34 = F_22 ( V_2 , V_10 , V_37 ) ;
if ( V_34 < 0 )
return - V_27 ;
return F_21 ( V_2 , V_34 ) ;
case V_52 :
V_38 = F_25 ( V_2 , V_10 , V_37 ) ;
if ( V_38 < 0 )
return - V_27 ;
return F_23 ( V_2 , V_38 ) ;
default:
return - V_27 ;
}
}
static int F_28 ( struct V_44 * V_45 ,
struct V_46 const * V_47 ,
long V_48 )
{
switch ( V_48 ) {
case V_54 :
return V_55 ;
case V_52 :
return V_53 ;
default:
return - V_27 ;
}
}
static T_6 F_29 ( int V_56 , void * V_57 )
{
struct V_58 * V_59 = V_57 ;
struct V_44 * V_45 = V_59 -> V_45 ;
struct V_1 * V_2 = F_15 ( V_45 ) ;
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_5 ( V_2 ) ;
if ( V_4 < 0 ) {
F_4 ( & V_2 -> V_5 ) ;
goto V_60;
}
V_4 = F_10 ( V_2 -> V_6 , V_17 ,
V_2 -> V_61 , 3 * sizeof( T_3 ) ) ;
F_4 ( & V_2 -> V_5 ) ;
if ( V_4 < 0 )
goto V_60;
F_30 ( V_45 , V_2 -> V_61 ,
F_31 () ) ;
V_60:
F_32 ( V_45 -> V_62 ) ;
return V_63 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_4 ;
T_2 V_64 [ 3 ] ;
V_4 = F_10 ( V_2 -> V_6 , V_65 ,
V_64 , F_34 ( V_64 ) ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_64 [ 0 ] != 'H' || V_64 [ 1 ] != '4' || V_64 [ 2 ] != '3' ) {
F_8 ( V_2 -> V_13 , L_5 ) ;
return - V_66 ;
}
V_4 = F_13 ( V_2 , V_67 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_21 ( V_2 , V_68 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_23 ( V_2 , V_69 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_1 ( V_2 , V_70 ) ;
}
int F_35 ( struct V_22 * V_13 )
{
return F_1 ( F_15 ( F_36 ( V_13 ) ) ,
V_70 ) ;
}
int F_37 ( struct V_22 * V_13 )
{
return F_1 ( F_15 ( F_36 ( V_13 ) ) ,
V_71 ) ;
}
int F_38 ( struct V_22 * V_13 , struct V_6 * V_6 ,
enum V_72 V_64 , const char * V_73 )
{
struct V_1 * V_2 ;
struct V_44 * V_45 ;
int V_4 ;
V_45 = F_39 ( V_13 , sizeof( * V_2 ) ) ;
if ( ! V_45 )
return - V_74 ;
F_40 ( V_13 , V_45 ) ;
V_2 = F_15 ( V_45 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_30 = & V_75 [ V_64 ] ;
F_41 ( & V_2 -> V_5 ) ;
V_45 -> V_13 . V_76 = V_13 ;
V_45 -> V_73 = V_73 ;
V_45 -> V_77 = & V_78 ;
V_45 -> V_79 = V_80 ;
V_45 -> V_81 = V_2 -> V_30 -> V_81 ;
V_45 -> V_82 = 4 ;
V_45 -> V_83 = V_84 ;
V_4 = F_33 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_42 ( V_45 , NULL ,
F_29 , NULL ) ;
if ( V_4 < 0 )
goto V_85;
V_4 = F_43 ( V_45 ) ;
if ( V_4 < 0 )
goto V_86;
return 0 ;
V_86:
F_44 ( V_45 ) ;
V_85:
F_1 ( F_15 ( V_45 ) , V_71 ) ;
return V_4 ;
}
int F_45 ( struct V_22 * V_13 )
{
struct V_44 * V_45 = F_36 ( V_13 ) ;
F_46 ( V_45 ) ;
F_44 ( V_45 ) ;
F_1 ( F_15 ( V_45 ) , V_71 ) ;
return 0 ;
}
