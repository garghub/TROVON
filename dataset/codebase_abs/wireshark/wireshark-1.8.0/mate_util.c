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
T_5 * V_8 = F_7 ( sizeof( T_5 ) ) ;
V_8 -> V_9 = F_8 ( V_10 , V_11 ) ;
return V_8 ;
}
T_3 * F_9 ( T_5 * V_8 , const T_3 * V_12 ) {
T_3 * V_13 = NULL ;
T_6 * V_14 = NULL ;
T_7 V_15 = 0 ;
F_10 ( V_8 -> V_9 , ( V_16 ) V_12 , ( V_17 ) & V_13 , ( V_17 ) & V_14 ) ;
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
V_13 = F_13 ( V_15 ) ;
F_14 ( V_13 , V_12 , V_15 ) ;
F_15 ( V_8 -> V_9 , V_13 , V_14 ) ;
}
return V_13 ;
}
void F_16 ( T_5 * V_8 , T_3 * V_12 ) {
T_3 * V_13 = NULL ;
T_6 * V_14 = NULL ;
T_7 V_15 = 0xffff ;
F_10 ( V_8 -> V_9 , ( V_16 ) V_12 , ( V_17 ) & V_13 , ( V_17 ) & V_14 ) ;
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
T_3 * V_41 = NULL ;
V_38 -> V_42 = F_9 ( V_35 , V_36 ) ;
if ( V_37 -> V_40 . V_43 -> V_44 ) {
V_41 = F_24 ( & V_37 -> V_40 , V_45 , NULL ) ;
}
if ( V_41 ) {
V_40 = F_9 ( V_35 , V_41 ) ;
#ifdef F_25
F_1 ( V_31 , 2 , V_29 , L_5 , V_40 ) ;
#endif
} else {
#ifdef F_25
F_1 ( V_31 , 2 , V_29 , L_6 , V_37 -> V_46 -> V_47 ) ;
#endif
V_40 = F_9 ( V_35 , L_7 ) ;
}
V_38 -> V_48 = V_40 ;
V_38 -> V_49 = '=' ;
#ifdef F_25
F_1 ( V_31 , 1 , V_29 , L_8 , ( V_50 ) V_38 , V_38 -> V_42 , V_38 -> V_49 , V_38 -> V_48 ) ;
#endif
return V_38 ;
}
extern T_8 * F_26 ( const T_3 * V_36 , const T_3 * V_40 , T_3 V_49 ) {
T_8 * V_38 = ( T_8 * ) F_11 ( V_39 ) ;
V_38 -> V_42 = F_9 ( V_35 , V_36 ) ;
V_38 -> V_48 = F_9 ( V_35 , V_40 ) ;
V_38 -> V_49 = V_49 ;
#ifdef F_25
F_1 ( V_31 , 1 , V_29 , L_9 , ( V_50 ) V_38 , V_38 -> V_42 , V_38 -> V_49 , V_38 -> V_48 ) ;
#endif
return V_38 ;
}
extern void F_27 ( T_8 * V_25 ) {
#ifdef F_25
F_1 ( V_31 , 1 , V_29 , L_10 , ( V_50 ) V_25 , V_25 -> V_42 , V_25 -> V_49 , V_25 -> V_48 ) ;
#endif
F_16 ( V_35 , V_25 -> V_42 ) ;
F_16 ( V_35 , V_25 -> V_48 ) ;
F_19 ( V_39 , ( V_39 * ) V_25 ) ;
}
extern T_8 * F_28 ( T_8 * V_51 ) {
T_8 * V_38 = ( T_8 * ) F_11 ( V_39 ) ;
V_38 -> V_42 = F_9 ( V_35 , V_51 -> V_42 ) ;
V_38 -> V_48 = F_9 ( V_35 , V_51 -> V_48 ) ;
V_38 -> V_49 = V_51 -> V_49 ;
#ifdef F_25
F_1 ( V_31 , 1 , V_29 , L_11 , ( V_50 ) V_38 , V_38 -> V_42 , V_38 -> V_49 , V_38 -> V_48 ) ;
#endif
return V_38 ;
}
extern T_10 * F_29 ( const T_3 * V_36 ) {
T_10 * V_52 = ( T_10 * ) F_11 ( V_39 ) ;
#ifdef F_25
F_1 ( V_34 , 7 , V_29 , L_12 , V_52 , V_36 ) ;
#endif
V_52 -> V_36 = V_36 ? F_9 ( V_35 , V_36 ) : F_9 ( V_35 , L_7 ) ;
V_52 -> V_15 = 0 ;
V_52 -> null . V_25 = NULL ;
V_52 -> null . V_53 = & V_52 -> null ;
V_52 -> null . V_54 = & V_52 -> null ;
return V_52 ;
}
extern void F_30 ( T_10 * V_27 , T_3 * V_36 ) {
F_16 ( V_35 , V_27 -> V_36 ) ;
V_27 -> V_36 = F_9 ( V_35 , V_36 ) ;
}
extern T_11 F_31 ( T_10 * V_27 , T_8 * V_25 ) {
T_12 * V_38 = ( T_12 * ) F_11 ( V_39 ) ;
T_12 * V_8 ;
V_38 -> V_25 = V_25 ;
#ifdef F_25
F_1 ( V_34 , 7 , V_29 , L_13 , V_38 ) ;
F_1 ( V_34 , 4 , V_29 , L_14 , V_27 , V_25 , V_25 -> V_42 , V_25 -> V_49 , V_25 -> V_48 ) ;
#endif
for( V_8 = V_27 -> null . V_53 ; V_8 -> V_25 ; V_8 = V_8 -> V_53 ) {
if ( V_25 -> V_42 == V_8 -> V_25 -> V_42 ) {
if ( V_25 -> V_48 > V_8 -> V_25 -> V_48 ) {
break;
}
if ( V_25 -> V_48 == V_8 -> V_25 -> V_48 ) {
if ( V_25 -> V_49 == V_55 ) {
#ifdef F_25
F_1 ( V_34 , 7 , V_29 , L_15 , V_38 ) ;
#endif
F_19 ( V_39 , ( V_39 * ) V_38 ) ;
return FALSE ;
}
}
}
if ( V_25 -> V_42 > V_8 -> V_25 -> V_42 ) {
break;
}
}
#ifdef F_25
F_1 ( V_33 , 5 , V_29 , L_16 , V_25 , V_27 , V_8 ) ;
#endif
V_38 -> V_53 = V_8 ;
V_38 -> V_54 = V_8 -> V_54 ;
V_8 -> V_54 -> V_53 = V_38 ;
V_8 -> V_54 = V_38 ;
V_27 -> V_15 ++ ;
#ifdef F_25
F_1 ( V_33 , 4 , V_29 , L_17 , V_27 , V_27 -> V_15 ) ;
#endif
return TRUE ;
}
extern T_8 * F_32 ( T_10 * V_27 , T_3 * V_36 , void * * V_56 ) {
T_12 * V_57 ;
T_12 * V_58 = ( T_12 * ) * V_56 ;
#ifdef F_25
F_1 ( V_34 , 7 , V_29 , L_18 , V_27 , V_36 , * V_56 ) ;
#endif
V_36 = F_9 ( V_35 , V_36 ) ;
if ( ! V_58 ) V_58 = V_27 -> null . V_53 ;
for ( V_57 = V_58 ; V_57 -> V_25 ; V_57 = V_57 -> V_53 ) {
if ( V_57 -> V_25 -> V_42 == V_36 ) {
break;
}
}
* V_56 = V_57 ;
#ifdef F_25
F_1 ( V_34 , 5 , V_29 , L_19 , V_57 ) ;
#endif
F_16 ( V_35 , V_36 ) ;
return V_57 -> V_25 ;
}
extern T_8 * F_33 ( T_10 * V_27 , T_3 * V_36 ) {
T_12 * V_57 ;
T_8 * V_25 = NULL ;
#ifdef F_25
F_1 ( V_34 , 7 , V_29 , L_20 , V_27 , V_36 ) ;
#endif
V_36 = F_9 ( V_35 , V_36 ) ;
for ( V_57 = V_27 -> null . V_53 ; V_57 -> V_25 ; V_57 = V_57 -> V_53 ) {
if ( V_57 -> V_25 -> V_42 == V_36 ) {
break;
}
}
F_16 ( V_35 , V_36 ) ;
if( ! V_57 -> V_25 ) return NULL ;
V_57 -> V_53 -> V_54 = V_57 -> V_54 ;
V_57 -> V_54 -> V_53 = V_57 -> V_53 ;
V_25 = V_57 -> V_25 ;
F_19 ( V_39 , ( V_39 * ) V_57 ) ;
( V_27 -> V_15 ) -- ;
#ifdef F_25
F_1 ( V_33 , 4 , V_29 , L_17 , V_27 , V_27 -> V_15 ) ;
#endif
#ifdef F_25
F_1 ( V_34 , 5 , V_29 , L_21 , V_25 ) ;
#endif
return V_25 ;
}
extern T_8 * F_34 ( T_10 * V_27 ) {
T_8 * V_25 ;
T_12 * V_59 ;
#ifdef F_25
F_1 ( V_34 , 7 , V_29 , L_22 , V_27 ) ;
#endif
V_59 = V_27 -> null . V_53 ;
V_27 -> null . V_53 -> V_54 = & V_27 -> null ;
V_27 -> null . V_53 = V_59 -> V_53 ;
V_25 = V_59 -> V_25 ;
if ( V_25 ) {
F_19 ( V_39 , ( V_39 * ) V_59 ) ;
( V_27 -> V_15 ) -- ;
#ifdef F_25
F_1 ( V_33 , 4 , V_29 , L_17 , V_27 , V_27 -> V_15 ) ;
#endif
}
#ifdef F_25
F_1 ( V_34 , 5 , V_29 , L_23 , V_25 ) ;
#endif
return V_25 ;
}
extern T_8 * F_35 ( T_10 * V_27 ) {
T_8 * V_25 ;
T_12 * V_59 ;
V_59 = V_27 -> null . V_54 ;
V_27 -> null . V_54 -> V_53 = & V_27 -> null ;
V_27 -> null . V_54 = V_59 -> V_54 ;
V_25 = V_59 -> V_25 ;
if ( V_25 ) {
F_19 ( V_39 , ( V_39 * ) V_59 ) ;
( V_27 -> V_15 ) -- ;
#ifdef F_25
F_1 ( V_33 , 4 , V_29 , L_17 , V_27 , V_27 -> V_15 ) ;
#endif
}
#ifdef F_25
F_1 ( V_34 , 5 , V_29 , L_24 , V_25 ) ;
#endif
return V_25 ;
}
extern void F_36 ( T_10 * V_27 , T_11 V_60 ) {
T_8 * V_25 ;
#ifdef F_25
F_1 ( V_33 , 3 , V_29 , L_25 , V_27 ) ;
#endif
while( ( V_25 = F_35 ( V_27 ) ) ) {
if ( V_60 ) {
F_27 ( V_25 ) ;
}
}
F_16 ( V_35 , V_27 -> V_36 ) ;
F_19 ( V_39 , ( V_39 * ) V_27 ) ;
}
extern T_8 * F_37 ( T_10 * V_27 , void * * V_56 ) {
T_12 * V_59 ;
#ifdef F_25
F_1 ( V_34 , 5 , V_29 , L_26 , V_27 , * V_56 ) ;
#endif
if ( * V_56 ) {
V_59 = ( T_12 * ) * V_56 ;
} else {
V_59 = V_27 -> null . V_53 ;
}
* V_56 = V_59 -> V_53 ;
#ifdef F_25
F_1 ( V_34 , 5 , V_29 , L_24 , V_59 -> V_25 ) ;
#endif
return V_59 -> V_25 ;
}
T_3 * F_38 ( T_10 * V_27 ) {
T_12 * V_8 ;
T_13 * V_12 = F_39 ( L_7 ) ;
T_3 * V_61 ;
T_3 * V_62 ;
for( V_8 = V_27 -> null . V_53 ; V_8 -> V_25 ; V_8 = V_8 -> V_53 ) {
V_61 = F_40 ( V_8 -> V_25 ) ;
F_41 ( V_12 , L_27 , V_61 ) ;
F_42 ( V_61 ) ;
}
V_62 = V_12 -> V_63 ;
F_43 ( V_12 , FALSE ) ;
return V_62 ;
}
extern T_3 * F_44 ( T_10 * V_27 ) {
T_12 * V_8 ;
T_13 * V_12 = F_39 ( L_7 ) ;
T_3 * V_61 ;
T_3 * V_62 ;
for( V_8 = V_27 -> null . V_53 ; V_8 -> V_25 ; V_8 = V_8 -> V_53 ) {
V_61 = F_40 ( V_8 -> V_25 ) ;
F_41 ( V_12 , L_28 , V_61 ) ;
F_42 ( V_61 ) ;
}
V_62 = V_12 -> V_63 ;
F_43 ( V_12 , FALSE ) ;
return V_62 ;
}
extern void F_45 ( T_10 * V_64 , T_10 * V_65 , T_11 V_66 ) {
T_12 * V_67 = NULL ;
T_12 * V_68 = NULL ;
T_14 V_8 ;
T_8 * V_69 ;
#ifdef F_25
F_1 ( V_34 , 3 , V_29 , L_29 , V_64 , V_65 ) ;
#endif
V_68 = V_65 -> null . V_53 ;
V_67 = V_64 -> null . V_53 ;
while( V_68 -> V_25 ) {
if( V_67 -> V_25 ) {
V_8 = F_46 ( V_67 -> V_25 -> V_42 , V_68 -> V_25 -> V_42 ) ;
} else {
V_8 = - 1 ;
}
if ( V_8 > 0 ) {
if ( V_67 -> V_25 ) V_67 = V_67 -> V_53 ;
} else if ( V_8 < 0 ) {
if ( V_66 ) {
V_69 = F_28 ( V_68 -> V_25 ) ;
if ( ! F_31 ( V_64 , V_69 ) ) {
F_27 ( V_69 ) ;
}
} else {
F_31 ( V_64 , V_68 -> V_25 ) ;
}
V_68 = V_68 -> V_53 ;
} else {
if ( ! V_67 -> V_25 || ! ( V_67 -> V_25 -> V_48 == V_68 -> V_25 -> V_48 ) ) {
if ( V_66 ) {
V_69 = F_28 ( V_68 -> V_25 ) ;
if ( ! F_31 ( V_64 , V_69 ) ) {
F_27 ( V_69 ) ;
}
} else {
F_31 ( V_64 , V_68 -> V_25 ) ;
}
}
V_68 = V_68 -> V_53 ;
if ( V_67 -> V_25 ) V_67 = V_67 -> V_53 ;
}
}
#ifdef F_25
F_1 ( V_34 , 8 , V_29 , L_30 ) ;
#endif
return;
}
extern T_10 * F_47 ( const T_3 * V_36 , T_10 * V_27 , T_11 V_66 ) {
T_10 * V_70 = F_29 ( V_36 ) ;
void * V_56 = NULL ;
T_8 * V_25 ;
T_8 * V_69 ;
#ifdef F_25
F_1 ( V_34 , 3 , V_29 , L_31 , V_70 , V_27 , V_36 ) ;
#endif
while( ( V_25 = F_37 ( V_27 , & V_56 ) ) ) {
if ( V_66 ) {
V_69 = F_28 ( V_25 ) ;
if ( ! F_31 ( V_70 , V_69 ) ) {
F_27 ( V_69 ) ;
}
} else {
F_31 ( V_70 , V_25 ) ;
}
}
#ifdef F_25
F_1 ( V_34 , 8 , V_29 , L_32 ) ;
#endif
return V_70 ;
}
extern T_8 * F_48 ( T_8 * V_65 , T_8 * V_71 ) {
T_3 * * V_72 ;
int V_73 ;
T_3 * V_74 ;
T_6 V_75 ;
T_6 V_76 ;
float V_77 = 0.0 ;
float V_78 = 0.0 ;
T_11 V_79 = FALSE ;
#ifdef F_25
F_1 ( V_34 , 3 , V_29 , L_33 , V_65 -> V_42 , V_65 -> V_49 , V_65 -> V_48 , V_71 -> V_42 , V_71 -> V_49 , V_71 -> V_48 ) ;
#endif
if ( V_65 -> V_42 != V_71 -> V_42 ) {
return NULL ;
}
switch ( V_71 -> V_49 ) {
case V_80 :
return V_65 ;
case V_55 :
return V_65 -> V_48 == V_71 -> V_48 ? V_65 : NULL ;
case V_81 :
return ! ( V_65 -> V_48 == V_71 -> V_48 ) ? V_65 : NULL ;
case V_82 :
return strncmp ( V_65 -> V_48 , V_71 -> V_48 , strlen ( V_71 -> V_48 ) ) == 0 ? V_65 : NULL ;
case V_83 :
V_72 = F_49 ( V_71 -> V_48 , L_34 , 0 ) ;
if ( V_72 ) {
for ( V_73 = 0 ; V_72 [ V_73 ] ; V_73 ++ ) {
if( V_11 ( V_72 [ V_73 ] , V_65 -> V_48 ) ) {
F_50 ( V_72 ) ;
return V_65 ;
}
}
F_50 ( V_72 ) ;
}
return NULL ;
case V_84 :
V_79 = TRUE ;
case V_85 :
V_77 = ( float ) strtod ( V_65 -> V_48 , NULL ) ;
V_78 = ( float ) strtod ( V_65 -> V_48 , NULL ) ;
if ( V_79 ) {
if ( V_77 < V_78 ) return V_65 ;
else return NULL ;
} else {
if ( V_77 > V_78 ) return V_65 ;
else return NULL ;
}
case V_86 :
V_75 = ( T_6 ) strlen ( V_65 -> V_48 ) ;
V_76 = ( T_6 ) strlen ( V_71 -> V_48 ) ;
if ( V_75 < V_76 ) {
return NULL ;
} else {
V_74 = V_65 -> V_48 + ( V_75 - V_76 ) ;
return V_11 ( V_74 , V_71 -> V_48 ) ? V_65 : NULL ;
}
case V_87 :
return NULL ;
}
return NULL ;
}
extern T_10 * F_51 ( const T_3 * V_36 ,
T_10 * V_65 ,
T_10 * V_71 ,
T_11 V_66 ) {
T_10 * V_70 = F_29 ( F_9 ( V_35 , V_36 ) ) ;
T_12 * V_88 = NULL ;
T_12 * V_68 = NULL ;
T_14 V_8 ;
T_8 * V_89 ;
T_8 * V_69 ;
#ifdef F_25
F_1 ( V_34 , 3 , V_29 , L_35 , V_70 , V_65 , V_71 , V_36 ) ;
#endif
V_68 = V_65 -> null . V_53 ;
V_88 = V_71 -> null . V_53 ;
while( 1 ) {
if ( ! V_88 -> V_25 ) {
return V_70 ;
}
if ( ! V_68 -> V_25 ) {
return V_70 ;
}
V_8 = F_46 ( V_88 -> V_25 -> V_42 , V_68 -> V_25 -> V_42 ) ;
if ( V_8 > 0 ) {
if ( V_88 -> V_25 ) V_88 = V_88 -> V_53 ;
} else if ( V_8 < 0 ) {
if ( V_68 -> V_25 ) V_68 = V_68 -> V_53 ;
} else {
V_89 = F_48 ( V_68 -> V_25 , V_88 -> V_25 ) ;
if( V_89 ) {
if ( V_66 ) {
V_69 = F_28 ( V_89 ) ;
if ( ! F_31 ( V_70 , V_69 ) ) {
F_27 ( V_69 ) ;
}
} else {
F_31 ( V_70 , V_89 ) ;
}
}
if ( V_68 -> V_25 ) V_68 = V_68 -> V_53 ;
}
}
#ifdef F_25
F_1 ( V_34 , 6 , V_29 , L_36 ) ;
#endif
return NULL ;
}
extern T_10 * F_52 ( const T_3 * V_36 , T_10 * V_65 , T_10 * V_71 , T_11 V_66 ) {
T_10 * V_70 ;
T_12 * V_88 = NULL ;
T_12 * V_68 = NULL ;
T_14 V_8 ;
T_8 * V_89 ;
T_8 * V_69 ;
T_11 V_90 ;
#ifdef F_25
F_1 ( V_34 , 3 , V_29 , L_37 , V_70 , V_65 , V_71 , V_36 ) ;
#endif
if ( V_65 -> V_15 == 0 ) return NULL ;
V_70 = F_29 ( F_9 ( V_35 , V_36 ) ) ;
if ( V_71 -> V_15 == 0 )
return V_70 ;
V_90 = TRUE ;
V_68 = V_65 -> null . V_53 ;
V_88 = V_71 -> null . V_53 ;
while( 1 ) {
if ( ! V_88 -> V_25 ) {
break;
}
if ( ! V_68 -> V_25 ) {
break;
}
V_8 = F_46 ( V_88 -> V_25 -> V_42 , V_68 -> V_25 -> V_42 ) ;
if ( V_8 > 0 ) {
F_36 ( V_70 , TRUE ) ;
return NULL ;
} else if ( V_8 < 0 ) {
V_68 = V_68 -> V_53 ;
if ( ! V_68 -> V_25 ) {
break;
}
} else {
V_89 = F_48 ( V_68 -> V_25 , V_88 -> V_25 ) ;
if( V_89 ) {
V_90 ++ ;
V_68 = V_68 -> V_53 ;
V_88 = V_88 -> V_53 ;
if ( V_66 ) {
V_69 = F_28 ( V_89 ) ;
if ( ! F_31 ( V_70 , V_69 ) ) {
F_27 ( V_69 ) ;
}
} else {
F_31 ( V_70 , V_89 ) ;
}
} else {
V_68 = V_68 -> V_53 ;
}
}
}
if ( V_90 ) {
return V_70 ;
} else {
F_36 ( V_70 , TRUE ) ;
return NULL ;
}
}
extern T_10 * F_53 ( const T_3 * V_36 , T_10 * V_65 , T_10 * V_71 , T_11 V_66 ) {
T_10 * V_70 = F_29 ( V_36 ) ;
T_12 * V_88 = NULL ;
T_12 * V_68 = NULL ;
T_14 V_8 ;
T_8 * V_89 ;
T_8 * V_69 ;
#ifdef F_25
F_1 ( V_34 , 3 , V_29 , L_37 , V_70 , V_65 , V_71 , V_36 ) ;
#endif
if ( V_71 -> V_15 == 0 )
return V_70 ;
if ( V_65 -> V_15 == 0 ) {
F_36 ( V_70 , FALSE ) ;
return NULL ;
}
V_68 = V_65 -> null . V_53 ;
V_88 = V_71 -> null . V_53 ;
while( 1 ) {
V_8 = F_46 ( V_88 -> V_25 -> V_42 , V_68 -> V_25 -> V_42 ) ;
if ( V_8 > 0 ) {
F_36 ( V_70 , TRUE ) ;
return NULL ;
} else if ( V_8 < 0 ) {
V_68 = V_68 -> V_53 ;
if ( ! V_68 -> V_25 ) {
F_36 ( V_70 , TRUE ) ;
return NULL ;
}
} else {
V_89 = F_48 ( V_68 -> V_25 , V_88 -> V_25 ) ;
if( V_89 ) {
V_68 = V_68 -> V_53 ;
V_88 = V_88 -> V_53 ;
if ( V_66 ) {
V_69 = F_28 ( V_89 ) ;
if ( ! F_31 ( V_70 , V_69 ) ) {
F_27 ( V_69 ) ;
}
} else {
F_31 ( V_70 , V_89 ) ;
}
if ( ! V_88 -> V_25 ) {
return V_70 ;
}
if ( ! V_68 -> V_25 ) {
F_36 ( V_70 , TRUE ) ;
return NULL ;
}
} else {
F_36 ( V_70 , TRUE ) ;
return NULL ;
}
}
}
return NULL ;
}
extern T_10 * F_54 ( T_15 V_91 , const T_3 * V_36 , T_10 * V_65 , T_10 * V_71 , T_11 V_66 ) {
T_10 * V_27 = NULL ;
switch ( V_91 ) {
case V_92 :
V_27 = F_53 ( V_36 , V_65 , V_71 , V_66 ) ;
break;
case V_93 :
V_27 = F_51 ( V_36 , V_65 , V_71 , V_66 ) ;
break;
case V_94 :
V_27 = F_52 ( V_36 , V_65 , V_71 , V_66 ) ;
break;
case V_95 :
V_27 = F_47 ( V_36 , V_65 , V_66 ) ;
F_45 ( V_27 , V_71 , V_66 ) ;
break;
}
return V_27 ;
}
extern void F_55 ( T_16 * V_71 ) {
T_16 * V_53 ;
for (; V_71 ; V_71 = V_53 ) {
V_53 = V_71 -> V_53 ;
F_42 ( V_71 -> V_36 ) ;
if ( V_71 -> V_96 ) {
F_36 ( V_71 -> V_96 , TRUE ) ;
}
if ( V_71 -> V_97 ) {
F_36 ( V_71 -> V_97 , TRUE ) ;
}
F_42 ( V_71 ) ;
}
}
extern void F_56 ( T_10 * V_65 , T_16 * V_71 ) {
T_10 * V_27 = NULL ;
T_12 * V_68 ;
T_12 * V_98 ;
T_12 * V_42 ;
#ifdef F_25
F_1 ( V_34 , 3 , V_29 , L_38 , V_65 , V_71 ) ;
#endif
for ( ; V_71 ; V_71 = V_71 -> V_53 ) {
V_27 = F_54 ( V_71 -> V_99 , V_65 -> V_36 , V_65 , V_71 -> V_96 , TRUE ) ;
if ( V_27 ) {
switch ( V_71 -> V_100 ) {
case V_101 :
F_36 ( V_27 , TRUE ) ;
return;
case V_102 :
F_45 ( V_65 , V_71 -> V_97 , TRUE ) ;
F_36 ( V_27 , TRUE ) ;
return;
case V_103 :
V_68 = V_65 -> null . V_53 ;
V_98 = V_27 -> null . V_53 ;
while( V_68 -> V_25 ) {
if ( V_98 -> V_25 && V_68 -> V_25 -> V_42 == V_98 -> V_25 -> V_42 && V_68 -> V_25 -> V_48 == V_98 -> V_25 -> V_48 ) {
V_42 = V_68 -> V_53 ;
V_68 -> V_54 -> V_53 = V_68 -> V_53 ;
V_68 -> V_53 -> V_54 = V_68 -> V_54 ;
F_19 ( V_39 , ( V_39 * ) V_68 ) ;
V_68 = V_42 ;
V_98 = V_98 -> V_53 ;
} else {
V_68 = V_68 -> V_53 ;
}
}
F_45 ( V_65 , V_71 -> V_97 , TRUE ) ;
F_36 ( V_27 , TRUE ) ;
return;
}
}
}
}
extern T_17 * F_57 ( const T_3 * V_36 ) {
T_17 * V_104 = ( T_17 * ) F_11 ( V_39 ) ;
if ( ! V_36 ) {
V_36 = L_39 ;
}
#ifdef F_25
F_1 ( V_34 , 3 , V_29 , L_40 , V_104 , V_36 ) ;
#endif
V_104 -> V_36 = F_9 ( V_35 , V_36 ) ;
V_104 -> null . V_27 = NULL ;
V_104 -> null . V_53 = & V_104 -> null ;
V_104 -> null . V_54 = & V_104 -> null ;
V_104 -> V_15 = 0 ;
return V_104 ;
}
extern void F_58 ( T_17 * V_105 , T_10 * V_27 ) {
T_18 * V_59 = ( T_18 * ) F_11 ( V_39 ) ;
#ifdef F_25
F_1 ( V_34 , 3 , V_29 , L_41 , V_59 ) ;
#endif
V_59 -> V_27 = V_27 ;
V_59 -> V_53 = & V_105 -> null ;
V_59 -> V_54 = V_105 -> null . V_54 ;
V_105 -> null . V_54 -> V_53 = V_59 ;
V_105 -> null . V_54 = V_59 ;
V_105 -> V_15 ++ ;
}
extern T_10 * F_59 ( T_17 * V_105 ) {
T_18 * V_59 ;
T_10 * V_27 ;
#ifdef F_25
F_1 ( V_34 , 3 , V_29 , L_42 , V_105 -> V_36 ) ;
#endif
V_59 = V_105 -> null . V_53 ;
V_105 -> null . V_53 -> V_53 -> V_54 = & V_105 -> null ;
V_105 -> null . V_53 = V_59 -> V_53 ;
V_105 -> V_15 -- ;
V_27 = V_59 -> V_27 ;
if ( V_27 ) {
F_19 ( V_39 , ( V_39 * ) V_59 ) ;
#ifdef F_25
F_1 ( V_34 , 3 , V_29 , L_43 , V_27 -> V_36 ) ;
F_1 ( V_34 , 3 , V_29 , L_44 , V_59 ) ;
#endif
}
return V_27 ;
}
extern T_10 * F_60 ( T_17 * V_105 ) {
T_18 * V_59 ;
T_10 * V_27 ;
V_59 = V_105 -> null . V_54 ;
V_105 -> null . V_54 -> V_54 -> V_53 = & V_105 -> null ;
V_105 -> null . V_54 = V_59 -> V_54 ;
V_105 -> V_15 -- ;
V_27 = V_59 -> V_27 ;
if ( V_27 ) {
F_19 ( V_39 , ( V_39 * ) V_59 ) ;
#ifdef F_25
F_1 ( V_34 , 3 , V_29 , L_44 , V_59 ) ;
#endif
}
return V_27 ;
}
extern T_10 * F_61 ( T_17 * V_105 , void * * V_56 ) {
T_18 * V_59 ;
#ifdef F_25
F_1 ( V_34 , 3 , V_29 , L_45 , V_105 , * V_56 ) ;
#endif
if ( * V_56 ) {
V_59 = ( T_18 * ) * V_56 ;
} else {
V_59 = V_105 -> null . V_53 ;
}
* V_56 = V_59 -> V_53 ;
return V_59 -> V_27 ;
}
extern void F_62 ( T_17 * V_105 , T_11 V_106 , T_11 V_60 ) {
T_10 * V_27 ;
#ifdef F_25
F_1 ( V_34 , 3 , V_29 , L_46 , V_105 ) ;
#endif
while( ( V_27 = F_60 ( V_105 ) ) ) {
if ( V_106 ) {
F_36 ( V_27 , V_60 ) ;
}
}
F_16 ( V_35 , V_105 -> V_36 ) ;
F_19 ( V_39 , ( V_39 * ) V_105 ) ;
}
static T_17 * F_63 ( T_2 * V_23 , T_17 * V_105 , T_10 * V_57 , int V_107 , const T_3 * V_4 , ... ) {
T_4 V_7 ;
T_3 * V_108 ;
T_17 * V_109 = NULL ;
T_3 * V_110 ;
va_start ( V_7 , V_4 ) ;
V_108 = F_64 ( V_4 , V_7 ) ;
va_end ( V_7 ) ;
V_110 = F_65 ( L_47 , V_105 -> V_36 , V_107 , V_108 ) ;
V_109 = F_57 ( V_110 ) ;
F_42 ( V_108 ) ;
F_42 ( V_110 ) ;
if ( V_23 ) fclose ( V_23 ) ;
if ( V_105 ) F_62 ( V_105 , TRUE , TRUE ) ;
if ( V_57 ) F_36 ( V_57 , TRUE ) ;
return V_109 ;
}
extern T_17 * F_66 ( T_3 * V_111 ) {
T_2 * V_23 = NULL ;
T_3 V_8 ;
int V_73 = 0 ;
V_50 V_107 = 1 ;
T_3 V_112 [ V_113 ] ;
T_3 V_36 [ V_113 ] ;
T_3 V_40 [ V_113 ] ;
T_3 V_71 = '?' ;
T_17 * V_105 = F_57 ( V_111 ) ;
T_10 * V_57 = NULL ;
T_8 * V_25 ;
enum T_19 {
V_114 ,
V_115 ,
V_116 ,
V_117 ,
V_118
} V_119 ;
#ifndef F_67
if ( ! F_68 () ) {
return F_63 ( V_23 , V_105 , V_57 , V_107 , L_48 ) ;
}
#endif
V_119 = V_114 ;
if ( ( V_23 = F_69 ( V_111 , L_49 ) ) ) {
while( ( V_8 = ( T_3 ) fgetc ( V_23 ) ) ) {
if ( feof ( V_23 ) ) {
if ( ferror ( V_23 ) ) {
F_70 ( V_111 , V_120 ) ;
return F_63 ( V_23 , V_105 , V_57 , V_107 , L_50 , V_111 ) ;
}
break;
}
if ( V_8 == '\n' ) {
V_107 ++ ;
}
if ( V_73 >= V_113 - 1 ) {
return F_63 ( V_23 , V_105 , V_57 , V_107 , L_51 ) ;
}
switch( V_119 ) {
case V_118 :
switch ( V_8 ) {
case '\n' :
V_119 = V_114 ;
V_73 = 0 ;
continue;
default:
continue;
}
case V_114 :
switch ( V_8 ) {
case ' ' : case '\t' :
continue;
case '\n' :
V_73 = 0 ;
continue;
case V_121 :
V_119 = V_116 ;
V_73 = 0 ;
V_36 [ V_73 ++ ] = V_8 ;
V_36 [ V_73 ] = '\0' ;
F_71 ( V_112 , sizeof( V_112 ) , L_52 , V_111 , V_107 ) ;
V_57 = F_29 ( V_112 ) ;
continue;
case '#' :
V_119 = V_118 ;
continue;
default:
return F_63 ( V_23 , V_105 , V_57 , V_107 , L_53 , V_8 ) ;
}
case V_115 :
V_73 = 0 ;
V_36 [ 0 ] = '\0' ;
switch ( V_8 ) {
case '\\' :
V_8 = ( T_3 ) fgetc ( V_23 ) ;
if ( V_8 != '\n' ) ungetc ( V_8 , V_23 ) ;
continue;
case ' ' :
case '\t' :
continue;
case V_121 :
V_119 = V_116 ;
V_36 [ V_73 ++ ] = V_8 ;
V_36 [ V_73 ] = '\0' ;
continue;
case '\n' :
F_58 ( V_105 , V_57 ) ;
V_119 = V_114 ;
continue;
default:
return F_63 ( V_23 , V_105 , V_57 , V_107 , L_53 , V_8 ) ;
}
case V_116 :
switch ( V_8 ) {
case ';' :
V_119 = V_115 ;
V_71 = '?' ;
V_36 [ V_73 ] = '\0' ;
V_40 [ 0 ] = '\0' ;
V_73 = 0 ;
V_25 = F_26 ( V_36 , V_40 , V_71 ) ;
if ( ! F_31 ( V_57 , V_25 ) ) {
F_27 ( V_25 ) ;
}
continue;
case V_122 :
V_36 [ V_73 ] = '\0' ;
V_73 = 0 ;
V_71 = V_8 ;
V_119 = V_117 ;
continue;
case V_121 :
V_36 [ V_73 ++ ] = V_8 ;
continue;
case '\n' :
return F_63 ( V_23 , V_105 , V_57 , V_107 , L_54 ) ;
default:
return F_63 ( V_23 , V_105 , V_57 , V_107 , L_55 , V_8 ) ;
}
case V_117 :
switch ( V_8 ) {
case '\\' :
V_40 [ V_73 ++ ] = ( T_3 ) fgetc ( V_23 ) ;
continue;
case ';' :
V_119 = V_115 ;
V_40 [ V_73 ] = '\0' ;
V_73 = 0 ;
V_25 = F_26 ( V_36 , V_40 , V_71 ) ;
if ( ! F_31 ( V_57 , V_25 ) ) {
F_27 ( V_25 ) ;
}
continue;
case '\n' :
return F_63 ( V_23 , V_105 , V_57 , V_107 , L_56 ) ;
default:
V_40 [ V_73 ++ ] = V_8 ;
continue;
}
}
}
fclose ( V_23 ) ;
return V_105 ;
} else {
F_72 ( V_111 , V_120 , FALSE ) ;
return F_63 ( NULL , V_105 , NULL , 0 , L_57 , V_111 ) ;
}
}
