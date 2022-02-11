int F_1 ( int V_1 , int V_2 )
{
if ( V_3 )
return 0 ;
V_4 = F_2 () ;
V_3 = V_4 ;
F_3 ( V_3 , V_5 ) ;
F_4 ( V_3 , V_1 ) ;
F_5 ( V_3 , V_2 ) ;
return 0 ;
}
static int F_6 ( struct V_6 * V_7 ,
int * V_8 , int * V_9 , const char * type )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
if ( ! * V_9 ) {
if ( ! V_3 -> V_14 )
return 0 ;
V_11 = V_3 -> V_14 [ 0 ] ;
V_13 = F_7 ( V_11 , type ) ;
if ( ! V_13 )
return 0 ;
* V_8 = V_13 -> V_8 ;
* V_9 = V_13 -> V_9 ;
}
return F_8 ( V_3 , V_7 -> V_15 + * V_8 , * V_9 ) ;
}
int F_9 ( struct V_6 * V_7 )
{
static int V_8 ;
static int V_9 ;
int V_16 ;
V_16 = F_6 ( V_7 , & V_9 , & V_8 ,
L_1 ) ;
if ( V_16 < 0 )
return - 1 ;
return V_16 ;
}
int F_10 ( struct V_6 * V_7 )
{
static int V_8 ;
static int V_9 ;
int V_16 ;
V_16 = F_6 ( V_7 , & V_9 , & V_8 ,
L_2 ) ;
if ( V_16 < 0 )
return - 1 ;
return V_16 ;
}
int F_11 ( struct V_6 * V_7 )
{
static int V_8 ;
static int V_9 ;
int V_16 ;
V_16 = F_6 ( V_7 , & V_9 , & V_8 ,
L_3 ) ;
if ( V_16 < 0 )
return - 1 ;
return V_16 ;
}
unsigned long long
F_12 ( struct V_10 * V_11 , const char * V_17 , void * V_18 )
{
struct V_12 * V_13 ;
unsigned long long V_19 ;
V_13 = F_13 ( V_11 , V_17 ) ;
if ( ! V_13 )
return 0ULL ;
F_14 ( V_13 , V_18 , & V_19 ) ;
return V_19 ;
}
void * F_15 ( struct V_10 * V_11 , const char * V_17 , void * V_18 )
{
struct V_12 * V_13 ;
V_13 = F_13 ( V_11 , V_17 ) ;
if ( ! V_13 )
return NULL ;
if ( V_13 -> V_20 & V_21 ) {
int V_8 ;
V_8 = * ( int * ) ( V_18 + V_13 -> V_8 ) ;
V_8 &= 0xffff ;
return V_18 + V_8 ;
}
return V_18 + V_13 -> V_8 ;
}
int F_16 ( void * V_18 )
{
struct V_22 V_23 ;
V_23 . V_18 = V_18 ;
return F_17 ( V_3 , & V_23 ) ;
}
int F_18 ( void * V_18 )
{
struct V_22 V_23 ;
V_23 . V_18 = V_18 ;
return F_19 ( V_3 , & V_23 ) ;
}
unsigned long long F_20 ( void * V_24 , int V_9 )
{
return F_8 ( V_3 , V_24 , V_9 ) ;
}
struct V_10 * F_21 ( int type )
{
return F_22 ( V_3 , type ) ;
}
void F_23 ( int V_25 , void * V_18 , int V_9 )
{
struct V_10 * V_11 ;
struct V_22 V_23 ;
struct V_26 V_27 ;
int type ;
type = F_16 ( V_18 ) ;
V_11 = F_21 ( type ) ;
if ( ! V_11 ) {
F_24 ( L_4 , type ) ;
return;
}
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_25 = V_25 ;
V_23 . V_9 = V_9 ;
V_23 . V_18 = V_18 ;
F_25 ( & V_27 ) ;
F_26 ( & V_27 , V_11 , & V_23 ) ;
F_27 ( & V_27 ) ;
}
void F_28 ( int V_25 , void * V_18 , int V_9 , unsigned long long V_28 ,
char * V_29 )
{
struct V_22 V_23 ;
struct V_26 V_27 ;
int V_30 ;
V_3 -> V_31 = V_31 ;
V_23 . V_32 = V_28 ;
V_23 . V_25 = V_25 ;
V_23 . V_9 = V_9 ;
V_23 . V_18 = V_18 ;
V_30 = F_19 ( V_3 , & V_23 ) ;
if ( ! F_29 ( V_3 , V_30 ) )
F_30 ( V_3 , V_29 , V_30 ) ;
F_25 ( & V_27 ) ;
F_31 ( V_3 , & V_27 , & V_23 ) ;
F_27 ( & V_27 ) ;
printf ( L_5 ) ;
}
void F_32 ( char * V_33 , unsigned int V_9 V_34 )
{
unsigned long long V_35 ;
char * V_36 ;
char * line ;
char * V_37 = NULL ;
char * V_38 ;
char * V_39 ;
char V_40 ;
line = strtok_r ( V_33 , L_5 , & V_37 ) ;
while ( line ) {
V_39 = NULL ;
sscanf ( line , L_6 ,
( float * ) ( void * ) & V_38 ,
& V_40 , ( float * ) ( void * ) & V_36 , ( float * ) ( void * ) & V_39 ) ;
V_35 = F_33 ( V_38 , NULL , 16 ) ;
free ( V_38 ) ;
if ( V_39 )
V_39 [ strlen ( V_39 ) - 1 ] = 0 ;
F_34 ( V_3 , V_36 , V_35 , V_39 ) ;
free ( V_36 ) ;
free ( V_39 ) ;
line = strtok_r ( NULL , L_5 , & V_37 ) ;
}
}
void F_35 ( char * V_33 , unsigned int V_9 V_34 )
{
unsigned long long V_35 ;
char * V_41 ;
char * line ;
char * V_37 = NULL ;
char * V_38 ;
char * V_42 ;
line = strtok_r ( V_33 , L_5 , & V_37 ) ;
while ( line ) {
V_38 = strtok_r ( line , L_7 , & V_42 ) ;
if ( ! V_38 ) {
F_24 ( L_8 ) ;
break;
}
V_35 = F_33 ( V_38 , NULL , 16 ) ;
V_41 = F_36 ( V_42 + 1 ) ;
line = strtok_r ( NULL , L_5 , & V_37 ) ;
F_37 ( V_3 , V_41 , V_35 ) ;
}
}
int F_38 ( char * V_43 , unsigned long V_9 )
{
return F_39 ( V_3 , V_43 , V_9 , L_9 ) ;
}
int F_40 ( char * V_43 , unsigned long V_9 , char * V_44 )
{
return F_39 ( V_3 , V_43 , V_9 , V_44 ) ;
}
struct V_10 * F_41 ( struct V_10 * V_11 )
{
static int V_45 ;
if ( ! V_3 -> V_14 )
return NULL ;
if ( ! V_11 ) {
V_45 = 0 ;
return V_3 -> V_14 [ 0 ] ;
}
if ( V_45 < V_3 -> V_46 && V_11 == V_3 -> V_14 [ V_45 ] ) {
V_45 ++ ;
if ( V_45 == V_3 -> V_46 )
return NULL ;
return V_3 -> V_14 [ V_45 ] ;
}
for ( V_45 = 1 ; V_45 < V_3 -> V_46 ; V_45 ++ ) {
if ( V_11 == V_3 -> V_14 [ V_45 - 1 ] )
return V_3 -> V_14 [ V_45 ] ;
}
return NULL ;
}
unsigned long long F_42 ( const char * V_47 )
{
int V_48 ;
if ( isdigit ( V_47 [ 0 ] ) )
return F_33 ( V_47 , NULL , 0 ) ;
for ( V_48 = 0 ; V_48 < ( int ) ( sizeof( V_20 ) / sizeof( V_20 [ 0 ] ) ) ; V_48 ++ )
if ( strcmp ( V_20 [ V_48 ] . V_17 , V_47 ) == 0 )
return V_20 [ V_48 ] . V_49 ;
return 0 ;
}
