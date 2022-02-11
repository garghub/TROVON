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
return pow ( V_8 , 1.0 / 2.6 ) ;
}
static double F_9 ( double V_8 )
{
const double V_9 = ( 2610.0 / 4096.0 ) / 4.0 ;
const double V_10 = 128.0 * 2523.0 / 4096.0 ;
const double V_11 = 3424.0 / 4096.0 ;
const double V_12 = 32.0 * 2413.0 / 4096.0 ;
const double V_13 = 32.0 * 2392.0 / 4096.0 ;
V_8 /= 100.0 ;
V_8 = pow ( V_8 , V_9 ) ;
return pow ( ( V_11 + V_12 * V_8 ) / ( 1 + V_13 * V_8 ) , V_10 ) ;
}
static double F_10 ( double V_8 )
{
return F_5 ( F_2 ( V_8 ) ) ;
}
static void F_11 ( enum V_14 V_15 , enum V_16 V_17 ,
double * V_1 , double * V_2 , double * V_3 )
{
int V_18 = 1 ;
* V_1 = F_2 ( * V_1 ) ;
* V_2 = F_2 ( * V_2 ) ;
* V_3 = F_2 ( * V_3 ) ;
switch ( V_15 ) {
case V_19 :
F_1 ( V_1 , V_2 , V_3 , V_20 ) ;
break;
case V_21 :
F_1 ( V_1 , V_2 , V_3 , V_22 ) ;
break;
case V_23 :
F_1 ( V_1 , V_2 , V_3 , V_24 ) ;
break;
case V_25 :
F_1 ( V_1 , V_2 , V_3 , V_26 ) ;
break;
case V_27 :
F_1 ( V_1 , V_2 , V_3 , V_28 ) ;
break;
case V_29 :
F_1 ( V_1 , V_2 , V_3 , V_30 ) ;
break;
case V_31 :
F_1 ( V_1 , V_2 , V_3 , V_32 ) ;
break;
case V_33 :
case V_34 :
break;
default:
break;
}
if ( V_18 ) {
* V_1 = ( ( * V_1 ) < 0 ) ? 0 : ( ( ( * V_1 ) > 1 ) ? 1 : ( * V_1 ) ) ;
* V_2 = ( ( * V_2 ) < 0 ) ? 0 : ( ( ( * V_2 ) > 1 ) ? 1 : ( * V_2 ) ) ;
* V_3 = ( ( * V_3 ) < 0 ) ? 0 : ( ( ( * V_3 ) > 1 ) ? 1 : ( * V_3 ) ) ;
}
switch ( V_17 ) {
case V_35 :
* V_1 = F_5 ( * V_1 ) ;
* V_2 = F_5 ( * V_2 ) ;
* V_3 = F_5 ( * V_3 ) ;
break;
case V_36 :
* V_1 = F_3 ( * V_1 ) ;
* V_2 = F_3 ( * V_2 ) ;
* V_3 = F_3 ( * V_3 ) ;
break;
case V_37 :
* V_1 = F_7 ( * V_1 ) ;
* V_2 = F_7 ( * V_2 ) ;
* V_3 = F_7 ( * V_3 ) ;
break;
case V_38 :
* V_1 = F_8 ( * V_1 ) ;
* V_2 = F_8 ( * V_2 ) ;
* V_3 = F_8 ( * V_3 ) ;
break;
case V_39 :
* V_1 = F_9 ( * V_1 ) ;
* V_2 = F_9 ( * V_2 ) ;
* V_3 = F_9 ( * V_3 ) ;
break;
case V_40 :
* V_1 = F_4 ( * V_1 ) ;
* V_2 = F_4 ( * V_2 ) ;
* V_3 = F_4 ( * V_3 ) ;
break;
case V_41 :
break;
}
}
int main ( int V_42 , char * * V_43 )
{
static const unsigned V_44 [] = {
0 ,
V_21 ,
V_19 ,
V_34 ,
0 ,
V_25 ,
V_23 ,
0 ,
V_33 ,
V_27 ,
V_29 ,
0 ,
V_31 ,
} ;
static const char * const V_45 [] = {
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
L_1 ,
L_10 ,
} ;
static const char * const V_46 [] = {
L_1 ,
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
L_17 ,
} ;
int V_47 ;
int V_48 ;
int V_49 ;
printf ( L_18 ) ;
printf ( L_19 ) ;
for ( V_47 = 0 ; V_47 <= 255 * 16 ; V_47 ++ ) {
if ( V_47 % 16 == 0 )
printf ( L_20 ) ;
printf ( L_21 ,
( int ) ( 0.5 + 16.0 * 255.0 *
F_6 ( V_47 / ( 16.0 * 255.0 ) ) ) ,
V_47 % 16 == 15 || V_47 == 255 * 16 ? L_1 : L_22 ) ;
}
printf ( L_23 ) ;
printf ( L_18 ) ;
printf ( L_24 ) ;
for ( V_47 = 0 ; V_47 <= 255 * 16 ; V_47 ++ ) {
if ( V_47 % 16 == 0 )
printf ( L_20 ) ;
printf ( L_21 ,
( int ) ( 0.5 + 16.0 * 255.0 *
F_5 ( V_47 / ( 16.0 * 255.0 ) ) ) ,
V_47 % 16 == 15 || V_47 == 255 * 16 ? L_1 : L_22 ) ;
}
printf ( L_23 ) ;
printf ( L_18 ) ;
printf ( L_25 ) ;
for ( V_49 = 0 ; V_49 <= V_31 ; V_49 ++ ) {
for ( V_48 = 1 ; V_48 <= V_39 ; V_48 ++ ) {
for ( V_47 = 0 ; V_47 <= V_50 ; V_47 ++ ) {
double V_1 , V_2 , V_3 ;
if ( V_44 [ V_49 ] == 0 )
continue;
V_1 = V_51 [ V_47 ] . V_1 / 255.0 ;
V_2 = V_51 [ V_47 ] . V_2 / 255.0 ;
V_3 = V_51 [ V_47 ] . V_3 / 255.0 ;
F_11 ( V_49 , V_48 , & V_1 , & V_2 , & V_3 ) ;
printf ( L_26 ,
V_45 [ V_49 ] ,
V_46 [ V_48 ] , V_47 ,
( int ) ( V_1 * 4080 ) , ( int ) ( V_2 * 4080 ) , ( int ) ( V_3 * 4080 ) ) ;
}
}
}
printf ( L_27 ) ;
return 0 ;
}
