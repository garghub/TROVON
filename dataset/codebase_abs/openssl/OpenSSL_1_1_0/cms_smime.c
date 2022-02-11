static T_1 * F_1 ( T_1 * V_1 , unsigned int V_2 )
{
T_1 * V_3 ;
if ( V_1 == NULL )
V_3 = F_2 ( F_3 () ) ;
else if ( V_2 & V_4 ) {
V_3 = F_2 ( F_4 () ) ;
F_5 ( V_3 , 0 ) ;
} else
V_3 = V_1 ;
return V_3 ;
}
static int F_6 ( T_1 * V_1 , T_1 * V_5 , unsigned int V_2 )
{
unsigned char V_6 [ 4096 ] ;
int V_7 = 0 , V_8 ;
T_1 * V_9 ;
V_9 = F_1 ( V_1 , V_2 ) ;
if ( V_9 == NULL ) {
F_7 ( V_10 , V_11 ) ;
goto V_12;
}
for (; ; ) {
V_8 = F_8 ( V_5 , V_6 , sizeof( V_6 ) ) ;
if ( V_8 <= 0 ) {
if ( F_9 ( V_5 ) == V_13 ) {
if ( ! F_10 ( V_5 ) )
goto V_12;
}
if ( V_8 < 0 )
goto V_12;
break;
}
if ( V_9 && ( F_11 ( V_9 , V_6 , V_8 ) != V_8 ) )
goto V_12;
}
if ( V_2 & V_4 ) {
if ( ! F_12 ( V_9 , V_1 ) ) {
F_7 ( V_10 , V_14 ) ;
goto V_12;
}
}
V_7 = 1 ;
V_12:
if ( V_9 != V_1 )
F_13 ( V_9 ) ;
return V_7 ;
}
static int F_14 ( T_2 * V_15 )
{
T_3 * * V_16 = F_15 ( V_15 ) ;
if ( ! V_16 || ! * V_16 ) {
F_7 ( V_17 , V_18 ) ;
return 0 ;
}
return 1 ;
}
static void F_16 ( T_1 * V_19 , T_1 * V_20 )
{
if ( V_20 ) {
T_1 * V_21 ;
do {
V_21 = F_17 ( V_19 ) ;
F_13 ( V_19 ) ;
V_19 = V_21 ;
}
while ( V_19 && V_19 != V_20 );
} else
F_18 ( V_19 ) ;
}
int F_19 ( T_2 * V_15 , T_1 * V_1 , unsigned int V_2 )
{
T_1 * V_22 ;
int V_7 ;
if ( F_20 ( F_21 ( V_15 ) ) != V_23 ) {
F_7 ( V_24 , V_25 ) ;
return 0 ;
}
V_22 = F_22 ( V_15 , NULL ) ;
if ( ! V_22 )
return 0 ;
V_7 = F_6 ( V_1 , V_22 , V_2 ) ;
F_18 ( V_22 ) ;
return V_7 ;
}
T_2 * F_23 ( T_1 * V_5 , unsigned int V_2 )
{
T_2 * V_15 ;
V_15 = F_24 () ;
if ( ! V_15 )
return NULL ;
if ( ( V_2 & V_26 ) || F_25 ( V_15 , V_5 , NULL , V_2 ) )
return V_15 ;
F_26 ( V_15 ) ;
return NULL ;
}
int F_27 ( T_2 * V_15 , T_1 * V_27 , T_1 * V_1 ,
unsigned int V_2 )
{
T_1 * V_22 ;
int V_7 ;
if ( F_20 ( F_21 ( V_15 ) ) != V_28 ) {
F_7 ( V_29 , V_30 ) ;
return 0 ;
}
if ( ! V_27 && ! F_14 ( V_15 ) )
return 0 ;
V_22 = F_22 ( V_15 , V_27 ) ;
if ( ! V_22 )
return 0 ;
V_7 = F_6 ( V_1 , V_22 , V_2 ) ;
if ( V_7 )
V_7 = F_28 ( V_15 , V_22 , 1 ) ;
F_16 ( V_22 , V_27 ) ;
return V_7 ;
}
T_2 * F_29 ( T_1 * V_5 , const T_4 * V_31 ,
unsigned int V_2 )
{
T_2 * V_15 ;
if ( ! V_31 )
V_31 = F_30 () ;
V_15 = F_31 ( V_31 ) ;
if ( ! V_15 )
return NULL ;
if ( ! ( V_2 & V_32 ) )
F_32 ( V_15 , 0 ) ;
if ( ( V_2 & V_26 ) || F_25 ( V_15 , V_5 , NULL , V_2 ) )
return V_15 ;
F_26 ( V_15 ) ;
return NULL ;
}
int F_33 ( T_2 * V_15 ,
const unsigned char * V_33 , T_5 V_34 ,
T_1 * V_27 , T_1 * V_1 , unsigned int V_2 )
{
T_1 * V_22 ;
int V_7 ;
if ( F_20 ( F_21 ( V_15 ) ) != V_35 ) {
F_7 ( V_36 ,
V_37 ) ;
return 0 ;
}
if ( ! V_27 && ! F_14 ( V_15 ) )
return 0 ;
if ( F_34 ( V_15 , NULL , V_33 , V_34 ) <= 0 )
return 0 ;
V_22 = F_22 ( V_15 , V_27 ) ;
if ( ! V_22 )
return 0 ;
V_7 = F_6 ( V_1 , V_22 , V_2 ) ;
F_16 ( V_22 , V_27 ) ;
return V_7 ;
}
T_2 * F_35 ( T_1 * V_5 , const T_6 * V_38 ,
const unsigned char * V_33 ,
T_5 V_34 , unsigned int V_2 )
{
T_2 * V_15 ;
if ( ! V_38 ) {
F_7 ( V_39 , V_40 ) ;
return NULL ;
}
V_15 = F_36 () ;
if ( V_15 == NULL )
return NULL ;
if ( ! F_34 ( V_15 , V_38 , V_33 , V_34 ) )
return NULL ;
if ( ! ( V_2 & V_32 ) )
F_32 ( V_15 , 0 ) ;
if ( ( V_2 & ( V_26 | V_41 ) )
|| F_25 ( V_15 , V_5 , NULL , V_2 ) )
return V_15 ;
F_26 ( V_15 ) ;
return NULL ;
}
static int F_37 ( T_2 * V_15 , T_7 * V_42 ,
T_8 * V_43 , T_9 * V_44 )
{
int V_8 ;
F_38 ( V_45 ) * V_46 ;
V_45 * V_47 ;
V_46 = F_39 ( V_42 ) ;
if ( ! V_44 )
return 0 ;
for ( V_8 = 0 ; V_8 < F_40 ( V_46 ) ; V_8 ++ ) {
int V_48 ;
V_47 = F_41 ( V_46 , V_8 ) ;
if ( F_42 ( V_47 , V_44 ) )
continue;
F_43 ( V_42 , V_43 ) ;
V_48 = F_44 ( V_15 , V_42 , V_47 ) ;
F_43 ( V_42 , NULL ) ;
if ( V_48 > 0 )
return 1 ;
return - 1 ;
}
return 0 ;
}
int F_45 ( T_2 * V_15 , T_8 * V_43 , T_9 * V_44 )
{
F_38 ( T_7 ) * V_49 ;
T_7 * V_42 ;
int V_8 , V_7 , V_50 ;
int V_51 = 0 , V_52 = 0 ;
V_49 = F_46 ( V_15 ) ;
if ( V_49 )
V_51 = V_15 -> V_53 . V_54 -> V_55 -> V_51 ;
V_50 = F_47 ( V_43 ) ;
if ( V_50 == V_56 ) {
F_7 ( V_57 ,
V_58 ) ;
return 0 ;
}
for ( V_8 = 0 ; V_8 < F_48 ( V_49 ) ; V_8 ++ ) {
V_42 = F_49 ( V_49 , V_8 ) ;
if ( F_50 ( V_42 ) != V_50 )
continue;
V_52 = 1 ;
if ( V_50 == V_59 ) {
V_7 = F_37 ( V_15 , V_42 , V_43 , V_44 ) ;
if ( V_7 > 0 )
return 1 ;
if ( V_7 < 0 )
return 0 ;
}
else if ( ! V_44 || ! F_51 ( V_42 , V_44 ) ) {
F_52 ( V_42 , V_43 ) ;
V_7 = F_53 ( V_15 , V_42 ) ;
F_52 ( V_42 , NULL ) ;
if ( V_44 ) {
if ( ! V_51 ) {
F_54 () ;
return 1 ;
}
if ( V_7 > 0 )
return 1 ;
F_7 ( V_57 , V_60 ) ;
return 0 ;
}
else if ( V_7 > 0 && V_51 )
return 1 ;
}
}
if ( V_52 && ! V_44 && ! V_51 ) {
F_54 () ;
return 1 ;
}
F_7 ( V_57 , V_61 ) ;
return 0 ;
}
int F_55 ( T_2 * V_15 ,
unsigned char * V_33 , T_5 V_34 ,
const unsigned char * V_62 , T_5 V_63 )
{
F_38 ( T_7 ) * V_49 ;
T_7 * V_42 ;
int V_8 , V_7 ;
V_49 = F_46 ( V_15 ) ;
for ( V_8 = 0 ; V_8 < F_48 ( V_49 ) ; V_8 ++ ) {
V_42 = F_49 ( V_49 , V_8 ) ;
if ( F_50 ( V_42 ) != V_64 )
continue;
if ( ! V_62 || ( F_56 ( V_42 , V_62 , V_63 ) == 0 ) ) {
F_57 ( V_42 , V_33 , V_34 ) ;
V_7 = F_53 ( V_15 , V_42 ) ;
F_57 ( V_42 , NULL , 0 ) ;
if ( V_7 > 0 )
return 1 ;
if ( V_62 ) {
F_7 ( V_65 , V_60 ) ;
return 0 ;
}
F_54 () ;
}
}
F_7 ( V_65 , V_61 ) ;
return 0 ;
}
int F_58 ( T_2 * V_15 ,
unsigned char * V_66 , T_10 V_67 )
{
F_38 ( T_7 ) * V_49 ;
T_7 * V_42 ;
int V_8 , V_7 ;
V_49 = F_46 ( V_15 ) ;
for ( V_8 = 0 ; V_8 < F_48 ( V_49 ) ; V_8 ++ ) {
V_42 = F_49 ( V_49 , V_8 ) ;
if ( F_50 ( V_42 ) != V_68 )
continue;
F_59 ( V_42 , V_66 , V_67 ) ;
V_7 = F_53 ( V_15 , V_42 ) ;
F_59 ( V_42 , NULL , 0 ) ;
if ( V_7 > 0 )
return 1 ;
}
F_7 ( V_69 , V_61 ) ;
return 0 ;
}
int F_60 ( T_2 * V_15 , T_8 * V_43 , T_9 * V_44 ,
T_1 * V_27 , T_1 * V_1 , unsigned int V_2 )
{
int V_7 ;
T_1 * V_22 ;
if ( F_20 ( F_21 ( V_15 ) ) != V_70 ) {
F_7 ( V_71 , V_72 ) ;
return 0 ;
}
if ( ! V_27 && ! F_14 ( V_15 ) )
return 0 ;
if ( V_2 & V_73 )
V_15 -> V_53 . V_54 -> V_55 -> V_51 = 1 ;
else
V_15 -> V_53 . V_54 -> V_55 -> V_51 = 0 ;
if ( ! V_43 && ! V_44 && ! V_27 && ! V_1 )
return 1 ;
if ( V_43 && ! F_45 ( V_15 , V_43 , V_44 ) )
return 0 ;
V_22 = F_22 ( V_15 , V_27 ) ;
if ( ! V_22 )
return 0 ;
V_7 = F_6 ( V_1 , V_22 , V_2 ) ;
F_16 ( V_22 , V_27 ) ;
return V_7 ;
}
int F_25 ( T_2 * V_15 , T_1 * V_74 , T_1 * V_27 , unsigned int V_2 )
{
T_1 * V_75 ;
int V_76 = 0 ;
if ( ( V_75 = F_22 ( V_15 , V_27 ) ) == NULL ) {
F_7 ( V_77 , V_78 ) ;
return 0 ;
}
F_61 ( V_74 , V_75 , V_2 ) ;
( void ) F_62 ( V_75 ) ;
if ( ! F_63 ( V_15 , V_75 ) ) {
F_7 ( V_77 , V_79 ) ;
goto V_12;
}
V_76 = 1 ;
V_12:
F_16 ( V_75 , V_27 ) ;
return V_76 ;
}
int F_64 ( T_2 * V_15 , T_1 * V_27 , T_1 * V_1 ,
unsigned int V_2 )
{
T_1 * V_22 ;
int V_7 ;
if ( F_20 ( F_21 ( V_15 ) ) != V_80 ) {
F_7 ( V_81 , V_82 ) ;
return 0 ;
}
if ( ! V_27 && ! F_14 ( V_15 ) )
return 0 ;
V_22 = F_22 ( V_15 , V_27 ) ;
if ( ! V_22 )
return 0 ;
V_7 = F_6 ( V_1 , V_22 , V_2 ) ;
F_16 ( V_22 , V_27 ) ;
return V_7 ;
}
T_2 * F_65 ( T_1 * V_5 , int V_83 , unsigned int V_2 )
{
T_2 * V_15 ;
if ( V_83 <= 0 )
V_83 = V_84 ;
V_15 = F_66 ( V_83 ) ;
if ( ! V_15 )
return NULL ;
if ( ! ( V_2 & V_32 ) )
F_32 ( V_15 , 0 ) ;
if ( ( V_2 & V_26 ) || F_25 ( V_15 , V_5 , NULL , V_2 ) )
return V_15 ;
F_26 ( V_15 ) ;
return NULL ;
}
int F_64 ( T_2 * V_15 , T_1 * V_27 , T_1 * V_1 ,
unsigned int V_2 )
{
F_7 ( V_81 , V_85 ) ;
return 0 ;
}
T_2 * F_65 ( T_1 * V_5 , int V_83 , unsigned int V_2 )
{
F_7 ( V_86 , V_85 ) ;
return NULL ;
}
