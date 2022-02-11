static void F_1 ( void )
{
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 ) ;
printf ( L_4 ) ;
printf ( L_5 ) ;
printf ( L_6 ) ;
printf ( L_7 ) ;
printf ( L_8 ) ;
printf ( L_9 ) ;
printf ( L_10 ) ;
}
static int F_2 ( void )
{
return F_3 ( V_1 , sizeof( V_2 ) ,
sizeof( V_2 ) , 1024 , 0 ) ;
}
static int F_4 ( const char * V_3 )
{
static const struct V_4 V_5 [] = {
F_5 ( V_6 , 1 ) ,
F_6 () ,
} ;
if ( V_3 ) {
assert ( ! F_7 ( ( char * ) V_3 ) ) ;
return V_7 [ 0 ] ;
} else {
return F_8 ( V_8 ,
V_5 , sizeof( V_5 ) , L_11 , 0 ) ;
}
}
static int F_9 ( const char * V_9 , V_2 V_10 , V_2 V_11 ,
V_2 V_12 )
{
int V_13 , V_14 ;
if ( V_10 & V_15 ) {
V_13 = F_2 () ;
printf ( L_12 , V_13 , strerror ( V_16 ) ) ;
assert ( V_13 > 0 ) ;
V_14 = F_10 ( V_13 , V_9 ) ;
printf ( L_13 , V_14 , strerror ( V_16 ) ) ;
assert ( V_14 == 0 ) ;
} else {
V_13 = F_11 ( V_9 ) ;
printf ( L_14 , V_13 , strerror ( V_16 ) ) ;
assert ( V_13 > 0 ) ;
}
if ( ( V_10 & V_17 ) == V_17 ) {
V_14 = F_12 ( V_13 , & V_11 , & V_12 , 0 ) ;
printf ( L_15 , V_13 , V_11 , V_12 ,
V_14 , strerror ( V_16 ) ) ;
assert ( V_14 == 0 ) ;
} else if ( V_10 & V_18 ) {
V_14 = F_13 ( V_13 , & V_11 , & V_12 ) ;
printf ( L_16 , V_13 , V_11 , V_12 ,
V_14 , strerror ( V_16 ) ) ;
assert ( V_14 == 0 ) ;
}
return 0 ;
}
static int F_14 ( const char * V_9 , V_2 V_10 , const char * V_3 )
{
int V_13 , V_19 , V_14 ;
if ( V_10 & V_15 ) {
V_13 = F_4 ( V_3 ) ;
printf ( L_17 , V_13 , strerror ( V_16 ) ) ;
assert ( V_13 > 0 ) ;
V_14 = F_10 ( V_13 , V_9 ) ;
printf ( L_13 , V_14 , strerror ( V_16 ) ) ;
assert ( V_14 == 0 ) ;
} else {
V_13 = F_11 ( V_9 ) ;
printf ( L_14 , V_13 , strerror ( V_16 ) ) ;
assert ( V_13 > 0 ) ;
}
V_19 = F_15 ( L_18 ) ;
assert ( V_19 > 0 ) ;
V_14 = F_16 ( V_19 , V_20 , V_21 , & V_13 , sizeof( V_13 ) ) ;
printf ( L_19 , V_19 , V_13 ,
V_14 , strerror ( V_16 ) ) ;
assert ( V_14 == 0 ) ;
return 0 ;
}
int main ( int V_22 , char * * V_23 )
{
const char * V_9 = NULL , * V_3 = NULL ;
V_2 V_11 = 0 , V_12 = 0 , V_10 = 0 ;
int V_24 , V_25 = V_26 ;
while ( ( V_24 = F_17 ( V_22 , V_23 , L_20 ) ) != - 1 ) {
switch ( V_24 ) {
case 'F' :
V_9 = V_27 ;
break;
case 'P' :
V_10 |= V_15 ;
break;
case 'G' :
V_10 |= V_28 ;
break;
case 'm' :
V_25 = V_29 ;
break;
case 'k' :
V_11 = strtoul ( V_27 , NULL , 0 ) ;
V_10 |= V_18 ;
break;
case 'v' :
V_12 = strtoul ( V_27 , NULL , 0 ) ;
V_10 |= V_30 ;
break;
case 'p' :
V_25 = V_31 ;
break;
case 'o' :
V_3 = V_27 ;
break;
default:
goto V_32;
}
}
if ( ! ( V_10 & V_33 ) || ! V_9 )
goto V_32;
switch ( V_25 ) {
case V_29 :
return F_9 ( V_9 , V_10 , V_11 , V_12 ) ;
case V_31 :
return F_14 ( V_9 , V_10 , V_3 ) ;
}
V_32:
F_1 () ;
return - 1 ;
}
