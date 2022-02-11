static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_3 * V_4 = NULL ;
T_4 * V_5 = NULL ;
T_5 V_6 ;
T_6 * V_7 ;
const char * V_8 ;
int V_9 ;
V_8 = V_2 -> V_10 ;
if ( ! ( V_8 && V_8 [ 0 ] ) ) {
V_8 = ( char * ) ( V_2 -> V_11 ) ;
if ( ! ( V_8 && V_8 [ 0 ] ) ) {
V_8 = NULL ;
}
}
if ( V_3 ) {
V_5 = F_2 ( V_3 , V_12 , V_1 , 0 , - 1 , V_13 ) ;
V_4 = F_3 ( V_5 , V_14 ) ;
if ( V_8 )
F_4 ( V_5 , L_1 , V_8 ) ;
}
V_9 = 0 ;
V_6 . V_15 = F_5 () ;
F_6 ( V_6 . V_15 , V_4 ) ;
V_7 = F_7 ( V_1 , V_9 , - 1 , & V_6 , V_16 ) ;
while ( ( F_8 ( V_7 , V_17 ) ) )
;
V_9 = F_9 ( V_7 ) ;
F_10 ( V_5 , V_9 ) ;
if ( F_11 ( V_1 , V_9 ) > 0 ) {
int V_18 , V_19 ;
T_1 * V_20 ;
V_18 = F_11 ( V_1 , V_9 ) ;
V_19 = F_12 ( V_1 , V_9 ) ;
V_20 = F_13 ( V_1 , V_9 , V_18 , V_19 ) ;
F_14 ( V_21 , V_20 , V_2 , V_3 ) ;
} else if ( V_8 ) {
F_15 ( V_2 -> V_22 , V_23 , L_2 , L_3 , V_8 ) ;
}
}
static void F_16 ( void * V_24 , const void * T_7 V_25 , T_8 * V_26 ) {
T_5 * V_27 = ( T_5 * ) V_24 ;
T_3 * V_3 = ( T_3 * ) F_17 ( V_27 -> V_15 ) ;
T_3 * V_28 ;
T_4 * V_5 ;
V_5 = F_2 ( V_3 , V_29 , V_26 -> V_1 , V_26 -> V_9 , V_26 -> V_30 , V_13 ) ;
V_28 = F_3 ( V_5 , V_31 ) ;
F_6 ( V_27 -> V_15 , V_28 ) ;
}
static void F_18 ( void * V_24 , const void * T_7 V_25 , T_8 * T_9 V_25 ) {
T_5 * V_27 = ( T_5 * ) V_24 ;
F_19 ( V_27 -> V_15 ) ;
}
static void F_20 ( void * V_24 , const void * T_7 V_25 , T_8 * V_26 ) {
T_5 * V_27 = ( T_5 * ) V_24 ;
T_3 * V_3 = ( T_3 * ) F_17 ( V_27 -> V_15 ) ;
T_3 * V_28 ;
T_4 * V_5 ;
V_5 = F_2 ( V_3 , V_32 , V_26 -> V_1 , V_26 -> V_9 , V_26 -> V_30 , V_13 ) ;
V_28 = F_3 ( V_5 , V_33 ) ;
F_6 ( V_27 -> V_15 , V_28 ) ;
}
static void F_21 ( void * V_24 , const void * T_7 V_25 , T_8 * V_26 ) {
T_5 * V_27 = ( T_5 * ) V_24 ;
T_3 * V_3 = ( T_3 * ) F_19 ( V_27 -> V_15 ) ;
if ( V_3 ) {
T_8 * V_34 = V_26 -> V_35 ;
if ( V_34 && V_34 -> V_36 == V_37 ) {
char * V_38 = F_22 ( V_34 -> V_1 , V_34 -> V_9 , V_34 -> V_30 ) ;
F_4 ( V_3 , L_4 , V_38 ) ;
}
}
}
static void F_23 ( void * V_24 , const void * T_7 V_25 , T_8 * V_26 ) {
T_5 * V_27 = ( T_5 * ) V_24 ;
T_3 * V_3 = ( T_3 * ) F_17 ( V_27 -> V_15 ) ;
T_3 * V_28 ;
T_4 * V_5 ;
V_5 = F_2 ( V_3 , V_39 , V_26 -> V_1 , V_26 -> V_9 , V_26 -> V_30 , V_13 ) ;
V_28 = F_3 ( V_5 , V_40 ) ;
F_6 ( V_27 -> V_15 , V_28 ) ;
}
static void F_24 ( void * V_24 , const void * T_7 V_25 , T_8 * T_9 V_25 ) {
T_5 * V_27 = ( T_5 * ) V_24 ;
F_19 ( V_27 -> V_15 ) ;
}
static char * F_25 ( T_8 * V_26 )
{
char * V_41 = ( char * ) F_26 ( V_26 -> V_30 - 1 ) ;
int V_42 , V_43 ;
V_43 = 0 ;
for ( V_42 = 1 ; V_42 < V_26 -> V_30 - 1 ; V_42 ++ ) {
T_10 V_44 = F_27 ( V_26 -> V_1 , V_26 -> V_9 + V_42 ) ;
if ( V_44 == '\\' ) {
V_42 ++ ;
V_44 = F_27 ( V_26 -> V_1 , V_26 -> V_9 + V_42 ) ;
switch ( V_44 ) {
case '\"' :
case '\\' :
case '/' :
default:
V_41 [ V_43 ++ ] = V_44 ;
break;
case 'b' :
V_41 [ V_43 ++ ] = '\b' ;
break;
case 'f' :
V_41 [ V_43 ++ ] = '\f' ;
break;
case 'n' :
V_41 [ V_43 ++ ] = '\n' ;
break;
case 'r' :
V_41 [ V_43 ++ ] = '\r' ;
break;
case 't' :
V_41 [ V_43 ++ ] = '\t' ;
break;
case 'u' :
{
T_11 V_45 = 0 ;
T_12 V_46 = TRUE ;
int V_47 ;
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ ) {
V_42 ++ ;
V_45 <<= 4 ;
V_44 = F_27 ( V_26 -> V_1 , V_26 -> V_9 + V_42 ) ;
if ( V_44 >= '0' && V_44 <= '9' )
V_45 |= ( V_44 - '0' ) ;
else if ( V_44 >= 'a' && V_44 <= 'f' )
V_45 |= ( 10 + ( V_44 - 'a' ) ) ;
else if ( V_44 >= 'A' && V_44 <= 'F' )
V_45 |= ( 10 + ( V_44 - 'A' ) ) ;
else {
V_46 = FALSE ;
break;
}
}
if ( ( F_28 ( V_45 ) ) ) {
V_44 = F_27 ( V_26 -> V_1 , V_26 -> V_9 + V_42 + 1 ) ;
if ( V_44 == '\\' ) {
V_42 ++ ;
V_44 = F_27 ( V_26 -> V_1 , V_26 -> V_9 + V_42 + 1 ) ;
if ( V_44 == 'u' ) {
T_13 V_48 = V_45 ;
T_13 V_49 = 0 ;
V_42 ++ ;
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ ) {
V_42 ++ ;
V_49 <<= 4 ;
V_44 = F_27 ( V_26 -> V_1 , V_26 -> V_9 + V_42 ) ;
if ( V_44 >= '0' && V_44 <= '9' )
V_49 |= ( V_44 - '0' ) ;
else if ( V_44 >= 'a' && V_44 <= 'f' )
V_49 |= ( 10 + ( V_44 - 'a' ) ) ;
else if ( V_44 >= 'A' && V_44 <= 'F' )
V_49 |= ( 10 + ( V_44 - 'A' ) ) ;
else {
V_46 = FALSE ;
break;
}
}
if ( ( F_29 ( V_49 ) ) ) {
V_45 = F_30 ( V_48 , V_49 ) ;
} else {
V_46 = FALSE ;
}
} else {
V_46 = FALSE ;
}
} else {
V_46 = FALSE ;
}
} else if ( ( F_29 ( V_45 ) ) ) {
V_42 ++ ;
V_46 = FALSE ;
}
if ( V_46 && F_31 ( V_45 ) && F_32 ( V_45 ) ) {
int V_50 = F_33 ( V_45 , & V_41 [ V_43 ] ) ;
V_43 += V_50 ;
} else
V_41 [ V_43 ++ ] = '?' ;
break;
}
}
} else
V_41 [ V_43 ++ ] = V_44 ;
}
V_41 [ V_43 ] = '\0' ;
return V_41 ;
}
static void F_34 ( void * V_24 , const void * T_7 V_25 , T_8 * V_26 ) {
T_5 * V_27 = ( T_5 * ) V_24 ;
T_3 * V_3 = ( T_3 * ) F_17 ( V_27 -> V_15 ) ;
T_14 V_51 = V_52 ;
if ( V_26 -> V_35 )
V_51 = ( T_14 ) V_26 -> V_35 -> V_36 ;
switch ( V_51 ) {
case V_37 :
if ( V_26 -> V_30 >= 2 )
F_35 ( V_3 , V_53 , V_26 -> V_1 , V_26 -> V_9 , V_26 -> V_30 , F_25 ( V_26 ) ) ;
else
F_2 ( V_3 , V_53 , V_26 -> V_1 , V_26 -> V_9 , V_26 -> V_30 , V_54 | V_13 ) ;
break;
case V_55 :
F_2 ( V_3 , V_56 , V_26 -> V_1 , V_26 -> V_9 , V_26 -> V_30 , V_54 | V_13 ) ;
break;
case V_57 :
F_2 ( V_3 , V_58 , V_26 -> V_1 , V_26 -> V_9 , V_26 -> V_30 , V_13 ) ;
break;
case V_59 :
F_2 ( V_3 , V_60 , V_26 -> V_1 , V_26 -> V_9 , V_26 -> V_30 , V_13 ) ;
break;
case V_61 :
F_2 ( V_3 , V_62 , V_26 -> V_1 , V_26 -> V_9 , V_26 -> V_30 , V_13 ) ;
break;
case V_63 :
case V_64 :
break;
default:
F_36 ( V_3 , V_26 -> V_1 , V_26 -> V_9 , V_26 -> V_30 , L_5 , F_37 ( V_26 -> V_1 , V_26 -> V_9 , V_26 -> V_30 ) ) ;
break;
}
}
static void F_38 ( void ) {
static T_15 V_65 ;
static T_15 V_66 ;
T_15 * V_67 , * V_68 ;
T_15 * V_69 ;
T_15 * V_70 ;
T_15 * V_71 , * V_72 ;
T_15 * V_73 ;
T_15 * V_74 ;
#define F_39 ( V_36 , V_11 , T_16 , T_17 , T_18 ) \
tvbparse_some(id, 0, 1, private_data, before_cb, after_cb, wanted)
T_15 * V_75 = F_40 ( - 1 , L_6 , NULL , NULL , NULL ) ;
V_70 = F_41 ( V_37 , NULL , NULL , NULL ,
V_75 ,
F_42 ( - 1 , 0 , V_76 , NULL , NULL , NULL ,
F_43 ( - 1 , NULL , NULL , NULL ,
F_44 ( - 1 , 0 , 0 , L_6 L_7 , NULL , NULL , NULL ) ,
F_41 ( - 1 , NULL , NULL , NULL ,
F_40 ( - 1 , L_7 , NULL , NULL , NULL ) ,
F_43 ( - 1 , NULL , NULL , NULL ,
F_45 ( - 1 , 0 , 1 , L_6 L_7 L_8 , NULL , NULL , NULL ) ,
F_41 ( - 1 , NULL , NULL , NULL ,
F_40 ( - 1 , L_9 , NULL , NULL , NULL ) ,
F_45 ( - 1 , 4 , 4 , L_10 , NULL , NULL , NULL ) ,
NULL ) ,
NULL ) ,
NULL ) ,
NULL )
) ,
V_75 ,
NULL ) ;
V_74 = F_40 ( - 1 , L_11 , NULL , NULL , NULL ) ;
V_72 = F_43 ( - 1 , NULL , NULL , NULL ,
F_40 ( - 1 , L_12 , NULL , NULL , NULL ) ,
F_41 ( - 1 , NULL , NULL , NULL ,
F_45 ( - 1 , 1 , 1 , L_13 , NULL , NULL , NULL ) ,
F_39 ( - 1 , NULL , NULL , NULL ,
F_45 ( - 1 , 0 , 0 , L_14 , NULL , NULL , NULL ) ) ,
NULL ) ,
NULL ) ;
V_71 = F_41 ( V_55 , NULL , NULL , NULL ,
F_39 ( - 1 , NULL , NULL , NULL ,
F_45 ( - 1 , 0 , 1 , L_15 , NULL , NULL , NULL ) ) ,
V_72 ,
F_39 ( - 1 , NULL , NULL , NULL ,
F_41 ( - 1 , NULL , NULL , NULL ,
F_40 ( - 1 , L_16 , NULL , NULL , NULL ) ,
F_45 ( - 1 , 1 , 0 , L_14 , NULL , NULL , NULL ) ,
NULL ) ) ,
F_39 ( - 1 , NULL , NULL , NULL ,
F_41 ( - 1 , NULL , NULL , NULL ,
F_40 ( - 1 , L_17 , NULL , NULL , NULL ) ,
F_39 ( - 1 , NULL , NULL , NULL ,
F_45 ( - 1 , 0 , 1 , L_18 , NULL , NULL , NULL ) ) ,
F_45 ( - 1 , 1 , 0 , L_14 , NULL , NULL , NULL ) ,
NULL ) ) ,
NULL ) ;
V_73 = F_43 ( - 1 , NULL , NULL , F_34 ,
F_46 ( V_57 , L_19 , NULL , NULL , NULL ) ,
F_46 ( V_59 , L_20 , NULL , NULL , NULL ) ,
F_46 ( V_61 , L_21 , NULL , NULL , NULL ) ,
& V_65 ,
& V_66 ,
V_71 ,
V_70 ,
NULL ) ;
V_68 = F_41 ( V_64 , NULL , F_23 , F_24 ,
F_40 ( - 1 , L_22 , NULL , NULL , NULL ) ,
F_39 ( - 1 , NULL , NULL , NULL ,
F_41 ( - 1 , NULL , NULL , NULL ,
V_73 ,
F_42 ( - 1 , 0 , V_76 , NULL , NULL , NULL ,
F_41 ( - 1 , NULL , NULL , NULL ,
V_74 ,
V_73 ,
NULL ) ) ,
NULL )
) ,
F_40 ( - 1 , L_23 , NULL , NULL , NULL ) ,
NULL ) ;
V_66 = * V_68 ;
V_69 = F_41 ( - 1 , NULL , F_20 , F_21 ,
V_70 ,
F_40 ( - 1 , L_24 , NULL , NULL , NULL ) ,
V_73 ,
NULL ) ;
V_67 = F_41 ( V_63 , NULL , F_16 , F_18 ,
F_40 ( - 1 , L_25 , NULL , NULL , NULL ) ,
F_39 ( - 1 , NULL , NULL , NULL ,
F_41 ( - 1 , NULL , NULL , NULL ,
V_69 ,
F_42 ( - 1 , 0 , V_76 , NULL , NULL , NULL ,
F_41 ( - 1 , NULL , NULL , NULL ,
V_74 ,
V_69 ,
NULL ) ) ,
NULL )
) ,
F_40 ( - 1 , L_26 , NULL , NULL , NULL ) ,
NULL ) ;
V_65 = * V_67 ;
V_16 = F_45 ( - 1 , 1 , 0 , L_27 , NULL , NULL , NULL ) ;
V_17 = F_43 ( - 1 , NULL , NULL , NULL ,
V_67 ,
V_68 ,
NULL ) ;
}
void
F_47 ( void ) {
static T_19 * V_77 [] = {
& V_14 ,
& V_40 ,
& V_31 ,
& V_33
} ;
static T_20 V_78 [] = {
{ & V_39 ,
{ L_28 , L_29 , V_79 , V_80 , NULL , 0x00 , L_30 , V_81 }
} ,
{ & V_29 ,
{ L_31 , L_32 , V_79 , V_80 , NULL , 0x00 , L_33 , V_81 }
} ,
{ & V_32 ,
{ L_34 , L_35 , V_79 , V_80 , NULL , 0x00 , L_36 , V_81 } ,
} ,
{ & V_53 ,
{ L_37 , L_38 , V_82 , V_80 , NULL , 0x00 , L_39 , V_81 } ,
} ,
{ & V_56 ,
{ L_40 , L_41 , V_82 , V_80 , NULL , 0x00 , L_42 , V_81 } ,
} ,
{ & V_58 ,
{ L_43 , L_44 , V_79 , V_80 , NULL , 0x00 , L_45 , V_81 } ,
} ,
{ & V_60 ,
{ L_46 , L_47 , V_79 , V_80 , NULL , 0x00 , L_48 , V_81 } ,
} ,
{ & V_62 ,
{ L_49 , L_50 , V_79 , V_80 , NULL , 0x00 , L_51 , V_81 } ,
} ,
} ;
V_12 = F_48 ( L_52 , L_53 , L_54 ) ;
F_49 ( V_12 , V_78 , F_50 ( V_78 ) ) ;
F_51 ( V_77 , F_50 ( V_77 ) ) ;
F_52 ( L_54 , F_1 , V_12 ) ;
F_38 () ;
}
void
F_53 ( void )
{
T_21 V_83 ;
V_83 = F_54 ( L_54 ) ;
F_55 ( L_55 , L_56 , V_83 ) ;
F_55 ( L_55 , L_57 , V_83 ) ;
F_55 ( L_55 , L_58 , V_83 ) ;
V_21 = F_54 ( L_59 ) ;
}
