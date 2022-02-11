static unsigned long F_1 ( int V_1 )
{
unsigned long V_2 ;
unsigned long V_3 ;
V_2 = V_1 * V_4 ;
V_3 = ( 60 * 1000000 ) / ( V_5 * V_6 ) ;
return ( V_2 + ( V_3 / 2 ) ) / V_3 ;
}
void F_2 ( void )
{
unsigned long V_7 ;
if( ! V_8 )
return;
V_7 = ( 60 * 1000000 ) / ( V_5 * V_6 ) ;
if ( V_7 < 2000 )
V_7 = 2000 ;
V_4 = V_8 -> V_9 ( V_8 -> V_10 , V_7 ) ;
}
void F_3 ( unsigned int V_11 )
{
V_12 = V_13 ;
V_14 += F_1 ( V_13 ) ;
V_13 = 0 ;
V_4 = V_11 ;
}
static void F_4 ( void )
{
unsigned long V_15 ;
F_5 ( & V_16 , V_15 ) ;
V_12 = 0 ;
V_14 = 0 ;
V_13 = 0 ;
V_17 = ( unsigned long ) - 1 ;
V_18 = 0 ;
V_19 = 0 ;
F_6 ( & V_16 , V_15 ) ;
}
static int F_7 ( int V_10 , int V_20 )
{
if ( V_21 )
return - V_22 ;
F_4 () ;
V_5 = 60 ;
V_6 = 100 ;
V_21 = 1 ;
F_2 () ;
return 0 ;
}
static void F_8 ( int V_10 )
{
V_21 = V_23 = 0 ;
V_8 -> V_24 ( V_8 -> V_10 ) ;
}
static int F_9 ( int V_10 , unsigned char * V_25 )
{
unsigned char V_26 = V_25 [ 1 ] ;
unsigned long V_27 = * ( int * ) & V_25 [ 4 ] ;
switch ( V_26 )
{
case V_28 :
V_27 += V_18 ;
case V_29 :
if ( V_27 > 0 )
{
long time ;
if ( V_27 <= V_19 )
return V_30 ;
time = V_27 ;
V_17 = V_18 = time ;
return V_31 ;
}
break;
case V_32 :
F_4 () ;
V_23 = 1 ;
F_2 () ;
break;
case V_33 :
V_23 = 0 ;
break;
case V_34 :
V_23 = 1 ;
F_2 () ;
break;
case V_35 :
if ( V_27 )
{
if ( V_27 < 8 )
V_27 = 8 ;
if ( V_27 > 250 )
V_27 = 250 ;
V_12 = V_13 ;
V_14 += F_1 ( V_13 ) ;
V_13 = 0 ;
V_5 = V_27 ;
F_2 () ;
}
break;
case V_36 :
F_10 ( V_25 , 8 ) ;
break;
default: ;
}
return V_30 ;
}
static unsigned long F_11 ( int V_10 )
{
if ( ! V_21 )
return 0 ;
return V_19 ;
}
static int F_12 ( int V_10 , unsigned int V_26 , void T_1 * V_37 )
{
int T_1 * V_38 = V_37 ;
int V_39 ;
switch ( V_26 )
{
case V_40 :
V_39 = V_41 ;
break;
case V_42 :
F_4 () ;
V_23 = 1 ;
return 0 ;
case V_43 :
V_23 = 0 ;
return 0 ;
case V_44 :
V_23 = 1 ;
return 0 ;
case V_45 :
if ( F_13 ( V_39 , V_38 ) )
return - V_46 ;
if ( V_39 )
{
if ( V_39 < 1 )
V_39 = 1 ;
if ( V_39 > 1000 )
V_39 = 1000 ;
V_6 = V_39 ;
}
V_39 = V_6 ;
break;
case V_47 :
if ( F_13 ( V_39 , V_38 ) )
return - V_46 ;
if ( V_39 )
{
if ( V_39 < 8 )
V_39 = 8 ;
if ( V_39 > 250 )
V_39 = 250 ;
V_12 = V_13 ;
V_14 += F_1 ( V_13 ) ;
V_13 = 0 ;
V_5 = V_39 ;
F_2 () ;
}
V_39 = V_5 ;
break;
case V_48 :
if ( F_13 ( V_39 , V_38 ) )
return - V_46 ;
if ( V_39 != 0 )
return - V_49 ;
V_39 = ( ( V_5 * V_6 ) + 30 ) / 60 ;
break;
case V_50 :
V_39 = V_19 ;
break;
case V_51 :
default:
return - V_49 ;
}
return F_14 ( V_39 , V_38 ) ;
}
static void F_15 ( int V_10 , long time )
{
if ( time < 0 )
time = V_19 + 1 ;
else if ( time <= V_19 )
return;
V_17 = V_18 = time ;
return;
}
void F_16 ( void )
{
unsigned long V_15 ;
if ( ! V_21 )
return;
V_8 -> V_52 ( V_8 -> V_10 ) ;
if ( ! V_23 )
return;
F_5 ( & V_16 , V_15 ) ;
V_13 ++ ;
V_19 = V_14 + F_1 ( V_13 ) ;
if ( V_19 >= V_17 )
{
V_17 = ( unsigned long ) - 1 ;
F_17 ( 0 ) ;
}
F_6 ( & V_16 , V_15 ) ;
}
void F_18 ( struct V_53 * V_54 , char * V_55 )
{
int V_56 ;
if ( V_57 )
{
if ( V_54 -> V_58 <= V_8 -> V_58 )
return;
V_8 = V_54 ;
return;
}
V_57 = 1 ;
V_8 = V_54 ;
V_56 = F_19 () ;
if ( V_56 == - 1 )
V_56 = 0 ;
strcpy ( V_59 . V_60 . V_55 , V_55 ) ;
V_61 [ V_56 ] = & V_59 ;
}
