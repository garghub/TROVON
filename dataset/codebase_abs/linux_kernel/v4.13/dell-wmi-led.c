static int F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 , T_1 V_6 )
{
struct V_7 V_8 = { V_9 , NULL } ;
struct V_10 * V_11 ;
struct V_7 V_12 ;
union V_13 * V_14 ;
T_2 V_15 ;
T_1 V_16 ;
struct V_10 args = {
. V_1 = V_1 ,
. V_2 = V_2 ,
. V_3 = V_3 ,
. V_4 = V_4 ,
. V_5 = V_5 ,
. V_6 = V_6
} ;
V_12 . V_1 = sizeof( struct V_10 ) ;
V_12 . V_17 = & args ;
V_15 = F_2 ( V_18 , 0 , 1 , & V_12 , & V_8 ) ;
if ( F_3 ( V_15 ) )
return V_15 ;
V_14 = V_8 . V_17 ;
if ( ! V_14 )
return - V_19 ;
if ( V_14 -> type != V_20 ) {
F_4 ( V_14 ) ;
return - V_19 ;
}
V_11 = ( (struct V_10 * ) V_14 -> V_21 . V_17 ) ;
V_16 = V_11 -> V_2 ;
F_4 ( V_14 ) ;
return V_16 ;
}
static int F_5 ( void )
{
return F_1 ( 3 ,
V_22 ,
V_23 ,
V_24 ,
0 ,
0 ) ;
}
static int F_6 ( void )
{
return F_1 ( 3 ,
V_22 ,
V_23 ,
V_25 ,
0 ,
0 ) ;
}
static int F_7 ( unsigned char V_26 , unsigned char V_27 )
{
return F_1 ( 5 ,
V_22 ,
V_23 ,
V_28 ,
V_26 ,
V_27 ) ;
}
static void F_8 ( struct V_29 * V_30 ,
enum V_31 V_32 )
{
if ( V_32 == V_33 )
F_6 () ;
else
F_5 () ;
}
static int F_9 ( struct V_29 * V_30 ,
unsigned long * V_34 , unsigned long * V_35 )
{
unsigned long V_26 ;
unsigned long V_27 ;
V_26 = F_10 ( * V_34 , 125 ) ;
V_26 = F_11 (unsigned long, on_eighths, 1 , 255 ) ;
* V_34 = V_26 * 125 ;
V_27 = F_10 ( * V_35 , 125 ) ;
V_27 = F_11 (unsigned long, off_eighths, 1 , 255 ) ;
* V_35 = V_27 * 125 ;
F_7 ( V_26 , V_27 ) ;
return 0 ;
}
static int T_3 F_12 ( void )
{
int error = 0 ;
if ( ! F_13 ( V_18 ) )
return - V_36 ;
error = F_6 () ;
if ( error != 0 )
return - V_36 ;
return F_14 ( NULL , & V_37 ) ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_37 ) ;
F_6 () ;
}
