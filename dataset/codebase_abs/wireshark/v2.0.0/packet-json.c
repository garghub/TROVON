static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_4 )
{
T_3 * V_5 = NULL ;
T_4 * V_6 = NULL ;
T_5 V_7 ;
T_6 * V_8 ;
const char * V_9 ;
int V_10 ;
T_7 * V_11 = F_2 ( F_3 ( V_2 -> V_12 ) ) ;
if ( V_11 ) {
const char * V_13 = F_4 ( F_5 ( F_6 ( V_11 ) ) ) ;
if ( ! strcmp ( V_13 , L_1 ) ) {
F_7 ( V_2 -> V_14 , V_15 , L_2 ) ;
F_7 ( V_2 -> V_14 , V_16 , L_3 ) ;
}
}
V_9 = V_2 -> V_17 ;
if ( ! ( V_9 && V_9 [ 0 ] ) ) {
V_9 = ( char * ) V_4 ;
if ( ! ( V_9 && V_9 [ 0 ] ) ) {
V_9 = NULL ;
}
}
if ( V_3 ) {
V_6 = F_8 ( V_3 , V_18 , V_1 , 0 , - 1 , V_19 ) ;
V_5 = F_9 ( V_6 , V_20 ) ;
if ( V_9 )
F_10 ( V_6 , L_4 , V_9 ) ;
}
V_10 = 0 ;
V_7 . V_21 = F_11 ( F_12 () ) ;
F_13 ( V_7 . V_21 , V_5 ) ;
V_8 = F_14 ( V_1 , V_10 , - 1 , & V_7 , V_22 ) ;
while ( ( F_15 ( V_8 , V_23 ) ) )
;
V_10 = F_16 ( V_8 ) ;
F_17 ( V_6 , V_10 ) ;
if ( F_18 ( V_1 , V_10 ) > 0 ) {
T_1 * V_24 ;
V_24 = F_19 ( V_1 , V_10 ) ;
F_20 ( V_25 , V_24 , V_2 , V_3 , V_4 ) ;
} else if ( V_9 ) {
F_21 ( V_2 -> V_14 , V_16 , L_5 , L_6 , V_9 ) ;
}
return F_22 ( V_1 ) ;
}
static int
F_23 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_4 V_26 )
{
return F_1 ( V_1 , V_2 , V_3 , NULL ) ;
}
static void F_24 ( void * V_27 , const void * T_8 V_26 , T_9 * V_28 ) {
T_5 * V_4 = ( T_5 * ) V_27 ;
T_3 * V_3 = ( T_3 * ) F_25 ( V_4 -> V_21 ) ;
T_3 * V_29 ;
T_4 * V_6 ;
V_6 = F_8 ( V_3 , & V_30 , V_28 -> V_1 , V_28 -> V_10 , V_28 -> V_31 , V_19 ) ;
V_29 = F_9 ( V_6 , V_32 ) ;
F_13 ( V_4 -> V_21 , V_29 ) ;
}
static void F_26 ( void * V_27 , const void * T_8 V_26 , T_9 * T_10 V_26 ) {
T_5 * V_4 = ( T_5 * ) V_27 ;
F_27 ( V_4 -> V_21 ) ;
}
static void F_28 ( void * V_27 , const void * T_8 V_26 , T_9 * V_28 ) {
T_5 * V_4 = ( T_5 * ) V_27 ;
T_3 * V_3 = ( T_3 * ) F_25 ( V_4 -> V_21 ) ;
T_3 * V_29 ;
T_4 * V_6 ;
V_6 = F_8 ( V_3 , & V_33 , V_28 -> V_1 , V_28 -> V_10 , V_28 -> V_31 , V_19 ) ;
V_29 = F_9 ( V_6 , V_34 ) ;
F_13 ( V_4 -> V_21 , V_29 ) ;
}
static void F_29 ( void * V_27 , const void * T_8 V_26 , T_9 * V_28 ) {
T_5 * V_4 = ( T_5 * ) V_27 ;
T_3 * V_3 = ( T_3 * ) F_27 ( V_4 -> V_21 ) ;
if ( V_3 ) {
T_9 * V_35 = V_28 -> V_36 ;
if ( V_35 && V_35 -> V_37 == V_38 ) {
char * V_39 = F_30 ( F_12 () , V_35 -> V_1 , V_35 -> V_10 , V_35 -> V_31 , V_40 ) ;
F_10 ( V_3 , L_7 , V_39 ) ;
}
}
}
static void F_31 ( void * V_27 , const void * T_8 V_26 , T_9 * V_28 ) {
T_5 * V_4 = ( T_5 * ) V_27 ;
T_3 * V_3 = ( T_3 * ) F_25 ( V_4 -> V_21 ) ;
T_3 * V_29 ;
T_4 * V_6 ;
V_6 = F_8 ( V_3 , & V_41 , V_28 -> V_1 , V_28 -> V_10 , V_28 -> V_31 , V_19 ) ;
V_29 = F_9 ( V_6 , V_42 ) ;
F_13 ( V_4 -> V_21 , V_29 ) ;
}
static void F_32 ( void * V_27 , const void * T_8 V_26 , T_9 * T_10 V_26 ) {
T_5 * V_4 = ( T_5 * ) V_27 ;
F_27 ( V_4 -> V_21 ) ;
}
static int
F_33 ( char * V_43 , T_1 * V_1 , int V_10 , int V_44 )
{
int V_31 = F_34 ( ( V_45 ) * V_43 ) ;
if ( V_31 == - 1 || ( ( V_46 ) ( V_10 + V_31 ) ) >= ( V_46 ) V_44 ) {
* V_43 = '?' ;
return 1 ;
}
F_35 ( V_1 , V_43 + 1 , V_10 + 1 , V_31 - 1 ) ;
if ( ! F_36 ( V_43 , V_31 , NULL ) ) {
* V_43 = '?' ;
return 1 ;
}
return V_31 ;
}
static char * F_37 ( T_9 * V_28 )
{
char * V_47 = ( char * ) F_38 ( F_12 () , V_28 -> V_31 - 1 ) ;
int V_48 , V_49 ;
V_49 = 0 ;
for ( V_48 = 1 ; V_48 < V_28 -> V_31 - 1 ; V_48 ++ ) {
V_45 V_50 = F_39 ( V_28 -> V_1 , V_28 -> V_10 + V_48 ) ;
int V_51 ;
if ( V_50 == '\\' ) {
V_48 ++ ;
V_50 = F_39 ( V_28 -> V_1 , V_28 -> V_10 + V_48 ) ;
switch ( V_50 ) {
case '\"' :
case '\\' :
case '/' :
V_47 [ V_49 ++ ] = V_50 ;
break;
case 'b' :
V_47 [ V_49 ++ ] = '\b' ;
break;
case 'f' :
V_47 [ V_49 ++ ] = '\f' ;
break;
case 'n' :
V_47 [ V_49 ++ ] = '\n' ;
break;
case 'r' :
V_47 [ V_49 ++ ] = '\r' ;
break;
case 't' :
V_47 [ V_49 ++ ] = '\t' ;
break;
case 'u' :
{
T_11 V_52 = 0 ;
T_12 V_53 = TRUE ;
int V_54 ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
V_48 ++ ;
V_52 <<= 4 ;
V_50 = F_39 ( V_28 -> V_1 , V_28 -> V_10 + V_48 ) ;
V_51 = F_40 ( V_50 ) ;
if ( V_51 == - 1 ) {
V_53 = FALSE ;
break;
}
V_52 |= V_51 ;
}
if ( ( F_41 ( V_52 ) ) ) {
V_50 = F_39 ( V_28 -> V_1 , V_28 -> V_10 + V_48 + 1 ) ;
if ( V_50 == '\\' ) {
V_48 ++ ;
V_50 = F_39 ( V_28 -> V_1 , V_28 -> V_10 + V_48 + 1 ) ;
if ( V_50 == 'u' ) {
T_13 V_55 = V_52 ;
T_13 V_56 = 0 ;
V_48 ++ ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
V_48 ++ ;
V_56 <<= 4 ;
V_50 = F_39 ( V_28 -> V_1 , V_28 -> V_10 + V_48 ) ;
V_51 = F_40 ( V_50 ) ;
if ( V_51 == - 1 ) {
V_53 = FALSE ;
break;
}
V_56 |= V_51 ;
}
if ( ( F_42 ( V_56 ) ) ) {
V_52 = F_43 ( V_55 , V_56 ) ;
} else {
V_53 = FALSE ;
}
} else {
V_53 = FALSE ;
}
} else {
V_53 = FALSE ;
}
} else if ( ( F_42 ( V_52 ) ) ) {
V_48 ++ ;
V_53 = FALSE ;
}
if ( V_53 && F_44 ( V_52 ) && F_45 ( V_52 ) ) {
int V_57 = F_46 ( V_52 , & V_47 [ V_49 ] ) ;
V_49 += V_57 ;
} else
V_47 [ V_49 ++ ] = '?' ;
break;
}
default:
F_47 () ;
break;
}
} else {
int V_58 ;
V_47 [ V_49 ] = V_50 ;
V_58 = F_33 ( & V_47 [ V_49 ] , V_28 -> V_1 , V_48 , V_28 -> V_31 ) ;
V_49 += V_58 ;
V_48 += ( V_58 - 1 ) ;
}
}
V_47 [ V_49 ] = '\0' ;
return V_47 ;
}
static void F_48 ( void * V_27 , const void * T_8 V_26 , T_9 * V_28 ) {
T_5 * V_4 = ( T_5 * ) V_27 ;
T_3 * V_3 = ( T_3 * ) F_25 ( V_4 -> V_21 ) ;
T_14 V_59 = V_60 ;
if ( V_28 -> V_36 )
V_59 = ( T_14 ) V_28 -> V_36 -> V_37 ;
switch ( V_59 ) {
case V_38 :
if ( V_28 -> V_31 >= 2 )
F_49 ( V_3 , & V_61 , V_28 -> V_1 , V_28 -> V_10 , V_28 -> V_31 , F_37 ( V_28 ) ) ;
else
F_8 ( V_3 , & V_61 , V_28 -> V_1 , V_28 -> V_10 , V_28 -> V_31 , V_40 | V_19 ) ;
break;
case V_62 :
F_8 ( V_3 , & V_63 , V_28 -> V_1 , V_28 -> V_10 , V_28 -> V_31 , V_40 | V_19 ) ;
break;
case V_64 :
F_8 ( V_3 , & V_65 , V_28 -> V_1 , V_28 -> V_10 , V_28 -> V_31 , V_19 ) ;
break;
case V_66 :
F_8 ( V_3 , & V_67 , V_28 -> V_1 , V_28 -> V_10 , V_28 -> V_31 , V_19 ) ;
break;
case V_68 :
F_8 ( V_3 , & V_69 , V_28 -> V_1 , V_28 -> V_10 , V_28 -> V_31 , V_19 ) ;
break;
case V_70 :
case V_71 :
break;
default:
F_50 ( V_3 , V_28 -> V_1 , V_28 -> V_10 , V_28 -> V_31 ) ;
break;
}
}
static void F_51 ( void ) {
static T_15 V_72 ;
static T_15 V_73 ;
T_15 * V_74 , * V_75 ;
T_15 * V_76 ;
T_15 * V_77 ;
T_15 * V_78 , * V_79 ;
T_15 * V_80 ;
T_15 * V_81 ;
#define F_52 ( V_37 , T_16 , T_17 , T_18 , T_19 ) \
tvbparse_some(id, 0, 1, private_data, before_cb, after_cb, wanted)
T_15 * V_82 = F_53 ( - 1 , L_8 , NULL , NULL , NULL ) ;
V_77 = F_54 ( V_38 , NULL , NULL , NULL ,
V_82 ,
F_55 ( - 1 , 0 , V_83 , NULL , NULL , NULL ,
F_56 ( - 1 , NULL , NULL , NULL ,
F_57 ( - 1 , 0 , 0 , L_8 L_9 , NULL , NULL , NULL ) ,
F_54 ( - 1 , NULL , NULL , NULL ,
F_53 ( - 1 , L_9 , NULL , NULL , NULL ) ,
F_56 ( - 1 , NULL , NULL , NULL ,
F_58 ( - 1 , 0 , 1 , L_8 L_9 L_10 , NULL , NULL , NULL ) ,
F_54 ( - 1 , NULL , NULL , NULL ,
F_53 ( - 1 , L_11 , NULL , NULL , NULL ) ,
F_58 ( - 1 , 4 , 4 , L_12 , NULL , NULL , NULL ) ,
NULL ) ,
NULL ) ,
NULL ) ,
NULL )
) ,
V_82 ,
NULL ) ;
V_81 = F_53 ( - 1 , L_13 , NULL , NULL , NULL ) ;
V_79 = F_56 ( - 1 , NULL , NULL , NULL ,
F_53 ( - 1 , L_14 , NULL , NULL , NULL ) ,
F_54 ( - 1 , NULL , NULL , NULL ,
F_58 ( - 1 , 1 , 1 , L_15 , NULL , NULL , NULL ) ,
F_52 ( - 1 , NULL , NULL , NULL ,
F_58 ( - 1 , 0 , 0 , L_16 , NULL , NULL , NULL ) ) ,
NULL ) ,
NULL ) ;
V_78 = F_54 ( V_62 , NULL , NULL , NULL ,
F_52 ( - 1 , NULL , NULL , NULL ,
F_58 ( - 1 , 0 , 1 , L_17 , NULL , NULL , NULL ) ) ,
V_79 ,
F_52 ( - 1 , NULL , NULL , NULL ,
F_54 ( - 1 , NULL , NULL , NULL ,
F_53 ( - 1 , L_18 , NULL , NULL , NULL ) ,
F_58 ( - 1 , 1 , 0 , L_16 , NULL , NULL , NULL ) ,
NULL ) ) ,
F_52 ( - 1 , NULL , NULL , NULL ,
F_54 ( - 1 , NULL , NULL , NULL ,
F_53 ( - 1 , L_19 , NULL , NULL , NULL ) ,
F_52 ( - 1 , NULL , NULL , NULL ,
F_58 ( - 1 , 0 , 1 , L_20 , NULL , NULL , NULL ) ) ,
F_58 ( - 1 , 1 , 0 , L_16 , NULL , NULL , NULL ) ,
NULL ) ) ,
NULL ) ;
V_80 = F_56 ( - 1 , NULL , NULL , F_48 ,
F_59 ( V_64 , L_21 , NULL , NULL , NULL ) ,
F_59 ( V_66 , L_22 , NULL , NULL , NULL ) ,
F_59 ( V_68 , L_23 , NULL , NULL , NULL ) ,
& V_72 ,
& V_73 ,
V_78 ,
V_77 ,
NULL ) ;
V_75 = F_54 ( V_71 , NULL , F_31 , F_32 ,
F_53 ( - 1 , L_24 , NULL , NULL , NULL ) ,
F_52 ( - 1 , NULL , NULL , NULL ,
F_54 ( - 1 , NULL , NULL , NULL ,
V_80 ,
F_55 ( - 1 , 0 , V_83 , NULL , NULL , NULL ,
F_54 ( - 1 , NULL , NULL , NULL ,
V_81 ,
V_80 ,
NULL ) ) ,
NULL )
) ,
F_53 ( - 1 , L_25 , NULL , NULL , NULL ) ,
NULL ) ;
V_73 = * V_75 ;
V_76 = F_54 ( - 1 , NULL , F_28 , F_29 ,
V_77 ,
F_53 ( - 1 , L_26 , NULL , NULL , NULL ) ,
V_80 ,
NULL ) ;
V_74 = F_54 ( V_70 , NULL , F_24 , F_26 ,
F_53 ( - 1 , L_27 , NULL , NULL , NULL ) ,
F_52 ( - 1 , NULL , NULL , NULL ,
F_54 ( - 1 , NULL , NULL , NULL ,
V_76 ,
F_55 ( - 1 , 0 , V_83 , NULL , NULL , NULL ,
F_54 ( - 1 , NULL , NULL , NULL ,
V_81 ,
V_76 ,
NULL ) ) ,
NULL )
) ,
F_53 ( - 1 , L_28 , NULL , NULL , NULL ) ,
NULL ) ;
V_72 = * V_74 ;
V_22 = F_58 ( - 1 , 1 , 0 , L_29 , NULL , NULL , NULL ) ;
V_23 = F_56 ( - 1 , NULL , NULL , NULL ,
V_74 ,
V_75 ,
NULL ) ;
}
static T_12
F_60 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_4 )
{
V_46 V_31 = F_22 ( V_1 ) ;
const V_45 * V_43 = F_30 ( F_12 () , V_1 , 0 , V_31 , V_40 ) ;
if ( F_61 ( V_43 , V_31 ) == FALSE )
return FALSE ;
return ( F_1 ( V_1 , V_2 , V_3 , V_4 ) != 0 ) ;
}
void
F_62 ( void )
{
static T_20 * V_84 [] = {
& V_20 ,
& V_42 ,
& V_32 ,
& V_34
} ;
#ifndef F_63
static T_21 * V_85 [] = {
& V_41 ,
& V_30 ,
& V_33 ,
& V_61 ,
& V_63 ,
& V_65 ,
& V_67 ,
& V_69 ,
} ;
#endif
V_86 = F_64 ( L_3 , L_2 , L_30 ) ;
V_18 = F_65 ( V_86 ) ;
F_66 ( V_86 , V_85 , F_67 ( V_85 ) ) ;
F_68 ( V_84 , F_67 ( V_84 ) ) ;
V_87 = F_69 ( L_30 , F_1 , V_86 ) ;
F_51 () ;
}
void
F_70 ( void )
{
T_22 V_88 = F_71 ( F_23 , V_86 ) ;
F_72 ( L_31 , F_60 , L_32 , L_33 , V_86 , V_89 ) ;
F_72 ( L_34 , F_60 , L_35 , L_36 , V_86 , V_89 ) ;
F_73 ( L_37 , V_90 , V_88 ) ;
F_74 ( L_38 , L_39 , V_87 ) ;
F_74 ( L_38 , L_40 , V_87 ) ;
F_74 ( L_38 , L_41 , V_87 ) ;
V_25 = F_75 ( L_42 ) ;
}
