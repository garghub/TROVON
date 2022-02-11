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
F_4 ( T_1 * V_1 , const char * V_4 , T_3 T_4 V_5 , T_5 V_6 )
{
char * V_7 = NULL ;
V_1 -> V_2 . V_3 = F_5 ( V_4 , & V_7 ) ;
if ( V_7 == V_4 || * V_7 != '\0' ) {
V_6 ( L_1 , V_4 ) ;
return FALSE ;
}
if ( V_8 == V_9 ) {
if ( V_1 -> V_2 . V_3 == 0 ) {
V_6 ( L_2 , V_4 ) ;
}
else if ( V_1 -> V_2 . V_3 == V_10 ) {
V_6 ( L_3 , V_4 ) ;
}
else {
V_6 ( L_4 ,
V_4 ) ;
}
return FALSE ;
}
return TRUE ;
}
static int
F_6 ( T_1 * V_1 V_5 , T_6 T_7 V_5 )
{
return 1 + 26 ;
}
static void
F_7 ( T_1 * V_1 , T_6 T_7 V_5 , char * V_11 )
{
sprintf ( V_11 , L_5 F_8 ( V_12 ) L_6 , V_1 -> V_2 . V_3 ) ;
}
static int
F_9 ( T_1 * V_1 V_5 , T_6 T_7 V_5 )
{
return 1 + 26 ;
}
static void
F_10 ( T_1 * V_1 , T_6 T_7 V_5 , char * V_11 )
{
sprintf ( V_11 , L_5 F_8 ( V_13 ) L_6 , V_1 -> V_2 . V_3 ) ;
}
static T_3
F_11 ( const T_1 * V_14 , const T_1 * V_15 )
{
return V_14 -> V_2 . V_3 == V_15 -> V_2 . V_3 ;
}
static T_3
F_12 ( const T_1 * V_14 , const T_1 * V_15 )
{
return V_14 -> V_2 . V_3 != V_15 -> V_2 . V_3 ;
}
static T_3
F_13 ( const T_1 * V_14 , const T_1 * V_15 )
{
return V_14 -> V_2 . V_3 > V_15 -> V_2 . V_3 ;
}
static T_3
F_14 ( const T_1 * V_14 , const T_1 * V_15 )
{
return V_14 -> V_2 . V_3 >= V_15 -> V_2 . V_3 ;
}
static T_3
F_15 ( const T_1 * V_14 , const T_1 * V_15 )
{
return V_14 -> V_2 . V_3 < V_15 -> V_2 . V_3 ;
}
static T_3
F_16 ( const T_1 * V_14 , const T_1 * V_15 )
{
return V_14 -> V_2 . V_3 <= V_15 -> V_2 . V_3 ;
}
void
F_17 ( void )
{
static T_8 V_16 = {
V_17 ,
L_7 ,
L_8 ,
0 ,
F_1 ,
NULL ,
F_4 ,
NULL ,
F_7 ,
F_6 ,
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
F_3 ,
F_11 ,
F_12 ,
F_13 ,
F_14 ,
F_15 ,
F_16 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_8 V_18 = {
V_19 ,
L_9 ,
L_10 ,
0 ,
F_1 ,
NULL ,
F_4 ,
NULL ,
F_10 ,
F_9 ,
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
F_3 ,
F_11 ,
F_12 ,
F_13 ,
F_14 ,
F_15 ,
F_16 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
F_18 ( V_17 , & V_16 ) ;
F_18 ( V_19 , & V_18 ) ;
}
