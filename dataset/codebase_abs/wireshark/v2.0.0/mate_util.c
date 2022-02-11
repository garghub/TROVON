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
V_41 = F_24 ( & V_37 -> V_40 , V_43 , V_37 -> V_44 -> V_45 , NULL ) ;
if ( V_41 ) {
V_40 = F_9 ( V_35 , V_41 ) ;
F_25 ( V_41 ) ;
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
extern T_11 F_32 ( T_10 * V_27 , T_8 * V_25 ) {
T_12 * V_38 = ( T_12 * ) F_11 ( V_39 ) ;
T_12 * V_8 ;
V_38 -> V_25 = V_25 ;
#ifdef F_26
F_1 ( V_34 , 7 , V_29 , L_13 , V_38 ) ;
F_1 ( V_34 , 4 , V_29 , L_14 , V_27 , V_25 , V_25 -> V_42 , V_25 -> V_48 , V_25 -> V_47 ) ;
#endif
for( V_8 = V_27 -> null . V_52 ; V_8 -> V_25 ; V_8 = V_8 -> V_52 ) {
if ( V_25 -> V_42 == V_8 -> V_25 -> V_42 ) {
if ( V_25 -> V_47 > V_8 -> V_25 -> V_47 ) {
break;
}
if ( V_25 -> V_47 == V_8 -> V_25 -> V_47 ) {
if ( V_25 -> V_48 == V_54 ) {
#ifdef F_26
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
#ifdef F_26
F_1 ( V_33 , 5 , V_29 , L_16 , V_25 , V_27 , V_8 ) ;
#endif
V_38 -> V_52 = V_8 ;
V_38 -> V_53 = V_8 -> V_53 ;
V_8 -> V_53 -> V_52 = V_38 ;
V_8 -> V_53 = V_38 ;
V_27 -> V_15 ++ ;
#ifdef F_26
F_1 ( V_33 , 4 , V_29 , L_17 , V_27 , V_27 -> V_15 ) ;
#endif
return TRUE ;
}
extern T_8 * F_33 ( T_10 * V_27 , T_3 * V_36 , void * * V_55 ) {
T_12 * V_56 ;
T_12 * V_57 = ( T_12 * ) * V_55 ;
#ifdef F_26
F_1 ( V_34 , 7 , V_29 , L_18 , V_27 , V_36 , * V_55 ) ;
#endif
V_36 = F_9 ( V_35 , V_36 ) ;
if ( ! V_57 ) V_57 = V_27 -> null . V_52 ;
for ( V_56 = V_57 ; V_56 -> V_25 ; V_56 = V_56 -> V_52 ) {
if ( V_56 -> V_25 -> V_42 == V_36 ) {
break;
}
}
* V_55 = V_56 ;
#ifdef F_26
F_1 ( V_34 , 5 , V_29 , L_19 , V_56 ) ;
#endif
F_16 ( V_35 , V_36 ) ;
return V_56 -> V_25 ;
}
extern T_8 * F_34 ( T_10 * V_27 , T_3 * V_36 ) {
T_12 * V_56 ;
T_8 * V_25 = NULL ;
#ifdef F_26
F_1 ( V_34 , 7 , V_29 , L_20 , V_27 , V_36 ) ;
#endif
V_36 = F_9 ( V_35 , V_36 ) ;
for ( V_56 = V_27 -> null . V_52 ; V_56 -> V_25 ; V_56 = V_56 -> V_52 ) {
if ( V_56 -> V_25 -> V_42 == V_36 ) {
break;
}
}
F_16 ( V_35 , V_36 ) ;
if( ! V_56 -> V_25 ) return NULL ;
V_56 -> V_52 -> V_53 = V_56 -> V_53 ;
V_56 -> V_53 -> V_52 = V_56 -> V_52 ;
V_25 = V_56 -> V_25 ;
F_19 ( V_39 , ( V_39 * ) V_56 ) ;
( V_27 -> V_15 ) -- ;
#ifdef F_26
F_1 ( V_33 , 4 , V_29 , L_17 , V_27 , V_27 -> V_15 ) ;
#endif
#ifdef F_26
F_1 ( V_34 , 5 , V_29 , L_21 , V_25 ) ;
#endif
return V_25 ;
}
extern T_8 * F_35 ( T_10 * V_27 ) {
T_8 * V_25 ;
T_12 * V_58 ;
#ifdef F_26
F_1 ( V_34 , 7 , V_29 , L_22 , V_27 ) ;
#endif
V_58 = V_27 -> null . V_52 ;
V_27 -> null . V_52 -> V_53 = & V_27 -> null ;
V_27 -> null . V_52 = V_58 -> V_52 ;
V_25 = V_58 -> V_25 ;
if ( V_25 ) {
F_19 ( V_39 , ( V_39 * ) V_58 ) ;
( V_27 -> V_15 ) -- ;
#ifdef F_26
F_1 ( V_33 , 4 , V_29 , L_17 , V_27 , V_27 -> V_15 ) ;
#endif
}
#ifdef F_26
F_1 ( V_34 , 5 , V_29 , L_23 , V_25 ) ;
#endif
return V_25 ;
}
extern T_8 * F_36 ( T_10 * V_27 ) {
T_8 * V_25 ;
T_12 * V_58 ;
V_58 = V_27 -> null . V_53 ;
V_27 -> null . V_53 -> V_52 = & V_27 -> null ;
V_27 -> null . V_53 = V_58 -> V_53 ;
V_25 = V_58 -> V_25 ;
if ( V_25 ) {
F_19 ( V_39 , ( V_39 * ) V_58 ) ;
( V_27 -> V_15 ) -- ;
#ifdef F_26
F_1 ( V_33 , 4 , V_29 , L_17 , V_27 , V_27 -> V_15 ) ;
#endif
}
#ifdef F_26
F_1 ( V_34 , 5 , V_29 , L_24 , V_25 ) ;
#endif
return V_25 ;
}
extern void F_37 ( T_10 * V_27 , T_11 V_59 ) {
T_8 * V_25 ;
#ifdef F_26
F_1 ( V_33 , 3 , V_29 , L_25 , V_27 ) ;
#endif
while( ( V_25 = F_36 ( V_27 ) ) ) {
if ( V_59 ) {
F_28 ( V_25 ) ;
}
}
F_16 ( V_35 , V_27 -> V_36 ) ;
F_19 ( V_39 , ( V_39 * ) V_27 ) ;
}
extern T_8 * F_38 ( T_10 * V_27 , void * * V_55 ) {
T_12 * V_58 ;
#ifdef F_26
F_1 ( V_34 , 5 , V_29 , L_26 , V_27 , * V_55 ) ;
#endif
if ( * V_55 ) {
V_58 = ( T_12 * ) * V_55 ;
} else {
V_58 = V_27 -> null . V_52 ;
}
* V_55 = V_58 -> V_52 ;
#ifdef F_26
F_1 ( V_34 , 5 , V_29 , L_24 , V_58 -> V_25 ) ;
#endif
return V_58 -> V_25 ;
}
T_3 * F_39 ( T_10 * V_27 ) {
T_12 * V_8 ;
T_13 * V_12 = F_40 ( L_7 ) ;
T_3 * V_60 ;
T_3 * V_61 ;
for( V_8 = V_27 -> null . V_52 ; V_8 -> V_25 ; V_8 = V_8 -> V_52 ) {
V_60 = F_41 ( V_8 -> V_25 ) ;
F_42 ( V_12 , L_27 , V_60 ) ;
F_25 ( V_60 ) ;
}
V_61 = F_43 ( V_12 , FALSE ) ;
return V_61 ;
}
extern T_3 * F_44 ( T_10 * V_27 ) {
T_12 * V_8 ;
T_13 * V_12 = F_40 ( L_7 ) ;
T_3 * V_60 ;
T_3 * V_61 ;
for( V_8 = V_27 -> null . V_52 ; V_8 -> V_25 ; V_8 = V_8 -> V_52 ) {
V_60 = F_41 ( V_8 -> V_25 ) ;
F_42 ( V_12 , L_28 , V_60 ) ;
F_25 ( V_60 ) ;
}
V_61 = F_43 ( V_12 , FALSE ) ;
return V_61 ;
}
extern void F_45 ( T_10 * V_62 , T_10 * V_63 , T_11 V_64 ) {
T_12 * V_65 = NULL ;
T_12 * V_66 = NULL ;
T_14 V_8 ;
T_8 * V_67 ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_29 , V_62 , V_63 ) ;
#endif
V_66 = V_63 -> null . V_52 ;
V_65 = V_62 -> null . V_52 ;
while( V_66 -> V_25 ) {
if( V_65 -> V_25 ) {
V_8 = F_46 ( V_65 -> V_25 -> V_42 , V_66 -> V_25 -> V_42 ) ;
} else {
V_8 = - 1 ;
}
if ( V_8 > 0 ) {
if ( V_65 -> V_25 ) V_65 = V_65 -> V_52 ;
} else if ( V_8 < 0 ) {
if ( V_64 ) {
V_67 = F_29 ( V_66 -> V_25 ) ;
if ( ! F_32 ( V_62 , V_67 ) ) {
F_28 ( V_67 ) ;
}
} else {
F_32 ( V_62 , V_66 -> V_25 ) ;
}
V_66 = V_66 -> V_52 ;
} else {
if ( ! V_65 -> V_25 || ! ( V_65 -> V_25 -> V_47 == V_66 -> V_25 -> V_47 ) ) {
if ( V_64 ) {
V_67 = F_29 ( V_66 -> V_25 ) ;
if ( ! F_32 ( V_62 , V_67 ) ) {
F_28 ( V_67 ) ;
}
} else {
F_32 ( V_62 , V_66 -> V_25 ) ;
}
}
V_66 = V_66 -> V_52 ;
if ( V_65 -> V_25 ) V_65 = V_65 -> V_52 ;
}
}
#ifdef F_26
F_1 ( V_34 , 8 , V_29 , L_30 ) ;
#endif
return;
}
extern T_10 * F_47 ( const T_3 * V_36 , T_10 * V_27 , T_11 V_64 ) {
T_10 * V_68 = F_30 ( V_36 ) ;
void * V_55 = NULL ;
T_8 * V_25 ;
T_8 * V_67 ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_31 , V_68 , V_27 , V_36 ) ;
#endif
while( ( V_25 = F_38 ( V_27 , & V_55 ) ) ) {
if ( V_64 ) {
V_67 = F_29 ( V_25 ) ;
if ( ! F_32 ( V_68 , V_67 ) ) {
F_28 ( V_67 ) ;
}
} else {
F_32 ( V_68 , V_25 ) ;
}
}
#ifdef F_26
F_1 ( V_34 , 8 , V_29 , L_32 ) ;
#endif
return V_68 ;
}
extern T_8 * F_48 ( T_8 * V_63 , T_8 * V_69 ) {
T_3 * * V_70 ;
int V_71 ;
T_3 * V_72 ;
T_6 V_73 ;
T_6 V_74 ;
float V_75 = 0.0f ;
float V_76 = 0.0f ;
T_11 V_77 = FALSE ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_33 , V_63 -> V_42 , V_63 -> V_48 , V_63 -> V_47 , V_69 -> V_42 , V_69 -> V_48 , V_69 -> V_47 ) ;
#endif
if ( V_63 -> V_42 != V_69 -> V_42 ) {
return NULL ;
}
switch ( V_69 -> V_48 ) {
case V_78 :
return V_63 ;
case V_54 :
return V_63 -> V_47 == V_69 -> V_47 ? V_63 : NULL ;
case V_79 :
return ! ( V_63 -> V_47 == V_69 -> V_47 ) ? V_63 : NULL ;
case V_80 :
return strncmp ( V_63 -> V_47 , V_69 -> V_47 , strlen ( V_69 -> V_47 ) ) == 0 ? V_63 : NULL ;
case V_81 :
V_70 = F_49 ( V_69 -> V_47 , L_34 , 0 ) ;
if ( V_70 ) {
for ( V_71 = 0 ; V_70 [ V_71 ] ; V_71 ++ ) {
if( V_11 ( V_70 [ V_71 ] , V_63 -> V_47 ) ) {
F_50 ( V_70 ) ;
return V_63 ;
}
}
F_50 ( V_70 ) ;
}
return NULL ;
case V_82 :
V_77 = TRUE ;
case V_83 :
V_75 = ( float ) F_51 ( V_63 -> V_47 , NULL ) ;
V_76 = ( float ) F_51 ( V_69 -> V_47 , NULL ) ;
if ( V_77 ) {
if ( V_75 < V_76 ) return V_63 ;
else return NULL ;
} else {
if ( V_75 > V_76 ) return V_63 ;
else return NULL ;
}
case V_84 :
V_73 = ( T_6 ) strlen ( V_63 -> V_47 ) ;
V_74 = ( T_6 ) strlen ( V_69 -> V_47 ) ;
if ( V_73 < V_74 ) {
return NULL ;
} else {
V_72 = V_63 -> V_47 + ( V_73 - V_74 ) ;
return V_11 ( V_72 , V_69 -> V_47 ) ? V_63 : NULL ;
}
case V_85 :
return F_52 ( V_63 -> V_47 , V_69 -> V_47 ) ? V_63 : NULL ; ;
}
return NULL ;
}
extern T_10 * F_53 ( const T_3 * V_36 ,
T_10 * V_63 ,
T_10 * V_69 ,
T_11 V_64 ) {
T_10 * V_68 = F_30 ( F_9 ( V_35 , V_36 ) ) ;
T_12 * V_86 = NULL ;
T_12 * V_66 = NULL ;
T_14 V_8 ;
T_8 * V_87 ;
T_8 * V_67 ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_35 , V_68 , V_63 , V_69 , V_36 ) ;
#endif
V_66 = V_63 -> null . V_52 ;
V_86 = V_69 -> null . V_52 ;
while( 1 ) {
if ( ! V_86 -> V_25 ) {
return V_68 ;
}
if ( ! V_66 -> V_25 ) {
return V_68 ;
}
V_8 = F_46 ( V_86 -> V_25 -> V_42 , V_66 -> V_25 -> V_42 ) ;
if ( V_8 > 0 ) {
if ( V_86 -> V_25 ) V_86 = V_86 -> V_52 ;
} else if ( V_8 < 0 ) {
if ( V_66 -> V_25 ) V_66 = V_66 -> V_52 ;
} else {
V_87 = F_48 ( V_66 -> V_25 , V_86 -> V_25 ) ;
if( V_87 ) {
if ( V_64 ) {
V_67 = F_29 ( V_87 ) ;
if ( ! F_32 ( V_68 , V_67 ) ) {
F_28 ( V_67 ) ;
}
} else {
F_32 ( V_68 , V_87 ) ;
}
}
if ( V_66 -> V_25 ) V_66 = V_66 -> V_52 ;
}
}
#ifdef F_26
F_1 ( V_34 , 6 , V_29 , L_36 ) ;
#endif
return NULL ;
}
extern T_10 * F_54 ( const T_3 * V_36 , T_10 * V_63 , T_10 * V_69 , T_11 V_64 ) {
T_10 * V_68 ;
T_12 * V_86 = NULL ;
T_12 * V_66 = NULL ;
T_14 V_8 ;
T_8 * V_87 ;
T_8 * V_67 ;
T_11 V_88 ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_37 , V_68 , V_63 , V_69 , V_36 ) ;
#endif
if ( V_63 -> V_15 == 0 ) return NULL ;
V_68 = F_30 ( F_9 ( V_35 , V_36 ) ) ;
if ( V_69 -> V_15 == 0 )
return V_68 ;
V_88 = TRUE ;
V_66 = V_63 -> null . V_52 ;
V_86 = V_69 -> null . V_52 ;
while( 1 ) {
if ( ! V_86 -> V_25 ) {
break;
}
if ( ! V_66 -> V_25 ) {
break;
}
V_8 = F_46 ( V_86 -> V_25 -> V_42 , V_66 -> V_25 -> V_42 ) ;
if ( V_8 > 0 ) {
F_37 ( V_68 , TRUE ) ;
return NULL ;
} else if ( V_8 < 0 ) {
V_66 = V_66 -> V_52 ;
if ( ! V_66 -> V_25 ) {
break;
}
} else {
V_87 = F_48 ( V_66 -> V_25 , V_86 -> V_25 ) ;
if( V_87 ) {
V_88 ++ ;
V_66 = V_66 -> V_52 ;
V_86 = V_86 -> V_52 ;
if ( V_64 ) {
V_67 = F_29 ( V_87 ) ;
if ( ! F_32 ( V_68 , V_67 ) ) {
F_28 ( V_67 ) ;
}
} else {
F_32 ( V_68 , V_87 ) ;
}
} else {
V_66 = V_66 -> V_52 ;
}
}
}
if ( V_88 ) {
return V_68 ;
} else {
F_37 ( V_68 , TRUE ) ;
return NULL ;
}
}
extern T_10 * F_55 ( const T_3 * V_36 , T_10 * V_63 , T_10 * V_69 , T_11 V_64 ) {
T_10 * V_68 = F_30 ( V_36 ) ;
T_12 * V_86 = NULL ;
T_12 * V_66 = NULL ;
T_14 V_8 ;
T_8 * V_87 ;
T_8 * V_67 ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_37 , V_68 , V_63 , V_69 , V_36 ) ;
#endif
if ( V_69 -> V_15 == 0 )
return V_68 ;
if ( V_63 -> V_15 == 0 ) {
F_37 ( V_68 , FALSE ) ;
return NULL ;
}
V_66 = V_63 -> null . V_52 ;
V_86 = V_69 -> null . V_52 ;
while( 1 ) {
V_8 = F_46 ( V_86 -> V_25 -> V_42 , V_66 -> V_25 -> V_42 ) ;
if ( V_8 > 0 ) {
F_37 ( V_68 , TRUE ) ;
return NULL ;
} else if ( V_8 < 0 ) {
V_66 = V_66 -> V_52 ;
if ( ! V_66 -> V_25 ) {
F_37 ( V_68 , TRUE ) ;
return NULL ;
}
} else {
V_87 = F_48 ( V_66 -> V_25 , V_86 -> V_25 ) ;
if( V_87 ) {
V_66 = V_66 -> V_52 ;
V_86 = V_86 -> V_52 ;
if ( V_64 ) {
V_67 = F_29 ( V_87 ) ;
if ( ! F_32 ( V_68 , V_67 ) ) {
F_28 ( V_67 ) ;
}
} else {
F_32 ( V_68 , V_87 ) ;
}
if ( ! V_86 -> V_25 ) {
return V_68 ;
}
if ( ! V_66 -> V_25 ) {
F_37 ( V_68 , TRUE ) ;
return NULL ;
}
} else {
F_37 ( V_68 , TRUE ) ;
return NULL ;
}
}
}
return NULL ;
}
extern T_10 * F_56 ( T_15 V_89 , const T_3 * V_36 , T_10 * V_63 , T_10 * V_69 , T_11 V_64 ) {
T_10 * V_27 = NULL ;
switch ( V_89 ) {
case V_90 :
V_27 = F_55 ( V_36 , V_63 , V_69 , V_64 ) ;
break;
case V_91 :
V_27 = F_53 ( V_36 , V_63 , V_69 , V_64 ) ;
break;
case V_92 :
V_27 = F_54 ( V_36 , V_63 , V_69 , V_64 ) ;
break;
case V_93 :
V_27 = F_47 ( V_36 , V_63 , V_64 ) ;
F_45 ( V_27 , V_69 , V_64 ) ;
break;
}
return V_27 ;
}
extern void F_57 ( T_16 * V_69 ) {
T_16 * V_52 ;
for (; V_69 ; V_69 = V_52 ) {
V_52 = V_69 -> V_52 ;
F_25 ( V_69 -> V_36 ) ;
if ( V_69 -> V_94 ) {
F_37 ( V_69 -> V_94 , TRUE ) ;
}
if ( V_69 -> V_95 ) {
F_37 ( V_69 -> V_95 , TRUE ) ;
}
F_25 ( V_69 ) ;
}
}
extern void F_58 ( T_10 * V_63 , T_16 * V_69 ) {
T_10 * V_27 = NULL ;
T_12 * V_66 ;
T_12 * V_96 ;
T_12 * V_42 ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_38 , V_63 , V_69 ) ;
#endif
for ( ; V_69 ; V_69 = V_69 -> V_52 ) {
V_27 = F_56 ( V_69 -> V_97 , V_63 -> V_36 , V_63 , V_69 -> V_94 , TRUE ) ;
if ( V_27 ) {
switch ( V_69 -> V_98 ) {
case V_99 :
F_37 ( V_27 , TRUE ) ;
return;
case V_100 :
F_45 ( V_63 , V_69 -> V_95 , TRUE ) ;
F_37 ( V_27 , TRUE ) ;
return;
case V_101 :
V_66 = V_63 -> null . V_52 ;
V_96 = V_27 -> null . V_52 ;
while( V_66 -> V_25 ) {
if ( V_96 -> V_25 && V_66 -> V_25 -> V_42 == V_96 -> V_25 -> V_42 && V_66 -> V_25 -> V_47 == V_96 -> V_25 -> V_47 ) {
V_42 = V_66 -> V_52 ;
V_66 -> V_53 -> V_52 = V_66 -> V_52 ;
V_66 -> V_52 -> V_53 = V_66 -> V_53 ;
F_19 ( V_39 , ( V_39 * ) V_66 ) ;
V_66 = V_42 ;
V_96 = V_96 -> V_52 ;
} else {
V_66 = V_66 -> V_52 ;
}
}
F_45 ( V_63 , V_69 -> V_95 , TRUE ) ;
F_37 ( V_27 , TRUE ) ;
return;
}
}
}
}
extern T_17 * F_59 ( const T_3 * V_36 ) {
T_17 * V_102 = ( T_17 * ) F_11 ( V_39 ) ;
if ( ! V_36 ) {
V_36 = L_39 ;
}
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_40 , V_102 , V_36 ) ;
#endif
V_102 -> V_36 = F_9 ( V_35 , V_36 ) ;
V_102 -> null . V_27 = NULL ;
V_102 -> null . V_52 = & V_102 -> null ;
V_102 -> null . V_53 = & V_102 -> null ;
V_102 -> V_15 = 0 ;
return V_102 ;
}
extern void F_60 ( T_17 * V_103 , T_10 * V_27 ) {
T_18 * V_58 = ( T_18 * ) F_11 ( V_39 ) ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_41 , V_58 ) ;
#endif
V_58 -> V_27 = V_27 ;
V_58 -> V_52 = & V_103 -> null ;
V_58 -> V_53 = V_103 -> null . V_53 ;
V_103 -> null . V_53 -> V_52 = V_58 ;
V_103 -> null . V_53 = V_58 ;
V_103 -> V_15 ++ ;
}
extern T_10 * F_61 ( T_17 * V_103 ) {
T_18 * V_58 ;
T_10 * V_27 ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_42 , V_103 -> V_36 ) ;
#endif
V_58 = V_103 -> null . V_52 ;
V_103 -> null . V_52 -> V_52 -> V_53 = & V_103 -> null ;
V_103 -> null . V_52 = V_58 -> V_52 ;
V_103 -> V_15 -- ;
V_27 = V_58 -> V_27 ;
if ( V_27 ) {
F_19 ( V_39 , ( V_39 * ) V_58 ) ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_43 , V_27 -> V_36 ) ;
F_1 ( V_34 , 3 , V_29 , L_44 , V_58 ) ;
#endif
}
return V_27 ;
}
extern T_10 * F_62 ( T_17 * V_103 ) {
T_18 * V_58 ;
T_10 * V_27 ;
V_58 = V_103 -> null . V_53 ;
V_103 -> null . V_53 -> V_53 -> V_52 = & V_103 -> null ;
V_103 -> null . V_53 = V_58 -> V_53 ;
V_103 -> V_15 -- ;
V_27 = V_58 -> V_27 ;
if ( V_27 ) {
F_19 ( V_39 , ( V_39 * ) V_58 ) ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_44 , V_58 ) ;
#endif
}
return V_27 ;
}
extern T_10 * F_63 ( T_17 * V_103 , void * * V_55 ) {
T_18 * V_58 ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_45 , V_103 , * V_55 ) ;
#endif
if ( * V_55 ) {
V_58 = ( T_18 * ) * V_55 ;
} else {
V_58 = V_103 -> null . V_52 ;
}
* V_55 = V_58 -> V_52 ;
return V_58 -> V_27 ;
}
extern void F_64 ( T_17 * V_103 , T_11 V_104 , T_11 V_59 ) {
T_10 * V_27 ;
#ifdef F_26
F_1 ( V_34 , 3 , V_29 , L_46 , V_103 ) ;
#endif
while( ( V_27 = F_62 ( V_103 ) ) ) {
if ( V_104 ) {
F_37 ( V_27 , V_59 ) ;
}
}
F_16 ( V_35 , V_103 -> V_36 ) ;
F_19 ( V_39 , ( V_39 * ) V_103 ) ;
}
static T_17 * F_65 ( T_2 * V_23 , T_17 * V_103 , T_10 * V_56 , int V_105 , const T_3 * V_4 , ... ) {
T_4 V_7 ;
T_3 * V_106 ;
T_17 * V_107 = NULL ;
T_3 * V_108 ;
va_start ( V_7 , V_4 ) ;
V_106 = F_66 ( V_4 , V_7 ) ;
va_end ( V_7 ) ;
V_108 = F_67 ( L_47 , V_103 -> V_36 , V_105 , V_106 ) ;
V_107 = F_59 ( V_108 ) ;
F_25 ( V_106 ) ;
F_25 ( V_108 ) ;
if ( V_23 ) fclose ( V_23 ) ;
if ( V_103 ) F_64 ( V_103 , TRUE , TRUE ) ;
if ( V_56 ) F_37 ( V_56 , TRUE ) ;
return V_107 ;
}
extern T_17 * F_68 ( T_3 * V_109 ) {
T_2 * V_23 = NULL ;
T_3 V_8 ;
int V_71 = 0 ;
V_49 V_105 = 1 ;
T_3 V_110 [ V_111 ] ;
T_3 V_36 [ V_111 ] ;
T_3 V_40 [ V_111 ] ;
T_3 V_69 = '?' ;
T_17 * V_103 = F_59 ( V_109 ) ;
T_10 * V_56 = NULL ;
T_8 * V_25 ;
enum T_19 {
V_112 ,
V_113 ,
V_114 ,
V_115 ,
V_116
} V_117 ;
#ifndef F_69
if ( ! F_70 () ) {
return F_65 ( V_23 , V_103 , V_56 , V_105 , L_48 ) ;
}
#endif
V_117 = V_112 ;
if ( ( V_23 = F_71 ( V_109 , L_49 ) ) ) {
while( ( V_8 = ( T_3 ) fgetc ( V_23 ) ) ) {
if ( feof ( V_23 ) ) {
if ( ferror ( V_23 ) ) {
F_72 ( V_109 , V_118 ) ;
return F_65 ( V_23 , V_103 , V_56 , V_105 , L_50 , V_109 ) ;
}
break;
}
if ( V_8 == '\n' ) {
V_105 ++ ;
}
if ( V_71 >= V_111 - 1 ) {
return F_65 ( V_23 , V_103 , V_56 , V_105 , L_51 ) ;
}
switch( V_117 ) {
case V_116 :
switch ( V_8 ) {
case '\n' :
V_117 = V_112 ;
V_71 = 0 ;
continue;
default:
continue;
}
case V_112 :
switch ( V_8 ) {
case ' ' : case '\t' :
continue;
case '\n' :
V_71 = 0 ;
continue;
case V_119 :
V_117 = V_114 ;
V_71 = 0 ;
V_36 [ V_71 ++ ] = V_8 ;
V_36 [ V_71 ] = '\0' ;
F_73 ( V_110 , sizeof( V_110 ) , L_52 , V_109 , V_105 ) ;
V_56 = F_30 ( V_110 ) ;
continue;
case '#' :
V_117 = V_116 ;
continue;
default:
return F_65 ( V_23 , V_103 , V_56 , V_105 , L_53 , V_8 ) ;
}
case V_113 :
V_71 = 0 ;
V_36 [ 0 ] = '\0' ;
switch ( V_8 ) {
case '\\' :
V_8 = ( T_3 ) fgetc ( V_23 ) ;
if ( V_8 != '\n' ) ungetc ( V_8 , V_23 ) ;
continue;
case ' ' :
case '\t' :
continue;
case V_119 :
V_117 = V_114 ;
V_36 [ V_71 ++ ] = V_8 ;
V_36 [ V_71 ] = '\0' ;
continue;
case '\n' :
F_60 ( V_103 , V_56 ) ;
V_117 = V_112 ;
continue;
default:
return F_65 ( V_23 , V_103 , V_56 , V_105 , L_53 , V_8 ) ;
}
case V_114 :
switch ( V_8 ) {
case ';' :
V_117 = V_113 ;
V_69 = '?' ;
V_36 [ V_71 ] = '\0' ;
V_40 [ 0 ] = '\0' ;
V_71 = 0 ;
V_25 = F_27 ( V_36 , V_40 , V_69 ) ;
if ( ! F_32 ( V_56 , V_25 ) ) {
F_28 ( V_25 ) ;
}
continue;
case V_120 :
V_36 [ V_71 ] = '\0' ;
V_71 = 0 ;
V_69 = V_8 ;
V_117 = V_115 ;
continue;
case V_119 :
V_36 [ V_71 ++ ] = V_8 ;
continue;
case '\n' :
return F_65 ( V_23 , V_103 , V_56 , V_105 , L_54 ) ;
default:
return F_65 ( V_23 , V_103 , V_56 , V_105 , L_55 , V_8 ) ;
}
case V_115 :
switch ( V_8 ) {
case '\\' :
V_40 [ V_71 ++ ] = ( T_3 ) fgetc ( V_23 ) ;
continue;
case ';' :
V_117 = V_113 ;
V_40 [ V_71 ] = '\0' ;
V_71 = 0 ;
V_25 = F_27 ( V_36 , V_40 , V_69 ) ;
if ( ! F_32 ( V_56 , V_25 ) ) {
F_28 ( V_25 ) ;
}
continue;
case '\n' :
return F_65 ( V_23 , V_103 , V_56 , V_105 , L_56 ) ;
default:
V_40 [ V_71 ++ ] = V_8 ;
continue;
}
}
}
fclose ( V_23 ) ;
return V_103 ;
} else {
F_74 ( V_109 , V_118 , FALSE ) ;
return F_65 ( NULL , V_103 , NULL , 0 , L_57 , V_109 ) ;
}
}
