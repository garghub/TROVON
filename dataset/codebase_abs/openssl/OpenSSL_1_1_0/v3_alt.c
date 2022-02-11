static int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_2 * V_3 ;
T_3 * V_4 ;
T_4 * V_5 ;
int V_6 ;
if ( V_1 && ( V_1 -> V_7 == V_8 ) )
return 1 ;
if ( ! V_1 || ! V_1 -> V_9 ) {
F_2 ( V_10 , V_11 ) ;
goto V_12;
}
V_6 = F_3 ( V_1 -> V_9 , V_13 , - 1 ) ;
if ( V_6 < 0 )
return 1 ;
if ( ( V_5 = F_4 ( V_1 -> V_9 , V_6 ) ) == NULL
|| ( V_3 = F_5 ( V_5 ) ) == NULL ) {
F_2 ( V_10 , V_14 ) ;
goto V_12;
}
for ( V_6 = 0 ; V_6 < F_6 ( V_3 ) ; V_6 ++ ) {
V_4 = F_7 ( V_3 , V_6 ) ;
if ( ! F_8 ( V_2 , V_4 ) ) {
F_2 ( V_10 , V_15 ) ;
goto V_12;
}
}
F_9 ( V_3 ) ;
return 1 ;
V_12:
return 0 ;
}
static int F_10 ( T_1 * V_1 , T_2 * V_2 , int V_16 )
{
T_5 * V_17 ;
T_6 * V_18 = NULL ;
T_7 * V_19 ;
T_3 * V_4 = NULL ;
int V_6 ;
if ( V_1 != NULL && V_1 -> V_7 == V_8 )
return 1 ;
if ( ! V_1 || ( ! V_1 -> V_20 && ! V_1 -> V_21 ) ) {
F_2 ( V_22 , V_23 ) ;
goto V_12;
}
if ( V_1 -> V_20 )
V_17 = F_11 ( V_1 -> V_20 ) ;
else
V_17 = F_12 ( V_1 -> V_21 ) ;
V_6 = - 1 ;
while ( ( V_6 = F_13 ( V_17 ,
V_24 , V_6 ) ) >= 0 ) {
V_19 = F_14 ( V_17 , V_6 ) ;
V_18 = F_15 ( F_16 ( V_19 ) ) ;
if ( V_16 ) {
F_17 ( V_17 , V_6 ) ;
F_18 ( V_19 ) ;
V_6 -- ;
}
if ( V_18 == NULL || ( V_4 = F_19 () ) == NULL ) {
F_2 ( V_22 , V_15 ) ;
goto V_12;
}
V_4 -> V_25 . V_26 = V_18 ;
V_18 = NULL ;
V_4 -> type = V_27 ;
if ( ! F_8 ( V_2 , V_4 ) ) {
F_2 ( V_22 , V_15 ) ;
goto V_12;
}
V_4 = NULL ;
}
return 1 ;
V_12:
F_20 ( V_4 ) ;
F_21 ( V_18 ) ;
return 0 ;
}
T_3 * F_22 ( const T_8 * V_28 ,
T_1 * V_1 , T_9 * V_29 )
{
return F_23 ( NULL , V_28 , V_1 , V_29 , 0 ) ;
}
T_3 * F_24 ( T_3 * V_30 ,
const T_8 * V_28 ,
T_1 * V_1 , int V_31 , const char * V_32 ,
int V_33 )
{
char V_34 = 0 ;
T_3 * V_4 = NULL ;
if ( ! V_32 ) {
F_2 ( V_35 , V_36 ) ;
return NULL ;
}
if ( V_30 )
V_4 = V_30 ;
else {
V_4 = F_19 () ;
if ( V_4 == NULL ) {
F_2 ( V_35 , V_15 ) ;
return NULL ;
}
}
switch ( V_31 ) {
case V_37 :
case V_27 :
case V_38 :
V_34 = 1 ;
break;
case V_39 :
{
T_10 * V_40 ;
if ( ( V_40 = F_25 ( V_32 , 0 ) ) == NULL ) {
F_2 ( V_35 , V_41 ) ;
F_26 ( 2 , L_1 , V_32 ) ;
goto V_12;
}
V_4 -> V_25 . V_42 = V_40 ;
}
break;
case V_43 :
if ( V_33 )
V_4 -> V_25 . V_44 = F_27 ( V_32 ) ;
else
V_4 -> V_25 . V_44 = F_28 ( V_32 ) ;
if ( V_4 -> V_25 . V_44 == NULL ) {
F_2 ( V_35 , V_45 ) ;
F_26 ( 2 , L_1 , V_32 ) ;
goto V_12;
}
break;
case V_46 :
if ( ! F_29 ( V_4 , V_32 , V_1 ) ) {
F_2 ( V_35 , V_47 ) ;
goto V_12;
}
break;
case V_48 :
if ( ! F_30 ( V_4 , V_32 , V_1 ) ) {
F_2 ( V_35 , V_49 ) ;
goto V_12;
}
break;
default:
F_2 ( V_35 , V_50 ) ;
goto V_12;
}
if ( V_34 ) {
if ( ( V_4 -> V_25 . V_26 = F_31 () ) == NULL ||
! F_32 ( V_4 -> V_25 . V_26 , ( unsigned char * ) V_32 ,
strlen ( V_32 ) ) ) {
F_2 ( V_35 , V_15 ) ;
goto V_12;
}
}
V_4 -> type = V_31 ;
return V_4 ;
V_12:
if ( ! V_30 )
F_20 ( V_4 ) ;
return NULL ;
}
T_3 * F_23 ( T_3 * V_30 ,
const T_8 * V_28 ,
T_1 * V_1 , T_9 * V_29 , int V_33 )
{
int type ;
char * V_51 , * V_32 ;
V_51 = V_29 -> V_51 ;
V_32 = V_29 -> V_32 ;
if ( ! V_32 ) {
F_2 ( V_52 , V_36 ) ;
return NULL ;
}
if ( ! F_33 ( V_51 , L_2 ) )
type = V_27 ;
else if ( ! F_33 ( V_51 , L_3 ) )
type = V_37 ;
else if ( ! F_33 ( V_51 , L_4 ) )
type = V_38 ;
else if ( ! F_33 ( V_51 , L_5 ) )
type = V_39 ;
else if ( ! F_33 ( V_51 , L_6 ) )
type = V_43 ;
else if ( ! F_33 ( V_51 , L_7 ) )
type = V_46 ;
else if ( ! F_33 ( V_51 , L_8 ) )
type = V_48 ;
else {
F_2 ( V_52 , V_53 ) ;
F_26 ( 2 , L_9 , V_51 ) ;
return NULL ;
}
return F_24 ( V_30 , V_28 , V_1 , type , V_32 , V_33 ) ;
}
static int F_30 ( T_3 * V_4 , const char * V_32 , T_1 * V_1 )
{
char * V_54 = NULL , * V_55 ;
int V_56 ;
if ( ( V_55 = strchr ( V_32 , ';' ) ) == NULL )
return 0 ;
if ( ( V_4 -> V_25 . V_57 = F_34 () ) == NULL )
return 0 ;
F_35 ( V_4 -> V_25 . V_57 -> V_32 ) ;
if ( ( V_4 -> V_25 . V_57 -> V_32 = F_36 ( V_55 + 1 , V_1 ) ) == NULL )
return 0 ;
V_56 = V_55 - V_32 ;
V_54 = F_37 ( V_32 , V_56 ) ;
if ( V_54 == NULL )
return 0 ;
V_4 -> V_25 . V_57 -> V_58 = F_25 ( V_54 , 0 ) ;
F_38 ( V_54 ) ;
if ( ! V_4 -> V_25 . V_57 -> V_58 )
return 0 ;
return 1 ;
}
static int F_29 ( T_3 * V_4 , const char * V_32 , T_1 * V_1 )
{
int V_59 = 0 ;
F_39 ( T_9 ) * V_60 = NULL ;
T_5 * V_17 ;
if ( ( V_17 = F_40 () ) == NULL )
goto V_12;
V_60 = F_41 ( V_1 , V_32 ) ;
if ( ! V_60 ) {
F_2 ( V_61 , V_62 ) ;
F_26 ( 2 , L_10 , V_32 ) ;
goto V_12;
}
V_59 = F_42 ( V_17 , V_60 , V_63 ) ;
if ( ! V_59 )
goto V_12;
V_4 -> V_25 . V_64 = V_17 ;
V_12:
if ( V_59 == 0 )
F_43 ( V_17 ) ;
F_44 ( V_1 , V_60 ) ;
return V_59 ;
}
