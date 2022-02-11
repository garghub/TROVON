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
void * F_15 ( struct V_9 * V_10 , const char * V_16 , void * V_17 )
{
struct V_11 * V_12 ;
V_12 = F_13 ( V_10 , V_16 ) ;
if ( ! V_12 )
return NULL ;
if ( V_12 -> V_19 & V_20 ) {
int V_7 ;
V_7 = * ( int * ) ( V_17 + V_12 -> V_7 ) ;
V_7 &= 0xffff ;
return V_17 + V_7 ;
}
return V_17 + V_12 -> V_7 ;
}
int F_16 ( struct V_1 * V_1 , void * V_17 )
{
struct V_21 V_22 ;
V_22 . V_17 = V_17 ;
return F_17 ( V_1 , & V_22 ) ;
}
int F_18 ( struct V_1 * V_1 , void * V_17 )
{
struct V_21 V_22 ;
V_22 . V_17 = V_17 ;
return F_19 ( V_1 , & V_22 ) ;
}
unsigned long long F_20 ( struct V_9 * V_10 , void * V_23 , int V_8 )
{
return F_8 ( V_10 -> V_1 , V_23 , V_8 ) ;
}
void F_21 ( struct V_9 * V_10 ,
int V_24 , void * V_17 , int V_8 )
{
struct V_21 V_22 ;
struct V_25 V_26 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_24 = V_24 ;
V_22 . V_8 = V_8 ;
V_22 . V_17 = V_17 ;
F_22 ( & V_26 ) ;
F_23 ( & V_26 , V_10 , & V_22 ) ;
F_24 ( & V_26 ) ;
}
void F_25 ( struct V_1 * V_1 ,
char * V_27 , unsigned int V_8 V_28 )
{
unsigned long long V_29 ;
char * V_30 ;
char * line ;
char * V_31 = NULL ;
char * V_32 ;
char * V_33 ;
char * V_34 ;
line = strtok_r ( V_27 , L_4 , & V_31 ) ;
while ( line ) {
V_33 = NULL ;
V_32 = strtok_r ( line , L_5 , & V_34 ) ;
V_29 = F_26 ( V_32 , NULL , 16 ) ;
strtok_r ( NULL , L_5 , & V_34 ) ;
V_30 = strtok_r ( NULL , L_6 , & V_34 ) ;
V_33 = strtok_r ( NULL , L_7 , & V_34 ) ;
if ( V_33 )
V_33 = V_33 + 1 ;
F_27 ( V_1 , V_30 , V_29 , V_33 ) ;
line = strtok_r ( NULL , L_4 , & V_31 ) ;
}
}
void F_28 ( struct V_1 * V_1 ,
char * V_27 , unsigned int V_8 V_28 )
{
unsigned long long V_29 ;
char * V_35 ;
char * line ;
char * V_31 = NULL ;
char * V_32 ;
char * V_34 ;
line = strtok_r ( V_27 , L_4 , & V_31 ) ;
while ( line ) {
V_32 = strtok_r ( line , L_8 , & V_34 ) ;
if ( ! V_32 ) {
F_29 ( L_9 ) ;
break;
}
V_29 = F_26 ( V_32 , NULL , 16 ) ;
V_35 = F_30 ( V_34 + 1 ) ;
line = strtok_r ( NULL , L_4 , & V_31 ) ;
F_31 ( V_1 , V_35 , V_29 ) ;
}
}
int F_32 ( struct V_1 * V_1 , char * V_36 , unsigned long V_8 )
{
return F_33 ( V_1 , V_36 , V_8 , L_10 ) ;
}
int F_34 ( struct V_1 * V_1 ,
char * V_36 , unsigned long V_8 , char * V_37 )
{
return F_33 ( V_1 , V_36 , V_8 , V_37 ) ;
}
struct V_9 * F_35 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
static int V_38 ;
if ( ! V_1 || ! V_1 -> V_13 )
return NULL ;
if ( ! V_10 ) {
V_38 = 0 ;
return V_1 -> V_13 [ 0 ] ;
}
if ( V_38 < V_1 -> V_39 && V_10 == V_1 -> V_13 [ V_38 ] ) {
V_38 ++ ;
if ( V_38 == V_1 -> V_39 )
return NULL ;
return V_1 -> V_13 [ V_38 ] ;
}
for ( V_38 = 1 ; V_38 < V_1 -> V_39 ; V_38 ++ ) {
if ( V_10 == V_1 -> V_13 [ V_38 - 1 ] )
return V_1 -> V_13 [ V_38 ] ;
}
return NULL ;
}
unsigned long long F_36 ( const char * V_40 )
{
int V_41 ;
if ( isdigit ( V_40 [ 0 ] ) )
return F_26 ( V_40 , NULL , 0 ) ;
for ( V_41 = 0 ; V_41 < ( int ) ( sizeof( V_19 ) / sizeof( V_19 [ 0 ] ) ) ; V_41 ++ )
if ( strcmp ( V_19 [ V_41 ] . V_16 , V_40 ) == 0 )
return V_19 [ V_41 ] . V_42 ;
return 0 ;
}
