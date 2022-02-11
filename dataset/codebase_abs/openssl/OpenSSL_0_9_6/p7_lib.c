int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
if ( V_1 -> V_3 != NULL )
{
if ( V_2 == NULL )
return ( ( int ) V_1 -> V_4 ) ;
memcpy ( * V_2 , V_1 -> V_3 , ( int ) V_1 -> V_4 ) ;
* V_2 += V_1 -> V_4 ;
return ( ( int ) V_1 -> V_4 ) ;
}
V_5 += 4 ;
F_3 ( V_1 -> type , V_6 ) ;
if ( V_1 -> V_7 . V_8 != NULL )
{
V_5 += 4 ;
switch ( F_4 ( V_1 -> type ) )
{
case V_9 :
F_3 ( V_1 -> V_7 . V_10 , V_11 ) ;
break;
case V_12 :
F_3 ( V_1 -> V_7 . V_13 , V_14 ) ;
break;
case V_15 :
F_3 ( V_1 -> V_7 . V_16 , V_17 ) ;
break;
case V_18 :
F_3 ( V_1 -> V_7 . V_19 ,
V_20 ) ;
break;
case V_21 :
F_3 ( V_1 -> V_7 . V_22 , V_23 ) ;
break;
case V_24 :
F_3 ( V_1 -> V_7 . V_25 , V_26 ) ;
break;
default:
F_3 ( V_1 -> V_7 . V_27 , V_28 ) ;
break;
}
}
V_29 = V_5 ;
if ( V_2 == NULL ) return ( V_29 ) ;
V_30 = * V_2 ;
F_5 ( V_31 , V_32 ) ;
F_6 ( V_1 -> type , V_6 ) ;
if ( V_1 -> V_7 . V_8 != NULL )
{
F_5 ( 0 , V_33 ) ;
switch ( F_4 ( V_1 -> type ) )
{
case V_9 :
F_6 ( V_1 -> V_7 . V_10 , V_11 ) ;
break;
case V_12 :
F_6 ( V_1 -> V_7 . V_13 , V_14 ) ;
break;
case V_15 :
F_6 ( V_1 -> V_7 . V_16 , V_17 ) ;
break;
case V_18 :
F_6 ( V_1 -> V_7 . V_19 ,
V_20 ) ;
break;
case V_21 :
F_6 ( V_1 -> V_7 . V_22 , V_23 ) ;
break;
case V_24 :
F_6 ( V_1 -> V_7 . V_25 , V_26 ) ;
break;
default:
F_6 ( V_1 -> V_7 . V_27 , V_28 ) ;
break;
}
F_7 () ;
}
F_7 () ;
F_8 () ;
}
int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
int V_34 = 0 ;
F_2 ( V_1 ) ;
if ( V_1 -> V_3 != NULL )
{
if ( V_2 == NULL )
return ( ( int ) V_1 -> V_4 ) ;
memcpy ( * V_2 , V_1 -> V_3 , ( int ) V_1 -> V_4 ) ;
* V_2 += V_1 -> V_4 ;
return ( ( int ) V_1 -> V_4 ) ;
}
F_3 ( V_1 -> type , V_6 ) ;
if ( V_1 -> V_7 . V_8 != NULL )
{
V_29 = V_5 ;
switch ( F_4 ( V_1 -> type ) )
{
case V_9 :
F_3 ( V_1 -> V_7 . V_10 , V_11 ) ;
break;
case V_12 :
F_3 ( V_1 -> V_7 . V_13 , V_14 ) ;
break;
case V_15 :
F_3 ( V_1 -> V_7 . V_16 , V_17 ) ;
break;
case V_18 :
F_3 ( V_1 -> V_7 . V_19 ,
V_20 ) ;
break;
case V_21 :
F_3 ( V_1 -> V_7 . V_22 , V_23 ) ;
break;
case V_24 :
F_3 ( V_1 -> V_7 . V_25 , V_26 ) ;
break;
default:
F_3 ( V_1 -> V_7 . V_27 , V_28 ) ;
break;
}
V_34 = V_5 - V_29 ;
V_5 = V_29 + F_9 ( 1 , V_34 , 0 ) ;
}
F_10 () ;
F_6 ( V_1 -> type , V_6 ) ;
if ( V_1 -> V_7 . V_8 != NULL )
{
F_11 ( & V_30 , 1 , V_34 , 0 , V_33 ) ;
switch ( F_4 ( V_1 -> type ) )
{
case V_9 :
F_6 ( V_1 -> V_7 . V_10 , V_11 ) ;
break;
case V_12 :
F_6 ( V_1 -> V_7 . V_13 , V_14 ) ;
break;
case V_15 :
F_6 ( V_1 -> V_7 . V_16 , V_17 ) ;
break;
case V_18 :
F_6 ( V_1 -> V_7 . V_19 ,
V_20 ) ;
break;
case V_21 :
F_6 ( V_1 -> V_7 . V_22 , V_23 ) ;
break;
case V_24 :
F_6 ( V_1 -> V_7 . V_25 , V_26 ) ;
break;
default:
F_6 ( V_1 -> V_7 . V_27 , V_28 ) ;
break;
}
}
F_8 () ;
}
T_1 * F_12 ( T_1 * * V_1 , unsigned char * * V_2 , long V_4 )
{
F_13 ( V_1 , T_1 * , V_35 ) ;
if ( ( V_1 != NULL ) && ( ( * V_1 ) != NULL ) )
{
if ( ( * V_1 ) -> V_3 != NULL )
{
F_14 ( ( * V_1 ) -> V_3 ) ;
( * V_1 ) -> V_3 = NULL ;
}
( * V_1 ) -> V_4 = 0 ;
}
F_15 () ;
F_16 () ;
F_17 ( V_5 -> type , V_36 ) ;
if ( ! F_18 () )
{
int V_37 , V_38 , V_39 ;
long V_40 ;
if ( V_41 != ( V_42 |
V_33 | 0 ) )
{
V_43 . error = V_44 ;
V_43 . line = __LINE__ ;
goto V_45;
}
V_5 -> V_46 = 0 ;
V_43 . V_47 = V_43 . V_30 ;
V_37 = F_19 ( & V_43 . V_30 , & V_40 , & V_38 , & V_39 ,
( V_43 . V_48 & 1 ) ? ( V_4 + * V_2 - V_43 . V_47 ) : V_43 . V_49 ) ;
if ( V_37 & 0x80 ) { V_43 . line = __LINE__ ; goto V_45; }
V_43 . V_49 -= ( V_43 . V_30 - V_43 . V_47 ) ;
switch ( F_4 ( V_5 -> type ) )
{
case V_9 :
F_17 ( V_5 -> V_7 . V_10 , V_50 ) ;
break;
case V_12 :
F_17 ( V_5 -> V_7 . V_13 , V_51 ) ;
if ( V_5 -> V_7 . V_13 -> V_52 -> V_7 . V_8 == NULL )
V_5 -> V_46 = 1 ;
break;
case V_15 :
F_17 ( V_5 -> V_7 . V_16 , V_53 ) ;
break;
case V_18 :
F_17 ( V_5 -> V_7 . V_19 ,
V_54 ) ;
break;
case V_21 :
F_17 ( V_5 -> V_7 . V_22 , V_55 ) ;
break;
case V_24 :
F_17 ( V_5 -> V_7 . V_25 , V_56 ) ;
break;
default:
F_17 ( V_5 -> V_7 . V_27 , V_57 ) ;
break;
}
if ( V_37 == ( 1 | V_42 ) )
{
if ( ! F_20 ( & V_43 . V_30 , V_43 . V_49 ) )
{
V_43 . error = V_58 ;
V_43 . line = __LINE__ ;
goto V_45;
}
}
}
else
V_5 -> V_46 = 1 ;
F_21 ( V_1 , V_59 , V_60 ) ;
}
T_1 * V_35 ( void )
{
T_1 * V_5 = NULL ;
T_2 V_43 ;
F_22 ( V_5 , T_1 ) ;
V_5 -> type = F_23 ( V_61 ) ;
V_5 -> V_3 = NULL ;
V_5 -> V_4 = 0 ;
V_5 -> V_46 = 0 ;
V_5 -> V_7 . V_8 = NULL ;
return ( V_5 ) ;
F_24 ( V_62 ) ;
}
void V_59 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_25 ( V_1 ) ;
if ( V_1 -> type != NULL )
{
F_26 ( V_1 -> type ) ;
}
F_14 ( V_1 ) ;
}
void F_25 ( T_1 * V_1 )
{
if( V_1 == NULL )
return;
if ( V_1 -> V_3 != NULL ) F_14 ( V_1 -> V_3 ) ;
if ( V_1 -> V_7 . V_8 != NULL )
{
if ( V_1 -> type == NULL ) return;
switch ( F_4 ( V_1 -> type ) )
{
case V_9 :
F_27 ( V_1 -> V_7 . V_10 ) ;
break;
case V_12 :
F_28 ( V_1 -> V_7 . V_13 ) ;
break;
case V_15 :
F_29 ( V_1 -> V_7 . V_16 ) ;
break;
case V_18 :
F_30 ( V_1 -> V_7 . V_19 ) ;
break;
case V_21 :
F_31 ( V_1 -> V_7 . V_22 ) ;
break;
case V_24 :
F_32 ( V_1 -> V_7 . V_25 ) ;
break;
default:
F_33 ( V_1 -> V_7 . V_27 ) ;
break;
}
}
V_1 -> V_7 . V_8 = NULL ;
}
