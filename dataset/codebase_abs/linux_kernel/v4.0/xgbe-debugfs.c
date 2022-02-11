static T_1 F_1 ( char T_2 * V_1 , T_3 V_2 ,
T_4 * V_3 , unsigned int V_4 )
{
char * V_5 ;
T_1 V_6 ;
if ( * V_3 != 0 )
return 0 ;
V_5 = F_2 ( V_7 , L_1 , V_4 ) ;
if ( ! V_5 )
return - V_8 ;
if ( V_2 < strlen ( V_5 ) ) {
F_3 ( V_5 ) ;
return - V_9 ;
}
V_6 = F_4 ( V_1 , V_2 , V_3 , V_5 , strlen ( V_5 ) ) ;
F_3 ( V_5 ) ;
return V_6 ;
}
static T_1 F_5 ( const char T_2 * V_1 , T_3 V_2 ,
T_4 * V_3 , unsigned int * V_4 )
{
char V_10 [ 32 ] ;
T_1 V_6 ;
int V_11 ;
if ( * V_3 != 0 )
return 0 ;
if ( V_2 >= sizeof( V_10 ) )
return - V_9 ;
V_6 = F_6 ( V_10 , sizeof( V_10 ) - 1 , V_3 ,
V_1 , V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_10 [ V_6 ] = '\0' ;
V_11 = F_7 ( V_10 , 16 , V_4 ) ;
if ( V_11 )
return - V_12 ;
return V_6 ;
}
static T_1 F_8 ( struct V_13 * V_14 , char T_2 * V_1 ,
T_3 V_2 , T_4 * V_3 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
return F_1 ( V_1 , V_2 , V_3 , V_16 -> V_18 ) ;
}
static T_1 F_9 ( struct V_13 * V_14 ,
const char T_2 * V_1 ,
T_3 V_2 , T_4 * V_3 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
return F_5 ( V_1 , V_2 , V_3 ,
& V_16 -> V_18 ) ;
}
static T_1 F_10 ( struct V_13 * V_14 , char T_2 * V_1 ,
T_3 V_2 , T_4 * V_3 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
unsigned int V_4 ;
V_4 = F_11 ( V_16 , V_16 -> V_18 ) ;
return F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
}
static T_1 F_12 ( struct V_13 * V_14 ,
const char T_2 * V_1 ,
T_3 V_2 , T_4 * V_3 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
unsigned int V_4 ;
T_1 V_6 ;
V_6 = F_5 ( V_1 , V_2 , V_3 , & V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_13 ( V_16 , V_16 -> V_18 , V_4 ) ;
return V_6 ;
}
static T_1 F_14 ( struct V_13 * V_14 , char T_2 * V_1 ,
T_3 V_2 , T_4 * V_3 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
return F_1 ( V_1 , V_2 , V_3 , V_16 -> V_19 ) ;
}
static T_1 F_15 ( struct V_13 * V_14 , const char T_2 * V_1 ,
T_3 V_2 , T_4 * V_3 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
return F_5 ( V_1 , V_2 , V_3 ,
& V_16 -> V_19 ) ;
}
static T_1 F_16 ( struct V_13 * V_14 , char T_2 * V_1 ,
T_3 V_2 , T_4 * V_3 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
return F_1 ( V_1 , V_2 , V_3 , V_16 -> V_20 ) ;
}
static T_1 F_17 ( struct V_13 * V_14 , const char T_2 * V_1 ,
T_3 V_2 , T_4 * V_3 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
return F_5 ( V_1 , V_2 , V_3 ,
& V_16 -> V_20 ) ;
}
static T_1 F_18 ( struct V_13 * V_14 , char T_2 * V_1 ,
T_3 V_2 , T_4 * V_3 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
unsigned int V_4 ;
V_4 = F_19 ( V_16 , V_16 -> V_19 ,
V_16 -> V_20 ) ;
return F_1 ( V_1 , V_2 , V_3 , V_4 ) ;
}
static T_1 F_20 ( struct V_13 * V_14 ,
const char T_2 * V_1 ,
T_3 V_2 , T_4 * V_3 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
unsigned int V_4 ;
T_1 V_6 ;
V_6 = F_5 ( V_1 , V_2 , V_3 , & V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
F_21 ( V_16 , V_16 -> V_19 , V_16 -> V_20 ,
V_4 ) ;
return V_6 ;
}
void F_22 ( struct V_15 * V_16 )
{
struct V_21 * V_22 ;
char * V_5 ;
V_16 -> V_18 = 0 ;
V_16 -> V_19 = 1 ;
V_16 -> V_20 = 0 ;
V_5 = F_2 ( V_7 , L_2 , V_16 -> V_23 -> V_24 ) ;
V_16 -> V_25 = F_23 ( V_5 , NULL ) ;
if ( ! V_16 -> V_25 ) {
F_24 ( V_16 -> V_23 , L_3 ) ;
return;
}
V_22 = F_25 ( L_4 , 0600 ,
V_16 -> V_25 , V_16 ,
& V_26 ) ;
if ( ! V_22 )
F_24 ( V_16 -> V_23 , L_5 ) ;
V_22 = F_25 ( L_6 , 0600 ,
V_16 -> V_25 , V_16 ,
& V_27 ) ;
if ( ! V_22 )
F_24 ( V_16 -> V_23 , L_5 ) ;
V_22 = F_25 ( L_7 , 0600 ,
V_16 -> V_25 , V_16 ,
& V_28 ) ;
if ( ! V_22 )
F_24 ( V_16 -> V_23 , L_5 ) ;
V_22 = F_25 ( L_8 , 0600 ,
V_16 -> V_25 , V_16 ,
& V_29 ) ;
if ( ! V_22 )
F_24 ( V_16 -> V_23 , L_5 ) ;
V_22 = F_25 ( L_9 , 0600 ,
V_16 -> V_25 , V_16 ,
& V_30 ) ;
if ( ! V_22 )
F_24 ( V_16 -> V_23 , L_5 ) ;
F_3 ( V_5 ) ;
}
void F_26 ( struct V_15 * V_16 )
{
F_27 ( V_16 -> V_25 ) ;
V_16 -> V_25 = NULL ;
}
