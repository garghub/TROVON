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
static struct V_4 V_5 [] = {
F_5 ( V_6 , 1 ) ,
F_6 () ,
} ;
T_1 V_7 = sizeof( V_5 ) / sizeof( struct V_4 ) ;
if ( V_3 ) {
assert ( ! F_7 ( ( char * ) V_3 ) ) ;
return V_8 [ 0 ] ;
} else {
return F_8 ( V_9 ,
V_5 , V_7 , L_11 , 0 ,
V_10 , V_11 ) ;
}
}
static int F_9 ( const char * V_12 , V_2 V_13 , V_2 V_14 ,
V_2 V_15 )
{
int V_16 , V_17 ;
if ( V_13 & V_18 ) {
V_16 = F_2 () ;
printf ( L_12 , V_16 , strerror ( V_19 ) ) ;
assert ( V_16 > 0 ) ;
V_17 = F_10 ( V_16 , V_12 ) ;
printf ( L_13 , V_17 , strerror ( V_19 ) ) ;
assert ( V_17 == 0 ) ;
} else {
V_16 = F_11 ( V_12 ) ;
printf ( L_14 , V_16 , strerror ( V_19 ) ) ;
assert ( V_16 > 0 ) ;
}
if ( ( V_13 & V_20 ) == V_20 ) {
V_17 = F_12 ( V_16 , & V_14 , & V_15 , 0 ) ;
printf ( L_15 , V_16 , V_14 , V_15 ,
V_17 , strerror ( V_19 ) ) ;
assert ( V_17 == 0 ) ;
} else if ( V_13 & V_21 ) {
V_17 = F_13 ( V_16 , & V_14 , & V_15 ) ;
printf ( L_16 , V_16 , V_14 , V_15 ,
V_17 , strerror ( V_19 ) ) ;
assert ( V_17 == 0 ) ;
}
return 0 ;
}
static int F_14 ( const char * V_12 , V_2 V_13 , const char * V_3 )
{
int V_16 , V_22 , V_17 ;
if ( V_13 & V_18 ) {
V_16 = F_4 ( V_3 ) ;
printf ( L_17 , V_16 , strerror ( V_19 ) ) ;
assert ( V_16 > 0 ) ;
V_17 = F_10 ( V_16 , V_12 ) ;
printf ( L_13 , V_17 , strerror ( V_19 ) ) ;
assert ( V_17 == 0 ) ;
} else {
V_16 = F_11 ( V_12 ) ;
printf ( L_14 , V_16 , strerror ( V_19 ) ) ;
assert ( V_16 > 0 ) ;
}
V_22 = F_15 ( L_18 ) ;
assert ( V_22 > 0 ) ;
V_17 = F_16 ( V_22 , V_23 , V_24 , & V_16 , sizeof( V_16 ) ) ;
printf ( L_19 , V_22 , V_16 ,
V_17 , strerror ( V_19 ) ) ;
assert ( V_17 == 0 ) ;
return 0 ;
}
int main ( int V_25 , char * * V_26 )
{
const char * V_12 = NULL , * V_3 = NULL ;
V_2 V_14 = 0 , V_15 = 0 , V_13 = 0 ;
int V_27 , V_28 = V_29 ;
while ( ( V_27 = F_17 ( V_25 , V_26 , L_20 ) ) != - 1 ) {
switch ( V_27 ) {
case 'F' :
V_12 = V_30 ;
break;
case 'P' :
V_13 |= V_18 ;
break;
case 'G' :
V_13 |= V_31 ;
break;
case 'm' :
V_28 = V_32 ;
break;
case 'k' :
V_14 = strtoul ( V_30 , NULL , 0 ) ;
V_13 |= V_21 ;
break;
case 'v' :
V_15 = strtoul ( V_30 , NULL , 0 ) ;
V_13 |= V_33 ;
break;
case 'p' :
V_28 = V_34 ;
break;
case 'o' :
V_3 = V_30 ;
break;
default:
goto V_35;
}
}
if ( ! ( V_13 & V_36 ) || ! V_12 )
goto V_35;
switch ( V_28 ) {
case V_32 :
return F_9 ( V_12 , V_13 , V_14 , V_15 ) ;
case V_34 :
return F_14 ( V_12 , V_13 , V_3 ) ;
}
V_35:
F_1 () ;
return - 1 ;
}
