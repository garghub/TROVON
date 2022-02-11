int F_1 ( T_1 * V_1 , long V_2 )
{
if ( V_1 == NULL )
return ( 0 ) ;
if ( V_1 -> V_3 . V_2 == NULL ) {
if ( ( V_1 -> V_3 . V_2 = F_2 () ) == NULL )
return ( 0 ) ;
}
return ( F_3 ( V_1 -> V_3 . V_2 , V_2 ) ) ;
}
int F_4 ( T_1 * V_1 , T_2 * V_4 )
{
if ( V_1 == NULL )
return ( 0 ) ;
return ( F_5 ( & V_1 -> V_3 . V_5 , V_4 ) ) ;
}
int F_6 ( T_1 * V_1 , const T_3 * V_6 )
{
if ( V_1 == NULL )
return 0 ;
return F_7 ( & V_1 -> V_3 . V_7 , V_6 ) ;
}
int F_8 ( T_1 * V_1 , const T_3 * V_6 )
{
if ( V_1 == NULL )
return 0 ;
return F_7 ( & V_1 -> V_3 . V_8 , V_6 ) ;
}
int F_9 ( T_1 * V_9 )
{
int V_10 ;
T_4 * V_11 ;
F_10 ( V_9 -> V_3 . V_12 ) ;
for ( V_10 = 0 ; V_10 < F_11 ( V_9 -> V_3 . V_12 ) ; V_10 ++ ) {
V_11 = F_12 ( V_9 -> V_3 . V_12 , V_10 ) ;
V_11 -> V_13 = V_10 ;
}
V_9 -> V_3 . V_14 . V_15 = 1 ;
return 1 ;
}
int F_13 ( T_1 * V_3 )
{
int V_10 ;
if ( F_14 ( & V_3 -> V_16 , 1 , & V_10 , V_3 -> V_17 ) <= 0 )
return 0 ;
F_15 ( L_1 , V_3 ) ;
F_16 ( V_10 < 2 ) ;
return ( ( V_10 > 1 ) ? 1 : 0 ) ;
}
long F_17 ( const T_1 * V_3 )
{
return F_18 ( V_3 -> V_3 . V_2 ) ;
}
const T_3 * F_19 ( const T_1 * V_3 )
{
return V_3 -> V_3 . V_7 ;
}
const T_3 * F_20 ( const T_1 * V_3 )
{
return V_3 -> V_3 . V_8 ;
}
T_3 * F_21 ( T_1 * V_3 )
{
return V_3 -> V_3 . V_7 ;
}
T_3 * F_22 ( T_1 * V_3 )
{
return V_3 -> V_3 . V_8 ;
}
T_2 * F_23 ( const T_1 * V_3 )
{
return V_3 -> V_3 . V_5 ;
}
void F_24 ( const T_1 * V_3 , const T_5 * * V_18 ,
const T_6 * * V_19 )
{
if ( V_18 != NULL )
* V_18 = & V_3 -> V_20 ;
if ( V_19 != NULL )
* V_19 = & V_3 -> V_21 ;
}
int F_25 ( const T_1 * V_3 )
{
return F_26 ( V_3 -> V_21 . V_22 ) ;
}
const T_3 * F_27 ( const T_4 * V_1 )
{
return V_1 -> V_23 ;
}
int F_28 ( T_4 * V_1 , T_3 * V_6 )
{
T_3 * V_24 ;
if ( V_1 == NULL )
return ( 0 ) ;
V_24 = V_1 -> V_23 ;
if ( V_24 != V_6 ) {
V_24 = F_29 ( V_6 ) ;
if ( V_24 != NULL ) {
F_30 ( V_1 -> V_23 ) ;
V_1 -> V_23 = V_24 ;
}
}
return ( V_24 != NULL ) ;
}
const T_7 * F_31 ( const T_4 * V_1 )
{
return & V_1 -> V_25 ;
}
int F_32 ( T_4 * V_1 , T_7 * V_26 )
{
T_7 * V_24 ;
if ( V_1 == NULL )
return ( 0 ) ;
V_24 = & V_1 -> V_25 ;
if ( V_24 != V_26 )
return F_33 ( V_24 , V_26 ) ;
return 1 ;
}
int F_34 ( T_1 * V_3 , unsigned char * * V_27 )
{
V_3 -> V_3 . V_14 . V_15 = 1 ;
return F_35 ( & V_3 -> V_3 , V_27 ) ;
}
