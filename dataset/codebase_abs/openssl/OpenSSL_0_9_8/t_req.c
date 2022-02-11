int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 * V_3 ;
int V_4 ;
if ( ( V_3 = F_2 ( F_3 () ) ) == NULL )
{
F_4 ( V_5 , V_6 ) ;
return ( 0 ) ;
}
F_5 ( V_3 , V_1 , V_7 ) ;
V_4 = F_6 ( V_3 , V_2 ) ;
F_7 ( V_3 ) ;
return ( V_4 ) ;
}
int F_8 ( T_3 * V_8 , T_2 * V_2 , unsigned long V_9 , unsigned long V_10 )
{
unsigned long V_11 ;
int V_12 ;
const char * V_13 ;
T_4 * V_14 ;
T_5 * V_15 ;
F_9 ( V_16 ) * V_17 ;
F_9 ( V_18 ) * V_19 ;
char V_20 = ' ' ;
int V_21 = 0 ;
if( ( V_9 & V_22 ) == V_23 ) {
V_20 = '\n' ;
V_21 = 12 ;
}
if( V_9 == V_24 )
V_21 = 16 ;
V_14 = V_2 -> V_25 ;
if( ! ( V_10 & V_26 ) )
{
if ( F_10 ( V_8 , L_1 , 21 ) <= 0 ) goto V_27;
if ( F_10 ( V_8 , L_2 , 10 ) <= 0 ) goto V_27;
}
if( ! ( V_10 & V_28 ) )
{
V_13 = ( V_14 -> V_29 -> type == V_30 ) ? L_3 : L_4 ;
V_11 = 0 ;
for ( V_12 = 0 ; V_12 < V_14 -> V_29 -> V_31 ; V_12 ++ )
{ V_11 <<= 8 ; V_11 += V_14 -> V_29 -> V_32 [ V_12 ] ; }
if( F_11 ( V_8 , L_5 , L_4 , V_13 , V_11 , V_13 ,
V_11 ) <= 0 )
goto V_27;
}
if( ! ( V_10 & V_33 ) )
{
if ( F_11 ( V_8 , L_6 , V_20 ) <= 0 ) goto V_27;
if ( F_12 ( V_8 , V_14 -> V_34 , V_21 , V_9 ) < 0 ) goto V_27;
if ( F_10 ( V_8 , L_7 , 1 ) <= 0 ) goto V_27;
}
if( ! ( V_10 & V_35 ) )
{
if ( F_10 ( V_8 , L_8 , 33 ) <= 0 )
goto V_27;
if ( F_11 ( V_8 , L_9 , L_4 ) <= 0 )
goto V_27;
if ( F_13 ( V_8 , V_14 -> V_36 -> V_37 -> V_38 ) <= 0 )
goto V_27;
if ( F_14 ( V_8 , L_7 ) <= 0 )
goto V_27;
V_15 = F_15 ( V_2 ) ;
if ( V_15 == NULL )
{
F_11 ( V_8 , L_10 , L_4 ) ;
F_16 ( V_8 ) ;
}
else
#ifndef F_17
if ( V_15 -> type == V_39 )
{
F_11 ( V_8 , L_11 , L_4 ,
F_18 ( V_15 -> V_15 . V_40 -> V_41 ) ) ;
F_19 ( V_8 , V_15 -> V_15 . V_40 , 16 ) ;
}
else
#endif
#ifndef F_20
if ( V_15 -> type == V_42 )
{
F_11 ( V_8 , L_12 , L_4 ) ;
F_21 ( V_8 , V_15 -> V_15 . V_43 , 16 ) ;
}
else
#endif
#ifndef F_22
if ( V_15 -> type == V_44 )
{
F_11 ( V_8 , L_13 , L_4 ) ;
F_23 ( V_8 , V_15 -> V_15 . V_45 , 16 ) ;
}
else
#endif
F_11 ( V_8 , L_14 , L_4 ) ;
F_24 ( V_15 ) ;
}
if( ! ( V_10 & V_46 ) )
{
if( F_11 ( V_8 , L_15 , L_4 ) <= 0 )
goto V_27;
V_17 = V_2 -> V_25 -> V_47 ;
if ( F_25 ( V_17 ) == 0 )
{
if( F_11 ( V_8 , L_16 , L_4 ) <= 0 )
goto V_27;
}
else
{
for ( V_12 = 0 ; V_12 < F_25 ( V_17 ) ; V_12 ++ )
{
T_6 * V_48 ;
V_16 * V_49 ;
T_7 * V_50 = NULL ;
T_6 * V_51 ;
int V_52 , type = 0 , V_53 = 1 , V_54 = 0 ;
V_49 = F_26 ( V_17 , V_12 ) ;
if( F_27 ( F_28 ( V_49 -> V_55 ) ) )
continue;
if( F_11 ( V_8 , L_17 , L_4 ) <= 0 )
goto V_27;
if ( ( V_52 = F_13 ( V_8 , V_49 -> V_55 ) ) > 0 )
{
if ( V_49 -> V_56 )
{
V_51 = V_49 -> V_57 . V_56 ;
type = V_51 -> type ;
V_50 = V_51 -> V_57 . V_58 ;
}
else
{
V_54 = 0 ;
V_53 = F_29 ( V_49 -> V_57 . V_59 ) ;
V_60:
V_48 = F_30 ( V_49 -> V_57 . V_59 , V_54 ) ;
type = V_48 -> type ;
V_50 = V_48 -> V_57 . V_61 ;
}
}
for ( V_52 = 25 - V_52 ; V_52 > 0 ; V_52 -- )
if ( F_10 ( V_8 , L_18 , 1 ) != 1 ) goto V_27;
if ( F_14 ( V_8 , L_19 ) <= 0 ) goto V_27;
if ( ( type == V_62 ) ||
( type == V_63 ) ||
( type == V_64 ) )
{
if ( F_10 ( V_8 , ( char * ) V_50 -> V_32 , V_50 -> V_31 )
!= V_50 -> V_31 )
goto V_27;
F_14 ( V_8 , L_7 ) ;
}
else
{
F_14 ( V_8 , L_20 ) ;
}
if ( ++ V_54 < V_53 ) goto V_60;
}
}
}
if( ! ( V_10 & V_46 ) )
{
V_19 = F_31 ( V_2 ) ;
if( V_19 )
{
F_11 ( V_8 , L_21 , L_4 ) ;
for ( V_12 = 0 ; V_12 < F_32 ( V_19 ) ; V_12 ++ )
{
T_8 * V_65 ;
V_18 * V_66 ;
int V_52 ;
V_66 = F_33 ( V_19 , V_12 ) ;
if ( F_11 ( V_8 , L_17 , L_4 ) <= 0 ) goto V_27;
V_65 = F_34 ( V_66 ) ;
F_13 ( V_8 , V_65 ) ;
V_52 = F_35 ( V_66 ) ;
if ( F_11 ( V_8 , L_22 , V_52 ? L_23 : L_4 ) <= 0 )
goto V_27;
if( ! F_36 ( V_8 , V_66 , 0 , 16 ) )
{
F_11 ( V_8 , L_24 , L_4 ) ;
F_37 ( V_8 , V_66 -> V_57 ) ;
}
if ( F_10 ( V_8 , L_7 , 1 ) <= 0 ) goto V_27;
}
F_38 ( V_19 , V_67 ) ;
}
}
if( ! ( V_10 & V_68 ) )
{
if( ! F_39 ( V_8 , V_2 -> V_69 , V_2 -> V_70 ) ) goto V_27;
}
return ( 1 ) ;
V_27:
F_4 ( V_71 , V_6 ) ;
return ( 0 ) ;
}
int F_6 ( T_3 * V_8 , T_2 * V_2 )
{
return F_8 ( V_8 , V_2 , V_72 , V_24 ) ;
}
