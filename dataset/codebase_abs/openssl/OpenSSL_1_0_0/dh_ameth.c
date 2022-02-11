static void F_1 ( T_1 * V_1 )
{
F_2 ( V_1 -> V_1 . V_2 ) ;
}
static int F_3 ( T_1 * V_1 , T_2 * V_3 )
{
const unsigned char * V_4 , * V_5 ;
int V_6 , V_7 ;
int V_8 ;
void * V_9 ;
T_3 * V_10 ;
T_4 * V_11 ;
T_5 * V_12 = NULL ;
T_6 * V_2 = NULL ;
if ( ! F_4 ( NULL , & V_4 , & V_6 , & V_11 , V_3 ) )
return 0 ;
F_5 ( NULL , & V_8 , & V_9 , V_11 ) ;
if ( V_8 != V_13 )
{
F_6 ( V_14 , V_15 ) ;
goto V_16;
}
V_10 = V_9 ;
V_5 = V_10 -> V_17 ;
V_7 = V_10 -> V_18 ;
if ( ! ( V_2 = F_7 ( NULL , & V_5 , V_7 ) ) )
{
F_6 ( V_14 , V_19 ) ;
goto V_16;
}
if ( ! ( V_12 = F_8 ( NULL , & V_4 , V_6 ) ) )
{
F_6 ( V_14 , V_19 ) ;
goto V_16;
}
if ( ! ( V_2 -> V_20 = F_9 ( V_12 , NULL ) ) )
{
F_6 ( V_14 , V_21 ) ;
goto V_16;
}
F_10 ( V_12 ) ;
F_11 ( V_1 , V_2 ) ;
return 1 ;
V_16:
if ( V_12 )
F_10 ( V_12 ) ;
if ( V_2 )
F_2 ( V_2 ) ;
return 0 ;
}
static int F_12 ( T_2 * V_22 , const T_1 * V_1 )
{
T_6 * V_2 ;
void * V_9 = NULL ;
int V_8 ;
unsigned char * V_23 = NULL ;
int V_24 ;
T_3 * V_25 ;
T_5 * V_20 = NULL ;
V_2 = V_1 -> V_1 . V_2 ;
V_25 = F_13 () ;
V_25 -> V_18 = F_14 ( V_2 , & V_25 -> V_17 ) ;
if ( V_25 -> V_18 <= 0 )
{
F_6 ( V_26 , V_27 ) ;
goto V_16;
}
V_9 = V_25 ;
V_8 = V_13 ;
V_20 = F_15 ( V_2 -> V_20 , NULL ) ;
if ( ! V_20 )
goto V_16;
V_24 = F_16 ( V_20 , & V_23 ) ;
F_10 ( V_20 ) ;
if ( V_24 <= 0 )
{
F_6 ( V_26 , V_27 ) ;
goto V_16;
}
if ( F_17 ( V_22 , F_18 ( V_28 ) ,
V_8 , V_9 , V_23 , V_24 ) )
return 1 ;
V_16:
if ( V_23 )
F_19 ( V_23 ) ;
if ( V_9 )
F_20 ( V_9 ) ;
return 0 ;
}
static int F_21 ( T_1 * V_1 , T_7 * V_29 )
{
const unsigned char * V_4 , * V_5 ;
int V_6 , V_7 ;
int V_8 ;
void * V_9 ;
T_3 * V_10 ;
T_4 * V_11 ;
T_5 * V_30 = NULL ;
T_6 * V_2 = NULL ;
if ( ! F_22 ( NULL , & V_4 , & V_6 , & V_11 , V_29 ) )
return 0 ;
F_5 ( NULL , & V_8 , & V_9 , V_11 ) ;
if ( V_8 != V_13 )
goto V_31;
if ( ! ( V_30 = F_8 ( NULL , & V_4 , V_6 ) ) )
goto V_31;
V_10 = V_9 ;
V_5 = V_10 -> V_17 ;
V_7 = V_10 -> V_18 ;
if ( ! ( V_2 = F_7 ( NULL , & V_5 , V_7 ) ) )
goto V_31;
if ( ! ( V_2 -> V_32 = F_9 ( V_30 , NULL ) ) )
{
F_6 ( V_33 , V_34 ) ;
goto V_35;
}
if ( ! F_23 ( V_2 ) )
goto V_35;
F_11 ( V_1 , V_2 ) ;
F_10 ( V_30 ) ;
return 1 ;
V_31:
F_6 ( V_33 , V_36 ) ;
V_35:
F_2 ( V_2 ) ;
return 0 ;
}
static int F_24 ( T_7 * V_29 , const T_1 * V_1 )
{
T_3 * V_37 = NULL ;
T_5 * V_38 = NULL ;
unsigned char * V_39 = NULL ;
int V_40 ;
V_37 = F_13 () ;
if ( ! V_37 )
{
F_6 ( V_41 , V_27 ) ;
goto V_16;
}
V_37 -> V_18 = F_14 ( V_1 -> V_1 . V_2 , & V_37 -> V_17 ) ;
if ( V_37 -> V_18 <= 0 )
{
F_6 ( V_41 , V_27 ) ;
goto V_16;
}
V_37 -> type = V_13 ;
V_38 = F_15 ( V_1 -> V_1 . V_2 -> V_32 , NULL ) ;
if ( ! V_38 )
{
F_6 ( V_41 , V_34 ) ;
goto V_16;
}
V_40 = F_16 ( V_38 , & V_39 ) ;
F_10 ( V_38 ) ;
if ( ! F_25 ( V_29 , F_18 ( V_42 ) , 0 ,
V_13 , V_37 , V_39 , V_40 ) )
goto V_16;
return 1 ;
V_16:
if ( V_39 != NULL )
F_19 ( V_39 ) ;
if ( V_37 != NULL )
F_20 ( V_37 ) ;
if ( V_38 != NULL )
F_10 ( V_38 ) ;
return 0 ;
}
static void F_26 ( const T_8 * V_43 , T_9 * V_44 )
{
T_9 V_45 ;
if ( ! V_43 )
return;
if ( * V_44 < ( V_45 = ( T_9 ) F_27 ( V_43 ) ) )
* V_44 = V_45 ;
}
static int F_28 ( T_1 * V_1 ,
const unsigned char * * V_46 , int V_47 )
{
T_6 * V_2 ;
if ( ! ( V_2 = F_7 ( NULL , V_46 , V_47 ) ) )
{
F_6 ( V_48 , V_49 ) ;
return 0 ;
}
F_11 ( V_1 , V_2 ) ;
return 1 ;
}
static int F_29 ( const T_1 * V_1 , unsigned char * * V_46 )
{
return F_14 ( V_1 -> V_1 . V_2 , V_46 ) ;
}
static int F_30 ( T_10 * V_50 , const T_6 * V_51 , int V_52 ,
T_11 * V_53 , int V_8 )
{
unsigned char * V_54 = NULL ;
int V_55 = V_56 , V_57 = 0 ;
T_9 V_58 = 0 ;
const char * V_59 = NULL ;
T_8 * V_32 , * V_20 ;
if ( V_8 == 2 )
V_32 = V_51 -> V_32 ;
else
V_32 = NULL ;
if ( V_8 > 0 )
V_20 = V_51 -> V_20 ;
else
V_20 = NULL ;
F_26 ( V_51 -> V_4 , & V_58 ) ;
if ( V_58 == 0 )
{
V_55 = V_60 ;
goto V_16;
}
F_26 ( V_51 -> V_61 , & V_58 ) ;
F_26 ( V_20 , & V_58 ) ;
F_26 ( V_32 , & V_58 ) ;
if ( V_8 == 2 )
V_59 = L_1 ;
else if ( V_8 == 1 )
V_59 = L_2 ;
else
V_59 = L_3 ;
V_54 = F_31 ( V_58 + 10 ) ;
if ( V_54 == NULL )
{
V_55 = V_27 ;
goto V_16;
}
F_32 ( V_50 , V_52 , 128 ) ;
if ( F_33 ( V_50 , L_4 , V_59 , F_34 ( V_51 -> V_4 ) ) <= 0 )
goto V_16;
V_52 += 4 ;
if ( ! F_35 ( V_50 , L_5 , V_32 , V_54 , V_52 ) ) goto V_16;
if ( ! F_35 ( V_50 , L_6 , V_20 , V_54 , V_52 ) ) goto V_16;
if ( ! F_35 ( V_50 , L_7 , V_51 -> V_4 , V_54 , V_52 ) ) goto V_16;
if ( ! F_35 ( V_50 , L_8 , V_51 -> V_61 , V_54 , V_52 ) ) goto V_16;
if ( V_51 -> V_18 != 0 )
{
F_32 ( V_50 , V_52 , 128 ) ;
if ( F_33 ( V_50 , L_9 ,
( int ) V_51 -> V_18 ) <= 0 ) goto V_16;
}
V_57 = 1 ;
if ( 0 )
{
V_16:
F_6 ( V_62 , V_55 ) ;
}
if ( V_54 != NULL ) F_19 ( V_54 ) ;
return ( V_57 ) ;
}
static int F_36 ( const T_1 * V_1 )
{
return ( F_37 ( V_1 -> V_1 . V_2 ) ) ;
}
static int F_38 ( const T_1 * V_1 )
{
return F_34 ( V_1 -> V_1 . V_2 -> V_4 ) ;
}
static int F_39 ( const T_1 * V_63 , const T_1 * V_43 )
{
if ( F_40 ( V_63 -> V_1 . V_2 -> V_4 , V_43 -> V_1 . V_2 -> V_4 ) ||
F_40 ( V_63 -> V_1 . V_2 -> V_61 , V_43 -> V_1 . V_2 -> V_61 ) )
return 0 ;
else
return 1 ;
}
static int F_41 ( T_1 * V_64 , const T_1 * V_65 )
{
T_8 * V_63 ;
if ( ( V_63 = F_42 ( V_65 -> V_1 . V_2 -> V_4 ) ) == NULL )
return 0 ;
if ( V_64 -> V_1 . V_2 -> V_4 != NULL )
F_43 ( V_64 -> V_1 . V_2 -> V_4 ) ;
V_64 -> V_1 . V_2 -> V_4 = V_63 ;
if ( ( V_63 = F_42 ( V_65 -> V_1 . V_2 -> V_61 ) ) == NULL )
return 0 ;
if ( V_64 -> V_1 . V_2 -> V_61 != NULL )
F_43 ( V_64 -> V_1 . V_2 -> V_61 ) ;
V_64 -> V_1 . V_2 -> V_61 = V_63 ;
return 1 ;
}
static int F_44 ( const T_1 * V_63 )
{
if ( ! V_63 -> V_1 . V_2 -> V_4 || ! V_63 -> V_1 . V_2 -> V_61 )
return 1 ;
return 0 ;
}
static int F_45 ( const T_1 * V_63 , const T_1 * V_43 )
{
if ( F_39 ( V_63 , V_43 ) == 0 )
return 0 ;
if ( F_40 ( V_43 -> V_1 . V_2 -> V_20 , V_63 -> V_1 . V_2 -> V_20 ) != 0 )
return 0 ;
else
return 1 ;
}
static int F_46 ( T_10 * V_50 , const T_1 * V_1 , int V_52 ,
T_11 * V_53 )
{
return F_30 ( V_50 , V_1 -> V_1 . V_2 , V_52 , V_53 , 0 ) ;
}
static int F_47 ( T_10 * V_50 , const T_1 * V_1 , int V_52 ,
T_11 * V_53 )
{
return F_30 ( V_50 , V_1 -> V_1 . V_2 , V_52 , V_53 , 1 ) ;
}
static int F_48 ( T_10 * V_50 , const T_1 * V_1 , int V_52 ,
T_11 * V_53 )
{
return F_30 ( V_50 , V_1 -> V_1 . V_2 , V_52 , V_53 , 2 ) ;
}
int F_49 ( T_10 * V_50 , const T_6 * V_51 )
{
return F_30 ( V_50 , V_51 , 4 , NULL , 0 ) ;
}
