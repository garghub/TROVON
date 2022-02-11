static int F_1 ( T_1 * * V_1 , T_1 * * V_2 )
{
return ( strcmp ( ( * V_1 ) -> V_3 , ( * V_2 ) -> V_3 ) ) ;
}
static void F_2 ( void )
{
V_4 = 0 ;
V_5 [ V_6 ] =
F_3 ( V_7 ) ;
V_5 [ V_8 ] =
F_3 ( V_9 ) ;
V_5 [ V_10 ] =
F_3 ( V_11 ) ;
V_5 [ V_12 ] =
F_3 ( V_13 ) ;
V_5 [ V_14 ] =
F_3 ( V_15 ) ;
V_16 [ V_17 ] =
F_4 ( V_18 ) ;
V_16 [ V_19 ] =
F_4 ( V_20 ) ;
}
int F_5 ( T_2 * V_21 , const T_3 * * V_22 ,
const T_4 * * V_23 , T_5 * * V_24 )
{
int V_25 ;
T_1 * V_26 ;
V_26 = V_21 -> V_27 ;
if ( V_26 == NULL ) return ( 0 ) ;
if ( V_24 != NULL )
{
T_5 V_28 ;
if ( V_21 -> V_29 == 0 )
* V_24 = NULL ;
else if ( V_30 == NULL )
{
* V_24 = NULL ;
}
else
{
V_28 . V_31 = V_21 -> V_29 ;
V_25 = F_6 ( V_30 , & V_28 ) ;
if ( V_25 >= 0 )
* V_24 = F_7 ( V_30 , V_25 ) ;
else
* V_24 = NULL ;
}
}
if ( ( V_22 == NULL ) || ( V_23 == NULL ) ) return ( 0 ) ;
switch ( V_26 -> V_32 & V_33 )
{
case V_34 :
V_25 = V_6 ;
break;
case V_35 :
V_25 = V_8 ;
break;
case V_36 :
V_25 = V_10 ;
break;
case V_37 :
V_25 = V_12 ;
break;
case V_38 :
V_25 = V_14 ;
break;
case V_39 :
V_25 = V_40 ;
break;
default:
V_25 = - 1 ;
break;
}
if ( ( V_25 < 0 ) || ( V_25 > V_41 ) )
* V_22 = NULL ;
else
{
if ( V_25 == V_40 )
* V_22 = F_8 () ;
else
* V_22 = V_5 [ V_25 ] ;
}
switch ( V_26 -> V_32 & V_42 )
{
case V_43 :
V_25 = V_17 ;
break;
case V_44 :
V_25 = V_19 ;
break;
default:
V_25 = - 1 ;
break;
}
if ( ( V_25 < 0 ) || ( V_25 > V_45 ) )
* V_23 = NULL ;
else
* V_23 = V_16 [ V_25 ] ;
if ( ( * V_22 != NULL ) && ( * V_23 != NULL ) )
return ( 1 ) ;
else
return ( 0 ) ;
}
static void F_9 ( T_6 * * V_46 , T_6 * V_47 ,
T_6 * * V_48 )
{
if ( V_47 == * V_48 ) return;
if ( V_47 == * V_46 )
* V_46 = V_47 -> V_49 ;
if ( V_47 -> V_50 != NULL )
V_47 -> V_50 -> V_49 = V_47 -> V_49 ;
if ( V_47 -> V_49 != NULL )
V_47 -> V_49 -> V_50 = V_47 -> V_50 ;
( * V_48 ) -> V_49 = V_47 ;
V_47 -> V_50 = * V_48 ;
V_47 -> V_49 = NULL ;
* V_48 = V_47 ;
}
char * F_10 ( T_1 * V_26 )
{
if ( V_26 != NULL )
return ( V_26 -> V_3 ) ;
return ( L_1 ) ;
}
int F_11 ( T_1 * V_26 , int * V_51 )
{
int V_52 = 0 , V_1 = 0 ;
const T_3 * V_22 ;
const T_4 * V_23 ;
T_2 V_53 ;
if ( V_26 != NULL )
{
V_53 . V_27 = V_26 ;
if ( ! F_5 ( & V_53 , & V_22 , & V_23 , NULL ) )
return ( 0 ) ;
V_1 = F_12 ( V_22 ) * 8 ;
if ( F_13 ( V_26 ) )
{
V_52 = F_14 ( V_26 ) * 8 ;
}
else
{
if ( V_26 -> V_54 & V_55 )
V_52 = 64 ;
else
V_52 = V_1 ;
}
}
if ( V_51 != NULL ) * V_51 = V_1 ;
return ( V_52 ) ;
}
static int F_15 ( T_5 * * V_1 , T_5 * * V_2 )
{
return ( ( * V_1 ) -> V_31 - ( * V_2 ) -> V_31 ) ;
}
int F_16 ( int V_31 , T_7 * V_56 )
{
T_5 * V_24 ;
F_17 ( T_5 ) * V_57 ;
V_24 = ( T_5 * ) Malloc ( sizeof( T_5 ) ) ;
V_24 -> V_31 = V_31 ;
V_24 -> V_58 = V_56 ;
if ( V_30 == NULL )
V_57 = V_30 = F_18 ( F_15 ) ;
else
V_57 = V_30 ;
if ( ( V_57 == NULL ) || ! F_19 ( V_57 , V_24 ) )
{
F_20 ( V_59 , V_60 ) ;
return ( 0 ) ;
}
else
return ( 1 ) ;
}
