int F_1 ( T_1 * V_1 , long V_2 )
{
if ( V_1 == NULL )
return ( 0 ) ;
if ( V_2 == 0 ) {
F_2 ( V_1 -> V_3 . V_2 ) ;
V_1 -> V_3 . V_2 = NULL ;
return ( 1 ) ;
}
if ( V_1 -> V_3 . V_2 == NULL ) {
if ( ( V_1 -> V_3 . V_2 = F_3 () ) == NULL )
return ( 0 ) ;
}
return ( F_4 ( V_1 -> V_3 . V_2 , V_2 ) ) ;
}
int F_5 ( T_1 * V_1 , T_2 * V_4 )
{
T_2 * V_5 ;
if ( V_1 == NULL )
return 0 ;
V_5 = & V_1 -> V_3 . V_6 ;
if ( V_5 != V_4 )
return F_6 ( V_5 , V_4 ) ;
return 1 ;
}
int F_7 ( T_1 * V_1 , T_3 * V_7 )
{
if ( V_1 == NULL )
return ( 0 ) ;
return ( F_8 ( & V_1 -> V_3 . V_8 , V_7 ) ) ;
}
int F_9 ( T_1 * V_1 , T_3 * V_7 )
{
if ( V_1 == NULL )
return ( 0 ) ;
return ( F_8 ( & V_1 -> V_3 . V_9 , V_7 ) ) ;
}
int F_10 ( T_4 * * V_10 , const T_4 * V_11 )
{
T_4 * V_5 ;
V_5 = * V_10 ;
if ( V_5 != V_11 ) {
V_5 = F_11 ( V_11 ) ;
if ( V_5 != NULL ) {
F_12 ( * V_10 ) ;
* V_10 = V_5 ;
}
}
return ( V_5 != NULL ) ;
}
int F_13 ( T_1 * V_1 , const T_4 * V_11 )
{
if ( V_1 == NULL )
return 0 ;
return F_10 ( & V_1 -> V_3 . V_12 . V_13 , V_11 ) ;
}
int F_14 ( T_1 * V_1 , const T_4 * V_11 )
{
if ( V_1 == NULL )
return 0 ;
return F_10 ( & V_1 -> V_3 . V_12 . V_14 , V_11 ) ;
}
int F_15 ( T_1 * V_1 , T_5 * V_15 )
{
if ( V_1 == NULL )
return ( 0 ) ;
return ( F_16 ( & ( V_1 -> V_3 . V_16 ) , V_15 ) ) ;
}
int F_17 ( T_1 * V_1 )
{
int V_17 ;
if ( F_18 ( & V_1 -> V_18 , 1 , & V_17 , V_1 -> V_19 ) <= 0 )
return 0 ;
F_19 ( L_1 , V_1 ) ;
F_20 ( V_17 < 2 ) ;
return ( ( V_17 > 1 ) ? 1 : 0 ) ;
}
long F_21 ( const T_1 * V_1 )
{
return F_22 ( V_1 -> V_3 . V_2 ) ;
}
const T_4 * F_23 ( const T_1 * V_1 )
{
return V_1 -> V_3 . V_12 . V_13 ;
}
const T_4 * F_24 ( const T_1 * V_1 )
{
return V_1 -> V_3 . V_12 . V_14 ;
}
T_4 * F_25 ( const T_1 * V_1 )
{
return V_1 -> V_3 . V_12 . V_13 ;
}
T_4 * F_26 ( const T_1 * V_1 )
{
return V_1 -> V_3 . V_12 . V_14 ;
}
int F_27 ( const T_1 * V_1 )
{
return F_28 ( F_29 ( V_1 -> V_20 . V_21 ) ) ;
}
T_6 * F_30 ( const T_1 * V_1 )
{
return V_1 -> V_3 . V_16 ;
}
void F_31 ( const T_1 * V_1 , const T_7 * * V_22 ,
const T_7 * * V_23 )
{
if ( V_22 != NULL )
* V_22 = V_1 -> V_3 . V_24 ;
if ( V_23 != NULL )
* V_23 = V_1 -> V_3 . V_25 ;
}
const T_8 * F_32 ( const T_1 * V_1 )
{
return & V_1 -> V_3 . V_26 ;
}
