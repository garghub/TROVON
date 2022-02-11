static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( sizeof( T_2 ) ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = NULL ;
V_2 -> V_5 = - 1 ;
V_2 -> V_6 = NULL ;
V_2 -> V_7 = V_8 ;
V_2 -> V_9 = NULL ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = NULL ;
V_2 -> V_12 = 0 ;
V_1 -> V_13 = V_2 ;
return 1 ;
}
static int F_3 ( T_1 * V_14 , T_1 * V_15 )
{
T_2 * V_2 , * V_16 ;
if ( ! F_1 ( V_14 ) )
return 0 ;
V_16 = V_15 -> V_13 ;
V_2 = V_14 -> V_13 ;
if ( V_16 -> V_3 ) {
V_2 -> V_3 = F_4 ( V_16 -> V_3 ) ;
if ( ! V_2 -> V_3 )
return 0 ;
}
V_2 -> V_4 = V_16 -> V_4 ;
if ( V_16 -> V_6 ) {
V_2 -> V_6 = F_5 ( V_16 -> V_6 ) ;
if ( ! V_2 -> V_6 )
return 0 ;
}
V_2 -> V_7 = V_16 -> V_7 ;
V_2 -> V_9 = V_16 -> V_9 ;
V_2 -> V_10 = V_16 -> V_10 ;
if ( V_16 -> V_11 ) {
V_2 -> V_11 = F_6 ( V_16 -> V_11 , V_16 -> V_12 ) ;
if ( ! V_2 -> V_11 )
return 0 ;
} else
V_2 -> V_11 = NULL ;
V_2 -> V_12 = V_16 -> V_12 ;
return 1 ;
}
static void F_7 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_13 ;
if ( V_2 ) {
if ( V_2 -> V_3 )
F_8 ( V_2 -> V_3 ) ;
if ( V_2 -> V_6 )
F_9 ( V_2 -> V_6 ) ;
if ( V_2 -> V_11 )
F_10 ( V_2 -> V_11 ) ;
F_10 ( V_2 ) ;
}
}
static int F_11 ( T_1 * V_1 , unsigned char * V_17 , T_3 * V_18 ,
const unsigned char * V_19 , T_3 V_20 )
{
int V_21 , type ;
unsigned int V_22 ;
T_2 * V_2 = V_1 -> V_13 ;
T_4 * V_23 = V_1 -> V_24 -> V_24 . V_23 ;
if ( ! V_17 ) {
* V_18 = F_12 ( V_23 ) ;
return 1 ;
} else if ( * V_18 < ( T_3 ) F_12 ( V_23 ) ) {
F_13 ( V_25 , V_26 ) ;
return 0 ;
}
if ( V_2 -> V_4 )
type = F_14 ( V_2 -> V_4 ) ;
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
T_2 * V_2 = V_1 -> V_13 ;
T_4 * V_23 = V_1 -> V_24 -> V_24 . V_23 ;
if ( V_2 -> V_4 )
type = F_14 ( V_2 -> V_4 ) ;
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
T_2 * V_2 = V_1 -> V_13 ;
if ( ! V_1 -> V_24 || ! V_1 -> V_33 ) {
F_13 ( V_34 , V_35 ) ;
return 0 ;
}
V_32 = V_2 -> V_6 ? V_2 -> V_6 : V_1 -> V_24 -> V_24 . V_23 ;
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
T_2 * V_2 = V_1 -> V_13 ;
unsigned char * V_37 = NULL ;
T_3 V_38 ;
int V_39 = 0 ;
if ( V_2 -> V_7 == V_8 )
return F_18 ( V_1 , V_28 , V_29 ) ;
if ( ! V_28 ) {
* V_29 = V_2 -> V_10 ;
return 1 ;
}
if ( * V_29 != V_2 -> V_10 )
return 0 ;
if ( ! F_18 ( V_1 , NULL , & V_38 ) )
return 0 ;
V_37 = F_2 ( V_38 ) ;
if ( ! V_37 )
return 0 ;
if ( ! F_18 ( V_1 , V_37 , & V_38 ) )
goto V_40;
if ( ! F_24 ( V_28 , * V_29 , V_37 , V_38 ,
V_2 -> V_11 , V_2 -> V_12 , V_2 -> V_9 ) )
goto V_40;
V_39 = 1 ;
V_40:
if ( V_37 ) {
F_25 ( V_37 , V_38 ) ;
F_10 ( V_37 ) ;
}
return V_39 ;
}
static int F_26 ( T_1 * V_1 , int type , int V_41 , void * V_42 )
{
T_2 * V_2 = V_1 -> V_13 ;
T_6 * V_36 ;
switch ( type ) {
case V_43 :
V_36 = F_27 ( V_41 ) ;
if ( V_36 == NULL ) {
F_13 ( V_44 , V_45 ) ;
return 0 ;
}
if ( V_2 -> V_3 )
F_8 ( V_2 -> V_3 ) ;
V_2 -> V_3 = V_36 ;
return 1 ;
case V_46 :
if ( ! V_2 -> V_3 ) {
F_13 ( V_44 , V_47 ) ;
return 0 ;
}
F_28 ( V_2 -> V_3 , V_41 ) ;
return 1 ;
#ifndef F_29
case V_48 :
if ( V_41 == - 2 ) {
if ( V_2 -> V_5 != - 1 )
return V_2 -> V_5 ;
else {
T_4 * V_49 = V_1 -> V_24 -> V_24 . V_23 ;
return F_30 ( V_49 ) & V_50 ? 1 :
0 ;
}
} else if ( V_41 < - 1 || V_41 > 1 )
return - 2 ;
V_2 -> V_5 = V_41 ;
if ( V_41 != - 1 ) {
T_4 * V_49 = V_1 -> V_24 -> V_24 . V_23 ;
if ( ! V_49 -> V_36 )
return - 2 ;
if ( F_31 ( & V_49 -> V_36 -> V_51 ) )
return 1 ;
if ( ! V_2 -> V_6 ) {
V_2 -> V_6 = F_5 ( V_49 ) ;
if ( ! V_2 -> V_6 )
return 0 ;
}
if ( V_41 )
F_32 ( V_2 -> V_6 , V_50 ) ;
else
F_33 ( V_2 -> V_6 , V_50 ) ;
} else if ( V_2 -> V_6 ) {
F_9 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
return 1 ;
#endif
case V_52 :
if ( V_41 == - 2 )
return V_2 -> V_7 ;
if ( V_41 != V_8 && V_41 != V_53 )
return - 2 ;
V_2 -> V_7 = V_41 ;
return 1 ;
case V_54 :
V_2 -> V_9 = V_42 ;
return 1 ;
case V_55 :
* ( const V_56 * * ) V_42 = V_2 -> V_9 ;
return 1 ;
case V_57 :
if ( V_41 <= 0 )
return - 2 ;
V_2 -> V_10 = ( T_3 ) V_41 ;
return 1 ;
case V_58 :
* ( int * ) V_42 = V_2 -> V_10 ;
return 1 ;
case V_59 :
if ( V_2 -> V_11 )
F_10 ( V_2 -> V_11 ) ;
V_2 -> V_11 = V_42 ;
if ( V_42 )
V_2 -> V_12 = V_41 ;
else
V_2 -> V_12 = 0 ;
return 1 ;
case V_60 :
* ( unsigned char * * ) V_42 = V_2 -> V_11 ;
return V_2 -> V_12 ;
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
V_2 -> V_4 = V_42 ;
return 1 ;
case V_68 :
* ( const V_56 * * ) V_42 = V_2 -> V_4 ;
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
static int F_34 ( T_1 * V_1 ,
const char * type , const char * V_73 )
{
if ( ! strcmp ( type , L_1 ) ) {
int V_74 ;
V_74 = F_35 ( V_73 ) ;
if ( V_74 == V_75 )
V_74 = F_36 ( V_73 ) ;
if ( V_74 == V_75 )
V_74 = F_37 ( V_73 ) ;
if ( V_74 == V_75 ) {
F_13 ( V_76 , V_45 ) ;
return 0 ;
}
return F_38 ( V_1 , V_74 ) ;
} else if ( ! strcmp ( type , L_2 ) ) {
int V_77 ;
if ( ! strcmp ( V_73 , L_3 ) )
V_77 = 0 ;
else if ( ! strcmp ( V_73 , L_4 ) )
V_77 = V_78 ;
else
return - 2 ;
return F_39 ( V_1 , V_77 ) ;
} else if ( ! strcmp ( type , L_5 ) ) {
const V_56 * V_4 ;
if ( ! ( V_4 = F_40 ( V_73 ) ) ) {
F_13 ( V_76 , V_79 ) ;
return 0 ;
}
return F_41 ( V_1 , V_4 ) ;
} else if ( ! strcmp ( type , L_6 ) ) {
int V_80 ;
V_80 = atoi ( V_73 ) ;
return F_42 ( V_1 , V_80 ) ;
}
return - 2 ;
}
static int F_43 ( T_1 * V_1 , T_7 * V_24 )
{
T_4 * V_23 = NULL ;
T_2 * V_2 = V_1 -> V_13 ;
int V_21 = 0 ;
if ( V_2 -> V_3 == NULL ) {
F_13 ( V_81 , V_47 ) ;
return 0 ;
}
V_23 = F_44 () ;
if ( ! V_23 )
return 0 ;
V_21 = F_45 ( V_23 , V_2 -> V_3 ) ;
if ( V_21 )
F_46 ( V_24 , V_23 ) ;
else
F_9 ( V_23 ) ;
return V_21 ;
}
static int F_47 ( T_1 * V_1 , T_7 * V_24 )
{
T_4 * V_23 = NULL ;
T_2 * V_2 = V_1 -> V_13 ;
if ( V_1 -> V_24 == NULL && V_2 -> V_3 == NULL ) {
F_13 ( V_82 , V_47 ) ;
return 0 ;
}
V_23 = F_44 () ;
if ( ! V_23 )
return 0 ;
F_46 ( V_24 , V_23 ) ;
if ( V_1 -> V_24 ) {
if ( ! F_48 ( V_24 , V_1 -> V_24 ) )
return 0 ;
} else {
if ( ! F_45 ( V_23 , V_2 -> V_3 ) )
return 0 ;
}
return F_49 ( V_24 -> V_24 . V_23 ) ;
}
