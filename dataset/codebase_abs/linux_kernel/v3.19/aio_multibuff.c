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
int V_13 ;
struct V_1 V_2 ;
V_13 = F_3 ( V_11 , & V_2 , sizeof( V_2 ) ) ;
if ( ! V_13 ) {
perror ( L_9 ) ;
return;
}
F_1 ( & V_2 ) ;
switch ( V_2 . type ) {
case V_8 :
if ( V_2 . V_14 . V_15 . V_16 & V_17 )
F_4 ( V_11 , NULL , 0 ) ;
else
F_3 ( V_11 , NULL , 0 ) ;
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
void F_5 ( struct V_18 * V_19 , unsigned V_20 , unsigned V_21 )
{
unsigned V_22 ;
V_19 -> V_23 = malloc ( V_20 * sizeof( * V_19 -> V_23 ) ) ;
V_19 -> V_24 = malloc ( V_20 * sizeof( * V_19 -> V_24 ) ) ;
V_19 -> V_25 = V_20 ;
V_19 -> V_21 = V_21 ;
V_19 -> V_26 = 0 ;
for ( V_22 = 0 ; V_22 < V_20 ; ++ V_22 ) {
V_19 -> V_23 [ V_22 ] = malloc ( V_21 * sizeof( * * V_19 -> V_23 ) ) ;
V_19 -> V_24 [ V_22 ] = malloc ( sizeof( * * V_19 -> V_24 ) ) ;
}
V_19 -> V_25 = V_20 ;
}
void F_6 ( struct V_18 * V_19 )
{
unsigned V_22 ;
for ( V_22 = 0 ; V_22 < V_19 -> V_25 ; ++ V_22 ) {
free ( V_19 -> V_23 [ V_22 ] ) ;
free ( V_19 -> V_24 [ V_22 ] ) ;
}
free ( V_19 -> V_23 ) ;
free ( V_19 -> V_24 ) ;
}
int main ( int V_27 , char * V_28 [] )
{
int V_13 ;
unsigned V_22 , V_29 ;
char * V_30 ;
int V_11 , V_31 ;
T_1 V_32 ;
int V_33 ;
T_2 V_34 ;
struct V_18 V_19 [ 2 ] ;
int V_35 = 0 ;
bool V_12 ;
if ( V_27 != 2 ) {
printf ( L_10 ) ;
return 1 ;
}
V_30 = malloc ( strlen ( V_28 [ 1 ] ) + 4 + 1 ) ;
if ( ! V_30 ) {
perror ( L_11 ) ;
return 1 ;
}
sprintf ( V_30 , L_12 , V_28 [ 1 ] ) ;
V_11 = F_7 ( V_30 , V_36 ) ;
if ( V_11 < 0 ) {
perror ( L_13 ) ;
return 1 ;
}
if ( F_4 ( V_11 , & V_37 , sizeof( V_37 ) ) < 0 ) {
perror ( L_14 ) ;
return 1 ;
}
if ( F_4 ( V_11 , & V_38 , sizeof( V_38 ) ) < 0 ) {
perror ( L_15 ) ;
return 1 ;
}
sprintf ( V_30 , L_16 , V_28 [ 1 ] ) ;
V_31 = F_7 ( V_30 , V_36 ) ;
if ( V_31 < 0 ) {
perror ( L_17 ) ;
return 1 ;
}
free ( V_30 ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
if ( F_8 ( V_39 , & V_32 ) < 0 ) {
perror ( L_18 ) ;
return 1 ;
}
V_33 = F_9 ( 0 , 0 ) ;
if ( V_33 < 0 ) {
perror ( L_19 ) ;
return 1 ;
}
for ( V_22 = 0 ; V_22 < sizeof( V_19 ) / sizeof( * V_19 ) ; ++ V_22 )
F_5 ( & V_19 [ V_22 ] , V_40 , V_41 ) ;
while ( 1 ) {
F_10 ( & V_34 ) ;
F_11 ( V_11 , & V_34 ) ;
F_11 ( V_33 , & V_34 ) ;
V_13 = F_12 ( ( ( V_11 > V_33 ) ? V_11 : V_33 ) + 1 ,
& V_34 , NULL , NULL , NULL ) ;
if ( V_13 < 0 ) {
if ( V_42 == V_43 )
continue;
perror ( L_20 ) ;
break;
}
if ( F_13 ( V_11 , & V_34 ) )
F_2 ( V_11 , & V_12 ) ;
if ( ! V_12 )
continue;
for ( V_22 = 0 ; V_22 < sizeof( V_19 ) / sizeof( * V_19 ) ; ++ V_22 ) {
if ( V_19 [ V_22 ] . V_26 )
continue;
for ( V_29 = 0 ; V_29 < V_19 [ V_22 ] . V_25 ; ++ V_29 ) {
F_14 ( V_19 [ V_22 ] . V_24 [ V_29 ] , V_31 ,
V_19 [ V_22 ] . V_23 [ V_29 ] ,
V_19 [ V_22 ] . V_21 , 0 ) ;
V_19 [ V_22 ] . V_24 [ V_29 ] -> V_14 . V_44 . V_45 |= V_46 ;
V_19 [ V_22 ] . V_24 [ V_29 ] -> V_14 . V_44 . V_47 = V_33 ;
}
V_13 = F_15 ( V_32 , V_19 [ V_22 ] . V_25 , V_19 [ V_22 ] . V_24 ) ;
if ( V_13 >= 0 ) {
V_19 [ V_22 ] . V_26 = V_13 ;
printf ( L_21 , V_13 , V_22 ) ;
} else
perror ( L_22 ) ;
}
if ( ! F_13 ( V_33 , & V_34 ) )
continue;
T_3 V_48 ;
V_13 = F_3 ( V_33 , & V_48 , sizeof( V_48 ) ) ;
if ( V_13 < 0 ) {
perror ( L_23 ) ;
break;
}
struct V_49 V_50 [ V_40 ] ;
V_13 = F_16 ( V_32 , 1 , V_40 , V_50 , NULL ) ;
if ( V_13 > 0 )
V_19 [ V_35 ] . V_26 -= V_13 ;
if ( ! V_19 [ V_35 ] . V_26 )
V_35 = ( V_35 + 1 ) % ( sizeof( V_19 ) / sizeof( * V_19 ) ) ;
}
for ( V_22 = 0 ; V_22 < sizeof( V_19 ) / sizeof( * V_19 ) ; ++ V_22 )
F_6 ( & V_19 [ V_22 ] ) ;
F_17 ( V_32 ) ;
F_18 ( V_31 ) ;
F_18 ( V_11 ) ;
return 0 ;
}
