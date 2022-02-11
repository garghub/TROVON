static int F_1 ( T_1 * V_1 , T_1 * V_2 , unsigned int V_3 )
{
unsigned char V_4 [ 4096 ] ;
int V_5 = 0 , V_6 ;
T_1 * V_7 = NULL ;
if ( V_1 == NULL )
V_7 = F_2 ( F_3 () ) ;
else if ( V_3 & V_8 ) {
V_7 = F_2 ( F_4 () ) ;
F_5 ( V_7 , 0 ) ;
} else
V_7 = V_1 ;
if ( ! V_7 ) {
F_6 ( V_9 , V_10 ) ;
goto V_11;
}
for (; ; ) {
V_6 = F_7 ( V_2 , V_4 , sizeof( V_4 ) ) ;
if ( V_6 <= 0 ) {
if ( F_8 ( V_2 ) == V_12 ) {
if ( ! F_9 ( V_2 ) )
goto V_11;
}
if ( V_6 < 0 )
goto V_11;
break;
}
if ( V_7 && ( F_10 ( V_7 , V_4 , V_6 ) != V_6 ) )
goto V_11;
}
if ( V_3 & V_8 ) {
if ( ! F_11 ( V_7 , V_1 ) ) {
F_6 ( V_9 , V_13 ) ;
goto V_11;
}
}
V_5 = 1 ;
V_11:
if ( V_7 && ( V_7 != V_1 ) )
F_12 ( V_7 ) ;
return V_5 ;
}
static int F_13 ( T_2 * V_14 )
{
T_3 * * V_15 = F_14 ( V_14 ) ;
if ( ! V_15 || ! * V_15 ) {
F_6 ( V_16 , V_17 ) ;
return 0 ;
}
return 1 ;
}
static void F_15 ( T_1 * V_18 , T_1 * V_19 )
{
if ( V_19 ) {
T_1 * V_20 ;
do {
V_20 = F_16 ( V_18 ) ;
F_12 ( V_18 ) ;
V_18 = V_20 ;
}
while ( V_18 != V_19 );
} else
F_17 ( V_18 ) ;
}
int F_18 ( T_2 * V_14 , T_1 * V_1 , unsigned int V_3 )
{
T_1 * V_21 ;
int V_5 ;
if ( F_19 ( F_20 ( V_14 ) ) != V_22 ) {
F_6 ( V_23 , V_24 ) ;
return 0 ;
}
V_21 = F_21 ( V_14 , NULL ) ;
if ( ! V_21 )
return 0 ;
V_5 = F_1 ( V_1 , V_21 , V_3 ) ;
F_17 ( V_21 ) ;
return V_5 ;
}
T_2 * F_22 ( T_1 * V_2 , unsigned int V_3 )
{
T_2 * V_14 ;
V_14 = F_23 () ;
if ( ! V_14 )
return NULL ;
if ( ( V_3 & V_25 ) || F_24 ( V_14 , V_2 , NULL , V_3 ) )
return V_14 ;
F_25 ( V_14 ) ;
return NULL ;
}
int F_26 ( T_2 * V_14 , T_1 * V_26 , T_1 * V_1 ,
unsigned int V_3 )
{
T_1 * V_21 ;
int V_5 ;
if ( F_19 ( F_20 ( V_14 ) ) != V_27 ) {
F_6 ( V_28 , V_29 ) ;
return 0 ;
}
if ( ! V_26 && ! F_13 ( V_14 ) )
return 0 ;
V_21 = F_21 ( V_14 , V_26 ) ;
if ( ! V_21 )
return 0 ;
V_5 = F_1 ( V_1 , V_21 , V_3 ) ;
if ( V_5 )
V_5 = F_27 ( V_14 , V_21 , 1 ) ;
F_15 ( V_21 , V_26 ) ;
return V_5 ;
}
T_2 * F_28 ( T_1 * V_2 , const T_4 * V_30 ,
unsigned int V_3 )
{
T_2 * V_14 ;
if ( ! V_30 )
V_30 = F_29 () ;
V_14 = F_30 ( V_30 ) ;
if ( ! V_14 )
return NULL ;
if ( ! ( V_3 & V_31 ) )
F_31 ( V_14 , 0 ) ;
if ( ( V_3 & V_25 ) || F_24 ( V_14 , V_2 , NULL , V_3 ) )
return V_14 ;
F_25 ( V_14 ) ;
return NULL ;
}
int F_32 ( T_2 * V_14 ,
const unsigned char * V_32 , T_5 V_33 ,
T_1 * V_26 , T_1 * V_1 , unsigned int V_3 )
{
T_1 * V_21 ;
int V_5 ;
if ( F_19 ( F_20 ( V_14 ) ) != V_34 ) {
F_6 ( V_35 ,
V_36 ) ;
return 0 ;
}
if ( ! V_26 && ! F_13 ( V_14 ) )
return 0 ;
if ( F_33 ( V_14 , NULL , V_32 , V_33 ) <= 0 )
return 0 ;
V_21 = F_21 ( V_14 , V_26 ) ;
if ( ! V_21 )
return 0 ;
V_5 = F_1 ( V_1 , V_21 , V_3 ) ;
F_15 ( V_21 , V_26 ) ;
return V_5 ;
}
T_2 * F_34 ( T_1 * V_2 , const T_6 * V_37 ,
const unsigned char * V_32 ,
T_5 V_33 , unsigned int V_3 )
{
T_2 * V_14 ;
if ( ! V_37 ) {
F_6 ( V_38 , V_39 ) ;
return NULL ;
}
V_14 = F_35 () ;
if ( ! V_14 )
return NULL ;
if ( ! F_33 ( V_14 , V_37 , V_32 , V_33 ) )
return NULL ;
if ( ! ( V_3 & V_31 ) )
F_31 ( V_14 , 0 ) ;
if ( ( V_3 & ( V_25 | V_40 ) )
|| F_24 ( V_14 , V_2 , NULL , V_3 ) )
return V_14 ;
F_25 ( V_14 ) ;
return NULL ;
}
static int F_36 ( T_2 * V_14 , T_7 * V_41 ,
T_8 * V_42 , T_9 * V_43 )
{
int V_6 ;
F_37 ( V_44 ) * V_45 ;
V_44 * V_46 ;
V_45 = F_38 ( V_41 ) ;
if ( ! V_43 )
return 0 ;
for ( V_6 = 0 ; V_6 < F_39 ( V_45 ) ; V_6 ++ ) {
int V_47 ;
V_46 = F_40 ( V_45 , V_6 ) ;
if ( F_41 ( V_46 , V_43 ) )
continue;
F_42 ( V_41 , V_42 ) ;
V_47 = F_43 ( V_14 , V_41 , V_46 ) ;
F_42 ( V_41 , NULL ) ;
if ( V_47 > 0 )
return 1 ;
return - 1 ;
}
return 0 ;
}
int F_44 ( T_2 * V_14 , T_8 * V_42 , T_9 * V_43 )
{
F_37 ( T_7 ) * V_48 ;
T_7 * V_41 ;
int V_6 , V_5 , V_49 ;
int V_50 = 0 , V_51 = 0 ;
V_48 = F_45 ( V_14 ) ;
if ( V_48 )
V_50 = V_14 -> V_52 . V_53 -> V_54 -> V_50 ;
V_49 = F_46 ( V_42 ) ;
if ( V_49 == V_55 ) {
F_6 ( V_56 ,
V_57 ) ;
return 0 ;
}
for ( V_6 = 0 ; V_6 < F_47 ( V_48 ) ; V_6 ++ ) {
V_41 = F_48 ( V_48 , V_6 ) ;
if ( F_49 ( V_41 ) != V_49 )
continue;
V_51 = 1 ;
if ( V_49 == V_58 ) {
V_5 = F_36 ( V_14 , V_41 , V_42 , V_43 ) ;
if ( V_5 > 0 )
return 1 ;
if ( V_5 < 0 )
return 0 ;
}
else if ( ! V_43 || ! F_50 ( V_41 , V_43 ) ) {
F_51 ( V_41 , V_42 ) ;
V_5 = F_52 ( V_14 , V_41 ) ;
F_51 ( V_41 , NULL ) ;
if ( V_43 ) {
if ( ! V_50 ) {
F_53 () ;
return 1 ;
}
if ( V_5 > 0 )
return 1 ;
F_6 ( V_56 , V_59 ) ;
return 0 ;
}
else if ( V_5 > 0 && V_50 )
return 1 ;
}
}
if ( V_51 && ! V_43 && ! V_50 ) {
F_53 () ;
return 1 ;
}
F_6 ( V_56 , V_60 ) ;
return 0 ;
}
int F_54 ( T_2 * V_14 ,
unsigned char * V_32 , T_5 V_33 ,
unsigned char * V_61 , T_5 V_62 )
{
F_37 ( T_7 ) * V_48 ;
T_7 * V_41 ;
int V_6 , V_5 ;
V_48 = F_45 ( V_14 ) ;
for ( V_6 = 0 ; V_6 < F_47 ( V_48 ) ; V_6 ++ ) {
V_41 = F_48 ( V_48 , V_6 ) ;
if ( F_49 ( V_41 ) != V_63 )
continue;
if ( ! V_61 || ( F_55 ( V_41 , V_61 , V_62 ) == 0 ) ) {
F_56 ( V_41 , V_32 , V_33 ) ;
V_5 = F_52 ( V_14 , V_41 ) ;
F_56 ( V_41 , NULL , 0 ) ;
if ( V_5 > 0 )
return 1 ;
if ( V_61 ) {
F_6 ( V_64 , V_59 ) ;
return 0 ;
}
F_53 () ;
}
}
F_6 ( V_64 , V_60 ) ;
return 0 ;
}
int F_57 ( T_2 * V_14 ,
unsigned char * V_65 , T_10 V_66 )
{
F_37 ( T_7 ) * V_48 ;
T_7 * V_41 ;
int V_6 , V_5 ;
V_48 = F_45 ( V_14 ) ;
for ( V_6 = 0 ; V_6 < F_47 ( V_48 ) ; V_6 ++ ) {
V_41 = F_48 ( V_48 , V_6 ) ;
if ( F_49 ( V_41 ) != V_67 )
continue;
F_58 ( V_41 , V_65 , V_66 ) ;
V_5 = F_52 ( V_14 , V_41 ) ;
F_58 ( V_41 , NULL , 0 ) ;
if ( V_5 > 0 )
return 1 ;
}
F_6 ( V_68 , V_60 ) ;
return 0 ;
}
int F_59 ( T_2 * V_14 , T_8 * V_42 , T_9 * V_43 ,
T_1 * V_26 , T_1 * V_1 , unsigned int V_3 )
{
int V_5 ;
T_1 * V_21 ;
if ( F_19 ( F_20 ( V_14 ) ) != V_69 ) {
F_6 ( V_70 , V_71 ) ;
return 0 ;
}
if ( ! V_26 && ! F_13 ( V_14 ) )
return 0 ;
if ( V_3 & V_72 )
V_14 -> V_52 . V_53 -> V_54 -> V_50 = 1 ;
else
V_14 -> V_52 . V_53 -> V_54 -> V_50 = 0 ;
if ( ! V_42 && ! V_43 && ! V_26 && ! V_1 )
return 1 ;
if ( V_42 && ! F_44 ( V_14 , V_42 , V_43 ) )
return 0 ;
V_21 = F_21 ( V_14 , V_26 ) ;
if ( ! V_21 )
return 0 ;
V_5 = F_1 ( V_1 , V_21 , V_3 ) ;
F_15 ( V_21 , V_26 ) ;
return V_5 ;
}
int F_24 ( T_2 * V_14 , T_1 * V_73 , T_1 * V_26 , unsigned int V_3 )
{
T_1 * V_74 ;
int V_75 = 0 ;
if ( ! ( V_74 = F_21 ( V_14 , V_26 ) ) ) {
F_6 ( V_76 , V_10 ) ;
return 0 ;
}
F_60 ( V_73 , V_74 , V_3 ) ;
( void ) F_61 ( V_74 ) ;
if ( ! F_62 ( V_14 , V_74 ) ) {
F_6 ( V_76 , V_77 ) ;
goto V_11;
}
V_75 = 1 ;
V_11:
F_15 ( V_74 , V_26 ) ;
return V_75 ;
}
int F_63 ( T_2 * V_14 , T_1 * V_26 , T_1 * V_1 ,
unsigned int V_3 )
{
T_1 * V_21 ;
int V_5 ;
if ( F_19 ( F_20 ( V_14 ) ) != V_78 ) {
F_6 ( V_79 , V_80 ) ;
return 0 ;
}
if ( ! V_26 && ! F_13 ( V_14 ) )
return 0 ;
V_21 = F_21 ( V_14 , V_26 ) ;
if ( ! V_21 )
return 0 ;
V_5 = F_1 ( V_1 , V_21 , V_3 ) ;
F_15 ( V_21 , V_26 ) ;
return V_5 ;
}
T_2 * F_64 ( T_1 * V_2 , int V_81 , unsigned int V_3 )
{
T_2 * V_14 ;
if ( V_81 <= 0 )
V_81 = V_82 ;
V_14 = F_65 ( V_81 ) ;
if ( ! V_14 )
return NULL ;
if ( ! ( V_3 & V_31 ) )
F_31 ( V_14 , 0 ) ;
if ( ( V_3 & V_25 ) || F_24 ( V_14 , V_2 , NULL , V_3 ) )
return V_14 ;
F_25 ( V_14 ) ;
return NULL ;
}
int F_63 ( T_2 * V_14 , T_1 * V_26 , T_1 * V_1 ,
unsigned int V_3 )
{
F_6 ( V_79 , V_83 ) ;
return 0 ;
}
T_2 * F_64 ( T_1 * V_2 , int V_81 , unsigned int V_3 )
{
F_6 ( V_84 , V_83 ) ;
return NULL ;
}
