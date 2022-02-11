int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
#define F_2 (sizeof(long)*2)
int V_3 = 0 , V_4 = 0 , V_5 = 0 , V_6 = 0 , V_7 = 0 , V_8 = 0 , V_9 = 0 ;
unsigned char V_10 [ 4 ] , V_11 [ F_2 ] , V_12 [ F_2 ] ;
unsigned char V_13 [ F_2 ] , V_14 [ F_2 ] , V_15 [ F_2 ] ;
#ifndef F_3
int V_16 = 0 , V_17 = 0 , V_18 = 0 ;
unsigned char V_19 [ F_2 ] ;
#endif
#ifndef F_4
unsigned char V_20 ;
int V_21 = 0 ;
#endif
long V_22 ;
T_2 V_23 ;
F_5 ( V_1 ) ;
if ( ( V_1 == NULL ) || ( ( V_1 -> V_24 == NULL ) && ( V_1 -> V_25 == 0 ) ) )
return ( 0 ) ;
V_23 . V_26 . V_27 = F_2 ;
V_23 . V_26 . type = V_28 ;
V_23 . V_26 . V_29 = V_11 ;
F_6 ( & ( V_23 . V_26 ) , V_30 ) ;
V_23 . V_31 . V_27 = F_2 ;
V_23 . V_31 . type = V_28 ;
V_23 . V_31 . V_29 = V_12 ;
F_6 ( & ( V_23 . V_31 ) , V_1 -> V_31 ) ;
V_23 . V_24 . type = V_32 ;
V_23 . V_24 . V_29 = V_10 ;
if ( V_1 -> V_24 == NULL )
V_22 = V_1 -> V_25 ;
else
V_22 = V_1 -> V_24 -> V_33 ;
if ( V_1 -> V_31 == V_34 )
{
V_23 . V_24 . V_27 = 3 ;
V_10 [ 0 ] = ( ( unsigned char ) ( V_22 >> 16L ) ) & 0xff ;
V_10 [ 1 ] = ( ( unsigned char ) ( V_22 >> 8L ) ) & 0xff ;
V_10 [ 2 ] = ( ( unsigned char ) ( V_22 ) ) & 0xff ;
}
else
{
V_23 . V_24 . V_27 = 2 ;
V_10 [ 0 ] = ( ( unsigned char ) ( V_22 >> 8L ) ) & 0xff ;
V_10 [ 1 ] = ( ( unsigned char ) ( V_22 ) ) & 0xff ;
}
#ifndef F_4
if ( V_1 -> V_35 )
{
V_20 = ( unsigned char ) V_1 -> V_35 ;
V_23 . V_36 . V_27 = 1 ;
V_23 . V_36 . type = V_32 ;
V_23 . V_36 . V_29 = & V_20 ;
}
#endif
V_23 . V_37 . V_27 = V_1 -> V_38 ;
V_23 . V_37 . type = V_32 ;
V_23 . V_37 . V_29 = V_1 -> V_37 ;
V_23 . V_39 . V_27 = V_1 -> V_40 ;
V_23 . V_39 . type = V_32 ;
V_23 . V_39 . V_29 = V_1 -> V_39 ;
V_23 . V_41 . V_27 = V_1 -> V_42 ;
V_23 . V_41 . type = V_32 ;
V_23 . V_41 . V_29 = V_1 -> V_43 ;
V_23 . V_44 . V_27 = V_1 -> V_45 ;
V_23 . V_44 . type = V_32 ;
V_23 . V_44 . V_29 = V_1 -> V_44 ;
#ifndef F_7
if ( V_1 -> V_46 )
{
V_23 . V_47 . V_27 = V_1 -> V_46 ;
V_23 . V_47 . type = V_32 ;
V_23 . V_47 . V_29 = V_1 -> V_48 ;
}
#endif
if ( V_1 -> time != 0L )
{
V_23 . time . V_27 = F_2 ;
V_23 . time . type = V_28 ;
V_23 . time . V_29 = V_13 ;
F_6 ( & ( V_23 . time ) , V_1 -> time ) ;
}
if ( V_1 -> V_49 != 0L )
{
V_23 . V_49 . V_27 = F_2 ;
V_23 . V_49 . type = V_28 ;
V_23 . V_49 . V_29 = V_14 ;
F_6 ( & ( V_23 . V_49 ) , V_1 -> V_49 ) ;
}
if ( V_1 -> V_50 != V_51 )
{
V_23 . V_50 . V_27 = F_2 ;
V_23 . V_50 . type = V_28 ;
V_23 . V_50 . V_29 = V_15 ;
F_6 ( & V_23 . V_50 , V_1 -> V_50 ) ;
}
#ifndef F_3
if ( V_1 -> V_52 )
{
V_23 . V_52 . V_27 = strlen ( V_1 -> V_52 ) ;
V_23 . V_52 . type = V_32 ;
V_23 . V_52 . V_29 = ( unsigned char * ) V_1 -> V_52 ;
}
if ( V_1 -> V_53 )
{
V_23 . V_53 . V_27 = V_1 -> V_54 ;
V_23 . V_53 . type = V_32 ;
V_23 . V_53 . V_29 = ( unsigned char * ) V_1 -> V_53 ;
}
if ( V_1 -> V_55 > 0 )
{
V_23 . V_56 . V_27 = F_2 ;
V_23 . V_56 . type = V_28 ;
V_23 . V_56 . V_29 = V_19 ;
F_6 ( & V_23 . V_56 , V_1 -> V_55 ) ;
}
#endif
#ifndef F_8
if ( V_1 -> V_57 )
{
V_23 . V_57 . V_27 = strlen ( V_1 -> V_57 ) ;
V_23 . V_57 . type = V_32 ;
V_23 . V_57 . V_29 = ( unsigned char * ) ( V_1 -> V_57 ) ;
}
if ( V_1 -> V_58 )
{
V_23 . V_58 . V_27 = strlen ( V_1 -> V_58 ) ;
V_23 . V_58 . type = V_32 ;
V_23 . V_58 . V_29 = ( unsigned char * ) ( V_1 -> V_58 ) ;
}
#endif
F_9 ( & ( V_23 . V_26 ) , V_59 ) ;
F_9 ( & ( V_23 . V_31 ) , V_59 ) ;
F_9 ( & ( V_23 . V_24 ) , V_60 ) ;
F_9 ( & ( V_23 . V_39 ) , V_60 ) ;
F_9 ( & ( V_23 . V_37 ) , V_60 ) ;
#ifndef F_7
if ( V_1 -> V_46 )
F_9 ( & ( V_23 . V_47 ) , V_60 ) ;
#endif
if ( V_1 -> V_45 > 0 )
F_10 ( & ( V_23 . V_44 ) , V_60 ) ;
if ( V_1 -> time != 0L )
F_11 ( & ( V_23 . time ) , V_59 , 1 , V_3 ) ;
if ( V_1 -> V_49 != 0L )
F_11 ( & ( V_23 . V_49 ) , V_59 , 2 , V_4 ) ;
if ( V_1 -> V_61 != NULL )
F_11 ( V_1 -> V_61 , V_62 , 3 , V_5 ) ;
F_11 ( & V_23 . V_41 , V_60 , 4 , V_6 ) ;
if ( V_1 -> V_50 != V_51 )
F_11 ( & ( V_23 . V_50 ) , V_59 , 5 , V_7 ) ;
#ifndef F_3
if ( V_1 -> V_55 > 0 )
F_11 ( & V_23 . V_56 , V_59 , 9 , V_17 ) ;
if ( V_1 -> V_53 )
F_11 ( & ( V_23 . V_53 ) , V_60 , 10 , V_18 ) ;
if ( V_1 -> V_52 )
F_11 ( & ( V_23 . V_52 ) , V_60 , 6 , V_16 ) ;
#ifndef F_4
if ( V_1 -> V_35 )
F_11 ( & ( V_23 . V_36 ) , V_60 , 11 , V_21 ) ;
#endif
#endif
#ifndef F_8
if ( V_1 -> V_57 )
F_11 ( & ( V_23 . V_57 ) , V_60 , 7 , V_8 ) ;
if ( V_1 -> V_58 )
F_11 ( & ( V_23 . V_58 ) , V_60 , 8 , V_9 ) ;
#endif
F_12 () ;
F_13 ( & ( V_23 . V_26 ) , V_59 ) ;
F_13 ( & ( V_23 . V_31 ) , V_59 ) ;
F_13 ( & ( V_23 . V_24 ) , V_60 ) ;
F_13 ( & ( V_23 . V_39 ) , V_60 ) ;
F_13 ( & ( V_23 . V_37 ) , V_60 ) ;
#ifndef F_7
if ( V_1 -> V_46 )
F_13 ( & ( V_23 . V_47 ) , V_60 ) ;
#endif
if ( V_1 -> V_45 > 0 )
F_14 ( & ( V_23 . V_44 ) , V_60 , 0 ) ;
if ( V_1 -> time != 0L )
F_15 ( & ( V_23 . time ) , V_59 , 1 , V_3 ) ;
if ( V_1 -> V_49 != 0L )
F_15 ( & ( V_23 . V_49 ) , V_59 , 2 , V_4 ) ;
if ( V_1 -> V_61 != NULL )
F_15 ( V_1 -> V_61 , V_62 , 3 , V_5 ) ;
F_15 ( & V_23 . V_41 , V_60 , 4 ,
V_6 ) ;
if ( V_1 -> V_50 != V_51 )
F_15 ( & V_23 . V_50 , V_59 , 5 , V_7 ) ;
#ifndef F_3
if ( V_1 -> V_52 )
F_15 ( & ( V_23 . V_52 ) , V_60 , 6 , V_16 ) ;
#endif
#ifndef F_8
if ( V_1 -> V_57 )
F_15 ( & ( V_23 . V_57 ) , V_60 , 7 , V_8 ) ;
if ( V_1 -> V_58 )
F_15 ( & ( V_23 . V_58 ) , V_60 , 8 , V_9 ) ;
#endif
#ifndef F_3
if ( V_1 -> V_55 > 0 )
F_15 ( & V_23 . V_56 , V_59 , 9 , V_17 ) ;
if ( V_1 -> V_53 )
F_15 ( & ( V_23 . V_53 ) , V_60 , 10 , V_18 ) ;
#endif
#ifndef F_4
if ( V_1 -> V_35 )
F_15 ( & ( V_23 . V_36 ) , V_60 , 11 , V_21 ) ;
#endif
F_16 () ;
}
T_1 * F_17 ( T_1 * * V_23 , const unsigned char * * V_2 ,
long V_27 )
{
int V_26 , V_31 = 0 , V_63 ;
long V_33 ;
T_3 V_64 , * V_65 ;
T_4 V_66 , * V_67 ;
F_18 ( V_23 , T_1 * , V_68 ) ;
V_65 = & V_64 ;
V_67 = & V_66 ;
F_19 () ;
F_20 () ;
V_64 . V_29 = NULL ; V_64 . V_27 = 0 ;
F_21 ( T_3 , V_65 , V_69 ) ;
V_26 = ( int ) F_22 ( V_65 ) ;
if ( V_64 . V_29 != NULL ) { F_23 ( V_64 . V_29 ) ; V_64 . V_29 = NULL ; V_64 . V_27 = 0 ; }
F_21 ( T_3 , V_65 , V_69 ) ;
V_31 = ( int ) F_22 ( V_65 ) ;
V_70 -> V_31 = V_31 ;
if ( V_64 . V_29 != NULL ) { F_23 ( V_64 . V_29 ) ; V_64 . V_29 = NULL ; V_64 . V_27 = 0 ; }
V_66 . V_29 = NULL ; V_66 . V_27 = 0 ;
F_21 ( T_4 , V_67 , V_71 ) ;
if ( V_31 == V_34 )
{
if ( V_66 . V_27 != 3 )
{
V_72 . error = V_73 ;
goto V_74;
}
V_33 = 0x02000000L |
( ( unsigned long ) V_66 . V_29 [ 0 ] << 16L ) |
( ( unsigned long ) V_66 . V_29 [ 1 ] << 8L ) |
( unsigned long ) V_66 . V_29 [ 2 ] ;
}
else if ( ( V_31 >> 8 ) >= V_75 )
{
if ( V_66 . V_27 != 2 )
{
V_72 . error = V_73 ;
goto V_74;
}
V_33 = 0x03000000L |
( ( unsigned long ) V_66 . V_29 [ 0 ] << 8L ) |
( unsigned long ) V_66 . V_29 [ 1 ] ;
}
else
{
V_72 . error = V_76 ;
goto V_74;
}
V_70 -> V_24 = NULL ;
V_70 -> V_25 = V_33 ;
F_21 ( T_4 , V_67 , V_71 ) ;
if ( ( V_31 >> 8 ) >= V_75 )
V_63 = V_77 ;
else
V_63 = V_78 ;
if ( V_66 . V_27 > V_63 )
V_66 . V_27 = V_63 ;
if ( V_66 . V_27 > ( int ) sizeof( V_70 -> V_39 ) )
V_66 . V_27 = sizeof( V_70 -> V_39 ) ;
V_70 -> V_40 = V_66 . V_27 ;
F_24 ( V_66 . V_27 <= ( int ) sizeof( V_70 -> V_39 ) ) ;
memcpy ( V_70 -> V_39 , V_66 . V_29 , V_66 . V_27 ) ;
F_21 ( T_4 , V_67 , V_71 ) ;
if ( V_66 . V_27 > V_79 )
V_70 -> V_38 = V_79 ;
else
V_70 -> V_38 = V_66 . V_27 ;
memcpy ( V_70 -> V_37 , V_66 . V_29 , V_70 -> V_38 ) ;
V_66 . V_27 = 0 ;
#ifndef F_7
V_66 . V_27 = 0 ;
F_25 ( V_67 , V_71 , V_32 ) ;
if ( V_66 . V_29 )
{
if ( V_66 . V_27 > V_80 )
V_70 -> V_46 = 0 ;
else
V_70 -> V_46 = V_66 . V_27 ;
memcpy ( V_70 -> V_48 , V_66 . V_29 , V_70 -> V_46 ) ;
F_23 ( V_66 . V_29 ) ;
V_66 . V_29 = NULL ;
V_66 . V_27 = 0 ;
}
else
V_70 -> V_46 = 0 ;
#endif
F_26 ( V_67 , V_71 , 0 , V_32 ) ;
if ( V_66 . V_27 > V_81 )
V_70 -> V_45 = V_81 ;
else
V_70 -> V_45 = V_66 . V_27 ;
memcpy ( V_70 -> V_44 , V_66 . V_29 , V_70 -> V_45 ) ;
if ( V_66 . V_29 != NULL ) F_23 ( V_66 . V_29 ) ;
V_64 . V_27 = 0 ;
F_27 ( V_65 , V_69 , 1 ) ;
if ( V_64 . V_29 != NULL )
{
V_70 -> time = F_22 ( V_65 ) ;
F_23 ( V_64 . V_29 ) ; V_64 . V_29 = NULL ; V_64 . V_27 = 0 ;
}
else
V_70 -> time = ( unsigned long ) time ( NULL ) ;
V_64 . V_27 = 0 ;
F_27 ( V_65 , V_69 , 2 ) ;
if ( V_64 . V_29 != NULL )
{
V_70 -> V_49 = F_22 ( V_65 ) ;
F_23 ( V_64 . V_29 ) ; V_64 . V_29 = NULL ; V_64 . V_27 = 0 ;
}
else
V_70 -> V_49 = 3 ;
if ( V_70 -> V_61 != NULL )
{
F_28 ( V_70 -> V_61 ) ;
V_70 -> V_61 = NULL ;
}
F_27 ( V_70 -> V_61 , V_82 , 3 ) ;
V_66 . V_27 = 0 ;
V_66 . V_29 = NULL ;
F_27 ( V_67 , V_71 , 4 ) ;
if( V_66 . V_29 != NULL )
{
if ( V_66 . V_27 > V_83 )
{
V_72 . error = V_84 ;
goto V_74;
}
else
{
V_70 -> V_42 = V_66 . V_27 ;
memcpy ( V_70 -> V_43 , V_66 . V_29 , V_66 . V_27 ) ;
}
F_23 ( V_66 . V_29 ) ; V_66 . V_29 = NULL ; V_66 . V_27 = 0 ;
}
else
V_70 -> V_42 = 0 ;
V_64 . V_27 = 0 ;
F_27 ( V_65 , V_69 , 5 ) ;
if ( V_64 . V_29 != NULL )
{
V_70 -> V_50 = F_22 ( V_65 ) ;
F_23 ( V_64 . V_29 ) ; V_64 . V_29 = NULL ; V_64 . V_27 = 0 ;
}
else
V_70 -> V_50 = V_51 ;
#ifndef F_3
V_66 . V_27 = 0 ;
V_66 . V_29 = NULL ;
F_27 ( V_67 , V_71 , 6 ) ;
if ( V_66 . V_29 )
{
V_70 -> V_52 = F_29 ( ( char * ) V_66 . V_29 , V_66 . V_27 ) ;
F_23 ( V_66 . V_29 ) ;
V_66 . V_29 = NULL ;
V_66 . V_27 = 0 ;
}
else
V_70 -> V_52 = NULL ;
#endif
#ifndef F_8
V_66 . V_27 = 0 ;
V_66 . V_29 = NULL ;
F_27 ( V_67 , V_71 , 7 ) ;
if ( V_66 . V_29 )
{
V_70 -> V_57 = F_29 ( ( char * ) V_66 . V_29 , V_66 . V_27 ) ;
F_23 ( V_66 . V_29 ) ;
V_66 . V_29 = NULL ;
V_66 . V_27 = 0 ;
}
else
V_70 -> V_57 = NULL ;
#endif
#ifndef F_3
V_64 . V_27 = 0 ;
F_27 ( V_65 , V_69 , 9 ) ;
if ( V_64 . V_29 != NULL )
{
V_70 -> V_55 = F_22 ( V_65 ) ;
F_23 ( V_64 . V_29 ) ; V_64 . V_29 = NULL ; V_64 . V_27 = 0 ;
}
else if ( V_70 -> V_54 && V_70 -> V_40 )
V_70 -> V_55 = - 1 ;
else
V_70 -> V_55 = 0 ;
V_66 . V_27 = 0 ;
V_66 . V_29 = NULL ;
F_27 ( V_67 , V_71 , 10 ) ;
if ( V_66 . V_29 )
{
V_70 -> V_53 = V_66 . V_29 ;
V_70 -> V_54 = V_66 . V_27 ;
V_66 . V_29 = NULL ;
V_66 . V_27 = 0 ;
}
else
V_70 -> V_53 = NULL ;
#endif
#ifndef F_4
V_66 . V_27 = 0 ;
V_66 . V_29 = NULL ;
F_27 ( V_67 , V_71 , 11 ) ;
if ( V_66 . V_29 )
{
V_70 -> V_35 = V_66 . V_29 [ 0 ] ;
F_23 ( V_66 . V_29 ) ;
V_66 . V_29 = NULL ;
}
#endif
F_30 ( V_23 , V_85 , V_86 ) ;
}
