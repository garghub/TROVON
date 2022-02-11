static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_4 )
{
T_3 * V_5 = NULL ;
T_4 * V_6 = NULL ;
T_5 V_7 ;
T_6 * V_8 ;
const char * V_9 ;
int V_10 ;
V_9 = V_2 -> V_11 ;
if ( ! ( V_9 && V_9 [ 0 ] ) ) {
V_9 = ( char * ) V_4 ;
if ( ! ( V_9 && V_9 [ 0 ] ) ) {
V_9 = ( char * ) ( V_2 -> V_12 ) ;
if ( ! ( V_9 && V_9 [ 0 ] ) ) {
V_9 = NULL ;
}
}
}
if ( V_3 ) {
V_6 = F_2 ( V_3 , V_13 , V_1 , 0 , - 1 , V_14 ) ;
V_5 = F_3 ( V_6 , V_15 ) ;
if ( V_9 )
F_4 ( V_6 , L_1 , V_9 ) ;
}
V_10 = 0 ;
V_7 . V_16 = F_5 ( F_6 () ) ;
F_7 ( V_7 . V_16 , V_5 ) ;
V_8 = F_8 ( V_1 , V_10 , - 1 , & V_7 , V_17 ) ;
while ( ( F_9 ( V_8 , V_18 ) ) )
;
V_10 = F_10 ( V_8 ) ;
F_11 ( V_6 , V_10 ) ;
if ( F_12 ( V_1 , V_10 ) > 0 ) {
int V_19 , V_20 ;
T_1 * V_21 ;
V_19 = F_12 ( V_1 , V_10 ) ;
V_20 = F_13 ( V_1 , V_10 ) ;
V_21 = F_14 ( V_1 , V_10 , V_19 , V_20 ) ;
F_15 ( V_22 , V_21 , V_2 , V_3 ) ;
} else if ( V_9 ) {
F_16 ( V_2 -> V_23 , V_24 , L_2 , L_3 , V_9 ) ;
}
return F_17 ( V_1 ) ;
}
static void F_18 ( void * V_25 , const void * T_7 V_26 , T_8 * V_27 ) {
T_5 * V_4 = ( T_5 * ) V_25 ;
T_3 * V_3 = ( T_3 * ) F_19 ( V_4 -> V_16 ) ;
T_3 * V_28 ;
T_4 * V_6 ;
V_6 = F_2 ( V_3 , & V_29 , V_27 -> V_1 , V_27 -> V_10 , V_27 -> V_30 , V_14 ) ;
V_28 = F_3 ( V_6 , V_31 ) ;
F_7 ( V_4 -> V_16 , V_28 ) ;
}
static void F_20 ( void * V_25 , const void * T_7 V_26 , T_8 * T_9 V_26 ) {
T_5 * V_4 = ( T_5 * ) V_25 ;
F_21 ( V_4 -> V_16 ) ;
}
static void F_22 ( void * V_25 , const void * T_7 V_26 , T_8 * V_27 ) {
T_5 * V_4 = ( T_5 * ) V_25 ;
T_3 * V_3 = ( T_3 * ) F_19 ( V_4 -> V_16 ) ;
T_3 * V_28 ;
T_4 * V_6 ;
V_6 = F_2 ( V_3 , & V_32 , V_27 -> V_1 , V_27 -> V_10 , V_27 -> V_30 , V_14 ) ;
V_28 = F_3 ( V_6 , V_33 ) ;
F_7 ( V_4 -> V_16 , V_28 ) ;
}
static void F_23 ( void * V_25 , const void * T_7 V_26 , T_8 * V_27 ) {
T_5 * V_4 = ( T_5 * ) V_25 ;
T_3 * V_3 = ( T_3 * ) F_21 ( V_4 -> V_16 ) ;
if ( V_3 ) {
T_8 * V_34 = V_27 -> V_35 ;
if ( V_34 && V_34 -> V_36 == V_37 ) {
char * V_38 = F_24 ( F_6 () , V_34 -> V_1 , V_34 -> V_10 , V_34 -> V_30 ) ;
F_4 ( V_3 , L_4 , V_38 ) ;
}
}
}
static void F_25 ( void * V_25 , const void * T_7 V_26 , T_8 * V_27 ) {
T_5 * V_4 = ( T_5 * ) V_25 ;
T_3 * V_3 = ( T_3 * ) F_19 ( V_4 -> V_16 ) ;
T_3 * V_28 ;
T_4 * V_6 ;
V_6 = F_2 ( V_3 , & V_39 , V_27 -> V_1 , V_27 -> V_10 , V_27 -> V_30 , V_14 ) ;
V_28 = F_3 ( V_6 , V_40 ) ;
F_7 ( V_4 -> V_16 , V_28 ) ;
}
static void F_26 ( void * V_25 , const void * T_7 V_26 , T_8 * T_9 V_26 ) {
T_5 * V_4 = ( T_5 * ) V_25 ;
F_21 ( V_4 -> V_16 ) ;
}
static int
F_27 ( char * V_41 , T_1 * V_1 , int V_10 , int V_42 )
{
int V_30 = F_28 ( ( V_43 ) * V_41 ) ;
if ( V_30 == - 1 || ( ( V_44 ) ( V_10 + V_30 ) ) >= ( V_44 ) V_42 ) {
* V_41 = '?' ;
return 1 ;
}
F_29 ( V_1 , V_41 + 1 , V_10 + 1 , V_30 - 1 ) ;
if ( ! F_30 ( V_41 , V_30 , NULL ) ) {
* V_41 = '?' ;
return 1 ;
}
return V_30 ;
}
static char * F_31 ( T_8 * V_27 )
{
char * V_45 = ( char * ) F_32 ( F_6 () , V_27 -> V_30 - 1 ) ;
int V_46 , V_47 ;
V_47 = 0 ;
for ( V_46 = 1 ; V_46 < V_27 -> V_30 - 1 ; V_46 ++ ) {
V_43 V_48 = F_33 ( V_27 -> V_1 , V_27 -> V_10 + V_46 ) ;
int V_49 ;
if ( V_48 == '\\' ) {
V_46 ++ ;
V_48 = F_33 ( V_27 -> V_1 , V_27 -> V_10 + V_46 ) ;
switch ( V_48 ) {
case '\"' :
case '\\' :
case '/' :
V_45 [ V_47 ++ ] = V_48 ;
break;
case 'b' :
V_45 [ V_47 ++ ] = '\b' ;
break;
case 'f' :
V_45 [ V_47 ++ ] = '\f' ;
break;
case 'n' :
V_45 [ V_47 ++ ] = '\n' ;
break;
case 'r' :
V_45 [ V_47 ++ ] = '\r' ;
break;
case 't' :
V_45 [ V_47 ++ ] = '\t' ;
break;
case 'u' :
{
T_10 V_50 = 0 ;
T_11 V_51 = TRUE ;
int V_52 ;
for ( V_52 = 0 ; V_52 < 4 ; V_52 ++ ) {
V_46 ++ ;
V_50 <<= 4 ;
V_48 = F_33 ( V_27 -> V_1 , V_27 -> V_10 + V_46 ) ;
V_49 = F_34 ( V_48 ) ;
if ( V_49 == - 1 ) {
V_51 = FALSE ;
break;
}
V_50 |= V_49 ;
}
if ( ( F_35 ( V_50 ) ) ) {
V_48 = F_33 ( V_27 -> V_1 , V_27 -> V_10 + V_46 + 1 ) ;
if ( V_48 == '\\' ) {
V_46 ++ ;
V_48 = F_33 ( V_27 -> V_1 , V_27 -> V_10 + V_46 + 1 ) ;
if ( V_48 == 'u' ) {
T_12 V_53 = V_50 ;
T_12 V_54 = 0 ;
V_46 ++ ;
for ( V_52 = 0 ; V_52 < 4 ; V_52 ++ ) {
V_46 ++ ;
V_54 <<= 4 ;
V_48 = F_33 ( V_27 -> V_1 , V_27 -> V_10 + V_46 ) ;
V_49 = F_34 ( V_48 ) ;
if ( V_49 == - 1 ) {
V_51 = FALSE ;
break;
}
V_54 |= V_49 ;
}
if ( ( F_36 ( V_54 ) ) ) {
V_50 = F_37 ( V_53 , V_54 ) ;
} else {
V_51 = FALSE ;
}
} else {
V_51 = FALSE ;
}
} else {
V_51 = FALSE ;
}
} else if ( ( F_36 ( V_50 ) ) ) {
V_46 ++ ;
V_51 = FALSE ;
}
if ( V_51 && F_38 ( V_50 ) && F_39 ( V_50 ) ) {
int V_55 = F_40 ( V_50 , & V_45 [ V_47 ] ) ;
V_47 += V_55 ;
} else
V_45 [ V_47 ++ ] = '?' ;
break;
}
default:
F_41 () ;
break;
}
} else {
int V_56 ;
V_45 [ V_47 ] = V_48 ;
V_56 = F_27 ( & V_45 [ V_47 ] , V_27 -> V_1 , V_46 , V_27 -> V_30 ) ;
V_47 += V_56 ;
V_46 += ( V_56 - 1 ) ;
}
}
V_45 [ V_47 ] = '\0' ;
return V_45 ;
}
static void F_42 ( void * V_25 , const void * T_7 V_26 , T_8 * V_27 ) {
T_5 * V_4 = ( T_5 * ) V_25 ;
T_3 * V_3 = ( T_3 * ) F_19 ( V_4 -> V_16 ) ;
T_13 V_57 = V_58 ;
if ( V_27 -> V_35 )
V_57 = ( T_13 ) V_27 -> V_35 -> V_36 ;
switch ( V_57 ) {
case V_37 :
if ( V_27 -> V_30 >= 2 )
F_43 ( V_3 , & V_59 , V_27 -> V_1 , V_27 -> V_10 , V_27 -> V_30 , F_31 ( V_27 ) ) ;
else
F_2 ( V_3 , & V_59 , V_27 -> V_1 , V_27 -> V_10 , V_27 -> V_30 , V_60 | V_14 ) ;
break;
case V_61 :
F_2 ( V_3 , & V_62 , V_27 -> V_1 , V_27 -> V_10 , V_27 -> V_30 , V_60 | V_14 ) ;
break;
case V_63 :
F_2 ( V_3 , & V_64 , V_27 -> V_1 , V_27 -> V_10 , V_27 -> V_30 , V_14 ) ;
break;
case V_65 :
F_2 ( V_3 , & V_66 , V_27 -> V_1 , V_27 -> V_10 , V_27 -> V_30 , V_14 ) ;
break;
case V_67 :
F_2 ( V_3 , & V_68 , V_27 -> V_1 , V_27 -> V_10 , V_27 -> V_30 , V_14 ) ;
break;
case V_69 :
case V_70 :
break;
default:
F_44 ( V_3 , V_27 -> V_1 , V_27 -> V_10 , V_27 -> V_30 ) ;
break;
}
}
static void F_45 ( void ) {
static T_14 V_71 ;
static T_14 V_72 ;
T_14 * V_73 , * V_74 ;
T_14 * V_75 ;
T_14 * V_76 ;
T_14 * V_77 , * V_78 ;
T_14 * V_79 ;
T_14 * V_80 ;
#define F_46 ( V_36 , V_12 , T_15 , T_16 , T_17 ) \
tvbparse_some(id, 0, 1, private_data, before_cb, after_cb, wanted)
T_14 * V_81 = F_47 ( - 1 , L_5 , NULL , NULL , NULL ) ;
V_76 = F_48 ( V_37 , NULL , NULL , NULL ,
V_81 ,
F_49 ( - 1 , 0 , V_82 , NULL , NULL , NULL ,
F_50 ( - 1 , NULL , NULL , NULL ,
F_51 ( - 1 , 0 , 0 , L_5 L_6 , NULL , NULL , NULL ) ,
F_48 ( - 1 , NULL , NULL , NULL ,
F_47 ( - 1 , L_6 , NULL , NULL , NULL ) ,
F_50 ( - 1 , NULL , NULL , NULL ,
F_52 ( - 1 , 0 , 1 , L_5 L_6 L_7 , NULL , NULL , NULL ) ,
F_48 ( - 1 , NULL , NULL , NULL ,
F_47 ( - 1 , L_8 , NULL , NULL , NULL ) ,
F_52 ( - 1 , 4 , 4 , L_9 , NULL , NULL , NULL ) ,
NULL ) ,
NULL ) ,
NULL ) ,
NULL )
) ,
V_81 ,
NULL ) ;
V_80 = F_47 ( - 1 , L_10 , NULL , NULL , NULL ) ;
V_78 = F_50 ( - 1 , NULL , NULL , NULL ,
F_47 ( - 1 , L_11 , NULL , NULL , NULL ) ,
F_48 ( - 1 , NULL , NULL , NULL ,
F_52 ( - 1 , 1 , 1 , L_12 , NULL , NULL , NULL ) ,
F_46 ( - 1 , NULL , NULL , NULL ,
F_52 ( - 1 , 0 , 0 , L_13 , NULL , NULL , NULL ) ) ,
NULL ) ,
NULL ) ;
V_77 = F_48 ( V_61 , NULL , NULL , NULL ,
F_46 ( - 1 , NULL , NULL , NULL ,
F_52 ( - 1 , 0 , 1 , L_14 , NULL , NULL , NULL ) ) ,
V_78 ,
F_46 ( - 1 , NULL , NULL , NULL ,
F_48 ( - 1 , NULL , NULL , NULL ,
F_47 ( - 1 , L_15 , NULL , NULL , NULL ) ,
F_52 ( - 1 , 1 , 0 , L_13 , NULL , NULL , NULL ) ,
NULL ) ) ,
F_46 ( - 1 , NULL , NULL , NULL ,
F_48 ( - 1 , NULL , NULL , NULL ,
F_47 ( - 1 , L_16 , NULL , NULL , NULL ) ,
F_46 ( - 1 , NULL , NULL , NULL ,
F_52 ( - 1 , 0 , 1 , L_17 , NULL , NULL , NULL ) ) ,
F_52 ( - 1 , 1 , 0 , L_13 , NULL , NULL , NULL ) ,
NULL ) ) ,
NULL ) ;
V_79 = F_50 ( - 1 , NULL , NULL , F_42 ,
F_53 ( V_63 , L_18 , NULL , NULL , NULL ) ,
F_53 ( V_65 , L_19 , NULL , NULL , NULL ) ,
F_53 ( V_67 , L_20 , NULL , NULL , NULL ) ,
& V_71 ,
& V_72 ,
V_77 ,
V_76 ,
NULL ) ;
V_74 = F_48 ( V_70 , NULL , F_25 , F_26 ,
F_47 ( - 1 , L_21 , NULL , NULL , NULL ) ,
F_46 ( - 1 , NULL , NULL , NULL ,
F_48 ( - 1 , NULL , NULL , NULL ,
V_79 ,
F_49 ( - 1 , 0 , V_82 , NULL , NULL , NULL ,
F_48 ( - 1 , NULL , NULL , NULL ,
V_80 ,
V_79 ,
NULL ) ) ,
NULL )
) ,
F_47 ( - 1 , L_22 , NULL , NULL , NULL ) ,
NULL ) ;
V_72 = * V_74 ;
V_75 = F_48 ( - 1 , NULL , F_22 , F_23 ,
V_76 ,
F_47 ( - 1 , L_23 , NULL , NULL , NULL ) ,
V_79 ,
NULL ) ;
V_73 = F_48 ( V_69 , NULL , F_18 , F_20 ,
F_47 ( - 1 , L_24 , NULL , NULL , NULL ) ,
F_46 ( - 1 , NULL , NULL , NULL ,
F_48 ( - 1 , NULL , NULL , NULL ,
V_75 ,
F_49 ( - 1 , 0 , V_82 , NULL , NULL , NULL ,
F_48 ( - 1 , NULL , NULL , NULL ,
V_80 ,
V_75 ,
NULL ) ) ,
NULL )
) ,
F_47 ( - 1 , L_25 , NULL , NULL , NULL ) ,
NULL ) ;
V_71 = * V_73 ;
V_17 = F_52 ( - 1 , 1 , 0 , L_26 , NULL , NULL , NULL ) ;
V_18 = F_50 ( - 1 , NULL , NULL , NULL ,
V_73 ,
V_74 ,
NULL ) ;
}
void
F_54 ( void )
{
static T_18 * V_83 [] = {
& V_15 ,
& V_40 ,
& V_31 ,
& V_33
} ;
#ifndef F_55
static T_19 * V_84 [] = {
& V_39 ,
& V_29 ,
& V_32 ,
& V_59 ,
& V_62 ,
& V_64 ,
& V_66 ,
& V_68 ,
} ;
#endif
int V_85 ;
V_85 = F_56 ( L_27 , L_28 , L_29 ) ;
V_13 = F_57 ( V_85 ) ;
F_58 ( V_85 , V_84 , F_59 ( V_84 ) ) ;
F_60 ( V_83 , F_59 ( V_83 ) ) ;
V_86 = F_61 ( L_29 , F_1 , V_85 ) ;
F_45 () ;
}
void
F_62 ( void )
{
F_63 ( L_30 , L_31 , V_86 ) ;
F_63 ( L_30 , L_32 , V_86 ) ;
F_63 ( L_30 , L_33 , V_86 ) ;
V_22 = F_64 ( L_34 ) ;
}
