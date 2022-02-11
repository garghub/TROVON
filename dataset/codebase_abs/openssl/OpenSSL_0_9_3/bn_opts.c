int main ( int V_1 , char * * V_2 )
{
T_1 V_3 ;
T_2 * V_4 ;
int V_5 = 0 , V_6 ;
char * V_7 ;
int type = V_8 ;
V_4 = F_1 () ;
V_3 . V_4 = NULL ;
V_3 . V_9 = F_2 () ;
F_3 ( & V_3 . V_10 ) ;
F_3 ( & V_3 . V_11 ) ;
F_3 ( & V_3 . V_12 ) ;
F_3 ( & V_3 . V_13 ) ;
F_3 ( & V_3 . V_14 ) ;
V_3 . V_15 = 0 ;
for (; ; )
{
if ( V_1 > 1 )
{
if ( V_2 [ 1 ] [ 0 ] == '-' )
{
switch( V_2 [ 1 ] [ 1 ] )
{
case 'e' : type = V_8 ; break;
case 'm' : type = V_16 ; break;
case 's' : type = V_17 ; break;
case 'l' : type = V_18 ; break;
case 'h' : type = V_19 ; break;
case 'r' : type = V_20 ; break;
default:
fprintf ( V_21 , L_1 ) ;
exit ( 1 ) ;
}
}
else
{
V_5 = atoi ( V_2 [ 1 ] ) ;
}
V_1 -- ;
V_2 ++ ;
}
else
break;
}
if ( V_5 == 0 )
V_5 = V_22 ;
printf ( L_2 , V_5 ) ;
F_4 ( & V_3 . V_11 , V_5 , 1 , 0 ) ;
F_4 ( & V_3 . V_12 , V_5 , 1 , 0 ) ;
F_4 ( & V_3 . V_13 , V_5 , 1 , 1 ) ;
F_5 ( & V_3 . V_11 , & V_3 . V_11 , & V_3 . V_13 , V_3 . V_9 ) ;
F_5 ( & V_3 . V_12 , & V_3 . V_12 , & V_3 . V_13 , V_3 . V_9 ) ;
V_3 . V_15 = ( V_3 . V_11 . V_23 + 1 ) / 2 ;
F_6 ( & V_3 . V_14 , & V_3 . V_11 , & V_3 . V_12 , V_3 . V_9 ) ;
V_3 . V_14 . V_23 = V_3 . V_11 . V_23 ;
switch( type )
{
case V_8 :
V_3 . V_7 = L_3 ;
V_3 . V_24 = V_25 ;
V_3 . V_4 = V_4 ;
break;
case V_16 :
V_3 . V_7 = L_4 ;
V_3 . V_24 = V_26 ;
break;
case V_17 :
V_3 . V_7 = L_5 ;
V_3 . V_24 = V_27 ;
break;
case V_18 :
V_3 . V_7 = L_6 ;
V_3 . V_24 = V_28 ;
break;
case V_19 :
V_3 . V_7 = L_7 ;
V_3 . V_24 = V_29 ;
break;
case V_20 :
V_3 . V_7 = L_8 ;
V_3 . V_24 = V_30 ;
V_3 . V_4 = V_4 ;
break;
default:
fprintf ( V_21 , L_1 ) ;
exit ( 1 ) ;
}
V_6 = F_7 ( V_31 , & V_3 ) ;
F_8 ( V_6 , & V_3 ) ;
}
void F_8 ( int V_6 , T_1 * V_3 )
{
char * V_32 , * V_33 ;
int V_34 , V_35 , V_36 ;
double V_37 ;
V_32 = F_9 () ;
V_33 = F_9 () ;
V_36 = F_10 ( ( V_38 ) F_11 ( & ( V_3 -> V_13 ) ) ) -
F_10 ( V_39 ) + 2 ;
for ( V_34 = V_36 - 1 ; V_34 >= 0 ; V_34 -- )
{
if ( V_34 == 1 ) continue;
F_12 ( V_34 , V_34 , V_34 , 1 ) ;
if ( V_3 -> V_4 != NULL )
F_13 ( V_3 -> V_4 , & ( V_3 -> V_13 ) , V_3 -> V_9 ) ;
printf ( L_9 ,
( 1 << V_34 ) * V_39 , V_34 ,
F_14 ( 0 ) ,
F_14 ( 1 ) ,
F_14 ( 2 ) ,
F_14 ( 3 ) ) ;
fflush ( stdout ) ;
F_15 ( V_32 ) ;
V_3 -> V_24 ( V_6 , V_3 ) ;
F_15 ( V_33 ) ;
V_37 = F_16 ( V_32 , V_33 ) ;
printf ( L_10 ,
( double ) V_37 / V_6 , V_6 , V_37 ) ;
}
}
int F_7 ( int V_40 , T_1 * V_3 )
{
char * V_32 , * V_33 ;
int V_34 , V_35 ;
double V_37 ;
if ( V_3 -> V_4 != NULL )
F_13 ( V_3 -> V_4 , & ( V_3 -> V_13 ) , V_3 -> V_9 ) ;
V_32 = F_9 () ;
V_33 = F_9 () ;
V_34 = 1 ;
for (; ; )
{
if ( V_41 )
printf ( L_11 , V_3 -> V_7 , V_34 ) ;
F_15 ( V_32 ) ;
V_3 -> V_24 ( V_34 , V_3 ) ;
F_15 ( V_33 ) ;
V_37 = F_16 ( V_32 , V_33 ) ;
if ( V_37 < 0.01 ) V_34 *= 100 ;
else if ( V_37 < 0.1 ) V_34 *= 10 ;
else if ( V_37 > ( double ) V_40 ) break;
else
{
V_34 = ( int ) ( 1.0 * V_34 * V_40 / V_37 ) ;
break;
}
}
if ( V_41 )
printf ( L_12 , V_34 ) ;
return ( V_34 ) ;
}
void V_25 ( int V_6 , T_1 * V_3 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_6 ; V_34 ++ )
F_17 ( & ( V_3 -> V_10 ) , & ( V_3 -> V_11 ) , & ( V_3 -> V_12 ) , & ( V_3 -> V_13 ) ,
V_3 -> V_9 , V_3 -> V_4 ) ;
}
void V_26 ( int V_6 , T_1 * V_3 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_6 ; V_34 ++ )
F_6 ( & ( V_3 -> V_10 ) , & ( V_3 -> V_11 ) , & ( V_3 -> V_12 ) , V_3 -> V_9 ) ;
}
void V_27 ( int V_6 , T_1 * V_3 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_6 ; V_34 ++ )
F_18 ( & ( V_3 -> V_10 ) , & ( V_3 -> V_11 ) , V_3 -> V_9 ) ;
}
void V_28 ( int V_6 , T_1 * V_3 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_6 ; V_34 ++ )
F_19 ( & ( V_3 -> V_10 ) , & ( V_3 -> V_11 ) , & ( V_3 -> V_12 ) , V_3 -> V_15 , V_3 -> V_9 ) ;
}
void V_29 ( int V_6 , T_1 * V_3 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_6 ; V_34 ++ )
F_19 ( & ( V_3 -> V_10 ) , & ( V_3 -> V_11 ) , & ( V_3 -> V_12 ) , & ( V_3 -> V_14 ) , V_3 -> V_15 , V_3 -> V_9 ) ;
}
void V_30 ( int V_6 , T_1 * V_3 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_6 ; V_34 ++ )
F_20 ( & ( V_3 -> V_10 ) , & ( V_3 -> V_11 ) , V_3 -> V_4 , V_3 -> V_9 ) ;
}
