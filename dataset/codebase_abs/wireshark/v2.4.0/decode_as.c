void F_1 ( T_1 * V_1 )
{
T_2 V_2 ;
F_2 ( V_1 -> V_3 ) ;
F_2 ( V_1 -> V_4 ) ;
F_2 ( V_1 -> V_5 ) ;
V_2 = F_3 ( V_1 -> V_6 ) ;
if ( V_2 != NULL )
{
F_4 ( V_2 ) ;
}
V_7 = F_5 ( V_7 , V_1 ) ;
}
static void
F_6 ( const T_3 * V_6 , T_4 V_8 , T_4 V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_9 ;
const T_3 * V_12 ;
T_5 V_13 ;
T_6 V_14 ;
V_14 = ( T_6 ) V_8 ;
V_12 = F_7 ( V_14 ) ;
V_13 = F_8 ( V_14 ) ;
if ( V_13 >= 0 && ! F_9 ( F_10 ( V_13 ) ) )
return;
V_11 -> V_15 ( V_6 , V_12 , V_8 , V_11 -> V_16 ) ;
}
void F_11 ( const T_3 * V_6 , T_7 V_15 , T_4 V_16 )
{
struct V_10 V_11 ;
V_11 . V_15 = V_15 ;
V_11 . V_16 = V_16 ;
F_12 ( V_6 , F_6 , & V_11 ) ;
}
T_8 F_13 ( const T_3 * V_17 , T_9 V_18 )
{
switch ( F_14 ( V_17 ) ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
F_15 ( V_17 , F_16 ( V_18 ) ) ;
return TRUE ;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
F_17 ( V_17 , ( ! V_18 ) ? L_1 : ( T_3 * ) V_18 ) ;
return TRUE ;
default:
return FALSE ;
} ;
return TRUE ;
}
T_8 F_18 ( const T_3 * V_17 , T_9 V_18 , T_4 V_14 , T_3 * T_10 V_27 )
{
T_6 * V_28 = ( T_6 * ) V_14 ;
if ( V_28 != NULL ) {
switch ( F_14 ( V_17 ) ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
F_19 ( V_17 , F_16 ( V_18 ) , * V_28 ) ;
return TRUE ;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
F_20 ( V_17 , ( ! V_18 ) ? L_1 : ( T_3 * ) V_18 , * V_28 ) ;
return TRUE ;
default:
return FALSE ;
} ;
return FALSE ;
}
return TRUE ;
}
static T_11
F_21 ( T_3 * V_29 , const T_3 * V_8 ,
void * V_9 ,
T_8 T_12 V_27 )
{
T_3 * V_30 [ 4 ] = { NULL , NULL , NULL , NULL } ;
T_3 V_31 [ 4 ] = { ',' , ',' , ',' , '\0' } ;
T_3 * V_32 ;
T_13 V_13 , V_33 ;
T_14 * V_34 = ( T_14 * ) V_9 ;
T_2 V_35 ;
T_11 V_36 = V_37 ;
T_8 V_38 = FALSE ;
if ( strcmp ( V_29 , V_39 ) == 0 ) {
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
V_32 = strchr ( V_8 , V_31 [ V_13 ] ) ;
if ( V_32 == NULL ) {
for ( V_33 = 0 ; V_33 < V_13 ; V_33 ++ ) {
F_22 ( V_30 [ V_33 ] ) ;
}
return V_40 ;
}
V_30 [ V_13 ] = F_23 ( V_8 , V_32 - V_8 ) ;
V_8 = V_32 + 1 ;
}
V_35 = F_3 ( V_30 [ 0 ] ) ;
if ( V_35 != NULL ) {
T_6 V_14 ;
T_15 V_41 ;
T_16 * V_42 ;
T_17 * V_43 ;
const char * V_12 ;
V_41 = F_24 ( V_35 ) ;
V_14 = F_25 ( V_35 , V_30 [ 3 ] ) ;
if ( V_14 != NULL || F_26 ( V_30 [ 3 ] , V_44 ) == 0 ) {
V_38 = TRUE ;
}
if ( V_38 ) {
if ( F_27 ( V_41 ) ) {
F_20 ( V_30 [ 0 ] , V_30 [ 1 ] , V_14 ) ;
} else {
char * V_45 ;
long V_46 ;
V_46 = strtol ( V_30 [ 1 ] , & V_45 , 0 ) ;
if ( V_45 == V_30 [ 0 ] || * V_45 != '\0' || V_46 < 0 ||
( unsigned long ) V_46 > V_47 ) {
V_36 = V_40 ;
V_38 = FALSE ;
} else {
F_19 ( V_30 [ 0 ] , ( T_13 ) V_46 , V_14 ) ;
}
V_12 = F_28 ( F_8 ( V_14 ) ) ;
V_43 = F_29 ( V_12 ) ;
V_42 = F_30 ( V_43 , V_30 [ 0 ] ) ;
if ( V_42 != NULL ) {
T_8 V_48 = FALSE ;
if ( F_31 ( V_34 , V_12 ) == NULL ) {
V_48 = TRUE ;
F_32 ( V_34 , ( T_4 ) V_12 , ( T_4 ) V_12 ) ;
}
F_33 ( V_42 , ( T_13 ) V_46 , V_48 ) ;
V_43 -> V_49 = TRUE ;
}
}
}
if ( V_38 ) {
F_34 ( V_30 [ 0 ] , V_41 , V_30 [ 1 ] , NULL , NULL ) ;
}
} else {
V_36 = V_40 ;
}
} else {
V_36 = V_50 ;
}
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
F_22 ( V_30 [ V_13 ] ) ;
}
return V_36 ;
}
void
F_35 ( void )
{
char * V_51 ;
T_18 * V_52 ;
if ( V_53 ) {
F_36 () ;
}
V_51 = F_37 ( V_54 , TRUE ) ;
if ( ( V_52 = F_38 ( V_51 , L_2 ) ) != NULL ) {
T_14 * V_34 = F_39 ( V_55 , V_56 ) ;
F_40 ( V_51 , V_52 , F_21 , V_34 ) ;
F_41 ( V_34 ) ;
fclose ( V_52 ) ;
}
F_22 ( V_51 ) ;
}
static void
F_42 ( const T_3 * V_6 , T_15 V_41 ,
T_4 V_29 , T_4 V_8 , T_4 V_9 )
{
T_18 * V_57 = ( T_18 * ) V_9 ;
T_6 V_58 , V_59 ;
const T_3 * V_60 , * V_61 ;
V_58 = F_43 ( ( V_62 * ) V_8 ) ;
if ( V_58 == NULL )
V_60 = V_44 ;
else
V_60 = F_7 ( V_58 ) ;
V_59 = F_44 ( ( V_62 * ) V_8 ) ;
if ( V_59 == NULL )
V_61 = V_44 ;
else
V_61 = F_7 ( V_59 ) ;
switch ( V_41 ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
fprintf ( V_57 ,
V_39 L_3 ,
V_6 , F_16 ( V_29 ) , V_61 ,
V_60 ) ;
break;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
fprintf ( V_57 ,
V_39 L_4 ,
V_6 , ( T_3 * ) V_29 , V_61 ,
V_60 ) ;
break;
default:
F_45 () ;
break;
}
}
int
F_46 ( T_3 * * V_63 )
{
char * V_64 ;
char * V_51 ;
T_18 * V_57 ;
if ( F_47 ( & V_64 ) == - 1 ) {
* V_63 = F_48 ( L_5 ,
V_64 , F_49 ( V_65 ) ) ;
F_22 ( V_64 ) ;
return - 1 ;
}
V_51 = F_37 ( V_54 , TRUE ) ;
if ( ( V_57 = F_38 ( V_51 , L_6 ) ) == NULL ) {
* V_63 = F_48 ( L_7 ,
V_51 , F_49 ( V_65 ) ) ;
F_22 ( V_51 ) ;
return - 1 ;
}
fputs ( L_8 V_66 L_9
L_10
L_11
L_12
L_13 , V_57 ) ;
F_50 ( F_42 , V_57 ) ;
fclose ( V_57 ) ;
F_22 ( V_51 ) ;
return 0 ;
}
void
F_34 ( const T_3 * V_6 , T_15 V_41 ,
T_4 V_29 , T_4 V_8 V_27 ,
T_4 V_9 V_27 )
{
T_19 * V_67 ;
V_67 = F_51 ( T_19 , 1 ) ;
V_67 -> V_68 = F_52 ( V_6 ) ;
V_67 -> V_69 = V_41 ;
switch ( V_41 ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
V_67 -> V_70 . V_71 = F_16 ( V_29 ) ;
break;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
V_67 -> V_70 . V_72 = F_52 ( ( char * ) V_29 ) ;
break;
default:
F_45 () ;
}
V_53 = F_53 ( V_53 , V_67 ) ;
}
void
F_36 ( void )
{
T_19 * V_67 ;
T_20 * V_73 ;
F_50 ( F_34 , NULL ) ;
for ( V_73 = V_53 ; V_73 ; V_73 = F_54 ( V_73 ) ) {
V_67 = ( T_19 * ) V_73 -> V_74 ;
switch ( V_67 -> V_69 ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
F_15 ( V_67 -> V_68 ,
V_67 -> V_70 . V_71 ) ;
break;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
F_17 ( V_67 -> V_68 ,
V_67 -> V_70 . V_72 ) ;
F_22 ( V_67 -> V_70 . V_72 ) ;
break;
default:
F_45 () ;
}
F_22 ( V_67 -> V_68 ) ;
F_22 ( V_67 ) ;
}
F_55 ( V_53 ) ;
V_53 = NULL ;
F_56 ( V_7 ) ;
V_7 = NULL ;
F_57 () ;
}
