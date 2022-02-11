static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 ,
void * V_4 )
{
T_3 * V_5 = ( T_3 * ) * V_2 ;
switch ( V_1 ) {
case V_6 :
V_5 -> V_7 = 0 ;
V_5 -> V_8 = - 1 ;
V_5 -> V_9 = - 1 ;
V_5 -> V_10 = NULL ;
V_5 -> V_11 = NULL ;
#ifndef F_2
V_5 -> V_12 = NULL ;
V_5 -> V_13 = NULL ;
#endif
V_5 -> V_14 = NULL ;
V_5 -> V_15 = NULL ;
if ( ! F_3 ( V_16 , V_5 , & V_5 -> V_17 ) )
return 0 ;
break;
case V_18 :
F_4 ( V_16 , V_5 , & V_5 -> V_17 ) ;
F_5 ( V_5 -> V_14 ) ;
F_6 ( V_5 -> V_10 ) ;
F_7 ( V_5 -> V_11 ) ;
F_8 ( V_5 -> V_15 ) ;
F_9 ( V_5 -> V_19 ) ;
F_10 ( V_5 -> V_20 ) ;
F_11 ( V_5 -> V_21 ) ;
#ifndef F_2
F_12 ( V_5 -> V_12 , V_22 ) ;
F_13 ( V_5 -> V_13 ) ;
#endif
break;
}
return 1 ;
}
void * F_14 ( T_3 * V_23 , int V_24 )
{
return ( F_15 ( & V_23 -> V_17 , V_24 ) ) ;
}
T_3 * F_16 ( T_3 * * V_25 , const unsigned char * * V_26 , long V_27 )
{
const unsigned char * V_28 ;
T_3 * V_5 ;
int V_29 = 0 ;
V_28 = * V_26 ;
if ( V_25 == NULL || * V_25 == NULL )
V_29 = 1 ;
V_5 = F_17 ( V_25 , & V_28 , V_27 ) ;
if ( V_5 == NULL )
return NULL ;
V_27 -= V_28 - * V_26 ;
if ( V_27 > 0 && ! F_18 ( & V_5 -> V_14 , & V_28 , V_27 ) )
goto V_30;
* V_26 = V_28 ;
return V_5 ;
V_30:
if ( V_29 ) {
F_19 ( V_5 ) ;
if ( V_25 )
* V_25 = NULL ;
}
return NULL ;
}
static int F_20 ( T_3 * V_25 , unsigned char * * V_26 )
{
int V_27 , V_31 ;
unsigned char * V_32 = V_26 != NULL ? * V_26 : NULL ;
F_21 ( V_26 == NULL || * V_26 != NULL ) ;
V_27 = F_22 ( V_25 , V_26 ) ;
if ( V_27 <= 0 || V_25 == NULL )
return V_27 ;
V_31 = F_23 ( V_25 -> V_14 , V_26 ) ;
if ( V_31 < 0 ) {
if ( V_32 != NULL )
* V_26 = V_32 ;
return V_31 ;
}
V_27 += V_31 ;
return V_27 ;
}
int F_24 ( T_3 * V_25 , unsigned char * * V_26 )
{
int V_27 ;
unsigned char * V_33 ;
if ( V_26 == NULL || * V_26 != NULL )
return F_20 ( V_25 , V_26 ) ;
if ( ( V_27 = F_20 ( V_25 , NULL ) ) <= 0 )
return V_27 ;
* V_26 = V_33 = F_25 ( V_27 ) ;
if ( V_33 == NULL )
return - 1 ;
V_27 = F_20 ( V_25 , & V_33 ) ;
if ( V_27 <= 0 ) {
F_26 ( * V_26 ) ;
* V_26 = NULL ;
}
return V_27 ;
}
int F_27 ( T_3 * V_34 , unsigned char * * V_26 )
{
V_34 -> V_35 . V_36 . V_37 = 1 ;
return F_28 ( & V_34 -> V_35 , V_26 ) ;
}
void F_29 ( const T_4 * * V_38 ,
const T_5 * * V_39 , const T_3 * V_34 )
{
if ( V_38 )
* V_38 = & V_34 -> V_40 ;
if ( V_39 )
* V_39 = & V_34 -> V_41 ;
}
int F_30 ( const T_3 * V_34 )
{
return F_31 ( V_34 -> V_41 . V_42 ) ;
}
