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
static bool F_9 ( struct V_8 * V_8 , int T_2 V_9 )
{
char V_1 [ V_10 ] ;
T_1 V_5 [ V_4 ] ;
if ( F_10 ( V_8 , V_1 , sizeof( V_1 ) ) &&
F_2 ( V_1 , V_5 ,
sizeof( V_5 ) ) != sizeof( V_5 ) ) {
if ( V_11 == V_12 )
return false ;
F_11 ( L_6 ,
V_1 ) ;
} else if ( memcmp ( V_8 -> V_5 , V_5 , sizeof( V_8 -> V_5 ) ) ) {
F_11 ( L_6 ,
V_1 ) ;
}
return true ;
}
static int F_12 ( const char * V_1 , bool V_13 , T_3 * V_14 )
{
struct V_15 * V_16 = F_13 ( V_1 , V_17 ,
V_13 , false , NULL ) ;
if ( V_16 == NULL )
return - 1 ;
F_14 ( V_16 , V_14 , F_9 , 0 ) ;
F_15 ( V_16 ) ;
return 0 ;
}
static int F_16 ( const char * V_1 ,
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
if ( ! V_6 ) {
V_6 = F_5 ( V_3 , V_2 , V_1 ,
false , false ) ;
}
if ( V_7 )
F_6 ( L_7 , V_3 , V_1 ,
V_6 ? L_3 : L_4 ) ;
return V_6 ;
}
int F_17 ( int V_18 , const char * * V_19 ,
const char * T_4 V_9 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_24 = 0 ;
bool V_13 = false ;
char V_2 [ V_10 ] ;
char const * V_25 = NULL ,
* V_26 = NULL ,
* V_27 = NULL ,
* V_28 = NULL ;
const struct V_29 V_30 [] = {
F_18 ( 'a' , L_8 , & V_25 ,
L_9 , L_10 ) ,
F_18 ( 'r' , L_11 , & V_26 , L_9 ,
L_12 ) ,
F_18 ( 'M' , L_13 , & V_27 , L_14 ,
L_15 ) ,
F_19 ( 'f' , L_16 , & V_13 , L_17 ) ,
F_18 ( 'u' , L_18 , & V_28 , L_9 ,
L_19 ) ,
F_20 ( 'v' , L_20 , & V_7 , L_21 ) ,
F_21 ()
} ;
const char * const V_31 [] = {
L_22 ,
NULL
} ;
V_18 = F_22 ( V_18 , V_19 , V_30 ,
V_31 , 0 ) ;
if ( F_23 () < 0 )
return - 1 ;
F_24 () ;
snprintf ( V_2 , sizeof( V_2 ) , L_23 , V_32 ) ;
if ( V_25 ) {
V_21 = F_25 ( true , V_25 ) ;
if ( V_21 ) {
F_26 (pos, list)
if ( F_1 ( V_23 -> V_33 , V_2 ) ) {
if ( V_11 == V_34 ) {
F_3 ( L_24 ,
V_23 -> V_33 ) ;
continue;
}
F_11 ( L_25 ,
V_23 -> V_33 , strerror ( V_11 ) ) ;
}
F_27 ( V_21 ) ;
}
}
if ( V_26 ) {
V_21 = F_25 ( true , V_26 ) ;
if ( V_21 ) {
F_26 (pos, list)
if ( F_7 ( V_23 -> V_33 , V_2 ) ) {
if ( V_11 == V_12 ) {
F_3 ( L_26 ,
V_23 -> V_33 ) ;
continue;
}
F_11 ( L_27 ,
V_23 -> V_33 , strerror ( V_11 ) ) ;
}
F_27 ( V_21 ) ;
}
}
if ( V_27 )
V_24 = F_12 ( V_27 , V_13 , stdout ) ;
if ( V_28 ) {
V_21 = F_25 ( true , V_28 ) ;
if ( V_21 ) {
F_26 (pos, list)
if ( F_16 ( V_23 -> V_33 , V_2 ) ) {
if ( V_11 == V_12 ) {
F_3 ( L_26 ,
V_23 -> V_33 ) ;
continue;
}
F_11 ( L_28 ,
V_23 -> V_33 , strerror ( V_11 ) ) ;
}
F_27 ( V_21 ) ;
}
}
return V_24 ;
}
