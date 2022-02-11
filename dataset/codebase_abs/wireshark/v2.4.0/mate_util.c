void F_1 ( const T_1 * V_1 , T_1 V_2 , T_2 * V_3 , const T_3 * V_4 , ... ) {
static T_3 V_5 [ V_6 ] ;
T_4 V_7 ;
if ( ! V_1 || * V_1 < V_2 ) return;
va_start ( V_7 , V_4 ) ;
F_2 ( V_5 , V_6 , V_4 , V_7 ) ;
va_end ( V_7 ) ;
if ( ! V_3 ) {
F_3 ( L_1 , V_5 ) ;
} else {
fputs ( V_5 , V_3 ) ;
fputs ( L_2 , V_3 ) ;
}
}
static void F_4 ( T_5 * V_8 ) {
if ( V_8 -> V_9 ) F_5 ( V_8 -> V_9 ) ;
}
static T_5 * F_6 ( void ) {
T_5 * V_8 = ( T_5 * ) F_7 ( sizeof( T_5 ) ) ;
V_8 -> V_9 = F_8 ( V_10 , V_11 ) ;
return V_8 ;
}
T_3 * F_9 ( T_5 * V_8 , const T_3 * V_12 ) {
T_3 * V_13 = NULL ;
T_6 * V_14 = NULL ;
T_7 V_15 = 0 ;
F_10 ( V_8 -> V_9 , ( V_16 ) V_12 , ( V_17 * ) & V_13 , ( V_17 * ) & V_14 ) ;
if ( V_14 ) {
( * V_14 ) ++ ;
} else {
V_14 = F_11 ( T_6 ) ;
* V_14 = 0 ;
V_15 = strlen ( V_12 ) + 1 ;
if ( V_15 <= V_18 ) {
V_15 = V_18 ;
} else if ( V_15 <= V_19 ) {
V_15 = V_19 ;
} else if ( V_15 <= V_20 ) {
V_15 = V_20 ;
} else if ( V_15 < V_21 ) {
V_15 = V_21 ;
} else {
V_15 = V_21 ;
F_12 ( L_3 ) ;
}
V_13 = ( T_3 * ) F_13 ( V_15 ) ;
F_14 ( V_13 , V_12 , V_15 ) ;
F_15 ( V_8 -> V_9 , V_13 , V_14 ) ;
}
return V_13 ;
}
void F_16 ( T_5 * V_8 , T_3 * V_12 ) {
T_3 * V_13 = NULL ;
T_6 * V_14 = NULL ;
T_7 V_15 = 0xffff ;
F_10 ( V_8 -> V_9 , ( V_16 ) V_12 , ( V_17 * ) & V_13 , ( V_17 * ) & V_14 ) ;
if ( V_14 ) {
if ( * V_14 == 0 ) {
F_17 ( V_8 -> V_9 , V_13 ) ;
V_15 = strlen ( V_13 ) ;
if ( V_15 < V_18 ) {
V_15 = V_18 ;
} else if ( V_15 < V_19 ) {
V_15 = V_19 ;
} else if ( V_15 < V_20 ) {
V_15 = V_20 ;
} else {
V_15 = V_21 ;
}
F_18 ( V_15 , V_13 ) ;
F_19 ( T_6 , V_14 ) ;
}
else {
( * V_14 ) -- ;
}
} else {
F_12 ( L_4 ) ;
}
}
T_3 * F_20 ( T_5 * V_8 , T_3 * V_4 , ... ) {
T_4 V_7 ;
static T_3 V_22 [ V_21 ] ;
va_start ( V_7 , V_4 ) ;
F_2 ( V_22 , V_21 , V_4 , V_7 ) ;
va_end ( V_7 ) ;
return F_9 ( V_8 , V_22 ) ;
}
extern void F_21 ( T_2 * V_23 , int * V_24 , int * V_25 , int * V_26 , int * V_27 , int * V_28 ) {
V_29 = V_23 ;
V_30 = V_24 ;
V_31 = V_25 ;
V_32 = V_26 ;
V_33 = V_27 ;
V_34 = V_28 ;
}
extern void F_22 ( void ) {
if ( V_35 ) F_4 ( V_35 ) ;
V_35 = F_6 () ;
}
extern T_8 * F_23 ( const T_3 * V_36 , T_9 * V_37 ) {
T_8 * V_38 = ( T_8 * ) F_11 ( V_39 ) ;
T_3 * V_40 ;
T_3 * V_41 ;
V_38 -> V_42 = F_9 ( V_35 , V_36 ) ;
V_41 = F_24 ( NULL , & V_37 -> V_40 , V_43 , V_37 -> V_44 -> V_45 ) ;
if ( V_41 ) {
V_40 = F_9 ( V_35 , V_41 ) ;
F_25 ( NULL , V_41 ) ;
#ifdef F_26
F_1 ( V_31 , 2 , V_29 , L_5 , V_40 ) ;
#endif
} else {
#ifdef F_26
F_1 ( V_31 , 2 , V_29 , L_6 , V_37 -> V_44 -> V_46 ) ;
#endif
V_40 = F_9 ( V_35 , L_7 ) ;
}
V_38 -> V_47 = V_40 ;
V_38 -> V_48 = '=' ;
#ifdef F_26
F_1 ( V_31 , 1 , V_29 , L_8 , ( V_49 ) V_38 , V_38 -> V_42 , V_38 -> V_48 , V_38 -> V_47 ) ;
#endif
return V_38 ;
}
extern T_8 * F_27 ( const T_3 * V_36 , const T_3 * V_40 , T_3 V_48 ) {
T_8 * V_38 = ( T_8 * ) F_11 ( V_39 ) ;
V_38 -> V_42 = F_9 ( V_35 , V_36 ) ;
V_38 -> V_47 = F_9 ( V_35 , V_40 ) ;
V_38 -> V_48 = V_48 ;
#ifdef F_26
F_1 ( V_31 , 1 , V_29 , L_9 , ( V_49 ) V_38 , V_38 -> V_42 , V_38 -> V_48 , V_38 -> V_47 ) ;
#endif
return V_38 ;
}
extern void F_28 ( T_8 * V_25 ) {
#ifdef F_26
F_1 ( V_31 , 1 , V_29 , L_10 , ( V_49 ) V_25 , V_25 -> V_42 , V_25 -> V_48 , V_25 -> V_47 ) ;
#endif
F_16 ( V_35 , V_25 -> V_42 ) ;
F_16 ( V_35 , V_25 -> V_47 ) ;
F_19 ( V_39 , ( V_39 * ) V_25 ) ;
}
extern T_8 * F_29 ( T_8 * V_50 ) {
T_8 * V_38 = ( T_8 * ) F_11 ( V_39 ) ;
V_38 -> V_42 = F_9 ( V_35 , V_50 -> V_42 ) ;
V_38 -> V_47 = F_9 ( V_35 , V_50 -> V_47 ) ;
V_38 -> V_48 = V_50 -> V_48 ;
#ifdef F_26
F_1 ( V_31 , 1 , V_29 , L_11 , ( V_49 ) V_38 , V_38 -> V_42 , V_38 -> V_48 , V_38 -> V_47 ) ;
#endif
return V_38 ;
}
extern T_10 * F_30 ( const T_3 * V_36 ) {
T_10 * V_51 = ( T_10 * ) F_11 ( V_39 ) ;
#ifdef F_26
F_1 ( V_34 , 7 , V_29 , L_12 , V_51 , V_36 ) ;
#endif
V_51 -> V_36 = V_36 ? F_9 ( V_35 , V_36 ) : F_9 ( V_35 , L_7 ) ;
V_51 -> V_15 = 0 ;
V_51 -> null . V_25 = NULL ;
V_51 -> null . V_52 = & V_51 -> null ;
V_51 -> null . V_53 = & V_51 -> null ;
return V_51 ;
}
extern void F_31 ( T_10 * V_27 , T_3 * V_36 ) {
F_16 ( V_35 , V_27 -> V_36 ) ;
V_27 -> V_36 = F_9 ( V_35 , V_36 ) ;
}
static void F_32 ( T_10 * V_27 , T_11 * V_54 , T_8 * V_25 , T_12 V_55 ) {
T_11 * V_38 = ( T_11 * ) F_11 ( V_39 ) ;
V_38 -> V_25 = V_55 ? F_29 ( V_25 ) : V_25 ;
#ifdef F_26
F_1 ( V_34 , 7 , V_29 , L_13 , V_38 ) ;
F_1 ( V_33 , 5 , V_29 , L_14 , V_25 , V_27 , V_54 ) ;
#endif
V_38 -> V_52 = V_54 ;
V_38 -> V_53 = V_54 -> V_53 ;
V_54 -> V_53 -> V_52 = V_38 ;
V_54 -> V_53 = V_38 ;
V_27 -> V_15 ++ ;
#ifdef F_26
F_1 ( V_33 , 4 , V_29 , L_15 , V_27 , V_27 -> V_15 ) ;
#endif
}
extern T_12 F_33 ( T_10 * V_27 , T_8 * V_25 ) {
T_11 * V_8 ;
#ifdef F_26
F_1 ( V_34 , 4 , V_29 , L_16 , V_27 , V_25 , V_25 -> V_42 , V_25 -> V_48 , V_25 -> V_47 ) ;
#endif
for ( V_8 = V_27 -> null . V_52 ; V_8 -> V_25 ; V_8 = V_8 -> V_52 ) {
int V_56 = strcmp ( V_25 -> V_42 , V_8 -> V_25 -> V_42 ) ;
if ( V_56 == 0 ) {
int V_57 = strcmp ( V_25 -> V_47 , V_8 -> V_25 -> V_47 ) ;
if ( V_57 < 0 ) {
break;
}
if ( V_57 == 0 ) {
if ( V_8 -> V_25 -> V_48 == V_25 -> V_48 && V_25 -> V_48 == V_58 ) {
return FALSE ;
}
}
}
if ( V_56 < 0 ) {
break;
}
}
F_32 ( V_27 , V_8 , V_25 , FALSE ) ;
return TRUE ;
}
extern T_8 * F_34 ( T_10 * V_27 , T_3 * V_36 , void * * V_59 ) {
T_11 * V_60 ;
T_11 * V_61 = ( T_11 * ) * V_59 ;
#ifdef F_26
F_1 ( V_34 , 7 , V_29 , L_17 , V_27 , V_36 , * V_59 ) ;
#endif
V_36 = F_9 ( V_35 , V_36 ) ;
if ( ! V_61 ) V_61 = V_27 -> null . V_52 ;
for ( V_60 = V_61 ; V_60 -> V_25 ; V_60 = V_60 -> V_52 ) {
if ( V_60 -> V_25 -> V_42 == V_36 ) {
break;
}
}
* V_59 = V_60 ;
#ifdef F_26
F_1 ( V_34 , 5 , V_29 , L_18 , V_60 ) ;
#endif
F_16 ( V_35 , V_36 ) ;
return V_60 -> V_25 ;
}
extern T_8 * F_35 ( T_10 * V_27 , T_3 * V_36 ) {
T_11 * V_60 ;
T_8 * V_25 = NULL ;
#ifdef F_26
F_1 ( V_34 , 7 , V_29 , L_19 , V_27 , V_36 ) ;
#endif
V_36 = F_9 ( V_35 , V_36 ) ;
for ( V_60 = V_27 -> null . V_52 ; V_60 -> V_25 ; V_60 = V_60 -> V_52 ) {
if ( V_60 -> V_25 -> V_42 == V_36 ) {
break;
}
}
F_16 ( V_35 , V_36 ) ;
if( ! V_60 -> V_25 ) return NULL ;
V_60 -> V_52 -> V_53 = V_60 -> V_53 ;
V_60 -> V_53 -> V_52 = V_60 -> V_52 ;
V_25 = V_60 -> V_25 ;
F_19 ( V_39 , ( V_39 * ) V_60 ) ;
( V_27 -> V_15 ) -- ;
#ifdef F_26
F_1 ( V_33 , 4 , V_29 , L_20 , V_27 , V_27 -> V_15 ) ;
#endif
#ifdef F_26
F_1 ( V_34 , 5 , V_29 , L_21 , V_25 ) ;
#endif
return V_25 ;
}
extern T_8 * F_36 ( T_10 * V_27 ) {
T_8 * V_25 ;
T_11 * V_62 ;
#ifdef F_26
F_1 ( V_34 , 7 , V_29 , L_22 , V_27 ) ;
#endif
V_62 = V_27 -> null . V_52 ;
V_27 -> null . V_52 -> V_53 = & V_27 -> null ;
V_27 -> null . V_52 = V_62 -> V_52 ;
V_25 = V_62 -> V_25 ;
if ( V_25 ) {
F_19 ( V_39 , ( V_39 * ) V_62 ) ;
( V_27 -> V_15 ) -- ;
#ifdef F_26
F_1 ( V_33 , 4 , V_29 , L_20 , V_27 , V_27 -> V_15 ) ;
#endif
}
#ifdef F_26
F_1 ( V_34 , 5 , V_29 , L_23 , V_25 ) ;
#endif
return V_25 ;
}
extern T_8 * F_37 ( T_10 * V_27 ) {
T_8 * V_25 ;
T_11 * V_62 ;
V_62 = V_27 -> null . V_53 ;
V_27 -> null . V_53 -> V_52 = & V_27 -> null ;
V_27 -> null . V_53 = V_62 -> V_53 ;
V_25 = V_62 -> V_25 ;
if ( V_25 ) {
F_19 ( V_39 , ( V_39 * ) V_62 ) ;
( V_27 -> V_15 ) -- ;
#ifdef F_26
F_1 ( V_33 , 4 , V_29 , L_20 , V_27 , V_27 -> V_15 ) ;
#endif
}
#ifdef F_26
F_1 ( V_34 , 5 , V_29 , L_24 , V_25 ) ;
#endif
return V_25 ;
}
extern void F_38 ( T_10 * V_27 , T_12 V_63 ) {
T_8 * V_25 ;
#ifdef F_26
F_1 ( V_33 , 3 , V_29 , L_25 , V_27 ) ;
#endif
while( ( V_25 = F_37 ( V_27 ) ) ) {
if ( V_63 ) {
F_28 ( V_25 ) ;
}
}
F_16 ( V_35 , V_27 -> V_36 ) ;
F_19 ( V_39 , ( V_39 * ) V_27 ) ;
}
extern T_8 * F_39 ( T_10 * V_27 , void * * V_59 ) {
T_11 * V_62 ;
#ifdef F_26
F_1 ( V_34 , 5 , V_29 , L_26 , V_27 , * V_59 ) ;
#endif
if ( * V_59 ) {
V_62 = ( T_11 * ) * V_59 ;
} else {
V_62 = V_27 -> null . V_52 ;
}
* V_59 = V_62 -> V_52 ;
#ifdef F_26
F_1 ( V_34 , 5 , V_29 , L_24 , V_62 -> V_25 ) ;
#endif
return V_62 -> V_25 ;
}
T_3 * F_40 ( T_10 * V_27 ) {
T_11 * V_8 ;
T_13 * V_12 = F_41 ( L_7 ) ;
T_3 * V_64 ;
T_3 * V_65 ;
for( V_8 = V_27 -> null . V_52 ; V_8 -> V_25 ; V_8 = V_8 -> V_52 ) {
V_64 = F_42 ( V_8 -> V_25 ) ;
F_43 ( V_12 , L_27 , V_64 ) ;
F_44 ( V_64 ) ;
}
V_65 = F_45 ( V_12 , FALSE ) ;
return V_65 ;
}
extern T_3 * F_46 ( T_10 * V_27 ) {
T_11 * V_8 ;
T_13 * V_12 = F_41 ( L_7 ) ;
T_3 * V_64 ;
T_3 * V_65 ;
for( V_8 = V_27 -> null . V_52 ; V_8 -> V_25 ; V_8 = V_8 -> V_52 ) {
V_64 = F_42 ( V_8 -> V_25 ) ;
F_43 ( V_12 , L_28 , V_64 ) ;
F_44 ( V_64 ) ;
}
V_65 = F_45 ( V_12 , FALSE ) ;
return V_65 ;
}
extern void F_47 ( T_10 * V_66 , T_10 * V_67 , T_12 V_68 ) {
T_11 * V_69 = NULL ;
T_11 * V_70 = NULL ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_29 , V_66 , V_67 ) ;
#endif
V_70 = V_67 -> null . V_52 ;
V_69 = V_66 -> null . V_52 ;
while ( V_70 -> V_25 && V_69 -> V_25 ) {
int V_56 = strcmp ( V_69 -> V_25 -> V_42 , V_70 -> V_25 -> V_42 ) ;
if ( V_56 < 0 ) {
V_69 = V_69 -> V_52 ;
} else if ( V_56 > 0 ) {
F_32 ( V_66 , V_69 , V_70 -> V_25 , V_68 ) ;
V_70 = V_70 -> V_52 ;
} else {
int V_57 = strcmp ( V_69 -> V_25 -> V_47 , V_70 -> V_25 -> V_47 ) ;
if ( V_57 < 0 ) {
V_69 = V_69 -> V_52 ;
} else if ( V_57 > 0 ) {
F_32 ( V_66 , V_69 , V_70 -> V_25 , V_68 ) ;
V_70 = V_70 -> V_52 ;
} else {
V_70 = V_70 -> V_52 ;
}
}
}
while ( V_70 -> V_25 ) {
F_32 ( V_66 , V_69 , V_70 -> V_25 , V_68 ) ;
V_70 = V_70 -> V_52 ;
}
#ifdef F_26
F_1 ( V_34 , 8 , V_29 , L_30 ) ;
#endif
return;
}
extern T_10 * F_48 ( const T_3 * V_36 , T_10 * V_27 , T_12 V_68 ) {
T_10 * V_71 = F_30 ( V_36 ) ;
void * V_59 = NULL ;
T_8 * V_25 ;
T_8 * V_72 ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_31 , V_71 , V_27 , V_36 ) ;
#endif
while( ( V_25 = F_39 ( V_27 , & V_59 ) ) ) {
if ( V_68 ) {
V_72 = F_29 ( V_25 ) ;
if ( ! F_33 ( V_71 , V_72 ) ) {
F_28 ( V_72 ) ;
}
} else {
F_33 ( V_71 , V_25 ) ;
}
}
#ifdef F_26
F_1 ( V_34 , 8 , V_29 , L_32 ) ;
#endif
return V_71 ;
}
extern T_8 * F_49 ( T_8 * V_67 , T_8 * V_73 ) {
T_3 * * V_74 ;
int V_75 ;
T_3 * V_76 ;
T_6 V_77 ;
T_6 V_78 ;
float V_79 = 0.0f ;
float V_80 = 0.0f ;
T_12 V_81 = FALSE ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_33 , V_67 -> V_42 , V_67 -> V_48 , V_67 -> V_47 , V_73 -> V_42 , V_73 -> V_48 , V_73 -> V_47 ) ;
#endif
if ( V_67 -> V_42 != V_73 -> V_42 ) {
return NULL ;
}
switch ( V_73 -> V_48 ) {
case V_82 :
return V_67 ;
case V_58 :
return V_67 -> V_47 == V_73 -> V_47 ? V_67 : NULL ;
case V_83 :
return ! ( V_67 -> V_47 == V_73 -> V_47 ) ? V_67 : NULL ;
case V_84 :
return strncmp ( V_67 -> V_47 , V_73 -> V_47 , strlen ( V_73 -> V_47 ) ) == 0 ? V_67 : NULL ;
case V_85 :
V_74 = F_50 ( V_73 -> V_47 , L_34 , 0 ) ;
if ( V_74 ) {
for ( V_75 = 0 ; V_74 [ V_75 ] ; V_75 ++ ) {
if( V_11 ( V_74 [ V_75 ] , V_67 -> V_47 ) ) {
F_51 ( V_74 ) ;
return V_67 ;
}
}
F_51 ( V_74 ) ;
}
return NULL ;
case V_86 :
V_81 = TRUE ;
case V_87 :
V_79 = ( float ) F_52 ( V_67 -> V_47 , NULL ) ;
V_80 = ( float ) F_52 ( V_73 -> V_47 , NULL ) ;
if ( V_81 ) {
if ( V_79 < V_80 ) return V_67 ;
else return NULL ;
} else {
if ( V_79 > V_80 ) return V_67 ;
else return NULL ;
}
case V_88 :
V_77 = ( T_6 ) strlen ( V_67 -> V_47 ) ;
V_78 = ( T_6 ) strlen ( V_73 -> V_47 ) ;
if ( V_77 < V_78 ) {
return NULL ;
} else {
V_76 = V_67 -> V_47 + ( V_77 - V_78 ) ;
return V_11 ( V_76 , V_73 -> V_47 ) ? V_67 : NULL ;
}
case V_89 :
return F_53 ( V_67 -> V_47 , V_73 -> V_47 ) ? V_67 : NULL ; ;
}
return NULL ;
}
extern T_10 * F_54 ( const T_3 * V_36 ,
T_10 * V_67 ,
T_10 * V_73 ,
T_12 V_68 ) {
T_10 * V_71 = F_30 ( F_9 ( V_35 , V_36 ) ) ;
T_11 * V_90 = NULL ;
T_11 * V_70 = NULL ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_35 , V_71 , V_67 , V_73 , V_36 ) ;
#endif
V_70 = V_67 -> null . V_52 ;
V_90 = V_73 -> null . V_52 ;
while ( V_70 -> V_25 && V_90 -> V_25 ) {
int V_56 = strcmp ( V_90 -> V_25 -> V_42 , V_70 -> V_25 -> V_42 ) ;
if ( V_56 < 0 ) {
V_90 = V_90 -> V_52 ;
} else if ( V_56 > 0 ) {
V_70 = V_70 -> V_52 ;
} else {
T_11 * V_91 = V_90 ;
do {
if ( F_49 ( V_70 -> V_25 , V_91 -> V_25 ) ) {
F_32 ( V_71 , V_71 -> null . V_53 , V_70 -> V_25 , V_68 ) ;
break;
}
V_91 = V_91 -> V_52 ;
} while ( V_91 -> V_25 && V_91 -> V_25 -> V_42 == V_70 -> V_25 -> V_42 );
V_70 = V_70 -> V_52 ;
}
}
return V_71 ;
}
extern T_10 * F_55 ( const T_3 * V_36 , T_10 * V_67 , T_10 * V_73 , T_12 V_92 , T_12 V_68 ) {
T_10 * V_71 ;
T_11 * V_90 = NULL ;
T_11 * V_70 = NULL ;
const T_3 * V_93 = NULL ;
T_12 V_94 = TRUE ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_36 , V_95 , V_71 , V_67 , V_73 , V_36 ) ;
#endif
V_71 = F_30 ( F_9 ( V_35 , V_36 ) ) ;
V_70 = V_67 -> null . V_52 ;
V_90 = V_73 -> null . V_52 ;
while ( V_70 -> V_25 && V_90 -> V_25 ) {
int V_56 = strcmp ( V_90 -> V_25 -> V_42 , V_70 -> V_25 -> V_42 ) ;
const T_3 * V_96 = NULL ;
if ( V_56 < 0 ) {
V_96 = V_90 -> V_25 -> V_42 ;
V_90 = V_90 -> V_52 ;
} else if ( V_56 > 0 ) {
V_70 = V_70 -> V_52 ;
} else {
if ( F_49 ( V_70 -> V_25 , V_90 -> V_25 ) ) {
F_32 ( V_71 , V_71 -> null . V_53 , V_70 -> V_25 , V_68 ) ;
V_93 = V_90 -> V_25 -> V_42 ;
V_70 = V_70 -> V_52 ;
} else {
V_96 = V_90 -> V_25 -> V_42 ;
}
V_90 = V_90 -> V_52 ;
}
if ( V_96 ) {
if ( V_92 ) {
V_94 = FALSE ;
break;
} else if ( V_93 != V_96 ) {
if ( ! V_90 -> V_25 || V_90 -> V_25 -> V_42 != V_93 ) {
V_94 = FALSE ;
break;
}
}
}
}
if ( V_94 && V_92 && V_90 -> V_25 ) {
V_94 = FALSE ;
}
if ( V_94 ) {
return V_71 ;
} else {
F_38 ( V_71 , V_68 ) ;
return NULL ;
}
}
extern T_10 * F_56 ( T_14 V_97 , const T_3 * V_36 , T_10 * V_67 , T_10 * V_73 , T_12 V_68 ) {
T_10 * V_27 = NULL ;
switch ( V_97 ) {
case V_98 :
V_27 = F_55 ( V_36 , V_67 , V_73 , TRUE , V_68 ) ;
break;
case V_99 :
V_27 = F_54 ( V_36 , V_67 , V_73 , V_68 ) ;
break;
case V_100 :
V_27 = F_55 ( V_36 , V_67 , V_73 , FALSE , V_68 ) ;
break;
case V_101 :
V_27 = F_48 ( V_36 , V_67 , V_68 ) ;
F_47 ( V_27 , V_73 , V_68 ) ;
break;
}
return V_27 ;
}
extern void F_57 ( T_15 * V_73 ) {
T_15 * V_52 ;
for (; V_73 ; V_73 = V_52 ) {
V_52 = V_73 -> V_52 ;
F_44 ( V_73 -> V_36 ) ;
if ( V_73 -> V_102 ) {
F_38 ( V_73 -> V_102 , TRUE ) ;
}
if ( V_73 -> V_103 ) {
F_38 ( V_73 -> V_103 , TRUE ) ;
}
F_44 ( V_73 ) ;
}
}
extern void F_58 ( T_10 * V_67 , T_15 * V_73 ) {
T_10 * V_27 = NULL ;
T_11 * V_70 ;
T_11 * V_104 ;
T_11 * V_42 ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_37 , V_67 , V_73 ) ;
#endif
for ( ; V_73 ; V_73 = V_73 -> V_52 ) {
V_27 = F_56 ( V_73 -> V_105 , V_67 -> V_36 , V_67 , V_73 -> V_102 , TRUE ) ;
if ( V_27 ) {
switch ( V_73 -> V_106 ) {
case V_107 :
F_38 ( V_27 , TRUE ) ;
return;
case V_108 :
F_47 ( V_67 , V_73 -> V_103 , TRUE ) ;
F_38 ( V_27 , TRUE ) ;
return;
case V_109 :
V_70 = V_67 -> null . V_52 ;
V_104 = V_27 -> null . V_52 ;
while ( V_70 -> V_25 && V_104 -> V_25 ) {
if ( V_70 -> V_25 -> V_42 == V_104 -> V_25 -> V_42 && V_70 -> V_25 -> V_47 == V_104 -> V_25 -> V_47 ) {
V_42 = V_70 -> V_52 ;
V_70 -> V_53 -> V_52 = V_70 -> V_52 ;
V_70 -> V_52 -> V_53 = V_70 -> V_53 ;
F_19 ( V_39 , ( V_39 * ) V_70 ) ;
V_70 = V_42 ;
V_104 = V_104 -> V_52 ;
} else {
V_70 = V_70 -> V_52 ;
}
}
F_47 ( V_67 , V_73 -> V_103 , TRUE ) ;
F_38 ( V_27 , TRUE ) ;
return;
}
}
}
}
extern T_16 * F_59 ( const T_3 * V_36 ) {
T_16 * V_110 = ( T_16 * ) F_11 ( V_39 ) ;
if ( ! V_36 ) {
V_36 = L_38 ;
}
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_39 , V_110 , V_36 ) ;
#endif
V_110 -> V_36 = F_9 ( V_35 , V_36 ) ;
V_110 -> null . V_27 = NULL ;
V_110 -> null . V_52 = & V_110 -> null ;
V_110 -> null . V_53 = & V_110 -> null ;
V_110 -> V_15 = 0 ;
return V_110 ;
}
extern void F_60 ( T_16 * V_111 , T_10 * V_27 ) {
T_17 * V_62 = ( T_17 * ) F_11 ( V_39 ) ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_40 , V_62 ) ;
#endif
V_62 -> V_27 = V_27 ;
V_62 -> V_52 = & V_111 -> null ;
V_62 -> V_53 = V_111 -> null . V_53 ;
V_111 -> null . V_53 -> V_52 = V_62 ;
V_111 -> null . V_53 = V_62 ;
V_111 -> V_15 ++ ;
}
extern T_10 * F_61 ( T_16 * V_111 ) {
T_17 * V_62 ;
T_10 * V_27 ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_41 , V_111 -> V_36 ) ;
#endif
V_62 = V_111 -> null . V_52 ;
V_111 -> null . V_52 -> V_52 -> V_53 = & V_111 -> null ;
V_111 -> null . V_52 = V_62 -> V_52 ;
V_111 -> V_15 -- ;
V_27 = V_62 -> V_27 ;
if ( V_27 ) {
F_19 ( V_39 , ( V_39 * ) V_62 ) ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_42 , V_27 -> V_36 ) ;
F_1 ( V_34 , 3 , V_29 , L_43 , V_62 ) ;
#endif
}
return V_27 ;
}
extern T_10 * F_62 ( T_16 * V_111 ) {
T_17 * V_62 ;
T_10 * V_27 ;
V_62 = V_111 -> null . V_53 ;
V_111 -> null . V_53 -> V_53 -> V_52 = & V_111 -> null ;
V_111 -> null . V_53 = V_62 -> V_53 ;
V_111 -> V_15 -- ;
V_27 = V_62 -> V_27 ;
if ( V_27 ) {
F_19 ( V_39 , ( V_39 * ) V_62 ) ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_43 , V_62 ) ;
#endif
}
return V_27 ;
}
extern T_10 * F_63 ( T_16 * V_111 , void * * V_59 ) {
T_17 * V_62 ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_44 , V_111 , * V_59 ) ;
#endif
if ( * V_59 ) {
V_62 = ( T_17 * ) * V_59 ;
} else {
V_62 = V_111 -> null . V_52 ;
}
* V_59 = V_62 -> V_52 ;
return V_62 -> V_27 ;
}
extern void F_64 ( T_16 * V_111 , T_12 V_112 , T_12 V_63 ) {
T_10 * V_27 ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_45 , V_111 ) ;
#endif
while( ( V_27 = F_62 ( V_111 ) ) ) {
if ( V_112 ) {
F_38 ( V_27 , V_63 ) ;
}
}
F_16 ( V_35 , V_111 -> V_36 ) ;
F_19 ( V_39 , ( V_39 * ) V_111 ) ;
}
static T_16 * F_65 ( T_2 * V_23 , T_16 * V_111 , T_10 * V_60 , int V_113 , const T_3 * V_4 , ... ) {
T_4 V_7 ;
T_3 * V_114 ;
T_16 * V_115 = NULL ;
T_3 * V_116 ;
va_start ( V_7 , V_4 ) ;
V_114 = F_66 ( V_4 , V_7 ) ;
va_end ( V_7 ) ;
V_116 = F_67 ( L_46 , V_111 -> V_36 , V_113 , V_114 ) ;
V_115 = F_59 ( V_116 ) ;
F_44 ( V_114 ) ;
F_44 ( V_116 ) ;
if ( V_23 ) fclose ( V_23 ) ;
if ( V_111 ) F_64 ( V_111 , TRUE , TRUE ) ;
if ( V_60 ) F_38 ( V_60 , TRUE ) ;
return V_115 ;
}
extern T_16 * F_68 ( T_3 * V_117 ) {
T_2 * V_23 = NULL ;
T_3 V_8 ;
int V_75 = 0 ;
V_49 V_113 = 1 ;
T_3 * V_118 ;
T_3 * V_36 ;
T_3 * V_40 ;
T_3 V_73 = '?' ;
T_16 * V_119 , * V_111 = F_59 ( V_117 ) ;
T_10 * V_60 = NULL ;
T_8 * V_25 ;
enum T_18 {
V_120 ,
V_121 ,
V_122 ,
V_123 ,
V_124
} V_125 ;
V_118 = ( T_3 * ) F_7 ( V_126 ) ;
V_36 = ( T_3 * ) F_7 ( V_126 ) ;
V_40 = ( T_3 * ) F_7 ( V_126 ) ;
#ifndef F_69
if ( ! F_70 () ) {
V_119 = F_65 ( V_23 , V_111 , V_60 , V_113 , L_47 ) ;
goto error;
}
#endif
V_125 = V_120 ;
if ( ( V_23 = F_71 ( V_117 , L_48 ) ) ) {
while( ( V_8 = ( T_3 ) fgetc ( V_23 ) ) ) {
if ( feof ( V_23 ) ) {
if ( ferror ( V_23 ) ) {
F_72 ( V_117 , V_127 ) ;
V_119 = F_65 ( V_23 , V_111 , V_60 , V_113 , L_49 , V_117 ) ;
goto error;
}
break;
}
if ( V_8 == '\n' ) {
V_113 ++ ;
}
if ( V_75 >= V_126 - 1 ) {
V_119 = F_65 ( V_23 , V_111 , V_60 , V_113 , L_50 ) ;
goto error;
}
switch( V_125 ) {
case V_124 :
switch ( V_8 ) {
case '\n' :
V_125 = V_120 ;
V_75 = 0 ;
continue;
default:
continue;
}
case V_120 :
switch ( V_8 ) {
case ' ' : case '\t' :
continue;
case '\n' :
V_75 = 0 ;
continue;
case V_128 :
V_125 = V_122 ;
V_75 = 0 ;
V_36 [ V_75 ++ ] = V_8 ;
V_36 [ V_75 ] = '\0' ;
F_73 ( V_118 , V_126 , L_51 , V_117 , V_113 ) ;
V_60 = F_30 ( V_118 ) ;
continue;
case '#' :
V_125 = V_124 ;
continue;
default:
V_119 = F_65 ( V_23 , V_111 , V_60 , V_113 , L_52 , V_8 ) ;
goto error;
}
case V_121 :
V_75 = 0 ;
V_36 [ 0 ] = '\0' ;
switch ( V_8 ) {
case '\\' :
V_8 = ( T_3 ) fgetc ( V_23 ) ;
if ( V_8 != '\n' ) ungetc ( V_8 , V_23 ) ;
continue;
case ' ' :
case '\t' :
continue;
case V_128 :
V_125 = V_122 ;
V_36 [ V_75 ++ ] = V_8 ;
V_36 [ V_75 ] = '\0' ;
continue;
case '\n' :
F_60 ( V_111 , V_60 ) ;
V_125 = V_120 ;
continue;
default:
V_119 = F_65 ( V_23 , V_111 , V_60 , V_113 , L_52 , V_8 ) ;
goto error;
}
case V_122 :
switch ( V_8 ) {
case ';' :
V_125 = V_121 ;
V_73 = '?' ;
V_36 [ V_75 ] = '\0' ;
V_40 [ 0 ] = '\0' ;
V_75 = 0 ;
V_25 = F_27 ( V_36 , V_40 , V_73 ) ;
if ( ! F_33 ( V_60 , V_25 ) ) {
F_28 ( V_25 ) ;
}
continue;
case V_129 :
V_36 [ V_75 ] = '\0' ;
V_75 = 0 ;
V_73 = V_8 ;
V_125 = V_123 ;
continue;
case V_128 :
V_36 [ V_75 ++ ] = V_8 ;
continue;
case '\n' :
V_119 = F_65 ( V_23 , V_111 , V_60 , V_113 , L_53 ) ;
goto error;
default:
V_119 = F_65 ( V_23 , V_111 , V_60 , V_113 , L_54 , V_8 ) ;
goto error;
}
case V_123 :
switch ( V_8 ) {
case '\\' :
V_40 [ V_75 ++ ] = ( T_3 ) fgetc ( V_23 ) ;
continue;
case ';' :
V_125 = V_121 ;
V_40 [ V_75 ] = '\0' ;
V_75 = 0 ;
V_25 = F_27 ( V_36 , V_40 , V_73 ) ;
if ( ! F_33 ( V_60 , V_25 ) ) {
F_28 ( V_25 ) ;
}
continue;
case '\n' :
V_119 = F_65 ( V_23 , V_111 , V_60 , V_113 , L_55 ) ;
goto error;
default:
V_40 [ V_75 ++ ] = V_8 ;
continue;
}
}
}
fclose ( V_23 ) ;
F_44 ( V_118 ) ;
F_44 ( V_36 ) ;
F_44 ( V_40 ) ;
return V_111 ;
} else {
F_74 ( V_117 , V_127 , FALSE ) ;
V_119 = F_65 ( NULL , V_111 , NULL , 0 , L_56 , V_117 ) ;
}
error:
F_44 ( V_118 ) ;
F_44 ( V_36 ) ;
F_44 ( V_40 ) ;
return V_119 ;
}
