static void F_1 ( struct V_1 * V_2 )
{
static const char * const V_3 [] = {
[ V_4 ] = L_1 ,
[ V_5 ] = L_2 ,
[ V_6 ] = L_3 ,
[ V_7 ] = L_4 ,
[ V_8 ] = L_5 ,
[ V_9 ] = L_6 ,
[ V_10 ] = L_7 ,
} ;
switch ( V_2 -> type ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
printf ( L_8 , V_3 [ V_2 -> type ] ) ;
}
}
static void F_2 ( int V_11 , bool * V_12 )
{
struct V_1 V_2 ;
int V_13 ;
struct V_14 V_15 [ 1 ] ;
V_15 [ 0 ] . V_16 = V_11 ;
V_15 [ 0 ] . V_17 = V_18 ;
V_13 = F_3 ( V_15 , 1 , 0 ) ;
if ( V_13 && ( V_15 [ 0 ] . V_19 & V_18 ) ) {
V_13 = F_4 ( V_11 , & V_2 , sizeof( V_2 ) ) ;
if ( ! V_13 ) {
perror ( L_9 ) ;
return;
}
F_1 ( & V_2 ) ;
switch ( V_2 . type ) {
case V_8 :
if ( V_2 . V_20 . V_21 . V_22 & V_23 )
F_5 ( V_11 , NULL , 0 ) ;
else
F_4 ( V_11 , NULL , 0 ) ;
break;
case V_6 :
* V_12 = true ;
break;
case V_7 :
* V_12 = false ;
break;
default:
break;
}
}
}
int main ( int V_24 , char * V_25 [] )
{
int V_26 , V_13 ;
char * V_27 ;
int V_11 ;
int V_28 [ 2 ] ;
T_1 V_29 ;
int V_30 ;
T_2 V_31 ;
char * V_32 , * V_33 ;
struct V_34 * V_35 , * V_36 ;
int V_37 = 0 , V_38 = 0 ;
bool V_12 ;
if ( V_24 != 2 ) {
printf ( L_10 ) ;
return 1 ;
}
V_27 = malloc ( strlen ( V_25 [ 1 ] ) + 4 + 1 ) ;
if ( ! V_27 ) {
perror ( L_11 ) ;
return 1 ;
}
sprintf ( V_27 , L_12 , V_25 [ 1 ] ) ;
V_11 = F_6 ( V_27 , V_39 ) ;
if ( V_11 < 0 ) {
perror ( L_13 ) ;
return 1 ;
}
if ( F_5 ( V_11 , & V_40 , sizeof( V_40 ) ) < 0 ) {
perror ( L_14 ) ;
return 1 ;
}
if ( F_5 ( V_11 , & V_41 , sizeof( V_41 ) ) < 0 ) {
perror ( L_15 ) ;
return 1 ;
}
for ( V_26 = 0 ; V_26 < 2 ; ++ V_26 ) {
sprintf ( V_27 , L_16 , V_25 [ 1 ] , V_26 + 1 ) ;
V_28 [ V_26 ] = F_6 ( V_27 , V_39 ) ;
if ( V_28 [ V_26 ] < 0 ) {
printf ( L_17 , V_26 + 1 ,
strerror ( V_42 ) ) ;
return 1 ;
}
}
free ( V_27 ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
if ( F_7 ( 2 , & V_29 ) < 0 ) {
perror ( L_18 ) ;
return 1 ;
}
V_30 = F_8 ( 0 , 0 ) ;
if ( V_30 < 0 ) {
perror ( L_19 ) ;
return 1 ;
}
V_32 = malloc ( V_43 ) ;
V_33 = malloc ( V_43 ) ;
V_35 = malloc ( sizeof( * V_35 ) ) ;
V_36 = malloc ( sizeof( * V_36 ) ) ;
while ( 1 ) {
F_9 ( & V_31 ) ;
F_10 ( V_11 , & V_31 ) ;
F_10 ( V_30 , & V_31 ) ;
V_13 = F_11 ( ( ( V_11 > V_30 ) ? V_11 : V_30 ) + 1 ,
& V_31 , NULL , NULL , NULL ) ;
if ( V_13 < 0 ) {
if ( V_42 == V_44 )
continue;
perror ( L_20 ) ;
break;
}
if ( F_12 ( V_11 , & V_31 ) )
F_2 ( V_11 , & V_12 ) ;
if ( ! V_12 )
continue;
if ( F_12 ( V_30 , & V_31 ) ) {
T_3 V_45 ;
V_13 = F_4 ( V_30 , & V_45 , sizeof( V_45 ) ) ;
if ( V_13 < 0 ) {
perror ( L_21 ) ;
break;
}
struct V_46 V_47 [ 2 ] ;
V_13 = F_13 ( V_29 , 1 , 2 , V_47 , NULL ) ;
for ( V_26 = 0 ; V_26 < V_13 ; ++ V_26 ) {
if ( V_47 [ V_26 ] . V_48 -> V_49 == V_28 [ 0 ] ) {
printf ( L_22 , V_47 [ V_26 ] . V_50 ) ;
V_37 = 0 ;
} else if ( V_47 [ V_26 ] . V_48 -> V_49 == V_28 [ 1 ] ) {
printf ( L_23 , V_47 [ V_26 ] . V_50 ) ;
V_38 = 0 ;
}
}
}
if ( ! V_37 ) {
F_14 ( V_35 , V_28 [ 0 ] , V_32 , V_43 , 0 ) ;
V_35 -> V_20 . V_51 . V_52 |= V_53 ;
V_35 -> V_20 . V_51 . V_54 = V_30 ;
V_13 = F_15 ( V_29 , 1 , & V_35 ) ;
if ( V_13 >= 0 ) {
V_37 = 1 ;
printf ( L_24 ) ;
} else
perror ( L_25 ) ;
}
if ( ! V_38 ) {
F_16 ( V_36 , V_28 [ 1 ] , V_33 , V_43 , 0 ) ;
V_36 -> V_20 . V_51 . V_52 |= V_53 ;
V_36 -> V_20 . V_51 . V_54 = V_30 ;
V_13 = F_15 ( V_29 , 1 , & V_36 ) ;
if ( V_13 >= 0 ) {
V_38 = 1 ;
printf ( L_26 ) ;
} else
perror ( L_25 ) ;
}
}
F_17 ( V_29 ) ;
free ( V_32 ) ;
free ( V_33 ) ;
free ( V_35 ) ;
free ( V_36 ) ;
for ( V_26 = 0 ; V_26 < 2 ; ++ V_26 )
F_18 ( V_28 [ V_26 ] ) ;
F_18 ( V_11 ) ;
return 0 ;
}
