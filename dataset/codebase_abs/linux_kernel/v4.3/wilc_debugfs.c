static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 128 ] ;
int V_6 = 0 ;
if ( * V_4 > 0 )
return 0 ;
V_6 = F_2 ( V_5 , sizeof( V_5 ) , L_1 , F_3 ( & V_7 ) ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static T_1 F_5 ( struct V_1 * V_8 , const char T_2 * V_5 ,
T_3 V_3 , T_4 * V_4 )
{
int V_9 = 0 ;
int V_10 ;
V_10 = F_6 ( V_5 , V_3 , 16 , & V_9 ) ;
if ( V_10 )
return V_10 ;
if ( V_9 > V_11 ) {
F_7 ( L_2 , V_12 , V_9 , F_3 ( & V_7 ) ) ;
return - V_13 ;
}
F_8 ( & V_7 , ( int ) V_9 ) ;
if ( V_9 == 0 )
F_7 ( L_3 ) ;
else
F_7 ( L_4 ) ;
return V_3 ;
}
static T_1 F_9 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 128 ] ;
int V_6 = 0 ;
if ( * V_4 > 0 )
return 0 ;
V_6 = F_2 ( V_5 , sizeof( V_5 ) , L_5 , F_3 ( & V_14 ) ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static T_1 F_10 ( struct V_1 * V_8 , const char * V_5 , T_3 V_3 , T_4 * V_4 )
{
char V_15 [ 128 ] = {} ;
int V_9 ;
if ( V_3 > sizeof( V_15 ) )
return - V_13 ;
if ( F_11 ( V_15 , V_5 , V_3 ) ) {
return - V_16 ;
}
V_9 = V_15 [ 0 ] - '0' ;
if ( V_9 > V_17 ) {
F_7 ( L_2 , V_12 , V_9 , F_3 ( & V_14 ) ) ;
return - V_16 ;
}
F_8 ( & V_14 , ( int ) V_9 ) ;
F_7 ( L_6 , F_3 ( & V_14 ) ) ;
return V_3 ;
}
int F_12 ( void )
{
int V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
V_23 = F_13 ( L_7 , NULL ) ;
if ( V_23 == F_14 ( - V_24 ) ) {
F_7 ( L_8 ) ;
return 0 ;
}
if ( ! V_23 ) {
F_7 ( L_9 ) ;
return - 1 ;
}
for ( V_18 = 0 ; V_18 < F_15 ( V_25 ) ; V_18 ++ ) {
V_22 = & V_25 [ V_18 ] ;
V_20 = F_16 ( V_22 -> V_26 ,
V_22 -> V_27 ,
V_23 ,
& V_22 -> V_28 ,
& V_22 -> V_29 ) ;
if ( ! V_20 ) {
F_7 ( L_10 , V_22 -> V_26 ) ;
F_17 ( V_23 ) ;
return - 1 ;
}
}
return 0 ;
}
void F_18 ( void )
{
F_17 ( V_23 ) ;
}
