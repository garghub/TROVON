struct V_1 * F_1 ( int V_2 , int V_3 )
{
struct V_1 * V_1 = F_2 () ;
if ( V_1 != NULL ) {
F_3 ( V_1 , V_4 ) ;
F_4 ( V_1 , V_2 ) ;
F_5 ( V_1 , V_3 ) ;
}
return V_1 ;
}
static int F_6 ( struct V_5 * V_6 ,
int * V_7 , int * V_8 , const char * type )
{
struct V_1 * V_1 = V_6 -> V_1 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
if ( ! * V_8 ) {
if ( ! V_1 -> V_13 )
return 0 ;
V_10 = V_1 -> V_13 [ 0 ] ;
V_12 = F_7 ( V_10 , type ) ;
if ( ! V_12 )
return 0 ;
* V_7 = V_12 -> V_7 ;
* V_8 = V_12 -> V_8 ;
}
return F_8 ( V_1 , V_6 -> V_14 + * V_7 , * V_8 ) ;
}
int F_9 ( struct V_5 * V_6 )
{
static int V_7 ;
static int V_8 ;
int V_15 ;
V_15 = F_6 ( V_6 , & V_8 , & V_7 ,
L_1 ) ;
if ( V_15 < 0 )
return - 1 ;
return V_15 ;
}
int F_10 ( struct V_5 * V_6 )
{
static int V_7 ;
static int V_8 ;
int V_15 ;
V_15 = F_6 ( V_6 , & V_8 , & V_7 ,
L_2 ) ;
if ( V_15 < 0 )
return - 1 ;
return V_15 ;
}
int F_11 ( struct V_5 * V_6 )
{
static int V_7 ;
static int V_8 ;
int V_15 ;
V_15 = F_6 ( V_6 , & V_8 , & V_7 ,
L_3 ) ;
if ( V_15 < 0 )
return - 1 ;
return V_15 ;
}
unsigned long long
F_12 ( struct V_9 * V_10 , const char * V_16 , void * V_17 )
{
struct V_11 * V_12 ;
unsigned long long V_18 ;
V_12 = F_13 ( V_10 , V_16 ) ;
if ( ! V_12 )
return 0ULL ;
F_14 ( V_12 , V_17 , & V_18 ) ;
return V_18 ;
}
unsigned long long F_15 ( struct V_9 * V_10 , void * V_19 , int V_8 )
{
return F_8 ( V_10 -> V_1 , V_19 , V_8 ) ;
}
void F_16 ( struct V_9 * V_10 ,
int V_20 , void * V_17 , int V_8 )
{
struct V_21 V_22 ;
struct V_23 V_24 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_20 = V_20 ;
V_22 . V_8 = V_8 ;
V_22 . V_17 = V_17 ;
F_17 ( & V_24 ) ;
F_18 ( & V_24 , V_10 , & V_22 ) ;
F_19 ( & V_24 ) ;
}
void F_20 ( struct V_1 * V_1 ,
char * V_25 , unsigned int V_8 V_26 )
{
unsigned long long V_27 ;
char * V_28 ;
char * line ;
char * V_29 = NULL ;
char * V_30 ;
char * V_31 ;
char * V_32 = NULL ;
line = strtok_r ( V_25 , L_4 , & V_29 ) ;
while ( line ) {
V_31 = NULL ;
V_30 = strtok_r ( line , L_5 , & V_32 ) ;
V_27 = F_21 ( V_30 , NULL , 16 ) ;
strtok_r ( NULL , L_5 , & V_32 ) ;
V_28 = strtok_r ( NULL , L_6 , & V_32 ) ;
V_31 = strtok_r ( NULL , L_7 , & V_32 ) ;
if ( V_31 )
V_31 = V_31 + 1 ;
F_22 ( V_1 , V_28 , V_27 , V_31 ) ;
line = strtok_r ( NULL , L_4 , & V_29 ) ;
}
}
void F_23 ( struct V_1 * V_1 ,
char * V_25 , unsigned int V_8 V_26 )
{
unsigned long long V_27 ;
char * V_33 ;
char * line ;
char * V_29 = NULL ;
char * V_30 ;
char * V_32 ;
line = strtok_r ( V_25 , L_4 , & V_29 ) ;
while ( line ) {
V_30 = strtok_r ( line , L_8 , & V_32 ) ;
if ( ! V_30 ) {
F_24 ( L_9 ) ;
break;
}
V_27 = F_21 ( V_30 , NULL , 16 ) ;
V_33 = F_25 ( V_32 + 1 ) ;
line = strtok_r ( NULL , L_4 , & V_29 ) ;
F_26 ( V_1 , V_33 , V_27 ) ;
}
}
int F_27 ( struct V_1 * V_1 , char * V_34 , unsigned long V_8 )
{
return F_28 ( V_1 , V_34 , V_8 , L_10 ) ;
}
int F_29 ( struct V_1 * V_1 ,
char * V_34 , unsigned long V_8 , char * V_35 )
{
return F_28 ( V_1 , V_34 , V_8 , V_35 ) ;
}
struct V_9 * F_30 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
static int V_36 ;
if ( ! V_1 || ! V_1 -> V_13 )
return NULL ;
if ( ! V_10 ) {
V_36 = 0 ;
return V_1 -> V_13 [ 0 ] ;
}
if ( V_36 < V_1 -> V_37 && V_10 == V_1 -> V_13 [ V_36 ] ) {
V_36 ++ ;
if ( V_36 == V_1 -> V_37 )
return NULL ;
return V_1 -> V_13 [ V_36 ] ;
}
for ( V_36 = 1 ; V_36 < V_1 -> V_37 ; V_36 ++ ) {
if ( V_10 == V_1 -> V_13 [ V_36 - 1 ] )
return V_1 -> V_13 [ V_36 ] ;
}
return NULL ;
}
unsigned long long F_31 ( const char * V_38 )
{
int V_39 ;
if ( isdigit ( V_38 [ 0 ] ) )
return F_21 ( V_38 , NULL , 0 ) ;
for ( V_39 = 0 ; V_39 < ( int ) ( sizeof( V_40 ) / sizeof( V_40 [ 0 ] ) ) ; V_39 ++ )
if ( strcmp ( V_40 [ V_39 ] . V_16 , V_38 ) == 0 )
return V_40 [ V_39 ] . V_41 ;
return 0 ;
}
