int main ( int V_1 , char * * V_2 )
{
int V_3 ;
int V_4 , V_5 , V_6 = 0 ;
char V_7 [ 256 ] ;
struct V_8 V_9 ;
struct V_10 V_11 ;
char * V_12 = L_1 ;
if ( V_1 > 1 )
V_12 = V_2 [ 1 ] ;
V_3 = F_1 ( V_12 , V_13 | V_14 ) ;
if ( V_3 < 0 ) {
perror ( L_2 ) ;
return 1 ;
}
memset ( & V_9 , 0x0 , sizeof( V_9 ) ) ;
memset ( & V_11 , 0x0 , sizeof( V_11 ) ) ;
memset ( V_7 , 0x0 , sizeof( V_7 ) ) ;
V_5 = F_2 ( V_3 , V_15 , & V_6 ) ;
if ( V_5 < 0 )
perror ( L_3 ) ;
else
printf ( L_4 , V_6 ) ;
V_9 . V_16 = V_6 ;
V_5 = F_2 ( V_3 , V_17 , & V_9 ) ;
if ( V_5 < 0 ) {
perror ( L_5 ) ;
} else {
printf ( L_6 ) ;
for ( V_4 = 0 ; V_4 < V_9 . V_16 ; V_4 ++ )
printf ( L_7 , V_9 . V_18 [ V_4 ] ) ;
puts ( L_8 ) ;
}
V_5 = F_2 ( V_3 , F_3 ( 256 ) , V_7 ) ;
if ( V_5 < 0 )
perror ( L_9 ) ;
else
printf ( L_10 , V_7 ) ;
V_5 = F_2 ( V_3 , F_4 ( 256 ) , V_7 ) ;
if ( V_5 < 0 )
perror ( L_11 ) ;
else
printf ( L_12 , V_7 ) ;
V_5 = F_2 ( V_3 , V_19 , & V_11 ) ;
if ( V_5 < 0 ) {
perror ( L_13 ) ;
} else {
printf ( L_14 ) ;
printf ( L_15 ,
V_11 . V_20 , F_5 ( V_11 . V_20 ) ) ;
printf ( L_16 , V_11 . V_21 ) ;
printf ( L_17 , V_11 . V_22 ) ;
}
V_7 [ 0 ] = 0x9 ;
V_7 [ 1 ] = 0xff ;
V_7 [ 2 ] = 0xff ;
V_7 [ 3 ] = 0xff ;
V_5 = F_2 ( V_3 , F_6 ( 4 ) , V_7 ) ;
if ( V_5 < 0 )
perror ( L_18 ) ;
else
printf ( L_19 , V_5 ) ;
V_7 [ 0 ] = 0x9 ;
V_5 = F_2 ( V_3 , F_7 ( 256 ) , V_7 ) ;
if ( V_5 < 0 ) {
perror ( L_20 ) ;
} else {
printf ( L_19 , V_5 ) ;
printf ( L_21 ) ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
printf ( L_7 , V_7 [ V_4 ] ) ;
puts ( L_8 ) ;
}
V_7 [ 0 ] = 0x1 ;
V_7 [ 1 ] = 0x77 ;
V_5 = F_8 ( V_3 , V_7 , 2 ) ;
if ( V_5 < 0 ) {
printf ( L_22 , V_23 ) ;
perror ( L_23 ) ;
} else {
printf ( L_24 , V_5 ) ;
}
V_5 = F_9 ( V_3 , V_7 , 16 ) ;
if ( V_5 < 0 ) {
perror ( L_25 ) ;
} else {
printf ( L_26 , V_5 ) ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
printf ( L_7 , V_7 [ V_4 ] ) ;
puts ( L_8 ) ;
}
F_10 ( V_3 ) ;
return 0 ;
}
const char *
F_5 ( int V_24 )
{
switch ( V_24 ) {
case V_25 :
return L_27 ;
break;
case V_26 :
return L_28 ;
break;
case V_27 :
return L_29 ;
break;
case V_28 :
return L_30 ;
break;
default:
return L_31 ;
break;
}
}
