static unsigned long
F_1 ( int V_1 )
{
unsigned long V_2 ;
unsigned long V_3 ;
V_2 = V_1 * ( 1000000 / V_4 ) ;
V_3 = ( 60 * 1000000 ) / ( V_5 * V_6 ) ;
return ( V_2 + V_3 / 2 ) / V_3 ;
}
static void
F_2 ( unsigned long V_7 )
{
if ( ! V_8 )
return;
V_9 . V_10 = ( 1 ) + V_11 ;
F_3 ( & V_9 ) ;
if ( ! V_12 )
return;
F_4 ( & V_13 ) ;
V_14 ++ ;
V_15 = V_16 + F_1 ( V_14 ) ;
if ( V_15 >= V_17 ) {
V_17 = ( unsigned long ) - 1 ;
F_5 ( 0 ) ;
}
F_6 ( & V_13 ) ;
}
static void
F_7 ( void )
{
unsigned long V_18 ;
F_8 ( & V_13 , V_18 ) ;
V_19 = 0 ;
V_16 = 0 ;
V_14 = 0 ;
V_17 = ( unsigned long ) - 1 ;
V_20 = 0 ;
V_15 = 0 ;
F_9 ( & V_13 , V_18 ) ;
}
static int
F_10 ( int V_21 , int V_22 )
{
if ( V_8 )
return - V_23 ;
F_7 () ;
V_5 = 60 ;
V_6 = 100 ;
V_8 = 1 ;
{
V_9 . V_10 = ( 1 ) + V_11 ;
F_3 ( & V_9 ) ;
}
return 0 ;
}
static void
F_11 ( int V_21 )
{
V_8 = V_12 = 0 ;
F_12 ( & V_9 ) ;
}
static int
F_13 ( int V_21 , unsigned char * V_24 )
{
unsigned char V_25 = V_24 [ 1 ] ;
unsigned long V_26 = * ( int * ) & V_24 [ 4 ] ;
switch ( V_25 )
{
case V_27 :
V_26 += V_20 ;
case V_28 :
if ( V_26 > 0 )
{
long time ;
if ( V_26 <= V_15 )
return V_29 ;
time = V_26 ;
V_17 = V_20 = time ;
return V_30 ;
}
break;
case V_31 :
F_7 () ;
V_12 = 1 ;
break;
case V_32 :
V_12 = 0 ;
break;
case V_33 :
V_12 = 1 ;
break;
case V_34 :
if ( V_26 )
{
if ( V_26 < 8 )
V_26 = 8 ;
if ( V_26 > 360 )
V_26 = 360 ;
V_19 = V_14 ;
V_16 += F_1 ( V_14 ) ;
V_14 = 0 ;
V_5 = V_26 ;
}
break;
case V_35 :
F_14 ( V_24 , 8 ) ;
break;
default: ;
}
return V_29 ;
}
static unsigned long
F_15 ( int V_21 )
{
if ( ! V_8 )
return 0 ;
return V_15 ;
}
static int F_16 ( int V_21 , unsigned int V_25 , void T_1 * V_36 )
{
int T_1 * V_37 = V_36 ;
int V_38 ;
switch ( V_25 ) {
case V_39 :
return F_17 ( V_40 , V_37 ) ;
case V_41 :
F_7 () ;
V_12 = 1 ;
return 0 ;
case V_42 :
V_12 = 0 ;
return 0 ;
case V_43 :
V_12 = 1 ;
return 0 ;
case V_44 :
if ( F_18 ( V_38 , V_37 ) )
return - V_45 ;
if ( V_38 ) {
if ( V_38 < 1 )
V_38 = 1 ;
if ( V_38 > 1000 )
V_38 = 1000 ;
V_6 = V_38 ;
}
return F_17 ( V_6 , V_37 ) ;
case V_46 :
if ( F_18 ( V_38 , V_37 ) )
return - V_45 ;
if ( V_38 ) {
if ( V_38 < 8 )
V_38 = 8 ;
if ( V_38 > 250 )
V_38 = 250 ;
V_19 = V_14 ;
V_16 += F_1 ( V_14 ) ;
V_14 = 0 ;
V_5 = V_38 ;
F_19 () ;
}
return F_17 ( V_5 , V_37 ) ;
case V_47 :
if ( F_18 ( V_38 , V_37 ) )
return - V_45 ;
if ( V_38 != 0 )
return - V_48 ;
V_38 = ( ( V_5 * V_6 ) + 30 ) / 60 ;
return F_17 ( V_38 , V_37 ) ;
case V_49 :
return F_17 ( V_15 , V_37 ) ;
case V_50 :
break;
default: ;
}
return - V_48 ;
}
static void
F_20 ( int V_21 , long time )
{
if ( time < 0 )
time = V_15 + 1 ;
else if ( time <= V_15 )
return;
V_17 = V_20 = time ;
return;
}
