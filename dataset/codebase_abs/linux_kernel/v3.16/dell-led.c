static int F_1 ( struct V_1 * args )
{
struct V_1 * V_2 ;
union V_3 * V_4 ;
struct V_5 V_6 ;
struct V_5 V_7 = { V_8 , NULL } ;
T_1 V_9 ;
T_2 V_10 = - V_11 ;
V_6 . V_12 = 128 ;
V_6 . V_13 = args ;
V_9 = F_2 ( V_14 , 0 , 1 , & V_6 , & V_7 ) ;
if ( ! F_3 ( V_9 ) )
goto V_15;
V_4 = V_7 . V_13 ;
if ( ! V_4 )
goto V_15;
if ( V_4 -> type != V_16 )
goto V_17;
V_2 = (struct V_1 * ) V_4 -> V_18 . V_13 ;
V_10 = V_2 -> V_19 ;
if ( V_10 )
goto V_17;
memcpy ( args , V_2 , sizeof( struct V_1 ) ) ;
V_10 = 0 ;
V_17:
F_4 ( V_4 ) ;
V_15:
return V_10 ;
}
static void T_3 F_5 ( const struct V_20 * V_21 , void * V_22 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
int V_27 = sizeof( struct V_25 ) ;
int V_28 = 0 ;
if ( V_21 -> type == 0xda && V_21 -> V_12 > 17 ) {
V_24 = F_6 ( V_21 ,
struct V_23 , V_29 ) ;
V_26 = & V_24 -> V_30 [ V_28 ] ;
while ( V_26 -> V_31 != 0xffff ) {
if ( V_26 -> V_31 == V_32 )
memcpy ( & V_33 [ 0 ] , V_26 , V_27 ) ;
else if ( V_26 -> V_31 == V_34 )
memcpy ( & V_33 [ 1 ] , V_26 , V_27 ) ;
V_28 ++ ;
V_26 = & V_24 -> V_30 [ V_28 ] ;
}
}
}
static int F_7 ( int V_35 )
{
struct V_1 args ;
struct V_25 * V_26 ;
if ( ! F_8 ( V_14 ) )
return - V_36 ;
if ( V_35 == 0 || V_35 == 1 )
V_26 = & V_33 [ V_35 ] ;
else
return - V_11 ;
memset ( & args , 0 , sizeof( struct V_1 ) ) ;
args . V_37 = 1 ;
args . V_38 = V_26 -> V_39 ;
args . V_40 = V_26 -> V_41 ;
F_1 ( & args ) ;
return V_35 ;
}
int F_9 ( int V_42 , int V_43 )
{
int V_35 = 0 ;
switch ( V_42 ) {
case V_44 :
V_35 = F_7 ( V_43 ) ;
break;
default:
F_10 ( L_1 , V_42 ) ;
break;
}
return V_35 ;
}
static int T_3 F_11 ( void )
{
memset ( V_33 , 0 , sizeof( struct V_25 ) * 2 ) ;
F_12 ( F_5 , NULL ) ;
return 0 ;
}
static int F_13 ( T_4 V_12 ,
T_4 V_45 ,
T_4 V_46 ,
T_4 V_47 ,
T_4 V_48 ,
T_4 V_49 )
{
struct V_50 * V_2 ;
T_4 V_51 ;
union V_3 * V_4 ;
struct V_5 V_7 = { V_8 , NULL } ;
struct V_5 V_6 ;
T_1 V_9 ;
struct V_50 args ;
args . V_12 = V_12 ;
args . V_45 = V_45 ;
args . V_46 = V_46 ;
args . V_47 = V_47 ;
args . V_48 = V_48 ;
args . V_49 = V_49 ;
V_6 . V_12 = sizeof( struct V_50 ) ;
V_6 . V_13 = & args ;
V_9 = F_2 ( V_52 ,
1 ,
1 ,
& V_6 ,
& V_7 ) ;
if ( F_14 ( V_9 ) )
return V_9 ;
V_4 = V_7 . V_13 ;
if ( ! V_4 )
return - V_11 ;
else if ( V_4 -> type != V_16 ) {
F_4 ( V_4 ) ;
return - V_11 ;
}
V_2 = ( (struct V_50 * ) V_4 -> V_18 . V_13 ) ;
V_51 = V_2 -> V_45 ;
F_4 ( V_4 ) ;
return V_51 ;
}
static int F_15 ( void )
{
return F_13 ( 3 ,
V_53 ,
V_54 ,
V_55 ,
0 ,
0 ) ;
}
static int F_16 ( void )
{
return F_13 ( 3 ,
V_53 ,
V_54 ,
V_56 ,
0 ,
0 ) ;
}
static int F_17 ( unsigned char V_57 ,
unsigned char V_58 )
{
return F_13 ( 5 ,
V_53 ,
V_54 ,
V_59 ,
V_57 ,
V_58 ) ;
}
static void F_18 ( struct V_60 * V_61 ,
enum V_62 V_41 )
{
if ( V_41 == V_63 )
F_16 () ;
else
F_15 () ;
}
static int F_19 ( struct V_60 * V_61 ,
unsigned long * V_64 ,
unsigned long * V_65 )
{
unsigned long V_57 ;
unsigned long V_58 ;
V_57 = ( * V_64 + 124 ) / 125 ;
if ( 0 == V_57 )
V_57 = 1 ;
if ( V_57 > 255 )
V_57 = 255 ;
* V_64 = V_57 * 125 ;
V_58 = ( * V_65 + 124 ) / 125 ;
if ( 0 == V_58 )
V_58 = 1 ;
if ( V_58 > 255 )
V_58 = 255 ;
* V_65 = V_58 * 125 ;
F_17 ( V_57 , V_58 ) ;
return 0 ;
}
static int T_3 F_20 ( void )
{
int error = 0 ;
if ( ! F_8 ( V_52 ) && ! F_8 ( V_14 ) )
return - V_36 ;
if ( F_8 ( V_14 ) )
error = F_11 () ;
if ( F_8 ( V_52 ) ) {
error = F_16 () ;
if ( error != 0 )
return - V_36 ;
error = F_21 ( NULL , & V_66 ) ;
}
return error ;
}
static void T_5 F_22 ( void )
{
int error = 0 ;
if ( F_8 ( V_52 ) ) {
error = F_16 () ;
if ( error == 0 )
F_23 ( & V_66 ) ;
}
}
