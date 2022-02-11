static void
F_1 ( T_1 * V_1 )
{
V_1 -> V_2 . V_3 = 0.0 ;
}
static void
F_2 ( T_1 * V_1 , T_2 V_2 )
{
V_1 -> V_2 . V_3 = V_2 ;
}
static double
F_3 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_3 ;
}
static T_3
F_4 ( T_1 * V_1 , const char * V_4 , T_3 T_4 V_5 , T_5 * * V_6 )
{
char * V_7 = NULL ;
V_1 -> V_2 . V_3 = F_5 ( V_4 , & V_7 ) ;
if ( V_7 == V_4 || * V_7 != '\0' ) {
if ( V_6 != NULL )
* V_6 = F_6 ( L_1 , V_4 ) ;
return FALSE ;
}
if ( V_8 == V_9 ) {
if ( V_1 -> V_2 . V_3 == 0 ) {
if ( V_6 != NULL )
* V_6 = F_6 ( L_2 , V_4 ) ;
}
else if ( V_1 -> V_2 . V_3 == V_10 ) {
if ( V_6 != NULL )
* V_6 = F_6 ( L_3 , V_4 ) ;
}
else {
if ( V_6 != NULL )
* V_6 = F_6 ( L_4 ,
V_4 ) ;
}
return FALSE ;
}
return TRUE ;
}
static int
F_7 ( T_1 * V_1 V_5 , T_6 T_7 V_5 , int T_8 V_5 )
{
return V_11 ;
}
static void
F_8 ( T_1 * V_1 , T_6 T_7 V_5 , int T_8 V_5 , char * V_12 )
{
F_9 ( V_12 , V_11 , L_5 F_10 ( V_13 ) L_6 , V_1 -> V_2 . V_3 ) ;
}
static int
F_11 ( T_1 * V_1 V_5 , T_6 T_7 V_5 , int T_8 V_5 )
{
return V_11 ;
}
static void
F_12 ( T_1 * V_1 , T_6 T_7 V_5 , int T_8 V_5 , char * V_12 )
{
F_9 ( V_12 , V_11 , L_5 F_10 ( V_14 ) L_6 , V_1 -> V_2 . V_3 ) ;
}
static T_3
F_13 ( const T_1 * V_15 , const T_1 * V_16 )
{
return V_15 -> V_2 . V_3 == V_16 -> V_2 . V_3 ;
}
static T_3
F_14 ( const T_1 * V_15 , const T_1 * V_16 )
{
return V_15 -> V_2 . V_3 != V_16 -> V_2 . V_3 ;
}
static T_3
F_15 ( const T_1 * V_15 , const T_1 * V_16 )
{
return V_15 -> V_2 . V_3 > V_16 -> V_2 . V_3 ;
}
static T_3
F_16 ( const T_1 * V_15 , const T_1 * V_16 )
{
return V_15 -> V_2 . V_3 >= V_16 -> V_2 . V_3 ;
}
static T_3
F_17 ( const T_1 * V_15 , const T_1 * V_16 )
{
return V_15 -> V_2 . V_3 < V_16 -> V_2 . V_3 ;
}
static T_3
F_18 ( const T_1 * V_15 , const T_1 * V_16 )
{
return V_15 -> V_2 . V_3 <= V_16 -> V_2 . V_3 ;
}
void
F_19 ( void )
{
static T_9 V_17 = {
V_18 ,
L_7 ,
L_8 ,
0 ,
F_1 ,
NULL ,
F_4 ,
NULL ,
F_8 ,
F_7 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_2 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_3 ,
F_13 ,
F_14 ,
F_15 ,
F_16 ,
F_17 ,
F_18 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_9 V_19 = {
V_20 ,
L_9 ,
L_10 ,
0 ,
F_1 ,
NULL ,
F_4 ,
NULL ,
F_12 ,
F_11 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_2 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_3 ,
F_13 ,
F_14 ,
F_15 ,
F_16 ,
F_17 ,
F_18 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
F_20 ( V_18 , & V_17 ) ;
F_20 ( V_20 , & V_19 ) ;
}
