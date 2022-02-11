static void F_1 ( const char * V_1 , int V_2 )
{
fprintf ( V_3 , L_1 , V_1 , F_2 ( V_2 ) ) ;
}
static int F_3 ( struct V_4 * V_5 , const char * V_6 , int V_7 )
{
int V_8 , V_9 ;
const T_1 * V_10 = ( const T_1 * ) V_6 ;
const char * V_11 ;
int V_12 ;
int V_13 ;
char V_14 [ 3 ] ;
if ( V_7 == 0 )
return 0 ;
V_13 = ( V_5 -> type ) == 's' ||
( ! V_5 -> type && F_4 ( V_6 , V_7 ) ) ;
if ( V_13 ) {
if ( V_6 [ V_7 - 1 ] != '\0' ) {
fprintf ( V_3 , L_2 ) ;
return - 1 ;
}
for ( V_11 = V_6 ; V_11 - V_6 < V_7 ; V_11 += strlen ( V_11 ) + 1 ) {
if ( V_11 != V_6 )
printf ( L_3 ) ;
printf ( L_4 , ( const char * ) V_11 ) ;
}
return 0 ;
}
V_9 = V_5 -> V_9 ;
if ( V_9 == - 1 ) {
V_9 = ( V_7 % 4 ) == 0 ? 4 : 1 ;
} else if ( V_7 % V_9 ) {
fprintf ( V_3 , L_5
L_6 ) ;
return - 1 ;
}
V_14 [ 0 ] = '%' ;
V_14 [ 1 ] = V_5 -> type ? V_5 -> type : 'd' ;
V_14 [ 2 ] = '\0' ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 += V_9 , V_10 += V_9 ) {
if ( V_8 )
printf ( L_3 ) ;
V_12 = V_9 == 4 ? F_5 ( * ( const V_15 * ) V_10 ) :
V_9 == 2 ? ( * V_10 << 8 ) | V_10 [ 1 ] : * V_10 ;
printf ( V_14 , V_12 ) ;
}
return 0 ;
}
static int F_6 ( const void * V_16 , int V_17 )
{
const struct V_18 * V_6 ;
const char * V_19 ;
int V_20 ;
V_20 = F_7 ( V_16 , V_17 ) ;
do {
if ( V_20 < 0 )
return V_20 == - V_21 ? 0 : V_20 ;
V_6 = F_8 ( V_16 , V_20 , NULL ) ;
V_19 = F_9 ( V_16 , F_5 ( V_6 -> V_22 ) ) ;
if ( V_19 )
puts ( V_19 ) ;
V_20 = F_10 ( V_16 , V_20 ) ;
} while ( 1 );
}
static int F_11 ( const void * V_16 , int V_17 )
{
int V_23 ;
V_15 V_24 ;
int V_25 = 0 ;
const char * V_26 ;
int V_27 = 1 ;
while ( V_25 >= 0 ) {
V_24 = F_12 ( V_16 , V_17 , & V_23 ) ;
switch ( V_24 ) {
case V_28 :
V_26 = F_13 ( V_16 , V_17 , NULL ) ;
if ( V_25 <= V_27 ) {
if ( V_26 == NULL )
V_26 = L_7 ;
if ( * V_26 == '\0' )
V_26 = L_8 ;
if ( V_25 == 1 )
puts ( V_26 ) ;
}
V_25 ++ ;
if ( V_25 >= V_29 ) {
printf ( L_9 ) ;
return 1 ;
}
break;
case V_30 :
V_25 -- ;
if ( V_25 == 0 )
V_25 = - 1 ;
break;
case V_31 :
return 1 ;
case V_32 :
break;
default:
if ( V_25 <= V_27 )
printf ( L_10 , V_24 ) ;
return 1 ;
}
V_17 = V_23 ;
}
return 0 ;
}
static int F_14 ( const void * V_16 , struct V_4 * V_5 ,
int V_17 , const char * V_33 )
{
const void * V_12 = NULL ;
int V_7 , V_2 = 0 ;
switch ( V_5 -> V_34 ) {
case V_35 :
V_2 = F_6 ( V_16 , V_17 ) ;
break;
case V_36 :
V_2 = F_11 ( V_16 , V_17 ) ;
break;
default:
assert ( V_33 ) ;
V_12 = F_15 ( V_16 , V_17 , V_33 , & V_7 ) ;
if ( V_12 ) {
if ( F_3 ( V_5 , V_12 , V_7 ) )
V_2 = - 1 ;
else
printf ( L_11 ) ;
} else if ( V_5 -> V_37 ) {
puts ( V_5 -> V_37 ) ;
} else {
F_1 ( V_33 , V_7 ) ;
V_2 = - 1 ;
}
break;
}
return V_2 ;
}
static int F_16 ( struct V_4 * V_5 , const char * V_38 ,
char * * V_39 , int V_40 , int V_41 )
{
char * V_16 ;
const char * V_20 ;
int V_8 , V_17 ;
V_16 = F_17 ( V_38 ) ;
if ( ! V_16 )
return - 1 ;
for ( V_8 = 0 ; V_8 + V_41 <= V_40 ; V_8 += V_41 ) {
V_17 = F_18 ( V_16 , V_39 [ V_8 ] ) ;
if ( V_17 < 0 ) {
if ( V_5 -> V_37 ) {
puts ( V_5 -> V_37 ) ;
continue;
} else {
F_1 ( V_39 [ V_8 ] , V_17 ) ;
return - 1 ;
}
}
V_20 = V_41 == 1 ? NULL : V_39 [ V_8 + 1 ] ;
if ( F_14 ( V_16 , V_5 , V_17 , V_20 ) )
return - 1 ;
}
return 0 ;
}
static void F_19 ( const char * V_42 )
{
if ( V_42 )
fprintf ( V_3 , L_12 , V_42 ) ;
fprintf ( V_3 , L_4 , V_43 ) ;
exit ( 2 ) ;
}
int main ( int V_44 , char * V_45 [] )
{
char * V_38 = NULL ;
struct V_4 V_5 ;
int V_41 = 2 ;
memset ( & V_5 , '\0' , sizeof( V_5 ) ) ;
V_5 . V_9 = - 1 ;
V_5 . V_34 = V_46 ;
for (; ; ) {
int V_47 = F_20 ( V_44 , V_45 , L_13 ) ;
if ( V_47 == - 1 )
break;
switch ( V_47 ) {
case 'h' :
case '?' :
F_19 ( NULL ) ;
case 't' :
if ( F_21 ( V_48 , & V_5 . type ,
& V_5 . V_9 ) )
F_19 ( L_14 ) ;
break;
case 'p' :
V_5 . V_34 = V_35 ;
V_41 = 1 ;
break;
case 'l' :
V_5 . V_34 = V_36 ;
V_41 = 1 ;
break;
case 'd' :
V_5 . V_37 = V_48 ;
break;
}
}
if ( V_49 < V_44 )
V_38 = V_45 [ V_49 ++ ] ;
if ( ! V_38 )
F_19 ( L_15 ) ;
V_45 += V_49 ;
V_44 -= V_49 ;
if ( ! V_44 )
return 0 ;
if ( V_41 == 2 && ( V_44 % 2 ) )
F_19 ( L_16 ) ;
if ( F_16 ( & V_5 , V_38 , V_45 , V_44 , V_41 ) )
return 1 ;
return 0 ;
}
