static int F_1 ( const char * V_1 , const char * V_2 )
{
char V_3 [ V_4 * 2 + 1 ] ;
T_1 V_5 [ V_4 ] ;
int V_6 ;
if ( F_2 ( V_1 , & V_5 , sizeof( V_5 ) ) < 0 ) {
F_3 ( L_1 , V_1 ) ;
return - 1 ;
}
F_4 ( V_5 , sizeof( V_5 ) , V_3 ) ;
V_6 = F_5 ( V_3 , V_2 , V_1 , false ) ;
if ( V_7 )
F_6 ( L_2 , V_3 , V_1 ,
V_6 ? L_3 : L_4 ) ;
return V_6 ;
}
static int F_7 ( const char * V_1 V_8 ,
const char * V_2 V_8 )
{
T_1 V_5 [ V_4 ] ;
char V_3 [ V_4 * 2 + 1 ] ;
int V_6 ;
if ( F_2 ( V_1 , & V_5 , sizeof( V_5 ) ) < 0 ) {
F_3 ( L_1 , V_1 ) ;
return - 1 ;
}
F_4 ( V_5 , sizeof( V_5 ) , V_3 ) ;
V_6 = F_8 ( V_3 , V_2 ) ;
if ( V_7 )
F_6 ( L_5 , V_3 , V_1 ,
V_6 ? L_3 : L_4 ) ;
return V_6 ;
}
static int F_9 ( void )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
char V_2 [ V_13 ] ;
snprintf ( V_2 , sizeof( V_2 ) , L_6 , V_14 ) ;
if ( V_15 ) {
V_10 = F_10 ( true , V_15 ) ;
if ( V_10 ) {
F_11 (pos, list)
if ( F_1 ( V_12 -> V_16 , V_2 ) ) {
if ( V_17 == V_18 ) {
F_3 ( L_7 ,
V_12 -> V_16 ) ;
continue;
}
F_12 ( L_8 ,
V_12 -> V_16 , strerror ( V_17 ) ) ;
}
F_13 ( V_10 ) ;
}
}
if ( V_19 ) {
V_10 = F_10 ( true , V_19 ) ;
if ( V_10 ) {
F_11 (pos, list)
if ( F_7 ( V_12 -> V_16 , V_2 ) ) {
if ( V_17 == V_20 ) {
F_3 ( L_9 ,
V_12 -> V_16 ) ;
continue;
}
F_12 ( L_10 ,
V_12 -> V_16 , strerror ( V_17 ) ) ;
}
F_13 ( V_10 ) ;
}
}
return 0 ;
}
int F_14 ( int V_21 , const char * * V_22 , const char * T_2 V_8 )
{
V_21 = F_15 ( V_21 , V_22 , V_23 ,
V_24 , 0 ) ;
if ( F_16 () < 0 )
return - 1 ;
F_17 () ;
return F_9 () ;
}
