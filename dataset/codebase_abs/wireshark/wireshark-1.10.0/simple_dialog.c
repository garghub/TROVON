static T_1 *
F_1 ( T_2 type , T_2 V_1 , char * V_2 )
{
T_1 * V_3 , * V_4 , * V_5 , * V_6 , * V_7 , * V_8 , * V_9 ,
* V_10 , * V_11 , * V_12 , * V_13 , * V_14 , * V_15 ;
switch ( type ) {
case V_16 :
V_7 = F_2 ( V_17 , V_18 ) ;
break;
case V_19 :
V_7 = F_2 ( V_20 , V_18 ) ;
break;
case V_21 :
V_7 = F_2 ( V_22 , V_18 ) ;
break;
case V_23 :
V_7 = F_2 ( V_24 , V_18 ) ;
break;
case V_25 :
default :
V_7 = F_2 ( V_17 , V_18 ) ;
break;
}
if( V_1 == V_26 ) {
V_3 = F_3 () ;
} else {
#ifdef F_4
V_3 = F_5 ( L_1 ) ;
#else
V_3 = F_5 ( L_2 ) ;
#endif
}
F_6 ( F_7 ( V_3 ) , TRUE ) ;
F_8 ( F_9 ( V_3 ) , 6 ) ;
V_4 = F_10 ( V_27 , 12 , FALSE ) ;
F_11 ( F_9 ( V_3 ) , V_4 ) ;
F_12 ( V_4 ) ;
V_5 = F_10 ( V_28 , 12 , FALSE ) ;
F_8 ( F_9 ( V_4 ) , 6 ) ;
F_13 ( F_14 ( V_4 ) , V_5 , TRUE , TRUE , 0 ) ;
F_12 ( V_5 ) ;
F_15 ( F_16 ( V_7 ) , 0.5f , 0.0f ) ;
F_13 ( F_14 ( V_5 ) , V_7 , TRUE , TRUE , 0 ) ;
F_12 ( V_7 ) ;
V_6 = F_10 ( V_27 , 6 , FALSE ) ;
F_17 ( F_14 ( V_6 ) , 24 ) ;
F_13 ( F_14 ( V_5 ) , V_6 , TRUE , TRUE , 0 ) ;
F_12 ( V_6 ) ;
V_8 = F_18 ( V_2 ) ;
F_19 ( F_20 ( V_8 ) , V_2 ) ;
F_21 ( F_20 ( V_8 ) , TRUE ) ;
F_22 ( F_23 ( V_8 ) ,
L_3 , FALSE , NULL ) ;
F_24 ( F_20 ( V_8 ) , V_29 ) ;
F_15 ( F_16 ( V_7 ) , 0.5f , 0.0f ) ;
F_13 ( F_14 ( V_6 ) , V_8 , TRUE , TRUE , 0 ) ;
F_25 ( F_20 ( V_8 ) , TRUE ) ;
F_12 ( V_8 ) ;
if( V_1 == V_26 ) {
F_12 ( V_3 ) ;
return V_3 ;
}
V_9 = F_26 ( L_4 ) ;
F_13 ( F_14 ( V_6 ) , V_9 , TRUE , TRUE , 0 ) ;
F_27 ( F_28 ( V_3 ) , V_30 , V_9 ) ;
switch( V_1 ) {
case ( V_31 ) :
V_10 = F_29 ( V_32 , NULL ) ;
break;
case ( V_31 | V_33 ) :
V_10 = F_29 ( V_32 , V_34 , NULL ) ;
break;
case ( V_35 | V_33 ) :
V_10 = F_29 ( V_36 , V_34 , NULL ) ;
break;
case ( V_37 ) :
V_10 = F_29 ( V_38 , V_39 , V_34 , NULL ) ;
break;
case ( V_40 ) :
V_10 = F_29 ( V_41 , V_42 , V_34 , NULL ) ;
break;
case ( V_43 ) :
V_10 = F_29 ( V_41 , V_44 , V_34 , NULL ) ;
break;
case ( V_45 ) :
V_10 = F_29 ( V_44 , V_34 , NULL ) ;
break;
case ( V_46 ) :
V_10 = F_29 ( V_38 , V_39 , NULL ) ;
break;
default:
F_30 () ;
V_10 = NULL ;
break;
}
F_13 ( F_14 ( V_4 ) , V_10 , TRUE , TRUE , 0 ) ;
F_12 ( V_10 ) ;
V_11 = ( T_1 * ) F_31 ( F_28 ( V_10 ) , V_32 ) ;
if( V_11 ) {
F_27 ( F_28 ( V_11 ) , V_47 , F_32 ( V_31 ) ) ;
F_33 ( V_11 , L_5 , F_34 ( V_48 ) , V_3 ) ;
}
V_14 = ( T_1 * ) F_31 ( F_28 ( V_10 ) , V_41 ) ;
if ( V_14 ) {
F_27 ( F_28 ( V_14 ) , V_47 , F_32 ( V_49 ) ) ;
F_33 ( V_14 , L_5 , F_34 ( V_48 ) , V_3 ) ;
}
V_15 = ( T_1 * ) F_31 ( F_28 ( V_10 ) , V_42 ) ;
if ( V_15 ) {
F_27 ( F_28 ( V_15 ) , V_47 , F_32 ( V_50 ) ) ;
F_33 ( V_15 , L_5 , F_34 ( V_48 ) , V_3 ) ;
}
V_15 = ( T_1 * ) F_31 ( F_28 ( V_10 ) , V_44 ) ;
if ( V_15 ) {
F_27 ( F_28 ( V_15 ) , V_47 , F_32 ( V_51 ) ) ;
F_33 ( V_15 , L_5 , F_34 ( V_48 ) , V_3 ) ;
}
V_13 = ( T_1 * ) F_31 ( F_28 ( V_10 ) , V_36 ) ;
if( V_13 ) {
F_27 ( F_28 ( V_13 ) , V_47 , F_32 ( V_35 ) ) ;
F_33 ( V_13 , L_5 , F_34 ( V_48 ) , V_3 ) ;
}
V_12 = ( T_1 * ) F_31 ( F_28 ( V_10 ) , V_38 ) ;
if( V_12 ) {
F_27 ( F_28 ( V_12 ) , V_47 , F_32 ( V_52 ) ) ;
F_33 ( V_12 , L_5 , F_34 ( V_48 ) , V_3 ) ;
}
V_13 = ( T_1 * ) F_31 ( F_28 ( V_10 ) , V_39 ) ;
if( V_13 ) {
F_27 ( F_28 ( V_13 ) , V_47 , F_32 ( V_53 ) ) ;
F_33 ( V_13 , L_5 , F_34 ( V_48 ) , V_3 ) ;
}
V_13 = ( T_1 * ) F_31 ( F_28 ( V_10 ) , V_34 ) ;
if( V_13 ) {
F_27 ( F_28 ( V_13 ) , V_47 , F_32 ( V_33 ) ) ;
F_35 ( V_3 , V_13 , V_48 ) ;
}
if( ! V_13 ) {
if( V_12 ) {
F_35 ( V_3 , V_12 , V_48 ) ;
} else {
F_35 ( V_3 , V_11 , V_48 ) ;
}
}
F_36 ( V_10 , 0 ) ;
F_12 ( V_3 ) ;
return V_3 ;
}
void
F_37 ( void )
{
T_3 * V_54 ;
while ( V_55 != NULL ) {
V_54 = ( T_3 * ) V_55 -> V_56 ;
V_55 = F_38 ( V_55 , V_54 ) ;
F_1 ( V_54 -> type , V_54 -> V_1 ,
V_54 -> V_2 ) ;
F_39 ( V_54 -> V_2 ) ;
F_39 ( V_54 ) ;
}
}
T_4
F_40 ( T_5 type , T_2 V_1 , const T_6 * V_57 , T_7 V_58 )
{
T_6 * V_2 ;
T_3 * V_54 ;
T_1 * V_3 ;
T_8 V_59 = ( T_8 ) 0 ;
V_2 = F_41 ( V_57 , V_58 ) ;
if ( V_60 != NULL ) {
V_59 = F_42 ( F_43 ( V_60 ) ) ;
}
if ( ( V_60 == NULL ) || V_59 & V_61
|| V_59 & V_62 ) {
V_54 = ( T_3 * ) F_44 ( sizeof ( T_3 ) ) ;
V_54 -> type = type ;
V_54 -> V_1 = V_1 ;
V_54 -> V_2 = V_2 ;
V_55 = F_45 ( V_55 , V_54 ) ;
return NULL ;
}
F_37 () ;
V_3 = F_1 ( type , V_1 , V_2 ) ;
F_39 ( V_2 ) ;
return V_3 ;
}
T_4
F_46 ( T_5 type , T_2 V_1 , const T_6 * V_57 , ... )
{
T_7 V_58 ;
T_4 V_63 ;
va_start ( V_58 , V_57 ) ;
V_63 = F_40 ( type , V_1 , V_57 , V_58 ) ;
va_end ( V_58 ) ;
return V_63 ;
}
static void
V_48 ( T_1 * V_64 , T_4 V_3 ) {
T_2 V_65 = F_47 ( F_31 ( F_28 ( V_64 ) , V_47 ) ) ;
T_9 V_66 = ( T_9 ) F_31 ( F_28 ( V_3 ) , V_67 ) ;
T_4 V_56 = F_31 ( F_28 ( V_3 ) , V_68 ) ;
if ( V_66 )
( V_66 ) ( V_3 , V_65 , V_56 ) ;
F_48 ( F_49 ( V_3 ) ) ;
}
void
F_50 ( T_4 V_69 )
{
F_48 ( F_49 ( V_69 ) ) ;
}
void
F_51 ( T_4 V_69 , T_9 V_66 , T_4 V_56 )
{
F_27 ( F_28 ( F_49 ( V_69 ) ) , V_67 , V_66 ) ;
F_27 ( F_28 ( F_49 ( V_69 ) ) , V_68 , V_56 ) ;
}
void
F_52 ( T_4 V_69 , const T_6 * V_70 ) {
T_1 * V_9 = ( T_1 * ) F_31 ( F_28 ( V_69 ) , V_30 ) ;
F_53 ( F_54 ( V_9 ) , V_70 ) ;
F_12 ( V_9 ) ;
}
T_10
F_55 ( T_4 V_69 ) {
T_1 * V_9 = ( T_1 * ) F_31 ( F_28 ( F_49 ( V_69 ) ) , V_30 ) ;
return F_56 ( F_57 ( V_9 ) ) ;
}
const char *
F_58 ( void ) {
return L_6 ;
}
const char *
F_59 ( void ) {
return L_7 ;
}
char *
F_60 ( const char * V_71 )
{
char * V_72 ;
if ( V_71 ) {
V_72 = F_61 ( V_71 ) ;
} else {
V_72 = NULL ;
}
return V_72 ;
}
static void
F_62 ( T_5 type , T_10 * V_73 ,
const char * V_74 , const char * V_57 ,
T_7 V_58 )
{
T_11 V_75 ;
T_6 * V_2 ;
T_1 * V_76 ;
T_1 * V_77 = NULL ;
if ( V_73 != NULL ) {
if ( * V_73 ) {
return;
}
}
switch ( type ) {
case V_25 :
V_75 = V_78 ;
break;
case V_16 :
V_75 = V_79 ;
break;
case V_21 :
V_75 = V_80 ;
break;
default:
F_30 () ;
V_75 = V_78 ;
break;
}
V_2 = F_41 ( V_57 , V_58 ) ;
V_76 = F_63 ( F_7 ( V_60 ) ,
( V_81 ) ( V_82 | V_83 ) ,
V_75 ,
V_84 ,
L_8 , V_2 ) ;
F_39 ( V_2 ) ;
if ( V_74 != NULL )
F_64 ( F_65 ( V_76 ) ,
L_8 , V_74 ) ;
if ( V_73 != NULL ) {
V_77 = F_26 ( L_9 ) ;
F_8 ( F_9 ( V_77 ) , 12 ) ;
F_13 ( F_14 ( F_66 ( F_67 ( V_76 ) ) ) ,
V_77 , TRUE , TRUE , 0 ) ;
F_12 ( V_77 ) ;
}
F_68 ( F_67 ( V_76 ) ) ;
if ( V_73 != NULL ) {
* V_73 = F_56 ( F_57 ( V_77 ) ) ;
}
F_69 ( V_76 ) ;
}
void
F_70 ( T_5 type , T_10 * V_73 ,
const char * V_74 , const char * V_57 , ... )
{
T_7 V_58 ;
va_start ( V_58 , V_57 ) ;
F_62 ( type , V_73 , V_74 , V_57 , V_58 ) ;
va_end ( V_58 ) ;
}
void
F_71 ( const char * V_57 , T_7 V_58 )
{
F_62 ( V_21 , NULL , NULL , V_57 , V_58 ) ;
}
void
F_72 ( const char * V_57 , ... )
{
T_7 V_58 ;
va_start ( V_58 , V_57 ) ;
F_62 ( V_21 , NULL , NULL , V_57 , V_58 ) ;
va_end ( V_58 ) ;
}
