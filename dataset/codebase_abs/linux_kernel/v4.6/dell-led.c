static int F_1 ( int V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
if ( ! F_2 ( V_6 ) )
return - V_7 ;
if ( V_1 == 0 )
V_5 = F_3 ( V_8 ) ;
else if ( V_1 == 1 )
V_5 = F_3 ( V_9 ) ;
else
return - V_10 ;
if ( ! V_5 )
return - V_7 ;
V_3 = F_4 () ;
V_3 -> V_11 [ 0 ] = V_5 -> V_12 ;
V_3 -> V_11 [ 1 ] = V_5 -> V_13 ;
F_5 ( 1 , 0 ) ;
F_6 () ;
return V_1 ;
}
int F_7 ( int V_14 , int V_15 )
{
int V_1 = 0 ;
switch ( V_14 ) {
case V_16 :
V_1 = F_1 ( V_15 ) ;
break;
default:
F_8 ( L_1 , V_14 ) ;
break;
}
return V_1 ;
}
static int F_9 ( T_1 V_17 ,
T_1 V_18 ,
T_1 V_19 ,
T_1 V_20 ,
T_1 V_21 ,
T_1 V_22 )
{
struct V_23 * V_24 ;
T_1 V_25 ;
union V_26 * V_27 ;
struct V_28 V_29 = { V_30 , NULL } ;
struct V_28 V_11 ;
T_2 V_31 ;
struct V_23 args ;
args . V_17 = V_17 ;
args . V_18 = V_18 ;
args . V_19 = V_19 ;
args . V_20 = V_20 ;
args . V_21 = V_21 ;
args . V_22 = V_22 ;
V_11 . V_17 = sizeof( struct V_23 ) ;
V_11 . V_32 = & args ;
V_31 = F_10 ( V_33 ,
1 ,
1 ,
& V_11 ,
& V_29 ) ;
if ( F_11 ( V_31 ) )
return V_31 ;
V_27 = V_29 . V_32 ;
if ( ! V_27 )
return - V_10 ;
else if ( V_27 -> type != V_34 ) {
F_12 ( V_27 ) ;
return - V_10 ;
}
V_24 = ( (struct V_23 * ) V_27 -> V_3 . V_32 ) ;
V_25 = V_24 -> V_18 ;
F_12 ( V_27 ) ;
return V_25 ;
}
static int F_13 ( void )
{
return F_9 ( 3 ,
V_35 ,
V_36 ,
V_37 ,
0 ,
0 ) ;
}
static int F_14 ( void )
{
return F_9 ( 3 ,
V_35 ,
V_36 ,
V_38 ,
0 ,
0 ) ;
}
static int F_15 ( unsigned char V_39 ,
unsigned char V_40 )
{
return F_9 ( 5 ,
V_35 ,
V_36 ,
V_41 ,
V_39 ,
V_40 ) ;
}
static void F_16 ( struct V_42 * V_43 ,
enum V_44 V_13 )
{
if ( V_13 == V_45 )
F_14 () ;
else
F_13 () ;
}
static int F_17 ( struct V_42 * V_43 ,
unsigned long * V_46 ,
unsigned long * V_47 )
{
unsigned long V_39 ;
unsigned long V_40 ;
V_39 = ( * V_46 + 124 ) / 125 ;
if ( 0 == V_39 )
V_39 = 1 ;
if ( V_39 > 255 )
V_39 = 255 ;
* V_46 = V_39 * 125 ;
V_40 = ( * V_47 + 124 ) / 125 ;
if ( 0 == V_40 )
V_40 = 1 ;
if ( V_40 > 255 )
V_40 = 255 ;
* V_47 = V_40 * 125 ;
F_15 ( V_39 , V_40 ) ;
return 0 ;
}
static int T_3 F_18 ( void )
{
int error = 0 ;
if ( ! F_2 ( V_33 ) && ! F_2 ( V_6 ) )
return - V_7 ;
if ( F_2 ( V_33 ) ) {
error = F_14 () ;
if ( error != 0 )
return - V_7 ;
error = F_19 ( NULL , & V_48 ) ;
}
return error ;
}
static void T_4 F_20 ( void )
{
int error = 0 ;
if ( F_2 ( V_33 ) ) {
error = F_14 () ;
if ( error == 0 )
F_21 ( & V_48 ) ;
}
}
