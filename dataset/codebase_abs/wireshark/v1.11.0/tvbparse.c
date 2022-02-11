static T_1 * F_1 ( T_2 * V_1 ,
int V_2 ,
int V_3 ,
int V_4 ,
const T_3 * V_5 ) {
T_1 * V_6 ;
#ifdef F_2
if ( F_2 & V_7 ) F_3 ( L_1 , V_2 , V_3 , V_4 ) ;
#endif
V_6 = ( T_1 * ) F_4 ( sizeof( T_1 ) ) ;
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
static int F_5 ( T_2 * V_1 , int V_3 ) {
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
static int F_6 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_4 V_18 , V_19 ;
T_5 V_20 ;
#ifdef F_2
if ( F_2 & V_21 ) F_3 ( L_5 , V_5 -> V_22 . V_23 ) ;
#endif
if ( V_3 + 1 > V_1 -> V_24 )
return - 1 ;
V_19 = ( T_4 ) F_7 ( V_1 -> V_8 , V_3 ) ;
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
T_3 * F_8 ( const int V_2 ,
const T_4 * V_25 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ) {
T_3 * V_28 = ( T_3 * ) F_9 ( sizeof( T_3 ) ) ;
V_28 -> V_17 = F_6 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_22 . V_23 = V_25 ;
V_28 -> V_4 = 1 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
static int F_10 ( T_2 * V_1 , int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
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
T_4 V_19 = ( T_4 ) F_7 ( V_1 -> V_8 , V_3 ++ ) ;
T_4 V_18 ;
T_5 V_20 = 0 ;
while ( ( V_18 = V_5 -> V_22 . V_23 [ V_20 ++ ] ) ) {
if ( V_18 == V_19 ) goto V_37;
}
break;
V_37:
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
T_3 * F_11 ( const int V_2 ,
const T_5 V_38 ,
const T_5 V_39 ,
const T_4 * V_25 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ) {
T_3 * V_28 = ( T_3 * ) F_9 ( sizeof( T_3 ) ) ;
V_28 -> V_17 = F_10 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_22 . V_23 = V_25 ;
V_28 -> V_35 = V_38 ? V_38 : 1 ;
V_28 -> V_36 = V_39 ? V_39 : V_40 / 2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
static int F_12 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_4 V_18 , V_19 ;
T_5 V_20 ;
T_7 V_41 = FALSE ;
#ifdef F_2
if ( F_2 & V_42 ) F_3 ( L_9 , V_5 -> V_22 . V_23 ) ;
#endif
if ( ! V_3 < V_1 -> V_24 ) {
return - 1 ;
}
V_19 = ( T_4 ) F_7 ( V_1 -> V_8 , V_3 ) ;
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
T_3 * F_13 ( const int V_2 ,
const T_4 * V_25 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ) {
T_3 * V_28 = ( T_3 * ) F_9 ( sizeof( T_3 ) ) ;
V_28 -> V_17 = F_12 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_22 . V_23 = V_25 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
static int F_14 ( T_2 * V_1 , int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_5 V_31 = 0 ;
int V_33 = V_1 -> V_24 - V_3 ;
int V_32 = V_3 ;
#ifdef F_2
if ( F_2 & V_43 ) F_3 ( L_11 , V_5 -> V_22 . V_23 ) ;
#endif
if ( V_3 + ( int ) V_5 -> V_35 > V_1 -> V_24 )
return - 1 ;
if ( V_33 < ( int ) V_5 -> V_35 )
return - 1 ;
V_33 = V_33 <= ( int ) V_5 -> V_36 ? V_33 : ( int ) V_5 -> V_36 ;
while( V_33 > 0 ) {
T_4 V_18 ;
T_4 V_19 = ( T_4 ) F_7 ( V_1 -> V_8 , V_3 ) ;
T_5 V_20 = 0 ;
while ( ( V_18 = V_5 -> V_22 . V_23 [ V_20 ++ ] ) ) {
if ( V_18 == V_19 ) goto V_44;
}
V_3 ++ ;
V_31 ++ ;
V_33 -- ;
}
V_44:
if ( V_31 < V_5 -> V_35 ) {
return - 1 ;
} else {
* V_6 = F_1 ( V_1 , V_5 -> V_2 , V_32 , V_31 , V_5 ) ;
#ifdef F_2
if ( F_2 & V_43 ) F_3 ( L_12 , V_31 ) ;
#endif
return V_31 ;
}
}
T_3 * F_15 ( const int V_2 ,
const T_5 V_38 ,
const T_5 V_39 ,
const T_4 * V_25 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ) {
T_3 * V_28 = ( T_3 * ) F_9 ( sizeof( T_3 ) ) ;
V_28 -> V_17 = F_14 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_22 . V_23 = V_25 ;
V_28 -> V_4 = 0 ;
V_28 -> V_35 = V_38 ? V_38 : 1 ;
V_28 -> V_36 = V_39 ? V_39 : V_40 / 2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
static int F_16 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
int V_4 = V_5 -> V_4 ;
#ifdef F_2
if ( F_2 & V_45 ) F_3 ( L_13 , V_5 -> V_22 . V_23 ) ;
#endif
if ( V_3 + V_5 -> V_4 > V_1 -> V_24 )
return - 1 ;
if ( F_17 ( V_1 -> V_8 , V_3 , V_5 -> V_22 . V_23 , V_4 ) == 0 ) {
* V_6 = F_1 ( V_1 , V_5 -> V_2 , V_3 , V_4 , V_5 ) ;
#ifdef F_2
if ( F_2 & V_45 ) F_3 ( L_14 , V_4 ) ;
#endif
return V_4 ;
} else {
return - 1 ;
}
}
T_3 * F_18 ( const int V_2 ,
const T_4 * V_23 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ) {
T_3 * V_28 = ( T_3 * ) F_9 ( sizeof( T_3 ) ) ;
V_28 -> V_17 = F_16 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_22 . V_23 = V_23 ;
V_28 -> V_4 = ( int ) strlen ( V_23 ) ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
static int F_19 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
int V_4 = V_5 -> V_4 ;
#ifdef F_2
if ( F_2 & V_46 ) F_3 ( L_15 , V_5 -> V_22 . V_23 ) ;
#endif
if ( V_3 + V_4 > V_1 -> V_24 )
return - 1 ;
if ( F_20 ( V_1 -> V_8 , V_3 , V_5 -> V_22 . V_23 , V_4 ) == 0 ) {
* V_6 = F_1 ( V_1 , V_5 -> V_2 , V_3 , V_4 , V_5 ) ;
#ifdef F_2
if ( F_2 & V_46 ) F_3 ( L_16 , V_4 ) ;
#endif
return V_4 ;
} else {
* V_6 = NULL ;
return - 1 ;
}
}
T_3 * F_21 ( const int V_2 ,
const T_4 * V_23 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ) {
T_3 * V_28 = ( T_3 * ) F_9 ( sizeof( T_3 ) ) ;
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
T_5 V_20 ;
#ifdef F_2
if ( F_2 & V_47 ) F_3 ( L_17 ) ;
#endif
if ( V_3 > V_1 -> V_24 )
return - 1 ;
for( V_20 = 0 ; V_20 < V_5 -> V_22 . V_48 -> V_4 ; V_20 ++ ) {
T_3 * V_28 = ( T_3 * ) F_23 ( V_5 -> V_22 . V_48 , V_20 ) ;
T_1 * V_49 = NULL ;
int V_50 ;
if ( V_3 + V_28 -> V_4 > V_1 -> V_24 )
continue;
V_50 = V_28 -> V_17 ( V_1 , V_3 , V_28 , & V_49 ) ;
if ( V_50 >= 0 ) {
* V_6 = F_1 ( V_1 , V_5 -> V_2 , V_49 -> V_3 , V_49 -> V_4 , V_5 ) ;
( * V_6 ) -> V_10 = V_49 ;
#ifdef F_2
if ( F_2 & V_47 ) F_3 ( L_18 , V_50 ) ;
#endif
return V_50 ;
}
}
return - 1 ;
}
T_3 * F_24 ( const int V_2 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
... ) {
T_3 * V_28 = ( T_3 * ) F_9 ( sizeof( T_3 ) ) ;
T_2 * V_51 ;
T_8 V_52 ;
V_28 -> V_17 = F_22 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
V_28 -> V_22 . V_48 = F_25 () ;
va_start ( V_52 , V_27 ) ;
while( ( V_51 = va_arg ( V_52 , T_2 * ) ) ) {
F_26 ( V_28 -> V_22 . V_48 , V_51 ) ;
} ;
va_end ( V_52 ) ;
return V_28 ;
}
static int F_27 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
int V_53 ;
T_4 * V_54 = NULL ;
T_1 * V_55 = NULL ;
T_3 * V_56 = NULL ;
int V_57 ;
T_1 * V_58 = NULL ;
int V_59 ;
T_1 * V_60 ;
#ifdef F_2
if ( F_2 & V_61 ) F_3 ( L_19 ) ;
#endif
if ( V_3 > V_1 -> V_24 )
return - 1 ;
V_53 = V_5 -> V_22 . V_62 . V_54 -> V_17 ( V_1 , V_3 , V_5 -> V_22 . V_62 . V_54 , & V_55 ) ;
if ( V_53 < 0 )
return - 1 ;
V_54 = F_28 ( F_29 () , V_55 -> V_8 , V_55 -> V_3 , V_55 -> V_4 ) ;
#ifdef F_2
if ( F_2 & V_61 ) F_3 ( L_20 , V_54 ) ;
#endif
if ( ( V_56 = ( T_3 * ) F_30 ( V_5 -> V_22 . V_62 . V_63 , V_54 ) ) ) {
V_57 = V_56 -> V_17 ( V_1 , V_3 + V_53 , V_56 , & V_58 ) ;
} else if ( V_5 -> V_22 . V_62 . V_64 ) {
V_57 = V_5 -> V_22 . V_62 . V_64 -> V_17 ( V_1 , V_3 + V_53 , V_5 -> V_22 . V_62 . V_64 , & V_58 ) ;
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
if ( F_2 & V_61 ) F_3 ( L_21 , V_59 ) ;
#endif
return V_59 ;
}
T_3 * F_31 ( const int V_2 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
T_3 * V_54 ,
T_3 * V_64 ,
... ) {
T_3 * V_28 = ( T_3 * ) F_9 ( sizeof( T_3 ) ) ;
T_4 * V_65 ;
T_3 * V_51 ;
T_8 V_52 ;
V_28 -> V_17 = F_27 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
V_28 -> V_22 . V_62 . V_63 = F_32 ( V_66 , V_67 ) ;
V_28 -> V_22 . V_62 . V_54 = V_54 ;
V_28 -> V_22 . V_62 . V_64 = V_64 ;
va_start ( V_52 , V_64 ) ;
while( ( V_65 = va_arg ( V_52 , T_4 * ) ) ) {
V_51 = va_arg ( V_52 , T_3 * ) ;
F_33 ( V_28 -> V_22 . V_62 . V_63 , V_65 , V_51 ) ;
}
va_end ( V_52 ) ;
return V_28 ;
}
void F_34 ( T_3 * V_28 , ... ) {
T_3 * V_51 ;
T_8 V_52 ;
T_4 * V_65 ;
va_start ( V_52 , V_28 ) ;
while ( ( V_65 = va_arg ( V_52 , T_4 * ) ) ) {
V_51 = va_arg ( V_52 , T_3 * ) ;
F_33 ( V_28 -> V_22 . V_62 . V_63 , V_65 , V_51 ) ;
}
va_end ( V_52 ) ;
}
static int F_35 ( T_2 * V_1 , int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_5 V_20 ;
int V_4 = 0 ;
int V_32 = V_3 ;
T_1 * V_60 = NULL ;
if ( V_3 > V_1 -> V_24 )
return - 1 ;
#ifdef F_2
if ( F_2 & V_68 ) F_3 ( L_22 ) ;
#endif
for( V_20 = 0 ; V_20 < V_5 -> V_22 . V_48 -> V_4 ; V_20 ++ ) {
T_3 * V_28 = ( T_3 * ) F_23 ( V_5 -> V_22 . V_48 , V_20 ) ;
T_1 * V_49 = NULL ;
if ( V_3 + V_28 -> V_4 > V_1 -> V_24 )
return - 1 ;
V_4 = V_28 -> V_17 ( V_1 , V_3 , V_28 , & V_49 ) ;
if ( V_4 >= 0 ) {
if ( V_60 ) {
V_60 -> V_4 = ( V_49 -> V_3 - V_60 -> V_3 ) + V_49 -> V_4 ;
V_60 -> V_10 -> V_12 -> V_11 = V_49 ;
V_60 -> V_10 -> V_12 = V_49 ;
} else {
V_60 = F_1 ( V_1 , V_5 -> V_2 , V_49 -> V_3 , V_49 -> V_4 , V_5 ) ;
V_60 -> V_10 = V_49 ;
V_49 -> V_12 = V_49 ;
}
} else {
return - 1 ;
}
V_3 += V_4 ;
V_3 += F_5 ( V_1 , V_3 ) ;
}
* V_6 = V_60 ;
#ifdef F_2
if ( F_2 & V_68 ) F_3 ( L_23 , V_3 - V_32 ) ;
#endif
return V_3 - V_32 ;
}
T_3 * F_36 ( const int V_2 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
... ) {
T_3 * V_28 = ( T_3 * ) F_9 ( sizeof( T_3 ) ) ;
T_3 * V_51 = NULL ;
T_8 V_52 ;
V_28 -> V_17 = F_35 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
V_28 -> V_22 . V_48 = F_25 () ;
va_start ( V_52 , V_27 ) ;
while( ( V_51 = va_arg ( V_52 , T_3 * ) ) ) {
F_26 ( V_28 -> V_22 . V_48 , V_51 ) ;
} ;
va_end ( V_52 ) ;
return V_28 ;
}
static int F_37 ( T_2 * V_1 , int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_5 V_69 = 0 ;
int V_32 = V_3 ;
T_1 * V_60 = NULL ;
#ifdef F_2
if ( F_2 & V_70 ) F_3 ( L_24 ) ;
#endif
if ( V_3 > V_1 -> V_24 )
return - 1 ;
if ( V_5 -> V_35 == 0 ) {
V_60 = F_1 ( V_1 , V_5 -> V_2 , V_3 , 0 , V_5 ) ;
}
while ( V_69 < V_5 -> V_36 ) {
T_1 * V_49 = NULL ;
int V_13 ;
if ( V_3 > V_1 -> V_24 )
return - 1 ;
V_13 = V_5 -> V_22 . V_71 -> V_17 ( V_1 , V_3 , V_5 -> V_22 . V_71 , & V_49 ) ;
if( V_13 >= 0 ) {
if ( V_60 ) {
V_60 -> V_4 = ( V_49 -> V_3 - V_60 -> V_3 ) + V_49 -> V_4 ;
if ( V_60 -> V_10 ) {
V_60 -> V_10 -> V_12 -> V_11 = V_49 ;
V_60 -> V_10 -> V_12 = V_49 ;
} else {
V_60 -> V_10 = V_49 ;
}
} else {
V_60 = F_1 ( V_1 , V_5 -> V_2 , V_49 -> V_3 , V_49 -> V_4 , V_5 ) ;
V_60 -> V_10 = V_49 ;
}
} else {
break;
}
V_3 += V_13 ;
V_69 ++ ;
}
#ifdef F_2
if ( F_2 & V_70 ) F_3 ( L_25 , V_69 ) ;
#endif
if( V_69 < V_5 -> V_35 ) {
return - 1 ;
}
* V_6 = V_60 ;
#ifdef F_2
if ( F_2 & V_70 ) F_3 ( L_26 , V_3 - V_32 ) ;
#endif
return V_3 - V_32 ;
}
T_3 * F_38 ( const int V_2 ,
const T_5 V_72 ,
const T_5 V_73 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
const T_3 * V_51 ) {
T_3 * V_28 = ( T_3 * ) F_9 ( sizeof( T_3 ) ) ;
F_39 ( V_72 <= V_73 ) ;
V_28 -> V_17 = F_37 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_35 = V_72 ;
V_28 -> V_36 = V_73 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
V_28 -> V_22 . V_71 = V_51 ;
return V_28 ;
}
static int F_40 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_1 * V_49 = NULL ;
int V_4 = 0 ;
int V_74 = V_3 ;
#ifdef F_2
if ( F_2 & V_75 ) F_3 ( L_27 ) ;
#endif
if ( V_3 + V_5 -> V_22 . V_76 . V_71 -> V_4 > V_1 -> V_24 )
return - 1 ;
do {
V_4 = V_5 -> V_22 . V_76 . V_71 -> V_17 ( V_1 , V_74 ++ , V_5 -> V_22 . V_76 . V_71 , & V_49 ) ;
} while( V_4 < 0 && V_74 + 1 < V_1 -> V_24 );
if ( V_4 >= 0 ) {
V_49 -> V_2 = V_5 -> V_2 ;
V_49 -> V_11 = NULL ;
V_49 -> V_12 = NULL ;
V_49 -> V_5 = V_5 ;
V_49 -> V_3 = V_3 ;
( * V_6 ) = V_49 ;
switch ( V_5 -> V_22 . V_76 . V_77 ) {
case V_78 :
V_49 -> V_4 = V_74 - V_3 - 1 + V_4 ;
#ifdef F_2
if ( F_2 & V_75 ) F_3 ( L_28 , V_74 - V_3 - 1 + V_4 ) ;
#endif
return V_74 - V_3 - 1 + V_4 ;
case V_79 :
V_49 -> V_4 = V_74 - V_3 - 1 ;
#ifdef F_2
if ( F_2 & V_75 ) F_3 ( L_28 , V_74 - V_3 - 1 + V_4 ) ;
#endif
return V_74 - V_3 - 1 + V_4 ;
case V_80 :
V_49 -> V_4 = V_74 - V_3 - 1 ;
#ifdef F_2
if ( F_2 & V_75 ) F_3 ( L_28 , V_74 - V_3 - 1 ) ;
#endif
return V_74 - V_3 - 1 ;
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
const T_3 * V_51 ,
T_9 V_81 ) {
T_3 * V_28 = ( T_3 * ) F_9 ( sizeof( T_3 ) ) ;
V_28 -> V_17 = F_40 ;
V_28 -> V_22 . V_76 . V_77 = V_81 ;
V_28 -> V_22 . V_76 . V_71 = V_51 ;
V_28 -> V_2 = V_2 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_30 = V_27 ;
return V_28 ;
}
static int F_43 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 , T_1 * * V_6 ) {
T_3 * V_28 = * ( V_5 -> V_22 . V_82 ) ;
int V_4 = V_28 -> V_17 ( V_1 , V_3 , V_28 , V_6 ) ;
if ( V_4 >= 0 ) {
return V_4 ;
} else {
return - 1 ;
}
}
T_3 * F_44 ( T_3 * * V_82 ) {
T_3 * V_28 = ( T_3 * ) F_9 ( sizeof( T_3 ) ) ;
V_28 -> V_17 = F_43 ;
V_28 -> V_22 . V_82 = V_82 ;
return V_28 ;
}
static int F_45 ( T_2 * V_1 , const int V_3 , const T_3 * V_5 V_83 , T_1 * * V_6 ) {
if ( V_3 == V_1 -> V_24 ) {
* V_6 = F_1 ( V_1 , V_5 -> V_2 , V_3 , 0 , V_5 ) ;
return 0 ;
} else {
return - 1 ;
}
}
T_3 * F_46 ( const int V_2 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ) {
T_3 * V_28 = ( T_3 * ) F_9 ( sizeof( T_3 ) ) ;
V_28 -> V_2 = V_2 ;
V_28 -> V_17 = F_45 ;
V_28 -> V_30 = V_27 ;
V_28 -> V_29 = V_26 ;
V_28 -> V_9 = V_9 ;
return V_28 ;
}
T_3 * F_47 ( const int V_2 ,
const void * V_9 ,
T_6 V_26 ,
T_6 V_27 ,
const char V_84 ,
const char V_85 ) {
T_4 * V_86 = F_48 ( L_29 , V_85 , V_84 ) ;
T_4 * V_87 = F_48 ( L_30 , V_84 ) ;
T_3 * V_88 = F_8 ( - 1 , V_87 , NULL , NULL , NULL ) ;
return F_24 ( V_2 , V_9 , V_26 , V_27 ,
F_36 ( - 1 , NULL , NULL , NULL ,
V_88 ,
F_36 ( - 1 , NULL , NULL , NULL ,
F_24 ( - 1 , NULL , NULL , NULL ,
F_18 ( - 1 , V_86 , NULL , NULL , NULL ) ,
F_15 ( - 1 , 0 , 0 , V_87 , NULL , NULL , NULL ) ,
NULL ) ,
NULL ) ,
V_88 ,
NULL ) ,
F_36 ( - 1 , NULL , NULL , NULL ,
V_88 ,
V_88 ,
NULL ) ,
NULL ) ;
}
void F_49 ( void * T_10 V_83 ,
const void * T_11 V_83 ,
T_1 * V_6 ) {
V_6 -> V_3 += 1 ;
V_6 -> V_4 -= 2 ;
}
T_2 * F_50 ( T_12 * V_8 ,
const int V_3 ,
int V_4 ,
void * V_9 ,
const T_3 * V_15 ) {
T_2 * V_1 = ( T_2 * ) F_4 ( sizeof( T_2 ) ) ;
#ifdef F_2
if ( F_2 & V_89 ) F_3 ( L_31 , V_3 , V_4 ) ;
#endif
V_1 -> V_8 = V_8 ;
V_1 -> V_3 = V_3 ;
V_4 = ( V_4 == - 1 ) ? ( int ) F_51 ( V_8 ) : V_4 ;
V_1 -> V_24 = V_3 + V_4 ;
V_1 -> V_9 = V_9 ;
V_1 -> V_15 = V_15 ;
return V_1 ;
}
T_7 F_52 ( T_2 * V_1 ,
const int V_3 ,
int V_4 ) {
#ifdef F_2
if ( F_2 & V_89 ) F_3 ( L_31 , V_3 , V_4 ) ;
#endif
V_4 = ( V_4 == - 1 ) ? ( int ) F_51 ( V_1 -> V_8 ) : V_4 ;
if( F_53 ( V_1 -> V_8 , V_3 ) >= V_4 ) {
V_1 -> V_3 = V_3 ;
V_1 -> V_24 = V_3 + V_4 ;
return TRUE ;
} else {
return FALSE ;
}
}
T_5 F_54 ( T_2 * V_1 ) {
return V_1 -> V_3 ;
}
static void F_55 ( T_2 * V_1 , T_1 * V_90 ) {
T_13 V_91 = F_56 () ;
while ( V_90 ) {
if( V_90 -> V_5 -> V_29 ) {
#ifdef F_2
if ( F_2 & V_92 ) F_3 ( L_32 , V_90 -> V_2 , V_90 -> V_3 , V_90 -> V_4 ) ;
#endif
V_90 -> V_5 -> V_29 ( V_1 -> V_9 , V_90 -> V_5 -> V_9 , V_90 ) ;
}
if( V_90 -> V_10 ) {
F_57 ( V_91 , V_90 ) ;
V_90 = V_90 -> V_10 ;
continue;
} else {
#ifdef F_2
if ( F_2 & V_92 ) F_3 ( L_33 , V_90 -> V_2 , V_90 -> V_3 , V_90 -> V_4 ) ;
#endif
if( V_90 -> V_5 -> V_30 ) V_90 -> V_5 -> V_30 ( V_1 -> V_9 , V_90 -> V_5 -> V_9 , V_90 ) ;
}
V_90 = V_90 -> V_11 ;
while( ! V_90 && F_58 ( V_91 ) ) {
V_90 = ( T_1 * ) F_59 ( V_91 ) ;
#ifdef F_2
if ( F_2 & V_92 ) F_3 ( L_33 , V_90 -> V_2 , V_90 -> V_3 , V_90 -> V_4 ) ;
#endif
if( V_90 -> V_5 -> V_30 ) V_90 -> V_5 -> V_30 ( V_1 -> V_9 , V_90 -> V_5 -> V_9 , V_90 ) ;
V_90 = V_90 -> V_11 ;
}
}
}
T_7 F_60 ( T_2 * V_1 ,
const T_3 * V_5 ) {
T_1 * V_6 = NULL ;
int V_13 ;
int V_3 = V_1 -> V_3 ;
#ifdef F_2
if ( F_2 & V_93 ) F_3 ( L_34 , V_3 ) ;
#endif
V_3 += F_5 ( V_1 , V_3 ) ;
#ifdef F_2
if ( F_2 & V_93 ) F_3 ( L_35 , V_3 ) ;
#endif
V_13 = V_5 -> V_17 ( V_1 , V_3 , V_5 , & V_6 ) ;
if ( V_13 >= 0 ) {
#ifdef F_2
if ( F_2 & V_93 ) F_3 ( L_36 , V_13 ) ;
#endif
return TRUE ;
} else {
#ifdef F_2
if ( F_2 & V_93 ) F_3 ( L_37 ) ;
#endif
return FALSE ;
}
}
T_1 * F_61 ( T_2 * V_1 ,
const T_3 * V_5 ) {
T_1 * V_6 = NULL ;
int V_13 ;
int V_3 = V_1 -> V_3 ;
#ifdef F_2
if ( F_2 & V_94 ) F_3 ( L_38 , V_3 ) ;
#endif
V_3 += F_5 ( V_1 , V_3 ) ;
#ifdef F_2
if ( F_2 & V_94 ) F_3 ( L_39 , V_3 ) ;
#endif
V_13 = V_5 -> V_17 ( V_1 , V_3 , V_5 , & V_6 ) ;
if ( V_13 >= 0 ) {
#ifdef F_2
if ( F_2 & V_94 ) F_3 ( L_40 , V_13 ) ;
#endif
F_55 ( V_1 , V_6 ) ;
V_1 -> V_3 = V_3 + V_13 ;
#ifdef F_2
if ( F_2 & V_94 ) F_3 ( L_41 , V_1 -> V_3 ) ;
#endif
return V_6 ;
} else {
return NULL ;
}
}
T_1 * F_62 ( T_2 * V_1 , const T_3 * V_5 ) {
T_1 * V_6 = NULL ;
int V_4 = 0 ;
int V_3 = V_1 -> V_3 ;
int V_74 = V_3 - 1 ;
#ifdef F_2
if ( F_2 & V_95 ) F_3 ( L_38 , V_1 -> V_3 ) ;
#endif
do {
V_4 = V_5 -> V_17 ( V_1 , V_74 + 1 , V_5 , & V_6 ) ;
} while( V_4 < 0 && ++ V_74 < V_1 -> V_24 );
if ( V_4 >= 0 ) {
#ifdef F_2
if ( F_2 & V_95 ) F_3 ( L_42 , V_74 , V_4 ) ;
#endif
F_55 ( V_1 , V_6 ) ;
V_1 -> V_3 = V_74 + V_4 ;
#ifdef F_2
if ( F_2 & V_95 ) F_3 ( L_41 , V_1 -> V_3 ) ;
#endif
return V_6 ;
} else {
#ifdef F_2
if ( F_2 & V_95 ) F_3 ( L_43 ) ;
#endif
return NULL ;
}
}
void F_63 ( T_14 * V_96 , T_1 * V_90 ) {
T_13 V_91 = F_56 () ;
struct V_97 * V_98 = (struct V_97 * ) F_4 ( sizeof( struct V_97 ) ) ;
T_15 * V_99 ;
V_98 -> V_96 = V_96 ;
V_98 -> V_100 = V_90 ;
while ( V_90 ) {
V_99 = F_64 ( V_98 -> V_96 , V_90 -> V_8 , V_90 -> V_3 , V_90 -> V_4 , L_44 , F_65 ( V_90 -> V_8 , V_90 -> V_3 , V_90 -> V_4 ) ) ;
if( V_90 -> V_10 ) {
V_98 -> V_100 = V_90 ;
F_57 ( V_91 , V_98 ) ;
V_98 = (struct V_97 * ) F_4 ( sizeof( struct V_97 ) ) ;
V_98 -> V_96 = F_66 ( V_99 , 0 ) ;
V_90 = V_90 -> V_10 ;
continue;
}
V_90 = V_90 -> V_11 ;
while( ! V_90 && F_58 ( V_91 ) ) {
V_98 = (struct V_97 * ) F_59 ( V_91 ) ;
V_90 = V_98 -> V_100 -> V_11 ;
}
}
}
