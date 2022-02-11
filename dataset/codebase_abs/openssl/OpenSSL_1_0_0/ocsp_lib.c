T_1 * F_1 ( const T_2 * V_1 , T_3 * V_2 , T_3 * V_3 )
{
T_4 * V_4 ;
T_5 * V_5 ;
T_6 * V_6 ;
#ifndef F_2
if( ! V_1 ) V_1 = F_3 () ;
#endif
if ( V_2 )
{
V_4 = F_4 ( V_2 ) ;
V_5 = F_5 ( V_2 ) ;
}
else
{
V_4 = F_6 ( V_3 ) ;
V_5 = NULL ;
}
V_6 = F_7 ( V_3 ) ;
return F_8 ( V_1 , V_4 , V_6 , V_5 ) ;
}
T_1 * F_8 ( const T_2 * V_1 ,
T_4 * V_7 ,
T_6 * V_8 ,
T_5 * V_9 )
{
int V_10 ;
unsigned int V_11 ;
T_7 * V_12 ;
T_1 * V_13 = NULL ;
unsigned char V_14 [ V_15 ] ;
if ( ! ( V_13 = F_9 () ) ) goto V_16;
V_12 = V_13 -> V_17 ;
if ( V_12 -> V_18 != NULL ) F_10 ( V_12 -> V_18 ) ;
if ( ( V_10 = F_11 ( V_1 ) ) == V_19 )
{
F_12 ( V_20 , V_21 ) ;
goto V_16;
}
if ( ! ( V_12 -> V_18 = F_13 ( V_10 ) ) ) goto V_16;
if ( ( V_12 -> V_22 = F_14 () ) == NULL ) goto V_16;
V_12 -> V_22 -> type = V_23 ;
if ( ! F_15 ( V_7 , V_1 , V_14 , & V_11 ) ) goto V_24;
if ( ! ( F_16 ( V_13 -> V_25 , V_14 , V_11 ) ) ) goto V_16;
F_17 ( V_8 -> V_26 , V_8 -> V_27 , V_14 , & V_11 , V_1 , NULL ) ;
if ( ! ( F_16 ( V_13 -> V_28 , V_14 , V_11 ) ) ) goto V_16;
if ( V_9 )
{
F_18 ( V_13 -> V_9 ) ;
if ( ! ( V_13 -> V_9 = F_19 ( V_9 ) ) ) goto V_16;
}
return V_13 ;
V_24:
F_12 ( V_20 , V_29 ) ;
V_16:
if ( V_13 ) F_20 ( V_13 ) ;
return NULL ;
}
int F_21 ( T_1 * V_30 , T_1 * V_31 )
{
int V_32 ;
V_32 = F_22 ( V_30 -> V_17 -> V_18 , V_31 -> V_17 -> V_18 ) ;
if ( V_32 ) return V_32 ;
V_32 = F_23 ( V_30 -> V_25 , V_31 -> V_25 ) ;
if ( V_32 ) return V_32 ;
return F_23 ( V_30 -> V_28 , V_31 -> V_28 ) ;
}
int F_24 ( T_1 * V_30 , T_1 * V_31 )
{
int V_32 ;
V_32 = F_21 ( V_30 , V_31 ) ;
if ( V_32 ) return V_32 ;
return F_25 ( V_30 -> V_9 , V_31 -> V_9 ) ;
}
int F_26 ( char * V_33 , char * * V_34 , char * * V_35 , char * * V_36 , int * V_37 )
{
char * V_38 , * V_39 ;
char * V_40 , * V_41 ;
V_39 = F_27 ( V_33 ) ;
if ( ! V_39 ) goto V_42;
* V_34 = NULL ;
* V_35 = NULL ;
* V_36 = NULL ;
V_38 = strchr ( V_39 , ':' ) ;
if ( ! V_38 ) goto V_43;
* ( V_38 ++ ) = '\0' ;
if ( ! strcmp ( V_39 , L_1 ) )
{
* V_37 = 0 ;
V_41 = L_2 ;
}
else if ( ! strcmp ( V_39 , L_3 ) )
{
* V_37 = 1 ;
V_41 = L_4 ;
}
else
goto V_43;
if ( ( V_38 [ 0 ] != '/' ) || ( V_38 [ 1 ] != '/' ) )
goto V_43;
V_38 += 2 ;
V_40 = V_38 ;
V_38 = strchr ( V_38 , '/' ) ;
if ( ! V_38 )
* V_36 = F_27 ( L_5 ) ;
else
{
* V_36 = F_27 ( V_38 ) ;
* V_38 = '\0' ;
}
if ( ! * V_36 ) goto V_42;
if ( ( V_38 = strchr ( V_40 , ':' ) ) )
{
* V_38 = 0 ;
V_41 = V_38 + 1 ;
}
else
{
if ( * V_37 ) V_41 = L_4 ;
else V_41 = L_2 ;
}
* V_35 = F_27 ( V_41 ) ;
if ( ! * V_35 ) goto V_42;
* V_34 = F_27 ( V_40 ) ;
if ( ! * V_34 ) goto V_42;
F_28 ( V_39 ) ;
return 1 ;
V_42:
F_12 ( V_44 , V_45 ) ;
goto V_16;
V_43:
F_12 ( V_44 , V_46 ) ;
V_16:
if ( V_39 ) F_28 ( V_39 ) ;
if ( * V_36 ) F_28 ( * V_36 ) ;
if ( * V_35 ) F_28 ( * V_35 ) ;
if ( * V_34 ) F_28 ( * V_34 ) ;
return 0 ;
}
