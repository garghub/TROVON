static T_1 F_1 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
char * V_9 ;
int V_10 ;
if ( * V_5 != 0 )
return 0 ;
V_9 = F_2 ( V_11 , L_1 ,
V_7 -> V_12 -> V_13 ,
V_14 ) ;
if ( ! V_9 )
return - V_15 ;
if ( V_4 < strlen ( V_9 ) ) {
F_3 ( V_9 ) ;
return - V_16 ;
}
V_10 = F_4 ( V_3 , V_4 , V_5 , V_9 , strlen ( V_9 ) ) ;
F_3 ( V_9 ) ;
return V_10 ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
const char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_10 ;
if ( * V_5 != 0 )
return 0 ;
if ( V_4 >= sizeof( V_14 ) )
return - V_16 ;
V_10 = F_6 ( V_14 ,
sizeof( V_14 ) - 1 ,
V_5 ,
V_3 ,
V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
V_14 [ V_10 ] = '\0' ;
if ( strncmp ( V_14 , L_2 , 5 ) == 0 ) {
T_5 V_17 , V_18 ;
int V_19 ;
V_19 = sscanf ( & V_14 [ 5 ] , L_3 , & V_17 , & V_18 ) ;
if ( V_19 == 2 ) {
F_7 ( & V_7 -> V_20 , V_17 , V_18 ) ;
V_18 = F_8 ( & V_7 -> V_20 , V_17 ) ;
F_9 ( L_4 , V_17 , V_18 ) ;
} else {
F_9 ( L_5 ) ;
}
} else if ( strncmp ( V_14 , L_6 , 4 ) == 0 ) {
T_5 V_17 , V_18 ;
int V_19 ;
V_19 = sscanf ( & V_14 [ 4 ] , L_7 , & V_17 ) ;
if ( V_19 == 1 ) {
V_18 = F_8 ( & V_7 -> V_20 , V_17 ) ;
F_9 ( L_8 , V_17 , V_18 ) ;
} else {
F_9 ( L_9 ) ;
}
} else {
F_9 ( L_10 , V_14 ) ;
F_9 ( L_11 ) ;
F_9 ( L_12 ) ;
F_9 ( L_13 ) ;
}
return V_4 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
char * V_9 ;
int V_10 ;
if ( * V_5 != 0 )
return 0 ;
V_9 = F_2 ( V_11 , L_1 ,
V_7 -> V_12 -> V_13 ,
V_21 ) ;
if ( ! V_9 )
return - V_15 ;
if ( V_4 < strlen ( V_9 ) ) {
F_3 ( V_9 ) ;
return - V_16 ;
}
V_10 = F_4 ( V_3 , V_4 , V_5 , V_9 , strlen ( V_9 ) ) ;
F_3 ( V_9 ) ;
return V_10 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
const char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_10 ;
if ( * V_5 != 0 )
return 0 ;
if ( V_4 >= sizeof( V_21 ) )
return - V_16 ;
V_10 = F_6 ( V_21 ,
sizeof( V_21 ) - 1 ,
V_5 ,
V_3 ,
V_4 ) ;
if ( V_10 < 0 )
return V_10 ;
V_21 [ V_10 ] = '\0' ;
if ( strncmp ( V_21 , L_14 , 10 ) == 0 ) {
V_7 -> V_12 -> V_22 -> V_23 ( V_7 -> V_12 ) ;
F_9 ( L_15 ) ;
} else {
F_9 ( L_16 , V_21 ) ;
F_9 ( L_11 ) ;
F_9 ( L_17 ) ;
}
return V_4 ;
}
void F_12 ( struct V_6 * V_7 )
{
const char * V_13 = F_13 ( V_7 -> V_24 ) ;
struct V_25 * V_26 ;
V_7 -> V_27 = F_14 ( V_13 , V_28 ) ;
if ( V_7 -> V_27 ) {
V_26 = F_15 ( L_18 , 0600 ,
V_7 -> V_27 , V_7 ,
& V_29 ) ;
if ( ! V_26 )
F_16 ( L_19 , V_13 ) ;
V_26 = F_15 ( L_20 , 0600 ,
V_7 -> V_27 , V_7 ,
& V_30 ) ;
if ( ! V_26 )
F_16 ( L_21 , V_13 ) ;
} else {
F_16 ( L_22 , V_13 ) ;
}
}
void F_17 ( struct V_6 * V_7 )
{
if ( V_7 -> V_27 )
F_18 ( V_7 -> V_27 ) ;
V_7 -> V_27 = NULL ;
}
void F_19 ( void )
{
V_28 = F_14 ( V_31 , NULL ) ;
if ( V_28 == NULL )
F_20 ( L_23 ) ;
}
void F_21 ( void )
{
F_18 ( V_28 ) ;
}
