static int F_1 ( const T_1 * const * V_1 ,
const T_1 * const * V_2 )
{
return ( ( * V_1 ) -> V_3 - ( * V_2 ) -> V_3 ) ;
}
const T_1 * F_2 ( int type )
{
T_1 V_4 ;
const T_1 * V_5 = & V_4 , * * V_6 ;
V_4 . V_3 = type ;
if ( V_7 ) {
int V_8 ;
V_8 = F_3 ( V_7 , & V_4 ) ;
if ( V_8 >= 0 )
return F_4 ( V_7 , V_8 ) ;
}
V_6 = F_5 ( & V_5 , V_9 ,
sizeof( V_9 ) /
sizeof( T_1 * ) ) ;
if ( ! V_6 || ! * V_6 )
return NULL ;
return * V_6 ;
}
static T_2 * F_6 ( T_3 * V_10 , T_4 * V_11 , int V_12 )
{
T_2 * V_6 ;
const T_1 * V_13 ;
if ( V_12 == - 1 ) {
if ( ! V_10 || ! V_10 -> V_14 )
return NULL ;
V_12 = V_10 -> V_14 -> V_3 ;
}
#ifndef F_7
if ( V_10 && V_10 -> V_15 )
V_11 = V_10 -> V_15 ;
if ( V_11 ) {
if ( ! F_8 ( V_11 ) ) {
F_9 ( V_16 , V_17 ) ;
return NULL ;
}
} else
V_11 = F_10 ( V_12 ) ;
if ( V_11 )
V_13 = F_11 ( V_11 , V_12 ) ;
else
#endif
V_13 = F_2 ( V_12 ) ;
if ( V_13 == NULL ) {
F_9 ( V_16 , V_18 ) ;
return NULL ;
}
V_6 = F_12 ( sizeof( T_2 ) ) ;
if ( ! V_6 ) {
#ifndef F_7
if ( V_11 )
F_13 ( V_11 ) ;
#endif
F_9 ( V_16 , V_19 ) ;
return NULL ;
}
V_6 -> V_15 = V_11 ;
V_6 -> V_13 = V_13 ;
V_6 -> V_20 = V_21 ;
V_6 -> V_10 = V_10 ;
V_6 -> V_22 = NULL ;
V_6 -> V_23 = 0 ;
if ( V_10 )
F_14 ( & V_10 -> V_24 , 1 , V_25 ) ;
V_6 -> V_26 = NULL ;
if ( V_13 -> V_27 ) {
if ( V_13 -> V_27 ( V_6 ) <= 0 ) {
F_15 ( V_6 ) ;
return NULL ;
}
}
return V_6 ;
}
T_1 * F_16 ( int V_12 , int V_28 )
{
T_1 * V_13 ;
V_13 = F_12 ( sizeof( T_1 ) ) ;
if ( ! V_13 )
return NULL ;
memset ( V_13 , 0 , sizeof( T_1 ) ) ;
V_13 -> V_3 = V_12 ;
V_13 -> V_28 = V_28 | V_29 ;
V_13 -> V_27 = 0 ;
V_13 -> V_30 = 0 ;
V_13 -> V_31 = 0 ;
V_13 -> V_32 = 0 ;
V_13 -> V_33 = 0 ;
V_13 -> V_34 = 0 ;
V_13 -> V_35 = 0 ;
V_13 -> V_36 = 0 ;
V_13 -> V_37 = 0 ;
V_13 -> V_38 = 0 ;
V_13 -> V_39 = 0 ;
V_13 -> V_40 = 0 ;
V_13 -> V_41 = 0 ;
V_13 -> V_42 = 0 ;
V_13 -> V_43 = 0 ;
V_13 -> V_44 = 0 ;
V_13 -> V_45 = 0 ;
V_13 -> V_46 = 0 ;
V_13 -> V_47 = 0 ;
V_13 -> V_48 = 0 ;
V_13 -> V_49 = 0 ;
V_13 -> V_50 = 0 ;
V_13 -> V_51 = 0 ;
V_13 -> V_52 = 0 ;
V_13 -> V_53 = 0 ;
return V_13 ;
}
void F_17 ( int * V_54 , int * V_55 ,
const T_1 * V_56 )
{
if ( V_54 )
* V_54 = V_56 -> V_3 ;
if ( V_55 )
* V_55 = V_56 -> V_28 ;
}
void F_18 ( T_1 * V_57 , const T_1 * V_58 )
{
V_57 -> V_27 = V_58 -> V_27 ;
V_57 -> V_30 = V_58 -> V_30 ;
V_57 -> V_31 = V_58 -> V_31 ;
V_57 -> V_32 = V_58 -> V_32 ;
V_57 -> V_33 = V_58 -> V_33 ;
V_57 -> V_34 = V_58 -> V_34 ;
V_57 -> V_35 = V_58 -> V_35 ;
V_57 -> V_36 = V_58 -> V_36 ;
V_57 -> V_37 = V_58 -> V_37 ;
V_57 -> V_38 = V_58 -> V_38 ;
V_57 -> V_39 = V_58 -> V_39 ;
V_57 -> V_40 = V_58 -> V_40 ;
V_57 -> V_41 = V_58 -> V_41 ;
V_57 -> V_42 = V_58 -> V_42 ;
V_57 -> V_43 = V_58 -> V_43 ;
V_57 -> V_44 = V_58 -> V_44 ;
V_57 -> V_45 = V_58 -> V_45 ;
V_57 -> V_46 = V_58 -> V_46 ;
V_57 -> V_47 = V_58 -> V_47 ;
V_57 -> V_48 = V_58 -> V_48 ;
V_57 -> V_49 = V_58 -> V_49 ;
V_57 -> V_50 = V_58 -> V_50 ;
V_57 -> V_51 = V_58 -> V_51 ;
V_57 -> V_52 = V_58 -> V_52 ;
V_57 -> V_53 = V_58 -> V_53 ;
}
void F_19 ( T_1 * V_13 )
{
if ( V_13 && ( V_13 -> V_28 & V_29 ) )
F_20 ( V_13 ) ;
}
T_2 * F_21 ( T_3 * V_10 , T_4 * V_11 )
{
return F_6 ( V_10 , V_11 , - 1 ) ;
}
T_2 * F_22 ( int V_12 , T_4 * V_11 )
{
return F_6 ( NULL , V_11 , V_12 ) ;
}
T_2 * F_23 ( T_2 * V_59 )
{
T_2 * V_60 ;
if ( ! V_59 -> V_13 || ! V_59 -> V_13 -> V_30 )
return NULL ;
#ifndef F_7
if ( V_59 -> V_15 && ! F_8 ( V_59 -> V_15 ) ) {
F_9 ( V_61 , V_17 ) ;
return 0 ;
}
#endif
V_60 = F_12 ( sizeof( T_2 ) ) ;
if ( ! V_60 )
return NULL ;
V_60 -> V_13 = V_59 -> V_13 ;
#ifndef F_7
V_60 -> V_15 = V_59 -> V_15 ;
#endif
if ( V_59 -> V_10 )
F_14 ( & V_59 -> V_10 -> V_24 , 1 , V_25 ) ;
V_60 -> V_10 = V_59 -> V_10 ;
if ( V_59 -> V_22 )
F_14 ( & V_59 -> V_22 -> V_24 , 1 , V_25 ) ;
V_60 -> V_22 = V_59 -> V_22 ;
V_60 -> V_26 = NULL ;
V_60 -> V_62 = NULL ;
V_60 -> V_20 = V_59 -> V_20 ;
if ( V_59 -> V_13 -> V_30 ( V_60 , V_59 ) > 0 )
return V_60 ;
F_15 ( V_60 ) ;
return NULL ;
}
int F_24 ( const T_1 * V_13 )
{
if ( V_7 == NULL ) {
V_7 = F_25 ( F_1 ) ;
if ( ! V_7 )
return 0 ;
}
if ( ! F_26 ( V_7 , V_13 ) )
return 0 ;
F_27 ( V_7 ) ;
return 1 ;
}
void F_15 ( T_2 * V_63 )
{
if ( V_63 == NULL )
return;
if ( V_63 -> V_13 && V_63 -> V_13 -> V_31 )
V_63 -> V_13 -> V_31 ( V_63 ) ;
if ( V_63 -> V_10 )
F_28 ( V_63 -> V_10 ) ;
if ( V_63 -> V_22 )
F_28 ( V_63 -> V_22 ) ;
#ifndef F_7
if ( V_63 -> V_15 )
F_13 ( V_63 -> V_15 ) ;
#endif
F_20 ( V_63 ) ;
}
int F_29 ( T_2 * V_63 , int V_64 , int V_65 ,
int V_66 , int V_67 , void * V_68 )
{
int V_6 ;
if ( ! V_63 || ! V_63 -> V_13 || ! V_63 -> V_13 -> V_52 ) {
F_9 ( V_69 , V_70 ) ;
return - 2 ;
}
if ( ( V_64 != - 1 ) && ( V_63 -> V_13 -> V_3 != V_64 ) )
return - 1 ;
if ( V_63 -> V_20 == V_21 ) {
F_9 ( V_69 , V_71 ) ;
return - 1 ;
}
if ( ( V_65 != - 1 ) && ! ( V_63 -> V_20 & V_65 ) ) {
F_9 ( V_69 , V_72 ) ;
return - 1 ;
}
V_6 = V_63 -> V_13 -> V_52 ( V_63 , V_66 , V_67 , V_68 ) ;
if ( V_6 == - 2 )
F_9 ( V_69 , V_70 ) ;
return V_6 ;
}
int F_30 ( T_2 * V_63 ,
const char * V_73 , const char * V_74 )
{
if ( ! V_63 || ! V_63 -> V_13 || ! V_63 -> V_13 -> V_53 ) {
F_9 ( V_75 , V_70 ) ;
return - 2 ;
}
if ( ! strcmp ( V_73 , L_1 ) ) {
const T_5 * V_76 ;
if ( ! V_74 || ! ( V_76 = F_31 ( V_74 ) ) ) {
F_9 ( V_75 , V_77 ) ;
return 0 ;
}
return F_32 ( V_63 , V_76 ) ;
}
return V_63 -> V_13 -> V_53 ( V_63 , V_73 , V_74 ) ;
}
int F_33 ( T_2 * V_63 )
{
return V_63 -> V_20 ;
}
void F_34 ( T_2 * V_63 , int * V_78 , int V_79 )
{
V_63 -> V_80 = V_78 ;
V_63 -> V_81 = V_79 ;
}
void F_35 ( T_2 * V_63 , void * V_26 )
{
V_63 -> V_26 = V_26 ;
}
void * F_36 ( T_2 * V_63 )
{
return V_63 -> V_26 ;
}
T_3 * F_37 ( T_2 * V_63 )
{
return V_63 -> V_10 ;
}
T_3 * F_38 ( T_2 * V_63 )
{
return V_63 -> V_22 ;
}
void F_39 ( T_2 * V_63 , void * V_26 )
{
V_63 -> V_62 = V_26 ;
}
void * F_40 ( T_2 * V_63 )
{
return V_63 -> V_62 ;
}
void F_41 ( T_1 * V_13 ,
int (* V_27) ( T_2 * V_63 ) )
{
V_13 -> V_27 = V_27 ;
}
void F_42 ( T_1 * V_13 ,
int (* V_30) ( T_2 * V_57 ,
T_2 * V_58 ) )
{
V_13 -> V_30 = V_30 ;
}
void F_43 ( T_1 * V_13 ,
void (* V_31) ( T_2 * V_63 ) )
{
V_13 -> V_31 = V_31 ;
}
void F_44 ( T_1 * V_13 ,
int (* V_32) ( T_2 * V_63 ) ,
int (* V_33) ( T_2 * V_63 ,
T_3 * V_10 ) )
{
V_13 -> V_32 = V_32 ;
V_13 -> V_33 = V_33 ;
}
void F_45 ( T_1 * V_13 ,
int (* V_34) ( T_2 * V_63 ) ,
int (* V_35) ( T_2 * V_63 ,
T_3 * V_10 ) )
{
V_13 -> V_34 = V_34 ;
V_13 -> V_35 = V_35 ;
}
void F_46 ( T_1 * V_13 ,
int (* V_36) ( T_2 * V_63 ) ,
int (* V_37) ( T_2 * V_63 ,
unsigned char * V_82 , T_6 * V_83 ,
const unsigned char * V_84 ,
T_6 V_85 ) )
{
V_13 -> V_36 = V_36 ;
V_13 -> V_37 = V_37 ;
}
void F_47 ( T_1 * V_13 ,
int (* V_38) ( T_2 * V_63 ) ,
int (* V_39) ( T_2 * V_63 ,
const unsigned char * V_82 ,
T_6 V_83 ,
const unsigned char * V_84 ,
T_6 V_85 ) )
{
V_13 -> V_38 = V_38 ;
V_13 -> V_39 = V_39 ;
}
void F_48 ( T_1 * V_13 ,
int (* V_40) ( T_2
* V_63 ) ,
int (* V_41) ( T_2
* V_63 ,
unsigned char
* V_82 ,
T_6 * V_83 ,
const unsigned
char * V_84 ,
T_6 V_85 ) )
{
V_13 -> V_40 = V_40 ;
V_13 -> V_41 = V_41 ;
}
void F_49 ( T_1 * V_13 ,
int (* V_42) ( T_2 * V_63 ,
T_7 * V_86 ) ,
int (* V_43) ( T_2 * V_63 ,
unsigned char * V_82 ,
T_6 * V_83 ,
T_7 * V_86 ) )
{
V_13 -> V_42 = V_42 ;
V_13 -> V_43 = V_43 ;
}
void F_50 ( T_1 * V_13 ,
int (* V_44) ( T_2 * V_63 ,
T_7 * V_86 ) ,
int (* V_45) ( T_2 * V_63 ,
const unsigned char * V_82 ,
int V_83 ,
T_7 * V_86 ) )
{
V_13 -> V_44 = V_44 ;
V_13 -> V_45 = V_45 ;
}
void F_51 ( T_1 * V_13 ,
int (* V_46) ( T_2 * V_63 ) ,
int (* F_52) ( T_2 * V_63 ,
unsigned char * V_87 ,
T_6 * V_88 ,
const unsigned char * V_89 ,
T_6 V_90 ) )
{
V_13 -> V_46 = V_46 ;
V_13 -> V_47 = F_52 ;
}
void F_53 ( T_1 * V_13 ,
int (* V_48) ( T_2 * V_63 ) ,
int (* V_49) ( T_2 * V_63 ,
unsigned char * V_87 ,
T_6 * V_88 ,
const unsigned char * V_89 ,
T_6 V_90 ) )
{
V_13 -> V_48 = V_48 ;
V_13 -> V_49 = V_49 ;
}
void F_54 ( T_1 * V_13 ,
int (* V_50) ( T_2 * V_63 ) ,
int (* V_51) ( T_2 * V_63 ,
unsigned char * V_91 ,
T_6 * V_92 ) )
{
V_13 -> V_50 = V_50 ;
V_13 -> V_51 = V_51 ;
}
void F_55 ( T_1 * V_13 ,
int (* V_52) ( T_2 * V_63 , int type , int V_67 ,
void * V_68 ) ,
int (* V_53) ( T_2 * V_63 ,
const char * type ,
const char * V_74 ) )
{
V_13 -> V_52 = V_52 ;
V_13 -> V_53 = V_53 ;
}
