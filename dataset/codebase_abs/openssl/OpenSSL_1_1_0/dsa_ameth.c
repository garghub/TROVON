static int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
const unsigned char * V_3 , * V_4 ;
int V_5 , V_6 ;
int V_7 ;
const void * V_8 ;
const T_3 * V_9 ;
T_4 * V_10 ;
T_5 * V_11 = NULL ;
T_6 * V_12 = NULL ;
if ( ! F_2 ( NULL , & V_3 , & V_5 , & V_10 , V_2 ) )
return 0 ;
F_3 ( NULL , & V_7 , & V_8 , V_10 ) ;
if ( V_7 == V_13 ) {
V_9 = V_8 ;
V_4 = V_9 -> V_14 ;
V_6 = V_9 -> V_15 ;
if ( ( V_12 = F_4 ( NULL , & V_4 , V_6 ) ) == NULL ) {
F_5 ( V_16 , V_17 ) ;
goto V_18;
}
} else if ( ( V_7 == V_19 ) || ( V_7 == V_20 ) ) {
if ( ( V_12 = F_6 () ) == NULL ) {
F_5 ( V_16 , V_21 ) ;
goto V_18;
}
} else {
F_5 ( V_16 , V_22 ) ;
goto V_18;
}
if ( ( V_11 = F_7 ( NULL , & V_3 , V_5 ) ) == NULL ) {
F_5 ( V_16 , V_17 ) ;
goto V_18;
}
if ( ( V_12 -> V_23 = F_8 ( V_11 , NULL ) ) == NULL ) {
F_5 ( V_16 , V_24 ) ;
goto V_18;
}
F_9 ( V_11 ) ;
F_10 ( V_1 , V_12 ) ;
return 1 ;
V_18:
F_9 ( V_11 ) ;
F_11 ( V_12 ) ;
return 0 ;
}
static int F_12 ( T_2 * V_25 , const T_1 * V_1 )
{
T_6 * V_12 ;
int V_7 ;
unsigned char * V_26 = NULL ;
int V_27 ;
T_3 * V_28 = NULL ;
T_5 * V_29 = NULL ;
V_12 = V_1 -> V_1 . V_12 ;
if ( V_1 -> V_30 && V_12 -> V_3 && V_12 -> V_31 && V_12 -> V_32 ) {
V_28 = F_13 () ;
if ( V_28 == NULL ) {
F_5 ( V_33 , V_21 ) ;
goto V_18;
}
V_28 -> V_15 = F_14 ( V_12 , & V_28 -> V_14 ) ;
if ( V_28 -> V_15 <= 0 ) {
F_5 ( V_33 , V_21 ) ;
goto V_18;
}
V_7 = V_13 ;
} else
V_7 = V_20 ;
V_29 = F_15 ( V_12 -> V_23 , NULL ) ;
if ( V_29 == NULL ) {
F_5 ( V_33 , V_21 ) ;
goto V_18;
}
V_27 = F_16 ( V_29 , & V_26 ) ;
F_9 ( V_29 ) ;
if ( V_27 <= 0 ) {
F_5 ( V_33 , V_21 ) ;
goto V_18;
}
if ( F_17 ( V_25 , F_18 ( V_34 ) ,
V_7 , V_28 , V_26 , V_27 ) )
return 1 ;
V_18:
F_19 ( V_26 ) ;
F_20 ( V_28 ) ;
return 0 ;
}
static int F_21 ( T_1 * V_1 , const T_7 * V_35 )
{
const unsigned char * V_3 , * V_4 ;
int V_5 , V_6 ;
int V_7 ;
const void * V_8 ;
const T_3 * V_9 ;
const T_4 * V_10 ;
T_5 * V_36 = NULL ;
T_8 * V_37 = NULL ;
T_6 * V_12 = NULL ;
int V_38 = 0 ;
if ( ! F_22 ( NULL , & V_3 , & V_5 , & V_10 , V_35 ) )
return 0 ;
F_3 ( NULL , & V_7 , & V_8 , V_10 ) ;
if ( ( V_36 = F_7 ( NULL , & V_3 , V_5 ) ) == NULL )
goto V_39;
if ( V_36 -> type == V_40 || V_7 != V_13 )
goto V_39;
V_9 = V_8 ;
V_4 = V_9 -> V_14 ;
V_6 = V_9 -> V_15 ;
if ( ( V_12 = F_4 ( NULL , & V_4 , V_6 ) ) == NULL )
goto V_39;
if ( ( V_12 -> V_41 = F_23 () ) == NULL
|| ! F_8 ( V_36 , V_12 -> V_41 ) ) {
F_5 ( V_42 , V_43 ) ;
goto V_44;
}
if ( ( V_12 -> V_23 = F_24 () ) == NULL ) {
F_5 ( V_42 , V_21 ) ;
goto V_44;
}
if ( ( V_37 = F_25 () ) == NULL ) {
F_5 ( V_42 , V_21 ) ;
goto V_44;
}
if ( ! F_26 ( V_12 -> V_23 , V_12 -> V_32 , V_12 -> V_41 , V_12 -> V_3 , V_37 ) ) {
F_5 ( V_42 , V_43 ) ;
goto V_44;
}
F_10 ( V_1 , V_12 ) ;
V_38 = 1 ;
goto V_45;
V_39:
F_5 ( V_42 , V_17 ) ;
V_44:
F_11 ( V_12 ) ;
V_45:
F_27 ( V_37 ) ;
F_28 ( V_36 ) ;
return V_38 ;
}
static int F_29 ( T_7 * V_35 , const T_1 * V_1 )
{
T_3 * V_46 = NULL ;
T_5 * V_47 = NULL ;
unsigned char * V_48 = NULL ;
int V_49 ;
if ( ! V_1 -> V_1 . V_12 || ! V_1 -> V_1 . V_12 -> V_41 ) {
F_5 ( V_50 , V_51 ) ;
goto V_18;
}
V_46 = F_13 () ;
if ( V_46 == NULL ) {
F_5 ( V_50 , V_21 ) ;
goto V_18;
}
V_46 -> V_15 = F_14 ( V_1 -> V_1 . V_12 , & V_46 -> V_14 ) ;
if ( V_46 -> V_15 <= 0 ) {
F_5 ( V_50 , V_21 ) ;
goto V_18;
}
V_46 -> type = V_13 ;
V_47 = F_15 ( V_1 -> V_1 . V_12 -> V_41 , NULL ) ;
if ( ! V_47 ) {
F_5 ( V_50 , V_43 ) ;
goto V_18;
}
V_49 = F_16 ( V_47 , & V_48 ) ;
F_28 ( V_47 ) ;
V_47 = NULL ;
if ( ! F_30 ( V_35 , F_18 ( V_52 ) , 0 ,
V_13 , V_46 , V_48 , V_49 ) )
goto V_18;
return 1 ;
V_18:
F_19 ( V_48 ) ;
F_20 ( V_46 ) ;
F_28 ( V_47 ) ;
return 0 ;
}
static int F_31 ( const T_1 * V_1 )
{
return ( F_32 ( V_1 -> V_1 . V_12 ) ) ;
}
static int F_33 ( const T_1 * V_1 )
{
return F_34 ( V_1 -> V_1 . V_12 ) ;
}
static int F_35 ( const T_1 * V_1 )
{
return F_36 ( V_1 -> V_1 . V_12 ) ;
}
static int F_37 ( const T_1 * V_1 )
{
T_6 * V_12 ;
V_12 = V_1 -> V_1 . V_12 ;
if ( V_12 == NULL || V_12 -> V_3 == NULL || V_12 -> V_31 == NULL || V_12 -> V_32 == NULL )
return 1 ;
return 0 ;
}
static int F_38 ( T_1 * V_53 , const T_1 * V_54 )
{
T_9 * V_55 ;
if ( V_53 -> V_1 . V_12 == NULL ) {
V_53 -> V_1 . V_12 = F_6 () ;
if ( V_53 -> V_1 . V_12 == NULL )
return 0 ;
}
if ( ( V_55 = F_39 ( V_54 -> V_1 . V_12 -> V_3 ) ) == NULL )
return 0 ;
F_40 ( V_53 -> V_1 . V_12 -> V_3 ) ;
V_53 -> V_1 . V_12 -> V_3 = V_55 ;
if ( ( V_55 = F_39 ( V_54 -> V_1 . V_12 -> V_31 ) ) == NULL )
return 0 ;
F_40 ( V_53 -> V_1 . V_12 -> V_31 ) ;
V_53 -> V_1 . V_12 -> V_31 = V_55 ;
if ( ( V_55 = F_39 ( V_54 -> V_1 . V_12 -> V_32 ) ) == NULL )
return 0 ;
F_40 ( V_53 -> V_1 . V_12 -> V_32 ) ;
V_53 -> V_1 . V_12 -> V_32 = V_55 ;
return 1 ;
}
static int F_41 ( const T_1 * V_55 , const T_1 * V_56 )
{
if ( F_42 ( V_55 -> V_1 . V_12 -> V_3 , V_56 -> V_1 . V_12 -> V_3 ) ||
F_42 ( V_55 -> V_1 . V_12 -> V_31 , V_56 -> V_1 . V_12 -> V_31 ) ||
F_42 ( V_55 -> V_1 . V_12 -> V_32 , V_56 -> V_1 . V_12 -> V_32 ) )
return 0 ;
else
return 1 ;
}
static int F_43 ( const T_1 * V_55 , const T_1 * V_56 )
{
if ( F_42 ( V_56 -> V_1 . V_12 -> V_23 , V_55 -> V_1 . V_12 -> V_23 ) != 0 )
return 0 ;
else
return 1 ;
}
static void F_44 ( T_1 * V_1 )
{
F_11 ( V_1 -> V_1 . V_12 ) ;
}
static int F_45 ( T_10 * V_57 , const T_6 * V_58 , int V_59 , int V_7 )
{
int V_38 = 0 ;
const char * V_60 = NULL ;
const T_9 * V_41 , * V_23 ;
if ( V_7 == 2 )
V_41 = V_58 -> V_41 ;
else
V_41 = NULL ;
if ( V_7 > 0 )
V_23 = V_58 -> V_23 ;
else
V_23 = NULL ;
if ( V_7 == 2 )
V_60 = L_1 ;
else if ( V_7 == 1 )
V_60 = L_2 ;
else
V_60 = L_3 ;
if ( V_41 ) {
if ( ! F_46 ( V_57 , V_59 , 128 ) )
goto V_18;
if ( F_47 ( V_57 , L_4 , V_60 , F_48 ( V_58 -> V_3 ) )
<= 0 )
goto V_18;
}
if ( ! F_49 ( V_57 , L_5 , V_41 , NULL , V_59 ) )
goto V_18;
if ( ! F_49 ( V_57 , L_6 , V_23 , NULL , V_59 ) )
goto V_18;
if ( ! F_49 ( V_57 , L_7 , V_58 -> V_3 , NULL , V_59 ) )
goto V_18;
if ( ! F_49 ( V_57 , L_8 , V_58 -> V_31 , NULL , V_59 ) )
goto V_18;
if ( ! F_49 ( V_57 , L_9 , V_58 -> V_32 , NULL , V_59 ) )
goto V_18;
V_38 = 1 ;
V_18:
return ( V_38 ) ;
}
static int F_50 ( T_1 * V_1 ,
const unsigned char * * V_61 , int V_62 )
{
T_6 * V_12 ;
if ( ( V_12 = F_4 ( NULL , V_61 , V_62 ) ) == NULL ) {
F_5 ( V_63 , V_64 ) ;
return 0 ;
}
F_10 ( V_1 , V_12 ) ;
return 1 ;
}
static int F_51 ( const T_1 * V_1 , unsigned char * * V_61 )
{
return F_14 ( V_1 -> V_1 . V_12 , V_61 ) ;
}
static int F_52 ( T_10 * V_57 , const T_1 * V_1 , int V_65 ,
T_11 * V_37 )
{
return F_45 ( V_57 , V_1 -> V_1 . V_12 , V_65 , 0 ) ;
}
static int F_53 ( T_10 * V_57 , const T_1 * V_1 , int V_65 ,
T_11 * V_37 )
{
return F_45 ( V_57 , V_1 -> V_1 . V_12 , V_65 , 1 ) ;
}
static int F_54 ( T_10 * V_57 , const T_1 * V_1 , int V_65 ,
T_11 * V_37 )
{
return F_45 ( V_57 , V_1 -> V_1 . V_12 , V_65 , 2 ) ;
}
static int F_55 ( T_1 * V_1 ,
const unsigned char * * V_61 , int V_62 )
{
T_6 * V_12 ;
if ( ( V_12 = F_56 ( NULL , V_61 , V_62 ) ) == NULL ) {
F_5 ( V_66 , V_64 ) ;
return 0 ;
}
F_10 ( V_1 , V_12 ) ;
return 1 ;
}
static int F_57 ( const T_1 * V_1 , unsigned char * * V_61 )
{
return F_58 ( V_1 -> V_1 . V_12 , V_61 ) ;
}
static int F_59 ( T_10 * V_57 , const T_4 * V_67 ,
const T_3 * V_68 , int V_65 , T_11 * V_69 )
{
T_12 * V_70 ;
const unsigned char * V_3 ;
if ( ! V_68 ) {
if ( F_60 ( V_57 , L_10 ) <= 0 )
return 0 ;
else
return 1 ;
}
V_3 = V_68 -> V_14 ;
V_70 = F_61 ( NULL , & V_3 , V_68 -> V_15 ) ;
if ( V_70 ) {
int V_71 = 0 ;
const T_9 * V_72 , * V_73 ;
F_62 ( V_70 , & V_72 , & V_73 ) ;
if ( F_63 ( V_57 , L_10 , 1 ) != 1 )
goto V_18;
if ( ! F_49 ( V_57 , L_11 , V_72 , NULL , V_65 ) )
goto V_18;
if ( ! F_49 ( V_57 , L_12 , V_73 , NULL , V_65 ) )
goto V_18;
V_71 = 1 ;
V_18:
F_64 ( V_70 ) ;
return V_71 ;
}
return F_65 ( V_57 , V_68 , V_65 ) ;
}
static int F_66 ( T_1 * V_1 , int V_74 , long V_75 , void * V_76 )
{
switch ( V_74 ) {
case V_77 :
if ( V_75 == 0 ) {
int V_78 , V_79 ;
T_4 * V_80 , * V_81 ;
F_67 ( V_76 , NULL , & V_80 , & V_81 ) ;
if ( V_80 == NULL || V_80 -> V_82 == NULL )
return - 1 ;
V_79 = F_68 ( V_80 -> V_82 ) ;
if ( V_79 == V_83 )
return - 1 ;
if ( ! F_69 ( & V_78 , V_79 , F_70 ( V_1 ) ) )
return - 1 ;
F_71 ( V_81 , F_18 ( V_78 ) , V_20 , 0 ) ;
}
return 1 ;
#ifndef F_72
case V_84 :
if ( V_75 == 0 ) {
int V_78 , V_79 ;
T_4 * V_80 , * V_81 ;
F_73 ( V_76 , NULL , NULL , & V_80 , & V_81 ) ;
if ( V_80 == NULL || V_80 -> V_82 == NULL )
return - 1 ;
V_79 = F_68 ( V_80 -> V_82 ) ;
if ( V_79 == V_83 )
return - 1 ;
if ( ! F_69 ( & V_78 , V_79 , F_70 ( V_1 ) ) )
return - 1 ;
F_71 ( V_81 , F_18 ( V_78 ) , V_20 , 0 ) ;
}
return 1 ;
case V_85 :
* ( int * ) V_76 = V_86 ;
return 1 ;
#endif
case V_87 :
* ( int * ) V_76 = V_88 ;
return 2 ;
default:
return - 2 ;
}
}
