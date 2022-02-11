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
F_11 ( F_9 ( V_4 ) , V_5 ) ;
F_12 ( V_5 ) ;
F_13 ( F_14 ( V_7 ) , 0.5f , 0.0f ) ;
F_11 ( F_9 ( V_5 ) , V_7 ) ;
F_12 ( V_7 ) ;
V_6 = F_10 ( V_27 , 6 , FALSE ) ;
F_15 ( F_16 ( V_6 ) , 24 ) ;
F_11 ( F_9 ( V_5 ) , V_6 ) ;
F_12 ( V_6 ) ;
V_8 = F_17 ( V_2 ) ;
F_18 ( F_19 ( V_8 ) , V_2 ) ;
F_20 ( F_19 ( V_8 ) , TRUE ) ;
F_21 ( F_22 ( V_8 ) ,
L_3 , FALSE , NULL ) ;
F_23 ( F_19 ( V_8 ) , V_29 ) ;
F_13 ( F_14 ( V_7 ) , 0.5f , 0.0f ) ;
F_11 ( F_9 ( V_6 ) , V_8 ) ;
F_24 ( F_19 ( V_8 ) , TRUE ) ;
F_12 ( V_8 ) ;
if( V_1 == V_26 ) {
F_12 ( V_3 ) ;
return V_3 ;
}
V_9 = F_25 ( L_4 ) ;
F_11 ( F_9 ( V_6 ) , V_9 ) ;
F_26 ( F_27 ( V_3 ) , V_30 , V_9 ) ;
switch( V_1 ) {
case ( V_31 ) :
V_10 = F_28 ( V_32 , NULL ) ;
break;
case ( V_31 | V_33 ) :
V_10 = F_28 ( V_32 , V_34 , NULL ) ;
break;
case ( V_35 | V_33 ) :
V_10 = F_28 ( V_36 , V_34 , NULL ) ;
break;
case ( V_37 ) :
V_10 = F_28 ( V_38 , V_39 , V_34 , NULL ) ;
break;
case ( V_40 ) :
V_10 = F_28 ( V_41 , V_42 , V_34 , NULL ) ;
break;
case ( V_43 ) :
V_10 = F_28 ( V_41 , V_44 , V_34 , NULL ) ;
break;
case ( V_45 ) :
V_10 = F_28 ( V_44 , V_34 , NULL ) ;
break;
case ( V_46 ) :
V_10 = F_28 ( V_38 , V_39 , NULL ) ;
break;
default:
F_29 () ;
V_10 = NULL ;
break;
}
F_11 ( F_9 ( V_4 ) , V_10 ) ;
F_12 ( V_10 ) ;
V_11 = F_30 ( F_27 ( V_10 ) , V_32 ) ;
if( V_11 ) {
F_26 ( F_27 ( V_11 ) , V_47 , F_31 ( V_31 ) ) ;
F_32 ( V_11 , L_5 , F_33 ( V_48 ) , V_3 ) ;
}
V_14 = F_30 ( F_27 ( V_10 ) , V_41 ) ;
if ( V_14 ) {
F_26 ( F_27 ( V_14 ) , V_47 , F_31 ( V_49 ) ) ;
F_32 ( V_14 , L_5 , F_33 ( V_48 ) , V_3 ) ;
}
V_15 = F_30 ( F_27 ( V_10 ) , V_42 ) ;
if ( V_15 ) {
F_26 ( F_27 ( V_15 ) , V_47 , F_31 ( V_50 ) ) ;
F_32 ( V_15 , L_5 , F_33 ( V_48 ) , V_3 ) ;
}
V_15 = F_30 ( F_27 ( V_10 ) , V_44 ) ;
if ( V_15 ) {
F_26 ( F_27 ( V_15 ) , V_47 , F_31 ( V_51 ) ) ;
F_32 ( V_15 , L_5 , F_33 ( V_48 ) , V_3 ) ;
}
V_13 = F_30 ( F_27 ( V_10 ) , V_36 ) ;
if( V_13 ) {
F_26 ( F_27 ( V_13 ) , V_47 , F_31 ( V_35 ) ) ;
F_32 ( V_13 , L_5 , F_33 ( V_48 ) , V_3 ) ;
}
V_12 = F_30 ( F_27 ( V_10 ) , V_38 ) ;
if( V_12 ) {
F_26 ( F_27 ( V_12 ) , V_47 , F_31 ( V_52 ) ) ;
F_32 ( V_12 , L_5 , F_33 ( V_48 ) , V_3 ) ;
}
V_13 = F_30 ( F_27 ( V_10 ) , V_39 ) ;
if( V_13 ) {
F_26 ( F_27 ( V_13 ) , V_47 , F_31 ( V_53 ) ) ;
F_32 ( V_13 , L_5 , F_33 ( V_48 ) , V_3 ) ;
}
V_13 = F_30 ( F_27 ( V_10 ) , V_34 ) ;
if( V_13 ) {
F_26 ( F_27 ( V_13 ) , V_47 , F_31 ( V_33 ) ) ;
F_34 ( V_3 , V_13 , V_48 ) ;
}
if( ! V_13 ) {
if( V_12 ) {
F_34 ( V_3 , V_12 , V_48 ) ;
} else {
F_34 ( V_3 , V_11 , V_48 ) ;
}
}
F_35 ( V_10 , 0 ) ;
F_12 ( V_3 ) ;
return V_3 ;
}
void
F_36 ( void )
{
T_3 * V_54 ;
while ( V_55 != NULL ) {
V_54 = V_55 -> V_56 ;
V_55 = F_37 ( V_55 , V_54 ) ;
F_1 ( V_54 -> type , V_54 -> V_1 ,
V_54 -> V_2 ) ;
F_38 ( V_54 -> V_2 ) ;
F_38 ( V_54 ) ;
}
}
T_4
F_39 ( T_5 type , T_2 V_1 , const T_6 * V_57 , T_7 V_58 )
{
T_6 * V_2 ;
T_3 * V_54 ;
T_1 * V_3 ;
T_8 V_59 = 0 ;
V_2 = F_40 ( V_57 , V_58 ) ;
if ( V_60 != NULL ) {
V_59 = F_41 ( F_42 ( V_60 ) ) ;
}
if ( V_60 == NULL || V_59 & V_61
|| V_59 & V_62 ) {
V_54 = F_43 ( sizeof ( T_3 ) ) ;
V_54 -> type = type ;
V_54 -> V_1 = V_1 ;
V_54 -> V_2 = V_2 ;
V_55 = F_44 ( V_55 , V_54 ) ;
return NULL ;
}
F_36 () ;
V_3 = F_1 ( type , V_1 , V_2 ) ;
F_38 ( V_2 ) ;
return V_3 ;
}
T_4
F_45 ( T_5 type , T_2 V_1 , const T_6 * V_57 , ... )
{
T_7 V_58 ;
T_4 V_63 ;
va_start ( V_58 , V_57 ) ;
V_63 = F_39 ( type , V_1 , V_57 , V_58 ) ;
va_end ( V_58 ) ;
return V_63 ;
}
static void
V_48 ( T_1 * V_64 , T_4 V_3 ) {
T_2 V_65 = F_46 ( F_30 ( F_27 ( V_64 ) , V_47 ) ) ;
T_9 V_66 = F_30 ( F_27 ( V_3 ) , V_67 ) ;
T_4 V_56 = F_30 ( F_27 ( V_3 ) , V_68 ) ;
if ( V_66 )
( V_66 ) ( V_3 , V_65 , V_56 ) ;
F_47 ( F_48 ( V_3 ) ) ;
}
void
F_49 ( T_4 V_69 )
{
F_47 ( F_48 ( V_69 ) ) ;
}
void F_50 ( T_4 V_69 , T_9 V_66 , T_4 V_56 )
{
F_26 ( F_27 ( F_48 ( V_69 ) ) , V_67 , V_66 ) ;
F_26 ( F_27 ( F_48 ( V_69 ) ) , V_68 , V_56 ) ;
}
void F_51 ( T_4 V_69 , T_6 * T_10 V_70 ) {
T_1 * V_9 = F_30 ( F_27 ( V_69 ) , V_30 ) ;
F_52 ( F_53 ( V_9 ) , T_10 ) ;
F_12 ( V_9 ) ;
}
T_11 F_54 ( T_4 V_69 ) {
T_1 * V_9 = F_30 ( F_27 ( F_48 ( V_69 ) ) , V_30 ) ;
return F_55 ( F_56 ( V_9 ) ) ;
}
char *
F_57 ( void ) {
return L_6 ;
}
char *
F_58 ( void ) {
return L_7 ;
}
char *
F_59 ( const char * V_71 )
{
char * V_72 ;
if ( V_71 ) {
V_72 = F_60 ( V_71 ) ;
} else {
V_72 = NULL ;
}
return V_72 ;
}
static void
F_61 ( T_5 type , T_11 * V_73 ,
const char * V_74 , const char * V_57 ,
T_7 V_58 )
{
T_12 V_75 ;
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
F_29 () ;
V_75 = V_78 ;
break;
}
V_2 = F_40 ( V_57 , V_58 ) ;
V_76 = F_62 ( F_7 ( V_60 ) ,
V_81 | V_82 ,
V_75 ,
V_83 ,
L_8 , V_2 ) ;
F_38 ( V_2 ) ;
if ( V_74 != NULL )
F_63 ( F_64 ( V_76 ) ,
L_8 , V_74 ) ;
if ( V_73 != NULL ) {
V_77 = F_25 ( L_9 ) ;
F_8 ( F_9 ( V_77 ) , 12 ) ;
F_65 ( F_16 ( F_66 ( F_67 ( V_76 ) ) ) ,
V_77 , TRUE , TRUE , 0 ) ;
F_12 ( V_77 ) ;
}
F_68 ( F_67 ( V_76 ) ) ;
if ( V_73 != NULL ) {
* V_73 = F_55 ( F_56 ( V_77 ) ) ;
}
F_69 ( V_76 ) ;
}
void
F_70 ( T_5 type , T_11 * V_73 ,
const char * V_74 , const char * V_57 , ... )
{
T_7 V_58 ;
va_start ( V_58 , V_57 ) ;
F_61 ( type , V_73 , V_74 , V_57 , V_58 ) ;
va_end ( V_58 ) ;
}
void
F_71 ( const char * V_57 , T_7 V_58 )
{
F_61 ( V_21 , NULL , NULL , V_57 , V_58 ) ;
}
void
F_72 ( const char * V_57 , ... )
{
T_7 V_58 ;
va_start ( V_58 , V_57 ) ;
F_61 ( V_21 , NULL , NULL , V_57 , V_58 ) ;
va_end ( V_58 ) ;
}
