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
T_3 * V_28 = F_10 ( F_11 () , T_3 ) ;
V_28 -> V_17 = F_7 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_22 . V_23 = V_25 ;
V_28 -> V_4 = 1 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
static int F_12 ( T_2 * V_1 , int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
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
T_3 * F_13 ( const int V_2 ,
const T_5 V_37 ,
const T_5 V_38 ,
const T_4 * V_25 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 )
{
T_3 * V_28 = ( T_3 * ) F_14 ( F_11 () , sizeof( T_3 ) ) ;
char * V_39 ;
T_8 V_20 ;
V_39 = ( char * ) F_15 ( F_11 () , 256 ) ;
memset ( V_39 , 0x00 , 256 ) ;
for ( V_20 = 0 ; V_25 [ V_20 ] ; V_20 ++ )
V_39 [ ( unsigned ) V_25 [ V_20 ] ] = ( char ) 0xFF ;
V_28 -> V_17 = F_12 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_22 . V_23 = V_39 ;
V_28 -> V_35 = V_37 ? V_37 : 1 ;
V_28 -> V_36 = V_38 ? V_38 : V_40 / 2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
static int F_16 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
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
T_3 * F_17 ( const int V_2 ,
const T_4 * V_25 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ) {
T_3 * V_28 = ( T_3 * ) F_14 ( F_11 () , sizeof( T_3 ) ) ;
V_28 -> V_17 = F_16 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_22 . V_23 = V_25 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
T_3 * F_18 ( const int V_2 ,
const T_5 V_37 ,
const T_5 V_38 ,
const T_4 * V_25 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 )
{
T_3 * V_28 = ( T_3 * ) F_14 ( F_11 () , sizeof( T_3 ) ) ;
char * V_39 ;
T_8 V_20 ;
V_39 = ( char * ) F_15 ( F_11 () , 256 ) ;
memset ( V_39 , 0xFF , 256 ) ;
for ( V_20 = 0 ; V_25 [ V_20 ] ; V_20 ++ )
V_39 [ ( unsigned ) V_25 [ V_20 ] ] = '\0' ;
V_28 -> V_17 = F_12 ;
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
static int F_19 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
int V_4 = V_5 -> V_4 ;
#ifdef F_2
if ( F_2 & V_43 ) F_3 ( L_11 , V_5 -> V_22 . V_23 ) ;
#endif
if ( V_3 + V_5 -> V_4 > V_1 -> V_24 )
return - 1 ;
if ( F_20 ( V_1 -> V_8 , V_3 , V_5 -> V_22 . V_23 , V_4 ) == 0 ) {
* V_6 = F_1 ( V_1 , V_5 -> V_2 , V_3 , V_4 , V_5 ) ;
#ifdef F_2
if ( F_2 & V_43 ) F_3 ( L_12 , V_4 ) ;
#endif
return V_4 ;
} else {
return - 1 ;
}
}
T_3 * F_21 ( const int V_2 ,
const T_4 * V_23 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ) {
T_3 * V_28 = ( T_3 * ) F_14 ( F_11 () , sizeof( T_3 ) ) ;
V_28 -> V_17 = F_19 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_22 . V_23 = V_23 ;
V_28 -> V_4 = ( int ) strlen ( V_23 ) ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
static int F_22 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
int V_4 = V_5 -> V_4 ;
#ifdef F_2
if ( F_2 & V_44 ) F_3 ( L_13 , V_5 -> V_22 . V_23 ) ;
#endif
if ( V_3 + V_4 > V_1 -> V_24 )
return - 1 ;
if ( F_23 ( V_1 -> V_8 , V_3 , V_5 -> V_22 . V_23 , V_4 ) == 0 ) {
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
T_3 * F_24 ( const int V_2 ,
const T_4 * V_23 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ) {
T_3 * V_28 = ( T_3 * ) F_14 ( F_11 () , sizeof( T_3 ) ) ;
V_28 -> V_17 = F_22 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_22 . V_23 = V_23 ;
V_28 -> V_4 = ( int ) strlen ( V_23 ) ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
static int F_25 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_5 V_20 ;
#ifdef F_2
if ( F_2 & V_45 ) F_3 ( L_15 ) ;
#endif
if ( V_3 > V_1 -> V_24 )
return - 1 ;
for( V_20 = 0 ; V_20 < V_5 -> V_22 . V_46 -> V_4 ; V_20 ++ ) {
T_3 * V_28 = ( T_3 * ) F_26 ( V_5 -> V_22 . V_46 , V_20 ) ;
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
static T_9
F_27 ( T_10 * T_11 V_49 , T_12 T_13 V_49 , void * V_50 )
{
T_3 * V_28 = ( T_3 * ) V_50 ;
F_28 ( V_28 -> V_22 . V_46 , TRUE ) ;
return FALSE ;
}
T_3 * F_29 ( const int V_2 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
... ) {
T_3 * V_28 = ( T_3 * ) F_14 ( F_11 () , sizeof( T_3 ) ) ;
T_2 * V_51 ;
T_14 V_52 ;
V_28 -> V_17 = F_25 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
V_28 -> V_22 . V_46 = F_30 () ;
F_31 ( F_11 () , F_27 , V_28 ) ;
va_start ( V_52 , V_27 ) ;
while( ( V_51 = va_arg ( V_52 , T_2 * ) ) ) {
F_32 ( V_28 -> V_22 . V_46 , V_51 ) ;
} ;
va_end ( V_52 ) ;
return V_28 ;
}
static int F_33 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
int V_53 ;
T_4 * V_54 = NULL ;
T_1 * V_55 = NULL ;
T_3 * V_56 = NULL ;
int V_57 ;
T_1 * V_58 = NULL ;
int V_59 ;
T_1 * V_60 ;
#ifdef F_2
if ( F_2 & V_61 ) F_3 ( L_17 ) ;
#endif
if ( V_3 > V_1 -> V_24 )
return - 1 ;
V_53 = V_5 -> V_22 . V_62 . V_54 -> V_17 ( V_1 , V_3 , V_5 -> V_22 . V_62 . V_54 , & V_55 ) ;
if ( V_53 < 0 )
return - 1 ;
V_54 = F_34 ( F_5 () , V_55 -> V_8 , V_55 -> V_3 , V_55 -> V_4 , V_63 ) ;
#ifdef F_2
if ( F_2 & V_61 ) F_3 ( L_18 , V_54 ) ;
#endif
if ( ( V_56 = ( T_3 * ) F_35 ( V_5 -> V_22 . V_62 . V_64 , V_54 ) ) ) {
V_57 = V_56 -> V_17 ( V_1 , V_3 + V_53 , V_56 , & V_58 ) ;
} else if ( V_5 -> V_22 . V_62 . V_65 ) {
V_57 = V_5 -> V_22 . V_62 . V_65 -> V_17 ( V_1 , V_3 + V_53 , V_5 -> V_22 . V_62 . V_65 , & V_58 ) ;
if ( V_57 < 0 )
return - 1 ;
} else {
return - 1 ;
}
V_59 = V_53 + V_57 ;
V_60 = F_1 ( V_1 , V_58 -> V_2 , V_3 , V_59 , V_5 ) ;
V_60 -> V_10 = V_55 ;
V_60 -> V_10 -> V_12 -> V_11 = V_58 ;
* V_6 = V_60 ;
#ifdef F_2
if ( F_2 & V_61 ) F_3 ( L_19 , V_59 ) ;
#endif
return V_59 ;
}
T_3 * F_36 ( const int V_2 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
T_3 * V_54 ,
T_3 * V_65 ,
... ) {
T_3 * V_28 = ( T_3 * ) F_14 ( F_11 () , sizeof( T_3 ) ) ;
T_4 * V_66 ;
T_3 * V_51 ;
T_14 V_52 ;
V_28 -> V_17 = F_33 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
V_28 -> V_22 . V_62 . V_64 = F_37 ( F_11 () , V_67 , V_68 ) ;
V_28 -> V_22 . V_62 . V_54 = V_54 ;
V_28 -> V_22 . V_62 . V_65 = V_65 ;
va_start ( V_52 , V_65 ) ;
while( ( V_66 = va_arg ( V_52 , T_4 * ) ) ) {
V_51 = va_arg ( V_52 , T_3 * ) ;
F_38 ( V_28 -> V_22 . V_62 . V_64 , V_66 , V_51 ) ;
}
va_end ( V_52 ) ;
return V_28 ;
}
void F_39 ( T_3 * V_28 , ... ) {
T_3 * V_51 ;
T_14 V_52 ;
T_4 * V_66 ;
va_start ( V_52 , V_28 ) ;
while ( ( V_66 = va_arg ( V_52 , T_4 * ) ) ) {
V_51 = va_arg ( V_52 , T_3 * ) ;
F_38 ( V_28 -> V_22 . V_62 . V_64 , V_66 , V_51 ) ;
}
va_end ( V_52 ) ;
}
static int F_40 ( T_2 * V_1 , int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_5 V_20 ;
int V_4 = 0 ;
int V_32 = V_3 ;
T_1 * V_60 = NULL ;
if ( V_3 > V_1 -> V_24 )
return - 1 ;
#ifdef F_2
if ( F_2 & V_69 ) F_3 ( L_20 ) ;
#endif
for( V_20 = 0 ; V_20 < V_5 -> V_22 . V_46 -> V_4 ; V_20 ++ ) {
T_3 * V_28 = ( T_3 * ) F_26 ( V_5 -> V_22 . V_46 , V_20 ) ;
T_1 * V_47 = NULL ;
if ( V_3 + V_28 -> V_4 > V_1 -> V_24 )
return - 1 ;
V_4 = V_28 -> V_17 ( V_1 , V_3 , V_28 , & V_47 ) ;
if ( V_4 >= 0 ) {
if ( V_60 ) {
if ( V_47 -> V_4 )
V_60 -> V_4 = ( V_47 -> V_3 - V_60 -> V_3 ) + V_47 -> V_4 ;
V_60 -> V_10 -> V_12 -> V_11 = V_47 ;
V_60 -> V_10 -> V_12 = V_47 ;
} else {
V_60 = F_1 ( V_1 , V_5 -> V_2 , V_47 -> V_3 , V_47 -> V_4 , V_5 ) ;
V_60 -> V_10 = V_47 ;
V_47 -> V_12 = V_47 ;
}
} else {
return - 1 ;
}
V_3 += V_4 ;
V_3 += F_6 ( V_1 , V_3 ) ;
}
* V_6 = V_60 ;
#ifdef F_2
if ( F_2 & V_69 ) F_3 ( L_21 , V_3 - V_32 ) ;
#endif
return V_3 - V_32 ;
}
T_3 * F_41 ( const int V_2 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
... ) {
T_3 * V_28 = ( T_3 * ) F_14 ( F_11 () , sizeof( T_3 ) ) ;
T_3 * V_51 = NULL ;
T_14 V_52 ;
V_28 -> V_17 = F_40 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
V_28 -> V_22 . V_46 = F_30 () ;
F_31 ( F_11 () , F_27 , V_28 ) ;
va_start ( V_52 , V_27 ) ;
while( ( V_51 = va_arg ( V_52 , T_3 * ) ) ) {
F_32 ( V_28 -> V_22 . V_46 , V_51 ) ;
} ;
va_end ( V_52 ) ;
return V_28 ;
}
static int F_42 ( T_2 * V_1 , int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_5 V_70 = 0 ;
int V_32 = V_3 ;
T_1 * V_60 = NULL ;
#ifdef F_2
if ( F_2 & V_71 ) F_3 ( L_22 ) ;
#endif
if ( V_3 > V_1 -> V_24 )
return - 1 ;
if ( V_5 -> V_35 == 0 ) {
V_60 = F_1 ( V_1 , V_5 -> V_2 , V_3 , 0 , V_5 ) ;
}
while ( V_70 < V_5 -> V_36 ) {
T_1 * V_47 = NULL ;
int V_13 ;
if ( V_3 > V_1 -> V_24 )
return - 1 ;
V_13 = V_5 -> V_22 . V_72 -> V_17 ( V_1 , V_3 , V_5 -> V_22 . V_72 , & V_47 ) ;
if( V_13 >= 0 ) {
if ( V_60 ) {
if ( V_47 -> V_4 )
V_60 -> V_4 = ( V_47 -> V_3 - V_60 -> V_3 ) + V_47 -> V_4 ;
if ( V_60 -> V_10 ) {
V_60 -> V_10 -> V_12 -> V_11 = V_47 ;
V_60 -> V_10 -> V_12 = V_47 ;
} else {
V_60 -> V_10 = V_47 ;
}
} else {
V_60 = F_1 ( V_1 , V_5 -> V_2 , V_47 -> V_3 , V_47 -> V_4 , V_5 ) ;
V_60 -> V_10 = V_47 ;
}
} else {
break;
}
V_3 += V_13 ;
V_70 ++ ;
}
#ifdef F_2
if ( F_2 & V_71 ) F_3 ( L_23 , V_70 ) ;
#endif
if( V_70 < V_5 -> V_35 ) {
return - 1 ;
}
* V_6 = V_60 ;
#ifdef F_2
if ( F_2 & V_71 ) F_3 ( L_24 , V_3 - V_32 ) ;
#endif
return V_3 - V_32 ;
}
T_3 * F_43 ( const int V_2 ,
const T_5 V_73 ,
const T_5 V_74 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
const T_3 * V_51 ) {
T_3 * V_28 = ( T_3 * ) F_14 ( F_11 () , sizeof( T_3 ) ) ;
F_44 ( V_73 <= V_74 ) ;
V_28 -> V_17 = F_42 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_35 = V_73 ;
V_28 -> V_36 = V_74 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
V_28 -> V_22 . V_72 = V_51 ;
return V_28 ;
}
static int F_45 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_1 * V_47 = NULL ;
int V_4 = 0 ;
int V_75 = V_3 ;
#ifdef F_2
if ( F_2 & V_76 ) F_3 ( L_25 ) ;
#endif
if ( V_3 + V_5 -> V_22 . V_77 . V_72 -> V_4 > V_1 -> V_24 )
return - 1 ;
do {
V_4 = V_5 -> V_22 . V_77 . V_72 -> V_17 ( V_1 , V_75 ++ , V_5 -> V_22 . V_77 . V_72 , & V_47 ) ;
} while( V_4 < 0 && V_75 + 1 < V_1 -> V_24 );
if ( V_4 >= 0 ) {
V_47 -> V_2 = V_5 -> V_2 ;
V_47 -> V_11 = NULL ;
V_47 -> V_12 = NULL ;
V_47 -> V_5 = V_5 ;
V_47 -> V_3 = V_3 ;
( * V_6 ) = V_47 ;
switch ( V_5 -> V_22 . V_77 . V_78 ) {
case V_79 :
V_47 -> V_4 = V_75 - V_3 - 1 + V_4 ;
#ifdef F_2
if ( F_2 & V_76 ) F_3 ( L_26 , V_75 - V_3 - 1 + V_4 ) ;
#endif
return V_75 - V_3 - 1 + V_4 ;
case V_80 :
V_47 -> V_4 = V_75 - V_3 - 1 ;
#ifdef F_2
if ( F_2 & V_76 ) F_3 ( L_26 , V_75 - V_3 - 1 + V_4 ) ;
#endif
return V_75 - V_3 - 1 + V_4 ;
case V_81 :
V_47 -> V_4 = V_75 - V_3 - 1 ;
#ifdef F_2
if ( F_2 & V_76 ) F_3 ( L_26 , V_75 - V_3 - 1 ) ;
#endif
return V_75 - V_3 - 1 ;
default:
F_46 () ;
return - 1 ;
}
} else {
return - 1 ;
}
}
T_3 * F_47 ( const int V_2 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
const T_3 * V_51 ,
T_15 V_82 ) {
T_3 * V_28 = ( T_3 * ) F_14 ( F_11 () , sizeof( T_3 ) ) ;
V_28 -> V_17 = F_45 ;
V_28 -> V_22 . V_77 . V_78 = V_82 ;
V_28 -> V_22 . V_77 . V_72 = V_51 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
T_3 * F_48 ( const int V_2 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
const char V_83 ,
const char V_84 ) {
T_4 * V_85 = F_49 ( F_11 () , L_27 , V_84 , V_83 ) ;
T_4 * V_86 = F_49 ( F_11 () , L_28 , V_83 ) ;
T_3 * V_87 = F_9 ( - 1 , V_86 , NULL , NULL , NULL ) ;
return F_29 ( V_2 , V_9 , V_26 , V_27 ,
F_41 ( - 1 , NULL , NULL , NULL ,
V_87 ,
F_41 ( - 1 , NULL , NULL , NULL ,
F_29 ( - 1 , NULL , NULL , NULL ,
F_21 ( - 1 , V_85 , NULL , NULL , NULL ) ,
F_18 ( - 1 , 0 , 0 , V_86 , NULL , NULL , NULL ) ,
NULL ) ,
NULL ) ,
V_87 ,
NULL ) ,
F_41 ( - 1 , NULL , NULL , NULL ,
V_87 ,
V_87 ,
NULL ) ,
NULL ) ;
}
void F_50 ( void * T_16 V_49 ,
const void * T_17 V_49 ,
T_1 * V_6 ) {
V_6 -> V_3 += 1 ;
V_6 -> V_4 -= 2 ;
}
T_2 * F_51 ( T_18 * V_8 ,
const int V_3 ,
int V_4 ,
void * V_9 ,
const T_3 * V_15 ) {
T_2 * V_1 = ( T_2 * ) F_4 ( F_5 () , T_2 ) ;
#ifdef F_2
if ( F_2 & V_88 ) F_3 ( L_29 , V_3 , V_4 ) ;
#endif
V_1 -> V_8 = V_8 ;
V_1 -> V_3 = V_3 ;
V_4 = ( V_4 == - 1 ) ? ( int ) F_52 ( V_8 ) : V_4 ;
V_1 -> V_24 = V_3 + V_4 ;
V_1 -> V_9 = V_9 ;
V_1 -> V_15 = V_15 ;
return V_1 ;
}
T_9 F_53 ( T_2 * V_1 ,
const int V_3 ,
int V_4 ) {
#ifdef F_2
if ( F_2 & V_88 ) F_3 ( L_29 , V_3 , V_4 ) ;
#endif
V_4 = ( V_4 == - 1 ) ? ( int ) F_52 ( V_1 -> V_8 ) : V_4 ;
if( F_54 ( V_1 -> V_8 , V_3 ) >= V_4 ) {
V_1 -> V_3 = V_3 ;
V_1 -> V_24 = V_3 + V_4 ;
return TRUE ;
} else {
return FALSE ;
}
}
T_5 F_55 ( T_2 * V_1 ) {
return V_1 -> V_3 ;
}
static void F_56 ( T_2 * V_1 , T_1 * V_89 ) {
T_19 * V_90 = F_57 ( F_5 () ) ;
while ( V_89 ) {
if( V_89 -> V_5 -> V_29 ) {
#ifdef F_2
if ( F_2 & V_91 ) F_3 ( L_30 , V_89 -> V_2 , V_89 -> V_3 , V_89 -> V_4 ) ;
#endif
V_89 -> V_5 -> V_29 ( V_1 -> V_9 , V_89 -> V_5 -> V_9 , V_89 ) ;
}
if( V_89 -> V_10 ) {
F_58 ( V_90 , V_89 ) ;
V_89 = V_89 -> V_10 ;
continue;
} else {
#ifdef F_2
if ( F_2 & V_91 ) F_3 ( L_31 , V_89 -> V_2 , V_89 -> V_3 , V_89 -> V_4 ) ;
#endif
if( V_89 -> V_5 -> V_30 ) V_89 -> V_5 -> V_30 ( V_1 -> V_9 , V_89 -> V_5 -> V_9 , V_89 ) ;
}
V_89 = V_89 -> V_11 ;
while( ! V_89 && F_59 ( V_90 ) > 0 ) {
V_89 = ( T_1 * ) F_60 ( V_90 ) ;
#ifdef F_2
if ( F_2 & V_91 ) F_3 ( L_31 , V_89 -> V_2 , V_89 -> V_3 , V_89 -> V_4 ) ;
#endif
if( V_89 -> V_5 -> V_30 ) V_89 -> V_5 -> V_30 ( V_1 -> V_9 , V_89 -> V_5 -> V_9 , V_89 ) ;
V_89 = V_89 -> V_11 ;
}
}
}
T_9 F_61 ( T_2 * V_1 ,
const T_3 * V_5 ) {
T_1 * V_6 = NULL ;
int V_13 ;
int V_3 = V_1 -> V_3 ;
#ifdef F_2
if ( F_2 & V_92 ) F_3 ( L_32 , V_3 ) ;
#endif
V_3 += F_6 ( V_1 , V_3 ) ;
#ifdef F_2
if ( F_2 & V_92 ) F_3 ( L_33 , V_3 ) ;
#endif
V_13 = V_5 -> V_17 ( V_1 , V_3 , V_5 , & V_6 ) ;
if ( V_13 >= 0 ) {
#ifdef F_2
if ( F_2 & V_92 ) F_3 ( L_34 , V_13 ) ;
#endif
return TRUE ;
} else {
#ifdef F_2
if ( F_2 & V_92 ) F_3 ( L_35 ) ;
#endif
return FALSE ;
}
}
T_1 * F_62 ( T_2 * V_1 ,
const T_3 * V_5 ) {
T_1 * V_6 = NULL ;
int V_13 ;
int V_3 = V_1 -> V_3 ;
#ifdef F_2
if ( F_2 & V_93 ) F_3 ( L_36 , V_3 ) ;
#endif
V_3 += F_6 ( V_1 , V_3 ) ;
#ifdef F_2
if ( F_2 & V_93 ) F_3 ( L_37 , V_3 ) ;
#endif
V_13 = V_5 -> V_17 ( V_1 , V_3 , V_5 , & V_6 ) ;
if ( V_13 >= 0 ) {
#ifdef F_2
if ( F_2 & V_93 ) F_3 ( L_38 , V_13 ) ;
#endif
F_56 ( V_1 , V_6 ) ;
V_1 -> V_3 = V_3 + V_13 ;
#ifdef F_2
if ( F_2 & V_93 ) F_3 ( L_39 , V_1 -> V_3 ) ;
#endif
return V_6 ;
} else {
return NULL ;
}
}
T_1 * F_63 ( T_2 * V_1 , const T_3 * V_5 ) {
T_1 * V_6 = NULL ;
int V_4 = 0 ;
int V_3 = V_1 -> V_3 ;
int V_75 = V_3 - 1 ;
#ifdef F_2
if ( F_2 & V_94 ) F_3 ( L_36 , V_1 -> V_3 ) ;
#endif
do {
V_4 = V_5 -> V_17 ( V_1 , V_75 + 1 , V_5 , & V_6 ) ;
} while( V_4 < 0 && ++ V_75 < V_1 -> V_24 );
if ( V_4 >= 0 ) {
#ifdef F_2
if ( F_2 & V_94 ) F_3 ( L_40 , V_75 , V_4 ) ;
#endif
F_56 ( V_1 , V_6 ) ;
V_1 -> V_3 = V_75 + V_4 ;
#ifdef F_2
if ( F_2 & V_94 ) F_3 ( L_39 , V_1 -> V_3 ) ;
#endif
return V_6 ;
} else {
#ifdef F_2
if ( F_2 & V_94 ) F_3 ( L_41 ) ;
#endif
return NULL ;
}
}
void F_64 ( T_20 * V_95 , T_1 * V_89 ) {
T_19 * V_90 = F_57 ( F_5 () ) ;
struct V_96 * V_97 = F_4 ( F_5 () , struct V_96 ) ;
T_21 * V_98 ;
V_97 -> V_95 = V_95 ;
V_97 -> V_99 = V_89 ;
while ( V_89 ) {
V_98 = F_65 ( V_97 -> V_95 , V_89 -> V_8 , V_89 -> V_3 , V_89 -> V_4 ) ;
if( V_89 -> V_10 ) {
V_97 -> V_99 = V_89 ;
F_58 ( V_90 , V_97 ) ;
V_97 = F_4 ( F_5 () , struct V_96 ) ;
V_97 -> V_95 = F_66 ( V_98 , 0 ) ;
V_89 = V_89 -> V_10 ;
continue;
}
V_89 = V_89 -> V_11 ;
while( ! V_89 && F_59 ( V_90 ) > 0 ) {
V_97 = (struct V_96 * ) F_60 ( V_90 ) ;
V_89 = V_97 -> V_99 -> V_11 ;
}
}
}
