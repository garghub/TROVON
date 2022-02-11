int F_1 ( T_1 * V_1 ,
unsigned char * V_2 , T_2 V_3 )
{
T_3 * V_4 ;
if ( V_1 -> type != V_5 )
{
F_2 ( V_6 , V_7 ) ;
return 0 ;
}
V_4 = V_1 -> V_8 . V_4 ;
V_4 -> V_2 = V_2 ;
if ( V_2 && V_3 < 0 )
V_3 = strlen ( ( char * ) V_2 ) ;
V_4 -> V_3 = V_3 ;
return 1 ;
}
T_1 * F_3 ( T_4 * V_9 ,
int V_10 , int V_11 , int V_12 ,
unsigned char * V_2 ,
T_2 V_3 ,
const T_5 * V_13 )
{
T_1 * V_1 = NULL ;
T_6 * V_14 ;
T_3 * V_4 ;
T_7 V_15 ;
T_8 * V_16 = NULL ;
unsigned char V_17 [ V_18 ] ;
int V_19 ;
V_14 = F_4 ( V_9 ) ;
if ( ! V_14 )
goto V_20;
if ( V_11 <= 0 )
V_11 = V_21 ;
if ( V_12 <= 0 )
V_12 = V_22 ;
if ( V_13 == NULL )
V_13 = V_14 -> V_23 -> V_24 ;
if ( V_13 == NULL )
{
F_2 ( V_25 , V_26 ) ;
return NULL ;
}
if ( V_11 != V_21 )
{
F_2 ( V_25 ,
V_27 ) ;
return NULL ;
}
V_16 = F_5 () ;
F_6 ( & V_15 ) ;
if ( F_7 ( & V_15 , V_13 , NULL , NULL , NULL ) <= 0 )
{
F_2 ( V_25 , V_28 ) ;
goto V_20;
}
V_19 = F_8 ( & V_15 ) ;
if ( V_19 > 0 )
{
if ( F_9 ( V_17 , V_19 ) <= 0 )
goto V_20;
if ( F_7 ( & V_15 , NULL , NULL , NULL , V_17 ) <= 0 )
{
F_2 ( V_25 ,
V_28 ) ;
goto V_20;
}
V_16 -> V_29 = F_10 () ;
if ( ! V_16 -> V_29 )
{
F_2 ( V_25 ,
V_30 ) ;
goto V_20;
}
if ( F_11 ( & V_15 , V_16 -> V_29 ) <= 0 )
{
F_2 ( V_25 ,
V_31 ) ;
goto V_20;
}
}
V_16 -> V_32 = F_12 ( F_13 ( & V_15 ) ) ;
F_14 ( & V_15 ) ;
V_1 = F_15 ( T_1 ) ;
if ( ! V_1 )
goto V_33;
V_1 -> V_8 . V_4 = F_15 ( T_3 ) ;
if ( ! V_1 -> V_8 . V_4 )
goto V_33;
V_1 -> type = V_5 ;
V_4 = V_1 -> V_8 . V_4 ;
F_16 ( V_4 -> V_34 ) ;
V_4 -> V_34 = F_5 () ;
if ( ! V_4 -> V_34 )
goto V_33;
V_4 -> V_34 -> V_32 = F_12 ( V_11 ) ;
V_4 -> V_34 -> V_29 = F_10 () ;
if ( ! V_4 -> V_34 -> V_29 )
goto V_33;
if( ! F_17 ( V_16 , F_18 ( T_8 ) ,
& V_4 -> V_34 -> V_29 -> V_35 . V_36 ) )
goto V_33;
V_4 -> V_34 -> V_29 -> type = V_37 ;
F_16 ( V_16 ) ;
V_16 = NULL ;
V_4 -> V_38 = F_19 ( V_10 , NULL , 0 , - 1 , - 1 ) ;
if ( ! V_4 -> V_38 )
goto V_20;
F_1 ( V_1 , V_2 , V_3 ) ;
V_4 -> V_39 = 0 ;
if ( ! F_20 ( V_14 -> V_40 , V_1 ) )
goto V_33;
return V_1 ;
V_33:
F_2 ( V_25 , V_30 ) ;
V_20:
F_14 ( & V_15 ) ;
if ( V_1 )
F_21 ( V_1 , T_1 ) ;
if ( V_16 )
F_16 ( V_16 ) ;
return NULL ;
}
static int F_22 ( unsigned char * V_41 , T_9 * V_42 ,
const unsigned char * V_43 , T_9 V_44 , T_7 * V_15 )
{
T_9 V_45 = F_23 ( V_15 ) ;
unsigned char * V_46 ;
int V_47 , V_48 = 0 ;
if ( V_44 < 2 * V_45 )
{
return 0 ;
}
if ( V_44 % V_45 )
{
return 0 ;
}
V_46 = F_24 ( V_44 ) ;
F_25 ( V_15 , V_46 + V_44 - 2 * V_45 , & V_47 ,
V_43 + V_44 - 2 * V_45 , V_45 * 2 ) ;
F_25 ( V_15 , V_46 , & V_47 ,
V_46 + V_44 - V_45 , V_45 ) ;
F_25 ( V_15 , V_46 , & V_47 , V_43 , V_44 - V_45 ) ;
F_26 ( V_15 , NULL , NULL , NULL , NULL ) ;
F_25 ( V_15 , V_46 , & V_47 , V_46 , V_44 ) ;
if ( ( ( V_46 [ 1 ] ^ V_46 [ 4 ] ) & ( V_46 [ 2 ] ^ V_46 [ 5 ] ) & ( V_46 [ 3 ] ^ V_46 [ 6 ] ) ) != 0xff )
{
goto V_20;
}
if ( V_44 < ( T_9 ) ( V_46 [ 0 ] - 4 ) )
{
goto V_20;
}
* V_42 = ( T_9 ) V_46 [ 0 ] ;
memcpy ( V_41 , V_46 + 4 , * V_42 ) ;
V_48 = 1 ;
V_20:
F_27 ( V_46 , V_44 ) ;
F_28 ( V_46 ) ;
return V_48 ;
}
static int F_29 ( unsigned char * V_41 , T_9 * V_42 ,
const unsigned char * V_43 , T_9 V_44 , T_7 * V_15 )
{
T_9 V_45 = F_23 ( V_15 ) ;
T_9 V_49 ;
int V_50 ;
V_49 = ( V_44 + 4 + V_45 - 1 ) / V_45 ;
V_49 *= V_45 ;
if ( V_49 < 2 * V_45 )
{
return 0 ;
}
if ( V_44 > 0xFF )
{
return 0 ;
}
if ( V_41 )
{
V_41 [ 0 ] = ( unsigned char ) V_44 ;
V_41 [ 1 ] = V_43 [ 0 ] ^ 0xFF ;
V_41 [ 2 ] = V_43 [ 1 ] ^ 0xFF ;
V_41 [ 3 ] = V_43 [ 2 ] ^ 0xFF ;
memcpy ( V_41 + 4 , V_43 , V_44 ) ;
if ( V_49 > V_44 + 4 )
F_9 ( V_41 + 4 + V_44 , V_49 - 4 - V_44 ) ;
F_30 ( V_15 , V_41 , & V_50 , V_41 , V_49 ) ;
F_30 ( V_15 , V_41 , & V_50 , V_41 , V_49 ) ;
}
* V_42 = V_49 ;
return 1 ;
}
int F_31 ( T_4 * V_9 , T_1 * V_1 ,
int V_51 )
{
T_10 * V_52 ;
T_3 * V_4 ;
const unsigned char * V_53 = NULL ;
int V_54 ;
int V_55 = 0 ;
T_8 * V_56 , * V_57 = NULL ;
T_7 V_58 ;
const T_5 * V_59 ;
unsigned char * V_60 = NULL ;
T_9 V_61 ;
V_52 = V_9 -> V_8 . V_62 -> V_23 ;
V_4 = V_1 -> V_8 . V_4 ;
F_6 ( & V_58 ) ;
if ( ! V_4 -> V_2 )
{
F_2 ( V_63 , V_64 ) ;
return 0 ;
}
V_56 = V_4 -> V_34 ;
if ( ! V_56 || F_32 ( V_56 -> V_32 ) != V_21 )
{
F_2 ( V_63 ,
V_27 ) ;
return 0 ;
}
if ( V_56 -> V_29 -> type == V_37 )
{
V_53 = V_56 -> V_29 -> V_35 . V_36 -> V_65 ;
V_54 = V_56 -> V_29 -> V_35 . V_36 -> V_66 ;
V_57 = F_33 ( NULL , & V_53 , V_54 ) ;
}
if ( V_57 == NULL )
{
F_2 ( V_63 ,
V_67 ) ;
return 0 ;
}
V_59 = F_34 ( V_57 -> V_32 ) ;
if( ! V_59 )
{
F_2 ( V_63 ,
V_68 ) ;
goto V_20;
}
if ( ! F_35 ( & V_58 , V_59 , NULL , NULL , NULL , V_51 ) )
goto V_20;
F_36 ( & V_58 , 0 ) ;
if( F_37 ( & V_58 , V_57 -> V_29 ) < 0 )
{
F_2 ( V_63 ,
V_31 ) ;
goto V_20;
}
V_56 = V_4 -> V_38 ;
if ( F_38 ( V_56 -> V_32 ,
( char * ) V_4 -> V_2 , V_4 -> V_3 ,
V_56 -> V_29 , & V_58 , V_51 ) < 0 )
{
F_2 ( V_63 , V_28 ) ;
goto V_20;
}
if ( V_51 )
{
if ( ! F_29 ( NULL , & V_61 , V_52 -> V_60 , V_52 -> V_61 , & V_58 ) )
goto V_20;
V_60 = F_24 ( V_61 ) ;
if ( ! V_60 )
goto V_20;
if ( ! F_29 ( V_60 , & V_61 , V_52 -> V_60 , V_52 -> V_61 , & V_58 ) )
goto V_20;
V_4 -> V_69 -> V_65 = V_60 ;
V_4 -> V_69 -> V_66 = V_61 ;
}
else
{
V_60 = F_24 ( V_4 -> V_69 -> V_66 ) ;
if ( ! V_60 )
{
F_2 ( V_63 ,
V_30 ) ;
goto V_20;
}
if ( ! F_22 ( V_60 , & V_61 ,
V_4 -> V_69 -> V_65 ,
V_4 -> V_69 -> V_66 , & V_58 ) )
{
F_2 ( V_63 ,
V_70 ) ;
goto V_20;
}
V_52 -> V_60 = V_60 ;
V_52 -> V_61 = V_61 ;
}
V_55 = 1 ;
V_20:
F_14 ( & V_58 ) ;
if ( ! V_55 && V_60 )
F_28 ( V_60 ) ;
F_16 ( V_57 ) ;
return V_55 ;
}
