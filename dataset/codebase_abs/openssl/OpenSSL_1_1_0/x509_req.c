T_1 * F_1 ( T_2 * V_1 , T_3 * V_2 , const T_4 * V_3 )
{
T_1 * V_4 ;
T_5 * V_5 ;
int V_6 ;
T_3 * V_7 ;
V_4 = F_2 () ;
if ( V_4 == NULL ) {
F_3 ( V_8 , V_9 ) ;
goto V_10;
}
V_5 = & V_4 -> V_11 ;
V_5 -> V_12 -> V_13 = 1 ;
V_5 -> V_12 -> V_14 = F_4 ( 1 ) ;
if ( V_5 -> V_12 -> V_14 == NULL )
goto V_10;
V_5 -> V_12 -> V_14 [ 0 ] = 0 ;
if ( ! F_5 ( V_4 , F_6 ( V_1 ) ) )
goto V_10;
V_7 = F_7 ( V_1 ) ;
if ( V_7 == NULL )
goto V_10;
V_6 = F_8 ( V_4 , V_7 ) ;
if ( ! V_6 )
goto V_10;
if ( V_2 != NULL ) {
if ( ! F_9 ( V_4 , V_2 , V_3 ) )
goto V_10;
}
return ( V_4 ) ;
V_10:
F_10 ( V_4 ) ;
return ( NULL ) ;
}
T_3 * F_11 ( T_1 * V_15 )
{
if ( V_15 == NULL )
return ( NULL ) ;
return ( F_12 ( V_15 -> V_11 . V_16 ) ) ;
}
T_3 * F_13 ( T_1 * V_15 )
{
if ( V_15 == NULL )
return NULL ;
return ( F_14 ( V_15 -> V_11 . V_16 ) ) ;
}
T_6 * F_15 ( T_1 * V_15 )
{
return V_15 -> V_11 . V_16 ;
}
int F_16 ( T_1 * V_1 , T_3 * V_17 )
{
T_3 * V_18 = NULL ;
int V_19 = 0 ;
V_18 = F_11 ( V_1 ) ;
switch ( F_17 ( V_18 , V_17 ) ) {
case 1 :
V_19 = 1 ;
break;
case 0 :
F_3 ( V_20 ,
V_21 ) ;
break;
case - 1 :
F_3 ( V_20 , V_22 ) ;
break;
case - 2 :
#ifndef F_18
if ( F_19 ( V_17 ) == V_23 ) {
F_3 ( V_20 , V_24 ) ;
break;
}
#endif
#ifndef F_20
if ( F_19 ( V_17 ) == V_25 ) {
F_3 ( V_20 ,
V_26 ) ;
break;
}
#endif
F_3 ( V_20 , V_27 ) ;
}
F_21 ( V_18 ) ;
return ( V_19 ) ;
}
int F_22 ( int V_28 )
{
int V_6 , V_29 ;
for ( V_6 = 0 ; ; V_6 ++ ) {
V_29 = V_30 [ V_6 ] ;
if ( V_29 == V_31 )
return 0 ;
else if ( V_28 == V_29 )
return 1 ;
}
}
int * F_23 ( void )
{
return V_30 ;
}
void F_24 ( int * V_32 )
{
V_30 = V_32 ;
}
int F_25 ( const T_1 * V_15 )
{
return F_26 ( V_15 -> V_11 . V_33 ) ;
}
int F_27 ( const T_1 * V_15 , int V_29 , int V_34 )
{
return F_28 ( V_15 -> V_11 . V_33 , V_29 , V_34 ) ;
}
int F_29 ( const T_1 * V_15 , const T_7 * V_35 ,
int V_34 )
{
return F_30 ( V_15 -> V_11 . V_33 , V_35 , V_34 ) ;
}
T_8 * F_31 ( const T_1 * V_15 , int V_36 )
{
return F_32 ( V_15 -> V_11 . V_33 , V_36 ) ;
}
T_8 * F_33 ( T_1 * V_15 , int V_36 )
{
return F_34 ( V_15 -> V_11 . V_33 , V_36 ) ;
}
int F_35 ( T_1 * V_15 , T_8 * V_37 )
{
if ( F_36 ( & V_15 -> V_11 . V_33 , V_37 ) )
return 1 ;
return 0 ;
}
int F_37 ( T_1 * V_15 ,
const T_7 * V_35 , int type ,
const unsigned char * V_38 , int V_39 )
{
if ( F_38 ( & V_15 -> V_11 . V_33 , V_35 ,
type , V_38 , V_39 ) )
return 1 ;
return 0 ;
}
int F_39 ( T_1 * V_15 ,
int V_29 , int type ,
const unsigned char * V_38 , int V_39 )
{
if ( F_40 ( & V_15 -> V_11 . V_33 , V_29 ,
type , V_38 , V_39 ) )
return 1 ;
return 0 ;
}
int F_41 ( T_1 * V_15 ,
const char * V_40 , int type ,
const unsigned char * V_38 , int V_39 )
{
if ( F_42 ( & V_15 -> V_11 . V_33 , V_40 ,
type , V_38 , V_39 ) )
return 1 ;
return 0 ;
}
long F_43 ( const T_1 * V_15 )
{
return F_44 ( V_15 -> V_11 . V_12 ) ;
}
T_9 * F_45 ( const T_1 * V_15 )
{
return V_15 -> V_11 . V_41 ;
}
void F_46 ( const T_1 * V_15 , const T_10 * * V_42 ,
const T_11 * * V_43 )
{
if ( V_42 != NULL )
* V_42 = V_15 -> V_44 ;
if ( V_43 != NULL )
* V_43 = & V_15 -> V_45 ;
}
int F_47 ( const T_1 * V_15 )
{
return F_48 ( V_15 -> V_45 . V_46 ) ;
}
int F_49 ( T_1 * V_15 , unsigned char * * V_47 )
{
V_15 -> V_11 . V_48 . V_49 = 1 ;
return F_50 ( & V_15 -> V_11 , V_47 ) ;
}
