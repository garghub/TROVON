T_1 * F_1 ( void )
{
return F_2 ( NULL ) ;
}
T_1 * F_3 ( int V_1 )
{
T_1 * V_2 = F_1 () ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_3 = F_4 ( V_1 ) ;
if ( V_2 -> V_3 == NULL ) {
F_5 ( V_2 ) ;
return NULL ;
}
if ( V_2 -> V_4 -> V_5 != NULL
&& V_2 -> V_4 -> V_5 ( V_2 , V_2 -> V_3 ) == 0 ) {
F_5 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void F_5 ( T_1 * V_6 )
{
int V_7 ;
if ( V_6 == NULL )
return;
F_6 ( & V_6 -> V_8 , - 1 , & V_7 , V_6 -> V_9 ) ;
F_7 ( L_1 , V_6 ) ;
if ( V_7 > 0 )
return;
F_8 ( V_7 < 0 ) ;
if ( V_6 -> V_4 -> V_10 != NULL )
V_6 -> V_4 -> V_10 ( V_6 ) ;
#ifndef F_9
F_10 ( V_6 -> V_11 ) ;
#endif
if ( V_6 -> V_3 && V_6 -> V_3 -> V_4 -> V_12 )
V_6 -> V_3 -> V_4 -> V_12 ( V_6 ) ;
F_11 ( V_13 , V_6 , & V_6 -> V_14 ) ;
F_12 ( V_6 -> V_9 ) ;
F_13 ( V_6 -> V_3 ) ;
F_14 ( V_6 -> V_15 ) ;
F_15 ( V_6 -> V_16 ) ;
F_16 ( ( void * ) V_6 , sizeof( T_1 ) ) ;
}
T_1 * F_17 ( T_1 * V_17 , const T_1 * V_18 )
{
if ( V_17 == NULL || V_18 == NULL ) {
F_18 ( V_19 , V_20 ) ;
return NULL ;
}
if ( V_18 -> V_4 != V_17 -> V_4 ) {
if ( V_17 -> V_4 -> V_10 != NULL )
V_17 -> V_4 -> V_10 ( V_17 ) ;
if ( V_17 -> V_3 && V_17 -> V_3 -> V_4 -> V_12 )
V_17 -> V_3 -> V_4 -> V_12 ( V_17 ) ;
#ifndef F_9
if ( F_10 ( V_17 -> V_11 ) == 0 )
return 0 ;
V_17 -> V_11 = NULL ;
#endif
}
if ( V_18 -> V_3 != NULL ) {
const T_2 * V_4 = F_19 ( V_18 -> V_3 ) ;
F_13 ( V_17 -> V_3 ) ;
V_17 -> V_3 = F_20 ( V_4 ) ;
if ( V_17 -> V_3 == NULL )
return NULL ;
if ( ! F_21 ( V_17 -> V_3 , V_18 -> V_3 ) )
return NULL ;
if ( V_18 -> V_15 != NULL ) {
F_14 ( V_17 -> V_15 ) ;
V_17 -> V_15 = F_22 ( V_18 -> V_3 ) ;
if ( V_17 -> V_15 == NULL )
return NULL ;
if ( ! F_23 ( V_17 -> V_15 , V_18 -> V_15 ) )
return NULL ;
}
if ( V_18 -> V_16 != NULL ) {
if ( V_17 -> V_16 == NULL ) {
V_17 -> V_16 = F_24 () ;
if ( V_17 -> V_16 == NULL )
return NULL ;
}
if ( ! F_25 ( V_17 -> V_16 , V_18 -> V_16 ) )
return NULL ;
if ( V_18 -> V_3 -> V_4 -> V_21
&& V_18 -> V_3 -> V_4 -> V_21 ( V_17 , V_18 ) == 0 )
return NULL ;
}
}
V_17 -> V_22 = V_18 -> V_22 ;
V_17 -> V_23 = V_18 -> V_23 ;
V_17 -> V_24 = V_18 -> V_24 ;
V_17 -> V_25 = V_18 -> V_25 ;
if ( ! F_26 ( V_13 ,
& V_17 -> V_14 , & V_18 -> V_14 ) )
return NULL ;
if ( V_18 -> V_4 != V_17 -> V_4 ) {
#ifndef F_9
if ( V_18 -> V_11 != NULL && F_27 ( V_18 -> V_11 ) == 0 )
return NULL ;
V_17 -> V_11 = V_18 -> V_11 ;
#endif
V_17 -> V_4 = V_18 -> V_4 ;
}
if ( V_18 -> V_4 -> V_26 != NULL && V_18 -> V_4 -> V_26 ( V_17 , V_18 ) == 0 )
return NULL ;
return V_17 ;
}
T_1 * F_28 ( const T_1 * V_27 )
{
T_1 * V_2 = F_2 ( V_27 -> V_11 ) ;
if ( V_2 == NULL )
return NULL ;
if ( F_17 ( V_2 , V_27 ) == NULL ) {
F_5 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
int F_29 ( T_1 * V_6 )
{
int V_7 ;
if ( F_6 ( & V_6 -> V_8 , 1 , & V_7 , V_6 -> V_9 ) <= 0 )
return 0 ;
F_7 ( L_1 , V_6 ) ;
F_8 ( V_7 < 2 ) ;
return ( ( V_7 > 1 ) ? 1 : 0 ) ;
}
int F_30 ( T_1 * V_28 )
{
if ( V_28 == NULL || V_28 -> V_3 == NULL ) {
F_18 ( V_29 , V_20 ) ;
return 0 ;
}
if ( V_28 -> V_4 -> V_30 != NULL )
return V_28 -> V_4 -> V_30 ( V_28 ) ;
F_18 ( V_29 , V_31 ) ;
return 0 ;
}
int F_31 ( T_1 * V_28 )
{
F_32 ( V_28 -> V_3 -> V_4 -> V_30 != NULL ) ;
return V_28 -> V_3 -> V_4 -> V_30 ( V_28 ) ;
}
int F_33 ( T_1 * V_28 )
{
int V_32 = 0 ;
T_3 * V_33 = NULL ;
T_4 * V_16 = NULL ;
const T_4 * V_34 = NULL ;
T_5 * V_15 = NULL ;
if ( ( V_33 = F_34 () ) == NULL )
goto V_35;
if ( V_28 -> V_16 == NULL ) {
V_16 = F_24 () ;
if ( V_16 == NULL )
goto V_35;
} else
V_16 = V_28 -> V_16 ;
V_34 = F_35 ( V_28 -> V_3 ) ;
if ( V_34 == NULL )
goto V_35;
do
if ( ! F_36 ( V_16 , V_34 ) )
goto V_35;
while ( F_37 ( V_16 ) ) ;
if ( V_28 -> V_15 == NULL ) {
V_15 = F_22 ( V_28 -> V_3 ) ;
if ( V_15 == NULL )
goto V_35;
} else
V_15 = V_28 -> V_15 ;
if ( ! F_38 ( V_28 -> V_3 , V_15 , V_16 , NULL , NULL , V_33 ) )
goto V_35;
V_28 -> V_16 = V_16 ;
V_28 -> V_15 = V_15 ;
V_32 = 1 ;
V_35:
if ( V_28 -> V_15 == NULL )
F_14 ( V_15 ) ;
if ( V_28 -> V_16 != V_16 )
F_39 ( V_16 ) ;
F_40 ( V_33 ) ;
return V_32 ;
}
int F_41 ( T_1 * V_28 )
{
return F_38 ( V_28 -> V_3 , V_28 -> V_15 , V_28 -> V_16 , NULL ,
NULL , NULL ) ;
}
int F_42 ( const T_1 * V_28 )
{
if ( V_28 == NULL || V_28 -> V_3 == NULL || V_28 -> V_15 == NULL ) {
F_18 ( V_36 , V_20 ) ;
return 0 ;
}
if ( V_28 -> V_3 -> V_4 -> V_37 == NULL ) {
F_18 ( V_36 , V_38 ) ;
return 0 ;
}
return V_28 -> V_3 -> V_4 -> V_37 ( V_28 ) ;
}
int F_43 ( const T_1 * V_28 )
{
int V_32 = 0 ;
T_3 * V_33 = NULL ;
const T_4 * V_34 = NULL ;
T_5 * V_39 = NULL ;
if ( V_28 == NULL || V_28 -> V_3 == NULL || V_28 -> V_15 == NULL ) {
F_18 ( V_40 , V_20 ) ;
return 0 ;
}
if ( F_44 ( V_28 -> V_3 , V_28 -> V_15 ) ) {
F_18 ( V_40 , V_41 ) ;
goto V_35;
}
if ( ( V_33 = F_34 () ) == NULL )
goto V_35;
if ( ( V_39 = F_22 ( V_28 -> V_3 ) ) == NULL )
goto V_35;
if ( F_45 ( V_28 -> V_3 , V_28 -> V_15 , V_33 ) <= 0 ) {
F_18 ( V_40 , V_42 ) ;
goto V_35;
}
V_34 = V_28 -> V_3 -> V_34 ;
if ( F_37 ( V_34 ) ) {
F_18 ( V_40 , V_43 ) ;
goto V_35;
}
if ( ! F_38 ( V_28 -> V_3 , V_39 , NULL , V_28 -> V_15 , V_34 , V_33 ) ) {
F_18 ( V_40 , V_44 ) ;
goto V_35;
}
if ( ! F_44 ( V_28 -> V_3 , V_39 ) ) {
F_18 ( V_40 , V_45 ) ;
goto V_35;
}
if ( V_28 -> V_16 != NULL ) {
if ( F_46 ( V_28 -> V_16 , V_34 ) >= 0 ) {
F_18 ( V_40 , V_45 ) ;
goto V_35;
}
if ( ! F_38 ( V_28 -> V_3 , V_39 , V_28 -> V_16 ,
NULL , NULL , V_33 ) ) {
F_18 ( V_40 , V_44 ) ;
goto V_35;
}
if ( F_47 ( V_28 -> V_3 , V_39 , V_28 -> V_15 , V_33 ) != 0 ) {
F_18 ( V_40 , V_46 ) ;
goto V_35;
}
}
V_32 = 1 ;
V_35:
F_40 ( V_33 ) ;
F_14 ( V_39 ) ;
return V_32 ;
}
int F_48 ( T_1 * V_47 , T_4 * V_48 ,
T_4 * V_49 )
{
T_3 * V_33 = NULL ;
T_4 * V_50 , * V_51 ;
T_5 * V_39 = NULL ;
int V_32 = 0 ;
#ifndef F_49
int V_52 , V_53 = 0 ;
#endif
if ( V_47 == NULL || V_47 -> V_3 == NULL || V_48 == NULL || V_49 == NULL ) {
F_18 ( V_54 ,
V_20 ) ;
return 0 ;
}
V_33 = F_34 () ;
if ( V_33 == NULL )
return 0 ;
F_50 ( V_33 ) ;
V_39 = F_22 ( V_47 -> V_3 ) ;
if ( V_39 == NULL )
goto V_35;
V_50 = F_51 ( V_33 ) ;
V_51 = F_51 ( V_33 ) ;
if ( V_51 == NULL )
goto V_35;
#ifndef F_49
V_52 = F_52 ( F_19 ( V_47 -> V_3 ) ) ;
if ( V_52 == V_55 )
V_53 = 1 ;
if ( V_53 ) {
if ( ! F_53 ( V_47 -> V_3 , V_39 ,
V_48 , V_49 , V_33 ) )
goto V_35;
if ( ! F_54 ( V_47 -> V_3 , V_39 ,
V_50 , V_51 , V_33 ) )
goto V_35;
} else
#endif
{
if ( ! F_55 ( V_47 -> V_3 , V_39 ,
V_48 , V_49 , V_33 ) )
goto V_35;
if ( ! F_56 ( V_47 -> V_3 , V_39 ,
V_50 , V_51 , V_33 ) )
goto V_35;
}
if ( F_46 ( V_48 , V_50 ) || F_46 ( V_49 , V_51 )
|| ( F_46 ( V_48 , V_47 -> V_3 -> V_56 ) >= 0 )
|| ( F_46 ( V_49 , V_47 -> V_3 -> V_56 ) >= 0 ) ) {
F_18 ( V_54 ,
V_57 ) ;
goto V_35;
}
if ( ! F_57 ( V_47 , V_39 ) )
goto V_35;
if ( F_42 ( V_47 ) == 0 )
goto V_35;
V_32 = 1 ;
V_35:
F_58 ( V_33 ) ;
F_40 ( V_33 ) ;
F_14 ( V_39 ) ;
return V_32 ;
}
const T_6 * F_59 ( const T_1 * V_47 )
{
return V_47 -> V_3 ;
}
int F_60 ( T_1 * V_47 , const T_6 * V_3 )
{
if ( V_47 -> V_4 -> V_5 != NULL && V_47 -> V_4 -> V_5 ( V_47 , V_3 ) == 0 )
return 0 ;
F_13 ( V_47 -> V_3 ) ;
V_47 -> V_3 = F_61 ( V_3 ) ;
return ( V_47 -> V_3 == NULL ) ? 0 : 1 ;
}
const T_4 * F_62 ( const T_1 * V_47 )
{
return V_47 -> V_16 ;
}
int F_63 ( T_1 * V_47 , const T_4 * V_16 )
{
if ( V_47 -> V_3 == NULL || V_47 -> V_3 -> V_4 == NULL )
return 0 ;
if ( V_47 -> V_3 -> V_4 -> V_58 != NULL
&& V_47 -> V_3 -> V_4 -> V_58 ( V_47 , V_16 ) == 0 )
return 0 ;
if ( V_47 -> V_4 -> V_58 != NULL
&& V_47 -> V_4 -> V_58 ( V_47 , V_16 ) == 0 )
return 0 ;
F_15 ( V_47 -> V_16 ) ;
V_47 -> V_16 = F_64 ( V_16 ) ;
return ( V_47 -> V_16 == NULL ) ? 0 : 1 ;
}
const T_5 * F_65 ( const T_1 * V_47 )
{
return V_47 -> V_15 ;
}
int F_57 ( T_1 * V_47 , const T_5 * V_15 )
{
if ( V_47 -> V_4 -> V_59 != NULL
&& V_47 -> V_4 -> V_59 ( V_47 , V_15 ) == 0 )
return 0 ;
F_14 ( V_47 -> V_15 ) ;
V_47 -> V_15 = F_66 ( V_15 , V_47 -> V_3 ) ;
return ( V_47 -> V_15 == NULL ) ? 0 : 1 ;
}
unsigned int F_67 ( const T_1 * V_47 )
{
return V_47 -> V_22 ;
}
void F_68 ( T_1 * V_47 , unsigned int V_25 )
{
V_47 -> V_22 = V_25 ;
}
T_7 F_69 ( const T_1 * V_47 )
{
return V_47 -> V_23 ;
}
void F_70 ( T_1 * V_47 , T_7 V_60 )
{
V_47 -> V_23 = V_60 ;
if ( V_47 -> V_3 != NULL )
F_71 ( V_47 -> V_3 , V_60 ) ;
}
void F_72 ( T_1 * V_47 , int V_61 )
{
if ( V_47 -> V_3 != NULL )
F_73 ( V_47 -> V_3 , V_61 ) ;
}
int F_74 ( T_1 * V_47 , T_3 * V_33 )
{
if ( V_47 -> V_3 == NULL )
return 0 ;
return F_75 ( V_47 -> V_3 , V_33 ) ;
}
int F_76 ( const T_1 * V_47 )
{
return V_47 -> V_25 ;
}
void F_77 ( T_1 * V_47 , int V_25 )
{
V_47 -> V_25 |= V_25 ;
}
void F_78 ( T_1 * V_47 , int V_25 )
{
V_47 -> V_25 &= ~ V_25 ;
}
T_8 F_79 ( const T_1 * V_47 , T_7 V_62 ,
unsigned char * * V_63 , T_3 * V_33 )
{
if ( V_47 == NULL || V_47 -> V_15 == NULL || V_47 -> V_3 == NULL )
return 0 ;
return F_80 ( V_47 -> V_3 , V_47 -> V_15 , V_62 , V_63 , V_33 ) ;
}
int F_81 ( T_1 * V_47 , const unsigned char * V_64 , T_8 V_65 ,
T_3 * V_33 )
{
if ( V_47 == NULL || V_47 -> V_3 == NULL )
return 0 ;
if ( V_47 -> V_15 == NULL )
V_47 -> V_15 = F_22 ( V_47 -> V_3 ) ;
if ( V_47 -> V_15 == NULL )
return 0 ;
if ( F_82 ( V_47 -> V_3 , V_47 -> V_15 , V_64 , V_65 , V_33 ) == 0 )
return 0 ;
if ( ( V_47 -> V_3 -> V_4 -> V_25 & V_66 ) == 0 )
V_47 -> V_23 = ( T_7 ) ( V_64 [ 0 ] & ~ 0x01 ) ;
return 1 ;
}
T_8 F_83 ( const T_1 * V_28 ,
unsigned char * V_64 , T_8 V_65 )
{
if ( V_28 -> V_3 == NULL || V_28 -> V_3 -> V_4 == NULL )
return 0 ;
if ( V_28 -> V_3 -> V_4 -> V_67 == NULL ) {
F_18 ( V_68 , V_38 ) ;
return 0 ;
}
return V_28 -> V_3 -> V_4 -> V_67 ( V_28 , V_64 , V_65 ) ;
}
T_8 F_84 ( const T_1 * V_28 ,
unsigned char * V_64 , T_8 V_65 )
{
T_8 V_69 ;
V_69 = ( F_85 ( V_28 -> V_3 ) + 7 ) / 8 ;
if ( V_28 -> V_16 == NULL )
return 0 ;
if ( V_64 == NULL )
return V_69 ;
else if ( V_65 < V_69 )
return 0 ;
if ( F_86 ( V_28 -> V_16 , V_64 , V_69 ) == - 1 ) {
F_18 ( V_70 , V_71 ) ;
return 0 ;
}
return V_69 ;
}
int F_87 ( T_1 * V_28 , const unsigned char * V_64 , T_8 V_65 )
{
if ( V_28 -> V_3 == NULL || V_28 -> V_3 -> V_4 == NULL )
return 0 ;
if ( V_28 -> V_3 -> V_4 -> V_72 == NULL ) {
F_18 ( V_73 , V_38 ) ;
return 0 ;
}
return V_28 -> V_3 -> V_4 -> V_72 ( V_28 , V_64 , V_65 ) ;
}
int F_88 ( T_1 * V_28 , const unsigned char * V_64 , T_8 V_65 )
{
if ( V_28 -> V_16 == NULL )
V_28 -> V_16 = F_89 () ;
if ( V_28 -> V_16 == NULL ) {
F_18 ( V_74 , V_75 ) ;
return 0 ;
}
V_28 -> V_16 = F_90 ( V_64 , V_65 , V_28 -> V_16 ) ;
if ( V_28 -> V_16 == NULL ) {
F_18 ( V_74 , V_76 ) ;
return 0 ;
}
return 1 ;
}
T_8 F_91 ( const T_1 * V_28 , unsigned char * * V_63 )
{
T_8 V_65 ;
unsigned char * V_64 ;
V_65 = F_83 ( V_28 , NULL , 0 ) ;
if ( V_65 == 0 )
return 0 ;
V_64 = F_92 ( V_65 ) ;
if ( V_64 == NULL )
return 0 ;
V_65 = F_83 ( V_28 , V_64 , V_65 ) ;
if ( V_65 == 0 ) {
F_93 ( V_64 ) ;
return 0 ;
}
* V_63 = V_64 ;
return V_65 ;
}
int F_94 ( const T_1 * V_28 )
{
if ( V_28 -> V_3 == NULL || V_28 -> V_3 -> V_4 == NULL
|| ( V_28 -> V_3 -> V_4 -> V_25 & V_77 ) )
return 0 ;
return 1 ;
}
