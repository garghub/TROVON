T_1 * F_1 ( T_1 * V_1 , T_2 V_2 )
{
return F_2 ( V_1 , V_2 , 0 , 0 ) ;
}
T_1 * F_2 ( T_1 * V_1 , T_2 V_2 ,
int V_3 , long V_4 )
{
struct V_5 * V_6 ;
struct V_5 V_7 ;
V_6 = F_3 ( & V_2 , & V_7 ) ;
if ( V_6 == NULL ) {
F_4 ( V_8 , V_9 ) ;
return NULL ;
}
if ( V_3 || V_4 ) {
if ( ! F_5 ( V_6 , V_3 , V_4 ) )
return NULL ;
}
if ( ( V_6 -> V_10 >= 50 ) && ( V_6 -> V_10 < 150 ) )
return F_6 ( V_1 , V_2 , V_3 , V_4 ) ;
return F_7 ( V_1 , V_2 , V_3 , V_4 ) ;
}
int F_8 ( T_1 * V_2 )
{
if ( V_2 -> type == V_11 )
return F_9 ( V_2 ) ;
else if ( V_2 -> type == V_12 )
return F_10 ( V_2 ) ;
return 0 ;
}
T_3 * F_11 ( T_1 * V_2 ,
T_3 * * V_13 )
{
T_3 * V_14 ;
char * V_15 ;
int V_16 ;
if ( ! F_8 ( V_2 ) )
return NULL ;
if ( ! V_13 || ! * V_13 ) {
if ( ! ( V_14 = F_12 () ) )
return NULL ;
if ( V_13 )
* V_13 = V_14 ;
} else
V_14 = * V_13 ;
if ( V_2 -> type == V_11 ) {
if ( ! F_13 ( V_14 , V_2 -> V_7 , V_2 -> V_17 ) )
return NULL ;
return V_14 ;
}
if ( ! F_13 ( V_14 , NULL , V_2 -> V_17 + 2 ) )
return NULL ;
V_16 = V_2 -> V_17 + 2 + 1 ;
V_15 = ( char * ) V_14 -> V_7 ;
if ( V_2 -> V_7 [ 0 ] >= '5' )
F_14 ( V_15 , L_1 , V_16 ) ;
else
F_14 ( V_15 , L_2 , V_16 ) ;
F_15 ( V_15 , ( char * ) V_2 -> V_7 , V_16 ) ;
return V_14 ;
}
int F_16 ( T_1 * V_1 , const char * V_15 )
{
T_1 V_2 ;
V_2 . V_17 = strlen ( V_15 ) ;
V_2 . V_7 = ( unsigned char * ) V_15 ;
V_2 . V_18 = 0 ;
V_2 . type = V_12 ;
if ( ! F_8 ( & V_2 ) ) {
V_2 . type = V_11 ;
if ( ! F_8 ( & V_2 ) )
return 0 ;
}
if ( V_1 && ! F_17 ( ( V_19 * ) V_1 , ( V_19 * ) & V_2 ) )
return 0 ;
return 1 ;
}
static int F_18 ( struct V_5 * V_5 , const T_1 * V_2 )
{
if ( V_2 == NULL ) {
T_2 V_20 ;
time ( & V_20 ) ;
if ( F_3 ( & V_20 , V_5 ) )
return 1 ;
return 0 ;
}
if ( V_2 -> type == V_12 )
return F_19 ( V_5 , V_2 ) ;
else if ( V_2 -> type == V_11 )
return F_20 ( V_5 , V_2 ) ;
return 0 ;
}
int F_21 ( int * V_21 , int * V_22 ,
const T_1 * V_23 , const T_1 * V_24 )
{
struct V_5 V_25 , V_26 ;
if ( ! F_18 ( & V_25 , V_23 ) )
return 0 ;
if ( ! F_18 ( & V_26 , V_24 ) )
return 0 ;
return F_22 ( V_21 , V_22 , & V_25 , & V_26 ) ;
}
