static void F_1 ( T_1 * V_1 ) {
if ( V_1 -> V_2 )
F_2 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
}
static void F_3 ( T_1 * V_1 ) {
if ( V_1 -> error )
F_4 ( V_1 -> error ) ;
V_1 -> error = NULL ;
}
static int F_5 ( T_1 * V_1 , int V_3 ) {
int V_4 = - 1 ;
F_6 ( V_1 -> V_2 , V_3 , & V_4 , NULL ) ;
return V_4 ;
}
static int F_7 ( T_1 * V_1 , int V_3 ) {
int V_5 = - 1 ;
F_6 ( V_1 -> V_2 , V_3 , NULL , & V_5 ) ;
return V_5 ;
}
static int F_8 ( T_2 * V_6 , int V_7 ) {
switch ( F_9 ( V_6 , V_7 ) ) {
case V_8 :
case V_9 :
return V_10 ;
case V_11 : {
int V_12 = ( int ) F_10 ( V_6 , V_7 ) ;
if ( ( V_12 & ~ V_13 ) != 0 ) {
return F_11 ( V_6 , L_1 ) ;
}
return V_12 ;
}
case V_14 : {
const char * V_15 = F_12 ( V_6 , V_7 ) ;
int V_12 = 0 , V_16 ;
while ( ( V_16 = * V_15 ++ ) != '\0' ) {
if ( V_16 == 'i' ) V_12 |= V_17 ;
else if ( V_16 == 'm' ) V_12 |= V_18 ;
else if ( V_16 == 's' ) V_12 |= V_19 ;
else if ( V_16 == 'x' ) V_12 |= V_20 ;
else if ( V_16 == 'U' ) V_12 |= V_21 ;
}
return ( int ) V_12 ;
}
default:
return F_13 ( V_6 , V_7 , L_2 ) ;
}
}
static int F_14 ( T_2 * V_6 , const int V_22 , const int V_23 ) {
int V_24 = F_15 ( V_6 , V_22 , V_23 ) ;
if ( ( V_24 & ~ V_25 ) != 0 ) {
return F_11 ( V_6 , L_3 ) ;
}
return V_24 ;
}
static int F_16 ( T_2 * V_6 , const T_1 * V_1 , int V_26 ) {
const char * V_27 = F_17 ( V_28 , V_1 -> error -> V_29 ) ;
( void ) V_26 ;
if ( V_27 )
return F_11 ( V_6 , L_4 , V_27 , V_1 -> error -> V_30 ) ;
else
return F_11 ( V_6 , L_5 , V_1 -> error -> V_30 , V_1 -> error -> V_29 ) ;
}
static int F_18 ( T_2 * V_6 , const T_3 * V_31 , T_1 * * V_32 ) {
T_1 * V_1 ;
V_1 = ( T_1 * ) F_19 ( V_6 , sizeof ( T_1 ) ) ;
memset ( V_1 , 0 , sizeof ( T_1 ) ) ;
F_20 ( V_6 , V_33 ) ;
F_21 ( V_6 , - 2 ) ;
V_1 -> V_34 = F_22 ( V_31 -> V_35 ,
( V_36 ) ( V_31 -> V_37 | V_38 ) , ( V_39 ) 0 , & V_1 -> error ) ;
if ( ! V_1 -> V_34 )
return F_11 ( V_6 , L_6 , V_1 -> error -> V_30 , V_1 -> error -> V_29 ) ;
if ( V_32 ) * V_32 = V_1 ;
return 1 ;
}
static void F_23 ( T_2 * V_6 , T_4 * V_40 , T_1 * * V_1 ) {
* V_1 = F_24 ( V_6 ) ;
V_40 -> V_41 = F_25 ( V_6 , 2 , & V_40 -> V_42 ) ;
V_40 -> V_43 = F_26 ( V_6 , 3 , V_40 -> V_42 ) ;
V_40 -> V_24 = F_27 ( V_6 , 4 ) ;
}
static int F_28 ( T_2 * V_6 )
{
T_4 V_40 ;
T_1 * V_1 ;
T_5 V_12 ;
F_23 ( V_6 , & V_40 , & V_1 ) ;
F_3 ( V_1 ) ;
V_12 = F_29 ( V_1 -> V_34 , V_40 . V_41 , ( int ) V_40 . V_42 ,
V_40 . V_43 , ( V_39 ) V_40 . V_24 , & V_1 -> V_2 , & V_1 -> error ) ;
if ( F_30 ( V_12 ) ) {
int V_44 , V_4 , V_5 ;
int V_45 = F_31 ( V_1 -> V_2 ) ;
F_6 ( V_1 -> V_2 , 0 , & V_4 , NULL ) ;
F_32 ( V_6 , V_4 + 1 ) ;
F_33 ( V_6 ) ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ ) {
F_6 ( V_1 -> V_2 , V_44 , NULL , & V_5 ) ;
F_32 ( V_6 , V_5 ) ;
F_34 ( V_6 , - 2 , V_44 + 1 ) ;
}
F_32 ( V_6 , V_45 ) ;
F_1 ( V_1 ) ;
return 3 ;
}
else if ( F_35 ( V_1 -> V_2 ) ) {
F_36 ( V_6 , 1 ) ;
F_1 ( V_1 ) ;
return 1 ;
}
else {
F_1 ( V_1 ) ;
if ( F_37 ( V_12 ) )
return F_38 ( V_6 ) , 1 ;
else
return F_16 ( V_6 , V_1 , 0 ) ;
}
}
static int F_39 ( T_6 * V_1 , T_4 * V_40 , int V_46 ) {
int V_24 = V_46 ? ( V_40 -> V_24 | V_47 | V_48 ) : V_40 -> V_24 ;
F_1 ( V_1 ) ;
F_3 ( V_1 ) ;
return F_40 ( V_1 -> V_34 , V_40 -> V_41 , V_40 -> V_42 ,
V_40 -> V_43 , ( V_39 ) V_24 , & V_1 -> V_2 , & V_1 -> error ) ;
}
static int F_39 ( T_6 * V_1 , T_4 * V_40 ) {
F_1 ( V_1 ) ;
F_3 ( V_1 ) ;
return F_40 ( V_1 -> V_34 , V_40 -> V_41 , V_40 -> V_42 ,
V_40 -> V_43 , ( V_39 ) V_40 -> V_24 , & V_1 -> V_2 , & V_1 -> error ) ;
}
static void F_41 ( T_2 * V_6 , T_4 * V_40 ) {
F_42 ( V_6 , V_40 -> V_41 , V_40 -> V_42 ) ;
}
static int F_43 ( T_1 * V_1 , T_4 * V_40 ) {
F_1 ( V_1 ) ;
F_3 ( V_1 ) ;
return F_40 ( V_1 -> V_34 , V_40 -> V_41 , V_40 -> V_42 ,
V_40 -> V_43 , ( V_39 ) V_40 -> V_24 , & V_1 -> V_2 , & V_1 -> error ) ;
}
static int F_44 ( T_1 * V_1 , T_4 * V_40 , int V_49 , int V_46 ) {
int V_24 = V_46 ? ( V_40 -> V_24 | V_47 | V_48 ) : V_40 -> V_24 ;
F_1 ( V_1 ) ;
F_3 ( V_1 ) ;
return F_40 ( V_1 -> V_34 , V_40 -> V_41 , V_40 -> V_42 ,
V_49 , ( V_39 ) V_24 , & V_1 -> V_2 , & V_1 -> error ) ;
}
static int F_44 ( T_1 * V_1 , T_4 * V_40 , int V_49 ) {
F_1 ( V_1 ) ;
F_3 ( V_1 ) ;
return F_40 ( V_1 -> V_34 , V_40 -> V_41 , V_40 -> V_42 ,
V_49 , ( V_39 ) V_40 -> V_24 , & V_1 -> V_2 , & V_1 -> error ) ;
}
static int F_45 ( T_1 * V_1 , T_4 * V_40 , int V_50 ) {
F_1 ( V_1 ) ;
F_3 ( V_1 ) ;
return F_40 ( V_1 -> V_34 , V_40 -> V_41 , V_40 -> V_42 , V_50 ,
( V_39 ) V_40 -> V_24 , & V_1 -> V_2 , & V_1 -> error ) ;
}
static int F_46 ( T_2 * V_6 ) {
T_1 * V_1 = F_24 ( V_6 ) ;
if ( V_1 -> V_51 == 0 ) {
V_1 -> V_51 = 1 ;
if ( V_1 -> V_34 ) F_47 ( V_1 -> V_34 ) ;
F_1 ( V_1 ) ;
F_3 ( V_1 ) ;
}
return 0 ;
}
static int F_48 ( T_2 * V_6 ) {
T_1 * V_1 = F_24 ( V_6 ) ;
if ( V_1 -> V_51 == 0 )
F_49 ( V_6 , L_7 , V_52 , ( void * ) V_1 ) ;
else
F_49 ( V_6 , L_8 , V_52 ) ;
return 1 ;
}
static int F_50 ( T_2 * V_6 ) {
F_49 ( V_6 , L_9 , V_53 , V_54 , V_55 ) ;
return 1 ;
}
T_7 int F_51 ( T_2 * V_6 ) {
F_52 ( V_6 , V_56 , V_57 , L_10 ) ;
return 1 ;
}
