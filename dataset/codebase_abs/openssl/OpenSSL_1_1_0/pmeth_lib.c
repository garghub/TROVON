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
V_6 = F_12 ( sizeof( * V_6 ) ) ;
if ( V_6 == NULL ) {
#ifndef F_7
F_13 ( V_11 ) ;
#endif
F_9 ( V_16 , V_19 ) ;
return NULL ;
}
V_6 -> V_15 = V_11 ;
V_6 -> V_13 = V_13 ;
V_6 -> V_20 = V_21 ;
V_6 -> V_10 = V_10 ;
if ( V_10 )
F_14 ( V_10 ) ;
if ( V_13 -> V_22 ) {
if ( V_13 -> V_22 ( V_6 ) <= 0 ) {
F_15 ( V_6 ) ;
return NULL ;
}
}
return V_6 ;
}
T_1 * F_16 ( int V_12 , int V_23 )
{
T_1 * V_13 ;
V_13 = F_12 ( sizeof( * V_13 ) ) ;
if ( V_13 == NULL )
return NULL ;
V_13 -> V_3 = V_12 ;
V_13 -> V_23 = V_23 | V_24 ;
return V_13 ;
}
void F_17 ( int * V_25 , int * V_26 ,
const T_1 * V_27 )
{
if ( V_25 )
* V_25 = V_27 -> V_3 ;
if ( V_26 )
* V_26 = V_27 -> V_23 ;
}
void F_18 ( T_1 * V_28 , const T_1 * V_29 )
{
V_28 -> V_22 = V_29 -> V_22 ;
V_28 -> V_30 = V_29 -> V_30 ;
V_28 -> V_31 = V_29 -> V_31 ;
V_28 -> V_32 = V_29 -> V_32 ;
V_28 -> V_33 = V_29 -> V_33 ;
V_28 -> V_34 = V_29 -> V_34 ;
V_28 -> V_35 = V_29 -> V_35 ;
V_28 -> V_36 = V_29 -> V_36 ;
V_28 -> V_37 = V_29 -> V_37 ;
V_28 -> V_38 = V_29 -> V_38 ;
V_28 -> V_39 = V_29 -> V_39 ;
V_28 -> V_40 = V_29 -> V_40 ;
V_28 -> V_41 = V_29 -> V_41 ;
V_28 -> V_42 = V_29 -> V_42 ;
V_28 -> V_43 = V_29 -> V_43 ;
V_28 -> V_44 = V_29 -> V_44 ;
V_28 -> V_45 = V_29 -> V_45 ;
V_28 -> V_46 = V_29 -> V_46 ;
V_28 -> V_47 = V_29 -> V_47 ;
V_28 -> V_48 = V_29 -> V_48 ;
V_28 -> V_49 = V_29 -> V_49 ;
V_28 -> V_50 = V_29 -> V_50 ;
V_28 -> V_51 = V_29 -> V_51 ;
V_28 -> V_52 = V_29 -> V_52 ;
V_28 -> V_53 = V_29 -> V_53 ;
}
void F_19 ( T_1 * V_13 )
{
if ( V_13 && ( V_13 -> V_23 & V_24 ) )
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
T_2 * F_23 ( T_2 * V_54 )
{
T_2 * V_55 ;
if ( ! V_54 -> V_13 || ! V_54 -> V_13 -> V_30 )
return NULL ;
#ifndef F_7
if ( V_54 -> V_15 && ! F_8 ( V_54 -> V_15 ) ) {
F_9 ( V_56 , V_17 ) ;
return 0 ;
}
#endif
V_55 = F_24 ( sizeof( * V_55 ) ) ;
if ( V_55 == NULL )
return NULL ;
V_55 -> V_13 = V_54 -> V_13 ;
#ifndef F_7
V_55 -> V_15 = V_54 -> V_15 ;
#endif
if ( V_54 -> V_10 )
F_14 ( V_54 -> V_10 ) ;
V_55 -> V_10 = V_54 -> V_10 ;
if ( V_54 -> V_57 )
F_14 ( V_54 -> V_57 ) ;
V_55 -> V_57 = V_54 -> V_57 ;
V_55 -> V_58 = NULL ;
V_55 -> V_59 = NULL ;
V_55 -> V_20 = V_54 -> V_20 ;
if ( V_54 -> V_13 -> V_30 ( V_55 , V_54 ) > 0 )
return V_55 ;
F_15 ( V_55 ) ;
return NULL ;
}
int F_25 ( const T_1 * V_13 )
{
if ( V_7 == NULL ) {
V_7 = F_26 ( F_1 ) ;
if ( V_7 == NULL )
return 0 ;
}
if ( ! F_27 ( V_7 , V_13 ) )
return 0 ;
F_28 ( V_7 ) ;
return 1 ;
}
void F_15 ( T_2 * V_60 )
{
if ( V_60 == NULL )
return;
if ( V_60 -> V_13 && V_60 -> V_13 -> V_31 )
V_60 -> V_13 -> V_31 ( V_60 ) ;
F_29 ( V_60 -> V_10 ) ;
F_29 ( V_60 -> V_57 ) ;
#ifndef F_7
F_13 ( V_60 -> V_15 ) ;
#endif
F_20 ( V_60 ) ;
}
int F_30 ( T_2 * V_60 , int V_61 , int V_62 ,
int V_63 , int V_64 , void * V_65 )
{
int V_6 ;
if ( ! V_60 || ! V_60 -> V_13 || ! V_60 -> V_13 -> V_52 ) {
F_9 ( V_66 , V_67 ) ;
return - 2 ;
}
if ( ( V_61 != - 1 ) && ( V_60 -> V_13 -> V_3 != V_61 ) )
return - 1 ;
if ( V_60 -> V_20 == V_21 ) {
F_9 ( V_66 , V_68 ) ;
return - 1 ;
}
if ( ( V_62 != - 1 ) && ! ( V_60 -> V_20 & V_62 ) ) {
F_9 ( V_66 , V_69 ) ;
return - 1 ;
}
V_6 = V_60 -> V_13 -> V_52 ( V_60 , V_63 , V_64 , V_65 ) ;
if ( V_6 == - 2 )
F_9 ( V_66 , V_67 ) ;
return V_6 ;
}
int F_31 ( T_2 * V_60 ,
const char * V_70 , const char * V_71 )
{
if ( ! V_60 || ! V_60 -> V_13 || ! V_60 -> V_13 -> V_53 ) {
F_9 ( V_72 , V_67 ) ;
return - 2 ;
}
if ( strcmp ( V_70 , L_1 ) == 0 ) {
const T_5 * V_73 ;
if ( V_71 == NULL || ( V_73 = F_32 ( V_71 ) ) == NULL ) {
F_9 ( V_72 , V_74 ) ;
return 0 ;
}
return F_33 ( V_60 , V_73 ) ;
}
return V_60 -> V_13 -> V_53 ( V_60 , V_70 , V_71 ) ;
}
int F_34 ( T_2 * V_60 , int V_63 , const char * V_75 )
{
T_6 V_76 ;
V_76 = strlen ( V_75 ) ;
if ( V_76 > V_77 )
return - 1 ;
return V_60 -> V_13 -> V_52 ( V_60 , V_63 , V_76 , ( void * ) V_75 ) ;
}
int F_35 ( T_2 * V_60 , int V_63 , const char * V_78 )
{
unsigned char * V_79 ;
long V_80 ;
int V_81 = - 1 ;
V_79 = F_36 ( V_78 , & V_80 ) ;
if ( V_79 == NULL )
return 0 ;
if ( V_80 <= V_77 )
V_81 = V_60 -> V_13 -> V_52 ( V_60 , V_63 , V_80 , V_79 ) ;
F_20 ( V_79 ) ;
return V_81 ;
}
int F_37 ( T_2 * V_60 )
{
return V_60 -> V_20 ;
}
void F_38 ( T_2 * V_60 , int * V_82 , int V_83 )
{
V_60 -> V_84 = V_82 ;
V_60 -> V_85 = V_83 ;
}
void F_39 ( T_2 * V_60 , void * V_58 )
{
V_60 -> V_58 = V_58 ;
}
void * F_40 ( T_2 * V_60 )
{
return V_60 -> V_58 ;
}
T_3 * F_41 ( T_2 * V_60 )
{
return V_60 -> V_10 ;
}
T_3 * F_42 ( T_2 * V_60 )
{
return V_60 -> V_57 ;
}
void F_43 ( T_2 * V_60 , void * V_58 )
{
V_60 -> V_59 = V_58 ;
}
void * F_44 ( T_2 * V_60 )
{
return V_60 -> V_59 ;
}
void F_45 ( T_1 * V_13 ,
int (* V_22) ( T_2 * V_60 ) )
{
V_13 -> V_22 = V_22 ;
}
void F_46 ( T_1 * V_13 ,
int (* V_30) ( T_2 * V_28 ,
T_2 * V_29 ) )
{
V_13 -> V_30 = V_30 ;
}
void F_47 ( T_1 * V_13 ,
void (* V_31) ( T_2 * V_60 ) )
{
V_13 -> V_31 = V_31 ;
}
void F_48 ( T_1 * V_13 ,
int (* V_32) ( T_2 * V_60 ) ,
int (* V_33) ( T_2 * V_60 ,
T_3 * V_10 ) )
{
V_13 -> V_32 = V_32 ;
V_13 -> V_33 = V_33 ;
}
void F_49 ( T_1 * V_13 ,
int (* V_34) ( T_2 * V_60 ) ,
int (* V_35) ( T_2 * V_60 ,
T_3 * V_10 ) )
{
V_13 -> V_34 = V_34 ;
V_13 -> V_35 = V_35 ;
}
void F_50 ( T_1 * V_13 ,
int (* V_36) ( T_2 * V_60 ) ,
int (* V_37) ( T_2 * V_60 ,
unsigned char * V_86 , T_6 * V_87 ,
const unsigned char * V_88 ,
T_6 V_89 ) )
{
V_13 -> V_36 = V_36 ;
V_13 -> V_37 = V_37 ;
}
void F_51 ( T_1 * V_13 ,
int (* V_38) ( T_2 * V_60 ) ,
int (* V_39) ( T_2 * V_60 ,
const unsigned char * V_86 ,
T_6 V_87 ,
const unsigned char * V_88 ,
T_6 V_89 ) )
{
V_13 -> V_38 = V_38 ;
V_13 -> V_39 = V_39 ;
}
void F_52 ( T_1 * V_13 ,
int (* V_40) ( T_2
* V_60 ) ,
int (* V_41) ( T_2
* V_60 ,
unsigned char
* V_86 ,
T_6 * V_87 ,
const unsigned
char * V_88 ,
T_6 V_89 ) )
{
V_13 -> V_40 = V_40 ;
V_13 -> V_41 = V_41 ;
}
void F_53 ( T_1 * V_13 ,
int (* V_42) ( T_2 * V_60 ,
T_7 * V_90 ) ,
int (* V_43) ( T_2 * V_60 ,
unsigned char * V_86 ,
T_6 * V_87 ,
T_7 * V_90 ) )
{
V_13 -> V_42 = V_42 ;
V_13 -> V_43 = V_43 ;
}
void F_54 ( T_1 * V_13 ,
int (* V_44) ( T_2 * V_60 ,
T_7 * V_90 ) ,
int (* V_45) ( T_2 * V_60 ,
const unsigned char * V_86 ,
int V_87 ,
T_7 * V_90 ) )
{
V_13 -> V_44 = V_44 ;
V_13 -> V_45 = V_45 ;
}
void F_55 ( T_1 * V_13 ,
int (* V_46) ( T_2 * V_60 ) ,
int (* F_56) ( T_2 * V_60 ,
unsigned char * V_91 ,
T_6 * V_92 ,
const unsigned char * V_93 ,
T_6 V_94 ) )
{
V_13 -> V_46 = V_46 ;
V_13 -> V_47 = F_56 ;
}
void F_57 ( T_1 * V_13 ,
int (* V_48) ( T_2 * V_60 ) ,
int (* V_49) ( T_2 * V_60 ,
unsigned char * V_91 ,
T_6 * V_92 ,
const unsigned char * V_93 ,
T_6 V_94 ) )
{
V_13 -> V_48 = V_48 ;
V_13 -> V_49 = V_49 ;
}
void F_58 ( T_1 * V_13 ,
int (* V_50) ( T_2 * V_60 ) ,
int (* V_51) ( T_2 * V_60 ,
unsigned char * V_95 ,
T_6 * V_96 ) )
{
V_13 -> V_50 = V_50 ;
V_13 -> V_51 = V_51 ;
}
void F_59 ( T_1 * V_13 ,
int (* V_52) ( T_2 * V_60 , int type , int V_64 ,
void * V_65 ) ,
int (* V_53) ( T_2 * V_60 ,
const char * type ,
const char * V_71 ) )
{
V_13 -> V_52 = V_52 ;
V_13 -> V_53 = V_53 ;
}
void F_60 ( T_1 * V_13 ,
int (* * F_61) ( T_2 * V_60 ) )
{
* F_61 = V_13 -> V_22 ;
}
void F_62 ( T_1 * V_13 ,
int (* * F_63) ( T_2 * V_28 ,
T_2 * V_29 ) )
{
* F_63 = V_13 -> V_30 ;
}
void F_64 ( T_1 * V_13 ,
void (* * F_65) ( T_2 * V_60 ) )
{
* F_65 = V_13 -> V_31 ;
}
void F_66 ( T_1 * V_13 ,
int (* * F_67) ( T_2 * V_60 ) ,
int (* * F_68) ( T_2 * V_60 ,
T_3 * V_10 ) )
{
if ( F_67 )
* F_67 = V_13 -> V_32 ;
if ( F_68 )
* F_68 = V_13 -> V_33 ;
}
void F_69 ( T_1 * V_13 ,
int (* * F_70) ( T_2 * V_60 ) ,
int (* * F_71) ( T_2 * V_60 ,
T_3 * V_10 ) )
{
if ( F_70 )
* F_70 = V_13 -> V_34 ;
if ( F_71 )
* F_71 = V_13 -> V_35 ;
}
void F_72 ( T_1 * V_13 ,
int (* * F_73) ( T_2 * V_60 ) ,
int (* * F_74) ( T_2 * V_60 ,
unsigned char * V_86 , T_6 * V_87 ,
const unsigned char * V_88 ,
T_6 V_89 ) )
{
if ( F_73 )
* F_73 = V_13 -> V_36 ;
if ( F_74 )
* F_74 = V_13 -> V_37 ;
}
void F_75 ( T_1 * V_13 ,
int (* * F_76) ( T_2 * V_60 ) ,
int (* * F_77) ( T_2 * V_60 ,
const unsigned char * V_86 ,
T_6 V_87 ,
const unsigned char * V_88 ,
T_6 V_89 ) )
{
if ( F_76 )
* F_76 = V_13 -> V_38 ;
if ( F_77 )
* F_77 = V_13 -> V_39 ;
}
void F_78 ( T_1 * V_13 ,
int (* * F_79) ( T_2
* V_60 ) ,
int (* * F_80) ( T_2
* V_60 ,
unsigned char
* V_86 ,
T_6 * V_87 ,
const unsigned
char * V_88 ,
T_6 V_89 ) )
{
if ( F_79 )
* F_79 = V_13 -> V_40 ;
if ( F_80 )
* F_80 = V_13 -> V_41 ;
}
void F_81 ( T_1 * V_13 ,
int (* * F_82) ( T_2 * V_60 ,
T_7 * V_90 ) ,
int (* * F_83) ( T_2 * V_60 ,
unsigned char * V_86 ,
T_6 * V_87 ,
T_7 * V_90 ) )
{
if ( F_82 )
* F_82 = V_13 -> V_42 ;
if ( F_83 )
* F_83 = V_13 -> V_43 ;
}
void F_84 ( T_1 * V_13 ,
int (* * F_85) ( T_2 * V_60 ,
T_7 * V_90 ) ,
int (* * F_86) ( T_2 * V_60 ,
const unsigned char * V_86 ,
int V_87 ,
T_7 * V_90 ) )
{
if ( F_85 )
* F_85 = V_13 -> V_44 ;
if ( F_86 )
* F_86 = V_13 -> V_45 ;
}
void F_87 ( T_1 * V_13 ,
int (* * F_88) ( T_2 * V_60 ) ,
int (* * F_89) ( T_2 * V_60 ,
unsigned char * V_91 ,
T_6 * V_92 ,
const unsigned char * V_93 ,
T_6 V_94 ) )
{
if ( F_88 )
* F_88 = V_13 -> V_46 ;
if ( F_89 )
* F_89 = V_13 -> V_47 ;
}
void F_90 ( T_1 * V_13 ,
int (* * F_91) ( T_2 * V_60 ) ,
int (* * F_92) ( T_2 * V_60 ,
unsigned char * V_91 ,
T_6 * V_92 ,
const unsigned char * V_93 ,
T_6 V_94 ) )
{
if ( F_91 )
* F_91 = V_13 -> V_48 ;
if ( F_92 )
* F_92 = V_13 -> V_49 ;
}
void F_93 ( T_1 * V_13 ,
int (* * F_94) ( T_2 * V_60 ) ,
int (* * F_95) ( T_2 * V_60 ,
unsigned char * V_95 ,
T_6 * V_96 ) )
{
if ( F_94 )
* F_94 = V_13 -> V_50 ;
if ( F_95 )
* F_95 = V_13 -> V_51 ;
}
void F_96 ( T_1 * V_13 ,
int (* * F_97) ( T_2 * V_60 , int type , int V_64 ,
void * V_65 ) ,
int (* * F_98) ( T_2 * V_60 ,
const char * type ,
const char * V_71 ) )
{
if ( F_97 )
* F_97 = V_13 -> V_52 ;
if ( F_98 )
* F_98 = V_13 -> V_53 ;
}
