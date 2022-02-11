static void F_1 ( void )
{
F_2 () ;
}
void F_3 ( void )
{
F_4 ( F_1 ) ;
}
void F_2 ( void )
{
V_1 = 1 ;
}
T_1 F_5 ( T_2 V_2 )
{
T_1 V_3 ;
T_1 V_4 = V_1 ++ ;
if ( V_1 == V_5 )
{
V_1 = 1 ;
}
V_3 = ( ( T_1 ) ( ( V_4 & V_6 ) << V_7 ) ) | V_2 ;
return ( V_3 ) ;
}
T_3 F_6 ( T_1 V_8 )
{
T_2 V_9 ;
V_9 = F_7 ( V_8 ) ;
switch ( V_9 )
{
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
return ( TRUE ) ;
break;
default:
break;
}
return ( FALSE ) ;
}
T_2 F_8 ( T_1 V_8 )
{
T_2 V_9 ;
V_9 = F_7 ( V_8 ) ;
return ( V_9 ) ;
}
T_1 F_9 ( void )
{
return ( V_16 ) ;
}
T_1 F_10 ( void )
{
return ( V_17 ) ;
}
T_1 F_11 ( void )
{
return ( V_18 ) ;
}
T_3 F_12 ( T_1 V_8 )
{
return ( F_13 ( V_8 ) || F_14 ( V_8 ) ) ;
}
T_3 F_13 ( T_1 V_8 )
{
if ( V_8 == V_16 )
{
return ( TRUE ) ;
}
return ( FALSE ) ;
}
T_3 F_14 ( T_1 V_8 )
{
if ( V_8 == V_17 )
{
return ( TRUE ) ;
}
return ( FALSE ) ;
}
T_3 F_15 ( T_1 V_8 )
{
if ( V_8 == V_18 )
{
return ( TRUE ) ;
}
return ( FALSE ) ;
}
T_3 F_16 ( T_1 V_8 )
{
return ( ! F_12 ( V_8 ) && ! F_15 ( V_8 ) ) ;
}
T_4 * F_17 ( T_5 * V_19 , T_2 type , T_6 V_20 , T_6 V_21 , T_3 V_22 )
{
T_4 * V_23 = NULL ;
V_23 = ( T_4 * ) F_18 ( V_19 , V_20 ) ;
if ( V_23 != NULL )
{
return ( V_23 ) ;
}
V_23 = F_19 ( F_20 () , T_4 ) ;
V_23 -> V_20 = V_20 ;
V_23 -> type = type ;
V_23 -> V_21 = V_21 ;
V_23 -> V_24 = 0 ;
V_23 -> V_25 = 0 ;
V_23 -> V_26 = 0 ;
V_23 -> V_27 = 0 ;
V_23 -> V_22 = V_22 ;
V_23 -> V_28 = 0 ;
V_23 -> V_29 = 0 ;
V_23 -> V_30 = FALSE ;
F_21 ( V_19 , V_20 , ( void * ) V_23 ) ;
return ( V_23 ) ;
}
T_7 * F_22 ( T_5 * V_19 , T_4 * V_20 )
{
T_7 * V_31 = NULL ;
T_8 * V_23 = NULL ;
V_31 = ( T_7 * ) F_18 ( V_19 , V_20 -> V_21 ) ;
if ( V_31 == NULL )
{
V_31 = F_19 ( F_20 () , T_7 ) ;
V_31 -> V_21 = V_20 -> V_21 ;
V_31 -> V_32 = 0 ;
V_31 -> V_20 = F_23 ( F_20 () ) ;
F_21 ( V_19 , V_20 -> V_21 , ( void * ) V_31 ) ;
}
V_23 = F_19 ( F_20 () , T_8 ) ;
V_23 -> V_20 = V_20 -> V_20 ;
V_23 -> V_22 = V_20 -> V_22 ;
F_21 ( V_31 -> V_20 , V_20 -> V_20 , ( void * ) V_23 ) ;
V_31 -> V_32 ++ ;
return ( V_31 ) ;
}
void F_24 ( void )
{
V_33 = F_25 ( F_26 () , F_20 () ) ;
}
static void F_27 ( T_6 * V_34 , T_9 * V_35 , T_1 V_8 , T_6 V_36 )
{
V_34 [ V_37 ] = ( T_6 ) ( ( V_8 >> 32 ) & 0xffffffff ) ;
V_34 [ V_38 ] = ( T_6 ) ( ( V_8 & 0xffffffff ) >> 32 ) ;
V_34 [ V_39 ] = V_36 ;
V_35 [ 0 ] . V_40 = V_41 ;
V_35 [ 0 ] . V_35 = V_34 ;
V_35 [ 1 ] . V_40 = 0 ;
V_35 [ 1 ] . V_35 = NULL ;
}
static T_10 * F_28 ( T_1 V_8 , T_6 V_36 )
{
T_10 * V_42 = NULL ;
T_6 V_43 [ V_41 ] ;
T_9 V_44 [ 2 ] ;
F_27 ( V_43 , V_44 , V_8 , V_36 ) ;
V_42 = ( T_10 * ) F_29 ( V_33 , V_44 ) ;
return ( V_42 ) ;
}
const char * F_30 ( T_1 V_8 , T_6 V_36 )
{
T_10 * V_42 = NULL ;
const char * V_45 = NULL ;
V_42 = F_28 ( V_8 , V_36 ) ;
if ( V_42 != NULL )
{
V_45 = V_42 -> V_45 ;
}
return ( V_45 ) ;
}
void F_31 ( T_1 V_8 , T_6 V_36 , const char * V_46 )
{
T_10 * V_42 ;
T_6 V_43 [ V_41 ] ;
T_9 V_44 [ 2 ] ;
V_42 = F_28 ( V_8 , V_36 ) ;
if ( V_42 != NULL )
{
return;
}
V_42 = F_19 ( F_20 () , T_10 ) ;
V_42 -> V_35 . V_8 = V_8 ;
V_42 -> V_35 . V_47 = V_36 ;
V_42 -> V_35 . V_45 = V_42 ;
V_42 -> V_45 = F_32 ( F_20 () , V_46 ) ;
F_27 ( V_43 , V_44 , V_8 , V_36 ) ;
F_33 ( V_33 , V_44 , ( void * ) V_42 ) ;
}
