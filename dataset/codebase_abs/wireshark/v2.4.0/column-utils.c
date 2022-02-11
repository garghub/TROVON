void
F_1 ( T_1 * V_1 , const T_2 V_2 )
{
int V_3 ;
V_4 = localeconv () -> V_5 ;
V_1 -> V_2 = V_2 ;
V_1 -> V_6 = F_2 ( V_7 , V_2 ) ;
V_1 -> V_8 = F_2 ( int , V_9 ) ;
V_1 -> V_10 = F_2 ( int , V_9 ) ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
V_1 -> V_6 [ V_3 ] . V_11 = NULL ;
}
V_1 -> V_12 . V_12 = F_2 ( const V_13 * , V_2 + 1 ) ;
V_1 -> V_12 . V_14 = F_2 ( V_13 * , V_2 + 1 ) ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
V_1 -> V_8 [ V_3 ] = - 1 ;
V_1 -> V_10 [ V_3 ] = - 1 ;
}
V_1 -> V_15 = F_3 ( V_16 ,
V_17 , V_18 , NULL ) ;
}
static void
F_4 ( T_3 V_19 , T_3 T_4 V_20 )
{
F_5 ( V_19 ) ;
}
static void
F_6 ( T_5 * * V_21 )
{
if ( * V_21 != NULL ) {
F_7 ( * V_21 , F_4 , NULL ) ;
F_8 ( * V_21 ) ;
}
* V_21 = NULL ;
}
void
F_9 ( T_1 * V_1 )
{
int V_3 ;
V_7 * V_22 ;
if ( ! V_1 )
return;
for ( V_3 = 0 ; V_3 < V_1 -> V_2 ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
F_5 ( V_22 -> V_23 ) ;
F_5 ( V_22 -> V_24 ) ;
F_5 ( V_22 -> V_25 ) ;
F_10 ( V_22 -> V_26 ) ;
F_5 ( V_22 -> V_27 ) ;
F_5 ( V_1 -> V_12 . V_14 [ V_3 ] ) ;
F_6 ( & V_22 -> V_11 ) ;
}
F_5 ( V_1 -> V_6 ) ;
F_5 ( V_1 -> V_8 ) ;
F_5 ( V_1 -> V_10 ) ;
F_5 ( ( V_13 * * ) V_1 -> V_12 . V_12 ) ;
F_5 ( V_1 -> V_12 . V_14 ) ;
if ( V_1 -> V_15 )
F_11 ( V_1 -> V_15 ) ;
}
void
F_12 ( T_1 * V_1 , const struct V_28 * V_29 )
{
int V_3 ;
V_7 * V_22 ;
if ( ! V_1 )
return;
for ( V_3 = 0 ; V_3 < V_1 -> V_2 ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
V_22 -> V_27 [ 0 ] = '\0' ;
V_22 -> V_30 = V_22 -> V_27 ;
V_22 -> V_31 = 0 ;
V_22 -> V_32 = TRUE ;
V_1 -> V_12 . V_12 [ V_3 ] = L_1 ;
V_1 -> V_12 . V_14 [ V_3 ] [ 0 ] = '\0' ;
}
V_1 -> V_32 = TRUE ;
V_1 -> V_29 = V_29 ;
}
T_6
F_13 ( T_1 * V_1 , const T_2 V_33 )
{
int V_3 ;
V_7 * V_22 ;
if ( V_1 == NULL )
return FALSE ;
if ( ( V_33 == - 1 ) || ( V_1 -> V_32 == FALSE ) )
return V_1 -> V_32 ;
if ( V_1 -> V_8 [ V_33 ] >= 0 ) {
for ( V_3 = V_1 -> V_8 [ V_33 ] ; V_3 <= V_1 -> V_10 [ V_33 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_33 ] ) {
return V_22 -> V_32 ;
}
}
}
return FALSE ;
}
void
F_14 ( T_1 * V_1 , const T_2 V_33 , const T_6 V_32 )
{
int V_3 ;
V_7 * V_22 ;
if ( V_1 ) {
if ( V_33 == - 1 ) {
V_1 -> V_32 = V_32 ;
} else if ( V_1 -> V_8 [ V_33 ] >= 0 ) {
for ( V_3 = V_1 -> V_8 [ V_33 ] ; V_3 <= V_1 -> V_10 [ V_33 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_33 ] ) {
V_22 -> V_32 = V_32 ;
}
}
}
}
}
void
F_15 ( T_1 * V_1 , const T_2 V_34 )
{
int V_3 ;
V_7 * V_22 ;
if ( ! F_16 ( V_1 , V_34 ) )
return;
for ( V_3 = V_1 -> V_8 [ V_34 ] ; V_3 <= V_1 -> V_10 [ V_34 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_34 ] ) {
V_22 -> V_31 = ( int ) strlen ( V_22 -> V_30 ) ;
}
}
}
void
F_17 ( T_1 * V_1 , const T_2 V_34 )
{
int V_3 ;
V_7 * V_22 ;
if ( ! F_16 ( V_1 , V_34 ) )
return;
for ( V_3 = V_1 -> V_8 [ V_34 ] ; V_3 <= V_1 -> V_10 [ V_34 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_34 ] ) {
V_22 -> V_31 = 0 ;
}
}
}
const V_13 *
F_18 ( T_1 * V_1 , const T_2 V_34 )
{
int V_3 ;
const V_13 * V_35 = NULL ;
V_7 * V_22 ;
if ( ! ( V_1 && ( V_1 ) -> V_8 [ V_34 ] >= 0 ) ) {
return NULL ;
}
for ( V_3 = V_1 -> V_8 [ V_34 ] ; V_3 <= V_1 -> V_10 [ V_34 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_34 ] ) {
V_35 = ( V_22 -> V_30 ) ;
}
}
return V_35 ;
}
void
F_19 ( T_1 * V_1 , const T_2 V_34 )
{
int V_3 ;
V_7 * V_22 ;
if ( ! F_16 ( V_1 , V_34 ) )
return;
for ( V_3 = V_1 -> V_8 [ V_34 ] ; V_3 <= V_1 -> V_10 [ V_34 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_34 ] ) {
if ( V_22 -> V_27 == V_22 -> V_30 || V_22 -> V_31 == 0 ) {
V_22 -> V_27 [ V_22 -> V_31 ] = '\0' ;
V_22 -> V_30 = V_22 -> V_27 ;
}
V_1 -> V_12 . V_12 [ V_3 ] = L_1 ;
V_1 -> V_12 . V_14 [ V_3 ] [ 0 ] = '\0' ;
}
}
}
T_6
F_20 ( T_1 * V_1 )
{
return F_21 ( V_1 ) ;
}
T_6
F_22 ( void )
{
#ifdef F_23
return F_24 () ;
#else
return FALSE ;
#endif
}
void F_25 ( T_7 * V_36 , T_1 * V_1 )
{
int V_3 ;
V_7 * V_22 ;
if ( ! F_21 ( V_1 ) )
return;
for ( V_3 = V_1 -> V_8 [ V_37 ] ;
V_3 <= V_1 -> V_10 [ V_37 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_37 ] &&
V_22 -> V_25 &&
V_22 -> V_11 ) {
V_22 -> V_30 = V_22 -> V_27 ;
V_1 -> V_12 . V_12 [ V_3 ] = F_26 ( V_36 , V_22 -> V_11 ,
V_22 -> V_38 ,
V_22 -> V_27 ,
V_1 -> V_12 . V_14 [ V_3 ] ,
V_39 ) ;
}
}
}
void
F_27 ( T_7 * V_36 , T_1 * V_1 )
{
int V_3 ;
V_7 * V_22 ;
if ( ! F_21 ( V_1 ) )
return;
for ( V_3 = V_1 -> V_8 [ V_37 ] ;
V_3 <= V_1 -> V_10 [ V_37 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_37 ] &&
V_22 -> V_26 ) {
F_28 ( V_36 , V_22 -> V_26 ) ;
}
}
}
void
F_29 ( T_1 * V_1 , const T_2 V_34 , const V_13 * V_40 , ... )
{
T_8 V_41 ;
T_9 V_42 , V_43 ;
int V_3 ;
const V_13 * V_44 ;
V_7 * V_22 ;
if ( ! F_16 ( V_1 , V_34 ) )
return;
if ( V_34 == V_45 )
V_43 = V_46 ;
else
V_43 = V_39 ;
for ( V_3 = V_1 -> V_8 [ V_34 ] ; V_3 <= V_1 -> V_10 [ V_34 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_34 ] ) {
F_30 ( V_22 , V_43 ) ;
V_42 = strlen ( V_22 -> V_27 ) ;
if ( V_42 >= V_43 )
return;
va_start ( V_41 , V_40 ) ;
V_44 = V_40 ;
do {
if G_UNLIKELY( V_44 == NULL )
V_44 = L_2 ;
V_42 += F_31 ( & V_22 -> V_27 [ V_42 ] , V_44 , V_43 - V_42 ) ;
} while ( V_42 < V_43 && ( V_44 = va_arg ( V_41 , const char * ) ) != V_47 );
va_end ( V_41 ) ;
}
}
}
void
F_32 ( T_1 * V_1 , const T_2 V_33 , const V_13 * V_48 , T_10 V_49 , const V_13 * V_50 )
{
char V_51 [ 16 ] ;
F_33 ( V_49 , V_51 , sizeof( V_51 ) ) ;
F_29 ( V_1 , V_33 , V_50 ? V_50 : L_1 , V_48 , L_3 , V_51 , V_47 ) ;
}
static inline void
F_34 ( V_13 * V_51 , T_11 V_52 , T_12 V_53 , T_13 V_49 )
{
const char * V_44 ;
if ( V_54 . V_55 &&
( V_44 = F_35 ( V_53 , V_49 ) ) != NULL ) {
F_36 ( V_51 , V_52 , L_4 V_56 L_5 , V_44 , V_49 ) ;
} else {
F_36 ( V_51 , V_52 , L_6 V_56 , V_49 ) ;
}
}
void
F_37 ( T_1 * V_1 , const T_2 V_33 , T_12 V_53 , T_13 V_57 , T_13 V_58 )
{
char V_59 [ 32 ] , V_60 [ 32 ] ;
F_34 ( V_59 , 32 , V_53 , V_57 ) ;
F_34 ( V_60 , 32 , V_53 , V_58 ) ;
F_29 ( V_1 , V_33 , V_59 , L_7 V_61 L_7 , V_60 , V_47 ) ;
}
static void
F_38 ( T_1 * V_1 , const int V_34 , const char * V_62 , const char * V_63 , T_8 V_41 )
{
T_9 V_64 , V_43 , V_65 ;
int V_3 ;
V_7 * V_22 ;
V_65 = ( V_62 ) ? strlen ( V_62 ) : 0 ;
if ( V_34 == V_45 )
V_43 = V_46 ;
else
V_43 = V_39 ;
for ( V_3 = V_1 -> V_8 [ V_34 ] ; V_3 <= V_1 -> V_10 [ V_34 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_34 ] ) {
F_30 ( V_22 , V_43 ) ;
V_64 = strlen ( V_22 -> V_27 ) ;
if ( V_65 != 0 && V_64 != 0 ) {
F_39 ( V_22 -> V_27 , V_62 , V_43 ) ;
V_64 += V_65 ;
}
if ( V_64 < V_43 ) {
T_8 V_66 ;
F_40 ( V_66 , V_41 ) ;
F_41 ( & V_22 -> V_27 [ V_64 ] , ( T_10 ) ( V_43 - V_64 ) , V_63 , V_66 ) ;
va_end ( V_66 ) ;
}
}
}
}
void
F_42 ( T_1 * V_1 , const T_2 V_34 , const V_13 * V_63 , ... )
{
T_8 V_41 ;
if ( ! F_16 ( V_1 , V_34 ) )
return;
va_start ( V_41 , V_63 ) ;
F_38 ( V_1 , V_34 , NULL , V_63 , V_41 ) ;
va_end ( V_41 ) ;
}
void
F_43 ( T_1 * V_1 , const T_2 V_34 , const V_13 * V_62 ,
const V_13 * V_63 , ... )
{
T_8 V_41 ;
if ( ! F_16 ( V_1 , V_34 ) )
return;
if ( V_62 == NULL )
V_62 = L_8 ;
va_start ( V_41 , V_63 ) ;
F_38 ( V_1 , V_34 , V_62 , V_63 , V_41 ) ;
va_end ( V_41 ) ;
}
void
F_44 ( T_1 * V_1 , const T_2 V_34 , const V_13 * V_63 , ... )
{
T_8 V_41 ;
int V_3 ;
char V_67 [ V_68 ] ;
const char * V_69 ;
int V_43 ;
V_7 * V_22 ;
if ( ! F_16 ( V_1 , V_34 ) )
return;
if ( V_34 == V_45 )
V_43 = V_46 ;
else
V_43 = V_39 ;
for ( V_3 = V_1 -> V_8 [ V_34 ] ; V_3 <= V_1 -> V_10 [ V_34 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_34 ] ) {
if ( V_22 -> V_30 != V_22 -> V_27 ) {
V_69 = V_22 -> V_30 ;
} else {
F_31 ( V_67 , V_22 -> V_27 , V_43 ) ;
V_69 = V_67 ;
}
va_start ( V_41 , V_63 ) ;
F_41 ( V_22 -> V_27 , V_43 , V_63 , V_41 ) ;
va_end ( V_41 ) ;
if ( V_22 -> V_31 > 0 )
V_22 -> V_31 += ( int ) strlen ( V_22 -> V_27 ) ;
F_39 ( V_22 -> V_27 , V_69 , V_43 ) ;
V_22 -> V_30 = V_22 -> V_27 ;
}
}
}
void
F_45 ( T_1 * V_1 , const T_2 V_34 , const V_13 * V_63 , ... )
{
T_8 V_41 ;
int V_3 ;
char V_67 [ V_68 ] ;
const char * V_69 ;
int V_43 ;
V_7 * V_22 ;
if ( ! F_16 ( V_1 , V_34 ) )
return;
if ( V_34 == V_45 )
V_43 = V_46 ;
else
V_43 = V_39 ;
for ( V_3 = V_1 -> V_8 [ V_34 ] ; V_3 <= V_1 -> V_10 [ V_34 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_34 ] ) {
if ( V_22 -> V_30 != V_22 -> V_27 ) {
V_69 = V_22 -> V_30 ;
} else {
F_31 ( V_67 , V_22 -> V_27 , V_43 ) ;
V_69 = V_67 ;
}
va_start ( V_41 , V_63 ) ;
F_41 ( V_22 -> V_27 , V_43 , V_63 , V_41 ) ;
va_end ( V_41 ) ;
if ( V_22 -> V_31 > 0 ) {
V_22 -> V_31 += ( int ) strlen ( V_22 -> V_27 ) ;
} else {
V_22 -> V_31 = ( int ) strlen ( V_22 -> V_27 ) ;
}
F_39 ( V_22 -> V_27 , V_69 , V_43 ) ;
V_22 -> V_30 = V_22 -> V_27 ;
}
}
}
void
F_46 ( T_1 * V_1 , const T_2 V_34 , const V_13 * V_44 )
{
int V_3 ;
T_9 V_43 ;
V_7 * V_22 ;
if ( ! F_16 ( V_1 , V_34 ) )
return;
if ( V_34 == V_45 )
V_43 = V_46 ;
else
V_43 = V_39 ;
for ( V_3 = V_1 -> V_8 [ V_34 ] ; V_3 <= V_1 -> V_10 [ V_34 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_34 ] ) {
if ( V_22 -> V_31 != 0 ) {
F_30 ( V_22 , V_43 ) ;
} else {
V_22 -> V_30 = V_22 -> V_27 ;
}
F_31 ( & V_22 -> V_27 [ V_22 -> V_31 ] , V_44 , V_43 - V_22 -> V_31 ) ;
}
}
}
void
F_47 ( T_1 * V_1 , const T_2 V_34 , const V_13 * V_44 )
{
int V_3 ;
T_9 V_43 ;
V_7 * V_22 ;
F_48 ( V_44 ) ;
if ( ! F_16 ( V_1 , V_34 ) )
return;
if ( V_34 == V_45 )
V_43 = V_46 ;
else
V_43 = V_39 ;
for ( V_3 = V_1 -> V_8 [ V_34 ] ; V_3 <= V_1 -> V_10 [ V_34 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_34 ] ) {
if ( V_22 -> V_31 != 0 ) {
F_30 ( V_22 , V_43 ) ;
F_31 ( & V_22 -> V_27 [ V_22 -> V_31 ] , V_44 , V_43 - V_22 -> V_31 ) ;
} else {
V_22 -> V_30 = V_44 ;
}
}
}
}
void
F_49 ( T_1 * V_1 , const T_2 V_34 , const V_13 * V_40 , ... )
{
T_8 V_41 ;
int V_3 ;
T_14 V_42 ;
T_14 V_43 ;
const V_13 * V_44 ;
V_7 * V_22 ;
if ( ! F_16 ( V_1 , V_34 ) )
return;
if ( V_34 == V_45 )
V_43 = V_46 ;
else
V_43 = V_39 ;
for ( V_3 = V_1 -> V_8 [ V_34 ] ; V_3 <= V_1 -> V_10 [ V_34 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_34 ] ) {
V_42 = V_22 -> V_31 ;
if ( V_42 != 0 ) {
F_30 ( V_22 , V_43 ) ;
} else {
V_22 -> V_30 = V_22 -> V_27 ;
}
va_start ( V_41 , V_40 ) ;
V_44 = V_40 ;
do {
if G_UNLIKELY( V_44 == NULL )
V_44 = L_2 ;
V_42 += F_31 ( & V_22 -> V_27 [ V_42 ] , V_44 , V_43 - V_42 ) ;
} while ( V_42 < V_43 && ( V_44 = va_arg ( V_41 , const char * ) ) != V_47 );
va_end ( V_41 ) ;
}
}
}
void
F_50 ( T_1 * V_1 , const T_2 V_34 , const V_13 * V_63 , ... )
{
T_8 V_41 ;
int V_3 ;
int V_43 ;
V_7 * V_22 ;
if ( ! F_16 ( V_1 , V_34 ) )
return;
if ( V_34 == V_45 )
V_43 = V_46 ;
else
V_43 = V_39 ;
for ( V_3 = V_1 -> V_8 [ V_34 ] ; V_3 <= V_1 -> V_10 [ V_34 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_34 ] ) {
if ( V_22 -> V_31 != 0 ) {
F_30 ( V_22 , V_43 ) ;
} else {
V_22 -> V_30 = V_22 -> V_27 ;
}
va_start ( V_41 , V_63 ) ;
F_41 ( & V_22 -> V_27 [ V_22 -> V_31 ] , V_43 - V_22 -> V_31 , V_63 , V_41 ) ;
va_end ( V_41 ) ;
}
}
}
static void
F_51 ( T_1 * V_1 , const T_2 V_34 , const V_13 * V_62 ,
const V_13 * V_44 )
{
int V_3 ;
T_9 V_64 , V_43 ;
V_7 * V_22 ;
if ( V_34 == V_45 )
V_43 = V_46 ;
else
V_43 = V_39 ;
for ( V_3 = V_1 -> V_8 [ V_34 ] ; V_3 <= V_1 -> V_10 [ V_34 ] ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( V_22 -> V_23 [ V_34 ] ) {
F_30 ( V_22 , V_43 ) ;
V_64 = V_22 -> V_27 [ 0 ] ;
if ( V_62 != NULL ) {
if ( V_64 != 0 ) {
F_39 ( V_22 -> V_27 , V_62 , V_43 ) ;
}
}
F_39 ( V_22 -> V_27 , V_44 , V_43 ) ;
}
}
}
void
F_52 ( T_1 * V_1 , const T_2 V_34 , const V_13 * V_44 )
{
if ( ! F_16 ( V_1 , V_34 ) )
return;
F_51 ( V_1 , V_34 , NULL , V_44 ) ;
}
void
F_53 ( T_1 * V_1 , const T_2 V_34 , const V_13 * V_62 ,
const V_13 * V_44 )
{
if ( ! F_16 ( V_1 , V_34 ) )
return;
if ( V_62 == NULL )
V_62 = L_8 ;
F_51 ( V_1 , V_34 , V_62 , V_44 ) ;
}
T_6
F_54 ( T_1 * V_1 , const T_2 V_33 )
{
V_7 * V_22 = & V_1 -> V_6 [ V_33 ] ;
return ( ( V_22 -> V_23 [ V_70 ] ) ||
( V_22 -> V_23 [ V_71 ] ) ||
( V_22 -> V_23 [ V_72 ] ) ||
( V_22 -> V_23 [ V_73 ] ) ||
( V_22 -> V_23 [ V_74 ] ) ||
( V_22 -> V_23 [ V_75 ] ) ||
( V_22 -> V_23 [ V_76 ] ) ||
( V_22 -> V_23 [ V_77 ] ) ||
( V_22 -> V_23 [ V_78 ] ) ||
( V_22 -> V_23 [ V_79 ] ) ) ;
}
static void
F_55 ( const T_15 * V_80 , V_13 * V_51 , char * V_5 , T_6 V_81 )
{
struct V_82 * V_83 ;
T_16 V_84 ;
int V_85 ;
if ( V_80 -> V_86 . V_87 ) {
V_84 = V_80 -> V_88 . V_89 ;
if ( V_81 )
V_83 = localtime ( & V_84 ) ;
else
V_83 = gmtime ( & V_84 ) ;
} else
V_83 = NULL ;
if ( V_83 != NULL ) {
switch ( F_56 () ) {
case V_90 :
V_85 = V_91 ;
break;
case V_92 :
V_85 = V_93 ;
break;
case V_94 :
V_85 = V_95 ;
break;
case V_96 :
V_85 = V_97 ;
break;
case V_98 :
V_85 = V_99 ;
break;
case V_100 :
V_85 = V_101 ;
break;
case V_102 :
V_85 = V_80 -> V_103 ;
break;
default:
F_57 () ;
}
switch ( V_85 ) {
case V_91 :
F_36 ( V_51 , V_39 , L_9 ,
V_83 -> V_104 + 1900 ,
V_83 -> V_105 + 1 ,
V_83 -> V_106 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ) ;
break;
case V_93 :
F_36 ( V_51 , V_39 , L_10 ,
V_83 -> V_104 + 1900 ,
V_83 -> V_105 + 1 ,
V_83 -> V_106 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ,
V_5 ,
V_80 -> V_88 . V_110 / 100000000 ) ;
break;
case V_95 :
F_36 ( V_51 , V_39 , L_11 ,
V_83 -> V_104 + 1900 ,
V_83 -> V_105 + 1 ,
V_83 -> V_106 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ,
V_5 ,
V_80 -> V_88 . V_110 / 10000000 ) ;
break;
case V_97 :
F_36 ( V_51 , V_39 , L_12 ,
V_83 -> V_104 + 1900 ,
V_83 -> V_105 + 1 ,
V_83 -> V_106 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ,
V_5 ,
V_80 -> V_88 . V_110 / 1000000 ) ;
break;
case V_99 :
F_36 ( V_51 , V_39 , L_13 ,
V_83 -> V_104 + 1900 ,
V_83 -> V_105 + 1 ,
V_83 -> V_106 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ,
V_5 ,
V_80 -> V_88 . V_110 / 1000 ) ;
break;
case V_101 :
F_36 ( V_51 , V_39 , L_14 ,
V_83 -> V_104 + 1900 ,
V_83 -> V_105 + 1 ,
V_83 -> V_106 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ,
V_5 ,
V_80 -> V_88 . V_110 ) ;
break;
default:
F_57 () ;
}
} else {
V_51 [ 0 ] = '\0' ;
}
}
static void
F_58 ( const T_15 * V_80 , T_1 * V_1 , const int V_33 )
{
F_55 ( V_80 , V_1 -> V_6 [ V_33 ] . V_27 , V_4 , TRUE ) ;
V_1 -> V_12 . V_12 [ V_33 ] = L_15 ;
F_31 ( V_1 -> V_12 . V_14 [ V_33 ] , V_1 -> V_6 [ V_33 ] . V_27 , V_39 ) ;
V_1 -> V_6 [ V_33 ] . V_30 = V_1 -> V_6 [ V_33 ] . V_27 ;
}
static void
F_59 ( const T_15 * V_80 , T_1 * V_1 , const int V_33 )
{
F_55 ( V_80 , V_1 -> V_6 [ V_33 ] . V_27 , V_4 , FALSE ) ;
V_1 -> V_12 . V_12 [ V_33 ] = L_15 ;
F_31 ( V_1 -> V_12 . V_14 [ V_33 ] , V_1 -> V_6 [ V_33 ] . V_27 , V_39 ) ;
V_1 -> V_6 [ V_33 ] . V_30 = V_1 -> V_6 [ V_33 ] . V_27 ;
}
static void
F_60 ( const T_15 * V_80 , V_13 * V_51 , char * V_5 , T_6 V_81 )
{
struct V_82 * V_83 ;
T_16 V_84 ;
int V_85 ;
if ( V_80 -> V_86 . V_87 ) {
V_84 = V_80 -> V_88 . V_89 ;
if ( V_81 )
V_83 = localtime ( & V_84 ) ;
else
V_83 = gmtime ( & V_84 ) ;
} else
V_83 = NULL ;
if ( V_83 != NULL ) {
switch ( F_56 () ) {
case V_90 :
V_85 = V_91 ;
break;
case V_92 :
V_85 = V_93 ;
break;
case V_94 :
V_85 = V_95 ;
break;
case V_96 :
V_85 = V_97 ;
break;
case V_98 :
V_85 = V_99 ;
break;
case V_100 :
V_85 = V_101 ;
break;
case V_102 :
V_85 = V_80 -> V_103 ;
break;
default:
F_57 () ;
}
switch ( V_85 ) {
case V_91 :
F_36 ( V_51 , V_39 , L_16 ,
V_83 -> V_104 + 1900 ,
V_83 -> V_111 + 1 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ) ;
break;
case V_93 :
F_36 ( V_51 , V_39 , L_17 ,
V_83 -> V_104 + 1900 ,
V_83 -> V_111 + 1 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ,
V_5 ,
V_80 -> V_88 . V_110 / 100000000 ) ;
break;
case V_95 :
F_36 ( V_51 , V_39 , L_18 ,
V_83 -> V_104 + 1900 ,
V_83 -> V_111 + 1 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ,
V_5 ,
V_80 -> V_88 . V_110 / 10000000 ) ;
break;
case V_97 :
F_36 ( V_51 , V_39 , L_19 ,
V_83 -> V_104 + 1900 ,
V_83 -> V_111 + 1 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ,
V_5 ,
V_80 -> V_88 . V_110 / 1000000 ) ;
break;
case V_99 :
F_36 ( V_51 , V_39 , L_20 ,
V_83 -> V_104 + 1900 ,
V_83 -> V_111 + 1 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ,
V_5 ,
V_80 -> V_88 . V_110 / 1000 ) ;
break;
case V_101 :
F_36 ( V_51 , V_39 , L_21 ,
V_83 -> V_104 + 1900 ,
V_83 -> V_111 + 1 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ,
V_5 ,
V_80 -> V_88 . V_110 ) ;
break;
default:
F_57 () ;
}
} else {
V_51 [ 0 ] = '\0' ;
}
}
static void
F_61 ( const T_15 * V_80 , T_1 * V_1 , const int V_33 )
{
F_60 ( V_80 , V_1 -> V_6 [ V_33 ] . V_27 , V_4 , TRUE ) ;
V_1 -> V_12 . V_12 [ V_33 ] = L_15 ;
F_31 ( V_1 -> V_12 . V_14 [ V_33 ] , V_1 -> V_6 [ V_33 ] . V_27 , V_39 ) ;
V_1 -> V_6 [ V_33 ] . V_30 = V_1 -> V_6 [ V_33 ] . V_27 ;
}
static void
F_62 ( const T_15 * V_80 , T_1 * V_1 , const int V_33 )
{
F_60 ( V_80 , V_1 -> V_6 [ V_33 ] . V_27 , V_4 , FALSE ) ;
V_1 -> V_12 . V_12 [ V_33 ] = L_15 ;
F_31 ( V_1 -> V_12 . V_14 [ V_33 ] , V_1 -> V_6 [ V_33 ] . V_27 , V_39 ) ;
V_1 -> V_6 [ V_33 ] . V_30 = V_1 -> V_6 [ V_33 ] . V_27 ;
}
static void
F_63 ( const T_15 * V_80 , const T_17 * V_112 , V_13 * V_51 )
{
int V_85 ;
switch ( F_56 () ) {
case V_90 :
V_85 = V_91 ;
break;
case V_92 :
V_85 = V_93 ;
break;
case V_94 :
V_85 = V_95 ;
break;
case V_96 :
V_85 = V_97 ;
break;
case V_98 :
V_85 = V_99 ;
break;
case V_100 :
V_85 = V_101 ;
break;
case V_102 :
V_85 = V_80 -> V_103 ;
break;
default:
F_57 () ;
}
switch ( V_85 ) {
case V_91 :
F_64 ( V_51 , V_39 ,
( V_113 ) V_112 -> V_89 , V_112 -> V_110 / 1000000000 , V_114 ) ;
break;
case V_93 :
F_64 ( V_51 , V_39 ,
( V_113 ) V_112 -> V_89 , V_112 -> V_110 / 100000000 , V_115 ) ;
break;
case V_95 :
F_64 ( V_51 , V_39 ,
( V_113 ) V_112 -> V_89 , V_112 -> V_110 / 10000000 , V_116 ) ;
break;
case V_97 :
F_64 ( V_51 , V_39 ,
( V_113 ) V_112 -> V_89 , V_112 -> V_110 / 1000000 , V_117 ) ;
break;
case V_99 :
F_64 ( V_51 , V_39 ,
( V_113 ) V_112 -> V_89 , V_112 -> V_110 / 1000 , V_118 ) ;
break;
case V_101 :
F_64 ( V_51 , V_39 ,
( V_113 ) V_112 -> V_89 , V_112 -> V_110 , V_119 ) ;
break;
default:
F_57 () ;
}
}
static void
F_65 ( const T_15 * V_80 , const T_17 * V_112 , V_13 * V_51 , char * V_5 )
{
T_16 V_89 = V_112 -> V_89 ;
long V_110 = ( long ) V_112 -> V_110 ;
T_6 V_120 = FALSE ;
int V_85 ;
if ( V_89 < 0 ) {
V_89 = - V_89 ;
V_120 = TRUE ;
}
if ( V_110 < 0 ) {
V_110 = - V_110 ;
V_120 = TRUE ;
}
switch ( F_56 () ) {
case V_90 :
V_85 = V_91 ;
break;
case V_92 :
V_85 = V_93 ;
break;
case V_94 :
V_85 = V_95 ;
break;
case V_96 :
V_85 = V_97 ;
break;
case V_98 :
V_85 = V_99 ;
break;
case V_100 :
V_85 = V_101 ;
break;
case V_102 :
V_85 = V_80 -> V_103 ;
break;
default:
F_57 () ;
}
switch ( V_85 ) {
case V_91 :
if ( V_89 >= ( 60 * 60 ) ) {
F_36 ( V_51 , V_39 , L_22 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 / ( 60 * 60 ) ,
( V_113 ) ( V_89 / 60 ) % 60 ,
( V_113 ) V_89 % 60 ) ;
} else if ( V_89 >= 60 ) {
F_36 ( V_51 , V_39 , L_24 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 / 60 ,
( V_113 ) V_89 % 60 ) ;
} else {
F_36 ( V_51 , V_39 , L_25 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 ) ;
}
break;
case V_93 :
if ( V_89 >= ( 60 * 60 ) ) {
F_36 ( V_51 , V_39 , L_26 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 / ( 60 * 60 ) ,
( V_113 ) ( V_89 / 60 ) % 60 ,
( V_113 ) V_89 % 60 ,
V_5 ,
V_110 / 100000000 ) ;
} else if ( V_89 >= 60 ) {
F_36 ( V_51 , V_39 , L_27 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 / 60 ,
( V_113 ) V_89 % 60 ,
V_5 ,
V_110 / 100000000 ) ;
} else {
F_36 ( V_51 , V_39 , L_28 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 ,
V_5 ,
V_110 / 100000000 ) ;
}
break;
case V_95 :
if ( V_89 >= ( 60 * 60 ) ) {
F_36 ( V_51 , V_39 , L_29 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 / ( 60 * 60 ) ,
( V_113 ) ( V_89 / 60 ) % 60 ,
( V_113 ) V_89 % 60 ,
V_5 ,
V_110 / 10000000 ) ;
} else if ( V_89 >= 60 ) {
F_36 ( V_51 , V_39 , L_30 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 / 60 ,
( V_113 ) V_89 % 60 ,
V_5 ,
V_110 / 10000000 ) ;
} else {
F_36 ( V_51 , V_39 , L_31 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 ,
V_5 ,
V_110 / 10000000 ) ;
}
break;
case V_97 :
if ( V_89 >= ( 60 * 60 ) ) {
F_36 ( V_51 , V_39 , L_32 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 / ( 60 * 60 ) ,
( V_113 ) ( V_89 / 60 ) % 60 ,
( V_113 ) V_89 % 60 ,
V_5 ,
V_110 / 1000000 ) ;
} else if ( V_89 >= 60 ) {
F_36 ( V_51 , V_39 , L_33 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 / 60 ,
( V_113 ) V_89 % 60 ,
V_5 ,
V_110 / 1000000 ) ;
} else {
F_36 ( V_51 , V_39 , L_34 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 ,
V_5 ,
V_110 / 1000000 ) ;
}
break;
case V_99 :
if ( V_89 >= ( 60 * 60 ) ) {
F_36 ( V_51 , V_39 , L_35 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 / ( 60 * 60 ) ,
( V_113 ) ( V_89 / 60 ) % 60 ,
( V_113 ) V_89 % 60 ,
V_5 ,
V_110 / 1000 ) ;
} else if ( V_89 >= 60 ) {
F_36 ( V_51 , V_39 , L_36 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 / 60 ,
( V_113 ) V_89 % 60 ,
V_5 ,
V_110 / 1000 ) ;
} else {
F_36 ( V_51 , V_39 , L_37 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 ,
V_5 ,
V_110 / 1000 ) ;
}
break;
case V_101 :
if ( V_89 >= ( 60 * 60 ) ) {
F_36 ( V_51 , V_39 , L_38 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 / ( 60 * 60 ) ,
( V_113 ) ( V_89 / 60 ) % 60 ,
( V_113 ) V_89 % 60 ,
V_5 ,
V_110 ) ;
} else if ( V_89 >= 60 ) {
F_36 ( V_51 , V_39 , L_39 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 / 60 ,
( V_113 ) V_89 % 60 ,
V_5 ,
V_110 ) ;
} else {
F_36 ( V_51 , V_39 , L_40 ,
V_120 ? L_23 : L_1 ,
( V_113 ) V_89 ,
V_5 ,
V_110 ) ;
}
break;
default:
F_57 () ;
}
}
static void
F_66 ( const T_15 * V_80 , T_1 * V_1 , const int V_33 )
{
T_17 V_121 ;
if ( ! V_80 -> V_86 . V_87 ) {
V_1 -> V_6 [ V_33 ] . V_27 [ 0 ] = '\0' ;
return;
}
F_67 ( V_1 -> V_29 , V_80 , V_80 -> V_122 , & V_121 ) ;
switch ( F_68 () ) {
case V_123 :
F_63 ( V_80 , & V_121 , V_1 -> V_6 [ V_33 ] . V_27 ) ;
V_1 -> V_12 . V_12 [ V_33 ] = L_41 ;
F_31 ( V_1 -> V_12 . V_14 [ V_33 ] , V_1 -> V_6 [ V_33 ] . V_27 , V_39 ) ;
break;
case V_124 :
F_65 ( V_80 , & V_121 , V_1 -> V_6 [ V_33 ] . V_27 , V_4 ) ;
V_1 -> V_12 . V_12 [ V_33 ] = L_41 ;
F_63 ( V_80 , & V_121 , V_1 -> V_12 . V_14 [ V_33 ] ) ;
break;
default:
F_57 () ;
}
V_1 -> V_6 [ V_33 ] . V_30 = V_1 -> V_6 [ V_33 ] . V_27 ;
}
static void
F_69 ( const T_15 * V_80 , T_1 * V_1 , const int V_33 )
{
T_17 V_125 ;
F_67 ( V_1 -> V_29 , V_80 , V_80 -> V_126 - 1 , & V_125 ) ;
switch ( F_68 () ) {
case V_123 :
F_63 ( V_80 , & V_125 , V_1 -> V_6 [ V_33 ] . V_27 ) ;
V_1 -> V_12 . V_12 [ V_33 ] = L_42 ;
F_31 ( V_1 -> V_12 . V_14 [ V_33 ] , V_1 -> V_6 [ V_33 ] . V_27 , V_39 ) ;
break;
case V_124 :
F_65 ( V_80 , & V_125 , V_1 -> V_6 [ V_33 ] . V_27 , V_4 ) ;
V_1 -> V_12 . V_12 [ V_33 ] = L_42 ;
F_63 ( V_80 , & V_125 , V_1 -> V_12 . V_14 [ V_33 ] ) ;
break;
default:
F_57 () ;
}
V_1 -> V_6 [ V_33 ] . V_30 = V_1 -> V_6 [ V_33 ] . V_27 ;
}
static void
F_70 ( const T_15 * V_80 , T_1 * V_1 , const int V_33 )
{
T_17 V_127 ;
if ( ! V_80 -> V_86 . V_87 ) {
V_1 -> V_6 [ V_33 ] . V_27 [ 0 ] = '\0' ;
return;
}
F_67 ( V_1 -> V_29 , V_80 , V_80 -> V_128 , & V_127 ) ;
switch ( F_68 () ) {
case V_123 :
F_63 ( V_80 , & V_127 , V_1 -> V_6 [ V_33 ] . V_27 ) ;
V_1 -> V_12 . V_12 [ V_33 ] = L_43 ;
F_31 ( V_1 -> V_12 . V_14 [ V_33 ] , V_1 -> V_6 [ V_33 ] . V_27 , V_39 ) ;
break;
case V_124 :
F_65 ( V_80 , & V_127 , V_1 -> V_6 [ V_33 ] . V_27 , V_4 ) ;
V_1 -> V_12 . V_12 [ V_33 ] = L_43 ;
F_63 ( V_80 , & V_127 , V_1 -> V_12 . V_14 [ V_33 ] ) ;
break;
default:
F_57 () ;
}
V_1 -> V_6 [ V_33 ] . V_30 = V_1 -> V_6 [ V_33 ] . V_27 ;
}
static void
F_71 ( const T_15 * V_80 , V_13 * V_51 , char * V_5 , T_6 V_81 )
{
struct V_82 * V_83 ;
T_16 V_84 ;
int V_85 ;
if ( V_80 -> V_86 . V_87 ) {
V_84 = V_80 -> V_88 . V_89 ;
if ( V_81 )
V_83 = localtime ( & V_84 ) ;
else
V_83 = gmtime ( & V_84 ) ;
} else
V_83 = NULL ;
if ( V_83 != NULL ) {
switch ( F_56 () ) {
case V_90 :
V_85 = V_91 ;
break;
case V_92 :
V_85 = V_93 ;
break;
case V_94 :
V_85 = V_95 ;
break;
case V_96 :
V_85 = V_97 ;
break;
case V_98 :
V_85 = V_99 ;
break;
case V_100 :
V_85 = V_101 ;
break;
case V_102 :
V_85 = V_80 -> V_103 ;
break;
default:
F_57 () ;
}
switch ( V_85 ) {
case V_91 :
F_36 ( V_51 , V_39 , L_44 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ) ;
break;
case V_93 :
F_36 ( V_51 , V_39 , L_45 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ,
V_5 ,
V_80 -> V_88 . V_110 / 100000000 ) ;
break;
case V_95 :
F_36 ( V_51 , V_39 , L_46 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ,
V_5 ,
V_80 -> V_88 . V_110 / 10000000 ) ;
break;
case V_97 :
F_36 ( V_51 , V_39 , L_47 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ,
V_5 ,
V_80 -> V_88 . V_110 / 1000000 ) ;
break;
case V_99 :
F_36 ( V_51 , V_39 , L_48 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ,
V_5 ,
V_80 -> V_88 . V_110 / 1000 ) ;
break;
case V_101 :
F_36 ( V_51 , V_39 , L_49 ,
V_83 -> V_107 ,
V_83 -> V_108 ,
V_83 -> V_109 ,
V_5 ,
V_80 -> V_88 . V_110 ) ;
break;
default:
F_57 () ;
}
} else {
* V_51 = '\0' ;
}
}
static void
F_72 ( const T_15 * V_80 , T_1 * V_1 , const int V_33 )
{
F_71 ( V_80 , V_1 -> V_6 [ V_33 ] . V_27 , V_4 , TRUE ) ;
V_1 -> V_12 . V_12 [ V_33 ] = L_15 ;
F_31 ( V_1 -> V_12 . V_14 [ V_33 ] , V_1 -> V_6 [ V_33 ] . V_27 , V_39 ) ;
V_1 -> V_6 [ V_33 ] . V_30 = V_1 -> V_6 [ V_33 ] . V_27 ;
}
static void
F_73 ( const T_15 * V_80 , T_1 * V_1 , const int V_33 )
{
F_71 ( V_80 , V_1 -> V_6 [ V_33 ] . V_27 , V_4 , FALSE ) ;
V_1 -> V_12 . V_12 [ V_33 ] = L_15 ;
F_31 ( V_1 -> V_12 . V_14 [ V_33 ] , V_1 -> V_6 [ V_33 ] . V_27 , V_39 ) ;
V_1 -> V_6 [ V_33 ] . V_30 = V_1 -> V_6 [ V_33 ] . V_27 ;
}
static T_6
F_74 ( const T_15 * V_80 , V_13 * V_51 )
{
int V_85 ;
if ( ! V_80 -> V_86 . V_87 ) {
V_51 [ 0 ] = '\0' ;
return FALSE ;
}
switch ( F_56 () ) {
case V_90 :
V_85 = V_91 ;
break;
case V_92 :
V_85 = V_93 ;
break;
case V_94 :
V_85 = V_95 ;
break;
case V_96 :
V_85 = V_97 ;
break;
case V_98 :
V_85 = V_99 ;
break;
case V_100 :
V_85 = V_101 ;
break;
case V_102 :
V_85 = V_80 -> V_103 ;
break;
default:
F_57 () ;
}
switch ( V_85 ) {
case V_91 :
F_75 ( V_51 , V_39 ,
V_80 -> V_88 . V_89 , V_80 -> V_88 . V_110 / 1000000000 , V_114 ) ;
break;
case V_93 :
F_75 ( V_51 , V_39 ,
V_80 -> V_88 . V_89 , V_80 -> V_88 . V_110 / 100000000 , V_115 ) ;
break;
case V_95 :
F_75 ( V_51 , V_39 ,
V_80 -> V_88 . V_89 , V_80 -> V_88 . V_110 / 10000000 , V_116 ) ;
break;
case V_97 :
F_75 ( V_51 , V_39 ,
V_80 -> V_88 . V_89 , V_80 -> V_88 . V_110 / 1000000 , V_117 ) ;
break;
case V_99 :
F_75 ( V_51 , V_39 ,
V_80 -> V_88 . V_89 , V_80 -> V_88 . V_110 / 1000 , V_118 ) ;
break;
case V_101 :
F_75 ( V_51 , V_39 ,
V_80 -> V_88 . V_89 , V_80 -> V_88 . V_110 , V_119 ) ;
break;
default:
F_57 () ;
}
return TRUE ;
}
static void
F_76 ( const T_15 * V_80 , T_1 * V_1 , const int V_33 )
{
if ( F_74 ( V_80 , V_1 -> V_6 [ V_33 ] . V_27 ) ) {
V_1 -> V_12 . V_12 [ V_33 ] = L_42 ;
F_31 ( V_1 -> V_12 . V_14 [ V_33 ] , V_1 -> V_6 [ V_33 ] . V_27 , V_39 ) ;
}
V_1 -> V_6 [ V_33 ] . V_30 = V_1 -> V_6 [ V_33 ] . V_27 ;
}
void
F_77 ( const T_18 * V_29 , T_15 * V_80 , V_13 * V_51 )
{
switch ( F_78 () ) {
case V_129 :
F_71 ( V_80 , V_51 , V_4 , TRUE ) ;
break;
case V_130 :
F_55 ( V_80 , V_51 , V_4 , TRUE ) ;
break;
case V_131 :
F_60 ( V_80 , V_51 , V_4 , TRUE ) ;
break;
case V_132 :
if ( V_80 -> V_86 . V_87 ) {
T_17 V_121 ;
F_67 ( V_29 , V_80 , V_80 -> V_122 , & V_121 ) ;
switch ( F_68 () ) {
case V_123 :
F_63 ( V_80 , & V_121 , V_51 ) ;
break;
case V_124 :
F_63 ( V_80 , & V_121 , V_51 ) ;
break;
default:
F_57 () ;
}
} else {
V_51 [ 0 ] = '\0' ;
}
break;
case V_133 :
if ( V_80 -> V_86 . V_87 ) {
T_17 V_125 ;
F_67 ( V_29 , V_80 , V_80 -> V_126 - 1 , & V_125 ) ;
switch ( F_68 () ) {
case V_123 :
F_63 ( V_80 , & V_125 , V_51 ) ;
break;
case V_124 :
F_65 ( V_80 , & V_125 , V_51 , V_4 ) ;
break;
default:
F_57 () ;
}
} else {
V_51 [ 0 ] = '\0' ;
}
break;
case V_134 :
if ( V_80 -> V_86 . V_87 ) {
T_17 V_127 ;
F_67 ( V_29 , V_80 , V_80 -> V_128 , & V_127 ) ;
switch ( F_68 () ) {
case V_123 :
F_63 ( V_80 , & V_127 , V_51 ) ;
break;
case V_124 :
F_65 ( V_80 , & V_127 , V_51 , V_4 ) ;
break;
default:
F_57 () ;
}
} else {
V_51 [ 0 ] = '\0' ;
}
break;
case V_135 :
F_74 ( V_80 , V_51 ) ;
break;
case V_136 :
F_71 ( V_80 , V_51 , V_4 , FALSE ) ;
break;
case V_137 :
F_55 ( V_80 , V_51 , V_4 , FALSE ) ;
break;
case V_138 :
F_60 ( V_80 , V_51 , V_4 , FALSE ) ;
break;
case V_139 :
F_79 ( FALSE ) ;
break;
}
}
static void
F_80 ( const T_15 * V_80 , T_1 * V_1 , const T_2 V_33 )
{
switch ( F_78 () ) {
case V_129 :
F_72 ( V_80 , V_1 , V_33 ) ;
break;
case V_130 :
F_58 ( V_80 , V_1 , V_33 ) ;
break;
case V_131 :
F_61 ( V_80 , V_1 , V_33 ) ;
break;
case V_132 :
F_66 ( V_80 , V_1 , V_33 ) ;
break;
case V_133 :
F_69 ( V_80 , V_1 , V_33 ) ;
break;
case V_134 :
F_70 ( V_80 , V_1 , V_33 ) ;
break;
case V_135 :
F_76 ( V_80 , V_1 , V_33 ) ;
break;
case V_136 :
F_73 ( V_80 , V_1 , V_33 ) ;
break;
case V_137 :
F_59 ( V_80 , V_1 , V_33 ) ;
break;
case V_138 :
F_62 ( V_80 , V_1 , V_33 ) ;
break;
case V_139 :
F_57 () ;
break;
}
}
static void
F_81 ( const T_15 * V_80 , T_1 * V_1 , const T_2 V_140 , const T_2 V_33 )
{
F_82 ( V_80 , V_1 -> V_6 [ V_33 ] . V_27 ) ;
switch ( V_140 ) {
case V_70 :
F_80 ( V_80 , V_1 , V_33 ) ;
break;
case V_71 :
F_72 ( V_80 , V_1 , V_33 ) ;
break;
case V_72 :
F_58 ( V_80 , V_1 , V_33 ) ;
break;
case V_73 :
F_61 ( V_80 , V_1 , V_33 ) ;
break;
case V_77 :
F_66 ( V_80 , V_1 , V_33 ) ;
break;
case V_78 :
F_69 ( V_80 , V_1 , V_33 ) ;
break;
case V_79 :
F_70 ( V_80 , V_1 , V_33 ) ;
break;
case V_74 :
F_73 ( V_80 , V_1 , V_33 ) ;
break;
case V_75 :
F_59 ( V_80 , V_1 , V_33 ) ;
break;
case V_76 :
F_62 ( V_80 , V_1 , V_33 ) ;
break;
default:
F_57 () ;
break;
}
}
void
F_83 ( T_1 * V_1 , const T_2 V_34 , const T_17 * V_112 , const char * V_141 )
{
int V_33 ;
V_7 * V_22 ;
if ( ! F_16 ( V_1 , V_34 ) )
return;
for ( V_33 = V_1 -> V_8 [ V_34 ] ; V_33 <= V_1 -> V_10 [ V_34 ] ; V_33 ++ ) {
V_22 = & V_1 -> V_6 [ V_33 ] ;
if ( V_22 -> V_23 [ V_34 ] ) {
switch ( F_56 () ) {
case V_90 :
F_64 ( V_22 -> V_27 , V_39 ,
( V_113 ) V_112 -> V_89 , V_112 -> V_110 / 1000000000 , V_114 ) ;
break;
case V_92 :
F_64 ( V_22 -> V_27 , V_39 ,
( V_113 ) V_112 -> V_89 , V_112 -> V_110 / 100000000 , V_115 ) ;
break;
case V_94 :
F_64 ( V_22 -> V_27 , V_39 ,
( V_113 ) V_112 -> V_89 , V_112 -> V_110 / 10000000 , V_116 ) ;
break;
case V_96 :
F_64 ( V_22 -> V_27 , V_39 ,
( V_113 ) V_112 -> V_89 , V_112 -> V_110 / 1000000 , V_117 ) ;
break;
case V_98 :
F_64 ( V_22 -> V_27 , V_39 ,
( V_113 ) V_112 -> V_89 , V_112 -> V_110 / 1000 , V_118 ) ;
break;
case V_100 :
case V_102 :
F_64 ( V_22 -> V_27 , V_39 ,
( V_113 ) V_112 -> V_89 , V_112 -> V_110 , V_119 ) ;
break;
default:
F_57 () ;
}
V_22 -> V_30 = V_22 -> V_27 ;
V_1 -> V_12 . V_12 [ V_33 ] = V_141 ;
F_31 ( V_1 -> V_12 . V_14 [ V_33 ] , V_22 -> V_27 , V_39 ) ;
}
}
}
static void
F_84 ( T_19 * V_142 , const int V_33 , const T_20 * V_143 , const T_6 V_144 ,
const T_6 V_145 , const T_6 V_146 )
{
const char * V_147 ;
V_7 * V_22 = & V_142 -> V_1 -> V_6 [ V_33 ] ;
if ( V_143 -> type == V_148 ) {
return;
}
if ( V_146 && ( V_147 = F_85 ( V_143 ) ) != NULL )
V_22 -> V_30 = V_147 ;
else {
V_22 -> V_30 = V_22 -> V_27 ;
F_86 ( V_143 , V_22 -> V_27 , V_39 ) ;
}
if ( ! V_145 )
return;
V_142 -> V_1 -> V_12 . V_12 [ V_33 ] = F_87 ( V_143 , V_144 ) ;
if ( strlen ( V_142 -> V_1 -> V_12 . V_12 [ V_33 ] ) > 0 )
F_86 ( V_143 , V_142 -> V_1 -> V_12 . V_14 [ V_33 ] , V_39 ) ;
}
static void
F_88 ( T_19 * V_142 , const int V_33 , const T_6 V_149 , const T_6 V_144 , const T_6 V_145 V_20 )
{
T_10 V_150 ;
V_7 * V_22 = & V_142 -> V_1 -> V_6 [ V_33 ] ;
if ( V_144 )
V_150 = V_142 -> V_151 ;
else
V_150 = V_142 -> V_152 ;
switch ( V_142 -> V_153 ) {
case V_154 :
if ( V_149 )
F_31 ( V_22 -> V_27 , F_89 ( V_142 -> V_155 , V_150 ) , V_39 ) ;
else
F_33 ( V_150 , V_22 -> V_27 , V_39 ) ;
break;
case V_156 :
F_33 ( V_150 , V_142 -> V_1 -> V_12 . V_14 [ V_33 ] , V_39 ) ;
if ( V_149 )
F_31 ( V_22 -> V_27 , F_90 ( V_142 -> V_155 , V_150 ) , V_39 ) ;
else
F_31 ( V_22 -> V_27 , V_142 -> V_1 -> V_12 . V_14 [ V_33 ] , V_39 ) ;
if ( V_144 )
V_142 -> V_1 -> V_12 . V_12 [ V_33 ] = L_50 ;
else
V_142 -> V_1 -> V_12 . V_12 [ V_33 ] = L_51 ;
break;
case V_157 :
F_33 ( V_150 , V_142 -> V_1 -> V_12 . V_14 [ V_33 ] , V_39 ) ;
if ( V_149 )
F_31 ( V_22 -> V_27 , F_91 ( V_142 -> V_155 , V_150 ) , V_39 ) ;
else
F_31 ( V_22 -> V_27 , V_142 -> V_1 -> V_12 . V_14 [ V_33 ] , V_39 ) ;
if ( V_144 )
V_142 -> V_1 -> V_12 . V_12 [ V_33 ] = L_52 ;
else
V_142 -> V_1 -> V_12 . V_12 [ V_33 ] = L_53 ;
break;
case V_158 :
if ( V_144 )
V_142 -> V_1 -> V_12 . V_12 [ V_33 ] = L_54 ;
else
V_142 -> V_1 -> V_12 . V_12 [ V_33 ] = L_55 ;
F_33 ( V_150 , V_142 -> V_1 -> V_12 . V_14 [ V_33 ] , V_39 ) ;
F_31 ( V_22 -> V_27 , V_142 -> V_1 -> V_12 . V_14 [ V_33 ] , V_39 ) ;
break;
case V_159 :
F_36 ( V_22 -> V_27 , V_39 , L_56 , V_150 ) ;
F_31 ( V_142 -> V_1 -> V_12 . V_14 [ V_33 ] , V_22 -> V_27 , V_39 ) ;
if ( V_144 )
V_142 -> V_1 -> V_12 . V_12 [ V_33 ] = L_57 ;
else
V_142 -> V_1 -> V_12 . V_12 [ V_33 ] = L_58 ;
break;
case V_160 :
F_36 ( V_22 -> V_27 , V_39 , L_56 , V_150 ) ;
F_31 ( V_142 -> V_1 -> V_12 . V_14 [ V_33 ] , V_22 -> V_27 , V_39 ) ;
if ( V_144 )
V_142 -> V_1 -> V_12 . V_12 [ V_33 ] = L_59 ;
else
V_142 -> V_1 -> V_12 . V_12 [ V_33 ] = L_60 ;
break;
case V_161 :
F_36 ( V_22 -> V_27 , V_39 , L_61 , V_150 ) ;
F_31 ( V_142 -> V_1 -> V_12 . V_14 [ V_33 ] , V_22 -> V_27 , V_39 ) ;
if ( V_144 )
V_142 -> V_1 -> V_12 . V_12 [ V_33 ] = L_62 ;
else
V_142 -> V_1 -> V_12 . V_12 [ V_33 ] = L_63 ;
break;
default:
break;
}
V_22 -> V_30 = V_22 -> V_27 ;
}
T_6
F_92 ( T_1 * V_1 , const T_2 V_33 )
{
F_79 ( V_1 ) ;
F_79 ( V_33 < V_1 -> V_2 ) ;
switch ( V_1 -> V_6 [ V_33 ] . V_162 ) {
case V_163 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_164 :
case V_165 :
return TRUE ;
default:
return FALSE ;
}
}
void
F_93 ( const T_15 * V_80 , T_1 * V_1 , const T_2 V_33 , const T_6 V_145 )
{
V_7 * V_22 = & V_1 -> V_6 [ V_33 ] ;
switch ( V_22 -> V_162 ) {
case V_163 :
F_33 ( V_80 -> V_126 , V_22 -> V_27 , V_39 ) ;
V_22 -> V_30 = V_22 -> V_27 ;
break;
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
F_81 ( V_80 , V_1 , V_22 -> V_162 , V_33 ) ;
break;
case V_164 :
F_33 ( V_80 -> V_166 , V_22 -> V_27 , V_39 ) ;
V_22 -> V_30 = V_22 -> V_27 ;
break;
case V_165 :
F_33 ( V_80 -> V_167 , V_22 -> V_27 , V_39 ) ;
V_22 -> V_30 = V_22 -> V_27 ;
break;
default:
break;
}
if ( ! V_145 )
return;
switch ( V_22 -> V_162 ) {
case V_163 :
V_1 -> V_12 . V_12 [ V_33 ] = L_64 ;
F_31 ( V_1 -> V_12 . V_14 [ V_33 ] , V_22 -> V_27 , V_39 ) ;
break;
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
break;
case V_164 :
V_1 -> V_12 . V_12 [ V_33 ] = L_65 ;
F_31 ( V_1 -> V_12 . V_14 [ V_33 ] , V_22 -> V_27 , V_39 ) ;
break;
case V_165 :
break;
default:
break;
}
}
void
F_94 ( T_19 * V_142 , const T_6 V_145 , const T_6 V_168 )
{
int V_3 ;
V_7 * V_22 ;
if ( ! V_142 -> V_1 )
return;
for ( V_3 = 0 ; V_3 < V_142 -> V_1 -> V_2 ; V_3 ++ ) {
V_22 = & V_142 -> V_1 -> V_6 [ V_3 ] ;
if ( F_92 ( V_142 -> V_1 , V_3 ) ) {
if ( V_168 )
F_93 ( V_142 -> V_80 , V_142 -> V_1 , V_3 , V_145 ) ;
} else {
switch ( V_22 -> V_162 ) {
case V_169 :
case V_170 :
F_84 ( V_142 , V_3 , & V_142 -> V_57 , TRUE , V_145 , TRUE ) ;
break;
case V_171 :
F_84 ( V_142 , V_3 , & V_142 -> V_57 , TRUE , V_145 , FALSE ) ;
break;
case V_172 :
case V_173 :
F_84 ( V_142 , V_3 , & V_142 -> V_174 , TRUE , V_145 , TRUE ) ;
break;
case V_175 :
F_84 ( V_142 , V_3 , & V_142 -> V_174 , TRUE , V_145 , FALSE ) ;
break;
case V_176 :
case V_177 :
F_84 ( V_142 , V_3 , & V_142 -> V_178 , TRUE , V_145 , TRUE ) ;
break;
case V_179 :
F_84 ( V_142 , V_3 , & V_142 -> V_178 , TRUE , V_145 , FALSE ) ;
break;
case V_180 :
case V_181 :
F_84 ( V_142 , V_3 , & V_142 -> V_58 , FALSE , V_145 , TRUE ) ;
break;
case V_182 :
F_84 ( V_142 , V_3 , & V_142 -> V_58 , FALSE , V_145 , FALSE ) ;
break;
case V_183 :
case V_184 :
F_84 ( V_142 , V_3 , & V_142 -> V_185 , FALSE , V_145 , TRUE ) ;
break;
case V_186 :
F_84 ( V_142 , V_3 , & V_142 -> V_185 , FALSE , V_145 , FALSE ) ;
break;
case V_187 :
case V_188 :
F_84 ( V_142 , V_3 , & V_142 -> V_189 , FALSE , V_145 , TRUE ) ;
break;
case V_190 :
F_84 ( V_142 , V_3 , & V_142 -> V_189 , FALSE , V_145 , FALSE ) ;
break;
case V_191 :
case V_192 :
F_88 ( V_142 , V_3 , TRUE , TRUE , V_145 ) ;
break;
case V_193 :
F_88 ( V_142 , V_3 , FALSE , TRUE , V_145 ) ;
break;
case V_194 :
case V_195 :
F_88 ( V_142 , V_3 , TRUE , FALSE , V_145 ) ;
break;
case V_196 :
F_88 ( V_142 , V_3 , FALSE , FALSE , V_145 ) ;
break;
case V_9 :
F_57 () ;
break;
default:
if ( V_22 -> V_162 >= V_9 ) {
F_57 () ;
}
break;
}
}
}
}
void
F_95 ( T_1 * V_1 , T_15 * V_197 , const T_6 V_145 , const T_6 V_168 )
{
int V_3 ;
V_7 * V_22 ;
if ( ! V_1 )
return;
for ( V_3 = 0 ; V_3 < V_1 -> V_2 ; V_3 ++ ) {
V_22 = & V_1 -> V_6 [ V_3 ] ;
if ( F_92 ( V_1 , V_3 ) ) {
if ( V_168 )
F_93 ( V_197 , V_1 , V_3 , V_145 ) ;
} else if ( V_22 -> V_162 == V_45 ) {
V_22 -> V_30 = L_66 ;
} else {
if ( V_22 -> V_162 >= V_9 ) {
F_57 () ;
}
V_22 -> V_30 = L_67 ;
break;
}
}
}
