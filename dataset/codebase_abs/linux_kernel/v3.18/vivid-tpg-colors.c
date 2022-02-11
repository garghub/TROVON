static void F_1 ( double * V_1 , double * V_2 , double * V_3 , const double V_4 [ 3 ] [ 3 ] )
{
double V_5 , V_6 , V_7 ;
V_5 = V_4 [ 0 ] [ 0 ] * ( * V_1 ) + V_4 [ 0 ] [ 1 ] * ( * V_2 ) + V_4 [ 0 ] [ 2 ] * ( * V_3 ) ;
V_6 = V_4 [ 1 ] [ 0 ] * ( * V_1 ) + V_4 [ 1 ] [ 1 ] * ( * V_2 ) + V_4 [ 1 ] [ 2 ] * ( * V_3 ) ;
V_7 = V_4 [ 2 ] [ 0 ] * ( * V_1 ) + V_4 [ 2 ] [ 1 ] * ( * V_2 ) + V_4 [ 2 ] [ 2 ] * ( * V_3 ) ;
* V_1 = V_5 ;
* V_2 = V_6 ;
* V_3 = V_7 ;
}
static double F_2 ( double V_8 )
{
return ( V_8 <= 0.03928 ) ? V_8 / 12.92 : pow ( ( V_8 + 0.055 ) / 1.055 , 2.4 ) ;
}
static double F_3 ( double V_8 )
{
return ( V_8 <= 0.0228 ) ? V_8 * 4.0 : 1.1115 * pow ( V_8 , 0.45 ) - 0.1115 ;
}
static double F_4 ( double V_8 )
{
return ( V_8 < 0.018 ) ? V_8 * 4.5 : 1.099 * pow ( V_8 , 0.45 ) - 0.099 ;
}
static double F_5 ( double V_8 )
{
return F_4 ( F_2 ( V_8 ) ) ;
}
static void F_6 ( enum V_9 V_10 , double * V_1 , double * V_2 , double * V_3 )
{
switch ( V_10 ) {
case V_11 :
* V_1 = F_2 ( * V_1 ) ;
* V_2 = F_2 ( * V_2 ) ;
* V_3 = F_2 ( * V_3 ) ;
F_1 ( V_1 , V_2 , V_3 , V_12 ) ;
break;
case V_13 :
* V_1 = F_2 ( * V_1 ) ;
* V_2 = F_2 ( * V_2 ) ;
* V_3 = F_2 ( * V_3 ) ;
F_1 ( V_1 , V_2 , V_3 , V_14 ) ;
break;
case V_15 :
* V_1 = F_2 ( * V_1 ) ;
* V_2 = F_2 ( * V_2 ) ;
* V_3 = F_2 ( * V_3 ) ;
F_1 ( V_1 , V_2 , V_3 , V_16 ) ;
break;
case V_17 :
* V_1 = F_2 ( * V_1 ) ;
* V_2 = F_2 ( * V_2 ) ;
* V_3 = F_2 ( * V_3 ) ;
F_1 ( V_1 , V_2 , V_3 , V_18 ) ;
break;
case V_19 :
case V_20 :
default:
break;
}
* V_1 = ( ( * V_1 ) < 0 ) ? 0 : ( ( ( * V_1 ) > 1 ) ? 1 : ( * V_1 ) ) ;
* V_2 = ( ( * V_2 ) < 0 ) ? 0 : ( ( ( * V_2 ) > 1 ) ? 1 : ( * V_2 ) ) ;
* V_3 = ( ( * V_3 ) < 0 ) ? 0 : ( ( ( * V_3 ) > 1 ) ? 1 : ( * V_3 ) ) ;
switch ( V_10 ) {
case V_11 :
* V_1 = F_3 ( * V_1 ) ;
* V_2 = F_3 ( * V_2 ) ;
* V_3 = F_3 ( * V_3 ) ;
break;
case V_13 :
case V_17 :
case V_15 :
* V_1 = F_4 ( * V_1 ) ;
* V_2 = F_4 ( * V_2 ) ;
* V_3 = F_4 ( * V_3 ) ;
break;
case V_19 :
break;
case V_20 :
default:
* V_1 = F_5 ( * V_1 ) ;
* V_2 = F_5 ( * V_2 ) ;
* V_3 = F_5 ( * V_3 ) ;
break;
}
}
int main ( int V_21 , char * * V_22 )
{
static const unsigned V_23 [] = {
0 ,
V_13 ,
V_11 ,
V_20 ,
0 ,
V_17 ,
V_15 ,
0 ,
V_19 ,
} ;
static const char * const V_24 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_1 ,
L_5 ,
L_6 ,
L_1 ,
L_7 ,
} ;
int V_25 ;
int V_26 ;
printf ( L_8 ) ;
printf ( L_9 ) ;
for ( V_26 = 0 ; V_26 <= V_19 ; V_26 ++ ) {
for ( V_25 = 0 ; V_25 <= V_27 ; V_25 ++ ) {
double V_1 , V_2 , V_3 ;
if ( V_23 [ V_26 ] == 0 )
continue;
V_1 = V_28 [ V_25 ] . V_1 / 255.0 ;
V_2 = V_28 [ V_25 ] . V_2 / 255.0 ;
V_3 = V_28 [ V_25 ] . V_3 / 255.0 ;
F_6 ( V_26 , & V_1 , & V_2 , & V_3 ) ;
printf ( L_10 , V_24 [ V_26 ] , V_25 ,
( int ) ( V_1 * 4080 ) , ( int ) ( V_2 * 4080 ) , ( int ) ( V_3 * 4080 ) ) ;
}
}
printf ( L_11 ) ;
return 0 ;
}
