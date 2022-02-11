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
int F_14 ( struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
unsigned int V_10 ;
int V_4 ;
V_4 = F_6 ( V_2 -> V_6 , V_20 , & V_10 ) ;
if ( V_4 )
return V_4 ;
return V_10 & V_21 ;
}
static
int F_16 ( struct V_22 * V_23 ,
const struct V_24 * V_25 ,
unsigned int V_19 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
return F_13 ( V_2 , V_19 ) ;
}
static
T_4 F_17 ( struct V_26 * V_13 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_1 * V_2 = F_15 ( F_18 ( V_13 ) ) ;
T_5 V_30 = 0 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_32 -> V_33 ; V_31 ++ )
V_30 += F_19 ( V_29 + V_30 , V_34 - V_30 ,
L_2 , V_2 -> V_32 -> V_35 [ V_31 ] [ 0 ] ,
V_2 -> V_32 -> V_35 [ V_31 ] [ 1 ] ) ;
V_29 [ V_30 - 1 ] = '\n' ;
return V_30 ;
}
static int F_20 ( struct V_1 * V_2 , T_2 V_36 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_6 , V_20 ,
V_37 ,
V_36 << V_38 ) ;
F_4 ( & V_2 -> V_5 ) ;
return V_4 ;
}
static int F_21 ( struct V_1 * V_2 ,
int V_10 , int V_39 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_32 -> V_33 ; V_31 ++ )
if ( V_10 == V_2 -> V_32 -> V_35 [ V_31 ] [ 0 ] &&
V_39 == V_2 -> V_32 -> V_35 [ V_31 ] [ 1 ] )
return V_31 ;
return - V_40 ;
}
static int F_22 ( struct V_1 * V_2 , T_2 V_41 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_6 , V_42 ,
V_43 ,
V_41 << V_44 ) ;
F_4 ( & V_2 -> V_5 ) ;
return V_4 ;
}
static T_4 F_23 ( struct V_26 * V_13 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_1 * V_2 = F_15 ( F_18 ( V_13 ) ) ;
T_5 V_30 = 0 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_32 -> V_45 ; V_31 ++ )
V_30 += F_19 ( V_29 + V_30 , V_34 - V_30 ,
L_3 , V_2 -> V_32 -> V_46 [ V_31 ] ) ;
V_29 [ V_30 - 1 ] = '\n' ;
return V_30 ;
}
static int F_24 ( struct V_1 * V_2 , int V_10 , int V_39 )
{
int V_31 ;
if ( V_10 )
return - V_40 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_32 -> V_45 ; V_31 ++ )
if ( V_39 == V_2 -> V_32 -> V_46 [ V_31 ] )
return V_31 ;
return - V_40 ;
}
static int F_25 ( struct V_22 * V_23 ,
struct V_24 const * V_25 ,
int * V_10 , int * V_39 , long V_47 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
unsigned int V_48 ;
int V_4 ;
switch ( V_47 ) {
case V_49 :
return F_9 ( V_2 , V_25 -> V_50 , V_10 ) ;
case V_51 :
V_4 = F_6 ( V_2 -> V_6 , V_42 , & V_48 ) ;
if ( V_4 < 0 )
return V_4 ;
V_48 >>= V_44 ;
* V_10 = 0 ;
* V_39 = V_2 -> V_32 -> V_46 [ V_48 ] ;
return V_52 ;
case V_53 :
V_4 = F_6 ( V_2 -> V_6 , V_20 , & V_48 ) ;
if ( V_4 < 0 )
return V_4 ;
V_48 >>= V_38 ;
* V_10 = V_2 -> V_32 -> V_35 [ V_48 ] [ 0 ] ;
* V_39 = V_2 -> V_32 -> V_35 [ V_48 ] [ 1 ] ;
return V_54 ;
}
return - V_40 ;
}
static int F_26 ( struct V_22 * V_23 ,
struct V_24 const * V_25 ,
int V_10 , int V_39 , long V_47 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
int V_36 , V_41 ;
switch ( V_47 ) {
case V_53 :
V_36 = F_21 ( V_2 , V_10 , V_39 ) ;
if ( V_36 < 0 )
return - V_40 ;
return F_20 ( V_2 , V_36 ) ;
case V_51 :
V_41 = F_24 ( V_2 , V_10 , V_39 ) ;
if ( V_41 < 0 )
return - V_40 ;
return F_22 ( V_2 , V_41 ) ;
default:
return - V_40 ;
}
}
static int F_27 ( struct V_22 * V_23 ,
struct V_24 const * V_25 ,
long V_47 )
{
switch ( V_47 ) {
case V_53 :
return V_54 ;
case V_51 :
return V_52 ;
default:
return - V_40 ;
}
}
static T_6 F_28 ( int V_55 , void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_22 * V_23 = V_58 -> V_23 ;
struct V_1 * V_2 = F_15 ( V_23 ) ;
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_5 ( V_2 ) ;
if ( V_4 < 0 ) {
F_4 ( & V_2 -> V_5 ) ;
goto V_59;
}
V_4 = F_10 ( V_2 -> V_6 , V_17 ,
V_2 -> V_60 , 3 * sizeof( T_3 ) ) ;
F_4 ( & V_2 -> V_5 ) ;
if ( V_4 < 0 )
goto V_59;
F_29 ( V_23 , V_2 -> V_60 ,
F_30 () ) ;
V_59:
F_31 ( V_23 -> V_61 ) ;
return V_62 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_4 ;
T_2 V_63 [ 3 ] ;
V_4 = F_10 ( V_2 -> V_6 , V_64 ,
V_63 , F_33 ( V_63 ) ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_63 [ 0 ] != 'H' || V_63 [ 1 ] != '4' || V_63 [ 2 ] != '3' ) {
F_8 ( V_2 -> V_13 , L_4 ) ;
return - V_65 ;
}
V_4 = F_13 ( V_2 , V_66 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_20 ( V_2 , V_67 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_22 ( V_2 , V_68 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_1 ( V_2 , V_69 ) ;
}
int F_34 ( struct V_26 * V_13 )
{
return F_1 ( F_15 ( F_35 ( V_13 ) ) ,
V_70 ) ;
}
int F_36 ( struct V_26 * V_13 )
{
return F_1 ( F_15 ( F_35 ( V_13 ) ) ,
V_69 ) ;
}
int F_37 ( struct V_26 * V_13 , struct V_6 * V_6 ,
enum V_71 V_63 , const char * V_72 )
{
struct V_1 * V_2 ;
struct V_22 * V_23 ;
int V_4 ;
V_23 = F_38 ( V_13 , sizeof( * V_2 ) ) ;
if ( ! V_23 )
return - V_73 ;
F_39 ( V_13 , V_23 ) ;
V_2 = F_15 ( V_23 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_32 = & V_74 [ V_63 ] ;
F_40 ( & V_2 -> V_5 ) ;
V_23 -> V_13 . V_75 = V_13 ;
V_23 -> V_72 = V_72 ;
V_23 -> V_76 = & V_77 ;
V_23 -> V_78 = V_79 ;
V_23 -> V_80 = V_2 -> V_32 -> V_80 ;
V_23 -> V_81 = 4 ;
V_23 -> V_82 = V_83 ;
V_4 = F_32 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_41 ( V_23 , NULL ,
F_28 , NULL ) ;
if ( V_4 < 0 )
goto V_84;
V_4 = F_42 ( V_23 ) ;
if ( V_4 < 0 )
goto V_85;
return 0 ;
V_85:
F_43 ( V_23 ) ;
V_84:
F_1 ( F_15 ( V_23 ) , V_70 ) ;
return V_4 ;
}
int F_44 ( struct V_26 * V_13 )
{
struct V_22 * V_23 = F_35 ( V_13 ) ;
F_45 ( V_23 ) ;
F_43 ( V_23 ) ;
F_1 ( F_15 ( V_23 ) , V_70 ) ;
return 0 ;
}
