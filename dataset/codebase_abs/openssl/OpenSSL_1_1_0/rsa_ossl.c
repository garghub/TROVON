const T_1 * F_1 ( void )
{
return & V_1 ;
}
static int F_2 ( int V_2 , const unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 * V_7 , * V_8 ;
int V_9 , V_10 , V_11 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
if ( F_3 ( V_5 -> V_16 ) > V_17 ) {
F_4 ( V_18 , V_19 ) ;
return - 1 ;
}
if ( F_5 ( V_5 -> V_16 , V_5 -> V_20 ) <= 0 ) {
F_4 ( V_18 , V_21 ) ;
return - 1 ;
}
if ( F_3 ( V_5 -> V_16 ) > V_22 ) {
if ( F_3 ( V_5 -> V_20 ) > V_23 ) {
F_4 ( V_18 , V_21 ) ;
return - 1 ;
}
}
if ( ( V_15 = F_6 () ) == NULL )
goto V_24;
F_7 ( V_15 ) ;
V_7 = F_8 ( V_15 ) ;
V_8 = F_8 ( V_15 ) ;
V_12 = F_9 ( V_5 -> V_16 ) ;
V_14 = F_10 ( V_12 ) ;
if ( V_7 == NULL || V_8 == NULL || V_14 == NULL ) {
F_4 ( V_18 , V_25 ) ;
goto V_24;
}
switch ( V_6 ) {
case V_26 :
V_9 = F_11 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_27 :
V_9 = F_12 ( V_14 , V_12 , V_3 , V_2 , NULL , 0 ) ;
break;
case V_28 :
V_9 = F_13 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_29 :
V_9 = F_14 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
default:
F_4 ( V_18 , V_30 ) ;
goto V_24;
}
if ( V_9 <= 0 )
goto V_24;
if ( F_15 ( V_14 , V_12 , V_7 ) == NULL )
goto V_24;
if ( F_5 ( V_7 , V_5 -> V_16 ) >= 0 ) {
F_4 ( V_18 ,
V_31 ) ;
goto V_24;
}
if ( V_5 -> V_32 & V_33 )
if ( ! F_16
( & V_5 -> V_34 , V_5 -> V_35 , V_5 -> V_16 , V_15 ) )
goto V_24;
if ( ! V_5 -> V_36 -> V_37 ( V_8 , V_7 , V_5 -> V_20 , V_5 -> V_16 , V_15 ,
V_5 -> V_34 ) )
goto V_24;
V_10 = F_9 ( V_8 ) ;
V_9 = F_17 ( V_8 , & ( V_4 [ V_12 - V_10 ] ) ) ;
for ( V_11 = 0 ; V_11 < ( V_12 - V_9 ) ; V_11 ++ )
V_4 [ V_11 ] = 0 ;
V_13 = V_12 ;
V_24:
if ( V_15 != NULL )
F_18 ( V_15 ) ;
F_19 ( V_15 ) ;
F_20 ( V_14 , V_12 ) ;
return ( V_13 ) ;
}
static T_5 * F_21 ( T_2 * V_5 , int * V_38 , T_4 * V_15 )
{
T_5 * V_8 ;
F_22 ( V_5 -> V_35 ) ;
if ( V_5 -> V_39 == NULL ) {
V_5 -> V_39 = F_23 ( V_5 , V_15 ) ;
}
V_8 = V_5 -> V_39 ;
if ( V_8 == NULL )
goto V_24;
if ( F_24 ( V_8 ) ) {
* V_38 = 1 ;
} else {
* V_38 = 0 ;
if ( V_5 -> V_40 == NULL ) {
V_5 -> V_40 = F_23 ( V_5 , V_15 ) ;
}
V_8 = V_5 -> V_40 ;
}
V_24:
F_25 ( V_5 -> V_35 ) ;
return V_8 ;
}
static int F_26 ( T_5 * V_41 , T_3 * V_7 , T_3 * V_42 ,
T_4 * V_15 )
{
if ( V_42 == NULL )
return F_27 ( V_7 , NULL , V_41 , V_15 ) ;
else {
int V_8 ;
F_28 ( V_41 ) ;
V_8 = F_27 ( V_7 , V_42 , V_41 , V_15 ) ;
F_29 ( V_41 ) ;
return V_8 ;
}
}
static int F_30 ( T_5 * V_41 , T_3 * V_7 , T_3 * V_42 ,
T_4 * V_15 )
{
return F_31 ( V_7 , V_42 , V_41 , V_15 ) ;
}
static int F_32 ( int V_2 , const unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 * V_7 , * V_8 , * V_43 ;
int V_9 , V_10 , V_11 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
int V_44 = 0 ;
T_3 * V_42 = NULL ;
T_5 * V_39 = NULL ;
if ( ( V_15 = F_6 () ) == NULL )
goto V_24;
F_7 ( V_15 ) ;
V_7 = F_8 ( V_15 ) ;
V_8 = F_8 ( V_15 ) ;
V_12 = F_9 ( V_5 -> V_16 ) ;
V_14 = F_10 ( V_12 ) ;
if ( V_7 == NULL || V_8 == NULL || V_14 == NULL ) {
F_4 ( V_45 , V_25 ) ;
goto V_24;
}
switch ( V_6 ) {
case V_26 :
V_9 = F_33 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_46 :
V_9 = F_34 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_29 :
V_9 = F_14 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_28 :
default:
F_4 ( V_45 , V_30 ) ;
goto V_24;
}
if ( V_9 <= 0 )
goto V_24;
if ( F_15 ( V_14 , V_12 , V_7 ) == NULL )
goto V_24;
if ( F_5 ( V_7 , V_5 -> V_16 ) >= 0 ) {
F_4 ( V_45 ,
V_31 ) ;
goto V_24;
}
if ( ! ( V_5 -> V_32 & V_47 ) ) {
V_39 = F_21 ( V_5 , & V_44 , V_15 ) ;
if ( V_39 == NULL ) {
F_4 ( V_45 , V_48 ) ;
goto V_24;
}
}
if ( V_39 != NULL ) {
if ( ! V_44 && ( ( V_42 = F_8 ( V_15 ) ) == NULL ) ) {
F_4 ( V_45 , V_25 ) ;
goto V_24;
}
if ( ! F_26 ( V_39 , V_7 , V_42 , V_15 ) )
goto V_24;
}
if ( ( V_5 -> V_32 & V_49 ) ||
( ( V_5 -> V_50 != NULL ) &&
( V_5 -> V_51 != NULL ) &&
( V_5 -> V_52 != NULL ) && ( V_5 -> V_53 != NULL ) && ( V_5 -> V_54 != NULL ) ) ) {
if ( ! V_5 -> V_36 -> V_55 ( V_8 , V_7 , V_5 , V_15 ) )
goto V_24;
} else {
T_3 * V_56 = F_35 () ;
if ( V_56 == NULL ) {
F_4 ( V_45 , V_25 ) ;
goto V_24;
}
F_36 ( V_56 , V_5 -> V_56 , V_57 ) ;
if ( V_5 -> V_32 & V_33 )
if ( ! F_16
( & V_5 -> V_34 , V_5 -> V_35 , V_5 -> V_16 , V_15 ) ) {
F_37 ( V_56 ) ;
goto V_24;
}
if ( ! V_5 -> V_36 -> V_37 ( V_8 , V_7 , V_56 , V_5 -> V_16 , V_15 ,
V_5 -> V_34 ) ) {
F_37 ( V_56 ) ;
goto V_24;
}
F_37 ( V_56 ) ;
}
if ( V_39 )
if ( ! F_30 ( V_39 , V_8 , V_42 , V_15 ) )
goto V_24;
if ( V_6 == V_46 ) {
F_38 ( V_7 , V_5 -> V_16 , V_8 ) ;
if ( F_39 ( V_8 , V_7 ) > 0 )
V_43 = V_7 ;
else
V_43 = V_8 ;
} else
V_43 = V_8 ;
V_10 = F_9 ( V_43 ) ;
V_9 = F_17 ( V_43 , & ( V_4 [ V_12 - V_10 ] ) ) ;
for ( V_11 = 0 ; V_11 < ( V_12 - V_9 ) ; V_11 ++ )
V_4 [ V_11 ] = 0 ;
V_13 = V_12 ;
V_24:
if ( V_15 != NULL )
F_18 ( V_15 ) ;
F_19 ( V_15 ) ;
F_20 ( V_14 , V_12 ) ;
return ( V_13 ) ;
}
static int F_40 ( int V_2 , const unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 * V_7 , * V_8 ;
int V_10 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_50 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
int V_44 = 0 ;
T_3 * V_42 = NULL ;
T_5 * V_39 = NULL ;
if ( ( V_15 = F_6 () ) == NULL )
goto V_24;
F_7 ( V_15 ) ;
V_7 = F_8 ( V_15 ) ;
V_8 = F_8 ( V_15 ) ;
V_12 = F_9 ( V_5 -> V_16 ) ;
V_14 = F_10 ( V_12 ) ;
if ( V_7 == NULL || V_8 == NULL || V_14 == NULL ) {
F_4 ( V_58 , V_25 ) ;
goto V_24;
}
if ( V_2 > V_12 ) {
F_4 ( V_58 ,
V_59 ) ;
goto V_24;
}
if ( F_15 ( V_3 , ( int ) V_2 , V_7 ) == NULL )
goto V_24;
if ( F_5 ( V_7 , V_5 -> V_16 ) >= 0 ) {
F_4 ( V_58 ,
V_31 ) ;
goto V_24;
}
if ( ! ( V_5 -> V_32 & V_47 ) ) {
V_39 = F_21 ( V_5 , & V_44 , V_15 ) ;
if ( V_39 == NULL ) {
F_4 ( V_58 , V_48 ) ;
goto V_24;
}
}
if ( V_39 != NULL ) {
if ( ! V_44 && ( ( V_42 = F_8 ( V_15 ) ) == NULL ) ) {
F_4 ( V_58 , V_25 ) ;
goto V_24;
}
if ( ! F_26 ( V_39 , V_7 , V_42 , V_15 ) )
goto V_24;
}
if ( ( V_5 -> V_32 & V_49 ) ||
( ( V_5 -> V_50 != NULL ) &&
( V_5 -> V_51 != NULL ) &&
( V_5 -> V_52 != NULL ) && ( V_5 -> V_53 != NULL ) && ( V_5 -> V_54 != NULL ) ) ) {
if ( ! V_5 -> V_36 -> V_55 ( V_8 , V_7 , V_5 , V_15 ) )
goto V_24;
} else {
T_3 * V_56 = F_35 () ;
if ( V_56 == NULL ) {
F_4 ( V_58 , V_25 ) ;
goto V_24;
}
F_36 ( V_56 , V_5 -> V_56 , V_57 ) ;
if ( V_5 -> V_32 & V_33 )
if ( ! F_16
( & V_5 -> V_34 , V_5 -> V_35 , V_5 -> V_16 , V_15 ) ) {
F_37 ( V_56 ) ;
goto V_24;
}
if ( ! V_5 -> V_36 -> V_37 ( V_8 , V_7 , V_56 , V_5 -> V_16 , V_15 ,
V_5 -> V_34 ) ) {
F_37 ( V_56 ) ;
goto V_24;
}
F_37 ( V_56 ) ;
}
if ( V_39 )
if ( ! F_30 ( V_39 , V_8 , V_42 , V_15 ) )
goto V_24;
V_50 = V_14 ;
V_10 = F_17 ( V_8 , V_50 ) ;
switch ( V_6 ) {
case V_26 :
V_13 = F_41 ( V_4 , V_12 , V_14 , V_10 , V_12 ) ;
break;
case V_27 :
V_13 = F_42 ( V_4 , V_12 , V_14 , V_10 , V_12 , NULL , 0 ) ;
break;
case V_28 :
V_13 = F_43 ( V_4 , V_12 , V_14 , V_10 , V_12 ) ;
break;
case V_29 :
V_13 = F_44 ( V_4 , V_12 , V_14 , V_10 , V_12 ) ;
break;
default:
F_4 ( V_58 , V_30 ) ;
goto V_24;
}
if ( V_13 < 0 )
F_4 ( V_58 , V_60 ) ;
V_24:
if ( V_15 != NULL )
F_18 ( V_15 ) ;
F_19 ( V_15 ) ;
F_20 ( V_14 , V_12 ) ;
return ( V_13 ) ;
}
static int F_45 ( int V_2 , const unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 * V_7 , * V_8 ;
int V_9 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_50 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
if ( F_3 ( V_5 -> V_16 ) > V_17 ) {
F_4 ( V_61 , V_19 ) ;
return - 1 ;
}
if ( F_5 ( V_5 -> V_16 , V_5 -> V_20 ) <= 0 ) {
F_4 ( V_61 , V_21 ) ;
return - 1 ;
}
if ( F_3 ( V_5 -> V_16 ) > V_22 ) {
if ( F_3 ( V_5 -> V_20 ) > V_23 ) {
F_4 ( V_61 , V_21 ) ;
return - 1 ;
}
}
if ( ( V_15 = F_6 () ) == NULL )
goto V_24;
F_7 ( V_15 ) ;
V_7 = F_8 ( V_15 ) ;
V_8 = F_8 ( V_15 ) ;
V_12 = F_9 ( V_5 -> V_16 ) ;
V_14 = F_10 ( V_12 ) ;
if ( V_7 == NULL || V_8 == NULL || V_14 == NULL ) {
F_4 ( V_61 , V_25 ) ;
goto V_24;
}
if ( V_2 > V_12 ) {
F_4 ( V_61 , V_59 ) ;
goto V_24;
}
if ( F_15 ( V_3 , V_2 , V_7 ) == NULL )
goto V_24;
if ( F_5 ( V_7 , V_5 -> V_16 ) >= 0 ) {
F_4 ( V_61 ,
V_31 ) ;
goto V_24;
}
if ( V_5 -> V_32 & V_33 )
if ( ! F_16
( & V_5 -> V_34 , V_5 -> V_35 , V_5 -> V_16 , V_15 ) )
goto V_24;
if ( ! V_5 -> V_36 -> V_37 ( V_8 , V_7 , V_5 -> V_20 , V_5 -> V_16 , V_15 ,
V_5 -> V_34 ) )
goto V_24;
if ( ( V_6 == V_46 ) && ( ( F_46 ( V_8 ) [ 0 ] & 0xf ) != 12 ) )
if ( ! F_38 ( V_8 , V_5 -> V_16 , V_8 ) )
goto V_24;
V_50 = V_14 ;
V_9 = F_17 ( V_8 , V_50 ) ;
switch ( V_6 ) {
case V_26 :
V_13 = F_47 ( V_4 , V_12 , V_14 , V_9 , V_12 ) ;
break;
case V_46 :
V_13 = F_48 ( V_4 , V_12 , V_14 , V_9 , V_12 ) ;
break;
case V_29 :
V_13 = F_44 ( V_4 , V_12 , V_14 , V_9 , V_12 ) ;
break;
default:
F_4 ( V_61 , V_30 ) ;
goto V_24;
}
if ( V_13 < 0 )
F_4 ( V_61 , V_60 ) ;
V_24:
if ( V_15 != NULL )
F_18 ( V_15 ) ;
F_19 ( V_15 ) ;
F_20 ( V_14 , V_12 ) ;
return ( V_13 ) ;
}
static int F_49 ( T_3 * V_62 , const T_3 * V_63 , T_2 * V_5 , T_4 * V_15 )
{
T_3 * V_64 , * V_65 , * V_66 ;
int V_8 = 0 ;
F_7 ( V_15 ) ;
V_64 = F_8 ( V_15 ) ;
V_65 = F_8 ( V_15 ) ;
V_66 = F_8 ( V_15 ) ;
{
T_3 * V_50 = F_35 () , * V_51 = F_35 () ;
if ( V_50 == NULL || V_51 == NULL ) {
F_37 ( V_50 ) ;
F_37 ( V_51 ) ;
goto V_24;
}
F_36 ( V_50 , V_5 -> V_50 , V_57 ) ;
F_36 ( V_51 , V_5 -> V_51 , V_57 ) ;
if ( V_5 -> V_32 & V_67 ) {
if ( ! F_16
( & V_5 -> V_68 , V_5 -> V_35 , V_50 , V_15 )
|| ! F_16 ( & V_5 -> V_69 ,
V_5 -> V_35 , V_51 , V_15 ) ) {
F_37 ( V_50 ) ;
F_37 ( V_51 ) ;
goto V_24;
}
}
F_37 ( V_50 ) ;
F_37 ( V_51 ) ;
}
if ( V_5 -> V_32 & V_33 )
if ( ! F_16
( & V_5 -> V_34 , V_5 -> V_35 , V_5 -> V_16 , V_15 ) )
goto V_24;
{
T_3 * V_70 = F_35 () ;
if ( V_70 == NULL )
goto V_24;
F_36 ( V_70 , V_63 , V_57 ) ;
if ( ! F_50 ( V_64 , V_70 , V_5 -> V_51 , V_15 ) ) {
F_37 ( V_70 ) ;
goto V_24;
}
{
T_3 * V_53 = F_35 () ;
if ( V_53 == NULL ) {
F_37 ( V_70 ) ;
goto V_24;
}
F_36 ( V_53 , V_5 -> V_53 , V_57 ) ;
if ( ! V_5 -> V_36 -> V_37 ( V_65 , V_64 , V_53 , V_5 -> V_51 , V_15 ,
V_5 -> V_69 ) ) {
F_37 ( V_70 ) ;
F_37 ( V_53 ) ;
goto V_24;
}
F_37 ( V_53 ) ;
}
if ( ! F_50 ( V_64 , V_70 , V_5 -> V_50 , V_15 ) ) {
F_37 ( V_70 ) ;
goto V_24;
}
F_37 ( V_70 ) ;
}
{
T_3 * V_52 = F_35 () ;
if ( V_52 == NULL )
goto V_24;
F_36 ( V_52 , V_5 -> V_52 , V_57 ) ;
if ( ! V_5 -> V_36 -> V_37 ( V_62 , V_64 , V_52 , V_5 -> V_50 , V_15 ,
V_5 -> V_68 ) ) {
F_37 ( V_52 ) ;
goto V_24;
}
F_37 ( V_52 ) ;
}
if ( ! F_38 ( V_62 , V_62 , V_65 ) )
goto V_24;
if ( F_51 ( V_62 ) )
if ( ! F_52 ( V_62 , V_62 , V_5 -> V_50 ) )
goto V_24;
if ( ! F_53 ( V_64 , V_62 , V_5 -> V_54 , V_15 ) )
goto V_24;
{
T_3 * V_71 = F_35 () ;
if ( V_71 == NULL )
goto V_24;
F_36 ( V_71 , V_64 , V_57 ) ;
if ( ! F_50 ( V_62 , V_71 , V_5 -> V_50 , V_15 ) ) {
F_37 ( V_71 ) ;
goto V_24;
}
F_37 ( V_71 ) ;
}
if ( F_51 ( V_62 ) )
if ( ! F_52 ( V_62 , V_62 , V_5 -> V_50 ) )
goto V_24;
if ( ! F_53 ( V_64 , V_62 , V_5 -> V_51 , V_15 ) )
goto V_24;
if ( ! F_52 ( V_62 , V_64 , V_65 ) )
goto V_24;
if ( V_5 -> V_20 && V_5 -> V_16 ) {
if ( ! V_5 -> V_36 -> V_37 ( V_66 , V_62 , V_5 -> V_20 , V_5 -> V_16 , V_15 ,
V_5 -> V_34 ) )
goto V_24;
if ( ! F_38 ( V_66 , V_66 , V_63 ) )
goto V_24;
if ( ! F_50 ( V_66 , V_66 , V_5 -> V_16 , V_15 ) )
goto V_24;
if ( F_51 ( V_66 ) )
if ( ! F_52 ( V_66 , V_66 , V_5 -> V_16 ) )
goto V_24;
if ( ! F_54 ( V_66 ) ) {
T_3 * V_56 = F_35 () ;
if ( V_56 == NULL )
goto V_24;
F_36 ( V_56 , V_5 -> V_56 , V_57 ) ;
if ( ! V_5 -> V_36 -> V_37 ( V_62 , V_63 , V_56 , V_5 -> V_16 , V_15 ,
V_5 -> V_34 ) ) {
F_37 ( V_56 ) ;
goto V_24;
}
F_37 ( V_56 ) ;
}
}
V_8 = 1 ;
V_24:
F_18 ( V_15 ) ;
return ( V_8 ) ;
}
static int F_55 ( T_2 * V_5 )
{
V_5 -> V_32 |= V_33 | V_67 ;
return ( 1 ) ;
}
static int F_56 ( T_2 * V_5 )
{
F_57 ( V_5 -> V_34 ) ;
F_57 ( V_5 -> V_68 ) ;
F_57 ( V_5 -> V_69 ) ;
return ( 1 ) ;
}
