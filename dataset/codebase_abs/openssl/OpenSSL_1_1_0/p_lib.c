int F_1 ( const T_1 * V_1 )
{
if ( V_1 && V_1 -> V_2 && V_1 -> V_2 -> V_3 )
return V_1 -> V_2 -> V_3 ( V_1 ) ;
return 0 ;
}
int F_2 ( const T_1 * V_1 )
{
if ( V_1 == NULL )
return 0 ;
if ( ! V_1 -> V_2 || ! V_1 -> V_2 -> V_4 )
return - 2 ;
return V_1 -> V_2 -> V_4 ( V_1 ) ;
}
int F_3 ( T_1 * V_1 )
{
if ( V_1 && V_1 -> V_2 && V_1 -> V_2 -> V_5 )
return V_1 -> V_2 -> V_5 ( V_1 ) ;
return 0 ;
}
int F_4 ( T_1 * V_1 , int V_6 )
{
#ifndef F_5
if ( V_1 -> type == V_7 ) {
int V_8 = V_1 -> V_9 ;
if ( V_6 >= 0 )
V_1 -> V_9 = V_6 ;
return ( V_8 ) ;
}
#endif
#ifndef F_6
if ( V_1 -> type == V_10 ) {
int V_8 = V_1 -> V_9 ;
if ( V_6 >= 0 )
V_1 -> V_9 = V_6 ;
return ( V_8 ) ;
}
#endif
return ( 0 ) ;
}
int F_7 ( T_1 * V_11 , const T_1 * V_12 )
{
if ( V_11 -> type == V_13 ) {
if ( F_8 ( V_11 , V_12 -> type ) == 0 )
return 0 ;
} else if ( V_11 -> type != V_12 -> type ) {
F_9 ( V_14 , V_15 ) ;
goto V_16;
}
if ( F_10 ( V_12 ) ) {
F_9 ( V_14 , V_17 ) ;
goto V_16;
}
if ( ! F_10 ( V_11 ) ) {
if ( F_11 ( V_11 , V_12 ) == 1 )
return 1 ;
F_9 ( V_14 , V_18 ) ;
return 0 ;
}
if ( V_12 -> V_2 && V_12 -> V_2 -> V_19 )
return V_12 -> V_2 -> V_19 ( V_11 , V_12 ) ;
V_16:
return 0 ;
}
int F_10 ( const T_1 * V_1 )
{
if ( V_1 -> V_2 && V_1 -> V_2 -> V_20 )
return V_1 -> V_2 -> V_20 ( V_1 ) ;
return 0 ;
}
int F_11 ( const T_1 * V_21 , const T_1 * V_22 )
{
if ( V_21 -> type != V_22 -> type )
return - 1 ;
if ( V_21 -> V_2 && V_21 -> V_2 -> V_23 )
return V_21 -> V_2 -> V_23 ( V_21 , V_22 ) ;
return - 2 ;
}
int F_12 ( const T_1 * V_21 , const T_1 * V_22 )
{
if ( V_21 -> type != V_22 -> type )
return - 1 ;
if ( V_21 -> V_2 ) {
int V_8 ;
if ( V_21 -> V_2 -> V_23 ) {
V_8 = V_21 -> V_2 -> V_23 ( V_21 , V_22 ) ;
if ( V_8 <= 0 )
return V_8 ;
}
if ( V_21 -> V_2 -> V_24 )
return V_21 -> V_2 -> V_24 ( V_21 , V_22 ) ;
}
return - 2 ;
}
T_1 * F_13 ( void )
{
T_1 * V_8 = F_14 ( sizeof( * V_8 ) ) ;
if ( V_8 == NULL ) {
F_9 ( V_25 , V_26 ) ;
return NULL ;
}
V_8 -> type = V_13 ;
V_8 -> V_27 = V_13 ;
V_8 -> V_28 = 1 ;
V_8 -> V_9 = 1 ;
V_8 -> V_29 = F_15 () ;
if ( V_8 -> V_29 == NULL ) {
F_9 ( V_25 , V_26 ) ;
F_16 ( V_8 ) ;
return NULL ;
}
return V_8 ;
}
int F_17 ( T_1 * V_1 )
{
int V_30 ;
if ( F_18 ( & V_1 -> V_28 , 1 , & V_30 , V_1 -> V_29 ) <= 0 )
return 0 ;
F_19 ( L_1 , V_1 ) ;
F_20 ( V_30 < 2 ) ;
return ( ( V_30 > 1 ) ? 1 : 0 ) ;
}
static int F_21 ( T_1 * V_1 , int type , const char * V_31 , int V_32 )
{
const T_2 * V_2 ;
T_3 * V_33 = NULL ;
if ( V_1 ) {
if ( V_1 -> V_1 . V_34 )
F_22 ( V_1 ) ;
if ( ( type == V_1 -> V_27 ) && V_1 -> V_2 )
return 1 ;
#ifndef F_23
F_24 ( V_1 -> V_35 ) ;
V_1 -> V_35 = NULL ;
#endif
}
if ( V_31 )
V_2 = F_25 ( & V_33 , V_31 , V_32 ) ;
else
V_2 = F_26 ( & V_33 , type ) ;
#ifndef F_23
if ( V_1 == NULL )
F_24 ( V_33 ) ;
#endif
if ( V_2 == NULL ) {
F_9 ( V_36 , V_37 ) ;
return 0 ;
}
if ( V_1 ) {
V_1 -> V_2 = V_2 ;
V_1 -> V_35 = V_33 ;
V_1 -> type = V_1 -> V_2 -> V_38 ;
V_1 -> V_27 = type ;
}
return 1 ;
}
int F_8 ( T_1 * V_1 , int type )
{
return F_21 ( V_1 , type , NULL , - 1 ) ;
}
int F_27 ( T_1 * V_1 , const char * V_31 , int V_32 )
{
return F_21 ( V_1 , V_13 , V_31 , V_32 ) ;
}
int F_28 ( T_1 * V_1 , int type , void * V_39 )
{
if ( V_1 == NULL || ! F_8 ( V_1 , type ) )
return 0 ;
V_1 -> V_1 . V_34 = V_39 ;
return ( V_39 != NULL ) ;
}
void * F_29 ( const T_1 * V_1 )
{
return V_1 -> V_1 . V_34 ;
}
const unsigned char * F_30 ( const T_1 * V_1 , T_4 * V_32 )
{
T_5 * V_40 = NULL ;
if ( V_1 -> type != V_41 ) {
F_9 ( V_42 , V_43 ) ;
return NULL ;
}
V_40 = F_29 ( V_1 ) ;
* V_32 = V_40 -> V_44 ;
return V_40 -> V_45 ;
}
int F_31 ( T_1 * V_1 , T_6 * V_39 )
{
int V_8 = F_32 ( V_1 , V_39 ) ;
if ( V_8 )
F_33 ( V_39 ) ;
return V_8 ;
}
T_6 * F_34 ( T_1 * V_1 )
{
if ( V_1 -> type != V_46 ) {
F_9 ( V_47 , V_48 ) ;
return NULL ;
}
return V_1 -> V_1 . V_49 ;
}
T_6 * F_35 ( T_1 * V_1 )
{
T_6 * V_8 = F_34 ( V_1 ) ;
if ( V_8 != NULL )
F_33 ( V_8 ) ;
return V_8 ;
}
int F_36 ( T_1 * V_1 , T_7 * V_39 )
{
int V_8 = F_37 ( V_1 , V_39 ) ;
if ( V_8 )
F_38 ( V_39 ) ;
return V_8 ;
}
T_7 * F_39 ( T_1 * V_1 )
{
if ( V_1 -> type != V_7 ) {
F_9 ( V_50 , V_51 ) ;
return NULL ;
}
return V_1 -> V_1 . V_52 ;
}
T_7 * F_40 ( T_1 * V_1 )
{
T_7 * V_8 = F_39 ( V_1 ) ;
if ( V_8 != NULL )
F_38 ( V_8 ) ;
return V_8 ;
}
int F_41 ( T_1 * V_1 , T_8 * V_39 )
{
int V_8 = F_42 ( V_1 , V_39 ) ;
if ( V_8 )
F_43 ( V_39 ) ;
return V_8 ;
}
T_8 * F_44 ( T_1 * V_1 )
{
if ( V_1 -> type != V_10 ) {
F_9 ( V_53 , V_54 ) ;
return NULL ;
}
return V_1 -> V_1 . V_55 ;
}
T_8 * F_45 ( T_1 * V_1 )
{
T_8 * V_8 = F_44 ( V_1 ) ;
if ( V_8 != NULL )
F_43 ( V_8 ) ;
return V_8 ;
}
int F_46 ( T_1 * V_1 , T_9 * V_39 )
{
int V_8 = F_47 ( V_1 , V_39 ) ;
if ( V_8 )
F_48 ( V_39 ) ;
return V_8 ;
}
T_9 * F_49 ( T_1 * V_1 )
{
if ( V_1 -> type != V_56 && V_1 -> type != V_57 ) {
F_9 ( V_58 , V_59 ) ;
return NULL ;
}
return V_1 -> V_1 . V_60 ;
}
T_9 * F_50 ( T_1 * V_1 )
{
T_9 * V_8 = F_49 ( V_1 ) ;
if ( V_8 != NULL )
F_48 ( V_8 ) ;
return V_8 ;
}
int F_51 ( int type )
{
int V_8 ;
const T_2 * V_2 ;
T_3 * V_33 ;
V_2 = F_26 ( & V_33 , type ) ;
if ( V_2 )
V_8 = V_2 -> V_38 ;
else
V_8 = V_61 ;
#ifndef F_23
F_24 ( V_33 ) ;
#endif
return V_8 ;
}
int F_52 ( const T_1 * V_1 )
{
return V_1 -> type ;
}
int F_53 ( const T_1 * V_1 )
{
return F_51 ( V_1 -> type ) ;
}
void F_54 ( T_1 * V_62 )
{
int V_30 ;
if ( V_62 == NULL )
return;
F_18 ( & V_62 -> V_28 , - 1 , & V_30 , V_62 -> V_29 ) ;
F_19 ( L_1 , V_62 ) ;
if ( V_30 > 0 )
return;
F_20 ( V_30 < 0 ) ;
F_22 ( V_62 ) ;
F_55 ( V_62 -> V_63 , V_64 ) ;
F_16 ( V_62 ) ;
}
static void F_22 ( T_1 * V_62 )
{
if ( V_62 -> V_2 && V_62 -> V_2 -> V_65 ) {
V_62 -> V_2 -> V_65 ( V_62 ) ;
V_62 -> V_1 . V_34 = NULL ;
}
#ifndef F_23
F_24 ( V_62 -> V_35 ) ;
V_62 -> V_35 = NULL ;
#endif
F_56 ( V_62 -> V_29 ) ;
}
static int F_57 ( T_10 * V_66 , const T_1 * V_1 , int V_67 ,
const char * V_68 )
{
F_58 ( V_66 , V_67 , 128 ) ;
F_59 ( V_66 , L_2 ,
V_68 , F_60 ( V_1 -> type ) ) ;
return 1 ;
}
int F_61 ( T_10 * V_66 , const T_1 * V_1 ,
int V_67 , T_11 * V_69 )
{
if ( V_1 -> V_2 && V_1 -> V_2 -> V_70 )
return V_1 -> V_2 -> V_70 ( V_66 , V_1 , V_67 , V_69 ) ;
return F_57 ( V_66 , V_1 , V_67 , L_3 ) ;
}
int F_62 ( T_10 * V_66 , const T_1 * V_1 ,
int V_67 , T_11 * V_69 )
{
if ( V_1 -> V_2 && V_1 -> V_2 -> V_71 )
return V_1 -> V_2 -> V_71 ( V_66 , V_1 , V_67 , V_69 ) ;
return F_57 ( V_66 , V_1 , V_67 , L_4 ) ;
}
int F_63 ( T_10 * V_66 , const T_1 * V_1 ,
int V_67 , T_11 * V_69 )
{
if ( V_1 -> V_2 && V_1 -> V_2 -> V_72 )
return V_1 -> V_2 -> V_72 ( V_66 , V_1 , V_67 , V_69 ) ;
return F_57 ( V_66 , V_1 , V_67 , L_5 ) ;
}
static int F_64 ( T_1 * V_1 , int V_73 , int V_74 , void * V_75 )
{
if ( V_1 -> V_2 == NULL || V_1 -> V_2 -> V_76 == NULL )
return - 2 ;
return V_1 -> V_2 -> V_76 ( V_1 , V_73 , V_74 , V_75 ) ;
}
int F_65 ( T_1 * V_1 , int * V_77 )
{
return F_64 ( V_1 , V_78 , 0 , V_77 ) ;
}
int F_66 ( T_1 * V_1 ,
const unsigned char * V_79 , T_4 V_80 )
{
if ( V_80 > V_81 )
return 0 ;
if ( F_64 ( V_1 , V_82 , V_80 ,
( void * ) V_79 ) <= 0 )
return 0 ;
return 1 ;
}
T_4 F_67 ( T_1 * V_1 , unsigned char * * V_83 )
{
int V_84 ;
V_84 = F_64 ( V_1 , V_85 , 0 , V_83 ) ;
if ( V_84 <= 0 )
return 0 ;
return V_84 ;
}
