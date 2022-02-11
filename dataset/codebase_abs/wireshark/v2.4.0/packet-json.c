static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_4 )
{
T_3 * V_5 = NULL ;
T_4 * V_6 = NULL ;
T_5 V_7 ;
T_6 * V_8 ;
T_7 * V_9 ;
const char * V_10 ;
int V_11 ;
T_8 * V_12 = F_2 ( F_3 ( V_2 -> V_13 ) ) ;
if ( V_12 ) {
const char * V_14 = F_4 ( F_5 ( F_6 ( V_12 ) ) ) ;
if ( ! strcmp ( V_14 , L_1 ) ) {
F_7 ( V_2 -> V_15 , V_16 , L_2 ) ;
F_7 ( V_2 -> V_15 , V_17 , L_3 ) ;
}
}
V_10 = V_2 -> V_18 ;
if ( ! ( V_10 && V_10 [ 0 ] ) ) {
V_9 = ( T_7 * ) V_4 ;
if ( V_9 == NULL ) {
V_10 = NULL ;
} else {
V_10 = V_9 -> V_19 ;
if ( ! ( V_10 && V_10 [ 0 ] ) ) {
V_10 = NULL ;
}
}
}
if ( V_3 ) {
V_6 = F_8 ( V_3 , V_20 , V_1 , 0 , - 1 , V_21 ) ;
V_5 = F_9 ( V_6 , V_22 ) ;
if ( V_10 )
F_10 ( V_6 , L_4 , V_10 ) ;
}
V_11 = 0 ;
V_7 . V_23 = F_11 ( F_12 () ) ;
F_13 ( V_7 . V_23 , V_5 ) ;
V_8 = F_14 ( V_1 , V_11 , - 1 , & V_7 , V_24 ) ;
while ( ( F_15 ( V_8 , V_25 ) ) )
;
V_11 = F_16 ( V_8 ) ;
F_17 ( V_6 , V_11 ) ;
if ( F_18 ( V_1 , V_11 ) > 0 ) {
T_1 * V_26 ;
V_26 = F_19 ( V_1 , V_11 ) ;
F_20 ( V_27 , V_26 , V_2 , V_3 , V_4 ) ;
} else if ( V_10 ) {
F_21 ( V_2 -> V_15 , V_17 , L_5 , L_6 , V_10 ) ;
}
return F_22 ( V_1 ) ;
}
static int
F_23 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_4 V_28 )
{
return F_1 ( V_1 , V_2 , V_3 , NULL ) ;
}
static void F_24 ( void * V_29 , const void * T_9 V_28 , T_10 * V_30 ) {
T_5 * V_4 = ( T_5 * ) V_29 ;
T_3 * V_3 = ( T_3 * ) F_25 ( V_4 -> V_23 ) ;
T_3 * V_31 ;
T_4 * V_6 ;
V_6 = F_8 ( V_3 , & V_32 , V_30 -> V_1 , V_30 -> V_11 , V_30 -> V_33 , V_21 ) ;
V_31 = F_9 ( V_6 , V_34 ) ;
F_13 ( V_4 -> V_23 , V_31 ) ;
}
static void F_26 ( void * V_29 , const void * T_9 V_28 , T_10 * T_11 V_28 ) {
T_5 * V_4 = ( T_5 * ) V_29 ;
F_27 ( V_4 -> V_23 ) ;
}
static void F_28 ( void * V_29 , const void * T_9 V_28 , T_10 * V_30 ) {
T_5 * V_4 = ( T_5 * ) V_29 ;
T_3 * V_3 = ( T_3 * ) F_25 ( V_4 -> V_23 ) ;
T_3 * V_31 ;
T_4 * V_6 ;
V_6 = F_8 ( V_3 , & V_35 , V_30 -> V_1 , V_30 -> V_11 , V_30 -> V_33 , V_21 ) ;
V_31 = F_9 ( V_6 , V_36 ) ;
F_13 ( V_4 -> V_23 , V_31 ) ;
}
static void F_29 ( void * V_29 , const void * T_9 V_28 , T_10 * V_30 ) {
T_5 * V_4 = ( T_5 * ) V_29 ;
T_3 * V_3 = ( T_3 * ) F_27 ( V_4 -> V_23 ) ;
if ( V_3 ) {
T_10 * V_37 = V_30 -> V_38 ;
if ( V_37 && V_37 -> V_39 == V_40 ) {
char * V_41 = F_30 ( V_37 ) ;
F_31 ( V_3 , & V_42 , V_37 -> V_1 , V_37 -> V_11 , V_37 -> V_33 , V_41 ) ;
F_10 ( V_3 , L_7 , V_41 ) ;
}
}
}
static void F_32 ( void * V_29 , const void * T_9 V_28 , T_10 * V_30 ) {
T_5 * V_4 = ( T_5 * ) V_29 ;
T_3 * V_3 = ( T_3 * ) F_25 ( V_4 -> V_23 ) ;
T_3 * V_31 ;
T_4 * V_6 ;
V_6 = F_8 ( V_3 , & V_43 , V_30 -> V_1 , V_30 -> V_11 , V_30 -> V_33 , V_21 ) ;
V_31 = F_9 ( V_6 , V_44 ) ;
F_13 ( V_4 -> V_23 , V_31 ) ;
}
static void F_33 ( void * V_29 , const void * T_9 V_28 , T_10 * T_11 V_28 ) {
T_5 * V_4 = ( T_5 * ) V_29 ;
F_27 ( V_4 -> V_23 ) ;
}
static int
F_34 ( char * V_45 , T_1 * V_1 , int V_11 , int V_46 )
{
int V_33 = F_35 ( ( V_47 ) * V_45 ) ;
if ( V_33 == - 1 || ( ( V_48 ) ( V_11 + V_33 ) ) >= ( V_48 ) V_46 ) {
* V_45 = '?' ;
return 1 ;
}
F_36 ( V_1 , V_45 + 1 , V_11 + 1 , V_33 - 1 ) ;
if ( ! F_37 ( V_45 , V_33 , NULL ) ) {
* V_45 = '?' ;
return 1 ;
}
return V_33 ;
}
static char * F_30 ( T_10 * V_30 )
{
char * V_49 = ( char * ) F_38 ( F_12 () , V_30 -> V_33 - 1 ) ;
int V_50 , V_51 ;
V_51 = 0 ;
for ( V_50 = 1 ; V_50 < V_30 -> V_33 - 1 ; V_50 ++ ) {
V_47 V_52 = F_39 ( V_30 -> V_1 , V_30 -> V_11 + V_50 ) ;
int V_53 ;
if ( V_52 == '\\' ) {
V_50 ++ ;
V_52 = F_39 ( V_30 -> V_1 , V_30 -> V_11 + V_50 ) ;
switch ( V_52 ) {
case '\"' :
case '\\' :
case '/' :
V_49 [ V_51 ++ ] = V_52 ;
break;
case 'b' :
V_49 [ V_51 ++ ] = '\b' ;
break;
case 'f' :
V_49 [ V_51 ++ ] = '\f' ;
break;
case 'n' :
V_49 [ V_51 ++ ] = '\n' ;
break;
case 'r' :
V_49 [ V_51 ++ ] = '\r' ;
break;
case 't' :
V_49 [ V_51 ++ ] = '\t' ;
break;
case 'u' :
{
T_12 V_54 = 0 ;
T_13 V_55 = TRUE ;
int V_56 ;
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ ) {
V_50 ++ ;
V_54 <<= 4 ;
V_52 = F_39 ( V_30 -> V_1 , V_30 -> V_11 + V_50 ) ;
V_53 = F_40 ( V_52 ) ;
if ( V_53 == - 1 ) {
V_55 = FALSE ;
break;
}
V_54 |= V_53 ;
}
if ( ( F_41 ( V_54 ) ) ) {
V_52 = F_39 ( V_30 -> V_1 , V_30 -> V_11 + V_50 + 1 ) ;
if ( V_52 == '\\' ) {
V_50 ++ ;
V_52 = F_39 ( V_30 -> V_1 , V_30 -> V_11 + V_50 + 1 ) ;
if ( V_52 == 'u' ) {
T_14 V_57 = V_54 ;
T_14 V_58 = 0 ;
V_50 ++ ;
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ ) {
V_50 ++ ;
V_58 <<= 4 ;
V_52 = F_39 ( V_30 -> V_1 , V_30 -> V_11 + V_50 ) ;
V_53 = F_40 ( V_52 ) ;
if ( V_53 == - 1 ) {
V_55 = FALSE ;
break;
}
V_58 |= V_53 ;
}
if ( ( F_42 ( V_58 ) ) ) {
V_54 = F_43 ( V_57 , V_58 ) ;
} else {
V_55 = FALSE ;
}
} else {
V_55 = FALSE ;
}
} else {
V_55 = FALSE ;
}
} else if ( ( F_42 ( V_54 ) ) ) {
V_50 ++ ;
V_55 = FALSE ;
}
if ( V_55 && F_44 ( V_54 ) && F_45 ( V_54 ) ) {
int V_59 = F_46 ( V_54 , & V_49 [ V_51 ] ) ;
V_51 += V_59 ;
} else
V_49 [ V_51 ++ ] = '?' ;
break;
}
default:
F_47 () ;
break;
}
} else {
int V_60 ;
V_49 [ V_51 ] = V_52 ;
V_60 = F_34 ( & V_49 [ V_51 ] , V_30 -> V_1 , V_50 , V_30 -> V_33 ) ;
V_51 += V_60 ;
V_50 += ( V_60 - 1 ) ;
}
}
V_49 [ V_51 ] = '\0' ;
return V_49 ;
}
static void F_48 ( void * V_29 , const void * T_9 V_28 , T_10 * V_30 ) {
T_5 * V_4 = ( T_5 * ) V_29 ;
T_3 * V_3 = ( T_3 * ) F_25 ( V_4 -> V_23 ) ;
T_15 V_61 = V_62 ;
if ( V_30 -> V_38 )
V_61 = ( T_15 ) V_30 -> V_38 -> V_39 ;
switch ( V_61 ) {
case V_40 :
if ( V_30 -> V_33 >= 2 )
F_31 ( V_3 , & V_63 , V_30 -> V_1 , V_30 -> V_11 , V_30 -> V_33 , F_30 ( V_30 ) ) ;
else
F_8 ( V_3 , & V_63 , V_30 -> V_1 , V_30 -> V_11 , V_30 -> V_33 , V_64 | V_21 ) ;
break;
case V_65 :
F_8 ( V_3 , & V_66 , V_30 -> V_1 , V_30 -> V_11 , V_30 -> V_33 , V_64 | V_21 ) ;
break;
case V_67 :
F_8 ( V_3 , & V_68 , V_30 -> V_1 , V_30 -> V_11 , V_30 -> V_33 , V_21 ) ;
break;
case V_69 :
F_8 ( V_3 , & V_70 , V_30 -> V_1 , V_30 -> V_11 , V_30 -> V_33 , V_21 ) ;
break;
case V_71 :
F_8 ( V_3 , & V_72 , V_30 -> V_1 , V_30 -> V_11 , V_30 -> V_33 , V_21 ) ;
break;
case V_73 :
case V_74 :
break;
default:
F_49 ( V_3 , V_30 -> V_1 , V_30 -> V_11 , V_30 -> V_33 ) ;
break;
}
}
static void F_50 ( void ) {
static T_16 V_75 ;
static T_16 V_76 ;
T_16 * V_77 , * V_78 ;
T_16 * V_79 ;
T_16 * V_80 ;
T_16 * V_81 , * V_82 ;
T_16 * V_83 ;
T_16 * V_84 ;
#define F_51 ( V_39 , T_17 , T_18 , T_19 , T_20 ) \
tvbparse_some(id, 0, 1, private_data, before_cb, after_cb, wanted)
T_16 * V_85 = F_52 ( - 1 , L_8 , NULL , NULL , NULL ) ;
V_80 = F_53 ( V_40 , NULL , NULL , NULL ,
V_85 ,
F_54 ( - 1 , 0 , V_86 , NULL , NULL , NULL ,
F_55 ( - 1 , NULL , NULL , NULL ,
F_56 ( - 1 , 0 , 0 , L_8 L_9 , NULL , NULL , NULL ) ,
F_53 ( - 1 , NULL , NULL , NULL ,
F_52 ( - 1 , L_9 , NULL , NULL , NULL ) ,
F_55 ( - 1 , NULL , NULL , NULL ,
F_57 ( - 1 , 0 , 1 , L_8 L_9 L_10 , NULL , NULL , NULL ) ,
F_53 ( - 1 , NULL , NULL , NULL ,
F_52 ( - 1 , L_11 , NULL , NULL , NULL ) ,
F_57 ( - 1 , 4 , 4 , L_12 , NULL , NULL , NULL ) ,
NULL ) ,
NULL ) ,
NULL ) ,
NULL )
) ,
V_85 ,
NULL ) ;
V_84 = F_52 ( - 1 , L_13 , NULL , NULL , NULL ) ;
V_82 = F_55 ( - 1 , NULL , NULL , NULL ,
F_52 ( - 1 , L_14 , NULL , NULL , NULL ) ,
F_53 ( - 1 , NULL , NULL , NULL ,
F_57 ( - 1 , 1 , 1 , L_15 , NULL , NULL , NULL ) ,
F_51 ( - 1 , NULL , NULL , NULL ,
F_57 ( - 1 , 0 , 0 , L_16 , NULL , NULL , NULL ) ) ,
NULL ) ,
NULL ) ;
V_81 = F_53 ( V_65 , NULL , NULL , NULL ,
F_51 ( - 1 , NULL , NULL , NULL ,
F_57 ( - 1 , 0 , 1 , L_17 , NULL , NULL , NULL ) ) ,
V_82 ,
F_51 ( - 1 , NULL , NULL , NULL ,
F_53 ( - 1 , NULL , NULL , NULL ,
F_52 ( - 1 , L_18 , NULL , NULL , NULL ) ,
F_57 ( - 1 , 1 , 0 , L_16 , NULL , NULL , NULL ) ,
NULL ) ) ,
F_51 ( - 1 , NULL , NULL , NULL ,
F_53 ( - 1 , NULL , NULL , NULL ,
F_52 ( - 1 , L_19 , NULL , NULL , NULL ) ,
F_51 ( - 1 , NULL , NULL , NULL ,
F_57 ( - 1 , 0 , 1 , L_20 , NULL , NULL , NULL ) ) ,
F_57 ( - 1 , 1 , 0 , L_16 , NULL , NULL , NULL ) ,
NULL ) ) ,
NULL ) ;
V_83 = F_55 ( - 1 , NULL , NULL , F_48 ,
F_58 ( V_67 , L_21 , NULL , NULL , NULL ) ,
F_58 ( V_69 , L_22 , NULL , NULL , NULL ) ,
F_58 ( V_71 , L_23 , NULL , NULL , NULL ) ,
& V_75 ,
& V_76 ,
V_81 ,
V_80 ,
NULL ) ;
V_78 = F_53 ( V_74 , NULL , F_32 , F_33 ,
F_52 ( - 1 , L_24 , NULL , NULL , NULL ) ,
F_51 ( - 1 , NULL , NULL , NULL ,
F_53 ( - 1 , NULL , NULL , NULL ,
V_83 ,
F_54 ( - 1 , 0 , V_86 , NULL , NULL , NULL ,
F_53 ( - 1 , NULL , NULL , NULL ,
V_84 ,
V_83 ,
NULL ) ) ,
NULL )
) ,
F_52 ( - 1 , L_25 , NULL , NULL , NULL ) ,
NULL ) ;
V_76 = * V_78 ;
V_79 = F_53 ( - 1 , NULL , F_28 , F_29 ,
V_80 ,
F_52 ( - 1 , L_26 , NULL , NULL , NULL ) ,
V_83 ,
NULL ) ;
V_77 = F_53 ( V_73 , NULL , F_24 , F_26 ,
F_52 ( - 1 , L_27 , NULL , NULL , NULL ) ,
F_51 ( - 1 , NULL , NULL , NULL ,
F_53 ( - 1 , NULL , NULL , NULL ,
V_79 ,
F_54 ( - 1 , 0 , V_86 , NULL , NULL , NULL ,
F_53 ( - 1 , NULL , NULL , NULL ,
V_84 ,
V_79 ,
NULL ) ) ,
NULL )
) ,
F_52 ( - 1 , L_28 , NULL , NULL , NULL ) ,
NULL ) ;
V_75 = * V_77 ;
V_24 = F_57 ( - 1 , 1 , 0 , L_29 , NULL , NULL , NULL ) ;
V_25 = F_55 ( - 1 , NULL , NULL , NULL ,
V_77 ,
V_78 ,
NULL ) ;
}
static T_13
F_59 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_4 )
{
V_48 V_33 = F_22 ( V_1 ) ;
const V_47 * V_45 = F_60 ( F_12 () , V_1 , 0 , V_33 , V_64 ) ;
if ( F_61 ( V_45 , V_33 ) == FALSE )
return FALSE ;
return ( F_1 ( V_1 , V_2 , V_3 , V_4 ) != 0 ) ;
}
void
F_62 ( void )
{
static T_21 * V_87 [] = {
& V_22 ,
& V_44 ,
& V_34 ,
& V_36
} ;
#ifndef F_63
static T_22 * V_88 [] = {
& V_43 ,
& V_32 ,
& V_35 ,
& V_42 ,
& V_63 ,
& V_66 ,
& V_68 ,
& V_70 ,
& V_72 ,
} ;
#endif
V_89 = F_64 ( L_3 , L_2 , L_30 ) ;
V_20 = F_65 ( V_89 ) ;
F_66 ( V_89 , V_88 , F_67 ( V_88 ) ) ;
F_68 ( V_87 , F_67 ( V_87 ) ) ;
V_90 = F_69 ( L_30 , F_1 , V_89 ) ;
F_50 () ;
}
void
F_70 ( void )
{
T_23 V_91 = F_71 ( F_23 , V_89 ) ;
F_72 ( L_31 , F_59 , L_32 , L_33 , V_89 , V_92 ) ;
F_72 ( L_34 , F_59 , L_35 , L_36 , V_89 , V_92 ) ;
F_73 ( L_37 , V_93 , V_91 ) ;
F_74 ( L_38 , L_39 , V_90 ) ;
F_74 ( L_38 , L_40 , V_90 ) ;
F_74 ( L_38 , L_41 , V_90 ) ;
F_74 ( L_38 , L_42 , V_90 ) ;
V_27 = F_75 ( L_43 , V_89 ) ;
}
