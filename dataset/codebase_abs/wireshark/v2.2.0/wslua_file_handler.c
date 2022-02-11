static int F_1 ( T_1 * V_1 ) {
const T_2 * error = F_2 ( V_1 , 1 ) ;
const T_2 * V_2 = F_3 ( V_1 , F_4 ( 1 ) , L_1 ) ;
F_5 ( L_2 , V_2 , error ) ;
F_6 ( V_1 , 1 ) ;
return 0 ;
}
static int F_7 ( T_1 * V_1 , const T_2 * V_3 ) {
F_8 ( V_1 , V_3 ) ;
F_9 ( V_1 , F_1 , 1 ) ;
return 1 ;
}
static T_3
F_10 ( T_4 * V_4 , int * V_5 , T_2 * * V_6 )
{
T_5 V_7 = ( T_5 ) ( V_4 -> V_8 ) ;
T_3 V_9 = V_10 ;
T_1 * V_1 = NULL ;
T_6 * V_11 = NULL ;
T_7 * V_12 = NULL ;
F_11 ( V_13 , V_10 ) ;
F_12 ( V_1 , V_4 ) ;
V_11 = F_13 ( V_1 , V_4 -> V_7 ) ;
V_12 = F_14 ( V_1 , V_4 , TRUE ) ;
V_14 = V_15 ;
switch ( F_15 ( V_1 , 2 , 1 , 1 ) ) {
case 0 :
V_9 = ( T_3 ) F_16 ( V_1 , - 1 , 0 ) ;
break;
F_17 ( L_3 )
}
F_18 () ;
( * V_11 ) -> V_16 = TRUE ;
( * V_12 ) -> V_16 = TRUE ;
if ( V_9 == V_17 ) {
if ( V_7 -> V_18 != V_19 ) {
V_4 -> V_20 = V_21 ;
}
else {
F_19 ( L_4 ) ;
return V_10 ;
}
if ( V_7 -> V_22 != V_19 ) {
V_4 -> V_23 = V_24 ;
}
else {
F_19 ( L_5 ) ;
return V_10 ;
}
if ( V_7 -> V_25 != V_19 )
V_4 -> V_26 = V_27 ;
else
V_4 -> V_26 = NULL ;
if ( V_7 -> V_28 != V_19 )
V_4 -> V_29 = V_30 ;
else
V_4 -> V_29 = NULL ;
V_4 -> V_31 = V_7 -> V_32 ;
}
else if ( V_9 == V_33 ) {
if ( V_5 ) {
* V_5 = V_15 ;
}
}
else if ( V_9 == V_10 ) {
F_20 ( V_1 , V_4 ) ;
}
else {
F_19 ( L_6 , V_9 ) ;
if ( V_5 ) {
* V_5 = V_34 ;
}
V_9 = V_33 ;
}
F_21 ( V_1 , 0 ) ;
return V_9 ;
}
static T_8
V_21 ( T_4 * V_4 , int * V_5 , T_2 * * V_6 ,
T_9 * V_35 )
{
T_5 V_7 = ( T_5 ) ( V_4 -> V_8 ) ;
int V_9 = - 1 ;
T_1 * V_1 = NULL ;
T_6 * V_11 = NULL ;
T_7 * V_12 = NULL ;
T_10 * V_36 = NULL ;
F_11 ( V_37 , FALSE ) ;
if ( V_5 ) {
* V_5 = V_14 = 0 ;
}
V_4 -> V_38 . V_39 = NULL ;
V_11 = F_13 ( V_1 , V_4 -> V_7 ) ;
V_12 = F_14 ( V_1 , V_4 , FALSE ) ;
V_36 = F_22 ( V_1 , & V_4 -> V_38 , V_4 -> V_40 ) ;
switch ( F_15 ( V_1 , 3 , 1 , 1 ) ) {
case 0 :
if ( F_23 ( V_1 , - 1 ) ) {
* V_35 = F_24 ( V_1 , - 1 ) ;
V_9 = 1 ;
break;
}
V_9 = F_16 ( V_1 , - 1 , 0 ) ;
break;
F_17 ( L_7 )
}
F_18 () ;
( * V_11 ) -> V_16 = TRUE ;
( * V_12 ) -> V_16 = TRUE ;
( * V_36 ) -> V_16 = TRUE ;
F_21 ( V_1 , 0 ) ;
return ( V_9 == 1 ) ;
}
static T_8
V_24 ( T_4 * V_4 , T_9 V_41 ,
struct V_42 * V_38 , T_11 * V_43 ,
int * V_5 , T_2 * * V_6 )
{
T_5 V_7 = ( T_5 ) ( V_4 -> V_8 ) ;
int V_9 = - 1 ;
T_1 * V_1 = NULL ;
T_6 * V_11 = NULL ;
T_7 * V_12 = NULL ;
T_10 * V_36 = NULL ;
F_11 ( V_44 , FALSE ) ;
if ( V_5 ) {
* V_5 = V_14 = 0 ;
}
V_38 -> V_39 = NULL ;
V_11 = F_13 ( V_1 , V_4 -> V_45 ) ;
V_12 = F_14 ( V_1 , V_4 , FALSE ) ;
V_36 = F_22 ( V_1 , V_38 , V_43 ) ;
F_25 ( V_1 , ( V_46 ) V_41 ) ;
switch ( F_15 ( V_1 , 4 , 1 , 1 ) ) {
case 0 :
if ( F_26 ( V_1 , - 1 ) ) {
T_12 V_47 = 0 ;
const T_2 * V_48 = F_27 ( V_1 , - 1 , & V_47 ) ;
if ( V_47 < V_49 )
memcpy ( F_28 ( V_43 ) , V_48 , V_47 ) ;
V_9 = 1 ;
break;
}
V_9 = F_16 ( V_1 , - 1 , 0 ) ;
break;
F_17 ( L_8 )
}
F_18 () ;
( * V_11 ) -> V_16 = TRUE ;
( * V_12 ) -> V_16 = TRUE ;
( * V_36 ) -> V_16 = TRUE ;
F_21 ( V_1 , 0 ) ;
return ( V_9 == 1 ) ;
}
static void
V_27 ( T_4 * V_4 )
{
T_5 V_7 = ( T_5 ) ( V_4 -> V_8 ) ;
T_1 * V_1 = NULL ;
T_6 * V_11 = NULL ;
T_7 * V_12 = NULL ;
F_11 ( V_50 ,) ;
V_11 = F_13 ( V_1 , V_4 -> V_7 ) ;
V_12 = F_14 ( V_1 , V_4 , FALSE ) ;
switch ( F_15 ( V_1 , 2 , 1 , 1 ) ) {
case 0 :
break;
F_29 ( L_9 )
}
F_18 () ;
F_20 ( V_1 , V_4 ) ;
( * V_11 ) -> V_16 = TRUE ;
( * V_12 ) -> V_16 = TRUE ;
F_21 ( V_1 , 0 ) ;
return;
}
static void
V_30 ( T_4 * V_4 )
{
T_5 V_7 = ( T_5 ) ( V_4 -> V_8 ) ;
T_1 * V_1 = NULL ;
T_6 * V_11 = NULL ;
T_7 * V_12 = NULL ;
F_11 ( V_51 ,) ;
V_11 = F_13 ( V_1 , V_4 -> V_7 ) ;
V_12 = F_14 ( V_1 , V_4 , FALSE ) ;
switch ( F_15 ( V_1 , 2 , 1 , 1 ) ) {
case 0 :
break;
F_29 ( L_10 )
}
F_18 () ;
( * V_11 ) -> V_16 = TRUE ;
( * V_12 ) -> V_16 = TRUE ;
F_21 ( V_1 , 0 ) ;
return;
}
static int
F_30 ( int T_13 V_52 )
{
return V_53 ;
}
static int
F_31 ( int T_13 , void * V_54 )
{
T_5 V_7 = ( T_5 ) ( V_54 ) ;
int V_9 = V_55 ;
T_1 * V_1 = NULL ;
F_11 ( V_56 , V_34 ) ;
F_25 ( V_1 , T_13 ) ;
switch ( F_15 ( V_1 , 1 , 1 , 1 ) ) {
case 0 :
V_9 = F_16 ( V_1 , - 1 , V_55 ) ;
break;
F_29 ( L_11 )
}
F_18 () ;
if ( V_9 == 1 ) {
V_9 = 0 ;
} else if ( V_9 == 0 ) {
V_9 = V_55 ;
}
return V_9 ;
}
static int
F_32 ( T_14 * V_57 , int * V_5 )
{
T_5 V_7 = ( T_5 ) ( V_57 -> V_8 ) ;
int V_9 = 0 ;
T_1 * V_1 = NULL ;
T_6 * V_11 = NULL ;
T_15 * V_12 = NULL ;
F_11 ( V_58 , 0 ) ;
F_33 ( V_1 , V_57 ) ;
V_11 = F_34 ( V_1 , V_57 ) ;
V_12 = F_35 ( V_1 , V_57 ) ;
if ( V_5 ) {
* V_5 = 0 ;
}
switch ( F_15 ( V_1 , 2 , 1 , 1 ) ) {
case 0 :
V_9 = F_16 ( V_1 , - 1 , 0 ) ;
break;
F_29 ( L_12 )
}
F_18 () ;
( * V_11 ) -> V_16 = TRUE ;
( * V_12 ) -> V_16 = TRUE ;
if ( V_9 == 1 ) {
if ( V_7 -> V_59 != V_19 ) {
V_57 -> V_60 = V_61 ;
}
else {
F_19 ( L_13 ) ;
return 0 ;
}
if ( V_7 -> V_62 != V_19 )
V_57 -> V_63 = V_64 ;
else
V_57 -> V_63 = NULL ;
}
else {
F_36 ( V_1 , V_57 ) ;
}
return V_9 ;
}
static T_8
V_61 ( T_14 * V_57 , const struct V_42 * V_38 ,
const T_16 * V_65 , int * V_5 , T_2 * * V_6 V_52 )
{
T_5 V_7 = ( T_5 ) ( V_57 -> V_8 ) ;
int V_9 = - 1 ;
T_1 * V_1 = NULL ;
T_6 * V_11 = NULL ;
T_15 * V_12 = NULL ;
T_17 * V_36 = NULL ;
F_11 ( V_66 , FALSE ) ;
if ( V_5 ) {
* V_5 = V_14 = 0 ;
}
V_11 = F_34 ( V_1 , V_57 ) ;
V_12 = F_35 ( V_1 , V_57 ) ;
V_36 = F_37 ( V_1 , V_38 , V_65 ) ;
V_14 = V_67 ;
switch ( F_15 ( V_1 , 3 , 1 , 1 ) ) {
case 0 :
V_9 = F_16 ( V_1 , - 1 , 0 ) ;
break;
F_29 ( L_14 )
}
F_18 () ;
( * V_11 ) -> V_16 = TRUE ;
( * V_12 ) -> V_16 = TRUE ;
( * V_36 ) -> V_16 = TRUE ;
return ( V_9 == 1 ) ;
}
static T_8
V_64 ( T_14 * V_57 , int * V_5 )
{
T_5 V_7 = ( T_5 ) ( V_57 -> V_8 ) ;
int V_9 = - 1 ;
T_1 * V_1 = NULL ;
T_6 * V_11 = NULL ;
T_15 * V_12 = NULL ;
F_11 ( V_68 , FALSE ) ;
if ( V_5 ) {
* V_5 = V_14 = 0 ;
}
V_11 = F_34 ( V_1 , V_57 ) ;
V_12 = F_35 ( V_1 , V_57 ) ;
V_14 = V_69 ;
switch ( F_15 ( V_1 , 2 , 1 , 1 ) ) {
case 0 :
V_9 = F_16 ( V_1 , - 1 , 0 ) ;
break;
F_29 ( L_15 )
}
F_18 () ;
F_36 ( V_1 , V_57 ) ;
( * V_11 ) -> V_16 = TRUE ;
( * V_12 ) -> V_16 = TRUE ;
return ( V_9 == 1 ) ;
}
T_18 F_38 ( T_1 * V_1 ) {
#define F_39 1
#define F_40 2
#define F_41 3
#define F_42 4
const T_2 * V_70 = F_43 ( V_1 , F_39 ) ;
const T_2 * V_71 = F_43 ( V_1 , F_40 ) ;
const T_2 * V_72 = F_43 ( V_1 , F_41 ) ;
const T_2 * type = F_43 ( V_1 , F_42 ) ;
T_5 V_7 = ( T_5 ) F_44 ( sizeof( struct V_73 ) ) ;
V_7 -> V_74 = ( strchr ( type , 'r' ) != NULL ) ? TRUE : FALSE ;
V_7 -> V_75 = ( strchr ( type , 'w' ) != NULL ) ? TRUE : FALSE ;
if ( V_7 -> V_74 && F_45 ( V_71 ) ) {
return F_46 ( V_1 , L_16 , V_71 ) ;
}
if ( V_7 -> V_75 && F_47 ( V_71 ) > - 1 ) {
return F_46 ( V_1 , L_17 , V_71 ) ;
}
V_7 -> type = F_48 ( type ) ;
V_7 -> V_76 . V_70 = F_48 ( V_70 ) ;
V_7 -> V_76 . V_71 = F_48 ( V_71 ) ;
V_7 -> V_76 . V_77 = NULL ;
V_7 -> V_76 . V_78 = NULL ;
V_7 -> V_76 . V_79 = FALSE ;
V_7 -> V_76 . V_80 = FALSE ;
V_7 -> V_76 . V_56 = NULL ;
V_7 -> V_76 . V_81 = NULL ;
V_7 -> V_32 = V_82 ;
V_7 -> V_83 = F_48 ( V_72 ) ;
V_7 -> V_1 = V_1 ;
V_7 -> V_84 = V_19 ;
V_7 -> V_18 = V_19 ;
V_7 -> V_22 = V_19 ;
V_7 -> V_25 = V_19 ;
V_7 -> V_28 = V_19 ;
V_7 -> V_85 = V_19 ;
V_7 -> V_59 = V_19 ;
V_7 -> V_62 = V_19 ;
V_7 -> V_86 = V_19 ;
V_7 -> V_87 = FALSE ;
F_49 ( V_1 , V_7 ) ;
F_50 ( 1 ) ;
}
T_19 F_51 ( T_1 * V_1 ) {
T_5 V_7 = F_52 ( V_1 , 1 ) ;
if ( ! V_7 ) {
F_8 ( V_1 , L_18 ) ;
} else {
F_53 ( V_1 , L_19 ,
V_7 -> V_76 . V_70 , V_7 -> V_76 . V_71 , V_7 -> V_83 , V_7 -> V_84 , V_7 -> V_18 , V_7 -> V_59 ) ;
}
F_50 ( 1 ) ;
}
static int F_54 ( T_1 * V_1 V_52 ) {
return 0 ;
}
static T_8 F_55 ( T_5 V_7 ) {
return ( ( V_7 -> V_74 || V_7 -> V_75 ) &&
( ! V_7 -> V_74 ||
( V_7 -> V_74 &&
V_7 -> V_84 != V_19 &&
V_7 -> V_18 != V_19 &&
V_7 -> V_22 != V_19 ) ) &&
( ! V_7 -> V_75 ||
( V_7 -> V_75 &&
V_7 -> V_86 != V_19 &&
V_7 -> V_85 != V_19 &&
V_7 -> V_59 != V_19 ) ) ) ;
}
T_20 F_56 ( T_1 * V_1 ) {
#define F_57 1
T_5 V_7 = F_58 ( V_1 , F_57 ) ;
if ( V_88 )
return F_46 ( V_1 , L_20 ) ;
if ( V_7 -> V_87 )
return F_46 ( V_1 , L_21 ) ;
if ( ! F_55 ( V_7 ) )
return F_46 ( V_1 , L_22 ) ;
if ( V_7 -> V_75 ) {
V_7 -> V_76 . V_56 = F_30 ;
V_7 -> V_76 . V_89 = ( V_90 * ) F_44 ( sizeof( V_90 ) ) ;
V_7 -> V_76 . V_89 -> V_91 = F_31 ;
V_7 -> V_76 . V_89 -> V_8 = ( void * ) ( V_7 ) ;
V_7 -> V_76 . V_81 = F_32 ;
}
V_7 -> V_32 = F_59 ( & ( V_7 -> V_76 ) , V_7 -> V_32 ) ;
if ( V_7 -> V_74 ) {
struct V_92 V_93 = { NULL , V_94 , NULL , NULL , NULL , NULL } ;
V_93 . V_70 = V_7 -> V_76 . V_71 ;
V_93 . V_95 = F_10 ;
V_93 . V_96 = V_7 -> V_76 . V_78 ;
V_93 . V_8 = ( void * ) ( V_7 ) ;
if ( strchr ( V_7 -> type , 'm' ) != NULL ) {
V_93 . type = V_97 ;
} else {
V_93 . type = V_94 ;
}
F_60 ( & V_93 , ( strchr ( V_7 -> type , 's' ) != NULL ) ) ;
}
V_7 -> V_87 = TRUE ;
F_25 ( V_1 , V_7 -> V_32 ) ;
F_50 ( 1 ) ;
}
T_20 F_61 ( T_1 * V_1 ) {
#define F_57 1
T_5 V_7 = F_58 ( V_1 , F_57 ) ;
if ( V_88 )
return F_46 ( V_1 , L_23 ) ;
if ( ! V_7 -> V_87 )
return 0 ;
V_7 -> V_76 . V_56 = NULL ;
if ( V_7 -> V_76 . V_89 ) {
V_7 -> V_76 . V_89 -> V_91 = NULL ;
V_7 -> V_76 . V_89 -> V_8 = NULL ;
F_62 ( V_7 -> V_76 . V_89 ) ;
V_7 -> V_76 . V_89 = NULL ;
}
V_7 -> V_76 . V_81 = NULL ;
if ( V_7 -> V_32 != V_82 )
F_63 ( V_7 -> V_32 ) ;
if ( V_7 -> V_74 && F_45 ( V_7 -> V_76 . V_71 ) ) {
F_64 ( V_7 -> V_76 . V_71 ) ;
}
V_7 -> V_87 = FALSE ;
return 0 ;
}
int F_65 ( T_1 * V_1 ) {
F_66 ( T_5 ) ;
F_67 ( T_5 ) ;
return 0 ;
}
int F_68 ( T_1 * V_1 V_52 ) {
return 0 ;
}
