static void F_1 ( int V_1 , bool V_2 )
{
char V_3 [ V_4 ] ;
if ( V_1 == - V_5 ) {
const char * V_6 ;
if ( V_2 )
V_6 = L_1 ;
else
V_6 = L_2 ;
F_2 ( L_3
L_4 ,
V_2 ? 'u' : 'k' , V_6 ) ;
} else if ( V_1 == - V_7 )
F_2 ( L_5 ) ;
else
F_2 ( L_6 ,
V_2 ? 'u' : 'k' ,
F_3 ( - V_1 , V_3 , sizeof( V_3 ) ) ) ;
}
static void F_4 ( int V_8 , int V_9 )
{
if ( V_8 == - V_7 && V_9 == - V_7 )
F_2 ( L_5 ) ;
else if ( V_8 == - V_5 && V_9 == - V_5 )
F_2 ( L_7
L_8 ) ;
else {
char V_3 [ V_4 ] ;
F_2 ( L_9 ,
F_3 ( - V_8 , V_3 , sizeof( V_3 ) ) ) ;
F_2 ( L_10 ,
F_3 ( - V_9 , V_3 , sizeof( V_3 ) ) ) ;
}
}
static int F_5 ( const char * V_10 , bool V_11 )
{
char V_12 [ V_13 ] ;
const char * V_14 = L_11 ;
int V_15 ;
V_15 = F_6 ( V_12 , V_13 , L_12 ,
V_16 , V_14 , V_10 ) ;
if ( V_15 >= 0 ) {
F_7 ( L_13 , V_12 , V_11 ) ;
if ( V_11 && ! V_17 )
V_15 = F_8 ( V_12 , V_18 | V_19 , 0 ) ;
else
V_15 = F_8 ( V_12 , V_20 , 0 ) ;
if ( V_15 < 0 )
V_15 = - V_21 ;
}
return V_15 ;
}
static int F_9 ( bool V_11 )
{
return F_5 ( L_14 , V_11 ) ;
}
static int F_10 ( bool V_11 )
{
return F_5 ( L_15 , V_11 ) ;
}
int F_11 ( int V_22 )
{
int V_23 ;
if ( V_22 & V_24 )
V_23 = F_10 ( V_22 & V_25 ) ;
else
V_23 = F_9 ( V_22 & V_25 ) ;
if ( V_23 < 0 )
F_1 ( V_23 , V_22 & V_24 ) ;
return V_23 ;
}
int F_12 ( int * V_26 , int * V_27 , int V_22 )
{
if ( ! V_26 || ! V_27 )
return - V_28 ;
* V_26 = F_9 ( V_22 & V_25 ) ;
* V_27 = F_10 ( V_22 & V_25 ) ;
if ( * V_26 < 0 && * V_27 < 0 ) {
F_4 ( * V_26 , * V_27 ) ;
return * V_26 ;
}
return 0 ;
}
struct V_29 * F_13 ( int V_23 )
{
int V_15 , V_30 ;
T_1 * V_31 ;
char V_12 [ V_32 ] ;
char * V_33 ;
struct V_29 * V_34 ;
if ( V_23 < 0 )
return NULL ;
V_34 = F_14 ( NULL , NULL ) ;
V_31 = fdopen ( F_15 ( V_23 ) , L_16 ) ;
while ( ! feof ( V_31 ) ) {
V_33 = fgets ( V_12 , V_32 , V_31 ) ;
if ( ! V_33 )
break;
V_30 = strlen ( V_33 ) - 1 ;
if ( V_33 [ V_30 ] == '\n' )
V_33 [ V_30 ] = '\0' ;
V_15 = F_16 ( V_34 , V_12 ) ;
if ( V_15 < 0 ) {
F_7 ( L_17 , V_15 ) ;
F_17 ( V_34 ) ;
return NULL ;
}
}
fclose ( V_31 ) ;
return V_34 ;
}
static struct V_29 * F_18 ( int V_23 , bool V_35 )
{
char V_12 [ 128 ] ;
struct V_29 * V_34 , * V_36 ;
struct V_37 * V_38 ;
struct V_39 V_40 ;
int V_15 = 0 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_36 = F_13 ( V_23 ) ;
if ( ! V_36 )
return NULL ;
V_34 = F_14 ( NULL , NULL ) ;
F_19 (ent, rawlist) {
V_15 = F_20 ( V_38 -> V_41 , & V_40 ) ;
if ( V_15 < 0 )
break;
if ( V_35 ) {
V_15 = F_6 ( V_12 , 128 , L_18 , V_40 . V_42 ,
V_40 . V_43 ) ;
if ( V_15 >= 0 )
V_15 = F_16 ( V_34 , V_12 ) ;
} else
V_15 = F_16 ( V_34 , V_40 . V_43 ) ;
F_21 ( & V_40 ) ;
if ( V_15 < 0 )
break;
}
F_17 ( V_36 ) ;
if ( V_15 < 0 ) {
F_17 ( V_34 ) ;
return NULL ;
}
return V_34 ;
}
struct V_29 * F_22 ( int V_23 )
{
return F_18 ( V_23 , false ) ;
}
int F_23 ( int V_23 , struct V_39 * V_40 )
{
int V_15 = 0 ;
char * V_12 = F_24 ( V_40 ) ;
char V_3 [ V_4 ] ;
if ( ! V_12 ) {
F_7 ( L_19 ) ;
return - V_28 ;
}
F_7 ( L_20 , V_12 ) ;
if ( ! V_17 ) {
if ( F_25 ( V_23 , V_12 , strlen ( V_12 ) ) < ( int ) strlen ( V_12 ) ) {
V_15 = - V_21 ;
F_2 ( L_21 ,
F_3 ( V_21 , V_3 , sizeof( V_3 ) ) ) ;
}
}
free ( V_12 ) ;
return V_15 ;
}
static int F_26 ( int V_23 , struct V_37 * V_38 )
{
char * V_33 ;
char V_12 [ 128 ] ;
int V_15 ;
V_15 = F_6 ( V_12 , 128 , L_22 , V_38 -> V_41 ) ;
if ( V_15 < 0 )
goto error;
V_33 = strchr ( V_12 + 2 , ':' ) ;
if ( ! V_33 ) {
F_7 ( L_23 ,
V_38 -> V_41 ) ;
V_15 = - V_7 ;
goto error;
}
* V_33 = '/' ;
F_7 ( L_20 , V_12 ) ;
V_15 = F_25 ( V_23 , V_12 , strlen ( V_12 ) ) ;
if ( V_15 < 0 ) {
V_15 = - V_21 ;
goto error;
}
return 0 ;
error:
F_2 ( L_24 ,
F_3 ( - V_15 , V_12 , sizeof( V_12 ) ) ) ;
return V_15 ;
}
int F_27 ( int V_23 , struct V_44 * V_45 ,
struct V_29 * V_46 )
{
struct V_29 * V_47 ;
struct V_37 * V_38 ;
const char * V_33 ;
int V_15 = - V_5 ;
if ( ! V_46 )
return - V_28 ;
V_47 = F_18 ( V_23 , true ) ;
if ( ! V_47 )
return - V_5 ;
F_19 (ent, namelist) {
V_33 = strchr ( V_38 -> V_41 , ':' ) ;
if ( ( V_33 && F_28 ( V_45 , V_33 + 1 ) ) ||
F_28 ( V_45 , V_38 -> V_41 ) ) {
F_16 ( V_46 , V_38 -> V_41 ) ;
V_15 = 0 ;
}
}
F_17 ( V_47 ) ;
return V_15 ;
}
int F_29 ( int V_23 , struct V_29 * V_47 )
{
int V_15 = 0 ;
struct V_37 * V_38 ;
F_19 (ent, namelist) {
V_15 = F_26 ( V_23 , V_38 ) ;
if ( V_15 < 0 )
break;
}
return V_15 ;
}
int F_30 ( int V_23 , struct V_44 * V_45 )
{
struct V_29 * V_47 ;
int V_15 ;
V_47 = F_14 ( NULL , NULL ) ;
if ( ! V_47 )
return - V_48 ;
V_15 = F_27 ( V_23 , V_45 , V_47 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_29 ( V_23 , V_47 ) ;
F_17 ( V_47 ) ;
return V_15 ;
}
