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
if ( F_23 ( V_1 , - 1 ) == V_41 ) {
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
V_24 ( T_4 * V_4 , T_9 V_42 ,
struct V_43 * V_38 , T_11 * V_44 ,
int * V_5 , T_2 * * V_6 )
{
T_5 V_7 = ( T_5 ) ( V_4 -> V_8 ) ;
int V_9 = - 1 ;
T_1 * V_1 = NULL ;
T_6 * V_11 = NULL ;
T_7 * V_12 = NULL ;
T_10 * V_36 = NULL ;
F_11 ( V_45 , FALSE ) ;
if ( V_5 ) {
* V_5 = V_14 = 0 ;
}
V_38 -> V_39 = NULL ;
V_11 = F_13 ( V_1 , V_4 -> V_46 ) ;
V_12 = F_14 ( V_1 , V_4 , FALSE ) ;
V_36 = F_22 ( V_1 , V_38 , V_44 ) ;
F_25 ( V_1 , ( V_47 ) V_42 ) ;
switch ( F_15 ( V_1 , 4 , 1 , 1 ) ) {
case 0 :
V_9 = F_26 ( V_1 , - 1 ) ;
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
F_11 ( V_48 ,) ;
V_11 = F_13 ( V_1 , V_4 -> V_7 ) ;
V_12 = F_14 ( V_1 , V_4 , FALSE ) ;
switch ( F_15 ( V_1 , 2 , 1 , 1 ) ) {
case 0 :
break;
F_27 ( L_9 )
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
F_11 ( V_49 ,) ;
V_11 = F_13 ( V_1 , V_4 -> V_7 ) ;
V_12 = F_14 ( V_1 , V_4 , FALSE ) ;
switch ( F_15 ( V_1 , 2 , 1 , 1 ) ) {
case 0 :
break;
F_27 ( L_10 )
}
F_18 () ;
( * V_11 ) -> V_16 = TRUE ;
( * V_12 ) -> V_16 = TRUE ;
F_21 ( V_1 , 0 ) ;
return;
}
static int
F_28 ( int T_12 V_50 )
{
return V_51 ;
}
static int
F_29 ( int T_12 , void * V_52 )
{
T_5 V_7 = ( T_5 ) ( V_52 ) ;
int V_9 = V_53 ;
T_1 * V_1 = NULL ;
F_11 ( V_54 , V_34 ) ;
F_25 ( V_1 , T_12 ) ;
switch ( F_15 ( V_1 , 1 , 1 , 1 ) ) {
case 0 :
V_9 = F_16 ( V_1 , - 1 , V_53 ) ;
break;
F_27 ( L_11 )
}
F_18 () ;
if ( V_9 == 1 ) {
V_9 = 0 ;
} else if ( V_9 == 0 ) {
V_9 = V_53 ;
}
return V_9 ;
}
static int
F_30 ( T_13 * V_55 , int * V_5 )
{
T_5 V_7 = ( T_5 ) ( V_55 -> V_8 ) ;
int V_9 = 0 ;
T_1 * V_1 = NULL ;
T_6 * V_11 = NULL ;
T_14 * V_12 = NULL ;
F_11 ( V_56 , 0 ) ;
F_31 ( V_1 , V_55 ) ;
V_11 = F_32 ( V_1 , V_55 ) ;
V_12 = F_33 ( V_1 , V_55 ) ;
if ( V_5 ) {
* V_5 = 0 ;
}
switch ( F_15 ( V_1 , 2 , 1 , 1 ) ) {
case 0 :
V_9 = F_16 ( V_1 , - 1 , 0 ) ;
break;
F_27 ( L_12 )
}
F_18 () ;
( * V_11 ) -> V_16 = TRUE ;
( * V_12 ) -> V_16 = TRUE ;
if ( V_9 == 1 ) {
if ( V_7 -> V_57 != V_19 ) {
V_55 -> V_58 = V_59 ;
}
else {
F_19 ( L_13 ) ;
return 0 ;
}
if ( V_7 -> V_60 != V_19 )
V_55 -> V_61 = V_62 ;
else
V_55 -> V_61 = NULL ;
}
else {
F_34 ( V_1 , V_55 ) ;
}
return V_9 ;
}
static T_8
V_59 ( T_13 * V_55 , const struct V_43 * V_38 ,
const T_15 * V_63 , int * V_5 , T_2 * * V_6 V_50 )
{
T_5 V_7 = ( T_5 ) ( V_55 -> V_8 ) ;
int V_9 = - 1 ;
T_1 * V_1 = NULL ;
T_6 * V_11 = NULL ;
T_14 * V_12 = NULL ;
T_16 * V_36 = NULL ;
F_11 ( V_64 , FALSE ) ;
if ( V_5 ) {
* V_5 = V_14 = 0 ;
}
V_11 = F_32 ( V_1 , V_55 ) ;
V_12 = F_33 ( V_1 , V_55 ) ;
V_36 = F_35 ( V_1 , V_38 , V_63 ) ;
V_14 = V_65 ;
switch ( F_15 ( V_1 , 3 , 1 , 1 ) ) {
case 0 :
V_9 = F_16 ( V_1 , - 1 , 0 ) ;
break;
F_27 ( L_14 )
}
F_18 () ;
( * V_11 ) -> V_16 = TRUE ;
( * V_12 ) -> V_16 = TRUE ;
( * V_36 ) -> V_16 = TRUE ;
return ( V_9 == 1 ) ;
}
static T_8
V_62 ( T_13 * V_55 , int * V_5 )
{
T_5 V_7 = ( T_5 ) ( V_55 -> V_8 ) ;
int V_9 = - 1 ;
T_1 * V_1 = NULL ;
T_6 * V_11 = NULL ;
T_14 * V_12 = NULL ;
F_11 ( V_66 , FALSE ) ;
if ( V_5 ) {
* V_5 = V_14 = 0 ;
}
V_11 = F_32 ( V_1 , V_55 ) ;
V_12 = F_33 ( V_1 , V_55 ) ;
V_14 = V_67 ;
switch ( F_15 ( V_1 , 2 , 1 , 1 ) ) {
case 0 :
V_9 = F_16 ( V_1 , - 1 , 0 ) ;
break;
F_27 ( L_15 )
}
F_18 () ;
F_34 ( V_1 , V_55 ) ;
( * V_11 ) -> V_16 = TRUE ;
( * V_12 ) -> V_16 = TRUE ;
return ( V_9 == 1 ) ;
}
T_17 F_36 ( T_1 * V_1 ) {
#define F_37 1
#define F_38 2
#define F_39 3
#define F_40 4
const T_2 * V_68 = F_41 ( V_1 , F_37 ) ;
const T_2 * V_69 = F_41 ( V_1 , F_38 ) ;
const T_2 * V_70 = F_41 ( V_1 , F_39 ) ;
const T_2 * type = F_41 ( V_1 , F_40 ) ;
T_5 V_7 = ( T_5 ) F_42 ( sizeof( struct V_71 ) ) ;
V_7 -> V_72 = ( strchr ( type , 'r' ) != NULL ) ? TRUE : FALSE ;
V_7 -> V_73 = ( strchr ( type , 'w' ) != NULL ) ? TRUE : FALSE ;
if ( V_7 -> V_72 && F_43 ( V_69 ) ) {
return F_44 ( V_1 , L_16 , V_69 ) ;
}
if ( V_7 -> V_73 && F_45 ( V_69 ) > - 1 ) {
return F_44 ( V_1 , L_17 , V_69 ) ;
}
V_7 -> type = F_46 ( type ) ;
V_7 -> V_74 . V_68 = F_46 ( V_68 ) ;
V_7 -> V_74 . V_69 = F_46 ( V_69 ) ;
V_7 -> V_74 . V_75 = NULL ;
V_7 -> V_74 . V_76 = NULL ;
V_7 -> V_74 . V_77 = FALSE ;
V_7 -> V_74 . V_78 = FALSE ;
V_7 -> V_74 . V_54 = NULL ;
V_7 -> V_74 . V_79 = NULL ;
V_7 -> V_32 = V_80 ;
V_7 -> V_81 = F_46 ( V_70 ) ;
V_7 -> V_1 = V_1 ;
V_7 -> V_82 = V_19 ;
V_7 -> V_18 = V_19 ;
V_7 -> V_22 = V_19 ;
V_7 -> V_25 = V_19 ;
V_7 -> V_28 = V_19 ;
V_7 -> V_83 = V_19 ;
V_7 -> V_57 = V_19 ;
V_7 -> V_60 = V_19 ;
V_7 -> V_84 = V_19 ;
V_7 -> V_85 = FALSE ;
F_47 ( V_1 , V_7 ) ;
F_48 ( 1 ) ;
}
T_18 F_49 ( T_1 * V_1 ) {
T_5 V_7 = F_50 ( V_1 , 1 ) ;
if ( ! V_7 ) {
F_8 ( V_1 , L_18 ) ;
} else {
F_51 ( V_1 , L_19 ,
V_7 -> V_74 . V_68 , V_7 -> V_74 . V_69 , V_7 -> V_81 , V_7 -> V_82 , V_7 -> V_18 , V_7 -> V_57 ) ;
}
F_48 ( 1 ) ;
}
static int F_52 ( T_1 * V_1 V_50 ) {
return 0 ;
}
static T_8 F_53 ( T_5 V_7 ) {
return ( ( V_7 -> V_72 || V_7 -> V_73 ) &&
( ! V_7 -> V_72 ||
( V_7 -> V_72 &&
V_7 -> V_82 != V_19 &&
V_7 -> V_18 != V_19 &&
V_7 -> V_22 != V_19 ) ) &&
( ! V_7 -> V_73 ||
( V_7 -> V_73 &&
V_7 -> V_84 != V_19 &&
V_7 -> V_83 != V_19 &&
V_7 -> V_57 != V_19 ) ) ) ;
}
T_19 F_54 ( T_1 * V_1 ) {
#define F_55 1
T_5 V_7 = F_56 ( V_1 , F_55 ) ;
if ( V_86 )
return F_44 ( V_1 , L_20 ) ;
if ( V_7 -> V_85 )
return F_44 ( V_1 , L_21 ) ;
if ( ! F_53 ( V_7 ) )
return F_44 ( V_1 , L_22 ) ;
if ( V_7 -> V_73 ) {
V_7 -> V_74 . V_54 = F_28 ;
V_7 -> V_74 . V_87 = ( V_88 * ) F_42 ( sizeof( V_88 ) ) ;
V_7 -> V_74 . V_87 -> V_89 = F_29 ;
V_7 -> V_74 . V_87 -> V_8 = ( void * ) ( V_7 ) ;
V_7 -> V_74 . V_79 = F_30 ;
}
V_7 -> V_32 = F_57 ( & ( V_7 -> V_74 ) , V_7 -> V_32 ) ;
if ( V_7 -> V_72 ) {
struct V_90 V_91 = { NULL , V_92 , NULL , NULL , NULL , NULL } ;
V_91 . V_68 = V_7 -> V_74 . V_69 ;
V_91 . V_93 = F_10 ;
V_91 . V_94 = V_7 -> V_74 . V_76 ;
V_91 . V_8 = ( void * ) ( V_7 ) ;
if ( strchr ( V_7 -> type , 'm' ) != NULL ) {
V_91 . type = V_95 ;
} else {
V_91 . type = V_92 ;
}
F_58 ( & V_91 , ( strchr ( V_7 -> type , 's' ) != NULL ) ) ;
}
V_7 -> V_85 = TRUE ;
F_25 ( V_1 , V_7 -> V_32 ) ;
F_48 ( 1 ) ;
}
T_19 F_59 ( T_1 * V_1 ) {
#define F_55 1
T_5 V_7 = F_56 ( V_1 , F_55 ) ;
if ( V_86 )
return F_44 ( V_1 , L_23 ) ;
if ( ! V_7 -> V_85 )
return 0 ;
V_7 -> V_74 . V_54 = NULL ;
if ( V_7 -> V_74 . V_87 ) {
V_7 -> V_74 . V_87 -> V_89 = NULL ;
V_7 -> V_74 . V_87 -> V_8 = NULL ;
F_60 ( V_7 -> V_74 . V_87 ) ;
V_7 -> V_74 . V_87 = NULL ;
}
V_7 -> V_74 . V_79 = NULL ;
if ( V_7 -> V_32 != V_80 )
F_61 ( V_7 -> V_32 ) ;
if ( V_7 -> V_72 && F_43 ( V_7 -> V_74 . V_69 ) ) {
F_62 ( V_7 -> V_74 . V_69 ) ;
}
V_7 -> V_85 = FALSE ;
return 0 ;
}
int F_63 ( T_1 * V_1 ) {
F_64 ( T_5 ) ;
F_65 ( T_5 ) ;
return 0 ;
}
int F_66 ( T_1 * V_1 V_50 ) {
return 0 ;
}
