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
break;
}
}
V_27 = V_5 ;
if ( V_2 == NULL ) return ( V_27 ) ;
V_28 = * V_2 ;
F_5 ( V_29 , V_30 ) ;
F_6 ( V_1 -> type , V_6 ) ;
if ( V_1 -> V_7 . V_8 != NULL )
{
F_5 ( 0 , V_31 ) ;
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
break;
}
F_7 () ;
}
F_7 () ;
F_8 () ;
}
T_1 * F_9 ( T_1 * * V_1 , unsigned char * * V_2 , long V_4 )
{
F_10 ( V_1 , T_1 * , V_32 ) ;
if ( ( V_1 != NULL ) && ( ( * V_1 ) != NULL ) )
{
if ( ( * V_1 ) -> V_3 != NULL )
{
Free ( ( char * ) ( * V_1 ) -> V_3 ) ;
( * V_1 ) -> V_3 = NULL ;
}
( * V_1 ) -> V_4 = 0 ;
}
F_11 () ;
F_12 () ;
F_13 ( V_5 -> type , V_33 ) ;
if ( ! F_14 () )
{
int V_34 , V_35 , V_36 ;
long V_37 ;
if ( V_38 != ( V_39 |
V_31 | 0 ) )
{
V_40 . error = V_41 ;
V_40 . line = __LINE__ ;
goto V_42;
}
V_5 -> V_43 = 0 ;
V_40 . V_44 = V_40 . V_28 ;
V_34 = F_15 ( & V_40 . V_28 , & V_37 , & V_35 , & V_36 ,
( V_40 . V_45 & 1 ) ? ( V_4 + * V_2 - V_40 . V_44 ) : V_40 . V_46 ) ;
if ( V_34 & 0x80 ) { V_40 . line = __LINE__ ; goto V_42; }
V_40 . V_46 -= ( V_40 . V_28 - V_40 . V_44 ) ;
switch ( F_4 ( V_5 -> type ) )
{
case V_9 :
F_13 ( V_5 -> V_7 . V_10 , V_47 ) ;
break;
case V_12 :
F_13 ( V_5 -> V_7 . V_13 , V_48 ) ;
if ( V_5 -> V_7 . V_13 -> V_49 -> V_7 . V_8 == NULL )
V_5 -> V_43 = 1 ;
break;
case V_15 :
F_13 ( V_5 -> V_7 . V_16 , V_50 ) ;
break;
case V_18 :
F_13 ( V_5 -> V_7 . V_19 ,
V_51 ) ;
break;
case V_21 :
F_13 ( V_5 -> V_7 . V_22 , V_52 ) ;
break;
case V_24 :
F_13 ( V_5 -> V_7 . V_25 , V_53 ) ;
break;
default:
V_40 . error = V_54 ;
V_40 . line = __LINE__ ;
goto V_42;
}
if ( V_34 == ( 1 | V_39 ) )
{
if ( ! F_16 ( & V_40 . V_28 , V_40 . V_46 ) )
{
V_40 . error = V_55 ;
V_40 . line = __LINE__ ;
goto V_42;
}
}
}
else
V_5 -> V_43 = 1 ;
F_17 ( V_1 , V_56 , V_57 ) ;
}
T_1 * V_32 ( void )
{
T_1 * V_5 = NULL ;
T_2 V_40 ;
F_18 ( V_5 , T_1 ) ;
V_5 -> type = F_19 ( V_58 ) ;
V_5 -> V_3 = NULL ;
V_5 -> V_4 = 0 ;
V_5 -> V_43 = 0 ;
V_5 -> V_7 . V_8 = NULL ;
return ( V_5 ) ;
F_20 ( V_59 ) ;
}
void V_56 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_21 ( V_1 ) ;
if ( V_1 -> type != NULL )
{
F_22 ( V_1 -> type ) ;
}
Free ( ( char * ) ( char * ) V_1 ) ;
}
void F_21 ( T_1 * V_1 )
{
if( V_1 == NULL )
return;
if ( V_1 -> V_3 != NULL ) Free ( ( char * ) V_1 -> V_3 ) ;
if ( V_1 -> V_7 . V_8 != NULL )
{
if ( V_1 -> type == NULL ) return;
switch ( F_4 ( V_1 -> type ) )
{
case V_9 :
F_23 ( V_1 -> V_7 . V_10 ) ;
break;
case V_12 :
F_24 ( V_1 -> V_7 . V_13 ) ;
break;
case V_15 :
F_25 ( V_1 -> V_7 . V_16 ) ;
break;
case V_18 :
F_26 ( V_1 -> V_7 . V_19 ) ;
break;
case V_21 :
F_27 ( V_1 -> V_7 . V_22 ) ;
break;
case V_24 :
F_28 ( V_1 -> V_7 . V_25 ) ;
break;
default:
break;
}
}
V_1 -> V_7 . V_8 = NULL ;
}
