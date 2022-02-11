static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 128 ] ;
int V_6 = 0 ;
if ( * V_4 > 0 )
return 0 ;
V_6 = F_2 ( V_5 , sizeof( V_5 ) , L_1 , F_3 ( & V_7 ) ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static T_1 F_5 ( struct V_1 * V_8 , const char * V_5 , T_3 V_3 , T_4 * V_4 )
{
char V_9 [ 128 ] = {} ;
int V_10 = 0 ;
if ( V_3 > sizeof( V_9 ) )
return - V_11 ;
if ( F_6 ( V_9 , V_5 , V_3 ) ) {
return - V_12 ;
}
V_10 = V_9 [ 0 ] - '0' ;
if ( V_10 > 0 ) {
V_10 = V_13 | V_14 ;
} else if ( V_10 < 0 ) {
V_10 = 100 ;
}
if ( V_10 > V_15 ) {
F_7 ( L_2 , V_16 , V_10 , F_3 ( & V_7 ) ) ;
return - V_12 ;
}
F_8 ( & V_7 , ( int ) V_10 ) ;
if ( V_10 == 0 ) {
F_7 ( L_3 ) ;
} else {
F_7 ( L_4 ) ;
}
return V_3 ;
}
static T_1 F_9 ( struct V_1 * V_1 , char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
char V_5 [ 128 ] ;
int V_6 = 0 ;
if ( * V_4 > 0 )
return 0 ;
V_6 = F_2 ( V_5 , sizeof( V_5 ) , L_5 , F_3 ( & V_17 ) ) ;
return F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static T_1 F_10 ( struct V_1 * V_8 , const char * V_5 , T_3 V_3 , T_4 * V_4 )
{
char V_9 [ 128 ] = {} ;
int V_10 ;
if ( V_3 > sizeof( V_9 ) )
return - V_11 ;
if ( F_6 ( V_9 , V_5 , V_3 ) ) {
return - V_12 ;
}
V_10 = V_9 [ 0 ] - '0' ;
if ( V_10 > V_18 ) {
F_7 ( L_2 , V_16 , V_10 , F_3 ( & V_17 ) ) ;
return - V_12 ;
}
F_8 ( & V_17 , ( int ) V_10 ) ;
F_7 ( L_6 , F_3 ( & V_17 ) ) ;
return V_3 ;
}
int F_11 ( void )
{
int V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
V_24 = F_12 ( L_7 , NULL ) ;
if ( V_24 == F_13 ( - V_25 ) ) {
F_7 ( L_8 ) ;
return 0 ;
}
if ( ! V_24 ) {
F_7 ( L_9 ) ;
return - 1 ;
}
for ( V_19 = 0 ; V_19 < F_14 ( V_26 ) ; V_19 ++ ) {
V_23 = & V_26 [ V_19 ] ;
V_21 = F_15 ( V_23 -> V_27 ,
V_23 -> V_28 ,
V_24 ,
& V_23 -> V_29 ,
& V_23 -> V_30 ) ;
if ( ! V_21 ) {
F_7 ( L_10 , V_23 -> V_27 ) ;
F_16 ( V_24 ) ;
return - 1 ;
}
}
return 0 ;
}
void F_17 ( void )
{
F_16 ( V_24 ) ;
}
