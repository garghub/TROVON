static void F_1 ( const char * V_1 , int V_2 , int V_3 )
{
if ( V_2 == - 1 )
V_2 = strlen ( V_1 ) ;
fprintf ( V_4 , L_1 , V_2 , V_1 ,
F_2 ( V_3 ) ) ;
}
static int F_3 ( struct V_5 * V_6 , char * * V_7 , int V_8 ,
char * * V_9 , int * V_10 )
{
char * V_11 = NULL ;
int V_12 = 0 ;
char * V_13 ;
int V_14 ;
int V_15 ;
int V_16 ;
char V_17 [ 3 ] ;
V_16 = 0 ;
if ( V_6 -> V_18 )
fprintf ( V_4 , L_2 ) ;
V_17 [ 0 ] = '%' ;
V_17 [ 1 ] = V_6 -> type ? V_6 -> type : 'd' ;
V_17 [ 2 ] = '\0' ;
for (; V_8 > 0 ; V_7 ++ , V_8 -- , V_16 += V_14 ) {
if ( V_6 -> type == 's' )
V_14 = strlen ( * V_7 ) + 1 ;
else
V_14 = V_6 -> V_19 == - 1 ? 4 : V_6 -> V_19 ;
if ( V_16 + V_14 > V_12 ) {
V_12 = ( V_16 + V_14 ) + 500 ;
V_11 = realloc ( V_11 , V_12 ) ;
if ( ! V_11 ) {
fprintf ( V_4 , L_3
L_4 , V_12 ) ;
return - 1 ;
}
}
V_13 = V_11 + V_16 ;
if ( V_6 -> type == 's' ) {
memcpy ( V_13 , * V_7 , V_14 ) ;
if ( V_6 -> V_18 )
fprintf ( V_4 , L_5 , V_13 ) ;
} else {
int * V_20 = ( int * ) V_13 ;
sscanf ( * V_7 , V_17 , & V_15 ) ;
if ( V_14 == 4 )
* V_20 = F_4 ( V_15 ) ;
else
* V_13 = ( V_21 ) V_15 ;
if ( V_6 -> V_18 ) {
fprintf ( V_4 , L_6 ,
V_6 -> V_19 == 1 ? L_7 :
V_6 -> V_19 == 2 ? L_8 : L_9 ,
V_15 ) ;
}
}
}
* V_10 = V_16 ;
* V_9 = V_11 ;
if ( V_6 -> V_18 )
fprintf ( V_4 , L_10 , V_16 ) ;
return 0 ;
}
static int F_5 ( void * V_22 , const char * V_23 ,
const char * V_24 , const char * V_25 , int V_14 )
{
int V_26 ;
int V_3 ;
V_26 = F_6 ( V_22 , V_23 ) ;
if ( V_26 < 0 ) {
F_1 ( V_23 , - 1 , V_26 ) ;
return - 1 ;
}
V_3 = F_7 ( V_22 , V_26 , V_24 , V_25 , V_14 ) ;
if ( V_3 ) {
F_1 ( V_24 , - 1 , V_3 ) ;
return - 1 ;
}
return 0 ;
}
static int F_8 ( void * V_22 , const char * V_27 )
{
const char * V_28 = V_27 ;
const char * V_29 ;
int V_26 , V_30 = 0 ;
while ( * V_28 == '/' )
V_28 ++ ;
for ( V_29 = V_28 ; * V_29 ; V_28 = V_29 + 1 , V_30 = V_26 ) {
V_29 = strchr ( V_28 , '/' ) ;
if ( ! V_29 )
V_29 = V_28 + strlen ( V_28 ) ;
V_26 = F_9 ( V_22 , V_30 , V_28 ,
V_29 - V_28 ) ;
if ( V_26 == - V_31 ) {
V_26 = F_10 ( V_22 , V_30 , V_28 ,
V_29 - V_28 ) ;
}
if ( V_26 < 0 ) {
F_1 ( V_28 , V_29 - V_28 , V_26 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_11 ( void * V_22 , const char * V_23 )
{
int V_26 = 0 ;
char * V_32 ;
V_32 = strrchr ( V_23 , '/' ) ;
if ( ! V_32 ) {
F_1 ( V_23 , - 1 , - V_33 ) ;
return - 1 ;
}
* V_32 = '\0' ;
if ( V_32 > V_23 ) {
V_26 = F_6 ( V_22 , V_23 ) ;
if ( V_26 < 0 ) {
F_1 ( V_23 , - 1 , V_26 ) ;
return - 1 ;
}
}
V_26 = F_12 ( V_22 , V_26 , V_32 + 1 ) ;
if ( V_26 < 0 ) {
F_1 ( V_32 + 1 , - 1 , V_26 ) ;
return - 1 ;
}
return 0 ;
}
static int F_13 ( struct V_5 * V_6 , const char * V_34 ,
char * * V_7 , int V_8 )
{
char * V_11 ;
char * V_22 ;
int V_14 , V_35 = 0 ;
V_22 = F_14 ( V_34 ) ;
if ( ! V_22 )
return - 1 ;
switch ( V_6 -> V_36 ) {
case V_37 :
assert ( V_8 >= 2 ) ;
if ( V_6 -> V_38 && F_8 ( V_22 , * V_7 ) )
return - 1 ;
if ( F_3 ( V_6 , V_7 + 2 , V_8 - 2 , & V_11 , & V_14 ) ||
F_5 ( V_22 , * V_7 , V_7 [ 1 ] , V_11 , V_14 ) )
V_35 = - 1 ;
break;
case V_39 :
for (; V_35 >= 0 && V_8 -- ; V_7 ++ ) {
if ( V_6 -> V_38 )
V_35 = F_8 ( V_22 , * V_7 ) ;
else
V_35 = F_11 ( V_22 , * V_7 ) ;
}
break;
}
if ( V_35 >= 0 )
V_35 = F_15 ( V_34 , V_22 ) ;
free ( V_22 ) ;
return V_35 ;
}
static void F_16 ( const char * V_40 )
{
if ( V_40 )
fprintf ( V_4 , L_11 , V_40 ) ;
fprintf ( V_4 , L_12 , V_41 ) ;
exit ( 2 ) ;
}
int main ( int V_42 , char * V_43 [] )
{
struct V_5 V_6 ;
char * V_34 = NULL ;
memset ( & V_6 , '\0' , sizeof( V_6 ) ) ;
V_6 . V_19 = - 1 ;
V_6 . V_36 = V_37 ;
for (; ; ) {
int V_44 = F_17 ( V_42 , V_43 , L_13 ) ;
if ( V_44 == - 1 )
break;
switch ( V_44 ) {
case 'c' :
V_6 . V_36 = V_39 ;
break;
case 'h' :
case '?' :
F_16 ( NULL ) ;
case 'p' :
V_6 . V_38 = 1 ;
break;
case 't' :
if ( F_18 ( V_45 , & V_6 . type ,
& V_6 . V_19 ) )
F_16 ( L_14 ) ;
break;
case 'v' :
V_6 . V_18 = 1 ;
break;
}
}
if ( V_46 < V_42 )
V_34 = V_43 [ V_46 ++ ] ;
if ( ! V_34 )
F_16 ( L_15 ) ;
V_43 += V_46 ;
V_42 -= V_46 ;
if ( V_6 . V_36 == V_37 ) {
if ( V_42 < 1 )
F_16 ( L_16 ) ;
if ( V_42 < 2 )
F_16 ( L_17 ) ;
}
if ( F_13 ( & V_6 , V_34 , V_43 , V_42 ) )
return 1 ;
return 0 ;
}
