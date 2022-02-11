static T_1 * F_1 ( T_2 * V_1 ,
int V_2 ,
int V_3 ,
int V_4 ,
const T_3 * V_5 ) {
T_1 * V_6 ;
#ifdef F_2
if ( F_2 & V_7 ) F_3 ( L_1 , V_2 , V_3 , V_4 ) ;
#endif
V_6 = ( T_1 * ) F_4 ( F_5 () , T_1 ) ;
V_6 -> V_8 = V_1 -> V_8 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_4 = V_4 ;
V_6 -> V_9 = NULL ;
V_6 -> V_10 = NULL ;
V_6 -> V_11 = NULL ;
V_6 -> V_5 = V_5 ;
V_6 -> V_12 = V_6 ;
return V_6 ;
}
static int F_6 ( T_2 * V_1 , int V_3 ) {
int V_4 = 0 ;
int V_13 ;
T_1 * V_14 = NULL ;
if ( ! V_1 -> V_15 ) return 0 ;
#ifdef F_2
if ( F_2 & V_16 ) F_3 ( L_2 ) ;
#endif
while ( ( V_13 = V_1 -> V_15 -> V_17 ( V_1 , V_3 , V_1 -> V_15 , & V_14 ) ) > 0 ) {
V_4 += V_13 ;
V_3 += V_13 ;
#ifdef F_2
if ( F_2 & V_16 ) F_3 ( L_3 , V_13 ) ;
#endif
}
#ifdef F_2
if ( F_2 & V_16 ) F_3 ( L_4 , V_4 ) ;
#endif
return V_4 ;
}
static int F_7 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_4 V_18 , V_19 ;
T_5 V_20 ;
#ifdef F_2
if ( F_2 & V_21 ) F_3 ( L_5 , V_5 -> V_22 . V_23 ) ;
#endif
if ( V_3 + 1 > V_1 -> V_24 )
return - 1 ;
V_19 = ( T_4 ) F_8 ( V_1 -> V_8 , V_3 ) ;
for( V_20 = 0 ; ( V_18 = V_5 -> V_22 . V_23 [ V_20 ] ) && V_3 <= V_1 -> V_24 ; V_20 ++ ) {
if ( V_18 == V_19 ) {
* V_6 = F_1 ( V_1 , V_5 -> V_2 , V_3 , 1 , V_5 ) ;
#ifdef F_2
if ( F_2 & V_21 ) F_3 ( L_6 , V_18 ) ;
#endif
return 1 ;
}
}
return - 1 ;
}
T_3 * F_9 ( const int V_2 ,
const T_4 * V_25 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ) {
T_3 * V_28 = ( T_3 * ) F_10 ( sizeof( T_3 ) ) ;
V_28 -> V_17 = F_7 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_22 . V_23 = V_25 ;
V_28 -> V_4 = 1 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
static int F_11 ( T_2 * V_1 , int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_5 V_31 = 0 ;
int V_32 = V_3 ;
int V_33 = V_1 -> V_24 - V_3 ;
#ifdef F_2
if ( F_2 & V_34 ) F_3 ( L_7 , V_5 -> V_22 . V_23 ) ;
#endif
if ( V_3 + ( int ) V_5 -> V_35 > V_1 -> V_24 )
return - 1 ;
V_33 = V_33 < ( int ) V_5 -> V_36 ? V_33 : ( int ) V_5 -> V_36 ;
while( V_33 > 0 ) {
T_7 V_19 = F_8 ( V_1 -> V_8 , V_3 ++ ) ;
if ( ! V_5 -> V_22 . V_23 [ V_19 ] )
break;
V_31 ++ ;
V_33 -- ;
} ;
if ( V_31 < V_5 -> V_35 ) {
return - 1 ;
} else {
* V_6 = F_1 ( V_1 , V_5 -> V_2 , V_32 , V_31 , V_5 ) ;
#ifdef F_2
if ( F_2 & V_34 ) F_3 ( L_8 , V_31 ) ;
#endif
return V_31 ;
}
}
T_3 * F_12 ( const int V_2 ,
const T_5 V_37 ,
const T_5 V_38 ,
const T_4 * V_25 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 )
{
T_3 * V_28 = ( T_3 * ) F_10 ( sizeof( T_3 ) ) ;
char * V_39 ;
T_8 V_20 ;
V_39 = ( char * ) F_13 ( 256 ) ;
memset ( V_39 , 0x00 , 256 ) ;
for ( V_20 = 0 ; V_25 [ V_20 ] ; V_20 ++ )
V_39 [ ( unsigned ) V_25 [ V_20 ] ] = 0xFF ;
V_28 -> V_17 = F_11 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_22 . V_23 = V_39 ;
V_28 -> V_35 = V_37 ? V_37 : 1 ;
V_28 -> V_36 = V_38 ? V_38 : V_40 / 2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
static int F_14 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_4 V_18 , V_19 ;
T_5 V_20 ;
T_9 V_41 = FALSE ;
#ifdef F_2
if ( F_2 & V_42 ) F_3 ( L_9 , V_5 -> V_22 . V_23 ) ;
#endif
if ( V_3 >= V_1 -> V_24 ) {
return - 1 ;
}
V_19 = ( T_4 ) F_8 ( V_1 -> V_8 , V_3 ) ;
for( V_20 = 0 ; ( V_18 = V_5 -> V_22 . V_23 [ V_20 ] ) ; V_20 ++ ) {
if ( V_18 == V_19 ) {
V_41 = TRUE ;
}
}
if ( V_41 ) {
return - 1 ;
} else {
* V_6 = F_1 ( V_1 , V_5 -> V_2 , V_3 , 1 , V_5 ) ;
#ifdef F_2
if ( F_2 & V_42 ) F_3 ( L_10 , V_19 ) ;
#endif
return 1 ;
}
}
T_3 * F_15 ( const int V_2 ,
const T_4 * V_25 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ) {
T_3 * V_28 = ( T_3 * ) F_10 ( sizeof( T_3 ) ) ;
V_28 -> V_17 = F_14 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_22 . V_23 = V_25 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
T_3 * F_16 ( const int V_2 ,
const T_5 V_37 ,
const T_5 V_38 ,
const T_4 * V_25 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 )
{
T_3 * V_28 = ( T_3 * ) F_10 ( sizeof( T_3 ) ) ;
char * V_39 ;
T_8 V_20 ;
V_39 = ( char * ) F_13 ( 256 ) ;
memset ( V_39 , 0xFF , 256 ) ;
for ( V_20 = 0 ; V_25 [ V_20 ] ; V_20 ++ )
V_39 [ ( unsigned ) V_25 [ V_20 ] ] = '\0' ;
V_28 -> V_17 = F_11 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_22 . V_23 = V_39 ;
V_28 -> V_4 = 0 ;
V_28 -> V_35 = V_37 ? V_37 : 1 ;
V_28 -> V_36 = V_38 ? V_38 : V_40 / 2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
static int F_17 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
int V_4 = V_5 -> V_4 ;
#ifdef F_2
if ( F_2 & V_43 ) F_3 ( L_11 , V_5 -> V_22 . V_23 ) ;
#endif
if ( V_3 + V_5 -> V_4 > V_1 -> V_24 )
return - 1 ;
if ( F_18 ( V_1 -> V_8 , V_3 , V_5 -> V_22 . V_23 , V_4 ) == 0 ) {
* V_6 = F_1 ( V_1 , V_5 -> V_2 , V_3 , V_4 , V_5 ) ;
#ifdef F_2
if ( F_2 & V_43 ) F_3 ( L_12 , V_4 ) ;
#endif
return V_4 ;
} else {
return - 1 ;
}
}
T_3 * F_19 ( const int V_2 ,
const T_4 * V_23 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ) {
T_3 * V_28 = ( T_3 * ) F_10 ( sizeof( T_3 ) ) ;
V_28 -> V_17 = F_17 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_22 . V_23 = V_23 ;
V_28 -> V_4 = ( int ) strlen ( V_23 ) ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
static int F_20 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
int V_4 = V_5 -> V_4 ;
#ifdef F_2
if ( F_2 & V_44 ) F_3 ( L_13 , V_5 -> V_22 . V_23 ) ;
#endif
if ( V_3 + V_4 > V_1 -> V_24 )
return - 1 ;
if ( F_21 ( V_1 -> V_8 , V_3 , V_5 -> V_22 . V_23 , V_4 ) == 0 ) {
* V_6 = F_1 ( V_1 , V_5 -> V_2 , V_3 , V_4 , V_5 ) ;
#ifdef F_2
if ( F_2 & V_44 ) F_3 ( L_14 , V_4 ) ;
#endif
return V_4 ;
} else {
* V_6 = NULL ;
return - 1 ;
}
}
T_3 * F_22 ( const int V_2 ,
const T_4 * V_23 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ) {
T_3 * V_28 = ( T_3 * ) F_10 ( sizeof( T_3 ) ) ;
V_28 -> V_17 = F_20 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_22 . V_23 = V_23 ;
V_28 -> V_4 = ( int ) strlen ( V_23 ) ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
static int F_23 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_5 V_20 ;
#ifdef F_2
if ( F_2 & V_45 ) F_3 ( L_15 ) ;
#endif
if ( V_3 > V_1 -> V_24 )
return - 1 ;
for( V_20 = 0 ; V_20 < V_5 -> V_22 . V_46 -> V_4 ; V_20 ++ ) {
T_3 * V_28 = ( T_3 * ) F_24 ( V_5 -> V_22 . V_46 , V_20 ) ;
T_1 * V_47 = NULL ;
int V_48 ;
if ( V_3 + V_28 -> V_4 > V_1 -> V_24 )
continue;
V_48 = V_28 -> V_17 ( V_1 , V_3 , V_28 , & V_47 ) ;
if ( V_48 >= 0 ) {
* V_6 = F_1 ( V_1 , V_5 -> V_2 , V_47 -> V_3 , V_47 -> V_4 , V_5 ) ;
( * V_6 ) -> V_10 = V_47 ;
#ifdef F_2
if ( F_2 & V_45 ) F_3 ( L_16 , V_48 ) ;
#endif
return V_48 ;
}
}
return - 1 ;
}
T_3 * F_25 ( const int V_2 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
... ) {
T_3 * V_28 = ( T_3 * ) F_10 ( sizeof( T_3 ) ) ;
T_2 * V_49 ;
T_10 V_50 ;
V_28 -> V_17 = F_23 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
V_28 -> V_22 . V_46 = F_26 () ;
va_start ( V_50 , V_27 ) ;
while( ( V_49 = va_arg ( V_50 , T_2 * ) ) ) {
F_27 ( V_28 -> V_22 . V_46 , V_49 ) ;
} ;
va_end ( V_50 ) ;
return V_28 ;
}
static int F_28 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
int V_51 ;
T_4 * V_52 = NULL ;
T_1 * V_53 = NULL ;
T_3 * V_54 = NULL ;
int V_55 ;
T_1 * V_56 = NULL ;
int V_57 ;
T_1 * V_58 ;
#ifdef F_2
if ( F_2 & V_59 ) F_3 ( L_17 ) ;
#endif
if ( V_3 > V_1 -> V_24 )
return - 1 ;
V_51 = V_5 -> V_22 . V_60 . V_52 -> V_17 ( V_1 , V_3 , V_5 -> V_22 . V_60 . V_52 , & V_53 ) ;
if ( V_51 < 0 )
return - 1 ;
V_52 = F_29 ( F_5 () , V_53 -> V_8 , V_53 -> V_3 , V_53 -> V_4 ) ;
#ifdef F_2
if ( F_2 & V_59 ) F_3 ( L_18 , V_52 ) ;
#endif
if ( ( V_54 = ( T_3 * ) F_30 ( V_5 -> V_22 . V_60 . V_61 , V_52 ) ) ) {
V_55 = V_54 -> V_17 ( V_1 , V_3 + V_51 , V_54 , & V_56 ) ;
} else if ( V_5 -> V_22 . V_60 . V_62 ) {
V_55 = V_5 -> V_22 . V_60 . V_62 -> V_17 ( V_1 , V_3 + V_51 , V_5 -> V_22 . V_60 . V_62 , & V_56 ) ;
if ( V_55 < 0 )
return - 1 ;
} else {
return - 1 ;
}
V_57 = V_51 + V_55 ;
V_58 = F_1 ( V_1 , V_56 -> V_2 , V_3 , V_57 , V_5 ) ;
V_58 -> V_10 = V_53 ;
V_58 -> V_10 -> V_12 -> V_11 = V_56 ;
* V_6 = V_58 ;
#ifdef F_2
if ( F_2 & V_59 ) F_3 ( L_19 , V_57 ) ;
#endif
return V_57 ;
}
T_3 * F_31 ( const int V_2 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
T_3 * V_52 ,
T_3 * V_62 ,
... ) {
T_3 * V_28 = ( T_3 * ) F_10 ( sizeof( T_3 ) ) ;
T_4 * V_63 ;
T_3 * V_49 ;
T_10 V_50 ;
V_28 -> V_17 = F_28 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
V_28 -> V_22 . V_60 . V_61 = F_32 ( V_64 , V_65 ) ;
V_28 -> V_22 . V_60 . V_52 = V_52 ;
V_28 -> V_22 . V_60 . V_62 = V_62 ;
va_start ( V_50 , V_62 ) ;
while( ( V_63 = va_arg ( V_50 , T_4 * ) ) ) {
V_49 = va_arg ( V_50 , T_3 * ) ;
F_33 ( V_28 -> V_22 . V_60 . V_61 , V_63 , V_49 ) ;
}
va_end ( V_50 ) ;
return V_28 ;
}
void F_34 ( T_3 * V_28 , ... ) {
T_3 * V_49 ;
T_10 V_50 ;
T_4 * V_63 ;
va_start ( V_50 , V_28 ) ;
while ( ( V_63 = va_arg ( V_50 , T_4 * ) ) ) {
V_49 = va_arg ( V_50 , T_3 * ) ;
F_33 ( V_28 -> V_22 . V_60 . V_61 , V_63 , V_49 ) ;
}
va_end ( V_50 ) ;
}
static int F_35 ( T_2 * V_1 , int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_5 V_20 ;
int V_4 = 0 ;
int V_32 = V_3 ;
T_1 * V_58 = NULL ;
if ( V_3 > V_1 -> V_24 )
return - 1 ;
#ifdef F_2
if ( F_2 & V_66 ) F_3 ( L_20 ) ;
#endif
for( V_20 = 0 ; V_20 < V_5 -> V_22 . V_46 -> V_4 ; V_20 ++ ) {
T_3 * V_28 = ( T_3 * ) F_24 ( V_5 -> V_22 . V_46 , V_20 ) ;
T_1 * V_47 = NULL ;
if ( V_3 + V_28 -> V_4 > V_1 -> V_24 )
return - 1 ;
V_4 = V_28 -> V_17 ( V_1 , V_3 , V_28 , & V_47 ) ;
if ( V_4 >= 0 ) {
if ( V_58 ) {
if ( V_47 -> V_4 )
V_58 -> V_4 = ( V_47 -> V_3 - V_58 -> V_3 ) + V_47 -> V_4 ;
V_58 -> V_10 -> V_12 -> V_11 = V_47 ;
V_58 -> V_10 -> V_12 = V_47 ;
} else {
V_58 = F_1 ( V_1 , V_5 -> V_2 , V_47 -> V_3 , V_47 -> V_4 , V_5 ) ;
V_58 -> V_10 = V_47 ;
V_47 -> V_12 = V_47 ;
}
} else {
return - 1 ;
}
V_3 += V_4 ;
V_3 += F_6 ( V_1 , V_3 ) ;
}
* V_6 = V_58 ;
#ifdef F_2
if ( F_2 & V_66 ) F_3 ( L_21 , V_3 - V_32 ) ;
#endif
return V_3 - V_32 ;
}
T_3 * F_36 ( const int V_2 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
... ) {
T_3 * V_28 = ( T_3 * ) F_10 ( sizeof( T_3 ) ) ;
T_3 * V_49 = NULL ;
T_10 V_50 ;
V_28 -> V_17 = F_35 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
V_28 -> V_22 . V_46 = F_26 () ;
va_start ( V_50 , V_27 ) ;
while( ( V_49 = va_arg ( V_50 , T_3 * ) ) ) {
F_27 ( V_28 -> V_22 . V_46 , V_49 ) ;
} ;
va_end ( V_50 ) ;
return V_28 ;
}
static int F_37 ( T_2 * V_1 , int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_5 V_67 = 0 ;
int V_32 = V_3 ;
T_1 * V_58 = NULL ;
#ifdef F_2
if ( F_2 & V_68 ) F_3 ( L_22 ) ;
#endif
if ( V_3 > V_1 -> V_24 )
return - 1 ;
if ( V_5 -> V_35 == 0 ) {
V_58 = F_1 ( V_1 , V_5 -> V_2 , V_3 , 0 , V_5 ) ;
}
while ( V_67 < V_5 -> V_36 ) {
T_1 * V_47 = NULL ;
int V_13 ;
if ( V_3 > V_1 -> V_24 )
return - 1 ;
V_13 = V_5 -> V_22 . V_69 -> V_17 ( V_1 , V_3 , V_5 -> V_22 . V_69 , & V_47 ) ;
if( V_13 >= 0 ) {
if ( V_58 ) {
if ( V_47 -> V_4 )
V_58 -> V_4 = ( V_47 -> V_3 - V_58 -> V_3 ) + V_47 -> V_4 ;
if ( V_58 -> V_10 ) {
V_58 -> V_10 -> V_12 -> V_11 = V_47 ;
V_58 -> V_10 -> V_12 = V_47 ;
} else {
V_58 -> V_10 = V_47 ;
}
} else {
V_58 = F_1 ( V_1 , V_5 -> V_2 , V_47 -> V_3 , V_47 -> V_4 , V_5 ) ;
V_58 -> V_10 = V_47 ;
}
} else {
break;
}
V_3 += V_13 ;
V_67 ++ ;
}
#ifdef F_2
if ( F_2 & V_68 ) F_3 ( L_23 , V_67 ) ;
#endif
if( V_67 < V_5 -> V_35 ) {
return - 1 ;
}
* V_6 = V_58 ;
#ifdef F_2
if ( F_2 & V_68 ) F_3 ( L_24 , V_3 - V_32 ) ;
#endif
return V_3 - V_32 ;
}
T_3 * F_38 ( const int V_2 ,
const T_5 V_70 ,
const T_5 V_71 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
const T_3 * V_49 ) {
T_3 * V_28 = ( T_3 * ) F_10 ( sizeof( T_3 ) ) ;
F_39 ( V_70 <= V_71 ) ;
V_28 -> V_17 = F_37 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_35 = V_70 ;
V_28 -> V_36 = V_71 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
V_28 -> V_22 . V_69 = V_49 ;
return V_28 ;
}
static int F_40 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_1 * V_47 = NULL ;
int V_4 = 0 ;
int V_72 = V_3 ;
#ifdef F_2
if ( F_2 & V_73 ) F_3 ( L_25 ) ;
#endif
if ( V_3 + V_5 -> V_22 . V_74 . V_69 -> V_4 > V_1 -> V_24 )
return - 1 ;
do {
V_4 = V_5 -> V_22 . V_74 . V_69 -> V_17 ( V_1 , V_72 ++ , V_5 -> V_22 . V_74 . V_69 , & V_47 ) ;
} while( V_4 < 0 && V_72 + 1 < V_1 -> V_24 );
if ( V_4 >= 0 ) {
V_47 -> V_2 = V_5 -> V_2 ;
V_47 -> V_11 = NULL ;
V_47 -> V_12 = NULL ;
V_47 -> V_5 = V_5 ;
V_47 -> V_3 = V_3 ;
( * V_6 ) = V_47 ;
switch ( V_5 -> V_22 . V_74 . V_75 ) {
case V_76 :
V_47 -> V_4 = V_72 - V_3 - 1 + V_4 ;
#ifdef F_2
if ( F_2 & V_73 ) F_3 ( L_26 , V_72 - V_3 - 1 + V_4 ) ;
#endif
return V_72 - V_3 - 1 + V_4 ;
case V_77 :
V_47 -> V_4 = V_72 - V_3 - 1 ;
#ifdef F_2
if ( F_2 & V_73 ) F_3 ( L_26 , V_72 - V_3 - 1 + V_4 ) ;
#endif
return V_72 - V_3 - 1 + V_4 ;
case V_78 :
V_47 -> V_4 = V_72 - V_3 - 1 ;
#ifdef F_2
if ( F_2 & V_73 ) F_3 ( L_26 , V_72 - V_3 - 1 ) ;
#endif
return V_72 - V_3 - 1 ;
default:
F_41 () ;
return - 1 ;
}
} else {
return - 1 ;
}
}
T_3 * F_42 ( const int V_2 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
const T_3 * V_49 ,
T_11 V_79 ) {
T_3 * V_28 = ( T_3 * ) F_10 ( sizeof( T_3 ) ) ;
V_28 -> V_17 = F_40 ;
V_28 -> V_22 . V_74 . V_75 = V_79 ;
V_28 -> V_22 . V_74 . V_69 = V_49 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
T_3 * F_43 ( const int V_2 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
const char V_80 ,
const char V_81 ) {
T_4 * V_82 = F_44 ( L_27 , V_81 , V_80 ) ;
T_4 * V_83 = F_44 ( L_28 , V_80 ) ;
T_3 * V_84 = F_9 ( - 1 , V_83 , NULL , NULL , NULL ) ;
return F_25 ( V_2 , V_9 , V_26 , V_27 ,
F_36 ( - 1 , NULL , NULL , NULL ,
V_84 ,
F_36 ( - 1 , NULL , NULL , NULL ,
F_25 ( - 1 , NULL , NULL , NULL ,
F_19 ( - 1 , V_82 , NULL , NULL , NULL ) ,
F_16 ( - 1 , 0 , 0 , V_83 , NULL , NULL , NULL ) ,
NULL ) ,
NULL ) ,
V_84 ,
NULL ) ,
F_36 ( - 1 , NULL , NULL , NULL ,
V_84 ,
V_84 ,
NULL ) ,
NULL ) ;
}
void F_45 ( void * T_12 V_85 ,
const void * T_13 V_85 ,
T_1 * V_6 ) {
V_6 -> V_3 += 1 ;
V_6 -> V_4 -= 2 ;
}
T_2 * F_46 ( T_14 * V_8 ,
const int V_3 ,
int V_4 ,
void * V_9 ,
const T_3 * V_15 ) {
T_2 * V_1 = ( T_2 * ) F_4 ( F_5 () , T_2 ) ;
#ifdef F_2
if ( F_2 & V_86 ) F_3 ( L_29 , V_3 , V_4 ) ;
#endif
V_1 -> V_8 = V_8 ;
V_1 -> V_3 = V_3 ;
V_4 = ( V_4 == - 1 ) ? ( int ) F_47 ( V_8 ) : V_4 ;
V_1 -> V_24 = V_3 + V_4 ;
V_1 -> V_9 = V_9 ;
V_1 -> V_15 = V_15 ;
return V_1 ;
}
T_9 F_48 ( T_2 * V_1 ,
const int V_3 ,
int V_4 ) {
#ifdef F_2
if ( F_2 & V_86 ) F_3 ( L_29 , V_3 , V_4 ) ;
#endif
V_4 = ( V_4 == - 1 ) ? ( int ) F_47 ( V_1 -> V_8 ) : V_4 ;
if( F_49 ( V_1 -> V_8 , V_3 ) >= V_4 ) {
V_1 -> V_3 = V_3 ;
V_1 -> V_24 = V_3 + V_4 ;
return TRUE ;
} else {
return FALSE ;
}
}
T_5 F_50 ( T_2 * V_1 ) {
return V_1 -> V_3 ;
}
static void F_51 ( T_2 * V_1 , T_1 * V_87 ) {
T_15 * V_88 = F_52 ( F_5 () ) ;
while ( V_87 ) {
if( V_87 -> V_5 -> V_29 ) {
#ifdef F_2
if ( F_2 & V_89 ) F_3 ( L_30 , V_87 -> V_2 , V_87 -> V_3 , V_87 -> V_4 ) ;
#endif
V_87 -> V_5 -> V_29 ( V_1 -> V_9 , V_87 -> V_5 -> V_9 , V_87 ) ;
}
if( V_87 -> V_10 ) {
F_53 ( V_88 , V_87 ) ;
V_87 = V_87 -> V_10 ;
continue;
} else {
#ifdef F_2
if ( F_2 & V_89 ) F_3 ( L_31 , V_87 -> V_2 , V_87 -> V_3 , V_87 -> V_4 ) ;
#endif
if( V_87 -> V_5 -> V_30 ) V_87 -> V_5 -> V_30 ( V_1 -> V_9 , V_87 -> V_5 -> V_9 , V_87 ) ;
}
V_87 = V_87 -> V_11 ;
while( ! V_87 && F_54 ( V_88 ) > 0 ) {
V_87 = ( T_1 * ) F_55 ( V_88 ) ;
#ifdef F_2
if ( F_2 & V_89 ) F_3 ( L_31 , V_87 -> V_2 , V_87 -> V_3 , V_87 -> V_4 ) ;
#endif
if( V_87 -> V_5 -> V_30 ) V_87 -> V_5 -> V_30 ( V_1 -> V_9 , V_87 -> V_5 -> V_9 , V_87 ) ;
V_87 = V_87 -> V_11 ;
}
}
}
T_9 F_56 ( T_2 * V_1 ,
const T_3 * V_5 ) {
T_1 * V_6 = NULL ;
int V_13 ;
int V_3 = V_1 -> V_3 ;
#ifdef F_2
if ( F_2 & V_90 ) F_3 ( L_32 , V_3 ) ;
#endif
V_3 += F_6 ( V_1 , V_3 ) ;
#ifdef F_2
if ( F_2 & V_90 ) F_3 ( L_33 , V_3 ) ;
#endif
V_13 = V_5 -> V_17 ( V_1 , V_3 , V_5 , & V_6 ) ;
if ( V_13 >= 0 ) {
#ifdef F_2
if ( F_2 & V_90 ) F_3 ( L_34 , V_13 ) ;
#endif
return TRUE ;
} else {
#ifdef F_2
if ( F_2 & V_90 ) F_3 ( L_35 ) ;
#endif
return FALSE ;
}
}
T_1 * F_57 ( T_2 * V_1 ,
const T_3 * V_5 ) {
T_1 * V_6 = NULL ;
int V_13 ;
int V_3 = V_1 -> V_3 ;
#ifdef F_2
if ( F_2 & V_91 ) F_3 ( L_36 , V_3 ) ;
#endif
V_3 += F_6 ( V_1 , V_3 ) ;
#ifdef F_2
if ( F_2 & V_91 ) F_3 ( L_37 , V_3 ) ;
#endif
V_13 = V_5 -> V_17 ( V_1 , V_3 , V_5 , & V_6 ) ;
if ( V_13 >= 0 ) {
#ifdef F_2
if ( F_2 & V_91 ) F_3 ( L_38 , V_13 ) ;
#endif
F_51 ( V_1 , V_6 ) ;
V_1 -> V_3 = V_3 + V_13 ;
#ifdef F_2
if ( F_2 & V_91 ) F_3 ( L_39 , V_1 -> V_3 ) ;
#endif
return V_6 ;
} else {
return NULL ;
}
}
T_1 * F_58 ( T_2 * V_1 , const T_3 * V_5 ) {
T_1 * V_6 = NULL ;
int V_4 = 0 ;
int V_3 = V_1 -> V_3 ;
int V_72 = V_3 - 1 ;
#ifdef F_2
if ( F_2 & V_92 ) F_3 ( L_36 , V_1 -> V_3 ) ;
#endif
do {
V_4 = V_5 -> V_17 ( V_1 , V_72 + 1 , V_5 , & V_6 ) ;
} while( V_4 < 0 && ++ V_72 < V_1 -> V_24 );
if ( V_4 >= 0 ) {
#ifdef F_2
if ( F_2 & V_92 ) F_3 ( L_40 , V_72 , V_4 ) ;
#endif
F_51 ( V_1 , V_6 ) ;
V_1 -> V_3 = V_72 + V_4 ;
#ifdef F_2
if ( F_2 & V_92 ) F_3 ( L_39 , V_1 -> V_3 ) ;
#endif
return V_6 ;
} else {
#ifdef F_2
if ( F_2 & V_92 ) F_3 ( L_41 ) ;
#endif
return NULL ;
}
}
void F_59 ( T_16 * V_93 , T_1 * V_87 ) {
T_15 * V_88 = F_52 ( F_5 () ) ;
struct V_94 * V_95 = F_4 ( F_5 () , struct V_94 ) ;
T_17 * V_96 ;
V_95 -> V_93 = V_93 ;
V_95 -> V_97 = V_87 ;
while ( V_87 ) {
V_96 = F_60 ( V_95 -> V_93 , V_87 -> V_8 , V_87 -> V_3 , V_87 -> V_4 ) ;
if( V_87 -> V_10 ) {
V_95 -> V_97 = V_87 ;
F_53 ( V_88 , V_95 ) ;
V_95 = F_4 ( F_5 () , struct V_94 ) ;
V_95 -> V_93 = F_61 ( V_96 , 0 ) ;
V_87 = V_87 -> V_10 ;
continue;
}
V_87 = V_87 -> V_11 ;
while( ! V_87 && F_54 ( V_88 ) > 0 ) {
V_95 = (struct V_94 * ) F_55 ( V_88 ) ;
V_87 = V_95 -> V_97 -> V_11 ;
}
}
}
