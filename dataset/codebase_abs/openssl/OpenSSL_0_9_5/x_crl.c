int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_3 , V_4 ) ;
F_3 ( V_1 -> V_5 , V_6 ) ;
F_4 ( V_7 , V_1 -> V_8 ,
V_9 ) ;
F_5 () ;
F_6 ( V_1 -> V_3 , V_4 ) ;
F_6 ( V_1 -> V_5 , V_6 ) ;
F_7 ( V_7 , V_1 -> V_8 ,
V_9 ) ;
F_8 () ;
}
T_1 * F_9 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_10 )
{
F_10 ( V_1 , T_1 * , V_11 ) ;
F_11 () ;
F_12 () ;
F_13 ( V_12 -> V_3 , V_13 ) ;
F_13 ( V_12 -> V_5 , V_14 ) ;
F_14 ( V_7 , V_12 -> V_8 ,
V_15 , V_16 ) ;
F_15 ( V_1 , V_17 , V_18 ) ;
}
int F_16 ( T_2 * V_1 , unsigned char * * V_2 )
{
int V_19 = 0 ;
long V_20 = 0 ;
int (* F_17)( T_1 * * , T_1 * * );
F_2 ( V_1 ) ;
F_17 = F_18 ( V_1 -> V_21 , V_22 ) ;
F_19 ( V_1 -> V_21 ) ;
F_18 ( V_1 -> V_21 , F_17 ) ;
if ( ( V_1 -> V_23 != NULL ) && ( ( V_20 = F_20 ( V_1 -> V_23 ) ) != 0 ) )
{
F_3 ( V_1 -> V_23 , V_4 ) ;
}
F_3 ( V_1 -> V_24 , V_25 ) ;
F_3 ( V_1 -> V_26 , V_27 ) ;
F_3 ( V_1 -> V_28 , V_6 ) ;
if ( V_1 -> V_29 != NULL )
{ F_3 ( V_1 -> V_29 , V_6 ) ; }
F_4 ( T_1 , V_1 -> V_21 ,
F_1 ) ;
F_21 ( V_7 , V_1 -> V_8 ,
V_9 , 0 ,
V_30 , V_19 ) ;
F_5 () ;
if ( ( V_1 -> V_23 != NULL ) && ( V_20 != 0 ) )
{
F_6 ( V_1 -> V_23 , V_4 ) ;
}
F_6 ( V_1 -> V_24 , V_25 ) ;
F_6 ( V_1 -> V_26 , V_27 ) ;
F_6 ( V_1 -> V_28 , V_6 ) ;
if ( V_1 -> V_29 != NULL )
{ F_6 ( V_1 -> V_29 , V_6 ) ; }
F_7 ( T_1 , V_1 -> V_21 ,
F_1 ) ;
F_22 ( V_7 , V_1 -> V_8 ,
V_9 , 0 ,
V_30 , V_19 ) ;
F_8 () ;
}
T_2 * F_23 ( T_2 * * V_1 , unsigned char * * V_2 ,
long V_10 )
{
int V_31 , V_32 = 0 ;
F_10 ( V_1 , T_2 * , V_33 ) ;
F_11 () ;
F_12 () ;
F_24 ( V_12 -> V_23 , V_13 , V_34 ) ;
if ( V_12 -> V_23 != NULL )
V_32 = V_12 -> V_23 -> V_35 [ 0 ] ;
if ( ( V_32 == 0 ) && ( V_12 -> V_23 != NULL ) )
{
F_25 ( V_12 -> V_23 ) ;
V_12 -> V_23 = NULL ;
}
F_13 ( V_12 -> V_24 , V_36 ) ;
F_13 ( V_12 -> V_26 , V_37 ) ;
F_13 ( V_12 -> V_28 , V_14 ) ;
F_24 ( V_12 -> V_29 , V_38 , V_39 ) ;
if( ! V_12 -> V_29 )
F_24 ( V_12 -> V_29 , V_40 ,
V_41 ) ;
if ( V_12 -> V_21 != NULL )
{
while ( F_26 ( V_12 -> V_21 ) )
V_17 ( F_27 ( V_12 -> V_21 ) ) ;
}
F_14 ( T_1 , V_12 -> V_21 , F_9 ,
V_17 ) ;
if ( V_12 -> V_21 != NULL )
{
for ( V_31 = 0 ; V_31 < F_26 ( V_12 -> V_21 ) ; V_31 ++ )
{
F_28 ( V_12 -> V_21 , V_31 ) -> V_42 = V_31 ;
}
}
if ( V_12 -> V_8 != NULL )
{
while ( F_29 ( V_12 -> V_8 ) )
V_16 (
F_30 ( V_12 -> V_8 ) ) ;
}
F_31 ( V_7 , V_12 -> V_8 ,
V_15 ,
V_16 , 0 ,
V_30 ) ;
F_15 ( V_1 , V_43 , V_44 ) ;
}
int F_32 ( T_3 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_45 , F_16 ) ;
F_3 ( V_1 -> V_24 , V_25 ) ;
F_3 ( V_1 -> V_46 , V_47 ) ;
F_5 () ;
F_6 ( V_1 -> V_45 , F_16 ) ;
F_6 ( V_1 -> V_24 , V_25 ) ;
F_6 ( V_1 -> V_46 , V_47 ) ;
F_8 () ;
}
T_3 * F_33 ( T_3 * * V_1 , unsigned char * * V_2 , long V_10 )
{
F_10 ( V_1 , T_3 * , V_48 ) ;
F_11 () ;
F_12 () ;
F_13 ( V_12 -> V_45 , F_23 ) ;
F_13 ( V_12 -> V_24 , V_36 ) ;
F_13 ( V_12 -> V_46 , V_49 ) ;
F_15 ( V_1 , V_50 , V_51 ) ;
}
T_1 * V_11 ( void )
{
T_1 * V_12 = NULL ;
T_4 V_52 ;
F_34 ( V_12 , T_1 ) ;
F_35 ( V_12 -> V_3 , V_53 ) ;
F_35 ( V_12 -> V_5 , V_54 ) ;
V_12 -> V_8 = NULL ;
return ( V_12 ) ;
F_36 ( V_55 ) ;
}
T_2 * V_33 ( void )
{
T_2 * V_12 = NULL ;
T_4 V_52 ;
F_34 ( V_12 , T_2 ) ;
V_12 -> V_23 = NULL ;
F_35 ( V_12 -> V_24 , V_56 ) ;
F_35 ( V_12 -> V_26 , V_57 ) ;
F_35 ( V_12 -> V_28 , V_54 ) ;
V_12 -> V_29 = NULL ;
F_35 ( V_12 -> V_21 , V_58 ) ;
F_35 ( V_12 -> V_8 , V_59 ) ;
F_18 ( V_12 -> V_21 , V_60 ) ;
return ( V_12 ) ;
F_36 ( V_61 ) ;
}
T_3 * V_48 ( void )
{
T_3 * V_12 = NULL ;
T_4 V_52 ;
F_34 ( V_12 , T_3 ) ;
V_12 -> V_62 = 1 ;
F_35 ( V_12 -> V_45 , V_33 ) ;
F_35 ( V_12 -> V_24 , V_56 ) ;
F_35 ( V_12 -> V_46 , V_63 ) ;
return ( V_12 ) ;
F_36 ( V_64 ) ;
}
void V_17 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_25 ( V_1 -> V_3 ) ;
F_37 ( V_1 -> V_5 ) ;
F_38 ( V_1 -> V_8 , V_16 ) ;
Free ( V_1 ) ;
}
void V_43 ( T_2 * V_1 )
{
if ( V_1 == NULL ) return;
F_25 ( V_1 -> V_23 ) ;
F_39 ( V_1 -> V_24 ) ;
F_40 ( V_1 -> V_26 ) ;
F_37 ( V_1 -> V_28 ) ;
if ( V_1 -> V_29 )
F_37 ( V_1 -> V_29 ) ;
F_41 ( V_1 -> V_21 , V_17 ) ;
F_38 ( V_1 -> V_8 , V_16 ) ;
Free ( V_1 ) ;
}
void V_50 ( T_3 * V_1 )
{
int V_31 ;
if ( V_1 == NULL ) return;
V_31 = F_42 ( & V_1 -> V_62 , - 1 , V_65 ) ;
#ifdef F_43
F_43 ( L_1 , V_1 ) ;
#endif
if ( V_31 > 0 ) return;
#ifdef F_44
if ( V_31 < 0 )
{
fprintf ( V_66 , L_2 ) ;
abort () ;
}
#endif
V_43 ( V_1 -> V_45 ) ;
F_39 ( V_1 -> V_24 ) ;
F_45 ( V_1 -> V_46 ) ;
Free ( V_1 ) ;
}
static int V_60 ( T_1 * * V_1 , T_1 * * V_67 )
{
return ( F_46 (
( V_68 * ) ( * V_1 ) -> V_3 ,
( V_68 * ) ( * V_67 ) -> V_3 ) ) ;
}
static int V_22 ( T_1 * * V_1 , T_1 * * V_67 )
{
return ( ( * V_1 ) -> V_42 - ( * V_67 ) -> V_42 ) ;
}
