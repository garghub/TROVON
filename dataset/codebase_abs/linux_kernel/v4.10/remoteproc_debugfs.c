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
char V_12 [ 100 ] ;
int V_13 ;
V_13 = F_5 ( V_12 , sizeof( V_12 ) , L_1 , V_11 -> V_14 ) ;
return F_3 ( V_3 , V_4 , V_5 , V_12 , V_13 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_11 * V_11 = V_2 -> V_8 ;
char * V_12 = V_11 -> V_15 ? L_2 : L_3 ;
return F_3 ( V_3 , V_4 , V_5 , V_12 , strlen ( V_12 ) ) ;
}
static T_1
F_7 ( struct V_1 * V_2 , const char T_2 * V_16 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_11 * V_11 = V_2 -> V_8 ;
char V_12 [ 10 ] ;
int V_17 ;
if ( V_4 < 1 || V_4 > sizeof( V_12 ) )
return - V_18 ;
V_17 = F_8 ( V_12 , V_16 , V_4 ) ;
if ( V_17 )
return - V_19 ;
if ( V_12 [ V_4 - 1 ] == '\n' )
V_12 [ V_4 - 1 ] = '\0' ;
if ( ! strncmp ( V_12 , L_4 , V_4 ) ) {
V_11 -> V_15 = false ;
if ( V_11 -> V_20 == V_21 )
F_9 ( V_11 ) ;
} else if ( ! strncmp ( V_12 , L_5 , V_4 ) ) {
V_11 -> V_15 = true ;
} else if ( ! strncmp ( V_12 , L_6 , V_4 ) ) {
if ( V_11 -> V_20 == V_21 )
F_9 ( V_11 ) ;
}
return V_4 ;
}
void F_10 ( struct V_22 * V_23 )
{
F_11 ( V_23 ) ;
}
struct V_22 * F_12 ( const char * V_14 , struct V_11 * V_11 ,
struct V_6 * V_7 )
{
struct V_22 * V_23 ;
V_23 = F_13 ( V_14 , 0400 , V_11 -> V_24 , V_7 ,
& V_25 ) ;
if ( ! V_23 ) {
F_14 ( & V_11 -> V_26 , L_7 ) ;
return NULL ;
}
return V_23 ;
}
void F_15 ( struct V_11 * V_11 )
{
if ( ! V_11 -> V_24 )
return;
F_16 ( V_11 -> V_24 ) ;
}
void F_17 ( struct V_11 * V_11 )
{
struct V_27 * V_26 = & V_11 -> V_26 ;
if ( ! V_28 )
return;
V_11 -> V_24 = F_18 ( F_19 ( V_26 ) , V_28 ) ;
if ( ! V_11 -> V_24 )
return;
F_13 ( L_8 , 0400 , V_11 -> V_24 ,
V_11 , & V_29 ) ;
F_13 ( L_9 , 0400 , V_11 -> V_24 ,
V_11 , & V_30 ) ;
}
void T_5 F_20 ( void )
{
if ( F_21 () ) {
V_28 = F_18 ( V_31 , NULL ) ;
if ( ! V_28 )
F_22 ( L_10 ) ;
}
}
void T_6 F_23 ( void )
{
F_11 ( V_28 ) ;
}
