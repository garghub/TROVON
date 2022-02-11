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
void F_25 ( struct V_1 * V_1 , int V_24 , void * V_17 , int V_8 )
{
int type = F_16 ( V_1 , V_17 ) ;
struct V_9 * V_10 = F_26 ( V_1 , type ) ;
if ( ! V_10 ) {
F_27 ( L_4 , type ) ;
return;
}
F_21 ( V_10 , V_24 , V_17 , V_8 ) ;
}
void F_28 ( struct V_1 * V_1 , int V_24 , void * V_17 , int V_8 ,
unsigned long long V_27 , char * V_28 )
{
struct V_21 V_22 ;
struct V_25 V_26 ;
int V_29 ;
V_1 -> V_30 = V_30 ;
V_22 . V_31 = V_27 ;
V_22 . V_24 = V_24 ;
V_22 . V_8 = V_8 ;
V_22 . V_17 = V_17 ;
V_29 = F_19 ( V_1 , & V_22 ) ;
if ( ! F_29 ( V_1 , V_29 ) )
F_30 ( V_1 , V_28 , V_29 ) ;
F_22 ( & V_26 ) ;
F_31 ( V_1 , & V_26 , & V_22 ) ;
F_24 ( & V_26 ) ;
printf ( L_5 ) ;
}
void F_32 ( struct V_1 * V_1 ,
char * V_32 , unsigned int V_8 V_33 )
{
unsigned long long V_34 ;
char * V_35 ;
char * line ;
char * V_36 = NULL ;
char * V_37 ;
char * V_38 ;
char * V_39 ;
line = strtok_r ( V_32 , L_5 , & V_36 ) ;
while ( line ) {
V_38 = NULL ;
V_37 = strtok_r ( line , L_6 , & V_39 ) ;
V_34 = F_33 ( V_37 , NULL , 16 ) ;
strtok_r ( NULL , L_6 , & V_39 ) ;
V_35 = strtok_r ( NULL , L_7 , & V_39 ) ;
V_38 = strtok_r ( NULL , L_8 , & V_39 ) ;
if ( V_38 )
V_38 = V_38 + 1 ;
F_34 ( V_1 , V_35 , V_34 , V_38 ) ;
line = strtok_r ( NULL , L_5 , & V_36 ) ;
}
}
void F_35 ( struct V_1 * V_1 ,
char * V_32 , unsigned int V_8 V_33 )
{
unsigned long long V_34 ;
char * V_40 ;
char * line ;
char * V_36 = NULL ;
char * V_37 ;
char * V_39 ;
line = strtok_r ( V_32 , L_5 , & V_36 ) ;
while ( line ) {
V_37 = strtok_r ( line , L_9 , & V_39 ) ;
if ( ! V_37 ) {
F_27 ( L_10 ) ;
break;
}
V_34 = F_33 ( V_37 , NULL , 16 ) ;
V_40 = F_36 ( V_39 + 1 ) ;
line = strtok_r ( NULL , L_5 , & V_36 ) ;
F_37 ( V_1 , V_40 , V_34 ) ;
}
}
int F_38 ( struct V_1 * V_1 , char * V_41 , unsigned long V_8 )
{
return F_39 ( V_1 , V_41 , V_8 , L_11 ) ;
}
int F_40 ( struct V_1 * V_1 ,
char * V_41 , unsigned long V_8 , char * V_42 )
{
return F_39 ( V_1 , V_41 , V_8 , V_42 ) ;
}
struct V_9 * F_41 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
static int V_43 ;
if ( ! V_1 || ! V_1 -> V_13 )
return NULL ;
if ( ! V_10 ) {
V_43 = 0 ;
return V_1 -> V_13 [ 0 ] ;
}
if ( V_43 < V_1 -> V_44 && V_10 == V_1 -> V_13 [ V_43 ] ) {
V_43 ++ ;
if ( V_43 == V_1 -> V_44 )
return NULL ;
return V_1 -> V_13 [ V_43 ] ;
}
for ( V_43 = 1 ; V_43 < V_1 -> V_44 ; V_43 ++ ) {
if ( V_10 == V_1 -> V_13 [ V_43 - 1 ] )
return V_1 -> V_13 [ V_43 ] ;
}
return NULL ;
}
unsigned long long F_42 ( const char * V_45 )
{
int V_46 ;
if ( isdigit ( V_45 [ 0 ] ) )
return F_33 ( V_45 , NULL , 0 ) ;
for ( V_46 = 0 ; V_46 < ( int ) ( sizeof( V_19 ) / sizeof( V_19 [ 0 ] ) ) ; V_46 ++ )
if ( strcmp ( V_19 [ V_46 ] . V_16 , V_45 ) == 0 )
return V_19 [ V_46 ] . V_47 ;
return 0 ;
}
