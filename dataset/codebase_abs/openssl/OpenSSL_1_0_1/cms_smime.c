static int F_1 ( T_1 * V_1 , T_1 * V_2 , unsigned int V_3 )
{
unsigned char V_4 [ 4096 ] ;
int V_5 = 0 , V_6 ;
T_1 * V_7 = NULL ;
if ( V_1 == NULL )
V_7 = F_2 ( F_3 () ) ;
else if ( V_3 & V_8 )
{
V_7 = F_2 ( F_4 () ) ;
F_5 ( V_7 , 0 ) ;
}
else
V_7 = V_1 ;
if( ! V_7 )
{
F_6 ( V_9 , V_10 ) ;
goto V_11;
}
for (; ; )
{
V_6 = F_7 ( V_2 , V_4 , sizeof( V_4 ) ) ;
if ( V_6 <= 0 )
{
if ( F_8 ( V_2 ) == V_12 )
{
if ( ! F_9 ( V_2 ) )
goto V_11;
}
if ( V_6 < 0 )
goto V_11;
break;
}
if ( V_7 && ( F_10 ( V_7 , V_4 , V_6 ) != V_6 ) )
goto V_11;
}
if( V_3 & V_8 )
{
if( ! F_11 ( V_7 , V_1 ) )
{
F_6 ( V_9 , V_13 ) ;
goto V_11;
}
}
V_5 = 1 ;
V_11:
if ( V_7 && ( V_7 != V_1 ) )
F_12 ( V_7 ) ;
return V_5 ;
}
static int F_13 ( T_2 * V_14 )
{
T_3 * * V_15 = F_14 ( V_14 ) ;
if ( ! V_15 || ! * V_15 )
{
F_6 ( V_16 , V_17 ) ;
return 0 ;
}
return 1 ;
}
static void F_15 ( T_1 * V_18 , T_1 * V_19 )
{
if ( V_19 )
{
T_1 * V_20 ;
do
{
V_20 = F_16 ( V_18 ) ;
F_12 ( V_18 ) ;
V_18 = V_20 ;
}
while ( V_18 != V_19 );
}
else
F_17 ( V_18 ) ;
}
int F_18 ( T_2 * V_14 , T_1 * V_1 , unsigned int V_3 )
{
T_1 * V_21 ;
int V_5 ;
if ( F_19 ( F_20 ( V_14 ) ) != V_22 )
{
F_6 ( V_23 , V_24 ) ;
return 0 ;
}
V_21 = F_21 ( V_14 , NULL ) ;
if ( ! V_21 )
return 0 ;
V_5 = F_1 ( V_1 , V_21 , V_3 ) ;
F_17 ( V_21 ) ;
return V_5 ;
}
T_2 * F_22 ( T_1 * V_2 , unsigned int V_3 )
{
T_2 * V_14 ;
V_14 = F_23 () ;
if ( ! V_14 )
return NULL ;
if ( ( V_3 & V_25 ) || F_24 ( V_14 , V_2 , NULL , V_3 ) )
return V_14 ;
F_25 ( V_14 ) ;
return NULL ;
}
int F_26 ( T_2 * V_14 , T_1 * V_26 , T_1 * V_1 ,
unsigned int V_3 )
{
T_1 * V_21 ;
int V_5 ;
if ( F_19 ( F_20 ( V_14 ) ) != V_27 )
{
F_6 ( V_28 , V_29 ) ;
return 0 ;
}
if ( ! V_26 && ! F_13 ( V_14 ) )
return 0 ;
V_21 = F_21 ( V_14 , V_26 ) ;
if ( ! V_21 )
return 0 ;
V_5 = F_1 ( V_1 , V_21 , V_3 ) ;
if ( V_5 )
V_5 = F_27 ( V_14 , V_21 , 1 ) ;
F_15 ( V_21 , V_26 ) ;
return V_5 ;
}
T_2 * F_28 ( T_1 * V_2 , const T_4 * V_30 ,
unsigned int V_3 )
{
T_2 * V_14 ;
if ( ! V_30 )
V_30 = F_29 () ;
V_14 = F_30 ( V_30 ) ;
if ( ! V_14 )
return NULL ;
if( ! ( V_3 & V_31 ) )
F_31 ( V_14 , 0 ) ;
if ( ( V_3 & V_25 ) || F_24 ( V_14 , V_2 , NULL , V_3 ) )
return V_14 ;
F_25 ( V_14 ) ;
return NULL ;
}
int F_32 ( T_2 * V_14 ,
const unsigned char * V_32 , T_5 V_33 ,
T_1 * V_26 , T_1 * V_1 , unsigned int V_3 )
{
T_1 * V_21 ;
int V_5 ;
if ( F_19 ( F_20 ( V_14 ) ) != V_34 )
{
F_6 ( V_35 ,
V_36 ) ;
return 0 ;
}
if ( ! V_26 && ! F_13 ( V_14 ) )
return 0 ;
if ( F_33 ( V_14 , NULL , V_32 , V_33 ) <= 0 )
return 0 ;
V_21 = F_21 ( V_14 , V_26 ) ;
if ( ! V_21 )
return 0 ;
V_5 = F_1 ( V_1 , V_21 , V_3 ) ;
F_15 ( V_21 , V_26 ) ;
return V_5 ;
}
T_2 * F_34 ( T_1 * V_2 , const T_6 * V_37 ,
const unsigned char * V_32 , T_5 V_33 ,
unsigned int V_3 )
{
T_2 * V_14 ;
if ( ! V_37 )
{
F_6 ( V_38 , V_39 ) ;
return NULL ;
}
V_14 = F_35 () ;
if ( ! V_14 )
return NULL ;
if ( ! F_33 ( V_14 , V_37 , V_32 , V_33 ) )
return NULL ;
if( ! ( V_3 & V_31 ) )
F_31 ( V_14 , 0 ) ;
if ( ( V_3 & ( V_25 | V_40 ) )
|| F_24 ( V_14 , V_2 , NULL , V_3 ) )
return V_14 ;
F_25 ( V_14 ) ;
return NULL ;
}
int F_36 ( T_2 * V_14 , T_7 * V_41 , T_8 * V_42 )
{
F_37 ( V_43 ) * V_44 ;
V_43 * V_45 ;
int V_6 , V_5 ;
int V_46 = 0 ;
V_44 = F_38 ( V_14 ) ;
if ( V_44 )
V_46 = V_14 -> V_47 . V_48 -> V_49 -> V_46 ;
for ( V_6 = 0 ; V_6 < F_39 ( V_44 ) ; V_6 ++ )
{
V_45 = F_40 ( V_44 , V_6 ) ;
if ( F_41 ( V_45 ) != V_50 )
continue;
if ( ! V_42 || ( F_42 ( V_45 , V_42 ) == 0 ) )
{
F_43 ( V_45 , V_41 ) ;
V_5 = F_44 ( V_14 , V_45 ) ;
F_43 ( V_45 , NULL ) ;
if ( V_42 )
{
if ( ! V_46 )
{
F_45 () ;
return 1 ;
}
if ( V_5 > 0 )
return 1 ;
F_6 ( V_51 ,
V_52 ) ;
return 0 ;
}
else if ( V_5 > 0 && V_46 )
return 1 ;
}
}
if ( ! V_42 && ! V_46 )
{
F_45 () ;
return 1 ;
}
F_6 ( V_51 , V_53 ) ;
return 0 ;
}
int F_46 ( T_2 * V_14 ,
unsigned char * V_32 , T_5 V_33 ,
unsigned char * V_54 , T_5 V_55 )
{
F_37 ( V_43 ) * V_44 ;
V_43 * V_45 ;
int V_6 , V_5 ;
V_44 = F_38 ( V_14 ) ;
for ( V_6 = 0 ; V_6 < F_39 ( V_44 ) ; V_6 ++ )
{
V_45 = F_40 ( V_44 , V_6 ) ;
if ( F_41 ( V_45 ) != V_56 )
continue;
if ( ! V_54 || ( F_47 ( V_45 , V_54 , V_55 ) == 0 ) )
{
F_48 ( V_45 , V_32 , V_33 ) ;
V_5 = F_44 ( V_14 , V_45 ) ;
F_48 ( V_45 , NULL , 0 ) ;
if ( V_5 > 0 )
return 1 ;
if ( V_54 )
{
F_6 ( V_57 ,
V_52 ) ;
return 0 ;
}
F_45 () ;
}
}
F_6 ( V_57 , V_53 ) ;
return 0 ;
}
int F_49 ( T_2 * V_14 ,
unsigned char * V_58 , T_9 V_59 )
{
F_37 ( V_43 ) * V_44 ;
V_43 * V_45 ;
int V_6 , V_5 ;
V_44 = F_38 ( V_14 ) ;
for ( V_6 = 0 ; V_6 < F_39 ( V_44 ) ; V_6 ++ )
{
V_45 = F_40 ( V_44 , V_6 ) ;
if ( F_41 ( V_45 ) != V_60 )
continue;
F_50 ( V_45 , V_58 , V_59 ) ;
V_5 = F_44 ( V_14 , V_45 ) ;
F_50 ( V_45 , NULL , 0 ) ;
if ( V_5 > 0 )
return 1 ;
}
F_6 ( V_61 , V_53 ) ;
return 0 ;
}
int F_51 ( T_2 * V_14 , T_7 * V_41 , T_8 * V_42 ,
T_1 * V_26 , T_1 * V_1 ,
unsigned int V_3 )
{
int V_5 ;
T_1 * V_21 ;
if ( F_19 ( F_20 ( V_14 ) ) != V_62 )
{
F_6 ( V_63 , V_64 ) ;
return 0 ;
}
if ( ! V_26 && ! F_13 ( V_14 ) )
return 0 ;
if ( V_3 & V_65 )
V_14 -> V_47 . V_48 -> V_49 -> V_46 = 1 ;
else
V_14 -> V_47 . V_48 -> V_49 -> V_46 = 0 ;
if ( ! V_41 && ! V_42 && ! V_26 && ! V_1 )
return 1 ;
if ( V_41 && ! F_36 ( V_14 , V_41 , V_42 ) )
return 0 ;
V_21 = F_21 ( V_14 , V_26 ) ;
if ( ! V_21 )
return 0 ;
V_5 = F_1 ( V_1 , V_21 , V_3 ) ;
F_15 ( V_21 , V_26 ) ;
return V_5 ;
}
int F_24 ( T_2 * V_14 , T_1 * V_66 , T_1 * V_26 , unsigned int V_3 )
{
T_1 * V_67 ;
int V_68 = 0 ;
if ( ! ( V_67 = F_21 ( V_14 , V_26 ) ) )
{
F_6 ( V_69 , V_10 ) ;
return 0 ;
}
F_52 ( V_66 , V_67 , V_3 ) ;
( void ) F_53 ( V_67 ) ;
if ( ! F_54 ( V_14 , V_67 ) )
{
F_6 ( V_69 , V_70 ) ;
goto V_11;
}
V_68 = 1 ;
V_11:
F_15 ( V_67 , V_26 ) ;
return V_68 ;
}
int F_55 ( T_2 * V_14 , T_1 * V_26 , T_1 * V_1 ,
unsigned int V_3 )
{
T_1 * V_21 ;
int V_5 ;
if ( F_19 ( F_20 ( V_14 ) ) != V_71 )
{
F_6 ( V_72 ,
V_73 ) ;
return 0 ;
}
if ( ! V_26 && ! F_13 ( V_14 ) )
return 0 ;
V_21 = F_21 ( V_14 , V_26 ) ;
if ( ! V_21 )
return 0 ;
V_5 = F_1 ( V_1 , V_21 , V_3 ) ;
F_15 ( V_21 , V_26 ) ;
return V_5 ;
}
T_2 * F_56 ( T_1 * V_2 , int V_74 , unsigned int V_3 )
{
T_2 * V_14 ;
if ( V_74 <= 0 )
V_74 = V_75 ;
V_14 = F_57 ( V_74 ) ;
if ( ! V_14 )
return NULL ;
if( ! ( V_3 & V_31 ) )
F_31 ( V_14 , 0 ) ;
if ( ( V_3 & V_25 ) || F_24 ( V_14 , V_2 , NULL , V_3 ) )
return V_14 ;
F_25 ( V_14 ) ;
return NULL ;
}
int F_55 ( T_2 * V_14 , T_1 * V_26 , T_1 * V_1 ,
unsigned int V_3 )
{
F_6 ( V_72 , V_76 ) ;
return 0 ;
}
T_2 * F_56 ( T_1 * V_2 , int V_74 , unsigned int V_3 )
{
F_6 ( V_77 , V_76 ) ;
return NULL ;
}
