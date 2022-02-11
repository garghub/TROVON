static int F_1 ( struct V_1 * V_2 ,
int * V_3 , int * V_4 , const char * type )
{
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
if ( ! * V_4 ) {
if ( ! V_5 -> V_10 )
return 0 ;
V_7 = V_5 -> V_10 [ 0 ] ;
V_9 = F_2 ( V_7 , type ) ;
if ( ! V_9 )
return 0 ;
* V_3 = V_9 -> V_3 ;
* V_4 = V_9 -> V_4 ;
}
return F_3 ( V_5 , V_2 -> V_11 + * V_3 , * V_4 ) ;
}
int F_4 ( struct V_1 * V_2 )
{
static int V_3 ;
static int V_4 ;
int V_12 ;
V_12 = F_1 ( V_2 , & V_4 , & V_3 ,
L_1 ) ;
if ( V_12 < 0 )
return - 1 ;
return V_12 ;
}
int F_5 ( struct V_1 * V_2 )
{
static int V_3 ;
static int V_4 ;
int V_12 ;
V_12 = F_1 ( V_2 , & V_4 , & V_3 ,
L_2 ) ;
if ( V_12 < 0 )
return - 1 ;
return V_12 ;
}
int F_6 ( struct V_1 * V_2 )
{
static int V_3 ;
static int V_4 ;
int V_12 ;
V_12 = F_1 ( V_2 , & V_4 , & V_3 ,
L_3 ) ;
if ( V_12 < 0 )
return - 1 ;
return V_12 ;
}
unsigned long long
F_7 ( struct V_6 * V_7 , const char * V_13 , void * V_14 )
{
struct V_8 * V_9 ;
unsigned long long V_15 ;
V_9 = F_8 ( V_7 , V_13 ) ;
if ( ! V_9 )
return 0ULL ;
F_9 ( V_9 , V_14 , & V_15 ) ;
return V_15 ;
}
unsigned long long F_10 ( struct V_6 * V_7 , void * V_16 , int V_4 )
{
return F_3 ( V_7 -> V_5 , V_16 , V_4 ) ;
}
void F_11 ( struct V_6 * V_7 ,
int V_17 , void * V_14 , int V_4 , T_1 * V_18 )
{
struct V_19 V_20 ;
struct V_21 V_22 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . V_17 = V_17 ;
V_20 . V_4 = V_4 ;
V_20 . V_14 = V_14 ;
F_12 ( & V_22 ) ;
F_13 ( & V_22 , V_7 , & V_20 ) ;
F_14 ( & V_22 , V_18 ) ;
F_15 ( & V_22 ) ;
}
void F_16 ( struct V_6 * V_7 ,
int V_17 , void * V_14 , int V_4 )
{
return F_11 ( V_7 , V_17 , V_14 , V_4 , stdout ) ;
}
void F_17 ( struct V_5 * V_5 ,
char * V_23 , unsigned int V_4 V_24 )
{
unsigned long long V_25 ;
char * V_26 ;
char * line ;
char * V_27 = NULL ;
char * V_28 ;
char * V_29 = NULL ;
line = strtok_r ( V_23 , L_4 , & V_27 ) ;
while ( line ) {
V_28 = strtok_r ( line , L_5 , & V_29 ) ;
if ( ! V_28 ) {
F_18 ( L_6 ) ;
break;
}
V_25 = F_19 ( V_28 , NULL , 16 ) ;
V_26 = F_20 ( V_29 + 1 ) ;
line = strtok_r ( NULL , L_4 , & V_27 ) ;
F_21 ( V_5 , V_26 , V_25 ) ;
}
}
void F_22 ( struct V_5 * V_5 ,
char * V_23 , unsigned int V_4 V_24 )
{
char * V_30 ;
char * line ;
char * V_27 = NULL ;
int V_31 ;
line = strtok_r ( V_23 , L_4 , & V_27 ) ;
while ( line ) {
sscanf ( line , L_7 , & V_31 , & V_30 ) ;
F_23 ( V_5 , V_30 , V_31 ) ;
free ( V_30 ) ;
line = strtok_r ( NULL , L_4 , & V_27 ) ;
}
}
int F_24 ( struct V_5 * V_5 , char * V_32 , unsigned long V_4 )
{
return F_25 ( V_5 , V_32 , V_4 , L_8 ) ;
}
int F_26 ( struct V_5 * V_5 ,
char * V_32 , unsigned long V_4 , char * V_33 )
{
return F_25 ( V_5 , V_32 , V_4 , V_33 ) ;
}
struct V_6 * F_27 ( struct V_5 * V_5 ,
struct V_6 * V_7 )
{
static int V_34 ;
if ( ! V_5 || ! V_5 -> V_10 )
return NULL ;
if ( ! V_7 ) {
V_34 = 0 ;
return V_5 -> V_10 [ 0 ] ;
}
if ( V_34 < V_5 -> V_35 && V_7 == V_5 -> V_10 [ V_34 ] ) {
V_34 ++ ;
if ( V_34 == V_5 -> V_35 )
return NULL ;
return V_5 -> V_10 [ V_34 ] ;
}
for ( V_34 = 1 ; V_34 < V_5 -> V_35 ; V_34 ++ ) {
if ( V_7 == V_5 -> V_10 [ V_34 - 1 ] )
return V_5 -> V_10 [ V_34 ] ;
}
return NULL ;
}
unsigned long long F_28 ( const char * V_36 )
{
int V_37 ;
if ( isdigit ( V_36 [ 0 ] ) )
return F_19 ( V_36 , NULL , 0 ) ;
for ( V_37 = 0 ; V_37 < ( int ) ( sizeof( V_38 ) / sizeof( V_38 [ 0 ] ) ) ; V_37 ++ )
if ( strcmp ( V_38 [ V_37 ] . V_13 , V_36 ) == 0 )
return V_38 [ V_37 ] . V_39 ;
return 0 ;
}
