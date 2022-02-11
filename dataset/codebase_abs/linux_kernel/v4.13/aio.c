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
F_8 () ;
while ( 1 ) {
V_1 = F_4 ( V_4 , 1 , 1 , & V_42 , NULL ) ;
if ( V_1 < 0 ) {
if ( V_38 == V_45 )
continue;
F_6 ( V_36 L_2
L_3 , V_38 ) ;
}
else {
V_41 = ( (struct V_40 )
{ . V_46 = ( void * ) ( long ) V_42 . V_46 ,
. V_43 = V_42 . V_47 } ) ;
V_44 = ( (struct V_21 * ) V_41 . V_46 ) -> V_44 ;
V_43 = F_9 ( V_44 , & V_41 , sizeof( V_41 ) ) ;
if ( V_43 != sizeof( V_41 ) )
F_6 ( V_36 L_4
L_5 , V_44 , V_38 ) ;
}
}
return 0 ;
}
static int F_10 ( struct V_48 * V_49 )
{
char V_29 ;
unsigned long long V_50 ;
int V_1 ;
V_50 = F_11 ( V_49 -> V_51 , V_49 -> V_20 , V_52 ) ;
if ( V_50 != V_49 -> V_20 )
return - V_38 ;
switch ( V_49 -> type ) {
case V_30 :
V_1 = F_12 ( V_49 -> V_51 , V_49 -> V_18 , V_49 -> V_19 ) ;
break;
case V_33 :
V_1 = F_9 ( V_49 -> V_51 , V_49 -> V_18 , V_49 -> V_19 ) ;
break;
case V_35 :
V_1 = F_12 ( V_49 -> V_51 , & V_29 , sizeof( V_29 ) ) ;
break;
default:
F_6 ( V_36 L_6 ,
V_49 -> type ) ;
return - V_37 ;
}
if ( V_1 < 0 )
return - V_38 ;
return 0 ;
}
static int F_13 ( void * V_39 )
{
struct V_48 V_49 ;
struct V_40 V_41 ;
int V_43 ;
F_8 () ;
while ( 1 ) {
V_43 = F_12 ( V_53 , & V_49 , sizeof( V_49 ) ) ;
if ( V_43 != sizeof( V_49 ) ) {
if ( V_43 < 0 )
F_6 ( V_36 L_7
L_8 ,
V_53 ,
V_38 ) ;
else {
F_6 ( V_36 L_9
L_10 ,
V_53 , V_43 ) ;
}
continue;
}
V_43 = F_10 ( & V_49 ) ;
V_41 = ( (struct V_40 ) { . V_46 = V_49 . V_22 ,
. V_43 = V_43 } ) ;
V_43 = F_9 ( V_49 . V_22 -> V_44 , & V_41 , sizeof( V_41 ) ) ;
if ( V_43 != sizeof( V_41 ) )
F_6 ( V_36 L_11
L_5 , V_49 . V_22 -> V_44 , V_38 ) ;
}
return 0 ;
}
static int F_14 ( void )
{
int V_54 [ 2 ] , V_43 ;
V_43 = F_15 ( V_54 , 1 , 1 ) ;
if ( V_43 )
goto V_55;
V_56 = V_54 [ 0 ] ;
V_53 = V_54 [ 1 ] ;
V_43 = F_16 ( V_56 , 0 ) ;
if ( V_43 )
goto V_57;
V_43 = F_17 ( F_13 , NULL ,
V_58 | V_59 , & V_60 ) ;
if ( V_43 < 0 )
goto V_57;
V_61 = V_43 ;
goto V_55;
V_57:
F_18 ( V_54 [ 0 ] ) ;
F_18 ( V_54 [ 1 ] ) ;
V_56 = - 1 ;
V_53 = - 1 ;
V_55:
#ifndef F_19
F_6 ( V_62 L_12
L_13 ) ;
#endif
F_6 ( V_62 L_14
L_15 ) ;
return 0 ;
}
static int F_20 ( void )
{
int V_43 ;
if ( F_1 ( 256 , & V_4 ) ) {
V_43 = - V_38 ;
F_6 ( V_36 L_16
L_17 , V_38 ) ;
return V_43 ;
}
V_43 = F_17 ( F_7 , NULL ,
V_58 | V_59 , & V_60 ) ;
if ( V_43 < 0 )
return V_43 ;
V_61 = V_43 ;
F_6 ( V_62 L_18 ) ;
return 0 ;
}
static int F_21 ( enum V_16 type , int V_51 , char * V_18 , int V_19 ,
unsigned long long V_20 , struct V_21 * V_22 )
{
struct V_40 V_41 ;
int V_43 ;
V_43 = F_5 ( V_4 , type , V_51 , V_18 , V_19 , V_20 , V_22 ) ;
if ( V_43 ) {
V_41 = ( (struct V_40 ) { . V_46 = V_22 ,
. V_43 = V_43 } ) ;
V_43 = F_9 ( V_22 -> V_44 , & V_41 , sizeof( V_41 ) ) ;
if ( V_43 != sizeof( V_41 ) ) {
V_43 = - V_38 ;
F_6 ( V_36 L_19
L_5 , V_22 -> V_44 , - V_43 ) ;
}
else V_43 = 0 ;
}
return V_43 ;
}
static int F_20 ( void )
{
return - V_63 ;
}
static int F_21 ( enum V_16 type , int V_51 , char * V_18 , int V_19 ,
unsigned long long V_20 , struct V_21 * V_22 )
{
return - V_63 ;
}
static int T_2 F_22 ( char * V_64 , int * V_65 )
{
V_66 = 1 ;
return 0 ;
}
static int F_23 ( void )
{
int V_43 ;
if ( ! V_66 ) {
V_43 = F_20 () ;
if ( V_43 && ( V_38 == V_63 ) ) {
F_6 ( V_62 L_20
L_21 ) ;
V_66 = 1 ;
}
else return V_43 ;
}
if ( V_66 )
return F_14 () ;
return 0 ;
}
static void F_24 ( void )
{
if ( V_61 != - 1 ) {
F_25 ( V_61 , 1 ) ;
F_26 ( V_60 , 0 ) ;
}
}
static int F_27 ( enum V_16 type , int V_51 , char * V_18 , int V_19 ,
unsigned long long V_20 , struct V_21 * V_22 )
{
struct V_48 V_49 = { . type = type ,
. V_51 = V_51 ,
. V_20 = V_20 ,
. V_18 = V_18 ,
. V_19 = V_19 ,
. V_22 = V_22 ,
} ;
int V_43 ;
V_43 = F_9 ( V_56 , & V_49 , sizeof( V_49 ) ) ;
if ( V_43 == sizeof( V_49 ) )
V_43 = 0 ;
else V_43 = - V_38 ;
return V_43 ;
}
int F_28 ( enum V_16 type , int V_51 , char * V_18 , int V_19 ,
unsigned long long V_20 , int V_44 ,
struct V_21 * V_22 )
{
V_22 -> V_44 = V_44 ;
if ( V_66 )
return F_27 ( type , V_51 , V_18 , V_19 , V_20 , V_22 ) ;
else
return F_21 ( type , V_51 , V_18 , V_19 , V_20 , V_22 ) ;
}
