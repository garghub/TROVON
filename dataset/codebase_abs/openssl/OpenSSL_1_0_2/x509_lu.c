T_1 * F_1 ( T_2 * V_1 )
{
T_1 * V_2 ;
V_2 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_1 = V_1 ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = NULL ;
if ( ( V_1 -> V_7 != NULL ) && ! V_1 -> V_7 ( V_2 ) ) {
F_3 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void F_4 ( T_1 * V_8 )
{
if ( V_8 == NULL )
return;
if ( ( V_8 -> V_1 != NULL ) && ( V_8 -> V_1 -> free != NULL ) )
(* V_8 -> V_1 -> free ) ( V_8 ) ;
F_3 ( V_8 ) ;
}
int F_5 ( T_1 * V_8 )
{
if ( V_8 -> V_1 == NULL )
return 0 ;
if ( V_8 -> V_1 -> V_3 != NULL )
return V_8 -> V_1 -> V_3 ( V_8 ) ;
else
return 1 ;
}
int F_6 ( T_1 * V_8 )
{
if ( V_8 -> V_1 == NULL )
return 0 ;
if ( V_8 -> V_1 -> V_9 != NULL )
return V_8 -> V_1 -> V_9 ( V_8 ) ;
else
return 1 ;
}
int F_7 ( T_1 * V_8 , int V_10 , const char * V_11 , long V_12 ,
char * * V_2 )
{
if ( V_8 -> V_1 == NULL )
return - 1 ;
if ( V_8 -> V_1 -> V_13 != NULL )
return V_8 -> V_1 -> V_13 ( V_8 , V_10 , V_11 , V_12 , V_2 ) ;
else
return 1 ;
}
int F_8 ( T_1 * V_8 , int type , T_3 * V_14 ,
T_4 * V_2 )
{
if ( ( V_8 -> V_1 == NULL ) || ( V_8 -> V_1 -> V_15 == NULL ) )
return V_16 ;
if ( V_8 -> V_4 )
return 0 ;
return V_8 -> V_1 -> V_15 ( V_8 , type , V_14 , V_2 ) ;
}
int F_9 ( T_1 * V_8 , int type , T_3 * V_14 ,
T_5 * V_17 , T_4 * V_2 )
{
if ( ( V_8 -> V_1 == NULL ) || ( V_8 -> V_1 -> V_18 == NULL ) )
return V_16 ;
return V_8 -> V_1 -> V_18 ( V_8 , type , V_14 , V_17 , V_2 ) ;
}
int F_10 ( T_1 * V_8 , int type ,
unsigned char * V_19 , int V_20 ,
T_4 * V_2 )
{
if ( ( V_8 -> V_1 == NULL ) || ( V_8 -> V_1 -> V_21 == NULL ) )
return V_16 ;
return V_8 -> V_1 -> V_21 ( V_8 , type , V_19 , V_20 , V_2 ) ;
}
int F_11 ( T_1 * V_8 , int type , char * V_22 , int V_20 ,
T_4 * V_2 )
{
if ( ( V_8 -> V_1 == NULL ) || ( V_8 -> V_1 -> V_23 == NULL ) )
return V_16 ;
return V_8 -> V_1 -> V_23 ( V_8 , type , V_22 , V_20 , V_2 ) ;
}
static int F_12 ( const T_4 * const * V_24 ,
const T_4 * const * V_25 )
{
int V_2 ;
V_2 = ( ( * V_24 ) -> type - ( * V_25 ) -> type ) ;
if ( V_2 )
return V_2 ;
switch ( ( * V_24 ) -> type ) {
case V_26 :
V_2 = F_13 ( ( * V_24 ) -> V_27 . V_28 , ( * V_25 ) -> V_27 . V_28 ) ;
break;
case V_29 :
V_2 = F_14 ( ( * V_24 ) -> V_27 . V_30 , ( * V_25 ) -> V_27 . V_30 ) ;
break;
default:
return 0 ;
}
return V_2 ;
}
T_6 * F_15 ( void )
{
T_6 * V_2 ;
if ( ( V_2 = ( T_6 * ) F_2 ( sizeof( T_6 ) ) ) == NULL )
return NULL ;
V_2 -> V_31 = F_16 ( F_12 ) ;
V_2 -> V_32 = 1 ;
V_2 -> V_33 = F_17 () ;
V_2 -> V_34 = 0 ;
V_2 -> V_35 = 0 ;
if ( ( V_2 -> V_36 = F_18 () ) == NULL )
return NULL ;
V_2 -> V_37 = 0 ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = 0 ;
V_2 -> V_40 = 0 ;
V_2 -> V_41 = 0 ;
V_2 -> V_42 = 0 ;
V_2 -> V_43 = 0 ;
V_2 -> V_44 = 0 ;
V_2 -> V_45 = 0 ;
if ( ! F_19 ( V_46 , V_2 , & V_2 -> V_47 ) ) {
F_20 ( V_2 -> V_31 ) ;
F_3 ( V_2 ) ;
return NULL ;
}
V_2 -> V_48 = 1 ;
return V_2 ;
}
static void V_45 ( T_4 * V_24 )
{
if ( V_24 -> type == V_26 ) {
F_21 ( V_24 -> V_27 . V_28 ) ;
} else if ( V_24 -> type == V_29 ) {
F_22 ( V_24 -> V_27 . V_30 ) ;
} else {
}
F_3 ( V_24 ) ;
}
void F_23 ( T_6 * V_49 )
{
int V_50 ;
F_24 ( T_1 ) * V_51 ;
T_1 * V_52 ;
if ( V_49 == NULL )
return;
V_50 = F_25 ( & V_49 -> V_48 , - 1 , V_53 ) ;
#ifdef F_26
F_26 ( L_1 , V_49 ) ;
#endif
if ( V_50 > 0 )
return;
#ifdef F_27
if ( V_50 < 0 ) {
fprintf ( V_54 , L_2 ) ;
abort () ;
}
#endif
V_51 = V_49 -> V_33 ;
for ( V_50 = 0 ; V_50 < F_28 ( V_51 ) ; V_50 ++ ) {
V_52 = F_29 ( V_51 , V_50 ) ;
F_6 ( V_52 ) ;
F_4 ( V_52 ) ;
}
F_30 ( V_51 ) ;
F_31 ( V_49 -> V_31 , V_45 ) ;
F_32 ( V_46 , V_49 , & V_49 -> V_47 ) ;
if ( V_49 -> V_36 )
F_33 ( V_49 -> V_36 ) ;
F_3 ( V_49 ) ;
}
T_1 * F_34 ( T_6 * V_55 , T_2 * V_56 )
{
int V_50 ;
F_24 ( T_1 ) * V_51 ;
T_1 * V_52 ;
V_51 = V_55 -> V_33 ;
for ( V_50 = 0 ; V_50 < F_28 ( V_51 ) ; V_50 ++ ) {
V_52 = F_29 ( V_51 , V_50 ) ;
if ( V_56 == V_52 -> V_1 ) {
return V_52 ;
}
}
V_52 = F_1 ( V_56 ) ;
if ( V_52 == NULL )
return NULL ;
else {
V_52 -> V_6 = V_55 ;
if ( F_35 ( V_55 -> V_33 , V_52 ) )
return V_52 ;
else {
F_4 ( V_52 ) ;
return NULL ;
}
}
}
int F_36 ( T_7 * V_57 , int type , T_3 * V_14 ,
T_4 * V_2 )
{
T_6 * V_8 = V_57 -> V_8 ;
T_1 * V_52 ;
T_4 V_58 , * V_59 ;
int V_50 , V_60 ;
F_37 ( V_53 ) ;
V_59 = F_38 ( V_8 -> V_31 , type , V_14 ) ;
F_39 ( V_53 ) ;
if ( V_59 == NULL || type == V_29 ) {
for ( V_50 = V_57 -> V_61 ;
V_50 < F_28 ( V_8 -> V_33 ) ; V_50 ++ ) {
V_52 = F_29 ( V_8 -> V_33 , V_50 ) ;
V_60 = F_8 ( V_52 , type , V_14 , & V_58 ) ;
if ( V_60 < 0 ) {
V_57 -> V_61 = V_60 ;
return V_60 ;
} else if ( V_60 ) {
V_59 = & V_58 ;
break;
}
}
V_57 -> V_61 = 0 ;
if ( V_59 == NULL )
return 0 ;
}
V_2 -> type = V_59 -> type ;
V_2 -> V_27 . V_62 = V_59 -> V_27 . V_62 ;
F_40 ( V_2 ) ;
return 1 ;
}
int F_41 ( T_6 * V_8 , T_8 * V_63 )
{
T_4 * V_64 ;
int V_2 = 1 ;
if ( V_63 == NULL )
return 0 ;
V_64 = ( T_4 * ) F_2 ( sizeof( T_4 ) ) ;
if ( V_64 == NULL ) {
F_42 ( V_65 , V_66 ) ;
return 0 ;
}
V_64 -> type = V_26 ;
V_64 -> V_27 . V_28 = V_63 ;
F_37 ( V_53 ) ;
F_40 ( V_64 ) ;
if ( F_43 ( V_8 -> V_31 , V_64 ) ) {
F_44 ( V_64 ) ;
F_3 ( V_64 ) ;
F_42 ( V_65 ,
V_67 ) ;
V_2 = 0 ;
} else
F_45 ( V_8 -> V_31 , V_64 ) ;
F_39 ( V_53 ) ;
return V_2 ;
}
int F_46 ( T_6 * V_8 , T_9 * V_63 )
{
T_4 * V_64 ;
int V_2 = 1 ;
if ( V_63 == NULL )
return 0 ;
V_64 = ( T_4 * ) F_2 ( sizeof( T_4 ) ) ;
if ( V_64 == NULL ) {
F_42 ( V_68 , V_66 ) ;
return 0 ;
}
V_64 -> type = V_29 ;
V_64 -> V_27 . V_30 = V_63 ;
F_37 ( V_53 ) ;
F_40 ( V_64 ) ;
if ( F_43 ( V_8 -> V_31 , V_64 ) ) {
F_44 ( V_64 ) ;
F_3 ( V_64 ) ;
F_42 ( V_68 , V_67 ) ;
V_2 = 0 ;
} else
F_45 ( V_8 -> V_31 , V_64 ) ;
F_39 ( V_53 ) ;
return V_2 ;
}
void F_40 ( T_4 * V_24 )
{
switch ( V_24 -> type ) {
case V_26 :
F_25 ( & V_24 -> V_27 . V_28 -> V_48 , 1 , V_69 ) ;
break;
case V_29 :
F_25 ( & V_24 -> V_27 . V_30 -> V_48 , 1 , V_70 ) ;
break;
}
}
void F_44 ( T_4 * V_24 )
{
switch ( V_24 -> type ) {
case V_26 :
F_21 ( V_24 -> V_27 . V_28 ) ;
break;
case V_29 :
F_22 ( V_24 -> V_27 . V_30 ) ;
break;
}
}
int F_47 ( T_6 * V_8 , unsigned long V_71 )
{
return F_48 ( V_8 -> V_36 , V_71 ) ;
}
int F_49 ( T_6 * V_8 , int V_72 )
{
F_50 ( V_8 -> V_36 , V_72 ) ;
return 1 ;
}
int F_51 ( T_6 * V_8 , int V_73 )
{
return F_52 ( V_8 -> V_36 , V_73 ) ;
}
int F_53 ( T_6 * V_8 , int V_74 )
{
return F_54 ( V_8 -> V_36 , V_74 ) ;
}
int F_55 ( T_6 * V_8 , T_10 * V_36 )
{
return F_56 ( V_8 -> V_36 , V_36 ) ;
}
void F_57 ( T_6 * V_8 ,
int (* V_35) ( int , T_7 * ) )
{
V_8 -> V_35 = V_35 ;
}
T_6 * F_58 ( T_7 * V_8 )
{
return V_8 -> V_8 ;
}
