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
V_6 = F_5 ( V_3 , V_2 , V_1 ,
false , false ) ;
if ( V_7 )
F_6 ( L_2 , V_3 , V_1 ,
V_6 ? L_3 : L_4 ) ;
return V_6 ;
}
static int F_7 ( const char * V_1 ,
const char * V_2 )
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
int F_9 ( int V_8 , const char * * V_9 ,
const char * T_2 V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
char V_2 [ V_15 ] ;
char const * V_16 = NULL ,
* V_17 = NULL ;
const struct V_18 V_19 [] = {
F_10 ( 'a' , L_6 , & V_16 ,
L_7 , L_8 ) ,
F_10 ( 'r' , L_9 , & V_17 , L_7 ,
L_10 ) ,
F_11 ( 'v' , L_11 , & V_7 , L_12 ) ,
F_12 ()
} ;
const char * const V_20 [] = {
L_13 ,
NULL
} ;
V_8 = F_13 ( V_8 , V_9 , V_19 ,
V_20 , 0 ) ;
if ( F_14 () < 0 )
return - 1 ;
F_15 () ;
snprintf ( V_2 , sizeof( V_2 ) , L_14 , V_21 ) ;
if ( V_16 ) {
V_12 = F_16 ( true , V_16 ) ;
if ( V_12 ) {
F_17 (pos, list)
if ( F_1 ( V_14 -> V_22 , V_2 ) ) {
if ( V_23 == V_24 ) {
F_3 ( L_15 ,
V_14 -> V_22 ) ;
continue;
}
F_18 ( L_16 ,
V_14 -> V_22 , strerror ( V_23 ) ) ;
}
F_19 ( V_12 ) ;
}
}
if ( V_17 ) {
V_12 = F_16 ( true , V_17 ) ;
if ( V_12 ) {
F_17 (pos, list)
if ( F_7 ( V_14 -> V_22 , V_2 ) ) {
if ( V_23 == V_25 ) {
F_3 ( L_17 ,
V_14 -> V_22 ) ;
continue;
}
F_18 ( L_18 ,
V_14 -> V_22 , strerror ( V_23 ) ) ;
}
F_19 ( V_12 ) ;
}
}
return 0 ;
}
