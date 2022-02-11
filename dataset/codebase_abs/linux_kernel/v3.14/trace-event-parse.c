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
int V_17 , void * V_14 , int V_4 )
{
struct V_18 V_19 ;
struct V_20 V_21 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_17 = V_17 ;
V_19 . V_4 = V_4 ;
V_19 . V_14 = V_14 ;
F_12 ( & V_21 ) ;
F_13 ( & V_21 , V_7 , & V_19 ) ;
F_14 ( & V_21 ) ;
}
void F_15 ( struct V_5 * V_5 ,
char * V_22 , unsigned int V_4 V_23 )
{
unsigned long long V_24 ;
char * V_25 ;
char * line ;
char * V_26 = NULL ;
char * V_27 ;
char * V_28 ;
char * V_29 = NULL ;
line = strtok_r ( V_22 , L_4 , & V_26 ) ;
while ( line ) {
V_28 = NULL ;
V_27 = strtok_r ( line , L_5 , & V_29 ) ;
V_24 = F_16 ( V_27 , NULL , 16 ) ;
strtok_r ( NULL , L_5 , & V_29 ) ;
V_25 = strtok_r ( NULL , L_6 , & V_29 ) ;
V_28 = strtok_r ( NULL , L_7 , & V_29 ) ;
if ( V_28 )
V_28 = V_28 + 1 ;
F_17 ( V_5 , V_25 , V_24 , V_28 ) ;
line = strtok_r ( NULL , L_4 , & V_26 ) ;
}
}
void F_18 ( struct V_5 * V_5 ,
char * V_22 , unsigned int V_4 V_23 )
{
unsigned long long V_24 ;
char * V_30 ;
char * line ;
char * V_26 = NULL ;
char * V_27 ;
char * V_29 ;
line = strtok_r ( V_22 , L_4 , & V_26 ) ;
while ( line ) {
V_27 = strtok_r ( line , L_8 , & V_29 ) ;
if ( ! V_27 ) {
F_19 ( L_9 ) ;
break;
}
V_24 = F_16 ( V_27 , NULL , 16 ) ;
V_30 = F_20 ( V_29 + 1 ) ;
line = strtok_r ( NULL , L_4 , & V_26 ) ;
F_21 ( V_5 , V_30 , V_24 ) ;
}
}
int F_22 ( struct V_5 * V_5 , char * V_31 , unsigned long V_4 )
{
return F_23 ( V_5 , V_31 , V_4 , L_10 ) ;
}
int F_24 ( struct V_5 * V_5 ,
char * V_31 , unsigned long V_4 , char * V_32 )
{
return F_23 ( V_5 , V_31 , V_4 , V_32 ) ;
}
struct V_6 * F_25 ( struct V_5 * V_5 ,
struct V_6 * V_7 )
{
static int V_33 ;
if ( ! V_5 || ! V_5 -> V_10 )
return NULL ;
if ( ! V_7 ) {
V_33 = 0 ;
return V_5 -> V_10 [ 0 ] ;
}
if ( V_33 < V_5 -> V_34 && V_7 == V_5 -> V_10 [ V_33 ] ) {
V_33 ++ ;
if ( V_33 == V_5 -> V_34 )
return NULL ;
return V_5 -> V_10 [ V_33 ] ;
}
for ( V_33 = 1 ; V_33 < V_5 -> V_34 ; V_33 ++ ) {
if ( V_7 == V_5 -> V_10 [ V_33 - 1 ] )
return V_5 -> V_10 [ V_33 ] ;
}
return NULL ;
}
unsigned long long F_26 ( const char * V_35 )
{
int V_36 ;
if ( isdigit ( V_35 [ 0 ] ) )
return F_16 ( V_35 , NULL , 0 ) ;
for ( V_36 = 0 ; V_36 < ( int ) ( sizeof( V_37 ) / sizeof( V_37 [ 0 ] ) ) ; V_36 ++ )
if ( strcmp ( V_37 [ V_36 ] . V_13 , V_35 ) == 0 )
return V_37 [ V_36 ] . V_38 ;
return 0 ;
}
