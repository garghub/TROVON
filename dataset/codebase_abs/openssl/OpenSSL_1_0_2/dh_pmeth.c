static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( sizeof( T_2 ) ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_3 = 1024 ;
V_2 -> V_4 = - 1 ;
V_2 -> V_5 = 2 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = NULL ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = NULL ;
V_2 -> V_12 = NULL ;
V_2 -> V_13 = NULL ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_1 -> V_16 = V_2 ;
V_1 -> V_17 = V_2 -> V_18 ;
V_1 -> V_19 = 2 ;
return 1 ;
}
static int F_3 ( T_1 * V_20 , T_1 * V_21 )
{
T_2 * V_2 , * V_22 ;
if ( ! F_1 ( V_20 ) )
return 0 ;
V_22 = V_21 -> V_16 ;
V_2 = V_20 -> V_16 ;
V_2 -> V_3 = V_22 -> V_3 ;
V_2 -> V_4 = V_22 -> V_4 ;
V_2 -> V_5 = V_22 -> V_5 ;
V_2 -> V_6 = V_22 -> V_6 ;
V_2 -> V_7 = V_22 -> V_7 ;
V_2 -> V_8 = V_22 -> V_8 ;
V_2 -> V_9 = V_22 -> V_9 ;
V_2 -> V_11 = F_4 ( V_22 -> V_11 ) ;
if ( ! V_2 -> V_11 )
return 0 ;
V_2 -> V_12 = V_22 -> V_12 ;
if ( V_2 -> V_13 ) {
V_2 -> V_13 = F_5 ( V_22 -> V_13 , V_22 -> V_14 ) ;
V_2 -> V_14 = V_22 -> V_14 ;
}
V_2 -> V_15 = V_22 -> V_15 ;
return 1 ;
}
static void F_6 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_16 ;
if ( V_2 ) {
if ( V_2 -> V_13 )
F_7 ( V_2 -> V_13 ) ;
if ( V_2 -> V_11 )
F_8 ( V_2 -> V_11 ) ;
F_7 ( V_2 ) ;
}
}
static int F_9 ( T_1 * V_1 , int type , int V_23 , void * V_24 )
{
T_2 * V_2 = V_1 -> V_16 ;
switch ( type ) {
case V_25 :
if ( V_23 < 256 )
return - 2 ;
V_2 -> V_3 = V_23 ;
return 1 ;
case V_26 :
if ( V_2 -> V_6 == 0 )
return - 2 ;
V_2 -> V_4 = V_23 ;
return 1 ;
case V_27 :
if ( V_2 -> V_6 )
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
V_2 -> V_6 = V_23 ;
return 1 ;
case V_29 :
if ( V_23 < 1 || V_23 > 3 )
return - 2 ;
V_2 -> V_8 = V_23 ;
return 1 ;
case V_30 :
return 1 ;
case V_31 :
if ( V_23 == - 2 )
return V_2 -> V_9 ;
if ( V_23 != V_10 && V_23 != V_32 )
return - 2 ;
V_2 -> V_9 = V_23 ;
return 1 ;
case V_33 :
V_2 -> V_12 = V_24 ;
return 1 ;
case V_34 :
* ( const V_35 * * ) V_24 = V_2 -> V_12 ;
return 1 ;
case V_36 :
if ( V_23 <= 0 )
return - 2 ;
V_2 -> V_15 = ( V_37 ) V_23 ;
return 1 ;
case V_38 :
* ( int * ) V_24 = V_2 -> V_15 ;
return 1 ;
case V_39 :
if ( V_2 -> V_13 )
F_7 ( V_2 -> V_13 ) ;
V_2 -> V_13 = V_24 ;
if ( V_24 )
V_2 -> V_14 = V_23 ;
else
V_2 -> V_14 = 0 ;
return 1 ;
case V_40 :
* ( unsigned char * * ) V_24 = V_2 -> V_13 ;
return V_2 -> V_14 ;
case V_41 :
if ( V_2 -> V_11 )
F_8 ( V_2 -> V_11 ) ;
V_2 -> V_11 = V_24 ;
return 1 ;
case V_42 :
* ( V_43 * * ) V_24 = V_2 -> V_11 ;
return 1 ;
default:
return - 2 ;
}
}
static int F_11 ( T_1 * V_1 ,
const char * type , const char * V_44 )
{
if ( ! strcmp ( type , L_1 ) ) {
int V_45 ;
V_45 = atoi ( V_44 ) ;
return F_12 ( V_1 , V_45 ) ;
}
if ( ! strcmp ( type , L_2 ) ) {
T_2 * V_2 = V_1 -> V_16 ;
int V_45 ;
V_45 = atoi ( V_44 ) ;
if ( V_45 < 0 || V_45 > 3 )
return - 2 ;
V_2 -> V_8 = V_45 ;
return 1 ;
}
if ( ! strcmp ( type , L_3 ) ) {
int V_45 ;
V_45 = atoi ( V_44 ) ;
return F_13 ( V_1 , V_45 ) ;
}
if ( ! strcmp ( type , L_4 ) ) {
int V_45 ;
V_45 = atoi ( V_44 ) ;
return F_14 ( V_1 , V_45 ) ;
}
if ( ! strcmp ( type , L_5 ) ) {
int V_46 ;
V_46 = atoi ( V_44 ) ;
return F_15 ( V_1 , V_46 ) ;
}
return - 2 ;
}
static T_3 * F_16 ( T_2 * V_2 , T_4 * V_47 )
{
T_3 * V_48 ;
int V_49 = 0 ;
int V_3 = V_2 -> V_3 ;
int V_4 = V_2 -> V_4 ;
const V_35 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_6 > 2 )
return NULL ;
V_48 = F_17 () ;
if ( ! V_48 )
return NULL ;
if ( V_4 == - 1 ) {
if ( V_3 >= 2048 )
V_4 = 256 ;
else
V_4 = 160 ;
}
if ( V_7 == NULL ) {
if ( V_3 >= 2048 )
V_7 = F_18 () ;
else
V_7 = F_19 () ;
}
if ( V_2 -> V_6 == 1 )
V_49 = F_20 ( V_48 , V_3 , V_4 , V_7 ,
NULL , 0 , NULL , NULL , NULL , V_47 ) ;
else if ( V_2 -> V_6 == 2 )
V_49 = F_21 ( V_48 , V_3 , V_4 , V_7 ,
NULL , 0 , - 1 , NULL , NULL , NULL , V_47 ) ;
if ( V_49 <= 0 ) {
F_22 ( V_48 ) ;
return NULL ;
}
return V_48 ;
}
static int F_23 ( T_1 * V_1 , T_5 * V_50 )
{
T_6 * V_51 = NULL ;
T_2 * V_2 = V_1 -> V_16 ;
T_4 * V_47 , V_52 ;
int V_48 ;
if ( V_2 -> V_8 ) {
switch ( V_2 -> V_8 ) {
case 1 :
V_51 = F_24 () ;
break;
case 2 :
V_51 = F_25 () ;
break;
case 3 :
V_51 = F_26 () ;
break;
default:
return - 2 ;
}
F_27 ( V_50 , V_53 , V_51 ) ;
return 1 ;
}
if ( V_1 -> V_54 ) {
V_47 = & V_52 ;
F_28 ( V_47 , V_1 ) ;
} else
V_47 = NULL ;
#ifndef F_10
if ( V_2 -> V_6 ) {
T_3 * V_55 ;
V_55 = F_16 ( V_2 , V_47 ) ;
if ( ! V_55 )
return 0 ;
V_51 = F_29 ( V_55 ) ;
F_22 ( V_55 ) ;
if ( ! V_51 )
return 0 ;
F_27 ( V_50 , V_53 , V_51 ) ;
return 1 ;
}
#endif
V_51 = F_30 () ;
if ( ! V_51 )
return 0 ;
V_48 = F_31 ( V_51 ,
V_2 -> V_3 , V_2 -> V_5 , V_47 ) ;
if ( V_48 )
F_32 ( V_50 , V_51 ) ;
else
F_33 ( V_51 ) ;
return V_48 ;
}
static int F_34 ( T_1 * V_1 , T_5 * V_50 )
{
T_6 * V_51 = NULL ;
if ( V_1 -> V_50 == NULL ) {
F_35 ( V_56 , V_57 ) ;
return 0 ;
}
V_51 = F_30 () ;
if ( ! V_51 )
return 0 ;
F_27 ( V_50 , V_1 -> V_58 -> V_59 , V_51 ) ;
if ( ! F_36 ( V_50 , V_1 -> V_50 ) )
return 0 ;
return F_37 ( V_50 -> V_50 . V_51 ) ;
}
static int F_38 ( T_1 * V_1 , unsigned char * V_60 ,
V_37 * V_61 )
{
int V_48 ;
T_6 * V_51 ;
T_2 * V_2 = V_1 -> V_16 ;
T_7 * V_62 ;
if ( ! V_1 -> V_50 || ! V_1 -> V_63 ) {
F_35 ( V_64 , V_65 ) ;
return 0 ;
}
V_51 = V_1 -> V_50 -> V_50 . V_51 ;
V_62 = V_1 -> V_63 -> V_50 . V_51 -> V_66 ;
if ( V_2 -> V_9 == V_10 ) {
if ( V_60 == NULL ) {
* V_61 = F_39 ( V_51 ) ;
return 1 ;
}
V_48 = F_40 ( V_60 , V_62 , V_51 ) ;
if ( V_48 < 0 )
return V_48 ;
* V_61 = V_48 ;
return 1 ;
} else if ( V_2 -> V_9 == V_32 ) {
unsigned char * V_67 = NULL ;
V_37 V_68 = 0 ;
if ( ! V_2 -> V_15 || ! V_2 -> V_11 )
return 0 ;
if ( V_60 == NULL ) {
* V_61 = V_2 -> V_15 ;
return 1 ;
}
if ( * V_61 != V_2 -> V_15 )
return 0 ;
V_48 = 0 ;
V_68 = F_39 ( V_51 ) ;
V_67 = F_2 ( V_68 ) ;
if ( F_41 ( V_67 , V_62 , V_51 ) <= 0 )
goto V_69;
if ( ! F_42 ( V_60 , * V_61 , V_67 , V_68 , V_2 -> V_11 ,
V_2 -> V_13 , V_2 -> V_14 , V_2 -> V_12 ) )
goto V_69;
* V_61 = V_2 -> V_15 ;
V_48 = 1 ;
V_69:
if ( V_67 ) {
F_43 ( V_67 , V_68 ) ;
F_7 ( V_67 ) ;
}
return V_48 ;
}
return 1 ;
}
