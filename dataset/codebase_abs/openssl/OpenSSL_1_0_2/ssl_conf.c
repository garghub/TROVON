static int F_1 ( T_1 * V_1 , const T_2 * V_2 ,
const char * V_3 , int V_4 , int V_5 )
{
if ( ! ( V_1 -> V_6 & V_2 -> V_7 & V_8 ) )
return 0 ;
if ( V_4 == - 1 ) {
if ( strcmp ( V_2 -> V_3 , V_3 ) )
return 0 ;
} else if ( V_2 -> V_4 != V_4
|| strncasecmp ( V_2 -> V_3 , V_3 , V_4 ) )
return 0 ;
if ( V_1 -> V_9 ) {
if ( V_2 -> V_7 & V_10 )
V_5 ^= 1 ;
if ( V_2 -> V_7 & V_11 ) {
if ( V_5 )
* V_1 -> V_12 |= V_2 -> V_13 ;
else
* V_1 -> V_12 &= ~ V_2 -> V_13 ;
} else {
if ( V_5 )
* V_1 -> V_9 |= V_2 -> V_13 ;
else
* V_1 -> V_9 &= ~ V_2 -> V_13 ;
}
}
return 1 ;
}
static int F_2 ( const char * V_14 , int V_15 , void * V_16 )
{
T_1 * V_1 = V_16 ;
T_3 V_17 ;
const T_2 * V_2 ;
int V_5 = 1 ;
if ( V_15 != - 1 ) {
if ( * V_14 == '+' ) {
V_14 ++ ;
V_15 -- ;
V_5 = 1 ;
} else if ( * V_14 == '-' ) {
V_14 ++ ;
V_15 -- ;
V_5 = 0 ;
}
}
for ( V_17 = 0 , V_2 = V_1 -> V_2 ; V_17 < V_1 -> V_18 ; V_17 ++ , V_2 ++ ) {
if ( F_1 ( V_1 , V_2 , V_14 , V_15 , V_5 ) )
return 1 ;
}
return 0 ;
}
static int F_3 ( T_1 * V_1 , const char * V_19 )
{
static const T_2 V_20 [] = {
F_4 ( L_1 , V_21 ) ,
F_4 ( L_2 , V_22 ) ,
F_4 ( L_3 , V_23 ) ,
F_4 ( L_4 , V_24 ) ,
F_4 ( L_5 , V_25 ) ,
F_4 ( L_6 , V_26 ) ,
F_4 ( L_7 , V_27 ) ,
F_5 ( L_8 , V_28 ) ,
#ifndef F_6
F_4 ( L_9 , V_29 ) ,
#endif
F_5 ( L_10 , V_30 ) ,
F_4 ( L_11 ,
V_31 ) ,
F_5 ( L_12 ,
V_32 ) ,
F_5 ( L_13 ,
V_33 ) ,
F_7 ( L_14 ,
V_32 ) ,
F_8 ( L_15 , V_34 ) ,
#ifdef F_9
F_8 ( L_16 ,
V_35 ) ,
#endif
} ;
V_1 -> V_2 = V_20 ;
V_1 -> V_18 = sizeof( V_20 ) / sizeof( T_2 ) ;
return F_2 ( V_19 , - 1 , V_1 ) ;
}
static int F_10 ( T_1 * V_1 , const char * V_36 )
{
int V_37 ;
if ( V_1 -> V_38 )
V_37 = F_11 ( V_1 -> V_38 , V_36 ) ;
else
V_37 = F_12 ( V_1 -> V_39 , V_36 ) ;
return V_37 > 0 ;
}
static int F_13 ( T_1 * V_1 ,
const char * V_36 )
{
int V_37 ;
if ( V_1 -> V_38 )
V_37 = F_14 ( V_1 -> V_38 , V_36 ) ;
else
V_37 = F_15 ( V_1 -> V_39 , V_36 ) ;
return V_37 > 0 ;
}
static int F_16 ( T_1 * V_1 , const char * V_36 )
{
int V_37 ;
if ( V_1 -> V_38 )
V_37 = F_17 ( V_1 -> V_38 , V_36 ) ;
else
V_37 = F_18 ( V_1 -> V_39 , V_36 ) ;
return V_37 > 0 ;
}
static int F_19 ( T_1 * V_1 , const char * V_36 )
{
int V_5 = - 1 , V_37 = 1 ;
if ( ! ( V_1 -> V_6 & V_40 ) )
return - 2 ;
if ( V_1 -> V_6 & V_41 ) {
if ( * V_36 == '+' ) {
V_5 = 1 ;
V_36 ++ ;
}
if ( * V_36 == '-' ) {
V_5 = 0 ;
V_36 ++ ;
}
if ( ! strcasecmp ( V_36 , L_17 ) ) {
if ( V_5 == - 1 )
V_5 = 1 ;
} else if ( V_5 != - 1 )
return 0 ;
} else if ( V_1 -> V_6 & V_42 ) {
if ( ! strcmp ( V_36 , L_18 ) )
V_5 = 1 ;
}
if ( V_5 != - 1 ) {
if ( V_1 -> V_39 )
V_37 = F_20 ( V_1 -> V_39 , V_5 ) ;
else if ( V_1 -> V_38 )
V_37 = F_21 ( V_1 -> V_38 , V_5 ) ;
} else {
T_4 * V_43 ;
int V_44 ;
V_44 = F_22 ( V_36 ) ;
if ( V_44 == V_45 )
V_44 = F_23 ( V_36 ) ;
if ( V_44 == 0 )
return 0 ;
V_43 = F_24 ( V_44 ) ;
if ( ! V_43 )
return 0 ;
if ( V_1 -> V_39 )
V_37 = F_25 ( V_1 -> V_39 , V_43 ) ;
else if ( V_1 -> V_38 )
V_37 = F_26 ( V_1 -> V_38 , V_43 ) ;
F_27 ( V_43 ) ;
}
return V_37 > 0 ;
}
static int F_28 ( T_1 * V_1 , const char * V_36 )
{
int V_37 = 1 ;
if ( V_1 -> V_39 )
V_37 = F_29 ( V_1 -> V_39 , V_36 ) ;
if ( V_1 -> V_38 )
V_37 = F_30 ( V_1 -> V_38 , V_36 ) ;
return V_37 > 0 ;
}
static int F_31 ( T_1 * V_1 , const char * V_36 )
{
static const T_2 V_46 [] = {
F_32 ( L_19 , V_47 ) ,
F_32 ( L_20 , V_21 ) ,
F_32 ( L_21 , V_22 ) ,
F_32 ( L_22 , V_23 ) ,
F_32 ( L_23 , V_24 ) ,
F_32 ( L_24 , SSL_OP_NO_TLSv1_2)
} ;
if ( ! ( V_1 -> V_6 & V_41 ) )
return - 2 ;
V_1 -> V_2 = V_46 ;
V_1 -> V_18 = sizeof( V_46 ) / sizeof( T_2 ) ;
return F_33 ( V_36 , ',' , 1 , F_2 , V_1 ) ;
}
static int F_34 ( T_1 * V_1 , const char * V_36 )
{
static const T_2 V_48 [] = {
F_32 ( L_25 , V_29 ) ,
F_32 ( L_26 ,
V_49 ) ,
F_4 ( L_27 , V_26 ) ,
F_32 ( L_28 , V_27 ) ,
F_5 ( L_29 , V_30 ) ,
F_5 ( L_30 ,
V_33 ) ,
F_5 ( L_31 , V_50 ) ,
F_5 ( L_32 , V_28 ) ,
F_4 ( L_33 ,
V_31 ) ,
} ;
if ( ! ( V_1 -> V_6 & V_41 ) )
return - 2 ;
if ( V_36 == NULL )
return - 3 ;
V_1 -> V_2 = V_48 ;
V_1 -> V_18 = sizeof( V_48 ) / sizeof( T_2 ) ;
return F_33 ( V_36 , ',' , 1 , F_2 , V_1 ) ;
}
static int F_35 ( T_1 * V_1 , const char * V_36 )
{
int V_37 = 1 ;
if ( ! ( V_1 -> V_6 & V_51 ) )
return - 2 ;
if ( V_1 -> V_39 )
V_37 = F_36 ( V_1 -> V_39 , V_36 ) ;
if ( V_1 -> V_38 )
V_37 = F_37 ( V_1 -> V_38 , V_36 , V_52 ) ;
return V_37 > 0 ;
}
static int F_38 ( T_1 * V_1 , const char * V_36 )
{
int V_37 = 1 ;
if ( ! ( V_1 -> V_6 & V_51 ) )
return - 2 ;
if ( V_1 -> V_39 )
V_37 = F_39 ( V_1 -> V_39 , V_36 , V_52 ) ;
if ( V_1 -> V_38 )
V_37 = F_40 ( V_1 -> V_38 , V_36 , V_52 ) ;
return V_37 > 0 ;
}
static int F_41 ( T_1 * V_1 , const char * V_36 )
{
int V_37 = 0 ;
T_5 * V_53 = NULL ;
T_6 * V_54 = NULL ;
if ( ! ( V_1 -> V_6 & V_51 ) )
return - 2 ;
if ( V_1 -> V_39 || V_1 -> V_38 ) {
V_54 = F_42 ( F_43 () ) ;
if ( ! V_54 )
goto V_55;
if ( F_44 ( V_54 , V_36 ) <= 0 )
goto V_55;
V_53 = F_45 ( V_54 , NULL , NULL , NULL ) ;
if ( ! V_53 )
goto V_55;
} else
return 1 ;
if ( V_1 -> V_39 )
V_37 = F_46 ( V_1 -> V_39 , V_53 ) ;
if ( V_1 -> V_38 )
V_37 = F_47 ( V_1 -> V_38 , V_53 ) ;
V_55:
if ( V_53 )
F_48 ( V_53 ) ;
if ( V_54 )
F_49 ( V_54 ) ;
return V_37 > 0 ;
}
static int F_50 ( T_1 * V_1 , const char * * V_56 )
{
if ( ! V_56 || ! * V_56 )
return 0 ;
if ( V_1 -> V_57 ) {
if ( strlen ( * V_56 ) <= V_1 -> V_58 )
return 0 ;
if ( V_1 -> V_6 & V_42 &&
strncmp ( * V_56 , V_1 -> V_57 , V_1 -> V_58 ) )
return 0 ;
if ( V_1 -> V_6 & V_41 &&
strncasecmp ( * V_56 , V_1 -> V_57 , V_1 -> V_58 ) )
return 0 ;
* V_56 += V_1 -> V_58 ;
} else if ( V_1 -> V_6 & V_42 ) {
if ( * * V_56 != '-' || ! ( * V_56 ) [ 1 ] )
return 0 ;
* V_56 += 1 ;
}
return 1 ;
}
static const T_7 * F_51 ( T_1 * V_1 ,
const char * V_19 )
{
const T_7 * V_59 ;
T_3 V_17 ;
if ( V_19 == NULL )
return NULL ;
for ( V_17 = 0 , V_59 = V_60 ;
V_17 < sizeof( V_60 ) / sizeof( T_7 ) ; V_17 ++ , V_59 ++ ) {
if ( V_1 -> V_6 & V_42 ) {
if ( V_59 -> V_61 && ! strcmp ( V_59 -> V_61 , V_19 ) )
return V_59 ;
}
if ( V_1 -> V_6 & V_41 ) {
if ( V_59 -> V_62 && ! strcasecmp ( V_59 -> V_62 , V_19 ) )
return V_59 ;
}
}
return NULL ;
}
int F_52 ( T_1 * V_1 , const char * V_19 , const char * V_36 )
{
const T_7 * V_63 ;
if ( V_19 == NULL ) {
F_53 ( V_64 , V_65 ) ;
return 0 ;
}
if ( ! F_50 ( V_1 , & V_19 ) )
return - 2 ;
V_63 = F_51 ( V_1 , V_19 ) ;
if ( V_63 ) {
int V_37 ;
if ( V_36 == NULL )
return - 3 ;
V_37 = V_63 -> V_19 ( V_1 , V_36 ) ;
if ( V_37 > 0 )
return 2 ;
if ( V_37 == - 2 )
return - 2 ;
if ( V_1 -> V_6 & V_66 ) {
F_53 ( V_64 , V_67 ) ;
F_54 ( 4 , L_34 , V_19 , L_35 , V_36 ) ;
}
return 0 ;
}
if ( V_1 -> V_6 & V_42 ) {
if ( F_3 ( V_1 , V_19 ) )
return 1 ;
}
if ( V_1 -> V_6 & V_66 ) {
F_53 ( V_64 , V_68 ) ;
F_54 ( 2 , L_34 , V_19 ) ;
}
return - 2 ;
}
int F_55 ( T_1 * V_1 , int * V_69 , char * * * V_70 )
{
int V_37 ;
const char * V_71 = NULL , * V_72 ;
if ( V_69 && * V_69 == 0 )
return 0 ;
if ( ! V_69 || * V_69 > 0 )
V_71 = * * V_70 ;
if ( V_71 == NULL )
return 0 ;
if ( ! V_69 || * V_69 > 1 )
V_72 = ( * V_70 ) [ 1 ] ;
else
V_72 = NULL ;
V_1 -> V_6 &= ~ V_41 ;
V_1 -> V_6 |= V_42 ;
V_37 = F_52 ( V_1 , V_71 , V_72 ) ;
if ( V_37 > 0 ) {
( * V_70 ) += V_37 ;
if ( V_69 )
( * V_69 ) -= V_37 ;
return V_37 ;
}
if ( V_37 == - 2 )
return 0 ;
if ( V_37 == 0 )
return - 1 ;
return V_37 ;
}
int F_56 ( T_1 * V_1 , const char * V_19 )
{
if ( F_50 ( V_1 , & V_19 ) ) {
const T_7 * V_63 ;
V_63 = F_51 ( V_1 , V_19 ) ;
if ( V_63 )
return V_63 -> V_73 ;
}
return V_74 ;
}
T_1 * F_57 ( void )
{
T_1 * V_75 ;
V_75 = F_58 ( sizeof( T_1 ) ) ;
if ( V_75 ) {
V_75 -> V_6 = 0 ;
V_75 -> V_57 = NULL ;
V_75 -> V_58 = 0 ;
V_75 -> V_38 = NULL ;
V_75 -> V_39 = NULL ;
V_75 -> V_9 = NULL ;
V_75 -> V_12 = NULL ;
V_75 -> V_2 = NULL ;
V_75 -> V_18 = 0 ;
}
return V_75 ;
}
int F_59 ( T_1 * V_1 )
{
return 1 ;
}
void F_60 ( T_1 * V_1 )
{
if ( V_1 ) {
if ( V_1 -> V_57 )
F_61 ( V_1 -> V_57 ) ;
F_61 ( V_1 ) ;
}
}
unsigned int F_62 ( T_1 * V_1 , unsigned int V_6 )
{
V_1 -> V_6 |= V_6 ;
return V_1 -> V_6 ;
}
unsigned int F_63 ( T_1 * V_1 , unsigned int V_6 )
{
V_1 -> V_6 &= ~ V_6 ;
return V_1 -> V_6 ;
}
int F_64 ( T_1 * V_1 , const char * V_76 )
{
char * V_77 = NULL ;
if ( V_76 ) {
V_77 = F_65 ( V_76 ) ;
if ( V_77 == NULL )
return 0 ;
}
if ( V_1 -> V_57 )
F_61 ( V_1 -> V_57 ) ;
V_1 -> V_57 = V_77 ;
if ( V_77 )
V_1 -> V_58 = strlen ( V_77 ) ;
else
V_1 -> V_58 = 0 ;
return 1 ;
}
void F_66 ( T_1 * V_1 , T_8 * V_38 )
{
V_1 -> V_38 = V_38 ;
V_1 -> V_39 = NULL ;
if ( V_38 ) {
V_1 -> V_9 = & V_38 -> V_78 ;
V_1 -> V_12 = & V_38 -> V_79 -> V_80 ;
} else {
V_1 -> V_9 = NULL ;
V_1 -> V_12 = NULL ;
}
}
void F_67 ( T_1 * V_1 , T_9 * V_39 )
{
V_1 -> V_39 = V_39 ;
V_1 -> V_38 = NULL ;
if ( V_39 ) {
V_1 -> V_9 = & V_39 -> V_78 ;
V_1 -> V_12 = & V_39 -> V_79 -> V_80 ;
} else {
V_1 -> V_9 = NULL ;
V_1 -> V_12 = NULL ;
}
}
