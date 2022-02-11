static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 ,
void * V_4 )
{
T_3 * V_5 = ( T_3 * ) * V_2 ;
switch ( V_1 ) {
case V_6 :
V_5 -> V_7 = 0 ;
V_5 -> V_8 = NULL ;
V_5 -> V_9 = 0 ;
V_5 -> V_10 = - 1 ;
V_5 -> V_11 = NULL ;
V_5 -> V_12 = NULL ;
#ifndef F_2
V_5 -> V_13 = NULL ;
V_5 -> V_14 = NULL ;
#endif
V_5 -> V_15 = NULL ;
V_5 -> V_16 = NULL ;
F_3 ( V_17 , V_5 , & V_5 -> V_18 ) ;
break;
case V_19 :
if ( V_5 -> V_8 != NULL )
F_4 ( V_5 -> V_8 ) ;
V_5 -> V_8 = F_5 ( V_5 -> V_20 -> V_21 , NULL , 0 ) ;
break;
case V_22 :
F_6 ( V_17 , V_5 , & V_5 -> V_18 ) ;
F_7 ( V_5 -> V_15 ) ;
F_8 ( V_5 -> V_11 ) ;
F_9 ( V_5 -> V_12 ) ;
F_10 ( V_5 -> V_16 ) ;
F_11 ( V_5 -> V_23 ) ;
F_12 ( V_5 -> V_24 ) ;
F_13 ( V_5 -> V_25 ) ;
#ifndef F_2
F_14 ( V_5 -> V_13 , V_26 ) ;
F_15 ( V_5 -> V_14 ) ;
#endif
if ( V_5 -> V_8 != NULL )
F_4 ( V_5 -> V_8 ) ;
break;
}
return 1 ;
}
int F_16 ( T_3 * V_27 , int V_28 , void * V_29 )
{
return ( F_17 ( & V_27 -> V_18 , V_28 , V_29 ) ) ;
}
void * F_18 ( T_3 * V_27 , int V_28 )
{
return ( F_19 ( & V_27 -> V_18 , V_28 ) ) ;
}
T_3 * F_20 ( T_3 * * V_30 , const unsigned char * * V_31 , long V_32 )
{
const unsigned char * V_33 ;
T_3 * V_5 ;
V_33 = * V_31 ;
V_5 = F_21 ( V_30 , V_31 , V_32 ) ;
if ( ! V_5 )
return NULL ;
V_32 -= * V_31 - V_33 ;
if ( ! V_32 )
return V_5 ;
if ( ! F_22 ( & V_5 -> V_15 , V_31 , V_32 ) )
goto V_34;
return V_5 ;
V_34:
F_23 ( V_5 ) ;
return NULL ;
}
int F_24 ( T_3 * V_30 , unsigned char * * V_31 )
{
int V_32 ;
V_32 = F_25 ( V_30 , V_31 ) ;
if ( V_30 )
V_32 += F_26 ( V_30 -> V_15 , V_31 ) ;
return V_32 ;
}
int F_27 ( T_3 * V_35 , unsigned char * * V_31 )
{
V_35 -> V_20 -> V_36 . V_37 = 1 ;
return F_28 ( V_35 -> V_20 , V_31 ) ;
}
void F_29 ( T_4 * * V_38 , T_5 * * V_39 ,
const T_3 * V_35 )
{
if ( V_38 )
* V_38 = V_35 -> V_40 ;
if ( V_39 )
* V_39 = V_35 -> V_41 ;
}
int F_30 ( const T_3 * V_35 )
{
return F_31 ( V_35 -> V_41 -> V_42 ) ;
}
