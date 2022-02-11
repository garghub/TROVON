static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return 0 ;
V_2 -> V_3 = - 1 ;
V_2 -> V_4 = V_5 ;
V_1 -> V_6 = V_2 ;
return 1 ;
}
static int F_3 ( T_1 * V_7 , T_1 * V_8 )
{
T_2 * V_2 , * V_9 ;
if ( ! F_1 ( V_7 ) )
return 0 ;
V_9 = V_8 -> V_6 ;
V_2 = V_7 -> V_6 ;
if ( V_9 -> V_10 ) {
V_2 -> V_10 = F_4 ( V_9 -> V_10 ) ;
if ( ! V_2 -> V_10 )
return 0 ;
}
V_2 -> V_11 = V_9 -> V_11 ;
if ( V_9 -> V_12 ) {
V_2 -> V_12 = F_5 ( V_9 -> V_12 ) ;
if ( ! V_2 -> V_12 )
return 0 ;
}
V_2 -> V_4 = V_9 -> V_4 ;
V_2 -> V_13 = V_9 -> V_13 ;
V_2 -> V_14 = V_9 -> V_14 ;
if ( V_9 -> V_15 ) {
V_2 -> V_15 = F_6 ( V_9 -> V_15 , V_9 -> V_16 ) ;
if ( ! V_2 -> V_15 )
return 0 ;
} else
V_2 -> V_15 = NULL ;
V_2 -> V_16 = V_9 -> V_16 ;
return 1 ;
}
static void F_7 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_6 ;
if ( V_2 ) {
F_8 ( V_2 -> V_10 ) ;
F_9 ( V_2 -> V_12 ) ;
F_10 ( V_2 -> V_15 ) ;
F_10 ( V_2 ) ;
}
}
static int F_11 ( T_1 * V_1 , unsigned char * V_17 , T_3 * V_18 ,
const unsigned char * V_19 , T_3 V_20 )
{
int V_21 , type ;
unsigned int V_22 ;
T_2 * V_2 = V_1 -> V_6 ;
T_4 * V_23 = V_1 -> V_24 -> V_24 . V_23 ;
if ( ! V_17 ) {
* V_18 = F_12 ( V_23 ) ;
return 1 ;
} else if ( * V_18 < ( T_3 ) F_12 ( V_23 ) ) {
F_13 ( V_25 , V_26 ) ;
return 0 ;
}
if ( V_2 -> V_11 )
type = F_14 ( V_2 -> V_11 ) ;
else
type = V_27 ;
V_21 = F_15 ( type , V_19 , V_20 , V_17 , & V_22 , V_23 ) ;
if ( V_21 <= 0 )
return V_21 ;
* V_18 = ( T_3 ) V_22 ;
return 1 ;
}
static int F_16 ( T_1 * V_1 ,
const unsigned char * V_17 , T_3 V_18 ,
const unsigned char * V_19 , T_3 V_20 )
{
int V_21 , type ;
T_2 * V_2 = V_1 -> V_6 ;
T_4 * V_23 = V_1 -> V_24 -> V_24 . V_23 ;
if ( V_2 -> V_11 )
type = F_14 ( V_2 -> V_11 ) ;
else
type = V_27 ;
V_21 = F_17 ( type , V_19 , V_20 , V_17 , V_18 , V_23 ) ;
return V_21 ;
}
static int F_18 ( T_1 * V_1 , unsigned char * V_28 ,
T_3 * V_29 )
{
int V_21 ;
T_3 V_30 ;
const T_5 * V_31 = NULL ;
T_4 * V_32 ;
T_2 * V_2 = V_1 -> V_6 ;
if ( ! V_1 -> V_24 || ! V_1 -> V_33 ) {
F_13 ( V_34 , V_35 ) ;
return 0 ;
}
V_32 = V_2 -> V_12 ? V_2 -> V_12 : V_1 -> V_24 -> V_24 . V_23 ;
if ( ! V_28 ) {
const T_6 * V_36 ;
V_36 = F_19 ( V_32 ) ;
* V_29 = ( F_20 ( V_36 ) + 7 ) / 8 ;
return 1 ;
}
V_31 = F_21 ( V_1 -> V_33 -> V_24 . V_23 ) ;
V_30 = * V_29 ;
V_21 = F_22 ( V_28 , V_30 , V_31 , V_32 , 0 ) ;
if ( V_21 <= 0 )
return 0 ;
* V_29 = V_21 ;
return 1 ;
}
static int F_23 ( T_1 * V_1 ,
unsigned char * V_28 , T_3 * V_29 )
{
T_2 * V_2 = V_1 -> V_6 ;
unsigned char * V_37 = NULL ;
T_3 V_38 ;
int V_39 = 0 ;
if ( V_2 -> V_4 == V_5 )
return F_18 ( V_1 , V_28 , V_29 ) ;
if ( ! V_28 ) {
* V_29 = V_2 -> V_14 ;
return 1 ;
}
if ( * V_29 != V_2 -> V_14 )
return 0 ;
if ( ! F_18 ( V_1 , NULL , & V_38 ) )
return 0 ;
V_37 = F_24 ( V_38 ) ;
if ( V_37 == NULL )
return 0 ;
if ( ! F_18 ( V_1 , V_37 , & V_38 ) )
goto V_40;
if ( ! F_25 ( V_28 , * V_29 , V_37 , V_38 ,
V_2 -> V_15 , V_2 -> V_16 , V_2 -> V_13 ) )
goto V_40;
V_39 = 1 ;
V_40:
F_26 ( V_37 , V_38 ) ;
return V_39 ;
}
static int F_27 ( T_1 * V_1 , int type , int V_41 , void * V_42 )
{
T_2 * V_2 = V_1 -> V_6 ;
T_6 * V_36 ;
switch ( type ) {
case V_43 :
V_36 = F_28 ( V_41 ) ;
if ( V_36 == NULL ) {
F_13 ( V_44 , V_45 ) ;
return 0 ;
}
F_8 ( V_2 -> V_10 ) ;
V_2 -> V_10 = V_36 ;
return 1 ;
case V_46 :
if ( ! V_2 -> V_10 ) {
F_13 ( V_44 , V_47 ) ;
return 0 ;
}
F_29 ( V_2 -> V_10 , V_41 ) ;
return 1 ;
#ifndef F_30
case V_48 :
if ( V_41 == - 2 ) {
if ( V_2 -> V_3 != - 1 )
return V_2 -> V_3 ;
else {
T_4 * V_49 = V_1 -> V_24 -> V_24 . V_23 ;
return F_31 ( V_49 ) & V_50 ? 1 :
0 ;
}
} else if ( V_41 < - 1 || V_41 > 1 )
return - 2 ;
V_2 -> V_3 = V_41 ;
if ( V_41 != - 1 ) {
T_4 * V_49 = V_1 -> V_24 -> V_24 . V_23 ;
if ( ! V_49 -> V_36 )
return - 2 ;
if ( F_32 ( V_49 -> V_36 -> V_51 ) )
return 1 ;
if ( ! V_2 -> V_12 ) {
V_2 -> V_12 = F_5 ( V_49 ) ;
if ( ! V_2 -> V_12 )
return 0 ;
}
if ( V_41 )
F_33 ( V_2 -> V_12 , V_50 ) ;
else
F_34 ( V_2 -> V_12 , V_50 ) ;
} else {
F_9 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
return 1 ;
#endif
case V_52 :
if ( V_41 == - 2 )
return V_2 -> V_4 ;
if ( V_41 != V_5 && V_41 != V_53 )
return - 2 ;
V_2 -> V_4 = V_41 ;
return 1 ;
case V_54 :
V_2 -> V_13 = V_42 ;
return 1 ;
case V_55 :
* ( const V_56 * * ) V_42 = V_2 -> V_13 ;
return 1 ;
case V_57 :
if ( V_41 <= 0 )
return - 2 ;
V_2 -> V_14 = ( T_3 ) V_41 ;
return 1 ;
case V_58 :
* ( int * ) V_42 = V_2 -> V_14 ;
return 1 ;
case V_59 :
F_10 ( V_2 -> V_15 ) ;
V_2 -> V_15 = V_42 ;
if ( V_42 )
V_2 -> V_16 = V_41 ;
else
V_2 -> V_16 = 0 ;
return 1 ;
case V_60 :
* ( unsigned char * * ) V_42 = V_2 -> V_15 ;
return V_2 -> V_16 ;
case V_61 :
if ( F_14 ( ( const V_56 * ) V_42 ) != V_27 &&
F_14 ( ( const V_56 * ) V_42 ) != V_62 &&
F_14 ( ( const V_56 * ) V_42 ) != V_63 &&
F_14 ( ( const V_56 * ) V_42 ) != V_64 &&
F_14 ( ( const V_56 * ) V_42 ) != V_65 &&
F_14 ( ( const V_56 * ) V_42 ) != V_66 ) {
F_13 ( V_44 , V_67 ) ;
return 0 ;
}
V_2 -> V_11 = V_42 ;
return 1 ;
case V_68 :
* ( const V_56 * * ) V_42 = V_2 -> V_11 ;
return 1 ;
case V_69 :
case V_70 :
case V_71 :
case V_72 :
return 1 ;
default:
return - 2 ;
}
}
static int F_35 ( T_1 * V_1 ,
const char * type , const char * V_73 )
{
if ( strcmp ( type , L_1 ) == 0 ) {
int V_74 ;
V_74 = F_36 ( V_73 ) ;
if ( V_74 == V_75 )
V_74 = F_37 ( V_73 ) ;
if ( V_74 == V_75 )
V_74 = F_38 ( V_73 ) ;
if ( V_74 == V_75 ) {
F_13 ( V_76 , V_45 ) ;
return 0 ;
}
return F_39 ( V_1 , V_74 ) ;
} else if ( strcmp ( type , L_2 ) == 0 ) {
int V_77 ;
if ( strcmp ( V_73 , L_3 ) == 0 )
V_77 = 0 ;
else if ( strcmp ( V_73 , L_4 ) == 0 )
V_77 = V_78 ;
else
return - 2 ;
return F_40 ( V_1 , V_77 ) ;
} else if ( strcmp ( type , L_5 ) == 0 ) {
const V_56 * V_11 ;
if ( ( V_11 = F_41 ( V_73 ) ) == NULL ) {
F_13 ( V_76 , V_79 ) ;
return 0 ;
}
return F_42 ( V_1 , V_11 ) ;
} else if ( strcmp ( type , L_6 ) == 0 ) {
int V_80 ;
V_80 = atoi ( V_73 ) ;
return F_43 ( V_1 , V_80 ) ;
}
return - 2 ;
}
static int F_44 ( T_1 * V_1 , T_7 * V_24 )
{
T_4 * V_23 = NULL ;
T_2 * V_2 = V_1 -> V_6 ;
int V_21 = 0 ;
if ( V_2 -> V_10 == NULL ) {
F_13 ( V_81 , V_47 ) ;
return 0 ;
}
V_23 = F_45 () ;
if ( V_23 == NULL )
return 0 ;
V_21 = F_46 ( V_23 , V_2 -> V_10 ) ;
if ( V_21 )
F_47 ( V_24 , V_23 ) ;
else
F_9 ( V_23 ) ;
return V_21 ;
}
static int F_48 ( T_1 * V_1 , T_7 * V_24 )
{
T_4 * V_23 = NULL ;
T_2 * V_2 = V_1 -> V_6 ;
if ( V_1 -> V_24 == NULL && V_2 -> V_10 == NULL ) {
F_13 ( V_82 , V_47 ) ;
return 0 ;
}
V_23 = F_45 () ;
if ( ! V_23 )
return 0 ;
F_47 ( V_24 , V_23 ) ;
if ( V_1 -> V_24 ) {
if ( ! F_49 ( V_24 , V_1 -> V_24 ) )
return 0 ;
} else {
if ( ! F_46 ( V_23 , V_2 -> V_10 ) )
return 0 ;
}
return F_50 ( V_24 -> V_24 . V_23 ) ;
}
