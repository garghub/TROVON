static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_6 , V_7 ,
V_3 & V_8 ) ;
if ( V_4 >= 0 )
V_2 -> V_3 = V_3 ;
F_4 ( & V_2 -> V_5 ) ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_9 ;
int V_10 = 150 ;
while ( V_10 -- > 0 ) {
V_9 = F_6 ( V_2 -> V_6 ,
V_11 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 & V_12 )
break;
F_7 ( 20 ) ;
}
if ( V_10 < 0 ) {
F_8 ( & V_2 -> V_6 -> V_13 , L_1 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
int V_15 , int * V_16 )
{
T_1 V_9 ;
T_3 V_17 [ 3 ] ;
F_2 ( & V_2 -> V_5 ) ;
V_9 = F_5 ( V_2 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_2 -> V_5 ) ;
return V_9 ;
}
V_9 = F_10 ( V_2 -> V_6 ,
V_18 , sizeof( V_17 ) , ( T_2 * ) V_17 ) ;
F_4 ( & V_2 -> V_5 ) ;
if ( V_9 < 0 )
return - V_19 ;
* V_16 = F_11 ( F_12 ( V_17 [ V_15 ] ) , 15 ) ;
return V_20 ;
}
static T_1 F_13 ( struct V_1 * V_2 , T_2 V_21 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_6 , V_22 ,
( V_21 & V_23 ) |
( V_2 -> V_24 << V_25 ) ) ;
if ( V_4 >= 0 )
V_2 -> V_21 = V_21 ;
F_4 ( & V_2 -> V_5 ) ;
return V_4 ;
}
static T_4 F_14 ( struct V_26 * V_13 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_1 * V_2 = F_15 ( F_16 ( V_13 ) ) ;
return sprintf ( V_29 , L_2 , V_2 -> V_21 ) ;
}
static T_4 F_17 ( struct V_26 * V_13 ,
struct V_27 * V_28 ,
const char * V_29 ,
T_5 V_30 )
{
struct V_1 * V_2 = F_15 ( F_16 ( V_13 ) ) ;
unsigned long V_21 = 0 ;
int V_4 ;
V_4 = F_18 ( V_29 , 10 , & V_21 ) ;
if ( V_4 )
return V_4 ;
if ( V_21 >= V_23 )
return - V_19 ;
V_4 = F_13 ( V_2 , V_21 ) ;
return ( V_4 < 0 ) ? V_4 : V_30 ;
}
static T_4 F_19 ( struct V_26 * V_13 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_1 * V_2 = F_15 ( F_16 ( V_13 ) ) ;
T_5 V_31 = 0 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
V_31 += F_20 ( V_29 + V_31 , V_34 - V_31 ,
L_3 , V_2 -> V_35 -> V_36 [ V_32 ] [ 0 ] ,
V_2 -> V_35 -> V_36 [ V_32 ] [ 1 ] ) ;
V_29 [ V_31 - 1 ] = '\n' ;
return V_31 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_24 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_6 , V_22 ,
V_2 -> V_21 | ( V_24 << V_25 ) ) ;
if ( V_4 >= 0 )
V_2 -> V_24 = V_24 ;
F_4 ( & V_2 -> V_5 ) ;
return V_4 ;
}
static int F_22 ( struct V_1 * V_2 ,
int V_16 , int V_37 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
if ( V_16 == V_2 -> V_35 -> V_36 [ V_32 ] [ 0 ] &&
V_37 == V_2 -> V_35 -> V_36 [ V_32 ] [ 1 ] )
return V_32 ;
return - V_19 ;
}
static int F_23 ( struct V_1 * V_2 , T_2 V_38 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_6 , V_39 ,
V_38 << V_40 ) ;
if ( V_4 >= 0 )
V_2 -> V_38 = V_38 ;
F_4 ( & V_2 -> V_5 ) ;
return V_4 ;
}
static T_4 F_24 ( struct V_26 * V_13 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_1 * V_2 = F_15 ( F_16 ( V_13 ) ) ;
T_5 V_31 = 0 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_41 ; V_32 ++ )
V_31 += F_20 ( V_29 + V_31 , V_34 - V_31 ,
L_4 , V_2 -> V_35 -> V_42 [ V_32 ] ) ;
V_29 [ V_31 - 1 ] = '\n' ;
return V_31 ;
}
static int F_25 ( struct V_1 * V_2 , int V_16 , int V_37 )
{
int V_32 ;
if ( V_16 != 0 )
return - V_19 ;
for ( V_32 = 0 ; V_32 < V_41 ; V_32 ++ )
if ( V_37 == V_2 -> V_35 -> V_42 [ V_32 ] )
return V_32 ;
return - V_19 ;
}
static int F_26 ( struct V_43 * V_44 ,
struct V_45 const * V_46 ,
int * V_16 , int * V_37 , long V_47 )
{
struct V_1 * V_2 = F_15 ( V_44 ) ;
switch ( V_47 ) {
case V_48 :
return F_9 ( V_2 , V_46 -> V_49 , V_16 ) ;
case V_50 :
* V_16 = 0 ;
* V_37 = V_2 -> V_35 -> V_42 [ V_2 -> V_38 ] ;
return V_51 ;
case V_52 :
* V_16 = V_2 -> V_35 -> V_36 [ V_2 -> V_24 ] [ 0 ] ;
* V_37 = V_2 -> V_35 -> V_36 [ V_2 -> V_24 ] [ 1 ] ;
return V_53 ;
}
return - V_19 ;
}
static int F_27 ( struct V_43 * V_44 ,
struct V_45 const * V_46 ,
int V_16 , int V_37 , long V_47 )
{
struct V_1 * V_2 = F_15 ( V_44 ) ;
int V_24 , V_38 ;
switch ( V_47 ) {
case V_52 :
V_24 = F_22 ( V_2 , V_16 , V_37 ) ;
if ( V_24 < 0 )
return - V_19 ;
return F_21 ( V_2 , V_24 ) ;
case V_50 :
V_38 = F_25 ( V_2 , V_16 , V_37 ) ;
if ( V_38 < 0 )
return - V_19 ;
return F_23 ( V_2 , V_38 ) ;
default:
return - V_19 ;
}
}
static int F_28 ( struct V_43 * V_44 ,
struct V_45 const * V_46 , long V_47 )
{
switch ( V_47 ) {
case V_52 :
return V_53 ;
case V_50 :
return V_51 ;
default:
return - V_19 ;
}
}
static T_6 F_29 ( int V_54 , void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_43 * V_44 = V_57 -> V_44 ;
struct V_1 * V_2 = F_15 ( V_44 ) ;
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_5 ( V_2 ) ;
if ( V_4 < 0 ) {
F_4 ( & V_2 -> V_5 ) ;
goto V_58;
}
V_4 = F_10 ( V_2 -> V_6 ,
V_18 , 3 * sizeof( T_3 ) ,
( T_2 * ) V_2 -> V_59 ) ;
F_4 ( & V_2 -> V_5 ) ;
if ( V_4 < 0 )
goto V_58;
F_30 ( V_44 , V_2 -> V_59 ,
F_31 () ) ;
V_58:
F_32 ( V_44 -> V_60 ) ;
return V_61 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_4 ;
T_2 V_62 [ 3 ] ;
V_4 = F_10 ( V_2 -> V_6 , V_63 ,
sizeof( V_62 ) , V_62 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_62 [ 0 ] != 'H' || V_62 [ 1 ] != '4' || V_62 [ 2 ] != '3' ) {
F_8 ( & V_2 -> V_6 -> V_13 , L_5 ) ;
return - V_64 ;
}
V_4 = F_13 ( V_2 , V_65 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_21 ( V_2 , V_66 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_23 ( V_2 , V_67 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_1 ( V_2 , V_68 ) ;
}
static int F_34 ( struct V_69 * V_6 ,
const struct V_70 * V_62 )
{
struct V_1 * V_2 ;
struct V_43 * V_44 ;
int V_4 ;
V_44 = F_35 ( & V_6 -> V_13 , sizeof( * V_2 ) ) ;
if ( V_44 == NULL )
return - V_71 ;
V_2 = F_15 ( V_44 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_35 = & V_72 [ V_62 -> V_73 ] ;
F_36 ( & V_2 -> V_5 ) ;
F_37 ( V_6 , V_44 ) ;
V_44 -> V_74 = & V_75 ;
V_44 -> V_76 = V_62 -> V_76 ;
V_44 -> V_13 . V_77 = & V_6 -> V_13 ;
V_44 -> V_78 = V_79 ;
V_44 -> V_80 = V_2 -> V_35 -> V_80 ;
V_44 -> V_81 = 4 ;
V_44 -> V_82 = V_83 ;
V_4 = F_33 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_38 ( V_44 , NULL ,
F_29 , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_39 ( V_44 ) ;
if ( V_4 < 0 )
goto V_84;
return 0 ;
V_84:
F_40 ( V_44 ) ;
return V_4 ;
}
static int F_41 ( struct V_69 * V_6 )
{
struct V_43 * V_44 = F_42 ( V_6 ) ;
F_43 ( V_44 ) ;
F_40 ( V_44 ) ;
F_1 ( F_15 ( V_44 ) , V_85 ) ;
return 0 ;
}
static int F_44 ( struct V_26 * V_13 )
{
struct V_1 * V_2 = F_15 ( F_42 (
F_45 ( V_13 ) ) ) ;
return F_1 ( V_2 , V_85 ) ;
}
static int F_46 ( struct V_26 * V_13 )
{
struct V_1 * V_2 = F_15 ( F_42 (
F_45 ( V_13 ) ) ) ;
return F_1 ( V_2 , V_68 ) ;
}
