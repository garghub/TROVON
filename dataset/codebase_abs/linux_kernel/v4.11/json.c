static char * F_1 ( const char * V_1 , T_1 * V_2 )
{
unsigned V_3 = F_2 ( V_4 ) ;
struct V_5 V_6 ;
char * V_7 = NULL ;
int V_8 ;
int V_9 = F_3 ( V_1 , V_10 ) ;
if ( V_9 < 0 && V_11 > 0 && V_1 ) {
F_4 ( L_1 , V_1 ,
strerror ( V_12 ) ) ;
}
if ( V_9 < 0 )
return NULL ;
V_8 = F_5 ( V_9 , & V_6 ) ;
if ( V_8 < 0 )
goto V_13;
* V_2 = V_6 . V_14 ;
V_7 = F_6 ( NULL ,
( V_6 . V_14 + V_3 - 1 ) & ~ ( V_3 - 1 ) ,
V_15 | V_16 , V_17 , V_9 , 0 ) ;
if ( V_7 == V_18 )
V_7 = NULL ;
V_13:
F_7 ( V_9 ) ;
return V_7 ;
}
static void F_8 ( char * V_7 , T_1 V_2 )
{
unsigned V_3 = F_2 ( V_4 ) ;
F_9 ( V_7 , F_10 ( V_2 , V_3 ) ) ;
}
T_2 * F_11 ( const char * V_1 , char * * V_7 , T_1 * V_2 , int * V_19 )
{
T_3 V_20 ;
T_2 * V_21 ;
T_4 V_22 ;
unsigned V_23 ;
* V_7 = F_1 ( V_1 , V_2 ) ;
if ( ! * V_7 )
return NULL ;
V_23 = * V_2 * 16 ;
V_21 = malloc ( V_23 ) ;
if ( ! V_21 )
goto error;
F_12 ( & V_20 ) ;
V_22 = F_13 ( & V_20 , * V_7 , * V_2 , V_21 ,
V_23 / sizeof( T_2 ) ) ;
if ( V_22 != V_24 ) {
F_4 ( L_2 , V_1 , F_14 ( V_22 ) ) ;
goto V_25;
}
if ( V_19 )
* V_19 = V_20 . V_26 ;
return V_21 ;
V_25:
free ( V_21 ) ;
error:
F_8 ( * V_7 , * V_2 ) ;
return NULL ;
}
void F_15 ( char * V_7 , T_1 V_2 , T_2 * V_21 )
{
free ( V_21 ) ;
F_8 ( V_7 , V_2 ) ;
}
static int F_16 ( char * V_7 , char V_27 , int V_28 )
{
int V_29 ;
int V_30 = 0 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ )
if ( V_7 [ V_29 ] == V_27 )
V_30 ++ ;
return V_30 ;
}
int F_17 ( char * V_7 , T_2 * V_31 )
{
return F_16 ( V_7 , '\n' , V_31 -> V_32 ) + 1 ;
}
const char * F_18 ( T_2 * V_31 )
{
return F_19 ( V_33 , V_31 -> type ) ;
}
int F_20 ( T_2 * V_31 )
{
return V_31 -> V_28 - V_31 -> V_32 ;
}
int F_21 ( char * V_7 , T_2 * V_31 , const char * V_34 )
{
unsigned V_19 = F_20 ( V_31 ) ;
return V_19 == strlen ( V_34 ) && ! strncasecmp ( V_7 + V_31 -> V_32 , V_34 , V_19 ) ;
}
