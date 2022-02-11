int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
int V_3 = 0 ;
if ( V_1 == NULL ) return ( 0 ) ;
switch ( V_1 -> type )
{
case V_4 :
if ( V_2 != NULL )
F_2 ( V_2 , 0 , 0 , V_4 , V_5 ) ;
V_3 = 2 ;
break;
case V_6 :
case V_7 :
V_3 = F_3 ( V_1 -> V_8 . integer , V_2 ) ;
break;
case V_9 :
case V_10 :
V_3 = F_4 ( V_1 -> V_8 . V_11 , V_2 ) ;
break;
case V_12 :
V_3 = F_5 ( V_1 -> V_8 . V_13 , V_2 ) ;
break;
case V_14 :
V_3 = F_6 ( V_1 -> V_8 . V_15 , V_2 ) ;
break;
case V_16 :
V_3 = F_7 ( V_1 -> V_8 . V_17 , V_2 ) ;
break;
case V_18 :
V_3 = F_8 ( V_1 -> V_8 . V_19 , V_2 ) ;
break;
case V_20 :
V_3 = F_9 ( V_1 -> V_8 . V_21 , V_2 ) ;
break;
case V_22 :
V_3 = F_10 ( V_1 -> V_8 . V_23 , V_2 ) ;
break;
case V_24 :
V_3 = F_11 ( V_1 -> V_8 . V_25 , V_2 ) ;
break;
case V_26 :
V_3 = F_12 ( V_1 -> V_8 . V_27 , V_2 ) ;
break;
case V_28 :
V_3 = F_13 ( V_1 -> V_8 . V_29 , V_2 ) ;
break;
case V_30 :
V_3 = F_14 ( V_1 -> V_8 . V_31 , V_2 ) ;
break;
case V_32 :
V_3 = F_15 ( V_1 -> V_8 . V_33 , V_2 ) ;
break;
case V_34 :
V_3 = F_16 ( V_1 -> V_8 . V_35 , V_2 ) ;
break;
case V_36 :
V_3 = F_17 ( V_1 -> V_8 . V_37 , V_2 ) ;
break;
case V_38 :
case V_39 :
case V_40 :
default:
if ( V_1 -> V_8 . V_41 == NULL )
V_3 = 0 ;
else
{
V_3 = V_1 -> V_8 . V_41 -> V_42 ;
if ( V_2 != NULL )
{
memcpy ( * V_2 , V_1 -> V_8 . V_41 -> V_43 , V_3 ) ;
* V_2 += V_3 ;
}
}
break;
}
return ( V_3 ) ;
}
T_1 * F_18 ( T_1 * * V_1 , unsigned char * * V_2 , long V_42 )
{
T_1 * V_44 = NULL ;
unsigned char * V_45 , * V_46 , * V_47 ;
int V_48 , V_49 , V_50 ;
long V_51 ;
if ( ( V_1 == NULL ) || ( ( * V_1 ) == NULL ) )
{
if ( ( V_44 = F_19 () ) == NULL ) goto V_52;
}
else
V_44 = ( * V_1 ) ;
V_46 = * V_2 ;
V_45 = V_46 ;
V_47 = ( V_46 + V_42 ) ;
V_48 = F_20 ( & V_45 , & V_51 , & V_49 , & V_50 , V_42 ) ;
if ( V_48 & 0x80 ) goto V_52;
if( V_50 != V_5 ) V_49 = V_40 ;
F_21 ( V_44 ) ;
switch ( V_49 )
{
case V_4 :
V_46 = V_45 ;
V_44 -> V_8 . V_53 = NULL ;
break;
case V_6 :
if ( ( V_44 -> V_8 . integer =
F_22 ( NULL , & V_46 , V_47 - V_46 ) ) == NULL )
goto V_52;
break;
case V_9 :
if ( ( V_44 -> V_8 . V_11 =
F_23 ( NULL , & V_46 , V_47 - V_46 ) ) == NULL )
goto V_52;
break;
case V_12 :
if ( ( V_44 -> V_8 . V_13 =
F_24 ( NULL , & V_46 , V_47 - V_46 ) ) == NULL )
goto V_52;
break;
case V_14 :
if ( ( V_44 -> V_8 . V_15 =
F_25 ( NULL , & V_46 , V_47 - V_46 ) ) == NULL )
goto V_52;
break;
case V_30 :
if ( ( V_44 -> V_8 . V_31 =
F_26 ( NULL , & V_46 , V_47 - V_46 ) ) == NULL )
goto V_52;
break;
case V_28 :
if ( ( V_44 -> V_8 . V_29 =
F_27 ( NULL , & V_46 , V_47 - V_46 ) ) == NULL )
goto V_52;
break;
case V_16 :
if ( ( V_44 -> V_8 . V_17 =
F_28 ( NULL , & V_46 , V_47 - V_46 ) ) == NULL )
goto V_52;
break;
case V_18 :
if ( ( V_44 -> V_8 . V_19 =
F_29 ( NULL , & V_46 , V_47 - V_46 ) ) == NULL )
goto V_52;
break;
case V_20 :
if ( ( V_44 -> V_8 . V_21 =
F_30 ( NULL , & V_46 , V_47 - V_46 ) ) == NULL )
goto V_52;
break;
case V_22 :
if ( ( V_44 -> V_8 . V_23 =
F_31 ( NULL , & V_46 , V_47 - V_46 ) ) == NULL )
goto V_52;
break;
case V_24 :
if ( ( V_44 -> V_8 . V_25 =
F_32 ( NULL , & V_46 , V_47 - V_46 ) ) == NULL )
goto V_52;
break;
case V_26 :
if ( ( V_44 -> V_8 . V_27 =
F_33 ( NULL , & V_46 , V_47 - V_46 ) ) == NULL )
goto V_52;
break;
case V_32 :
if ( ( V_44 -> V_8 . V_33 =
F_34 ( NULL , & V_46 , V_47 - V_46 ) ) == NULL )
goto V_52;
break;
case V_34 :
if ( ( V_44 -> V_8 . V_35 =
F_35 ( NULL , & V_46 , V_47 - V_46 ) ) == NULL )
goto V_52;
break;
case V_36 :
if ( ( V_44 -> V_8 . V_37 =
F_36 ( NULL , & V_46 , V_47 - V_46 ) ) == NULL )
goto V_52;
break;
case V_38 :
case V_39 :
case V_40 :
default:
if ( ( V_44 -> V_8 . V_41 = F_37 () ) == NULL ) goto V_52;
V_44 -> V_8 . V_41 -> type = V_49 ;
V_51 += ( V_45 - V_46 ) ;
if ( ! F_38 ( V_44 -> V_8 . V_41 , V_46 , ( int ) V_51 ) ) goto V_52;
V_46 += V_51 ;
break;
}
V_44 -> type = V_49 ;
if ( V_1 != NULL ) ( * V_1 ) = V_44 ;
* V_2 = V_46 ;
return ( V_44 ) ;
V_52:
if ( ( V_44 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_44 ) ) ) F_39 ( V_44 ) ;
return ( NULL ) ;
}
T_1 * F_19 ( void )
{
T_1 * V_44 = NULL ;
T_2 V_54 ;
F_40 ( V_44 , T_1 ) ;
V_44 -> type = - 1 ;
V_44 -> V_8 . V_53 = NULL ;
return ( V_44 ) ;
F_41 ( V_55 ) ;
}
void F_39 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_21 ( V_1 ) ;
F_42 ( V_1 ) ;
}
int F_43 ( T_1 * V_1 )
{
if ( V_1 -> V_8 . V_53 != NULL )
return ( V_1 -> type ) ;
else
return ( 0 ) ;
}
void F_44 ( T_1 * V_1 , int type , void * V_8 )
{
if ( V_1 -> V_8 . V_53 != NULL )
F_21 ( V_1 ) ;
V_1 -> type = type ;
V_1 -> V_8 . V_53 = V_8 ;
}
static void F_21 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
if ( V_1 -> V_8 . V_53 != NULL )
{
switch ( V_1 -> type )
{
case V_16 :
F_45 ( V_1 -> V_8 . V_17 ) ;
break;
case V_4 :
break;
case V_6 :
case V_7 :
case V_9 :
case V_10 :
case V_12 :
case V_14 :
case V_39 :
case V_38 :
case V_56 :
case V_18 :
case V_20 :
case V_57 :
case V_22 :
case V_34 :
case V_36 :
case V_58 :
case V_30 :
case V_24 :
case V_26 :
case V_32 :
case V_28 :
case V_40 :
default:
F_46 ( ( V_59 * ) V_1 -> V_8 . V_53 ) ;
break;
}
V_1 -> type = 0 ;
V_1 -> V_8 . V_53 = NULL ;
}
}
