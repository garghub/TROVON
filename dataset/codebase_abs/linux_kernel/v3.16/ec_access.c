void F_1 ( char V_1 [] , int V_2 )
{
printf ( L_1 ) ;
printf ( L_2 , F_2 ( V_1 ) ) ;
printf ( L_3 , F_2 ( V_1 ) ) ;
printf ( L_4 , F_2 ( V_1 ) ) ;
puts ( L_5 ) ;
puts ( L_6 ) ;
puts ( L_7 ) ;
puts ( L_8 ) ;
puts ( L_9 ) ;
puts ( L_10 ) ;
puts ( L_11 ) ;
puts ( L_12 ) ;
exit ( V_2 ) ;
}
void F_3 ( int V_3 , char * V_4 [] )
{
int V_5 ;
while ( ( V_5 = F_4 ( V_3 , V_4 , L_13 ) ) != - 1 ) {
switch ( V_5 ) {
case 'r' :
if ( V_6 != - 1 )
F_1 ( V_4 [ 0 ] , V_7 ) ;
V_6 = 1 ;
break;
case 's' :
if ( V_6 != - 1 && V_6 != 1 )
F_1 ( V_4 [ 0 ] , V_7 ) ;
V_8 = atoi ( V_9 ) ;
if ( V_8 <= 0 ) {
V_8 = 0 ;
F_1 ( V_4 [ 0 ] , V_7 ) ;
printf ( L_14 , V_9 ) ;
}
break;
case 'b' :
if ( V_6 != - 1 )
F_1 ( V_4 [ 0 ] , V_7 ) ;
V_6 = 1 ;
V_10 = strtoul ( V_9 , NULL , 16 ) ;
break;
case 'w' :
if ( V_6 != - 1 )
F_1 ( V_4 [ 0 ] , V_7 ) ;
V_6 = 0 ;
V_11 = strtoul ( V_9 , NULL , 16 ) ;
break;
case 'v' :
V_12 = strtoul ( V_9 , NULL , 16 ) ;
break;
case 'h' :
F_1 ( V_4 [ 0 ] , V_13 ) ;
default:
fprintf ( V_14 , L_15 ) ;
F_1 ( V_4 [ 0 ] , V_7 ) ;
}
}
if ( V_6 == 0 ) {
if ( V_11 < 0 ||
V_11 >= V_15 ) {
fprintf ( V_14 , L_16
L_17 ,
V_11 , V_15 - 1 ) ;
F_1 ( V_4 [ 0 ] , V_7 ) ;
}
if ( V_12 < 0 ||
V_12 >= 255 ) {
fprintf ( V_14 , L_18
L_19 , V_11 ) ;
F_1 ( V_4 [ 0 ] , V_7 ) ;
}
}
if ( V_6 == 1 && V_10 != - 1 ) {
if ( V_10 < - 1 ||
V_10 >= V_15 ) {
fprintf ( V_14 , L_16
L_17 ,
V_10 , V_15 - 1 ) ;
F_1 ( V_4 [ 0 ] , V_7 ) ;
}
}
}
void F_5 ( int V_16 )
{
char V_17 [ V_15 ] ;
char V_18 [ V_15 ] ;
int V_19 , V_20 ;
V_20 = F_6 ( V_16 , V_17 , V_15 ) ;
if ( V_20 == - 1 )
F_7 ( V_7 , L_20 , V_21 ) ;
if ( V_20 != V_15 )
fprintf ( V_14 , L_21 , V_20 ) ;
printf ( L_22 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
if ( ( V_19 % 16 ) == 0 )
printf ( L_23 , V_19 ) ;
printf ( L_24 , ( V_22 ) V_17 [ V_19 ] ) ;
}
printf ( L_25 ) ;
if ( ! V_8 )
return;
printf ( L_25 ) ;
F_8 ( V_16 , 0 , V_23 ) ;
F_9 ( V_8 ) ;
V_20 = F_6 ( V_16 , V_18 , V_15 ) ;
if ( V_20 == - 1 )
F_7 ( V_7 , L_20 , V_21 ) ;
if ( V_20 != V_15 )
fprintf ( V_14 , L_21 , V_20 ) ;
printf ( L_22 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
if ( ( V_19 % 16 ) == 0 )
printf ( L_23 , V_19 ) ;
if ( V_17 [ V_19 ] == V_18 [ V_19 ] )
printf ( L_24 , ( V_22 ) V_18 [ V_19 ] ) ;
else
printf ( L_26 , ( V_22 ) V_18 [ V_19 ] ) ;
}
printf ( L_25 ) ;
}
void F_10 ( int V_16 , int V_24 )
{
V_22 V_17 ;
int error ;
error = F_8 ( V_16 , V_24 , V_23 ) ;
if ( error != V_24 )
F_7 ( V_7 , L_27 , V_24 ) ;
error = F_6 ( V_16 , & V_17 , 1 ) ;
if ( error != 1 )
F_7 ( V_7 , L_28 ,
V_24 , V_21 ) ;
printf ( L_29 , V_17 ) ;
return;
}
void F_11 ( int V_16 , int V_24 , V_22 V_25 )
{
int error ;
error = F_8 ( V_16 , V_24 , V_23 ) ;
if ( error != V_24 )
F_7 ( V_7 , L_27 , V_24 ) ;
error = F_12 ( V_16 , & V_25 , 1 ) ;
if ( error != 1 )
F_7 ( V_7 , L_30 ,
V_25 , V_24 ) ;
}
int main ( int V_3 , char * V_4 [] )
{
int V_26 = V_27 ;
int V_16 ;
F_3 ( V_3 , V_4 ) ;
if ( V_6 == 0 )
V_26 = V_28 ;
else if ( V_6 == 1 )
V_26 = V_27 ;
else
F_1 ( V_4 [ 0 ] , V_7 ) ;
V_16 = F_13 ( V_21 , V_26 ) ;
if ( V_16 == - 1 )
F_7 ( V_7 , L_31 , V_21 ) ;
if ( V_6 )
if ( V_10 == - 1 )
F_5 ( V_16 ) ;
else if ( V_10 < 0 ||
V_10 >= V_15 )
F_1 ( V_4 [ 0 ] , V_7 ) ;
else
F_10 ( V_16 , V_10 ) ;
else
F_11 ( V_16 , V_11 , V_12 ) ;
F_14 ( V_16 ) ;
exit ( V_13 ) ;
}
