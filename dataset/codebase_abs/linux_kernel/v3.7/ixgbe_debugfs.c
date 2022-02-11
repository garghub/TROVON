static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
V_3 -> V_4 = V_1 -> V_5 ;
return 0 ;
}
static T_1 F_2 ( struct V_2 * V_3 , char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
struct V_9 * V_10 = V_3 -> V_4 ;
char V_11 [ 256 ] ;
int V_12 ;
int V_13 ;
if ( * V_8 != 0 )
return 0 ;
V_13 = snprintf ( V_11 , sizeof( V_11 ) , L_1 ,
V_10 -> V_14 -> V_15 , V_16 ) ;
if ( V_7 < V_13 )
return - V_17 ;
V_12 = F_3 ( V_6 , V_11 , V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_8 = V_13 ;
return V_13 ;
}
static T_1 F_4 ( struct V_2 * V_3 ,
const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
struct V_9 * V_10 = V_3 -> V_4 ;
int V_12 ;
if ( * V_8 != 0 )
return 0 ;
if ( V_7 >= sizeof( V_16 ) )
return - V_17 ;
V_12 = F_5 ( V_16 , V_6 , V_7 ) ;
if ( V_12 < 0 )
return V_12 ;
else if ( V_12 < V_7 )
V_7 -= V_12 ;
else
return - V_17 ;
V_16 [ V_7 ] = '\0' ;
if ( strncmp ( V_16 , L_2 , 5 ) == 0 ) {
T_5 V_18 , V_19 ;
int V_20 ;
V_20 = sscanf ( & V_16 [ 5 ] , L_3 , & V_18 , & V_19 ) ;
if ( V_20 == 2 ) {
F_6 ( & V_10 -> V_21 , V_18 , V_19 ) ;
V_19 = F_7 ( & V_10 -> V_21 , V_18 ) ;
F_8 ( L_4 , V_18 , V_19 ) ;
} else {
F_8 ( L_5 ) ;
}
} else if ( strncmp ( V_16 , L_6 , 4 ) == 0 ) {
T_5 V_18 , V_19 ;
int V_20 ;
V_20 = sscanf ( & V_16 [ 4 ] , L_7 , & V_18 ) ;
if ( V_20 == 1 ) {
V_19 = F_7 ( & V_10 -> V_21 , V_18 ) ;
F_8 ( L_8 , V_18 , V_19 ) ;
} else {
F_8 ( L_9 ) ;
}
} else {
F_8 ( L_10 , V_16 ) ;
F_8 ( L_11 ) ;
F_8 ( L_12 ) ;
F_8 ( L_13 ) ;
}
return V_7 ;
}
static int F_9 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
V_3 -> V_4 = V_1 -> V_5 ;
return 0 ;
}
static T_1 F_10 ( struct V_2 * V_3 ,
char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
struct V_9 * V_10 = V_3 -> V_4 ;
char V_11 [ 256 ] ;
int V_12 ;
int V_13 ;
if ( * V_8 != 0 )
return 0 ;
V_13 = snprintf ( V_11 , sizeof( V_11 ) , L_1 ,
V_10 -> V_14 -> V_15 , V_22 ) ;
if ( V_7 < V_13 )
return - V_17 ;
V_12 = F_3 ( V_6 , V_11 , V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_8 = V_13 ;
return V_13 ;
}
static T_1 F_11 ( struct V_2 * V_3 ,
const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
struct V_9 * V_10 = V_3 -> V_4 ;
int V_12 ;
if ( * V_8 != 0 )
return 0 ;
if ( V_7 >= sizeof( V_22 ) )
return - V_17 ;
V_12 = F_5 ( V_22 ,
V_6 , V_7 ) ;
if ( V_12 < 0 )
return V_12 ;
else if ( V_12 < V_7 )
V_7 -= V_12 ;
else
return - V_17 ;
V_22 [ V_7 ] = '\0' ;
if ( strncmp ( V_22 , L_14 , 10 ) == 0 ) {
V_10 -> V_14 -> V_23 -> V_24 ( V_10 -> V_14 ) ;
F_8 ( L_15 ) ;
} else {
F_8 ( L_16 , V_22 ) ;
F_8 ( L_11 ) ;
F_8 ( L_17 ) ;
}
return V_7 ;
}
void F_12 ( struct V_9 * V_10 )
{
const char * V_15 = F_13 ( V_10 -> V_25 ) ;
struct V_26 * V_27 ;
V_10 -> V_28 = F_14 ( V_15 , V_29 ) ;
if ( V_10 -> V_28 ) {
V_27 = F_15 ( L_18 , 0600 ,
V_10 -> V_28 , V_10 ,
& V_30 ) ;
if ( ! V_27 )
F_16 ( L_19 , V_15 ) ;
V_27 = F_15 ( L_20 , 0600 ,
V_10 -> V_28 , V_10 ,
& V_31 ) ;
if ( ! V_27 )
F_16 ( L_21 , V_15 ) ;
} else {
F_16 ( L_22 , V_15 ) ;
}
}
void F_17 ( struct V_9 * V_10 )
{
if ( V_10 -> V_28 )
F_18 ( V_10 -> V_28 ) ;
V_10 -> V_28 = NULL ;
}
void F_19 ( void )
{
V_29 = F_14 ( V_32 , NULL ) ;
if ( V_29 == NULL )
F_20 ( L_23 ) ;
}
void F_21 ( void )
{
F_18 ( V_29 ) ;
}
