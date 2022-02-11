static T_1 F_1 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_9 = F_2 ( V_7 -> V_10 , V_7 -> V_9 ) ;
return F_3 ( V_3 , V_4 , V_5 , V_7 -> V_10 , V_9 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_11 * V_11 = V_2 -> V_8 ;
unsigned int V_12 ;
char V_13 [ 30 ] ;
int V_14 ;
V_12 = V_11 -> V_12 > V_15 ? V_15 : V_11 -> V_12 ;
V_14 = F_5 ( V_13 , 30 , L_1 , V_16 [ V_12 ] ,
V_11 -> V_12 ) ;
return F_3 ( V_3 , V_4 , V_5 , V_13 , V_14 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_11 * V_11 = V_2 -> V_8 ;
char V_13 [ 100 ] ;
int V_14 ;
V_14 = F_5 ( V_13 , sizeof( V_13 ) , L_2 , V_11 -> V_17 ) ;
return F_3 ( V_3 , V_4 , V_5 , V_13 , V_14 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_11 * V_11 = V_2 -> V_8 ;
char * V_13 = V_11 -> V_18 ? L_3 : L_4 ;
return F_3 ( V_3 , V_4 , V_5 , V_13 , strlen ( V_13 ) ) ;
}
static T_1
F_8 ( struct V_1 * V_2 , const char T_2 * V_19 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_11 * V_11 = V_2 -> V_8 ;
char V_13 [ 10 ] ;
int V_20 ;
if ( V_4 < 1 || V_4 > sizeof( V_13 ) )
return V_4 ;
V_20 = F_9 ( V_13 , V_19 , V_4 ) ;
if ( V_20 )
return - V_21 ;
if ( V_13 [ V_4 - 1 ] == '\n' )
V_13 [ V_4 - 1 ] = '\0' ;
if ( ! strncmp ( V_13 , L_5 , V_4 ) ) {
V_11 -> V_18 = false ;
if ( V_11 -> V_12 == V_22 )
F_10 ( V_11 ) ;
} else if ( ! strncmp ( V_13 , L_6 , V_4 ) ) {
V_11 -> V_18 = true ;
} else if ( ! strncmp ( V_13 , L_7 , V_4 ) ) {
if ( V_11 -> V_12 == V_22 )
F_10 ( V_11 ) ;
}
return V_4 ;
}
void F_11 ( struct V_23 * V_24 )
{
F_12 ( V_24 ) ;
}
struct V_23 * F_13 ( const char * V_17 , struct V_11 * V_11 ,
struct V_6 * V_7 )
{
struct V_23 * V_24 ;
V_24 = F_14 ( V_17 , 0400 , V_11 -> V_25 ,
V_7 , & V_26 ) ;
if ( ! V_24 ) {
F_15 ( & V_11 -> V_27 , L_8 ) ;
return NULL ;
}
return V_24 ;
}
void F_16 ( struct V_11 * V_11 )
{
if ( ! V_11 -> V_25 )
return;
F_17 ( V_11 -> V_25 ) ;
}
void F_18 ( struct V_11 * V_11 )
{
struct V_28 * V_27 = & V_11 -> V_27 ;
if ( ! V_29 )
return;
V_11 -> V_25 = F_19 ( F_20 ( V_27 ) , V_29 ) ;
if ( ! V_11 -> V_25 )
return;
F_14 ( L_9 , 0400 , V_11 -> V_25 ,
V_11 , & V_30 ) ;
F_14 ( L_10 , 0400 , V_11 -> V_25 ,
V_11 , & V_31 ) ;
F_14 ( L_11 , 0400 , V_11 -> V_25 ,
V_11 , & V_32 ) ;
}
void T_5 F_21 ( void )
{
if ( F_22 () ) {
V_29 = F_19 ( V_33 , NULL ) ;
if ( ! V_29 )
F_23 ( L_12 ) ;
}
}
void T_6 F_24 ( void )
{
F_12 ( V_29 ) ;
}
