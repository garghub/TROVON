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
#ifndef F_5
int V_22 = 0 ;
#endif
long V_23 ;
T_2 V_24 ;
F_6 ( V_1 ) ;
if ( ( V_1 == NULL ) || ( ( V_1 -> V_25 == NULL ) && ( V_1 -> V_26 == 0 ) ) )
return ( 0 ) ;
V_24 . V_27 . V_28 = F_2 ;
V_24 . V_27 . type = V_29 ;
V_24 . V_27 . V_30 = V_11 ;
F_7 ( & ( V_24 . V_27 ) , V_31 ) ;
V_24 . V_32 . V_28 = F_2 ;
V_24 . V_32 . type = V_29 ;
V_24 . V_32 . V_30 = V_12 ;
F_7 ( & ( V_24 . V_32 ) , V_1 -> V_32 ) ;
V_24 . V_25 . type = V_33 ;
V_24 . V_25 . V_30 = V_10 ;
if ( V_1 -> V_25 == NULL )
V_23 = V_1 -> V_26 ;
else
V_23 = V_1 -> V_25 -> V_34 ;
if ( V_1 -> V_32 == V_35 )
{
V_24 . V_25 . V_28 = 3 ;
V_10 [ 0 ] = ( ( unsigned char ) ( V_23 >> 16L ) ) & 0xff ;
V_10 [ 1 ] = ( ( unsigned char ) ( V_23 >> 8L ) ) & 0xff ;
V_10 [ 2 ] = ( ( unsigned char ) ( V_23 ) ) & 0xff ;
}
else
{
V_24 . V_25 . V_28 = 2 ;
V_10 [ 0 ] = ( ( unsigned char ) ( V_23 >> 8L ) ) & 0xff ;
V_10 [ 1 ] = ( ( unsigned char ) ( V_23 ) ) & 0xff ;
}
#ifndef F_4
if ( V_1 -> V_36 )
{
V_20 = ( unsigned char ) V_1 -> V_36 ;
V_24 . V_37 . V_28 = 1 ;
V_24 . V_37 . type = V_33 ;
V_24 . V_37 . V_30 = & V_20 ;
}
#endif
V_24 . V_38 . V_28 = V_1 -> V_39 ;
V_24 . V_38 . type = V_33 ;
V_24 . V_38 . V_30 = V_1 -> V_38 ;
V_24 . V_40 . V_28 = V_1 -> V_41 ;
V_24 . V_40 . type = V_33 ;
V_24 . V_40 . V_30 = V_1 -> V_40 ;
V_24 . V_42 . V_28 = V_1 -> V_43 ;
V_24 . V_42 . type = V_33 ;
V_24 . V_42 . V_30 = V_1 -> V_44 ;
V_24 . V_45 . V_28 = V_1 -> V_46 ;
V_24 . V_45 . type = V_33 ;
V_24 . V_45 . V_30 = V_1 -> V_45 ;
#ifndef F_8
if ( V_1 -> V_47 )
{
V_24 . V_48 . V_28 = V_1 -> V_47 ;
V_24 . V_48 . type = V_33 ;
V_24 . V_48 . V_30 = V_1 -> V_49 ;
}
#endif
if ( V_1 -> time != 0L )
{
V_24 . time . V_28 = F_2 ;
V_24 . time . type = V_29 ;
V_24 . time . V_30 = V_13 ;
F_7 ( & ( V_24 . time ) , V_1 -> time ) ;
}
if ( V_1 -> V_50 != 0L )
{
V_24 . V_50 . V_28 = F_2 ;
V_24 . V_50 . type = V_29 ;
V_24 . V_50 . V_30 = V_14 ;
F_7 ( & ( V_24 . V_50 ) , V_1 -> V_50 ) ;
}
if ( V_1 -> V_51 != V_52 )
{
V_24 . V_51 . V_28 = F_2 ;
V_24 . V_51 . type = V_29 ;
V_24 . V_51 . V_30 = V_15 ;
F_7 ( & V_24 . V_51 , V_1 -> V_51 ) ;
}
#ifndef F_3
if ( V_1 -> V_53 )
{
V_24 . V_53 . V_28 = strlen ( V_1 -> V_53 ) ;
V_24 . V_53 . type = V_33 ;
V_24 . V_53 . V_30 = ( unsigned char * ) V_1 -> V_53 ;
}
if ( V_1 -> V_54 )
{
V_24 . V_54 . V_28 = V_1 -> V_55 ;
V_24 . V_54 . type = V_33 ;
V_24 . V_54 . V_30 = ( unsigned char * ) V_1 -> V_54 ;
}
if ( V_1 -> V_56 > 0 )
{
V_24 . V_57 . V_28 = F_2 ;
V_24 . V_57 . type = V_29 ;
V_24 . V_57 . V_30 = V_19 ;
F_7 ( & V_24 . V_57 , V_1 -> V_56 ) ;
}
#endif
#ifndef F_9
if ( V_1 -> V_58 )
{
V_24 . V_58 . V_28 = strlen ( V_1 -> V_58 ) ;
V_24 . V_58 . type = V_33 ;
V_24 . V_58 . V_30 = ( unsigned char * ) ( V_1 -> V_58 ) ;
}
if ( V_1 -> V_59 )
{
V_24 . V_59 . V_28 = strlen ( V_1 -> V_59 ) ;
V_24 . V_59 . type = V_33 ;
V_24 . V_59 . V_30 = ( unsigned char * ) ( V_1 -> V_59 ) ;
}
#endif
#ifndef F_5
if ( V_1 -> V_60 )
{
V_24 . V_60 . V_28 = strlen ( V_1 -> V_60 ) ;
V_24 . V_60 . type = V_33 ;
V_24 . V_60 . V_30 = ( unsigned char * ) ( V_1 -> V_60 ) ;
}
#endif
F_10 ( & ( V_24 . V_27 ) , V_61 ) ;
F_10 ( & ( V_24 . V_32 ) , V_61 ) ;
F_10 ( & ( V_24 . V_25 ) , V_62 ) ;
F_10 ( & ( V_24 . V_40 ) , V_62 ) ;
F_10 ( & ( V_24 . V_38 ) , V_62 ) ;
#ifndef F_8
if ( V_1 -> V_47 )
F_10 ( & ( V_24 . V_48 ) , V_62 ) ;
#endif
if ( V_1 -> V_46 > 0 )
F_11 ( & ( V_24 . V_45 ) , V_62 ) ;
if ( V_1 -> time != 0L )
F_12 ( & ( V_24 . time ) , V_61 , 1 , V_3 ) ;
if ( V_1 -> V_50 != 0L )
F_12 ( & ( V_24 . V_50 ) , V_61 , 2 , V_4 ) ;
if ( V_1 -> V_63 != NULL )
F_12 ( V_1 -> V_63 , V_64 , 3 , V_5 ) ;
F_12 ( & V_24 . V_42 , V_62 , 4 , V_6 ) ;
if ( V_1 -> V_51 != V_52 )
F_12 ( & ( V_24 . V_51 ) , V_61 , 5 , V_7 ) ;
#ifndef F_3
if ( V_1 -> V_56 > 0 )
F_12 ( & V_24 . V_57 , V_61 , 9 , V_17 ) ;
if ( V_1 -> V_54 )
F_12 ( & ( V_24 . V_54 ) , V_62 , 10 , V_18 ) ;
if ( V_1 -> V_53 )
F_12 ( & ( V_24 . V_53 ) , V_62 , 6 , V_16 ) ;
#ifndef F_4
if ( V_1 -> V_36 )
F_12 ( & ( V_24 . V_37 ) , V_62 , 11 , V_21 ) ;
#endif
#endif
#ifndef F_9
if ( V_1 -> V_58 )
F_12 ( & ( V_24 . V_58 ) , V_62 , 7 , V_8 ) ;
if ( V_1 -> V_59 )
F_12 ( & ( V_24 . V_59 ) , V_62 , 8 , V_9 ) ;
#endif
#ifndef F_5
if ( V_1 -> V_60 )
F_12 ( & ( V_24 . V_60 ) , V_62 , 12 , V_22 ) ;
#endif
F_13 () ;
F_14 ( & ( V_24 . V_27 ) , V_61 ) ;
F_14 ( & ( V_24 . V_32 ) , V_61 ) ;
F_14 ( & ( V_24 . V_25 ) , V_62 ) ;
F_14 ( & ( V_24 . V_40 ) , V_62 ) ;
F_14 ( & ( V_24 . V_38 ) , V_62 ) ;
#ifndef F_8
if ( V_1 -> V_47 )
F_14 ( & ( V_24 . V_48 ) , V_62 ) ;
#endif
if ( V_1 -> V_46 > 0 )
F_15 ( & ( V_24 . V_45 ) , V_62 , 0 ) ;
if ( V_1 -> time != 0L )
F_16 ( & ( V_24 . time ) , V_61 , 1 , V_3 ) ;
if ( V_1 -> V_50 != 0L )
F_16 ( & ( V_24 . V_50 ) , V_61 , 2 , V_4 ) ;
if ( V_1 -> V_63 != NULL )
F_16 ( V_1 -> V_63 , V_64 , 3 , V_5 ) ;
F_16 ( & V_24 . V_42 , V_62 , 4 ,
V_6 ) ;
if ( V_1 -> V_51 != V_52 )
F_16 ( & V_24 . V_51 , V_61 , 5 , V_7 ) ;
#ifndef F_3
if ( V_1 -> V_53 )
F_16 ( & ( V_24 . V_53 ) , V_62 , 6 , V_16 ) ;
#endif
#ifndef F_9
if ( V_1 -> V_58 )
F_16 ( & ( V_24 . V_58 ) , V_62 , 7 , V_8 ) ;
if ( V_1 -> V_59 )
F_16 ( & ( V_24 . V_59 ) , V_62 , 8 , V_9 ) ;
#endif
#ifndef F_3
if ( V_1 -> V_56 > 0 )
F_16 ( & V_24 . V_57 , V_61 , 9 , V_17 ) ;
if ( V_1 -> V_54 )
F_16 ( & ( V_24 . V_54 ) , V_62 , 10 , V_18 ) ;
#endif
#ifndef F_4
if ( V_1 -> V_36 )
F_16 ( & ( V_24 . V_37 ) , V_62 , 11 , V_21 ) ;
#endif
#ifndef F_5
if ( V_1 -> V_60 )
F_16 ( & ( V_24 . V_60 ) , V_62 , 12 , V_22 ) ;
#endif
F_17 () ;
}
T_1 * F_18 ( T_1 * * V_24 , const unsigned char * * V_2 ,
long V_28 )
{
int V_32 = 0 , V_65 ;
long V_34 ;
T_3 V_66 , * V_67 ;
T_4 V_68 , * V_69 ;
F_19 ( V_24 , T_1 * , V_70 ) ;
V_67 = & V_66 ;
V_69 = & V_68 ;
F_20 () ;
F_21 () ;
V_66 . V_30 = NULL ; V_66 . V_28 = 0 ;
F_22 ( T_3 , V_67 , V_71 ) ;
if ( V_66 . V_30 != NULL ) { F_23 ( V_66 . V_30 ) ; V_66 . V_30 = NULL ; V_66 . V_28 = 0 ; }
F_22 ( T_3 , V_67 , V_71 ) ;
V_32 = ( int ) F_24 ( V_67 ) ;
V_72 -> V_32 = V_32 ;
if ( V_66 . V_30 != NULL ) { F_23 ( V_66 . V_30 ) ; V_66 . V_30 = NULL ; V_66 . V_28 = 0 ; }
V_68 . V_30 = NULL ; V_68 . V_28 = 0 ;
F_22 ( T_4 , V_69 , V_73 ) ;
if ( V_32 == V_35 )
{
if ( V_68 . V_28 != 3 )
{
V_74 . error = V_75 ;
goto V_76;
}
V_34 = 0x02000000L |
( ( unsigned long ) V_68 . V_30 [ 0 ] << 16L ) |
( ( unsigned long ) V_68 . V_30 [ 1 ] << 8L ) |
( unsigned long ) V_68 . V_30 [ 2 ] ;
}
else if ( ( V_32 >> 8 ) >= V_77 )
{
if ( V_68 . V_28 != 2 )
{
V_74 . error = V_75 ;
goto V_76;
}
V_34 = 0x03000000L |
( ( unsigned long ) V_68 . V_30 [ 0 ] << 8L ) |
( unsigned long ) V_68 . V_30 [ 1 ] ;
}
else
{
V_74 . error = V_78 ;
goto V_76;
}
V_72 -> V_25 = NULL ;
V_72 -> V_26 = V_34 ;
F_22 ( T_4 , V_69 , V_73 ) ;
if ( ( V_32 >> 8 ) >= V_77 )
V_65 = V_79 ;
else
V_65 = V_80 ;
if ( V_68 . V_28 > V_65 )
V_68 . V_28 = V_65 ;
if ( V_68 . V_28 > ( int ) sizeof( V_72 -> V_40 ) )
V_68 . V_28 = sizeof( V_72 -> V_40 ) ;
V_72 -> V_41 = V_68 . V_28 ;
F_25 ( V_68 . V_28 <= ( int ) sizeof( V_72 -> V_40 ) ) ;
memcpy ( V_72 -> V_40 , V_68 . V_30 , V_68 . V_28 ) ;
F_22 ( T_4 , V_69 , V_73 ) ;
if ( V_68 . V_28 > V_81 )
V_72 -> V_39 = V_81 ;
else
V_72 -> V_39 = V_68 . V_28 ;
memcpy ( V_72 -> V_38 , V_68 . V_30 , V_72 -> V_39 ) ;
V_68 . V_28 = 0 ;
#ifndef F_8
V_68 . V_28 = 0 ;
F_26 ( V_69 , V_73 , V_33 ) ;
if ( V_68 . V_30 )
{
if ( V_68 . V_28 > V_82 )
V_72 -> V_47 = 0 ;
else
V_72 -> V_47 = V_68 . V_28 ;
memcpy ( V_72 -> V_49 , V_68 . V_30 , V_72 -> V_47 ) ;
F_23 ( V_68 . V_30 ) ;
V_68 . V_30 = NULL ;
V_68 . V_28 = 0 ;
}
else
V_72 -> V_47 = 0 ;
#endif
F_27 ( V_69 , V_73 , 0 , V_33 ) ;
if ( V_68 . V_28 > V_83 )
V_72 -> V_46 = V_83 ;
else
V_72 -> V_46 = V_68 . V_28 ;
memcpy ( V_72 -> V_45 , V_68 . V_30 , V_72 -> V_46 ) ;
if ( V_68 . V_30 != NULL ) F_23 ( V_68 . V_30 ) ;
V_66 . V_28 = 0 ;
F_28 ( V_67 , V_71 , 1 ) ;
if ( V_66 . V_30 != NULL )
{
V_72 -> time = F_24 ( V_67 ) ;
F_23 ( V_66 . V_30 ) ; V_66 . V_30 = NULL ; V_66 . V_28 = 0 ;
}
else
V_72 -> time = ( unsigned long ) time ( NULL ) ;
V_66 . V_28 = 0 ;
F_28 ( V_67 , V_71 , 2 ) ;
if ( V_66 . V_30 != NULL )
{
V_72 -> V_50 = F_24 ( V_67 ) ;
F_23 ( V_66 . V_30 ) ; V_66 . V_30 = NULL ; V_66 . V_28 = 0 ;
}
else
V_72 -> V_50 = 3 ;
if ( V_72 -> V_63 != NULL )
{
F_29 ( V_72 -> V_63 ) ;
V_72 -> V_63 = NULL ;
}
F_28 ( V_72 -> V_63 , V_84 , 3 ) ;
V_68 . V_28 = 0 ;
V_68 . V_30 = NULL ;
F_28 ( V_69 , V_73 , 4 ) ;
if( V_68 . V_30 != NULL )
{
if ( V_68 . V_28 > V_85 )
{
V_74 . error = V_86 ;
goto V_76;
}
else
{
V_72 -> V_43 = V_68 . V_28 ;
memcpy ( V_72 -> V_44 , V_68 . V_30 , V_68 . V_28 ) ;
}
F_23 ( V_68 . V_30 ) ; V_68 . V_30 = NULL ; V_68 . V_28 = 0 ;
}
else
V_72 -> V_43 = 0 ;
V_66 . V_28 = 0 ;
F_28 ( V_67 , V_71 , 5 ) ;
if ( V_66 . V_30 != NULL )
{
V_72 -> V_51 = F_24 ( V_67 ) ;
F_23 ( V_66 . V_30 ) ; V_66 . V_30 = NULL ; V_66 . V_28 = 0 ;
}
else
V_72 -> V_51 = V_52 ;
#ifndef F_3
V_68 . V_28 = 0 ;
V_68 . V_30 = NULL ;
F_28 ( V_69 , V_73 , 6 ) ;
if ( V_68 . V_30 )
{
V_72 -> V_53 = F_30 ( ( char * ) V_68 . V_30 , V_68 . V_28 ) ;
F_23 ( V_68 . V_30 ) ;
V_68 . V_30 = NULL ;
V_68 . V_28 = 0 ;
}
else
V_72 -> V_53 = NULL ;
#endif
#ifndef F_9
V_68 . V_28 = 0 ;
V_68 . V_30 = NULL ;
F_28 ( V_69 , V_73 , 7 ) ;
if ( V_68 . V_30 )
{
V_72 -> V_58 = F_30 ( ( char * ) V_68 . V_30 , V_68 . V_28 ) ;
F_23 ( V_68 . V_30 ) ;
V_68 . V_30 = NULL ;
V_68 . V_28 = 0 ;
}
else
V_72 -> V_58 = NULL ;
V_68 . V_28 = 0 ;
V_68 . V_30 = NULL ;
F_28 ( V_69 , V_73 , 8 ) ;
if ( V_68 . V_30 )
{
V_72 -> V_59 = F_30 ( ( char * ) V_68 . V_30 , V_68 . V_28 ) ;
F_23 ( V_68 . V_30 ) ;
V_68 . V_30 = NULL ;
V_68 . V_28 = 0 ;
}
else
V_72 -> V_59 = NULL ;
#endif
#ifndef F_3
V_66 . V_28 = 0 ;
F_28 ( V_67 , V_71 , 9 ) ;
if ( V_66 . V_30 != NULL )
{
V_72 -> V_56 = F_24 ( V_67 ) ;
F_23 ( V_66 . V_30 ) ; V_66 . V_30 = NULL ; V_66 . V_28 = 0 ;
}
else if ( V_72 -> V_55 && V_72 -> V_41 )
V_72 -> V_56 = - 1 ;
else
V_72 -> V_56 = 0 ;
V_68 . V_28 = 0 ;
V_68 . V_30 = NULL ;
F_28 ( V_69 , V_73 , 10 ) ;
if ( V_68 . V_30 )
{
V_72 -> V_54 = V_68 . V_30 ;
V_72 -> V_55 = V_68 . V_28 ;
V_68 . V_30 = NULL ;
V_68 . V_28 = 0 ;
}
else
V_72 -> V_54 = NULL ;
#endif
#ifndef F_4
V_68 . V_28 = 0 ;
V_68 . V_30 = NULL ;
F_28 ( V_69 , V_73 , 11 ) ;
if ( V_68 . V_30 )
{
V_72 -> V_36 = V_68 . V_30 [ 0 ] ;
F_23 ( V_68 . V_30 ) ;
V_68 . V_30 = NULL ;
}
#endif
#ifndef F_5
V_68 . V_28 = 0 ;
V_68 . V_30 = NULL ;
F_28 ( V_69 , V_73 , 12 ) ;
if ( V_68 . V_30 )
{
V_72 -> V_60 = F_30 ( ( char * ) V_68 . V_30 , V_68 . V_28 ) ;
F_23 ( V_68 . V_30 ) ;
V_68 . V_30 = NULL ;
V_68 . V_28 = 0 ;
}
else
V_72 -> V_60 = NULL ;
#endif
F_31 ( V_24 , V_87 , V_88 ) ;
}
