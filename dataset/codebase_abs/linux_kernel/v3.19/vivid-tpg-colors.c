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
if ( V_8 < - 0.04045 )
return pow ( ( - V_8 + 0.055 ) / 1.055 , 2.4 ) ;
return ( V_8 <= 0.04045 ) ? V_8 / 12.92 : pow ( ( V_8 + 0.055 ) / 1.055 , 2.4 ) ;
}
static double F_3 ( double V_8 )
{
if ( V_8 <= - 0.0031308 )
return - 1.055 * pow ( - V_8 , 1.0 / 2.4 ) + 0.055 ;
if ( V_8 <= 0.0031308 )
return V_8 * 12.92 ;
return 1.055 * pow ( V_8 , 1.0 / 2.4 ) - 0.055 ;
}
static double F_4 ( double V_8 )
{
return ( V_8 <= 0.0228 ) ? V_8 * 4.0 : 1.1115 * pow ( V_8 , 0.45 ) - 0.1115 ;
}
static double F_5 ( double V_8 )
{
if ( V_8 <= - 0.018 )
return - 1.099 * pow ( - V_8 , 0.45 ) + 0.099 ;
return ( V_8 < 0.018 ) ? V_8 * 4.5 : 1.099 * pow ( V_8 , 0.45 ) - 0.099 ;
}
static double F_6 ( double V_8 )
{
return ( V_8 < 0.081 ) ? V_8 / 4.5 : pow ( ( V_8 + 0.099 ) / 1.099 , 1.0 / 0.45 ) ;
}
static double F_7 ( double V_8 )
{
return pow ( V_8 , 1.0 / 2.19921875 ) ;
}
static double F_8 ( double V_8 )
{
return F_5 ( F_2 ( V_8 ) ) ;
}
static void F_9 ( enum V_9 V_10 , double * V_1 , double * V_2 , double * V_3 )
{
int V_11 = 1 ;
switch ( V_10 ) {
case V_12 :
* V_1 = F_2 ( * V_1 ) ;
* V_2 = F_2 ( * V_2 ) ;
* V_3 = F_2 ( * V_3 ) ;
F_1 ( V_1 , V_2 , V_3 , V_13 ) ;
break;
case V_14 :
* V_1 = F_2 ( * V_1 ) ;
* V_2 = F_2 ( * V_2 ) ;
* V_3 = F_2 ( * V_3 ) ;
F_1 ( V_1 , V_2 , V_3 , V_15 ) ;
break;
case V_16 :
* V_1 = F_2 ( * V_1 ) ;
* V_2 = F_2 ( * V_2 ) ;
* V_3 = F_2 ( * V_3 ) ;
F_1 ( V_1 , V_2 , V_3 , V_17 ) ;
break;
case V_18 :
* V_1 = F_2 ( * V_1 ) ;
* V_2 = F_2 ( * V_2 ) ;
* V_3 = F_2 ( * V_3 ) ;
F_1 ( V_1 , V_2 , V_3 , V_19 ) ;
break;
case V_20 :
* V_1 = F_2 ( * V_1 ) ;
* V_2 = F_2 ( * V_2 ) ;
* V_3 = F_2 ( * V_3 ) ;
F_1 ( V_1 , V_2 , V_3 , V_21 ) ;
break;
case V_22 :
* V_1 = F_2 ( * V_1 ) ;
* V_2 = F_2 ( * V_2 ) ;
* V_3 = F_2 ( * V_3 ) ;
F_1 ( V_1 , V_2 , V_3 , V_23 ) ;
break;
case V_24 :
case V_25 :
default:
break;
}
if ( V_11 ) {
* V_1 = ( ( * V_1 ) < 0 ) ? 0 : ( ( ( * V_1 ) > 1 ) ? 1 : ( * V_1 ) ) ;
* V_2 = ( ( * V_2 ) < 0 ) ? 0 : ( ( ( * V_2 ) > 1 ) ? 1 : ( * V_2 ) ) ;
* V_3 = ( ( * V_3 ) < 0 ) ? 0 : ( ( ( * V_3 ) > 1 ) ? 1 : ( * V_3 ) ) ;
}
switch ( V_10 ) {
case V_12 :
* V_1 = F_4 ( * V_1 ) ;
* V_2 = F_4 ( * V_2 ) ;
* V_3 = F_4 ( * V_3 ) ;
break;
case V_14 :
case V_18 :
case V_16 :
case V_22 :
* V_1 = F_5 ( * V_1 ) ;
* V_2 = F_5 ( * V_2 ) ;
* V_3 = F_5 ( * V_3 ) ;
break;
case V_24 :
break;
case V_20 :
* V_1 = F_7 ( * V_1 ) ;
* V_2 = F_7 ( * V_2 ) ;
* V_3 = F_7 ( * V_3 ) ;
break;
case V_25 :
default:
* V_1 = F_8 ( * V_1 ) ;
* V_2 = F_8 ( * V_2 ) ;
* V_3 = F_8 ( * V_3 ) ;
break;
}
}
int main ( int V_26 , char * * V_27 )
{
static const unsigned V_28 [] = {
0 ,
V_14 ,
V_12 ,
V_25 ,
0 ,
V_18 ,
V_16 ,
0 ,
V_24 ,
V_20 ,
V_22 ,
} ;
static const char * const V_29 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_1 ,
L_5 ,
L_6 ,
L_1 ,
L_7 ,
L_8 ,
L_9 ,
} ;
int V_30 ;
int V_31 ;
printf ( L_10 ) ;
printf ( L_11 ) ;
for ( V_30 = 0 ; V_30 <= 255 * 16 ; V_30 ++ ) {
if ( V_30 % 16 == 0 )
printf ( L_12 ) ;
printf ( L_13 ,
( int ) ( 0.5 + 16.0 * 255.0 *
F_6 ( V_30 / ( 16.0 * 255.0 ) ) ) ,
V_30 % 16 == 15 || V_30 == 255 * 16 ? L_1 : L_14 ) ;
}
printf ( L_15 ) ;
printf ( L_10 ) ;
printf ( L_16 ) ;
for ( V_30 = 0 ; V_30 <= 255 * 16 ; V_30 ++ ) {
if ( V_30 % 16 == 0 )
printf ( L_12 ) ;
printf ( L_13 ,
( int ) ( 0.5 + 16.0 * 255.0 *
F_5 ( V_30 / ( 16.0 * 255.0 ) ) ) ,
V_30 % 16 == 15 || V_30 == 255 * 16 ? L_1 : L_14 ) ;
}
printf ( L_15 ) ;
printf ( L_10 ) ;
printf ( L_17 ) ;
for ( V_31 = 0 ; V_31 <= V_22 ; V_31 ++ ) {
for ( V_30 = 0 ; V_30 <= V_32 ; V_30 ++ ) {
double V_1 , V_2 , V_3 ;
if ( V_28 [ V_31 ] == 0 )
continue;
V_1 = V_33 [ V_30 ] . V_1 / 255.0 ;
V_2 = V_33 [ V_30 ] . V_2 / 255.0 ;
V_3 = V_33 [ V_30 ] . V_3 / 255.0 ;
F_9 ( V_31 , & V_1 , & V_2 , & V_3 ) ;
printf ( L_18 , V_29 [ V_31 ] , V_30 ,
( int ) ( V_1 * 4080 ) , ( int ) ( V_2 * 4080 ) , ( int ) ( V_3 * 4080 ) ) ;
}
}
printf ( L_19 ) ;
return 0 ;
}
