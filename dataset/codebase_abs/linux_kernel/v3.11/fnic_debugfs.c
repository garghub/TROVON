static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
V_3 -> V_4 = V_1 -> V_5 ;
return 0 ;
}
static T_1 F_2 ( struct V_2 * V_3 ,
char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
char V_9 [ 64 ] ;
int V_10 ;
V_10 = sprintf ( V_9 , L_1 , V_11 ) ;
return F_3 ( V_6 , V_7 , V_8 , V_9 , V_10 ) ;
}
static T_1 F_4 ( struct V_2 * V_3 ,
const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
char V_9 [ 64 ] ;
unsigned long V_12 ;
int V_13 ;
if ( V_7 >= sizeof( V_9 ) )
return - V_14 ;
if ( F_5 ( & V_9 , V_6 , V_7 ) )
return - V_15 ;
V_9 [ V_7 ] = 0 ;
V_13 = F_6 ( V_9 , 10 , & V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
V_11 = V_12 ;
( * V_8 ) ++ ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_1 ,
struct V_2 * V_2 )
{
T_5 * V_16 ;
V_16 = F_8 ( sizeof( T_5 ) , V_17 ) ;
if ( ! V_16 )
return - V_18 ;
V_16 -> V_19 = F_9 ( ( 3 * ( V_20 * V_21 ) ) ) ;
if ( ! V_16 -> V_19 ) {
F_10 ( V_16 ) ;
return - V_18 ;
}
memset ( ( void * ) V_16 -> V_19 , 0 ,
( 3 * ( V_20 * V_21 ) ) ) ;
V_16 -> V_22 = F_11 ( V_16 ) ;
V_2 -> V_4 = V_16 ;
return 0 ;
}
static T_4 F_12 ( struct V_2 * V_2 ,
T_4 V_23 ,
int V_24 )
{
T_5 * V_16 = V_2 -> V_4 ;
return F_13 ( V_2 , V_23 , V_24 ,
V_16 -> V_22 ) ;
}
static T_1 F_14 ( struct V_2 * V_2 ,
char T_2 * V_6 ,
T_3 V_25 ,
T_4 * V_26 )
{
T_5 * V_16 = V_2 -> V_4 ;
int V_27 = 0 ;
V_27 = F_3 ( V_6 , V_25 , V_26 ,
V_16 -> V_19 ,
V_16 -> V_22 ) ;
return V_27 ;
}
static int F_15 ( struct V_1 * V_1 ,
struct V_2 * V_2 )
{
T_5 * V_16 = V_2 -> V_4 ;
F_16 ( V_16 -> V_19 ) ;
F_10 ( V_16 ) ;
return 0 ;
}
int F_17 ( void )
{
int V_27 = - 1 ;
V_28 = F_18 ( L_2 , NULL ) ;
if ( ! V_28 ) {
F_19 ( V_29 L_3 ) ;
return V_27 ;
}
V_30 = F_20 ( L_4 ,
V_31 | V_32 | V_33 ,
V_28 ,
NULL , & V_34 ) ;
if ( ! V_30 ) {
F_19 ( V_29 L_5
L_6 ) ;
return V_27 ;
}
V_35 = F_20 ( L_7 ,
V_31 | V_32 | V_33 ,
V_28 ,
NULL ,
& V_36 ) ;
if ( ! V_35 ) {
F_19 ( V_29 L_8 ) ;
return V_27 ;
}
V_27 = 0 ;
return V_27 ;
}
void F_21 ( void )
{
if ( V_35 ) {
F_22 ( V_35 ) ;
V_35 = NULL ;
}
if ( V_30 ) {
F_22 ( V_30 ) ;
V_30 = NULL ;
}
if ( V_28 ) {
F_22 ( V_28 ) ;
V_28 = NULL ;
}
}
