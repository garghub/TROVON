static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return 0 ;
V_2 -> V_3 = 1024 ;
V_2 -> V_4 = - 1 ;
V_2 -> V_5 = 2 ;
V_2 -> V_6 = V_7 ;
V_1 -> V_8 = V_2 ;
V_1 -> V_9 = V_2 -> V_10 ;
V_1 -> V_11 = 2 ;
return 1 ;
}
static void F_3 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_8 ;
if ( V_2 != NULL ) {
F_4 ( V_2 -> V_12 ) ;
F_5 ( V_2 -> V_13 ) ;
F_4 ( V_2 ) ;
}
}
static int F_6 ( T_1 * V_14 , T_1 * V_15 )
{
T_2 * V_2 , * V_16 ;
if ( ! F_1 ( V_14 ) )
return 0 ;
V_16 = V_15 -> V_8 ;
V_2 = V_14 -> V_8 ;
V_2 -> V_3 = V_16 -> V_3 ;
V_2 -> V_4 = V_16 -> V_4 ;
V_2 -> V_5 = V_16 -> V_5 ;
V_2 -> V_17 = V_16 -> V_17 ;
V_2 -> V_18 = V_16 -> V_18 ;
V_2 -> V_19 = V_16 -> V_19 ;
V_2 -> V_6 = V_16 -> V_6 ;
V_2 -> V_13 = F_7 ( V_16 -> V_13 ) ;
if ( V_2 -> V_13 == NULL )
return 0 ;
V_2 -> V_20 = V_16 -> V_20 ;
if ( V_16 -> V_12 != NULL ) {
V_2 -> V_12 = F_8 ( V_16 -> V_12 , V_16 -> V_21 ) ;
if ( V_2 -> V_12 == NULL )
return 0 ;
V_2 -> V_21 = V_16 -> V_21 ;
}
V_2 -> V_22 = V_16 -> V_22 ;
return 1 ;
}
static int F_9 ( T_1 * V_1 , int type , int V_23 , void * V_24 )
{
T_2 * V_2 = V_1 -> V_8 ;
switch ( type ) {
case V_25 :
if ( V_23 < 256 )
return - 2 ;
V_2 -> V_3 = V_23 ;
return 1 ;
case V_26 :
if ( V_2 -> V_17 == 0 )
return - 2 ;
V_2 -> V_4 = V_23 ;
return 1 ;
case V_27 :
if ( V_2 -> V_17 )
return - 2 ;
V_2 -> V_5 = V_23 ;
return 1 ;
case V_28 :
#ifdef F_10
if ( V_23 != 0 )
return - 2 ;
#else
if ( V_23 < 0 || V_23 > 2 )
return - 2 ;
#endif
V_2 -> V_17 = V_23 ;
return 1 ;
case V_29 :
if ( V_23 < 1 || V_23 > 3 )
return - 2 ;
V_2 -> V_19 = V_23 ;
return 1 ;
case V_30 :
return 1 ;
case V_31 :
if ( V_23 == - 2 )
return V_2 -> V_6 ;
#ifdef F_11
if ( V_23 != V_7 )
#else
if ( V_23 != V_7 && V_23 != V_32 )
#endif
return - 2 ;
V_2 -> V_6 = V_23 ;
return 1 ;
case V_33 :
V_2 -> V_20 = V_24 ;
return 1 ;
case V_34 :
* ( const V_35 * * ) V_24 = V_2 -> V_20 ;
return 1 ;
case V_36 :
if ( V_23 <= 0 )
return - 2 ;
V_2 -> V_22 = ( V_37 ) V_23 ;
return 1 ;
case V_38 :
* ( int * ) V_24 = V_2 -> V_22 ;
return 1 ;
case V_39 :
F_4 ( V_2 -> V_12 ) ;
V_2 -> V_12 = V_24 ;
if ( V_24 )
V_2 -> V_21 = V_23 ;
else
V_2 -> V_21 = 0 ;
return 1 ;
case V_40 :
* ( unsigned char * * ) V_24 = V_2 -> V_12 ;
return V_2 -> V_21 ;
case V_41 :
F_5 ( V_2 -> V_13 ) ;
V_2 -> V_13 = V_24 ;
return 1 ;
case V_42 :
* ( V_43 * * ) V_24 = V_2 -> V_13 ;
return 1 ;
default:
return - 2 ;
}
}
static int F_12 ( T_1 * V_1 ,
const char * type , const char * V_44 )
{
if ( strcmp ( type , L_1 ) == 0 ) {
int V_45 ;
V_45 = atoi ( V_44 ) ;
return F_13 ( V_1 , V_45 ) ;
}
if ( strcmp ( type , L_2 ) == 0 ) {
T_2 * V_2 = V_1 -> V_8 ;
int V_45 ;
V_45 = atoi ( V_44 ) ;
if ( V_45 < 0 || V_45 > 3 )
return - 2 ;
V_2 -> V_19 = V_45 ;
return 1 ;
}
if ( strcmp ( type , L_3 ) == 0 ) {
int V_45 ;
V_45 = atoi ( V_44 ) ;
return F_14 ( V_1 , V_45 ) ;
}
if ( strcmp ( type , L_4 ) == 0 ) {
int V_45 ;
V_45 = atoi ( V_44 ) ;
return F_15 ( V_1 , V_45 ) ;
}
if ( strcmp ( type , L_5 ) == 0 ) {
int V_46 ;
V_46 = atoi ( V_44 ) ;
return F_16 ( V_1 , V_46 ) ;
}
return - 2 ;
}
static T_3 * F_17 ( T_2 * V_2 , T_4 * V_47 )
{
T_3 * V_48 ;
int V_49 = 0 ;
int V_3 = V_2 -> V_3 ;
int V_4 = V_2 -> V_4 ;
const V_35 * V_18 = V_2 -> V_18 ;
if ( V_2 -> V_17 > 2 )
return NULL ;
V_48 = F_18 () ;
if ( V_48 == NULL )
return NULL ;
if ( V_4 == - 1 ) {
if ( V_3 >= 2048 )
V_4 = 256 ;
else
V_4 = 160 ;
}
if ( V_18 == NULL ) {
if ( V_3 >= 2048 )
V_18 = F_19 () ;
else
V_18 = F_20 () ;
}
if ( V_2 -> V_17 == 1 )
V_49 = F_21 ( V_48 , V_3 , V_4 , V_18 ,
NULL , 0 , NULL , NULL , NULL , V_47 ) ;
else if ( V_2 -> V_17 == 2 )
V_49 = F_22 ( V_48 , V_3 , V_4 , V_18 ,
NULL , 0 , - 1 , NULL , NULL , NULL , V_47 ) ;
if ( V_49 <= 0 ) {
F_23 ( V_48 ) ;
return NULL ;
}
return V_48 ;
}
static int F_24 ( T_1 * V_1 , T_5 * V_50 )
{
T_6 * V_51 = NULL ;
T_2 * V_2 = V_1 -> V_8 ;
T_4 * V_47 ;
int V_48 ;
if ( V_2 -> V_19 ) {
switch ( V_2 -> V_19 ) {
case 1 :
V_51 = F_25 () ;
break;
case 2 :
V_51 = F_26 () ;
break;
case 3 :
V_51 = F_27 () ;
break;
default:
return - 2 ;
}
F_28 ( V_50 , V_52 , V_51 ) ;
return 1 ;
}
if ( V_1 -> V_53 ) {
V_47 = F_29 () ;
if ( V_47 == NULL )
return 0 ;
F_30 ( V_47 , V_1 ) ;
} else
V_47 = NULL ;
#ifndef F_10
if ( V_2 -> V_17 ) {
T_3 * V_54 ;
V_54 = F_17 ( V_2 , V_47 ) ;
F_31 ( V_47 ) ;
if ( V_54 == NULL )
return 0 ;
V_51 = F_32 ( V_54 ) ;
F_23 ( V_54 ) ;
if ( ! V_51 )
return 0 ;
F_28 ( V_50 , V_52 , V_51 ) ;
return 1 ;
}
#endif
V_51 = F_33 () ;
if ( V_51 == NULL ) {
F_31 ( V_47 ) ;
return 0 ;
}
V_48 = F_34 ( V_51 ,
V_2 -> V_3 , V_2 -> V_5 , V_47 ) ;
F_31 ( V_47 ) ;
if ( V_48 )
F_35 ( V_50 , V_51 ) ;
else
F_36 ( V_51 ) ;
return V_48 ;
}
static int F_37 ( T_1 * V_1 , T_5 * V_50 )
{
T_6 * V_51 = NULL ;
if ( V_1 -> V_50 == NULL ) {
F_38 ( V_55 , V_56 ) ;
return 0 ;
}
V_51 = F_33 () ;
if ( V_51 == NULL )
return 0 ;
F_28 ( V_50 , V_1 -> V_57 -> V_58 , V_51 ) ;
if ( ! F_39 ( V_50 , V_1 -> V_50 ) )
return 0 ;
return F_40 ( V_50 -> V_50 . V_51 ) ;
}
static int F_41 ( T_1 * V_1 , unsigned char * V_59 ,
V_37 * V_60 )
{
int V_48 ;
T_6 * V_51 ;
T_2 * V_2 = V_1 -> V_8 ;
T_7 * V_61 ;
if ( ! V_1 -> V_50 || ! V_1 -> V_62 ) {
F_38 ( V_63 , V_64 ) ;
return 0 ;
}
V_51 = V_1 -> V_50 -> V_50 . V_51 ;
V_61 = V_1 -> V_62 -> V_50 . V_51 -> V_65 ;
if ( V_2 -> V_6 == V_7 ) {
if ( V_59 == NULL ) {
* V_60 = F_42 ( V_51 ) ;
return 1 ;
}
V_48 = F_43 ( V_59 , V_61 , V_51 ) ;
if ( V_48 < 0 )
return V_48 ;
* V_60 = V_48 ;
return 1 ;
}
#ifndef F_11
else if ( V_2 -> V_6 == V_32 ) {
unsigned char * V_66 = NULL ;
V_37 V_67 = 0 ;
if ( ! V_2 -> V_22 || ! V_2 -> V_13 )
return 0 ;
if ( V_59 == NULL ) {
* V_60 = V_2 -> V_22 ;
return 1 ;
}
if ( * V_60 != V_2 -> V_22 )
return 0 ;
V_48 = 0 ;
V_67 = F_42 ( V_51 ) ;
V_66 = F_44 ( V_67 ) ;
if ( V_66 == NULL ) {
goto V_68;
}
if ( F_45 ( V_66 , V_61 , V_51 ) <= 0 )
goto V_68;
if ( ! F_46 ( V_59 , * V_60 , V_66 , V_67 , V_2 -> V_13 ,
V_2 -> V_12 , V_2 -> V_21 , V_2 -> V_20 ) )
goto V_68;
* V_60 = V_2 -> V_22 ;
V_48 = 1 ;
V_68:
F_47 ( V_66 , V_67 ) ;
return V_48 ;
}
#endif
return 0 ;
}
