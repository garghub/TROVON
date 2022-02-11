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
static T_1 F_6 ( struct V_1 * V_2 , const char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_11 * V_11 = V_2 -> V_8 ;
char V_13 [ 10 ] ;
int V_17 ;
if ( V_4 > sizeof( V_13 ) || V_4 <= 0 )
return - V_18 ;
V_17 = F_7 ( V_13 , V_3 , V_4 ) ;
if ( V_17 )
return - V_19 ;
if ( V_13 [ V_4 - 1 ] == '\n' )
V_13 [ V_4 - 1 ] = '\0' ;
if ( ! strncmp ( V_13 , L_2 , V_4 ) ) {
V_17 = F_8 ( V_11 ) ;
if ( V_17 ) {
F_9 ( & V_11 -> V_20 , L_3 , V_17 ) ;
return V_17 ;
}
} else if ( ! strncmp ( V_13 , L_4 , V_4 ) ) {
F_10 ( V_11 ) ;
} else {
F_9 ( & V_11 -> V_20 , L_5 , V_13 ) ;
return - V_18 ;
}
return V_4 ;
}
static T_1 F_11 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_11 * V_11 = V_2 -> V_8 ;
char V_13 [ 100 ] ;
int V_14 ;
V_14 = F_5 ( V_13 , sizeof( V_13 ) , L_6 , V_11 -> V_21 ) ;
return F_3 ( V_3 , V_4 , V_5 , V_13 , V_14 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_11 * V_11 = V_2 -> V_8 ;
char * V_13 = V_11 -> V_22 ? L_7 : L_8 ;
return F_3 ( V_3 , V_4 , V_5 , V_13 , strlen ( V_13 ) ) ;
}
static T_1
F_13 ( struct V_1 * V_2 , const char T_2 * V_23 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_11 * V_11 = V_2 -> V_8 ;
char V_13 [ 10 ] ;
int V_17 ;
if ( V_4 < 1 || V_4 > sizeof( V_13 ) )
return - V_18 ;
V_17 = F_7 ( V_13 , V_23 , V_4 ) ;
if ( V_17 )
return - V_19 ;
if ( V_13 [ V_4 - 1 ] == '\n' )
V_13 [ V_4 - 1 ] = '\0' ;
if ( ! strncmp ( V_13 , L_9 , V_4 ) ) {
V_11 -> V_22 = false ;
if ( V_11 -> V_12 == V_24 )
F_14 ( V_11 ) ;
} else if ( ! strncmp ( V_13 , L_10 , V_4 ) ) {
V_11 -> V_22 = true ;
} else if ( ! strncmp ( V_13 , L_11 , V_4 ) ) {
if ( V_11 -> V_12 == V_24 )
F_14 ( V_11 ) ;
}
return V_4 ;
}
void F_15 ( struct V_25 * V_26 )
{
F_16 ( V_26 ) ;
}
struct V_25 * F_17 ( const char * V_21 , struct V_11 * V_11 ,
struct V_6 * V_7 )
{
struct V_25 * V_26 ;
V_26 = F_18 ( V_21 , 0400 , V_11 -> V_27 ,
V_7 , & V_28 ) ;
if ( ! V_26 ) {
F_9 ( & V_11 -> V_20 , L_12 ) ;
return NULL ;
}
return V_26 ;
}
void F_19 ( struct V_11 * V_11 )
{
if ( ! V_11 -> V_27 )
return;
F_20 ( V_11 -> V_27 ) ;
}
void F_21 ( struct V_11 * V_11 )
{
struct V_29 * V_20 = & V_11 -> V_20 ;
if ( ! V_30 )
return;
V_11 -> V_27 = F_22 ( F_23 ( V_20 ) , V_30 ) ;
if ( ! V_11 -> V_27 )
return;
F_18 ( L_13 , 0400 , V_11 -> V_27 ,
V_11 , & V_31 ) ;
F_18 ( L_14 , 0400 , V_11 -> V_27 ,
V_11 , & V_32 ) ;
F_18 ( L_15 , 0400 , V_11 -> V_27 ,
V_11 , & V_33 ) ;
}
void T_5 F_24 ( void )
{
if ( F_25 () ) {
V_30 = F_22 ( V_34 , NULL ) ;
if ( ! V_30 )
F_26 ( L_16 ) ;
}
}
void T_6 F_27 ( void )
{
F_16 ( V_30 ) ;
}
