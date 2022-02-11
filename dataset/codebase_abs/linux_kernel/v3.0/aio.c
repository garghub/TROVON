static long F_1 ( int V_1 , T_1 * V_2 )
{
return F_2 ( V_3 , V_1 , V_2 ) ;
}
static long F_3 ( T_1 V_4 , long V_5 , struct V_6 * * V_7 )
{
return F_2 ( V_8 , V_4 , V_5 , V_7 ) ;
}
static long F_4 ( T_1 V_9 , long V_10 , long V_5 ,
struct V_11 * V_12 , struct V_13 * V_14 )
{
return F_2 ( V_15 , V_9 , V_10 , V_5 , V_12 , V_14 ) ;
}
static int F_5 ( T_1 V_4 , enum V_16 type , int V_17 , char * V_18 ,
int V_19 , unsigned long long V_20 , struct V_21 * V_22 )
{
struct V_6 * V_23 = & ( (struct V_6 ) {
. V_24 = ( unsigned long ) V_22 ,
. V_25 = V_17 ,
. V_26 = ( unsigned long ) V_18 ,
. V_27 = V_19 ,
. V_28 = V_20
} ) ;
char V_29 ;
switch ( type ) {
case V_30 :
V_23 -> V_31 = V_32 ;
break;
case V_33 :
V_23 -> V_31 = V_34 ;
break;
case V_35 :
V_23 -> V_31 = V_32 ;
V_23 -> V_26 = ( unsigned long ) & V_29 ;
V_23 -> V_27 = sizeof( V_29 ) ;
break;
default:
F_6 ( V_36 L_1 , type ) ;
return - V_37 ;
}
return ( F_3 ( V_4 , 1 , & V_23 ) > 0 ) ? 0 : - V_38 ;
}
static int F_7 ( void * V_39 )
{
struct V_40 V_41 ;
struct V_11 V_42 ;
int V_43 , V_1 , V_44 ;
signal ( V_45 , V_46 ) ;
while ( 1 ) {
V_1 = F_4 ( V_4 , 1 , 1 , & V_42 , NULL ) ;
if ( V_1 < 0 ) {
if ( V_38 == V_47 )
continue;
F_6 ( V_36 L_2
L_3 , V_38 ) ;
}
else {
V_41 = ( (struct V_40 )
{ . V_48 = ( void * ) ( long ) V_42 . V_48 ,
. V_43 = V_42 . V_49 } ) ;
V_44 = ( (struct V_21 * ) V_41 . V_48 ) -> V_44 ;
V_43 = F_8 ( V_44 , & V_41 , sizeof( V_41 ) ) ;
if ( V_43 != sizeof( V_41 ) )
F_6 ( V_36 L_4
L_5 , V_44 , V_38 ) ;
}
}
return 0 ;
}
static int F_9 ( struct V_50 * V_51 )
{
char V_29 ;
unsigned long long V_52 ;
int V_1 ;
V_52 = F_10 ( V_51 -> V_53 , V_51 -> V_20 , V_54 ) ;
if ( V_52 != V_51 -> V_20 )
return - V_38 ;
switch ( V_51 -> type ) {
case V_30 :
V_1 = F_11 ( V_51 -> V_53 , V_51 -> V_18 , V_51 -> V_19 ) ;
break;
case V_33 :
V_1 = F_8 ( V_51 -> V_53 , V_51 -> V_18 , V_51 -> V_19 ) ;
break;
case V_35 :
V_1 = F_11 ( V_51 -> V_53 , & V_29 , sizeof( V_29 ) ) ;
break;
default:
F_6 ( V_36 L_6 ,
V_51 -> type ) ;
return - V_37 ;
}
if ( V_1 < 0 )
return - V_38 ;
return 0 ;
}
static int F_12 ( void * V_39 )
{
struct V_50 V_51 ;
struct V_40 V_41 ;
int V_43 ;
signal ( V_45 , V_46 ) ;
while ( 1 ) {
V_43 = F_11 ( V_55 , & V_51 , sizeof( V_51 ) ) ;
if ( V_43 != sizeof( V_51 ) ) {
if ( V_43 < 0 )
F_6 ( V_36 L_7
L_8 ,
V_55 ,
V_38 ) ;
else {
F_6 ( V_36 L_9
L_10 ,
V_55 , V_43 ) ;
}
continue;
}
V_43 = F_9 ( & V_51 ) ;
V_41 = ( (struct V_40 ) { . V_48 = V_51 . V_22 ,
. V_43 = V_43 } ) ;
V_43 = F_8 ( V_51 . V_22 -> V_44 , & V_41 , sizeof( V_41 ) ) ;
if ( V_43 != sizeof( V_41 ) )
F_6 ( V_36 L_11
L_5 , V_51 . V_22 -> V_44 , V_38 ) ;
}
return 0 ;
}
static int F_13 ( void )
{
int V_56 [ 2 ] , V_43 ;
V_43 = F_14 ( V_56 , 1 , 1 ) ;
if ( V_43 )
goto V_57;
V_58 = V_56 [ 0 ] ;
V_55 = V_56 [ 1 ] ;
V_43 = F_15 ( V_58 , 0 ) ;
if ( V_43 )
goto V_59;
V_43 = F_16 ( F_12 , NULL ,
V_60 | V_61 , & V_62 ) ;
if ( V_43 < 0 )
goto V_59;
V_63 = V_43 ;
goto V_57;
V_59:
F_17 ( V_56 [ 0 ] ) ;
F_17 ( V_56 [ 1 ] ) ;
V_58 = - 1 ;
V_55 = - 1 ;
V_57:
#ifndef F_18
F_6 ( V_64 L_12
L_13 ) ;
#endif
F_6 ( V_64 L_14
L_15 ) ;
return 0 ;
}
static int F_19 ( void )
{
int V_43 ;
if ( F_1 ( 256 , & V_4 ) ) {
V_43 = - V_38 ;
F_6 ( V_36 L_16
L_17 , V_38 ) ;
return V_43 ;
}
V_43 = F_16 ( F_7 , NULL ,
V_60 | V_61 , & V_62 ) ;
if ( V_43 < 0 )
return V_43 ;
V_63 = V_43 ;
F_6 ( V_64 L_18 ) ;
return 0 ;
}
static int F_20 ( enum V_16 type , int V_53 , char * V_18 , int V_19 ,
unsigned long long V_20 , struct V_21 * V_22 )
{
struct V_40 V_41 ;
int V_43 ;
V_43 = F_5 ( V_4 , type , V_53 , V_18 , V_19 , V_20 , V_22 ) ;
if ( V_43 ) {
V_41 = ( (struct V_40 ) { . V_48 = V_22 ,
. V_43 = V_43 } ) ;
V_43 = F_8 ( V_22 -> V_44 , & V_41 , sizeof( V_41 ) ) ;
if ( V_43 != sizeof( V_41 ) ) {
V_43 = - V_38 ;
F_6 ( V_36 L_19
L_5 , V_22 -> V_44 , - V_43 ) ;
}
else V_43 = 0 ;
}
return V_43 ;
}
static int F_19 ( void )
{
return - V_65 ;
}
static int F_20 ( enum V_16 type , int V_53 , char * V_18 , int V_19 ,
unsigned long long V_20 , struct V_21 * V_22 )
{
return - V_65 ;
}
static int T_2 F_21 ( char * V_66 , int * V_67 )
{
V_68 = 1 ;
return 0 ;
}
static int F_22 ( void )
{
int V_43 ;
if ( ! V_68 ) {
V_43 = F_19 () ;
if ( V_43 && ( V_38 == V_65 ) ) {
F_6 ( V_64 L_20
L_21 ) ;
V_68 = 1 ;
}
else return V_43 ;
}
if ( V_68 )
return F_13 () ;
return 0 ;
}
static void F_23 ( void )
{
if ( V_63 != - 1 ) {
F_24 ( V_63 , 1 ) ;
F_25 ( V_62 , 0 ) ;
}
}
static int F_26 ( enum V_16 type , int V_53 , char * V_18 , int V_19 ,
unsigned long long V_20 , struct V_21 * V_22 )
{
struct V_50 V_51 = { . type = type ,
. V_53 = V_53 ,
. V_20 = V_20 ,
. V_18 = V_18 ,
. V_19 = V_19 ,
. V_22 = V_22 ,
} ;
int V_43 ;
V_43 = F_8 ( V_58 , & V_51 , sizeof( V_51 ) ) ;
if ( V_43 == sizeof( V_51 ) )
V_43 = 0 ;
else V_43 = - V_38 ;
return V_43 ;
}
int F_27 ( enum V_16 type , int V_53 , char * V_18 , int V_19 ,
unsigned long long V_20 , int V_44 ,
struct V_21 * V_22 )
{
V_22 -> V_44 = V_44 ;
if ( V_68 )
return F_26 ( type , V_53 , V_18 , V_19 , V_20 , V_22 ) ;
else
return F_20 ( type , V_53 , V_18 , V_19 , V_20 , V_22 ) ;
}
