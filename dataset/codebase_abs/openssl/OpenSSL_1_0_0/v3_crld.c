int F_1 ( T_1 * * V_1 , T_2 * V_2 ,
T_3 * V_3 )
{
F_2 ( V_4 ) * V_5 = NULL ;
F_2 ( V_6 ) * V_7 = NULL ;
if ( ! strncmp ( V_3 -> V_8 , L_1 , 9 ) )
{
V_5 = F_3 ( V_2 , V_3 -> V_9 ) ;
if ( ! V_5 )
goto V_10;
}
else if ( ! strcmp ( V_3 -> V_8 , L_2 ) )
{
int V_11 ;
F_2 ( T_3 ) * V_12 ;
T_4 * V_13 ;
V_13 = F_4 () ;
if ( ! V_13 )
return - 1 ;
V_12 = F_5 ( V_2 , V_3 -> V_9 ) ;
if ( ! V_12 )
{
F_6 ( V_14 ,
V_15 ) ;
return - 1 ;
}
V_11 = F_7 ( V_13 , V_12 , V_16 ) ;
F_8 ( V_2 , V_12 ) ;
V_7 = V_13 -> V_17 ;
V_13 -> V_17 = NULL ;
F_9 ( V_13 ) ;
if ( ! V_11 || F_10 ( V_7 ) <= 0 )
goto V_10;
if ( F_11 ( V_7 ,
F_10 ( V_7 ) - 1 ) -> V_18 )
{
F_6 ( V_14 ,
V_19 ) ;
goto V_10;
}
}
else
return 0 ;
if ( * V_1 )
{
F_6 ( V_14 ,
V_20 ) ;
goto V_10;
}
* V_1 = F_12 () ;
if ( ! * V_1 )
goto V_10;
if ( V_5 )
{
( * V_1 ) -> type = 0 ;
( * V_1 ) -> V_8 . V_21 = V_5 ;
}
else
{
( * V_1 ) -> type = 1 ;
( * V_1 ) -> V_8 . V_22 = V_7 ;
}
return 1 ;
V_10:
if ( V_5 )
F_13 ( V_5 , V_23 ) ;
if ( V_7 )
F_14 ( V_7 , V_24 ) ;
return - 1 ;
}
static int F_15 ( T_5 * * V_25 , char * V_9 )
{
F_2 ( T_3 ) * V_26 = NULL ;
const T_6 * V_27 ;
const char * V_28 ;
int V_29 , V_11 = 0 ;
V_26 = F_16 ( V_9 ) ;
if ( ! V_26 )
return 0 ;
if ( * V_25 )
return 0 ;
for ( V_29 = 0 ; V_29 < F_17 ( V_26 ) ; V_29 ++ )
{
V_28 = F_18 ( V_26 , V_29 ) -> V_8 ;
if ( ! * V_25 )
{
* V_25 = F_19 () ;
if ( ! * V_25 )
goto V_10;
}
for ( V_27 = V_30 ; V_27 -> V_31 ; V_27 ++ )
{
if ( ! strcmp ( V_27 -> V_32 , V_28 ) )
{
if ( ! F_20 ( * V_25 ,
V_27 -> V_33 , 1 ) )
goto V_10;
break;
}
}
if ( ! V_27 -> V_31 )
goto V_10;
}
V_11 = 1 ;
V_10:
F_21 ( V_26 , V_34 ) ;
return V_11 ;
}
static int F_22 ( T_7 * V_35 , const char * V_36 ,
T_5 * V_37 , int V_38 )
{
int V_39 = 1 ;
const T_6 * V_27 ;
F_23 ( V_35 , L_3 , V_38 , L_4 , V_36 , V_38 + 2 , L_4 ) ;
for ( V_27 = V_30 ; V_27 -> V_31 ; V_27 ++ )
{
if ( F_24 ( V_37 , V_27 -> V_33 ) )
{
if ( V_39 )
V_39 = 0 ;
else
F_25 ( V_35 , L_5 ) ;
F_25 ( V_35 , V_27 -> V_31 ) ;
}
}
if ( V_39 )
F_25 ( V_35 , L_6 ) ;
else
F_25 ( V_35 , L_7 ) ;
return 1 ;
}
static int F_26 ( int V_40 , T_8 * * V_41 , const T_9 * V_42 ,
void * V_43 )
{
T_1 * V_44 = ( T_1 * ) * V_41 ;
switch( V_40 )
{
case V_45 :
V_44 -> V_46 = NULL ;
break;
case V_47 :
if ( V_44 -> V_46 )
F_9 ( V_44 -> V_46 ) ;
break;
}
return 1 ;
}
static int F_27 ( T_7 * V_35 , T_1 * V_44 , int V_38 )
{
if ( V_44 -> type == 0 )
{
F_23 ( V_35 , L_8 , V_38 , L_4 ) ;
F_28 ( V_35 , V_44 -> V_8 . V_21 , V_38 ) ;
}
else
{
T_4 V_48 ;
V_48 . V_17 = V_44 -> V_8 . V_22 ;
F_23 ( V_35 , L_9 ,
V_38 , L_4 , V_38 + 2 , L_4 ) ;
F_29 ( V_35 , & V_48 , 0 , V_49 ) ;
F_25 ( V_35 , L_7 ) ;
}
return 1 ;
}
static int F_30 ( const T_10 * V_50 , void * V_51 , T_7 * V_35 ,
int V_38 )
{
T_11 * V_52 = V_51 ;
if ( V_52 -> V_53 )
F_27 ( V_35 , V_52 -> V_53 , V_38 ) ;
if ( V_52 -> V_54 > 0 )
F_23 ( V_35 , L_10 , V_38 , L_4 ) ;
if ( V_52 -> V_55 > 0 )
F_23 ( V_35 , L_11 , V_38 , L_4 ) ;
if ( V_52 -> V_56 > 0 )
F_23 ( V_35 , L_12 , V_38 , L_4 ) ;
if ( V_52 -> V_57 )
F_22 ( V_35 , L_13 ,
V_52 -> V_57 , V_38 ) ;
if ( V_52 -> V_58 > 0 )
F_23 ( V_35 , L_14 , V_38 , L_4 ) ;
if ( ! V_52 -> V_53 && ( V_52 -> V_54 <= 0 ) && ( V_52 -> V_55 <= 0 )
&& ( V_52 -> V_56 <= 0 ) && ! V_52 -> V_57
&& ( V_52 -> V_58 <= 0 ) )
F_23 ( V_35 , L_15 , V_38 , L_4 ) ;
return 1 ;
}
static int F_31 ( const T_10 * V_50 , void * V_59 , T_7 * V_35 ,
int V_38 )
{
F_2 ( V_60 ) * V_61 = V_59 ;
V_60 * V_62 ;
int V_29 ;
for( V_29 = 0 ; V_29 < F_32 ( V_61 ) ; V_29 ++ )
{
F_25 ( V_35 , L_7 ) ;
V_62 = F_33 ( V_61 , V_29 ) ;
if( V_62 -> V_53 )
F_27 ( V_35 , V_62 -> V_53 , V_38 ) ;
if( V_62 -> V_63 )
F_22 ( V_35 , L_16 , V_62 -> V_63 ,
V_38 ) ;
if( V_62 -> V_64 )
{
F_23 ( V_35 , L_17 , V_38 , L_4 ) ;
F_28 ( V_35 , V_62 -> V_64 , V_38 ) ;
}
}
return 1 ;
}
int F_34 ( T_1 * V_44 , T_4 * V_65 )
{
int V_29 ;
F_2 ( V_6 ) * V_66 ;
V_6 * V_67 ;
if ( ! V_44 || ( V_44 -> type != 1 ) )
return 1 ;
V_66 = V_44 -> V_8 . V_22 ;
V_44 -> V_46 = F_35 ( V_65 ) ;
if ( ! V_44 -> V_46 )
return 0 ;
for ( V_29 = 0 ; V_29 < F_10 ( V_66 ) ; V_29 ++ )
{
V_67 = F_11 ( V_66 , V_29 ) ;
if ( ! F_36 ( V_44 -> V_46 , V_67 , - 1 , V_29 ? 0 : 1 ) )
{
F_9 ( V_44 -> V_46 ) ;
V_44 -> V_46 = NULL ;
return 0 ;
}
}
if ( F_37 ( V_44 -> V_46 , NULL ) < 0 )
{
F_9 ( V_44 -> V_46 ) ;
V_44 -> V_46 = NULL ;
return 0 ;
}
return 1 ;
}
